#include "../Include/emax6_sparselib.h"




static coo_format* make_sparse_mat_1(emax6_param* emax6_param,float sparsity){
  // 値を入れるのはA_row_sizeまでだが,A_row_size_pad分飛ばす
  // sparsity 何パーセント疎か
  int col,row,tmp,tmp1,nnz=0;
  // int A_row_size = emax6_param->A_row_size_param;
  int A_col_size = emax6_param->A_col_size_param;
  int A_row_size = emax6_param->A_row_size_param;
  int A_row_size_pad = emax6_param->A_row_size_pad_param;
  int A_col_size_pad = emax6_param->A_col_size_pad_param;
  int B_row_size_pad = emax6_param->B_row_size_pad_param;
  int B_col_size_pad = emax6_param->B_col_size_pad_param;
  double sum = 0;
  coo_format* coo = (coo_format*)malloc(sizeof(coo_format));
  Uint* col_index = (Uint *)calloc(A_row_size_pad*A_col_size_pad,sizeof(Uint));
  Uint* row_index = (Uint *)calloc(A_row_size_pad*A_col_size_pad,sizeof(Uint));
  Uint* A_tmp = (Uint *)calloc(A_row_size_pad*A_col_size_pad,sizeof(Uint));
  if((sparsity>1)||(sparsity<0)){
      fprintf(stderr,"make_sparse_mat fail \n");
      exit(1);
  }
  // Arow_size != A_row_size_pad A_row_sizeより大きい領域は埋めない 
  for (col=0; col<A_col_size; col++){
    for (row=0; row<A_row_size; row++) {
    tmp = (rand()%(int)100);
    tmp1 = (int)(tmp==0)&&(((1-sparsity)*10.0)>    0.0)
              ||(tmp==1)&&(((1-sparsity)*10.0)>    0.1)  
              ||(tmp==2)&&(((1-sparsity)*10.0)>    0.2) 
              ||(tmp==3)&&(((1-sparsity)*10.0)>    0.3)
              ||(tmp==4)&&(((1-sparsity)*10.0)>    0.4) 
              ||(tmp==5)&&(((1-sparsity)*10.0)>    0.5)   
              ||(tmp==6)&&(((1-sparsity)*10.0)>    0.6)
              ||(tmp==7)&&(((1-sparsity)*10.0)>    0.7)   
              ||(tmp==8)&&(((1-sparsity)*10.0)>    0.8) 
              ||(tmp==9)&&(((1-sparsity)*10.0)>    0.9)   
              ||(tmp==10)&&(((1-sparsity)*10.0)>   1.0)   
              ||(tmp==11)&&(((1-sparsity)*10.0)>   1.1)   
              ||(tmp==12)&&(((1-sparsity)*10.0)>   1.2)   
              ||(tmp==13)&&(((1-sparsity)*10.0)>   1.3)   
              ||(tmp==14)&&(((1-sparsity)*10.0)>   1.4)   
              ||(tmp==15)&&(((1-sparsity)*10.0)>   1.5)   
              ||(tmp==16)&&(((1-sparsity)*10.0)>   1.6)   
              ||(tmp==17)&&(((1-sparsity)*10.0)>   1.7)   
              ||(tmp==18)&&(((1-sparsity)*10.0)>   1.8)   
              ||(tmp==19)&&(((1-sparsity)*10.0)>   1.9)   
              ||(tmp==20)&&(((1-sparsity)*10.0)>   2.0)   
              ||(tmp==21)&&(((1-sparsity)*10.0)>   2.1)   
              ||(tmp==22)&&(((1-sparsity)*10.0)>   2.2)   
              ||(tmp==23)&&(((1-sparsity)*10.0)>   2.3)   
              ||(tmp==24)&&(((1-sparsity)*10.0)>   2.4)   
              ||(tmp==25)&&(((1-sparsity)*10.0)>   2.5)   
              ||(tmp==26)&&(((1-sparsity)*10.0)>   2.6)   
              ||(tmp==27)&&(((1-sparsity)*10.0)>   2.7)   
              ||(tmp==28)&&(((1-sparsity)*10.0)>   2.8)   
              ||(tmp==29)&&(((1-sparsity)*10.0)>   2.9)   
              ||(tmp==30)&&(((1-sparsity)*10.0)>   3.0)   
              ||(tmp==31)&&(((1-sparsity)*10.0)>   3.1) 
              ||(tmp==32)&&(((1-sparsity)*10.0)>   3.2) 
              ||(tmp==33)&&(((1-sparsity)*10.0)>   3.3)   
              ||(tmp==34)&&(((1-sparsity)*10.0)>   3.4)   
              ||(tmp==35)&&(((1-sparsity)*10.0)>   3.5)   
              ||(tmp==36)&&(((1-sparsity)*10.0)>   3.6)   
              ||(tmp==37)&&(((1-sparsity)*10.0)>   3.7)   
              ||(tmp==38)&&(((1-sparsity)*10.0)>   3.8)   
              ||(tmp==39)&&(((1-sparsity)*10.0)>   3.9)   
              ||(tmp==40)&&(((1-sparsity)*10.0)>   4.0)   
              ||(tmp==41)&&(((1-sparsity)*10.0)>   4.1)   
              ||(tmp==42)&&(((1-sparsity)*10.0)>   4.2)   
              ||(tmp==43)&&(((1-sparsity)*10.0)>   4.3)   
              ||(tmp==44)&&(((1-sparsity)*10.0)>   4.4)   
              ||(tmp==45)&&(((1-sparsity)*10.0)>   4.5)   
              ||(tmp==46)&&(((1-sparsity)*10.0)>   4.6)   
              ||(tmp==47)&&(((1-sparsity)*10.0)>   4.7)   
              ||(tmp==48)&&(((1-sparsity)*10.0)>   4.8)   
              ||(tmp==49)&&(((1-sparsity)*10.0)>   4.9)   
              ||(tmp==50)&&(((1-sparsity)*10.0)>   5.0)   
              ||(tmp==51)&&(((1-sparsity)*10.0)>   5.1)   
              ||(tmp==52)&&(((1-sparsity)*10.0)>   5.2)   
              ||(tmp==53)&&(((1-sparsity)*10.0)>   5.3)   
              ||(tmp==54)&&(((1-sparsity)*10.0)>   5.4)   
              ||(tmp==55)&&(((1-sparsity)*10.0)>   5.5)   
              ||(tmp==56)&&(((1-sparsity)*10.0)>   5.6)   
              ||(tmp==57)&&(((1-sparsity)*10.0)>   5.7)   
              ||(tmp==58)&&(((1-sparsity)*10.0)>   5.8)   
              ||(tmp==59)&&(((1-sparsity)*10.0)>   5.9)   
              ||(tmp==60)&&(((1-sparsity)*10.0)>   6.0)   
              ||(tmp==61)&&(((1-sparsity)*10.0)>   6.1)   
              ||(tmp==62)&&(((1-sparsity)*10.0)>   6.2)   
              ||(tmp==63)&&(((1-sparsity)*10.0)>   6.3)   
              ||(tmp==64)&&(((1-sparsity)*10.0)>   6.4)   
              ||(tmp==65)&&(((1-sparsity)*10.0)>   6.5)   
              ||(tmp==66)&&(((1-sparsity)*10.0)>   6.6)   
              ||(tmp==67)&&(((1-sparsity)*10.0)>   6.7)   
              ||(tmp==68)&&(((1-sparsity)*10.0)>   6.8)   
              ||(tmp==69)&&(((1-sparsity)*10.0)>   6.9)   
              ||(tmp==70)&&(((1-sparsity)*10.0)>   7.0)   
              ||(tmp==71)&&(((1-sparsity)*10.0)>   7.1)   
              ||(tmp==72)&&(((1-sparsity)*10.0)>   7.2)   
              ||(tmp==73)&&(((1-sparsity)*10.0)>   7.3)   
              ||(tmp==74)&&(((1-sparsity)*10.0)>   7.4)   
              ||(tmp==75)&&(((1-sparsity)*10.0)>   7.5)   
              ||(tmp==76)&&(((1-sparsity)*10.0)>   7.6)   
              ||(tmp==77)&&(((1-sparsity)*10.0)>   7.7)   
              ||(tmp==78)&&(((1-sparsity)*10.0)>   7.8)   
              ||(tmp==79)&&(((1-sparsity)*10.0)>   7.9)   
              ||(tmp==80)&&(((1-sparsity)*10.0)>   8.0)   
              ||(tmp==81)&&(((1-sparsity)*10.0)>   8.1)   
              ||(tmp==82)&&(((1-sparsity)*10.0)>   8.2)   
              ||(tmp==83)&&(((1-sparsity)*10.0)>   8.3)   
              ||(tmp==84)&&(((1-sparsity)*10.0)>   8.4)   
              ||(tmp==85)&&(((1-sparsity)*10.0)>   8.5)   
              ||(tmp==86)&&(((1-sparsity)*10.0)>   8.6)   
              ||(tmp==87)&&(((1-sparsity)*10.0)>   8.7)   
              ||(tmp==88)&&(((1-sparsity)*10.0)>   8.8)   
              ||(tmp==89)&&(((1-sparsity)*10.0)>   8.9)   
              ||(tmp==90)&&(((1-sparsity)*10.0)>   9.0)   
              ||(tmp==91)&&(((1-sparsity)*10.0)>   9.1)   
              ||(tmp==92)&&(((1-sparsity)*10.0)>   9.2)   
              ||(tmp==93)&&(((1-sparsity)*10.0)>   9.3)   
              ||(tmp==94)&&(((1-sparsity)*10.0)>   9.4)   
              ||(tmp==95)&&(((1-sparsity)*10.0)>   9.5)   
              ||(tmp==96)&&(((1-sparsity)*10.0)>   9.6)   
              ||(tmp==97)&&(((1-sparsity)*10.0)>   9.7)   
              ||(tmp==98)&&(((1-sparsity)*10.0)>   9.8)   
              ||(tmp==99)&&(((1-sparsity)*10.0)>   9.9)   
              ||(tmp==100)&&(((1-sparsity)*10.0)>  10.0)   
              ||(tmp==101)&&(((1-sparsity)*10.0)>  10.1)
              ;   

    sum += tmp1;
    // tmp = (int) rand()%3;
    // tmp = (int) ((tmp == 0)||(tmp == 1));
    // rnad()%x 0~x-1の間の数字をとる
    // if(emax6_param->mode == DENSE_DENSE_MODE){A_row_size = A_row_size_pad;}
    *(float*)&A_tmp[row+col*A_row_size_pad] = (float)(tmp1) ;
    // floatで等価の判断するの危険なので、LIMITで0判定をしている。
    if(!((-LIMIT <= *(float*)&A_tmp[row+col*A_row_size_pad]) && (*(float*)&A_tmp[row+col*A_row_size_pad] <= LIMIT))){
        col_index[nnz] = col;
        row_index[nnz] = row;
        nnz += 1;
      }
    }
  }
  printf("nnz percent %f %% \n",(sum/((double)A_col_size*A_row_size_pad))*100);

  coo->col_index = col_index;
  coo->row_index = row_index;
  coo->nnz = nnz;
  coo->val = A_tmp;

  return coo;
}

