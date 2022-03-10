static char RcsHeader[] = "$Header: /usr/home/nakashim/proj-arm64/sample/mm_cnn_lf/RCS/mm.c,v 1.4 2018/02/04 10:28:53 nakashim Exp nakashim $";

/*                          Copyright (C) 2013- by NAIST */
/*                           Primary writer: Y.Nakashima */
/*                                  nakashim@is.naist.jp */


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
int row,row1, col, col1, n, n1;
int count0, count1, count2;
double sum=0,sum1=0;
FILE* fp,*fp1,*fp1_tmp;
Uint memsize_tmp;
Uint H;
size_t A_row_size,A_row_size_pad;
size_t A_col_size,A_col_size_pad;
size_t B_row_size,B_row_size_pad;
size_t B_col_size,B_col_size_pad;
size_t B_col_blk_ini ,B_col_blk ;
size_t NCHIP = 1                ;
size_t W                        ;
size_t A_col_blk                ;
size_t C_col_blk                ;
extern Ull nanosec[NANOS_CLASS];
Uint tmp = 0;
float zero_bias = 0.0;
int index_tmp = 0;
char* data_name = NULL;
char* store_name = "result/result.csv";
Uint data_index = 0;
int sparse_rate_index = 0;
float sparse_rate[1] = {0.0};
emax6_param params;
init_param init_params;

params.mode = SPARSE_DENSE_58_SPMV_MODE;
params.data_format = JDS_INDEX_VAL_SET_SPMV_FORMAT;
params.data_type = REAL_DATA_TYPE;

// params.mode = SPARSE_DENSE_58_SPMV_MODE;
// params.data_format = CSR_INDEX_VAL_SET_SPMV_FORMAT;
// params.data_type = REAL_DATA_TYPE;

// params.mode = DENSE_SPMV_MODE;
// params.data_format = DENSE_DENSE_SPMV_FORMAT;
// params.data_type = REAL_DATA_TYPE;

// 43686119
// 1418588
// 1508967
// params.data_format = DENSE_DENSE_FORMAT;
// params.mode = DENSE_DENSE_MODE;
// params.data_type = DENSE_TYPE;



params.mode = DENSE_SPMV_MODE;
params.data_format = DENSE_DENSE_SPMV_FORMAT;
params.data_type = REAL_DATA_TYPE;

init_params.mode = INITIAL_MEMBASE_WITH_MAT_LEN;
init_params.init_allocate_mat_len = 6000;
get_param(&params,&init_params);
Uchar* membase = NULL;
Uint memsize;
membase = init_params.membase;
memsize = init_params.memsize;
argc--;


#if !defined(CSIMDEBUG)
if(argc == 0){
    store_name = "./result/result.csv";
    data_name = "./data/reorientation_7/reorientation_7.mtx" ;
}
else if(argc == 1){
    store_name = argv[1];
    data_name = "./data/reorientation_7/reorientation_7.mtx" ;
}
else if(argc == 2){
    store_name = argv[1]; 
    data_name = argv[2]; 
}
if((fp=fopen(store_name,"w"))==NULL){
    fprintf(stderr,"cant open csv\n");
    exit(1);
}
if((fp1=fopen(data_name,"r"))==NULL){
    fprintf(stderr,"cant open data set\n");
    exit(1);
}
#endif

#if !defined(CSIMDEBUG)
STORE_CSV_INI(fp);
#endif
//はみ出た時の拡張
//fpをparam取得まで進める
init_params.mode = INITIAL_PARAM_FROM_FILE_DATA;
init_params.fp = fp1;
get_param(&params,&init_params);
A_row_size = params.A_row_size_param;
A_col_size = params.A_col_size_param;
B_row_size = params.B_row_size_param;
B_col_size = params.B_col_size_param = 1;
B_col_size_pad = params.B_col_size_pad_param = 1;

H = params.H_param;
A_row_size_pad = params.A_row_size_pad_param;
A_col_size_pad = params.A_col_size_pad_param;
B_row_size_pad = params.B_row_size_pad_param;
params.NCHIP_param      = NCHIP     ;
W = params.W_param;

IMAX_param_tunig(&params);

PRINT_PARAM(params);


mem_reset_offset();

A          = (Uint*)IMAX_malloc(2*(A_row_size_pad*(A_col_size_pad))*sizeof(Uint));
B          = (Uint*)IMAX_malloc((B_row_size_pad)*(B_col_size_pad)*sizeof(Uint));
C1         = (Uint*)IMAX_malloc_output(A_row_size_pad*(B_col_size_pad)*sizeof(Uint));
sort_index = (Uint*)IMAX_malloc((A_row_size_pad)*sizeof(Uint));

C0      = (Uint*)calloc(A_row_size_pad*(B_col_size_pad),sizeof(Uint));
C_debug = (Uint*)calloc(A_row_size_pad*(B_col_size_pad),sizeof(Uint));
B_debug = (Uint*)calloc((B_col_size_pad)*(B_row_size_pad),sizeof(Uint));

make_random_mat(&params,B,B_debug);

coo = make_mat(&params,params.sparsity,zero_bias,&init_params);


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
memcpy(C_debug,C1,A_row_size_pad*sizeof(Uint));

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
    exit(1);
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
if(init_params.fp != NULL){
    fclose(init_params.fp);
    init_params.fp = NULL;
}
#endif
} // main





