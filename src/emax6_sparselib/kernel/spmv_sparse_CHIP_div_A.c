#ifndef NO_EMAX6LIB_BODY
#define NO_EMAX6LIB_BODY
#endif
#include "../Include/kernel_lib.h"

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
    Ull a011,a012,a013,a014,a015,a016,a017,a018,a019,a020;
    Ull a021,a022,a023,a024,a025,a026,a027,a028,a029,a030;
    Ull a031,a032,a033,a034,a035,a036,a037,a038,a039,a040;
    Ull a041,a042,a043,a044,a045,a046,a047,a048,a049,a050;
    Ull a051,a052,a053,a054,a055,a056,a057,a058,a059,a060;

    Ull a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a110;
    Ull a111,a112,a113,a114,a115,a116,a117,a118,a119,a120;
    Ull a121,a122,a123,a124,a125,a126,a127,a128,a129,a130;
    Ull a131,a132,a133,a134,a135,a136,a137,a138,a139,a140;
    Ull a141,a142,a143,a144,a145,a146,a147,a148,a149,a150;
    Ull a151,a152,a153,a154,a155,a156,a157,a158,a159,a160;

    Ull a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a210;
    Ull a211,a212,a213,a214,a215,a216,a217,a218,a219,a220;
    Ull a221,a222,a223,a224,a225,a226,a227,a228,a229,a230;
    Ull a231,a232,a233,a234,a235,a236,a237,a238,a239,a240;
    Ull a241,a242,a243,a244,a245,a246,a247,a248,a249,a250;
    Ull a251,a252,a253,a254,a255,a256,a257,a258,a259,a260;

    Ull a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a310;
    Ull a311,a312,a313,a314,a315,a316,a317,a318,a319,a320;
    Ull a321,a322,a323,a324,a325,a326,a327,a328,a329,a330;
    Ull a331,a332,a333,a334,a335,a336,a337,a338,a339,a340;
    Ull a341,a342,a343,a344,a345,a346,a347,a348,a349,a350;
    Ull a351,a352,a353,a354,a355,a356,a357,a358,a359,a360;

    Ull b00,b01,b02,b03,b04,b05,b06,b07,b08,b09,b010;
    Ull b011,b012,b013,b014,b015,b016,b017,b018,b019,b020;
    Ull b021,b022,b023,b024,b025,b026,b027,b028,b029,b030;
    Ull b031,b032,b033,b034,b035,b036,b037,b038,b039,b040;
    Ull b041,b042,b043,b044,b045,b046,b047,b048,b049,b050;
    Ull b051,b052,b053,b054,b055,b056,b057,b058,b059,b060;

    Ull b10,b11,b12,b13,b14,b15,b16,b17,b18,b19,b110;
    Ull b111,b112,b113,b114,b115,b116,b117,b118,b119,b120;
    Ull b121,b122,b123,b124,b125,b126,b127,b128,b129,b130;
    Ull b131,b132,b133,b134,b135,b136,b137,b138,b139,b140;
    Ull b141,b142,b143,b144,b145,b146,b147,b148,b149,b150;
    Ull b151,b152,b153,b154,b155,b156,b157,b158,b159,b160;

    Ull b20,b21,b22,b23,b24,b25,b26,b27,b28,b29,b210;
    Ull b211,b212,b213,b214,b215,b216,b217,b218,b219,b220;
    Ull b221,b222,b223,b224,b225,b226,b227,b228,b229,b230;
    Ull b231,b232,b233,b234,b235,b236,b237,b238,b239,b240;
    Ull b241,b242,b243,b244,b245,b246,b247,b248,b249,b250;
    Ull b251,b252,b253,b254,b255,b256,b257,b258,b259,b260;

    Ull b30,b31,b32,b33,b34,b35,b36,b37,b38,b39,b310;
    Ull b311,b312,b313,b314,b315,b316,b317,b318,b319,b320;
    Ull b321,b322,b323,b324,b325,b326,b327,b328,b329,b330;
    Ull b331,b332,b333,b334,b335,b336,b337,b338,b339,b340;
    Ull b341,b342,b343,b344,b345,b346,b347,b348,b349,b350;
    Ull b351,b352,b353,b354,b355,b356,b357,b358,b359,b360;


    Ull  cc0, cc1, cc2, cc3, ex0, ex1;
    Ull  cofs, rofs,a_rofs,b_rofs,c_rofs,oofs, k;
    // Ull A_row_size = M, A_col_size = K, B_row_size = K, B_col_size = N;
    // Uint* paddings = A_sparse->paddings;

    Uint top,blk,b_col_B_col_blk;
    Ull c_index,c_index1;
    Uint C_debug_val = 0,A_debug_val = 0,B_debug_val = 0;

    #define NCHIP 1
    Sll A_row_size = params->A_row_size_param;   // 縛りなし
    Sll A_col_size = params->A_col_size_param;   // 縛りなし　H_padのおかげ
    Sll B_row_size = params->B_row_size_param;    // 縛りなし
    Sll B_col_size = params->B_col_size_param;   // B_col_blk*NCHIP縛り
    Sll A_row_size_pad = params->A_row_size_pad_param;
    Sll A_col_size_pad = params->A_col_size_pad_param;
    Sll B_row_size_pad = params->B_row_size_pad_param;
    Sll B_col_size_pad = params->B_col_size_pad_param;
    Uint blk_iter,A_margin_tmp,blk_iter_tmp;
    Ull* A_margin = A_sparse->margin;
    Uint* val_index_set = A_sparse->val_index_set;
    // Uint* paddings = A_sparse->paddings;
    Uint A_col_blk_tmp;

    Uint* A_sort_index= A_sparse->sort_index;
    // #define B_col_blk 16
    Sll B_col_blk = params->B_col_blk_param;
    /*Sll NCHIP 4*/
    // Sll NCHIP = params->NCHIP_param;
    Sll W  = params->W_param;
    Sll H  = params->H_param;
    // Sll A_col_blk = 1;
    Sll A_col_blk = params->A_col_blk_param;
    Sll A_row_size_mul_mul_A_col_blk = A_row_size_pad*A_col_blk;
    Sll A_row_size_mul_2_mul_A_col_blk = A_row_size_pad*2*A_col_blk;
    Sll A_row_size_mul_B_col_blk = A_row_size_pad*B_col_blk;
    Sll A_row_size_mul_4 = A_row_size_pad*4;
    Sll A_row_size_mul_8 = A_row_size_pad*8;
    Sll A_row_size_div2 = A_row_size_pad>>1;
    Sll cofs_init = (0-A_row_size_mul_8)<<32|((0-1*4LL)&0xffffffff);
    // 4(byte)*2(index+val)*2(W)
    Sll rofs_init = (0-4*2*2LL)<<32|((0-4LL)&0xffffffff);
    Sll A_row_size_mul_4_4 = (A_row_size_mul_4)<<32|(4LL&0xffffffff);
    Sll A_row_size_mul_8_4 = (A_row_size_mul_8)<<32|(4LL&0xffffffff);
    Ull Force,Force_reverse;
    Force = 1;
    // Force_reverse = ~Force;
    Sll B_col_blk_mul_B_row_size = B_col_blk*(B_row_size_pad);
    // Sll A_col_add_A_H_pad = A_col_size + A_H_pad;
    Uint *a[H],*a0_base[H],*a1_base[H],*a2_base[H],*a3_base[H],*a_index[H],*a_debug[H+1];
    Uint  *b, *b0[H], *b1[H], *b2[H], *b3[H];
    Uint  *c,*c0_debug;
    Uint  *c0, *c1, *c2, *c3;
    //(Uint *) 0x7ffff747fd84
    printf("IMAX\n");
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

        b =  (Uint*)B;
        c  = (Uint*)C;
        c0 = (Uint*)C;
        c1 = (Uint*)C+1;
        c2 = (Uint*)C+2;
        c3 = (Uint*)C+3;


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
            mop(OP_LDR, 3, &BR[br][0][1],  (Ull)a0_base[a_index], (Ull)a_rofs,  MSK_W0, (Ull)a[a_index], A_row_size_mul_2_mul_A_col_blk, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk); \
            mop(OP_LDR, 3, &BR[br][1][1],  (Ull)a1_base[a_index], (Ull)a_rofs,  MSK_W0, (Ull)a[a_index], A_row_size_mul_2_mul_A_col_blk, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk); \
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


    #define sparse_final(r, rp1,index_val) \
            mop(OP_LDWR,  1, &BR[rp1][0][1],  (Ull)c0, (Ull)index_val, MSK_W0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            mop(OP_LDWR,  1, &BR[rp1][1][1],  (Ull)c1, (Ull)index_val, MSK_W0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            exe(OP_FAD, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[rp1][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FAD, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[rp1][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            mop(OP_STWR,  1, &AR[rp1][0],  (Ull)index_val, (Ull)c0, MSK_D0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            mop(OP_STWR,  1, &AR[rp1][1],  (Ull)index_val, (Ull)c1, MSK_D0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk)


//EMAX5A begin spmv1 mapdist=0
/*3*/  for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   /*1*/ for (INIT1=1,LOOP1=A_col_blk_tmp,cofs=cofs_init; LOOP1--; INIT1=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
  /*2*/    for (INIT0=1,LOOP0=A_row_size_div2,rofs=rofs_init; LOOP0--; INIT0=0) {  /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
            exe(OP_ADD,    &rofs, INIT0?rofs:rofs, EXP_H3210, 4*2*2LL<<32|4LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */ //1*8LL<<32|1*4LLとしてはいけない!!!!
            exe(OP_ADD,    &cofs, cofs, EXP_H3210, INIT0?A_row_size_mul_8_4:0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */
            mop(OP_LDWR, 1, &c_index, (Ull)A_sort_index, (Ull)rofs, MSK_W0, (Ull)A_sort_index, A_row_size, 0, Force, (Ull)NULL, A_row_size);
            exe(OP_ADD,    &a_rofs, rofs, EXP_H3232, cofs, EXP_H3232, 0LL, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);            /* stage#1 */
            // exe(OP_ADD,    &c_rofs, rofs, EXP_H1010, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);            /* stage#1 */            
            mop(OP_LDR,  3, &BR[2][0][1], (Ull)a0_base[0], (Ull)a_rofs, MSK_W0, (Ull)a[0], A_row_size_mul_2_mul_A_col_blk, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk);             /* stage#1 */
            mop(OP_LDR,  3, &BR[2][1][1], (Ull)a1_base[0], (Ull)a_rofs, MSK_W0, (Ull)a[0], A_row_size_mul_2_mul_A_col_blk, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk);             /* stage#1 */
            exe(OP_ADD,    &c_index1, (Ull)c_index, EXP_H1010, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);            /* stage#1 */
            mop(OP_LDR,  3, &BR[3][0][1], (Ull)a0_base[1], (Ull)a_rofs, MSK_W0, (Ull)a[1], A_row_size_mul_2_mul_A_col_blk, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk); /* stage#2 16KB */
            mop(OP_LDR,  3, &BR[3][1][1], (Ull)a1_base[1], (Ull)a_rofs, MSK_W0, (Ull)a[1], A_row_size_mul_2_mul_A_col_blk, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk); /* stage#2 16KB */
            mop(OP_LDWR, 3, &BR[3][2][1], (Ull)b, BR[2][0][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL,B_col_blk_mul_B_row_size);             /* stage#2 */
            mop(OP_LDWR, 3, &BR[3][3][1], (Ull)b, BR[2][1][1], MSK_W1, (Ull)b,B_col_blk_mul_B_row_size, 0, Force, (Ull)NULL,B_col_blk_mul_B_row_size);             /* stage#2 */

            exe(OP_FML, &AR[4][0], BR[2][0][1], EXP_H1010, BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][1], BR[2][1][1], EXP_H1010, BR[3][3][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            mop(OP_LDR, 3, &BR[4][0][1],  (Ull)a0_base[2],    (Ull)a_rofs, MSK_W0, (Ull)a[2], A_row_size_mul_2_mul_A_col_blk, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk);
            mop(OP_LDR, 3, &BR[4][1][1],  (Ull)a1_base[2],    (Ull)a_rofs, MSK_W0, (Ull)a[2], A_row_size_mul_2_mul_A_col_blk, 0, Force, (Ull)NULL, A_row_size_mul_2_mul_A_col_blk);
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

            sparse_final(61,62,c_index1);


              
              }
            }
          }
//EMAX5A end
if (Force) Force = 0;

    }
//EMAX5A drain_dirty_lmm
}
