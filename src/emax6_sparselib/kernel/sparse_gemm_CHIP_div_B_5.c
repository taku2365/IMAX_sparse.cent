
#ifndef NO_EMAX6LIB_BODY
#define NO_EMAX6LIB_BODY
#endif
#include "../Include/kernel_lib.h"
void sparse_gemm_CHIP_div_B_5(Uint* C, const Uint* A, const Uint* B, emax6_sparse2* A_sparse, emax6_param* params) {
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
  Ull  cofs, rofs,a_rofs, oofs, k;
  // Ull A_row_size = M, A_col_size = K, B_row_size = K, B_col_size = N;
  Uint blk_iter,A_margin_tmp;
  Ull* A_margin = A_sparse->margin;
  Uint* val_index_set = A_sparse->val_index_set;

  Uint* A_sort_index= A_sparse->sort_index;
  Uint top,blk,b_col_RMGRP;
  Ull x,y,z,t;
  Ull a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
  Ull a11,a12,a13,a14,a15,a16,a17,a18,a19,a20;
  Ull a21,a22,a23,a24,a25,a26,a27,a28,a29,a30;
  Ull a31,a32,a33,a34,a35,a36,a37,a38,a39,a40;
  Ull a41,a42,a43,a44,a45,a46,a47,a48,a49,a50;
  Ull a51,a52,a53,a54,a55,a56,a57,a58,a59,a60;
  Ull nop,nop1,nop2;
  Ull c_index;
  Uint C_debug_val = 0,A_debug_val = 0,B_debug_val = 0;


  #undef A_row_size 
  #undef A_col_size 
  #undef B_row_size 
  #undef B_col_size 

  #undef RMGRP 
  #undef NCHIP 
  #undef W  
  #undef H  
  #undef OOFS_SHIFT  
  #undef A_col_blk
  #undef sparse_core1_1
  #undef sparse_core2
  #undef sparse_core2_1
  #undef sparse_core3_1
  #undef sparse_core4
  #undef sparse_final1

  #define A_row_size 400LL   // 縛りなし
  #define A_col_size 80LL    // 縛りなし　H_padのおかげ
  #define B_row_size 80LL    // 縛りなし
  #define B_col_size 768LL   // RMGRP*NCHIP縛り

  // #define RMGRP 16
  #define RMGRP 8
  /*#define NCHIP 4*/
  #define NCHIP 4
  #define W  4LL
  #define H  46
  #define A_col_blk 1


  printf("<<<IMAX>>>\n");
  for (top=0; top<B_col_size/NCHIP; top+=RMGRP) {
    for (blk=0,blk_iter=0; blk<A_col_size; blk+=A_col_blk*H,blk_iter+=A_col_blk) { /* 3重ループ展開の外側対象 */
      if((A_margin_tmp=A_margin[blk_iter])==0) break;
      for(b_col_RMGRP=0; b_col_RMGRP<RMGRP; b_col_RMGRP+=W*2){
      typedef struct {Uint i[8]} Ui8;
      Uint *a[H],*a_index[H],*a_debug[H+1];
      Ui8  *b[NCHIP], *b0[NCHIP], *b1[NCHIP], *b2[NCHIP], *b3[NCHIP];
      Ui8  *c0[NCHIP],*c0_debug[NCHIP];
      Ui8  *c00[NCHIP], *c01[NCHIP], *c02[NCHIP], *c03[NCHIP];
      A_debug_val = A[0];
      B_debug_val = B[0];
      C_debug_val = C[0];
      for (CHIP=0; CHIP<NCHIP; CHIP++) { 
      
        b[CHIP] = B+(CHIP*B_col_size/NCHIP+top+b_col_RMGRP)*B_row_size;
        b0[CHIP] = b[CHIP]+0; b1[CHIP] = (Uint*)b[CHIP]+B_row_size*2; b2[CHIP] = (Uint*)b[CHIP]+B_row_size*4;  b3[CHIP] = (Uint*)b[CHIP]+B_row_size*6; 


        c0[CHIP] = C+(CHIP*B_col_size/NCHIP+top+b_col_RMGRP)*A_row_size;
        c00[CHIP]= (Uint*)c0[CHIP]+0; c01[CHIP] = (Uint*)c0[CHIP]+A_row_size*2; c02[CHIP] = (Uint*)c0[CHIP]+A_row_size*4; c03[CHIP] = (Uint*)c0[CHIP]+A_row_size*6;
    
      }
      // little edianで格納 big <- <- <- <- small 右から左に流れていく
      //ex 64bit *((Ull*)&offset2)  11000000000000000000000000000000000   
      //   32bit *((Uint*)&offset2) -> 0    *((Uint*)&offset2+1) -> 1
      //   8bit  *((char*)&offset2+1) -> 0   *((char*)&offset2+2) -> 0 *((char*)&offset2+3) -> 0 *((char*)&offset2+4) -> 110
      // Ullで扱うときは *((Ull*)&offset2)>>32は*((Uint*)&offset2+1)を取得しているのと等価
      // https://hackaday.com/2020/08/04/dont-let-endianness-flip-you-around/
      //https://www.bogotobogo.com/Embedded/Little_endian_big_endian_htons_htonl.php
      //p *(float*)((Uint*)b[0]+6) 一つ目の値 3
      //>>> p/f  *((Uint*)&BR[2][0][1])
    // $17 = 3
    // >>> p/f  *((Uint*)&BR[2][0][1]+1)
    // $18 = 4
    //UllのA_row_size*2
    // rofs=(0-(Ull)1*8)<<32|((0-(Ull)1*4)&0xffffffff) マスクを使って2パターン使用している
    // 最後のstoreでMSK_D0を他のprogramが使っているので、先例に従った。
      for (k=0; k<H; k++) a[k] = (Uint*)val_index_set+blk*A_row_size*2+k*A_row_size*2*A_col_blk;
      //A_indexはUllなので*2している。 2(32bot*2 load)*4(load unit)*(H/8)=H
      //blk*A_row_size HごとにA_colを進めてる  (Hで何回colを進んだか)*A_row
      //Ullにまとめても取る量自体は同じ              blk/2*A_row_size*2(col/2なので+blk/2  2rowなのでA_row_size*2)
      //Hで割り切れないとき、割り切れない分のa_indexは0が入る  その結果、B_row=0が選ばれるがa[]には0がpadされているのでA[]*B[]=0となり問題ない
      // for (k=0; k<H/2; k++) a_index[k] = (Uint*)val_index_set+blk/2*A_row_size*2+k*A_row_size*2+A_col_size*A_row_size;


    // A_row_size*2*4*2は二か所で使用する　ブロードキャスト的な？

  #define sparse_core1_1(ar,ar_pre,br,br_pre,a_index,a_prev,a_current,a_next) \
      exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210, a_prev , EXP_H1010, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210, a_prev , EXP_H1010, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210, a_prev , EXP_H1010, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210, a_prev , EXP_H1010, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mop(OP_LDR,  3, &BR[br][0][1],  (Ull)b0[CHIP],(Ull)a_current, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][0][0],  (Ull)b1[CHIP],(Ull)a_current, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][1],  (Ull)b2[CHIP],(Ull)a_current, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][0],  (Ull)b3[CHIP],(Ull)a_current, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &a_next,  (Ull)a[a_index],  (Ull)a_rofs, MSK_W1, (Ull)a[a_index], A_row_size*2*A_col_blk, 0, 0, (Ull)NULL, A_row_size*2*A_col_blk)

  #define sparse_core2_1(ar,ar_pre,br,br_pre,a_prev,a_current) \
      exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210, a_prev , EXP_H1010, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210, a_prev , EXP_H1010, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210, a_prev , EXP_H1010, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210, a_prev , EXP_H1010, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mop(OP_LDR,  3, &BR[br][0][1],  (Ull)b0[CHIP],(Ull)a_current, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][0][0],  (Ull)b1[CHIP],(Ull)a_current, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][1],  (Ull)b2[CHIP],(Ull)a_current, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][0],  (Ull)b3[CHIP],(Ull)a_current, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size)

  #define sparse_core3_1(ar,ar_pre,br,br_pre,a_prev) \
      exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210, a_prev , EXP_H1010, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210, a_prev , EXP_H1010, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210, a_prev , EXP_H1010, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210, a_prev , EXP_H1010, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL)
      
  

