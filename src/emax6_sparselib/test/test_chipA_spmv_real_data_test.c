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
int blk_iter;
int mode,sparse_rate_len,sparse_rate_index;
int row,row1, col, col1, n, n1;
int top, blk;
int w, h;
int count0, count1, count2;
int nnz_A=0,nnz_B=0,nnz_B_debug=0;
double sum=0,sum1=0;
FILE* fp,*fp1,*fp1_tmp;
Uint size_array_index,size_array_len;
Uint memsize_tmp;
Sll H;
Sll A_row_size_ini,A_row_size,A_row_size_pad;
Sll A_col_size_ini,A_col_size,A_col_size_pad;
Sll B_row_size_ini,B_row_size,B_row_size_pad;
Sll B_col_size_ini,B_col_size,B_col_size_pad;
Sll B_col_blk_ini ,B_col_blk ;
Sll NCHIP_ini     ,NCHIP     ;
Sll W_ini         ,W         ;
Sll A_col_blk_ini ,A_col_blk ;
Sll C_col_blk_ini ,C_col_blk ;
extern Ull nanosec[NANOS_CLASS];
Uint tmp = 0;
float zero_bias = 0.0;
int index_tmp = 0;
char* data_name = NULL;
char* store_name = "result/result.csv";
A_row_size_ini = A_row_size = 1024*8LL;
A_col_size_ini = A_col_size = 1024*8LL;
B_row_size_ini = B_row_size = 1024*8LL;
B_col_size_ini = B_col_size = 1LL;

A_col_blk_ini  = A_col_blk  = 5LL  ;
B_col_blk_ini  = B_col_blk  = 8LL  ;
C_col_blk_ini  = C_col_blk  = 0LL  ;
NCHIP_ini      = NCHIP      = 1LL  ;
W_ini          = W          = 4LL  ;
// params = (emax6_param*) malloc(sizeof(emax6_param)*1);
emax6_param params;

params.mode = SPARSE_DENSE_58_SPMV_MODE;
params.data_format = CSR_INDEX_VAL_SET_SPMV_FORMAT;
params.data_type = REAL_DATA_TYPE;

// params.mode = DENSE_SPMV_MODE;
// params.data_format = DENSE_DENSE_SPMV_FORMAT;
// params.data_type = REAL_DATA_TYPE;

// 43686119
// 1418588
// 1508967
// params.data_format = DENSE_DENSE_FORMAT;
// params.mode = DENSE_DENSE_MODE;
// params.data_type = DENSE_TYPE;

H = get_H_param(&params);
// size_array_len = 2;
// Uint size_array[1] = {32,64};
// sparse_rate_len = 7;
// float sparse_rate[7] = {0.3,0.3,0.3,0.3,0.3,0.3,0.3};
size_array_len = 6;
Uint size_array[6] = {1003,512,256,128,64,32};
// size_array_len = 1;
// Uint size_array[1] = {32};
// Uint size_array[6] = {32,32,32,32,32,32};
sparse_rate_len = 12;
float sparse_rate[12] = {0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.85,0.9,0.95};
sparse_rate_index = 0;
if(params.mode == DENSE_SPMV_MODE){
    sparse_rate_len = 1;
    sparse_rate[0] = 0.0;
}
GET_PAD_SIZE(A_row_size_pad,1024*8,H);
GET_PAD_SIZE(A_col_size_pad,1024*8,H);
if(params.mode == DENSE_SPMV_MODE){
    GET_PAD_SIZE(A_row_size_pad,A_row_size,(W*2));
    GET_PAD_SIZE(B_row_size_pad,1024*8,H);
}
else if(params.mode == SPARSE_DENSE_58_SPMV_MODE){
    GET_PAD_SIZE(A_row_size_pad,A_row_size,W);
    B_row_size_pad = 1024*8;  
}
else{
    fprintf("future work spmv_size_test %d \n",__LINE__);
    exit(1);
}

B_col_size_pad = 1;
argc--;
if(argc == 1){
    store_name = argv[1]; 
}
else if(argc == 2){
    store_name = argv[1]; 
    data_name = argv[2]; 
}
#if !defined(CSIMDEBUG)
if(argc == 1){
    store_name = argv[1]; 
}
else if(argc == 2){
    store_name = argv[1]; 
    data_name = argv[2]; 
}
#if !defined(CSIMDEBUG)
if((fp=fopen(store_name,"w"))==NULL){
    fprintf(stderr,"cant open csv\n");
    exit(1);
}
if((fp1=fopen(data_name,"r"))==NULL){
    fprintf(stderr,"cant open data set\n");
    exit(1);
}

#endif

#endif

#if !defined(CSIMDEBUG)
STORE_CSV_INI(fp);
#endif
//はみ出た時の拡張
Uchar* membase = NULL;
Uint memsize = 2*(A_row_size_pad*(A_col_size_pad))*sizeof(Uint)
                +(B_row_size_pad)*(B_col_size_pad)*sizeof(Uint)
                +A_row_size_pad*(B_col_size_pad)*sizeof(Uint)
                // +A_row_size*B_col_size*sizeof(Uint)
                +A_row_size_pad*sizeof(Uint)
                +8*sizeof(Uint)*sparse_rate_len;
                
