#include "../Include/emax6_sparselib.h"

void orig_chip_divB(Uint* A_orig,Uint* B_orig,Uint* C_orig,emax6_param* emax6_param) {
  int row,col,n,count0;
  int A_row_size = emax6_param->A_row_size_param;
  int A_col_size = emax6_param->A_col_size_param;
  int B_row_size = emax6_param->B_row_size_param;
  int B_col_size = emax6_param->B_col_size_param;
  for (row=0; row<A_row_size; row++) {
    for (col=0; col<B_col_size; col++) {
      for (n=0; n<A_col_size; n++) {
        if (n==0) *(float*)&C_orig[row+col*A_row_size]  = *(float*)&A_orig[row+n*A_row_size] * *(float*)&B_orig[n+col*B_row_size];
        else      *(float*)&C_orig[row+col*A_row_size] += *(float*)&A_orig[row+n*A_row_size] * *(float*)&B_orig[n+col*B_row_size];
        count0++;
        /*printf("[%d %d %d]", row, col, n);*/
      }
      /*printf("\n");*/
    }
  }
}