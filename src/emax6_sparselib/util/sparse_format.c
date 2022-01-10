#include "../Include/emax6_sparselib.h"


emax6_sparse2* sparse_format(int nnz,Ull* val,Uint*val_tmp, const int* const col_index, const int* const row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write){
    // arg
    //mode 0 chip_divB_ver3 mode 1 chip_divB_ver4
    //read_or_write 0 none 1 read 2 write
    //valなどをformatに入れるとパフォーマンスが落ちるので、引数に直接渡す。

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
    int H = emax6_param->H_param;
    int A_col_blk = emax6_param->A_col_blk_param;
    int H_pad = 0;
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
    //A_colがHで割れないときのpadding
     //Hで割り切れないとき、割り切れない分のa_indexは0が入る  その結果、B_row=0が選ばれるがa[]には0がpadされているのでA[]*B[]=0となり問題ない
    //ex  H=42 col_size=96  -> H_pad = -4 + 46 = 42   size = 42+96=138   138/46=3
    if((col_size%H) != 0) H_pad = -col_size%H + H;
    Ull* margin = (Ull*) calloc((col_size+H_pad)/H+1,sizeof(Ull));
    int iter_num = 0,margin_tmp;
    int k,row,row1,col,col1,iter,count_sort_index_inverse_tmp,tmp,val_index_index,val_index_index2,row_index_k,col_index_k;
    // if ((fpr = fopen(argv[1], "rb")) == NULL){
    //     printf("cal val\n");
    // }
    // else{
    
    // }

    for(k=0; k<nnz; k++) count[row_index[k]]++; //ex {[0] = 3, [1] = 2, [2] = 2, [3] = 4, [4] = 4, [5] = 1, [6] = 4, [7] = 6, [8] = 4, [9] = 5}
    // count max = col_size
    for(row=0; row<row_size; row++){
        count_tmp[count[row]]++; //  {[0] = 0, [1] = 1, [2] = 2, [3] = 1, [4] = 4, [5] = 1, [6] = 1, [7] = 0, [8] = 0, [9] = 0, [10] = 0} 
    }
    // count max = col_size   rowとcolを混同してはいけない                                                                                                                  //row_nnz=2が3つ   row_nnz=3が4つ
    for(col=0; col<col_size; col++) count_tmp[col+1] += count_tmp[col];  //値を適切な場所に入れるため ex {[0] = 0, [1] = 1, [2] = 3, [3] = 4, [4] = 8, [5] = 9, [6] = 10, [7] = 10, [8] = 10, [9] = 10, [10] = 10}  
    for(row=0; row<row_size; row++){
        count_tmp1 = --count_tmp[count[row]]; // ex count[3]==4　--count_tmp[count[3]]==--8 == 7  row=3に4つのnnzがあって、8-1=7番目に少ない(昇順)      --は0番目から始めるため
        
        // count_sort_indexと count_sort_index_inverseは逆の関係
        //count_sort_indexは並べ替えた後、該当のrow(index)に入るべき、並べ替え前のrow(index)を返してくれて、count_sort_index_inverseはindex(row)を代入したら並べ替え後の場所を教えてくれる。
        //上の例が続いている 降順に表示  9番目がrow=5で一番少ないnnz=1
        //{[0] = 7, [1] = 9, [2] = 3, [3] = 4, [4] = 6, [5] = 8, [6] = 0, [7] = 1, [8] = 2, [9] = 5}
        // 実際のIMAXではUllでの足し算なのでポインタの足し算にならない　よって×4がいる。
        //Cが元の場所に戻すためにつかう
        tmp = (row_size-1) - count_tmp1;
        count_sort_index[tmp] =  row*2*4;  //降下sortされた場所に入る //simdの×2 

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
    for(iter=0;iter<(paddings[row_size-1]+1); iter++){
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
            for(iter=paddings[margin[iter_num-1]-1];iter<paddings[row]; iter++){
                //row+1が入る multiplyのfor文で扱いやすくするため。 for (rofs=0; rofs<A_margin[blk_iter]; rofs++) 
                margin[iter_num++] = row+1;
            } 
        }
        tmp = paddings[row];
    }
    // reset_nanosec();


    if(emax6_param->mode == 1){

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
        *(Uint*)&val_index_set[col*2*row_size+row+1+row_size*col_size] = *(Uint*)&val_index_set_tmp[(col1+1)*row_size+row1];
            }
        }
       free(val_index_set_tmp);

    }

    else if((emax6_param->mode == 2)||(emax6_param->mode == 3)){
        for(k=0; k<nnz; k++){
        row_index_k = row_index[k];
        col_index_k = col_index[k];

        val_index_index = (count_sort_index_inverse[row_index_k]+row_count[row_index_k]*row_size)*2;
        *((Ull*)&val_index_set[val_index_index]) = ((Ull)col_index_k*2*4)<<32|(Ull)val_tmp[row_index_k+col_index_k*row_size];

        row_count[row_index_k]++;
        }
    }

