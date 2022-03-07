//このincludeはemaxlib.cを含んでいるからkernel_lib.cでしか使わない
#include "./emax6_sparselib.h"
#include "./emax6lib.c"



#ifndef EMAX6_LIB_C
#define EMAX6_LIB_C
void sparse_gemm_CHIP_div_B(  Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse, emax6_param* params);
void sparse_spmv_CHIP_div_A(  Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse, emax6_param* params);
// void sparse_gemm_CHIP_div_B_2(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse, emax6_param* params);
// void sparse_gemm_CHIP_div_B_3(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse, emax6_param* params);
// void sparse_gemm_CHIP_div_B_4(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse, emax6_param* params);
// void sparse_gemm_CHIP_div_B_5(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse, emax6_param* params);
void sparse_gemm_CHIP_div_A(  Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse, emax6_param* params);
void sysinit(Uint memsize,Uint alignment,Uchar** membase);
#endif



