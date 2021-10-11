static char RcsHeader[] = "$Header: /usr/home/nakashim/proj-arm64/sample/mm_cnn_lf/RCS/mm.c,v 1.4 2018/02/04 10:28:53 nakashim Exp nakashim $";

/*                          Copyright (C) 2013- by NAIST */
/*                           Primary writer: Y.Nakashima */
/*                                  nakashim@is.naist.jp */

#ifndef UTYPEDEF
#define UTYPEDEF
typedef unsigned char      Uchar;
typedef unsigned short     Ushort;
typedef unsigned int       Uint;
typedef unsigned long long Ull;
typedef long long int      Sll;
#if __AARCH64EL__ == 1
typedef long double Dll;
#else
typedef struct {Ull u[2];} Dll;
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <math.h>
#include <malloc.h>
#ifndef ARMSIML
#include <unistd.h>
#include <sys/times.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <pthread.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>
#include <X11/extensions/Xdbe.h>
#endif


int WD=320, HT=240, BITMAP=320*240, SCRWD=5, SCRHT=5, VECWD=240, VECHT=240, VECSTEP=4;

#if defined(EMAX6)
#include "../../src/conv-c2c/emax6.h"
#include "../../src/conv-c2c/emax6lib.c"
#endif
#if !defined(ARMSIML)
#include "./xdisp.c"
#endif

Uchar* membase;

sysinit(memsize, alignment) Uint memsize, alignment;
{
#if defined(ARMZYNQ) && defined(EMAX5)
  if (emax5_open() == NULL)
    exit(1);
  membase = emax_info.hpp_mmap;
  {int i; for (i=0; i<(memsize+sizeof(Dll)-1)/sizeof(Dll); i++) *((Dll*)membase+i)=0;}
#elif defined(ARMZYNQ) && defined(EMAX6)
  if (emax6_open() == NULL)
    exit(1);
  membase = emax_info.ddr_mmap;
  {int i; for (i=0; i<(memsize+sizeof(Dll)-1)/sizeof(Dll); i++) *((Dll*)membase+i)=0;}
#else
  membase = (void*)malloc(memsize+alignment);
  printf("malloc size %d \n",malloc_usable_size(membase));
  printf("membase_before_align: %08.8x\n", (Uint)membase);
  if ((Ull)membase & (Ull)(alignment-1))
  membase = (void*)(((Ull)membase & ~(Ull)(alignment-1))+alignment);
  memset(membase, 0, memsize+alignment);
  
  // 32byte = 16byte*2 = 0x20
  printf("membase_after_align: %08.8x\n", (Uint)membase);

  
#endif

#if !defined(ARMZYNQ) && defined(EMAX5)
  emax_info.hpp_phys = membase;
  emax_info.hpp_mmap = emax_info.hpp_phys;
  emax_info.acp_phys = ACP_BASE2_PHYS; /* defined in emax5lib.h >= ALOCLIMIT */
  emax_info.acp_mmap = emax_info.acp_phys;
#endif
#if defined(EMAX5)
  acp_conf = emax_info.acp_mmap; /* 8KB * 256sets */
  acp_lmmi = emax_info.acp_mmap + 0x200000;
  acp_regv = emax_info.acp_mmap + 0x304000;
#endif

#if !defined(ARMZYNQ) && defined(EMAX6)
  emax_info.dma_phys = DMA_BASE2_PHYS; /* defined in emax6lib.h */
  emax_info.dma_mmap = emax_info.dma_phys;
  emax_info.reg_phys = REG_BASE2_PHYS; /* defined in emax6lib.h */
  emax_info.reg_mmap = emax_info.reg_phys;
  emax_info.lmm_phys = LMM_BASE2_PHYS;
  emax_info.lmm_mmap = emax_info.lmm_phys;
  emax_info.ddr_phys = membase;
  emax_info.ddr_mmap = emax_info.ddr_phys;
#endif
#if (defined(ARMSIML) || defined(ARMZYNQ)) && defined(EMAX6)
  emax6.dma_ctrl  = emax_info.dma_mmap;
  emax6.reg_ctrl  = emax_info.reg_mmap;
  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].cmd = CMD_RESET;  // ★★★ RESET
#if defined(ARMZYNQ)
  usleep(1);
#endif
  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].adtr = emax_info.ddr_mmap - emax_info.lmm_phys;
  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].dmrp = 0LL;
#endif
}

/* LMM:16KB, RMM:64KB: M/NCHIP=124 M/NCHIP/RMGRP=31 */
/* A A   B B B B B B   C C C C C C */
/* A A   B B B B B B   C C C C C C */
/* A A                 C C C C C C */
/* A A                 C C C C C C */
/* L=2, M1=4, M2=6     L<M1,M2     */

// #define L  120LL
// #define M1 120LL
// #define M2 120LL
#define L  736LL
#define M1 736LL
#define M2 736LL
#define A_row_size 736LL
#define A_col_size 736LL
#define B_row_size 736LL
#define B_col_size 736LL

// #define RMGRP 60
#define RMGRP 16
#define BLK_SIZE 80
/*#define NCHIP 4*/
#define NCHIP 2
#define W  4LL
#define H  46
#define LIMIT 1.0e-30
typedef struct {
    int nnz; // nonzero
    int col_normal_size; //matrix col size
    int row_normal_size; //matrix row size
    int* col_p; //row pointer //row_p[n] = nnz
    int* col_index; //column index len(column_index)=row_normal_size*col_normal_size
    Uint* val_index_set; // 0~M1*M2:actual nonzero  value M1*M2~2M1*M2:index
    Uint* sort_index; // index after sorting
    int* col_num;  // The number of calculations per H in row
    int* paddings; // pad operation  ex H=60 num=150 -> 150/60=2+1  120/60=2+0
    Ull* margin;   // A row per AcolH   0:omission of calculation else:Depth of A to be obtained 
} emax6_sparse2;

