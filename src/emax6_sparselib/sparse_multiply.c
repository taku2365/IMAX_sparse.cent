#include "./Include/emax6_sparselib.h"


void sparse_multiply(const emax6_sparse* const A_sparse, const Uint* const B, Uint* C, int B_col_size){

    if(!A_sparse||!B||!C){
        printf("A,B,C NULL pointer \n");
        exit(0);
    }
    
    int* A_row_p = A_sparse->row_p;
    int* A_nnz_col_index = A_sparse->col_index;
    Uint* A_nnz_val = A_sparse->val;
    int A_row_size = A_sparse->row_normal_size;
    int A_col_size = A_sparse->col_normal_size;
    int B_row_size = A_sparse->col_normal_size;
    int A_nnz =  A_sparse->nnz;
    memset(C, 0, sizeof(Uint)*A_row_size*B_col_size);

    

    for(int i=0; i<A_row_size;i++){
        for(int j=0; j<B_col_size;j++){
            for(int k=A_row_p[i]; k<A_row_p[i+1]; k++){
                if (k==0) *(float*)&C[i*B_col_size+j]  = *(float*)&A_nnz_val[k] * *(float*)&B[A_nnz_col_index[k]*B_col_size+j];
                else *(float*)&C[i*B_col_size+j]  += *(float*)&A_nnz_val[k] * *(float*)&B[A_nnz_col_index[k]*B_col_size+j];
            }
        }
    }


}