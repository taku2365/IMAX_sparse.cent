#include "./Include/emax6_sparselib.h"


void sparse_multiply(const emax6_sparse* const A_sparse, const Uint* const B, Uint* C, int B_col_size){

    if(!A_sparse||!B||!C){
        printf("A,B,C NULL pointer \n");
        exit(0);
    }
    
    int* A_row_p = A_sparse->row_p;
    int* A_nnz_col_index = A_sparse->col_index;
    Uint* A_nnz_val = A_sparse->val;
    int A_row_size = A_sparse->row_normal_size;
    int A_col_size = A_sparse->col_normal_size;
    int B_row_size = A_sparse->col_normal_size;
    int A_nnz =  A_sparse->nnz;
    memset(C, 0, sizeof(Uint)*A_row_size*B_col_size);

    
    //Aはnnzだけ入っている疎行列
    //Bは蜜行列
    //jはBの次列に行くためにある
    //A_nnz_col_indexはAnnzの列を表していて、Bの行を特定するために使う


    for(int i=0; i<A_row_size;i++){
        for(int j=0; j<B_col_size;j++){
            for(int k=A_row_p[i]; k<A_row_p[i+1]; k++){
                if (k==0) *(float*)&C[i*B_col_size+j]  = *(float*)&A_nnz_val[k] * *(float*)&B[A_nnz_col_index[k]*B_col_size+j];
                else *(float*)&C[i*B_col_size+j]  += *(float*)&A_nnz_val[k] * *(float*)&B[A_nnz_col_index[k]*B_col_size+j];
            }
        }
    }


}


void sparse_multiply_imax1(const emax6_sparse* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params){
    if(!A_sparse||!B||!C){
        printf("A,B,C NULL pointer \n");
        exit(0);
    }
    
    int* A_row_p = A_sparse->row_p;
    int* A_nnz_col_index = A_sparse->col_index;
    Uint* A_nnz_val = A_sparse->val;
    int A_row_size = A_sparse->row_normal_size;
    int A_col_size = A_sparse->col_normal_size;
    int B_row_size = A_sparse->col_normal_size;
    int A_nnz =  A_sparse->nnz;
    int* A_paddings = A_sparse->paddings;
    int A_judge=0;
    int B_row_min,B_row_max;
    int A_col_min,A_col_max;
    int NCHIP = params->NCHIP_param; 
    int RMGRP = params->RMGRP_param;
    int W = params->W_param; 
    int H = params->H_param; 
    int blk_size = H;
    memset(C, 0, sizeof(Uint)*A_row_size*B_col_size);

    
    //Aはnnzだけ入っている疎行列
    //Bは蜜行列
    //jはBの次列に行くためにある
    //A_nnz_col_indexはAnnzの列を表していて、Bの行を特定するために使う
    // blkは通常とは異なりB_colベース
    // jとblkはセット
    for(int top=0; top<A_row_size/NCHIP; top+=RMGRP){
        for (int blk=0; blk<B_col_size; blk+=blk_size) { 
            for(int CHIP=0; CHIP<NCHIP; CHIP++){
                for(int rofs=0; rofs<RMGRP;rofs++){
                    // pad_indexはA_rowが軸
                    //A_col_size/H -> A一行あたりのA_paddingsの数　
                    //ex CHIP=0 NCHIP=2 top=0 rofs=0 A_col_size/H 120/60=2   0<pad_index<2
                    //ex CHIP=1 A_row_size=120 NCHIP=2 top=RMGRP=15 rofs=1 A_col_size/H 120/60=2  ->  1*120/2+15+2 =<pad_index< 1*120/2+15+2+2   77=<pad_index<79
                    for(int pad_index=((CHIP*A_row_size/NCHIP+top+rofs)); pad_index<(CHIP*A_row_size/NCHIP+top+rofs+A_col_size/H); pad_index++ ){
                        A_judge = A_paddings[pad_index];
                        if(A_judge == 1){
                            A_col_min = A_row_p[rofs]+pad_index*H;
                            A_col_max = A_row_p[rofs]+(pad_index+1)*H;
                            B_row_min = H*pad_index; 
                            B_row_max = H*(pad_index+1);

                        }
                        else if(A_judge == -1){continue;}
                        else{
                            A_col_min = A_row_p[rofs]+pad_index*H;
                            A_col_max = A_row_p[rofs]+(pad_index+1)*H;
                            B_row_min = H*pad_index; 
                            B_row_max = H*(pad_index+1);
                        }

                        for(int w_col_4=0; w_col_4<blk; w_col_4+=W){
                            for(int w=0; w<W; w++){
                                for(int h=A_col_min; h<A_col_max; h++){
                                    if (h==0 && blk==0) *(float*)&C[(CHIP*A_row_size/NCHIP+rofs+top)*B_col_size+blk+w_col_4+w]  = *(float*)&A_nnz_val[h] * *(float*)&B[A_nnz_col_index[h]*B_col_size+blk+w_col_4+w];
                                    // H-padding回普通に計算した後に、padding回 0で埋める　
                                    else if ((A_judge!=1)&&(h>(H-A_paddings[pad_index]))) *(float*)&C[(CHIP*A_row_size/NCHIP+rofs+top)*B_col_size+blk+w_col_4+w] += 0.0f * *(float*)&B[A_nnz_col_index[h]*B_col_size+blk+w_col_4+w];
                                    else *(float*)&C[(CHIP*A_row_size/NCHIP+rofs+top)*B_col_size+blk+w_col_4+w]  += *(float*)&A_nnz_val[h] * *(float*)&B[A_nnz_col_index[h]*B_col_size+blk+w_col_4+w];
                                } 
                            }
                        }
                    }
                }
            }
        }
    }


}