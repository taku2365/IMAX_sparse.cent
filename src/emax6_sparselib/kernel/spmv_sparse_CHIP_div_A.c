#ifndef NO_EMAX6LIB_BODY
#define NO_EMAX6LIB_BODY
#endif
#include "../Include/kernel_lib.h"

#if 1
void spmv_sparse_CHIP_div_A(Uint* C, const Uint* A, const Uint* B,emax6_sparse2* A_sparse,emax6_param* params) {
    // args: A IMAX_CSR_format
    // arg B fortran continues simd format
    // arg C fortran continues simd format
    // A_col_blk=2 スケジューリング方法を変更
    #undef sparse_core1_1
    #undef sparse_core2
    #undef sparse_core2_1
    #undef sparse_core3_1
    #undef sparse_core4
    #undef sparse_final1
    Ull  CHIP;
    Ull  LOOP1, LOOP0;
    Ull  INIT1, INIT0;
    Ull  AR[64][4];                     /* output of EX     in each unit */
    Ull  BR[64][4][4];                  /* output registers in each unit */
    Ull  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
    Ull  r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
    Ull x,y,z,t;
    Ull a00,a01,a02,a03,a04,a05,a06,a07,a08,a09,a010;


    Ull  cc0, cc1, cc2, cc3, ex0, ex1;
    Ull  cofs, rofs,a_rofs,b_rofs,c_rofs,oofs, k;
    // Ull A_row_size = M, A_col_size = K, B_row_size = K, B_col_size = N;
    // Uint* paddings = A_sparse->paddings;

    Uint top,blk,b_col_B_col_blk;
    Ull c_index,c_index1,c_index2,c_index3;
    Uint C_debug_val = 0,A_debug_val = 0,B_debug_val = 0;

    #define NCHIP 1
    size_t A_row_size = params->A_row_size_param;   // 縛りなし
    size_t A_col_size = params->A_col_size_param;   // 縛りなし　H_padのおかげ
    size_t B_row_size = params->B_row_size_param;    // 縛りなし
    size_t B_col_size = params->B_col_size_param;   // B_col_blk*NCHIP縛り
    size_t A_row_size_pad = params->A_row_size_pad_param;
    size_t A_col_size_pad = params->A_col_size_pad_param;
    size_t B_row_size_pad = params->B_row_size_pad_param;
    size_t B_col_size_pad = params->B_col_size_pad_param;
    Uint blk_iter,A_margin_tmp,blk_iter_tmp;
    Ull* A_margin = A_sparse->margin;
    Uint* val_index_set = A_sparse->val_index_set;
    // Uint* paddings = A_sparse->paddings;
    Uint A_col_blk_tmp;

    Uint* A_sort_index= A_sparse->sort_index;
    // #define B_col_blk 16
    size_t B_col_blk = params->B_col_blk_param;
    /*size_t NCHIP 4*/
    // size_t NCHIP = params->NCHIP_param;
    Uint W = params->W_param;
    Uint H  = params->H_param;
    // size_t A_col_blk = 1;
    size_t A_col_blk = params->A_col_blk_param;
    size_t A_row_size_mul_mul_A_col_blk = A_row_size_pad*A_col_blk;
    size_t A_row_size_mul_2_mul_A_col_blk = A_row_size_pad*2*A_col_blk;
    size_t A_row_size_mul_2_mul_A_col_blk1 = A_row_size_pad*2*A_col_blk;
    size_t A_row_size_mul_B_col_blk = A_row_size_pad*B_col_blk;
    size_t A_row_size_mul_4 = A_row_size_pad*4;
    size_t A_row_size_mul_8 = A_row_size_pad*8;
    size_t A_row_size_div2 = A_row_size_pad>>1;
    size_t cofs_init = (0-A_row_size_mul_8)<<32|((0-1*4LL)&0xffffffff);
    // 4(byte)*2(index+val)*2(W)
    size_t rofs_init = (0-4*2*2LL)<<32|((0-8LL)&0xffffffff);
    size_t A_row_size_mul_4_4 = (A_row_size_mul_4)<<32|(4LL&0xffffffff);
    size_t A_row_size_mul_8_4 = (A_row_size_mul_8)<<32|(4LL&0xffffffff);
    Ull Force,Force_reverse;
    Force = 1;
    // Force_reverse = ~Force;
    size_t B_col_blk_mul_B_row_size = B_col_blk*(B_row_size_pad);
    // size_t A_col_add_A_H_pad = A_col_size + A_H_pad;
    Uint *a[H],*a0_base[H],*a1_base[H],*a2_base[H],*a3_base[H],*a_index[H],*a_debug[H+1];
    Uint  *b, *b0[H], *b1[H], *b2[H], *b3[H];
    Uint  *c,*c0_debug;
    Uint  *c0, *c1, *c2, *c3;
    Uint  *A_sort_index1,*A_sort_index2;
    //(Uint *) 0x7ffff747fd84
    printf("IMAX\n");
    if(params->col_max>50){
        H = 58;
    }
    else if (params->col_max>=40 && params->col_max<50){
        H = 50;
    }
    else if (params->col_max>=30 && params->col_max<40){
        H = 40;
    }
    else if (params->col_max>=20 && params->col_max<30){
        H = 30;
    }
    else if (params->col_max>=10 && params->col_max<20){
        H = 20;
    }
    else if (params->col_max<10){
        H = 10;
    }
    else  {
        fprintf(stderr,"Thie pattern does not exist spmv_sparse_CHIP_div_A.c:%d ",__LINE__);
    }
    for (blk=0,blk_iter=0,A_col_blk_tmp=A_col_blk,A_row_size_mul_2_mul_A_col_blk = A_row_size_pad*2*A_col_blk; blk<A_col_size; blk+=A_col_blk*H,blk_iter+=A_col_blk) { /* 3重ループ展開の外側対象 */
        if ((A_margin_tmp=A_margin[blk_iter])==0) {break;}
        // A_col_blkずつとるが、最後のA_col_blkは余分な場合があるので減らす
        for (blk_iter_tmp=blk_iter;blk_iter_tmp<(blk_iter+A_col_blk);blk_iter_tmp++){

            if (((A_margin[blk_iter_tmp])==0)||(blk_iter_tmp*H>(A_col_size_pad))){
                A_row_size_mul_2_mul_A_col_blk -= A_row_size_pad*2;
                A_col_blk_tmp -= 1;
            }
        }
        if(A_col_blk_tmp == 0){break;}
        //制限つきで導入 
        // TODO サイズに関わらず適用する
        if((A_margin[blk_iter] < 500)&&(A_row_size_pad>2000)&&(A_col_blk == 1)&&(params->data_format == JDS_INDEX_VAL_SET_SPMV_FORMAT)){
            //マージンをA_rowの確保用として使用
            A_row_size_mul_2_mul_A_col_blk1 = A_margin[blk_iter];
            //A_rowはsimd単位なので2の倍数にする
            GET_PAD_SIZE(A_row_size_mul_2_mul_A_col_blk1,(A_row_size_mul_2_mul_A_col_blk1),2);
            //A_rowの実行回数 simd単位で進むので2で割る
            A_row_size_div2 = A_row_size_mul_2_mul_A_col_blk1>>1;
            //indexとvalをセットで確保するので掛ける2
            A_row_size_mul_2_mul_A_col_blk1 = A_row_size_mul_2_mul_A_col_blk1*2;
            A_col_blk_tmp = 1;
        }
        else{
            A_row_size_mul_2_mul_A_col_blk1 = A_row_size_mul_2_mul_A_col_blk;
        }

        b =  (Uint*)B;
        c  = (Uint*)C;
        c0 = (Uint*)C;
        c1 = (Uint*)C+1;
        c2 = (Uint*)C+2;
        c3 = (Uint*)C+3;
        A_sort_index1 = A_sort_index;
        A_sort_index2 = A_sort_index+1;


        for (k=0; k<H; k++) {
            //simdのために2の倍数
            // *2はindex+valがblk単位だから
            a[k]       = (Uint*)A+blk*A_row_size_pad*2+k*A_row_size_mul_2_mul_A_col_blk;
            a0_base[k] = (Uint*)A+blk*A_row_size_pad*2+k*A_row_size_mul_2_mul_A_col_blk;
            a1_base[k] = (Uint*)A+blk*A_row_size_pad*2+k*A_row_size_mul_2_mul_A_col_blk+2;
            a2_base[k] = (Uint*)A+blk*A_row_size_pad*2+k*A_row_size_mul_2_mul_A_col_blk+4;
            a3_base[k] = (Uint*)A+blk*A_row_size_pad*2+k*A_row_size_mul_2_mul_A_col_blk+6;
            b0[k] = (Uint*)B+blk+k*A_col_blk_tmp;
        }
    // c_indexはH1010なので上位32bitを獲得
    #define basecomponet()\
            exe(OP_ADD,    &rofs, INIT0?rofs:rofs, EXP_H3210, 4*2*2LL<<32|8LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);\
            exe(OP_ADD,    &cofs, cofs, EXP_H3210, INIT0?A_row_size_mul_8_4:0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\ 
            mop(OP_LDWR, 1, &c_index, (Ull)A_sort_index1, (Ull)rofs, MSK_W0, (Ull)A_sort_index, A_row_size_pad, 0, Force, (Ull)NULL, A_row_size_pad);\
            mop(OP_LDWR, 1, &c_index1, (Ull)A_sort_index2, (Ull)rofs, MSK_W0, (Ull)A_sort_index, A_row_size_pad, 0, Force, (Ull)NULL, A_row_size_pad);\
            exe(OP_ADD,    &a_rofs, rofs, EXP_H3232, cofs, EXP_H3232, 0LL, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);\            
            mop(OP_LDR,  3, &BR[2][0][1], (Ull)a0_base[0], (Ull)a_rofs, MSK_W0, (Ull)a[0], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1);\             
            mop(OP_LDR,  3, &BR[2][1][1], (Ull)a1_base[0], (Ull)a_rofs, MSK_W0, (Ull)a[0], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1);\             
            exe(OP_ADD,    &c_index2, (Ull)c_index, EXP_H1010, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);\            
            exe(OP_ADD,    &c_index3, (Ull)c_index1, EXP_H1010,0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);\            
            mop(OP_LDR,  3, &BR[3][0][1], (Ull)a0_base[1], (Ull)a_rofs, MSK_W0, (Ull)a[1], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1);\ 
            mop(OP_LDR,  3, &BR[3][1][1], (Ull)a1_base[1], (Ull)a_rofs, MSK_W0, (Ull)a[1], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1);\ 
            mop(OP_LDWR, 3, &BR[3][2][1], (Ull)b, BR[2][0][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL,B_col_blk_mul_B_row_size);\             
            mop(OP_LDWR, 3, &BR[3][3][1], (Ull)b, BR[2][1][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL,B_col_blk_mul_B_row_size);\             
            exe(OP_FML, &AR[4][0], BR[2][0][1], EXP_H1010, BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\ 
            exe(OP_FML, &AR[4][1], BR[2][1][1], EXP_H1010, BR[3][3][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\ 
            mop(OP_LDR, 3, &BR[4][0][1],  (Ull)a0_base[2],    (Ull)a_rofs, MSK_W0, (Ull)a[2], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1);\
            mop(OP_LDR, 3, &BR[4][1][1],  (Ull)a1_base[2],    (Ull)a_rofs, MSK_W0, (Ull)a[2], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1);\
            mop(OP_LDWR,3, &BR[4][2][1],  (Ull)b,      BR[3][0][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL, B_col_blk_mul_B_row_size);\
            mop(OP_LDWR,3, &BR[4][3][1],  (Ull)b,      BR[3][1][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL, B_col_blk_mul_B_row_size)\

    #define spaerse_core1_1(ar,ar_pre,br,br_pre,br_pre_pre,a_index,b_index) \
            exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210, BR[br_pre_pre][0][1], EXP_H1010, BR[br_pre][2][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); \
            exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210, BR[br_pre_pre][1][1], EXP_H1010, BR[br_pre][3][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); \
            mop(OP_LDR, 3, &BR[br][0][1],  (Ull)a0_base[a_index], (Ull)a_rofs,  MSK_W0, (Ull)a[a_index], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1); \
            mop(OP_LDR, 3, &BR[br][1][1],  (Ull)a1_base[a_index], (Ull)a_rofs,  MSK_W0, (Ull)a[a_index], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1); \
            mop(OP_LDWR,3, &BR[br][2][1],  (Ull)b,  BR[br_pre][0][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL, B_col_blk_mul_B_row_size); \
            mop(OP_LDWR,3, &BR[br][3][1],  (Ull)b,  BR[br_pre][1][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL, B_col_blk_mul_B_row_size)

    #define spaerse_core2_1(ar,ar_pre,br,br_pre,br_pre_pre,a_index,b_index) \
            exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210, BR[br_pre_pre][0][1], EXP_H1010, BR[br_pre][2][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); \
            exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210, BR[br_pre_pre][1][1], EXP_H1010, BR[br_pre][3][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); \
            mop(OP_LDWR,3, &BR[br][2][1],  (Ull)b,  BR[br_pre][0][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL, B_col_blk_mul_B_row_size); \
            mop(OP_LDWR,3, &BR[br][3][1],  (Ull)b,  BR[br_pre][1][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL, B_col_blk_mul_B_row_size)

    
    #define spaerse_core3_1(ar,ar_pre,br,br_pre,br_pre_pre,a_index,b_index) \
            exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210, BR[br_pre_pre][0][1], EXP_H1010, BR[br_pre][2][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); \
            exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210, BR[br_pre_pre][1][1], EXP_H1010, BR[br_pre][3][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL)


    #define sparse_final(r, rp1,index_val,index_val1) \
            mop(OP_LDWR,  1, &BR[rp1][0][1],  (Ull)c0, (Ull)index_val, MSK_W0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            mop(OP_LDWR,  1, &BR[rp1][1][1],  (Ull)c0, (Ull)index_val1, MSK_W0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            exe(OP_FAD, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[rp1][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FAD, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[rp1][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            mop(OP_STWR,  1, &AR[rp1][0],  (Ull)index_val, (Ull)c0, MSK_D0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            mop(OP_STWR,  1, &AR[rp1][1],  (Ull)index_val1, (Ull)c0, MSK_D0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk)



    #define sparse_core1_1_3_9()\
            spaerse_core1_1(5  ,4  ,5  ,4  ,3  ,3  ,2   );\
            spaerse_core1_1(6  ,5  ,6  ,5  ,4  ,4  ,3   );\
            spaerse_core1_1(7  ,6  ,7  ,6  ,5  ,5  ,4   );\
            spaerse_core1_1(8  ,7  ,8  ,7  ,6  ,6  ,5   );\
            spaerse_core1_1(9  ,8  ,9  ,8  ,7  ,7  ,6   );\
            spaerse_core1_1(10 ,9  ,10 ,9  ,8  ,8  ,7   );\
            spaerse_core1_1(11 ,10 ,11 ,10 ,9  ,9  ,8   )

    #define sparse_core1_1_10_19()\
            spaerse_core1_1(12 ,11 ,12 ,11 ,10 ,10 ,9   );\
            spaerse_core1_1(13 ,12 ,13 ,12 ,11 ,11 ,10  );\
            spaerse_core1_1(14 ,13 ,14 ,13 ,12 ,12 ,11  );\
            spaerse_core1_1(15 ,14 ,15 ,14 ,13 ,13 ,12  );\
            spaerse_core1_1(16 ,15 ,16 ,15 ,14 ,14 ,13  );\
            spaerse_core1_1(17 ,16 ,17 ,16 ,15 ,15 ,14  );\
            spaerse_core1_1(18 ,17 ,18 ,17 ,16 ,16 ,15  );\
            spaerse_core1_1(19 ,18 ,19 ,18 ,17 ,17 ,16  );\
            spaerse_core1_1(20 ,19 ,20 ,19 ,18 ,18 ,17  );\
            spaerse_core1_1(21 ,20 ,21 ,20 ,19 ,19 ,18  )
    
    #define sparse_core1_1_20_29()\
            spaerse_core1_1(22 ,21 ,22 ,21 ,20 ,20 ,19  );\
            spaerse_core1_1(23 ,22 ,23 ,22 ,21 ,21 ,20  );\
            spaerse_core1_1(24 ,23 ,24 ,23 ,22 ,22 ,21  );\
            spaerse_core1_1(25 ,24 ,25 ,24 ,23 ,23 ,22  );\
            spaerse_core1_1(26 ,25 ,26 ,25 ,24 ,24 ,23  );\
            spaerse_core1_1(27 ,26 ,27 ,26 ,25 ,25 ,24  );\
            spaerse_core1_1(28 ,27 ,28 ,27 ,26 ,26 ,25  );\
            spaerse_core1_1(29 ,28 ,29 ,28 ,27 ,27 ,26  );\
            spaerse_core1_1(30 ,29 ,30 ,29 ,28 ,28 ,27  );\
            spaerse_core1_1(31 ,30 ,31 ,30 ,29 ,29 ,28  )

    #define sparse_core1_1_30_39()\
            spaerse_core1_1(32 ,31 ,32 ,31 ,30 ,30 ,29  );\
            spaerse_core1_1(33 ,32 ,33 ,32 ,31 ,31 ,30  );\
            spaerse_core1_1(34 ,33 ,34 ,33 ,32 ,32 ,31  );\
            spaerse_core1_1(35 ,34 ,35 ,34 ,33 ,33 ,32  );\
            spaerse_core1_1(36 ,35 ,36 ,35 ,34 ,34 ,33  );\
            spaerse_core1_1(37 ,36 ,37 ,36 ,35 ,35 ,34  );\
            spaerse_core1_1(38 ,37 ,38 ,37 ,36 ,36 ,35  );\
            spaerse_core1_1(39 ,38 ,39 ,38 ,37 ,37 ,36  );\
            spaerse_core1_1(40 ,39 ,40 ,39 ,38 ,38 ,37  );\
            spaerse_core1_1(41 ,40 ,41 ,40 ,39 ,39 ,38  )

    #define sparse_core1_1_40_49()\
            spaerse_core1_1(42 ,41 ,42 ,41 ,40 ,40 ,39  );\
            spaerse_core1_1(43 ,42 ,43 ,42 ,41 ,41 ,40  );\
            spaerse_core1_1(44 ,43 ,44 ,43 ,42 ,42 ,41  );\
            spaerse_core1_1(45 ,44 ,45 ,44 ,43 ,43 ,42  );\
            spaerse_core1_1(46 ,45 ,46 ,45 ,44 ,44 ,43  );\
            spaerse_core1_1(47 ,46 ,47 ,46 ,45 ,45 ,44  );\
            spaerse_core1_1(48 ,47 ,48 ,47 ,46 ,46 ,45  );\
            spaerse_core1_1(49 ,48 ,49 ,48 ,47 ,47 ,46  );\
            spaerse_core1_1(50 ,49 ,50 ,49 ,48 ,48 ,47  );\
            spaerse_core1_1(51 ,50 ,51 ,50 ,49 ,49 ,48  )

    
    #define sparse_core1_1_50_57()\
            spaerse_core1_1(52 ,51 ,52 ,51 ,50 ,50 ,49  );\
            spaerse_core1_1(53 ,52 ,53 ,52 ,51 ,51 ,50  );\
            spaerse_core1_1(54 ,53 ,54 ,53 ,52 ,52 ,51  );\
            spaerse_core1_1(55 ,54 ,55 ,54 ,53 ,53 ,52  );\
            spaerse_core1_1(56 ,55 ,56 ,55 ,54 ,54 ,53  );\
            spaerse_core1_1(57 ,56 ,57 ,56 ,55 ,55 ,54  );\
            spaerse_core1_1(58 ,57 ,58 ,57 ,56 ,56 ,55  );\
            spaerse_core1_1(59 ,58 ,59 ,58 ,57 ,57 ,56  )



if(H>50){
//EMAX5A begin spmv1_58 mapdist=0
  for (CHIP=0; CHIP<NCHIP; CHIP++) { 
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   for (INIT1=1,LOOP1=A_col_blk_tmp,cofs=cofs_init; LOOP1--; INIT1=0) {      
     for (INIT0=1,LOOP0=A_row_size_div2,rofs=rofs_init; LOOP0--; INIT0=0) {  
            basecomponet();
            sparse_core1_1_3_9();
            sparse_core1_1_10_19();
            sparse_core1_1_20_29();
            sparse_core1_1_30_39();
            sparse_core1_1_40_49();
            sparse_core1_1_50_57();
            spaerse_core2_1(60 ,59 ,60 ,59 ,58 ,58 ,57  );

            spaerse_core3_1(61 ,60 ,61 ,60 ,59 ,59 ,58  );

            sparse_final(61,62,c_index2,c_index3);   
            }
        }
    }
//EMAX5A end
}
else if(H>40){
//EMAX5A begin spmv1_50 mapdist=0
  for (CHIP=0; CHIP<NCHIP; CHIP++) { 
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   for (INIT1=1,LOOP1=A_col_blk_tmp,cofs=cofs_init; LOOP1--; INIT1=0) {      
     for (INIT0=1,LOOP0=A_row_size_div2,rofs=rofs_init; LOOP0--; INIT0=0) {  
            basecomponet();
            sparse_core1_1_3_9();
            sparse_core1_1_10_19();
            sparse_core1_1_20_29();
            sparse_core1_1_30_39();
            sparse_core1_1_40_49();
            spaerse_core2_1(52 ,51 ,52 ,51 ,50 ,50 ,49  );
            spaerse_core3_1(53 ,52 ,53 ,52 ,51 ,51 ,50  );

            sparse_final(53,54,c_index2,c_index3);   
            }
        }
    }
//EMAX5A end
}
else if(H>30){
//EMAX5A begin spmv1_40 mapdist=0
  for (CHIP=0; CHIP<NCHIP; CHIP++) { 
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   for (INIT1=1,LOOP1=A_col_blk_tmp,cofs=cofs_init; LOOP1--; INIT1=0) {      
     for (INIT0=1,LOOP0=A_row_size_div2,rofs=rofs_init; LOOP0--; INIT0=0) {  
            basecomponet();
            sparse_core1_1_3_9();
            sparse_core1_1_10_19();
            sparse_core1_1_20_29();
            sparse_core1_1_30_39();
            spaerse_core2_1(42 ,41 ,42 ,41 ,40 ,40 ,39  );
            spaerse_core3_1(43 ,42 ,43 ,42 ,41 ,41 ,40  );

            sparse_final(43,44,c_index2,c_index3);   
            }
        }
    }
//EMAX5A end
}
else if(H>20){
//EMAX5A begin spmv1_30 mapdist=0
  for (CHIP=0; CHIP<NCHIP; CHIP++) { 
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   for (INIT1=1,LOOP1=A_col_blk_tmp,cofs=cofs_init; LOOP1--; INIT1=0) {      
     for (INIT0=1,LOOP0=A_row_size_div2,rofs=rofs_init; LOOP0--; INIT0=0) {  
            basecomponet();
            sparse_core1_1_3_9();
            sparse_core1_1_10_19();
            sparse_core1_1_20_29();
            spaerse_core2_1(32 ,31 ,32 ,31 ,30 ,30 ,29  );
            spaerse_core3_1(33 ,32 ,33 ,32 ,31 ,31 ,30  );

            sparse_final(33,34,c_index2,c_index3);   
            }
        }
    }
//EMAX5A end
}
else if(H>10){
//EMAX5A begin spmv1_20 mapdist=0
  for (CHIP=0; CHIP<NCHIP; CHIP++) { 
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   for (INIT1=1,LOOP1=A_col_blk_tmp,cofs=cofs_init; LOOP1--; INIT1=0) {      
     for (INIT0=1,LOOP0=A_row_size_div2,rofs=rofs_init; LOOP0--; INIT0=0) {  
            basecomponet();
            sparse_core1_1_3_9();
            sparse_core1_1_10_19();
            spaerse_core2_1(22 ,21 ,22 ,21 ,20 ,20 ,19  );
            spaerse_core3_1(23 ,22 ,23 ,22 ,21 ,21 ,20  );

            sparse_final(23,24,c_index2,c_index3);   
            }
        }
    }
//EMAX5A end
}
else{
//EMAX5A begin spmv1_10 mapdist=0
  for (CHIP=0; CHIP<NCHIP; CHIP++) { 
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   for (INIT1=1,LOOP1=A_col_blk_tmp,cofs=cofs_init; LOOP1--; INIT1=0) {      
     for (INIT0=1,LOOP0=A_row_size_div2,rofs=rofs_init; LOOP0--; INIT0=0) {  
            basecomponet();
            sparse_core1_1_3_9();
            spaerse_core2_1(12 ,11 ,12 ,11 ,10 ,10 ,9   );
            spaerse_core3_1(13 ,12 ,13 ,12 ,11 ,11 ,10  );
            sparse_final(13,14,c_index2,c_index3);


              
              }
            }
          }
//EMAX5A end
}
if (Force) Force = 0;

    }
//EMAX5A drain_dirty_lmm
}
#endif



#if 0
void spmv_sparse_CHIP_div_A(Uint* C, const Uint* A, const Uint* B,emax6_sparse2* A_sparse,emax6_param* params) {
    // args: A IMAX_CSR_format
    // arg B fortran continues simd format
    // arg C fortran continues simd format
    // A_col_blk=2 スケジューリング方法を変更
    #undef sparse_core1_1
    #undef sparse_core2
    #undef sparse_core2_1
    #undef sparse_core3_1
    #undef sparse_core4
    #undef sparse_final1
    Ull  CHIP;
    Ull  LOOP1, LOOP0;
    Ull  INIT1, INIT0;
    Ull  AR[64][4];                     /* output of EX     in each unit */
    Ull  BR[64][4][4];                  /* output registers in each unit */
    Ull  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
    Ull  r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
    Ull x,y,z,t;
    Ull a00,a01,a02,a03,a04,a05,a06,a07,a08,a09,a010;


    Ull  cc0, cc1, cc2, cc3, ex0, ex1;
    Ull  cofs, rofs,a_rofs,b_rofs,c_rofs,oofs, k;
    // Ull A_row_size = M, A_col_size = K, B_row_size = K, B_col_size = N;
    // Uint* paddings = A_sparse->paddings;

    Uint top,blk,b_col_B_col_blk;
    Ull c_index,c_index1,c_index2,c_index3;
    Uint C_debug_val = 0,A_debug_val = 0,B_debug_val = 0;

    #define NCHIP 1
    size_t A_row_size = params->A_row_size_param;   // 縛りなし
    size_t A_col_size = params->A_col_size_param;   // 縛りなし　H_padのおかげ
    size_t B_row_size = params->B_row_size_param;    // 縛りなし
    size_t B_col_size = params->B_col_size_param;   // B_col_blk*NCHIP縛り
    size_t A_row_size_pad = params->A_row_size_pad_param;
    size_t A_col_size_pad = params->A_col_size_pad_param;
    size_t B_row_size_pad = params->B_row_size_pad_param;
    size_t B_col_size_pad = params->B_col_size_pad_param;
    Uint blk_iter,A_margin_tmp,blk_iter_tmp;
    Ull* A_margin = A_sparse->margin;
    Uint* val_index_set = A_sparse->val_index_set;
    // Uint* paddings = A_sparse->paddings;
    Uint A_col_blk_tmp;

    Uint* A_sort_index= A_sparse->sort_index;
    // #define B_col_blk 16
    size_t B_col_blk = params->B_col_blk_param;
    /*size_t NCHIP 4*/
    // size_t NCHIP = params->NCHIP_param;
    Uint W = params->W_param;
    Uint H  = params->H_param;
    // size_t A_col_blk = 1;
    size_t A_col_blk = params->A_col_blk_param;
    size_t A_row_size_mul_mul_A_col_blk = A_row_size_pad*A_col_blk;
    size_t A_row_size_mul_2_mul_A_col_blk = A_row_size_pad*2*A_col_blk;
    size_t A_row_size_mul_2_mul_A_col_blk1 = A_row_size_pad*2*A_col_blk;
    size_t A_row_size_mul_B_col_blk = A_row_size_pad*B_col_blk;
    size_t A_row_size_mul_4 = A_row_size_pad*4;
    size_t A_row_size_mul_8 = A_row_size_pad*8;
    size_t A_row_size_div2 = A_row_size_pad>>1;
    size_t cofs_init = (0-A_row_size_mul_8)<<32|((0-1*4LL)&0xffffffff);
    // 4(byte)*2(index+val)*2(W)
    size_t rofs_init = (0-4*2*2LL)<<32|((0-8LL)&0xffffffff);
    size_t A_row_size_mul_4_4 = (A_row_size_mul_4)<<32|(4LL&0xffffffff);
    size_t A_row_size_mul_8_4 = (A_row_size_mul_8)<<32|(4LL&0xffffffff);
    Ull Force,Force_reverse;
    Force = 1;
    // Force_reverse = ~Force;
    size_t B_col_blk_mul_B_row_size = B_col_blk*(B_row_size_pad);
    // size_t A_col_add_A_H_pad = A_col_size + A_H_pad;
    Uint *a[H],*a0_base[H],*a1_base[H],*a2_base[H],*a3_base[H],*a_index[H],*a_debug[H+1];
    Uint  *b, *b0[H], *b1[H], *b2[H], *b3[H];
    Uint  *c,*c0_debug;
    Uint  *c0, *c1, *c2, *c3;
    Uint  *A_sort_index1,*A_sort_index2;
    //(Uint *) 0x7ffff747fd84
    printf("IMAX\n");
    // if(params->col_max>50){
    //     H = 58;
    // }
    // else if (params->col_max>=40 && params->col_max<50){
    //     H = 50;
    // }
    // else if (params->col_max>=30 && params->col_max<40){
    //     H = 40;
    // }
    // else if (params->col_max>=20 && params->col_max<30){
    //     H = 30;
    // }
    // else if (params->col_max>=10 && params->col_max<20){
    //     H = 20;
    // }
    // else if (params->col_max<10){
    //     H = 10;
    // }
    // else  {
    //     fprintf(stderr,"Thie pattern does not exist spmv_sparse_CHIP_div_A.c:%d ",__LINE__);
    // }
    for (blk=0,blk_iter=0,A_col_blk_tmp=A_col_blk,A_row_size_mul_2_mul_A_col_blk = A_row_size_pad*2*A_col_blk; blk<A_col_size; blk+=A_col_blk*H,blk_iter+=A_col_blk) { /* 3重ループ展開の外側対象 */
        if ((A_margin_tmp=A_margin[blk_iter])==0) {break;}
        // A_col_blkずつとるが、最後のA_col_blkは余分な場合があるので減らす
        for (blk_iter_tmp=blk_iter;blk_iter_tmp<(blk_iter+A_col_blk);blk_iter_tmp++){

            if (((A_margin[blk_iter_tmp])==0)||(blk_iter_tmp*H>(A_col_size_pad))){
                A_row_size_mul_2_mul_A_col_blk -= A_row_size_pad*2;
                A_col_blk_tmp -= 1;
            }
        }
        if(A_col_blk_tmp == 0){break;}
        //制限つきで導入 
        // TODO サイズに関わらず適用する
        if((A_margin[blk_iter] < 500)&&(A_row_size_pad>2000)&&(A_col_blk == 1)&&(params->data_format == JDS_INDEX_VAL_SET_SPMV_FORMAT)){
            //マージンをA_rowの確保用として使用
            A_row_size_mul_2_mul_A_col_blk1 = A_margin[blk_iter];
            //A_rowはsimd単位なので2の倍数にする
            GET_PAD_SIZE(A_row_size_mul_2_mul_A_col_blk1,(A_row_size_mul_2_mul_A_col_blk1),2);
            //A_rowの実行回数 simd単位で進むので2で割る
            A_row_size_div2 = A_row_size_mul_2_mul_A_col_blk1>>1;
            //indexとvalをセットで確保するので掛ける2
            A_row_size_mul_2_mul_A_col_blk1 = A_row_size_mul_2_mul_A_col_blk1*2;
            A_col_blk_tmp = 1;
        }
        else{
            A_row_size_mul_2_mul_A_col_blk1 = A_row_size_mul_2_mul_A_col_blk;
        }

        b =  (Uint*)B;
        c  = (Uint*)C;
        c0 = (Uint*)C;
        c1 = (Uint*)C+1;
        c2 = (Uint*)C+2;
        c3 = (Uint*)C+3;
        A_sort_index1 = A_sort_index;
        A_sort_index2 = A_sort_index+1;


        for (k=0; k<H; k++) {
            //simdのために2の倍数
            // *2はindex+valがblk単位だから
            a[k]       = (Uint*)A+blk*A_row_size_pad*2+k*A_row_size_mul_2_mul_A_col_blk;
            a0_base[k] = (Uint*)A+blk*A_row_size_pad*2+k*A_row_size_mul_2_mul_A_col_blk;
            a1_base[k] = (Uint*)A+blk*A_row_size_pad*2+k*A_row_size_mul_2_mul_A_col_blk+2;
            a2_base[k] = (Uint*)A+blk*A_row_size_pad*2+k*A_row_size_mul_2_mul_A_col_blk+4;
            a3_base[k] = (Uint*)A+blk*A_row_size_pad*2+k*A_row_size_mul_2_mul_A_col_blk+6;
            b0[k] = (Uint*)B+blk+k*A_col_blk_tmp;
        }



    #define spaerse_core1_1(ar,ar_pre,br,br_pre,br_pre_pre,a_index,b_index) \
            exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210, BR[br_pre_pre][0][1], EXP_H1010, BR[br_pre][2][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); \
            exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210, BR[br_pre_pre][1][1], EXP_H1010, BR[br_pre][3][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); \
            mop(OP_LDR, 3, &BR[br][0][1],  (Ull)a0_base[a_index], (Ull)a_rofs,  MSK_W0, (Ull)a[a_index], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1); \
            mop(OP_LDR, 3, &BR[br][1][1],  (Ull)a1_base[a_index], (Ull)a_rofs,  MSK_W0, (Ull)a[a_index], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1); \
            mop(OP_LDWR,3, &BR[br][2][1],  (Ull)b,  BR[br_pre][0][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL, B_col_blk_mul_B_row_size); \
            mop(OP_LDWR,3, &BR[br][3][1],  (Ull)b,  BR[br_pre][1][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL, B_col_blk_mul_B_row_size)

    #define spaerse_core2_1(ar,ar_pre,br,br_pre,br_pre_pre,a_index,b_index) \
            exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210, BR[br_pre_pre][0][1], EXP_H1010, BR[br_pre][2][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); \
            exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210, BR[br_pre_pre][1][1], EXP_H1010, BR[br_pre][3][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); \
            mop(OP_LDWR,3, &BR[br][2][1],  (Ull)b,  BR[br_pre][0][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL, B_col_blk_mul_B_row_size); \
            mop(OP_LDWR,3, &BR[br][3][1],  (Ull)b,  BR[br_pre][1][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL, B_col_blk_mul_B_row_size)

    
    #define spaerse_core3_1(ar,ar_pre,br,br_pre,br_pre_pre,a_index,b_index) \
            exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210, BR[br_pre_pre][0][1], EXP_H1010, BR[br_pre][2][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); \
            exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210, BR[br_pre_pre][1][1], EXP_H1010, BR[br_pre][3][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL)


    #define sparse_final(r, rp1,index_val,index_val1) \
            mop(OP_LDWR,  1, &BR[rp1][0][1],  (Ull)c0, (Ull)index_val, MSK_W0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            mop(OP_LDWR,  1, &BR[rp1][1][1],  (Ull)c0, (Ull)index_val1, MSK_W0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            exe(OP_FAD, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[rp1][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FAD, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[rp1][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            mop(OP_STWR,  1, &AR[rp1][0],  (Ull)index_val, (Ull)c0, MSK_D0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            mop(OP_STWR,  1, &AR[rp1][1],  (Ull)index_val1, (Ull)c0, MSK_D0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk)


//EMAX5A begin spmv1 mapdist=0
/*3*/  for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   /*1*/ for (INIT1=1,LOOP1=A_col_blk_tmp,cofs=cofs_init; LOOP1--; INIT1=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
  /*2*/    for (INIT0=1,LOOP0=A_row_size_div2,rofs=rofs_init; LOOP0--; INIT0=0) {  /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
            exe(OP_ADD,    &rofs, INIT0?rofs:rofs, EXP_H3210, 4*2*2LL<<32|8LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */ //1*8LL<<32|1*4LLとしてはいけない!!!!
            exe(OP_ADD,    &cofs, cofs, EXP_H3210, INIT0?A_row_size_mul_8_4:0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */
            mop(OP_LDWR, 1, &c_index, (Ull)A_sort_index1, (Ull)rofs, MSK_W0, (Ull)A_sort_index, A_row_size_pad, 0, Force, (Ull)NULL, A_row_size_pad);
            mop(OP_LDWR, 1, &c_index1, (Ull)A_sort_index2, (Ull)rofs, MSK_W0, (Ull)A_sort_index, A_row_size_pad, 0, Force, (Ull)NULL, A_row_size_pad);
            exe(OP_ADD,    &a_rofs, rofs, EXP_H3232, cofs, EXP_H3232, 0LL, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);            
            // exe(OP_ADD,    &c_rofs, rofs, EXP_H1010, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);                        
            mop(OP_LDR,  3, &BR[2][0][1], (Ull)a0_base[0], (Ull)a_rofs, MSK_W0, (Ull)a[0], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1);             
            mop(OP_LDR,  3, &BR[2][1][1], (Ull)a1_base[0], (Ull)a_rofs, MSK_W0, (Ull)a[0], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1);             
            exe(OP_ADD,    &c_index2, (Ull)c_index, EXP_H1010, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);            
            exe(OP_ADD,    &c_index3, (Ull)c_index1, EXP_H1010,0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);            
            mop(OP_LDR,  3, &BR[3][0][1], (Ull)a0_base[1], (Ull)a_rofs, MSK_W0, (Ull)a[1], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1); 
            mop(OP_LDR,  3, &BR[3][1][1], (Ull)a1_base[1], (Ull)a_rofs, MSK_W0, (Ull)a[1], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1); 
            mop(OP_LDWR, 3, &BR[3][2][1], (Ull)b, BR[2][0][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL,B_col_blk_mul_B_row_size);             
            mop(OP_LDWR, 3, &BR[3][3][1], (Ull)b, BR[2][1][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL,B_col_blk_mul_B_row_size);             

            exe(OP_FML, &AR[4][0], BR[2][0][1], EXP_H1010, BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); 
            exe(OP_FML, &AR[4][1], BR[2][1][1], EXP_H1010, BR[3][3][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); 
            mop(OP_LDR, 3, &BR[4][0][1],  (Ull)a0_base[2],    (Ull)a_rofs, MSK_W0, (Ull)a[2], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1);
            mop(OP_LDR, 3, &BR[4][1][1],  (Ull)a1_base[2],    (Ull)a_rofs, MSK_W0, (Ull)a[2], A_row_size_mul_2_mul_A_col_blk1, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk1);
            mop(OP_LDWR,3, &BR[4][2][1],  (Ull)b,      BR[3][0][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL, B_col_blk_mul_B_row_size);
            mop(OP_LDWR,3, &BR[4][3][1],  (Ull)b,      BR[3][1][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL, B_col_blk_mul_B_row_size);

            spaerse_core1_1(5  ,4  ,5  ,4  ,3  ,3  ,2   );
            spaerse_core1_1(6  ,5  ,6  ,5  ,4  ,4  ,3   );
            spaerse_core1_1(7  ,6  ,7  ,6  ,5  ,5  ,4   );
            spaerse_core1_1(8  ,7  ,8  ,7  ,6  ,6  ,5   );
            spaerse_core1_1(9  ,8  ,9  ,8  ,7  ,7  ,6   );
            spaerse_core1_1(10 ,9  ,10 ,9  ,8  ,8  ,7   );
            spaerse_core1_1(11 ,10 ,11 ,10 ,9  ,9  ,8   );
            spaerse_core1_1(12 ,11 ,12 ,11 ,10 ,10 ,9   );
            spaerse_core1_1(13 ,12 ,13 ,12 ,11 ,11 ,10  );
            spaerse_core1_1(14 ,13 ,14 ,13 ,12 ,12 ,11  );
            spaerse_core1_1(15 ,14 ,15 ,14 ,13 ,13 ,12  );
            spaerse_core1_1(16 ,15 ,16 ,15 ,14 ,14 ,13  );
            spaerse_core1_1(17 ,16 ,17 ,16 ,15 ,15 ,14  );
            spaerse_core1_1(18 ,17 ,18 ,17 ,16 ,16 ,15  );
            spaerse_core1_1(19 ,18 ,19 ,18 ,17 ,17 ,16  );
            spaerse_core1_1(20 ,19 ,20 ,19 ,18 ,18 ,17  );
            spaerse_core1_1(21 ,20 ,21 ,20 ,19 ,19 ,18  );
            spaerse_core1_1(22 ,21 ,22 ,21 ,20 ,20 ,19  );
            spaerse_core1_1(23 ,22 ,23 ,22 ,21 ,21 ,20  );
            spaerse_core1_1(24 ,23 ,24 ,23 ,22 ,22 ,21  );
            spaerse_core1_1(25 ,24 ,25 ,24 ,23 ,23 ,22  );
            spaerse_core1_1(26 ,25 ,26 ,25 ,24 ,24 ,23  );
            spaerse_core1_1(27 ,26 ,27 ,26 ,25 ,25 ,24  );
            spaerse_core1_1(28 ,27 ,28 ,27 ,26 ,26 ,25  );
            spaerse_core1_1(29 ,28 ,29 ,28 ,27 ,27 ,26  );
            spaerse_core1_1(30 ,29 ,30 ,29 ,28 ,28 ,27  );
            spaerse_core1_1(31 ,30 ,31 ,30 ,29 ,29 ,28  );
            spaerse_core1_1(32 ,31 ,32 ,31 ,30 ,30 ,29  );
            spaerse_core1_1(33 ,32 ,33 ,32 ,31 ,31 ,30  );
            spaerse_core1_1(34 ,33 ,34 ,33 ,32 ,32 ,31  );
            spaerse_core1_1(35 ,34 ,35 ,34 ,33 ,33 ,32  );
            spaerse_core1_1(36 ,35 ,36 ,35 ,34 ,34 ,33  );
            spaerse_core1_1(37 ,36 ,37 ,36 ,35 ,35 ,34  );
            spaerse_core1_1(38 ,37 ,38 ,37 ,36 ,36 ,35  );
            spaerse_core1_1(39 ,38 ,39 ,38 ,37 ,37 ,36  );
            spaerse_core1_1(40 ,39 ,40 ,39 ,38 ,38 ,37  );
            spaerse_core1_1(41 ,40 ,41 ,40 ,39 ,39 ,38  );
            spaerse_core1_1(42 ,41 ,42 ,41 ,40 ,40 ,39  );
            spaerse_core1_1(43 ,42 ,43 ,42 ,41 ,41 ,40  );
            spaerse_core1_1(44 ,43 ,44 ,43 ,42 ,42 ,41  );
            spaerse_core1_1(45 ,44 ,45 ,44 ,43 ,43 ,42  );
            spaerse_core1_1(46 ,45 ,46 ,45 ,44 ,44 ,43  );
            spaerse_core1_1(47 ,46 ,47 ,46 ,45 ,45 ,44  );
            spaerse_core1_1(48 ,47 ,48 ,47 ,46 ,46 ,45  );
            spaerse_core1_1(49 ,48 ,49 ,48 ,47 ,47 ,46  );
            spaerse_core1_1(50 ,49 ,50 ,49 ,48 ,48 ,47  );
            spaerse_core1_1(51 ,50 ,51 ,50 ,49 ,49 ,48  );
            spaerse_core1_1(52 ,51 ,52 ,51 ,50 ,50 ,49  );
            spaerse_core1_1(53 ,52 ,53 ,52 ,51 ,51 ,50  );
            spaerse_core1_1(54 ,53 ,54 ,53 ,52 ,52 ,51  );
            spaerse_core1_1(55 ,54 ,55 ,54 ,53 ,53 ,52  );
            spaerse_core1_1(56 ,55 ,56 ,55 ,54 ,54 ,53  );
            spaerse_core1_1(57 ,56 ,57 ,56 ,55 ,55 ,54  );
            spaerse_core1_1(58 ,57 ,58 ,57 ,56 ,56 ,55  );
            spaerse_core1_1(59 ,58 ,59 ,58 ,57 ,57 ,56  );

            spaerse_core2_1(60 ,59 ,60 ,59 ,58 ,58 ,57  );

            spaerse_core3_1(61 ,60 ,61 ,60 ,59 ,59 ,58  );

            sparse_final(61,62,c_index2,c_index3);


              
              }
            }
          }
//EMAX5A end
if (Force) Force = 0;

    }
//EMAX5A drain_dirty_lmm
}

#endif