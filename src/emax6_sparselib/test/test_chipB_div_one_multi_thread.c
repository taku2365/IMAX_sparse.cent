static char RcsHeader[] = "$Header: /usr/home/nakashim/proj-arm64/sample/mm_cnn_lf/RCS/mm.c,v 1.4 2018/02/04 10:28:53 nakashim Exp nakashim $";

/*                          Copyright (C) 2013- by NAIST */
/*                           Primary writer: Y.Nakashima */
/*                                  nakashim@is.naist.jp */
#define _GNU_SOURCE
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



Uint *A = NULL;  /*[A_row_size][L];*/
Uint *B = NULL;  /*[L][B_col_size];*/
Uint *C0 = NULL; /*[A_row_size][B_col_size];*/
Uint *C1 = NULL; /*[A_row_size][B_col_size];*/
Uint *sort_index = NULL;
Uint *A_debug = NULL; /*[A_row_size][L];*/
Uint *B_debug = NULL; /*[L][B_col_size];*/
Uint *C_debug = NULL; /*[A_row_size][B_col_size];*/
coo_format* coo = NULL;
emax6_sparse2* A_sparse = NULL;
int blk_iter;
int mode,sparse_rate_len,sparse_rate_index;
int row,row1, col, col1, n, n1;
int top, blk;
int w, h;
int count0, count1, count2;
int nnz_A=0,nnz_B=0,nnz_B_debug=0;
double sum=0,sum1=0;
float zero_bias = 0.0;
int index_tmp = 0;

#define CSIMWD 320
#define CSIMHT 240
#define CSIMBM (CSIMWD*CSIMHT)
// pthread_mutex_t mutexQueue[THREAD_NUM];
// pthread_cond_t condQueue;
void *memcpy_sub(void *arg)
{
	imax_buf *buf = (imax_buf*)arg;
    // cpu_set_t mask;
    // cpu_set_t get;
    // CPU_ZERO(&mask);
    // CPU_SET(buf->thread_id, &mask);
    //     //特定のCPUをセットする
    // if (pthread_setaffinity_np(pthread_self(), sizeof(mask), &mask) < 0) {
    //         fprintf(stderr, "set thread affinity failed\n");
    // }
    // pthread_mutex_lock(&mutexQueue[buf->thread_id]);
    // pthread_cond_wait(&condQueue, &mutexQueue[buf->thread_id]);
    int col,col1,row,row1,j,num;
    for (col=0,col1=0; col<buf->col_range_end/2;col1+=2,col+=1){
        for (row=0,row1=0; row<buf->row_size*2;row1+=1,row+=2) {
            #ifdef CSIMDEBUG
                printf("C in\n");
            #endif
            *(float*)&buf->dst[col1*buf->row_size+row1] = *(float*)&buf->src[col*2*buf->row_size+row];
            *(float*)&buf->dst[(col1+1)*buf->row_size+row1] = *(float*)&buf->src[col*2*buf->row_size+row+1];
             // printf("C1[%d][%d]=%f \n", row, col, (double)*(float*)&C1[col*A_row_size+row]);
    
        }
    }
    // num = sysconf(_SC_NPROCESSORS_CONF);
    // CPU_ZERO(&get);
    // //printfで確かめるためにgetに動いているCPU一覧を入れる
    // if (pthread_getaffinity_np(pthread_self(), sizeof(get), &get) < 0) {
    //     fprintf(stderr, "get thread affinity failed\n");
    // }
    // for (j = 0; j < num; j++) {
    //     if (CPU_ISSET(j, &get)) {
    //         printf("thread %d is running in processor %d\n", (int)pthread_self(), j);
    //     }
    // }
// pthread_mutex_unlock(&mutexQueue[buf->thread_id]);
return 0;
}

