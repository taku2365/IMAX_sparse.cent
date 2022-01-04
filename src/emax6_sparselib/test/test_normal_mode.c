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
// #include <X11/Xlib.h>
// #include <X11/Xatom.h>
// #include <X11/Xutil.h>
// #include <X11/cursorfont.h>
// #include <X11/extensions/Xdbe.h>
#endif


int WD=320, HT=240, BITMAP=320*240, SCRWD=5, SCRHT=5, VECWD=240, VECHT=240, VECSTEP=4;

#if defined(EMAX6)
// #include "../../src/conv-c2c/emax6.h"
//includeの順番が逆やとエラー
#include "../Include/emax6_sparselib.h"
// #include "./../../conv-c2c/emax6lib.c"
#endif
#if !defined(ARMSIML)
// #include "./xdisp.c"
#endif



/* LMM:16KB, RMM:64KB: M/NCHIP=124 M/NCHIP/RMGRP=31 */
/* A A   B B B B B B   C C C C C C */
/* A A   B B B B B B   C C C C C C */
/* A A                 C C C C C C */
/* A A                 C C C C C C */
/* L=2, A_row_size=4, B_col_size=6     L<A_row_size,B_col_size     */



  #define A_row_size 58LL   // 縛りなし
  #define A_col_size 58LL    // 縛りなし　H_padのおかげ
  #define B_row_size 58LL    // 縛りなし
  #define B_col_size 64LL   // RMGRP*NCHIP縛り
  #define DIMENTION  2LL
  // #define RMGRP 16
  #define RMGRP 16
  /*#define NCHIP 4*/
  #define NCHIP 4
  #define W  4LL
  #define H  60
  #define OOFS_SHIFT 3LL
  #define A_col_blk 1


