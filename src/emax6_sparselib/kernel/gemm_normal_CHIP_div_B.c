#ifndef NO_EMAX6LIB_BODY
#define NO_EMAX6LIB_BODY
#endif
#include "../Include/kernel_lib.h"
void gemm_normal_CHIP_div_B(Uint* C, const Uint* A, const Uint* B, emax6_param* params) {
  Ull top,blk;
  Ull  CHIP;
  Ull  LOOP1, LOOP0;
  Ull  INIT1, INIT0;
  Ull  AR[64][4];                     /* output of EX     in each unit */
  Ull  BR[64][4][4];                  /* output registers in each unit */
  Ull  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
  Ull  r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
  Ull  cc0, cc1, cc2, cc3, ex0, ex1;
  Ull  cofs, rofs, oofs, k;
  #undef A_row_size 
  #undef B_col_size 
  #undef B_row_size 
  #undef B_col_size 

  #undef B_col_blk 
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


  #define NCHIP 4
  Sll A_row_size = params->A_row_size_param;   // 縛りなし
  Sll A_col_size = params->A_col_size_param;   // 縛りなし　H_padのおかげ
  Sll B_row_size = params->B_row_size_param;    // 縛りなし
  Sll B_col_size = params->B_col_size_param;   // B_col_blk*NCHIP縛り
  // #define B_col_blk 16
  Sll B_col_blk = params->B_col_blk_param;
  /*Sll NCHIP 4*/
  // Sll NCHIP = params->NCHIP_param;
  Sll W  = params->W_param;
  Sll H  = params->H_param;
  Sll A_col_blk = params->A_col_blk_param;
  Sll B_col_size_mul_B_col_blk = B_col_size*B_col_blk;
  Sll B_col_blk_mul_B_row_size = B_col_blk*B_row_size;
  Sll A_row_size_mul_2_mul_A_col_blk = A_row_size*2*A_col_blk;
  Sll A_col_size_mul_B_col_blk = A_col_size*B_col_blk;
  Sll A_row_size_mul_B_col_blk = A_row_size*B_col_blk;
  Sll A_row_size_mul_8 = A_row_size*8;
  Sll  W_mul_8_64 =  (W*8)<<32|(W*8);
  Sll cofs_init = (0-W*8)<<32|((0-W*8)&0xffffffff);
  Sll rofs_init = (0-A_col_size*4)<<32|((0-B_col_size*4)&0xffffffff);
  Sll A_row_size_mul_8_64 = (A_row_size_mul_8)<<32|(A_row_size_mul_8);
  Sll rofs_reverse = (A_col_size*4)<<32|(B_col_size*4);
  /*  ┌─────┐convolutionの場合                                                  */
  /*  │┌────┴┐Bが複数と考える                                                  */
  /*  ││┌────┴┐┌─────┐┐        ┌─────┐┐                       */
  /*  │││b         ││a a a a a ││B_col_blk   │o o o o o ││B_col_blk                  */
  /*  │││b         ┤│          │┤/CHIP   │          │┤/CHIP                  */
  /*  │││b   B0   b││ A(weight)││        │   out    ││ mmの場合は行で分割    */
  /*  └││b        l┤│          │┤        │          │┤ cnnの場合はoutで分割  */
  /*    └│b        k││blk       ││        │blk       ││                       */
  /*      └─────┘└─┴─┴─┘┘        └─┴─┴─┘┘                       */
  printf("<<<IMAX>>>\n");
  for (top=0; top<A_row_size/NCHIP; top+=B_col_blk) { /* will be parallelized by multi-chip (M/#chip) */
    for (blk=0; blk<B_row_size; blk+=H) { /* 3重ループ展開の外側対象 */
      typedef struct {Uint i[8]} Ui8;
      Uint *a0[NCHIP];
      Uint *a[H][NCHIP];
      Ui8  *b[H], *b0[H], *b1[H], *b2[H], *b3[H];
      Ui8  *c0[NCHIP];
      Ui8  *c00[NCHIP], *c01[NCHIP], *c02[NCHIP], *c03[NCHIP];
      for (k=0; k<H; k++) {
	b[k] = B+(blk+k)*B_col_size; b0[k] = b[k]; b1[k] = (Uint*)b[k]+2; b2[k] = (Uint*)b[k]+4;  b3[k] = (Uint*)b[k]+6; 
      }
      for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
	a0[CHIP] = A+(CHIP*A_row_size/NCHIP+top)*A_col_size;
	for (k=0; k<H; k++)
	  a[k][CHIP] = a0[CHIP]+blk+k;
	c0[CHIP] = C+(CHIP*A_row_size/NCHIP+top)*B_col_size;
	c00[CHIP]= (Uint*)c0[CHIP]+0; c01[CHIP]= (Uint*)c0[CHIP]+2; c02[CHIP]= (Uint*)c0[CHIP]+4; c03[CHIP]= (Uint*)c0[CHIP]+6;
      }

#define sgemm00_core1(r, rm1, rp1) \
	    mop(OP_LDR,  3, &BR[r][0][1],  (Ull)b0[rm1], (Ull)cofs, MSK_W1, (Ull)b[rm1], B_col_size, 0, 0, (Ull)NULL, B_col_size);\
	    mop(OP_LDR,  3, &BR[r][0][0],  (Ull)b1[rm1], (Ull)cofs, MSK_W1, (Ull)b[rm1], B_col_size, 0, 0, (Ull)NULL, B_col_size);\
	    mop(OP_LDR,  3, &BR[r][1][1],  (Ull)b2[rm1], (Ull)cofs, MSK_W1, (Ull)b[rm1], B_col_size, 0, 0, (Ull)NULL, B_col_size);\
	    mop(OP_LDR,  3, &BR[r][1][0],  (Ull)b3[rm1], (Ull)cofs, MSK_W1, (Ull)b[rm1], B_col_size, 0, 0, (Ull)NULL, B_col_size);\
	    mop(OP_LDWR,1, &BR[r][2][1],  (Ull)a[rm1][CHIP],  (Ull)rofs, MSK_W1, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)NULL, A_col_size_mul_B_col_blk);\
	    exe(OP_FMA, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[r][2][1], EXP_H1010, BR[r][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[r][2][1], EXP_H1010, BR[r][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[rp1][2], AR[r][2], EXP_H3210,  BR[r][2][1], EXP_H1010, BR[r][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[rp1][3], AR[r][3], EXP_H3210,  BR[r][2][1], EXP_H1010, BR[r][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL)

#define sgemm00_final(r, rp1) \
	    mop(OP_LDR,  3, &BR[rp1][0][1],  (Ull)c00[CHIP], (Ull)oofs, MSK_W0, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)NULL, B_col_size_mul_B_col_blk);\
	    mop(OP_LDR,  3, &BR[rp1][1][1],  (Ull)c01[CHIP], (Ull)oofs, MSK_W0, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)NULL, B_col_size_mul_B_col_blk);\
	    mop(OP_LDR,  3, &BR[rp1][2][1],  (Ull)c02[CHIP], (Ull)oofs, MSK_W0, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)NULL, B_col_size_mul_B_col_blk);\
	    mop(OP_LDR,  3, &BR[rp1][3][1],  (Ull)c03[CHIP], (Ull)oofs, MSK_W0, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)NULL, B_col_size_mul_B_col_blk);\
	    exe(OP_FAD, &AR[rp1][0], AR[r][0], EXP_H3210,  BR[rp1][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[rp1][1], AR[r][1], EXP_H3210,  BR[rp1][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[rp1][2], AR[r][2], EXP_H3210,  BR[rp1][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FAD, &AR[rp1][3], AR[r][3], EXP_H3210,  BR[rp1][3][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mop(OP_STR,  3, &AR[rp1][0],     (Ull)oofs, (Ull)c00[CHIP], MSK_D0, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)NULL, B_col_size_mul_B_col_blk);\
	    mop(OP_STR,  3, &AR[rp1][1],     (Ull)oofs, (Ull)c01[CHIP], MSK_D0, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)NULL, B_col_size_mul_B_col_blk);\
	    mop(OP_STR,  3, &AR[rp1][2],     (Ull)oofs, (Ull)c02[CHIP], MSK_D0, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)NULL, B_col_size_mul_B_col_blk);\
	    mop(OP_STR,  3, &AR[rp1][3],     (Ull)oofs, (Ull)c03[CHIP], MSK_D0, (Ull)c0[CHIP], B_col_size_mul_B_col_blk, 0, 1, (Ull)NULL, B_col_size_mul_B_col_blk)

//EMAX5A begin mm0 mapdist=0
/*3*/ for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
  /*2*/ for (INIT1=1,LOOP1=B_col_blk,rofs=rofs_init; LOOP1--; INIT1=0) { /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
    /*1*/ for (INIT0=1,LOOP0=B_col_size/W/2,cofs=cofs_init; LOOP0--; INIT0=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
            exe(OP_ADD,    &cofs, INIT0?cofs:cofs, EXP_H3210, W_mul_8_64, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */
            exe(OP_ADD,    &rofs, rofs, EXP_H3210, INIT0?rofs_reverse:0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */
            exe(OP_ADD,    &oofs, rofs, EXP_H3210, cofs, EXP_H3210, 0, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);            /* stage#1 */

            mop(OP_LDR,  3, &BR[1][0][1],  (Ull)b0[0], (Ull)cofs, MSK_W1, (Ull)b[0], B_col_size, 0, 0, (Ull)NULL, B_col_size);             /* stage#1 */
            mop(OP_LDR,  3, &BR[1][0][0],  (Ull)b1[0], (Ull)cofs, MSK_W1, (Ull)b[0], B_col_size, 0, 0, (Ull)NULL, B_col_size);             /* stage#1 */
            mop(OP_LDR,  3, &BR[1][1][1],  (Ull)b2[0], (Ull)cofs, MSK_W1, (Ull)b[0], B_col_size, 0, 0, (Ull)NULL, B_col_size);             /* stage#1 */
            mop(OP_LDR,  3, &BR[1][1][0],  (Ull)b3[0], (Ull)cofs, MSK_W1, (Ull)b[0], B_col_size, 0, 0, (Ull)NULL, B_col_size);             /* stage#1 2KB */
            mop(OP_LDWR,1, &BR[1][2][1],  (Ull)a[0][CHIP],  (Ull)rofs, MSK_W1, (Ull)a0[CHIP], A_col_size_mul_B_col_blk, 0, 0, (Ull)NULL, A_col_size_mul_B_col_blk); /* stage#1 16KB */
            exe(OP_FML, &AR[2][0], BR[1][0][1], EXP_H3210,  BR[1][2][1], EXP_H1010, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#2 */
            exe(OP_FML, &AR[2][1], BR[1][0][0], EXP_H3210,  BR[1][2][1], EXP_H1010, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#2 */
            exe(OP_FML, &AR[2][2], BR[1][1][1], EXP_H3210,  BR[1][2][1], EXP_H1010, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#2 */
            exe(OP_FML, &AR[2][3], BR[1][1][0], EXP_H3210,  BR[1][2][1], EXP_H1010, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#2 */

	    sgemm00_core1( 2,  1,  3);
	    sgemm00_core1( 3,  2,  4);
	    sgemm00_core1( 4,  3,  5);
	    sgemm00_core1( 5,  4,  6);
	    sgemm00_core1( 6,  5,  7);
	    sgemm00_core1( 7,  6,  8);
	    sgemm00_core1( 8,  7,  9);
	    sgemm00_core1( 9,  8, 10);
	    sgemm00_core1(10,  9, 11);
	    sgemm00_core1(11, 10, 12);
	    sgemm00_core1(12, 11, 13);
	    sgemm00_core1(13, 12, 14);
	    sgemm00_core1(14, 13, 15);
	    sgemm00_core1(15, 14, 16);
	    sgemm00_core1(16, 15, 17);
	    sgemm00_core1(17, 16, 18);
	    sgemm00_core1(18, 17, 19);
	    sgemm00_core1(19, 18, 20);
	    sgemm00_core1(20, 19, 21);
	    sgemm00_core1(21, 20, 22);
	    sgemm00_core1(22, 21, 23);
	    sgemm00_core1(23, 22, 24);
	    sgemm00_core1(24, 23, 25);
	    sgemm00_core1(25, 24, 26);
	    sgemm00_core1(26, 25, 27);
	    sgemm00_core1(27, 26, 28);
	    sgemm00_core1(28, 27, 29);
	    sgemm00_core1(29, 28, 30);
	    sgemm00_core1(30, 29, 31);
	    sgemm00_core1(31, 30, 32);
	    sgemm00_core1(32, 31, 33);
	    sgemm00_core1(33, 32, 34);
	    sgemm00_core1(34, 33, 35);
	    sgemm00_core1(35, 34, 36);
	    sgemm00_core1(36, 35, 37);
	    sgemm00_core1(37, 36, 38);
	    sgemm00_core1(38, 37, 39);
	    sgemm00_core1(39, 38, 40);
	    sgemm00_core1(40, 39, 41);
	    sgemm00_core1(41, 40, 42);
	    sgemm00_core1(42, 41, 43);
	    sgemm00_core1(43, 42, 44);
	    sgemm00_core1(44, 43, 45);
	    sgemm00_core1(45, 44, 46);
	    sgemm00_core1(46, 45, 47);
	    sgemm00_core1(47, 46, 48);
	    sgemm00_core1(48, 47, 49);
	    sgemm00_core1(49, 48, 50);
	    sgemm00_core1(50, 49, 51);
	    sgemm00_core1(51, 50, 52);
	    sgemm00_core1(52, 51, 53);
	    sgemm00_core1(53, 52, 54);
	    sgemm00_core1(54, 53, 55);
	    sgemm00_core1(55, 54, 56);
	    sgemm00_core1(56, 55, 57);
	    sgemm00_core1(57, 56, 58);
	    sgemm00_core1(58, 57, 59);
	    sgemm00_core1(59, 58, 60);
	    sgemm00_core1(60, 59, 61);

	    /****final*****/
	    sgemm00_final(61,     62);
          }
        }
      }
//EMAX5A end
    }
  }
//EMAX5A drain_dirty_lmm
}