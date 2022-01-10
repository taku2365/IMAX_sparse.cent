/*                                   疎行列演算withrtx3090*/
/*                               Primary writer: R.Funai */
/*                         funai.ryotaro.fs8@is.naist.jp */

#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <cinttypes>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <pthread.h>
#include <iostream>
#include <cuda_runtime_api.h>
#include <cublas_v2.h>
#include <cusparse_v2.h>
#include <thrust/device_vector.h>

typedef unsigned char      Uchar;
typedef unsigned short     Ushort;
typedef unsigned int       Uint;
typedef unsigned long long Ull;
typedef long long int      Sll;

//-----------------
// Device Kernel
//-----------------
__global__ void Device_Kernel(void)
{
	float ix = threadIdx.x + blockIdx.x * blockDim.x;
	float iy = threadIdx.y + blockIdx.y * blockDim.y;
	printf("Device (ix, iy) = (%d, %d) : \
threadIdx.x = %d, blockIdx.x = %d, blockDim.x = %d, \
threadIdx.y = %d, blockIdx.y = %d, blockDim.y = %d\n",
	        ix, iy, 
	        threadIdx.x, blockIdx.x, blockDim.x,
	        threadIdx.y, blockIdx.y, blockDim.y);
}

/* LMM:16KB, RMM:64KB: M/NCHIP=124 M/NCHIP/RMGRP=31 */
/* A A   B B B B B B   C C C C C C */
/* A A   B B B B B B   C C C C C C */
/* A A                 C C C C C C */
/* A A                 C C C C C C */
/* M1=4 L=2, M2=6      L<M1,M2     */

#define M1 240LL
#define M2 240LL
#define L  240LL
#define LP 24LL
#define BLOCK_SIZE (32,32)
#define GRID_SIZE (8,8)

// Cuda実行時、ランタイムAPIをCHECKで囲むとエラーが見れるようにする
#if 0
#define CHECK(func) 
{
    {
        const cudaError_t error = func; //funcで指定したAPIの戻り値を取得(error/success)
        // Errorなら以下を表示する
        if (error != cudaSuccess)
        {
            printf("Error: %s:%d, ",__FILE__, __LINE__);    //FILEと行数
            printf("Code:%d, Reason: %s\n", error, cudaGetErrorString(error));  //Error内容
            cudaDeviceReset();  //デバイスのリセット
            exit(EXIT_FAILURE); //エラー終了
        }
    }
}
#endif

typedef struct {
  float d; /* low */
  Uint  x; /* high */
} packed;

float A[M1*M2], B[M1*M2], B_T[M1*M2], C_Orig[M1*M2], C_Gpu[M1*M2];
int row, col, n;
int top, blk;
int w, h;
int count0, count1, count2;

void orig();
void gpu();
void reset_nanosec();
void show_nanosec();
void reset_time();
void show_time();

int main(void){
   int row, col;

  /* 乗数行列の生成 */ 
  /**************************************************/
  /* A                                              */
  /**************************************************/
  for (row=0; row<M1; row++) {
    for (col=0; col<L; col++) {
      if (abs(row-col) < LP/2)
        A[row*L+col] = (float)(row-col)/(float)(L/(128/LP));
      else  A[row*L+col] = 0;
    }
  }

  /* 被乗数行列の生成 */ 
  /**************************************************/
  /* B                                              */
  /**************************************************/
  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++) {
      if (abs(row-col) < LP/2)
        B[row*L+col] = (float)(row-col)/(float)(L/(128/LP));
      else B[row*L+col] = 0;
    }
  }
  /* 転置行列 */
  for(row=0;row<M1;++row){
    for(col=0;col<M2;++col){
     B_T[col*L+row]=B[row*L+col];
    }
  }
  /*結果格納行列の生成*/
  /**************************************************/
  /* C                                              */
  /**************************************************/
  for (row=0; row<M2; row++) {
    for (col=0; col<L; col++) {
        C_Orig[row*L+col] = 0;
        C_Gpu[row*L+col] = 0;
    }
  }
  orig();
//RTX3090によるCuSparseの実行
  gpu();

// 検算
  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++) {
      if (C_Orig[row*M2+col] != C_Gpu[row*M2+col]) {
        count2++;
        printf("C_Orig[%d][%d]=%f C_Gpu[%d][%d]=%f\n", row, col, (double)C_Orig[row*M2+col],
                                                        row, col, (double)C_Gpu[row*M2+col]);
      }
    }
  }
  if (count2)
    printf("Num of diffs: %d\n", count2);
  else
    printf("Results are equal\n");

  return (0);
}

