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
// #include "../../src/conv-c2c/emax6.h"
//includeの順番が逆やとエラー
#include "../../src/emax6_sparselib/Include/emax6_sparselib.h"
// #include "./../../conv-c2c/emax6lib.c"
#endif
#if !defined(ARMSIML)
#include "./xdisp.c"
#endif



/* LMM:16KB, RMM:64KB: M/NCHIP=124 M/NCHIP/RMGRP=31 */
/* A A   B B B B B B   C C C C C C */
/* A A   B B B B B B   C C C C C C */
/* A A                 C C C C C C */
/* A A                 C C C C C C */
/* L=2, M1=4, M2=6     L<M1,M2     */


#define L  736LL
#define M1 736LL
#define M2 736LL
#define A_row_size 736LL
#define A_col_size 736LL
#define B_row_size 736LL
#define B_col_size 736LL

// #define RMGRP 16
#define RMGRP 8
/*#define NCHIP 4*/
#define NCHIP 4
#define W  4LL
#define H  46


Uint *A;  /*[M1][L];*/
Uint *B;  /*[L][M2];*/
Uint *C0; /*[M1][M2];*/
Uint *C1; /*[M1][M2];*/
Uint *sort_index;
Uint *A_debug; /*[M1][L];*/
Uint *B_debug; /*[L][M2];*/
Uint *C_debug; /*[M1][M2];*/
emax6_sparse2* A_sparse;
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

#define ERRTH  (5.0E-3)
#define udiff(a,b) (((a)-(b)>=0.0?(a)-(b):(b)-(a))/((a)==0.0?1:(a)))
#define setmax(max, new) { if (max < (new)) max = (new); }

#define MAXINT (~(1<<(sizeof(int)*8-1)))
#define adif(a,b) (((a)>(b))?(a)-(b):(b)-(a))
#define dif(a,b)  (adif((((a)>>24)&255), (((b)>>24)&255))\
                  +adif((((a)>>16)&255), (((b)>>16)&255))\
                  +adif((((a)>> 8)&255), (((b)>> 8)&255)))
#define abs(a) (((a)<0)?-(a):(a))

