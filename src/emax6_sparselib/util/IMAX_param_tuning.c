#include "../Include/emax6_sparselib.h"




static void IMAX_param_tunig_impl0(emax6_param* params){

    Sll A_row_size = params->A_row_size_param;
    Sll A_col_size = params->A_col_size_param;
    Sll B_row_size = params->B_row_size_param;
    Sll B_col_size = params->B_col_size_param;
    Sll A_col_blk  = 0                       ;
    Sll B_col_blk  = 0                       ;
    Sll NCHIP      = params->NCHIP_param     ;
    Sll W          = params->W_param         ;
    Sll H          = params->H_param         ;
    Uint A_H_pad   = 0                       ;
    Uint B_col_pad = 0;
    B_col_pad = ((B_col_size%8) != 0) ? -B_col_size%8 + 8 : B_col_pad;

    A_H_pad = ((A_col_size%H) != 0) ? -A_col_size%H + H : A_H_pad;
    // LMM_SIZE 64k LMM>>32 32k
    // *4 はbyte変換

    //A_row_size*A_col_blk(Aをどれだけcolに確保するか)*2(index+valのUllが最小単位なので)*4(byte変換) 
    do{
        A_col_blk += 1;
    }while(A_row_size*A_col_blk*4<=(LMM_SIZE>>1)&&((A_row_size*A_col_blk*H)<=A_row_size*(A_col_size+A_H_pad)));
    A_col_blk -= 1;
    //32kよりBの確保範囲が小さいかつB_col*B_rowをCHIP数で割った数より小さいかつ64kよりCの確保範囲が小さいかつA_row*B_colをCHIP数で割った数より小さい
    if((A_col_blk == 0)){
        fprintf(stderr,"tuning fail line %d \n",__LINE__);
        exit(1);
    }

    do{
        B_col_blk += W*2;
    }while(
    ((B_row_size+A_H_pad)*B_col_blk*4<=(LMM_SIZE>>1))
    &&((B_row_size+A_H_pad)*B_col_blk<=((B_col_size+B_col_pad)*(B_row_size+A_H_pad)/NCHIP))
    &&((A_row_size*B_col_blk*4)<=LMM_SIZE)
    &&((A_row_size*B_col_blk)<=A_row_size*(B_col_size+B_col_pad)/NCHIP)
    );
    B_col_blk -= W*2;
    if((B_col_blk == 0)){
        fprintf(stderr,"tuning fail line %d \n",__LINE__);
        exit(1);
    }

    while(((B_col_size+B_col_pad)%(B_col_blk*NCHIP)) != 0){
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

    Sll A_row_size = params->A_row_size_param;
    Sll A_col_size = params->A_col_size_param;
    Sll B_row_size = params->B_row_size_param;
    Sll B_col_size = params->B_col_size_param;
    Sll NCHIP      = params->NCHIP_param     ;
    Sll W          = params->W_param         ;
    Sll H          = params->H_param         ;
    Uint B_col_pad = 0;
    B_col_pad = ((B_col_size%8) != 0) ? -B_col_size%8 + 8 : B_col_pad;
    Uint A_H_pad = ((A_col_size%H) != 0) ? -A_col_size%H + H : A_H_pad;
    Uint blk_iter_Arow = ((A_row_size%LMM_MAX_LENGTH) != 0) ? (int)A_row_size/LMM_MAX_LENGTH+1:(int)A_row_size/LMM_MAX_LENGTH;
    Uint blk_iter_Acol = (((A_col_size)%LMM_MAX_LENGTH) != 0) ? (int)(A_col_size)/LMM_MAX_LENGTH+1:(int)(A_col_size)/LMM_MAX_LENGTH;
    Uint blk_iter_Brow = (((B_row_size)%LMM_MAX_LENGTH) != 0) ? (int)(B_row_size)/LMM_MAX_LENGTH+1:(int)(B_row_size)/LMM_MAX_LENGTH;
    Uint blk_iter_Bcol = (((B_col_size+B_col_pad)%LMM_MAX_LENGTH) != 0) ? (int)(B_col_size+B_col_pad)/LMM_MAX_LENGTH+1:(int)(B_col_size+B_col_pad)/LMM_MAX_LENGTH;
    Uint* Arow_lens = calloc(blk_iter_Arow,sizeof(Uint));
    Uint* Acol_lens = calloc(blk_iter_Acol,sizeof(Uint));
    Uint* Brow_lens = calloc(blk_iter_Brow,sizeof(Uint));
    Uint* Bcol_lens = calloc(blk_iter_Bcol,sizeof(Uint));
    Uint blk_iter_tmp = 0;
    Sll* Arow_blks = calloc(blk_iter_Arow,sizeof(Sll));
    Sll* Acol_blks = calloc(blk_iter_Acol,sizeof(Sll));
    Sll* Brow_blks = calloc(blk_iter_Brow,sizeof(Sll));
    Sll* Bcol_blks = calloc(blk_iter_Bcol,sizeof(Sll));
    Sll A_row_blk_mean = 0;
    Sll A_col_blk_mean = 0;
    Sll B_row_blk_mean = 0;
    Sll B_col_blk_mean = 0;
    
    //最後から一つ手前は1024maxで頑張る
    for(blk_iter_tmp=0;blk_iter_tmp<(blk_iter_Arow-1);blk_iter_tmp++){
        Arow_lens[blk_iter_tmp] = LMM_MAX_LENGTH;
    }
    //最後だけ端数  1024以下だとそのまま値が入る
    Arow_lens[blk_iter_Arow-1] = A_row_size - LMM_MAX_LENGTH*blk_iter_tmp;

    for(blk_iter_tmp=0;blk_iter_tmp<(blk_iter_Acol-1);blk_iter_tmp++){
        //1024を超えない範囲かつHで割り切れる
        Acol_lens[blk_iter_tmp] = LMM_MAX_LENGTH-LMM_MAX_LENGTH%H;
        Brow_lens[blk_iter_tmp] = LMM_MAX_LENGTH-LMM_MAX_LENGTH%H;
    }
    //さいごに残った部分を最後のblkにまとめる blkは小さくなるが仕方がない
    Acol_lens[blk_iter_Acol-1] =  (A_col_size) - (LMM_MAX_LENGTH-LMM_MAX_LENGTH%H)*blk_iter_tmp + A_H_pad;
    Brow_lens[blk_iter_Acol-1] =  (A_col_size) - (LMM_MAX_LENGTH-LMM_MAX_LENGTH%H)*blk_iter_tmp + A_H_pad;

    //使わない？
    for(blk_iter_tmp=0;blk_iter_tmp<(blk_iter_Bcol-1);blk_iter_tmp++){
        Bcol_lens[blk_iter_tmp] = LMM_MAX_LENGTH;
    }   
    Bcol_lens[blk_iter_Bcol-1] = B_col_size - LMM_MAX_LENGTH*blk_iter_tmp;
    
    // LMM_SIZE 64k LMM>>32 32k
    // *4 はbyte変換
    for(blk_iter_tmp=0;blk_iter_tmp<blk_iter_Arow;blk_iter_tmp++){
        //A_row_size*A_col_blk(Aをどれだけcolに確保するか)*2(index+valのUllが最小単位なので)*4(byte変換) 
        do{
            Arow_blks[blk_iter_tmp] += 1;
        }while(
            (Acol_lens[blk_iter_tmp]-Acol_lens[blk_iter_tmp]%H)*Arow_blks[blk_iter_tmp]*4<=(LMM_SIZE>>1)
            &&(((Acol_lens[blk_iter_tmp]-Acol_lens[blk_iter_tmp]%H)*Arow_blks[blk_iter_tmp])<=A_row_size*(Acol_lens[blk_iter_tmp]-Acol_lens[blk_iter_tmp]%H)/NCHIP)
            //ここからはCの制約
            &&((Bcol_lens[blk_iter_tmp]*Arow_blks[blk_iter_tmp]*4)<=LMM_SIZE)
            &&((Bcol_lens[blk_iter_tmp]*Arow_blks[blk_iter_tmp])<=A_row_size*Bcol_lens[blk_iter_tmp])/NCHIP);
        Arow_blks[blk_iter_tmp] -= 1;
        while((Arow_lens[blk_iter_tmp]%(Arow_blks[blk_iter_tmp]*NCHIP)) != 0){
            //A全体が収容できるか
            Arow_blks[blk_iter_tmp] -= 1;
        }
        if((Arow_blks[blk_iter_tmp] == 0)){
            fprintf(stderr,"tuning fail line %d \n",__LINE__);
            exit(1);
        }
    }

    for(blk_iter_tmp=0;blk_iter_tmp<blk_iter_Brow;blk_iter_tmp++){
        //32kよりBの確保範囲が小さいかつB_col*B_rowをCHIP数で割った数より小さいかつ64kよりCの確保範囲が小さいかつA_row*B_colをCHIP数で割った数より小さい
        do{
            Brow_blks[blk_iter_tmp] += 1;
        }while(
        (Bcol_lens[blk_iter_tmp]*Brow_blks[blk_iter_tmp]*4<=(LMM_SIZE>>1))
        &&(Bcol_lens[blk_iter_tmp]*Brow_blks[blk_iter_tmp]*H<=(Bcol_lens[blk_iter_tmp]*(Brow_lens[blk_iter_tmp]-Acol_lens[blk_iter_tmp]%H)))
        );
        Brow_blks[blk_iter_tmp] -= 1;

        if((Brow_blks[blk_iter_tmp] == 0)){
            fprintf(stderr,"tuning fail line %d \n",__LINE__);
            exit(1);
        }
    }

    for(blk_iter_tmp=0;blk_iter_tmp<(blk_iter_Arow-1);blk_iter_tmp++){
        A_row_blk_mean += Arow_blks[blk_iter_tmp];
    }
    for(blk_iter_tmp=0;blk_iter_tmp<(blk_iter_Acol-1);blk_iter_tmp++){
        A_col_blk_mean += Acol_blks[blk_iter_tmp];
    }
    for(blk_iter_tmp=0;blk_iter_tmp<(blk_iter_Bcol-1);blk_iter_tmp++){
        B_col_blk_mean += Bcol_blks[blk_iter_tmp];
    }
    A_row_blk_mean = A_row_blk_mean/blk_iter_Arow;
    B_row_blk_mean = A_col_blk_mean = A_col_blk_mean/blk_iter_Acol;
    B_col_blk_mean = B_col_blk_mean/blk_iter_Bcol;

    exit(1);
    params->A_row_blks_param = Arow_blks;
    params->B_row_blks_param = Brow_blks;
    params->C_col_blks_param = Arow_blks;
    params->LMM_usage_A_kbyte = ((A_col_size*A_row_blk_mean)*4)/1000;
    params->LMM_usage_B_kbyte = ((B_col_size*B_row_blk_mean)*4)/1000;
    params->LMM_usage_kbyte   =  ((B_col_size*B_row_blk_mean+A_col_size*A_row_blk_mean)*4)/1000;
    params->LMM_usage_A_rate  = (float)((A_col_size*A_row_blk_mean)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_B_rate  = (float)((B_col_size*B_row_blk_mean)*4)/(float)(LMM_SIZE/2);
    params->LMM_usage_rate    = (float)((B_col_size*B_row_blk_mean+A_col_size*A_row_blk_mean)*4)/(float)LMM_SIZE;

}


static void IMAX_param_tunig_impl2(emax6_param* params){

    Sll A_row_size = params->A_row_size_param;
    Sll A_col_size = params->A_col_size_param;
    Sll B_row_size = params->B_row_size_param;
    Sll B_col_size = params->B_col_size_param;
    Sll A_col_blk  = 0                       ;
    Sll B_col_blk  = 0                       ;
    Sll NCHIP      = params->NCHIP_param     ;
    Sll W          = params->W_param         ;
    Sll H          = params->H_param         ;
    Uint A_H_pad   = 0                       ;
    A_H_pad = ((A_col_size%H) != 0) ? -A_col_size%H + H : A_H_pad;
    Uint B_col_pad = 0;
    B_col_pad = ((B_col_size%8) != 0) ? -B_col_size%8 + 8 : B_col_pad;
    // LMM_SIZE 64k LMM>>32 32k
    // *4 はbyte変換

    //A_row_size*A_col_blk(Aをどれだけcolに確保するか)*2(index+valのUllが最小単位なので)*4(byte変換) 
    do{
        A_col_blk += 1;
    }while(A_row_size*A_col_blk*2*4<=(LMM_SIZE>>1)&&((A_row_size*2*A_col_blk*H)<=A_row_size*(A_col_size+A_H_pad)*2));
    A_col_blk -= 1;
    //32kよりBの確保範囲が小さいかつB_col*B_rowをCHIP数で割った数より小さいかつ64kよりCの確保範囲が小さいかつA_row*B_colをCHIP数で割った数より小さい
    do{
        B_col_blk += W*2;
    }while(
    (B_row_size*B_col_blk*4<=(LMM_SIZE>>1))
    &&(B_row_size*B_col_blk<=((B_col_size+B_col_pad)*B_row_size/NCHIP))
    &&((A_row_size*B_col_blk*4)<=LMM_SIZE)
    &&((A_row_size*B_col_blk)<=A_row_size*(B_col_size+B_col_pad)/NCHIP)
    );
    B_col_blk -= W*2;
    while(((B_col_size+B_col_pad)%(B_col_blk*NCHIP)) != 0){
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


static void IMAX_param_tunig_impl3(emax6_param* params){

    Sll A_row_size = params->A_row_size_param;
    Sll A_col_size = params->A_col_size_param;
    Sll B_row_size = params->B_row_size_param;
    Sll B_col_size = params->B_col_size_param;
    Sll A_col_blk  = 0                       ;
    Sll B_col_blk  = 0                       ;
    Sll C_col_blk  = 0                       ;
    Sll NCHIP      = params->NCHIP_param     ;
    Sll W          = params->W_param         ;
    Sll H          = params->H_param         ;
    Uint A_H_pad   = 0                       ;
    A_H_pad = ((A_col_size%H) != 0) ? -A_col_size%H + H : A_H_pad;
    // LMM_SIZE 64k LMM>>32 32k
    // *4 はbyte変換

    //A_row_size*A_col_blk(Aをどれだけcolに確保するか)*2(index+valのUllが最小単位なので)*4(byte変換) 
    do{
        A_col_blk += 1;
    }while(A_row_size*A_col_blk*2*4<=(LMM_SIZE>>1)&&((A_row_size*2*A_col_blk*H)<=A_row_size*(A_col_size+A_H_pad)*2));
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
    case 0:
        if((params->A_row_size_param<=LMM_MAX_LENGTH)&&(params->A_col_size_param<=LMM_MAX_LENGTH)
         &&(params->B_row_size_param<=LMM_MAX_LENGTH))
        {IMAX_param_tunig_impl0(params);}
        else{IMAX_param_tunig_impl0_large(params);}
        break;
    case 1:
        break;
    case 2:
        if((params->A_row_size_param<=LMM_MAX_LENGTH)&&(params->A_col_size_param<=LMM_MAX_LENGTH)
        &&(params->B_row_size_param<=LMM_MAX_LENGTH))
        {IMAX_param_tunig_impl2(params);}
        else{IMAX_param_tunig_impl2(params);}
        break;
    case 3:
        IMAX_param_tunig_impl3(params);
        break;

    default:
        fprintf(stderr,"IMAX_param_tunig dont have this pattern\n");
        exit(1);
        break; 
    }
}