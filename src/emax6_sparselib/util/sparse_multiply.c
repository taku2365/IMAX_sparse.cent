#include "../Include/emax6_sparselib.h"


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


//A sparse B dense

int sparse_multiply_imax(const emax6_sparse* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params){
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
    int blk_size = 80;
    int A_col_H_div = A_col_size/H; // Aの列をHで何分割するか
    int pad_index;
    int count=0;
    memset(C, 0, sizeof(Uint)*A_row_size*B_col_size);

    
    //Aはnnzだけ入っている疎行列
    //Bは蜜行列
    //jはBの次列に行くためにある
    //A_nnz_col_indexはAnnzの列を表していて、Bの行を特定するために使う
    // blkは通常とは異なりB_colベース
    // w_col_4とblkはセット
    for(int top=0; top<A_row_size/NCHIP; top+=RMGRP){
        for (int blk=0; blk<B_col_size; blk+=blk_size) { 
            for(int CHIP=0; CHIP<NCHIP; CHIP++){
                for(int rofs=0; rofs<RMGRP;rofs++){
                    // pad_indexはA_rowが軸
                    //A_col_H_div_iterはAをHずつ進んだ回数
                    //一列あたりA_col_H_div回ある。
                    for(int A_col_H_div_iter=0; A_col_H_div_iter<A_col_H_div; A_col_H_div_iter++ ){

                        pad_index = (CHIP*A_row_size/NCHIP+top+rofs)*A_col_H_div+A_col_H_div_iter;
                        A_judge = A_paddings[pad_index];
                        if(A_judge == -1){
                            A_col_min = A_row_p[rofs]+A_col_H_div_iter*H;
                            A_col_max = A_row_p[rofs]+(A_col_H_div_iter+1)*H;
                        }
                        else if(A_judge == -2){continue;}
                        else{
                            A_col_min = A_row_p[rofs]+A_col_H_div_iter*H;
                            A_col_max = A_row_p[rofs]+(A_col_H_div_iter+1)*H;
                        }

                        for(int w_col_4=0; w_col_4<blk_size; w_col_4+=W){
                            for(int w=0; w<W; w++){
                                for(int h=A_col_min; h<A_col_max; h++){
                                    // H-padding回普通に計算した後に、padding回 0で埋める。A_paddingsにはpadする回数が入っている。　
                                    //h-A_col_min+1 比べているのは回数なので+1している。　さもないとex h=60 A_col_min=60で0になってしまう (実際には1回目)
                                    // ex A_col_min=60 h=63 H=60 A_paddings[pad_index]=58   h-A_col_min+1=3  H-A_paddings[pad_index]=60-58=2 3>2 ----> padding!
                                    count++;
                                    if ((A_judge!=-1)&&((h-A_col_min+1)>(H-A_paddings[pad_index]))) *(float*)&C[(CHIP*A_row_size/NCHIP+rofs+top)*B_col_size+blk+w_col_4+w] += 0.0f * *(float*)&B[A_nnz_col_index[h]*B_col_size+blk+w_col_4+w];
                                    else *(float*)&C[(CHIP*A_row_size/NCHIP+rofs+top)*B_col_size+blk+w_col_4+w]  += *(float*)&A_nnz_val[h] * *(float*)&B[A_nnz_col_index[h]*B_col_size+blk+w_col_4+w];
                                } 
                            }
                        }
                    }
                }
            }
        }
    }

    return count;


}