memsize += ((memsize%32) != 0) ? (-memsize%32 + 32) : 0;
sysinit((Uint)memsize,32,&membase);
//fpをparam取得まで進める
fp1_tmp = get_param_from_dataset(&params,fp1);
A_row_size = params.A_row_size_param;
A_col_size = params.A_col_size_param;
B_row_size = params.B_row_size_param;
B_col_size = params.B_col_size_param = 1;
B_col_size_pad = params.B_col_size_pad_param = 1;

H = params.H_param;
// GET_PAD_SIZE(A_col_size_pad,A_col_size,H);
// GET_PAD_SIZE(B_col_size_pad,B_col_size,(W*2));
A_row_size_pad = params.A_row_size_pad_param;
A_col_size_pad = params.A_col_size_pad_param;
B_row_size_pad = params.B_row_size_pad_param;
params.A_col_blk_param  = A_col_blk ;
params.B_col_blk_param  = B_col_blk ;
params.C_col_blk_param  = C_col_blk ;
params.NCHIP_param      = NCHIP     ;
params.W_param          = W         ;
IMAX_param_tunig(&params);

PRINT_PARAM(params);

Base_p  = (Uint*)((Uchar*)membase);
A  = (Uint*)((Uchar*)Base_p);
B  = (Uint*)((Uchar*)A  + 2*(A_row_size_pad*(A_col_size_pad))*sizeof(Uint));
//aligmentを8byteにしないとバグる
GET_PAD_SIZE(tmp,(B_row_size_pad)*(B_col_size_pad)*sizeof(Uint),8);
C1 = (Uint*)((Uchar*)B  + tmp + 8*sizeof(Uint)*sparse_rate_index);
GET_PAD_SIZE(tmp,A_row_size_pad*(B_col_size_pad)*sizeof(Uint),8);
sort_index = (Uint*)((Uchar*)C1 + tmp);
C0 = (Uint*)calloc(A_row_size_pad*(B_col_size_pad),sizeof(Uint));


C_debug = (Uint*)calloc(A_row_size_pad*(B_col_size_pad),sizeof(Uint));
B_debug = (Uint*)calloc((B_col_size_pad)*(B_row_size_pad),sizeof(Uint));

make_random_mat(&params,B,B_debug);

coo = make_mat(&params,sparse_rate[sparse_rate_index],zero_bias,fp1_tmp);
if(coo == NULL){
    fprintf(stderr,"coo NULL \n");
    exit(1);
}

if((params.mode == DENSE_DENSE_MODE)||(params.mode == DENSE_SPMV_MODE)){
    for(index_tmp=0;index_tmp<(A_row_size_pad*A_col_size_pad);index_tmp++){
        *(float*)&A[index_tmp] = *(float*)&coo->val[index_tmp];
    }
}   

//疎行列取得

reset_nanosec();
A_sparse = sparse_format(coo->nnz,A,coo->val,coo->col_index,coo->row_index,A_row_size_pad,A_col_size,&params,sort_index,"/home/takuya-s/IMAX_sparse.cent/sample/test/sparse_data.wb",0);
get_nanosec(0);
show_nanosec();
reset_nanosec();
sparse_spmv_CHIP_div_A(C1, A, B, A_sparse, &params);
get_nanosec(0);
show_nanosec();

#if !defined(CSIMDEBUG)
STORE_CSV(fp,sparse_rate_index);
#endif

orig(coo->val,B_debug,C0,&params);
sum = 0;
sum1 = 0;
for (row=0,row1=0; row<A_row_size_pad;row+=1) {
        count2++;
    #ifdef CSIMDEBUG
        printf("C in\n");
    #endif
    *(float*)&C_debug[row] = *(float*)&C1[row];
    // printf("C1[%d][%d]=%f \n", row, col, (double)*(float*)&C1[col*A_row_size_pad+row]);
    
}

for (col=0; col<(B_col_size_pad); col+=1){
    for (row=0; row<A_row_size_pad; row+=1) {
        sum += *(float*)&C0[col+row*(B_col_size_pad)];
        sum1 += *(float*)&C_debug[col*A_row_size_pad+row];
        if (abs(*(float*)&C0[col*A_row_size_pad+row] - *(float*)&C_debug[col*A_row_size_pad+row])>1) {
            count2++;

            printf("C0[%d][%d]=%f C_debug[%d][%d]=%f\n", row, col, *(float*)&C0[col*A_row_size_pad+row],
                                                row, col, *(float*)&C_debug[col*A_row_size_pad+row]);
            exit(1);
        }
    }
}
printf("sum %f \n",sum);
printf("sum1 %f \n",sum1);

#if !defined(ARMZYNQ) && defined(EMAX6)
if(abs(sum-sum1)>1){
    printf("sum %f \n",sum);
    printf("sum1 %f \n",sum1);
}
#endif
free_sparse_mat(coo);
free_sparse_format(A_sparse);
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
// memory clean

#if !defined(ARMZYNQ) && defined(EMAX6)
if(membase != NULL){
        free(membase);
        membase = NULL;
}
#endif
#if !defined(CSIMDEBUG)
if(fp != NULL){
fclose(fp);
fp = NULL;
}
if(fp1_tmp != NULL){
fclose(fp1_tmp);
fp1_tmp = NULL;
}
#endif
} // main





