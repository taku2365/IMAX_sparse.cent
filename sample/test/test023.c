static char RcsHeader[] = "$Header: /usr/home/nakashim/proj-arm64/sample/mm_cnn_lf/RCS/mm.c,v 1.4 2018/02/04 10:28:53 nakashim Exp nakashim $";

/*                          Copyright (C) 2013- by NAIST */
/*                           Primary writer: Y.Nakashima */
/*                                  nakashim@is.naist.jp */

#ifndef UTYPEDEF
#define UTYPEDEF
typedef unsigned char      Uchar;
typedef unsigned short     Ushort;
typedef unsigned int       Uint;
typedef unsigned long long Ull;
typedef long long int      Sll;
#if __AARCH64EL__ == 1
typedef long double Dll;
#else
typedef struct {Ull u[2];} Dll;
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <math.h>
#include <malloc.h>
#include <assert.h>
#ifndef ARMSIML
#include <unistd.h>
#include <sys/times.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <pthread.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>
#include <X11/extensions/Xdbe.h>
#endif


int WD=320, HT=240, BITMAP=320*240, SCRWD=5, SCRHT=5, VECWD=240, VECHT=240, VECSTEP=4;

#if defined(EMAX6)
#include "../../src/conv-c2c/emax6.h"
#include "../../src/conv-c2c/emax6lib.c"
#include "emax6_sparselib.h"
#endif
#if !defined(ARMSIML)
#include "./xdisp.c"
#endif

Uchar* membase;

sysinit(memsize, alignment) Uint memsize, alignment;
{
#if defined(ARMZYNQ) && defined(EMAX5)
  if (emax5_open() == NULL)
    exit(1);
  membase = emax_info.hpp_mmap;
  {int i; for (i=0; i<(memsize+sizeof(Dll)-1)/sizeof(Dll); i++) *((Dll*)membase+i)=0;}
#elif defined(ARMZYNQ) && defined(EMAX6)
  if (emax6_open() == NULL)
    exit(1);
  membase = emax_info.ddr_mmap;
  {int i; for (i=0; i<(memsize+sizeof(Dll)-1)/sizeof(Dll); i++) *((Dll*)membase+i)=0;}
#else
  membase = (void*)malloc(memsize+alignment);
  printf("malloc size %d \n",malloc_usable_size(membase));
  printf("membase_before_align: %08.8x\n", (Uint)membase);
  if ((Ull)membase & (Ull)(alignment-1))
  membase = (void*)(((Ull)membase & ~(Ull)(alignment-1))+alignment);
  memset(membase, 0, memsize+alignment);
  
  // 32byte = 16byte*2 = 0x20
  printf("membase_after_align: %08.8x\n", (Uint)membase);

  
#endif

#if !defined(ARMZYNQ) && defined(EMAX5)
  emax_info.hpp_phys = membase;
  emax_info.hpp_mmap = emax_info.hpp_phys;
  emax_info.acp_phys = ACP_BASE2_PHYS; /* defined in emax5lib.h >= ALOCLIMIT */
  emax_info.acp_mmap = emax_info.acp_phys;
#endif
#if defined(EMAX5)
  acp_conf = emax_info.acp_mmap; /* 8KB * 256sets */
  acp_lmmi = emax_info.acp_mmap + 0x200000;
  acp_regv = emax_info.acp_mmap + 0x304000;
#endif

#if !defined(ARMZYNQ) && defined(EMAX6)
  emax_info.dma_phys = DMA_BASE2_PHYS; /* defined in emax6lib.h */
  emax_info.dma_mmap = emax_info.dma_phys;
  emax_info.reg_phys = REG_BASE2_PHYS; /* defined in emax6lib.h */
  emax_info.reg_mmap = emax_info.reg_phys;
  emax_info.lmm_phys = LMM_BASE2_PHYS;
  emax_info.lmm_mmap = emax_info.lmm_phys;
  emax_info.ddr_phys = membase;
  emax_info.ddr_mmap = emax_info.ddr_phys;
#endif
#if (defined(ARMSIML) || defined(ARMZYNQ)) && defined(EMAX6)
  emax6.dma_ctrl  = emax_info.dma_mmap;
  emax6.reg_ctrl  = emax_info.reg_mmap;
  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].cmd = CMD_RESET;  // ★★★ RESET
#if defined(ARMZYNQ)
  usleep(1);
#endif
  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].adtr = emax_info.ddr_mmap - emax_info.lmm_phys;
  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].dmrp = 0LL;
#endif
}

/* LMM:16KB, RMM:64KB: M/NCHIP=124 M/NCHIP/RMGRP=31 */
/* A A   B B B B B B   C C C C C C */
/* A A   B B B B B B   C C C C C C */
/* A A                 C C C C C C */
/* A A                 C C C C C C */
/* L=2, M1=4, M2=6     L<M1,M2     */

// #define L  120LL
// #define M1 120LL
// #define M2 120LL
#define L  768LL
#define M1 768LL
#define M2 768LL
// #define RMGRP 60
#define RMGRP 16
#define BLK_SIZE 80
/*#define NCHIP 4*/
#define NCHIP 2
#define W  4LL
#define H  48
Uint *A;  /*[M1][L];*/
Uint *B;  /*[L][M2];*/
Uint *C0; /*[M1][M2];*/
Uint *C1; /*[M1][M2];*/
Uint *A_debug; /*[M1][L];*/
Uint *B_debug; /*[L][M2];*/
Uint *C_debug; /*[M1][M2];*/
emax6_sparse1* A_sparse;
emax6_param* params;
int blk_iter;
int row,row1, col, col1, n, n1;
int top, blk;
int w, h;
int count0, count1, count2;
int nnz_A,nnz_B,nnz_B_debug;
double sum=0,sum1=0;


#define CSIMWD 320
#define CSIMHT 240
#define CSIMBM (CSIMWD*CSIMHT)
Uint Z[CSIMBM];

#define MAXINT (~(1<<(sizeof(int)*8-1)))
#define adif(a,b) (((a)>(b))?(a)-(b):(b)-(a))
#define dif(a,b)  (adif((((a)>>24)&255), (((b)>>24)&255))\
                  +adif((((a)>>16)&255), (((b)>>16)&255))\
                  +adif((((a)>> 8)&255), (((b)>> 8)&255)))
#define abs(a) (((a)<0)?-(a):(a))