int sparse_multiply_imax1(const emax6_sparse1* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params){
    if(!A_sparse||!B||!C){
        fprintf(stderr,"A,B,C NULL pointer \n");
        exit(1);
    }
    

    int A_nnz =  A_sparse->nnz;
    int A_col_size = A_sparse->col_normal_size;
    int A_row_size = A_sparse->row_normal_size;
    int* A_col_p = A_sparse->col_p;
    int* A_nnz_col_index = A_sparse->col_index;
    Ull* A_val_index_set = A_sparse->val_index_set;
    Uint* A_sort_index= A_sparse->sort_index;
    int* A_col_num= A_sparse->col_num;
    int* A_paddings = A_sparse->paddings;
    Ull* A_margin = A_sparse->margin;
    int B_row_size = A_sparse->col_normal_size;
    int A_judge=0;
    int B_row_min,B_row_max;
    int A_col_min,A_col_max;
    int NCHIP = params->NCHIP_param; 
    int RMGRP = params->RMGRP_param;
    int W = params->W_param; 
    int H = params->H_param; 
    int blk_size = 80;
    int A_col_H_div = A_col_size/H; // Aの列をHで何分割するか
    int pad_index;
    int count=0;
    memset(C, 0, sizeof(Uint)*A_row_size*B_col_size);

    
  
  Ull CHIP;
  Ull rofs;
  printf("<<<IMAX>>>\n");
  // AもBも縦方向に格納している
  for (int top=0; top<B_col_size/NCHIP; top+=RMGRP) { //RMGRPごとに計算するBの列を動かす
    for (int blk=0,blk_iter=0; blk<A_col_size; blk+=H,blk_iter+=1) { //blk_iterをmarginに入れたら次のHに飛ばしてくれる
/*3*/ for (CHIP=0; (CHIP<NCHIP)&&((A_margin[blk_iter]!=0)); CHIP++) { //marginが0の時は計算省略できる　marginはAの入れ替え時にみる
  /*2*/ for (rofs=0; rofs<A_margin[blk_iter]; rofs++) { //Aがどれだけrowを確保するか
    /*1*/ for (int cofs=0; cofs<RMGRP; cofs+=W) { // どれだけBをcolにすすめるか
            for (int h=0; h<H; h++) { /* vertical (pipelined) execution */
                for (int w=0; w<W; w+=2) {    // Bcol +=2
                count++;
                // AもBもCも縦方向に格納している。
                // A  32bit val : 32bit next unit Brow
                // B simd  2colごとにひとまとめにして1rowにまとめてる  ex [0 480 1 481 2 482 3 483] simdのために次のcolをセットにしている
                // C simdかどうかを選べるようにする　今は普通に格納　future work  
                //A_sort_index[rofs]で適切な位置に並べ替えているが、実際のIMAXでは後処理でする
                //A_sort_indexを59段目でmopで読めるかもしれない。　その場合並べ替え不要
                //*(float*)&C[(A_sort_index[rofs])*B_col_size(並べ替え後のCの行)+CHIP*B_col_size/NCHIP(CHIPごとの列)+top(RMGRPごとのグループ)+cofs(wごとにRMGRPが終わるまでcolに進む)+w(colに進む)]
                //*(float*)&A_val_index_set[h*A_row_size(Aの列 Unitごとに入っている)+rofs(Aの行  AcolHごとにArowをどれだけ進めるか)+(blk+1)(前段Unitからの伝搬を表現するために+1している)*A_row_size(Hごとのcol marginが0の時はおわり)]
                //*(float*)&B[*((Uint*)&A_val_index_set[h*A_row_size+rofs+(blk*A_row_size]+1)(前段のunitから伝搬するBrow(Acol) 前段から伝播するので1+がない)*2(formatのほうに移した幻のsimdの2)/4(実際のIMAXに合わせるために×4してあるが模擬コードではいらないので割っている)+1(simdの1)+(CHIP*B_col_size/NCHIP(CHIP分割)+top(RMGRPごとに縦分割)+cofs(Bcol Wごとに更新)+w(Bcol 横幅))*B_row_size(かたまり全体でBのcol)]
                //A_sort_indexにsimdの×2が含まれている。
                // C = Aの行×Bの列
                // Bsimdのためにw+=2
                // IMAXの実際のコードに対応するために*4しているので、こちらでは/4する
                //+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_sizeでsimdのために2をかけないのはw+=2ですでに実現しているから。
                if (blk == 0 && h == 0){
                  *(float*)&C[(A_sort_index[rofs])/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size]  = *(float*)&A_val_index_set[h*A_row_size+rofs+(blk+1)*A_row_size]**(float*)&B[*((Uint*)&A_val_index_set[h*A_row_size+rofs+blk*A_row_size]+1)/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];
                  *(float*)&C[(A_sort_index[rofs])/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size]  = *(float*)&A_val_index_set[h*A_row_size+rofs+(blk+1)*A_row_size]**(float*)&B[*((Uint*)&A_val_index_set[h*A_row_size+rofs+blk*A_row_size]+1)/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];
                }
                else{
                  *(float*)&C[(A_sort_index[rofs])/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size] += *(float*)&A_val_index_set[h*A_row_size+rofs+(blk+1)*A_row_size]**(float*)&B[*((Uint*)&A_val_index_set[h*A_row_size+rofs+blk*A_row_size]+1)/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];
                  *(float*)&C[(A_sort_index[rofs])/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size]  += *(float*)&A_val_index_set[h*A_row_size+rofs+(blk+1)*A_row_size]**(float*)&B[*((Uint*)&A_val_index_set[h*A_row_size+rofs+blk*A_row_size]+1)/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];
                }
                /*printf("[%d %d %d %d %d %d %d]", CHIP, top, rofs, blk, col, w, h);*/
              }
            }
            /*printf("\n");*/
          }
        }
      }
    }
  }


return count;


}