void orig() {
  printf("<<<ORIG>>>\n");
  reset_nanosec();
  for (row=0; row<M1; row++) {
    for (col=0; col<M2; col++) {
      for (n=0; n<L; n++) {
        if (n==0) *(float*)&C_Orig[row*M2+col]  = *(float*)&A[row*L+n] * *(float*)&B[col*L+n];
        else      *(float*)&C_Orig[row*M2+col] += *(float*)&A[row*L+n] * *(float*)&B[col*L+n];
        count0++;
      }
    }
  }
  show_nanosec();
}

// ここを書き換える
void gpu() {
  cudaError_t cudaStat;
  cublasStatus_t stat;
  cublasHandle_t handle;
  float *dA,*dB,*dC;


  printf("<<<RTX3090>>>\n");
  
  // GPUのメモリを確保 
  cudaStat = cudaMalloc((void**)&dA, M1*M2*sizeof(float));
  if (cudaStat != cudaSuccess) printf ("device memory allocation failed");
  cudaStat = cudaMalloc((void**)&dB, M1*M2*sizeof(float));
  if (cudaStat != cudaSuccess) printf ("device memory allocation failed");
  cudaStat = cudaMalloc((void**)&dC, M1*M2*sizeof(float));
  if (cudaStat != cudaSuccess) printf ("device memory allocation failed");
  stat = cublasCreate(&handle);
  cublasSetMathMode(handle,CUBLAS_TENSOR_OP_MATH);  
  
  // 行列のコピー
  if (stat != CUBLAS_STATUS_SUCCESS) printf ("CUBLAS initialization failed\n");
  stat = cublasSetMatrix (M1, M2, sizeof(float), A, M1, dA, M1);
  if (stat != CUBLAS_STATUS_SUCCESS) {
    printf ("data download failed");
    cudaFree (dA);
    cublasDestroy(handle); 
  }
  stat = cublasSetMatrix (M1, M2, sizeof(float), B_T, M1, dB, M1);
  if (stat != CUBLAS_STATUS_SUCCESS) {
    printf ("data download failed");
    cudaFree (dB);
    cublasDestroy(handle); 
  }
  stat = cublasSetMatrix (M1, M2, sizeof(float), C_Gpu, M1, dC, M1);
  if (stat != CUBLAS_STATUS_SUCCESS) {
    printf ("data download failed");
    cudaFree (dC);
    cublasDestroy(handle); 
  }

  // 行列演算の実行
  // y=α*Ax + β*yと書く必要があるため、alpha=1.0f, beta=0.0f
  /*https://qiita.com/t-tkd3a/items/098f51c2cc40a5bddc38
    cublasSgemm(    
        handle,
        CUBLAS_OP_N, //行列A 転置有無
        CUBLAS_OP_N, //行列B 転置有無
        num,    // 行列Aの行数
        num,    // 行列Bの列数
        num,    // 行列Aの列数(=行列Ｂの行数)
        &alpha, // 行列の積に掛ける値(なければ1)
        devA,   // 行列A
        num,    // 行列Aの行数
        devB,   // 行列B
        num,    // 行列Bの行数
        &beta,  // 行列Cに掛けるスカラ値(なければ0)
        devC,   // 行列Cの初期値 兼 出力先
        num // 行列Cの行数
);*/
  reset_nanosec();
  float alpha=1.0f, beta=0.0f;
  cublasSgemm(handle,CUBLAS_OP_N,CUBLAS_OP_N,M1,M2,M2,&alpha,dA,M1,dB,M1,&beta,dC,M1);

  // 演算の終わりとともに計測終了
  show_nanosec();
  // 
  stat = cublasGetMatrix(M1,M2,sizeof(float),dC,M2,C_Gpu,M2);
  if (stat != CUBLAS_STATUS_SUCCESS) {
    printf ("data upload failed");
    cudaFree (dC);
    cublasDestroy(handle);
  }
  cudaFree(dA);
  cudaFree(dB);
  cudaFree(dC);
  cublasDestroy(handle);
}

Ull     nanosec_sav, nanosec;
double  tmssave, tms;
long    ticksave, ticks;
struct  rusage rusage;

void reset_nanosec()
{
  struct timespec ts;
  clock_gettime(0, &ts); /*CLOCK_REALTIME*/
  nanosec_sav = 1000000000*ts.tv_sec + ts.tv_nsec;
}

void show_nanosec()
{
  struct timespec ts;
  clock_gettime(0, &ts); /*CLOCK_REALTIME*/
  nanosec = 1000000000*ts.tv_sec + ts.tv_nsec;
  printf("nanosec: ARM:%llu\n", nanosec - nanosec_sav);
  nanosec_sav = nanosec;
}

void reset_time(void)
{
  struct tms    utms;

  times(&utms);
  ticksave = utms.tms_utime;
}

void show_time(void)
{
  struct tms    utms;

  times(&utms);
  ticks = utms.tms_utime;
  printf("====TOTAL-CPUS-TIME(w/o IO) %g sec===\n", (double)(ticks-ticksave)/sysconf(_SC_CLK_TCK));
  ticksave = ticks;
}
