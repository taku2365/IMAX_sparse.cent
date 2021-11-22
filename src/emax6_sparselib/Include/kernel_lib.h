//このincludeはemaxlib.cを含んでいるからkernel_lib.cでしか使わない
#include "./emax6_sparselib.h"
#include "./emax6lib.c"
void sparse_gemm_736(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse);
void sysinit(Uint memsize,Uint alignment,Uchar** membase);