main()
{ 
Uint H;
Sll A_row_size_ini,A_row_size,A_row_size_pad;
Sll A_col_size_ini,A_col_size,A_col_size_pad;
Sll B_row_size_ini,B_row_size,B_row_size_pad;
Sll B_col_size_ini,B_col_size,B_col_size_pad;
Sll B_col_blk_ini ,B_col_blk ;
Sll NCHIP_ini     ,NCHIP     ;
Sll W_ini         ,W         ;
Sll A_col_blk_ini ,A_col_blk ;

A_row_size_ini = A_row_size = 512LL;
A_col_size_ini = A_col_size = 512LL;
B_row_size_ini = B_row_size = 512LL;
B_col_size_ini = B_col_size = 512LL;
A_col_blk_ini  = A_col_blk  = 5LL  ;
B_col_blk_ini  = B_col_blk  = 8LL  ;
NCHIP_ini      = NCHIP      = 1LL  ;
W_ini          = W          = 4LL  ;
// params = (emax6_param*) malloc(sizeof(emax6_param)*1);
emax6_param params;
params.data_format = DENSE_DENSE_FORMAT;
params.mode = DENSE_DENSE_MODE;
params.data_type = DENSE_TYPE;
H = get_H_param(&params);
params.data_format = DENSE_DENSE_FORMAT;
params.mode = DENSE_DENSE_MODE;
params.data_type = DENSE_TYPE;
H = get_H_param(&params);
// GET_PAD_SIZE(A_row_size_pad,A_row_size,H);
// GET_PAD_SIZE(A_col_size_pad,A_col_size,H);
// GET_PAD_SIZE(B_row_size_pad,B_row_size,H);
// GET_PAD_SIZE(B_col_size_pad,B_col_size,(W*2));
// params.data_format = JDS_INDEX_VAL_SET_FORMAT;
// params.mode = SPARSE_DENSE_58_VER2_MODE;
// params.data_type = SPARSE_TYPE;
A_row_size_pad = A_row_size;
GET_PAD_SIZE(B_col_size_pad,B_col_size,(W*2));
GET_PAD_SIZE(A_col_size_pad,A_col_size,H);
if(params.mode == DENSE_DENSE_MODE){
    GET_PAD_SIZE(B_row_size_pad,B_row_size,H);
}
else{
    B_row_size_pad = B_row_size;    
}

float sparse_rate[12] = {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.85,0.9,0.95};
// float sparse_rate[4] = {0,0.3,0.5,0.9};
sparse_rate_index = 0;

//はみ出た時の拡張
Uchar* membase = NULL;
Uint memsize = 2*(A_row_size*(A_col_size_pad))*sizeof(Uint)
            +(B_row_size_pad)*(B_col_size_pad)*sizeof(Uint)
            +A_row_size*(B_col_size_pad)*sizeof(Uint)
            // +A_row_size*B_col_size*sizeof(Uint)
            +A_row_size*sizeof(Uint)
            ;
sysinit((Uint)memsize,32,&membase);
    //A_colがHで割れないときのpadding
        
params.A_row_size_param = A_row_size;
params.A_col_size_param = A_col_size;
params.B_row_size_param = B_row_size;
params.B_col_size_param = B_col_size;
params.A_row_size_pad_param = A_row_size_pad;
params.A_col_size_pad_param = A_col_size_pad;
params.B_row_size_pad_param = B_row_size_pad;
params.B_col_size_pad_param = B_col_size_pad;
params.A_col_blk_param  = A_col_blk ;
params.B_col_blk_param  = B_col_blk ;
params.NCHIP_param      = NCHIP     ;
params.W_param          = W         ;
IMAX_param_tunig(&params);
PRINT_PARAM(params);
H = params.H_param;
A  = (Uint*)membase;
B  = (Uint*)((Uchar*)A  + 2*(A_row_size*(A_col_size_pad))*sizeof(Uint));
C1 = (Uint*)((Uchar*)B  + (B_row_size_pad)*(B_col_size_pad)*sizeof(Uint));
sort_index = (Uint*)((Uchar*)C1 + A_row_size*(B_col_size_pad)*sizeof(Uint));
C0 = (Uint*)calloc(A_row_size*(B_col_size_pad),sizeof(Uint));


C_debug = (Uint*)calloc(A_row_size*(B_col_size_pad),sizeof(Uint));
B_debug = (Uint*)calloc((B_col_size_pad)*(B_row_size_pad),sizeof(Uint));


// make A sparse matrix with sparsity percent
coo = make_mat(&params,sparse_rate[sparse_rate_index],zero_bias,NULL);
// coo = make_sparse_mat(params,0.1);
// make B dense matrix for simd calculation
make_random_mat(&params,B,B_debug);

if(coo == NULL){
fprintf(stderr,"coo NULL \n");
}
if(params.mode == DENSE_DENSE_MODE){
    for(index_tmp=0;index_tmp<(A_row_size_pad*(A_col_size_pad));index_tmp++){
        *(float*)&A[index_tmp] = *(float*)&coo->val[index_tmp];
    }
}
reset_nanosec();
A_sparse = sparse_format(coo->nnz,A,coo->val,coo->col_index,coo->row_index,A_row_size,A_col_size,&params,sort_index,"/home/takuya-s/IMAX_sparse.cent/sample/test/sparse_data.wb",0);
// exit(1);
get_nanosec(0);
show_nanosec();

reset_nanosec();

sparse_gemm_CHIP_div_B(C1, A, B, A_sparse, &params);
get_nanosec(0);
show_nanosec();

orig(coo->val,B_debug,C0,&params);

printf("Reshape\n");
reset_nanosec();
#define THREAD_NUM 4
imax_buf taskQueue[THREAD_NUM];
pthread_t th[THREAD_NUM];
int taskCount = 0;

int total_size = A_row_size*(B_col_size_pad);
for (index_tmp = 0; index_tmp < THREAD_NUM; index_tmp++) {
    taskQueue[index_tmp].src = C1+index_tmp*total_size/THREAD_NUM;
    taskQueue[index_tmp].dst = C_debug+index_tmp*total_size/THREAD_NUM;
    taskQueue[index_tmp].row_size = A_row_size;
    taskQueue[index_tmp].thread_id = index_tmp;
    // taskQueue[index_tmp].row_range_end = A_row_size;
    taskQueue[index_tmp].col_range_end = (B_col_size_pad)/THREAD_NUM;
        if (pthread_create(&th[index_tmp], NULL, &memcpy_sub,&taskQueue[index_tmp]) != 0) {
            perror("Failed to create the thread");
        }
}
// pthread_cond_broadcast(&condQueue);


for (index_tmp = 0; index_tmp < THREAD_NUM; index_tmp++) {
    if (pthread_join(th[index_tmp], NULL) != 0) {
        perror("Failed to join the thread");
    }
}

// for (col=0,col1=0; col<(B_col_size_pad)/2;col1+=2,col+=1){
//     for (row=0,row1=0; row<2*A_row_size;row1+=1,row+=2) {
//         count2++;
//     #ifdef CSIMDEBUG
//         printf("C in\n");
//     #endif
//         *(float*)&C_debug[col1*A_row_size+row1] = *(float*)&C1[col*2*A_row_size+row];
//         *(float*)&C_debug[(col1+1)*A_row_size+row1] = *(float*)&C1[col*2*A_row_size+row+1];
//         // printf("C1[%d][%d]=%f \n", row, col, (double)*(float*)&C1[col*A_row_size+row]);
    
//     }
// }


get_nanosec(0);
show_nanosec();

sum = 0;
sum1 = 0;
for (col=0; col<(B_col_size_pad); col+=1){
    for (row=0; row<A_row_size; row+=1) {
    sum += *(float*)&C0[col+row*(B_col_size_pad)];
    sum1 += *(float*)&C_debug[col*A_row_size+row];
    if (abs(*(float*)&C0[col*A_row_size+row] - *(float*)&C_debug[col*A_row_size+row])>1) {
        count2++;

        printf("C0[%d][%d]=%f C_debug[%d][%d]=%f\n", row, col, *(float*)&C0[col*A_row_size+row],
                                                row, col, *(float*)&C_debug[col*A_row_size+row]);                                        
        exit(1);       
    }
}
}
#if !defined(ARMZYNQ) && defined(EMAX6)
if(abs(sum-sum1)>1){
printf("sum %f \n",sum);
printf("sum1 %f \n",sum1);
exit(1);
}
#endif
// memory clean
free_sparse_mat(coo);
free_sparse_format(A_sparse);

if(B_debug != NULL){
free(B_debug);
B_debug = NULL;
}
if(C_debug != NULL){
free(C_debug);
C_debug = NULL;
}
if(C0 != NULL){
free(C0);
C0 = NULL;
}
mem_release(memsize,&membase);

#if !defined(ARMZYNQ) && defined(EMAX6)
if(membase != NULL){
    free(membase);
    membase = NULL;
}
#endif
} // main





