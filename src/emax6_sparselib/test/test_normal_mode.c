// static char RcsHeader[] = "$Header: /usr/home/nakashim/proj-arm64/sample/mm_cnn_lf/RCS/mm.c,v 1.4 2018/02/04 10:28:53 nakashim Exp nakashim $";

// /*                          Copyright (C) 2013- by NAIST */
// /*                           Primary writer: Y.Nakashima */
// /*                                  nakashim@is.naist.jp */

// #ifndef UTYPEDEF
// #define UTYPEDEF
// typedef unsigned char      Uchar;
// typedef unsigned short     Ushort;
// typedef unsigned int       Uint;
// typedef unsigned long long Ull;
// typedef long long int      Sll;
// #if __AARCH64EL__ == 1
// typedef long double Dll;
// #else
// typedef struct {Ull u[2];} Dll;
// #endif
// #endif

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <fcntl.h>
// #include <math.h>
// #include <malloc.h>
// #ifndef ARMSIML
// #include <unistd.h>
// #include <sys/times.h>
// #include <sys/mman.h>
// #include <sys/resource.h>
// #include <pthread.h>
// // #include <X11/Xlib.h>
// // #include <X11/Xatom.h>
// // #include <X11/Xutil.h>
// // #include <X11/cursorfont.h>
// // #include <X11/extensions/Xdbe.h>
// #endif


// int WD=320, HT=240, BITMAP=320*240, SCRWD=5, SCRHT=5, VECWD=240, VECHT=240, VECSTEP=4;

// #if defined(EMAX6)
// // #include "../../src/conv-c2c/emax6.h"
// //includeの順番が逆やとエラー
// #include "../Include/emax6_sparselib.h"
// // #include "./../../conv-c2c/emax6lib.c"
// #endif
// #if !defined(ARMSIML)
// // #include "./xdisp.c"
// #endif



// /* LMM:16KB, RMM:64KB: M/NCHIP=124 M/NCHIP/RMGRP=31 */
// /* A A   B B B B B B   C C C C C C */
// /* A A   B B B B B B   C C C C C C */
// /* A A                 C C C C C C */
// /* A A                 C C C C C C */
// /* L=2, A_row_size=4, B_col_size=6     L<A_row_size,B_col_size     */



//   #define A_row_size 768LL   // 縛りなし
//   #define A_col_size 780LL    // 縛りなし　H_padのおかげ
//   #define B_row_size 780LL    // 縛りなし
//   #define B_col_size 768LL   // RMGRP*NCHIP縛り
//   #define DIMENTION  2LL
//   // #define RMGRP 16
//   #define RMGRP 8
//   /*#define NCHIP 4*/
//   #define NCHIP 4
//   #define W  4LL
//   #define H  60
//   #define OOFS_SHIFT 3LL
//   #define A_col_blk 1


// Uint *A;  /*[A_row_size][L];*/
// Uint *B;  /*[L][B_col_size];*/
// Uint *C0; /*[A_row_size][B_col_size];*/
// Uint *C1; /*[A_row_size][B_col_size];*/
// Uint *sort_index;
// Uint *A_debug; /*[A_row_size][L];*/
// Uint *B_debug; /*[L][B_col_size];*/
// Uint *C_debug; /*[A_row_size][B_col_size];*/
// emax6_sparse2* A_sparse;
// emax6_param* params;
// int blk_iter;
// int row,row1, col, col1, n, n1;
// int top, blk;
// int w, h;
// int count0, count1, count2;
// int nnz_A=0,nnz_B=0,nnz_B_debug=0;
// double sum=0,sum1=0;


// #define CSIMWD 320
// #define CSIMHT 240
// #define CSIMBM (CSIMWD*CSIMHT)
// Uint Z[CSIMBM];

// #define ERRTH  (5.0E-3)
// #define udiff(a,b) (((a)-(b)>=0.0?(a)-(b):(b)-(a))/((a)==0.0?1:(a)))
// #define setmax(max, new) { if (max < (new)) max = (new); }

// #define MAXINT (~(1<<(sizeof(int)*8-1)))
// #define adif(a,b) (((a)>(b))?(a)-(b):(b)-(a))
// #define dif(a,b)  (adif((((a)>>24)&255), (((b)>>24)&255))\
//                   +adif((((a)>>16)&255), (((b)>>16)&255))\
//                   +adif((((a)>> 8)&255), (((b)>> 8)&255)))
// #define abs(a) (((a)<0)?-(a):(a))




