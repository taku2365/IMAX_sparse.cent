#include "../Include/emax6_sparselib.h"


void IMAX_param_tunig(emax6_param* params){

    Sll A_row_size = params->A_row_size_param;
    Sll A_col_size = params->A_col_size_param;
    Sll B_row_size = params->B_row_size_param;
    Sll B_col_size = params->B_col_size_param;
    Sll RMGRP      = 0     ;
    Sll A_col_blk  = 0;
    Sll NCHIP      = params->NCHIP_param     ;
    Sll W          = params->W_param         ;
    Sll H          = params->H_param         ;

    // LMM_SIZE 64k LMM>>32 32k
    // *4 はbyte変換
    // 32k

    //A_row_size*A_col_blk(Aをどれだけ横に確保するか)*2(index+valが最小単位なので)*4(byte変換) 
    do{
        A_col_blk += 1;
    }while(A_row_size*A_col_blk*2*4<(LMM_SIZE>>1)&&((A_row_size*2*A_col_blk*H)<A_row_size*A_col_size*2));
    A_col_blk -= 1;
    //32kより確保範囲が小さいかつB_col*B_rowをCHIP数で割った数より小さい
    do{
        RMGRP += W*2;
    }while((B_row_size*RMGRP*4<(LMM_SIZE>>1))&&(B_row_size*RMGRP<(B_col_size*B_row_size/NCHIP)));
    RMGRP -= W*2;
    params->RMGRP_param     = RMGRP     ;
    params->A_col_blk_param = A_col_blk ;
    params->LMM_usage_kbyte  = ((B_row_size*RMGRP+2*A_row_size*A_col_blk)*4)/1000;
    params->LMM_usage_rate  = (float)((B_row_size*RMGRP+2*A_row_size*A_col_blk)*4)/(float)LMM_SIZE;

}