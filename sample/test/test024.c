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
// #include <X11/Xlib.h>
// #include <X11/Xatom.h>
// #include <X11/Xutil.h>
// #include <X11/cursorfont.h>
// #include <X11/extensions/Xdbe.h>
// #endif


// int WD=320, HT=240, BITMAP=320*240, SCRWD=5, SCRHT=5, VECWD=240, VECHT=240, VECSTEP=4;

// #if defined(EMAX6)
// // #include "../../src/conv-c2c/emax6.h"
// //includeの順番が逆やとエラー
// #include "../../src/emax6_sparselib/Include/emax6_sparselib.h"
// // #include "./../../conv-c2c/emax6lib.c"
// #endif
// #if !defined(ARMSIML)
// #include "./xdisp.c"
// #endif



// /* LMM:16KB, RMM:64KB: M/NCHIP=124 M/NCHIP/RMGRP=31 */
// /* A A   B B B B B B   C C C C C C */
// /* A A   B B B B B B   C C C C C C */
// /* A A                 C C C C C C */
// /* A A                 C C C C C C */
// /* L=2, A_row_size=4, B_col_size=6     L<A_row_size,B_col_size     */



//   #define A_row_size 786LL
//   #define A_col_size 736LL
//   #define B_row_size 736LL
//   #define B_col_size 736LL
//   #define DIMENTION  2LL
//   // #define RMGRP 16
//   #define RMGRP 8
//   /*#define NCHIP 4*/
//   #define NCHIP 4
//   #define W  4LL
//   #define H  46
//   #define OOFS_SHIFT 3LL


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
//                 +B_row_size*B_col_size*sizeof(Uint)
//                 +A_row_size*B_col_size*sizeof(Uint)
//                 +A_row_size*B_col_size*sizeof(Uint)
//                 +A_row_size*sizeof(Uint)
//                 ),32,&membase);
//   printf("membase: %08.8x\n", (Uint)membase);
//   A  = (Uint*)membase;
//   B  = (Uint*)((Uchar*)A  + 2*(A_row_size*(A_col_size+A_H_pad))*sizeof(Uint));
//   C0 = (Uint*)((Uchar*)B  + B_row_size*B_col_size*sizeof(Uint));
//   C1 = (Uint*)((Uchar*)C0 + A_row_size*B_col_size*sizeof(Uint));
//   sort_index = (Uint*)((Uchar*)C1 + A_row_size*B_col_size*sizeof(Uint));
  

//   B_debug  = (Uint*)calloc(2*B_row_size*B_col_size,sizeof(Uint));
//   C_debug = (Uint*)calloc(A_row_size*B_col_size,sizeof(Uint));
//   params = (emax6_param*) malloc(sizeof(emax6_param)*1);
//   params->RMGRP_param = RMGRP;
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
//       *(float*)&A_tmp[row+col*A_row_size] = (float) (1);
//       // floatで等価の判断するの危険なので、LIMITで0判定をしている。
//       if(!((-LIMIT <= *(float*)&A_tmp[row+col*A_row_size]) && (*(float*)&A_tmp[row+col*A_row_size] <= LIMIT))){
//           col_index_A[nnz_A] = col;
//           row_index_A[nnz_A] = row;
//           nnz_A += 1;
//         }
//     }
//   }

//   reset_nanosec();

 
//   A_sparse = sparse_format6(nnz_A,A,A_tmp,col_index_A,row_index_A,A_row_size,A_col_size,params,sort_index,"/home/takuya-s/IMAX_sparse.cent/sample/test/sparse_data.wb",0);


  
//   get_nanosec(0);
//   show_nanosec();


//   for (row=0; row<B_row_size; row++) {
//     for (col=0; col<B_col_size; col++){
//       float tmp = row+col;
//       // *(float*)&B[col*B_col_size+row] = (float) tmp;
//       if(col%4 == 0){
//       *(float*)&B_debug[col*B_row_size+row] = (float)1;
//       }
//       else{
//         *(float*)&B_debug[col*B_row_size+row] = (float)1;
//       }
//       // if(!((-LIMIT <= *(float*)&B[col*B_col_size+row]) && (*(float*)&B[col*B_col_size+row] <= LIMIT))) nnz_B += 1; 
//       // if(!((-LIMIT <= *(float*)&B_debug[col*B_col_size+row]) && (*(float*)&B_debug[col*B_col_size+row] <= LIMIT))) nnz_B_debug += 1; 
//     }
//   }



