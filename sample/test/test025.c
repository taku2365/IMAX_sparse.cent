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
  // memset(membase, 0, memsize+alignment);
  int i;
  for(i=0;i<memsize/sizeof(Uint);i++) *((Uint*)membase+i) = (Uint)0;


  
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
#define NCHIP 2
#define W  4LL
#define H  46

Uint *A;  /*[M1][L];*/
Uint *B;  /*[L][M2];*/
Uint *C0; /*[M1][M2];*/
Uint *C1; /*[M1][M2];*/
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
  sysinit((Uint)(2*((M1+1)*L)*sizeof(Uint)
                +L*M2*sizeof(Uint)
                +M1*M2*sizeof(Uint)
                +M1*M2*sizeof(Uint)
                ),32);
  printf("membase: %08.8x\n", (Uint)membase);
  A  = (Uint*)membase;
  B  = (Uint*)((Uchar*)A  + 2*((M1+1)*L)*sizeof(Uint));
  C0 = (Uint*)((Uchar*)B  + L*M2*sizeof(Uint));
  C1 = (Uint*)((Uchar*)C0 + M1*M2*sizeof(Uint));

  A_debug = (Uint*)calloc(M1*M2,sizeof(Uint));
  B_debug  = (Uint*)calloc(2*((M1+1)*L),sizeof(Uint));
  C_debug = (Uint*)calloc(L*M2,sizeof(Uint));
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
    for (col=0; col<L; col++)
    fprintf(stderr,"aaaa\n");
      *(float*)&A[row*L+col] = row%120+1;
  }
  for (row=0; row<L; row++) {
    fprintf(stderr,"bbbb\n");
    for (col=0; col<M2; col++)
      *(float*)&B[row*M2+col] = col%120+1;
  }

  // orig();
  reset_nanosec();
  imax();
  get_nanosec(0);
  show_nanosec();

  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++) {
      if (C0[row*M2+col] != C1[row*M2+col]) {
        count2++;
        printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row, col, (double)*(float*)&C0[row*M2+col],
                                                row, col, (double)*(float*)&C1[row*M2+col]);
      }
    }
  }

//     for (col=0,col1=0; col<M2/2; col+=1,col1+=2){
//       for (row=0,row1=0; row1<L; row+=2,row1+=1) {
//         if ((C0[col1+row1*L] != C1[col*2*M2+row])||(C0[(col1+1)+row1*L] != C1[col*2*M2+row+1])) {
//           count2++;
//           printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row1, col1, (double)*(float*)&C0[col1+row1*L],
//                                                   row, col*2, (double)*(float*)&C1[col*2*M2+row]);
//           printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row1, col1+1, (double)*(float*)&C0[(col1+1)+row1*L],
//                                                   row+1, col*2, (double)*(float*)&C1[col*2*M2+row+1]);  
//           exit(1);       
//       }
//     }
//   }
  
// free(A_tmp);


}




orig() {
  printf("<<<ORIG>>>\n");
  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++) {
      for (n=0; n<L; n++) {
        if (n==0) *(float*)&C0[row*M2+col]  = *(float*)&A[row*L+n] * *(float*)&B[n*M2+col];
        else      *(float*)&C0[row*M2+col] += *(float*)&A[row*L+n] * *(float*)&B[n*M2+col];
        count0++;
        /*printf("[%d %d %d]", row, col, n);*/
      }
      /*printf("\n");*/
    }
  }
}







