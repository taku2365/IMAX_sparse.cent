//このincludeはemaxlib.cを含んでいるからここでしか使わない
#ifndef NO_EMAX6LIB_BODY
#define NO_EMAX6LIB_BODY
#endif
#include "../Include/kernel_lib.h"



void sparse_gemm_CHIP_div_B(Uint* C, const Uint* A, const Uint* B, emax6_sparse2* A_sparse, emax6_param* params) {
    // pattern 0 dense dense
    // pattern 1 sparse dense H=46 ver
    // pattern 2 sparse dense H=58 ver
    switch (params->mode)
    {
    case DENSE_DENSE_MODE:
        gemm_normal_CHIP_div_B(C, A, B, params);
        break;
    case SPARSE_DENSE_46_MODE:
        sparse_gemm_CHIP_div_B_impl1(C, A, B, A_sparse, params);
        break;
    case SPARSE_DENSE_58_VER2_MODE:
        sparse_gemm_CHIP_div_B_impl2(C, A, B, A_sparse, params);
        break;
    case SPARSE_DENSE_58_VER3_MODE:
        sparse_gemm_CHIP_div_B_impl3(C, A, B, A_sparse, params);
        break;
    default:
        fprintf(stderr,"sparse_gemm_CHIP_div_B dont have this pattern\n");
        exit(1);
        break;
    }
}     


void sparse_spmv_CHIP_div_A(Uint* C, const Uint* A, const Uint* B, emax6_sparse2* A_sparse, emax6_param* params) {
        switch (params->mode)
    {
    case DENSE_SPMV_MODE:
        spmv_normal_CHIP_div_A(C, A, B, params);
        break;
    case SPARSE_DENSE_58_SPMV_MODE:
        spmv_sparse_CHIP_div_A(C, A, B, A_sparse, params);
    }
}





