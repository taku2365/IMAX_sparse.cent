//このincludeはemaxlib.cを含んでいるからここでしか使わない
#include "../Include/kernel_lib.h"



void sysinit(Uint memsize,Uint alignment,Uchar** membase)
{
 
  // Uchar* membase;
  #if defined(ARMZYNQ) && defined(EMAX5)
    if (emax5_open() == NULL)
      exit(1);
    *membase = emax_info.hpp_mmap;
    {int i; for (i=0; i<(memsize+sizeof(Dll)-1)/sizeof(Dll); i++) *((Dll*)*membase+i)=0;}
  #elif defined(ARMZYNQ) && defined(EMAX6)
    if (emax6_open() == NULL)
      exit(1);
    *membase = emax_info.ddr_mmap;
    {int i; for (i=0; i<(memsize+sizeof(Dll)-1)/sizeof(Dll); i++) *((Dll*)*membase+i)=0;}
  #else
    *membase = (Uchar*)malloc(memsize+alignment);
    printf("malloc size %d \n",malloc_usable_size(*membase));
    printf("membase_before_align: %08.8x\n", (Uint)*membase);
    if ((Ull)*membase & (Ull)(alignment-1))
    *membase = (void*)(((Ull)*membase & ~(Ull)(alignment-1))+alignment);
    // memset(membase, 0, memsize+alignment);
    int i;
    for(i=0;i<memsize/sizeof(Uint);i++) *((Uint*)*membase+i) = (Uint)0;


    
    // 32byte = 16byte*2 = 0x20
    printf("membase_after_align: %08.8x\n", (Uint)*membase);

    
  #endif

  #if !defined(ARMZYNQ) && defined(EMAX5)
    emax_info.hpp_phys = *membase;
    emax_info.hpp_mmap = emax_info.hpp_phys;
    emax_info.acp_phys = ACP_BASE2_PHYS; /* defined in emax5lib.h >= ALOCLIMIT */
    emax_info.acp_mmap = emax_info.acp_phys;
  #endif
  #if defined(EMAX5)
    acp_conf = emax_info.acp_mmap; /* 8KB * 256sets */
    acp_lmmi = emax_info.acp_mmap + 0x200000;
    acp_regv = emax_info.acp_mmap + 0x304000;
  #endif

  #if !defined(ARMZYNQ) && defined(EMAX6)
    emax_info.dma_phys = DMA_BASE2_PHYS; /* defined in emax6lib.h */
    emax_info.dma_mmap = emax_info.dma_phys;
    emax_info.reg_phys = REG_BASE2_PHYS; /* defined in emax6lib.h */
    emax_info.reg_mmap = emax_info.reg_phys;
    emax_info.lmm_phys = LMM_BASE2_PHYS;
    emax_info.lmm_mmap = emax_info.lmm_phys;
    emax_info.ddr_phys = *membase;
    emax_info.ddr_mmap = emax_info.ddr_phys;
  #endif
  #if (defined(ARMSIML) || defined(ARMZYNQ)) && defined(EMAX6)
    emax6.dma_ctrl  = emax_info.dma_mmap;
    emax6.reg_ctrl  = emax_info.reg_mmap;
    ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].cmd = CMD_RESET;  // ★★★ RESET
  #if defined(ARMZYNQ)
    usleep(1);
  #endif
    ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].adtr = emax_info.ddr_mmap - emax_info.lmm_phys;
    ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].dmrp = 0LL;
  #endif

  // return membase;
}


// nanosec: ARM:188517 DRAIN:5270159 CONF:87428 REGV:19516443 RANGE:5849841 LOAD:43347914 EXEC:5820325 total:80080627
void sparse_gemm_736_736_736_CHIP_div_B(Uint* C, const Uint* A, const Uint* B, emax6_sparse2* A_sparse) {
  // args: A IMAX_CSR_format
  // arg B fortran continues simd format
  // arg C fortran continues simd format

  Ull  CHIP;
  Ull  LOOP1, LOOP0;
  Ull  INIT1, INIT0;
  Ull  AR[64][4];                     /* output of EX     in each unit */
  Ull  BR[64][4][4];                  /* output registers in each unit */
  Ull  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
  Ull  r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
  Ull  cc0, cc1, cc2, cc3, ex0, ex1;
  Ull  cofs, rofs, oofs, k;
  // Ull A_row_size = M, A_col_size = K, B_row_size = K, B_col_size = N;
  Uint blk_iter,A_margin_tmp;
  Ull* A_margin = A_sparse->margin;
  Uint* val_index_set = A_sparse->val_index_set;

  Uint* A_sort_index= A_sparse->sort_index;
  Uint top,blk;
  Ull x,y,z,t;
  Ull x0,y0,z0,t0;
  Ull x1,y1,z1,t1;
  Ull x2,y2,z2,t2;
  Ull x3,y3,z3,t3;
  Ull x4,y4,z4,t4;
  Ull x5,y5,z5,t5;
  Ull x6,y6,z6,t6;


  #undef A_row_size 
  #undef A_col_size 
  #undef B_row_size 
  #undef B_col_size 

  #undef RMGRP 
  #undef NCHIP 
  #undef W  
  #undef H  
  #undef OOFS_SHIFT  


  #define A_row_size 736LL
  #define A_col_size 736LL
  #define B_row_size 736LL
  #define B_col_size 736LL

  // #define RMGRP 16
  #define RMGRP 8
  /*#define NCHIP 4*/
  #define NCHIP 4
  #define W  4LL
  #define H  46

  printf("<<<IMAX>>>\n");
  for (top=0; top<B_col_size/NCHIP; top+=RMGRP) {
    for (blk=0,blk_iter=0; blk<A_col_size; blk+=H,blk_iter+=1) { /* 3重ループ展開の外側対象 */
      if((A_margin_tmp=A_margin[blk_iter])==0) break;
      typedef struct {Uint i[8]} Ui8;
      Uint *a[H],*a_index[H],*a_debug[H+1];
      Ui8  *b[NCHIP], *b0[NCHIP], *b1[NCHIP], *b2[NCHIP], *b3[NCHIP];
      Ui8  *c0[NCHIP],*c0_debug[NCHIP];
      Ui8  *c00[NCHIP], *c01[NCHIP], *c02[NCHIP], *c03[NCHIP];
      for (CHIP=0; CHIP<NCHIP; CHIP++) { 
      
        b[CHIP] = B+(CHIP*B_col_size/NCHIP+top)*B_row_size;
        b0[CHIP] = b[CHIP]+0; b1[CHIP] = (Uint*)b[CHIP]+B_row_size*2; b2[CHIP] = (Uint*)b[CHIP]+B_row_size*4;  b3[CHIP] = (Uint*)b[CHIP]+B_row_size*6; 


        c0[CHIP] = C+(CHIP*B_col_size/NCHIP+top)*A_row_size;
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
      for (k=0; k<H; k++) a[k] = (Uint*)val_index_set+(blk+k)*A_row_size;
      //A_indexはUllなので*2している。 2(32bot*2 load)*4(load unit)*(H/8)=H
      //blk*A_row_size HごとにA_colを進めてる  (Hで何回colを進んだか)*A_row
      //Ullにまとめても取る量自体は同じ              blk/2*A_row_size*2(col/2なので+blk/2  2rowなのでA_row_size*2)
      //Hで割り切れないとき、割り切れない分のa_indexは0が入る  その結果、B_row=0が選ばれるがa[]には0がpadされているのでA[]*B[]=0となり問題ない
      for (k=0; k<H/2; k++) a_index[k] = (Uint*)val_index_set+blk/2*A_row_size*2+k*A_row_size*2+A_col_size*A_row_size;


    // A_row_size*2*4*2は二か所で使用する　ブロードキャスト的な？


#define sparse_core1_1(ar,ar_pre,br,br_pre,a_val,index_val,index_MSK) \
      exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mop(OP_LDR,  3, &BR[br][0][1],  (Ull)b0[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][0][0],  (Ull)b1[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][1],  (Ull)b2[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][0],  (Ull)b3[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDWR, 1, &BR[br][2][1],  (Ull)a[a_val],  (Ull)rofs, MSK_W0, (Ull)a[a_val], A_row_size, 0, 0, (Ull)NULL, A_row_size)


#define sparse_core2(ar,ar_pre,br,br_pre,a_index1,a_index2,a_index3,a_index4,a_index_base)\
        exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,3, &BR[br][1][1],  (Ull)a_index[a_index1], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][1][0],  (Ull)a_index[a_index2], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][2][1],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][2][0],  (Ull)a_index[a_index4], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2)

#define sparse_core2_1(ar,ar_pre,br,br_pre,a_index1,a_index2,a_index3,a_index_base)\
        exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,3, &BR[br][1][1],  (Ull)a_index[a_index1], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][1][0],  (Ull)a_index[a_index2], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][2][1],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][2][0],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2)\
    

