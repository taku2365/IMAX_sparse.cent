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
        if(row_index_tmp != row_index_tmp_past){
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




emax6_sparse* sparse_format1(int nnz,const Uint* const val, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param){

    if(!val || !col_index || !row_index ) {
        printf("sparse_format error! \n");
        exit(0);
    }

    emax6_sparse* sparse_info = (emax6_sparse *) malloc(1*sizeof(emax6_sparse));
    sparse_info->nnz = nnz;
    sparse_info->row_normal_size = row_size;
    sparse_info->col_normal_size = col_size;
    int H = emax6_param->H_param;

    int* col_index_sparse = (int*) malloc(nnz*sizeof(int)); 
    int* row_index_sparse_p = (int*) malloc((row_size+1)*sizeof(int));
    Uint* val_sparse = (Uint*) malloc(nnz*sizeof(Uint));
    int * paddings = (int*) malloc(row_size*(col_size/H)*sizeof(int));
    
    int row_index_tmp_past = 0,col_index_sum = 0,row_index_tmp = 0;
    int row_index_count = 1,col_index_tmp = 0,paddings_index = 0;
    int row_index_sparse_diff=0,full_calculate = 0,full_pad_iter = 0;
    int pad_surplus = 0;
    row_index_sparse_p[0] = 0; // 0からスタート
    for (int i=0; i<nnz; i++ ){
        col_index_tmp =  col_index[i];
        row_index_tmp =  row_index[i];
        col_index_sparse[i] = col_index_tmp;
        val_sparse[i] = val[row_index[i]*col_size+col_index[i]];
        col_index_sum += 1;
        if((row_index_tmp != row_index_tmp_past)||(i==nnz-1)){
            // rowが次に進んだら、次に進んだrowまでのcolのnozero個数を代入する。
            //rowのzeroはすでに埋まっているので1からスタートする。
            //このifに入っている時点で次の行に進んでいるのでひとつ前のcol_index_sum-1を代入する。
            // paddingsにpadする数を入れる やることがなかったら-2を入れてスキップする。
            // Hで割り切れなかったらpadを入れる。　pad_surplusdeで判定する。
            row_index_sparse_diff = (col_index_sum-1) - row_index_sparse_p[row_index_count-1] ; //その行のnnz
            row_index_sparse_diff = (i==nnz-1)? row_index_sparse_diff+1 : row_index_sparse_diff; //最後の時は次の行に行っていないので引く1
            full_calculate = row_index_sparse_diff/H; //H=60まで計算する回数  110/60=1 ..50
            pad_surplus = (row_index_sparse_diff%H != 0); // 割り切れなくて、途中までpadするパターン
            full_pad_iter = col_size/H - full_calculate - pad_surplus; //省略できる回数 ex 480/60 - 1 - 1  = 6

            for(int j=0; j<full_calculate; j++) paddings[paddings_index++] = -1; //Hすべて計算するときは-1を入れる

            if(pad_surplus) paddings[paddings_index++] = H - (int) row_index_sparse_diff%H; //途中まで計算して、最後はpadする回数 ex 60 - 110%60= 60 - 50 = 10　　ex1 60 - 40%60 = 60 - 40 = 20

            for(int k=0; k<full_pad_iter; k++) paddings[paddings_index++] = -2; //省略できるときは-2を入れる
    
            row_index_sparse_p[row_index_count++] = (i==nnz-1)? col_index_sum:col_index_sum-1; //formatの定義で一つ前のcolnnzの数を入れる　ex 0行に4つ 1行に3つ [0]=0 [1]=4　[2]=7
        }
        row_index_tmp_past = row_index_tmp;
    }

    //nnz-1も入れるので、for抜けた後にrow_index_sparse_pを代入する必要がなくなった。
    sparse_info->col_index = col_index_sparse;
    sparse_info->row_p = row_index_sparse_p;
    sparse_info->val = val_sparse;
    sparse_info->paddings = paddings;

    return sparse_info;


}
