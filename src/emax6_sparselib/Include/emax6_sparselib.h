#ifndef EMAX_SPARSE
#define EMAX_SPARSE 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./emax6.h"
#define LIMIT 1.0e-30

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
    
} emax6_sparse2;

typedef struct {
    Sll H_param;
    Sll W_param;
    Sll RMGRP_param;
    Sll NCHIP_param;
    Sll A_col_blk_param;
    Sll A_row_size_param;
    Sll A_col_size_param;
    Sll B_row_size_param;
    Sll B_col_size_param;  
} emax6_param;

typedef struct {    
    int nnz;
    Uint* val;
    Uint* col_index;
    Uint* row_index;
    int row_size;
    int col_size;
} coo_format;

coo_format* make_sparse_mat(emax6_param* emax6_param,float sparsity);
void make_simd_random_mat(emax6_param* emax6_param,Uint* B,Uint* B_debug);
void free_sparse_format(emax6_sparse2* sparse_format);
void orig_chip_divB(Uint* A_orig,Uint* B_orig,Uint* C_orig,emax6_param* emax6_param);
void mem_release(Uint memsize,Uchar** membase);
emax6_sparse2* sparse_format(int mode,int nnz,Ull* val,Uint* val_tmp, const int* const col_index, const int* const row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);
emax6_sparse2* sparse_format1(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write);
// void sparse_multiply(const emax6_sparse* const  A_sparse, const Uint* const B, Uint* C_sparse, int B_col_size);
// int sparse_multiply_imax(const emax6_sparse* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
// int sparse_multiply_imax1(const emax6_sparse1* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
// int sparse_multiply_imax2(const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
int sparse_multiply_imax3(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
int sparse_multiply_imax4(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
int sparse_multiply_imax5(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
#endif