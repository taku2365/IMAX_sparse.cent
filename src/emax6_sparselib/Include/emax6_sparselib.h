#ifndef EMAX_SPARSE

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
    int* row_p; //row pointer 
    int* col_index; //column index
    Ull* val;
} emax6_sparse;


emax6_sparse* sparse_format(int nnz, Ull* val, int* col_index, int* row_index,int row_size,int col_size);


#endif