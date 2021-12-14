//このincludeはemaxlib.cを含んでいるからkernel_lib.cでしか使わない
#include "./emax6_sparselib.h"
#include "./emax6lib.c"
void sparse_gemm_736_736_736_CHIP_div_B(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse);
void sparse_gemm_736_736_736_CHIP_div_B_2(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse);
void sparse_gemm_736_736_736_CHIP_div_B_3(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse);
void sparse_gemm_736_736_736_CHIP_div_B_4(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse);
void sparse_gemm_736_736_736_CHIP_div_A(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse);
void sysinit(Uint memsize,Uint alignment,Uchar** membase);