//     for (col=0,col1=0; col<B_col_size/2; col+=1,col1+=2){
//       for (row=0,row1=0; row1<B_row_size; row+=2,row1+=1) {
//         // simdを使うため
//       *(float*)&B[col*2*B_row_size+row] = *(float*)&B_debug[col1*B_row_size+row1];
//       *(float*)&B[col*2*B_row_size+row+1] = *(float*)&B_debug[(col1+1)*B_row_size+row1];
//     }
//   }
  
//     for (col=0; col<B_col_size; col++){
//       for (row=0; row<B_row_size; row++) {
//         // simdを使うため
//         sum += *(float*)&B_debug[col*B_row_size+row];
//         sum1 += *(float*)&B[col*B_row_size+row];
//     }
//   }

//   if((int)sum != (int)sum1) {
//     fprintf(stderr,"sum != sum\n");
//     exit(1);
//   }
                                                                                                                  
//                                      //  nanosec: ARM:14476178 DRAIN:0 CONF:0 REGV:0 RANGE:0 LOAD:0 EXEC:0  total:14476178 //format
// // nanosec: ARM:428330 DRAIN:5347764 CONF:103059 REGV:15701836 RANGE:10177188 LOAD:42058397 EXEC:10241348 total:84057922 4chip 密
// // nanosec: ARM:643720 DRAIN:3900830 CONF:139645 REGV:22034423 RANGE:12112945 LOAD:81180395 EXEC:20458796  total:140470754  密
// // nanosec: ARM:284607 DRAIN:5347242 CONF:104924 REGV:34797322 RANGE:10362789 LOAD:74936785 EXEC:10831409  total:136665078
// // nanosec: ARM:697759 DRAIN:3912415 CONF:144105 REGV:36137979 RANGE:12767833 LOAD:144809961　EXEC:21722040 total:220192092 そのまま計算
// // nanosec: ARM:228882 DRAIN:1898495 CONF:96632 REGV:27163829 RANGE:8146254 LOAD:28577880 EXEC:7937346     total:74049318
// // nanosec: ARM:523872 DRAIN:3860935 CONF:124981 REGV:27126625 RANGE:9538279 LOAD:109312336 EXEC:15392081  total:165879109  2/3
// // nanosec: ARM:179727 DRAIN:5271546 CONF:87108 REGV:19541144 RANGE:5845150 LOAD:43363760 EXEC:5812181     total:80100616 4chip %2
// // nanosec: ARM:183810 DRAIN:5271064 CONF:87208 REGV:19602317 RANGE:5766538 LOAD:43357904 EXEC:5827063     total:80095904 4chip  %2 forの順番入れ替え
// // nanosec: ARM:406986 DRAIN:3818889 CONF:110080 REGV:20350376 RANGE:7143744 LOAD:82684247 EXEC:11680525   total:126194847 %2
// // nanosec: ARM:318687 DRAIN:3793709 CONF:100085 REGV:15827467 RANGE:5573393 LOAD:64865556 EXEC:8321523    total:98800420 %3
// // nanosec: ARM:197559 DRAIN:3747668 CONF:85619 REGV:9034281 RANGE:3180254 LOAD:38802744 EXEC:5216107      total:60264232 //2.33 %4
// // nanosec: ARM:201870 DRAIN:3755070 CONF:84790 REGV:9040110 RANGE:3187043 LOAD:38284119 EXEC:5230658      total:59783660 %5
// // nanosec: ARM:201605 DRAIN:3751573 CONF:84941 REGV:9047404 RANGE:3170832 LOAD:38262244 EXEC:4460222      total:58978821 %6
// // nanosec: ARM:152969 DRAIN:3738010 CONF:80459 REGV:6775409 RANGE:2385811 LOAD:29399387 EXEC:4009696      total:46541741 %7
// // nanosec: ARM:154852 DRAIN:3737772 CONF:81778 REGV:6785112 RANGE:2377742 LOAD:29789329 EXEC:3514694      total:46441279 //3.02 %8
// // nanosec: ARM:161484 DRAIN:3740919 CONF:80551 REGV:6781150 RANGE:2391537 LOAD:29382167 EXEC:3101214      total:45639022 %9
// // nanosec: ARM:104578 DRAIN:5207871 CONF:73289 REGV:6516141 RANGE:1944812 LOAD:16307317 EXEC:1545583      total:31699591
// // nanosec: ARM:80258 DRAIN:5209217 CONF:72478 REGV:6516916 RANGE:1970062 LOAD:16281524  EXEC:1546550      total:31677005
// // nanosec: ARM:9881990142 DRAIN:0 CONF:0 REGV:0 RANGE:0 LOAD:0 EXEC:0 total:9881990142