static coo_format* make_sparse_mat_2(emax6_param* emax6_param,float sparsity,float biased_percent){
  // sparsity 何パーセント疎か
  int col,row,tmp,tmp1,nnz=0;
  // int A_row_size = emax6_param->A_row_size_param;
  int A_col_size = emax6_param->A_col_size_param;
  int A_row_size_pad = emax6_param->A_row_size_pad_param;
  int A_col_size_pad = emax6_param->A_col_size_pad_param;
  int B_row_size_pad = emax6_param->B_row_size_pad_param;
  int B_col_size_pad = emax6_param->B_col_size_pad_param;
  
  coo_format* coo = (coo_format*)malloc(sizeof(coo_format));
  Uint* col_index = (Uint *)calloc(A_row_size_pad*A_col_size,sizeof(Uint));
  Uint* row_index = (Uint *)calloc(A_row_size_pad*A_col_size,sizeof(Uint));
  Uint* A_tmp = (Uint *)calloc(A_row_size_pad*A_col_size,sizeof(Uint));
  if((sparsity>1)||(sparsity<0)){
      fprintf(stderr,"make_sparse_mat fail \n");
      exit(1);
  }
  for (col=0; col<A_col_size; col++){
    for (row=0; row<A_row_size_pad; row++) {
      tmp = 0;
    if(col<(int)(A_col_size*(sparsity+biased_percent))){
      tmp = 1;
    }
    if((col<(int)(A_col_size*(sparsity+biased_percent)))&&((int)(row<(A_row_size_pad*biased_percent)))){
      tmp = 0;
    }
    // if(emax6_param->mode == DENSE_DENSE_MODE){A_row_size = A_row_size_pad;}
    *(float*)&A_tmp[row+col*A_row_size_pad] = (float)(1) ;
    // floatで等価の判断するの危険なので、LIMITで0判定をしている。
    if(!((-LIMIT <= *(float*)&A_tmp[row+col*A_row_size_pad]) && (*(float*)&A_tmp[row+col*A_row_size_pad] <= LIMIT))){
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


static coo_format* make_sparse_mat_3(emax6_param* emax6_param,FILE* f){
  // sparsity 何パーセント疎か

  int col,row,tmp,tmp1,nnz=0;
  // int A_row_size = emax6_param->A_row_size_param;
  coo_format* coo = (coo_format*)malloc(sizeof(coo_format));
  Uint A_row_size, A_col_size; 
  Uint A_row_size_pad, A_col_size_pad; 
  Uint B_row_size, B_col_size; 
  Uint B_row_size_pad, B_col_size_pad; 
  size_t W; 
  int i;  
  double val;
  size_t nnz_shift1,nnz_tmp;
  MM_typecode* matcode;
  A_row_size     = emax6_param->A_row_size_param    ; 
  A_row_size_pad = emax6_param->A_row_size_pad_param; 
  A_col_size     = emax6_param->A_col_size_param    ; 
  A_col_size_pad = emax6_param->A_col_size_pad_param; 
  B_row_size     = emax6_param->B_row_size_param    ; 
  B_row_size_pad = emax6_param->B_row_size_pad_param; 
  W              = emax6_param->W_param             ; 
  nnz            = emax6_param->nnz                 ; 
  matcode        = emax6_param->matcode             ;

 

  int* col_index  = (int *) calloc(nnz,sizeof(int));
  int* row_index  = (int *) calloc(nnz,sizeof(int));
  float* A_tmp = (float *) calloc(A_col_size_pad*A_row_size_pad,sizeof(float));


  /* NOTE: when reading in doubles, ANSI C requires the use of the "l"  */
  /*   specifier as in "%lg", "%lf", "%le", otherwise errors will occur */
  /*  (ANSI C X3.159-1989, Sec. 4.9.6.2, p. 136 lines 13-15)            */
  if(mm_is_symmetric(*matcode)){
    nnz_shift1 = nnz>>1;
    nnz_tmp = 0;
    for (i=0; i<(nnz_shift1); i++)
    {
        fscanf(f, "%d %d %lf\n", &row_index[i], &col_index[i], &val);
        col_index[i]--;  /* adjust from 1-based to 0-based */
        row_index[i]--;
        if(col_index[i] != row_index[i]){

          col_index[nnz_tmp+nnz_shift1] = row_index[i];
          row_index[nnz_tmp+nnz_shift1] = col_index[i];
          A_tmp[row_index[nnz_tmp+nnz_shift1]+col_index[nnz_tmp+nnz_shift1]*A_row_size_pad] = (float)1;
          nnz_tmp +=1;
        }

        A_tmp[row_index[i]+col_index[i]*A_row_size_pad] = (float)1;
    }
    coo->nnz = (nnz>>1)+nnz_tmp;
  }
  else{
    for (i=0; i<nnz; i++)
    {
      fscanf(f, "%d %d %lf\n", &row_index[i], &col_index[i], &val);
      col_index[i]--;  /* adjust from 1-based to 0-based */
      row_index[i]--;
      A_tmp[row_index[i]+col_index[i]*A_row_size_pad] = (float)1;
    }
    coo->nnz = nnz;
  }


  coo->col_index = col_index;
  coo->row_index = row_index;
  coo->val = A_tmp;

  return coo;
}


coo_format* make_mat(emax6_param* emax6_param,float sparsity,float biased_percent,FILE* fp){
  coo_format* coo = NULL;

  switch (emax6_param->data_type)
  {
  case DENSE_TYPE:
  case DENSE_SPMV_TYPE:
  case SPARSE_TYPE:
  case SPARSE_SPMV_TYPE:
    coo = make_sparse_mat_1(emax6_param,sparsity);
    break;
  case BIASED_SPARSE_TYPE:
    coo = make_sparse_mat_2(emax6_param,sparsity,biased_percent);
    break;
  case REAL_DATA_TYPE:
    coo = make_sparse_mat_3(emax6_param,fp);
    break;
  default:
    fprintf(stderr,"This pattern doesnt exsit in make_sparse_mat\n");
    break;
  }
  if(!coo){
    fprintf(stderr,"make_sparse_mat NULL err make_sparse_mat.c:%d\n",__LINE__);
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