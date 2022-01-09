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
    // printf("malloc size %d \n",malloc_usable_size(*membase));
    // printf("membase_before_align: %08.8x\n", (Uint)*membase);
    // if ((Ull)*membase & (Ull)(alignment-1))
    // *membase = (void*)(((Ull)*membase & ~(Ull)(alignment-1))+alignment);
    // memset(membase, 0, memsize+alignment);
    int i;
    for(i=0;i<memsize/sizeof(Uint);i++) *((Uint*)*membase+i) = (Uint)0;


    
    // 32byte = 16byte*2 = 0x20
    // printf("membase_after_align: %08.8x\n", (Uint)*membase);

    
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


void mem_release(Uint memsize,Uchar** membase){
  // #if defined(ARMZYNQ) && defined(EMAX6)
    // {int i; for (i=0; i<(memsize+sizeof(Dll)-1)/sizeof(Dll); i++) *((Dll*)*membase+i)=0;}

    memset(*membase,0,memsize);
  // #else
  // if(*membase != NULL){
  //     free(*membase);
  //     *membase = NULL;
  //   }
  // #endif

}