// main()
// { //pointerでないので普通に足される。
//   // char* val;
//   // Uchar* membases = (Uchar*)malloc_test(sizeof(int)*10,&val);
//   // val = malloc_test(sizeof(int)*10);
//   // printf("malloc 10 %c \n",val[0]);
//   // printf("malloc size %d \n",malloc_usable_size(val));

//   Uchar* membase;
//   //A_colがHで割れないときのpadding
//   int A_H_pad = 0;
//   if((A_col_size%H) != 0) A_H_pad = -A_col_size%H + H;
//   sysinit((Uint)(2*(A_row_size*(A_col_size+A_H_pad))*sizeof(Uint)
//                 +(B_row_size+A_H_pad)*B_col_size*sizeof(Uint)
//                 +A_row_size*B_col_size*sizeof(Uint)
//                 // +A_row_size*B_col_size*sizeof(Uint)
//                 +A_row_size*sizeof(Uint)
//                 ),32,&membase);
//   printf("membase: %08.8x\n", (Uint)membase);
//   A  = (Uint*)membase;
//   B  = (Uint*)((Uchar*)A  + 2*(A_row_size*(A_col_size+A_H_pad))*sizeof(Uint));
//   C0 = (Uint*)calloc(A_row_size*B_col_size,sizeof(Uint));
//   C1 = (Uint*)((Uchar*)B  + B_row_size*B_col_size*sizeof(Uint));
//   sort_index = (Uint*)((Uchar*)C1 + A_row_size*B_col_size*sizeof(Uint));
  

//   B_debug  = (Uint*)calloc(2*B_row_size*B_col_size,sizeof(Uint));
//   C_debug = (Uint*)calloc(A_row_size*B_col_size,sizeof(Uint));
//   params = (emax6_param*) malloc(sizeof(emax6_param)*1);
//   params->A_row_size_param = A_row_size;
//   params->A_col_size_param = A_col_size;
//   params->B_row_size_param = B_row_size;
//   params->B_col_size_param = B_col_size;
//   params->A_row_blk_param = RMGRP;
//   params->NCHIP_param = NCHIP;
//   params->H_param = H;
//   params->W_param= W;
//   // params->W_param= W*2;
//   printf("A : %08.8x\n", A);
//   printf("B : %08.8x\n", B);
//   printf("C0: %08.8x\n", C0);
//   printf("C1: %08.8x\n", C1);
//   int tmp = 1,num = 0;
//   int* col_index_A = (int *)calloc(A_row_size*A_col_size,sizeof(int));
//   int* row_index_A = (int *)calloc(A_row_size*A_col_size,sizeof(int));
//   Uint* A_tmp = (Uint *)calloc(A_row_size*A_col_size,sizeof(Uint));
//     for (col=0; col<A_col_size; col++){
//       for (row=0; row<A_row_size; row++) {
//       tmp = (int) tmp;
//       tmp = (int) (rand()%2 == 0);
//       // rnad()%x 0~x-1の間の数字をとる
//       // tmp = (rand()%3 == 0)||(rand()%2);
//       *(float*)&A[row*A_col_size+col] = (float) (tmp);
//       // floatで等価の判断するの危険なので、LIMITで0判定をしている。
//       if(!((-LIMIT <= *(float*)&A_tmp[row+col*A_row_size]) && (*(float*)&A_tmp[row+col*A_row_size] <= LIMIT))){
//           col_index_A[nnz_A] = col;
//           row_index_A[nnz_A] = row;
//           nnz_A += 1;
//         }
//     }
//   }

//   reset_nanosec();


  
//   get_nanosec(0);
//   show_nanosec();

//   float val = 0;
//   for (row=0; row<B_row_size; row++) {
//     val += 1;
//     for (col=0; col<B_col_size; col++){
//       // *(float*)&B[col*B_col_size+row] = (float) tmp;
//       if(col%4 == 0){
//       *(float*)&B[col+row*B_col_size] = (float)1;
//       }
//       else{
//       *(float*)&B[col+row*B_col_size] = (float)0;
//       }
//       // if(!((-LIMIT <= *(float*)&B[col*B_col_size+row]) && (*(float*)&B[col*B_col_size+row] <= LIMIT))) nnz_B += 1; 
//       // if(!((-LIMIT <= *(float*)&B_debug[col*B_col_size+row]) && (*(float*)&B_debug[col*B_col_size+row] <= LIMIT))) nnz_B_debug += 1; 
//     }
//   }




//   if((int)sum != (int)sum1) {
//     fprintf(stderr,"sum != sum\n");
//     exit(1);
//   }