main()
{ //pointerでないので普通に足される。
  sysinit((Uint)(2*((M1+1)*L)*sizeof(Uint)
                +L*M2*sizeof(Uint)
                +M1*M2*sizeof(Uint)
                +M1*M2*sizeof(Uint)
                +2*((M1+1)*L)*sizeof(Uint)
                +L*M2*sizeof(Uint)
                +M1*M2*sizeof(Uint)
                ),32);
  printf("membase: %08.8x\n", (Uint)membase);
  A  = (Ull*)membase;
  B  = (Uint*)((Uchar*)A  + 2*((M1+1)*L)*sizeof(Uint));
  C0 = (Uint*)((Uchar*)B  + L*M2*sizeof(Uint));
  C1 = (Uint*)((Uchar*)C0 + M1*M2*sizeof(Uint));

  A_debug = (Uint*)((Uchar*)C1 + M1*M2*sizeof(Uint));
  B_debug  = (Uint*)((Uchar*)A_debug  +2*((M1+1)*L)*sizeof(Uint));
  C_debug = (Uint*)((Uchar*)B_debug  + L*M2*sizeof(Uint));
  params = (emax6_param*) malloc(sizeof(emax6_param)*1);
  params->RMGRP_param = RMGRP;
  params->NCHIP_param = NCHIP;
  params->H_param = H;
  params->W_param= W*2;
  // params->W_param= W*2;
  printf("A : %08.8x\n", A);
  printf("B : %08.8x\n", B);
  printf("C0: %08.8x\n", C0);
  printf("C1: %08.8x\n", C1);
  int tmp = 0,num = 0;
  int* col_index_A = (int *)calloc(M1*L,sizeof(int));
  int* row_index_A = (int *)calloc(M1*L,sizeof(int));
  Uint* A_tmp = (Uint *)calloc(M1*L,sizeof(Uint));
  for (row=0; row<M1; row++) {
    for (col=0; col<L; col++){
      tmp = (int) tmp;
      tmp = (rand()%5 == 0);
      // tmp = (rand()%3 == 0)||(rand()%2);
      *(float*)&A_tmp[row+col*M2] = (float) tmp;
      *(float*)&A_debug[row*L+col] = (float) tmp;
      // floatで等価の判断するの危険なので、LIMITで0判定をしている。
      if(!((-LIMIT <= *(float*)&A_tmp[row+col*M2]) && (*(float*)&A_tmp[row+col*M2] <= LIMIT))){
          col_index_A[nnz_A] = col;
          row_index_A[nnz_A] = row;
          nnz_A += 1;
        }
    }
  }

  clock_t start,end;
  start = clock();
  A_sparse = sparse_format2(nnz_A,A,A_tmp,col_index_A,row_index_A,M1,L,params);
  end = clock();
  printf("format %.2f\n",(double)(end-start)/CLOCKS_PER_SEC);
  

//   for (row=0; row<L; row++) {
//     for (col=0; col<M2; col++){
//        tmp = rand()%2 ;
//       *(float*)&B[row*M2+col] = (float) tmp;
//       if(B[row*L+col]) nnz_B += 1; 
//     }
//   }

  for (row=0; row<L; row++) {
    for (col=0; col<M2; col++){
      float tmp = row+col;
      *(float*)&B[col*M2+row] = (float) tmp;
      *(float*)&B_debug[col*M2+row] = (float) tmp;
      // if(!((-LIMIT <= *(float*)&B[col*M2+row]) && (*(float*)&B[col*M2+row] <= LIMIT))) nnz_B += 1; 
      // if(!((-LIMIT <= *(float*)&B_debug[col*M2+row]) && (*(float*)&B_debug[col*M2+row] <= LIMIT))) nnz_B_debug += 1; 
    }
  }


    for (col=0,col1=0; col<M2/2; col+=1,col1+=2){
      for (row=0,row1=0; row1<L; row+=2,row1+=1) {
        // simdを使うため
      *(float*)&B[col*2*L+row] = *(float*)&B_debug[col1*L+row1];
      *(float*)&B[col*2*L+row+1] = *(float*)&B_debug[(col1+1)*L+row1];
    }
  }
  
    for (col=0; col<M2; col++){
      for (row=0; row<L; row++) {
        // simdを使うため
        sum += *(float*)&B_debug[col*L+row];
        sum1 += *(float*)&B[col*L+row];
    }
  }

  assert(sum == sum1);


  // sparse_multiply(A_sparse,B,C1,M2);
  // count1 = sparse_multiply_imax(A_sparse,B,C1,M2,params);
  start = clock();
  orig(A_tmp,B_debug,C0);
  end = clock();
  printf("orig %.2f\n",(double)(end-start)/CLOCKS_PER_SEC);
  // orig_simd(A_tmp,B,C1);
  start = clock();
  count1 = sparse_multiply_imax1(A_sparse,B,C1,M2,params);
  end = clock();
  printf("sparse %.2f\n",(double)(end-start)/CLOCKS_PER_SEC);
 



  for (row=0; row<M1; row++) {
    for (col=0; col<L; col++)
      *(float*)&A_debug[row*L+col] = 0.0;
  }
  for (row=0; row<L; row++) {
    for (col=0; col<M2; col++)
      *(float*)&B_debug[row*M2+col] = 0.0;
  }

  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++)
      *(float*)&C_debug[row*M1+col] = 0.0;
  }

// #if !defined(ARMSIML)
//   x11_open(0);
// #endif

  // reset_nanosec();
  // size_t Dll_size = sizeof(Dll);

  //  for (row=0; row<M1; row++) {
  //   for (col=0; col<M2; col++) {
  //     if(row*M2+col==1){
  //       printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row, col, (double)*(float*)&C0[row*M2+col],
  //                                               row, col, (double)*(float*)&C1[row+col*M1]);
  //     }
  //     if (C0[row*M2+col] != C1[row+col*M1]) {
  //       count2++;
  //       printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row, col, (double)*(float*)&C0[row*M2+col],
  //                                               row, col, (double)*(float*)&C1[row+col*M1]);
  //     }
  //   }
  // }

  // printf("count_normal %d count_sparse %d \n",count0,count1);
  // exit(1);
  
    for (col=0,col1=0; col<M2/2; col+=1,col1+=2){
      for (row=0,row1=0; row1<L; row+=2,row1+=1) {
        if ((C0[col1+row1*L] != C1[col*2*M2+row])||(C0[(col1+1)+row1*L] != C1[col*2*M2+row+1])) {
          count2++;
          printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row1, col1, (double)*(float*)&C0[col1+row1*L],
                                                  row, col*2, (double)*(float*)&C1[col*2*M2+row]);
          printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row1, col1+1, (double)*(float*)&C0[(col1+1)+row1*L],
                                                  row+1, col*2, (double)*(float*)&C1[col*2*M2+row+1]);  
          exit(1);       
      }
    }
  }

  printf("count_normal %d count_sparse %d  normal/sparse = %d\n",count0,count1,count0/count1);


  // get_nanosec(0);
  // show_nanosec();

  // reset_nanosec();

  for (row=0; row<M1; row++) {
    for (col=0; col<L; col++)
      *(Ull*)&A_debug[row*L+col] = 0.0;
  }
  for (row=0; row<L; row++) {
    for (col=0; col<M2; col++)
      *(float*)&B_debug[row*M2+col] = 0.0;
  }

  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++)
      *(float*)&C_debug[row*M1+col] = 0.0;
      *(float*)&C1[row*M1+col] = 0.0;
  }
  memset(C1, 0,sizeof(Uint)*M1*M2 );
  start = clock();
  imax_debug(A_sparse, B, C1);
  end = clock();
  printf("sparse %.2f\n",(double)(end-start)/CLOCKS_PER_SEC);
//   free(col_index_B);
  // free(A_sparse);
  // free(B);