typedef struct {
    int  H_param;
    int  W_param;
    int  RMGRP_param;
    int  NCHIP_param;
} emax6_param;
Uint *A;  /*[M1][L];*/
Uint *B;  /*[L][M2];*/
Uint *C0; /*[M1][M2];*/
Uint *C1; /*[M1][M2];*/
Uint *A_debug; /*[M1][L];*/
Uint *B_debug; /*[L][M2];*/
Uint *C_debug; /*[M1][M2];*/
emax6_sparse2* A_sparse;
emax6_param* params;
emax6_sparse2* sparse_format4(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param);
int blk_iter;
int row,row1, col, col1, n, n1;
int top, blk;
int w, h;
int count0, count1, count2;
int nnz_A,nnz_B,nnz_B_debug;
double sum=0,sum1=0;


#define CSIMWD 320
#define CSIMHT 240
#define CSIMBM (CSIMWD*CSIMHT)
Uint Z[CSIMBM];

#define ERRTH  (5.0E-3)
#define udiff(a,b) (((a)-(b)>=0.0?(a)-(b):(b)-(a))/((a)==0.0?1:(a)))
#define setmax(max, new) { if (max < (new)) max = (new); }

#define MAXINT (~(1<<(sizeof(int)*8-1)))
#define adif(a,b) (((a)>(b))?(a)-(b):(b)-(a))
#define dif(a,b)  (adif((((a)>>24)&255), (((b)>>24)&255))\
                  +adif((((a)>>16)&255), (((b)>>16)&255))\
                  +adif((((a)>> 8)&255), (((b)>> 8)&255)))
#define abs(a) (((a)<0)?-(a):(a))

main()
{ //pointerでないので普通に足される。
  sysinit((Uint)(2*((M1+1)*L)*sizeof(Uint)
                +L*M2*sizeof(Uint)
                +M1*M2*sizeof(Uint)
                +M1*M2*sizeof(Uint)
                +2*((M1+1)*L)*sizeof(Uint)
                +L*M2*sizeof(Uint)
                +M1*M2*sizeof(Uint)
                ),32);
  printf("membase: %08.8x\n", (Uint)membase);
  A  = (Ull*)membase;
  B  = (Uint*)((Uchar*)A  + 2*((M1+1)*L)*sizeof(Uint));
  C0 = (Uint*)((Uchar*)B  + L*M2*sizeof(Uint));
  C1 = (Uint*)((Uchar*)C0 + M1*M2*sizeof(Uint));

  A_debug = (Uint*)((Uchar*)C1 + M1*M2*sizeof(Uint));
  B_debug  = (Uint*)((Uchar*)A_debug  +2*((M1+1)*L)*sizeof(Uint));
  C_debug = (Uint*)((Uchar*)B_debug  + L*M2*sizeof(Uint));
  params = (emax6_param*) malloc(sizeof(emax6_param)*1);
  params->RMGRP_param = RMGRP;
  params->NCHIP_param = NCHIP;
  params->H_param = H;
  params->W_param= W*2;
  
  // params->W_param= W*2;
  printf("A : %08.8x\n", A);
  printf("B : %08.8x\n", B);
  printf("C0: %08.8x\n", C0);
  printf("C1: %08.8x\n", C1);
  int tmp = 0,num = 0;
  int* col_index_A = (int *)calloc(M1*L,sizeof(int));
  int* row_index_A = (int *)calloc(M1*L,sizeof(int));
  Uint* A_tmp = (Uint *)calloc(M1*L,sizeof(Uint));
  for (row=0; row<M1; row++) {
    for (col=0; col<L; col++){
      tmp = (int) tmp;
      tmp = (rand()%5 == 0);
      // tmp = (rand()%3 == 0)||(rand()%2);
      *(float*)&A_tmp[row+col*M2] = (float) tmp;
      *(float*)&A_debug[row*L+col] = (float) tmp;
      // floatで等価の判断するの危険なので、LIMITで0判定をしている。
      if(!((-LIMIT <= *(float*)&A_tmp[row+col*M2]) && (*(float*)&A_tmp[row+col*M2] <= LIMIT))){
          col_index_A[nnz_A] = col;
          row_index_A[nnz_A] = row;
          nnz_A += 1;
        }
    }
  }

  clock_t start,end;
  start = clock();
 
  A_sparse = sparse_format4(nnz_A,A,A_tmp,col_index_A,row_index_A,M1,L,params);
  end = clock();
  printf("format %.2f\n",(double)(end-start)/CLOCKS_PER_SEC);
  

//   for (row=0; row<L; row++) {
//     for (col=0; col<M2; col++){
//        tmp = rand()%2 ;
//       *(float*)&B[row*M2+col] = (float) tmp;
//       if(B[row*L+col]) nnz_B += 1; 
//     }
//   }

  for (row=0; row<L; row++) {
    for (col=0; col<M2; col++){
      float tmp = row+col;
      *(float*)&B[col*M2+row] = (float) tmp;
      *(float*)&B_debug[col*M2+row] = (float) tmp;
      // if(!((-LIMIT <= *(float*)&B[col*M2+row]) && (*(float*)&B[col*M2+row] <= LIMIT))) nnz_B += 1; 
      // if(!((-LIMIT <= *(float*)&B_debug[col*M2+row]) && (*(float*)&B_debug[col*M2+row] <= LIMIT))) nnz_B_debug += 1; 
    }
  }


    for (col=0,col1=0; col<M2/2; col+=1,col1+=2){
      for (row=0,row1=0; row1<L; row+=2,row1+=1) {
        // simdを使うため
      *(float*)&B[col*2*L+row] = *(float*)&B_debug[col1*L+row1];
      *(float*)&B[col*2*L+row+1] = *(float*)&B_debug[(col1+1)*L+row1];
    }
  }
  
    for (col=0; col<M2; col++){
      for (row=0; row<L; row++) {
        // simdを使うため
        sum += *(float*)&B_debug[col*L+row];
        sum1 += *(float*)&B[col*L+row];
    }
  }

  if((int)sum != (int)sum1) {
    fprintf(stderr,"sum != sum\n");
    exit(1);
  }


  // sparse_multiply(A_sparse,B,C1,M2);
  // count1 = sparse_multiply_imax(A_sparse,B,C1,M2,params);

  orig(A_tmp,B_debug,C0);

  printf("orig %.2f\n",(double)(end-start)/CLOCKS_PER_SEC);


 



  for (row=0; row<M1; row++) {
    for (col=0; col<L; col++)
      *(float*)&A_debug[row*L+col] = 0.0;
  }
  for (row=0; row<L; row++) {
    for (col=0; col<M2; col++)
      *(float*)&B_debug[row*M2+col] = 0.0;
  }

  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++)
      *(float*)&C_debug[row*M1+col] = 0.0;
  }



  for (row=0; row<M1; row++) {
    for (col=0; col<L; col++)
      *(Ull*)&A_debug[row*L+col] = 0.0;
  }
  for (row=0; row<L; row++) {
    for (col=0; col<M2; col++)
      *(float*)&B_debug[row*M2+col] = 0.0;
  }

  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++)
      *(float*)&C_debug[row*M1+col] = 0.0;
      *(float*)&C1[row*M1+col] = 0.0;
  }
  memset(C1, 0,sizeof(Uint)*M1*M2 );
  start = clock();
  imax_debug(A_sparse, B, C1);
  end = clock();
  printf("sparse %.2f\n",(double)(end-start)/CLOCKS_PER_SEC);