// // nanosec: ARM:46525 DRAIN:5433830 CONF:69457 REGV:3404251 RANGE:1016464 LOAD:8883664 EXEC:1945807 total:20799998 [736][96][96][736] sparse_gemm_736_1_ver
// // nanosec: ARM:46333 DRAIN:5437919 CONF:69627 REGV:3404969 RANGE:1011242 LOAD:8888286 EXEC:1945960 total:20804336 同じ　　　　　　　　 sparse_gemm_736_2_ver
//   reset_nanosec();
//   orig(A_tmp,B_debug,C0);
//   get_nanosec(0);
//   show_nanosec();

//   reset_nanosec();
//   // imax();
//   // sparse_gemm_768_96_96_768_1(C1, A, B, A_sparse);
//   sparse_multiply_imax4(nnz_A,A_sparse,B,C1,B_col_size,params);
//   get_nanosec(0);
//   show_nanosec();

//   //   sum = 0;
//   //   sum1 = 0;

//   //   for (col=0,col1=0; col<B_col_size; col+=1,col1+=2){
//   //     for (row=0,row1=0; row1<A_row_size; row+=1,row1+=1) {
//   //         count2++;
//   //         sum += *(float*)&C0[col+row*B_col_size];
//   //         sum1 += *(float*)&C1[col+row*B_col_size];
//   //         // printf("C0[%d][%d]=%f \n", row, col, (double)*(float*)&C0[col+row*B_col_size]);
     
//   //   }
//   // }
//   // printf("sum %f \n",sum);
//   // printf("sum1 %f \n",sum1);
//   // count2 = 0;

//     for (col=0,col1=0; col<B_col_size/2;col1+=2,col+=1){
//       for (row=0,row1=0; row<2*A_row_size;row1+=1,row+=2) {
//           count2++;
//            *(float*)&C_debug[col1*A_row_size+row1] = *(float*)&C1[col*2*A_row_size+row];
//            *(float*)&C_debug[(col1+1)*A_row_size+row1] = *(float*)&C1[col*2*A_row_size+row+1];
//           // printf("C1[%d][%d]=%f \n", row, col, (double)*(float*)&C1[col*A_row_size+row]);
     
//     }
//   }
//   printf("count2 %d \n",count2);

//     sum = 0;
//     sum1 = 0;
//     for (col=0; col<B_col_size; col+=1){
//       for (row=0; row<A_row_size; row+=1) {
//         sum += *(float*)&C0[col+row*B_col_size];
//         sum1 += *(float*)&C_debug[col*A_row_size+row];
//         if (abs(*(float*)&C0[col*A_row_size+row] - *(float*)&C_debug[col*A_row_size+row])>1) {
//           count2++;

//           printf("C0[%d][%d]=%f C_debug[%d][%d]=%f\n", row, col, *(float*)&C0[col*A_row_size+row],
//                                                   row, col, *(float*)&C_debug[col*A_row_size+row]); 
//           // exit(1);       
//       }
//     }
//   }

//   printf("sum %f \n",sum);
//   printf("sum1 %f \n",sum1);
  
// free(A_tmp);




// }




// orig(Uint* A_orig,Uint* B_orig,Uint* C_orig) {
//   printf("<<<ORIG>>>\n");
//   for (row=0; row<A_row_size; row++) {
//     for (col=0; col<B_col_size; col++) {
//       for (n=0; n<A_col_size; n++) {
//         if (n==0) *(float*)&C_orig[row+col*A_row_size]  = *(float*)&A_orig[row+n*A_row_size] * *(float*)&B_orig[n+col*B_row_size];
//         else      *(float*)&C_orig[row+col*A_row_size] += *(float*)&A_orig[row+n*A_row_size] * *(float*)&B_orig[n+col*B_row_size];
//         count0++;
//         /*printf("[%d %d %d]", row, col, n);*/
//       }
//       /*printf("\n");*/
//     }
//   }
// }




