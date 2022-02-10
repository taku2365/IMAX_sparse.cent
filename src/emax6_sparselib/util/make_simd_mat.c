#include "../Include/emax6_sparselib.h"


// static void make_random_mat_0(emax6_param* emax6_param,Uint* B,Uint* B_debug){
//   // simdのために変形した行列を返す関数。
//   int col,col1,row,row1,tmp1,nnz=0;
//   int B_row_size = emax6_param->B_row_size_param;
//   int B_col_size = emax6_param->B_col_size_param;
//   int A_row_size_pad = emax6_param->A_row_size_pad_param;
//   int A_col_size_pad = emax6_param->A_col_size_pad_param;
//   int B_row_size_pad = emax6_param->B_row_size_pad_param;
//   int B_col_size_pad = emax6_param->B_col_size_pad_param;
//   int B_col_pad = 0;
//   float val = 0,sum=0,sum1=0;
//   for (row=0; row<B_row_size; row++) {
//     for (col=0; col<(B_col_size_pad); col++){
//       // *(float*)&B[col*(B_col_size_pad)+row] = (float) tmp;
//       if(col%2 == 0){
//       *(float*)&B_debug[row*(B_col_size_pad)+col] = (float)0;
//       }
//       else{
//       *(float*)&B_debug[row*(B_col_size_pad)+col] = (float)1;
//       }
//       // if(!((-LIMIT <= *(float*)&B[col*(B_col_size_pad)+row]) && (*(float*)&B[col*(B_col_size_pad)+row] <= LIMIT))) nnz_B += 1; 
//       // if(!((-LIMIT <= *(float*)&B_debug[col*(B_col_size_pad)+row]) && (*(float*)&B_debug[col*(B_col_size_pad)+row] <= LIMIT))) nnz_B_debug += 1; 
//     }
//   }


//   //To do  奇数も対応する
//   for (col=0,col1=0; col<(B_col_size_pad)/2; col+=1,col1+=2){
//     for (row=0,row1=0; row1<B_row_size; row+=2,row1+=1) {
//         // simdを使うため
//       #ifdef CSIMDEBUG
//        printf("B in\n");
//       #endif
//       *(float*)&B[col*2*B_row_size+row] = *(float*)&B_debug[col1*B_row_size+row1];
//       *(float*)&B[col*2*B_row_size+row+1] = *(float*)&B_debug[(col1+1)*B_row_size+row1];
//     }
//   }
  
//   #ifdef CSIMDEBUG
//   for (col=0; col<(B_col_size_pad); col++){
//     for (row=0; row<B_row_size; row++) {
//         // simdを使うため
//         sum += *(float*)&B_debug[row*(B_col_size_pad)+col];
//         sum1 += *(float*)&B[row*(B_col_size_pad)+col];
//     }
//   }
//   #endif

//   if((int)sum != (int)sum1) {
//     fprintf(stderr,"sum != sum\n");
//     exit(1);
//   }


// }