//   free(col_index_B);
  // free(A_sparse);
  // free(B);
//   free(row_index_B);
  // get_nanosec(0);
  // show_nanosec();

    for (col=0,col1=0; col<M2/2; col+=1,col1+=2){
      for (row=0,row1=0; row1<L; row+=2,row1+=1) {
        if ((C0[col1+row1*L] != C1[col*2*M2+row])||(C0[(col1+1)+row1*L] != C1[col*2*M2+row+1])) {
          count2++;
          printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row1, col1, (double)*(float*)&C0[col1+row1*L],
                                                  row, col*2, (double)*(float*)&C1[col*2*M2+row]);
          printf("C0[%d][%d]=%f C1[%d][%d]=%f\n", row1, col1+1, (double)*(float*)&C0[(col1+1)+row1*L],
                                                  row+1, col*2, (double)*(float*)&C1[col*2*M2+row+1]);  
          exit(1);       
      }
    }
  }
  
free(A_tmp);


}


emax6_sparse2* sparse_format4(int nnz,Ull* val,const Uint* const val_tmp, int* col_index, int* row_index,int row_size,int col_size,emax6_param* emax6_param){

    if(!val || !col_index || !row_index ) {
        fprintf(stderr,"sparse_format NULL error! \n");
        exit(1);
    }

    emax6_sparse2* sparse_info = (emax6_sparse2 *) malloc(1*sizeof(emax6_sparse2));
    // int W = emax6_param->W_param;
    int* count = (int*) calloc(col_size,sizeof(int));
    int* count_tmp = (int*) calloc((col_size+1),sizeof(int));
    int* count_sort_index_inverse = (int*) calloc(row_size,sizeof(int));
    Uint* count_sort_index= (Uint*) calloc(row_size,sizeof(Uint));
    int* row_count = (int*) calloc((row_size+1),sizeof(int));
    int* col_count = (int*) calloc((col_size+1),sizeof(int));
    int* paddings = (int*) calloc((row_size),sizeof(int));
    int count_tmp1;
    Ull* margin = (Ull*) calloc((row_size/H),sizeof(Ull));
    int iter_num = 0,margin_tmp;
    int k,row,row1,col,col1,iter,count_sort_index_inverse_tmp,tmp;
    for(k=0; k<nnz; k++) count[row_index[k]]++; //ex {[0] = 3, [1] = 2, [2] = 2, [3] = 4, [4] = 4, [5] = 1, [6] = 4, [7] = 6, [8] = 4, [9] = 5}

    for(row=0; row<row_size; row++){
        count_tmp[count[row]]++; //  {[0] = 0, [1] = 1, [2] = 2, [3] = 1, [4] = 4, [5] = 1, [6] = 1, [7] = 0, [8] = 0, [9] = 0, [10] = 0} 
    }
    for(row=0; row<row_size; row++) count_tmp[row+1] += count_tmp[row];  //値を適切な場所に入れるため ex {[0] = 0, [1] = 1, [2] = 3, [3] = 4, [4] = 8, [5] = 9, [6] = 10, [7] = 10, [8] = 10, [9] = 10, [10] = 10}  
    for(row=0,tmp; row<row_size; row++){
        count_tmp1 = --count_tmp[count[row]]; // ex count[row]=3  --count_tmp[count[row]]=3  --は0から始めるため
        
        // count_sort_indexと count_sort_index_inverseは逆の関係
        //count_sort_indexは並べ替えた後、該当のrow(index)に入るべき、並べ替え後のrow(index)を表していていて、count_sort_index_inverseは並べ替え後にindex(row)を代入したら並べ替え後の場所を教えてくれる。
        //{[0] = 7, [1] = 9, [2] = 3, [3] = 4, [4] = 6, [5] = 8, [6] = 0, [7] = 1, [8] = 2, [9] = 5}
        // 実際のIMAXではUllでの足し算なのでポインタの足し算にならない　よって×4がいる。
        count_sort_index[(row_size-1)-count_tmp1] =  row*2*4;  //降下sortされた場所に入る //simdの×2 

        //CSCで格納　indexがその列で何番目かを表している。分布数えソートは昇順なので、 (row_size-1) - count_tmp1dで降順にする。  
        // row_size-1は0から始めるために引く1している。            
        // ex row=0 count_sort_index_inverse[row]=6 row_size-1=9 count_tmp1=3　0行目は3番目に小さいの0列目の7-1番目に入る
        //{[0] = 6, [1] = 7, [2] = 8, [3] = 2, [4] = 3, [5] = 9, [6] = 4, [7] = 0, [8] = 5, [9] = 1}
        count_sort_index_inverse[row] = (row_size-1) - count_tmp1;
         //アライメントのために次の手段は使えない 倍数の時のみ可(count[row] + (H-1))~(H-1);
         // sortされた後のrowごとのpaddings
         //降順
         paddings[(row_size-1) - count_tmp1] = count[row]/H + (int)(count[row]%H != 0); 

    }
 

    //paddingsは最低でも1
    //最小のpaddingsではAを一番下まで確保するので、row_size
    for(iter=0;iter<paddings[row_size-1]; iter++){
        margin[iter_num++] = row_size; //row+1
    }
    for(row=row_size-2,tmp=paddings[row_size-1]; row>=0; row--){
        //前回からの変化があれば変化の差分を埋める
        if(tmp != paddings[row]){
            //row+1が入っているので、margin[iter_num-1]-1
            for(iter=paddings[margin[iter_num-1]-1];iter<paddings[row]; iter++){
                //row+1が入る multiplyのfor文で扱いやすくするため。 for (rofs=0; rofs<A_margin[blk_iter]; rofs++) 
                margin[iter_num++] = row+1;
            } 
        }
        tmp = paddings[row];
    }

  
    // Uint* val_debug    = (Uint*) calloc(1+row_size*col_size,sizeof(Uint));
    Uint* val_index_set = (Uint*) val;
    Uint* val_index_set_tmp = (Uint*) calloc(row_size*col_size,sizeof(Uint));
    int* col_index_sparse = (int*) calloc(row_size*col_size,sizeof(int));
    int* row_index_sort_sparse = (int*) calloc((row_size*col_size),sizeof(int));
    

    for(k=0,count_sort_index_inverse_tmp=0; k<nnz; k++){
        //CSCで格納
        // row_countは最初すべて0 row_countがふえると格納する行が右にずれて格納先が次のLMMになる
        //count_sort_index_inverse[row_index[k]]でどの行かを特定
        //row_count[1+row_index[k]]*row_sizeでどの列かを特定
        //CSRのpのようにrow_countを0から使うために1+row_index[k]にしている
        count_sort_index_inverse_tmp = count_sort_index_inverse[row_index[k]];
        //count_sort_index_inverseは並べ替え後にindex(row)を代入したら並べ替え後の場所を教えてくれる。
        //indexを1からスタートする。0は下段にindexを伝播するためだけに使う
        //Aが次のUnitに伝搬するのを表現するためにどの列かを特定+1
        //*((Uint*)&val_index_set[どの行かを特定+(どの列かを特定+1)]) = Aの値  
        //*((Uint*)&val_index_set[前の行+どの列かを特定]+1) = Bの対応箇所(下段Unit)*2(simd)*4(実際のIMAXコードはUllのアドレス演算なので4byteかける)
        val_index_set[count_sort_index_inverse_tmp+row_count[1+row_index[k]]*row_size] = val_tmp[row_index[k]+col_index[k]*row_size];
        val_index_set_tmp[count_sort_index_inverse_tmp+row_count[1+row_index[k]]*row_size] = col_index[k]*2*4;
        // *((Uint*)&val_debug[(1+count_sort_index_inverse_tmp)+row_count[1+row_index[k]]*row_size]) = val[row_index[k]+col_index[k]*row_size];
         //rowを左詰めしているので、colの位置が値ごとに必要
        col_index_sparse[count_sort_index_inverse_tmp+row_count[1+row_index[k]]*row_size] = col_index[k];
        row_index_sort_sparse[k] = count_sort_index_inverse_tmp;
        row_count[1+row_index[k]]++;
        col_count[1+col_index[k]]++;

    }

    for (col=0,col1=0; col<col_size/2; col+=1,col1+=2){
      for (row=0,row1=0; row1<row_size; row+=2,row1+=1) {
        
      *(Uint*)&val_index_set[col*2*row_size+row+row_size*col_size] = *(Uint*)&val_index_set_tmp[col1*row_size+row1];
      *(Uint*)&val_index_set[col*2*row_size+row+1+row_size*col_size] = *(Uint*)&val_index_set_tmp[(col1+1)*row_size+row1];
    }
  }
  printf("hhhh\n");
//   Uint sum=0,sum1=0;

//     for (int col=0; col<col_size; col+=1){
//       for (int row=0; row<row_size; row+=1) {
        
//       sum += *(Uint*)&val_index_set_tmp[col*row_size+row];
//       sum1 += *(Uint*)&val_index_set[col*row_size+row+row_size*col_size];
//     }
//   }
  
//   if(sum != sum1){
//       printf("format error\n");
//       printf("%d %d \n",sum,sum1);
//       exit(1);
//   }


    sparse_info->val_index_set = val_index_set;
    sparse_info->col_p = col_count;
    sparse_info->col_index = col_index_sparse;
    sparse_info->sort_index = count_sort_index;
    sparse_info->nnz = nnz;
    sparse_info->row_normal_size = row_size;
    sparse_info->col_normal_size = col_size;
    sparse_info->paddings = paddings;
    sparse_info->margin = margin;
    
    free(count);
    free(count_tmp);
    free(row_count);
    free(col_index);
    free(row_index);
    free(row_index_sort_sparse);
    free(count_sort_index_inverse);
    free(val_index_set_tmp);

    // free(val_debug);



    return sparse_info;

//Cは書き込みながら転置？
//outputCはCCR形式

}

