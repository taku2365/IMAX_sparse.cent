#include "../Include/emax6_sparselib.h"

static coo_format* make_mat_0(emax6_param* emax6_param,float sparsity){
  // sparsity 何パーセント疎か
  int col,row,tmp,tmp1,nnz=0;
  int A_row_size = emax6_param->A_row_size_param;
  int A_col_size = emax6_param->A_col_size_param;
  coo_format* coo = (coo_format*)malloc(sizeof(coo_format));
  Uint* col_index = (Uint *)calloc(A_row_size*A_col_size,sizeof(Uint));
  Uint* row_index = (Uint *)calloc(A_row_size*A_col_size,sizeof(Uint));
  Uint* A_tmp = (Uint *)calloc(A_row_size*A_col_size,sizeof(Uint));
  if((sparsity>1)||(sparsity<0)){
      fprintf(stderr,"make_sparse_mat fail \n");
      exit(1);
  }
  for (col=0; col<A_col_size; col++){
    for (row=0; row<A_row_size; row++) {
    tmp = (rand()%(int)10);
    tmp1 = (int)(tmp==0)&&((int)((1-sparsity)*10.0)>0)||(tmp==1)&&((int)((1-sparsity)*10.0)>1)||(tmp==2)&&((int)((1-sparsity)*10.0)>2)\
              ||(tmp==3)&&((int)((1-sparsity)*10.0)>3)||(tmp==4)&&((int)((1-sparsity)*10.0)>4)||(tmp==5)&&((int)((1-sparsity)*10.0)>5)||\
                (tmp==6)&&((int)((1-sparsity)*10.0)>6)||(tmp==7)&&((int)((1-sparsity)*10.0)>7)||(tmp==8)&&((int)((1-sparsity)*10.0)>8)||\
                (tmp==9)&&((int)((1-sparsity)*10.0)>9)||((sparsity>-1)&&(sparsity<0.001));
    // tmp = (int) rand()%3;
    // tmp = (int) ((tmp == 0)||(tmp == 1));
    // rnad()%x 0~x-1の間の数字をとる
    *(float*)&A_tmp[row*A_col_size+col] = (float)(tmp1) ;
    // floatで等価の判断するの危険なので、LIMITで0判定をしている。
    if(!((-LIMIT <= *(float*)&A_tmp[row*A_col_size+col]) && (*(float*)&A_tmp[row*A_col_size+col] <= LIMIT))){
        col_index[nnz] = col;
        row_index[nnz] = row;
        nnz += 1;
      }
    }
  }

  coo->col_index = col_index;
  coo->row_index = row_index;
  coo->nnz = nnz;
  coo->val = A_tmp;

  return coo;
}


static coo_format* make_sparse_mat_1(emax6_param* emax6_param,float sparsity){
  // sparsity 何パーセント疎か
  int col,row,tmp,tmp1,nnz=0;
  int A_row_size = emax6_param->A_row_size_param;
  int A_col_size = emax6_param->A_col_size_param;
  coo_format* coo = (coo_format*)malloc(sizeof(coo_format));
  Uint* col_index = (Uint *)calloc(A_row_size*A_col_size,sizeof(Uint));
  Uint* row_index = (Uint *)calloc(A_row_size*A_col_size,sizeof(Uint));
  Uint* A_tmp = (Uint *)calloc(A_row_size*A_col_size,sizeof(Uint));
  if((sparsity>1)||(sparsity<0)){
      fprintf(stderr,"make_sparse_mat fail \n");
      exit(1);
  }
  for (col=0; col<A_col_size; col++){
    for (row=0; row<A_row_size; row++) {
    tmp = (rand()%(int)10);
    tmp1 = (int)(tmp==0)&&((int)((1-sparsity)*10.0)>0)||(tmp==1)&&((int)((1-sparsity)*10.0)>1)||(tmp==2)&&((int)((1-sparsity)*10.0)>2)\
              ||(tmp==3)&&((int)((1-sparsity)*10.0)>3)||(tmp==4)&&((int)((1-sparsity)*10.0)>4)||(tmp==5)&&((int)((1-sparsity)*10.0)>5)||\
                (tmp==6)&&((int)((1-sparsity)*10.0)>6)||(tmp==7)&&((int)((1-sparsity)*10.0)>7)||(tmp==8)&&((int)((1-sparsity)*10.0)>8)||\
                (tmp==9)&&((int)((1-sparsity)*10.0)>9)||((sparsity>-1)&&(sparsity<0.001));
    // tmp = (int) rand()%3;
    // tmp = (int) ((tmp == 0)||(tmp == 1));
    // rnad()%x 0~x-1の間の数字をとる
    *(float*)&A_tmp[row+col*A_row_size] = (float)(tmp1) ;
    // floatで等価の判断するの危険なので、LIMITで0判定をしている。
    if(!((-LIMIT <= *(float*)&A_tmp[row+col*A_row_size]) && (*(float*)&A_tmp[row+col*A_row_size] <= LIMIT))){
        col_index[nnz] = col;
        row_index[nnz] = row;
        nnz += 1;
      }
    }
  }

  coo->col_index = col_index;
  coo->row_index = row_index;
  coo->nnz = nnz;
  coo->val = A_tmp;

  return coo;
}

