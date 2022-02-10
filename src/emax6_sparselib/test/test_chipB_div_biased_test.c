static char RcsHeader[] = "$Header: /usr/home/nakashim/proj-arm64/sample/mm_cnn_lf/RCS/mm.c,v 1.4 2018/02/04 10:28:53 nakashim Exp nakashim $";

/*                          Copyright (C) 2013- by NAIST */
/*                           Primary writer: Y.Nakashima */
/*                                  nakashim@is.naist.jp */

#ifndef UTYPEDEF
#define UTYPEDEF
typedef unsigned char      Uchar;
typedef unsigned short     Ushort;
typedef unsigned int       Uint;
typedef unsigned long long Ull;
typedef long long int      Sll;
#if __AARCH64EL__ == 1
typedef long double Dll;
#else
typedef struct {Ull u[2];} Dll;
#endif
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <math.h>
#include <malloc.h>
#ifndef ARMSIML
#include <unistd.h>
#include <sys/times.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <pthread.h>
#endif


int WD=320, HT=240, BITMAP=320*240, SCRWD=5, SCRHT=5, VECWD=240, VECHT=240, VECSTEP=4;

#if defined(EMAX6)
// #include "../../src/conv-c2c/emax6.h"
//includeの順番が逆やとエラー
#include "../Include/emax6_sparselib.h"
#ifndef NO_EMAX6LIB_BODY
#define NO_EMAX6LIB_BODY
#endif
#include "../Include/kernel_lib.h"
// #include "./../../conv-c2c/emax6lib.c"
#endif

#define CSIMWD 320
#define CSIMHT 240
#define CSIMBM (CSIMWD*CSIMHT)

