#include "../Include/emax6_sparselib.h"



static void IMAX_param_tunig_spmv_impl0(emax6_param* params){

    Sll A_row_size = params->A_row_size_param;
    Sll A_col_size = params->A_col_size_param;
    Sll B_row_size = params->B_row_size_param;
    Sll B_col_size = params->B_col_size_param;
    Sll A_row_size_pad = params->A_row_size_pad_param;
    Sll A_col_size_pad = params->A_col_size_pad_param;
    Sll B_row_size_pad = params->B_row_size_pad_param;
    Sll B_col_size_pad = params->B_col_size_pad_param;
    Sll A_col_blk  = 0                       ;
    Sll B_col_blk  = 1                       ;
    Sll NCHIP      = params->NCHIP_param     ;
    Uint W         = params->W_param         ;
    Uint H          = params->H_param         ;
    Uint B_col_pad = 0;
    if(NCHIP>1){
        fprintf(stderr,"you need to support MUlti CHIP IMAX_param_tuning %d \n",__LINE__);

    }
    // LMM_SIZE 64k LMM>>32 32k
    // *4 はbyte変換

    //A_row_size*A_col_blk(Aをどれだけcolに確保するか)*2(index+valのUllが最小単位なので)*4(byte変換) 
    do{
        A_col_blk += 1;
    }while(A_row_size_pad*A_col_blk*4<=(LMM_SIZE>>1)&&((A_row_size_pad*A_col_blk*H)<=A_row_size_pad*(A_col_size_pad)));
    A_col_blk -= 1;
    //32kよりBの確保範囲が小さいかつB_col*B_rowをCHIP数で割った数より小さいかつ64kよりCの確保範囲が小さいかつA_row*B_colをCHIP数で割った数より小さい
    if((A_col_blk == 0)){
            fprintf(stderr,"tuning fail line %d \n",__LINE__);
        exit(1);
    }

    if((A_col_blk == 0)){
        fprintf(stderr,"tuning fail\n");
        exit(1);
    }
    // A_col_blk = 1;
    params->A_col_blk_param = A_col_blk;
    params->B_col_blk_param = 1;
    params->C_col_blk_param = 1;
    params->LMM_usage_A_kbyte = ((A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_B_kbyte = ((B_row_size*B_col_blk)*4)/1000;
    params->LMM_usage_kbyte   =  ((B_row_size*B_col_blk+A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_A_rate  = (float)((A_row_size*A_col_blk)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_B_rate  = (float)((B_row_size*B_col_blk)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_rate    = (float)((B_row_size*B_col_blk+A_row_size*A_col_blk)*4)/(float)LMM_SIZE;

}



static void IMAX_param_tunig_impl0(emax6_param* params){

    Sll A_row_size = params->A_row_size_param;
    Sll A_col_size = params->A_col_size_param;
    Sll B_row_size = params->B_row_size_param;
    Sll B_col_size = params->B_col_size_param;
    Sll A_row_size_pad = params->A_row_size_pad_param;
    Sll A_col_size_pad = params->A_col_size_pad_param;
    Sll B_row_size_pad = params->B_row_size_pad_param;
    Sll B_col_size_pad = params->B_col_size_pad_param;
    Sll A_col_blk  = 0                       ;
    Sll B_col_blk  = 0                       ;
    Sll NCHIP      = params->NCHIP_param     ;
    Uint W         = params->W_param         ;
    Uint H          = params->H_param         ;
    Uint B_col_pad = 0;

    // LMM_SIZE 64k LMM>>32 32k
    // *4 はbyte変換

    //A_row_size*A_col_blk(Aをどれだけcolに確保するか)*2(index+valのUllが最小単位なので)*4(byte変換) 
    do{
        A_col_blk += 1;
    }while(A_row_size*A_col_blk*4<=(LMM_SIZE>>1)&&((A_row_size*A_col_blk*H)<=A_row_size*(A_col_size_pad)));
    A_col_blk -= 1;
    //32kよりBの確保範囲が小さいかつB_col*B_rowをCHIP数で割った数より小さいかつ64kよりCの確保範囲が小さいかつA_row*B_colをCHIP数で割った数より小さい
    if((A_col_blk == 0)){
            fprintf(stderr,"tuning fail line %d \n",__LINE__);
        exit(1);
    }

    do{
        B_col_blk += W*2;
    }while(
    ((B_row_size_pad)*B_col_blk*4<=(LMM_SIZE>>1))
    &&((B_row_size_pad)*B_col_blk<=((B_col_size_pad)*(B_row_size_pad)/NCHIP))
    &&((A_row_size*B_col_blk*4)<=LMM_SIZE)
    &&((A_row_size*B_col_blk)<=A_row_size*(B_col_size_pad)/NCHIP)
    );
    B_col_blk -= W*2;
    if((B_col_blk == 0)){
        fprintf(stderr,"tuning fail line %d \n",__LINE__);
        exit(1);
    }

    while(((B_col_size_pad)%(B_col_blk*NCHIP)) != 0){
        //B全体が収容できるようにするため
        B_col_blk -= W*2;
        if((B_col_blk == 0)){
            fprintf(stderr,"tuning fail line %d \n",__LINE__);
            exit(1);
        }
    }
    if((A_col_blk == 0)){
        fprintf(stderr,"tuning fail\n");
        exit(1);
    }
    // A_col_blk = 1;
    params->A_col_blk_param = A_col_blk;
    params->B_col_blk_param = B_col_blk;
    params->C_col_blk_param = B_col_blk;
    params->LMM_usage_A_kbyte = ((A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_B_kbyte = ((B_row_size*B_col_blk)*4)/1000;
    params->LMM_usage_kbyte   =  ((B_row_size*B_col_blk+A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_A_rate  = (float)((A_row_size*A_col_blk)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_B_rate  = (float)((B_row_size*B_col_blk)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_rate    = (float)((B_row_size*B_col_blk+A_row_size*A_col_blk)*4)/(float)LMM_SIZE;

}


static void IMAX_param_tunig_impl0_large(emax6_param* params){

    Sll A_row_size = params->A_row_size_param  ;
    Sll A_col_size = params->A_col_size_param  ;
    Sll B_row_size = params->B_row_size_param  ;
    Sll B_col_size = params->B_col_size_param  ;
    Sll A_col_blk  = 0                         ;
    Sll B_col_blk  = 0                         ;
    Sll NCHIP      = params->NCHIP_param       ;
    Uint W         = params->W_param           ;
    Uint H          = params->H_param           ;
    Uint A_H_pad   = 0                       ;
    Uint B_col_pad = 0;
    Uint LMM_MAX_LENGTH_modify = LMM_MAX_LENGTH - LMM_MAX_LENGTH%H;
    Uint LMM_MAX_LENGTH_modify1 = 0;
    Uint LMM_MAX_LENGTH_modify2 = 0;
    B_col_pad = ((B_col_size%(W*2)) != 0) ? -B_col_size%(W*2) + (W*2) : B_col_pad;
    A_H_pad = ((A_col_size%H) != 0) ? -A_col_size%H + H : A_H_pad;
    Uint blk_iter_Arow = ((A_row_size%LMM_MAX_LENGTH_modify) != 0) ? (int)A_row_size/LMM_MAX_LENGTH_modify+1:(int)A_row_size/LMM_MAX_LENGTH_modify;
    Uint blk_iter_Acol = (((A_col_size)%LMM_MAX_LENGTH_modify) != 0) ? (int)(A_col_size)/LMM_MAX_LENGTH_modify+1:(int)(A_col_size)/LMM_MAX_LENGTH_modify;
    Uint blk_iter_Brow = (((B_row_size)%LMM_MAX_LENGTH_modify) != 0) ? (int)(B_row_size)/LMM_MAX_LENGTH_modify+1:(int)(B_row_size)/LMM_MAX_LENGTH_modify;
    Uint blk_iter_Bcol = (((B_col_size+B_col_pad)%LMM_MAX_LENGTH_modify) != 0) ? (int)(B_col_size+B_col_pad)/LMM_MAX_LENGTH_modify+1:(int)(B_col_size+B_col_pad)/LMM_MAX_LENGTH_modify;
    // typedefの影響で A_blk_set* A_blk_setと宣言するとバグる
    A_blk_set* A_blk_sets = calloc(blk_iter_Arow*blk_iter_Acol,sizeof(A_blk_set));
    B_blk_set* B_blk_sets =  calloc(blk_iter_Brow,sizeof(B_blk_set));
    Uint blk_iter_tmp = 0;
    Sll* LMM_MAX_LENGTH_modify_pad = 0;
    Sll A_row_blk_mean = 0;
    Sll A_col_blk_mean = 0;
    Sll B_row_blk_mean = 0;
    Sll B_col_blk_mean = 0;
    Sll tmp = 0;
    Sll tmp1 = 0;
    Sll tmp_pad = 0;
    
    //LMM_MAX_LENGTH_modifyはHで割り切れる最大のブロックサイズを表している
    //LMM_MAX_LENGTH_modify1は分割後のHで割り切れるブロックサイズを表している
    //LMM_MAX_LENGTH_modifyで行列サイズを割った数+1が必要なブロック数で最後のrow一回はHで割れるように再調整している
    tmp = (int)(A_row_size/blk_iter_Arow);
    LMM_MAX_LENGTH_modify1 = (int)((tmp%H) != 0) ? -tmp%H + H + tmp : tmp;  
    LMM_MAX_LENGTH_modify2 = (int)((B_col_size%(W*2)) != 0) ?-B_col_size%(W*2) + (W*2) + B_col_size : B_col_size;
    for(blk_iter_tmp=0;blk_iter_tmp<(blk_iter_Arow)*(blk_iter_Acol);blk_iter_tmp++){
        A_blk_sets[blk_iter_tmp].row_subsize = LMM_MAX_LENGTH_modify1;
        A_blk_sets[blk_iter_tmp].col_subsize = LMM_MAX_LENGTH_modify1;
        if((blk_iter_tmp%(blk_iter_Arow-1)) == 0){
            // rowの一番下
            tmp = A_row_size - (blk_iter_Arow-1)*LMM_MAX_LENGTH_modify1;
            A_blk_sets[blk_iter_tmp].row_subsize = ((int)((tmp%H) != 0) ? -tmp%H + H + tmp : tmp);
            tmp1 = A_col_size - (blk_iter_Acol-1)*LMM_MAX_LENGTH_modify1;
            A_blk_sets[blk_iter_tmp].col_subsize = ((int)((tmp1%H) != 0) ? -tmp1%H + H + tmp1 : tmp1);
        }
    }
    //colはW*2のpadだけ
    for(blk_iter_tmp=0;blk_iter_tmp<(blk_iter_Brow-1);blk_iter_tmp++){
        B_blk_sets[blk_iter_tmp].row_subsize = LMM_MAX_LENGTH_modify1;
        B_blk_sets[blk_iter_tmp].col_subsize = LMM_MAX_LENGTH_modify2;
    }   
    tmp = B_row_size - (blk_iter_Brow-1)*LMM_MAX_LENGTH_modify1;
    B_blk_sets[blk_iter_Brow-1].row_subsize = ((int)((tmp%H) != 0) ? -tmp%H + H + tmp : tmp);
    B_blk_sets[blk_iter_Brow-1].col_subsize = (LMM_MAX_LENGTH_modify2);

    
    // LMM_SIZE 64k LMM>>32 32k
    // *4 はbyte変換

    //A_row_size*A_col_blk(Aをどれだけcolに確保するか)*2(index+valのUllが最小単位なので)*4(byte変換)
    for(blk_iter_tmp=0;blk_iter_tmp<blk_iter_Arow*blk_iter_Acol;blk_iter_tmp++){
        do{
            A_blk_sets[blk_iter_tmp].col_blk_param += 1;
        }while(A_blk_sets[blk_iter_tmp].row_subsize*A_blk_sets[blk_iter_tmp].col_blk_param*4<=(LMM_SIZE>>1)
        &&((A_blk_sets[blk_iter_tmp].row_subsize*A_blk_sets[blk_iter_tmp].col_blk_param*H)<=A_blk_sets[blk_iter_tmp].row_subsize*(A_blk_sets[blk_iter_tmp].col_subsize)));
        A_blk_sets[blk_iter_tmp].col_blk_param -= 1;
        //32kよりBの確保範囲が小さいかつB_col*B_rowをCHIP数で割った数より小さいかつ64kよりCの確保範囲が小さいかつA_row*B_colをCHIP数で割った数より小さい
        if((A_blk_sets[blk_iter_tmp].col_blk_param == 0)){
                fprintf(stderr,"tuning fail line %d \n",__LINE__);
            exit(1);
        }
    }

    // Cの制約条件につかうA_blk_setsは一列目だけ使う
    for(blk_iter_tmp=0;blk_iter_tmp<blk_iter_Brow;blk_iter_tmp++){
        do{
            B_blk_sets[blk_iter_tmp].col_blk_param += W*2;
        }while(
        ((B_blk_sets[blk_iter_tmp].row_subsize)*B_blk_sets[blk_iter_tmp].col_blk_param*4<=(LMM_SIZE>>1))
        &&((B_blk_sets[blk_iter_tmp].row_subsize)*B_blk_sets[blk_iter_tmp].col_blk_param<=((B_blk_sets[blk_iter_tmp].col_subsize)*(B_blk_sets[blk_iter_tmp].row_subsize)/NCHIP))
        &&((A_blk_sets[blk_iter_tmp].row_subsize*B_blk_sets[blk_iter_tmp].col_blk_param*4)<=LMM_SIZE)
        &&((A_blk_sets[blk_iter_tmp].row_subsize*B_blk_sets[blk_iter_tmp].col_blk_param)<=A_blk_sets[blk_iter_tmp].row_subsize*(B_blk_sets[blk_iter_tmp].col_subsize)/NCHIP)
        );
        B_blk_sets[blk_iter_tmp].col_blk_param -= W*2;
        if((B_blk_sets[blk_iter_tmp].col_blk_param == 0)){
            fprintf(stderr,"tuning fail line %d \n",__LINE__);
            exit(1);
        }

        while(((B_blk_sets[blk_iter_tmp].col_subsize)%(B_blk_sets[blk_iter_tmp].col_blk_param*NCHIP)) != 0){
            //B全体が収容できるようにするため
            B_blk_sets[blk_iter_tmp].col_blk_param -= W*2;
            if((B_blk_sets[blk_iter_tmp].col_blk_param == 0)){
                fprintf(stderr,"tuning fail line %d \n",__LINE__);
                exit(1);
            }
        }
    }
    for(blk_iter_tmp=0;blk_iter_tmp<blk_iter_Acol*blk_iter_Arow;blk_iter_tmp++){
        A_col_blk_mean += A_blk_sets[blk_iter_tmp].col_blk_param;
    }
    for(blk_iter_tmp=0;blk_iter_tmp<(blk_iter_Bcol);blk_iter_tmp++){
        B_col_blk_mean += B_blk_sets[blk_iter_tmp].col_blk_param;
    }
    A_col_blk_mean = A_col_blk_mean/(blk_iter_Arow*blk_iter_Acol);
    B_col_blk_mean = B_col_blk_mean/blk_iter_Bcol;
    // A_col_blk = 1;
    params->A_blk_sets = A_blk_sets;
    params->B_blk_sets = B_blk_sets;
    params->A_col_blk_param = NULL;
    params->B_col_blk_param = NULL;
    params->C_col_blk_param = NULL;
    params->LMM_usage_A_kbyte = ((A_row_size*A_col_blk_mean)*4)/1000;
    params->LMM_usage_B_kbyte = ((B_row_size*B_col_blk_mean)*4)/1000;
    params->LMM_usage_kbyte   =  ((B_row_size*B_col_blk_mean+A_row_size*A_col_blk_mean)*4)/1000;
    params->LMM_usage_A_rate  = (float)((A_row_size*A_col_blk_mean)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_B_rate  = (float)((B_row_size*B_col_blk_mean)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_rate    = (float)((B_row_size*B_col_blk_mean+A_row_size*A_col_blk_mean)*4)/(float)LMM_SIZE;

}




static void IMAX_param_tunig_impl2(emax6_param* params){

    Sll A_row_size = params->A_row_size_param;
    Sll A_col_size = params->A_col_size_param;
    Sll B_row_size = params->B_row_size_param;
    Sll B_col_size = params->B_col_size_param;
    Sll A_row_size_pad = params->A_row_size_pad_param;
    Sll A_col_size_pad = params->A_col_size_pad_param;
    Sll B_row_size_pad = params->B_row_size_pad_param;
    Sll B_col_size_pad = params->B_col_size_pad_param;
    Sll A_col_blk  = 0                       ;
    Sll B_col_blk  = 0                       ;
    Sll NCHIP      = params->NCHIP_param     ;
    Uint W         = params->W_param         ;
    Uint H          = params->H_param         ;
    // LMM_SIZE 64k LMM>>32 32k
    // *4 はbyte変換

    //A_row_size*A_col_blk(Aをどれだけcolに確保するか)*2(index+valのUllが最小単位なので)*4(byte変換) 
    //=A_row_size*(A_col_size_pad)*2の2はindexを含んだ全体だから
    do{
        A_col_blk += 1;
    }while(A_row_size*A_col_blk*2*4<=(LMM_SIZE>>1)&&((A_row_size*2*A_col_blk*H)<=A_row_size*(A_col_size_pad)*2));
    A_col_blk -= 1;
    //32kよりBの確保範囲が小さいかつB_col*B_rowをCHIP数で割った数より小さいかつ64kよりCの確保範囲が小さいかつA_row*B_colをCHIP数で割った数より小さい
    do{
        B_col_blk += W*2;
    }while(
    (B_row_size*B_col_blk*4<=(LMM_SIZE>>1))
    &&(B_row_size*B_col_blk<=((B_col_size_pad)*B_row_size/NCHIP))
    &&((A_row_size*B_col_blk*4)<=LMM_SIZE)
    &&((A_row_size*B_col_blk)<=A_row_size*(B_col_size_pad)/NCHIP)
    );
    B_col_blk -= W*2;
    while(((B_col_size_pad)%(B_col_blk*NCHIP)) != 0){
        //B全体が収容できるようにするため
        B_col_blk -= W*2;
        if((B_col_blk == 0)){
            fprintf(stderr,"tuning fail line %d \n",__LINE__);
            exit(1);
        }
    }
    if((B_col_blk == 0)||(A_col_blk == 0)){
        fprintf(stderr,"tuning fail\n");
        exit(1);
    }
    // A_col_blk = 1;
    params->A_col_blk_param = A_col_blk;
    params->B_col_blk_param = B_col_blk;
    params->C_col_blk_param = B_col_blk;
    params->LMM_usage_A_kbyte = (2*(A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_B_kbyte = ((B_row_size*B_col_blk)*4)/1000;
    params->LMM_usage_kbyte   =  ((B_row_size*B_col_blk+2*A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_A_rate  = (float)((2*A_row_size*A_col_blk)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_B_rate  = (float)((B_row_size*B_col_blk)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_rate    = (float)((B_row_size*B_col_blk+2*A_row_size*A_col_blk)*4)/(float)LMM_SIZE;

}


static void IMAX_param_tunig_spmv_impl2(emax6_param* params){

    Sll A_row_size = params->A_row_size_param;
    Sll A_col_size = params->A_col_size_param;
    Sll B_row_size = params->B_row_size_param;
    Sll B_col_size = params->B_col_size_param;
    Sll A_row_size_pad = params->A_row_size_pad_param;
    Sll A_col_size_pad = params->A_col_size_pad_param;
    Sll B_row_size_pad = params->B_row_size_pad_param;
    Sll B_col_size_pad = params->B_col_size_pad_param;
    Sll A_col_blk  = 0                       ;
    Sll B_col_blk  = 1                       ;
    Sll NCHIP      = params->NCHIP_param     ;
    Uint W         = params->W_param         ;
    Uint H          = params->H_param         ;
    // LMM_SIZE 64k LMM>>32 32k
    // *4 はbyte変換

    //A_row_size*A_col_blk(Aをどれだけcolに確保するか)*2(index+valのUllが最小単位なので)*4(byte変換) 
    do{
        A_col_blk += 1;
    }while(A_row_size*A_col_blk*2*4<=(LMM_SIZE>>1)&&((A_row_size*2*A_col_blk*H)<=A_row_size*(A_col_size_pad)*2));
    A_col_blk -= 1;

    params->A_col_blk_param = A_col_blk;
    params->B_col_blk_param = B_col_blk;
    params->C_col_blk_param = B_col_blk;
    params->LMM_usage_A_kbyte = (2*(A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_B_kbyte = ((B_row_size*B_col_blk)*4)/1000;
    params->LMM_usage_kbyte   =  ((B_row_size*B_col_blk+2*A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_A_rate  = (float)((2*A_row_size*A_col_blk)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_B_rate  = (float)((B_row_size*B_col_blk)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_rate    = (float)((B_row_size*B_col_blk+2*A_row_size*A_col_blk)*4)/(float)LMM_SIZE;

}


static void IMAX_param_tunig_impl3(emax6_param* params){

    Sll A_row_size = params->A_row_size_param;
    Sll A_col_size = params->A_col_size_param;
    Sll B_row_size = params->B_row_size_param;
    Sll B_col_size = params->B_col_size_param;
    Sll A_row_size_pad = params->A_row_size_pad_param;
    Sll A_col_size_pad = params->A_col_size_pad_param;
    Sll B_row_size_pad = params->B_row_size_pad_param;
    Sll B_col_size_pad = params->B_col_size_pad_param;
    Sll A_col_blk  = 0                       ;
    Sll B_col_blk  = 0                       ;
    Sll C_col_blk  = 0                       ;
    Sll NCHIP      = params->NCHIP_param     ;
    Uint W         = params->W_param         ;
    Uint H          = params->H_param         ;
    // LMM_SIZE 64k LMM>>32 32k
    // *4 はbyte変換

    //A_row_size*A_col_blk(Aをどれだけcolに確保するか)*2(index+valのUllが最小単位なので)*4(byte変換) 
    do{
        A_col_blk += 1;
    }while(A_row_size*A_col_blk*2*4<=(LMM_SIZE>>1)&&((A_row_size*2*A_col_blk*H)<=A_row_size*(A_col_size_pad)*2));
    A_col_blk -= 1;
    //32kよりBの確保範囲が小さいかつB_col*B_rowをCHIP数で割った数より小さいかつ64kよりCの確保範囲が小さいかつA_row*B_colをCHIP数で割った数より小さい
    do{
        B_col_blk += W*2;
    }while(
    (B_row_size*B_col_blk*4<=(LMM_SIZE>>1))
    &&(B_row_size*B_col_blk<=(B_col_size*B_row_size/NCHIP))
    );
    B_col_blk -= W*2;
    if((B_col_blk*NCHIP == 0)||(A_col_blk == 0)){
        fprintf(stderr,"zero divide tuning fail\n");
        exit(1);
    }
    while(((B_col_size%(B_col_blk*NCHIP)) != 0)&&(B_col_blk>0)&&(B_col_size%B_col_blk == 0)){
        B_col_blk -= W*2;
    }

    if((A_row_size*B_col_blk)*4<=LMM_SIZE){
    //B_col_blk分をCでも確保できたら
        C_col_blk = B_col_blk;
    }
    else{
        while(((B_col_blk%W*2*2) != 0)&&(B_col_blk>0)){
            B_col_blk -= W*2;
        }
        C_col_blk = B_col_blk;
        while(((A_row_size*C_col_blk)*4>LMM_SIZE)&&(C_col_blk>0)){
            C_col_blk = C_col_blk>>1;        
        }
    }


    if((B_col_blk == 0)||(A_col_blk == 0)||(C_col_blk == 0)||(B_col_blk%B_col_blk != 0)||(C_col_blk%C_col_blk != 0)){
        fprintf(stderr,"param_tuning_impl3 fail. Use impl2 instead of impl3\n");
        IMAX_param_tunig_impl2(params);
    }{
    params->A_col_blk_param = A_col_blk;
    params->B_col_blk_param = B_col_blk;
    params->C_col_blk_param = C_col_blk;
    params->LMM_usage_A_kbyte = (2*(A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_B_kbyte = ((B_row_size*B_col_blk)*4)/1000;
    params->LMM_usage_kbyte   =  ((B_row_size*B_col_blk+2*A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_A_rate  = (float)((2*A_row_size*A_col_blk)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_B_rate  = (float)((B_row_size*B_col_blk)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_rate    = (float)((B_row_size*B_col_blk+2*A_row_size*A_col_blk)*4)/(float)LMM_SIZE;
    }

}


void IMAX_param_tunig(emax6_param* params){

    switch(params->mode){
    
    case DENSE_DENSE_SPMV_FORMAT:
        IMAX_param_tunig_spmv_impl0(params);
        break;
    case DENSE_DENSE_MODE:
        if((params->A_row_size_param<=LMM_MAX_LENGTH)&&(params->A_col_size_param<=LMM_MAX_LENGTH)&&(params->B_row_size_param<=LMM_MAX_LENGTH)){
            IMAX_param_tunig_impl0(params);
        }
        else{
            IMAX_param_tunig_impl0_large(params);
        }
        break;
    case SPARSE_DENSE_46_MODE:
        break;
    case SPARSE_DENSE_58_VER2_MODE:
        if((params->A_row_size_param<=LMM_MAX_LENGTH)&&(params->A_col_size_param<=LMM_MAX_LENGTH)&&(params->B_row_size_param<=LMM_MAX_LENGTH)){
            IMAX_param_tunig_impl2(params);
        }
        else{
            //未対応
            fprintf(stderr,"Future work param_tuning.c %d \n",__LINE__);
            exit(1);
            // IMAX_param_tunig_impl2(params);
        }
        break;
    case SPARSE_DENSE_58_SPMV_MODE:
            IMAX_param_tunig_spmv_impl2(params);
        break;

    case SPARSE_DENSE_58_VER3_MODE:
        IMAX_param_tunig_impl3(params);
        break;

    default:
        fprintf(stderr,"IMAX_param_tunig dont have this pattern\n");
        exit(1);
        break; 
    }
}