orig(Uint* A_orig,Uint* B_orig,Uint* C_orig) {
  printf("<<<ORIG>>>\n");
  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++) {
      for (n=0; n<L; n++) {
        if (n==0) *(float*)&C_orig[row*M2+col]  = *(float*)&A_orig[row+n*M1] * *(float*)&B_orig[n+col*L];
        else      *(float*)&C_orig[row*M2+col] += *(float*)&A_orig[row+n*M1] * *(float*)&B_orig[n+col*L];
        count0++;
        /*printf("[%d %d %d]", row, col, n);*/
      }
      /*printf("\n");*/
    }
  }
}


//watch (row*M2+col1)>M1*M2
//watch (row+n*M1) > M1*L
// watch (n1+col*(2*L)) > M2*L
// watch (n1+1+col*(2*L)) > M2*L
orig_simd(Uint* A_orig_simd,Uint* B_orig_simd,Uint* C_orig_simd) {
  printf("<<<ORIG_simd>>>\n");
  for (row=0; row<M1; row++) {
    for (col=0,col1=0; col<M2/2; col++,col1+=2) {
      for (n=0,n1=0; n<L; n+=1,n1+=2) {
        // printf("n %d  n1 %d  col %d col1 %d row %d\n",n,n1,col,col1,row);
          if(!(((row*M2+col1)<M1*M2)&&((row+n*M1) < M1*L)&&((n1+col*(2*L)) <M2*L)&&((n1+1+col*(2*L)) < M2*L))) {
           fprintf(stderr,"simd debug error\n");
           exit(1);
        }
        if (n==0) {
          *(float*)&C_orig_simd[row*M2+col1]  = *(float*)&A_orig_simd[row+n*M1] * *(float*)&B_orig_simd[n1+col*(2*L)];
          *(float*)&C_orig_simd[row*M2+col1+1]  = *(float*)&A_orig_simd[row+n*M1] * *(float*)&B_orig_simd[n1+1+col*(2*L)];
        }
        else{      
          *(float*)&C_orig_simd[row*M2+col1]  += *(float*)&A_orig_simd[row+n*M1] * *(float*)&B_orig_simd[n1+col*(2*L)];
          *(float*)&C_orig_simd[row*M2+col1+1]  += *(float*)&A_orig_simd[row+n*M1] * *(float*)&B_orig_simd[n1+1+col*(2*L)];
        }  
        count0++;

        /*printf("[%d %d %d]", row, col, n);*/
      }
      /*printf("\n");*/
    }
  }
}





