#include "../Include/emax6_sparselib.h"

Sll get_H_param(emax6_param* params){
    Sll H = 0;
    switch(params->mode){

        case DENSE_DENSE_MODE:
        case DENSE_SPMV_MODE:
        H = params->H_param = 59LL;
        break;
        case SPARSE_DENSE_46_MODE:
            H = params->H_param = 46LL;
        break;
        case SPARSE_DENSE_58_VER2_MODE:
        case SPARSE_DENSE_58_VER3_MODE:
        case SPARSE_DENSE_58_SPMV_MODE:
            H =params->H_param = 58LL;
        break;
        default:
        printf("this pattern does not exist get_H_param LINE %d\n",__LINE__);
        exit(1);
    }
    return H;    
}

FILE* get_param_from_dataset(emax6_param* params,FILE* f){

    Uint A_row_size, A_col_size; 
    Uint A_row_size_pad, A_col_size_pad; 
    Uint B_row_size, B_col_size; 
    Uint B_row_size_pad, B_col_size_pad; 
    Sll W; 
    int nnz = 0;
    int ret_code;
    int i;
    MM_typecode matcode;
    Sll H = params->H_param;
    

    if (!f) {
    fprintf(stderr,"this file does not exist make_sparse_mat.c:%d\n",__LINE__);
    exit(1);
    }
    
//  "\377\177\000"
    if (mm_read_banner(f, &matcode) != 0)
    {
        printf("Could not process Matrix Market banner.\n");
        exit(1);
    }

    /*  This is how one can screen matrix types if their application */
    /*  only supports a subset of the Matrix Market data types.      */

    if (mm_is_complex(matcode) && mm_is_matrix(matcode) && 
            mm_is_sparse(matcode) )
    {
        printf("Sorry, this application does not support ");
        printf("Market Market type: [%s]\n", mm_typecode_to_str(matcode));
        exit(1);
    }

    /* find out size of sparse matrix .... */

    if ((ret_code = mm_read_mtx_crd_size(f, &A_row_size, &A_col_size, &nnz)) !=0)
        exit(1);


        /* reseve memory for matrices */
    B_row_size = A_col_size;
    GET_PAD_SIZE(A_col_size_pad,A_col_size,H);

    if(params->mode == DENSE_SPMV_MODE){
        W = 4;
        GET_PAD_SIZE(A_row_size_pad,A_row_size,(W*2));
        GET_PAD_SIZE(B_row_size_pad,B_row_size,H);
    }
    else if(params->mode == SPARSE_DENSE_58_SPMV_MODE){
        W = 2;
        GET_PAD_SIZE(A_row_size_pad,A_row_size,(W*2));
        B_row_size_pad = B_row_size;  
    }
    else{
        fprintf("future work spmv_size_test %d \n",__LINE__);
        exit(1);
    }

    params->A_row_size_param = A_row_size;
    params->A_row_size_pad_param = A_row_size_pad;
    params->A_col_size_param = A_col_size;
    params->A_col_size_pad_param = A_col_size_pad;
    params->B_row_size_param = B_row_size;
    params->B_row_size_pad_param = B_row_size_pad;
    params->W_param = W;
    if(mm_is_symmetric(matcode)){
        params->nnz = 2*nnz;
    }
    else{
        params->nnz = nnz;
    }
    for(i=0; i<MATCODE_LEN; i++){
    params->matcode[i] = matcode[i];
    }

    return f;
    
}
