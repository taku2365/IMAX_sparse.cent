#include "../Include/emax6_sparselib.h"
#include <stdbool.h>

static Uchar* membase1;
static Uchar* mem_current;
static size_t memsize1;

Uint get_H_param(emax6_param* params){
    Uint H;
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
    size_t W; 
    int nnz = 0;
    int ret_code;
    int i;
    MM_typecode matcode;
    Uint H = params->H_param;
    

    if (!f) {
    fprintf(stderr,"this file does not exist make_sparse_mat.c:%d\n",__LINE__);
    exit(1);
    }
    
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


    if((A_row_size == 0)||(A_col_size == 0)||(B_row_size == 0)){
        fprintf(stderr,"invalid size conf_param.c:%d\n",__LINE__);
        exit(1);
    }
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
    params->sparsity = nnz/(float)(A_row_size*A_col_size);
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

static void get_membase_spmv_init(emax6_param* params,init_param* init_param){

    Uint H = get_H_param(params);
    size_t A_row_size_pad;
    size_t A_col_size_pad;
    size_t B_row_size_pad;
    size_t B_col_size_pad;
    Uint W;


    Uint init_len = init_param->init_allocate_mat_len;
    Uchar* membase;
    size_t memsize;
    //HごとにAcolを進む
    GET_PAD_SIZE(A_col_size_pad,init_len,H);
    //denseでは8行分を計算できる sparseは2行分しか計算できないがindex+valのためにW*2とする。
    //sparseでははみ出た分はindex=0が割り当たるのでHでpadする必要がない
    if(params->mode == DENSE_SPMV_MODE){
        W = 4;
        GET_PAD_SIZE(A_row_size_pad,init_len,(W*2));
        GET_PAD_SIZE(B_row_size_pad,init_len,H);
    }
    else if(params->mode == SPARSE_DENSE_58_SPMV_MODE){
        W = 2;
        GET_PAD_SIZE(A_row_size_pad,init_len,(W*2));
        B_row_size_pad = init_len;  
    }
    else{
        fprintf("future work conf_param.c %d \n",__LINE__);
        exit(1);
    }

    B_col_size_pad = 1;
    if(init_param->mode == INITIAL_MEMBASE_WITH_MAT_LEN){
        memsize = 2*(A_row_size_pad*(A_col_size_pad))*sizeof(Uint)
                +(B_row_size_pad)*(B_col_size_pad)*sizeof(Uint)
                +A_row_size_pad*(B_col_size_pad)*sizeof(Uint)
                // +A_row_size*B_col_size*sizeof(Uint)
                +A_row_size_pad*sizeof(Uint)
                +8*sizeof(Uint);
    }
    else{
        memsize = init_param->memsize;
    }
    memsize += ((memsize%32) != 0) ? (-memsize%32 + 32) : 0;
    sysinit((Uint)memsize,32,&membase);
    init_param->membase = membase;
    //global変数
    membase1 = membase;
    mem_current = membase;
    memsize1 = memsize;
    params->W_param = W;
    init_param->memsize = memsize;
}

Uchar* IMAX_malloc(size_t size ){
    Uchar* mem_current_tmp = mem_current;
    // アライメント
    GET_PAD_SIZE(size,size,32);
    size = (size_t)size;
    mem_current = mem_current + size;
    if(mem_current>(membase1+memsize1)){
        fprintf(stderr,"Allocated memory has been exceeded.conf_param.c:%d \n",__LINE__);
        exit(1);
    }
    return mem_current_tmp;
}

Uchar* IMAX_malloc_output(size_t size ){
    Uchar* mem_current_tmp = mem_current;
    // アライメント
    GET_PAD_SIZE(size,size,32);
    size = (size_t)size;

    mem_current = mem_current + size;
    static Uchar* memout_past = NULL;
    //IMAXの制約上、同じoutputに書き込むと書き戻しをしてくれないのでずらす
    if(mem_current == memout_past){
        mem_current_tmp = mem_current_tmp + 32;
    }
    if(mem_current>(membase1+memsize1)){
        fprintf(stderr,"Allocated memory has been exceeded.\n conf_param.c:%d",__LINE__);
        exit(1);
    }
    memout_past = mem_current;
    
    return mem_current_tmp;
}

void mem_reset_offset(){
    mem_current = membase1;
}


static void get_param_spmv_from_file(emax6_param* params,init_param* init_param){
    // Uint A_row_size, A_col_size; 
    // Uint A_row_size_pad, A_col_size_pad; 
    // Uint B_row_size, B_col_size; 
    // Uint B_row_size_pad, B_col_size_pad; 
    // size_t W; 
    // int nnz = 0;
    // int ret_code;
    // int i;
    // MM_typecode matcode;
    // Uint H = params->H_param;
    

    // if (!f) {
    // fprintf(stderr,"this file does not exist make_sparse_mat.c:%d\n",__LINE__);
    // exit(1);
    // }
    
    // if (mm_read_banner(f, &matcode) != 0)
    // {
    //     printf("Could not process Matrix Market banner.\n");
    //     exit(1);
    // }

    // /*  This is how one can screen matrix types if their application */
    // /*  only supports a subset of the Matrix Market data types.      */

    // if (mm_is_complex(matcode) && mm_is_matrix(matcode) && 
    //         mm_is_sparse(matcode) )
    // {
    //     printf("Sorry, this application does not support ");
    //     printf("Market Market type: [%s]\n", mm_typecode_to_str(matcode));
    //     exit(1);
    // }

    // /* find out size of sparse matrix .... */

    // if ((ret_code = mm_read_mtx_crd_size(f, &A_row_size, &A_col_size, &nnz)) !=0)
    //     exit(1);


    //     /* reseve memory for matrices */
    // B_row_size = A_col_size;
    // GET_PAD_SIZE(A_col_size_pad,A_col_size,H);


    // if((A_row_size == 0)||(A_col_size == 0)||(B_row_size == 0)){
    //     fprintf(stderr,"invalid size conf_param.c:%d\n",__LINE__);
    //     exit(1);
    // }
    // if(params->mode == DENSE_SPMV_MODE){
    //     W = 4;
    //     GET_PAD_SIZE(A_row_size_pad,A_row_size,(W*2));
    //     GET_PAD_SIZE(B_row_size_pad,B_row_size,H);
    // }
    // else if(params->mode == SPARSE_DENSE_58_SPMV_MODE){
    //     W = 2;
    //     GET_PAD_SIZE(A_row_size_pad,A_row_size,(W*2));
    //     B_row_size_pad = B_row_size;  
    // }
    // else{
    //     fprintf("future work spmv_size_test %d \n",__LINE__);
    //     exit(1);
    // }
    // params->A_row_size_param = A_row_size;
    // params->A_row_size_pad_param = A_row_size_pad;
    // params->A_col_size_param = A_col_size;
    // params->A_col_size_pad_param = A_col_size_pad;
    // params->B_row_size_param = B_row_size;
    // params->B_row_size_pad_param = B_row_size_pad;
    // params->W_param = W;
    // params->sparsity = nnz/(float)(A_row_size*A_col_size);
    // if(mm_is_symmetric(matcode)){
    //     params->nnz = 2*nnz;
    // }
    // else{
    //     params->nnz = nnz;
    // }
    // for(i=0; i<MATCODE_LEN; i++){
    // params->matcode[i] = matcode[i];
    // }

    // return f;
}




void get_param(emax6_param* params,init_param* init_param){
    Uint emax6_mode = params->mode;
    Uint init_mode = init_param->mode;
    bool INITIAL_MEMBASE_valid = ((init_mode == INITIAL_MEMBASE_WITH_MAT_LEN)||(init_mode == INITIAL_MEMBASE_WITH_MEMSIZE));
    bool INITIAL_PARAM_FROM_FILE_valid = (init_mode == INITIAL_PARAM_FROM_FILE_DATA);
    bool SPMV_valid = ((emax6_mode == SPARSE_DENSE_58_SPMV_MODE)||(emax6_mode == DENSE_SPMV_MODE));

    if(INITIAL_MEMBASE_valid&&SPMV_valid){
        get_membase_spmv_init(params,init_param);
    }
    else if(INITIAL_PARAM_FROM_FILE_valid&&SPMV_valid){
        get_param_spmv_from_file(params,init_param);
    }
    
    // else if((mode == REAL_DATA)&&(params->mode == SPARSE_DENSE_58_SPMV_MODE)){
    //     get_param_spmv2(params,init_param);
    // }
}