//   free(row_index_B);
  // get_nanosec(0);
  // show_nanosec();

    for (col=0,col1=0; col<M2/2; col+=1,col1+=2){
      for (row=0,row1=0; row1<L; row+=2,row1+=1) {
        if ((C0[col1+row1*L] != C1[col*2*M2+row])||(C0[(col1+1)+row1*L] != C1[col*2*M2+row+1])) {
          count2++;
          printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row1, col1, (double)*(float*)&C0[col1+row1*L],
                                                  row, col*2, (double)*(float*)&C1[col*2*M2+row]);
          printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row1, col1+1, (double)*(float*)&C0[(col1+1)+row1*L],
                                                  row+1, col*2, (double)*(float*)&C1[col*2*M2+row+1]);  
          exit(1);       
      }
    }
  }
  
exit(1);



#ifdef ARMSIML
  copy_Z(0, C1); _copyX(0, Z);
  copy_Z(1, C1); _copyX(1, Z);
  copy_Z(4, C1); _copyX(4, Z);
  copy_Z(5, C1); _copyX(5, Z);
  copy_Z(8, C1); _copyX(8, Z);
  copy_Z(9, C1); _copyX(9, Z);
  _updateX();
#endif
#if !defined(ARMSIML)
  copy_Z(0, C1); BGR_to_X(0, Z);
  copy_Z(1, C1); BGR_to_X(1, Z);
  copy_Z(4, C1); BGR_to_X(5, Z);
  copy_Z(5, C1); BGR_to_X(6, Z);
  copy_Z(8, C1); BGR_to_X(10,Z);
  copy_Z(9, C1); BGR_to_X(11,Z);
  x11_update();
#endif

  printf("Num of MULT: orig=%d imax=%d\n", count0, count1);

  if (count2)
    printf("Num of diffs: %d\n", count2);
  else
    printf("Results are equal\n");

  show_nanosec();

#if !defined(ARMSIML)
  printf("==== Normal end. Type any in ImageWin ====\n");
  while (!x11_checkevent());
#endif
}


 


copy_Z(id, from)
     int id; /* 0 .. 11 */
     unsigned int *from;
{
  int i, j;
  volatile unsigned int *to = Z;
  unsigned int *offs;

  switch (id) {
  case 0:  offs = from;               break;
  case 1:  offs = from + WD;          break;
  case 2:  offs = from + WD*2;        break;
  case 3:  offs = from + WD*3;        break;
  case 4:  offs = from + M2*HT;        break;
  case 5:  offs = from + M2*HT+WD;     break;
  case 6:  offs = from + M2*HT+WD*2;   break;
  case 7:  offs = from + M2*HT+WD*3;   break;
  case 8:  offs = from + M2*HT*2;      break;
  case 9:  offs = from + M2*HT*2+WD;   break;
  case 10: offs = from + M2*HT*2+WD*2; break;
  case 11: offs = from + M2*HT*2+WD*3; break;
  case 12: offs = from + M2*HT*3;      break;
  case 13: offs = from + M2*HT*3+WD;   break;
  case 14: offs = from + M2*HT*3+WD*2; break;
  case 15: offs = from + M2*HT*3+WD*3; break;
  }
  for (i=0; i<HT; i++, offs+=M2) {
    if (offs<from+M1*M2) {
      for (j=0; j<WD; j++) {
	if (j+(id%4)*WD<M2) *to++ = (*(offs+j))>>0;
	else                *to++ = 0;
      }
    }
    else {
      for (j=0; j<WD; j++)
	*to++ = 0;
    }
  }
}

orig(Uint* A_orig,Uint* B_orig,Uint* C_orig) {
  printf("<<<ORIG>>>\n");
  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++) {
      for (n=0; n<L; n++) {
        if (n==0) *(float*)&C_orig[row*M2+col]  = *(float*)&A_orig[row+n*M1] * *(float*)&B_orig[n+col*L];
        else      *(float*)&C_orig[row*M2+col] += *(float*)&A_orig[row+n*M1] * *(float*)&B_orig[n+col*L];
        count0++;
        /*printf("[%d %d %d]", row, col, n);*/
      }
      /*printf("\n");*/
    }
  }
}


//watch (row*M2+col1)>M1*M2
//watch (row+n*M1) > M1*L
// watch (n1+col*(2*L)) > M2*L
// watch (n1+1+col*(2*L)) > M2*L
orig_simd(Uint* A_orig_simd,Uint* B_orig_simd,Uint* C_orig_simd) {
  printf("<<<ORIG_simd>>>\n");
  for (row=0; row<M1; row++) {
    for (col=0,col1=0; col<M2/2; col++,col1+=2) {
      for (n=0,n1=0; n<L; n+=1,n1+=2) {
        // printf("n %d  n1 %d  col %d col1 %d row %d\n",n,n1,col,col1,row);
        assert(((row*M2+col1)<M1*M2));
        assert((row+n*M1) < M1*L);
        assert((n1+col*(2*L)) <M2*L);
        assert((n1+1+col*(2*L)) < M2*L);
        if (n==0) {
          *(float*)&C_orig_simd[row*M2+col1]  = *(float*)&A_orig_simd[row+n*M1] * *(float*)&B_orig_simd[n1+col*(2*L)];
          *(float*)&C_orig_simd[row*M2+col1+1]  = *(float*)&A_orig_simd[row+n*M1] * *(float*)&B_orig_simd[n1+1+col*(2*L)];
        }
        else{      
          *(float*)&C_orig_simd[row*M2+col1]  += *(float*)&A_orig_simd[row+n*M1] * *(float*)&B_orig_simd[n1+col*(2*L)];
          *(float*)&C_orig_simd[row*M2+col1+1]  += *(float*)&A_orig_simd[row+n*M1] * *(float*)&B_orig_simd[n1+1+col*(2*L)];
        }  
        count0++;

        /*printf("[%d %d %d]", row, col, n);*/
      }
      /*printf("\n");*/
    }
  }
}

