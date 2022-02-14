#include "../Include/emax6_sparselib.h"

inline Sll get_H_param(emax6_param* params){
    Sll H = 0;
    switch(params->mode){

        case DENSE_DENSE_MODE:
        case DENSE_SPMV_MODE:
        H = params->H_param = 59LL;
        break;
        case SPARSE_DENSE_46_MODE:
            H = params->H_param = 46LL;
        break;
        case SPARSE_DENSE_58_VER2_MODE:
        case SPARSE_DENSE_58_VER3_MODE:
        case SPARSE_DENSE_58_SPMV_MODE:
            H =params->H_param = 58LL;
        break;
        default:
        printf("this pattern does not exist get_H_param LINE %d\n",__LINE__);
        exit(1);
    }
    return H;    
}
