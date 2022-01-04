#include "../Include/emax6_sparselib.h"





int sparse_multiply_imax3(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params){
    if(!A_sparse||!B||!C){
        fprintf(stderr,"A,B,C NULL pointer \n");
        exit(1);
    }
    

    int A_nnz =  A_sparse->nnz;
    int A_col_size = A_sparse->col_normal_size;
    int A_row_size = A_sparse->row_normal_size;
    int* A_col_p = A_sparse->col_p;
    Uint* A_nnz_col_index = A_sparse->col_index;
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









int sparse_multiply_imax4(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params){
  // CHIPA_div ver
    if(!A_sparse||!B||!C){
        fprintf(stderr,"A,B,C NULL pointer \n");
        exit(1);
    }
    

    int A_nnz =  A_sparse->nnz;
    int A_col_size = A_sparse->col_normal_size;
    int A_row_size = A_sparse->row_normal_size;
    int* A_col_p = A_sparse->col_p;
    Uint* A_nnz_col_index = A_sparse->col_index;
    Uint* A_val_index_set = A_sparse->val_index_set;
    Uint* A_sort_index= A_sparse->sort_index;
    int* A_col_num= A_sparse->col_num;
    int* A_paddings = A_sparse->paddings;
    Ull* A_margin = A_sparse->margin;
    Ull* A_margin_sum = A_sparse->margin_sum;
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
    int RMGRP1 = RMGRP;
    // memset(C, 0, sizeof(Uint)*A_row_size*B_col_size);

 int top,blk,h,w,blk_iter;
  
  Ull CHIP;
  Ull rofs,rofs_blk,cofs,top1;
  // AもBも縦方向に格納している
  for(top1=0;top1<A_row_size/NCHIP;top1+=RMGRP1){ // CHIPごとにRMGRPを分ける Cのため
    for (top=0; top<B_col_size; top+=RMGRP) { //RMGRPごとに計算するBの列を動かす
      for (rofs=0; rofs<RMGRP1; rofs+=1) { //Aのrow
  /*3*/ for (CHIP=0; (CHIP<NCHIP); CHIP++) { //marginが0の時は計算省略できる　marginはAの入れ替え時にみる
    /*2*/ for (rofs_blk=0; rofs_blk<A_margin[CHIP]/(A_row_size/NCHIP); rofs_blk++) { // Aのrow blkの飛び
      /*1*/ for (cofs=0; cofs<RMGRP; cofs+=W) { // どれだけBをcolにすすめるか
              for (h=0; h<H; h+=2) { // 一回で2段を表している
                  for (w=0; w<W; w+=2) {    // Bcol +=2
                  count++;
                  // AもBもCも縦方向に格納している。
                  // A  32bit val : 32bit next unit Brow
                  // B simd  2colごとにひとまとめにして1rowにまとめてる  ex [0 480 1 481 2 482 3 483] simdのために次のcolをセットにしている
                  // C simdかどうかを選べるようにする　今は普通に格納　future work  
                  // *(float*)&C[(rofs+top1)*B_col_size(Cのローカルメモリにはいるblk)+(top+cofs+w)(B_colにどれだけすすむか)+CHIP*(A_row_size/NCHIP)*B_col_size(CHIP分割)] 
                  // *(float*)&A_val_index_set[h*A_margin[CHIP](unitごとのA 変形しているのでA_rowではなくA_margin)+rofs_blk*(A_row_size/NCHIP)(row_blkは構造的には縦だが、元の形は横にすすむblk)+(rofs+top1)(Aのrow CのRMGRPの気にしながら)+A_margin_sum[CHIP]*H（CHIP分割）]
                  // *(float*)&B[A_val_index_set[h*A_margin[CHIP]+2*rofs_blk*(A_row_size/NCHIP)(simdの2)+2*(rofs+top1)(simdの2)+A_margin_sum[CHIP]*H+A_row_size*A_col_size]/4+(top+cofs+w)*B_row_size(B_colにW*2ごとにすすむ)]
                    *(float*)&C[(rofs+top1)*B_col_size+(top+cofs+w)+CHIP*(A_row_size/NCHIP)*B_col_size]    += *(float*)&A_val_index_set[h*A_margin[CHIP]+rofs_blk*(A_row_size/NCHIP)+(rofs+top1)+A_margin_sum[CHIP]*H]**(float*)&B[A_val_index_set[h*A_margin[CHIP]+2*rofs_blk*(A_row_size/NCHIP)+2*(rofs+top1)+A_margin_sum[CHIP]*H+A_row_size*A_col_size]/4+(top+cofs+w)*B_row_size];
                    *(float*)&C[(rofs+top1)*B_col_size+1+(top+cofs+w)+CHIP*(A_row_size/NCHIP)*B_col_size]  += *(float*)&A_val_index_set[h*A_margin[CHIP]+rofs_blk*(A_row_size/NCHIP)+(rofs+top1)+A_margin_sum[CHIP]*H]**(float*)&B[A_val_index_set[h*A_margin[CHIP]+2*rofs_blk*(A_row_size/NCHIP)+2*(rofs+top1)+A_margin_sum[CHIP]*H+A_row_size*A_col_size]/4+1+(top+cofs+w)*B_row_size];
                    *(float*)&C[(rofs+top1)*B_col_size+(top+cofs+w)+CHIP*(A_row_size/NCHIP)*B_col_size]    += *(float*)&A_val_index_set[(h+1)*A_margin[CHIP]+rofs_blk*(A_row_size/NCHIP)+(rofs+top1)+A_margin_sum[CHIP]*H]**(float*)&B[A_val_index_set[h*A_margin[CHIP]+2*rofs_blk*(A_row_size/NCHIP)+2*(rofs+top1)+A_margin_sum[CHIP]*H+1+A_row_size*A_col_size]/4+(top+cofs+w)*B_row_size];
                    *(float*)&C[(rofs+top1)*B_col_size+1+(top+cofs+w)+CHIP*(A_row_size/NCHIP)*B_col_size]  += *(float*)&A_val_index_set[(h+1)*A_margin[CHIP]+rofs_blk*(A_row_size/NCHIP)+(rofs+top1)+A_margin_sum[CHIP]*H]**(float*)&B[A_val_index_set[h*A_margin[CHIP]+2*rofs_blk*(A_row_size/NCHIP)+2*(rofs+top1)+A_margin_sum[CHIP]*H+1+A_row_size*A_col_size]/4+1+(top+cofs+w)*B_row_size];

                  /*printf("[%d %d %d %d %d %d %d]", CHIP, top, rofs, blk, col, w, h);*/
                }
              }
              /*printf("\n");*/
            }
          }
        }
      }
    }
  }


return count;


}




int sparse_multiply_imax5(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params){
  // CHIPA_div ver
  // chipごとにmarginを分けずに同じにした。
    if(!A_sparse||!B||!C){
        fprintf(stderr,"A,B,C NULL pointer \n");
        exit(1);
    }
    

    int A_nnz =  A_sparse->nnz;
    int A_col_size = A_sparse->col_normal_size;
    int A_row_size = A_sparse->row_normal_size;
    int* A_col_p = A_sparse->col_p;
    Uint* A_nnz_col_index = A_sparse->col_index;
    Uint* A_val_index_set = A_sparse->val_index_set;
    Uint* A_sort_index= A_sparse->sort_index;
    int* A_col_num= A_sparse->col_num;
    int* A_paddings = A_sparse->paddings;
    Ull* A_margin = A_sparse->margin;
    Ull* A_margin_sum = A_sparse->margin_sum;
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
    int RMGRP1 = RMGRP;
    // memset(C, 0, sizeof(Uint)*A_row_size*B_col_size);

 int top,blk,h,w,blk_iter;
  
  Ull CHIP;
  Ull rofs,rofs_blk,cofs,top1;
  // AもBも縦方向に格納している
  for(top1=0;top1<A_row_size/NCHIP;top1+=RMGRP1){ // CHIPごとにRMGRPを分ける Cのため
    for (top=0; top<B_col_size; top+=RMGRP) { //RMGRPごとに計算するBの列を動かす
      for (cofs=0; cofs<RMGRP; cofs+=W) { // どれだけBをcolにすすめるか
         for (CHIP=0; (CHIP<NCHIP); CHIP++) { //marginが0の時は計算省略できる　marginはAの入れ替え時にみる
          for (rofs=0; rofs<RMGRP1; rofs+=1) { //Aのrow
           for (rofs_blk=0; rofs_blk<A_margin[0]/(A_row_size/NCHIP); rofs_blk++) { // Aのrow blkの飛び
              for (h=0; h<H; h+=2) { // 一回で2段を表している
                  for (w=0; w<W; w+=2) {    // Bcol +=2
                  count++;
                  // AもBもCも縦方向に格納している。
                  // A  32bit val : 32bit next unit Brow
                  // B simd  2colごとにひとまとめにして1rowにまとめてる  ex [0 480 1 481 2 482 3 483] simdのために次のcolをセットにしている
                  // C simdかどうかを選べるようにする　今は普通に格納　future work  
                  // *(float*)&C[(rofs+top1)*B_col_size(Cのローカルメモリにはいるblk)+(top+cofs+w)(B_colにどれだけすすむか)+CHIP*(A_row_size/NCHIP)*B_col_size(CHIP分割)] 
                  // *(float*)&A_val_index_set[h*A_margin[CHIP](unitごとのA 変形しているのでA_rowではなくA_margin)+rofs_blk*(A_row_size/NCHIP)(row_blkは構造的には縦だが、元の形は横にすすむblk)+(rofs+top1)(Aのrow CのRMGRPの気にしながら)+A_margin_sum[CHIP]*H（CHIP分割）]
                  // *(float*)&B[A_val_index_set[h*A_margin[CHIP]+2*rofs_blk*(A_row_size/NCHIP)(simdの2)+2*(rofs+top1)(simdの2)+A_margin_sum[CHIP]*H+A_row_size*A_col_size]/4+(top+cofs+w)*B_row_size(B_colにW*2ごとにすすむ)]
                    *(float*)&C[(rofs+top1)*B_col_size+(top+cofs+w)+CHIP*(A_row_size/NCHIP)*B_col_size]    += *(float*)&A_val_index_set[h*A_margin[0]+rofs_blk*(A_row_size/NCHIP)+(rofs+top1)+A_margin[0]*H*CHIP]**(float*)&B[A_val_index_set[h*A_margin[0]+2*rofs_blk*(A_row_size/NCHIP)+2*(rofs+top1)+A_margin[0]*H*CHIP+A_row_size*A_col_size]/4+(top+cofs+w)*B_row_size];
                    *(float*)&C[(rofs+top1)*B_col_size+1+(top+cofs+w)+CHIP*(A_row_size/NCHIP)*B_col_size]  += *(float*)&A_val_index_set[h*A_margin[0]+rofs_blk*(A_row_size/NCHIP)+(rofs+top1)+A_margin[0]*H*CHIP]**(float*)&B[A_val_index_set[h*A_margin[0]+2*rofs_blk*(A_row_size/NCHIP)+2*(rofs+top1)+A_margin[0]*H*CHIP+A_row_size*A_col_size]/4+1+(top+cofs+w)*B_row_size];
                    *(float*)&C[(rofs+top1)*B_col_size+(top+cofs+w)+CHIP*(A_row_size/NCHIP)*B_col_size]    += *(float*)&A_val_index_set[(h+1)*A_margin[0]+rofs_blk*(A_row_size/NCHIP)+(rofs+top1)+A_margin[0]*H*CHIP]**(float*)&B[A_val_index_set[h*A_margin[0]+2*rofs_blk*(A_row_size/NCHIP)+2*(rofs+top1)+A_margin[0]*H*CHIP+1+A_row_size*A_col_size]/4+(top+cofs+w)*B_row_size];
                    *(float*)&C[(rofs+top1)*B_col_size+1+(top+cofs+w)+CHIP*(A_row_size/NCHIP)*B_col_size]  += *(float*)&A_val_index_set[(h+1)*A_margin[0]+rofs_blk*(A_row_size/NCHIP)+(rofs+top1)+A_margin[0]*H*CHIP]**(float*)&B[A_val_index_set[h*A_margin[0]+2*rofs_blk*(A_row_size/NCHIP)+2*(rofs+top1)+A_margin[0]*H*CHIP+1+A_row_size*A_col_size]/4+1+(top+cofs+w)*B_row_size];

                  /*printf("[%d %d %d %d %d %d %d]", CHIP, top, rofs, blk, col, w, h);*/
                }
              }
              /*printf("\n");*/
            }
          }
        }
      }
    }
  }


return count;


}



int sparse_multiply_imax6(const int nnz,const emax6_sparse2* const A_sparse, const Uint* const B, Uint* C, int B_col_size,emax6_param* params){
    // CHIP div B ver
    // indexとvalをまとめた 
    //RMGRPをそとに追い出す

    if(!A_sparse||!B||!C){
        fprintf(stderr,"A,B,C NULL pointer \n");
        exit(1);
    }


    

    int A_nnz =  A_sparse->nnz;
    int A_col_size = A_sparse->col_normal_size;
    int A_row_size = A_sparse->row_normal_size;
    int* A_col_p = A_sparse->col_p;
    Uint* A_nnz_col_index = A_sparse->col_index;
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
    int A_col_blk = params->A_col_blk_param;
    int W = params->W_param; 
    int H = params->H_param; 
    int A_col_H_div = A_col_size/H; // Aの列をHで何分割するか
    int pad_index;
    int count=0;
    // memset(C, 0, sizeof(Uint)*A_row_size*B_col_size);

 int top,blk,h,w,blk_iter,rofs1,A_margin_tmp;
  
  Ull CHIP;
  Ull rofs,cofs,A_col_blk_tmp,A_col_blk_tmp1;
  // AもBも縦方向に格納している
  for (top=0; top<B_col_size/NCHIP; top+=RMGRP) { //RMGRPごとに計算するBの列を動かす
    for (blk=0,blk_iter=0; blk<A_col_size; blk += H*A_col_blk,blk_iter+=A_col_blk) { //blk_iterをmarginに入れたら次のHに飛ばしてくれる
      for (cofs=0; cofs<RMGRP; cofs+=W) { // どれだけBをcolにすすめるか
/*3*/  for (CHIP=0; (CHIP<NCHIP)&&((A_margin[blk_iter]!=0)); CHIP++) { //marginが0の時は計算省略できる　marginはAの入れ替え時にみる
        A_margin_tmp = A_margin[blk_iter];
        for(A_col_blk_tmp=0;A_col_blk_tmp<A_col_blk;A_col_blk_tmp++){
  /*2*/  for (rofs=0;rofs<A_margin_tmp;rofs+=1) { //Aがどれだけrowを確保するか
            for (h=0; h<A_col_blk*H; h+=A_col_blk) { 
              for (w=0; w<W; w+=2) {    // Bcol +=2
                count++;
                // AもBもCも縦方向に格納している。
                // A  32bit val : 32bit next unit Brow
                // B simd  2colごとにひとまとめにして1rowにまとめてる  ex [0 480 1 481 2 482 3 483] simdのために次のcolをセットにしている
                // C simdかどうかを選べるようにする　今は普通に格納　future work  
                //A_sort_index[rofs]で適切なl位置に並べ替えているが、実際のIMAXでは後処理でする
                //A_sort_indexを59段目でmopで読めるかもしれない。　その場合並べ替え不要
                // *(float*)&C[(A_sort_index[rofs])/4(並べ替え後のCの行)+(CHIP*B_col_size/NCHIP+top+cofs+w)*A_row_size(Cの列)] 
                //*(float*)&A_val_index_set[((h+A_col_blk_tmp)*A_row_size(UnitごとのA要素)+rofs(UnitごとのA row)+blk*A_row_size(連続転送ごと))*2]
                //*(float*)&B[A_val_index_set[((h+A_col_blk_tmp)*A_row_size+rofs+blk*A_row_size)*2+1]/4(どのrowか)+1(index+val構成)+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size(CHIP分割を含むBcol)]
                //A_sort_indexにsimdの×2が含まれている
                // C = Aの行×Bの列
                // Bsimdのためにw+=2
                //A_indexが一度に2箇所読み出す
                //rofs*2はAindexがBのsimdと同じように格納されているから
                //(h+1)があるのは実際のIMAXがUll単位でindex読み出すのに合わせるため つぎのunitの計算を表している
                // IMAXの実際のコードに対応するために*4しているので、こちらでは/4する
                //+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_sizeでsimdのために2をかけないのはw+=2ですでに実現しているから
                  *(float*)&C[(A_sort_index[rofs])/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*A_row_size]    += *(float*)&A_val_index_set[((h+A_col_blk_tmp)*A_row_size+rofs+blk*A_row_size)*2]**(float*)&B[A_val_index_set[((h+A_col_blk_tmp)*A_row_size+rofs+blk*A_row_size)*2+1]/4+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];
                  *(float*)&C[(A_sort_index[rofs])/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*A_row_size]  += *(float*)&A_val_index_set[((h+A_col_blk_tmp)*A_row_size+rofs+blk*A_row_size)*2]**(float*)&B[A_val_index_set[((h+A_col_blk_tmp)*A_row_size+rofs+blk*A_row_size)*2+1]/4+1+(CHIP*B_col_size/NCHIP+top+cofs+w)*B_row_size];

                /*printf("[%d %d %d %d %d %d %d]", CHIP, top, rofs, blk, col, w, h);*/
                }
              }
            /*printf("\n");*/
            }
          }
        }
      }
    }  
  }


return count;


}