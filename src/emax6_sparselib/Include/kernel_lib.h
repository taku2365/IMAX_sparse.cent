//このincludeはemaxlib.cを含んでいるからkernel_lib.cでしか使わない
#include "./emax6_sparselib.h"
#include "./emax6lib.c"
void sparse_gemm_768_96_96_768_1(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse);
void sparse_gemm_768_96_96_768_2(Uint* C, const Uint* A, const Uint* B , emax6_sparse2* A_sparse);
void sysinit(Uint memsize,Uint alignment,Uchar** membase);