void imax_debug(const emax6_sparse2* const A_sparse,const Uint* const B, Uint* C1) {
  Ull  CHIP;
  Ull  LOOP1, LOOP0;
  Ull  INIT1, INIT0;
  Ull  AR[64][4];                     /* output of EX     in each unit */
  Ull  BR[64][4][4];                  /* output registers in each unit */
  Ull  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
  Ull  r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
  Ull  cc0, cc1, cc2, cc3, ex0, ex1;
  Ull  cofs, rofs, oofs, k;
  Uint blk_iter,A_margin_tmp;
  Ull* A_margin = A_sparse->margin;
  Ull* val_index_set = A_sparse->val_index_set;
  Uint* A_sort_index= A_sparse->sort_index;
  Ull x,y,z,t;
//   Ull A_row_size = M1;
//   Ull A_col_size = L;
//   Ull B_row_size = L;
//   Ull B_col_size = M2;


  /*  ┌─────┐convolutionの場合                                                  */
  /*  │┌────┴┐Bが複数と考える                                                  */
  /*  ││┌────┴┐┌─────┐┐        ┌─────┐┐                       */
  /*  │││b         ││a a a a a ││RMGRP   │o o o o o ││RMGRP                  */
  /*  │││b         ┤│          │┤/CHIP   │          │┤/CHIP                  */
  /*  │││b   B0   b││ A(weight)││        │   out    ││ mmの場合は行で分割    */
  /*  └││b        l┤│          │┤        │          │┤ cnnの場合はoutで分割  */
  /*    └│b        k││blk       ││        │blk       ││                       */
  /*      └─────┘└─┴─┴─┘┘        └─┴─┴─┘┘                       */
  printf("<<<IMAX>>>\n");
  for (top=0; top<B_col_size/NCHIP; top+=RMGRP) {
    for (blk=0,blk_iter=0; blk<A_col_size; blk+=H,blk_iter+=1) { /* 3重ループ展開の外側対象 */
      if((A_margin_tmp=A_margin[blk_iter])==0) break;
      typedef struct {Uint i[8]} Ui8;
      Uint *a[H],*a_index[H],*a_debug[H+1];
      Ui8  *b[NCHIP], *b0[NCHIP], *b1[NCHIP], *b2[NCHIP], *b3[NCHIP];
      Ui8  *b_debug[NCHIP], *b0_debug[NCHIP], *b1_debug[NCHIP], *b2_debug[NCHIP], *b3_debug[NCHIP];
      Ui8  *c0[NCHIP],*c0_debug[NCHIP];
      Ui8  *c00[NCHIP], *c01[NCHIP], *c02[NCHIP], *c03[NCHIP];
      Ui8  *c00_debug[NCHIP], *c01_debug[NCHIP], *c02_debug[NCHIP], *c03_debug[NCHIP];
      for (CHIP=0; CHIP<NCHIP; CHIP++) { 
      
        b[CHIP] = B+(CHIP*B_col_size/NCHIP+top)*B_row_size;
        b_debug[CHIP] = B_debug+(CHIP*B_col_size/NCHIP+top)*B_row_size;
        b0[CHIP] = b[CHIP]+0; b1[CHIP] = (Uint*)b[CHIP]+B_row_size*2; b2[CHIP] = (Uint*)b[CHIP]+B_row_size*4;  b3[CHIP] = (Uint*)b[CHIP]+B_row_size*6; 
        b0_debug[CHIP] = b_debug[CHIP]+0; b1_debug[CHIP] = (Uint*)b_debug[CHIP]+B_row_size*2; b2_debug[CHIP] = (Uint*)b_debug[CHIP]+B_row_size*4;  b3_debug[CHIP] = (Uint*)b_debug[CHIP]+B_row_size*6; 


        c0[CHIP] = C1+(CHIP*A_col_size/NCHIP+top)*B_row_size;
        c0_debug[CHIP] = C1+(CHIP*A_col_size/NCHIP+top)*B_row_size;
        c00[CHIP]= (Uint*)c0[CHIP]+0; c01[CHIP] = (Uint*)c0[CHIP]+A_row_size*2; c02[CHIP] = (Uint*)c0[CHIP]+A_row_size*4; c03[CHIP] = (Uint*)c0[CHIP]+A_row_size*6;
        c00_debug[CHIP] = (Uint*)c0_debug[CHIP]+0; c01_debug[CHIP] = (Uint*)c0_debug[CHIP]+A_row_size*2; c02_debug[CHIP] = (Uint*)c0_debug[CHIP]+A_row_size*4; c03_debug[CHIP] = (Uint*)c0_debug[CHIP]+A_row_size*6;
    
      }
      // little edianで格納 big <- <- <- <- small 右から左に流れていく
      //ex 64bit *((Ull*)&offset2)  11000000000000000000000000000000000   
      //   32bit *((Uint*)&offset2) -> 0    *((Uint*)&offset2+1) -> 1
      //   8bit  *((char*)&offset2+1) -> 0   *((char*)&offset2+2) -> 0 *((char*)&offset2+3) -> 0 *((char*)&offset2+4) -> 110
      // Ullで扱うときは *((Ull*)&offset2)>>32は*((Uint*)&offset2+1)を取得しているのと等価
      // https://hackaday.com/2020/08/04/dont-let-endianness-flip-you-around/
      //https://www.bogotobogo.com/Embedded/Little_endian_big_endian_htons_htonl.php
      //p *(float*)((Uint*)b[0]+6) 一つ目の値 3
      //>>> p/f  *((Uint*)&BR[2][0][1])
    // $17 = 3
    // >>> p/f  *((Uint*)&BR[2][0][1]+1)
    // $18 = 4
    //UllのA_row_size*2
    // rofs=(0-(Ull)1*8)<<32|((0-(Ull)1*4)&0xffffffff) マスクを使って2パターン使用している
      for (k=0; k<H; k++) a[k] = (Uint*)val_index_set+(blk+k)*A_row_size;
      //A_indeはUllなので*2している。
      for (k=0; k<H/2; k++) a_index[k] = (Uint*)val_index_set+blk*A_row_size+k*A_row_size*2+A_col_size*A_row_size;




#define sparse_core1(ar,ar_pre,br,br_pre,a_val,A_index1,A_index2,index_MSK) \
      exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mop(OP_LDR,  3, &BR[br][0][1],  (Ull)b0[CHIP],(Ull)AR[A_index1][A_index2], index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][0][0],  (Ull)b1[CHIP],(Ull)AR[A_index1][A_index2], index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][1],  (Ull)b2[CHIP],(Ull)AR[A_index1][A_index2], index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][0],  (Ull)b3[CHIP],(Ull)AR[A_index1][A_index2], index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDWR, 1, &BR[br][2][1],  (Ull)a[a_val],  (Ull)rofs, MSK_W0, (Ull)a[a_val], A_row_size, 0, 0, (Ull)NULL, A_row_size)