#define sparse_final1(ar,ar_pre,br,br_pre,index_val) \
	    mop(OP_LDR,  3, &BR[br][0][1],  (Ull)c00[CHIP],(Ull)index_val, MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_LDR,  3, &BR[br][1][1],  (Ull)c01[CHIP],(Ull)index_val, MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_LDR,  3, &BR[br][2][1],  (Ull)c02[CHIP],(Ull)index_val, MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_LDR,  3, &BR[br][3][1],  (Ull)c03[CHIP],(Ull)index_val, MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    exe(OP_FAD, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br][3][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mop(OP_STR, 3, &AR[ar][0], (Ull)index_val, (Ull)c00[CHIP],  MSK_D0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_STR, 3, &AR[ar][1], (Ull)index_val, (Ull)c01[CHIP],  MSK_D0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_STR, 3, &AR[ar][2], (Ull)index_val, (Ull)c02[CHIP],  MSK_D0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
	    mop(OP_STR, 3, &AR[ar][3], (Ull)index_val, (Ull)c03[CHIP],  MSK_D0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP)


//EMAX5A begin mm4 mapdist=0
/*3*/ for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   /*1*/ for (INIT1=1,LOOP1=A_col_blk,cofs=(0-A_row_size*8)<<32|((0-A_row_size*8)&0xffffffff); LOOP1--; INIT1=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
  /*2*/    for (INIT0=1,LOOP0=A_margin_tmp,rofs=(0-1*8)<<32|((0-1*4)&0xffffffff); LOOP0--; INIT0=0) {  /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
            exe(OP_ADD,    &cofs, cofs, EXP_H3210, INIT0? (A_row_size*8)<<32|(A_row_size*8):0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */
            exe(OP_ADD,    &rofs, INIT0?rofs:rofs, EXP_H3210, (1*8)<<32|(1*4), EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */
            exe(OP_ADD,    &a_rofs, rofs, EXP_H3210, cofs, EXP_H3210, 0, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);            /* stage#1 */
            exe(OP_ADD,    &oofs, cofs, EXP_H3210, 0, EXP_H3210, 0, EXP_H3210, OP_AND, 0xffffffff,OP_NOP, 0LL);            /* stage#1 */
            exe(OP_NOP,    &cofs, cofs, EXP_H3210, 0, EXP_H3210, 0, EXP_H3210,  OP_NOP, 0LL,OP_NOP, 0LL);            /* stage#1 */
            exe(OP_NOP,    &rofs, rofs, EXP_H3210, 0, EXP_H3210, 0, EXP_H3210,  OP_NOP, 0LL,OP_NOP, 0LL);            /* stage#1 */
            exe(OP_NOP,    &nop2, 0, EXP_H3210, 0, EXP_H3210, 0, EXP_H3210,  OP_NOP, 0LL,OP_NOP, 0LL);            /* stage#1 */
            mop(OP_LDR,  3, &a0, (Ull)a[0], (Ull)a_rofs, MSK_W1, (Ull)a[0], A_row_size*2*A_col_blk, 0, 0, (Ull)NULL, A_row_size*2*A_col_blk);             /* stage#1 */
            mop(OP_LDWR, 1, &c_index, (Ull)A_sort_index, (Ull)rofs, MSK_W0, (Ull)A_sort_index, A_row_size, 0, 0, (Ull)NULL, A_row_size);

            exe(OP_ADD,    &c_index, (Ull)c_index, EXP_H3210, 0, EXP_H3210, 0, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);            /* stage#1 */
            mop(OP_LDR,  3, &BR[4][0][1], (Ull)b0[CHIP], a0, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[4][0][0], (Ull)b1[CHIP], a0, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[4][1][1], (Ull)b2[CHIP], a0, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[4][1][0], (Ull)b3[CHIP], a0, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 2KB */
            mop(OP_LDR,  3, &a1, (Ull)a[1], (Ull)a_rofs, MSK_W1, (Ull)a[1], A_row_size*2*A_col_blk, 0, 0, (Ull)NULL, A_row_size*2*A_col_blk); /* stage#2 16KB */

            exe(OP_FML, &AR[5][0], a0, EXP_H1010, BR[4][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[5][1], a0, EXP_H1010, BR[4][0][0], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[5][2], a0, EXP_H1010, BR[4][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[5][3], a0, EXP_H1010, BR[4][1][0], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            mop(OP_LDR,  3, &BR[5][0][1],  (Ull)b0[CHIP],(Ull)a1, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[5][0][0],  (Ull)b1[CHIP],(Ull)a1, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[5][1][1],  (Ull)b2[CHIP],(Ull)a1, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[5][1][0],  (Ull)b3[CHIP],(Ull)a1, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &a2,  (Ull)a[2],    (Ull)a_rofs, MSK_W1, (Ull)a[2], A_row_size*2*A_col_blk, 0, 0, (Ull)NULL, A_row_size*2*A_col_blk);
            


            sparse_core1_1(6  ,5  , 6 ,  5, 3 , a1 , a2 , a3 );
            sparse_core1_1(7  ,6  , 7 ,  6, 4 , a2 , a3 , a4 );
            sparse_core1_1(8  ,7  , 8 ,  7, 5 , a3 , a4 , a5 );
            sparse_core1_1(9  ,8  , 9 ,  8, 6 , a4 , a5 , a6 );
            sparse_core1_1(10  , 9 , 10 ,  9, 7 , a5 , a6 , a7 );
            sparse_core1_1(11  , 10 , 11 ,  10, 8 , a6 , a7 , a8 );
            sparse_core1_1(12  , 11 , 12 ,  11, 9 , a7 , a8 , a9 );
            sparse_core1_1(13  , 12 , 13 ,  12, 10, a8 , a9 , a10);
            sparse_core1_1(14  , 13 , 14 ,  13, 11, a9 , a10, a11);
            sparse_core1_1(15  , 14 , 15 ,  14, 12, a10, a11, a12);
            sparse_core1_1(16  , 15 , 16 ,  15, 13, a11, a12, a13);
            sparse_core1_1(17  , 16 , 17 ,  16, 14, a12, a13, a14);
            sparse_core1_1(18  , 17 , 18 ,  17, 15, a13, a14, a15);
            sparse_core1_1(19  , 18 , 19 ,  18, 16, a14, a15, a16);
            sparse_core1_1(20  , 19 , 20 ,  19, 17, a15, a16, a17);
            sparse_core1_1(21  , 20 , 21 ,  20, 18, a16, a17, a18);
            sparse_core1_1(22  , 21 , 22 ,  21, 19, a17, a18, a19);
            sparse_core1_1(23  , 22 , 23 ,  22, 20, a18, a19, a20);
            sparse_core1_1(24  , 23 , 24 ,  23, 21, a19, a20, a21);
            sparse_core1_1(25  , 24 , 25 ,  24, 22, a20, a21, a22);
            sparse_core1_1(26  , 25 , 26 ,  25, 23, a21, a22, a23);
            sparse_core1_1(27  , 26 , 27 ,  26, 24, a22, a23, a24);
            sparse_core1_1(28  , 27 , 28 ,  27, 25, a23, a24, a25);
            sparse_core1_1(29  , 28 , 29 ,  28, 26, a24, a25, a26);
            sparse_core1_1(30  , 29 , 30 ,  29, 27, a25, a26, a27);
            sparse_core1_1(31  , 30 , 31 ,  30, 28, a26, a27, a28);
            sparse_core1_1(32  , 31 , 32 ,  31, 29, a27, a28, a29);
            sparse_core1_1(33  , 32 , 33 ,  32, 30, a28, a29, a30);
            sparse_core1_1(34  , 33 , 34 ,  33, 31, a29, a30, a31);
            sparse_core1_1(35  , 34 , 35 ,  34, 32, a30, a31, a32);
            sparse_core1_1(36  , 35 , 36 ,  35, 33, a31, a32, a33);
            sparse_core1_1(37  , 36 , 37 ,  36, 34, a32, a33, a34);
            sparse_core1_1(38  , 37 , 38 ,  37, 35, a33, a34, a35);
            sparse_core1_1(39  , 38 , 39 ,  38, 36, a34, a35, a36);
            sparse_core1_1(40  , 39 , 40 ,  39, 37, a35, a36, a37);
            sparse_core1_1(41  , 40 , 41 ,  40, 38, a36, a37, a38);
            sparse_core1_1(42  , 41 , 42 ,  41, 39, a37, a38, a39);
            sparse_core1_1(43  , 42 , 43 ,  42, 40, a38, a39, a40);
            sparse_core1_1(44  , 43 , 44 ,  43, 41, a39, a40, a41);
            sparse_core1_1(45  , 44 , 45 ,  44, 42, a40, a41, a42);
            sparse_core1_1(46  , 45 , 46 ,  45, 43, a41, a42, a43);
            sparse_core1_1(47  , 46 , 47 ,  46, 44, a42, a43, a44);
            sparse_core1_1(48  , 47 , 48 ,  47, 45, a43, a44, a45);

            sparse_core2_1(49, 48, 49 ,48,     a44, a45);
            sparse_core3_1(50, 49, 50 ,49,     a45);
            // sparse_core1_1(48, 47, 48 ,47, 47, a45, a46, a47);
            // sparse_core1_1(49, 48, 49 ,48, 48, a46, a47, a48);
            // sparse_core1_1(50, 49, 50 ,49, 49, a47, a48, a49);
            // sparse_core1_1(51, 50, 51 ,50, 50, a48, a49, a50);
            // sparse_core1_1(52, 51, 52 ,51, 51, a49, a50, a51);
            // sparse_core1_1(53, 52, 53 ,52, 52, a50, a51, a52);
            // sparse_core1_1(54, 53, 54 ,53, 53, a51, a52, a53);
            // sparse_core1_1(55, 54, 55 ,54, 54, a52, a53, a54);
            // sparse_core1_1(56, 55, 56 ,55, 55, a53, a54, a55);
            // sparse_core1_1(57, 56, 57 ,56, 56, a54, a55, a56);
            // sparse_core1_1(58, 57, 58 ,57, 57, a55, a56, a57);
            sparse_final1(  51, 50, 51, 50,c_index);
            // sparse_final1(62,59,62,59,x);

              
              }
            }
          }
//EMAX5A end
        }
      }
    }
//EMAX5A drain_dirty_lmm
}