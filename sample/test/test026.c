
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

int WD, HT, BITMAP, SCRWD, SCRHT, VECWD, VECHT, VECSTEP;
int enable_x11 = 1;

Uchar* membase;

#if defined(EMAX6)
#include "../../src/conv-c2c/emax6.h"
#include "../../src/conv-c2c/emax6lib.c"
#endif
#if !defined(ARMSIML)
#include "./xdisp.c"
#endif

sysinit(memsize, alignment) Uint memsize, alignment;
{
#if defined(ARMZYNQ) && defined(EMAX6)
  if (emax6_open() == NULL)
    exit(1);
  membase = emax_info.ddr_mmap;
  {int i; for (i=0; i<(memsize+sizeof(Dll)-1)/sizeof(Dll); i++) *((Dll*)membase+i)=0;}
#elif __linux__ == 1
  posix_memalign(&membase, alignment, memsize);
#else
  membase = (void*)malloc(memsize+alignment);
  if ((Ull)membase & (Ull)(alignment-1))
    membase = (void*)(((Ull)membase & ~(Ull)(alignment-1))+alignment);
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
  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].cmd = CMD_RESET;  // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ RESET
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
/* M1=4 L=2, M2=6      L<M1,M2     */

#define M1 216LL
#define M2 216LL
#define L  216LL
#define LP 24LL

typedef struct {
  float d; /* low */
  Uint  x; /* high */
} packed;

Uint  *A32_0; /*[M1][L]         */
Uint  *A32_1; /*[M1][L]   xdisp */
packed *A32_P; /*[M1][L]   pack  */
Uint  *B32_0; /*[M2][L] T       */
Uint  *B32_1; /*[M2][L] T xdisp */
packed *B32_P; /*[M2][L] T pack  */
Uint  *C32_0; /*[M1][M2]  orig  */
Uint  *C32_1; /*[M1][M2]  imax  */
int row, col, n;
int top, blk;
int w, h;
int count0, count1, count2;

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

#ifdef ARMSIML
void FP_to_X(int id, float *from)
{
  int i, j;
  Uint *to;

  to = Z; /* 320*240 buffer for CSM */
  for (i=0; i<HT; i++,to+=(CSIMWD-WD)) {
    for (j=0; j<WD; j++,to++,from++) {
      Uint color;
      if      (fabsf(*from) < 0.000)
        color = 0x00000000;
      else if (fabsf(*from) < 0.063)
        color = 0x80000000;
      else if (fabsf(*from) < 0.125)
        color = 0xff000000;
      else if (fabsf(*from) < 0.188)
        color = 0x00008000;
      else if (fabsf(*from) < 0.250)
        color = 0x0000ff00;
      else if (fabsf(*from) < 0.313)
        color = 0x80008000;
      else if (fabsf(*from) < 0.375)
        color = 0xff00ff00;
      else if (fabsf(*from) < 0.437)
        color = 0x00800000;
      else if (fabsf(*from) < 0.500)
        color = 0x00ff0000;
      else if (fabsf(*from) < 0.563)
        color = 0x00808000;
      else if (fabsf(*from) < 0.625)
        color = 0x00ffff00;
      else if (fabsf(*from) < 0.688)
        color = 0x80800000;
      else if (fabsf(*from) < 0.750)
        color = 0xc0c00000;
      else if (fabsf(*from) < 0.813)
        color = 0xffff0000;
      else if (fabsf(*from) < 0.875)
        color = 0x80808000;
      else if (fabsf(*from) < 0.938)
        color = 0xc0c0c000;
      else
        color = 0xffffff00;
      *to = color;
    }
  }
  _copyX(id, Z);
  _updateX();
}
#endif

