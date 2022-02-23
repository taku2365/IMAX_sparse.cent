#ifndef EMAX_SPARSE
#define EMAX_SPARSE 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include "./emax6.h"
#include "../3rd/Matrix_Format_Io/mmio.h"
#define LIMIT 1.0e-30
#define LMM_SIZE  65536
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

typedef struct {
	float *dst;
	const float *src;
    Uint row_size;
    // Uint row_range_start; 
    Uint row_range_end; 
    // Uint col_range_start; 
    Uint col_range_end;
    size_t thread_id; 
} imax_buf;



typedef struct {
    int nnz; // nonzero
    int col_normal_size; //matrix col size
    int row_normal_size; //matrix row size
    int* row_p; //row pointer //row_p[n] = nnz
    int* col_index; //column index len(column_index)=row_normal_size*col_normal_size
    Uint* val; // actual nonzero value
    int* paddings; // pad operation  -2 no cal ,-1 full cal ,others pad cal
} emax6_sparse;

typedef struct {
    int nnz; // nonzero
    int col_normal_size; //matrix col size
    int row_normal_size; //matrix row size
    int* col_p; //row pointer //row_p[n] = nnz
    int* col_index; //column index len(column_index)=row_normal_size*col_normal_size
    Ull* val_index_set; // 0:actual nonzero value 1:next index
    Uint* sort_index; // index after sorting
    int* col_num;  // The number of calculations per H in row
    int* paddings; // pad operation  ex H=60 num=150 -> 150/60=2+1  120/60=2+0
    Ull* margin;   // A row per AcolH   0:omission of calculation else:Depth of A to be obtained 
} emax6_sparse1;


typedef struct {
    int nnz; // nonzero
    int col_normal_size; //matrix col size
    int row_normal_size; //matrix row size
    int* col_p; //row pointer //row_p[n] = nnz
    Uint* col_index; //column index len(column_index)=row_normal_size*col_normal_size
    Uint* val_index_set; // 0~M1*M2:actual nonzero  value M1*M2~2M1*M2:index
    Uint* sort_index; // index after sorting
    int* col_num;  // The number of calculations per H in row
    int* paddings; // pad operation  ex H=60 num=150 -> 150/60=2+1  120/60=2+0
    Ull* margin;   // A row per AcolH   0:omission of calculation else:Depth of A to be obtained 
    Ull* margin_sum;   // sum A row per AcolH   0:omission of calculation else:Depth of A to be obtained 
    Ull* blk_ptr;
    
} emax6_sparse2;

typedef struct{
    Sll row_subsize;
    Sll col_subsize;
    Sll col_blk_param;
} A_blk_set;

typedef struct{
    Sll row_subsize;
    Sll col_subsize;
    Sll col_blk_param;
} B_blk_set;

typedef struct {
    Uint mode;    // 0:dense dense  1:sparse dense H=46 ver  2:sparse dense H=58 ver 3:sparse dense H=58 C_col_blk != B_col_blk ver
    Uint data_format; // 0:dense normal  1:csr index val set  2:jds index val separate  3:jds index val set 
    Uint data_type; // 0:normal 1:sparse 2:biased sparse
    Sll H_param;
    Sll W_param;
    Sll A_col_blk_param     ;
    Sll A_row_blk_param     ;
    Sll B_col_blk_param     ;
    Sll B_row_blk_param     ;
    Sll C_col_blk_param     ;
    Sll C_row_blk_param     ;
    Sll NCHIP_param         ;
    Sll A_row_size_param    ;
    Sll A_col_size_param    ;
    Sll B_row_size_param    ;
    Sll B_col_size_param    ;
    Sll A_row_size_pad_param;
    Sll A_col_size_pad_param;
    Sll B_row_size_pad_param;
    Sll B_col_size_pad_param;
    int nnz                 ;  
    Sll col_max; //1行あたりのnnzの最大数 
    A_blk_set* A_blk_sets   ;
    B_blk_set* B_blk_sets   ;
    MM_typecode matcode     ;
    float sparsity          ;
    float LMM_usage_A_kbyte ;
    float LMM_usage_A_rate  ;
    float LMM_usage_B_kbyte ;
    float LMM_usage_B_rate  ;
    float LMM_usage_kbyte   ;
    float LMM_usage_rate    ;    
} emax6_param;



