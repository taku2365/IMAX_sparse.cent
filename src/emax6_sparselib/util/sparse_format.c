#include "../Include/emax6_sparselib.h"


emax6_sparse2* sparse_format(int nnz,Ull* val,Uint*val_tmp, const int* const col_index, const int* const row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write){
    // arg
    //mode 0 chip_divB_ver3 mode 1 chip_divB_ver4
    //read_or_write 0 none 1 read 2 write
    //valなどをformatに入れるとパフォーマンスが落ちるので、実装とinterfaceの分離をしない。

    printf("Format\n");
    FILE *file;
    emax6_sparse2* sparse_info = (emax6_sparse2 *) malloc(1*sizeof(emax6_sparse2));
    sparse_info->val_index_set = NULL;
    sparse_info->col_p = NULL;
    sparse_info->col_index = NULL;
    sparse_info->sort_index = NULL;
    sparse_info->nnz = NULL;
    sparse_info->row_normal_size = NULL;
    sparse_info->col_normal_size = NULL;
    sparse_info->paddings = NULL;
    sparse_info->margin = NULL;
    sparse_info->margin_sum = NULL;
    sparse_info->col_num = NULL;
    Uint* val_index_set = (Uint*) val;
    size_t A_row_size_pad = emax6_param->A_row_size_pad_param;
    size_t A_col_size_pad = emax6_param->A_col_size_pad_param;
    if((emax6_param->mode == DENSE_DENSE_MODE)||(emax6_param->mode == DENSE_SPMV_MODE)){
        memcpy(val,val_tmp,A_row_size_pad*A_col_size_pad*sizeof(Uint));
        sparse_info->val_index_set = val;
        return sparse_info;
    }

    int H = emax6_param->H_param;
    int A_col_blk = emax6_param->A_col_blk_param;
    int H_pad = 0;
    int pad_max;
    // int col_size1 = coo.col_size;
    // int row_size1 = coo.row_size;
    // const int* row_index1 = coo.row_index;
    // const int* col_index1 = coo.col_index;
    // const Uint* val_in = coo.val;

    if(!val || !col_index || !row_index ) {
        fprintf(stderr,"sparse_format NULL error! \n");
        exit(1);
    }

    if(read_or_write == 1){
   // bはbinary fileのこと
    if((file = fopen(file_name, "rb")) == NULL) {
        fprintf(stderr, "Error opening file for reading.\n");
        return 0;
    }
    else{


        int col_size,row_size;
        fread(&row_size,         sizeof(int),  1,                         file);
        fread(&col_size,         sizeof(int),  1,                         file);
        sparse_info->row_normal_size = row_size;
        sparse_info->col_normal_size = col_size;
        fread(&sparse_info->nnz,                     sizeof(int),  1,     file);
        fread(val,     sizeof(Uint), 2*((col_size)*row_size), file);
        sparse_info->val_index_set = val_index_set;
        int* col_count = calloc((col_size),sizeof(int)); 
        fread(col_count,         sizeof(int),  col_size,                file);
        sparse_info->col_p = col_count;
        // int* col_index_sparse = (int*) calloc(row_size*col_size,sizeof(int));
        // fread(col_index_sparse,  sizeof(int),  row_size*col_size,         file);
        // sparse_info->col_index= col_index_sparse;
        Uint* count_sort_index = sort_index;
        // Uint* count_sort_index = (Uint*) calloc(row_size,sizeof(Uint));
        fread(count_sort_index,  sizeof(Uint), row_size,                  file);
        sparse_info->sort_index = count_sort_index;
        int* paddings = (int*) calloc(row_size,sizeof(int));
        fread(paddings,          sizeof(int),  row_size,                  file);
        sparse_info->paddings = paddings;
        if((col_size%H) != 0) H_pad = -col_size%H + H;
        Ull* margin = (Ull*) calloc((col_size/H+H_pad),sizeof(Ull));
        fread(margin,            sizeof(Ull),  row_size/H,                file);
        sparse_info->margin = margin;
        fclose(file); 
 

        return sparse_info;

    }
   }


    // int W = emax6_param->W_param;
    int* count = (int*) calloc(row_size,sizeof(int));
    // そのrowのnnz maxはcol_sizeなのでcout_tmpはcol_sizeを確保する。
    int* count_tmp = (int*) calloc((col_size+1),sizeof(int));
    int* count_sort_index_inverse = (int*) calloc(row_size,sizeof(int));
    Uint* count_sort_index= sort_index;
    int* row_count = (int*) calloc((row_size),sizeof(int));
    int* col_count = (int*) calloc((col_size),sizeof(int));
    int* paddings = (int*) calloc((row_size),sizeof(int));
    int count_tmp1;
    size_t col_max = 0;
    size_t byte_conv = 0;
    //A_colがHで割れないときのpadding
     //Hで割り切れないとき、割り切れない分のa_indexは0が入る  その結果、B_row=0が選ばれるがa[]には0がpadされているのでA[]*B[]=0となり問題ない
    //ex  H=42 col_size=96  -> H_pad = -4 + 46 = 42   size = 42+96=138   138/46=3
    if((col_size%H) != 0) H_pad = -col_size%H + H;
    // ptopではみ出ないため、念のための2* 
    Ull* margin = (Ull*) calloc(2*(col_size+H_pad)/H+1,sizeof(Ull));
    int iter_num = 0,margin_tmp;
    int k,row,row1,col,col1,iter,count_sort_index_inverse_tmp,tmp,val_index_index,val_index_index2,row_index_k,col_index_k;
    for(k=0; k<nnz; k++) count[row_index[k]]++; //ex {[0] = 3, [1] = 2, [2] = 2, [3] = 4, [4] = 4, [5] = 1, [6] = 4, [7] = 6, [8] = 4, [9] = 5}
        // count max = col_size
        for(row=0; row<row_size; row++){
            count_tmp[count[row]]++; //  {[0] = 0, [1] = 1, [2] = 2, [3] = 1, [4] = 4, [5] = 1, [6] = 1, [7] = 0, [8] = 0, [9] = 0, [10] = 0} 
        }
        // count max = col_size   rowとcolを混同してはいけない                                                                                                                  //row_nnz=2が3つ   row_nnz=3が4つ
    for(col=0; col<col_size; col++) count_tmp[col+1] += count_tmp[col];  //値を適切な場所に入れるため ex {[0] = 0, [1] = 1, [2] = 3, [3] = 4, [4] = 8, [5] = 9, [6] = 10, [7] = 10, [8] = 10, [9] = 10, [10] = 10}  

    //BとCがベクトルになるかで分ける
    if((emax6_param->data_format == CSR_INDEX_VAL_SET_SPMV_FORMAT)||(emax6_param->data_format == JDS_INDEX_VAL_SET_SPMV_FORMAT)){
        byte_conv = 4;
    }
    else{
        byte_conv = 4*2;
    }

    if((emax6_param->data_format != CSR_INDEX_VAL_SET_FORMAT)&&(emax6_param->data_format != CSR_INDEX_VAL_SET_SPMV_FORMAT)){
        for(row=0; row<row_size; row++){
            count_tmp1 = --count_tmp[count[row]]; // ex count[3]==4　--count_tmp[count[3]]==--8 == 7  row=3に4つのnnzがあって、8-1=7番目に少ない(昇順)      --は0番目から始めるため
            
            // count_sort_indexと count_sort_index_inverseは逆の関係
            //count_sort_indexは並べ替えた後、該当のrow(index)に入るべき、並べ替え前のrow(index)を返してくれて、count_sort_index_inverseはindex(row)を代入したら並べ替え後の場所を教えてくれる。
            //上の例が続いている 降順に表示  9番目がrow=5で一番少ないnnz=1
            //{[0] = 7, [1] = 9, [2] = 3, [3] = 4, [4] = 6, [5] = 8, [6] = 0, [7] = 1, [8] = 2, [9] = 5}
            // 実際のIMAXではUllでの足し算なのでポインタの足し算にならない　よって×4がいる。
            //Cが元の場所に戻すためにつかう
            tmp = (row_size-1) - count_tmp1;
            count_sort_index[tmp] =  row*byte_conv;  //降下sortされた場所に入る //simdの×2  spmvはAがsimdで2をかける

            //CSCで格納　indexがその列で何番目かを表している。分布数えソートは昇順なので、 (row_size-1) - count_tmp1dで降順にする。  
            // row_size-1は0から始めるために引く1している。            
            //count_sort_indexの逆                                             row7番目は一番nnzが多いので0に移動する
            //{[0] = 6, [1] = 7, [2] = 8, [3] = 2, [4] = 3, [5] = 9, [6] = 4, [7] = 0, [8] = 5, [9] = 1}
            //元の場所から並べ替えの先に移動するために使う
            count_sort_index_inverse[row] = tmp;
            //アライメントのために次の手段は使えない 倍数の時のみ可(count[row] + (H-1))~(H-1);
            // sortされた後のrowごとのpaddings
            //降順   上が一番nnzが長いrow
            // count[row]/H(IMAXが何回full(H)で計算いるか)+(int)(count[row]%H != 0) (Hで割り切れなかったら、もう一回H分の計算がpad付きで必要)
            paddings[tmp] = count[row]/H + (int)(count[row]%H != 0); 

        }
        //paddingsは最低でも1
        //marginはA_colをH進めるごとにA_rowをどれだけ確保すればいいかを教えてくれる
        //最小のpaddingsではAを一番下まで確保するので、row_size+1
        //ex paddings[row_size-1]=7 (row+1)  一番下のArowでもH分を6回計算  H*6回分のA_colはA_rowの一番下まで計算　よってrow_sizeを6回、marginに入れる 　  
        for(iter=0;iter<(paddings[row_size-1]); iter++){
            margin[iter_num++] = row_size; //row+1
        }
        // row_size回 for分を回す
        for(row=row_size-1,tmp=paddings[row_size-1]; row>=0; row--){
            //前回からの変化があれば変化の差分を埋める
            //  定義部分　Ull* margin = (Ull*) calloc((col_size/H),sizeof(Ull));
            // ex col_size/H 736/46=16
            //H*7は735がA_row方向のnnzの最後 H*8は365が最大
            // marginが決まったら、そのH区間はその値を使う
            //p margin[0]@16 $2 = {[0] = 736, [1] = 736, [2] = 736, [3] = 736, [4] = 736, [5] = 736, [6] = 736, [7] = 735, [8] = 365, [9] = 0, [10] = 0, [11] = 0, [12] = 0, [13] = 0, [14] = 0, [15] = 0}
            if(tmp != paddings[row]){
                //row+1が入っているので、margin[iter_num-1]-1 
                //iter_numはmargin[iter_num++]とされているの、iter_num-1は前回のiter_numを表している
                // A_rowの一番最後のrow_size-1から始める  marginを埋めるのは0から
                // tmp != paddings[row] 変化した次のrowを代入している
                // ex margin[iter_num-1]-1 == 736-1 = 735  paddings[margin[iter_num-1]-1]=2
                // 4 -> 2のようにいきなりpaddingが二個飛びで変化するケースに対応している。
                if(iter_num != 0) {
                    margin_tmp = margin[iter_num-1]-1;
                }
                else if(paddings[row+1] == 0){
                    //一個もnnzがあるrowが見つかってない偏りがあるパターン
                    margin_tmp = row+1;
                }
                else{
                    fprintf(stderr,"fail format LINE %d",__LINE__);
                }
    
                for(iter=paddings[margin_tmp];iter<paddings[row]; iter++){
                    //row+1が入る multiplyのfor文で扱いやすくするため。 for (rofs=0; rofs<A_margin[blk_iter]; rofs++) 
                    margin[iter_num++] = row+1;
                } 
            }
            tmp = paddings[row];
        }
    }
    else{
        //mmとspmvのCSR処理

        pad_max = 0;
        // count max = col_size   rowとcolを混同してはいけない                                                                                                                  
        
        for(row=0; row<row_size; row++){
            
            count_sort_index[row] =  row*byte_conv;  //降下sortされた場所に入る //simdの×2 
            paddings[row] = count[row]/H + (int)(count[row]%H != 0); 
            if(paddings[row]>pad_max){pad_max = paddings[row];}   
        }
        for(iter=0;iter<(pad_max); iter++){
            margin[iter_num++] = row_size; //row+1
        }
    }
 


    if(emax6_param->data_format == CSR_INDEX_VAL_SET_FORMAT){
        for(k=0; k<nnz; k++){
        row_index_k = row_index[k];
        col_index_k = col_index[k];
        
        val_index_index = (row_index_k+row_count[row_index_k]*row_size)*2;
        *((Ull*)&val_index_set[val_index_index]) = ((Ull)col_index_k*2*4)<<32|(Ull)val_tmp[row_index_k+col_index_k*row_size];

        row_count[row_index_k]++;
        }
    }
    else if(emax6_param->data_format == JDS_INDEX_SEPARATE_FORMAT){

        Uint* val_index_set_tmp = (Uint*) calloc(2*row_size*col_size,sizeof(Uint));
        for(k=0,count_sort_index_inverse_tmp=0; k<nnz; k++){
        //CSCで格納
        // row_countは最初すべて0 row_countがふえると格納する行が右にずれて格納先が次のLMMになる
        //count_sort_index_inverse[row_index[k]]でどの行かを特定
        //row_count[1+row_index[k]]*row_sizeでどの列かを特定
        count_sort_index_inverse_tmp = count_sort_index_inverse[row_index[k]];
        //count_sort_index_inverseはindex(row)を代入したら並べ替え後の場所を教えてくれる。
        //*((Uint*)&val_index_set[どの行かを特定+どの列かを特定]) = Aの値  
        //*((Uint*)&val_index_set[どの行かを特定+どの列かを特定]) = Bの対応箇所*2(simd)*4(実際のIMAXコードはUllのアドレス演算なのでpoiterの足し算ではないので4byteかける)
        val_index_set[count_sort_index_inverse_tmp+row_count[row_index[k]]*row_size] = val_tmp[row_index[k]+col_index[k]*row_size];
        val_index_set_tmp[count_sort_index_inverse_tmp+row_count[row_index[k]]*row_size] = col_index[k]*2*4;
        // *((Uint*)&val_debug[(1+count_sort_index_inverse_tmp)+row_count[row_index[k]]*row_size]) = val[row_index[k]+col_index[k]*row_size];
         //rowを左詰めしているので、colの位置が値ごとに必要
        // col_index_sparse[count_sort_index_inverse_tmp+row_count[row_index[k]]*row_size] = col_index[k];
        // row_index_sort_sparse[k] = count_sort_index_inverse_tmp;
        //そのrowに何個nonzeroがあるか
        row_count[row_index[k]]++;
        col_count[col_index[k]]++;

        }

        //32bit*2でindexを伝搬するためにAのindexをこのように格納
        for(col=0,col1=0; col<col_size/2; col+=1,col1+=2){
            for(row=0,row1=0; row1<row_size; row+=2,row1+=1) {
            #ifdef CSIMDEBUG
            printf("format\n");
            #endif
        *(Uint*)&val_index_set[col*2*row_size+row+row_size*col_size] = *(Uint*)&val_index_set_tmp[col1*row_size+row1];
        // Bの対応箇所*2(simd)*4(実際のIMAXコードはUllのアドレス演算なのでpoiterの足し算ではないので4byteかける)
        *(Uint*)&val_index_set[col*2*row_size+row+1+row_size*col_size] = *(Uint*)&val_index_set_tmp[(col1+1)*row_size+row1];
            }
        }
    if(val_index_set_tmp != NULL){
        free(val_index_set_tmp);
        val_index_set_tmp = NULL;
    }
    }
    else if(emax6_param->data_format == JDS_INDEX_VAL_SET_FORMAT){
        for(k=0; k<nnz; k++){
        
            row_index_k = row_index[k];
            col_index_k = col_index[k];
            val_index_index = (count_sort_index_inverse[row_index_k]+row_count[row_index_k]*row_size)*2;
            //col_index_k*2*4はBをsimdで折りたたんでいるため
            *((Ull*)&val_index_set[val_index_index]) = ((Ull)col_index_k*2*4)<<32|(Ull)val_tmp[row_index_k+col_index_k*row_size];

            row_count[row_index_k]++;
        }
    }
    else if(emax6_param->data_format == JDS_INDEX_VAL_SET_SPMV_FORMAT){
        for(k=0; k<nnz; k++){
        
            row_index_k = row_index[k];
            col_index_k = col_index[k];
            val_index_index = (count_sort_index_inverse[row_index_k]+row_count[row_index_k]*row_size)*2;
            //col_index_k*2*4はBをsimdで折りたたんでいるため
            *((Ull*)&val_index_set[val_index_index]) = ((Ull)col_index_k*4)<<32|(Ull)val_tmp[row_index_k+col_index_k*row_size];

            row_count[row_index_k]++;
        }
    }
    else if((emax6_param->data_format == CSR_INDEX_VAL_SET_SPMV_FORMAT)){
        for(k=0; k<nnz; k++){
            row_index_k = row_index[k];
            col_index_k = col_index[k];
            
            val_index_index = (row_index_k+row_count[row_index_k]*row_size)*2;
            //折りたたんでないので*4だけでいい
            *((Ull*)&val_index_set[val_index_index]) = ((Ull)col_index_k*4)<<32|(Ull)val_tmp[row_index_k+col_index_k*row_size];

            row_count[row_index_k]++;
        }

    }
    else{
        fprintf("data_format %d mode %d ,This pattern dosenot exsit !\n",emax6_param->data_format,emax6_param->mode);
    }

    for(tmp=0; tmp<row_size; tmp++){
        if(row_count[tmp]>col_max){
            col_max = row_count[tmp]; }
    }


    sparse_info->val_index_set = val_index_set;
    sparse_info->col_p = col_count;
    // sparse_info->col_index = (Uint*)col_index_sparse;
    sparse_info->sort_index = count_sort_index;
    sparse_info->nnz = nnz;
    sparse_info->row_normal_size = row_size;
    sparse_info->col_normal_size = col_size;
    sparse_info->paddings = paddings;
    sparse_info->margin = margin;

    emax6_param->col_max = col_max;

       
   
   if(read_or_write==2){
   // bはbinary fileのこと
    if((file = fopen(file_name, "wb")) == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return 0;
    }
    else{

        fwrite(&row_size,         sizeof(int),  1,                         file);
        fwrite(&col_size,         sizeof(int),  1,                         file);
        fwrite(&nnz,              sizeof(int),  1,                         file);
        fwrite(val_index_set,     sizeof(Uint), 2*((col_size)*row_size),   file);
        fwrite(col_count,         sizeof(int),  col_size,                  file);
        // fwrite(col_index_sparse,  sizeof(int),  row_size*col_size,         file);
        fwrite(count_sort_index,  sizeof(Uint), row_size,                  file);
        fwrite(paddings,          sizeof(int),  row_size,                  file);
        fwrite(margin,            sizeof(Ull),  col_size/H+H_pad,     file);

        fclose(file);   
    }
   }

    
    free(count);
    free(count_tmp);
    free(row_count);
    // free(paddings);
    // free(row_index_sort_sparse);
    free(count_sort_index_inverse);



    return sparse_info;

//Cは書き込みながら転置？
//outputCはCCR形式

}



void free_sparse_format(emax6_sparse2* sparse_format){
      if(sparse_format->col_p != NULL){
  free(sparse_format->col_p);
  sparse_format->col_p = NULL;
  }
  if(sparse_format->col_index != NULL){
  free(sparse_format->col_index);
  sparse_format->col_index = NULL;
  }
//   if(sparse_format->val_index_set != NULL){
//   free(sparse_format->val_index_set);
//   sparse_format->val_index_set = NULL;
//   }
  // if(sparse_format->sort_index != NULL){
  // free(sparse_format->sort_index);
  // sparse_format->sort_index = NULL;
  // }
  if(sparse_format->paddings != NULL){
  free(sparse_format->paddings);
  sparse_format->paddings = NULL;
  }
  if(sparse_format->col_num != NULL){
  free(sparse_format->col_num);
  sparse_format->col_num = NULL;
  }
  if(sparse_format->margin != NULL){
  free(sparse_format->margin);
  sparse_format->margin = NULL;
  }
  if(sparse_format->margin_sum != NULL){
  free(sparse_format->margin_sum);
  sparse_format->margin_sum = NULL;
  }
  if(sparse_format != NULL){
  free(sparse_format);
  sparse_format = NULL;
  }

}