int sparse_multiply_imax2(const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params){
    if(!A_sparse||!B||!C){
        fprintf(stderr,"A,B,C NULL pointer \n");
        exit(1);
    }
    

    int A_nnz =  A_sparse->nnz;
    int A_col_size = A_sparse->col_normal_size;
    int A_row_size = A_sparse->row_normal_size;
    int* A_col_p = A_sparse->col_p;
    int* A_nnz_col_index = A_sparse->col_index;
    Uint* A_val_index_set = A_sparse->val_index_set;
    Uint* A_sort_index= A_sparse->sort_index;
    int* A_col_num= A_sparse->col_num;
    int* A_paddings = A_sparse->paddings;
    Ull* A_margin = A_sparse->margin;
    int B_row_size = A_sparse->col_normal_size;
    int A_judge=0;
    int B_row_min,B_row_max;
    int A_col_min,A_col_max;
    int NCHIP = params->NCHIP_param; 
    int RMGRP = params->RMGRP_param;
    int W = params->W_param; 
    int H = params->H_param; 
    int blk_size = 80;
    int A_col_H_div = A_col_size/H; // Aの列をHで何分割するか
    int pad_index;
    int count=0;
    memset(C, 0, sizeof(Uint)*A_row_size*B_col_size);

    
  
  Ull CHIP;
  Ull rofs;
  printf("<<<IMAX>>>\n");
  // AもBも縦方向に格納している
  for (int top=0; top<B_col_size/NCHIP; top+=RMGRP) { //RMGRPごとに計算するBの列を動かす
    for (int blk=0,blk_iter=0; blk<A_col_size; blk+=H,blk_iter+=1) { //blk_iterをmarginに入れたら次のHに飛ばしてくれる
/*3*/ for (CHIP=0; (CHIP<NCHIP)&&((A_margin[blk_iter]!=0)); CHIP++) { //marginが0の時は計算省略できる　marginはAの入れ替え時にみる
  /*2*/ for (rofs=0; rofs<A_margin[blk_iter]; rofs++) { //Aがどれだけrowを確保するか
    /*1*/ for (int cofs=0; cofs<RMGRP; cofs+=W) { // どれだけBをcolにすすめるか
            for (int h=0; h<H; h++) { /* vertical (pipelined) execution */
                for (int w=0; w<W; w+=2) {    // Bcol +=2
                count++;
                // AもBもCも縦方向に格納している。
                // A  32bit val : 32bit next unit Brow
                // B simd  2colごとにひとまとめにして1rowにまとめてる  ex [0 480 1 481 2 482 3 483] simdのために次のcolをセットにしている
                // C simdかどうかを選べるようにする　今は普通に格納　future work  
                //A_sort_index[rofs]で適切な位置に並べ替えているが、実際のIMAXでは後処理でする
                //A_sort_indexを59段目でmopで読めるかもしれない。　その場合並べ替え不要
                //*(float*)&C[(A_sort_index[rofs])*B_col_size(並べ替え後のCの行)+CHIP*B_col_size/NCHIP(CHIPごとの列)+top(RMGRPごとのグループ)+cofs(wごとにRMGRPが終わるまでcolに進む)+w(colに進む)]
                //*(float*)&A_val_index_set[h*A_row_size(Aの列 Unitごとに入っている)+rofs(Aの行  AcolHごとにArowをどれだけ進めるか)+(blk+1)(前段Unitからの伝搬を表現するために+1している)*A_row_size(Hごとのcol marginが0の時はおわり)]
                //*(float*)&B[*((Uint*)&A_val_index_set[h*A_row_size+rofs+(blk*A_row_size]+1)(前段のunitから伝搬するBrow(Acol) 前段から伝播するので1+がない)*2(formatのほうに移した幻のsimdの2)/4(実際のIMAXに合わせるために×4してあるが模擬コードではいらないので割っている)+1(simdの1)+(CHIP*B_col_size/NCHIP(CHIP分割)+top(RMGRPごとに縦分割)+cofs(Bcol Wごとに更新)+w(Bcol 横幅))*B_row_size(かたまり全体でBのcol)]
                //A_sort_indexにsimdの×2が含まれている。
                // C = Aの行×Bの列
                // Bsimdのためにw+=2
                // IMAXの実際のコードに対応するために*4しているので、こちらでは/4する
                //+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_sizeでsimdのために2をかけないのはw+=2ですでに実現しているから。
                if (blk == 0 && h == 0){
                  *(float*)&C[(A_sort_index[rofs])/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size]  = *(float*)&A_val_index_set[h*A_row_size+rofs+(blk+1)*A_row_size]**(float*)&B[*((Uint*)&A_val_index_set[h*A_row_size+rofs+blk*A_row_size]+1)/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];
                  *(float*)&C[(A_sort_index[rofs])/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size]  = *(float*)&A_val_index_set[h*A_row_size+rofs+(blk+1)*A_row_size]**(float*)&B[*((Uint*)&A_val_index_set[h*A_row_size+rofs+blk*A_row_size]+1)/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];
                }
                else{
                  *(float*)&C[(A_sort_index[rofs])/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size] += *(float*)&A_val_index_set[h*A_row_size+rofs+(blk+1)*A_row_size]**(float*)&B[*((Uint*)&A_val_index_set[h*A_row_size+rofs+blk*A_row_size]+1)/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];
                  *(float*)&C[(A_sort_index[rofs])/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size]  += *(float*)&A_val_index_set[h*A_row_size+rofs+(blk+1)*A_row_size]**(float*)&B[*((Uint*)&A_val_index_set[h*A_row_size+rofs+blk*A_row_size]+1)/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];
                }
                /*printf("[%d %d %d %d %d %d %d]", CHIP, top, rofs, blk, col, w, h);*/
              }
            }
            /*printf("\n");*/
          }
        }
      }
    }
  }


return count;


}



