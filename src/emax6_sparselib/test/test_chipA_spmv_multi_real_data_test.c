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
Uint H;
size_t A_row_size_ini,A_row_size,A_row_size_pad;
size_t A_col_size_ini,A_col_size,A_col_size_pad;
size_t B_row_size_ini,B_row_size,B_row_size_pad;
size_t B_col_size_ini,B_col_size,B_col_size_pad;
size_t B_col_blk_ini ,B_col_blk ;
size_t NCHIP_ini     ,NCHIP     ;
size_t W_ini         ,W         ;
size_t A_col_blk_ini ,A_col_blk ;
size_t C_col_blk_ini ,C_col_blk ;
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
Uint data_index = 0;
emax6_param params; 
init_param init_params;
Uint data_index_len = 10;
char* dataset_names[10] = {"./data/poli/poli.mtx","./data/S40PI_n1/S40PI_n1.mtx","./data/S80PI_n1/S80PI_n1.mtx",
                          "./data/ACTIVSg2000/ACTIVSg2000.mtx","./data/ex10/ex10.mtx","./data/ex31/ex31.mtx",
                          "./data/cavity10/cavity10.mtx","./data/rdb3200l/rdb3200l.mtx","./data/reorientation_7/reorientation_7.mtx"
                          ,"./data/tols4000/tols4000.mtx"};

// char* dataset_names[1] = {"./data/ex10/ex10.mtx"};

params.mode = SPARSE_DENSE_58_SPMV_MODE;
params.data_format = JDS_INDEX_VAL_SET_SPMV_FORMAT;
params.data_type = REAL_DATA_TYPE;


// params.mode = SPARSE_DENSE_58_SPMV_MODE;
// params.data_format = CSR_INDEX_VAL_SET_SPMV_FORMAT;
// params.data_type = REAL_DATA_TYPE;

// params.mode = DENSE_SPMV_MODE;
// params.data_format = DENSE_DENSE_SPMV_FORMAT;
// params.data_type = REAL_DATA_TYPE;

init_params.mode = INITIAL_MEMBASE_WITH_MAT_LEN;
init_params.init_allocate_mat_len = 6000;
get_param(&params,&init_params);
Uchar* membase = NULL;
Uint memsize;
membase = init_params.membase;
memsize = init_params.memsize;

argc--;
if(argc == 1){
    store_name = argv[1]; 
}
else if(argc == 2){
    fprintf(stderr,"you should use single test pattern\n");
    exit(1);
}
#if !defined(CSIMDEBUG)
if((fp=fopen(store_name,"w"))==NULL){
    fprintf(stderr,"cant open csv\n");
    exit(1);
}

#endif

#if !defined(CSIMDEBUG)
STORE_CSV_INI(fp);
#endif
//fpをparam取得まで進める
for(data_index=0; data_index<data_index_len; data_index++){
    if((fp1=fopen(dataset_names[data_index],"r"))==NULL){
        fprintf(stderr,"cant open data set\n");
        exit(1);
    }
    fp1_tmp = get_param_from_dataset(&params,fp1);
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
    IMAX_param_tunig(&params);

    PRINT_PARAM_REAL_DATA(params,data_index);

    // Base_p  = (Uint*)((Uchar*)membase);
    // A  = (Uint*)((Uchar*)Base_p);
    // B  = (Uint*)((Uchar*)A  + 2*(A_row_size_pad*(A_col_size_pad))*sizeof(Uint));
    // //aligmentを8byteにしないとバグる
    // GET_PAD_SIZE(tmp,(B_row_size_pad)*(B_col_size_pad)*sizeof(Uint),8);
    // C1 = (Uint*)((Uchar*)B  + tmp + 8*sizeof(Uint));
    // GET_PAD_SIZE(tmp,A_row_size_pad*(B_col_size_pad)*sizeof(Uint),8);
    // sort_index = (Uint*)((Uchar*)C1 + tmp);
    mem_reset_offset();

    A = (Uint*)IMAX_malloc(2*(A_row_size_pad*(A_col_size_pad))*sizeof(Uint));
    B = (Uint*)IMAX_malloc((B_row_size_pad)*(B_col_size_pad)*sizeof(Uint));
    C0 = (Uint*)calloc(A_row_size_pad*(B_col_size_pad),sizeof(Uint));
    C1 = (Uint*)IMAX_malloc_output(A_row_size_pad*(B_col_size_pad)*sizeof(Uint));
    sort_index = (Uint*)IMAX_malloc((A_row_size_pad)*sizeof(Uint));
    C_debug = (Uint*)calloc(A_row_size_pad*(B_col_size_pad),sizeof(Uint));
    B_debug = (Uint*)calloc((B_col_size_pad)*(B_row_size_pad),sizeof(Uint));

    make_random_mat(&params,B,B_debug);

    coo = make_mat(&params,params.sparsity,zero_bias,fp1_tmp);
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
    STORE_CSV_REAL_DATA(fp,sparse_rate_index,data_index);
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
            if (abs(*(float*)&C0[col*A_row_size_pad+row] - *(float*)&C_debug[col*A_row_size_pad+row])>0.1) {
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

    fclose(fp1_tmp);
    fp1_tmp = NULL;
}
mem_release(memsize,&membase);
}

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





