#include "../Include/emax6_sparselib.h"

Sll get_H_param(emax6_param* params){
    Sll H = 0;
    switch(params->mode){

        case DENSE_DENSE:
        H = params->H_param = 59LL;
        break;
        case SPARSE_DENSE_46:
            H = params->H_param = 46LL;
        break;
        case SPARSE_DENSE_58_VER2:
        case SPARSE_DENSE_58_VER3:
            H =params->H_param = 58LL;
        break;
        default:
        printf("this pattern does not exist get_H_param LINE %d\n",__LINE__);
        exit(1);
    }
    return H;    
}