static void make_spmv_random_mat_pad(emax6_param* emax6_param,Uint* B,Uint* B_debug){
  // simdのために変形した行列を返す関数。
  int col,col1,row,row1,tmp1,nnz=0;
  int B_row_size = emax6_param->B_row_size_param;
  int B_col_size = emax6_param->B_col_size_param;
  int A_row_size_pad = emax6_param->A_row_size_pad_param;
  int A_col_size_pad = emax6_param->A_col_size_pad_param;
  int B_row_size_pad = emax6_param->B_row_size_pad_param;
  int B_col_size_pad = emax6_param->B_col_size_pad_param;
  int H = emax6_param->H_param;
  float val = 0,sum=0,sum1=0;
  int B_H_pad = 0;
  Uint B_col_pad = 0;
  for (row=0; row<(B_row_size_pad); row++) {
    for (col=0; col<(B_col_size_pad); col++){
      // *(float*)&B[col*(B_col_size_pad)+row] = (float) tmp;
      if((row>B_row_size)){
      *(float*)&B_debug[col*(B_row_size_pad)+row] = (float)1;
      *(float*)&B[col*(B_row_size_pad)+row] = (float)1;
      }
      else{
      *(float*)&B_debug[col*(B_row_size_pad)+row] = (float)1;
      *(float*)&B[col*(B_row_size_pad)+row] = (float)1;
      }
      // if(!((-LIMIT <= *(float*)&B[col*(B_col_size_pad)+row]) && (*(float*)&B[col*(B_col_size_pad)+row] <= LIMIT))) nnz_B += 1; 
      // if(!((-LIMIT <= *(float*)&B_debug[col*(B_col_size_pad)+row]) && (*(float*)&B_debug[col*(B_col_size_pad)+row] <= LIMIT))) nnz_B_debug += 1; 
    }
  }


  
  #ifdef CSIMDEBUG
  for (col=0; col<(B_col_size_pad); col++){
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


static void make_simd_random_mat(emax6_param* emax6_param,Uint* B,Uint* B_debug){
  // simdのために変形した行列を返す関数。
  int col,col1,row,row1,tmp1,nnz=0;
  int B_row_size = emax6_param->B_row_size_param;
  int B_col_size = emax6_param->B_col_size_param;
  int A_row_size_pad = emax6_param->A_row_size_pad_param;
  int A_col_size_pad = emax6_param->A_col_size_pad_param;
  int B_row_size_pad = emax6_param->B_row_size_pad_param;
  int B_col_size_pad = emax6_param->B_col_size_pad_param;
  float val = 0,sum=0,sum1=0;
  Uint B_col_pad = 0;
  if((B_debug == NULL)||(B == NULL)){
    fprintf(stderr,"make_simd_random_mat B_debug NULL %d \n",__LINE__);
    
  }
  for (row=0; row<B_row_size; row++) {
    for (col=0; col<(B_col_size_pad); col++){
      // *(float*)&B[col*(B_col_size_pad)+row] = (float) tmp;
      if(col%2 == 0){
      *(float*)&B_debug[col*B_row_size+row] = (float)0;
      }
      else{
      *(float*)&B_debug[col*B_row_size+row] = (float)1;
      }
      // if(!((-LIMIT <= *(float*)&B[col*(B_col_size_pad)+row]) && (*(float*)&B[col*(B_col_size_pad)+row] <= LIMIT))) nnz_B += 1; 
      // if(!((-LIMIT <= *(float*)&B_debug[col*(B_col_size_pad)+row]) && (*(float*)&B_debug[col*(B_col_size_pad)+row] <= LIMIT))) nnz_B_debug += 1; 
    }
  }


  //To do  奇数も対応する
  for (col=0,col1=0; col<(B_col_size_pad)/2; col+=1,col1+=2){
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
  for (col=0; col<(B_col_size_pad); col++){
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


static void make_simd_random_mat_pad(emax6_param* emax6_param,Uint* B,Uint* B_debug){
  // simdのために変形した行列を返す関数。
  int col,col1,row,row1,tmp1,nnz=0;
  int B_row_size = emax6_param->B_row_size_param;
  int B_col_size = emax6_param->B_col_size_param;
  int A_row_size_pad = emax6_param->A_row_size_pad_param;
  int A_col_size_pad = emax6_param->A_col_size_pad_param;
  int B_row_size_pad = emax6_param->B_row_size_pad_param;
  int B_col_size_pad = emax6_param->B_col_size_pad_param;
  int H = emax6_param->H_param;
  float val = 0,sum=0,sum1=0;
  int B_H_pad = 0;
  Uint B_col_pad = 0;
  for (row=0; row<(B_row_size_pad); row++) {
    for (col=0; col<(B_col_size_pad); col++){
      // *(float*)&B[col*(B_col_size_pad)+row] = (float) tmp;
      if((row>B_row_size)){
      *(float*)&B_debug[col*(B_row_size_pad)+row] = (float)0;
      }
      else{
      *(float*)&B_debug[col*(B_row_size_pad)+row] = (float)1;
      }
      // if(!((-LIMIT <= *(float*)&B[col*(B_col_size_pad)+row]) && (*(float*)&B[col*(B_col_size_pad)+row] <= LIMIT))) nnz_B += 1; 
      // if(!((-LIMIT <= *(float*)&B_debug[col*(B_col_size_pad)+row]) && (*(float*)&B_debug[col*(B_col_size_pad)+row] <= LIMIT))) nnz_B_debug += 1; 
    }
  }


  //To do  奇数も対応する
  for (col=0,col1=0; col<(B_col_size_pad)/2; col+=1,col1+=2){
    for (row=0,row1=0; row1<(B_row_size_pad); row+=2,row1+=1) {
        // simdを使うため
      #ifdef CSIMDEBUG
       printf("B in\n");
      #endif
      *(float*)&B[col*2*(B_row_size_pad)+row] = *(float*)&B_debug[col1*(B_row_size_pad)+row1];
      *(float*)&B[col*2*(B_row_size_pad)+row+1] = *(float*)&B_debug[(col1+1)*(B_row_size_pad)+row1];
    }
  }
  
  #ifdef CSIMDEBUG
  for (col=0; col<(B_col_size_pad); col++){
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


void make_random_mat(emax6_param* emax6_param,Uint* B,Uint* B_debug){
  switch (emax6_param->mode)
  {
    case DENSE_SPMV_MODE:
      make_spmv_random_mat_pad(emax6_param,B,B_debug);
    case DENSE_DENSE_MODE:
      make_simd_random_mat_pad(emax6_param,B,B_debug);
      break;
    case SPARSE_DENSE_46_MODE:
    case SPARSE_DENSE_58_VER2_MODE:
    case SPARSE_DENSE_58_VER3_MODE:
    make_simd_random_mat(emax6_param,B,B_debug);
    break;
  default:
    fprintf(stderr,"orig dont has this pattern\n");
    exit(1);
  }
}