#define sparse_core3_1(ar,ar_pre,br,br_pre,a_val,index_val1,index_val2,index_val3,index_val4,index_val,index_MSK)\
        exe(OP_ADD, &index_val1, BR[br_pre][1][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &index_val2, BR[br_pre][1][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &index_val3, BR[br_pre][2][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &index_val4, BR[br_pre][2][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,  3, &BR[br][0][1], (Ull)b0[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][0][0], (Ull)b1[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][1][1], (Ull)b2[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][1][0], (Ull)b3[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDWR, 1, &BR[br][2][1], (Ull)a[a_val], (Ull)rofs, MSK_W0, (Ull)a[a_val], A_row_size, 0, 0, (Ull)NULL, A_row_size)


#define sparse_core4(ar,ar_pre,br,br_pre) \
        exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDWR, 1, &BR[br][0][1], (Ull)A_sort_index, (Ull)rofs, MSK_W0, (Ull)A_sort_index, A_row_size, 0, 0, (Ull)NULL, A_row_size)


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


//EMAX5A begin mm mapdist=0
/*3*/ for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   /*1*/ for (INIT1=1,LOOP1=RMGRP/(W*2),cofs=(0-W*4*2*B_row_size)<<32|((0-W*4*2*B_row_size)&0xffffffff); LOOP1--; INIT1=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
  /*2*/    for (INIT0=1,LOOP0=A_margin_tmp,rofs=(0-(Ull)1*8)<<32|((0-(Ull)1*4)&0xffffffff); LOOP0--; INIT0=0) {  /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
            exe(OP_ADD,    &cofs, cofs, EXP_H3210, INIT0? (W*4*2*B_row_size)<<32|(W*4*2*B_row_size):0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */
            exe(OP_ADD,    &rofs, INIT0?rofs:rofs, EXP_H3210, ((Ull)1*8)<<32|(((Ull)1*4)&0xffffffff), EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */
            exe(OP_ADD,    &oofs, cofs, EXP_H3210, 0, EXP_H3210, 0, EXP_H3210, OP_NOP, 0LL, OP_SLL, 0);            /* stage#1 */
            mop(OP_LDR,3, &BR[1][1][1],  (Ull)a_index[0], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);             /* stage#1 */
            mop(OP_LDR,3, &BR[1][1][0],  (Ull)a_index[1], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);             /* stage#1 */
            mop(OP_LDR,3, &BR[1][2][1],  (Ull)a_index[2], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);             /* stage#1 */
            mop(OP_LDR,3, &BR[1][2][0],  (Ull)a_index[3], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);             /* stage#1 */

            exe(OP_ADD, &x, BR[1][1][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            exe(OP_ADD, &y, BR[1][1][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            exe(OP_ADD, &z, BR[1][2][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            exe(OP_ADD, &t, BR[1][2][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            mop(OP_LDR,  3, &BR[3][0][1], (Ull)b0[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][0][0], (Ull)b1[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][1][1], (Ull)b2[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][1][0], (Ull)b3[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 2KB */
            mop(OP_LDWR, 1, &BR[3][2][1], (Ull)a[0], (Ull)rofs, MSK_W0, (Ull)a[0], A_row_size, 0, 0, (Ull)NULL, A_row_size); /* stage#2 16KB */

            exe(OP_FML, &AR[4][0], BR[3][0][1], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][1], BR[3][0][0], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][2], BR[3][1][1], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][3], BR[3][1][0], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            mop(OP_LDR,  3, &BR[4][0][1],  (Ull)b0[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][0][0],  (Ull)b1[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][1][1],  (Ull)b2[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][1][0],  (Ull)b3[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDWR, 1, &BR[4][2][1],  (Ull)a[1],    (Ull)rofs, MSK_W0, (Ull)a[1], A_row_size, 0, 0, (Ull)NULL, A_row_size);
            
            sparse_core1_1(5,  4,  5,  4,     2,           y,MSK_W0);
            sparse_core1_1(6,  5,  6,  5,     3,           y,MSK_W1);
            sparse_core1_1(7,  6,  7,  6,     4,           z,MSK_W0);
            sparse_core1_1(8,  7,  8,  7,     5,           z,MSK_W1);
            sparse_core1_1(9,  8,  9,  8,     6,           t,MSK_W0);
            sparse_core1_1(10, 9,  10, 9,     7,           t,MSK_W1);

            sparse_core2(  11, 10, 11, 10,        4,5,6,7,0);
            sparse_core3_1(12, 11, 13, 11,    8,  x,y,z,t, x,MSK_W0);

            sparse_core1_1(14, 11, 14, 13,    9,           x,MSK_W1);

            sparse_core1_1(15, 14, 15, 14,    10,          y,MSK_W0);
            sparse_core1_1(16, 15, 16, 15,    11,          y,MSK_W1);
            sparse_core1_1(17, 16, 17, 16,    12,          z,MSK_W0);
            sparse_core1_1(18, 17, 18, 17,    13,          z,MSK_W1);
            sparse_core1_1(19, 18, 19, 18,    14,          t,MSK_W0);
            sparse_core1_1(20, 19, 20, 19,    15,          t,MSK_W1);

            sparse_core2(  21, 20, 21, 20,        8,9,10,11,8);
            sparse_core3_1(22, 21, 23, 21,    16, x,y,z,t, x,MSK_W0);

            sparse_core1_1(24, 21, 24, 23,    17,          x,MSK_W1);

            sparse_core1_1(25, 24, 25, 24,    18,          y,MSK_W0);
            sparse_core1_1(26, 25, 26, 25,    19,          y,MSK_W1);
            sparse_core1_1(27, 26, 27, 26,    20,          z,MSK_W0);
            sparse_core1_1(28, 27, 28, 27,    21,          z,MSK_W1);
            sparse_core1_1(29, 28, 29, 28,    22,          t,MSK_W0);
            sparse_core1_1(30, 29, 30, 29,    23,          t,MSK_W1);

            sparse_core2(  31, 30, 31, 30,        12,13,14,15,8);
            sparse_core3_1(32, 31, 33, 31,    24, x,y,z,t, x,MSK_W0);

            sparse_core1_1(34, 31, 34, 33,    25,          x,MSK_W1);

            sparse_core1_1(35, 34, 35, 34,    26,          y,MSK_W0);
            sparse_core1_1(36, 35, 36, 35,    27,          y,MSK_W1);
            sparse_core1_1(37, 36, 37, 36,    28,          z,MSK_W0);
            sparse_core1_1(38, 37, 38, 37,    29,          z,MSK_W1);
            sparse_core1_1(39, 38, 39, 38,    30,          t,MSK_W0);
            sparse_core1_1(40, 39, 40, 39,    31,          t,MSK_W1);

            sparse_core2(  41, 40, 41, 40,        16,17,18,19,16);
            sparse_core3_1(42, 41, 43, 41,    32, x,y,z,t, x,MSK_W0);
   
            sparse_core1_1(44, 41, 44, 43,    33,          x,MSK_W1);

            sparse_core1_1(45, 44, 45, 44,    34,          y,MSK_W0);
            sparse_core1_1(46, 45, 46, 45,    35,          y,MSK_W1);
            sparse_core1_1(47, 46, 47, 46,    36,          z,MSK_W0);
            sparse_core1_1(48, 47, 48, 47,    37,          z,MSK_W1);
            sparse_core1_1(49, 48, 49, 48,    38,          t,MSK_W0);
            sparse_core1_1(50, 49, 50, 49,    39,          t,MSK_W1);

            sparse_core2_1(51, 50, 51, 50,        20,21,22,16);
            sparse_core3_1(52, 51, 53, 51,    40, x,y,z,t, x,MSK_W0);
   
            sparse_core1_1(54, 51, 54, 53,    41,           x,MSK_W1);

            sparse_core1_1(55, 54, 55, 54,    42,             y,MSK_W0);
            sparse_core1_1(56, 55, 56, 55,    43,             y,MSK_W1);
            sparse_core1_1(57, 56, 57, 56,    44,             z,MSK_W0);
            sparse_core1_1(58, 57, 58, 57,    45,             z,MSK_W1);
            sparse_core4(  59, 58, 59, 58);
            exe(OP_ADD, &x, BR[59][0][1], EXP_H3210, oofs, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff,  OP_NOP, 0LL);
            
            sparse_final1(62,59,62,59,x);



          }
        }
      }
//EMAX5A end
    }
  }
//EMAX5A drain_dirty_lmm
}










void sparse_gemm_736_736_736_CHIP_div_B_2(Uint* C, const Uint* A, const Uint* B, emax6_sparse2* A_sparse) {
  // sparse_gemm_768_96_96_768_1とforの順番を入れ替えたver
  // args: A IMAX_CSR_format
  // arg B fortran continues simd format
  // arg C fortran continues simd format
  Ull  CHIP;
  Ull  LOOP1, LOOP0;
  Ull  INIT1, INIT0;
  Ull  AR[64][4];                     /* output of EX     in each unit */
  Ull  BR[64][4][4];                  /* output registers in each unit */
  Ull  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
  Ull  r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
  Ull  cc0, cc1, cc2, cc3, ex0, ex1;
  Ull  cofs, rofs, oofs, k;
  // Ull A_row_size = M, A_col_size = K, B_row_size = K, B_col_size = N;
  Uint blk_iter,A_margin_tmp;
  Ull* A_margin = A_sparse->margin;
  Uint* val_index_set = A_sparse->val_index_set;

  Uint* A_sort_index= A_sparse->sort_index;
  Uint top,blk;
  Ull x,y,z,t;
  Ull x0,y0,z0,t0;
  Ull x1,y1,z1,t1;
  Ull x2,y2,z2,t2;
  Ull x3,y3,z3,t3;
  Ull x4,y4,z4,t4;
  Ull x5,y5,z5,t5;
  Ull x6,y6,z6,t6;


  #undef A_row_size 
  #undef A_col_size 
  #undef B_row_size 
  #undef B_col_size 

  #undef RMGRP 
  #undef NCHIP 
  #undef W  
  #undef H  
  #undef OOFS_SHIFT


  #define A_row_size 736LL
  #define A_col_size 736LL
  #define B_row_size 736LL
  #define B_col_size 736LL

  // #define RMGRP 16
  #define RMGRP 8
  /*#define NCHIP 4*/
  #define NCHIP 4
  #define W  4LL
  #define H  46
  #define OOFS_SHIFT 3LL


  printf("<<<IMAX>>>\n");
  for (top=0; top<B_col_size/NCHIP; top+=RMGRP) {
    for (blk=0,blk_iter=0; blk<A_col_size; blk+=H,blk_iter+=1) { /* 3重ループ展開の外側対象 */
      if((A_margin_tmp=A_margin[blk_iter])==0) break;
      typedef struct {Uint i[8]} Ui8;
      Uint *a[H],*a_index[H],*a_debug[H+1];
      Ui8  *b[NCHIP], *b0[NCHIP], *b1[NCHIP], *b2[NCHIP], *b3[NCHIP];
      Ui8  *c0[NCHIP],*c0_debug[NCHIP];
      Ui8  *c00[NCHIP], *c01[NCHIP], *c02[NCHIP], *c03[NCHIP];
      for (CHIP=0; CHIP<NCHIP; CHIP++) { 
      
        b[CHIP] = B+(CHIP*B_col_size/NCHIP+top)*B_row_size;
        b0[CHIP] = b[CHIP]+0; b1[CHIP] = (Uint*)b[CHIP]+B_row_size*2; b2[CHIP] = (Uint*)b[CHIP]+B_row_size*4;  b3[CHIP] = (Uint*)b[CHIP]+B_row_size*6; 


        c0[CHIP] = C+(CHIP*B_col_size/NCHIP+top)*A_row_size;
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
      for (k=0; k<H; k++) a[k] = (Uint*)val_index_set+(blk+k)*A_row_size;
      //A_indexはUllなので*2している。 2(32bot*2 load)*4(load unit)*(H/8)=H
      //blk*A_row_size HごとにA_colを進めてる  (Hで何回colを進んだか)*A_row
      //Ullにまとめても取る量自体は同じ              blk/2*A_row_size*2(col/2なので+blk/2  2rowなのでA_row_size*2)
      //Hで割り切れないとき、割り切れない分のa_indexは0が入る  その結果、B_row=0が選ばれるがa[]には0がpadされているのでA[]*B[]=0となり問題ない
      for (k=0; k<H/2; k++) a_index[k] = (Uint*)val_index_set+blk/2*A_row_size*2+k*A_row_size*2+A_col_size*A_row_size;


    // A_row_size*2*4*2は二か所で使用する　ブロードキャスト的な？


#define sparse_core1_1(ar,ar_pre,br,br_pre,a_val,index_val,index_MSK) \
      exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mop(OP_LDR,  3, &BR[br][0][1],  (Ull)b0[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][0][0],  (Ull)b1[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][1],  (Ull)b2[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][0],  (Ull)b3[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDWR, 1, &BR[br][2][1],  (Ull)a[a_val],  (Ull)rofs, MSK_W0, (Ull)a[a_val], A_row_size, 0, 0, (Ull)NULL, A_row_size)


#define sparse_core2(ar,ar_pre,br,br_pre,a_index1,a_index2,a_index3,a_index4,a_index_base)\
        exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,3, &BR[br][1][1],  (Ull)a_index[a_index1], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][1][0],  (Ull)a_index[a_index2], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][2][1],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][2][0],  (Ull)a_index[a_index4], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2)

#define sparse_core2_1(ar,ar_pre,br,br_pre,a_index1,a_index2,a_index3,a_index_base)\
        exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,3, &BR[br][1][1],  (Ull)a_index[a_index1], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][1][0],  (Ull)a_index[a_index2], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][2][1],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][2][0],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2)\
    

#define sparse_core3_1(ar,ar_pre,br,br_pre,a_val,index_val1,index_val2,index_val3,index_val4,index_val,index_MSK)\
        exe(OP_ADD, &index_val1, BR[br_pre][1][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &index_val2, BR[br_pre][1][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &index_val3, BR[br_pre][2][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &index_val4, BR[br_pre][2][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,  3, &BR[br][0][1], (Ull)b0[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][0][0], (Ull)b1[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][1][1], (Ull)b2[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][1][0], (Ull)b3[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDWR, 1, &BR[br][2][1], (Ull)a[a_val], (Ull)rofs, MSK_W0, (Ull)a[a_val], A_row_size, 0, 0, (Ull)NULL, A_row_size)


#define sparse_core4(ar,ar_pre,br,br_pre) \
        exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDWR, 1, &BR[br][0][1], (Ull)A_sort_index, (Ull)rofs, MSK_W0, (Ull)A_sort_index, A_row_size, 0, 0, (Ull)NULL, A_row_size)


#define sparse_final2(ar,ar_pre,br,br_pre,index_val) \
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





//EMAX5A begin mm1 mapdist=0
/*3*/ for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
  /*2*/ for (INIT1=1,LOOP1=A_margin_tmp,rofs=(0-(Ull)1*8)<<32|((0-(Ull)1*4)&0xffffffff); LOOP1--; INIT1=0) {  /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
    /*1*/ for (INIT0=1,LOOP0=RMGRP/(W*2),cofs=(0-W*4*2*B_row_size)<<32|((0-W*4*2*B_row_size)&0xffffffff); LOOP0--; INIT0=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
            exe(OP_ADD,    &cofs, INIT0?cofs:cofs, EXP_H3210, (W*4*2*B_row_size)<<32|(W*4*2*B_row_size), EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */
            exe(OP_ADD,    &rofs, rofs, EXP_H3210, INIT0?((Ull)1*8)<<32|((Ull)1*4):0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */
            exe(OP_ADD,    &oofs, cofs, EXP_H3210, 0, EXP_H3210, 0, EXP_H3210, OP_NOP, 0LL, OP_SLL, OOFS_SHIFT);            /* stage#1 */
            mop(OP_LDR,3, &BR[1][1][1],  (Ull)a_index[0], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);             /* stage#1 */
            mop(OP_LDR,3, &BR[1][1][0],  (Ull)a_index[1], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);             /* stage#1 */
            mop(OP_LDR,3, &BR[1][2][1],  (Ull)a_index[2], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);             /* stage#1 */
            mop(OP_LDR,3, &BR[1][2][0],  (Ull)a_index[3], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);             /* stage#1 */

            exe(OP_ADD, &x, BR[1][1][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            exe(OP_ADD, &y, BR[1][1][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            exe(OP_ADD, &z, BR[1][2][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            exe(OP_ADD, &t, BR[1][2][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            mop(OP_LDR,  3, &BR[3][0][1], (Ull)b0[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][0][0], (Ull)b1[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][1][1], (Ull)b2[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][1][0], (Ull)b3[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 2KB */
            mop(OP_LDWR, 1, &BR[3][2][1], (Ull)a[0], (Ull)rofs, MSK_W0, (Ull)a[0], A_row_size, 0, 0, (Ull)NULL, A_row_size); /* stage#2 16KB */

            exe(OP_FML, &AR[4][0], BR[3][0][1], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][1], BR[3][0][0], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][2], BR[3][1][1], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][3], BR[3][1][0], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            mop(OP_LDR,  3, &BR[4][0][1],  (Ull)b0[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][0][0],  (Ull)b1[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][1][1],  (Ull)b2[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][1][0],  (Ull)b3[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDWR, 1, &BR[4][2][1],  (Ull)a[1],    (Ull)rofs, MSK_W0, (Ull)a[1], A_row_size, 0, 0, (Ull)NULL, A_row_size);
            
            sparse_core1_1(5,  4,  5,  4,     2,           y,MSK_W0);
            sparse_core1_1(6,  5,  6,  5,     3,           y,MSK_W1);
            sparse_core1_1(7,  6,  7,  6,     4,           z,MSK_W0);
            sparse_core1_1(8,  7,  8,  7,     5,           z,MSK_W1);
            sparse_core1_1(9,  8,  9,  8,     6,           t,MSK_W0);
            sparse_core1_1(10, 9,  10, 9,     7,           t,MSK_W1);

            sparse_core2(  11, 10, 11, 10,        4,5,6,7,0);
            sparse_core3_1(12, 11, 13, 11,    8,  x,y,z,t, x,MSK_W0);

            sparse_core1_1(14, 11, 14, 13,    9,           x,MSK_W1);

            sparse_core1_1(15, 14, 15, 14,    10,          y,MSK_W0);
            sparse_core1_1(16, 15, 16, 15,    11,          y,MSK_W1);
            sparse_core1_1(17, 16, 17, 16,    12,          z,MSK_W0);
            sparse_core1_1(18, 17, 18, 17,    13,          z,MSK_W1);
            sparse_core1_1(19, 18, 19, 18,    14,          t,MSK_W0);
            sparse_core1_1(20, 19, 20, 19,    15,          t,MSK_W1);

            sparse_core2(  21, 20, 21, 20,        8,9,10,11,8);
            sparse_core3_1(22, 21, 23, 21,    16, x,y,z,t, x,MSK_W0);

            sparse_core1_1(24, 21, 24, 23,    17,          x,MSK_W1);

            sparse_core1_1(25, 24, 25, 24,    18,          y,MSK_W0);
            sparse_core1_1(26, 25, 26, 25,    19,          y,MSK_W1);
            sparse_core1_1(27, 26, 27, 26,    20,          z,MSK_W0);
            sparse_core1_1(28, 27, 28, 27,    21,          z,MSK_W1);
            sparse_core1_1(29, 28, 29, 28,    22,          t,MSK_W0);
            sparse_core1_1(30, 29, 30, 29,    23,          t,MSK_W1);

            sparse_core2(  31, 30, 31, 30,        12,13,14,15,8);
            sparse_core3_1(32, 31, 33, 31,    24, x,y,z,t, x,MSK_W0);

            sparse_core1_1(34, 31, 34, 33,    25,          x,MSK_W1);

            sparse_core1_1(35, 34, 35, 34,    26,          y,MSK_W0);
            sparse_core1_1(36, 35, 36, 35,    27,          y,MSK_W1);
            sparse_core1_1(37, 36, 37, 36,    28,          z,MSK_W0);
            sparse_core1_1(38, 37, 38, 37,    29,          z,MSK_W1);
            sparse_core1_1(39, 38, 39, 38,    30,          t,MSK_W0);
            sparse_core1_1(40, 39, 40, 39,    31,          t,MSK_W1);

            sparse_core2(  41, 40, 41, 40,        16,17,18,19,16);
            sparse_core3_1(42, 41, 43, 41,    32, x,y,z,t, x,MSK_W0);
   
            sparse_core1_1(44, 41, 44, 43,    33,          x,MSK_W1);

            sparse_core1_1(45, 44, 45, 44,    34,          y,MSK_W0);
            sparse_core1_1(46, 45, 46, 45,    35,          y,MSK_W1);
            sparse_core1_1(47, 46, 47, 46,    36,          z,MSK_W0);
            sparse_core1_1(48, 47, 48, 47,    37,          z,MSK_W1);
            sparse_core1_1(49, 48, 49, 48,    38,          t,MSK_W0);
            sparse_core1_1(50, 49, 50, 49,    39,          t,MSK_W1);

            sparse_core2_1(51, 50, 51, 50,        20,21,22,16);
            sparse_core3_1(52, 51, 53, 51,    40, x,y,z,t, x,MSK_W0);
   
            sparse_core1_1(54, 51, 54, 53,    41,           x,MSK_W1);

            sparse_core1_1(55, 54, 55, 54,    42,             y,MSK_W0);
            sparse_core1_1(56, 55, 56, 55,    43,             y,MSK_W1);
            sparse_core1_1(57, 56, 57, 56,    44,             z,MSK_W0);
            sparse_core1_1(58, 57, 58, 57,    45,             z,MSK_W1);
            sparse_core4(  59, 58, 59, 58);
            exe(OP_ADD, &x, BR[59][0][1], EXP_H3210, oofs, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff,  OP_NOP, 0LL);
            
            sparse_final2(62,59,62,59,x);



          }
        }
      }
//EMAX5A end
    }
  }
//EMAX5A drain_dirty_lmm
}



void sparse_gemm_736_736_736_CHIP_div_B_3(Uint* C, const Uint* A, const Uint* B, emax6_sparse2* A_sparse) {
  // args: A IMAX_CSR_format
  // arg B fortran continues simd format
  // arg C fortran continues simd format
  // CHIP div B  EXP_1010使用
  Ull  CHIP;
  Ull  LOOP1, LOOP0;
  Ull  INIT1, INIT0;
  Ull  AR[64][4];                     /* output of EX     in each unit */
  Ull  BR[64][4][4];                  /* output registers in each unit */
  Ull  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
  Ull  r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
  Ull  cc0, cc1, cc2, cc3, ex0, ex1;
  Ull  cofs, rofs, oofs, k;
  // Ull A_row_size = M, A_col_size = K, B_row_size = K, B_col_size = N;
  Uint blk_iter,A_margin_tmp;
  Ull* A_margin = A_sparse->margin;
  Uint* val_index_set = A_sparse->val_index_set;

  Uint* A_sort_index= A_sparse->sort_index;
  Uint top,blk;
  Ull x,y,z,t;
  Ull x0,y0,z0,t0;
  Ull x1,y1,z1,t1;
  Ull x2,y2,z2,t2;
  Ull x3,y3,z3,t3;
  Ull x4,y4,z4,t4;
  Ull x5,y5,z5,t5;
  Ull x6,y6,z6,t6;
  Ull cofs1;

  #undef A_row_size 
  #undef A_col_size 
  #undef B_row_size 
  #undef B_col_size 

  #undef RMGRP 
  #undef NCHIP 
  #undef W  
  #undef H  
  #undef OOFS_SHIFT  


  #define A_row_size 736LL
  #define A_col_size 10LL
  #define B_row_size 10LL
  #define B_col_size 768LL

  // #define RMGRP 16
  #define RMGRP 16
  /*#define NCHIP 4*/
  #define NCHIP 4
  #define W  4LL
  #define H  46

  printf("<<<IMAX>>>\n");
  for (top=0; top<B_col_size/NCHIP; top+=RMGRP) {
    for (blk=0,blk_iter=0; blk<A_col_size; blk+=H,blk_iter+=1) { /* 3重ループ展開の外側対象 */
      if((A_margin_tmp=A_margin[blk_iter])==0) break;
      typedef struct {Uint i[8]} Ui8;
      Uint *a[H],*a_index[H],*a_debug[H+1];
      Ui8  *b[NCHIP], *b0[NCHIP], *b1[NCHIP], *b2[NCHIP], *b3[NCHIP];
      Ui8  *c0[NCHIP],*c0_debug[NCHIP];
      Ui8  *c00[NCHIP], *c01[NCHIP], *c02[NCHIP], *c03[NCHIP];
      for (CHIP=0; CHIP<NCHIP; CHIP++) { 
      
        b[CHIP] = B+(CHIP*B_col_size/NCHIP+top)*B_row_size;
        b0[CHIP] = b[CHIP]+0; b1[CHIP] = (Uint*)b[CHIP]+B_row_size*2; b2[CHIP] = (Uint*)b[CHIP]+B_row_size*4;  b3[CHIP] = (Uint*)b[CHIP]+B_row_size*6; 


        c0[CHIP] = C+(CHIP*B_col_size/NCHIP+top)*A_row_size;
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
      for (k=0; k<H; k++) a[k] = (Uint*)val_index_set+(blk+k)*A_row_size;
      //A_indexはUllなので*2している。 2(32bot*2 load)*4(load unit)*(H/8)=H
      //blk*A_row_size HごとにA_colを進めてる  (Hで何回colを進んだか)*A_row
      //Ullにまとめても取る量自体は同じ              blk/2*A_row_size*2(col/2なので+blk/2  2rowなのでA_row_size*2)
      //Hで割り切れないとき、割り切れない分のa_indexは0が入る  その結果、B_row=0が選ばれるがa[]には0がpadされているのでA[]*B[]=0となり問題ない
      for (k=0; k<H/2; k++) a_index[k] = (Uint*)val_index_set+blk/2*A_row_size*2+k*A_row_size*2+A_col_size*A_row_size;


    // A_row_size*2*4*2は二か所で使用する　ブロードキャスト的な？


#define sparse_core1_1(ar,ar_pre,br,br_pre,a_val,index_val,index_MSK) \
      exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
	    mop(OP_LDR,  3, &BR[br][0][1],  (Ull)b0[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][0][0],  (Ull)b1[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][1],  (Ull)b2[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDR,  3, &BR[br][1][0],  (Ull)b3[CHIP],(Ull)index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
	    mop(OP_LDWR, 1, &BR[br][2][1],  (Ull)a[a_val],  (Ull)rofs, MSK_W0, (Ull)a[a_val], A_row_size, 0, 0, (Ull)NULL, A_row_size)


#define sparse_core2(ar,ar_pre,br,br_pre,a_index1,a_index2,a_index3,a_index4,a_index_base)\
        exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,3, &BR[br][1][1],  (Ull)a_index[a_index1], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][1][0],  (Ull)a_index[a_index2], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][2][1],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][2][0],  (Ull)a_index[a_index4], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2)

#define sparse_core2_1(ar,ar_pre,br,br_pre,a_index1,a_index2,a_index3,a_index_base)\
        exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,3, &BR[br][1][1],  (Ull)a_index[a_index1], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][1][0],  (Ull)a_index[a_index2], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][2][1],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
        mop(OP_LDR,3, &BR[br][2][0],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2)\
    

#define sparse_core3_1(ar,ar_pre,br,br_pre,a_val,index_val1,index_val2,index_val3,index_val4,index_val,index_MSK)\
        exe(OP_ADD, &index_val1, BR[br_pre][1][1], EXP_H3210, cofs1, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &index_val2, BR[br_pre][1][0], EXP_H3210, cofs1, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &index_val3, BR[br_pre][2][1], EXP_H3210, cofs1, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_ADD, &index_val4, BR[br_pre][2][0], EXP_H3210, cofs1, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDR,  3, &BR[br][0][1], (Ull)b0[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][0][0], (Ull)b1[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][1][1], (Ull)b2[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDR,  3, &BR[br][1][0], (Ull)b3[CHIP], index_val, index_MSK, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
        mop(OP_LDWR, 1, &BR[br][2][1], (Ull)a[a_val], (Ull)rofs, MSK_W0, (Ull)a[a_val], A_row_size, 0, 0, (Ull)NULL, A_row_size)


#define sparse_core4(ar,ar_pre,br,br_pre) \
        exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
        mop(OP_LDWR, 1, &BR[br][0][1], (Ull)A_sort_index, (Ull)rofs, MSK_W0, (Ull)A_sort_index, A_row_size, 0, 0, (Ull)NULL, A_row_size)


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


//EMAX5A begin mm mapdist=0
/*3*/ for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   /*1*/ for (INIT1=1,LOOP1=RMGRP/(W*2),cofs=(0-W*4*2*A_row_size)<<32|((0-W*4*2*B_row_size)&0xffffffff); LOOP1--; INIT1=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
  /*2*/    for (INIT0=1,LOOP0=A_margin_tmp,rofs=(0-(Ull)1*8)<<32|((0-(Ull)1*4)&0xffffffff); LOOP0--; INIT0=0) {  /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
            exe(OP_ADD,    &cofs, cofs, EXP_H3210, INIT0? (W*4*2*A_row_size)<<32|(W*4*2*B_row_size):0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */
            exe(OP_ADD,    &rofs, INIT0?rofs:rofs, EXP_H3210, ((Ull)1*8)<<32|(((Ull)1*4)&0xffffffff), EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */
            exe(OP_ADD,    &cofs1, cofs, EXP_H1010, 0, EXP_H3210, 0, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0);            /* stage#1 */
            exe(OP_ADD,    &oofs, cofs, EXP_H3232, 0, EXP_H3210, 0, EXP_H3210, OP_NOP, 0LL,OP_NOP, 0);            /* stage#1 */
            mop(OP_LDR,3, &BR[1][1][1],  (Ull)a_index[0], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);             /* stage#1 */
            mop(OP_LDR,3, &BR[1][1][0],  (Ull)a_index[1], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);             /* stage#1 */
            mop(OP_LDR,3, &BR[1][2][1],  (Ull)a_index[2], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);             /* stage#1 */
            mop(OP_LDR,3, &BR[1][2][0],  (Ull)a_index[3], (Ull)rofs, MSK_W1, (Ull)a_index[0], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);             /* stage#1 */

            exe(OP_ADD, &x, BR[1][1][1], EXP_H3210, cofs1, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            exe(OP_ADD, &y, BR[1][1][0], EXP_H3210, cofs1, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            exe(OP_ADD, &z, BR[1][2][1], EXP_H3210, cofs1, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            exe(OP_ADD, &t, BR[1][2][0], EXP_H3210, cofs1, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);                                /* stage#2 */
            mop(OP_LDR,  3, &BR[3][0][1], (Ull)b0[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][0][0], (Ull)b1[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][1][1], (Ull)b2[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][1][0], (Ull)b3[CHIP], x, MSK_W0, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 2KB */
            mop(OP_LDWR, 1, &BR[3][2][1], (Ull)a[0], (Ull)rofs, MSK_W0, (Ull)a[0], A_row_size, 0, 0, (Ull)NULL, A_row_size); /* stage#2 16KB */

            exe(OP_FML, &AR[4][0], BR[3][0][1], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][1], BR[3][0][0], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][2], BR[3][1][1], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][3], BR[3][1][0], EXP_H3210,  BR[3][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            mop(OP_LDR,  3, &BR[4][0][1],  (Ull)b0[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][0][0],  (Ull)b1[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][1][1],  (Ull)b2[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][1][0],  (Ull)b3[CHIP],(Ull)x, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDWR, 1, &BR[4][2][1],  (Ull)a[1],    (Ull)rofs, MSK_W0, (Ull)a[1], A_row_size, 0, 0, (Ull)NULL, A_row_size);
            
            sparse_core1_1(5,  4,  5,  4,     2,           y,MSK_W0);
            sparse_core1_1(6,  5,  6,  5,     3,           y,MSK_W1);
            sparse_core1_1(7,  6,  7,  6,     4,           z,MSK_W0);
            sparse_core1_1(8,  7,  8,  7,     5,           z,MSK_W1);
            sparse_core1_1(9,  8,  9,  8,     6,           t,MSK_W0);
            sparse_core1_1(10, 9,  10, 9,     7,           t,MSK_W1);

            sparse_core2(  11, 10, 11, 10,        4,5,6,7,0);
            sparse_core3_1(12, 11, 13, 11,    8,  x,y,z,t, x,MSK_W0);

            sparse_core1_1(14, 11, 14, 13,    9,           x,MSK_W1);

            sparse_core1_1(15, 14, 15, 14,    10,          y,MSK_W0);
            sparse_core1_1(16, 15, 16, 15,    11,          y,MSK_W1);
            sparse_core1_1(17, 16, 17, 16,    12,          z,MSK_W0);
            sparse_core1_1(18, 17, 18, 17,    13,          z,MSK_W1);
            sparse_core1_1(19, 18, 19, 18,    14,          t,MSK_W0);
            sparse_core1_1(20, 19, 20, 19,    15,          t,MSK_W1);

            sparse_core2(  21, 20, 21, 20,        8,9,10,11,8);
            sparse_core3_1(22, 21, 23, 21,    16, x,y,z,t, x,MSK_W0);

            sparse_core1_1(24, 21, 24, 23,    17,          x,MSK_W1);

            sparse_core1_1(25, 24, 25, 24,    18,          y,MSK_W0);
            sparse_core1_1(26, 25, 26, 25,    19,          y,MSK_W1);
            sparse_core1_1(27, 26, 27, 26,    20,          z,MSK_W0);
            sparse_core1_1(28, 27, 28, 27,    21,          z,MSK_W1);
            sparse_core1_1(29, 28, 29, 28,    22,          t,MSK_W0);
            sparse_core1_1(30, 29, 30, 29,    23,          t,MSK_W1);

            sparse_core2(  31, 30, 31, 30,        12,13,14,15,8);
            sparse_core3_1(32, 31, 33, 31,    24, x,y,z,t, x,MSK_W0);

            sparse_core1_1(34, 31, 34, 33,    25,          x,MSK_W1);

            sparse_core1_1(35, 34, 35, 34,    26,          y,MSK_W0);
            sparse_core1_1(36, 35, 36, 35,    27,          y,MSK_W1);
            sparse_core1_1(37, 36, 37, 36,    28,          z,MSK_W0);
            sparse_core1_1(38, 37, 38, 37,    29,          z,MSK_W1);
            sparse_core1_1(39, 38, 39, 38,    30,          t,MSK_W0);
            sparse_core1_1(40, 39, 40, 39,    31,          t,MSK_W1);

            sparse_core2(  41, 40, 41, 40,        16,17,18,19,16);
            sparse_core3_1(42, 41, 43, 41,    32, x,y,z,t, x,MSK_W0);
   
            sparse_core1_1(44, 41, 44, 43,    33,          x,MSK_W1);

            sparse_core1_1(45, 44, 45, 44,    34,          y,MSK_W0);
            sparse_core1_1(46, 45, 46, 45,    35,          y,MSK_W1);
            sparse_core1_1(47, 46, 47, 46,    36,          z,MSK_W0);
            sparse_core1_1(48, 47, 48, 47,    37,          z,MSK_W1);
            sparse_core1_1(49, 48, 49, 48,    38,          t,MSK_W0);
            sparse_core1_1(50, 49, 50, 49,    39,          t,MSK_W1);

            sparse_core2_1(51, 50, 51, 50,        20,21,22,16);
            sparse_core3_1(52, 51, 53, 51,    40, x,y,z,t, x,MSK_W0);
   
            sparse_core1_1(54, 51, 54, 53,    41,           x,MSK_W1);

            sparse_core1_1(55, 54, 55, 54,    42,             y,MSK_W0);
            sparse_core1_1(56, 55, 56, 55,    43,             y,MSK_W1);
            sparse_core1_1(57, 56, 57, 56,    44,             z,MSK_W0);
            sparse_core1_1(58, 57, 58, 57,    45,             z,MSK_W1);
            sparse_core4(  59, 58, 59, 58);
            exe(OP_ADD, &x, BR[59][0][1], EXP_H3210, oofs, EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffff,  OP_NOP, 0LL);
            
            sparse_final1(62,59,62,59,x);



          }
        }
      }
//EMAX5A end
    }
  }
//EMAX5A drain_dirty_lmm
}





void sparse_gemm_736_736_736_CHIP_div_B_4(Uint* C, const Uint* A, const Uint* B, emax6_sparse2* A_sparse) {
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

  #define A_row_size 736LL
  #define A_col_size 736LL
  #define B_row_size 736LL
  #define B_col_size 736LL

  // #define RMGRP 16
  #define RMGRP 8
  /*#define NCHIP 4*/
  #define NCHIP 4
  #define W  4LL
  #define H  46
  #define A_col_blk 2


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


//EMAX5A begin mm2 mapdist=0
/*3*/ for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
        //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
   /*1*/ for (INIT1=1,LOOP1=A_col_blk,cofs=(0-A_row_size*8)<<32|((0-A_row_size*8)&0xffffffff); LOOP1--; INIT1=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
  /*2*/    for (INIT0=1,LOOP0=A_margin_tmp,rofs=(0-(Ull)1*8)<<32|((0-(Ull)1*4)&0xffffffff); LOOP0--; INIT0=0) {  /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
            exe(OP_ADD,    &cofs, cofs, EXP_H3210, INIT0? (A_row_size*8)<<32|(A_row_size*8):0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */
            exe(OP_ADD,    &rofs, INIT0?rofs:rofs, EXP_H3210, ((Ull)1*8)<<32|(((Ull)1*4)&0xffffffff), EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */
            exe(OP_ADD,    &a_rofs, rofs, EXP_H3210, cofs, EXP_H3210, 0, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);            /* stage#1 */
            exe(OP_ADD,    &oofs, cofs, EXP_H3210, 0, EXP_H3210, 0, EXP_H3210, OP_AND, 0xffffffff,OP_NOP, 0LL);            /* stage#1 */
            mop(OP_LDR,  3, &a0, (Ull)a[0], (Ull)a_rofs, MSK_W1, (Ull)a[0], A_row_size*2*A_col_blk, 0, 0, (Ull)NULL, A_row_size*2*A_col_blk);             /* stage#1 */
            mop(OP_LDWR, 1, &c_index, (Ull)A_sort_index, (Ull)rofs, MSK_W0, (Ull)A_sort_index, A_row_size, 0, 0, (Ull)NULL, A_row_size);

            exe(OP_ADD,    &c_index, (Ull)c_index, EXP_H3210, 0, EXP_H3210, 0, EXP_H3210, OP_AND, 0xffffffff, OP_NOP, 0LL);            /* stage#1 */
            mop(OP_LDR,  3, &BR[3][0][1], (Ull)b0[CHIP], a0, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][0][0], (Ull)b1[CHIP], a0, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][1][1], (Ull)b2[CHIP], a0, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
            mop(OP_LDR,  3, &BR[3][1][0], (Ull)b3[CHIP], a0, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 2KB */
            mop(OP_LDR,  3, &a1, (Ull)a[1], (Ull)a_rofs, MSK_W1, (Ull)a[1], A_row_size*2*A_col_blk, 0, 0, (Ull)NULL, A_row_size*2*A_col_blk); /* stage#2 16KB */

            exe(OP_FML, &AR[4][0], a0, EXP_H1010, BR[3][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][1], a0, EXP_H1010, BR[3][0][0], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][2], a0, EXP_H1010, BR[3][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            exe(OP_FML, &AR[4][3], a0, EXP_H1010, BR[3][1][0], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
            mop(OP_LDR,  3, &BR[4][0][1],  (Ull)b0[CHIP],(Ull)a1, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][0][0],  (Ull)b1[CHIP],(Ull)a1, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][1][1],  (Ull)b2[CHIP],(Ull)a1, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &BR[4][1][0],  (Ull)b3[CHIP],(Ull)a1, MSK_W1, (Ull)b[CHIP], RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
            mop(OP_LDR,  3, &a2,  (Ull)a[2],    (Ull)a_rofs, MSK_W1, (Ull)a[2], A_row_size*2*A_col_blk, 0, 0, (Ull)NULL, A_row_size*2*A_col_blk);
            


            sparse_core1_1(5,  4,  5  ,4 , 3 , a1 , a2 , a3 );
            sparse_core1_1(6,  5,  6  ,5 , 4 , a2 , a3 , a4 );
            sparse_core1_1(7,  6,  7  ,6 , 5 , a3 , a4 , a5 );
            sparse_core1_1(8,  7,  8  ,7 , 6 , a4 , a5 , a6 );
            sparse_core1_1(9,  8,  9  ,8 , 7 , a5 , a6 , a7 );
            sparse_core1_1(10, 9,  10 ,9 , 8 , a6 , a7 , a8 );
            sparse_core1_1(11, 10, 11 ,10, 9 , a7 , a8 , a9 );
            sparse_core1_1(12, 11, 12 ,11, 10, a8 , a9 , a10);
            sparse_core1_1(13, 12, 13 ,12, 11, a9 , a10, a11);
            sparse_core1_1(14, 13, 14 ,13, 12, a10, a11, a12);
            sparse_core1_1(15, 14, 15 ,14, 13, a11, a12, a13);
            sparse_core1_1(16, 15, 16 ,15, 14, a12, a13, a14);
            sparse_core1_1(17, 16, 17 ,16, 15, a13, a14, a15);
            sparse_core1_1(18, 17, 18 ,17, 16, a14, a15, a16);
            sparse_core1_1(19, 18, 19 ,18, 17, a15, a16, a17);
            sparse_core1_1(20, 19, 20 ,19, 18, a16, a17, a18);
            sparse_core1_1(21, 20, 21 ,20, 19, a17, a18, a19);
            sparse_core1_1(22, 21, 22 ,21, 20, a18, a19, a20);
            sparse_core1_1(23, 22, 23 ,22, 21, a19, a20, a21);
            sparse_core1_1(24, 23, 24 ,23, 22, a20, a21, a22);
            sparse_core1_1(25, 24, 25 ,24, 23, a21, a22, a23);
            sparse_core1_1(26, 25, 26 ,25, 24, a22, a23, a24);
            sparse_core1_1(27, 26, 27 ,26, 25, a23, a24, a25);
            sparse_core1_1(28, 27, 28 ,27, 26, a24, a25, a26);
            sparse_core1_1(29, 28, 29 ,28, 27, a25, a26, a27);
            sparse_core1_1(30, 29, 30 ,29, 28, a26, a27, a28);
            sparse_core1_1(31, 30, 31 ,30, 29, a27, a28, a29);
            sparse_core1_1(32, 31, 32 ,31, 30, a28, a29, a30);
            sparse_core1_1(33, 32, 33 ,32, 31, a29, a30, a31);
            sparse_core1_1(34, 33, 34 ,33, 32, a30, a31, a32);
            sparse_core1_1(35, 34, 35 ,34, 33, a31, a32, a33);
            sparse_core1_1(36, 35, 36 ,35, 34, a32, a33, a34);
            sparse_core1_1(37, 36, 37 ,36, 35, a33, a34, a35);
            sparse_core1_1(38, 37, 38 ,37, 36, a34, a35, a36);
            sparse_core1_1(39, 38, 39 ,38, 37, a35, a36, a37);
            sparse_core1_1(40, 39, 40 ,39, 38, a36, a37, a38);
            sparse_core1_1(41, 40, 41 ,40, 39, a37, a38, a39);
            sparse_core1_1(42, 41, 42 ,41, 40, a38, a39, a40);
            sparse_core1_1(43, 42, 43 ,42, 41, a39, a40, a41);
            sparse_core1_1(44, 43, 44 ,43, 42, a40, a41, a42);
            sparse_core1_1(45, 44, 45 ,44, 43, a41, a42, a43);
            sparse_core1_1(46, 45, 46 ,45, 44, a42, a43, a44);
            sparse_core1_1(47, 46, 47 ,46, 45, a43, a44, a45);

            sparse_core2_1(48, 47, 48 ,47,     a44, a45);
            sparse_core3_1(49, 48, 49 ,48,     a45);
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
            sparse_final1(  50, 49, 50, 49,c_index);
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



// void sparse_gemm_736_736_736_CHIP_div_A(Uint* C, const Uint* A, const Uint* B, emax6_sparse2* A_sparse) {
//   // CHIPをAで分割するver
//   // args: A IMAX_CSR_format
//   // arg B fortran continues simd format
//   // arg C fortran continues simd format
//   Ull  CHIP;
//   Ull  LOOP1, LOOP0;
//   Ull  INIT1, INIT0;
//   Ull  AR[64][4];                     /* output of EX     in each unit */
//   Ull  BR[64][4][4];                  /* output registers in each unit */
//   Ull  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
//   Ull  r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31;
//   Ull  cc0, cc1, cc2, cc3, ex0, ex1;
//   Ull  cofs, cofs1, rofs,rofs1, oofs, k,b_cofs,rofs_blk,top1;
//   //rofs1は8を使うため。
//   // Ull A_row_size = M, A_col_size = K, B_row_size = K, B_col_size = N;
//   Uint blk_iter,A_margin_tmp;
//   Ull* A_margin = A_sparse->margin;
//   Ull* A_margin_sum = A_sparse->margin_sum;
//   A_margin_tmp = A_margin[0];
//   Uint* val_index_set = A_sparse->val_index_set;

//   Uint* A_sort_index= A_sparse->sort_index;
//   Uint top,blk;
//   Ull x,y,z,t;
//   Ull x0,y0,z0,t0;
//   Ull x1,y1,z1,t1;
//   Ull x2,y2,z2,t2;
//   Ull x3,y3,z3,t3;
//   Ull x4,y4,z4,t4;
//   Ull x5,y5,z5,t5;
//   Ull x6,y6,z6,t6;
//   Ull a_index_val1,a_index_val2,a_index_val3,a_index_val4;
  


//   #undef A_row_size 
//   #undef A_col_size 
//   #undef B_row_size 
//   #undef B_col_size 

//   #undef RMGRP 
//   #undef NCHIP 
//   #undef W  
//   #undef H  
//   #undef OOFS_SHIFT


//   #define A_row_size 736LL
//   #define A_col_size 736LL
//   #define B_row_size 736LL
//   #define B_col_size 736LL

//   // #define RMGRP 16
//   #define RMGRP 8
//   /*#define NCHIP 4*/
//   #define NCHIP 4
//   #define W  4LL
//   #define H  46
//   #define OOFS_SHIFT 3LL


//   printf("<<<IMAX>>>\n");
//   for(top1=0;top1<A_row_size/NCHIP;top1+=RMGRP){
//     for (top=0; top<B_col_size/NCHIP; top+=RMGRP) {
//       for (b_cofs=0; b_cofs<RMGRP; b_cofs+=W*2) { /* 3重ループ展開の外側対象 */
        
//         typedef struct {Uint i[8]} Ui8;
//         Uint *a[NCHIP][H],*a_index[NCHIP][H],*a_index_val[NCHIP][H];
//         Ui8  *b, *b0, *b1, *b2, *b3;
//         Ui8  *c0[NCHIP];
//         Ui8  *c00[NCHIP], *c01[NCHIP], *c02[NCHIP], *c03[NCHIP];
//         for (CHIP=0; CHIP<NCHIP; CHIP++) { 
        
//           for (k=0; k<H; k++) a[CHIP][k] = (Uint*)val_index_set+k*A_margin_tmp+A_margin_tmp*H*CHIP;
//           //A_indexはUllなので*2している。 2(32bot*2 load)*4(load unit)*(H/8)=H
//           //blk*A_row_size HごとにA_colを進めてる  (Hで何回colを進んだか)*A_row
//           //Ullにまとめても取る量自体は同じ              blk/2*A_row_size*2(col/2なので+blk/2  2rowなのでA_row_size*2)
//           //Hで割り切れないとき、割り切れない分のa_indexは0が入る  その結果、B_row=0が選ばれるがa[]には0がpadされているのでA[]*B[]=0となり問題ない
//           for (k=0; k<H/2; k++) a_index[CHIP][k] = (Uint*)val_index_set+k*A_margin_tmp*2+A_margin_tmp*H*CHIP+A_col_size*A_row_size;

//           c0[CHIP] = C+CHIP*(A_row_size/NCHIP+top1)*B_col_size;
//           c00[CHIP]= (Uint*)c0[CHIP]+0; c01[CHIP] = (Uint*)c0[CHIP]+A_row_size*2; c02[CHIP] = (Uint*)c0[CHIP]+A_row_size*4; c03[CHIP] = (Uint*)c0[CHIP]+A_row_size*6;
      
//         }

//         b = B+top*B_row_size+b_cofs;
//         b0 = b+0; b1 = (Uint*)b+B_row_size*2; b2 = (Uint*)b+B_row_size*4;  b3 = (Uint*)b+B_row_size*6; 

//         // little edianで格納 big <- <- <- <- small 右から左に流れていく
//         //ex 64bit *((Ull*)&offset2)  11000000000000000000000000000000000   
//         //   32bit *((Uint*)&offset2) -> 0    *((Uint*)&offset2+1) -> 1
//         //   8bit  *((char*)&offset2+1) -> 0   *((char*)&offset2+2) -> 0 *((char*)&offset2+3) -> 0 *((char*)&offset2+4) -> 110
//         // Ullで扱うときは *((Ull*)&offset2)>>32は*((Uint*)&offset2+1)を取得しているのと等価
//         // https://hackaday.com/2020/08/04/dont-let-endianness-flip-you-around/
//         //https://www.bogotobogo.com/Embedded/Little_endian_big_endian_htons_htonl.php
//         //p *(float*)((Uint*)b[0]+6) 一つ目の値 3
//         //>>> p/f  *((Uint*)&BR[2][0][1])
//       // $17 = 3
//       // >>> p/f  *((Uint*)&BR[2][0][1]+1)
//       // $18 = 4
//       //UllのA_row_size*2
//       // rofs=(0-(Ull)1*8)<<32|((0-(Ull)1*4)&0xffffffff) マスクを使って2パターン使用している
//       // 最後のstoreでMSK_D0を他のprogramが使っているので、先例に従った。


// #define sparse_core1_1_CHIP_divA(ar,ar_pre,br,br_pre,a_val,index_val,index_MSK) \
//       exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
// 	    exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
// 	    exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
// 	    exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
// 	    mop(OP_LDR,  3, &BR[br][0][1],  (Ull)b0,(Ull)index_val, index_MSK, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
// 	    mop(OP_LDR,  3, &BR[br][0][0],  (Ull)b1,(Ull)index_val, index_MSK, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
// 	    mop(OP_LDR,  3, &BR[br][1][1],  (Ull)b2,(Ull)index_val, index_MSK, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
// 	    mop(OP_LDR,  3, &BR[br][1][0],  (Ull)b3,(Ull)index_val, index_MSK, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);\
// 	    mop(OP_LDWR, 1, &BR[br][2][1],  (Ull)a[a_val],  (Ull)rofs, MSK_W0, (Ull)a[a_val], A_row_size, 0, 0, (Ull)NULL, A_row_size)


// #define sparse_core2_CHIP_divA(ar,ar_pre,br,br_pre,a_index1,a_index2,a_index3,a_index4,a_index_base)\
//         exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         mop(OP_LDR,3, &BR[br][1][1],  (Ull)a_index[a_index1], (Ull)rofs1, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
//         mop(OP_LDR,3, &BR[br][1][0],  (Ull)a_index[a_index2], (Ull)rofs1, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
//         mop(OP_LDR,3, &BR[br][2][1],  (Ull)a_index[a_index3], (Ull)rofs1, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
//         mop(OP_LDR,3, &BR[br][2][0],  (Ull)a_index[a_index4], (Ull)rofs1, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2)

// #define sparse_core2_1_CHIP_divA(ar,ar_pre,br,br_pre,a_index1,a_index2,a_index3,a_index_base)\
//         exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         mop(OP_LDR,3, &BR[br][1][1],  (Ull)a_index[a_index1], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
//         mop(OP_LDR,3, &BR[br][1][0],  (Ull)a_index[a_index2], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
//         mop(OP_LDR,3, &BR[br][2][1],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2);\
//         mop(OP_LDR,3, &BR[br][2][0],  (Ull)a_index[a_index3], (Ull)rofs, MSK_W1, (Ull)a_index[a_index_base], A_row_size*2*4*2, 0, 0, (Ull)NULL, A_row_size*2*4*2)\
    

// #define sparse_core3_1_CHIP_divA(ar,ar_pre,br,br_pre,a_val,index_val1,index_val2,index_val3,index_val4,index_val,index_MSK)\
//         exe(OP_ADD, &index_val1, BR[br_pre][1][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         exe(OP_ADD, &index_val2, BR[br_pre][1][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         exe(OP_ADD, &index_val3, BR[br_pre][2][1], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         exe(OP_ADD, &index_val4, BR[br_pre][2][0], EXP_H3210, cofs, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         mop(OP_LDR,  3, &BR[br][0][1], (Ull)b0, index_val, index_MSK, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
//         mop(OP_LDR,  3, &BR[br][0][0], (Ull)b1, index_val, index_MSK, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
//         mop(OP_LDR,  3, &BR[br][1][1], (Ull)b2, index_val, index_MSK, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
//         mop(OP_LDR,  3, &BR[br][1][0], (Ull)b3, index_val, index_MSK, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);\
//         mop(OP_LDWR, 1, &BR[br][2][1], (Ull)a[a_val], (Ull)rofs, MSK_W0, (Ull)a[a_val], A_row_size, 0, 0, (Ull)NULL, A_row_size)


// #define sparse_core4_CHIP_divA(ar,ar_pre,br,br_pre) \
//         exe(OP_FMA, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         exe(OP_FMA, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][0][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         exe(OP_FMA, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][1], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
//         exe(OP_FMA, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br_pre][2][1], EXP_H3210, BR[br_pre][1][0], EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\


// #define sparse_final_CHIP_divA(ar,ar_pre,br,br_pre,index_val) \
// 	    mop(OP_LDR,  3, &BR[br][0][1],  (Ull)c00[CHIP],(Ull)index_val, MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
// 	    mop(OP_LDR,  3, &BR[br][1][1],  (Ull)c01[CHIP],(Ull)index_val, MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
// 	    mop(OP_LDR,  3, &BR[br][2][1],  (Ull)c02[CHIP],(Ull)index_val, MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
// 	    mop(OP_LDR,  3, &BR[br][3][1],  (Ull)c03[CHIP],(Ull)index_val, MSK_W0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
// 	    exe(OP_FAD, &AR[ar][0], AR[ar_pre][0], EXP_H3210,  BR[br][0][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
// 	    exe(OP_FAD, &AR[ar][1], AR[ar_pre][1], EXP_H3210,  BR[br][1][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
// 	    exe(OP_FAD, &AR[ar][2], AR[ar_pre][2], EXP_H3210,  BR[br][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
// 	    exe(OP_FAD, &AR[ar][3], AR[ar_pre][3], EXP_H3210,  BR[br][3][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL);\
// 	    mop(OP_STR, 3, &AR[ar][0], (Ull)index_val, (Ull)c00[CHIP],  MSK_D0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
// 	    mop(OP_STR, 3, &AR[ar][1], (Ull)index_val, (Ull)c01[CHIP],  MSK_D0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
// 	    mop(OP_STR, 3, &AR[ar][2], (Ull)index_val, (Ull)c02[CHIP],  MSK_D0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP);\
// 	    mop(OP_STR, 3, &AR[ar][3], (Ull)index_val, (Ull)c03[CHIP],  MSK_D0, (Ull)c0[CHIP], A_row_size*RMGRP, 0, 1, (Ull)NULL, A_row_size*RMGRP)





// //EMAX5A begin mm2 mapdist=0
// /*3*/ for (CHIP=0; CHIP<NCHIP; CHIP++) { /* will be parallelized by multi-chip (M/#chip) */
//         //LOOP1--はLOOP1==1で終了するので、LOOP1はrow+1がよい
//   /*2*/ for (INIT1=1,LOOP1=RMGRP,cofs=(0-(Ull)1*8)<<32|((0-(Ull)B_row_size)&0xffffffff); LOOP1--; INIT1=0) {  /* stage#0 *//* mapped to FOR() on BR[63][1][0] */
//     /*1*/ for (INIT0=1,LOOP0=A_margin_tmp/(A_row_size/NCHIP),rofs=(0-(A_row_size/NCHIP))<<32|((0-(A_row_size/NCHIP))&0xffffffff); LOOP0--; INIT0=0) {      /* stage#0 *//* mapped to FOR() on BR[63][0][0] */
//             exe(OP_ADD,    &cofs,  cofs, EXP_H3210, INIT0?((Ull)1*8)<<32|((Ull)B_row_size):0, EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#0 */
//             exe(OP_ADD,    &rofs, INIT0?rofs:rofs, EXP_H3210, (A_row_size/NCHIP)<<32|((A_row_size/NCHIP)), EXP_H3210, 0LL, EXP_H3210, OP_AND, 0xffffffffffffffffLL, OP_NOP, 0LL);/* stage#0 */
//             exe(OP_ADD,    &rofs1, rofs, EXP_H3210, 0, EXP_H3210, 0, EXP_H3210, OP_NOP, 0LL, OP_SRL,1LL);                                           /* stage#1 */
//             exe(OP_ADD,    &cofs1, cofs, EXP_H3210, rofs, EXP_H3210, 0, EXP_H3210, OP_NOP, 0LL, OP_NOP,0LL);  //W*4*2*B_row_sizeを上下にコピー          /* stage#1 */
//             mop(OP_LDR,  3, &BR[1][2][1], (Ull)a_index_val[CHIP][0], (Ull)rofs, MSK_W0, (Ull)a_index_val[CHIP][0], A_margin, 0, 0, (Ull)NULL, A_margin);             /* stage#1 */

//             mop(OP_LDR,  3, &BR[2][0][1], (Ull)b0, BR[1][2][1], MSK_W0, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
//             mop(OP_LDR,  3, &BR[2][0][0], (Ull)b1, BR[1][2][1], MSK_W0, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
//             mop(OP_LDR,  3, &BR[2][1][1], (Ull)b2, BR[1][2][1], MSK_W0, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 */
//             mop(OP_LDR,  3, &BR[2][1][0], (Ull)b3, BR[1][2][1], MSK_W0, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL, RMGRP*B_row_size);             /* stage#2 2KB */
//             mop(OP_LDR,  3, &BR[2][2][1], (Ull)a_index_val[CHIP][1], (Ull)rofs, MSK_W0, (Ull)a_index_val[CHIP][1], A_row_size, 0, 0, (Ull)NULL, A_row_size); /* stage#2 16KB */

//             exe(OP_FML, &AR[3][0], BR[2][0][1], EXP_H3210,  BR[2][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
//             exe(OP_FML, &AR[3][1], BR[2][0][0], EXP_H3210,  BR[2][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
//             exe(OP_FML, &AR[3][2], BR[2][1][1], EXP_H3210,  BR[2][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
//             exe(OP_FML, &AR[3][3], BR[2][1][0], EXP_H3210,  BR[2][2][1], EXP_H3210, 0LL, EXP_H3210, OP_NOP, 0LL, OP_NOP, 0LL); /* stage#3 */
//             mop(OP_LDR,  3, &BR[3][0][1],  (Ull)b0,(Ull)BR[2][2][1], MSK_W1, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
//             mop(OP_LDR,  3, &BR[3][0][0],  (Ull)b1,(Ull)BR[2][2][1], MSK_W1, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
//             mop(OP_LDR,  3, &BR[3][1][1],  (Ull)b2,(Ull)BR[2][2][1], MSK_W1, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
//             mop(OP_LDR,  3, &BR[3][1][0],  (Ull)b3,(Ull)BR[2][2][1], MSK_W1, (Ull)b, RMGRP*B_row_size, 0, 0, (Ull)NULL,  RMGRP*B_row_size);
//             mop(OP_LDWR, 1, &BR[3][2][1],  (Ull)a[1],    (Ull)rofs, MSK_W0, (Ull)a[1], A_row_size, 0, 0, (Ull)NULL, A_row_size);
            
//             sparse_core1_1_CHIP_divA(5,  4,  5,  4,     2,           y,MSK_W0);
//             sparse_core1_1_CHIP_divA(6,  5,  6,  5,     3,           y,MSK_W1);
//             sparse_core1_1_CHIP_divA(7,  6,  7,  6,     4,           z,MSK_W0);
//             sparse_core1_1_CHIP_divA(8,  7,  8,  7,     5,           z,MSK_W1);
//             sparse_core1_1_CHIP_divA(9,  8,  9,  8,     6,           t,MSK_W0);
//             sparse_core1_1_CHIP_divA(10, 9,  10, 9,     7,           t,MSK_W1);

//             sparse_core2_CHIP_divA(  11, 10, 11, 10,        4,5,6,7,0);
//             sparse_core3_1_CHIP_divA(12, 11, 13, 11,    8,  x,y,z,t, x,MSK_W0);

//             sparse_core1_1_CHIP_divA(14, 11, 14, 13,    9,           x,MSK_W1);

//             sparse_core1_1_CHIP_divA(15, 14, 15, 14,    10,          y,MSK_W0);
//             sparse_core1_1_CHIP_divA(16, 15, 16, 15,    11,          y,MSK_W1);
//             sparse_core1_1_CHIP_divA(17, 16, 17, 16,    12,          z,MSK_W0);
//             sparse_core1_1_CHIP_divA(18, 17, 18, 17,    13,          z,MSK_W1);
//             sparse_core1_1_CHIP_divA(19, 18, 19, 18,    14,          t,MSK_W0);
//             sparse_core1_1_CHIP_divA(20, 19, 20, 19,    15,          t,MSK_W1);

//             sparse_core2_CHIP_divA(  21, 20, 21, 20,        8,9,10,11,8);
//             sparse_core3_1_CHIP_divA(22, 21, 23, 21,    16, x,y,z,t, x,MSK_W0);

//             sparse_core1_1_CHIP_divA(24, 21, 24, 23,    17,          x,MSK_W1);

//             sparse_core1_1_CHIP_divA(25, 24, 25, 24,    18,          y,MSK_W0);
//             sparse_core1_1_CHIP_divA(26, 25, 26, 25,    19,          y,MSK_W1);
//             sparse_core1_1_CHIP_divA(27, 26, 27, 26,    20,          z,MSK_W0);
//             sparse_core1_1_CHIP_divA(28, 27, 28, 27,    21,          z,MSK_W1);
//             sparse_core1_1_CHIP_divA(29, 28, 29, 28,    22,          t,MSK_W0);
//             sparse_core1_1_CHIP_divA(30, 29, 30, 29,    23,          t,MSK_W1);

//             sparse_core2_CHIP_divA(  31, 30, 31, 30,        12,13,14,15,8);
//             sparse_core3_1_CHIP_divA(32, 31, 33, 31,    24, x,y,z,t, x,MSK_W0);

//             sparse_core1_1_CHIP_divA(34, 31, 34, 33,    25,          x,MSK_W1);

//             sparse_core1_1_CHIP_divA(35, 34, 35, 34,    26,          y,MSK_W0);
//             sparse_core1_1_CHIP_divA(36, 35, 36, 35,    27,          y,MSK_W1);
//             sparse_core1_1_CHIP_divA(37, 36, 37, 36,    28,          z,MSK_W0);
//             sparse_core1_1_CHIP_divA(38, 37, 38, 37,    29,          z,MSK_W1);
//             sparse_core1_1_CHIP_divA(39, 38, 39, 38,    30,          t,MSK_W0);
//             sparse_core1_1_CHIP_divA(40, 39, 40, 39,    31,          t,MSK_W1);

//             sparse_core2_CHIP_divA(  41, 40, 41, 40,        16,17,18,19,16);
//             sparse_core3_1_CHIP_divA(42, 41, 43, 41,    32, x,y,z,t, x,MSK_W0);
   
//             sparse_core1_1_CHIP_divA(44, 41, 44, 43,    33,          x,MSK_W1);

//             sparse_core1_1_CHIP_divA(45, 44, 45, 44,    34,          y,MSK_W0);
//             sparse_core1_1_CHIP_divA(46, 45, 46, 45,    35,          y,MSK_W1);
//             sparse_core1_1_CHIP_divA(47, 46, 47, 46,    36,          z,MSK_W0);
//             sparse_core1_1_CHIP_divA(48, 47, 48, 47,    37,          z,MSK_W1);
//             sparse_core1_1_CHIP_divA(49, 48, 49, 48,    38,          t,MSK_W0);
//             sparse_core1_1_CHIP_divA(50, 49, 50, 49,    39,          t,MSK_W1);

//             sparse_core2_1_CHIP_divA(51, 50, 51, 50,        20,21,22,16);
//             sparse_core3_1_CHIP_divA(52, 51, 53, 51,    40, x,y,z,t, x,MSK_W0);
   
//             sparse_core1_1_CHIP_divA(54, 51, 54, 53,    41,           x,MSK_W1);

//             sparse_core1_1_CHIP_divA(55, 54, 55, 54,    42,             y,MSK_W0);
//             sparse_core1_1_CHIP_divA(56, 55, 56, 55,    43,             y,MSK_W1);
//             sparse_core1_1_CHIP_divA(57, 56, 57, 56,    44,             z,MSK_W0);
//             sparse_core1_1_CHIP_divA(58, 57, 58, 57,    45,             z,MSK_W1);
//             sparse_core4(  59, 58, 59, 58);

//             sparse_final_CHIP_divA(62,59,62,59,x);



//             }
//           }
//         }
// //EMAX5A end
//       }
//     }
//   }
// //EMAX5A drain_dirty_lmm
// }