//         get_nanosec(0);
//   show_nanosec();
//   exit(1);



    sparse_info->val_index_set = val_index_set;
    sparse_info->col_p = col_count;
    // sparse_info->col_index = (Uint*)col_index_sparse;
    sparse_info->sort_index = count_sort_index;
    sparse_info->nnz = nnz;
    sparse_info->row_normal_size = row_size;
    sparse_info->col_normal_size = col_size;
    sparse_info->paddings = paddings;
    sparse_info->margin = margin;

       
   
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



emax6_sparse2* sparse_format1(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param,Uint* sort_index,const char* file_name,int read_or_write){

    // arg read_or_write 0 none 1 read 2 write
    //AをCHIP分割バージョン CHIPごとにmarginを変えないver


    FILE *file;
    emax6_sparse2* sparse_info = (emax6_sparse2 *) malloc(1*sizeof(emax6_sparse2));
    Uint* val_index_set = (Uint*) val;
    int H = emax6_param->H_param;
    int NCHIP = emax6_param->NCHIP_param;
    int H_pad = 0;

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
        int* col_index_sparse = (int*) calloc(row_size*col_size,sizeof(int));
        fread(col_index_sparse,  sizeof(int),  row_size*col_size,         file);
        sparse_info->col_index= col_index_sparse;
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
    int* count_chip = (int*) calloc(NCHIP,sizeof(int));
    // そのrowのnnz maxはcol_sizeなのでcout_tmpはcol_sizeを確保する。
    int count_tmp;
    int* count_sort_index_inverse = (int*) calloc(row_size,sizeof(int));
    Uint* count_sort_index= sort_index;
    int* row_count = (int*) calloc((row_size),sizeof(int));
    int* col_count = (int*) calloc((col_size),sizeof(int));
    int* paddings = (int*) calloc((row_size),sizeof(int));
    int count_tmp1;
    //A_colがHで割れないときのpadding
     //Hで割り切れないとき、割り切れない分のa_indexは0が入る  その結果、B_row=0が選ばれるがa[]には0がpadされているのでA[]*B[]=0となり問題ない
    //ex  H=42 col_size=96  -> H_pad = -4 + 46 = 42   size = 42+96=138   138/46=3
    if((col_size%H) != 0) H_pad = -col_size%H + H;
    Ull* margin = (Ull*) calloc(1,sizeof(Ull));
    Ull* margin_sum = (Ull*) calloc(NCHIP+1,sizeof(Ull));
    int iter_num = 0,margin_tmp;
    int k,h,row,chip,row_blk_prev,row1,blk,blk4,col,col1,row_blk,col_blk,iter,row_div_NHCHIP,count_sort_index_inverse_tmp,tmp,sum,sum1,index_sum,margin_index,margin_index1;
    double sum_double,sum1_double;
    // if ((fpr = fopen(argv[1], "rb")) == NULL){
    //     printf("cal val\n");
    // }
    // else{
    
    // }
    for(k=0; k<nnz; k++) count[row_index[k]]++; //ex {[0] = 3, [1] = 2, [2] = 2, [3] = 4, [4] = 4, [5] = 1, [6] = 4, [7] = 6, [8] = 4, [9] = 5}
    // count max = col_size

    margin_tmp = 0;
    count_tmp = 0;
    for(k=0; k<row_size; k++){
        //rowのなかでnnz最大値
        if(count[k]>count_tmp){
            count_tmp = count[k];
        }
    }

    // margin_tmp/H(A_colがなんかいHを必要とするか count_chip[0]が0になるために+1)　*(row_size/NCHIP) (変形後の必要なA_rowの長さに変換)
    if(count_tmp%H != 0){
        count_tmp = count_tmp - count_tmp%H + H;
    }
    margin_tmp = (Ull)(count_tmp/H)*(row_size/NCHIP);   
    margin[0] = margin_tmp; 
    // marginがCHIPごとに増えていく
    // for(chip=0;chip<NCHIP;chip++) margin_sum[chip+1] = margin_tmp + margin_sum[chip];
    // Uint* val_debug    = (Uint*) calloc(1+row_size*col_size,sizeof(Uint));

    Uint* val_index_set_tmp = (Uint*) calloc(2*row_size*col_size,sizeof(Uint));
    Uint* val_index_set_tmp1 = (Uint*) calloc(row_size*col_size,sizeof(Uint));
    Uint* col_index_sparse = (Uint*) calloc(row_size*col_size,sizeof(Uint));
    // int* row_index_sort_sparse = (int*) calloc((row_size*col_size),sizeof(int));
    

    for(k=0; k<nnz; k++){
        //CSCで格納
        // row_countは最初すべて0 row_countがふえると格納する行が右にずれて格納先が次のLMMになる
        //count_sort_index_inverse[row_index[k]]でどの行かを特定
        //row_count[1+row_index[k]]*row_sizeでどの列かを特定
        // count_sort_index_inverse_tmp = count_sort_index_inverse[row_index[k]];
        //count_sort_index_inverseはindex(row)を代入したら並べ替え後の場所を教えてくれる。
        //*((Uint*)&val_index_set[どの行かを特定+どの列かを特定]) = Aの値  
        //*((Uint*)&val_index_set[どの行かを特定+どの列かを特定]) = Bの対応箇所*2(simd)*4(実際のIMAXコードはUllのアドレス演算なのでpoiterの足し算ではないので4byteかける)
        val_index_set_tmp[row_index[k]+row_count[row_index[k]]*row_size] = val_tmp[row_index[k]+col_index[k]*row_size];
        val_index_set_tmp[row_index[k]+row_count[row_index[k]]*row_size+row_size*col_size] = col_index[k]*2*4;
        // *((Uint*)&val_debug[(1+count_sort_index_inverse_tmp)+row_count[row_index[k]]*row_size]) = val[row_index[k]+col_index[k]*row_size];
         //rowを左詰めしているので、colの位置が値ごとに必要
        col_index_sparse[row_index[k]+row_count[row_index[k]]*row_size] = col_index[k];
        // row_index_sort_sparse[k] = count_sort_index_inverse_tmp;
        //そのrowに何個nonzeroがあるか
        row_count[row_index[k]]++;
        col_count[col_index[k]]++;

    }

    index_sum = 0;
    for(row_blk=0;row_blk<NCHIP;row_blk++){
        for(col=0;col<H;col++){
            for(col_blk=0;col_blk<count_tmp/H;col_blk++){
                for(row=0;row<(row_size/NCHIP);row++){
                // blk == (A_row_size/NCHIP)*Hのかたまり
                // *(Uint*)&val_index_set_tmp[row(blkないのrow)+col_blk*row_size*H(隣のblkに飛ぶ)+col*(row_size)(blk内のcol)+row_blk*(row_size/NCHIP)(下のblkに飛ぶ)]
                *(Uint*)&val_index_set[row+index_sum] =  *(Uint*)&val_index_set_tmp[row+col_blk*row_size*H+col*(row_size)+row_blk*(row_size/NCHIP)];
                *(Uint*)&val_index_set_tmp1[row+index_sum] =  *(Uint*)&val_index_set_tmp[row+col_blk*row_size*H+col*(row_size)+row_blk*(row_size/NCHIP)+row_size*col_size];
                }
                index_sum+=(row_size/NCHIP); 
            }
        }
    }


    // 32bit*2でindexを伝搬するためにAのindexをこのように格納
    #ifdef DEBUG
    sum = 0,sum1 = 0;
    for (col=0; col<col_size; col+=1){
      for (row=0; row<row_size; row+=1) {
      sum += (double)*(float*)&val_index_set_tmp[row+col*row_size];
      sum1 += (double)*(float*)&val_index_set[row+col*row_size];
        }
    }
    if(sum != sum1){
      printf("format error\n");
      printf("%d %d \n",sum,sum1);
      exit(1);
    }
    #endif

    // printf("before %d  after %d\n",sum,sum1);

    // exit(1);

    //32bit*2でindexを伝搬するためにAのindexをこのように格納
    for (col=0,col1=0; col<col_size/2; col+=1,col1+=2){
      for (row=0,row1=0; row1<row_size; row+=2,row1+=1) {
        
      *(Uint*)&val_index_set[col*2*row_size+row+row_size*col_size] = *(Uint*)&val_index_set_tmp1[col1*row_size+row1];
      *(Uint*)&val_index_set[col*2*row_size+row+1+row_size*col_size] = *(Uint*)&val_index_set_tmp1[(col1+1)*row_size+row1];
        }
    }

    #ifdef DEBUG
    sum=0,sum1=0;

    for (col=0; col<col_size; col+=1){
      for (row=0; row<row_size; row+=1) {
        
      sum += *(Uint*)&val_index_set_tmp1[col*row_size+row];
      sum1 += *(Uint*)&val_index_set[col*row_size+row+row_size*col_size];
        }
    }
  
    if(sum != sum1){
      printf("format error1\n");
      printf("%d %d \n",sum,sum1);
      exit(1);
    }
    #endif


    sparse_info->val_index_set = val_index_set;
    sparse_info->col_p = col_count;
    sparse_info->col_index = col_index_sparse;
    sparse_info->sort_index = count_sort_index;
    sparse_info->nnz = nnz;
    sparse_info->row_normal_size = row_size;
    sparse_info->col_normal_size = col_size;
    sparse_info->paddings = paddings;
    sparse_info->margin = margin;
    sparse_info->margin_sum = margin_sum;

       
   
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
        fwrite(col_index_sparse,  sizeof(int),  row_size*col_size,         file);
        fwrite(count_sort_index,  sizeof(Uint), row_size,                  file);
        fwrite(paddings,          sizeof(int),  row_size,                  file);
        fwrite(margin,            sizeof(Ull),  col_size/H+H_pad,     file);

        fclose(file);   
    }
   }


    
    free(count);
    // free(count_tmp);
    free(row_count);
    free(col_index);
    free(row_index);
    // free(row_index_sort_sparse);
    free(count_sort_index_inverse);
    free(val_index_set_tmp);



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