#if 0
imax() {
  Ull CHIP;
  Ull rofs;
  printf("<<<IMAX>>>\n");
  for (top=0; top<M1/NCHIP; top+=RMGRP) { /* will be parallelized by multi-chip (M/#chip) */
    for (blk=0; blk<L; blk+=H) { /* 3重ループ目 (Cが確定するまでのDMA入れ換えはR/Wを伴うためオーバヘッドになる. Bのbroadcast回数を増やす方が結果的に高速) */
/*3*/ for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
  /*2*/ for (rofs=0; rofs<RMGRP; rofs++) { /* will be parallelized by multi-chip (M/#chip) */
          /*【3重ループ制御方法】                                                                                                                                                              */
          /*    loop0-reg 4           4           4           4           4           4           4           4           4           4           4           4           4                    */
          /*                 3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  - (stop1=1)       */
          /*    loop1-reg 4                                               4                                               4                                               4                    */
          /*                          3           2           1           0           3           2           1           0           3           2           1           0                    */
          /*    loop2-reg 3                                                                                                                                               3                    */
          /*                                                              2                                               1                                               0                    */
          /*                                                                                                                                                   【★Ａ★】 ↑arbrk=1(停止)      */
          /*                ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex ex --------- */
          /*        loop0    0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  0  1  2  3  - (stop1=1)       */
          /*        loop1    0  0  0  0  1  1  1  1  2  2  2  2  3  3  3  3  0  0  0  0  1  1  1  1  2  2  2  2  3  3  3  3  0  0  0  0  1  1  1  1  2  2  2  2  3  3  3  3                    */
          /*        loop2    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  2  2  2  2  2  2  2  2  2  2  2  2  2  2  2  2                    */

          /*【★Ａ★】部分の拡大              0         1         2         3      |  0         1         2         3      |  0         1         2         3      |  0                        */
          /*                 unit1 clk  ___/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____                  */
          /*                   stage1d  ----< loop0=2 X loop1=1 X loop2=1 X ======= X loop0=1 X loop1=1 X loop2=1 X ======= X loop0=4★-----------------------------X loop0=3                  */
          /*                                                                                                                  init0=1★                            |                           */
          /*                   stage2d  --------------< 0nzero  X nop     X nop     X ======= X 0zero★ X 1zero★ X 2zero★ X ======= >--------------------------------------                  */
          /*                                                                                                ↑        ↑                                           |                           */
          /*                                                                                           前cycle:zeroの場合decr                                      |                           */
          /*                   stage3d  ------------------------< loop0=1 X loop1=1 X loop2=1 X ======= X loop0=0 X loop1=0 X lop2=0★X ======= X loop0=3 >------------------                  */
          /*                                                                                                            ↑stage1dに戻る                            |                           */
          /*                                                                                                            │この時0ならstage1dにinit0=1を通知.stage1dに初期値をBRからセット      */
          /*                                                                                                            │init0=1は下方(BR)に伝搬                  |                           */
          /*                   stage4d  ----------------------------------< loop0=1 X loop1=1 X loop2=1 X ======= X loop0=0 X lop1=0  X lop2=0★X ======= X loop0=3 >--------       init0=1が  */
          /*                                                                                                                                                init0=1|              │次段unitへ */
          /*                                                                                                                                                       |stop1=1       ↓           */
          /*                                  0         1         2         3      |  0         1         2         3      |  0         1         2         3      |  0        stage1dに初期値 */
          /*                 unit2 clk  ___/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____/~~~~\____                  */
          /*                                                                                                          ★OP_WHILEが存在  かつ zeroの場合にarbrk=1セット★                       */
          /*                【3重ループのパターン】                                                       ★col=0から順に調べ nonzeroの場合はarbrk=0に戻す★                                   */
          /*                                     col2=0  col1=0  col0=0                                                                                                                        */
          /*                                       ↓      ↓      ↓     DMA以外のレジスタ値設定を自動化                                                                                      */
          /*                                     arbrk=1 init1=1 init0=1  受信したら初期値再セット                                                                                             */
          /*                                                   0       1                                                                                                                       */
          /*                                                   1       0                                                                                                                       */
          /*                                                   1       1                                                                                                                       */
          /*                                           1       X       X  IMAX終了                                                                                                             */
          /*                                                                                                                                                                                   */
          /*                【2重ループのパターン】      col1=0  col0=0                                                                                                                        */
          /*                                               ↓      ↓     DMA以外のレジスタ値設定を自動化                                                                                      */
          /*                                             arbrk=1 init0=1  受信したら初期値再セット                                                                                             */
          /*                                                   0       1  A先頭はA[0][0]からA[1][0]に変更（480x4B加算）                                                                        */
          /*                                                              B先頭は元に戻す(ofs=-Wx4に戻す:実際にはselfloopを一度解除しBRから入力するだけ)                                       */
          /*                                                              RANGEは60行x480列x4B=115200を加算(lenは無変更)                                                                       */
          /*                                                                exe(OP_ADD, &ofs, ★INIT0, ofs, EXP_H3210, W*4, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);              */
          /*                                                                                            ↑Cの記述はそのまま.IMAXではBRに初期値が残っているので利用                             */
          /*                                                                mop(OP_LDUWR,  1, &BR[1][0][1],  ★(Ull)b000, (Ull)ofs, MSK_D0, ★(Ull)b00, M/2, 0, 0, (Ull)NULL, M/2);            */
          /*                                                                                            ↑Cの記述はそのまま.2重ループの範囲では増分指定不要                                    */
          /*                                                   1       X  IMAX終了                                                                                                             */

          /*【3重ループ参照パターン】                                                                                                                                                          */
          /* a0000 a0001 a0002 a0003 a0004 ... a0059 | a0060 a0061 ... *//* LMM[ 0] b0000 b0001 b0002 b0003 b0004 ... b0059 b0099 ... *//* partial c0000 c0001 c0002 c0003 c0004 ... c0099 ... */
          /* a0100 a0101 a0102 a0103 a0104 ... a0159 | a0160 a0161 ... *//* LMM[ 1] b0100 b0101 b0102 b0103 b0104 ... b0159 b0199 ... *//* partial c0100 c0101 c0102 c0103 c0104 ... c0199 ... */
          /* a0200 a0201 a0202 a0203 a0204 ... a0259 | a0260 a0261 ... *//* LMM[ 2] b0200 b0201 b0202 b0203 b0204 ... b0259 b0299 ... *//* partial c0200 c0201 c0202 c0203 c0204 ... c0299 ... */
          /* a0300 a0301 a0302 a0303 a0304 ... a0359 | a0360 a0361 ... *//* LMM[ 3] b0300 b0301 b0302 b0303 b0304 ... b0359 b0399 ... *//* partial c0300 c0301 c0302 c0303 c0304 ... c0399 ... */
          /*                                                           *//* LMM[59] b5900 b5901 b5902 b5903 b5904 ... b5959 b5999 ... *//*                                                     */
          /*                                                           *//* --------------------------------------------------------- *//*                                                     */
          /* a9900 a9901 a9902 a9903 a9904 ... a9959 | a9960 a9961 ... *//* LMM[99] b9900 b9901 b9902 b9903 b9904 ... b9959 b9999 ... *//* partial c9900 c9901 c9902 c9903 c9904 ... c9999 ... */

          /*【3重ループ実行手順】                                                                                                                                                              */
          /* ================================== 3重ループ開始 ================================================================================================================================ */
          /*   LMM00: A[0:7][0:479] (必要なのはa000000,001000,...007000) 480x8x4B=16KB | B[00][0:479] 480x4B=2KB                                                                               */
          /*                                   a000060,001060,...007060                |                                                                                                       */
          /*                                   a000420,001420,...007420                |                                                                                                       */
          /*   LMM01: A[0:7][0:479] (必要なのはa000001,001001,...007001)               | B[01][0:479] 480x4B=2KB                                                                               */
          /*                                   a000061,001061,...007061                |                                                                                                       */
          /*                                   a000421,001421,...007421                |                                                                                                       */
          /*   LMM59: A[0:7][0:479] (必要なのはa000059,001059,...007059) 8要素         | B[59][0:479] 480x4B=2KB                                                                               */
          /*                                   a000119,001119,...007119  8要素         |                                                                                                       */
          /*                                   a000479,001479,...007479  8要素x8blk分  |                                                                                                       */
          /*   LMM60: ---------------------------------------------------------------------------------------- C[0:7][0:479] 480x8x4B=16KB  Cの途中結果をR/Wで入れ換えるのは損                 */
          /*                                                                                                   multi-chipに対するR/Wがシリアライズされるし,LMMのREADは遅いので回数を減らすべき */
          /* ★RANGE設定,A[0:7][0:479]を一度に供給                                                                                           ★RANGE設定,C[0:7][*]初期化書き込み               */
          /* ================================== 3重ループ先頭開始 BLK=0======================================================================================================================= */
          /*                                                                        ★BのREGV+RANGEを設定,次のB[  0: 59]を1回のburstで供給(MC-broadcast)                                       */
          /* ---------------------------------- 2重ループIMAX開始 --3重loopのblk-iteration-- 1回目 (blk=0)                            *//*                                                     */
          /* A[0][  0: 59]->LMMを再利用                                *//*   row= 0: B[  0][*]:480*4B=2KB /LMM(1/2) b00=B+(blk+ 0)*M *//*  row=0: C[0][*]:480*4B=2KB / LMM┐                  */
          /* A[1][  0: 59]->LMMを再利用                                *//*   row= 1: B[  1][*]:480*4B=2KB /LMM(1/2) b01=B+(blk+ 1)*M *//*  row=1: C[1][*]:480*4B=2KB / LMM│合計16KBは実際は  */
          /* A[7][  0: 59]->LMMを再利用                                *//*   row=59: B[ 59][*]:480*4B=2KB /LMM(1/2) b59=B+(blk+59)*M *//*  row=7: C[7][*]:480*4B=2KB / LMM┘1LMMに収容可能    */
          /* ---------------------------------- IMAX動作一旦終了 ----------------------------------------------------------------------------------------------------------------------------- */
          /*                                                                        ★BのREGV+RANGEを設定,次のB[ 60:119]を1回のburstで供給(MC-broadcast)                                       */
          /* ---------------------------------- 2重ループIMAX開始 --3重loopのblk-iteration-- 2回目 (blk=1)   B[0]とB[60]の距離は480*60*4B(128KB),LMM共存無理                                   */
          /* A[0][ 60:119]->LMMを再利用                                *//*   row= 0: B[ 60][*]:480*4B=2KB /LMM(1/2) b00+=(H-1)*M*4B  *//*  row=0: C[0][*]:480*4B=2KB / LMM (update)           */
          /* A[1][ 60:119]->LMMを再利用                                *//*   row= 1: B[ 61][*]:480*4B=2KB /LMM(1/2) b01+=(H-1)*M*4B  *//*  row=1: C[1][*]:480*4B=2KB / LMM (update)           */
          /* A[7][ 60:119]->LMMを再利用                                *//*   row=59: B[119][*]:480*4B=2KB /LMM(1/2) b59+=(H-1)*M*4B  *//*  row=7: C[7][*]:480*4B=2KB / LMM (update)           */
          /* ---------------------------------- IMAX動作一旦終了 ----------------------------------------------------------------------------------------------------------------------------- */
          /*                                                                        ★BのREGV+RANGEを設定,次のB[420:479]を1回のburstで供給(MC-broadcast)                                       */
          /* ---------------------------------- 2重ループIMAX開始 --3重loopのblk-iteration-- 8回目 (blk=7)                            *//*                                                     */
          /* A[0][420:479]->LMMを再利用                                *//*   row= 0: B[420][*]:480*4B=2KB /LMM(1/2) b00+=(H-1)*M*4B  *//*  row=0: C[0][*]:480*4B=2KB / LMM (update)           */
          /* A[1][420:479]->LMMを再利用                                *//*   row= 1: B[421][*]:480*4B=2KB /LMM(1/2) b01+=(H-1)*M*4B  *//*  row=1: C[1][*]:480*4B=2KB / LMM (update)           */
          /* A[7][420:479]->LMMを再利用                                *//*   row=59: B[479][*]:480*4B=2KB /LMM(1/2) b59+=(H-1)*M*4B  *//*  row=7: C[7][*]:480*4B=2KB / LMM (update)           */
          /* ---------------------------------- IMAX動作一旦終了 ----------------------------------------------------------------------------------------------------------------------------- */
          /* ================================== 3重ループ全体終了 ============================================================================================================================ */
          /* ★A[8:15][0:479]を一度に供給                                                                                                    ★RANGE設定,C[0:7][*]READ+C[8:15][*]WRITE         */
          /* ================================== 3重ループ先頭開始 BLK=0======================================================================================================================= */
          /*                                                                        ★BのREGV+RANGEを設定,次のB[  0: 59]を1回のburstで供給(MC-broadcast)                                       */
          /* ---------------------------------- 2重ループIMAX開始 --3重loopのblk-iteration-- 1回目 (blk=0)                            *//*                                                     */
          /* A[ 8][  0: 59]->LMMを再利用                               *//*   row= 0: B[  0][*]:480*4B=2KB /LMM(1/2) b00=B+(blk+ 0)*M *//*  row=0: C[ 8][*]:480*4B=2KB / LMM┐                 */
          /* A[ 9][  0: 59]->LMMを再利用                               *//*   row= 1: B[  1][*]:480*4B=2KB /LMM(1/2) b01=B+(blk+ 1)*M *//*  row=1: C[ 9][*]:480*4B=2KB / LMM│合計16KBは実際は */
          /* A[15][  0: 59]->LMMを再利用                               *//*   row=59: B[ 59][*]:480*4B=2KB /LMM(1/2) b59=B+(blk+59)*M *//*  row=7: C[15][*]:480*4B=2KB / LMM┘1LMMに収容可能   */

    /*1*/ for (col=0; col<M2; col+=W) { /* one-horizontal-line is calculated by EMAX-while(loop--) */
                                        /* C0xの部分和を生成（1行分）1chip分の総量はMword*M/#chip  */
                                        /*                          M=504の場合は64Kword(256KB)    */
                                        /*      さらにchip内でも行を分割すればcsimLMM(128KB)に入る */
            for (w=0; w<W; w++) {   /* horizontal (parallel) execution */
              for (h=0; h<H; h++) { /* vertical (pipelined) execution */
                if (blk == 0 && h == 0)
                  *(float*)&C1[(CHIP*M1/NCHIP+top+rofs)*M2+col+w]  = *(float*)&A[(CHIP*M1/NCHIP+top+rofs)*L+blk+h]**(float*)&B[(blk+h)*M2+col+w];
                else
                  *(float*)&C1[(CHIP*M1/NCHIP+top+rofs)*M2+col+w] += *(float*)&A[(CHIP*M1/NCHIP+top+rofs)*L+blk+h]**(float*)&B[(blk+h)*M2+col+w];
                count1++;
                /*printf("[%d %d %d %d %d %d %d]", CHIP, top, rofs, blk, col, w, h);*/
              }
            }
            /*printf("\n");*/
          }
        }
      }
    }
  }
}

