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




//CSR base
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


//CCR base
emax6_sparse1* sparse_format2(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param){

    if(!val || !col_index || !row_index ) {
        fprintf(stderr,"sparse_format NULL error! \n");
        exit(1);
    }

    emax6_sparse1* sparse_info = (emax6_sparse1 *) malloc(1*sizeof(emax6_sparse1));
    int H = emax6_param->H_param;
    // int W = emax6_param->W_param;
    int* count = (int*) calloc(col_size,sizeof(int));
    int* count_tmp = (int*) calloc((col_size+1),sizeof(int));
    int* count_sort_index_inverse = (int*) calloc(row_size,sizeof(int));
    Uint* count_sort_index= (Uint*) calloc(row_size,sizeof(Uint));
    int* row_count = (int*) calloc((row_size),sizeof(int));
    int* col_count = (int*) calloc((col_size+1),sizeof(int));
    int* paddings = (int*) calloc((row_size),sizeof(int));
    int count_tmp1;
    Ull* margin = (Ull*) calloc((row_size/H),sizeof(Ull));
    int iter_num = 0,margin_tmp;
    
    for(int k=0; k<nnz; k++) count[row_index[k]]++; //ex {[0] = 3, [1] = 2, [2] = 2, [3] = 4, [4] = 4, [5] = 1, [6] = 4, [7] = 6, [8] = 4, [9] = 5}

    for(int row=0; row<row_size; row++){
        count_tmp[count[row]]++; //  {[0] = 0, [1] = 1, [2] = 2, [3] = 1, [4] = 4, [5] = 1, [6] = 1, [7] = 0, [8] = 0, [9] = 0, [10] = 0} 
    }
    for(int row=0; row<row_size; row++) count_tmp[row+1] += count_tmp[row];  //値を適切な場所に入れるため ex {[0] = 0, [1] = 1, [2] = 3, [3] = 4, [4] = 8, [5] = 9, [6] = 10, [7] = 10, [8] = 10, [9] = 10, [10] = 10}  
    for(int row=0,tmp; row<row_size; row++){
        count_tmp1 = --count_tmp[count[row]]; // ex count[row]=3  --count_tmp[count[row]]=3  --は0から始めるため
        
        // count_sort_indexと count_sort_index_inverseは逆の関係
        //count_sort_indexは並べ替えた後、該当のrow(index)に入るべき、並べ替え後のrow(index)を表していていて、count_sort_index_inverseは並べ替え後にindex(row)を代入したら並べ替え後の場所を教えてくれる。
        //{[0] = 7, [1] = 9, [2] = 3, [3] = 4, [4] = 6, [5] = 8, [6] = 0, [7] = 1, [8] = 2, [9] = 5}
        // 実際のIMAXではUllでの足し算なのでポインタの足し算にならない　よって×4がいる。
        count_sort_index[(row_size-1)-count_tmp1] =  row*2*4;  //降下sortされた場所に入る //simdの×2 

        //CSCで格納　indexがその列で何番目かを表している。分布数えソートは昇順なので、 (row_size-1) - count_tmp1dで降順にする。  
        // row_size-1は0から始めるために引く1している。            
        // ex row=0 count_sort_index_inverse[row]=6 row_size-1=9 count_tmp1=3　0行目は3番目に小さいの0列目の7-1番目に入る
        //{[0] = 6, [1] = 7, [2] = 8, [3] = 2, [4] = 3, [5] = 9, [6] = 4, [7] = 0, [8] = 5, [9] = 1}
        count_sort_index_inverse[row] = (row_size-1) - count_tmp1;
         //アライメントのために次の手段は使えない 倍数の時のみ可(count[row] + (H-1))~(H-1);
         // sortされた後のrowごとのpaddings
         //降順
         paddings[(row_size-1) - count_tmp1] = count[row]/H + (int)(count[row]%H != 0); 

    }


    //paddingsは最低でも1
    //最小のpaddingsではAを一番下まで確保するので、row_size
    for(int iter=0;iter<paddings[row_size-1]; iter++){
        margin[iter_num++] = row_size; //row+1
    }
    for(int row=row_size-2,tmp=paddings[row_size-1]; row>=0; row--){
        //前回からの変化があれば変化の差分を埋める
        if(tmp != paddings[row]){
            //row+1が入っているので、margin[iter_num-1]-1
            for(int iter=paddings[margin[iter_num-1]-1];iter<paddings[row]; iter++){
                //row+1が入る multiplyのfor文で扱いやすくするため。 for (rofs=0; rofs<A_margin[blk_iter]; rofs++) 
                margin[iter_num++] = row+1;
            } 
        }
        tmp = paddings[row];
    }


    // Uint* val_debug    = (Uint*) calloc(1+row_size*col_size,sizeof(Uint));
    Ull* val_index_set = val;
    int* col_index_sparse = (int*) calloc(row_size*col_size,sizeof(int));
    int* row_index_sort_sparse = (int*) calloc((row_size*col_size),sizeof(int));
    

    for(int k=0,count_sort_index_inverse_tmp=0; k<nnz; k++){
        //CSCで格納
        // row_countは最初すべて0 row_countがふえると格納する行が右にずれて格納先が次のLMMになる
        //count_sort_index_inverse[row_index[k]]でどの行かを特定
        //row_count[1+row_index[k]]*row_sizeでどの列かを特定
        count_sort_index_inverse_tmp = count_sort_index_inverse[row_index[k]];
        //count_sort_index_inverseは並べ替え後にindex(row)を代入したら並べ替え後の場所を教えてくれる。
        //indexを1からスタートする。0は下段にindexを伝播するためだけに使う
        //Aが次のUnitに伝搬するのを表現するためにどの列かを特定+1
        //*((Uint*)&val_index_set[どの行かを特定+(どの列かを特定+1)]) = Aの値  
        //*((Uint*)&val_index_set[前の行+どの列かを特定]+1) = Bの対応箇所(下段Unit)*2(simd)*4(実際のIMAXコードはUllのアドレス演算なので4byteかける)
        *((Uint*)&val_index_set[(count_sort_index_inverse_tmp)+(1+row_count[row_index[k]])*row_size]) = val_tmp[row_index[k]+col_index[k]*row_size];
        *((Uint*)&val_index_set[count_sort_index_inverse_tmp+row_count[row_index[k]]*row_size]+1) = col_index[k]*2*4;
        // *((Uint*)&val_debug[(1+count_sort_index_inverse_tmp)+row_count[1+row_index[k]]*row_size]) = val[row_index[k]+col_index[k]*row_size];
         //rowを左詰めしているので、colの位置が値ごとに必要
        col_index_sparse[count_sort_index_inverse_tmp+row_count[row_index[k]]*row_size] = col_index[k];
        row_index_sort_sparse[k] = count_sort_index_inverse_tmp;
        row_count[row_index[k]]++;
        col_count[1+col_index[k]]++;

    }

    sparse_info->val_index_set = val_index_set;
    sparse_info->col_p = col_count;
    sparse_info->col_index = col_index_sparse;
    sparse_info->sort_index = count_sort_index;
    sparse_info->nnz = nnz;
    sparse_info->row_normal_size = row_size;
    sparse_info->col_normal_size = col_size;
    sparse_info->paddings = paddings;
    sparse_info->margin = margin;
    
    
    free(count);
    free(count_tmp);
    free(row_count);
    free(col_index);
    free(row_index);
    free(row_index_sort_sparse);
    // free(val_debug);


    return sparse_info;

//Cは書き込みながら転置？
//outputCはCCR形式

}