main()
{
  sysinit((Uint)(M1*L *sizeof(Uint)
                +M1*L *sizeof(Uint)
                +M1*L *sizeof(Uint)
                +M2*L *sizeof(Uint)
                +M2*L *sizeof(Uint)
                +M2*L *sizeof(Uint)
                +M1*M2*sizeof(Uint)
                +M1*M2*sizeof(Uint)),32);
  printf("membase: %08.8x_%08.8x\n", (Uint)((Ull)membase>>32), (Uint)membase);
  A32_0 = (Uint*)membase;
  A32_1 = (Uint*)((Uchar*)A32_0 + M1*L *sizeof(Uint));
  A32_P = (Uint*)((Uchar*)A32_1 + M1*L *sizeof(Uint));
  B32_0 = (Uint*)((Uchar*)A32_P + M1*L *sizeof(Uint));
  B32_1 = (Uint*)((Uchar*)B32_0 + M1*L *sizeof(Uint));
  B32_P = (Uint*)((Uchar*)B32_1 + M2*L *sizeof(Uint));
  C32_0 = (Uint*)((Uchar*)B32_P + M2*L *sizeof(Uint));
  C32_1 = (Uint*)((Uchar*)C32_0 + M1*M2*sizeof(Uint));
  printf("A32_0: %08.8x\n", (Uint)A32_0);
  printf("A32_1: %08.8x\n", (Uint)A32_1);
  printf("A32_P: %08.8x\n", (Uint)A32_P);
  printf("B32_0: %08.8x\n", (Uint)B32_0);
  printf("B32_1: %08.8x\n", (Uint)B32_1);
  printf("B32_P: %08.8x\n", (Uint)B32_P);
  printf("C32_0: %08.8x\n", (Uint)C32_0);
  printf("C32_1: %08.8x\n", (Uint)C32_1);

  WD      = M1;
  HT      = M2;
  BITMAP  = WD*HT;
  SCRWD   = 4;
  SCRHT   = 2;
  VECWD   = 1;
  VECHT   = 1;
  VECSTEP = 4;
// #if !defined(ARMSIML)
//   x11_open(1); /*sh_video->disp_w, sh_video->disp_h, # rows of output_screen*/
// #endif

  /**************************************************/
  /* A                                              */
  /**************************************************/
  for (row=0; row<M1; row++) {
    for (col=0; col<L; col++) {
      if (abs(row-col) < LP/2)
        *(float*)&A32_0[row*L+col] = (float)(row-col)/(float)(L/(128/LP));
      else *(float*)&A32_0[row*L+col] = 0;
    }
  }


  /**************************************************/
  /* B                                              */
  /**************************************************/
  for (row=0; row<M2; row++) {
    for (col=0; col<L; col++) {
      if (abs(row-col) < LP/2)
        *(float*)&B32_0[row*L+col] = (float)(row-col)/(float)(L/(128/LP));
      else *(float*)&B32_0[row*L+col] = 0;
    }
  }

  for (row=0; row<M2; row++) {
    for (col=0; col<L; col++) {
        *(float*)&C32_0[row*L+col] = 0;
        *(float*)&C32_1[row*L+col] = 0;
    }
  }



  orig();  
  imax(); 

#if 1
  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++) {
      float origC  = *(float*)&C32_0[row*M2+col];
      float imaxC  = *(float*)&C32_1[row*M2+col];
    //   if (udiff(origC, imaxC)>ERRTH) {
        count2++;
        printf("orig[%d][%d]=%7.4f imaxC [%d][%d]=%7.4f\n", row, col, origC, row, col, imaxC);
    //   }
    }
  }
  if (count2)
    printf("Num of diffs: %d\n", count2);
  else
    printf("Results are equal\n");
#endif

// #if !defined(ARMSIML)
//   printf("==== Normal end. Type any in ImageWin ====\n");
//   while (!x11_checkevent());
// #endif
}

orig() {
  printf("<<<ORIG>>>\n");
  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++) {
      for (n=0; n<L; n++) {
        if (n==0) *(float*)&C32_0[row*M2+col]  = *(float*)&A32_0[row*L+n] * *(float*)&B32_0[n*L+col];
        else      *(float*)&C32_0[row*M2+col] += *(float*)&A32_0[row*L+n] * *(float*)&B32_0[n*L+col];
        count0++;
      }
    }
  }
  printf("orig.FMA = %d\n", count0);
}

init_array(Ull *a, int len) {
  int i;
  for (i=0; i<len; i++)
    a[i] = 0;
}

