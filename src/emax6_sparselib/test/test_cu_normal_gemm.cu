#include <stdio.h>
#include <stdlib.h>

// CUDA runtime
#include <cuda_runtime.h>
#include <cublas_v2.h>

// #include "dense_help_func.hpp"
// #include "dense.cu"
#include <time.h>
#include <sys/times.h>
#include <unistd.h>



#include <stdio.h>
#include <stdlib.h>

// CUDA runtime
#include <cuda_runtime.h>
#include <cublas_v2.h>



// cal offset from row col and ld , in row-major matrix, ld is the width of the matrix
#define OFFSET(row, col, ld) ((row) * (ld) + (col))

// transfer float4
#define FETCH_FLOAT4(pointer) (reinterpret_cast<float4*>(&(pointer))[0])
template <
    const int BLOCK_SIZE_M,  // width of block of C that each thread block calculate
    const int BLOCK_SIZE_K,  // height of block of A that each thread block load into shared memory
    const int BLOCK_SIZE_N,  // height of block of C that each thread block calculate
    const int THREAD_SIZE_Y, // height of block of C that each thread calculate
    const int THREAD_SIZE_X,  // width of block of C that each thread calculate
    const bool ENABLE_DOUBLE_BUFFER // whether enable double buffering or not
    > 
__global__ void MatrixMulCUDA6( 
    float * __restrict__ A,
    float * __restrict__ B,
    float * __restrict__ C, 
    const int K,
    const int N) {
    // Block index
    int bx = blockIdx.x;
    int by = blockIdx.y;

    // Thread index
    int tx = threadIdx.x;
    int ty = threadIdx.y;
    
    // size of thread block
    const int bszx = BLOCK_SIZE_N / THREAD_SIZE_X;
    const int bszy = BLOCK_SIZE_M / THREAD_SIZE_Y;
    const int THREAD_NUM_PER_BLOCK = bszy * bszx;

    // thread id
    const int tid = ty * bszx + tx;

    // shared memory

    __shared__ float As[BLOCK_SIZE_M][BLOCK_SIZE_K]; // avoid bank conflict
    __shared__ float Bs[BLOCK_SIZE_K][BLOCK_SIZE_N];
    // registers for C
    float accum[THREAD_SIZE_Y][THREAD_SIZE_X] = {0};
    // registers for A and B
    float frag_a[THREAD_SIZE_Y];
    float frag_b[THREAD_SIZE_X];
    
    // threads needed to load one row of tile
    // / 4 is because float4 is used
    const int A_TILE_THREAD_PER_ROW = BLOCK_SIZE_K / 4;
    const int B_TILE_THREAD_PER_ROW = BLOCK_SIZE_N / 4;
    
    // row number and col number that needs to be loaded by this thread
    const int A_TILE_ROW_START = tid / A_TILE_THREAD_PER_ROW;
    const int B_TILE_ROW_START = tid / B_TILE_THREAD_PER_ROW;

    const int A_TILE_COL = tid % A_TILE_THREAD_PER_ROW * 4;
    const int B_TILE_COL = tid % B_TILE_THREAD_PER_ROW * 4;
    
    // row stride that thread uses to load multiple rows of a tile
    const int A_TILE_ROW_STRIDE = THREAD_NUM_PER_BLOCK / A_TILE_THREAD_PER_ROW;
    const int B_TILE_ROW_STRIDE = THREAD_NUM_PER_BLOCK / B_TILE_THREAD_PER_ROW;
    
    // can not unroll since K can not be determined at this point
    for (int tile_idx = 0 ; tile_idx < K ; tile_idx += BLOCK_SIZE_K) {
        // load A from global memory to shared memory
        #pragma unroll
        for ( int i = 0 ; i < BLOCK_SIZE_M ; i += A_TILE_ROW_STRIDE) {
            FETCH_FLOAT4(As[A_TILE_ROW_START + i][A_TILE_COL]) = FETCH_FLOAT4(A[OFFSET(
                    BLOCK_SIZE_M * by + A_TILE_ROW_START + i, // row
                    A_TILE_COL + tile_idx, // col
                    K )]);
        }

        // load B from global memory to shared memory
        #pragma unroll
        for ( int i = 0 ; i < BLOCK_SIZE_K; i += B_TILE_ROW_STRIDE) {
            FETCH_FLOAT4(Bs[B_TILE_ROW_START + i][B_TILE_COL]) = FETCH_FLOAT4(B[OFFSET(
                    tile_idx + B_TILE_ROW_START + i, // row
                    B_TILE_COL + BLOCK_SIZE_N * bx, // col
                    N )]);
        }
    
        __syncthreads();

        // compute c
        #pragma unroll
        for (int k = 0; k < BLOCK_SIZE_K; ++ k) {
            // load A from shared memory to register
            #pragma unroll
            for (int thread_y = 0; thread_y < THREAD_SIZE_Y; ++thread_y) {
                frag_a[thread_y] = As[ty * THREAD_SIZE_Y + thread_y][k];
            }

            // load B from shared memory to register
            #pragma unroll
            for (int thread_x = 0; thread_x < THREAD_SIZE_X; thread_x += 4) {
                FETCH_FLOAT4(frag_b[thread_x]) = FETCH_FLOAT4(Bs[k][THREAD_SIZE_X * tx + thread_x]);
            }
            
            #pragma unroll
            for (int thread_y = 0; thread_y < THREAD_SIZE_Y; ++thread_y) {
                #pragma unroll
                for (int thread_x = 0; thread_x < THREAD_SIZE_X; ++thread_x) {
                    accum[thread_y][thread_x] += frag_a[thread_y] * frag_b[thread_x];
                }
            }
            
        }
        __syncthreads();
    }

    // store back to C
    #pragma unroll
    for (int thread_y = 0; thread_y < THREAD_SIZE_Y; ++thread_y) {
        #pragma unroll
        for (int thread_x = 0; thread_x < THREAD_SIZE_X; thread_x+=4) {
            FETCH_FLOAT4(C[OFFSET(
                BLOCK_SIZE_M * by + ty * THREAD_SIZE_Y + thread_y,
                BLOCK_SIZE_N * bx + tx * THREAD_SIZE_X + thread_x,
                N)]) = FETCH_FLOAT4(accum[thread_y][thread_x]);
        }
    }
}