//   reset_nanosec();
//   // imax();
//   gemm_normal_CHIP_div_B(C1, A, B,params);
//   // sparse_gemm_736_736_736_CHIP_div_B_4(C1, A, B, A_sparse);
//   // sparse_multiply_imax6(nnz_A,A_sparse,B,C1,B_col_size,params);
//   get_nanosec(0);
//   show_nanosec();

//   reset_nanosec();
//   origB(A,B,C0);
//   get_nanosec(0);
//   show_nanosec();

//     sum = 0;
//     sum1 = 0;
//     for (col=0; col<B_col_size; col+=1){
//       for (row=0; row<A_row_size; row+=1) {
//         sum += *(float*)&C0[col+row*B_col_size];
//         sum1 += *(float*)&C1[col+row*B_col_size];
//         if (abs(*(float*)&C0[col+row*B_col_size] - *(float*)&C1[col+row*B_col_size])>1) {
//           count2++;

//           printf("C0[%d][%d]=%f C_debug[%d][%d]=%f\n", row, col, *(float*)&C0[col+row*B_col_size],
//                                                   row, col, *(float*)&C1[col+row*B_col_size]); 
//           // exit(1);       
//       }
//     }
//   }

//   printf("sum %f \n",sum);
//   printf("sum1 %f \n",sum1);
  
// free(A_tmp);




// }




// origB(Uint* A_orig,Uint* B_orig,Uint* C_orig) {
//   printf("<<<ORIG>>>\n");
//   for (row=0; row<A_row_size; row++) {
//     for (col=0; col<B_col_size; col++) {
//       for (n=0; n<A_col_size; n++) {
//         if (n==0) *(float*)&C_orig[row*B_col_size+col]  = *(float*)&A_orig[row*A_col_size+n] * *(float*)&B_orig[n*B_col_size+col];
//         else      *(float*)&C_orig[row*B_col_size+col] += *(float*)&A_orig[row*A_col_size+n] * *(float*)&B_orig[n*B_col_size+col];
//         count0++;
//         /*printf("[%d %d %d]", row, col, n);*/
//       }
//       /*printf("\n");*/
//     }
//   }
// }












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
#endif


int WD=320, HT=240, BITMAP=320*240, SCRWD=5, SCRHT=5, VECWD=240, VECHT=240, VECSTEP=4;

#if defined(EMAX6)
// #include "../../src/conv-c2c/emax6.h"
//includeの順番が逆やとエラー
#include "../Include/emax6_sparselib.h"
#ifndef NO_EMAX6LIB_BODY
#define NO_EMAX6LIB_BODY
#endif
#include "../Include/kernel_lib.h"
// #include "./../../conv-c2c/emax6lib.c"
#endif

#define CSIMWD 320
#define CSIMHT 240
#define CSIMBM (CSIMWD*CSIMHT)