//CCR base
emax6_sparse2* sparse_format3(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param){

    if(!val || !col_index || !row_index ) {
        fprintf(stderr,"sparse_format NULL error! \n");
        exit(1);
    }

    emax6_sparse2* sparse_info = (emax6_sparse2 *) malloc(1*sizeof(emax6_sparse2));
    int H = emax6_param->H_param;
    // int W = emax6_param->W_param;
    int* count = (int*) calloc(col_size,sizeof(int));
    int* count_tmp = (int*) calloc((col_size+1),sizeof(int));
    int* count_sort_index_inverse = (int*) calloc(row_size,sizeof(int));
    Uint* count_sort_index= (Uint*) calloc(row_size,sizeof(Uint));
    int* row_count = (int*) calloc((row_size+1),sizeof(int));
    int* col_count = (int*) calloc((col_size+1),sizeof(int));
    int* paddings = (int*) calloc((row_size),sizeof(int));
    int count_tmp1;
    Ull* margin = (Ull*) calloc((row_size/H),sizeof(Ull));
    int iter_num = 0,margin_tmp;
    
    for(int k=0; k<nnz; k++) count[row_index[k]]++; //ex {[0] = 3, [1] = 2, [2] = 2, [3] = 4, [4] = 4, [5] = 1, [6] = 4, [7] = 6, [8] = 4, [9] = 5}

    for(int row=0; row<row_size; row++){
        count_tmp[count[row]]++; //  {[0] = 0, [1] = 1, [2] = 2, [3] = 1, [4] = 4, [5] = 1, [6] = 1, [7] = 0, [8] = 0, [9] = 0, [10] = 0} 
    }
    for(int row=0; row<row_size; row++) count_tmp[row+1] += count_tmp[row];  //値を適切な場所に入れるため ex {[0] = 0, [1] = 1, [2] = 3, [3] = 4, [4] = 8, [5] = 9, [6] = 10, [7] = 10, [8] = 10, [9] = 10, [10] = 10}  
    for(int row=0,tmp; row<row_size; row++){
        count_tmp1 = --count_tmp[count[row]]; // ex count[row]=3  --count_tmp[count[row]]=3  --は0から始めるため
        
        // count_sort_indexと count_sort_index_inverseは逆の関係
        //count_sort_indexは並べ替えた後、該当のrow(index)に入るべき、並べ替え後のrow(index)を表していていて、count_sort_index_inverseは並べ替え後にindex(row)を代入したら並べ替え後の場所を教えてくれる。
        //{[0] = 7, [1] = 9, [2] = 3, [3] = 4, [4] = 6, [5] = 8, [6] = 0, [7] = 1, [8] = 2, [9] = 5}
        // 実際のIMAXではUllでの足し算なのでポインタの足し算にならない　よって×4がいる。
        count_sort_index[(row_size-1)-count_tmp1] =  row*2*4;  //降下sortされた場所に入る //simdの×2 

        //CSCで格納　indexがその列で何番目かを表している。分布数えソートは昇順なので、 (row_size-1) - count_tmp1dで降順にする。  
        // row_size-1は0から始めるために引く1している。            
        // ex row=0 count_sort_index_inverse[row]=6 row_size-1=9 count_tmp1=3　0行目は3番目に小さいの0列目の7-1番目に入る
        //{[0] = 6, [1] = 7, [2] = 8, [3] = 2, [4] = 3, [5] = 9, [6] = 4, [7] = 0, [8] = 5, [9] = 1}
        count_sort_index_inverse[row] = (row_size-1) - count_tmp1;
         //アライメントのために次の手段は使えない 倍数の時のみ可(count[row] + (H-1))~(H-1);
         // sortされた後のrowごとのpaddings
         //降順
         paddings[(row_size-1) - count_tmp1] = count[row]/H + (int)(count[row]%H != 0); 

    }


    //paddingsは最低でも1
    //最小のpaddingsではAを一番下まで確保するので、row_size
    for(int iter=0;iter<paddings[row_size-1]; iter++){
        margin[iter_num++] = row_size; //row+1
    }
    for(int row=row_size-2,tmp=paddings[row_size-1]; row>=0; row--){
        //前回からの変化があれば変化の差分を埋める
        if(tmp != paddings[row]){
            //row+1が入っているので、margin[iter_num-1]-1
            for(int iter=paddings[margin[iter_num-1]-1];iter<paddings[row]; iter++){
                //row+1が入る multiplyのfor文で扱いやすくするため。 for (rofs=0; rofs<A_margin[blk_iter]; rofs++) 
                margin[iter_num++] = row+1;
            } 
        }
        tmp = paddings[row];
    }


    // Uint* val_debug    = (Uint*) calloc(1+row_size*col_size,sizeof(Uint));
    Ull* val_index_set = val;
    int* col_index_sparse = (int*) calloc(row_size*col_size,sizeof(int));
    int* row_index_sort_sparse = (int*) calloc((row_size*col_size),sizeof(int));
    

    for(int k=0,count_sort_index_inverse_tmp=0; k<nnz; k++){
        //CSCで格納
        // row_countは最初すべて0 row_countがふえると格納する行が右にずれて格納先が次のLMMになる
        //count_sort_index_inverse[row_index[k]]でどの行かを特定
        //row_count[1+row_index[k]]*row_sizeでどの列かを特定
        //CSRのpのようにrow_countを0から使うために1+row_index[k]にしている
        count_sort_index_inverse_tmp = count_sort_index_inverse[row_index[k]];
        //count_sort_index_inverseは並べ替え後にindex(row)を代入したら並べ替え後の場所を教えてくれる。
        //indexを1からスタートする。0は下段にindexを伝播するためだけに使う
        //Aが次のUnitに伝搬するのを表現するためにどの列かを特定+1
        //*((Uint*)&val_index_set[どの行かを特定+(どの列かを特定+1)]) = Aの値  
        //*((Uint*)&val_index_set[前の行+どの列かを特定]+1) = Bの対応箇所(下段Unit)*2(simd)*4(実際のIMAXコードはUllのアドレス演算なので4byteかける)
        *((Uint*)&val_index_set[(count_sort_index_inverse_tmp)+(1+row_count[1+row_index[k]])*row_size]) = val_tmp[row_index[k]+col_index[k]*row_size];
        *((Uint*)&val_index_set[count_sort_index_inverse_tmp+row_count[1+row_index[k]]*row_size]+1) = col_index[k]*2*4;
        // *((Uint*)&val_debug[(1+count_sort_index_inverse_tmp)+row_count[1+row_index[k]]*row_size]) = val[row_index[k]+col_index[k]*row_size];
         //rowを左詰めしているので、colの位置が値ごとに必要
        col_index_sparse[count_sort_index_inverse_tmp+row_count[1+row_index[k]]*row_size] = col_index[k];
        row_index_sort_sparse[k] = count_sort_index_inverse_tmp;
        row_count[1+row_index[k]]++;
        col_count[1+col_index[k]]++;

    }

    sparse_info->val_index_set = val_index_set;
    sparse_info->col_p = col_count;
    sparse_info->col_index = col_index_sparse;
    sparse_info->sort_index = count_sort_index;
    sparse_info->nnz = nnz;
    sparse_info->row_normal_size = row_size;
    sparse_info->col_normal_size = col_size;
    sparse_info->paddings = paddings;
    sparse_info->margin = margin;
    
    
    free(count);
    free(count_tmp);
    free(row_count);
    free(col_index);
    free(row_index);
    free(row_index_sort_sparse);
    // free(val_debug);


    return sparse_info;

//Cは書き込みながら転置？
//outputCはCCR形式

}