typedef struct {    
    int nnz;
    Uint* val;
    Uint* col_index;
    Uint* row_index;
    int row_size;
    int col_size;
} coo_format;


coo_format* make_mat(emax6_param* emax6_param,float sparsity,float biased_percent,FILE* fp);
void make_random_mat(emax6_param* emax6_param,Uint* B,Uint* B_debug);
void free_sparse_format(emax6_sparse2* sparse_format);
void free_sparse_mat(coo_format* coo);
void orig(Uint* A_orig,Uint* B_orig,Uint* C_orig,emax6_param* emax6_param);
void mem_release(Uint memsize,Uchar** membase);
void IMAX_param_tunig(emax6_param* params);
emax6_sparse2* sparse_format(int nnz,Ull* val,Uint* val_tmp, const int* const col_index, const int* const row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);
// emax6_sparse2* sparse_format1(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);
// void sparse_multiply(const emax6_sparse* const  A_sparse, const Uint* const B, Uint* C_sparse, int B_col_size);
// int sparse_multiply_imax(const emax6_sparse* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
// int sparse_multiply_imax1(const emax6_sparse1* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
// int sparse_multiply_imax2(const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
int sparse_multiply_imax3(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
int sparse_multiply_imax4(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
int sparse_multiply_imax5(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
Sll get_H_param(emax6_param* params); 
FILE* get_param_from_dataset(emax6_param* params,FILE* f);
//mode  
#define DENSE_DENSE_MODE 0
#define DENSE_SPMV_MODE 1 
#define SPARSE_DENSE_46_MODE 2
#define SPARSE_DENSE_58_VER2_MODE 3
#define SPARSE_DENSE_58_VER3_MODE 4
#define SPARSE_DENSE_58_SPMV_MODE 5
// data_format
#define DENSE_DENSE_FORMAT 0
#define DENSE_DENSE_SPMV_FORMAT 1
#define CSR_INDEX_VAL_SET_FORMAT 2
#define JDS_INDEX_SEPARATE_FORMAT 3
#define JDS_INDEX_VAL_SET_FORMAT 4 
#define CSR_INDEX_VAL_SET_SPMV_FORMAT 5 
#define JDS_INDEX_VAL_SET_SPMV_FORMAT 6 
// data_type
#define DENSE_TYPE 0 
#define DENSE_SPMV_TYPE 1 
#define SPARSE_TYPE 2
#define BIASED_SPARSE_TYPE 3
#define SPARSE_SPMV_TYPE 4
#define REAL_DATA_TYPE 5


#define LMM_MAX_LENGTH 1024

#define STORE_CSV_INI(fp) do { \
    fprintf(fp,"LMM_usage_rate,LMM_usage_kbyte,LMM_usage_A_rate,LMM_usage_A_kbyte,LMM_usage_B_rate,LMM_usage_B_kbyte,sparse_rate,A_row_size,A_col_size,B_row_size,B_col_size,A_col_blk,B_col_blk,C_col_blk,NCHIP,W,ARM,DRAIN,CONF,REGV,RANGE,LOAD,EXEC,total,dataset_name\n"); \
    }\
    while (0)


#define STORE_CSV(fp,sparse_rate_index) do { \
        fprintf(fp,"%2.2f,%2.2f,%2.2f,%2.2f,%2.2f,%2.2f,%2.2f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%llu,%llu,%llu,%llu,%llu,%llu,%llu,%llu\n",\
        params.LMM_usage_rate,params.LMM_usage_kbyte,\
        params.LMM_usage_A_rate,params.LMM_usage_A_kbyte,\
        params.LMM_usage_B_rate,params.LMM_usage_B_kbyte,\
        sparse_rate[sparse_rate_index],(int)A_row_size,(int) A_col_size,\
        (int)B_row_size,(int)B_col_size,\
        (int)params.A_col_blk_param,(int)params.B_col_blk_param,\
        (int)params.C_col_blk_param,(int)NCHIP,(int)W,\
        nanosec[NANOS_ARM],nanosec[NANOS_DRAIN],nanosec[NANOS_CONF],nanosec[NANOS_REGV],\
        nanosec[NANOS_RANGE],nanosec[NANOS_LOAD],nanosec[NANOS_EXEC],nanosec[NANOS_TOTAL]); \
    }\
    while (0)

#define STORE_CSV_REAL_DATA(fp,sparse_rate_index,i) do { \
        fprintf(fp,"%2.2f,%2.2f,%2.2f,%2.2f,%2.2f,%2.2f,%1.7f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%llu,%llu,%llu,%llu,%llu,%llu,%llu,%llu,%s\n",\
        params.LMM_usage_rate,params.LMM_usage_kbyte,\
        params.LMM_usage_A_rate,params.LMM_usage_A_kbyte,\
        params.LMM_usage_B_rate,params.LMM_usage_B_kbyte,\
        params.sparsity,(int)A_row_size,(int) A_col_size,\ 
        (int)B_row_size,(int)B_col_size,\
        (int)params.A_col_blk_param,(int)params.B_col_blk_param,\
        (int)params.C_col_blk_param,(int)NCHIP,(int)W,\
        nanosec[NANOS_ARM],nanosec[NANOS_DRAIN],nanosec[NANOS_CONF],nanosec[NANOS_REGV],\
        nanosec[NANOS_RANGE],nanosec[NANOS_LOAD],nanosec[NANOS_EXEC],nanosec[NANOS_TOTAL],dataset_names[i]); \
    }\
    while (0)