#define sparse_core1_1(ar,ar_pre,br,br_pre,a_val,index_val,index_MSK) \
      exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mop(OP_LDR,  3, &BR[br][0][1],  (Ull)b0[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][0][0],  (Ull)b1[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][1],  (Ull)b2[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][0],  (Ull)b3[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDWR, 1, &BR[br][2][1],  (Ull)a[a_val],  (Ull)rofs, MSK_W0, (Ull)a[a_val], A_row_size, 0, 0, (Ull)NULL, A_row_size)


#define sparse_core2(ar,ar_pre,br,br_pre,a_index1,a_index2,a_index3,a_index4)\
        exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,3, &BR[br][1][1],  (Ull)a_index[a_index1], (Ull)rofs, MSK_W1, (Ull)a_index[a_index1], A_row_size*2*4, 0, 0, (Ull)NULL, A_row_size*2*4);\
        mop(OP_LDR,3, &BR[br][1][0],  (Ull)a_index[a_index2], (Ull)rofs, MSK_W1, (Ull)a_index[a_index1], A_row_size*2*4, 0, 0, (Ull)NULL, A_row_size*2*4);\
        mop(OP_LDR,3, &BR[br][2][1],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index1], A_row_size*2*4, 0, 0, (Ull)NULL, A_row_size*2*4);\
        mop(OP_LDR,3, &BR[br][2][0],  (Ull)a_index[a_index4], (Ull)rofs, MSK_W1, (Ull)a_index[a_index1], A_row_size*2*4, 0, 0, (Ull)NULL, A_row_size*2*4)

#define sparse_core2_1(ar,ar_pre,br,br_pre,a_index1,a_index2,a_index3)\
        exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,3, &BR[br][1][1],  (Ull)a_index[a_index1], (Ull)rofs, MSK_W1, (Ull)a_index[a_index1], A_row_size*2*4, 0, 0, (Ull)NULL, A_row_size*2*4);\
        mop(OP_LDR,3, &BR[br][1][0],  (Ull)a_index[a_index2], (Ull)rofs, MSK_W1, (Ull)a_index[a_index1], A_row_size*2*4, 0, 0, (Ull)NULL, A_row_size*2*4);\
        mop(OP_LDR,3, &BR[br][2][1],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index1], A_row_size*2*4, 0, 0, (Ull)NULL, A_row_size*2*4);\
        mop(OP_LDR,3, &BR[br][2][0],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index1], A_row_size*2*4, 0, 0, (Ull)NULL, A_row_size*2*4)\
    