main(int argc,char*argv[])
{   
Uint *A = NULL;  /*[A_row_size][L];*/
Uint *B = NULL;  /*[L][B_col_size];*/
Uint *C0 = NULL; /*[A_row_size][B_col_size];*/
Uint *C1 = NULL; /*[A_row_size][B_col_size];*/
Uint *Base_p = NULL;
Uint *sort_index = NULL;
Uint *A_debug = NULL; /*[A_row_size][L];*/
Uint *B_debug = NULL; /*[L][B_col_size];*/
Uint *C_debug = NULL; /*[A_row_size][B_col_size];*/
coo_format* coo = NULL;
emax6_sparse2* A_sparse = NULL;
emax6_param* params = NULL;
int blk_iter;
int mode,sparse_rate_len,sparse_rate_index = 0;
int row,row1, col, col1, n, n1;
int top, blk;
int w, h;
int count0, count1, count2;
int nnz_A=0,nnz_B=0,nnz_B_debug=0;
double sum=0,sum1=0;
FILE* fp;
Uint size_array_index,size_array_len;
Uint memsize_tmp;
Sll H;
Sll A_row_size_ini,A_row_size;
Sll A_col_size_ini,A_col_size;
Sll B_row_size_ini,B_row_size;
Sll B_col_size_ini,B_col_size;
Sll B_col_blk_ini ,B_col_blk ;
Sll NCHIP_ini     ,NCHIP     ;
Sll W_ini         ,W         ;
Sll A_col_blk_ini ,A_col_blk ;
Sll C_col_blk_ini ,C_col_blk ;
extern Ull nanosec[NANOS_CLASS];
Uint tmp;
float zero_bias = 0.0;
Sll A_H_pad = 0;


A_row_size_ini = A_row_size = 1080LL;
A_col_size_ini = A_col_size = 1080LL;
B_row_size_ini = B_row_size = 1080LL;
B_col_size_ini = B_col_size = 1080LL;
A_col_blk_ini  = A_col_blk  = 5LL  ;
B_col_blk_ini  = B_col_blk  = 8LL  ;
C_col_blk_ini  = C_col_blk  = 0LL  ;
NCHIP_ini      = NCHIP      = 4LL  ;
W_ini          = W          = 4LL  ;
params = (emax6_param*) malloc(sizeof(emax6_param)*1);
params->data_format = DENSE_DENSE;
params->mode = DENSE_NORMAL;
params->data_type = NORMAL;

switch(params->mode){
    case DENSE_DENSE:
        H = params->H_param = 60LL;
    break;
    case SPARSE_DENSE_46:
        H = params->H_param = 46LL;
    break;
    case SPARSE_DENSE_58_VER2:
    case SPARSE_DENSE_58_VER3:
        H =params->H_param = 58LL;
    break;
    default:
    printf("There isn`t this pattern\n");
    exit(1);
    
}
// size_array_len = 2;
// Uint size_array[1] = {32,64};
// sparse_rate_len = 7;
// float sparse_rate[7] = {0.3,0.3,0.3,0.3,0.3,0.3,0.3};
size_array_len = 5;
// Uint size_array[1] = {736};
Uint size_array[5] = {1024,512,256,128,64,32};
// Uint size_array[6] = {32,32,32,32,32,32};
sparse_rate_len = 10;
float sparse_rate[10] = {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
char* name = "result.csv";
if(argc == 2){name = argv[1];}
#if !defined(CSIMDEBUG)
if((fp=fopen(name,"w"))==NULL){
    fprintf(stderr,"cant open csv\n");
    exit(1);
}
#endif

#if !defined(CSIMDEBUG)
fprintf(fp,"LMM_usage_rate,LMM_usage_kbyte,LMM_usage_A_rate,LMM_usage_A_kbyte,LMM_usage_B_rate,LMM_usage_B_kbyte,sparse_rate,A_row_size,A_col_size,B_row_size,B_col_size,A_col_blk,B_col_blk,C_col_blk,NCHIP,W,ARM,DRAIN,CONF,REGV,RANGE,LOAD,EXEC,total\n");
#endif
//はみ出た時の拡張
Uchar* membase = NULL;
Uint memsize = (A_row_size*(A_col_size))*sizeof(Uint)
                +(B_row_size)*B_col_size*sizeof(Uint)
                +A_row_size*B_col_size*sizeof(Uint)
                // +A_row_size*B_col_size*sizeof(Uint)
                +A_row_size*sizeof(Uint)
                +8*sizeof(Uint)*sparse_rate_len;
                
memsize += ((memsize%32) != 0) ? (-memsize%32 + 32) : 0;
sysinit((Uint)memsize,32,&membase);
        //A_colがHで割れないときのpadding
for(size_array_index=0;size_array_index<size_array_len;size_array_index++){
  A_row_size = params->A_row_size_param = size_array[size_array_index];
  A_col_size = params->A_col_size_param = size_array[size_array_index];
  B_row_size = params->B_row_size_param = size_array[size_array_index];
  B_col_size = params->B_col_size_param = size_array[size_array_index];
  params->A_col_blk_param  = A_col_blk ;
  params->B_col_blk_param  = B_col_blk ;
  params->C_col_blk_param  = C_col_blk ;
  params->NCHIP_param      = NCHIP     ;
  params->W_param          = W         ;
  IMAX_param_tunig(params);


      // printf("LMM_usage_rate %2.2f LMM_usage_kbyte %2.1f sparse_rate %2.1f A_row_size %d A_col_size %d B_row_size %d B_col_size %d A_col_blk %d B_col_blk %d C_col_blk %d NCHIP %d W %d \n",

      printf("LMM_usage_rate %2.2f LMM_usage_kbyte %2.2f LMM_usage_A_rate %2.2f LMM_usage_A_kbyte %2.2f LMM_usage_B_rate %2.2f LMM_usage_B_kbyte %2.2f sparse_rate %2.1f A_row_size %d A_col_size %d B_row_size %d B_col_size %d A_col_blk %d B_col_blk %d C_col_blk %d NCHIP %d W %d \n",\
          params->LMM_usage_rate,params->LMM_usage_kbyte,\
          params->LMM_usage_A_rate,params->LMM_usage_A_kbyte,\
          params->LMM_usage_B_rate,params->LMM_usage_B_kbyte,\
          sparse_rate[sparse_rate_index],(int)A_row_size,(int) A_col_size,\
          (int)B_row_size,(int)B_col_size,\
          (int)params->A_col_blk_param,(int)params->B_col_blk_param,\
          (int)params->C_col_blk_param,(int)NCHIP,(int)W); 
      H = params->H_param;
      A_H_pad = ((A_col_size%H) != 0) ? -A_col_size%H + H : A_H_pad;

      
      Base_p  = (Uint*)((Uchar*)membase);
      A  = (Uint*)((Uchar*)Base_p);
      B  = (Uint*)((Uchar*)A  + (A_row_size*(A_col_size+A_H_pad))*sizeof(Uint));
      C1 = (Uint*)((Uchar*)B  + (B_row_size+A_H_pad)*B_col_size*sizeof(Uint)+8*sizeof(Uint)*sparse_rate_index);
      sort_index = (Uint*)((Uchar*)C1 + A_row_size*B_col_size*sizeof(Uint));
      C0 = (Uint*)calloc(A_row_size*B_col_size,sizeof(Uint));


      C_debug = (Uint*)calloc(A_row_size*B_col_size,sizeof(Uint));
      B_debug = (Uint*)calloc(B_col_size*B_row_size,sizeof(Uint));
      

      // make A sparse matrix with sparsity percent
      // coo = make_sparse_mat(params,0.1);
      // make B dense matrix for simd calculation
      for (row=0; row<A_row_size; row++) {
        for (col=0; col<A_col_size; col++)
          tmp = (rand()%(int)2);
          tmp = (tmp == 0);
          *(float*)&A[row*(A_col_size+A_H_pad)+col] = (float)tmp;

      }
      for (row=0; row<B_row_size; row++) {
        for (col=0; col<B_col_size; col++)
          tmp = (rand()%(int)2);
          tmp = (tmp == 0);
        * (float*)&B[row*B_col_size+ col] = (float)tmp;
      }


      reset_nanosec();
      sparse_gemm_CHIP_div_B(C1, A, B, A_sparse, params);
      get_nanosec(0);
      show_nanosec();
      #if !defined(CSIMDEBUG)
      fprintf(fp,"%2.2f,%2.2f,%2.2f,%2.2f,%2.2f,%2.2f,%2.2f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%llu,%llu,%llu,%llu,%llu,%llu,%llu,%llu\n",\
      params->LMM_usage_rate,params->LMM_usage_kbyte,\
      params->LMM_usage_A_rate,params->LMM_usage_A_kbyte,\
      params->LMM_usage_B_rate,params->LMM_usage_B_kbyte,\
      sparse_rate[sparse_rate_index],(int)A_row_size,(int) A_col_size,\
      (int)B_row_size,(int)B_col_size,\
      (int)params->A_col_blk_param,(int)params->B_col_blk_param,\
      (int)params->C_col_blk_param,(int)NCHIP,(int)W,\
      nanosec[NANOS_ARM],nanosec[NANOS_DRAIN],nanosec[NANOS_CONF],nanosec[NANOS_REGV],\
      nanosec[NANOS_RANGE],nanosec[NANOS_LOAD],nanosec[NANOS_EXEC],nanosec[NANOS_TOTAL]); 
      #endif


    //   orig(A,B,C0,params);
    //   sum = 0;
    //   sum1 = 0;
    //   for (col=0; col<B_col_size; col+=1){
    //       for (row=0; row<A_row_size; row+=1) {
    //           sum += *(float*)&C0[col+row*B_col_size];
    //           sum1 += *(float*)&C1[row*B_col_size+col];
    //           if (abs(*(float*)&C0[row*B_col_size+col] - *(float*)&C1[row*B_col_size+col])>1) {
    //               count2++;

    //               printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row, col, *(float*)&C0[row*B_col_size+col],
    //                                                   row, col, *(float*)&C1[row*B_col_size+col]);
    //               printf("sparse_rate_index %d \n",sparse_rate_index);                                        
    //               exit(1);
    //           }
    //       }
    //   }
      #if !defined(ARMZYNQ) && defined(EMAX6)
      if(abs(sum-sum1)>1){
          printf("sum %f \n",sum);
          printf("sum1 %f \n",sum1);
      }
      #endif
      // memory clean

      if(B_debug != NULL){
      free(B_debug);
      B_debug = NULL;
      }
      if(C0 != NULL){
      free(C0);
      C0 = NULL;
      }
      if(C_debug != NULL){
      free(C_debug);
      C_debug = NULL;
      }
      mem_release(memsize,&membase);
    

}
#if !defined(ARMZYNQ) && defined(EMAX6)
if(membase != NULL){
        free(membase);
        membase = NULL;
}
#endif
if(params != NULL){
    free(params);
    params = NULL;
}
#if !defined(CSIMDEBUG)
fclose(fp);
#endif
} // main