#define PRINT_PARAM(params) do { \
        printf("LMM_usage_rate %2.2f LMM_usage_kbyte %2.2f LMM_usage_A_rate %2.2f LMM_usage_A_kbyte %2.2f LMM_usage_B_rate %2.2f LMM_usage_B_kbyte %2.2f sparse_rate %2.1f A_row_size %d A_col_size %d B_row_size %d B_col_size %d A_col_blk %d B_col_blk %d C_col_blk %d NCHIP %d W %d \n",\
            params.LMM_usage_rate,params.LMM_usage_kbyte,\
            params.LMM_usage_A_rate,params.LMM_usage_A_kbyte,\
            params.LMM_usage_B_rate,params.LMM_usage_B_kbyte,\
            sparse_rate[sparse_rate_index],(int)A_row_size,(int) A_col_size,\
            (int)B_row_size,(int)B_col_size,\
            (int)params.A_col_blk_param,(int)params.B_col_blk_param,\
            (int)params.C_col_blk_param,(int)NCHIP,(int)W);}\
    while (0)


#define PRINT_PARAM_REAL_DATA(params,data_index) do { \
        printf("LMM_usage_rate %2.2f LMM_usage_kbyte %2.2f LMM_usage_A_rate %2.2f LMM_usage_A_kbyte %2.2f LMM_usage_B_rate %2.2f LMM_usage_B_kbyte %2.2f sparse_rate %1.7f A_row_size %d A_col_size %d B_row_size %d B_col_size %d A_col_blk %d B_col_blk %d C_col_blk %d NCHIP %d W %d data name %s \n",\
            params.LMM_usage_rate,params.LMM_usage_kbyte,\
            params.LMM_usage_A_rate,params.LMM_usage_A_kbyte,\
            params.LMM_usage_B_rate,params.LMM_usage_B_kbyte,\
            params.sparsity,(int)A_row_size,(int) A_col_size,\
            (int)B_row_size,(int)B_col_size,\
            (int)params.A_col_blk_param,(int)params.B_col_blk_param,\
            (int)params.C_col_blk_param,(int)NCHIP,(int)W,dataset_names[data_index]);}\
    while (0)


#define GET_PAD_SIZE(pad_size,size,align) do {\
     pad_size = ((size%align) != 0) ? size - size%align + align : size;\
}\
while (0)





#endif


