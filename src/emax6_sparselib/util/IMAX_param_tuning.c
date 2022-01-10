#include "../Include/emax6_sparselib.h"

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
    if((A_col_size%H) != 0) A_H_pad = -A_col_size%H + H;
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
    &&((A_row_size*B_col_blk*4)<=LMM_SIZE)
    &&((A_row_size*B_col_blk)<=A_row_size*B_row_size/NCHIP)
    );
    B_col_blk -= W*2;
    while((B_col_size%(B_col_blk*NCHIP)) != 0){
        B_col_blk -= W*2;
    }
    params->A_col_blk_param = A_col_blk;
    params->B_col_blk_param = B_col_blk;
    params->LMM_usage_kbyte = ((B_row_size*B_col_blk+2*A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_rate  = (float)((B_row_size*B_col_blk+2*A_row_size*A_col_blk)*4)/(float)LMM_SIZE;

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
    if((A_col_size%H) != 0) A_H_pad = -A_col_size%H + H;
    // LMM_SIZE 64k LMM>>32 32k
    // *4 はbyte変換

    //A_row_size*A_col_blk(Aをどれだけ横に確保するか)*2(index+valが最小単位なので)*4(byte変換) 
    do{
        A_col_blk += 1;
    }while(A_row_size*A_col_blk*2*4<(LMM_SIZE>>1)&&((A_row_size*2*A_col_blk*H)<A_row_size*(A_col_size+A_H_pad)*2));
    A_col_blk -= 1;
    //32kより確保範囲が小さいかつB_col*B_rowをCHIP数で割った数より小さい A_row*B_col -> Cの制限
    do{
        B_col_blk += W*2;
    }while(
    (B_row_size*B_col_blk*4<(LMM_SIZE>>1))
    &&((B_row_size*B_col_blk)<(B_col_size*B_row_size/NCHIP))
    );

    do{
        C_col_blk += W*2;
    }while(
    (A_row_size*C_col_blk*4<LMM_SIZE)
    &&((A_row_size*C_col_blk)<(A_row_size*B_row_size/NCHIP))
    );


    B_col_blk -= W*2;
    C_col_blk -= W*2;
    params->A_col_blk_param = A_col_blk;
    params->B_col_blk_param = B_col_blk;
    params->C_col_blk_param = C_col_blk;
    params->LMM_usage_kbyte = ((B_row_size*B_col_blk+2*A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_rate  = (float)((B_row_size*B_col_blk+2*A_row_size*A_col_blk)*4)/(float)LMM_SIZE;

}


void IMAX_param_tunig(emax6_param* params){

    switch(params->mode){
    case 2:
        IMAX_param_tunig_impl2(params);
        break;
    case 3:
        IMAX_param_tunig_impl2(params);
        break;

    default:
        fprintf(stderr,"IMAX_param_tunig dont have this pattern\n");
        exit(1);
        break; 
    }
}
