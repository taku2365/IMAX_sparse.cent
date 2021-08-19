#ifndef EMAX_SPARSE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int* paddings; // pad operation  -1 no cal ,1 full cal ,others pad cal
} emax6_sparse;

typedef struct {
    int  H_param;
    int  W_param;
    int  RMGRP_param;
    int  NCHIP_param;
} emax6_param;


emax6_sparse* sparse_format(int nnz, const Uint* const val, int* col_index, int* row_index,int row_size,int col_size);
emax6_sparse* sparse_format1(int nnz,const Uint* const val, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param);
void sparse_multiply(const emax6_sparse* const  A_sparse, const Uint* const B, Uint* C_sparse, int B_col_size);
void sparse_multiply_imax1(const emax6_sparse* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params);
#endif