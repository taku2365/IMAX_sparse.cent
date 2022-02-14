#ifndef NO_EMAX6LIB_BODY
#define NO_EMAX6LIB_BODY
#endif
#include "../Include/kernel_lib.h"

void spmv_normal_CHIP_div_A(Uint* C, const Uint* A, const Uint* B,emax6_param* params) {
    // args: A IMAX_CSR_format
    // arg B fortran continues simd format
    // arg C fortran continues simd format
    // A_col_blk=2 スケジューリング方法を変更
    Ull  CHIP;
    Ull  LOOP1, LOOP0;
    Ull  INIT1, INIT0;
    Ull  AR[64][4];                     /* output of EX     in each unit */
    Ull  BR[64][4][4];                  /* output registers in each unit */
    Ull  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
    Ull  r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
    Ull  cc0, cc1, cc2, cc3, ex0, ex1;
    Ull  cofs, rofs,a_rofs,b_rofs,c_rofs,oofs, k;
    // Ull A_row_size = M, A_col_size = K, B_row_size = K, B_col_size = N;
    Uint blk_iter,blk_iter_tmp;
    // Uint* paddings = A_sparse->paddings;
    Uint A_col_blk_tmp;

    Uint top,blk,b_col_B_col_blk;
    Ull x,y,z,t;
    Ull c_index,c_index1;
    Uint C_debug_val = 0,A_debug_val = 0,B_debug_val = 0;

    #define NCHIP 1
    // Sll A_row_size = params->A_row_size_param;   // 縛りなし
    Sll A_col_size = params->A_col_size_param;   // 縛りなし　H_padのおかげ
    Sll B_row_size = params->B_row_size_param;    // 縛りなし
    Sll B_col_size = params->B_col_size_param;   // B_col_blk*NCHIP縛り
    Sll A_row_size_pad = params->A_row_size_pad_param;
    Sll A_col_size_pad = params->A_col_size_pad_param;
    Sll B_row_size_pad = params->B_row_size_pad_param;
    Sll B_col_size_pad = params->B_col_size_pad_param;
    // #define B_col_blk 16
    Sll B_col_blk = params->B_col_blk_param;
    /*Sll NCHIP 4*/
    // Sll NCHIP = params->NCHIP_param;
    Sll W  = params->W_param;
    Sll H  = params->H_param;
    // Sll A_col_blk = 1;
    Sll A_col_blk = params->A_col_blk_param;
    Sll A_row_size_mul_mul_A_col_blk = A_row_size_pad*A_col_blk;
    Sll A_row_size_mul_B_col_blk = A_row_size_pad*B_col_blk;
    Sll A_row_size_mul_4 = A_row_size_pad*4;
    Sll A_row_size_div8 = A_row_size_pad>>3;
    Sll cofs_init = (0-A_row_size_mul_4)<<32|((0-1*4LL)&0xffffffff);
    Sll rofs_init = (0-8*4LL)<<32|((0-8*4LL)&0xffffffff);
    Sll A_row_size_mul_4_4 = (A_row_size_mul_4)<<32|(4LL&0xffffffff);
    Ull Force,Force_reverse;
    Force = 1;
    // Force_reverse = ~Force;
    Sll B_col_blk_mul_B_row_size = B_col_blk*(B_row_size_pad);
    // Sll A_col_add_A_H_pad = A_col_size + A_H_pad;
    Ull B_col_pad = 0;
    B_col_pad = ((B_col_size%(W*2)) != 0) ? -B_col_size%(W*2) + (W*2) : B_col_pad;    
    Uint *a[H],*a0[H],*a1[H],*a2[H],*a3[H],*a_index[H],*a_debug[H+1];
    Uint  *b, *b0[H], *b1[H], *b2[H], *b3[H];
    Uint  *c,*c0_debug;
    Uint  *c0, *c1, *c2, *c3;
    //(Uint *) 0x7ffff747fd84
    printf("IMAX\n");
    for (blk=0,blk_iter=0,A_col_blk_tmp=A_col_blk,A_row_size_mul_mul_A_col_blk = A_row_size_pad*A_col_blk; blk<(A_col_size_pad); blk+=A_col_blk*H,blk_iter+=A_col_blk) { /* 3重ループ展開の外側対象 */
        // A_col_blkずつとるが、最後のA_col_blkは余分な場合があるので減らす
        for (blk_iter_tmp=blk_iter;blk_iter_tmp<(blk_iter+A_col_blk);blk_iter_tmp++){

            if ((blk_iter_tmp*H>=(A_col_size_pad))){
                A_row_size_mul_mul_A_col_blk -= A_row_size_pad;
                A_col_blk_tmp -= 1;
            }
        }
        if(A_col_blk_tmp == 0){break;}
        b =  (Uint*)B;
        c  = (Uint*)C;
        c0 = (Uint*)C;
        c1 = (Uint*)C+2;
        c2 = (Uint*)C+4;
        c3 = (Uint*)C+6;


        for (k=0; k<H; k++) {
            //simdのために2の倍数
            // A_blkの単位がA_row_sizeなので疎行列と異なりblk*A_row_size_pad*2しない
            a[k]  = (Uint*)A+blk*A_row_size_pad+k*A_row_size_mul_mul_A_col_blk;
            a0[k] = (Uint*)A+blk*A_row_size_pad+k*A_row_size_mul_mul_A_col_blk;
            a1[k] = (Uint*)A+blk*A_row_size_pad+k*A_row_size_mul_mul_A_col_blk+2;
            a2[k] = (Uint*)A+blk*A_row_size_pad+k*A_row_size_mul_mul_A_col_blk+4;
            a3[k] = (Uint*)A+blk*A_row_size_pad+k*A_row_size_mul_mul_A_col_blk+6;
            b0[k] = (Uint*)B+blk+k*A_col_blk_tmp;
        }




    #define sgemm00_core1(r, rm1, rp1) \
            mop(OP_LDR,  3, &BR[r][0][1],  (Ull)a0[rm1], (Ull)a_rofs, MSK_W0,   (Ull)a[rm1], A_row_size_mul_mul_A_col_blk,     0, 0, (Ull)NULL, A_row_size_mul_mul_A_col_blk);\
            mop(OP_LDR,  3, &BR[r][0][0],  (Ull)a1[rm1], (Ull)a_rofs, MSK_W0,   (Ull)a[rm1], A_row_size_mul_mul_A_col_blk,     0, 0, (Ull)NULL, A_row_size_mul_mul_A_col_blk);\
            mop(OP_LDR,  3, &BR[r][1][1],  (Ull)a2[rm1], (Ull)a_rofs, MSK_W0,   (Ull)a[rm1], A_row_size_mul_mul_A_col_blk,     0, 0, (Ull)NULL, A_row_size_mul_mul_A_col_blk);\
            mop(OP_LDR,  3, &BR[r][1][0],  (Ull)a3[rm1], (Ull)a_rofs, MSK_W0,   (Ull)a[rm1], A_row_size_mul_mul_A_col_blk,     0, 0, (Ull)NULL, A_row_size_mul_mul_A_col_blk);\
            mop(OP_LDWR, 1, &BR[r][2][1],  (Ull)b0[rm1], (Ull)cofs,   MSK_W0,   (Ull)b, B_col_blk_mul_B_row_size, 0, 0, (Ull)NULL, B_col_blk_mul_B_row_size);\
            exe(OP_FMA, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[r][2][1], EXP_H1010, BR[r][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FMA, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[r][2][1], EXP_H1010, BR[r][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FMA, &AR[rp1][2], AR[r][2], EXP_H3210,  BR[r][2][1], EXP_H1010, BR[r][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FMA, &AR[rp1][3], AR[r][3], EXP_H3210,  BR[r][2][1], EXP_H1010, BR[r][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL)

    #define sgemm00_final(r, rp1) \
            mop(OP_LDR,  3, &BR[rp1][0][1],  (Ull)c0, (Ull)c_rofs, MSK_W0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            mop(OP_LDR,  3, &BR[rp1][1][1],  (Ull)c1, (Ull)c_rofs, MSK_W0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            mop(OP_LDR,  3, &BR[rp1][2][1],  (Ull)c2, (Ull)c_rofs, MSK_W0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            mop(OP_LDR,  3, &BR[rp1][3][1],  (Ull)c3, (Ull)c_rofs, MSK_W0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            exe(OP_FAD, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[rp1][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FAD, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[rp1][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FAD, &AR[rp1][2], AR[r][2], EXP_H3210,  BR[rp1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            exe(OP_FAD, &AR[rp1][3], AR[r][3], EXP_H3210,  BR[rp1][3][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
            mop(OP_STR,  3, &AR[rp1][0],  (Ull)c_rofs, (Ull)c0, MSK_D0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            mop(OP_STR,  3, &AR[rp1][1],  (Ull)c_rofs, (Ull)c1, MSK_D0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            mop(OP_STR,  3, &AR[rp1][2],  (Ull)c_rofs, (Ull)c2, MSK_D0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk);\
            mop(OP_STR,  3, &AR[rp1][3],  (Ull)c_rofs, (Ull)c3, MSK_D0, (Ull)c, A_row_size_mul_B_col_blk, 0, 1, (Ull)NULL, A_row_size_mul_B_col_blk)

//EMAX5A begin spmv0 mapdist=0
/*3*/  for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   /*1*/ for (INIT1=1,LOOP1=A_col_blk_tmp,cofs=cofs_init; LOOP1--; INIT1=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
  /*2*/    for (INIT0=1,LOOP0=A_row_size_div8,rofs=rofs_init; LOOP0--; INIT0=0) {  /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
            exe(OP_ADD,    &rofs, INIT0?rofs:rofs, EXP_H3210, 4*8LL<<32|4*8LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */ //1*8LL<<32|1*4LLとしてはいけない!!!!
            exe(OP_ADD,    &cofs, cofs, EXP_H3210, INIT0?A_row_size_mul_4_4:0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */
            exe(OP_ADD,    &a_rofs, rofs, EXP_H3210, cofs, EXP_H3232, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);            /* stage#1 */
            exe(OP_ADD,    &c_rofs, rofs, EXP_H1010, 0LL, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);            /* stage#1 */
            mop(OP_LDR,  3, &BR[2][0][1],  (Ull)a0[0],       (Ull)a_rofs, MSK_W1, (Ull)a[0]   ,A_row_size_mul_mul_A_col_blk, 0, Force, (Ull)NULL, A_row_size_mul_mul_A_col_blk);
            mop(OP_LDR,  3, &BR[2][0][0],  (Ull)a1[0],       (Ull)a_rofs, MSK_W1, (Ull)a[0]   ,A_row_size_mul_mul_A_col_blk, 0, Force, (Ull)NULL, A_row_size_mul_mul_A_col_blk);
            mop(OP_LDR,  3, &BR[2][1][1],  (Ull)a2[0],       (Ull)a_rofs, MSK_W1, (Ull)a[0]   ,A_row_size_mul_mul_A_col_blk, 0, Force, (Ull)NULL, A_row_size_mul_mul_A_col_blk);
            mop(OP_LDR,  3, &BR[2][1][0],  (Ull)a3[0],       (Ull)a_rofs, MSK_W1, (Ull)a[0]   ,A_row_size_mul_mul_A_col_blk, 0, Force, (Ull)NULL, A_row_size_mul_mul_A_col_blk);
            mop(OP_LDWR, 1, &BR[2][2][1],  (Ull)b0[0],       (Ull)cofs,   MSK_W0, (Ull)b      ,B_col_blk_mul_B_row_size,     0, Force, (Ull)NULL, B_col_blk_mul_B_row_size);
            exe(OP_FML, &AR[3][0], BR[2][2][1], EXP_H1010, BR[2][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[3][1], BR[2][2][1], EXP_H1010, BR[2][0][0], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[3][2], BR[2][2][1], EXP_H1010, BR[2][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[3][3], BR[2][2][1], EXP_H1010, BR[2][1][0], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            

            sgemm00_core1( 3, 1 ,  4 );
            sgemm00_core1( 4, 2 ,  5 );
            sgemm00_core1( 5, 3 ,  6 );
            sgemm00_core1( 6, 4 ,  7 );
            sgemm00_core1( 7, 5 ,  8 );
            sgemm00_core1( 8, 6 ,  9 );
            sgemm00_core1( 9, 7 ,  10);
            sgemm00_core1(10, 8 ,  11);
            sgemm00_core1(11, 9 ,  12);
            sgemm00_core1(12, 10 , 13);
            sgemm00_core1(13, 11 , 14);
            sgemm00_core1(14, 12 , 15);
            sgemm00_core1(15, 13 , 16);
            sgemm00_core1(16, 14 , 17);
            sgemm00_core1(17, 15 , 18);
            sgemm00_core1(18, 16 , 19);
            sgemm00_core1(19, 17 , 20);
            sgemm00_core1(20, 18 , 21);
            sgemm00_core1(21, 19 , 22);
            sgemm00_core1(22, 20 , 23);
            sgemm00_core1(23, 21 , 24);
            sgemm00_core1(24, 22 , 25);
            sgemm00_core1(25, 23 , 26);
            sgemm00_core1(26, 24 , 27);
            sgemm00_core1(27, 25 , 28);
            sgemm00_core1(28, 26 , 29);
            sgemm00_core1(29, 27 , 30);
            sgemm00_core1(30, 28 , 31);
            sgemm00_core1(31, 29 , 32);
            sgemm00_core1(32, 30 , 33);
            sgemm00_core1(33, 31 , 34);
            sgemm00_core1(34, 32 , 35);
            sgemm00_core1(35, 33 , 36);
            sgemm00_core1(36, 34 , 37);
            sgemm00_core1(37, 35 , 38);
            sgemm00_core1(38, 36 , 39);
            sgemm00_core1(39, 37 , 40);
            sgemm00_core1(40, 38 , 41);
            sgemm00_core1(41, 39 , 42);
            sgemm00_core1(42, 40 , 43);
            sgemm00_core1(43, 41 , 44);
            sgemm00_core1(44, 42 , 45);
            sgemm00_core1(45, 43 , 46);
            sgemm00_core1(46, 44 , 47);
            sgemm00_core1(47, 45 , 48);
            sgemm00_core1(48, 46 , 49);
            sgemm00_core1(49, 47 , 50);
            sgemm00_core1(50, 48 , 51);
            sgemm00_core1(51, 49 , 52);
            sgemm00_core1(52, 50 , 53);
            sgemm00_core1(53, 51 , 54);
            sgemm00_core1(54, 52 , 55);
            sgemm00_core1(55, 53 , 56);
            sgemm00_core1(56, 54 , 57);
            sgemm00_core1(57, 55 , 58);
            sgemm00_core1(58, 56 , 59);
            sgemm00_core1(59, 57 , 60);
            sgemm00_core1(60, 58 , 61);

            /****final*****/
            sgemm00_final(61,     62);

              
              }
            }
          }
//EMAX5A end
if (Force) Force = 0;

    }
//EMAX5A drain_dirty_lmm
}