static coo_format* make_sparse_mat_2(emax6_param* emax6_param,float sparsity,float biased_percent){
  // sparsity 何パーセント疎か
  int col,row,tmp,tmp1,nnz=0;
  int A_row_size = emax6_param->A_row_size_param;
  int A_col_size = emax6_param->A_col_size_param;
  coo_format* coo = (coo_format*)malloc(sizeof(coo_format));
  Uint* col_index = (Uint *)calloc(A_row_size*A_col_size,sizeof(Uint));
  Uint* row_index = (Uint *)calloc(A_row_size*A_col_size,sizeof(Uint));
  Uint* A_tmp = (Uint *)calloc(A_row_size*A_col_size,sizeof(Uint));
  if((sparsity>1)||(sparsity<0)){
      fprintf(stderr,"make_sparse_mat fail \n");
      exit(1);
  }
  for (col=0; col<A_col_size; col++){
    for (row=0; row<A_row_size; row++) {
      tmp = 0;
    if(col<(int)(A_col_size*(sparsity+biased_percent))){
      tmp = 1;
    }
    if((col<(int)(A_col_size*(sparsity+biased_percent)))&&((int)(row<(A_row_size*biased_percent)))){
      tmp = 0;
    }
    *(float*)&A_tmp[row+col*A_row_size] = (float)(tmp) ;
    // floatで等価の判断するの危険なので、LIMITで0判定をしている。
    if(!((-LIMIT <= *(float*)&A_tmp[row+col*A_row_size]) && (*(float*)&A_tmp[row+col*A_row_size] <= LIMIT))){
        col_index[nnz] = col;
        row_index[nnz] = row;
        nnz += 1;
      }
    } 
  }

  coo->col_index = col_index;
  coo->row_index = row_index;
  coo->nnz = nnz;
  coo->val = A_tmp;

  return coo;
}


coo_format* make_mat(emax6_param* emax6_param,float sparsity,float biased_percent){
  coo_format* coo = NULL;

  switch (emax6_param->data_type)
  {
  case 0:
    coo = make_mat_0(emax6_param,sparsity);
    break;
  case 1:
    coo = make_sparse_mat_1(emax6_param,sparsity);
    break;
  case 2:
    coo = make_sparse_mat_2(emax6_param,sparsity,biased_percent);
    break;
  default:
    fprintf(stderr,"This pattern doesnt exsit in make_sparse_mat\n");
    break;
  }
  if(!coo){
    fprintf(stderr,"make_sparse_mat err\n");
    exit(1);
    }
  return coo;
}

void free_sparse_mat(coo_format* coo){
  if(coo->val != NULL){
    free(coo->val);
    coo->val = NULL;
  }
  if(coo->col_index != NULL){
  free(coo->col_index);
  coo->col_index = NULL;
  }
  if(coo->row_index != NULL){
  free(coo->row_index);
  coo->row_index = NULL;
  }
  free(coo);
  coo = NULL;
}