#define sparse_core3(ar,ar_pre,br,br_pre,a_val,A_index1,A_index2,index_MSK)\
        exe(OP_ADD, &AR[ar][0], BR[br_pre][1][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &AR[ar][1], BR[br_pre][1][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &AR[ar][2], BR[br_pre][2][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &AR[ar][3], BR[br_pre][2][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,  3, &BR[br][0][1], (Ull)b0[CHIP], AR[A_index1][A_index2], index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][0][0], (Ull)b1[CHIP], AR[A_index1][A_index2], index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][1][1], (Ull)b2[CHIP], AR[A_index1][A_index2], index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][1][0], (Ull)b3[CHIP], AR[A_index1][A_index2], index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDWR, 1, &BR[br][2][1], (Ull)a[a_val], (Ull)rofs, MSK_W0, (Ull)a[a_val], A_row_size, 0, 0, (Ull)NULL, A_row_size)

#define sparse_core3_1(ar,ar_pre,br,br_pre,a_val,index_val1,index_val2,index_val3,index_val4,index_val,index_MSK)\
        exe(OP_ADD, &index_val1, BR[br_pre][1][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &index_val2, BR[br_pre][1][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &index_val3, BR[br_pre][2][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &index_val4, BR[br_pre][2][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,  3, &BR[br][0][1], (Ull)b0[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][0][0], (Ull)b1[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][1][1], (Ull)b2[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][1][0], (Ull)b3[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDWR, 1, &BR[br][2][1], (Ull)a[a_val], (Ull)rofs, MSK_W0, (Ull)a[a_val], A_row_size, 0, 0, (Ull)NULL, A_row_size)


#define sparse_core4(ar,ar_pre,br,br_pre) \
        exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDWR, 1, &BR[br][0][1], (Ull)A_sort_index, (Ull)rofs, MSK_W0, (Ull)A_sort_index, A_row_size, 0, 0, (Ull)NULL, A_row_size)

// sparse_final1(61,59,60,61,59,x);

#define sparse_final(ar,ar_pre,ar_pre1,br,br_pre) \
	    mop(OP_LDR,  3, &BR[br][0][1],  (Ull)c00[CHIP],(Ull)AR[ar_pre1][0], MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_LDR,  3, &BR[br][1][1],  (Ull)c01[CHIP],(Ull)AR[ar_pre1][0], MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_LDR,  3, &BR[br][2][1],  (Ull)c02[CHIP],(Ull)AR[ar_pre1][0], MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_LDR,  3, &BR[br][3][1],  (Ull)c03[CHIP],(Ull)AR[ar_pre1][0], MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    exe(OP_FAD, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br][3][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mop(OP_STR, 3, &AR[ar][0], (Ull)c00[CHIP], (Ull)AR[ar_pre1][0], MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_STR, 3, &AR[ar][1], (Ull)c01[CHIP], (Ull)AR[ar_pre1][0], MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_STR, 3, &AR[ar][2], (Ull)c02[CHIP], (Ull)AR[ar_pre1][0], MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_STR, 3, &AR[ar][3], (Ull)c03[CHIP], (Ull)AR[ar_pre1][0], MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP)

#define sparse_final1(ar,ar_pre,ar_pre1,br,br_pre,index_val) \
	    mop(OP_LDR,  3, &BR[br][0][1],  (Ull)c00[CHIP],(Ull)index_val, MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_LDR,  3, &BR[br][1][1],  (Ull)c01[CHIP],(Ull)index_val, MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_LDR,  3, &BR[br][2][1],  (Ull)c02[CHIP],(Ull)index_val, MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_LDR,  3, &BR[br][3][1],  (Ull)c03[CHIP],(Ull)index_val, MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    exe(OP_FAD, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br][3][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mop(OP_STR, 3, &AR[ar][0], (Ull)c00[CHIP], (Ull)index_val, MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_STR, 3, &AR[ar][1], (Ull)c01[CHIP], (Ull)index_val, MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_STR, 3, &AR[ar][2], (Ull)c02[CHIP], (Ull)index_val, MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_STR, 3, &AR[ar][3], (Ull)c03[CHIP], (Ull)index_val, MSK_W1, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP)




//EMAX5A begin mm mapdist=0
/*3*/ for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
  /*2*/ for (INIT1=1,LOOP1=A_margin_tmp,rofs=(0-(Ull)1*8)<<32|((0-(Ull)1*4)&0xffffffff); LOOP1--; INIT1=0) { /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
    /*1*/ for (INIT0=1,LOOP0=RMGRP/(W*2),cofs=(0-W*4*2*B_row_size)<<32|((0-W*4*2*B_row_size)&0xffffffff); LOOP0--; INIT0=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
            exe(OP_ADD,    &cofs, INIT0?cofs:cofs, EXP_H3210, (W*4*2*B_row_size)<<32|(W*4*2*B_row_size), EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */
            exe(OP_ADD,    &rofs, rofs, EXP_H3210, INIT0?((Ull)1*8)<<32|((Ull)1*4):0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */

            mop(OP_LDR,3, &BR[1][1][1],  (Ull)a_index[0], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4, 0, 0, (Ull)NULL, A_row_size*2*4);             /* stage#1 */
            mop(OP_LDR,3, &BR[1][1][0],  (Ull)a_index[1], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4, 0, 0, (Ull)NULL, A_row_size*2*4);             /* stage#1 */
            mop(OP_LDR,3, &BR[1][2][1],  (Ull)a_index[2], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4, 0, 0, (Ull)NULL, A_row_size*2*4);             /* stage#1 */
            mop(OP_LDR,3, &BR[1][2][0],  (Ull)a_index[3], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4, 0, 0, (Ull)NULL, A_row_size*2*4);             /* stage#1 */

            exe(OP_ADD, &x, BR[1][1][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            exe(OP_ADD, &y, BR[1][1][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            exe(OP_ADD, &z, BR[1][2][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            exe(OP_ADD, &t, BR[1][2][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            mop(OP_LDR,  3, &BR[3][0][1], (Ull)b0[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][0][0], (Ull)b1[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][1][1], (Ull)b2[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][1][0], (Ull)b3[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 2KB */
            mop(OP_LDWR, 1, &BR[3][2][1], (Ull)a[0], (Ull)rofs, MSK_W0, (Ull)a[0], A_row_size, 0, 0, (Ull)NULL, A_row_size); /* stage#2 16KB */

            exe(OP_FML, &AR[4][0], BR[3][0][1], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][1], BR[3][0][0], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][2], BR[3][1][1], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][3], BR[3][1][0], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            mop(OP_LDR,  3, &BR[4][0][1],  (Ull)b0[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][0][0],  (Ull)b1[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][1][1],  (Ull)b2[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][1][0],  (Ull)b3[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDWR, 1, &BR[4][2][1],  (Ull)a[1],    (Ull)rofs, MSK_W0, (Ull)a[1], A_row_size, 0, 0, (Ull)NULL, A_row_size);
            
            // #define sparse_core1(ar,ar_pre,br,br_pre,a_val,A_index1,A_index2,index_MSK) 
            sparse_core1_1(5,  4,  5,  4,     2,           y,MSK_W0);
            sparse_core1_1(6,  5,  6,  5,     3,           y,MSK_W1);
            sparse_core1_1(7,  6,  7,  6,     4,           z,MSK_W0);
            sparse_core1_1(8,  7,  8,  7,     5,           z,MSK_W1);
            sparse_core1_1(9,  8,  9,  8,     6,           t,MSK_W0);
            sparse_core1_1(10, 9,  10, 9,     7,           t,MSK_W1);

            sparse_core2(  11, 10, 11, 10,        4,5,6,7);
            sparse_core3_1(12, 11, 13, 11,    8,  x,y,z,t, x,MSK_W0);

            sparse_core1_1(14, 11, 14, 13,    9,           x,MSK_W1);

            sparse_core1_1(15, 14, 15, 14,    10,          y,MSK_W0);
            sparse_core1_1(16, 15, 16, 15,    11,          y,MSK_W1);
            sparse_core1_1(17, 16, 17, 16,    12,          z,MSK_W0);
            sparse_core1_1(18, 17, 18, 17,    13,          z,MSK_W1);
            sparse_core1_1(19, 18, 19, 18,    14,          t,MSK_W0);
            sparse_core1_1(20, 19, 20, 19,    15,          t,MSK_W1);

            sparse_core2(  21, 20, 21, 20,        8,9,10,11);
            sparse_core3_1(22, 21, 23, 21,    16, x,y,z,t, x,MSK_W0);

            sparse_core1_1(24, 21, 24, 23,    17,          x,MSK_W1);

            sparse_core1_1(25, 24, 25, 24,    18,          y,MSK_W0);
            sparse_core1_1(26, 25, 26, 25,    19,          y,MSK_W1);
            sparse_core1_1(27, 26, 27, 26,    20,          z,MSK_W0);
            sparse_core1_1(28, 27, 28, 27,    21,          z,MSK_W1);
            sparse_core1_1(29, 28, 29, 28,    22,          t,MSK_W0);
            sparse_core1_1(30, 29, 30, 29,    23,          t,MSK_W1);

            sparse_core2(  31, 30, 31, 30,        12,13,14,15);
            sparse_core3_1(32, 31, 33, 31,    24, x,y,z,t, x,MSK_W0);

            sparse_core1_1(34, 31, 34, 33,    25,          x,MSK_W1);

            sparse_core1_1(35, 34, 35, 34,    26,          y,MSK_W0);
            sparse_core1_1(36, 35, 36, 35,    27,          y,MSK_W1);
            sparse_core1_1(37, 36, 37, 36,    28,          z,MSK_W0);
            sparse_core1_1(38, 37, 38, 37,    29,          z,MSK_W1);
            sparse_core1_1(39, 38, 39, 38,    30,          t,MSK_W0);
            sparse_core1_1(40, 39, 40, 39,    31,          t,MSK_W1);

            sparse_core2(  41, 40, 41, 40,        16,17,18,19);
            sparse_core3_1(42, 41, 43, 41,    32, x,y,z,t, x,MSK_W0);
   
            sparse_core1_1(44, 41, 44, 43,    33,          x,MSK_W1);

            sparse_core1_1(45, 44, 45, 44,    34,          y,MSK_W0);
            sparse_core1_1(46, 45, 46, 45,    35,          y,MSK_W1);
            sparse_core1_1(47, 46, 47, 46,    36,          z,MSK_W0);
            sparse_core1_1(48, 47, 48, 47,    37,          z,MSK_W1);
            sparse_core1_1(49, 48, 49, 48,    38,          t,MSK_W0);
            sparse_core1_1(50, 49, 50, 49,    39,          t,MSK_W1);

            sparse_core2_1(51, 50, 51, 50,        20,21,22);
            sparse_core3_1(52, 51, 53, 51,    40, x,y,z,t, x,MSK_W0);
   
            sparse_core1_1(54, 51, 54, 53,    41,           x,MSK_W1);

            sparse_core1_1(55, 54, 55, 54,    42,             y,MSK_W0);
            sparse_core1_1(56, 55, 56, 55,    43,             y,MSK_W1);
            sparse_core1_1(57, 56, 57, 56,    44,             z,MSK_W0);
            sparse_core1_1(58, 57, 58, 57,    45,             z,MSK_W1);
            sparse_core4(  59, 58, 59, 58);
            exe(OP_ADD, &x, BR[59][0][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);
            
            sparse_final1(62,59,60,61,59,x);
          }
        }
      }
//EMAX5A end
    }
  }
//EMAX5A drain_dirty_lmm
}