imax() {
  Ull  CHIP;
  Ull  LOOP1, LOOP0;
  Ull  INIT1, INIT0;
  Ull  AR[64][4];                     /* output of EX     in each unit */
  Ull  BR[64][4][4];                  /* output registers in each unit */
  Ull  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
  Ull  r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
  Ull  cc0, cc1, cc2, cc3, ex0, ex1;
  Ull  cofs, rofs, oofs, k;
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
  for (top=0; top<M1/NCHIP; top+=RMGRP) { /* will be parallelized by multi-chip (M/#chip) */
    for (blk=0; blk<L; blk+=H) { /* 3重ループ展開の外側対象 */
      typedef struct {Uint i[8]} Ui8;
      Uint *a0[NCHIP];
      Uint *a[H][NCHIP];
      Ui8  *b[H], *b0[H], *b1[H], *b2[H], *b3[H];
      Ui8  *c0[NCHIP];
      Ui8  *c00[NCHIP], *c01[NCHIP], *c02[NCHIP], *c03[NCHIP];
      for (k=0; k<H; k++) {
	b[k] = B+(blk+k)*M2; b0[k] = b[k]; b1[k] = (Uint*)b[k]+2; b2[k] = (Uint*)b[k]+4;  b3[k] = (Uint*)b[k]+6; 
      }
      for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
	a0[CHIP] = A+(CHIP*M1/NCHIP+top)*L;
	for (k=0; k<H; k++)
	  a[k][CHIP] = a0[CHIP]+blk+k;
	c0[CHIP] = C1+(CHIP*M1/NCHIP+top)*M2;
	c00[CHIP]= (Uint*)c0[CHIP]+0; c01[CHIP]= (Uint*)c0[CHIP]+2; c02[CHIP]= (Uint*)c0[CHIP]+4; c03[CHIP]= (Uint*)c0[CHIP]+6;
      }

#define sgemm00_core1(r, rm1, rp1) \
	    mop(OP_LDR,  3, &BR[r][0][1],  (Ull)b0[rm1], (Ull)cofs, MSK_W1, (Ull)b[rm1], M2, 0, 0, (Ull)NULL, M2);\
	    mop(OP_LDR,  3, &BR[r][0][0],  (Ull)b1[rm1], (Ull)cofs, MSK_W1, (Ull)b[rm1], M2, 0, 0, (Ull)NULL, M2);\
	    mop(OP_LDR,  3, &BR[r][1][1],  (Ull)b2[rm1], (Ull)cofs, MSK_W1, (Ull)b[rm1], M2, 0, 0, (Ull)NULL, M2);\
	    mop(OP_LDR,  3, &BR[r][1][0],  (Ull)b3[rm1], (Ull)cofs, MSK_W1, (Ull)b[rm1], M2, 0, 0, (Ull)NULL, M2);\
	    mop(OP_LDUWR,1, &BR[r][2][1],  (Ull)a[rm1][CHIP],  (Ull)rofs, MSK_W1, (Ull)a0[CHIP], L*RMGRP, 0, 0, (Ull)NULL, L*RMGRP);\
	    exe(OP_FMA, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[rp1][2], AR[r][2], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[rp1][3], AR[r][3], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL)

#define sgemm00_final(r, rp1) \
	    mop(OP_LDR,  3, &BR[rp1][0][1],  (Ull)c00[CHIP], (Ull)oofs, MSK_W0, (Ull)c0[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
	    mop(OP_LDR,  3, &BR[rp1][1][1],  (Ull)c01[CHIP], (Ull)oofs, MSK_W0, (Ull)c0[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
	    mop(OP_LDR,  3, &BR[rp1][2][1],  (Ull)c02[CHIP], (Ull)oofs, MSK_W0, (Ull)c0[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
	    mop(OP_LDR,  3, &BR[rp1][3][1],  (Ull)c03[CHIP], (Ull)oofs, MSK_W0, (Ull)c0[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
	    exe(OP_FAD, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[rp1][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[rp1][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[rp1][2], AR[r][2], EXP_H3210,  BR[rp1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[rp1][3], AR[r][3], EXP_H3210,  BR[rp1][3][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mop(OP_STR,  3, &AR[rp1][0],     (Ull)oofs, (Ull)c00[CHIP], MSK_D0, (Ull)c0[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
	    mop(OP_STR,  3, &AR[rp1][1],     (Ull)oofs, (Ull)c01[CHIP], MSK_D0, (Ull)c0[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
	    mop(OP_STR,  3, &AR[rp1][2],     (Ull)oofs, (Ull)c02[CHIP], MSK_D0, (Ull)c0[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
	    mop(OP_STR,  3, &AR[rp1][3],     (Ull)oofs, (Ull)c03[CHIP], MSK_D0, (Ull)c0[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP)

//EMAX5A begin mm mapdist=0
/*3*/ for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
  /*2*/ for (INIT1=1,LOOP1=RMGRP,rofs=(0-L*4)<<32|((0-M2*4)&0xffffffff); LOOP1--; INIT1=0) { /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
    /*1*/ for (INIT0=1,LOOP0=M2/W/2,cofs=(0-W*8)<<32|((0-W*8)&0xffffffff); LOOP0--; INIT0=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
            exe(OP_ADD,    &cofs, INIT0?cofs:cofs, EXP_H3210, (W*8)<<32|(W*8), EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */
            exe(OP_ADD,    &rofs, rofs, EXP_H3210, INIT0?(L*4)<<32|(M2*4):0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */
            exe(OP_ADD,    &oofs, rofs, EXP_H3210, cofs, EXP_H3210, 0, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);            /* stage#1 */

            mop(OP_LDR,  3, &BR[1][0][1],  (Ull)b0[0], (Ull)cofs, MSK_W1, (Ull)b[0], M2, 0, 0, (Ull)NULL, M2);             /* stage#1 */
            mop(OP_LDR,  3, &BR[1][0][0],  (Ull)b1[0], (Ull)cofs, MSK_W1, (Ull)b[0], M2, 0, 0, (Ull)NULL, M2);             /* stage#1 */
            mop(OP_LDR,  3, &BR[1][1][1],  (Ull)b2[0], (Ull)cofs, MSK_W1, (Ull)b[0], M2, 0, 0, (Ull)NULL, M2);             /* stage#1 */
            mop(OP_LDR,  3, &BR[1][1][0],  (Ull)b3[0], (Ull)cofs, MSK_W1, (Ull)b[0], M2, 0, 0, (Ull)NULL, M2);             /* stage#1 2KB */
            mop(OP_LDUWR,1, &BR[1][2][1],  (Ull)a[0][CHIP],  (Ull)rofs, MSK_W1, (Ull)a0[CHIP], L*RMGRP, 0, 0, (Ull)NULL, L*RMGRP); /* stage#1 16KB */
            exe(OP_FML, &AR[2][0], BR[1][0][1], EXP_H3210,  BR[1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#2 */
            exe(OP_FML, &AR[2][1], BR[1][0][0], EXP_H3210,  BR[1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#2 */
            exe(OP_FML, &AR[2][2], BR[1][1][1], EXP_H3210,  BR[1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#2 */
            exe(OP_FML, &AR[2][3], BR[1][1][0], EXP_H3210,  BR[1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#2 */

	    sgemm00_core1( 2,  1,  3);
	    sgemm00_core1( 3,  2,  4);
	    sgemm00_core1( 4,  3,  5);
	    sgemm00_core1( 5,  4,  6);
	    sgemm00_core1( 6,  5,  7);
	    sgemm00_core1( 7,  6,  8);
	    sgemm00_core1( 8,  7,  9);
	    sgemm00_core1( 9,  8, 10);
	    sgemm00_core1(10,  9, 11);
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

	    /****final*****/
	    sgemm00_final(47,     48);
          }
        }
      }
//EMAX5A end
    }
  }
//EMAX5A drain_dirty_lmm
}






