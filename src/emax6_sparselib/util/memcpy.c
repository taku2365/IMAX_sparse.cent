#include "../Include/emax6_sparselib.h"

static void IMAX_mm_memcpy(Uchar* dst, Uchar* src, size_t len){
    int i;
    Uchar* dst_tmp,*src_tmp;
    dst_tmp = (Uchar*)dst;
    src_tmp = (Uchar*)src;
    for(i=0; i<len; i+=1){
        dst_tmp[i] = src_tmp[i];
    }

}


void IMAX_memcpy(Uchar* dst, Uchar* src, size_t len, emax6_param* param){
    if(((size_t)dst&0x0f)||((size_t)src&0x0f)){
        fprintf(stderr,"alignment error\n memcopy.c:%d\n",__LINE__);
        exit(1);
    }


    switch (param->mode)
    {
    case SPARSE_DENSE_58_SPMV_MODE:
    case DENSE_SPMV_MODE:
        IMAX_mm_memcpy(dst,src,len);
        break;
    
    default:
        fprintf(stderr,"This pattern does not exist memcopy.c:%d \n",__LINE__);
        break;
    }

}