imax() {
#undef  NCHIP
#undef  RMGRP
#undef  W
#undef  H
#define NCHIP 1
#define RMGRP 4
#define W     4LL
#define H     54
  Ull  CHIP;
  Ull  LOOP1, LOOP0;
  Ull  INIT1, INIT0;
  Ull  AR[64][4];                     /* output of EX     in each unit */
  Ull  BR[64][4][4];                  /* output registers in each unit */
  Ull  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
  Ull  r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
  Ull  cc0, cc1, cc2, cc3, ex0, ex1;
  Ull  cofs, rofs, oofs, k;


  /*                           ¢ªºÇÆâloop      ¢ªºÇÆâloop         */
  /*  ¨£¨¡¨¡L ¨¡¨¡¨¤¨¤      ¨£MT¨¡M2¨¡¨¡¨¤  ¨£MT¨¡M2¨¡¨¡¨¤¨¤      */
  /*  ¨¢a a a a a ¨¢¨¢RMGRP ¨¢bbbb     H¨¢  ¨¢oooo      ¨¢¨¢RMGRP */
  /*  ¨¢          ¨¢¨©CHIP  ¨¢bbbb      ¨©  ¨¢          ¨¢¨©CHIP  */
  /*  M1   A(in)  ¨¢¨¢      L bbbb  B0 H¨¢  M1   out    ¨¢¨¢      */
  /*  ¨¢          ¨¢¨©      ¨¢bbbb      ¨©  ¨¢          ¨¢¨©      */
  /*  ¨¢H   H   H ¨¢¨¢      ¨¢bbbb     H¨¢  ¨¢ 60*4ÊÂÎó ¨¢¨¢      */
  /*  ¨¦¨¡¨ª¨¡¨ª¨¡¨¥¨¥      ¨¦¨¡¨¡¨¡¨¡¨¡¨¥  ¨¦¨¡¨¡¨¡¨¡¨¡¨¥¨¥      */  
  printf("<<<IMAX>>>\n");
  /* M1/NCHIP/RMGRP * L/H * NCHIP * RMGRP * M2/W/2 * W*2 * H = M1*M2*L */
  for (top=0; top<M1/NCHIP; top+=RMGRP) { /* will be parallelized by multi-chip (M/#chip) */
    for (blk=0; blk<L; blk+=H) { /* 3½Å¥ë¡¼¥×Å¸³«¤Î³°Â¦ÂÐ¾Ý */
      typedef struct {Uint i[8]} Ui8;
      Uint *a[NCHIP], *a0[H][NCHIP];
      Ui8  *b[H], *b0[H], *b1[H], *b2[H], *b3[H];
      Ui8  *c[NCHIP], *c0[NCHIP], *c1[NCHIP], *c2[NCHIP], *c3[NCHIP];
      for (k=0; k<H; k++) {
        b[k] = B32_0+(blk+k)*M2; b0[k] = b[k]; b1[k] = (Uint*)b[k]+2; b2[k] = (Uint*)b[k]+4;  b3[k] = (Uint*)b[k]+6;
      }
      for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
        a[CHIP] = A32_0+(CHIP*M1/NCHIP+top)*L;
        for (k=0; k<H; k++)
          a0[k][CHIP] = a[CHIP]+blk+k;
        c[CHIP] = C32_1+(CHIP*M1/NCHIP+top)*M2;
        c0[CHIP]= (Uint*)c[CHIP]+0; c1[CHIP]= (Uint*)c[CHIP]+2; c2[CHIP]= (Uint*)c[CHIP]+4; c3[CHIP]= (Uint*)c[CHIP]+6;
      }

#define sgemm00_core1(r, rm1, rp1) \
            mop(OP_LDR,  3, &BR[r][0][1],  (Ull)b0[rm1], (Ull)cofs, MSK_W1, (Ull)b[rm1], M2, 0, 0, (Ull)NULL, M2);\
            mop(OP_LDR,  3, &BR[r][0][0],  (Ull)b1[rm1], (Ull)cofs, MSK_W1, (Ull)b[rm1], M2, 0, 0, (Ull)NULL, M2);\
            mop(OP_LDR,  3, &BR[r][1][1],  (Ull)b2[rm1], (Ull)cofs, MSK_W1, (Ull)b[rm1], M2, 0, 0, (Ull)NULL, M2);\
            mop(OP_LDR,  3, &BR[r][1][0],  (Ull)b3[rm1], (Ull)cofs, MSK_W1, (Ull)b[rm1], M2, 0, 0, (Ull)NULL, M2);\
            mop(OP_LDUWR,1, &BR[r][2][1],  (Ull)a0[rm1][CHIP],  (Ull)rofs, MSK_W1, (Ull)a[CHIP], L*RMGRP, 0, 0, (Ull)NULL, L*RMGRP);\
            exe(OP_FMA, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FMA, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FMA, &AR[rp1][2], AR[r][2], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FMA, &AR[rp1][3], AR[r][3], EXP_H3210,  BR[r][2][1], EXP_H3210, BR[r][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL)

#define sgemm00_final(r, rp1) \
            mop(OP_LDR,  3, &BR[rp1][0][1],  (Ull)c0[CHIP], (Ull)oofs, MSK_W0, (Ull)c[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
            mop(OP_LDR,  3, &BR[rp1][1][1],  (Ull)c1[CHIP], (Ull)oofs, MSK_W0, (Ull)c[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
            mop(OP_LDR,  3, &BR[rp1][2][1],  (Ull)c2[CHIP], (Ull)oofs, MSK_W0, (Ull)c[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
            mop(OP_LDR,  3, &BR[rp1][3][1],  (Ull)c3[CHIP], (Ull)oofs, MSK_W0, (Ull)c[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
            exe(OP_FAD, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[rp1][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FAD, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[rp1][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FAD, &AR[rp1][2], AR[r][2], EXP_H3210,  BR[rp1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FAD, &AR[rp1][3], AR[r][3], EXP_H3210,  BR[rp1][3][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            mop(OP_STR,  3, &AR[rp1][0],     (Ull)oofs, (Ull)c0[CHIP], MSK_D0, (Ull)c[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
            mop(OP_STR,  3, &AR[rp1][1],     (Ull)oofs, (Ull)c1[CHIP], MSK_D0, (Ull)c[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
            mop(OP_STR,  3, &AR[rp1][2],     (Ull)oofs, (Ull)c2[CHIP], MSK_D0, (Ull)c[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP);\
            mop(OP_STR,  3, &AR[rp1][3],     (Ull)oofs, (Ull)c3[CHIP], MSK_D0, (Ull)c[CHIP], M2*RMGRP, 0, 1, (Ull)NULL, M2*RMGRP)

//EMAX5A begin imax mapdist=0
/*3*/ for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
  /*2*/ for (INIT1=1,LOOP1=RMGRP,rofs=(0-L*4)<<32|((0-M2*4)&0xffffffff); LOOP1--; INIT1=0) {        /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
    /*1*/ for (INIT0=1,LOOP0=M2/W/2,cofs=(0-W*8)<<32|((0-W*8)&0xffffffff); LOOP0--; INIT0=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
            exe(OP_ADD,    &cofs, INIT0?cofs:cofs, EXP_H3210, (W*8)<<32|(W*8), EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */
            exe(OP_ADD,    &rofs, rofs, EXP_H3210, INIT0?(L*4)<<32|(M2*4):0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */
            exe(OP_ADD,    &oofs, rofs, EXP_H3210, cofs, EXP_H3210, 0, EXP_H3210, OP_AND, 0x00000000ffffffffLL, OP_NOP, 0LL);      /* stage#1 */

            mop(OP_LDR,  3, &BR[1][0][1],  (Ull)b0[0], (Ull)cofs, MSK_W1, (Ull)b[0], M2, 0, 0, (Ull)NULL, M2);                     /* stage#1 */
            mop(OP_LDR,  3, &BR[1][0][0],  (Ull)b1[0], (Ull)cofs, MSK_W1, (Ull)b[0], M2, 0, 0, (Ull)NULL, M2);                     /* stage#1 */
            mop(OP_LDR,  3, &BR[1][1][1],  (Ull)b2[0], (Ull)cofs, MSK_W1, (Ull)b[0], M2, 0, 0, (Ull)NULL, M2);                     /* stage#1 */
            mop(OP_LDR,  3, &BR[1][1][0],  (Ull)b3[0], (Ull)cofs, MSK_W1, (Ull)b[0], M2, 0, 0, (Ull)NULL, M2);                     /* stage#1 2KB */
            mop(OP_LDUWR,1, &BR[1][2][1],  (Ull)a0[0][CHIP],  (Ull)rofs, MSK_W1, (Ull)a[CHIP], L*RMGRP, 0, 0, (Ull)NULL, L*RMGRP); /* stage#1 16KB */
            exe(OP_FML, &AR[2][0], BR[1][0][1], EXP_H3210,  BR[1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);     /* stage#2 */
            exe(OP_FML, &AR[2][1], BR[1][0][0], EXP_H3210,  BR[1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);     /* stage#2 */
            exe(OP_FML, &AR[2][2], BR[1][1][1], EXP_H3210,  BR[1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);     /* stage#2 */
            exe(OP_FML, &AR[2][3], BR[1][1][0], EXP_H3210,  BR[1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);     /* stage#2 */

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
            sgemm00_core1(47, 46, 48);
            sgemm00_core1(48, 47, 49);
            sgemm00_core1(49, 48, 50);
            sgemm00_core1(50, 49, 51);
            sgemm00_core1(51, 50, 52);
            sgemm00_core1(52, 51, 53);
            sgemm00_core1(53, 52, 54);
            sgemm00_core1(54, 53, 55); /* H=54 */
            /****final*****/
            sgemm00_final(55,     56);
          }
        }
      }
//EMAX5A end
    }
  }
//EMAX5A drain_dirty_lmm
}
