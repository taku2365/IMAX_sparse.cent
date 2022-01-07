#include "../Include/emax6_sparselib.h"


void make_simd_random_mat(emax6_param* emax6_param,Uint* B,Uint* B_debug){
  // simdのために変形した行列を返す関数。
  int col,col1,row,row1,tmp,tmp1,nnz=0;
  int B_row_size = emax6_param->B_row_size_param;
  int B_col_size = emax6_param->B_col_size_param;
  float val = 0,sum=0,sum1=0;
  for (row=0; row<B_row_size; row++) {
    val += 1;
    for (col=0; col<B_col_size; col++){
      // *(float*)&B[col*B_col_size+row] = (float) tmp;
      if(col%4 == 0){
      *(float*)&B_debug[col*B_row_size+row] = (float)1;
      }
      else{
      *(float*)&B_debug[col*B_row_size+row] = (float)0;
      }
      // if(!((-LIMIT <= *(float*)&B[col*B_col_size+row]) && (*(float*)&B[col*B_col_size+row] <= LIMIT))) nnz_B += 1; 
      // if(!((-LIMIT <= *(float*)&B_debug[col*B_col_size+row]) && (*(float*)&B_debug[col*B_col_size+row] <= LIMIT))) nnz_B_debug += 1; 
    }
  }


  //To do  奇数も対応する
  for (col=0,col1=0; col<B_col_size/2; col+=1,col1+=2){
    for (row=0,row1=0; row1<B_row_size; row+=2,row1+=1) {
        // simdを使うため
      #ifdef CSIMDEBUG
       printf("B in\n");
      #endif
      *(float*)&B[col*2*B_row_size+row] = *(float*)&B_debug[col1*B_row_size+row1];
      *(float*)&B[col*2*B_row_size+row+1] = *(float*)&B_debug[(col1+1)*B_row_size+row1];
    }
  }
  
  #ifdef CSIMDEBUG
  for (col=0; col<B_col_size; col++){
    for (row=0; row<B_row_size; row++) {
        // simdを使うため
        sum += *(float*)&B_debug[col*B_row_size+row];
        sum1 += *(float*)&B[col*B_row_size+row];
    }
  }
  #endif

  if((int)sum != (int)sum1) {
    fprintf(stderr,"sum != sum\n");
    exit(1);
  }


}