main()
{ //pointerでないので普通に足される。
  Uchar* membase = sysinit((Uint)(2*((M1+1)*L)*sizeof(Uint)
                +L*M2*sizeof(Uint)
                +M1*M2*sizeof(Uint)
                +M1*M2*sizeof(Uint)
                +M1*sizeof(Uint)
                ),32);
  printf("membase: %08.8x\n", (Uint)membase);
  A  = (Uint*)membase;
  B  = (Uint*)((Uchar*)A  + 2*((M1+1)*L)*sizeof(Uint));
  C0 = (Uint*)((Uchar*)B  + L*M2*sizeof(Uint));
  C1 = (Uint*)((Uchar*)C0 + M1*M2*sizeof(Uint));
  sort_index = (Uint*)((Uchar*)C1 + M1*M2*sizeof(Uint));
  

  A_debug = (Uint*)calloc(M1*M2,sizeof(Uint));
  B_debug  = (Uint*)calloc(2*((M1+1)*L),sizeof(Uint));
  C_debug = (Uint*)calloc(M1*M2,sizeof(Uint));
  params = (emax6_param*) malloc(sizeof(emax6_param)*1);
  params->RMGRP_param = RMGRP;
  params->NCHIP_param = NCHIP;
  params->H_param = H;
  params->W_param= W;
  
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
      tmp = (int) (rand()%9 == 0);

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

  reset_nanosec();

 
  A_sparse = sparse_format5(nnz_A,A,A_tmp,col_index_A,row_index_A,M1,L,params,sort_index,"/home/takuya-s/IMAX_sparse.cent/sample/test/sparse_data.wb",0);


  
  get_nanosec(0);
  show_nanosec();


  for (row=0; row<L; row++) {
    for (col=0; col<M2; col++){
      float tmp = row+col;
      // *(float*)&B[col*M2+row] = (float) tmp;
      if(col%4 == 0){
      *(float*)&B_debug[col*M2+row] = (float)1;
      }
      else{
        *(float*)&B_debug[col*M2+row] = (float)0;
      }
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

  if((int)sum != (int)sum1) {
    fprintf(stderr,"sum != sum\n");
    exit(1);
  }

                                     //  nanosec: ARM:14476178 DRAIN:0 CONF:0 REGV:0 RANGE:0 LOAD:0 EXEC:0 total:14476178 //format
// nanosec: ARM:643720 DRAIN:3900830 CONF:139645 REGV:22034423 RANGE:12112945 LOAD:81180395 EXEC:20458796  total:140470754  密
// nanosec: ARM:697759 DRAIN:3912415 CONF:144105 REGV:36137979 RANGE:12767833 LOAD:144809961 EXEC:21722040 total:220192092 そのまま計算
// nanosec: ARM:523872 DRAIN:3860935 CONF:124981 REGV:27126625 RANGE:9538279 LOAD:109312336 EXEC:15392081  total:165879109  2/3
// nanosec: ARM:406986 DRAIN:3818889 CONF:110080 REGV:20350376 RANGE:7143744 LOAD:82684247 EXEC:11680525   total:126194847 %2
// nanosec: ARM:318687 DRAIN:3793709 CONF:100085 REGV:15827467 RANGE:5573393 LOAD:64865556 EXEC:8321523    total:98800420 %3
// nanosec: ARM:197559 DRAIN:3747668 CONF:85619 REGV:9034281 RANGE:3180254 LOAD:38802744 EXEC:5216107      total:60264232 //2.33 %4
// nanosec: ARM:201870 DRAIN:3755070 CONF:84790 REGV:9040110 RANGE:3187043 LOAD:38284119 EXEC:5230658      total:59783660 %5
// nanosec: ARM:201605 DRAIN:3751573 CONF:84941 REGV:9047404 RANGE:3170832 LOAD:38262244 EXEC:4460222      total:58978821 %6
// nanosec: ARM:152969 DRAIN:3738010 CONF:80459 REGV:6775409 RANGE:2385811 LOAD:29399387 EXEC:4009696      total:46541741 %7
// nanosec: ARM:154852 DRAIN:3737772 CONF:81778 REGV:6785112 RANGE:2377742 LOAD:29789329 EXEC:3514694      total:46441279 //3.02 %8
// nanosec: ARM:161484 DRAIN:3740919 CONF:80551 REGV:6781150 RANGE:2391537 LOAD:29382167 EXEC:3101214      total:45639022 %9
// nanosec: ARM:9881990142 DRAIN:0 CONF:0 REGV:0 RANGE:0 LOAD:0 EXEC:0 total:9881990142


// nanosec: ARM:340371 DRAIN:3700385 CONF:101603 REGV:11022509 RANGE:6211888 LOAD:41737707 EXEC:18581238 total:81695701
// nanosec: ARM:213895 DRAIN:3655417 CONF:87268 REGV:10172598 RANGE:3572451 LOAD:43506825  EXEC:10257497 total:71465951

  reset_nanosec();
  orig(A_tmp,B_debug,C0);
  get_nanosec(0);
  show_nanosec();

  reset_nanosec();
  // imax();
  sparse_gemm_736(C1, A, B, A_sparse);
  // sparse_multiply_imax3(nnz_A,A_sparse,B,C1,M2,params);
  get_nanosec(0);
  show_nanosec();




    for (col=0,col1=0; col<M2/2; col+=1,col1+=2){
      for (row=0,row1=0; row1<L; row+=2,row1+=1) {
        if ((C0[col1+row1*L] != C1[col*2*M2+row])||(C0[(col1+1)+row1*L] != C1[col*2*M2+row+1])) {
          count2++;
          printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row1, col1, (double)*(float*)&C0[col1+row1*L],
                                                  row, col*2, (double)*(float*)&C1[col*2*M2+row]);
          printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row1, col1+1, (double)*(float*)&C0[(col1+1)+row1*L],
                                                  row+1, col*2, (double)*(float*)&C1[col*2*M2+row+1]);  
          // exit(1);       
      }
    }
  }
  
free(A_tmp);


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
          if(!(((row*M2+col1)<M1*M2)&&((row+n*M1) < M1*L)&&((n1+col*(2*L)) <M2*L)&&((n1+1+col*(2*L)) < M2*L))) {
           fprintf(stderr,"simd debug error\n");
           exit(1);
        }
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