main(int argc,char*argv[])
{   
Uint *A = NULL;  /*[A_row_size][L];*/
Uint *B = NULL;  /*[L][B_col_size];*/
Uint *C0 = NULL; /*[A_row_size][B_col_size];*/
Uint *C1 = NULL; /*[A_row_size][B_col_size];*/
Uint *Base_p = NULL;
Uint *sort_index = NULL;
Uint *A_debug = NULL; /*[A_row_size][L];*/
Uint *B_debug = NULL; /*[L][B_col_size];*/
Uint *C_debug = NULL; /*[A_row_size][B_col_size];*/
coo_format* coo = NULL;
emax6_sparse2* A_sparse = NULL;
int blk_iter;
int mode,sparse_rate_len,sparse_rate_index;
int biased_percent_index,biased_percent_len;
int row,row1, col, col1, n, n1;
int top, blk;
int w, h;
int count0, count1, count2;
int nnz_A=0,nnz_B=0,nnz_B_debug=0;
double sum=0,sum1=0;
FILE* fp;
Uint size_array_index,size_array_len;
Uint memsize_tmp;
Sll H;
Sll A_row_size_ini,A_row_size,A_row_size_pad;
Sll A_col_size_ini,A_col_size,A_col_size_pad;
Sll B_row_size_ini,B_row_size,B_row_size_pad;
Sll B_col_size_ini,B_col_size,B_col_size_pad;
Sll B_col_blk_ini ,B_col_blk ;
Sll NCHIP_ini     ,NCHIP     ;
Sll W_ini         ,W         ;
Sll A_col_blk_ini ,A_col_blk ;
Sll C_col_blk_ini ,C_col_blk ;
extern Ull nanosec[NANOS_CLASS];
Uint tmp;
float zero_bias = 0.0;

// 77304050
// 3202063
A_row_size_ini = A_row_size = 1024LL;
A_col_size_ini = A_col_size = 1024LL;
B_row_size_ini = B_row_size = 1024LL;
B_col_size_ini = B_col_size = 1024LL;
A_col_blk_ini  = A_col_blk  = 5LL  ;
B_col_blk_ini  = B_col_blk  = 8LL  ;
C_col_blk_ini  = C_col_blk  = 0LL  ;
NCHIP_ini      = NCHIP      = 1LL  ;
W_ini          = W          = 4LL  ;

emax6_param params;
params.data_format = CSR_INDEX_VAL_SET_FORMAT;
// params.data_format = JDS_INDEX_VAL_SET_FORMAT;
params.mode = SPARSE_DENSE_58_VER2_MODE;
params.data_type = BIASED_SPARSE_TYPE;
//sparsity 0.5で固定
sparse_rate_index = 5;
H = get_H_param(&params);
// size_array_len = 2;
// Uint size_array[1] = {32,64};
// sparse_rate_len = 7;
// float sparse_rate[7] = {0.3,0.3,0.3,0.3,0.3,0.3,0.3};
size_array_len = 6;
Uint size_array[6] = {1024,512,256,128,64,32};
// Uint size_array[6] = {32,32,32,32,32,32};
sparse_rate_len = 12;
float sparse_rate[12] = {0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.85,0.9,0.95};
biased_percent_len = 9;
float biased_percent[9] = {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8};
Uint A_row_H_pad = 0;
Uint A_col_H_pad = 0;
Uint B_row_H_pad = 0;
Uint B_col_pad = 0;
A_row_H_pad = ((A_row_size%H) != 0) ? -A_row_size%H + H : A_row_H_pad;
B_row_H_pad = A_col_H_pad = ((A_col_size%H) != 0) ? -A_col_size%H + H : A_col_H_pad;
B_col_pad = ((B_col_size%8) != 0) ? -B_col_size%8 + 8 : B_col_pad;
A_row_size_pad = A_row_size+A_row_H_pad;
A_col_size_pad = A_col_size+A_col_H_pad;
B_row_size_pad = B_row_size+B_row_H_pad;
B_col_size_pad = B_col_size+B_col_pad  ;
char* name = "result.csv";
if(argc == 2){name = argv[1];}
#if !defined(CSIMDEBUG)
if((fp=fopen(name,"w"))==NULL){
    fprintf(stderr,"cant open csv\n");
    exit(1);
}
#endif

#if !defined(CSIMDEBUG)
STORE_CSV_INI(fp);
#endif
Uchar* membase = NULL;
Uint memsize = 2*(A_row_size_pad*(A_col_size_pad))*sizeof(Uint)
                +(B_row_size_pad)*(B_col_size_pad)*sizeof(Uint)
                +A_row_size_pad*(B_col_size_pad)*sizeof(Uint)
                // +A_row_size*B_col_size*sizeof(Uint)
                +A_row_size_pad*sizeof(Uint)
                +8*sizeof(Uint)*sparse_rate_len;
                
memsize += ((memsize%32) != 0) ? (-memsize%32 + 32) : 0;
sysinit((Uint)memsize,32,&membase);
        //A_colがHで割れないときのpadding
for(size_array_index=0;size_array_index<size_array_len;size_array_index++){
    for(biased_percent_index=0;biased_percent_index<biased_percent_len;biased_percent_index++){
        A_row_size = params.A_row_size_param = size_array[size_array_index];
        A_col_size = params.A_col_size_param = size_array[size_array_index];
        B_row_size = params.B_row_size_param = size_array[size_array_index];
        B_col_size = params.B_col_size_param = size_array[size_array_index];
        H = params.H_param;
        A_row_size_pad = A_row_size;
        // GET_PAD_SIZE(A_row_size_pad,A_row_size,H);
        GET_PAD_SIZE(A_col_size_pad,A_col_size,H);
        GET_PAD_SIZE(B_row_size_pad,B_row_size,H);
        GET_PAD_SIZE(B_col_size_pad,B_col_size,(W*2));
        params.A_row_size_pad_param = A_row_size_pad;
        params.A_col_size_pad_param = A_col_size_pad;
        params.B_row_size_pad_param = B_row_size_pad;
        params.B_col_size_pad_param = B_col_size_pad;
        params.A_col_blk_param  = A_col_blk ;
        params.B_col_blk_param  = B_col_blk ;
        params.C_col_blk_param  = C_col_blk ;
        params.NCHIP_param      = NCHIP     ;
        params.W_param          = W         ;
        IMAX_param_tunig(&params);

        // printf("LMM_usage_rate %2.2f LMM_usage_kbyte %2.1f sparse_rate %2.1f A_row_size %d A_col_size %d B_row_size %d B_col_size %d A_col_blk %d B_col_blk %d C_col_blk %d NCHIP %d W %d \n",

        PRINT_PARAM(params);
        Base_p  = (Uint*)((Uchar*)membase);
        A  = (Uint*)((Uchar*)Base_p);
        B  = (Uint*)((Uchar*)A  + 2*(A_row_size*(A_col_size_pad))*sizeof(Uint));
        C1 = (Uint*)((Uchar*)B  + (B_row_size_pad)*(B_col_size_pad)*sizeof(Uint)+8*sizeof(Uint)*sparse_rate_index);
        sort_index = (Uint*)((Uchar*)C1 + A_row_size*(B_col_size_pad)*sizeof(Uint));
        C0 = (Uint*)calloc(A_row_size*(B_col_size_pad),sizeof(Uint));
        
        C_debug = (Uint*)calloc(A_row_size*(B_col_size_pad),sizeof(Uint));
        B_debug = (Uint*)calloc((B_col_size_pad)*(B_row_size_pad),sizeof(Uint));
        // make A sparse matrix with sparsity percent
        coo = make_mat(&params,sparse_rate[sparse_rate_index],biased_percent[biased_percent_index]);
        // coo = make_mat(params,0.1);
        // make B dense matrix for simd calculation
        make_random_mat(&params,B,B_debug);

        if(coo == NULL){
            fprintf(stderr,"coo NULL \n");
        }

        reset_nanosec();
        A_sparse = sparse_format(coo->nnz,A,coo->val,coo->col_index,coo->row_index,A_row_size,A_col_size,&params,sort_index,"/home/takuya-s/IMAX_sparse.cent/sample/test/sparse_data.wb",0);
        get_nanosec(0);
        show_nanosec();
        reset_nanosec();

        reset_nanosec();
        sparse_gemm_CHIP_div_B(C1, A, B, A_sparse, &params);
        get_nanosec(0);
        show_nanosec();
        #if !defined(CSIMDEBUG)
        STORE_CSV(fp);
        #endif

// nanosec: ARM:154329 DRAIN:9835515 CONF:13903 REGV:14830345 RANGE:4417095 LOAD:159138651 EXEC:12162100 total:200551938
// nanosec: ARM:155206 DRAIN:9837535 CONF:13972 REGV:14814455 RANGE:4423073 LOAD:159105715 EXEC:16995296 total:205345252
// nanosec: ARM:181222 DRAIN:9854057 CONF:18311 REGV:18540761 RANGE:5497330 LOAD:178717371 EXEC:19210359 total:232019411
// nanosec: ARM:185999 DRAIN:9851571 CONF:18292 REGV:18529868 RANGE:5513430 LOAD:178676546 EXEC:7854506  total:220630212
        orig(coo->val,B_debug,C0,&params);

        for (col=0,col1=0; col<(B_col_size_pad)/2;col1+=2,col+=1){
            for (row=0,row1=0; row<2*A_row_size;row1+=1,row+=2) {
                count2++;
                #ifdef CSIMDEBUG
                printf("C in\n");
                #endif
                    *(float*)&C_debug[col1*A_row_size+row1] = *(float*)&C1[col*2*A_row_size+row];
                    *(float*)&C_debug[(col1+1)*A_row_size+row1] = *(float*)&C1[col*2*A_row_size+row+1];
                // printf("C1[%d][%d]=%f \n", row, col, (double)*(float*)&C1[col*A_row_size+row]);
            
            }
        }

        sum = 0;
        sum1 = 0;
        for (col=0; col<(B_col_size_pad); col+=1){
            for (row=0; row<A_row_size; row+=1) {
                sum += *(float*)&C0[col+row*(B_col_size_pad)];
                sum1 += *(float*)&C_debug[col*A_row_size+row];
                if (abs(*(float*)&C0[col*A_row_size+row] - *(float*)&C_debug[col*A_row_size+row])>1) {
                    count2++;

                    printf("C0[%d][%d]=%f C_debug[%d][%d]=%f\n", row, col, *(float*)&C0[col*A_row_size+row],
                                                        row, col, *(float*)&C_debug[col*A_row_size+row]);
                    exit(1);
                }
            }
        }
        #if !defined(ARMZYNQ) && defined(EMAX6)
        if(abs(sum-sum1)>1){
            printf("sum %f \n",sum);
            printf("sum1 %f \n",sum1);
        }
        #endif
        // memory clean
        free_sparse_mat(coo);
        free_sparse_format(A_sparse);

        if(B_debug != NULL){
        free(B_debug);
        B_debug = NULL;
        }
        if(C0 != NULL){
        free(C0);
        C0 = NULL;
        }
        if(C_debug != NULL){
        free(C_debug);
        C_debug = NULL;
        }
        mem_release(memsize,&membase);
    }

}
#if !defined(ARMZYNQ) && defined(EMAX6)
if(membase != NULL){
        free(membase);
        membase = NULL;
}
#endif
#if !defined(CSIMDEBUG)
fclose(fp);
#endif
} // main