int sparse_multiply_imax3(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params){
    if(!A_sparse||!B||!C){
        fprintf(stderr,"A,B,C NULL pointer \n");
        exit(1);
    }
    

    int A_nnz =  A_sparse->nnz;
    int A_col_size = A_sparse->col_normal_size;
    int A_row_size = A_sparse->row_normal_size;
    int* A_col_p = A_sparse->col_p;
    int* A_nnz_col_index = A_sparse->col_index;
    Uint* A_val_index_set = A_sparse->val_index_set;
    Uint* A_sort_index= A_sparse->sort_index;
    int* A_col_num= A_sparse->col_num;
    int* A_paddings = A_sparse->paddings;
    Ull* A_margin = A_sparse->margin;
    int B_row_size = A_sparse->col_normal_size;
    int A_judge=0;
    int B_row_min,B_row_max;
    int A_col_min,A_col_max;
    int NCHIP = params->NCHIP_param; 
    int RMGRP = params->RMGRP_param;
    int W = params->W_param; 
    int H = params->H_param; 
    int A_col_H_div = A_col_size/H; // Aの列をHで何分割するか
    int pad_index;
    int count=0;
    // memset(C, 0, sizeof(Uint)*A_row_size*B_col_size);

 int top,blk,h,w,blk_iter;
  
  Ull CHIP;
  Ull rofs,cofs;
  // AもBも縦方向に格納している
  for (top=0; top<B_col_size/NCHIP; top+=RMGRP) { //RMGRPごとに計算するBの列を動かす
    for (blk=0,blk_iter=0; blk<A_col_size; blk+=H,blk_iter+=1) { //blk_iterをmarginに入れたら次のHに飛ばしてくれる
/*3*/ for (CHIP=0; (CHIP<NCHIP)&&((A_margin[blk_iter]!=0)); CHIP++) { //marginが0の時は計算省略できる　marginはAの入れ替え時にみる
  /*2*/ for (rofs=0; rofs<A_margin[blk_iter]; rofs++) { //Aがどれだけrowを確保するか
    /*1*/ for (cofs=0; cofs<RMGRP; cofs+=W) { // どれだけBをcolにすすめるか
            for (h=0; h<H; h+=2) { // 一回で2段を表している
                for (w=0; w<W; w+=2) {    // Bcol +=2
                count++;
                // AもBもCも縦方向に格納している。
                // A  32bit val : 32bit next unit Brow
                // B simd  2colごとにひとまとめにして1rowにまとめてる  ex [0 480 1 481 2 482 3 483] simdのために次のcolをセットにしている
                // C simdかどうかを選べるようにする　今は普通に格納　future work  
                //A_sort_index[rofs]で適切なl位置に並べ替えているが、実際のIMAXでは後処理でする
                //A_sort_indexを59段目でmopで読めるかもしれない。　その場合並べ替え不要
                //*(float*)&C[(A_sort_index[rofs])*B_col_size(並べ替え後のCの行)+CHIP*B_col_size/NCHIP(CHIPごとの列)+top(RMGRPごとのグループ)+cofs(wごとにRMGRPが終わるまでcolに進む)+w(colに進む)]
                //*(float*)&A_val_index_set[h*A_row_size(Aの列 Unitごとに入っている)+rofs(Aの行  AcolHごとにArowをどれだけ進めるか)+(blk)*A_row_size(HごとのAcol marginが0の時はおわり)]
                //*(float*)&B[A_val_index_set[h*A_row_size+2*rofs+blk*A_row_size+A_row_size*A_col_size]/4(実際のIMAXに合わせるために割る4 IMAXがAのアドレスをULLで読むのでsimdみたいに格納している)+1(simdの1)+(CHIP*B_col_size/NCHIP(CHIP分割)+top(RMGRPごとに縦分割)+cofs(Bcol Wごとに更新)+w(Bcol 横幅))*B_row_size(かたまり全体でBのcol)]
                //*(float*)&B[A_val_index_set[h*A_row_size+2*rofs+blk*A_row_size+A_row_size*A_col_size+1(A_indexで隣のcolとセットで読み出すようにA_indexを格納している　+1は実質的に隣のcolを表している)]/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size]
                //A_sort_indexにsimdの×2が含まれている
                // C = Aの行×Bの列
                // Bsimdのためにw+=2
                //A_indexが一度に2箇所読み出す
                //rofs*2はAindexがBのsimdと同じように格納されているから
                //(h+1)があるのは実際のIMAXがUll単位でindex読み出すのに合わせるため つぎのunitの計算を表している
                // IMAXの実際のコードに対応するために*4しているので、こちらでは/4する
                //+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_sizeでsimdのために2をかけないのはw+=2ですでに実現しているから
                  *(float*)&C[(A_sort_index[rofs])/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*A_row_size]    += *(float*)&A_val_index_set[h*A_row_size+rofs+blk*A_row_size]**(float*)&B[A_val_index_set[h*A_row_size+2*rofs+blk*A_row_size+A_row_size*A_col_size]/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];
                  *(float*)&C[(A_sort_index[rofs])/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*A_row_size]  += *(float*)&A_val_index_set[h*A_row_size+rofs+blk*A_row_size]**(float*)&B[A_val_index_set[h*A_row_size+2*rofs+blk*A_row_size+A_row_size*A_col_size]/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];
                  *(float*)&C[(A_sort_index[rofs])/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*A_row_size]    += *(float*)&A_val_index_set[(h+1)*A_row_size+rofs+blk*A_row_size]**(float*)&B[A_val_index_set[h*A_row_size+2*rofs+blk*A_row_size+A_row_size*A_col_size+1]/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];
                  *(float*)&C[(A_sort_index[rofs])/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*A_row_size]  += *(float*)&A_val_index_set[(h+1)*A_row_size+rofs+blk*A_row_size]**(float*)&B[A_val_index_set[h*A_row_size+2*rofs+blk*A_row_size+A_row_size*A_col_size+1]/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];

                /*printf("[%d %d %d %d %d %d %d]", CHIP, top, rofs, blk, col, w, h);*/
              }
            }
            /*printf("\n");*/
          }
        }
      }
    }
  }


return count;


}