// TODO add shuffle to enable GPU write back col


#ifndef DENSE_HELP_FUNC
#define DENSE_HELP_FUNC

#define checkCudaErrors(func)				\
{									\
    cudaError_t e = (func);			\
    if(e != cudaSuccess)						                \
        printf ("%s %d CUDA: %s\n", __FILE__,  __LINE__, cudaGetErrorString(e));		\
}

static const char *_cuBlasGetErrorEnum(cublasStatus_t error)
{
    switch (error)
    {
        case CUBLAS_STATUS_SUCCESS:
            return "CUBLAS_STATUS_SUCCESS";

        case CUBLAS_STATUS_NOT_INITIALIZED:
            return "CUBLAS_STATUS_NOT_INITIALIZED";

        case CUBLAS_STATUS_ALLOC_FAILED:
            return "CUBLAS_STATUS_ALLOC_FAILED";

        case CUBLAS_STATUS_INVALID_VALUE:
            return "CUBLAS_STATUS_INVALID_VALUE";

        case CUBLAS_STATUS_ARCH_MISMATCH:
            return "CUBLAS_STATUS_ARCH_MISMATCH";

        case CUBLAS_STATUS_MAPPING_ERROR:
            return "CUBLAS_STATUS_MAPPING_ERROR";

        case CUBLAS_STATUS_EXECUTION_FAILED:
            return "CUBLAS_STATUS_EXECUTION_FAILED";

        case CUBLAS_STATUS_INTERNAL_ERROR:
            return "CUBLAS_STATUS_INTERNAL_ERROR";
    }
    return "<unknown>";
}


#define checkCuBlasErrors(func)				\
{									\
    cublasStatus_t e = (func);			\
    if(e != CUBLAS_STATUS_SUCCESS)						                \
        printf ("%s %d CuBlas: %s", __FILE__,  __LINE__, _cuBlasGetErrorEnum(e));		\
}