#else


void imax_debug(const emax6_sparse1* const A_sparse,const Uint* const B, Uint* C1) {
  Ull  CHIP;
  Ull  LOOP1, LOOP0;
  Ull  INIT1, INIT0;
  Ull  AR[64][4];                     /* output of EX     in each unit */
  Ull  BR[64][4][4];                  /* output registers in each unit */
  Ull  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
  Ull  r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
  Ull  cc0, cc1, cc2, cc3, ex0, ex1;
  Ull  cofs, rofs, oofs, k;
  Uint blk_iter,A_margin_tmp;
  Ull* A_margin = A_sparse->margin;
  Ull* val_index_set = A_sparse->val_index_set;
  Uint* A_sort_index= A_sparse->sort_index;
  Ull A_row_size = M1;
  Ull A_col_size = L;
  Ull B_row_size = L;
  Ull B_col_size = M2;


  /*  ┌─────┐convolutionの場合                                                  */
  /*  │┌────┴┐Bが複数と考える                                                  */
  /*  ││┌────┴┐┌─────┐┐        ┌─────┐┐                       */
  /*  │││b         ││a a a a a ││RMGRP   │o o o o o ││RMGRP                  */
  /*  │││b         ┤│          │┤/CHIP   │          │┤/CHIP                  */
  /*  │││b   B0   b││ A(weight)││        │   out    ││ mmの場合は行で分割    */
  /*  └││b        l┤│          │┤        │          │┤ cnnの場合はoutで分割  */
  /*    └│b        k││blk       ││        │blk       ││                       */
  /*      └─────┘└─┴─┴─┘┘        └─┴─┴─┘┘                       */
  printf("<<<IMAX>>>\n");
  for (top=0; top<B_col_size/NCHIP; top+=RMGRP) {
    for (blk=0,blk_iter=0; blk<A_col_size; blk+=H,blk_iter+=1) { /* 3重ループ展開の外側対象 */
      if((A_margin_tmp=A_margin[blk_iter])==0) break;
      typedef struct {Uint i[8]} Ui8;
      Uint *a[H+1],*a_debug[H+1];
      Ui8  *b[NCHIP], *b0[NCHIP], *b1[NCHIP], *b2[NCHIP], *b3[NCHIP];
      Ui8  *b_debug[NCHIP], *b0_debug[NCHIP], *b1_debug[NCHIP], *b2_debug[NCHIP], *b3_debug[NCHIP];
      Ui8  *c0[NCHIP],*c0_debug[NCHIP];
      Ui8  *c00[NCHIP], *c01[NCHIP], *c02[NCHIP], *c03[NCHIP];
      Ui8  *c00_debug[NCHIP], *c01_debug[NCHIP], *c02_debug[NCHIP], *c03_debug[NCHIP];
      for (CHIP=0; CHIP<NCHIP; CHIP++) { 
      
        b[CHIP] = B+(CHIP*B_col_size/NCHIP+top)*B_row_size;
        b_debug[CHIP] = B_debug+(CHIP*B_col_size/NCHIP+top)*B_row_size;
        b0[CHIP] = b[CHIP]+0; b1[CHIP] = (Uint*)b[CHIP]+B_row_size*2; b2[CHIP] = (Uint*)b[CHIP]+B_row_size*4;  b3[CHIP] = (Uint*)b[CHIP]+B_row_size*6; 
        b0_debug[CHIP] = b_debug[CHIP]+0; b1_debug[CHIP] = (Uint*)b_debug[CHIP]+B_row_size*2; b2_debug[CHIP] = (Uint*)b_debug[CHIP]+B_row_size*4;  b3_debug[CHIP] = (Uint*)b_debug[CHIP]+B_row_size*6; 


        c0[CHIP] = C1+(CHIP*A_col_size/NCHIP+top)*B_row_size;
        c0_debug[CHIP] = C1+(CHIP*A_col_size/NCHIP+top)*B_row_size;
        c00[CHIP]= (Uint*)c0[CHIP]+0; c01[CHIP] = (Uint*)c0[CHIP]+A_row_size*2; c02[CHIP] = (Uint*)c0[CHIP]+A_row_size*4; c03[CHIP] = (Uint*)c0[CHIP]+A_row_size*6;
        c00_debug[CHIP] = (Uint*)c0_debug[CHIP]+0; c01_debug[CHIP] = (Uint*)c0_debug[CHIP]+A_row_size*2; c02_debug[CHIP] = (Uint*)c0_debug[CHIP]+A_row_size*4; c03_debug[CHIP] = (Uint*)c0_debug[CHIP]+A_row_size*6;
    
      }
      // little edianで格納 big <- <- <- <- small 右から左に流れていく
      //ex 64bit *((Ull*)&offset2)  11000000000000000000000000000000000   
      //   32bit *((Uint*)&offset2) -> 0    *((Uint*)&offset2+1) -> 1
      //   8bit  *((char*)&offset2+1) -> 0   *((char*)&offset2+2) -> 0 *((char*)&offset2+3) -> 0 *((char*)&offset2+4) -> 110
      // Ullで扱うときは *((Ull*)&offset2)>>32は*((Uint*)&offset2+1)を取得しているのと等価
      // https://hackaday.com/2020/08/04/dont-let-endianness-flip-you-around/
      //https://www.bogotobogo.com/Embedded/Little_endian_big_endian_htons_htonl.php
      //p *(float*)((Uint*)b[0]+6) 一つ目の値 3
      //>>> p/f  *((Uint*)&BR[2][0][1])
    // $17 = 3
    // >>> p/f  *((Uint*)&BR[2][0][1]+1)
    // $18 = 4
    //UllのA_row_size*2
    // rofs=(0-(Ull)1*8)<<32|((0-(Ull)1*4)&0xffffffff) マスクを使って2パターン使用している
      for (k=0; k<H+1; k++) a[k] = (Uint*)val_index_set+(blk+k)*A_row_size*2;
      for (k=0; k<H+1; k++) a_debug[k]= (Uint*)A_debug+(blk+k)*A_row_size*2;
#define sgemm00_core1(r, rm1,rp1) \
	    mo2(OP_LDR,  3, &BR[r][0][1],  (Ull)b0[CHIP], (Ull)cofs,(Ull)BR[rm1][2][0], MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mo2(OP_LDR,  3, &BR[r][0][0],  (Ull)b1[CHIP], (Ull)cofs,(Ull)BR[rm1][2][0], MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mo2(OP_LDR,  3, &BR[r][1][1],  (Ull)b2[CHIP], (Ull)cofs,(Ull)BR[rm1][2][0], MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mo2(OP_LDR,  3, &BR[r][1][0],  (Ull)b3[CHIP], (Ull)cofs,(Ull)BR[rm1][2][0], MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mo2(OP_LDWR, 1, &BR[r][2][1],  (Ull)a[rm1],  (Ull)rofs,(Ull)0, MSK_W1, (Ull)a[rm1], A_row_size*2, 0, 0, (Ull)NULL, A_row_size*2);\
	    mo2(OP_LDR,  3, &BR[r][2][0],  (Ull)a[rm1],  (Ull)rofs,(Ull)0, MSK_W1, (Ull)a[rm1], A_row_size*2, 0, 0, (Ull)NULL, A_row_size*2);\
      mop2_debug(OP_LDR,  3, &BR[r][0][1],  (Ull)b0_debug[CHIP], (Ull)cofs,(Ull)BR[rm1][2][0], MSK_W1, (Ull)b_debug[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
	    mop2_debug(OP_LDR,  3, &BR[r][0][0],  (Ull)b1_debug[CHIP], (Ull)cofs,(Ull)BR[rm1][2][0], MSK_W1, (Ull)b_debug[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
	    mop2_debug(OP_LDR,  3, &BR[r][1][1],  (Ull)b2_debug[CHIP], (Ull)cofs,(Ull)BR[rm1][2][0], MSK_W1, (Ull)b_debug[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
	    mop2_debug(OP_LDR,  3, &BR[r][1][0],  (Ull)b3_debug[CHIP], (Ull)cofs,(Ull)BR[rm1][2][0], MSK_W1, (Ull)b_debug[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
	    mop2_debug(OP_LDR,  3, &BR[r][2][1],  (Ull)a_debug[rm1], (Ull)rofs,(Ull)0, MSK_W1, (Ull)a_debug[rm1], A_row_size*2, 0, 0, (Ull)NULL, A_row_size*2);\
      exe(OP_FMA, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[rp1][2], AR[r][2], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[rp1][3], AR[r][3], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL)

#define sgemm00_core2(r, rm1,rp1) \
	    mo2(OP_LDR,  3, &BR[r][0][1],  (Ull)b0[CHIP], (Ull)cofs,(Ull)BR[rm1][2][0], MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mo2(OP_LDR,  3, &BR[r][0][0],  (Ull)b1[CHIP], (Ull)cofs,(Ull)BR[rm1][2][0], MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mo2(OP_LDR,  3, &BR[r][1][1],  (Ull)b2[CHIP], (Ull)cofs,(Ull)BR[rm1][2][0], MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mo2(OP_LDR,  3, &BR[r][1][0],  (Ull)b3[CHIP], (Ull)cofs,(Ull)BR[rm1][2][0], MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mo2(OP_LDWR, 1, &BR[r][2][1],  (Ull)a[rm1],   (Ull)rofs,(Ull)0, MSK_W1, (Ull)a[rm1], A_row_size*2, 0, 0, (Ull)NULL, A_row_size*2);\
	    mo2(OP_LDWR, 1, &BR[r][2][0],  (Ull)A_sort_index,  (Ull)rofs,(Ull)0, MSK_W0,(Ull)A_sort_index,A_row_size*2, 0, 0, (Ull)NULL, A_row_size*2);\
      mop2_debug(OP_LDR,  3, &BR[r][0][1],  (Ull)b0_debug[CHIP], (Ull)cofs, MSK_W1,(Ull)BR[rm1][2][0], (Ull)b_debug[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
	    mop2_debug(OP_LDR,  3, &BR[r][0][0],  (Ull)b1_debug[CHIP], (Ull)cofs, MSK_W1,(Ull)BR[rm1][2][0], (Ull)b_debug[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
	    mop2_debug(OP_LDR,  3, &BR[r][1][1],  (Ull)b2_debug[CHIP], (Ull)cofs, MSK_W1,(Ull)BR[rm1][2][0], (Ull)b_debug[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
	    mop2_debug(OP_LDR,  3, &BR[r][1][0],  (Ull)b3_debug[CHIP], (Ull)cofs, MSK_W1,(Ull)BR[rm1][2][0], (Ull)b_debug[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
	    mop2_debug(OP_LDR,  3, &BR[r][2][1],  (Ull)a_debug[rm1],  (Ull)rofs,(Ull)0, MSK_W1, (Ull)a_debug[rm1], A_row_size*2, 0, 0, (Ull)NULL, A_row_size*2);\
	    exe(OP_FMA, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[rp1][2], AR[r][2], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[rp1][3], AR[r][3], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL)

#define sgemm00_final(r,r1,rp1) \
	    mo2(OP_LDR,  3, &BR[rp1][0][1],  (Ull)c00[CHIP], (Ull)cofs,(Ull)BR[r1][2][0], MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mo2(OP_LDR,  3, &BR[rp1][1][1],  (Ull)c01[CHIP], (Ull)cofs,(Ull)BR[r1][2][0], MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mo2(OP_LDR,  3, &BR[rp1][2][1],  (Ull)c02[CHIP], (Ull)cofs,(Ull)BR[r1][2][0], MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mo2(OP_LDR,  3, &BR[rp1][3][1],  (Ull)c03[CHIP], (Ull)cofs,(Ull)BR[r1][2][0], MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
      mop2_debug(OP_LDR,  3, &BR[rp1][0][1],  (Ull)c00_debug[CHIP], (Ull)cofs,(Ull)BR[r1][2][0], MSK_W0, (Ull)c0_debug[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop2_debug(OP_LDR,  3, &BR[rp1][1][1],  (Ull)c01_debug[CHIP], (Ull)cofs,(Ull)BR[r1][2][0], MSK_W0, (Ull)c0_debug[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop2_debug(OP_LDR,  3, &BR[rp1][2][1],  (Ull)c02_debug[CHIP], (Ull)cofs,(Ull)BR[r1][2][0], MSK_W0, (Ull)c0_debug[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop2_debug(OP_LDR,  3, &BR[rp1][3][1],  (Ull)c03_debug[CHIP], (Ull)cofs,(Ull)BR[r1][2][0], MSK_W0, (Ull)c0_debug[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    exe(OP_FAD, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[rp1][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[rp1][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[rp1][2], AR[r][2], EXP_H3210,  BR[rp1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[rp1][3], AR[r][3], EXP_H3210,  BR[rp1][3][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mo2(OP_STR, 3, &AR[rp1][0], (Ull)c00[CHIP], (Ull)BR[r1][2][0], (Ull)cofs, MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mo2(OP_STR, 3, &AR[rp1][1], (Ull)c01[CHIP], (Ull)BR[r1][2][0], (Ull)cofs, MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mo2(OP_STR, 3, &AR[rp1][2], (Ull)c02[CHIP], (Ull)BR[r1][2][0], (Ull)cofs, MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mo2(OP_STR, 3, &AR[rp1][3], (Ull)c03[CHIP], (Ull)BR[r1][2][0], (Ull)cofs, MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
      mop2_debug(OP_STR, 3, &AR[rp1][0], (Ull)c00_debug[CHIP], (Ull)BR[r1][2][0],  (Ull)cofs, MSK_W0, (Ull)c0_debug[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop2_debug(OP_STR, 3, &AR[rp1][1], (Ull)c01_debug[CHIP], (Ull)BR[r1][2][0],  (Ull)cofs, MSK_W0, (Ull)c0_debug[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop2_debug(OP_STR, 3, &AR[rp1][2], (Ull)c02_debug[CHIP], (Ull)BR[r1][2][0],  (Ull)cofs, MSK_W0, (Ull)c0_debug[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop2_debug(OP_STR, 3, &AR[rp1][3], (Ull)c03_debug[CHIP], (Ull)BR[r1][2][0],  (Ull)cofs, MSK_W0, (Ull)c0_debug[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP)


//EMAX5A begin mm mapdist=0
/*3*/ for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
  /*2*/ for (INIT1=1,LOOP1=A_margin_tmp,rofs=(0-(Ull)1*8)<<32|((0-(Ull)1*4)&0xffffffff); LOOP1--; INIT1=0) { /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
    /*1*/ for (INIT0=1,LOOP0=RMGRP/(W*2),cofs=(0-W*4*2*B_row_size)<<32|((0-W*4*2*B_row_size)&0xffffffff); LOOP0--; INIT0=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
            exe(OP_ADD,    &cofs, INIT0?cofs:cofs, EXP_H3210, (W*4*2*B_row_size)<<32|(W*4*2*B_row_size), EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */
            exe(OP_ADD,    &rofs, rofs, EXP_H3210, INIT0?((Ull)1*8)<<32|((Ull)1*4):0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */

            mo2(OP_LDR,3, &BR[1][2][0],  (Ull)a[0], (Ull)rofs,(Ull)0, MSK_W1, (Ull)a[0], A_row_size*2, 0, 0, (Ull)NULL, A_row_size*2);             /* stage#1 */
            mop2_debug(OP_LDR,1, &BR[1][2][0],  (Ull)a_debug[0],(Ull)rofs,(Ull)0, MSK_W1, (Ull)a_debug[0], A_row_size*2, 0, 0, (Ull)NULL, A_row_size*2);             /* stage#1 */

            mo2(OP_LDR,  3, &BR[2][0][1],  (Ull)b0[CHIP], (Ull)cofs,(Ull)BR[1][2][0], MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mo2(OP_LDR,  3, &BR[2][0][0],  (Ull)b1[CHIP], (Ull)cofs,(Ull)BR[1][2][0], MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mo2(OP_LDR,  3, &BR[2][1][1],  (Ull)b2[CHIP], (Ull)cofs,(Ull)BR[1][2][0], MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mo2(OP_LDR,  3, &BR[2][1][0],  (Ull)b3[CHIP], (Ull)cofs,(Ull)BR[1][2][0], MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 2KB */
            mo2(OP_LDWR, 1, &BR[2][2][1],  (Ull)a[1],        (Ull)rofs,(Ull)0,           MSK_W1, (Ull)a[1],      A_row_size*2,         0, 0, (Ull)NULL, A_row_size*2); /* stage#2 16KB */
            mo2(OP_LDR,  3, &BR[2][2][0],  (Ull)a[1],        (Ull)rofs,(Ull)0,           MSK_W1, (Ull)a[1],      A_row_size*2,         0, 0, (Ull)NULL, A_row_size*2); /* stage#2 16KB */
            mop2_debug(OP_LDR,  3, &BR[2][0][1],  (Ull)b0_debug[CHIP], (Ull)cofs,(Ull)BR[1][2][0], MSK_W1, (Ull)b_debug[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop2_debug(OP_LDR,  3, &BR[2][0][0],  (Ull)b1_debug[CHIP], (Ull)cofs,(Ull)BR[1][2][0], MSK_W1, (Ull)b_debug[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop2_debug(OP_LDR,  3, &BR[2][1][1],  (Ull)b2_debug[CHIP], (Ull)cofs,(Ull)BR[1][2][0], MSK_W1, (Ull)b_debug[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop2_debug(OP_LDR,  3, &BR[2][1][0],  (Ull)b3_debug[CHIP], (Ull)cofs,(Ull)BR[1][2][0], MSK_W1, (Ull)b_debug[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 2KB */
            mop2_debug(OP_LDWR, 3, &BR[2][2][1],  (Ull)a_debug[1], (Ull)rofs, (Ull)0, MSK_W1, (Ull)a_debug[1], A_row_size*2, 0, 0, (Ull)NULL, A_row_size*2); /* stage#2 16KB */

            exe(OP_FML, &AR[3][0], BR[2][0][1], EXP_H3210,  BR[2][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[3][1], BR[2][0][0], EXP_H3210,  BR[2][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[3][2], BR[2][1][1], EXP_H3210,  BR[2][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[3][3], BR[2][1][0], EXP_H3210,  BR[2][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */

//C0[10][0]=55257.000000 C1[20][0]=54495.000000
      
	    sgemm00_core1(3,  2,  4);
	    sgemm00_core1(4,  3,  5);
	    sgemm00_core1(5,  4,  6);
	    sgemm00_core1(6,  5,  7);
	    sgemm00_core1(7,  6,  8);                     
	    sgemm00_core1(8,  7,  9);
	    sgemm00_core1(9,  8,  10);
	    sgemm00_core1(10, 9,  11);
	    sgemm00_core1(11, 10, 12);
	    sgemm00_core1(12, 11, 13);
	    sgemm00_core1(13, 12, 14);
	    sgemm00_core1(14, 13, 15);
	    sgemm00_core1(15, 14, 16);
	    sgemm00_core1(16, 15, 17);
	    sgemm00_core1(17, 16, 18);
	    sgemm00_core1(18, 17, 19);
	    sgemm00_core1(19, 18, 20);
	    sgemm00_core1(20, 19, 21);
	    sgemm00_core1(21, 20, 22);
	    sgemm00_core1(22, 21, 23);
	    sgemm00_core1(23, 22, 24);
	    sgemm00_core1(24, 23, 25);
	    sgemm00_core1(25, 24, 26);
	    sgemm00_core1(26, 25, 27);                     
	    sgemm00_core1(27, 26, 28);
	    sgemm00_core1(28, 27, 29);
	    sgemm00_core1(29, 28, 30);
	    sgemm00_core1(30, 29, 31);
	    sgemm00_core1(31, 30, 32);
	    sgemm00_core1(32, 31, 33);
	    sgemm00_core1(33, 32, 34);
	    sgemm00_core1(34, 33, 35);
	    sgemm00_core1(35, 34, 36);
	    sgemm00_core1(36, 35, 37);
	    sgemm00_core1(37, 36, 38);
	    sgemm00_core1(38, 37, 39);
	    sgemm00_core1(39, 38, 40);
	    sgemm00_core1(40, 39, 41);
	    sgemm00_core1(41, 40, 42);
	    sgemm00_core1(42, 41, 43);
	    sgemm00_core1(43, 42, 44);
	    sgemm00_core1(44, 43, 45);
	    sgemm00_core1(45, 44, 46);
	    sgemm00_core1(46, 45, 47);
	    sgemm00_core1(47, 46, 48);
	    sgemm00_core1(48, 47, 49);
	    sgemm00_core2(49, 48, 50); /* H=48 */
	    /****final*****/
	    // mo2(OP_LDR,  3, &BR[49][2][0],  A_sort_index,  (Ull)rofs,(Ull)0, MSK_W1,A_sort_index,A_row_size, 0, 0, (Ull)NULL, A_row_size);
	    sgemm00_final(50,49,51);
          }
        }
      }
//EMAX5A end
    }
  }
//EMAX5A drain_dirty_lmm
}

#endif