#include "./Include/emax6_sparselib.h"


emax6_sparse* sparse_format(int nnz,const Uint* const val, int* col_index, int* row_index,int row_size,int col_size){

    if(!val || !col_index || !row_index ) {
        printf("sparse_format error! \n");
        exit(0);
    }

    emax6_sparse* sparse_info = (emax6_sparse *) malloc(1*sizeof(emax6_sparse));
    sparse_info->nnz = nnz;
    sparse_info->row_normal_size = row_size;
    sparse_info->col_normal_size = col_size;

    int* col_index_sparse = (int*) malloc(nnz*sizeof(int)); 
    int* row_index_sparse_p = (int*) malloc(row_size*sizeof(int)+1);
    Uint* val_sparse = (Uint*) malloc(nnz*sizeof(Uint));
    
    int row_index_tmp_past = 0,col_index_sum = 0,row_index_tmp = 0,row_index_count = 1,col_index_tmp=0;
    row_index_sparse_p[0] = 0; // 0からスタート
    for (int i=0; i<nnz; i++ ){
        col_index_tmp =  col_index[i];
        row_index_tmp =  row_index[i];
        col_index_sparse[i] = col_index_tmp;
        val_sparse[i] = val[row_index[i]*col_size+col_index[i]];
        col_index_sum += 1;
        if(row_index_tmp!=row_index_tmp_past){
            // rowが次に進んだら、次に進んだrowまでのcolのnozero個数を代入
            //rowのzeroはすでに埋まっているので1からスタート
            //このifに入っている時点で次の行に進んでいるのでひとつ前のcol_index_sum-1を代入
            row_index_sparse_p[row_index_count++] = col_index_sum-1;
        }
        row_index_tmp_past = row_index_tmp;
    }

    row_index_sparse_p[row_index_count] = col_index_sum; // rowsize+1個目にnnzが入る
    sparse_info->col_index = col_index_sparse;
    sparse_info->row_p = row_index_sparse_p;
    sparse_info->val = val_sparse;



    return sparse_info;

}