#endif
long     nanosec_sav, nanosec;
double  tmssave, tms;
long    ticksave, ticks;
int nIter = 200;

void reset_nanosec()
{
  struct timespec ts;
  clock_gettime(0, &ts); /*CLOCK_REALTIME*/
  nanosec_sav = 1000000000*ts.tv_sec + ts.tv_nsec;
}

void show_nanosec(int iter)
{
  struct timespec ts;
  clock_gettime(0, &ts); /*CLOCK_REALTIME*/
  nanosec = 1000000000*ts.tv_sec + ts.tv_nsec;
  printf("msec: ARM:%llu\n", (nanosec - nanosec_sav)/(long long)iter/1000000);
  nanosec_sav = nanosec;
}

void reset_time(void)
{
  struct tms    utms;

  times(&utms);
  ticksave = utms.tms_utime;
}


int main(int argc, char** argv) {
    if (argc != 4) {
        printf("usage: ./main [M] [K] [N]\n");
        exit(0);
    }
    size_t M = atoi(argv[1]);
    size_t K = atoi(argv[2]);
    size_t N = atoi(argv[3]);
    size_t bytes = sizeof(float) * M * K;
    float* h_A = (float*)malloc(bytes);
    float* h_B = (float*)malloc(bytes);
    float* h_C = (float*)malloc(bytes);
    float* h_C1 = (float*)malloc(bytes);

    float* d_A;
    float* d_B;
    float* d_C;

    checkCudaErrors(cudaMalloc(&d_A, bytes));
    checkCudaErrors(cudaMalloc(&d_B, bytes));
    checkCudaErrors(cudaMalloc(&d_C, bytes));
    double msecPerMatrixMul[2] = {0, 0};
    double gigaFlops[2] = {0, 0};
    double flopsPerMatrixMul = 2.0 * M * N * K;

    const int BLOCK_SIZE_M = 32;
    const int BLOCK_SIZE_K = 32;
    const int BLOCK_SIZE_N = 32;
    const int THREAD_SIZE_X = 4;
    const int THREAD_SIZE_Y = 4;
    const bool ENABLE_DOUBLE_BUFFER = false;
    int k_block = K / BLOCK_SIZE_K;
    int stride = 2;

    // 生成A的数据
    for( int i = 0; i < M * K; i++ ) {
        int row = (i / K);
        int col = (i % K);
        int row_block = row / BLOCK_SIZE_M;
        int col_block = col / BLOCK_SIZE_K;
        if ((row_block * k_block + col_block) % stride == 0) h_A[i] = 1;
        else {
            h_A[i] = 1;
        }
    }

    // 生成B的数据
    for( int i = 0; i < K * N; i++ ) {
        if ( i >= K * N / 2) h_B[i] = 2;
        else {
            h_B[i] = 1;
        }
    }

    // checkCudaErrors(cudaMemcpy( d_A, h_A, bytes, cudaMemcpyHostToDevice));
    // checkCudaErrors(cudaMemcpy( d_B, h_B, bytes, cudaMemcpyHostToDevice));
    
    cudaEvent_t start, stop;
    checkCudaErrors(cudaEventCreate(&start));
    checkCudaErrors(cudaEventCreate(&stop));
    float msecTotal = 0;

    // checkCudaErrors(cudaMemcpy( d_C, h_C, bytes, cudaMemcpyHostToDevice));
    // checkCudaErrors(cudaEventRecord(start));

    // for (int run = 0 ; run < nIter; run ++ ) {
    //     dim3 dimBlock(BLOCK_SIZE_N / THREAD_SIZE_X, BLOCK_SIZE_M / THREAD_SIZE_Y);
    //     dim3 dimGrid(N / BLOCK_SIZE_N, M / BLOCK_SIZE_M);
    //     MatrixMulCUDA6<BLOCK_SIZE_M, BLOCK_SIZE_K, BLOCK_SIZE_N, THREAD_SIZE_Y, THREAD_SIZE_X, ENABLE_DOUBLE_BUFFER> 
    //     <<< dimGrid, dimBlock >>>(d_A, d_B, d_C, K, N);

    // }
    // checkCudaErrors(cudaEventRecord(stop));
    // checkCudaErrors(cudaEventSynchronize(stop));
    // checkCudaErrors(cudaEventElapsedTime(&msecTotal, start, stop));


    // checkCudaErrors(cudaMemcpy( h_C, d_C, bytes, cudaMemcpyDeviceToHost));

    // msecPerMatrixMul[0] = msecTotal / nIter;
    // gigaFlops[0] = (flopsPerMatrixMul * 1.0e-9f) / (msecPerMatrixMul[0] / 1000.0f);
    // printf( "My gemm Performance= %.2f GFlop/s, Time= %.3f msec, Size= %.0f Ops,\n",
    //     gigaFlops[0],
    //     msecPerMatrixMul[0],
    //     flopsPerMatrixMul);

    // cublas
    cublasHandle_t blas_handle;  
    checkCuBlasErrors ( cublasCreate(&blas_handle) );
    float alpha = 1.0;
    float beta = 0;
    for( int i = 0; i < M * K; i++ ) {
        int row = (i / K);
        int col = (i % K);
        int row_block = row / BLOCK_SIZE_M;
        int col_block = col / BLOCK_SIZE_K;
        if ((row_block * k_block + col_block) % stride == 0) h_A[i] = 1;
        else {
            h_A[i] = 1;
        }
    }

    // 生成B的数据
    for( int i = 0; i < K * N; i++ ) {
        if ( i >= K * N / 2) h_B[i] = 2;
        else {
            h_B[i] = 1;
        }
    }

    checkCudaErrors(cudaEventRecord(start));
    // reset_nanosec();
    for (int run = 0 ; run < nIter; run ++ ) {
    checkCudaErrors(cudaMemcpy( d_A, h_A, bytes, cudaMemcpyHostToDevice));
    checkCudaErrors(cudaMemcpy( d_B, h_B, bytes, cudaMemcpyHostToDevice));
    checkCudaErrors(cudaMemcpy( d_C, h_C, bytes, cudaMemcpyHostToDevice));
        checkCuBlasErrors (
            cublasSgemm (blas_handle, CUBLAS_OP_T, CUBLAS_OP_T, 
                M, N, K, &alpha, 
                d_A, M, d_B, K, &beta, d_C, K
            )
        );
    checkCudaErrors(cudaMemcpy( h_C1, d_C, bytes, cudaMemcpyDeviceToHost));
    cudaDeviceSynchronize();
    }
    // show_nanosec(nIter);
    checkCudaErrors(cudaEventRecord(stop));
    checkCudaErrors(cudaEventSynchronize(stop));
    checkCudaErrors(cudaEventElapsedTime(&msecTotal, start, stop));


    msecPerMatrixMul[1] = msecTotal / nIter;
    gigaFlops[1] = (flopsPerMatrixMul * 1.0e-9f) / (msecPerMatrixMul[1] / 1000.0f);
    printf( "CuBlas Performance= %.2f GFlop/s, Time= %.3f msec, Size= %.0f Ops,\n",
        gigaFlops[1],
        msecPerMatrixMul[1],
        flopsPerMatrixMul);

    cublasDestroy(blas_handle); 

    
    // double eps = 1.e-6;  // machine zero
    // bool correct = true;
    // for (int i = 0; i < M * N; i++) {
    //     // h_C1 是转置
    //     int row = i / N;
    //     int col = i % N;
    //     double abs_err = fabs(h_C[i] - h_C1[col * M + row]);
    //     double dot_length = M;
    //     double abs_val = fabs(h_C[i]);
    //     double rel_err = abs_err / abs_val / dot_length;
    //     if (rel_err > eps) {
    //         printf("Error! Matrix[%05d]=%.8f, ref=%.8f error term is > %E\n",
    //                 i, h_C[i], h_C1[col * M + row], eps);
    //         correct = false;
    //         break;
    //     }
    // }

    // printf("%s\n", correct ? "Result= PASS" : "Result= FAIL");
    // printf("ratio= %f\n", gigaFlops[0] / gigaFlops[1]);
    
    // Free Memory
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
    
    free(h_A);
    free(h_B);
    free(h_C);
    free(h_C1);
}