Uint *A;  /*[A_row_size][L];*/
Uint *B;  /*[L][B_col_size];*/
Uint *C0; /*[A_row_size][B_col_size];*/
Uint *C1; /*[A_row_size][B_col_size];*/
Uint *sort_index;
Uint *A_debug; /*[A_row_size][L];*/
Uint *B_debug; /*[L][B_col_size];*/
Uint *C_debug; /*[A_row_size][B_col_size];*/
emax6_sparse2* A_sparse;
emax6_param* params;
int blk_iter;
int row,row1, col, col1, n, n1;
int top, blk;
int w, h;
int count0, count1, count2;
int nnz_A=0,nnz_B=0,nnz_B_debug=0;
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
  // char* val;
  // Uchar* membases = (Uchar*)malloc_test(sizeof(int)*10,&val);
  // val = malloc_test(sizeof(int)*10);
  // printf("malloc 10 %c \n",val[0]);
  // printf("malloc size %d \n",malloc_usable_size(val));

  Uchar* membase;
  //A_colがHで割れないときのpadding
  int A_H_pad = 0;
  if((A_col_size%H) != 0) A_H_pad = -A_col_size%H + H;
  sysinit((Uint)(2*(A_row_size*(A_col_size+A_H_pad))*sizeof(Uint)
                +(B_row_size+A_H_pad)*B_col_size*sizeof(Uint)
                +A_row_size*B_col_size*sizeof(Uint)
                // +A_row_size*B_col_size*sizeof(Uint)
                +A_row_size*sizeof(Uint)
                ),32,&membase);
  printf("membase: %08.8x\n", (Uint)membase);
  A  = (Uint*)membase;
  B  = (Uint*)((Uchar*)A  + 2*(A_row_size*(A_col_size+A_H_pad))*sizeof(Uint));
  C0 = (Uint*)calloc(A_row_size*B_col_size,sizeof(Uint));
  C1 = (Uint*)((Uchar*)B  + B_row_size*B_col_size*sizeof(Uint));
  sort_index = (Uint*)((Uchar*)C1 + A_row_size*B_col_size*sizeof(Uint));
  

  B_debug  = (Uint*)calloc(2*B_row_size*B_col_size,sizeof(Uint));
  C_debug = (Uint*)calloc(A_row_size*B_col_size,sizeof(Uint));
  params = (emax6_param*) malloc(sizeof(emax6_param)*1);
  params->RMGRP_param = RMGRP;
  params->NCHIP_param = NCHIP;
  params->H_param = H;
  params->W_param= W;
  params->A_col_blk_param = A_col_blk;
  
  // params->W_param= W*2;
  printf("A : %08.8x\n", A);
  printf("B : %08.8x\n", B);
  printf("C0: %08.8x\n", C0);
  printf("C1: %08.8x\n", C1);
  int tmp = 1,num = 0;
  int* col_index_A = (int *)calloc(A_row_size*A_col_size,sizeof(int));
  int* row_index_A = (int *)calloc(A_row_size*A_col_size,sizeof(int));
  Uint* A_tmp = (Uint *)calloc(A_row_size*A_col_size,sizeof(Uint));
    for (col=0; col<A_col_size; col++){
      for (row=0; row<A_row_size; row++) {
      tmp = (int) tmp;
      tmp = (int) (rand()%2 == 0);
      // rnad()%x 0~x-1の間の数字をとる
      // tmp = (rand()%3 == 0)||(rand()%2);
      *(float*)&A[row*A_col_size+col] = (float) (1);
      // floatで等価の判断するの危険なので、LIMITで0判定をしている。
      if(!((-LIMIT <= *(float*)&A_tmp[row+col*A_row_size]) && (*(float*)&A_tmp[row+col*A_row_size] <= LIMIT))){
          col_index_A[nnz_A] = col;
          row_index_A[nnz_A] = row;
          nnz_A += 1;
        }
    }
  }

  reset_nanosec();


  
  get_nanosec(0);
  show_nanosec();

  float val = 0;
  for (row=0; row<B_row_size; row++) {
    val += 1;
    for (col=0; col<B_col_size; col++){
      // *(float*)&B[col*B_col_size+row] = (float) tmp;
      if(col%4 == 0){
      *(float*)&B[col+row*B_col_size] = (float)1;
      }
      else{
      *(float*)&B[col+row*B_col_size] = (float)0;
      }
      // if(!((-LIMIT <= *(float*)&B[col*B_col_size+row]) && (*(float*)&B[col*B_col_size+row] <= LIMIT))) nnz_B += 1; 
      // if(!((-LIMIT <= *(float*)&B_debug[col*B_col_size+row]) && (*(float*)&B_debug[col*B_col_size+row] <= LIMIT))) nnz_B_debug += 1; 
    }
  }




  if((int)sum != (int)sum1) {
    fprintf(stderr,"sum != sum\n");
    exit(1);
  }


  reset_nanosec();
  orig(A,B,C0);
  get_nanosec(0);
  show_nanosec();

  reset_nanosec();
  // imax();
  gemm_normal_CHIP_div_B(C1, A, B);
  // sparse_gemm_736_736_736_CHIP_div_B_4(C1, A, B, A_sparse);
  // sparse_multiply_imax6(nnz_A,A_sparse,B,C1,B_col_size,params);
  get_nanosec(0);
  show_nanosec();


    sum = 0;
    sum1 = 0;
    for (col=0; col<B_col_size; col+=1){
      for (row=0; row<A_row_size; row+=1) {
        sum += *(float*)&C0[col+row*B_col_size];
        sum1 += *(float*)&C1[col+row*B_col_size];
        if (abs(*(float*)&C0[col+row*B_col_size] - *(float*)&C1[col+row*B_col_size])>1) {
          count2++;

          printf("C0[%d][%d]=%f C_debug[%d][%d]=%f\n", row, col, *(float*)&C0[col+row*B_col_size],
                                                  row, col, *(float*)&C1[col+row*B_col_size]); 
          // exit(1);       
      }
    }
  }

  printf("sum %f \n",sum);
  printf("sum1 %f \n",sum1);
  
free(A_tmp);




}




orig(Uint* A_orig,Uint* B_orig,Uint* C_orig) {
  printf("<<<ORIG>>>\n");
  for (row=0; row<A_row_size; row++) {
    for (col=0; col<B_col_size; col++) {
      for (n=0; n<A_col_size; n++) {
        if (n==0) *(float*)&C_orig[row*B_col_size+col]  = *(float*)&A_orig[row*A_col_size+n] * *(float*)&B_orig[n*B_col_size+col];
        else      *(float*)&C_orig[row*B_col_size+col] += *(float*)&A_orig[row*A_col_size+n] * *(float*)&B_orig[n*B_col_size+col];
        count0++;
        /*printf("[%d %d %d]", row, col, n);*/
      }
      /*printf("\n");*/
    }
  }
}





