
/* EMAX6 library                        */
/*         Copyright (C) 2013- by NAIST */
/*          Primary writer: Y.Nakashima */
/*                 nakashim@is.naist.jp */

/*******************************************************************************/
/******************************** Defs *****************************************/
/*******************************************************************************/

enum { NANOS_ARM, NANOS_DRAIN, NANOS_CONF, NANOS_REGV, NANOS_RANGE, NANOS_LOAD, NANOS_EXEC, NANOS_TOTAL, NANOS_CLASS };

typedef struct {
  Uint  f : 23;
  Uint  e :  8;
  Uint  s :  1;
} f32bit;

typedef struct {
  Uint  e :  6;
  Uint  b :  1;
  Uint  s :  1;
} u7bit;

typedef struct {
  Uint  e :  7;
  Uint  s :  1;
} u8bit;

typedef struct {
  Uchar u[8];
} u64bit;

#define abs(a)    ((a)>  0 ? (a) :-(a)    )
#define ad(a,b)   ((a)<(b)?(b)-(a):(a)-(b))
#define ss(a,b)   ((a)<(b)?   0   :(a)-(b))

/* dma_ctrl_space */
/* regmap of zynq ultrascale+ */
/* https://japan.xilinx.com/html_docs/registers/ug1087/ug1087-zynq-ultrascale-registers.html#_module_summary.html */
struct dma_ctrl {
  /*   Register Name		   Address	Width	Type	Reset Value	Description */
  Uint ZDMA_ERR_CTRL;    	/* 0x00000000	32	mixed	0x00000001	Enable/Disable a error response */
  Uint dmy0[63];
  Uint ZDMA_CH_ISR;      	/* 0x00000100	32	mixed	0x00000000	Interrupt Status Register for intrN. This is a sticky register that holds the value of the interrupt until cleared by a value of 1. */
  Uint ZDMA_CH_IMR;      	/* 0x00000104	32	mixed	0x00000FFF	Interrupt Mask Register for intrN. This is a read-only location and can be atomically altered by either the IDR or the IER. */
  Uint ZDMA_CH_IEN;      	/* 0x00000108	32	mixed	0x00000000	Interrupt Enable Register. A write of to this location will unmask the interrupt. (IMR: 0) */
  Uint ZDMA_CH_IDS;      	/* 0x0000010C	32	mixed	0x00000000	Interrupt Disable Register. A write of one to this location will mask the interrupt. (IMR: 1) */
  Uint ZDMA_CH_CTRL0;    	/* 0x00000110��	32	mixed	0x00000080	Channel Control Register 0 */
	/*   Field Name  Bits  Type Reset Value  Description            */
	/*   Reserved	 31:8  raz  0x0	         Reseved for future use */
	/*   OVR_FETCH	    7  rw   0x1	         0: DMA channel is not allowed to over-fetch on SRC */
	/*                                       1: DMA channel is allowed to over-fetch */
	/*                                       This field must remain stable while DMA Channel is enabled */
	/*   POINT_TYPE	    6  rw   0x0	       ��0: Simple mode DMA. Descriptor (DMA command) from APB register space. */
	/*                                       1: Scatter-gather mode DMA. Descriptor are stored in Memory. */
	/*                                       This field must remain stable while DMA Channel is enabled */
	/*   MODE	  5:4  rw   0x0	         00: Normal read & write DMA (default) */
	/*                                       01: Write only */
	/*                                       (uses data from WR_DMA_DATA*) */
	/*                                       10: Read only */
	/*                                       11: Reseved for future use */
	/*                                       This field must remain stable while DMA Channel is enabled */
	/*   RATE_CTRL	    3  rw   0x0	         Enable/Disable rate control */
	/*                                       0: rate control is disabled */
	/*                                       1: rate control is enabled, use rate control count to schedule AXI transaction (Read) */
	/*                                       This field must remain stable while DMA Channel is enabled */
	/*   CONT_ADDR	    2  rw   0x0	         Coming out of pause */
	/*                                       0: use continuous address(calculated from previous DSCR Addr) to fetch next descriptor */
	/*                                       1: use address specified in Start Address Register to fetch next descriptor on both SRC & DST side */
	/*   CONT	    1  wo   0x0	         Setting to 1 unpause (restarts from current position) the pauseed DMA */
	/*                                       SW sets this 1 to trigger. When DMA is unpaused , then hardware clears this bit. SW clear has no effect on it */
	/*   Reserved	    0  raz  0x0	         Reseved for future use */

  Uint ZDMA_CH_CTRL1;    	/* 0x00000114	32	mixed	0x000003FF	Channel Flow Control Register */
  Uint ZDMA_CH_FCI;      	/* 0x00000118	32	mixed 	0x00000000	Channel Control Register 1 */
  Uint ZDMA_CH_STATUS;   	/* 0x0000011C��	32	mixed	0x00000000	Channel Status Register */
	/*   Field Name  Bits  Type Reset Value  Description            */
	/*   Reserved    31:2  raz  0x0          Reseved for future use */
	/*   STATE        1:0  ro   0x0        ��00: Done with no error (as a result Enable bit is cleared by HW) */
	/*                                       01: paused with no error (as a result Enable bit remains set). */
	/*                                       10: DMA is busy transferring */
	/*                                     ��11: DMA done with error (error condition captured in otherregisters) */
	/*                                       This bit is cleared by HW when Enable or Unpause is set to 1. */

  Uint ZDMA_CH_DATA_ATTR;	/* 0x00000120	32	mixed	0x0483D20F	Channel DATA AXI parameter Register */
  Uint ZDMA_CH_DSCR_ATTR;	/* 0x00000124	32	mixed	0x00000000	Channel DSCR AXI parameter Register */
  Uint ZDMA_CH_SRC_DSCR_WORD0;	/* 0x00000128��	32	rw	0x00000000	SRC DSCR Word 0 */
  Uint ZDMA_CH_SRC_DSCR_WORD1;  /* 0x0000012C��	32	mixed	0x00000000	SRC DSCR Word 1 */
  Uint ZDMA_CH_SRC_DSCR_WORD2;  /* 0x00000130��	32	mixed	0x00000000	SRC DSCR Word 2 */
	/*   Field Name  Bits  Type Reset Value  Description            */
	/*   Reserved	 31:30 raz  0x0	         Reserved for furure use */
	/*   SIZE	 29:0  rw   0x0	         Buffer size in bytes (1G=2^30) */

  Uint ZDMA_CH_SRC_DSCR_WORD3;  /* 0x00000134	32	mixed	0x00000000	SRC DSCR Word 3 */
  Uint ZDMA_CH_DST_DSCR_WORD0;  /* 0x00000138��	32	rw	0x00000000	DST DSCR Word 0 */
  Uint ZDMA_CH_DST_DSCR_WORD1;  /* 0x0000013C��	32	mixed	0x00000000	DST DSCR Word 1 */
  Uint ZDMA_CH_DST_DSCR_WORD2;  /* 0x00000140��	32	mixed	0x00000000	DST DSCR Word 2 */
	/*   Field Name  Bits  Type Reset Value  Description            */
	/*   Reserved	 31:30 raz  0x0	         Reserved for furure use */
	/*   SIZE	 29:0  rw   0x0	         Buffer size in bytes (1G=2^30) */

  Uint ZDMA_CH_DST_DSCR_WORD3;  /* 0x00000144	32	mixed	0x00000000	DST DSCR Word 3 */
  Uint ZDMA_CH_WR_ONLY_WORD0;   /* 0x00000148	32	rw	0x00000000	Write Only Data Word 0 */
  Uint ZDMA_CH_WR_ONLY_WORD1;   /* 0x0000014C	32	rw	0x00000000	Write Only Data Word 1 */
  Uint ZDMA_CH_WR_ONLY_WORD2;   /* 0x00000150	32	rw	0x00000000	Write Only Data Word 2 */
  Uint ZDMA_CH_WR_ONLY_WORD3;   /* 0x00000154	32	rw	0x00000000	Write Only Data Word 3 */
  Uint ZDMA_CH_SRC_START_LSB;   /* 0x00000158	32	rw	0x00000000	SRC DSCR Start Address LSB Regiser */
  Uint ZDMA_CH_SRC_START_MSB;   /* 0x0000015C	32	mixed	0x00000000	SRC DSCR Start Address MSB Regiser */
  Uint ZDMA_CH_DST_START_LSB;   /* 0x00000160	32	rw	0x00000000	DST DSCR Start Address LSB Regiser */
  Uint ZDMA_CH_DST_START_MSB;   /* 0x00000164	32	mixed	0x00000000	DST DSCR Start Address MSB Regiser */
  Uint dmy1[9];
  Uint ZDMA_CH_RATE_CTRL;       /* 0x0000018C	32	mixed	0x00000000	Rate Control Count Register */
  Uint ZDMA_CH_IRQ_SRC_ACCT;    /* 0x00000190	32	mixed	0x00000000	SRC Interrupt Account Count Register */
  Uint ZDMA_CH_IRQ_DST_ACCT;    /* 0x00000194	32	mixed	0x00000000	DST Interrupt Account Count Register */
  Uint dmy2[26];
  Uint ZDMA_CH_CTRL2;  		/* 0x00000200��	32	mixed	0x00000000	zDMA Control Register 2 */
	/*   Field Name  Bits  Type Reset Value  Description            */
	/*   Reserved	 31:1  raz  0x0	         Reseved for future use */
	/*   EN	            0  rw   0x0	         Channel is enabled */
	/*                                       SW sets this 1 to trigger. If DMA channel is in pause and this bit is cleared by software */
	/*                                       then DMA channel goes to disable state when SW set CONT bit. */
	/*                                       HW clears this flag after finishing DMA opertion. */

  /* Simple Mode */
  /* 1. ZDMA_CH_STATUS �쥸�������ɤ߽Ф���STATE��00�ޤ���11(DMA��IDLE���ơ���) �ˤʤ�ޤ��Ԥ�. */
  /*    DMA��PAUSE���ơ��Ȥξ�硢�֥���ͥ�����ߡפ�����������˽��ä� PAUSE ���ơ��Ȥ�λ. */
  /* 2. ZDMA_CH_CTRL0�쥸������ POINT_TYPE (�ӥå� 6) �� 0 ������ */
  /*    �ǡ����������Хåե��Υ��ɥ쥹�� LSB �� ZDMA_CH_SRC_DSCR_WORD0�쥸�����˽񤭹��� */
  /*    �ǡ����������Хåե��Υ��ɥ쥹�� MSB �� ZDMA_CH_SRC_DSCR_WORD1�쥸�����˽񤭹��� */
  /* 3. �ǡ����ǥ��ƥ��͡������Хåե��Υ��ɥ쥹�� LSB �� ZDMA_CH_DST_DSCR_WORD0�쥸�����˽񤭹��� */
  /*    �ǡ����ǥ��ƥ��͡������Хåե��Υ��ɥ쥹�� MSB �� ZDMA_CH_DST_DSCR_WORD1�쥸�����˽񤭹��� */
  /* 4. Simple Mode�Ǥϡ�SRC�ȥ�󥶥�����󥵥�����DST�ȥ�󥶥�����󥵥�����ξ�������ꤹ��ɬ�פ����� */
  /*    DMA �� SRC�ȥ�󥶥�����󥵥�������Ѥ��ޤ�����ξ���Υ쥸���������ꤷ�Ƥ���ɬ�פ����� */
  /*    ZDMA_CH_SRC_DSCR_WORD2 �쥸�����˥������ǡ�����������񤭹��� */
  /*    ZDMA_CH_DST_DSCR_WORD2 �쥸�����˥ǥ��ƥ��͡������ȥ�󥶥�����󥵥�����񤭹��� */
  /*    SRC�ȥ�󥶥�����󥵥�����DST�ȥ�󥶥�����󥵥�����ɬ��Ʊ�� */
  /* 5. ɬ�פ˱���,ZDMA_CH_DST_DSCR_WORD3�����ZDMA_CH_SRC_DSCR_WORD3�쥸������INTR��1�˥��åȤ������ߤ�ͭ���ˤ��� */
  /* 6. ����������ӥǥ��ƥ��͡������Хåե�������å��女�ҡ����ȤȤ��Ƴ�����Ƥ��Ƥ��뤫�ե�å��夵��Ƥ�����, */
  /*    COHRNT�򥻥åȤ���ɬ�פϤʤ�. ����ʳ��ξ��,����������ӥǥ��ƥ��͡������Хåե�������å��女�ҡ����ȤȤ��� */
  /*    ������Ƥ��Ƥ��ʤ����ޤ��ϥե�å��夵��Ƥ��ʤ���硢ZDMA_CH_SRC_DSCR_WORD3�����ZDMA_CH_DST_DSCR_WORD3�쥸������ */
  /*    ���줾�� COHRNT�򥻥åȤ���. COHRNT�ӥåȤ� LPD-DMA �ξ��Τ�ͭ��. FPD-DMA�ϥ��ҡ���󥷤򥵥ݡ��Ȥ��ʤ�. */
  /* 7. ZDMA_CH_CTRL2�쥸������EN�ӥåȤ򥻥åȤ���,DMAž���˻��Ѥ���DMA����ͥ��ͭ���ˤ���. */
  /*    DMA��ͭ���ˤ����塢�֥��顼���פ˼������顼��������å�����. */
};

/* reg_ctrl */
enum { EXRING_IDLE, EXRING_BUSY};
enum { LMRING_IDLE, LMRING_BUSY};
enum { CMD_NOP, CMD_RESET, CMD_SCON, CMD_EXEC};
struct reg_ctrl {
  struct i0 {
    Ull  stat; /* +0000 bit7-4:LMRING, bit3-0:EXRING */
    Uint mcid; /* +0008 maximum chip-ID of IMAX (<EMAX_NCHIP) to be chained (activated) */
    Uint dmy0;
    Uint cmd;  /* +0010 host writes Ull cmd then chip# is propagated to succesors */
  /*Uint cid;*//* +0012 chip# ( set by write to cmd ) */
    Uint dmy1;
    Ull  dmy2;
    Ull  adtr; /* +0020 */
    Ull  dmy3;
    Ull  csel; /* +0030 */
    Ull  dmrp; /* +0038 DMAREAD-PREF */
    Ull  dmy4[1016];
    struct conf                    conf[AMAP_DEPTH][EMAX_WIDTH];  /* +2000-3fff */
    struct {Ull  br[UNIT_WIDTH];}  breg[AMAP_DEPTH][EMAX_WIDTH];  /* +4000-5fff *//* unit[cid][EMAX_DEPTH].breg[x][EMAX_WIDTH].br[UNIT_WIDTH] is used */
    struct {Uint ea0b ; /* ea0 base   (for avoiding ld-mask-st, should be extended to 32bits (lower 18bit is available)) */
      /*Ull  dmy0 :14;*/
        Uint ea0o ; /* ea0 offset (for avoiding ld-mask-st, should be extended to 32bits (lower 18bit is available)) */
      /*Ull  dmy1 :14;*/
        Uint ea1b ; /* ea1 base   (for avoiding ld-mask-st, should be extended to 32bits (lower 18bit is available)) */
      /*Ull  dmy2 :14;*/
        Uint ea1o ; /* ea1 offset (for avoiding ld-mask-st, should be extended to 32bits (lower 18bit is available)) */
      /*Ull  dmy3 :14;*/
        Uint top  ; /* LMM-top virtual-address */
      /*Ull  dmy4 : 1;*/
        Uint bot  ; /* LMM-bot virtual-address */
      /*Ull  dmy5 : 1;*/
        Ull  dmy6 ;}           addr[AMAP_DEPTH][EMAX_WIDTH];  /* +6000-7fff */
    struct {Ull  reg[UNIT_WIDTH];} lddmrw[AMAP_DEPTH][EMAX_WIDTH];/* +8000-9fff *//* lddmq/trans-r,lddmq-w */
    Ull dmy5[3072]; /* +a000-ffff */
  } i[EMAX_NCHIP]; /* 0000-ffff */
};

/* emax6 host control */
enum { STATUS_IDLE, STATUS_CONF, STATUS_SCON, STATUS_REGV, STATUS_RANGE, STATUS_DRAIN, STATUS_LOAD, STATUS_START, STATUS_EXEC, STATUS_TERM };

struct emax6 { /* host status of EMAX6 */
  volatile Ull   dma_ctrl;  /* struct dma_ctrl *dma_ctrl  DMA control */
  volatile Ull   reg_ctrl;  /* struct reg_ctrl *reg_ctrl  REG control */

  Ull   status            : 4;
  Ull   csel_save         : 2;
  Ull   last_conf            ; /* for insn_reuse */
  Ull   lmmic             : 1; /* 0:lmm[0] is curent, 1:lmm[1] is current */
  Ull   lmmio             : 1; /* 0:lmm[0] is prev,   1:lmm[1] is prev    */
  Ull   mapdist           : 6; /* specified mapdist */
  Ull   lastdist          : 6; /* lastdist for DYNAMIC_SCON */
  struct lmmi lmmi[EMAX_NCHIP][EMAX_DEPTH][EMAX_WIDTH][2]; /* lmmi for host (len/ofs/top are resolved) */
  Ull   lmmi_bitmap[EMAX_WIDTH];      /* based on lmmi[*][EMAX_WIDTH][2].v */
  Uchar lmmd[EMAX_DEPTH][EMAX_WIDTH]; /* chip#7,6,..,0:clean, 1:dirty, exec��store�ս��1, drainľ��0 */

#ifndef IGNORE_LMMI_BLKGATHER
  Ull   plist                ; /* pointer-list */
  Ull   blkcount          : 7; /* active block number */
  Ull   blksize           : 9; /* 1:64 2:128 3:256 dwords */
  Ull   lmmblktop            ; /* LMM-addr     for LDRQ(blk>0) */
  Ull   lmmblklen            ; /* total dwords for LDRQ(blk>0) */
#endif

  Ull   rw                    ; /* 0:load(mem->lmm), 1:store(lmm->mem)      */
  Ull   ddraddr               ; /* ddr-address                              */
  Ull   lmmaddr               ; /* lmm-address                              */
  Ull   dmalen                ; /* dma-length                               */

#ifndef IGNORE_LDDMQ_HANDSHAKE
  Ull   fsm_busy          : 1; /* for LDDMQ and TR */
  Ull   lmwd_valid        : 1; /* for LDDMQ */
  Ull   tcureg_valid      : 1; /* fsm->ARM   0 -> 1 -> 1 -> 0 -> 0 -> 0                              */
  Ull   tcureg_ready      : 1; /* fsm<-ARM   0 -> 0 -> 1 -> 0 -> 0 -> 0                              */
  Ull   tcureg_last       : 1; /* fsm->ARM   0 -> 0 -> 0 -> 1 -> 1 -> 0                              */
  Ull   tcureg_term       : 1; /* fsm<-ARM   0 -> 0 -> 0 -> 0 -> 1 -> 0                              */
  Ull   tcureg[UNIT_WIDTH]   ; /* tcu-data        of tcu                       v                     */
                               /* from ARM:  svc 0x1010 ... tcureg_valid->x0                         */
                               /* from ARM:  svc 0x1011 ... 1->tcureg_ready                          */
                               /* from ARM:  svc 0x1012 ... tcureg_last->x0                          */
                               /* from ARM:  svc 0x1013 ... 1->tcureg_term                           */
                               /* from ARM:  svc 0x1014 ... tcureg[3:0]->x3,2,1,0                    */
#endif
} emax6;

volatile struct emax_info {
  Ull  dma_phys;     // kern-phys
  Ull  dma_vadr;     // not used
  Ull  dma_mmap;     // user-virt Contiguous 64K register space
  Ull  reg_phys;     // kern-phys
  Ull  reg_vadr;     // not used
  Ull  reg_mmap;     // user-virt Contiguous 4GB space including LMM space
  Ull  lmm_phys;     // kern-phys
  Ull  lmm_vadr;     // not used
  Ull  lmm_mmap;     // user-virt Contiguous 2GB space for LMM space
  Ull  ddr_phys;     // kern-phys
  Ull  ddr_vadr;     // not used
  Ull  ddr_mmap;     // user-virt Contiguous 2GB space in DDR-high-2GB space
  int  driver_use_1;
  int  driver_use_2;
} emax_info;

/*  ... for ARMSIML only */
#define DMA_BASE2_PHYS	 0x50000000
#define REG_BASE2_PHYS	 0x50100000
#define REG_CONF_OFFS    0x00002000
#define REG_BREG_OFFS    0x00004000
#define REG_ADDR_OFFS    0x00006000
#define REG_LDDM_OFFS    0x00008000
#define REG_AREA_MASK    0x0000ffff
#define LMM_BASE2_PHYS 	 0x60000000
#define MEM_VALID_ADDR	 0xafffffff

#ifndef NO_EMAX6LIB_BODY

#ifdef ARMZYNQ
/*******************************************************************************/
/******************************** ZYNQ-COMMON **********************************/
/*******************************************************************************/

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <linux/ioctl.h>

#define DMA_BASE_PHYS	 0x00000000fd500000LL
/*  ... fixed */
#define DMA_MMAP_SIZE	 0x0000000000010000LL
/*  ... 64KB  */
#define REG_BASE_PHYS	 0x0000000400000000LL
/*  ... fixed */
#define REG_MMAP_SIZE	 0x0000000100000000LL
/*  ... 4GB(including REGS) */
#define LMM_BASE_PHYS	 0x0000000480000000LL
/*  ... fixed */
#define DDR_BASE_PHYS	 0x0000000800000000LL
/*  ... fixed */
#define DDR_MMAP_SIZE	 0x0000000080000000LL
/*  ... 2GB   */

#define EMAX_IOC_MAGIC  60
/* Please use a different 8-bit number in your code */
#define EMAX_IORESET			_IO( EMAX_IOC_MAGIC, 0)
#define EMAX_GET_ACPMEM			_IOWR(EMAX_IOC_MAGIC,  1, unsigned long)
#define EMAX_IOC_MAXNR 2

static int filter(struct dirent *dir)
{
  return dir->d_name[0] == '.' ? 0 : 1;
}

static void trim(char *d_name)
{
  char *p = strchr(d_name, '\n');
  if (p != NULL) *p = '\0';
}

static int is_dma_dev(char *d_name)
{
  char path[32];
  char name[32];
  FILE *fp;
  sprintf(path, "/sys/class/uio/%s/name", d_name);
  if ((fp = fopen(path, "r")) == NULL) return 0;
  if (fgets(name, sizeof(name), fp) == NULL) {
    fclose(fp);
    return 0;
  }
  fclose(fp);
  if (strcmp(name, "dma\n") != 0) return 0;
  return 1;
}

static int get_reg_size(char *d_name)
{
  char path[32];
  char size[32];
  FILE *fp;
  sprintf(path, "/sys/class/uio/%s/maps/map0/size", d_name);
  if ((fp = fopen(path, "r")) == NULL) return 0;
  if (fgets(size, sizeof(size), fp) == NULL) {
    fclose(fp);
    return 0;
  }
  fclose(fp);
  return strtoull(size, NULL, 16);
}

emax6_open()
/* HPM���ͳ��������쥸�����˥ꥻ�å����� */
/* HPP���ͳ�������������۶��֤˼��� */
/* ACP���ͳ����conf/lmmi/regv���֤��۶��֤˼��� */
{
  struct dirent **namelist;
  int num_dirs, dir;
  int reg_size;
  int  fd_dma_found = 0;
  char path[1024];
  int  fd_dma;
  int  fd_reg;
  int  fd_ddr;

  if ((fd_reg = open("/dev/uio8", O_RDWR | O_SYNC)) == -1) {
    printf("open(\"/dev/uio8\", ...) failed.\n");
    return (NULL);
  }
  if ((fd_ddr = open("/dev/uio9", O_RDWR | O_SYNC)) == -1) {
    printf("open(\"/dev/uio9\", ...) failed.\n");
    return (NULL);
  }

  // mmap(cache-off) 4KB aligned
  emax_info.reg_phys = REG_BASE_PHYS;
  emax_info.reg_mmap = (Ull)mmap(NULL, REG_MMAP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd_reg, 0); /* 4GB */
  if (emax_info.reg_mmap == MAP_FAILED) {
    printf("fd_reg mmap() failed.\n");
    return (NULL);
  }
  emax_info.lmm_phys = LMM_BASE_PHYS;
  emax_info.lmm_mmap = emax_info.reg_mmap + (LMM_BASE_PHYS - REG_BASE_PHYS);

  // mmap(cache-on)  4KB aligned
  emax_info.ddr_phys = DDR_BASE_PHYS;
  emax_info.ddr_mmap = (Ull)mmap(NULL, DDR_MMAP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd_ddr, 0); /* 2GB */
  if (emax_info.ddr_mmap == MAP_FAILED) {
    printf("fd_ddr mmap() failed.\n");
    return (NULL);
  }

  if ((num_dirs = scandir("/sys/class/uio", &namelist, filter, alphasort)) == -1)
    return (NULL);

  for (dir = 0; dir < num_dirs; ++dir) {
    trim(namelist[dir]->d_name);
    if (!is_dma_dev(namelist[dir]->d_name)) {
      free(namelist[dir]);
      continue;
    }
    if ((reg_size = get_reg_size(namelist[dir]->d_name)) == 0) {
      free(namelist[dir]);
      continue;
    }

    sprintf(path, "/dev/%s", namelist[dir]->d_name);
    free(namelist[dir]);
    if ((fd_dma = open(path, O_RDWR | O_SYNC)) == -1)
      continue;
    emax_info.dma_phys = DMA_BASE_PHYS;
    emax_info.dma_mmap = (Ull)mmap(NULL, reg_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd_dma, 0);
    close(fd_dma);
    if (emax_info.dma_mmap == MAP_FAILED)
      continue;
    fd_dma_found++;
    break;
  }
  free(namelist);

  if (fd_dma_found) {
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_ERR_CTRL          = 0x00000001;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_ISR            = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_IMR            = 0x00000FFF;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_IEN            = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_IDS            = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_CTRL0          = 0x00000080;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_CTRL1          = 0x000003FF;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_FCI            = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_STATUS         = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DATA_ATTR      = 0x04C3D30F; /* Note - AxCACHE: 0011 value recomended by Xilinx. */
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DSCR_ATTR      = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_SRC_DSCR_WORD0 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_SRC_DSCR_WORD1 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_SRC_DSCR_WORD2 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_SRC_DSCR_WORD3 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DST_DSCR_WORD0 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DST_DSCR_WORD1 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DST_DSCR_WORD2 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DST_DSCR_WORD3 = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_WR_ONLY_WORD0  = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_WR_ONLY_WORD1  = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_WR_ONLY_WORD2  = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_WR_ONLY_WORD3  = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_SRC_START_LSB  = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_SRC_START_MSB  = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DST_START_LSB  = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_DST_START_MSB  = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_RATE_CTRL      = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_IRQ_SRC_ACCT   = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_IRQ_DST_ACCT   = 0x00000000;
    ((struct dma_ctrl*)emax_info.dma_mmap)->ZDMA_CH_CTRL2          = 0x00000000;
  }
  return (1);
}
#endif

/*******************************************************************************/
/******************************** Timer ****************************************/
/*******************************************************************************/

Ull nanosec_sav;
Ull nanosec[NANOS_CLASS];

reset_nanosec()
{
  int i;
  for (i=0; i<NANOS_CLASS; i++)
    nanosec[i] = 0;
#if defined(ARMSIML)
  nanosec_sav = _getclk(0);
#else
  struct timespec ts;
  clock_gettime(0, &ts); /*CLOCK_REALTIME*/
  nanosec_sav = 1000000000*ts.tv_sec + ts.tv_nsec;
#endif
}

get_nanosec(int class)
{
  Ull nanosec_now;
#if defined(ARMSIML)
  nanosec_now = _getclk(0);
  nanosec[class] += nanosec_now - nanosec_sav;
  nanosec[NANOS_TOTAL] += nanosec_now - nanosec_sav;
  nanosec_sav = nanosec_now;
#else
  struct timespec ts;
  clock_gettime(0, &ts); /*CLOCK_REALTIME*/
  nanosec_now = 1000000000*ts.tv_sec + ts.tv_nsec;
  nanosec[class] += nanosec_now - nanosec_sav;
  nanosec[NANOS_TOTAL] += nanosec_now - nanosec_sav;
  nanosec_sav = nanosec_now;
#endif
}

show_nanosec()
{
#if defined(ARMSIML)
  printf("SIML_cycle: ARM:%llu DRAIN:%llu CONF:%llu REGV:%llu RANGE:%llu LOAD:%llu EXEC:%llu total:%llu\n",
	 nanosec[NANOS_ARM],
	 nanosec[NANOS_DRAIN],
	 nanosec[NANOS_CONF],
	 nanosec[NANOS_REGV],
	 nanosec[NANOS_RANGE],
	 nanosec[NANOS_LOAD],
	 nanosec[NANOS_EXEC],
	 nanosec[NANOS_TOTAL]);
#else
  printf("nanosec: ARM:%llu DRAIN:%llu CONF:%llu REGV:%llu RANGE:%llu LOAD:%llu EXEC:%llu total:%llu\n",
	 nanosec[NANOS_ARM],
	 nanosec[NANOS_DRAIN],
	 nanosec[NANOS_CONF],
	 nanosec[NANOS_REGV],
	 nanosec[NANOS_RANGE],
	 nanosec[NANOS_LOAD],
	 nanosec[NANOS_EXEC],
	 nanosec[NANOS_TOTAL]);
#endif
}

/*******************************************************************************/
/******************************** DMA-START ************************************/
/*******************************************************************************/

#if !defined(EMAXNC)
emax6_check_lmmi_and_dma(int mode, int phase, int lastdist, int c, int i, int j)
{
  /* mode   0:array, 1:drain */
  /* phase  0:nop,   1:drain, 2:load, 3exec */
  /* lastdist */
  /* i      row              */
  /* j      col              */
  /* lmmi������˸ƤФ��. lmd��Ϣ��lmd���֤����lmr/lmx�򸡺�(+lastdist����ͳ) */
  /*                   ����lmd    ���֤�,"lmmi[i         ][lmmic]" */
  /* lastdist=>0�ξ��,����lmw/lmx���֤�,"lmmi[i+lastdist][lmmio]" */
  /* ����,lmd�ξ��,SCON���Ƥ⤷�ʤ��Ƥ�EXEC��Ʊ����DRAIN (lastdist=0�ξ���lmm��Ⱦʬ��lmd/lmw�˻Ȥ�ʬ��������) */
  /* lastdist=0�ξ��,DYNAMIC_SCON��̵��̣�ʤΤǽ����̤� */
  /* lastdist>0�ξ��,DYNAMIC_SCON����SCONͭ��Ͻ����̤� */
  /*                 SCON̵��ξ��,���⤽��lmd���֤����ʤ��Τ�lmd�����̵�뤹�٤�.��lmw/lmx��EXEC��DRAIN��ɬ�� */
  /*                 ������������,lmd��Ȥ��������Ǥ�DYNAMIC_SCON��Ȥ�ʤ��Ϥ��ʤΤ�,�����б����ʤ� */
  int k, m = (i+lastdist)%EMAX_DEPTH; /* lmmo-index */
  int lmmc_topz;
  int lmmc_ofsz;
  int lmmo_stat;
  int lmmc_stat;
  int lmm_ready;
  int lmm_readz;
  int mark;

  /* check_lmmi */
  if ((mode==0 && phase == 1) || phase == 2 || phase == 3) { /* (array && drain) || load || exec */
    lmmc_topz =  (emax6.lmmi[c][i][j][emax6.lmmic].top == 0);
    lmmc_ofsz =  (emax6.lmmi[c][i][j][emax6.lmmic].ofs == 0);
    lmmo_stat = ((emax6.lmmi[c][m][j][emax6.lmmio].v)<<3)
	        |(emax6.lmmi[c][m][j][emax6.lmmio].rw<<2)|(emax6.lmmi[c][m][j][emax6.lmmio].f<<1)|(emax6.lmmi[c][m][j][emax6.lmmio].p); /* v|rw|f|p */
    lmmc_stat = ((emax6.lmmi[c][i][j][emax6.lmmic].v & ~emax6.lmmi[c][i][j][emax6.lmmic].hcopy & ~emax6.lmmi[c][i][j][emax6.lmmic].vcopy & ((emax6.lmmi[c][i][j][emax6.lmmic].f&emax6.lmmi[c][i][j][emax6.lmmic].p) | !lmmc_topz))<<3)
                                                                                          /* v= ~copy & (OP_LDDMQ/OP_TR �ޤ��� ptop!=NULL) */
	        |(emax6.lmmi[c][i][j][emax6.lmmic].rw<<2)|(emax6.lmmi[c][i][j][emax6.lmmic].f<<1)|(emax6.lmmi[c][i][j][emax6.lmmic].p); /* v|rw|f|p */
    lmm_ready =  (emax6.lmmi[c][m][j][emax6.lmmio].v && emax6.lmmi[c][m][j][emax6.lmmio].blk == emax6.lmmi[c][i][j][emax6.lmmic].blk
		                                     && emax6.lmmi[c][m][j][emax6.lmmio].len == emax6.lmmi[c][i][j][emax6.lmmic].len
                                                     && emax6.lmmi[c][m][j][emax6.lmmio].top == emax6.lmmi[c][i][j][emax6.lmmic].top);
    lmm_readz =  (emax6.lmmi[c][m][j][emax6.lmmio].v && emax6.lmmi[c][m][j][emax6.lmmio].blk == emax6.lmmi[c][i][j][emax6.lmmic].blk
		                                     && emax6.lmmi[c][m][j][emax6.lmmio].len == emax6.lmmi[c][i][j][emax6.lmmic].len
		                                     &&(emax6.lmmi[c][m][j][emax6.lmmio].top+(Sll)(int)emax6.lmmi[c][m][j][emax6.lmmio].ofs) == emax6.lmmi[c][i][j][emax6.lmmic].top);
  }

  if      (mode==0 && phase == 1) { /* drain */
    if      (lmmo_stat==12 && lmmc_stat!=13 && (emax6.lmmd[m][j]&1<<c)) { mark = 1; emax6.lmmd[m][j] &= ~(1<<c);} /* ��2 lmw&!lmd drain */
    else if (lmmo_stat==14 && !lmm_ready    && (emax6.lmmd[m][j]&1<<c)) { mark = 1; emax6.lmmd[m][j] &= ~(1<<c);} /* ��4 lmx      drain */
    else                                                                { mark = 0;                             }
  }
  else if (mode==1 && phase == 1) { /* drain */
    if (                                       (emax6.lmmd[i][j]&1<<c)) { mark = 1; emax6.lmmd[i][j] &= ~(1<<c);} /* ��  drain_dirty_lmm */
    else                                                                { mark = 0;                             }
  }
  else if (phase == 2) { /* load */
    if      (lmmc_stat== 8               && !lmm_ready)                 { mark = 1;                             } /* ��1 lmr & !ready */
    else if (lmmc_stat== 9 && !lmmc_ofsz && !lmm_readz)                 { mark = 1;                             } /* ��7 lmp & !readz */
    else if (lmmc_stat==10)                                             { mark = 1;                             } /* ��3 lmf always load */
    else if (lmmc_stat==14               && !lmm_ready)                 { mark = 1;                             } /* ��3 lmx always load */
    else                                                                { mark = 0;                             } /* skip load */
  }
  else if (phase == 3) { /* exec */
    if      (lmmc_stat== 9                                            ) { mark = 1;                             } /* ��5 lmp */
    else if (lmmc_stat==12 || lmmc_stat==14                           ) { mark = 0; emax6.lmmd[i][j] |=  (1<<c);} /* ��6 lmw/lmx */
    else if (lmmc_stat==13)                       { mark = (emax6.lmmd[m][j]&1<<c); emax6.lmmd[m][j] |= ((!lastdist)<<c);} /* ��6 lmd & dirty */
#ifndef IGNORE_LDDMQ_HANDSHAKE
//  else if (lmmc_stat==11                                            ) { mark = 1;                             } /*     LDDMQ */
//  else if (lmmc_stat==15                                            ) { mark = 1;                             } /*     TR */
#endif
    else                                                                { mark = 0;                             } /* skip pdrain/pload */
  }

  /* dma */
  if (mark) {
    if (phase == 1) { /* drain */
      emax6.rw     = 1; /* lmm->mem */
      emax6.ddraddr = (mode==0)?emax6.lmmi[c][m][j][emax6.lmmio].top:emax6.lmmi[c][i][j][emax6.lmmic].top; /* address should be 4B-aligned */
      emax6.lmmaddr = emax6.ddraddr;
      emax6.dmalen  = (mode==0)?emax6.lmmi[c][m][j][emax6.lmmio].len:emax6.lmmi[c][i][j][emax6.lmmic].len; /* length should be # of words */
    }
    else if (phase == 3 && emax6.lmmi[c][i][j][emax6.lmmic].rw==1) { /* pdrain */
      emax6.rw     = 1; /* lmm->mem */
      emax6.ddraddr = emax6.lmmi[c][i][j][emax6.lmmic].top+(Sll)(int)emax6.lmmi[c][i][j][emax6.lmmic].ofs; /* ������PDRAIN address should be 4B-aligned */
      emax6.lmmaddr = emax6.ddraddr;
      emax6.dmalen  = emax6.lmmi[c][i][j][emax6.lmmic].len; /* length should be # of words */
    }
    else if (phase == 2                                            /* load */
	  ||(phase == 3 && emax6.lmmi[c][i][j][emax6.lmmic].rw==0)) { /* pload *//* address should be 4B-aligned *//* length should be # of words */
      emax6.rw     = 0; /* mem->lmm */
      if (emax6.lmmi[c][i][j][emax6.lmmic].blk==0) { /* inf */
	if (phase == 2) /* load */
	  emax6.ddraddr = emax6.lmmi[c][i][j][emax6.lmmic].top; /* address should be 4B-aligned */
	else
	  emax6.ddraddr = emax6.lmmi[c][i][j][emax6.lmmic].top+(Sll)(int)emax6.lmmi[c][i][j][emax6.lmmic].ofs; /* ������PLOAD address should be 4B-aligned */
	emax6.lmmaddr   = emax6.ddraddr;
	emax6.dmalen    = emax6.lmmi[c][i][j][emax6.lmmic].len; /* length should be # of words */
#ifndef IGNORE_LMMI_BLKGATHER
	emax6.blksize    = 0; /* max:10bit */
#endif
      }
#ifndef IGNORE_LMMI_BLKGATHER
      else { /* 16,32,64 */
	if (phase == 2) /* load */
	  emax6.plist = emax6.lmmi[c][i][j][emax6.lmmic].top+emax6.blkcount*8; /* address should be 4B-aligned */
	else
	  emax6.plist = emax6.lmmi[c][i][j][emax6.lmmic].top+emax6.blkcount*8+(Sll)(int)emax6.lmmi[c][i][j][emax6.lmmic].ofs; /* ������PLOAD address should be 4B-aligned */
	emax6.blksize  = 32<<emax6.lmmi[c][i][j][emax6.lmmic].blk; /* max:10bit */
	if (emax6.blkcount==0) {
	  emax6.lmmblktop = 0; /* ������̤���������� ��Ƭ���ɥ쥹��0�ʤΤ�,addr_range�˹��פ�ɬ�� */
	  emax6.lmmblklen = emax6.lmmi[c][i][j][emax6.lmmic].len; /* length should be # of words */
	}
	emax6.ddraddr    = emax6.plist; /* address should be 4B-aligned */
	emax6.lmmaddr    = emax6.lmmblktop;
	emax6.dmalen     = (emax6.lmmblklen<emax6.blksize)?emax6.lmmblklen:emax6.blksize-1;
	emax6.lmmblktop += emax6.blksize*sizeof(Ull);
	emax6.lmmblklen = (emax6.lmmblklen<emax6.blksize)?0:(emax6.lmmblklen-emax6.blksize);
	if (emax6.lmmblklen==0)
	  emax6.blkcount = 0;
	else
	  emax6.blkcount++; /* ������̤���������� continue ʣ�����DMA��ư��ɬ�� */
      }
#endif
    }
#if 0
printf("====DMA mode=%x phase=%x i=%x m=%x j=%x lmmic/o=%x/%x lmmc_stat=%x(dirty=%x) lmmo_stat=%x(dirty=%x) mark=%x\n", mode, phase, i, m, j, emax6.lmmic, emax6.lmmio, lmmc_stat, emax6.lmmd[i][j], lmmo_stat, emax6.lmmd[m][j], mark);
printf("        rw=%d ddraddr=%08.8x lmmaddr=%08.8x dmalen=%d", emax6.rw, (Uint)emax6.ddraddr, (Uint)emax6.lmmaddr, (Uint)emax6.dmalen);
#endif
    emax6_kick_dma(j);
  }
}

emax6_kick_dma(int j) /* col */
{
  int status;
  Ull dst, src;
  Uint pio_words, pio_loop, pio_i, pio_b4, pio_b8, pio_b16, pio_e4, pio_e8, pio_e16;

  if (!emax6.ddraddr)
    return (0);

  if (j != emax6.csel_save) {
    ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].csel = j; /* DMA/LDDMQ/TRANS�Ѥ��о�col���å� */
    emax6.csel_save = j;
  }
#if defined(FPDDMA)
  /* kick dma_ctrl (Simple Mode) */
  /* 1. ZDMA_CH_STATUS �쥸�������ɤ߽Ф���STATE��00�ޤ���11(DMA��IDLE���ơ���) �ˤʤ�ޤ��Ԥ�. */
  /*    DMA��PAUSE���ơ��Ȥξ�硢�֥���ͥ�����ߡפ�����������˽��ä� PAUSE ���ơ��Ȥ�λ. */

  // �Ǹ�˰�ư
       
  /* 2. ZDMA_CH_CTRL0�쥸������ POINT_TYPE (�ӥå� 6) �� 0 ������ */
  /*    �ǡ����������Хåե��Υ��ɥ쥹�� LSB �� ZDMA_CH_SRC_DSCR_WORD0�쥸�����˽񤭹��� */
  /*    �ǡ����������Хåե��Υ��ɥ쥹�� MSB �� ZDMA_CH_SRC_DSCR_WORD1�쥸�����˽񤭹��� */
  /* 3. �ǡ����ǥ��ƥ��͡������Хåե��Υ��ɥ쥹�� LSB �� ZDMA_CH_DST_DSCR_WORD0�쥸�����˽񤭹��� */
  /*    �ǡ����ǥ��ƥ��͡������Хåե��Υ��ɥ쥹�� MSB �� ZDMA_CH_DST_DSCR_WORD1�쥸�����˽񤭹��� */
  /* 4. Simple Mode�Ǥϡ�SRC�ȥ�󥶥�����󥵥�����DST�ȥ�󥶥�����󥵥�����ξ�������ꤹ��ɬ�פ����� */
  /*    DMA �� SRC�ȥ�󥶥�����󥵥�������Ѥ��ޤ�����ξ���Υ쥸���������ꤷ�Ƥ���ɬ�פ����� */
  /*    ZDMA_CH_SRC_DSCR_WORD2 �쥸�����˥������ǡ�����������񤭹��� */
  /*    ZDMA_CH_DST_DSCR_WORD2 �쥸�����˥ǥ��ƥ��͡������ȥ�󥶥�����󥵥�����񤭹��� */
  /*    SRC�ȥ�󥶥�����󥵥�����DST�ȥ�󥶥�����󥵥�����ɬ��Ʊ�� */
  if (emax6.dmalen > 0) {
    if (emax6.rw == 0) { /* mem->lmm */
      do {
	status = ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_STATUS & 3;
      } while (status != 0 && status != 3);
      *(Ull*)&(((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_SRC_DSCR_WORD0) = emax6.ddraddr-emax_info.ddr_mmap+emax_info.ddr_phys;     /* address should be 4B-aligned */
      ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_SRC_DSCR_WORD2 = (emax6.dmalen+1)*sizeof(Uint);                                     /* length should be # of words */
      *(Ull*)&(((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_DST_DSCR_WORD0) = emax6.lmmaddr-emax_info.ddr_mmap+emax_info.lmm_phys;     /* (emax6.awaddr & ~(sizeof(Ull)*UNIT_WIDTH-1)) */
      ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_DST_DSCR_WORD2 = (emax6.dmalen+1)*sizeof(Uint);                                     /* length should be # of words */
      ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_CTRL2 = 1;
      do {
	status = ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_STATUS & 3;
      } while (status != 0 && status != 3);
    }
    else { /* lmm->mem */
      /* ZCU102��AXI3�ߴ��Τ���8beat/256bitʬ�䤹��Τ�IMAX#0��128beat/256bit��ˤޤȤ�prefetch���Ƥ��� */
      /* prefetch���ϸ�,��³DMAREAD��block����,prefetch��λ���BUF����READ+response */
      /* start of DMAREADBUF */
      /*#define LMM_BASE2_PHYS 	         0x60000000  */
      /*#define LMM_BASE_PHYS	 0x0000000480000000LL ... DMAREADBUF��vsim�Τ���, dmrp_top�˺���0x20000000��û� */
      /*                                            tb_top.conv�Ǥ�LMM���ɥ쥹��0x20000000��û�����Τ˹�碌�� */
      do {
	status = ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_STATUS & 3;
      } while (status != 0 && status != 3);
      ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].dmrp = (1LL<<63)|((emax6.dmalen+1)*sizeof(Uint)<<40)|(emax6.lmmaddr-emax_info.ddr_mmap+emax_info.lmm_phys);
      /*printf("dmrp=%08.8x_%08.8x\n", (Uint)((((struct reg_ctrl*)emax6.reg_ctrl)->i[0].dmrp)>>32), (Uint)(((struct reg_ctrl*)emax6.reg_ctrl)->i[0].dmrp));*/
      *(Ull*)&(((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_SRC_DSCR_WORD0) = emax6.lmmaddr-emax_info.ddr_mmap+emax_info.lmm_phys;     /* (emax6.awaddr & ~(sizeof(Ull)*UNIT_WIDTH-1)) */
      ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_SRC_DSCR_WORD2 = (emax6.dmalen+1)*sizeof(Uint);                                      /* length should be # of words */
      *(Ull*)&(((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_DST_DSCR_WORD0) = emax6.ddraddr-emax_info.ddr_mmap+emax_info.ddr_phys;     /* address should be 4B-aligned */
      ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_DST_DSCR_WORD2 = (emax6.dmalen+1)*sizeof(Uint);                                      /* length should be # of words */
      ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_CTRL2 = 1;
      do {
	status = ((struct dma_ctrl*)emax6.dma_ctrl)->ZDMA_CH_STATUS & 3;
      } while (status != 0 && status != 3);
      /* end of DMAREADBUF */
      ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].dmrp = (0LL<<63); /* off */
    }
  /* 5. ɬ�פ˱���,ZDMA_CH_DST_DSCR_WORD3�����ZDMA_CH_SRC_DSCR_WORD3�쥸������INTR��1�˥��åȤ������ߤ�ͭ���ˤ��� */
  /* 6. ����������ӥǥ��ƥ��͡������Хåե�������å��女�ҡ����ȤȤ��Ƴ�����Ƥ��Ƥ��뤫�ե�å��夵��Ƥ�����, */
  /*    COHRNT�򥻥åȤ���ɬ�פϤʤ�. ����ʳ��ξ��,����������ӥǥ��ƥ��͡������Хåե�������å��女�ҡ����ȤȤ��� */
  /*    ������Ƥ��Ƥ��ʤ����ޤ��ϥե�å��夵��Ƥ��ʤ���硢ZDMA_CH_SRC_DSCR_WORD3�����ZDMA_CH_DST_DSCR_WORD3�쥸������ */
  /*    ���줾�� COHRNT�򥻥åȤ���. COHRNT�ӥåȤ� LPD-DMA �ξ��Τ�ͭ��. FPD-DMA�ϥ��ҡ���󥷤򥵥ݡ��Ȥ��ʤ�. */
  /* 7. ZDMA_CH_CTRL2�쥸������EN�ӥåȤ򥻥åȤ���,DMAž���˻��Ѥ���DMA����ͥ��ͭ���ˤ���. */
  /*    DMA��ͭ���ˤ����塢�֥��顼���פ˼������顼��������å�����. */
    switch (status) {
    case 0:
      break;
    default: /* case 3 */
      printf("emax6_check_lmmi_and_dma(): ZDMA_CH_STATUS=%d (malfunction)\n", status);
      return (0);
    }
  }
  else { /* ���굡�¹Ԥˤ��cache-fill��ư���Ƥ��ޤ�.�굡���Ը��DMA��ư��,cache-fill�⤵���Τ�mismatch�Ȥʤ�� */
    if (emax6.rw == 0) { /* mem->lmm */
      dst = emax6.lmmaddr-emax_info.ddr_mmap+emax_info.lmm_mmap;
      src = emax6.ddraddr;
    }
    else { /* lmm->mem */
      dst = emax6.ddraddr;
      src = emax6.lmmaddr-emax_info.ddr_mmap+emax_info.lmm_mmap;
    }    
    *(Uint*)dst = *(Uint*)src;
  }
#else
  /*printf("emax_info.lmm_mmap-emax_info.ddr_mmap=%08.8x_%08.8x\n", (Uint)((emax_info.lmm_mmap-emax_info.ddr_mmap)>>32), (Uint)(emax_info.lmm_mmap-emax_info.ddr_mmap));*/
  if (emax6.rw == 0) { /* mem->lmm */
    dst = emax6.lmmaddr-emax_info.ddr_mmap+emax_info.lmm_mmap;
    src = emax6.ddraddr;
    /*printf("(emax6.lmmaddr+pio_loop):%08.8x_%08.8x <- (emax6.ddraddr + pio_loop):%08.8x_%08.8x\n",
           (Uint)((Ull)((Ull*)emax6.lmmaddr + pio_loop)>>32), (Uint)(Ull)((Ull*)emax6.lmmaddr + pio_loop),
           (Uint)((Ull)((Ull*)emax6.ddraddr + pio_loop)>>32), (Uint)(Ull)((Ull*)emax6.ddraddr + pio_loop));*/
  }
  else { /* lmm->mem */
    dst = emax6.ddraddr;
    src = emax6.lmmaddr-emax_info.ddr_mmap+emax_info.lmm_mmap;
    /*printf("(emax6.lmmaddr+pio_loop):%08.8x_%08.8x -> (emax6.ddraddr + pio_loop):%08.8x_%08.8x\n",
           (Uint)((Ull)((Ull*)emax6.lmmaddr + pio_loop)>>32), (Uint)(Ull)((Ull*)emax6.lmmaddr + pio_loop),
           (Uint)((Ull)((Ull*)emax6.ddraddr + pio_loop)>>32), (Uint)(Ull)((Ull*)emax6.ddraddr + pio_loop));*/
  }
  /* src��dst��32B���饤�󤵤�Ƥ���,��¦�Τ��󥢥饤��ˤʤ뤳�ȤϤʤ� */
  pio_words = emax6.dmalen+1;
  if (src & (sizeof(Ull)-1) & sizeof(Uint)) { /* 4B-access 0,4 */
    *(Uint*)dst = *(Uint*)src;
    src += sizeof(Uint);
    dst += sizeof(Uint);
    pio_words--;
  }
  if (pio_words >= 2) {
    if (src & (sizeof(Dll)-1) & sizeof(Ull)) { /* 8B-access 0,4 */
      *(Ull*)dst = *(Ull*)src;
      src += sizeof(Ull);
      dst += sizeof(Ull);
      pio_words-=2;
    }
  }
  if (pio_words >= 4) {
    if (pio_loop = pio_words/(sizeof(Dll)/sizeof(Uint))) {
      for(pio_i=0; pio_i<pio_loop; pio_i++)
	*((Dll*)dst + pio_i) = *((Dll*)src + pio_i);
      pio_words -= pio_loop*(sizeof(Dll)/sizeof(Uint));
      src += pio_loop*sizeof(Dll);
      dst += pio_loop*sizeof(Dll);
    }
  }
  if (pio_words >= 2) { /* 8B-access */
    *(Ull*)dst = *(Ull*)src;
    src += sizeof(Ull);
    dst += sizeof(Ull);
    pio_words-=2;
  }
  if (pio_words >= 1) { /* 4B-access */
    *(Uint*)dst = *(Uint*)src;
    src += sizeof(Uint);
    dst += sizeof(Uint);
    pio_words--;
  }
#endif

  return (0);
}

/*******************************************************************************/
/******************************** EMAX6-START **********************************/
/*******************************************************************************/

/* lmmwb=0: if lmm never be written back to DDR */
emax6_pre_with_keep_cache()
{
  /* (conf -> scon -> addr -> breg ) -> dma -> exec -> dma -> term */
#ifdef ARMSIML
  emax_pre_with_keep_cache(); /* start syscall EMAX6 */
#endif
#ifdef ARMZYNQ
  /* do nothing */
#endif
}

/* lmmwb=1: if lmm may   be written back to DDR */
emax6_pre_with_drain_cache()
{
  /* (conf -> scon -> addr -> breg ) -> dma -> exec -> dma -> term */
#ifdef ARMSIML
  emax_pre_with_drain_cache(); /* start syscall EMAX6 */
#endif
#ifdef ARMZYNQ
  /* do nothing */
#endif
}

#endif

/*******************************************************************************/
/******************************** EMAX6 NCLIB (no conv-c2c)*********************/
/*******************************************************************************/

void /*__attribute__((always_inline))*/
cex(Uint op_cx, Ull *ex, Ull c3, Ull c2, Ull c1, Ull c0, Ushort pattern)
{
  Uint index1, index0;

  switch (op_cx) {
  case OP_NOP:
    if (ex)
      *ex = 3; /* for bsim */
    break;
  case OP_CEXE:
    index1 = ((c3>>32&1)<<3)|((c2>>32&1)<<2)|((c1>>32&1)<<1)|(c0>>32&1);
    index0 = ((c3    &1)<<3)|((c2    &1)<<2)|((c1    &1)<<1)|(c0    &1);
    *ex = 0;
    if (pattern>>index1&1) *ex |= 2;
    if (pattern>>index0&1) *ex |= 1;
    break;
  default:
    printf("emax6lib: cex: undefined op_cx=%d\n", op_cx);
    break;
  }  
}

void /*__attribute__((always_inline))*/
ex4(Uint op_ex1, Ull *d, Ull *r1, Uint exp1, Ull *r2, Uint exp2, Ull *r3, Uint exp3, Uint op_ex2, Ull *r4, Uint op_ex3, Ull *r5)
{
  switch (op_ex1) {
  case OP_SFMA: /* 8bit*8  3in stochastic r1+r2*r3 -> 8bit */
    exe(op_ex1, (d+0), (Ull)r1, exp1, *(r2+0), exp2, *(r3+0), exp3, OP_NOP, (Ull)r4, OP_NOP, (Ull)r5);
    exe(op_ex1, (d+0), *(d+0),  exp1, *(r2+1), exp2, *(r3+1), exp3, OP_NOP, (Ull)r4, OP_NOP, (Ull)r5);
    exe(op_ex1, (d+0), *(d+0),  exp1, *(r2+2), exp2, *(r3+2), exp3, OP_NOP, (Ull)r4, OP_NOP, (Ull)r5);
    exe(op_ex1, (d+0), *(d+0),  exp1, *(r2+3), exp2, *(r3+3), exp3, OP_NOP, (Ull)r4, OP_NOP, (Ull)r5);
    break;
  case OP_NOP:
  case OP_FMA:  /* 32bit*2 3in floating-point r1+r2*r3 */
  case OP_FMS:  /* 32bit*2 3in floating-point r1-r2*r3 */
  case OP_FAD:  /* 32bit*2 2in floating-point r1+r2 */
  case OP_FML:  /* 32bit*2 2in floating-point r1*r2 */
  case OP_ADD3: /* 32bit*2 3in fixed-point r1+(r2+r3) */
  case OP_SUB3: /* 32bit*2 3in fixed-point r1-(r2+r3) */
  case OP_ADD:  /* 32bit*2 2in fixed-point r1+r2 */
  case OP_SUB:  /* 32bit*2 2in fixed-point r1-r2 */
    exe(op_ex1, (d+0), *(r1+0), exp1, *(r2+0), exp2, *(r3+0), exp3, OP_NOP, 0LL, OP_NOP, 0LL);
    exe(op_ex1, (d+1), *(r1+1), exp1, *(r2+1), exp2, *(r3+1), exp3, OP_NOP, 0LL, OP_NOP, 0LL);
    exe(op_ex1, (d+2), *(r1+2), exp1, *(r2+2), exp2, *(r3+2), exp3, OP_NOP, 0LL, OP_NOP, 0LL);
    exe(op_ex1, (d+3), *(r1+3), exp1, *(r2+3), exp2, *(r3+3), exp3, OP_NOP, 0LL, OP_NOP, 0LL);
    break;
  default:
    printf("emax6lib: ex4: undefined op_ex1=%d\n", op_ex1);
    break;
  }

  switch (op_ex2) {
  case OP_NOP:
    break;
  default:
    printf("emax6lib: ex4: illegal op_ex2=%d\n", op_ex2);
    break;
  }

  switch (op_ex3) {
  case OP_NOP:
    break;
  default:
    printf("emax6lib: ex4: illegal op_ex3=%d\n", op_ex3);
    break;
  }
}

int convf32tou7(u7bit *out, float in)
{
  //  convf32tou7 e=126     0.992 -> s0111111  0111111111111111111111111111111111111111111111111111111111111111
  //  convf32tou7 e=126 f=0 0.500 -> s0100000  0000000000000000000000000000000011111111111111111111111111111111
  //  convf32tou7 e=125 f=0 0.250 -> s0010000  0000000000000000000000000000000000000000000000001111111111111111
  //  convf32tou7 e=124 f=0 0.125 -> s0001000  0000000000000000000000000000000000000000000000000000000011111111
  //  convf32tou7 e=123 f=0 0.062 -> s0000100  0000000000000000000000000000000000000000000000000000000000001111
  //  convf32tou7 e=122 f=0 0.031 -> s0000010  0000000000000000000000000000000000000000000000000000000000000011
  //  convf32tou7 e=121 f=0 0.016 -> s0000001  0000000000000000000000000000000000000000000000000000000000000001
  //                        0.000 -> s0000000  0000000000000000000000000000000000000000000000000000000000000000
  f32bit in_f32;

  *(float*)&in_f32 = in;

  out->s = in_f32.s;
  out->b = 0;

  in = abs(in);
  if  (in >= 1.0) out->e = 63;    /* �軻����6bitɽ��(-1.0+1.0) */
  else            out->e = in*64; /* number of 1 */    

//printf("%7.4f -> %02.2x\n", *(float*)&in_f32, *(Uchar*)out);
}

int convf32tou8(u8bit *out, float in)
{
  f32bit in_f32;

  *(float*)&in_f32 = in;

  out->s = in_f32.s;

  in = abs(in);
  if  (in >= 2.0) out->e = 127;   /* �軻����6bitɽ��(-1.0+1.0) */
  else            out->e = in*64; /* number of 1 */    

//printf("%7.4f -> %02.2x\n", *(float*)&in_f32, *(Uchar*)out);
}

int convu8tof32(float *out, u8bit in)
{
  f32bit out_f32;

  *(float*)&out_f32 = (float)in.e/64; /* 6bitɽ��(-2.0+2.0) */
  out_f32.s = in.s;
  *out = *(float*)&out_f32;

//printf("%02.2x -> %7.4f\n", *(Uchar*)&in, *out);
}

Ull urand(int no)
{
  static Ull urand_seed[8]
    = {0xc3c3c3c3a5a5a5a5LL, 0x123456789abcdef0LL, 0xe1e1e1e1d4d4d4d4LL, 0x8888777766665555LL,
       0x8787878796969696LL, 0xfedcba9876543210LL, 0x5a5a5a5a3c3c3c3cLL, 0xbbbbccccddddeeeeLL};
  Ull retval = urand_seed[no];

//urand_seed = urand_seed * 1103515245LL + 12345LL;

  urand_seed[no] ^= (urand_seed[no]<<29);
  urand_seed[no] ^= (urand_seed[no]>>27);
  urand_seed[no] ^= (urand_seed[no]<<37);
  return (retval);
}

Ull shfl(Ull in, Ull r)
{
  int i;
  for (i=0; i<32; i++) {
    if (r&(1LL<<(i+16)))
      in = (in&~(1LL<<(i+32)|1LL<<i)) | (in>>i&1)<<(i+32) | (in>>(i+32)&1)<<i;
  }
  for (i=0; i<48; i++) {
    if (r&(1LL<<(i+8)))
      in = (in&~(1LL<<(i+16)|1LL<<i)) | (in>>i&1)<<(i+16) | (in>>(i+16)&1)<<i;
  }
  for (i=0; i<56; i++) {
    if (r&(1LL<<(i+4)))
      in = (in&~(1LL<<(i+ 8)|1LL<<i)) | (in>>i&1)<<(i+ 8) | (in>>(i+ 8)&1)<<i;
  }
  for (i=0; i<60; i++) {
    if (r&(1LL<<(i+2)))
      in = (in&~(1LL<<(i+ 4)|1LL<<i)) | (in>>i&1)<<(i+ 4) | (in>>(i+ 4)&1)<<i;
  }
  for (i=0; i<62; i++) {
    if (r&(1LL<<(i+1)))
      in = (in&~(1LL<<(i+ 2)|1LL<<i)) | (in>>i&1)<<(i+ 2) | (in>>(i+ 2)&1)<<i;
  }
  for (i=0; i<63; i++) {
    if (r&(1LL<<(i+0)))
      in = (in&~(1LL<<(i+ 1)|1LL<<i)) | (in>>i&1)<<(i+ 1) | (in>>(i+ 1)&1)<<i;
  }
  return(in);
}

int enable_x11;    /* 0 or set in extern */

void x11_softu64_dist(float, float);
int softu64(int stage, Ull *o1, Ull *o2, Ull *o3, Ull r1, Ull r2, Ull r3, Ull r4) /* o <- s1 + s2 * s3 */
     /* stage:1 stage_2 in EXEC:  r2*r3 64bit*2  -> *o1 32bit*8 b mult     */
     /* stage:2 stage_3 in EXEC:  *o1,r4 32bit*8 -> *o2 8bit+8bit count up */
     /* stage:3 stage_4 in EXEC:  r1 + *o2��     -> *o3 8bit               */
{
  int i, j;
  Ull u[8];
  Ull ss[8];
  Ull s2[8], s3[8];
  int pc, nc; /* number of 1 */
  int os, oc;

//#define SPU_DATA_BITS 31
//#define SPU_DATA_DIST 2
//#define SPU_COUT_BITS 31
#define SPU_DATA_BITS 15
#define SPU_DATA_DIST 4
#define SPU_COUT_BITS 12

  switch (stage) {
  case 1: /* stage2 */
    for (i=0; i<8; i++) /* s2 * s3 -> ad2 */
      u[i] = urand(i);
    for (i=0; i<8; i++) { /* s2 * s3 -> ad2 */
      ss[i] = (r2>>(i*8+7))&1 ^ (r3>>(i*8+7))&1;
  int s2e   = (r2>>(i*8))&0x7f; s2e = s2e<SPU_DATA_BITS?s2e:SPU_DATA_BITS;
  int s3e   = (r3>>(i*8))&0x7f; s3e = s3e<SPU_DATA_BITS?s3e:SPU_DATA_BITS;
#if 0
      s2[i] = (Ull)0x7fffffffffffffffLL>>(63-s2e); //�軻��6bit*6bit->6bit
      s3[i] = (Ull)0x7fffffffffffffffLL>>(63-s3e); //�軻��6bit*6bit->6bit
      // ����64bit��ǥ���åե�
      s2[i] = shfl(s2[i], u[2]);
      s3[i] = shfl(s3[i], u[3]);
#else
      // �����SPU_DATA_WIDTH bit��˻���.�����ͤ�6bit���ۤȤ��15�ʲ��Ǥ��뤳�Ȥ�����(63�᤯�ʤ�ȸ������Ф�Ϥ�)
      s2[i] = 0LL;
      s3[i] = 0LL;
      for (j=0; j<SPU_COUT_BITS; j++) {
	int k = j * SPU_DATA_DIST; /* SPU_DATA_BITS=15�ʤ�4bit�� */
	s2[i] |= ((u[(i+0)%8]>>k&SPU_DATA_BITS)<=s2e)<<j;
	s3[i] |= ((u[(i+1)%8]>>k&SPU_DATA_BITS)<=s3e)<<j;
      }
      //printf("%08.8x_%08.8x %08.8x_%08.8x %d:%08.8x %d:%08.8x\n", (Uint)(u2>>32), (Uint)u2, (Uint)(u3>>32), (Uint)u3, s2e, (Uint)s2[i], s3e, (Uint)s3[i]);
#endif
      // s2*s3 �����Ǥ�stochastic�軻
      o1[i] = s2[i] & s3[i];                         // 1*1=1�ˤʤ� �ºݤϾ��SPU_DATA_BITS�Τ�AND
      o1[i] = ss[i]<<63|(o1[i]&0x7fffffffffffffffLL);// stage2�ν��Ϥ�(��Ƭ���bit|SPU_DATA_BITS bit) * 8
    }
    break;
  case 2: /* stage3 */
    pc = 0;
    nc = 0;
    // ����/������롼�פ��Ȥˡ�������ʬ�򥹥ʥåץ���å�
    for (j=0; j<SPU_COUT_BITS; j++) {
      for (i=0; i<8; i++) { /* s2 * s3 -> ad2 */
	if (!(o1[i]>>63)) pc += (o1[i] & (1LL<<j))!=0;
	else              nc += (o1[i] & (1LL<<j))!=0;
      }
    }
    pc = pc>>r4; // r4=3 for MNIST/CIFAR10
    nc = nc>>r4; // r4=2 for test021
    *o2 = (Ull)(pc&0xffff)<<32 | (Ull)(nc&0xffff);
    break;
  case 3: /* stage4 */
    pc = *o2>>32&0xffff; /* high */
    nc = *o2    &0xffff; /* low */
    // s1�򤵤�˲û�
    if (!(r1&0x80)) pc += (r1&0x7f); /* merge pos s1 s1.e�Ϻ���7bit */
    else            nc += (r1&0x7f); /* merge neg s1 s1.e�Ϻ���7bit */
    // ����������βû�(s1:7bit + s2*s3:6bit->7bit)
    if (pc >= nc) {
      os = 0x00; /* pos */
      oc = pc-nc; /* # of 1 */
    }
    else {
      os = 0x80; /* neg */
      oc = nc-pc; /* # of 1 */
    }
    if (oc >= 128) oc = 127;
    *o3 = os|oc;
#if !defined(ARMSIML) && defined(TRACE_SPIKE)
    if (enable_x11) {
      int i;
      u8bit r2_u8;
      u8bit r3_u8;
      float r1_f32;
      float r2_f32;
      float r3_f32;
      float o3_f32;
      convu8tof32(&o3_f32, *(u8bit*)o3);   /* for graph */
      convu8tof32(&r1_f32, *(u8bit*)&r1); /* for graph */
      for (i=0; i<8; i++) { /* s2 * s3 -> ad2 */
	*(Uchar*)&r2_u8 = r2>>(i*8)&0xff;
	*(Uchar*)&r3_u8 = r3>>(i*8)&0xff;
	convu8tof32(&r2_f32, r2_u8); /* for graph */
	convu8tof32(&r3_f32, r3_u8); /* for graph */
	r1_f32 += r2_f32*r3_f32;
      }
      x11_softu64_dist(r1_f32, o3_f32);
    }
#endif
    break;
  }

  return (0);
}

int  /*__attribute__((always_inline))*/
exe(Uint op_ex1, Ull *d, Ull r1, Uint exp1, Ull r2, Uint exp2, Ull r3, Uint exp3, Uint op_ex2, Ull r4, Uint op_ex3, Ull r5)
{
  /* return 0:normal, 1:OP_WHILE breaks */
  union { Uint i; float f; } f3, f2, f1, f0;
  Ull t3, t2, t1, t0;
  Ull c1, c0;
  Ull ex1_outd;
  Ull ex1_outd_sfma[8];
  Ull ex2_outd;
  int retval = 0;

  switch (exp1) {
  case EXP_H3210:                                                                    break;
  case EXP_B7632: r1 = (r1>>8&0x00ff000000ff0000LL) | (r1>>16&0x000000ff000000ffLL); break;
  case EXP_B5410: r1 = (r1<<8&0x00ff000000ff0000LL) | (r1    &0x000000ff000000ffLL); break;
  }
  switch (exp2) {
  case EXP_H3210:                                                                    break;
  case EXP_B7632: r2 = (r2>>8&0x00ff000000ff0000LL) | (r2>>16&0x000000ff000000ffLL); break;
  case EXP_B5410: r2 = (r2<<8&0x00ff000000ff0000LL) | (r2    &0x000000ff000000ffLL); break;
  }
  switch (exp3) {
  case EXP_H3210:                                                                    break;
  case EXP_B7632: r3 = (r3>>8&0x00ff000000ff0000LL) | (r3>>16&0x000000ff000000ffLL); break;
  case EXP_B5410: r3 = (r3<<8&0x00ff000000ff0000LL) | (r3    &0x000000ff000000ffLL); break;
  }

  switch (op_ex1) {
  case OP_NOP:
    ex1_outd = r1;
    break;
  case OP_WHILE: /* emax6nc��lib�Ȥ��Ƥϻ��Ѥ���,bsim/emax6.c��siml�˻��� */
    t0 = (r1&0x00000000ffffffffLL)+(r2&0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = t0;
    if (t0==0) retval = 1;
    break;
  case OP_FOR: /* emax6nc��lib�Ȥ��Ƥϻ��Ѥ���,bsim/emax6.c��siml�˻��� */
    t0 = (r1&0x00000000ffffffffLL)+(r2&0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = t0;
    if (t0==0) retval = 1;
    break;
  case OP_SFMA: /* 8bit*8  3in stochastic r1+r2*r3 -> 8bit */
    softu64(1, ex1_outd_sfma, NULL, NULL, r1, r2, r3, r4);
    break;
  case OP_FMA: /* 32bit*2 3in floating-point r1+r2*r3 */
  case OP_FMS: /* 32bit*2 3in floating-point r1-r2*r3 */
    /* *(double*)&ex1_outd = *(double*)&r1 + (*(double*)&r2 * *(double*)&r3);*/
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32)^(op_ex1==OP_FMA?0:0x80000000);
    f3.i = (Uint)(r3>>32);
    f0.f = f1.f + (f2.f * f3.f);
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2)^(op_ex1==OP_FMA?0:0x80000000);
    f3.i = (Uint)(r3);
    f0.f = f1.f + (f2.f * f3.f);
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_FAD: /* 32bit*2 3in floating-point r1+r2 */
    /* *(double*)&ex1_outd = *(double*)&r1 + *(double*)&r2;*/
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32);
    f0.f = f1.f + f2.f;
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2);
    f0.f = f1.f + f2.f;
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_FML: /* 32bit*2 3in floating-point r1*r2 */
    /* *(double*)&ex1_outd = *(double*)&r1 * *(double*)&r2;*/
    f1.i = (Uint)(r1>>32);
    f2.i = (Uint)(r2>>32);
    f0.f = f1.f * f2.f;
    t2 = f0.i;
    f1.i = (Uint)(r1);
    f2.i = (Uint)(r2);
    f0.f = f1.f * f2.f;
    t0 = f0.i;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_ADD3: /* 32bit*2 3in integer add s1+(s2+s3) */
    t2 = (r1>>32&0x00000000ffffffffLL)+((r2>>32&0x00000000ffffffffLL)+(r3>>32&0x00000000ffffffffLL));
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1    &0x00000000ffffffffLL)+((r2    &0x00000000ffffffffLL)+(r3    &0x00000000ffffffffLL));
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_SUB3: /* 32bit*2 3in integer subtract s1-(s2+s3) */
    t2 = (r1>>32&0x00000000ffffffffLL)-((r2>>32&0x00000000ffffffffLL)+(r3>>32&0x00000000ffffffffLL));
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1    &0x00000000ffffffffLL)-((r2    &0x00000000ffffffffLL)+(r3    &0x00000000ffffffffLL));
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_ADD: /* 32bit*2 2in integer add s1+s2 */
    t2 = (r1>>32&0x00000000ffffffffLL)+(r2>>32&0x00000000ffffffffLL);
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1    &0x00000000ffffffffLL)+(r2    &0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_SUB: /* 32bit*2 2in integer subtract s1-s2 */
    t2 = (r1>>32&0x00000000ffffffffLL)-(r2>>32&0x00000000ffffffffLL);
    t2 &= 0x00000000ffffffffLL;
    t0 = (r1    &0x00000000ffffffffLL)-(r2    &0x00000000ffffffffLL);
    t0 &= 0x00000000ffffffffLL;
    ex1_outd = (t2<<32)|(t0);
    break;
  case OP_CMP_EQ: /* 32bit*2 2in compare and set 1*2bit-CC */
    c1 = (r1>>32&0x00000000ffffffffLL) == (r2>>32&0x00000000ffffffffLL);
    c0 = (r1    &0x00000000ffffffffLL) == (r2    &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case OP_CMP_NE: /* 32bit*2 2in compare and set 1*2bit-CC */
    c1 = (r1>>32&0x00000000ffffffffLL) != (r2>>32&0x00000000ffffffffLL);
    c0 = (r1    &0x00000000ffffffffLL) != (r2    &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case OP_CMP_LT: /* 32bit*2 2in compare and set 1*2bit-CC */
    c1 = (r1>>32&0x00000000ffffffffLL) < (r2>>32&0x00000000ffffffffLL);
    c0 = (r1    &0x00000000ffffffffLL) < (r2    &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case OP_CMP_LE: /* 32bit*2 2in compare and set 1*2bit-CC */
    c1 = (r1>>32&0x00000000ffffffffLL) <= (r2>>32&0x00000000ffffffffLL);
    c0 = (r1    &0x00000000ffffffffLL) <= (r2    &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case OP_CMP_GT: /* 32bit*2 2in compare and set 1*2bit-CC */
    c1 = (r1>>32&0x00000000ffffffffLL) > (r2>>32&0x00000000ffffffffLL);
    c0 = (r1    &0x00000000ffffffffLL) > (r2    &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case OP_CMP_GE: /* 32bit*2 2in compare and set 1*2bit-CC */
    c1 = (r1>>32&0x00000000ffffffffLL) >= (r2>>32&0x00000000ffffffffLL);
    c0 = (r1    &0x00000000ffffffffLL) >= (r2    &0x00000000ffffffffLL);
    ex1_outd = (c1<<32)|c0;
    break;
  case OP_CMOV: /* 32bit*2 3in 2bit conditional move */
    c1 = r1>>32&1;
    c0 = r1    &1;
    t2 = c1 ? (r2&0xffffffff00000000LL) : (r3&0xffffffff00000000LL);
    t0 = c0 ? (r2&0x00000000ffffffffLL) : (r3&0x00000000ffffffffLL);
    ex1_outd = t2 | t0;
    break;
//case OP_CCAT: /* 32bit 2in s1<<32|s2 concatenate */
//  ex1_outd = (r1<<32)|(r2);
//  break;
  case OP_MAUH3: /* 16bit*4 3in r1.pos+(r2.pos+r3.pos) */
    t3 = (r1>>48&0x000000000000ffffLL)+((r2>>48&0x000000000000ffffLL)+(r3>>48&0x000000000000ffffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL)+((r2>>32&0x000000000000ffffLL)+(r3>>32&0x000000000000ffffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL)+((r2>>16&0x000000000000ffffLL)+(r3>>16&0x000000000000ffffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1    &0x000000000000ffffLL)+((r2    &0x000000000000ffffLL)+(r3    &0x000000000000ffffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MAUH: /* 16bit*4 2in r1.pos+r2.pos */
    t3 = (r1>>48&0x000000000000ffffLL)+(r2>>48&0x000000000000ffffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL)+(r2>>32&0x000000000000ffffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL)+(r2>>16&0x000000000000ffffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1    &0x000000000000ffffLL)+(r2    &0x000000000000ffffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MSUH3: /* 16bit*4 3in r1.pos-(r2.pos+r3.pos) */
    t3 = (r1>>48&0x000000000000ffffLL)-((r2>>48&0x000000000000ffffLL)+(r3>>48&0x000000000000ffffLL));
    if (t3 > 0x000000000000ffffLL) t3 = 0x0000000000000000LL;
    t2 = (r1>>32&0x000000000000ffffLL)-((r2>>32&0x000000000000ffffLL)+(r3>>32&0x000000000000ffffLL));
    if (t2 > 0x000000000000ffffLL) t2 = 0x0000000000000000LL;
    t1 = (r1>>16&0x000000000000ffffLL)-((r2>>16&0x000000000000ffffLL)+(r3>>16&0x000000000000ffffLL));
    if (t1 > 0x000000000000ffffLL) t1 = 0x0000000000000000LL;
    t0 = (r1    &0x000000000000ffffLL)-((r2    &0x000000000000ffffLL)+(r3    &0x000000000000ffffLL));
    if (t0 > 0x000000000000ffffLL) t0 = 0x0000000000000000LL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MSUH: /* 16bit*4 2in r1.pos-r2.pos */
    t3 = (r1>>48&0x000000000000ffffLL)-(r2>>48&0x000000000000ffffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x0000000000000000LL;
    t2 = (r1>>32&0x000000000000ffffLL)-(r2>>32&0x000000000000ffffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x0000000000000000LL;
    t1 = (r1>>16&0x000000000000ffffLL)-(r2>>16&0x000000000000ffffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x0000000000000000LL;
    t0 = (r1    &0x000000000000ffffLL)-(r2    &0x000000000000ffffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x0000000000000000LL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MLUH: /* (11bit*4)*9bit r1.pos*r2.pos */
    t3 = (r1>>48&0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1    &0x00000000000007ffLL)*(r2&0x00000000000001ffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MMRG: /* 8bit*2 3in r1.b4|r2.b4|r3.b4|0->w1, r1.b0|r2.b0|r3.b0|0->w0 */
    ex1_outd = ((r1&0x000000ff00000000LL)<<24) | ((r2&0x000000ff00000000LL)<<16) | ((r3&0x000000ff00000000LL)<<8)
             | ((r1&0x00000000000000ffLL)<<24) | ((r2&0x00000000000000ffLL)<<16) | ((r3&0x00000000000000ffLL)<<8);
    break;
  case OP_MSSAD: /* 16bit*4 8bit*8 2in r1.h3+df(r2.b7,r3.b7)+df(r2.b6,r3.b6)->d.h3
                                       r1.h2+df(r2.b5,r3.b5)+df(r2.b4,r3.b4)->d.h2
                                       r1.h1+df(r2.b3,r3.b3)+df(r2.b2,r3.b2)->d.h1
                                       r1.h0+df(r2.b1,r3.b1)+df(r2.b0,r3.b0)->d.h0 */
    t3 = (r1>>48&0x000000000000ffffLL) + ad(r2>>56&0x00000000000000ffLL, r3>>56&0x00000000000000ffLL) + ad(r2>>48&0x00000000000000ffLL, r3>>48&0x00000000000000ffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = (r1>>32&0x000000000000ffffLL) + ad(r2>>40&0x00000000000000ffLL, r3>>40&0x00000000000000ffLL) + ad(r2>>32&0x00000000000000ffLL, r3>>32&0x00000000000000ffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = (r1>>16&0x000000000000ffffLL) + ad(r2>>24&0x00000000000000ffLL, r3>>24&0x00000000000000ffLL) + ad(r2>>16&0x00000000000000ffLL, r3>>16&0x00000000000000ffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = (r1    &0x000000000000ffffLL) + ad(r2>> 8&0x00000000000000ffLL, r3>> 8&0x00000000000000ffLL) + ad(r2    &0x00000000000000ffLL, r3    &0x00000000000000ffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MSAD: /* 16bit*4 8bit*8 2in df(r1.b7,r2.b7)+df(r1.b6,r2.b6)->d.h3
                                      df(r1.b5,r2.b5)+df(r1.b4,r2.b4)->d.h2
                                      df(r1.b3,r2.b3)+df(r1.b2,r2.b2)->d.h1
                                      df(r1.b1,r2.b1)+df(r1.b0,r2.b0)->d.h0 */
    t3 = ad(r1>>56&0x00000000000000ffLL, r2>>56&0x00000000000000ffLL) + ad(r1>>48&0x00000000000000ffLL, r2>>48&0x00000000000000ffLL);
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t2 = ad(r1>>40&0x00000000000000ffLL, r2>>40&0x00000000000000ffLL) + ad(r1>>32&0x00000000000000ffLL, r2>>32&0x00000000000000ffLL);
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t1 = ad(r1>>24&0x00000000000000ffLL, r2>>24&0x00000000000000ffLL) + ad(r1>>16&0x00000000000000ffLL, r2>>16&0x00000000000000ffLL);
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    t0 = ad(r1>> 8&0x00000000000000ffLL, r2>> 8&0x00000000000000ffLL) + ad(r1    &0x00000000000000ffLL, r2    &0x00000000000000ffLL);
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex1_outd = (t3<<48)|(t2<<32)|(t1<<16)|(t0);
    break;
  case OP_MINL3: /* 16bit*4 3in (r3.h3<r3.h2)?r1.h3|r3.h3:r2.h3|r3.h2->d.w1
                                (r3.h1<r3.h0)?r1.h1|r3.h1:r2.h1|r3.h0->d.w0 */
    t3 = r3>>48&0x000000000000ffffLL;
    t2 = r3>>32&0x000000000000ffffLL;
    t1 = r3>>16&0x000000000000ffffLL;
    t0 = r3    &0x000000000000ffffLL;
    if (t3<t2) t2 = (r1&0xffff000000000000LL)|(r3>>16&0x0000ffff00000000LL);
    else       t2 = (r2&0xffff000000000000LL)|(r3    &0x0000ffff00000000LL);
    if (t1<t0) t0 = (r1&0x00000000ffff0000LL)|(r3>>16&0x000000000000ffffLL);
    else       t0 = (r2&0x00000000ffff0000LL)|(r3    &0x000000000000ffffLL);
    ex1_outd = t2 | t0;
    break;
  case OP_MINL: /* 16bit*4 2in (r1.h2<r2.h2)?r1.w1:r2.w1->d.w1
	                       (r1.h0<r2.h0)?r1.w0:r2.w0->d.w0 */
    if ((r1&0x0000ffff00000000LL)<(r2&0x0000ffff00000000LL)) t2 = r1&0xffffffff00000000LL;
    else                                                     t2 = r2&0xffffffff00000000LL;
    if ((r1&0x000000000000ffffLL)<(r2&0x000000000000ffffLL)) t0 = r1&0x00000000ffffffffLL;
    else                                                     t0 = r2&0x00000000ffffffffLL;
    ex1_outd = t2 | t0;
   break;
  case OP_MH2BW: /* 16bit*4 2in r1.b6|r1.b4|r2.b6|r2.b4|r1.b2|r1.b0|r2.b2|r2.b0 */
    ex1_outd = (((r1>>48&0x000000000000ff00LL) ? 255 : (r1>>48&0x00000000000000ffLL))<<56)
             | (((r1>>32&0x000000000000ff00LL) ? 255 : (r1>>32&0x00000000000000ffLL))<<48)
             | (((r2>>48&0x000000000000ff00LL) ? 255 : (r2>>48&0x00000000000000ffLL))<<40)
             | (((r2>>32&0x000000000000ff00LL) ? 255 : (r2>>32&0x00000000000000ffLL))<<32)
             | (((r1>>16&0x000000000000ff00LL) ? 255 : (r1>>16&0x00000000000000ffLL))<<24)
             | (((r1    &0x000000000000ff00LL) ? 255 : (r1    &0x00000000000000ffLL))<<16)
             | (((r2>>16&0x000000000000ff00LL) ? 255 : (r2>>16&0x00000000000000ffLL))<< 8)
             | (((r2    &0x000000000000ff00LL) ? 255 : (r2    &0x00000000000000ffLL))    );
    break;
  case OP_MCAS: /* 16bit*2 2in (r1.h2<r2.h2)?0:0xff->d.b1
                               (r1.h0<r2.h0)?0:0xff->d.b0 */
    t2 = ((r1&0x0000ffff00000000LL)<(r2&0x0000ffff00000000LL))?0:0x000000ff00000000LL;
    t0 = ((r1&0x000000000000ffffLL)<(r2&0x000000000000ffffLL))?0:0x00000000000000ffLL;
    ex1_outd = t2 | t0;
    break;
  case OP_MMID3: /* 8bit*8 3in bytewise compare and output middle */
    t1 = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    t2 = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    ex1_outd = ((r3&0xff00000000000000LL)<(t1&0xff00000000000000LL)?(t1&0xff00000000000000LL):((r3&0xff00000000000000LL)<(t2&0xff00000000000000LL)?(r3&0xff00000000000000LL):(t2&0xff00000000000000LL)))
             | ((r3&0x00ff000000000000LL)<(t1&0x00ff000000000000LL)?(t1&0x00ff000000000000LL):((r3&0x00ff000000000000LL)<(t2&0x00ff000000000000LL)?(r3&0x00ff000000000000LL):(t2&0x00ff000000000000LL)))
             | ((r3&0x0000ff0000000000LL)<(t1&0x0000ff0000000000LL)?(t1&0x0000ff0000000000LL):((r3&0x0000ff0000000000LL)<(t2&0x0000ff0000000000LL)?(r3&0x0000ff0000000000LL):(t2&0x0000ff0000000000LL)))
             | ((r3&0x000000ff00000000LL)<(t1&0x000000ff00000000LL)?(t1&0x000000ff00000000LL):((r3&0x000000ff00000000LL)<(t2&0x000000ff00000000LL)?(r3&0x000000ff00000000LL):(t2&0x000000ff00000000LL)))
             | ((r3&0x00000000ff000000LL)<(t1&0x00000000ff000000LL)?(t1&0x00000000ff000000LL):((r3&0x00000000ff000000LL)<(t2&0x00000000ff000000LL)?(r3&0x00000000ff000000LL):(t2&0x00000000ff000000LL)))
             | ((r3&0x0000000000ff0000LL)<(t1&0x0000000000ff0000LL)?(t1&0x0000000000ff0000LL):((r3&0x0000000000ff0000LL)<(t2&0x0000000000ff0000LL)?(r3&0x0000000000ff0000LL):(t2&0x0000000000ff0000LL)))
             | ((r3&0x000000000000ff00LL)<(t1&0x000000000000ff00LL)?(t1&0x000000000000ff00LL):((r3&0x000000000000ff00LL)<(t2&0x000000000000ff00LL)?(r3&0x000000000000ff00LL):(t2&0x000000000000ff00LL)))
             | ((r3&0x00000000000000ffLL)<(t1&0x00000000000000ffLL)?(t1&0x00000000000000ffLL):((r3&0x00000000000000ffLL)<(t2&0x00000000000000ffLL)?(r3&0x00000000000000ffLL):(t2&0x00000000000000ffLL)));
    break;
  case OP_MMAX3: /* 8bit*8 3in bytewise compare and output maximum */
    t1 = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    ex1_outd = ((t1&0xff00000000000000LL)>(r3&0xff00000000000000LL)?(t1&0xff00000000000000LL):(r3&0xff00000000000000LL))
             | ((t1&0x00ff000000000000LL)>(r3&0x00ff000000000000LL)?(t1&0x00ff000000000000LL):(r3&0x00ff000000000000LL))
             | ((t1&0x0000ff0000000000LL)>(r3&0x0000ff0000000000LL)?(t1&0x0000ff0000000000LL):(r3&0x0000ff0000000000LL))
             | ((t1&0x000000ff00000000LL)>(r3&0x000000ff00000000LL)?(t1&0x000000ff00000000LL):(r3&0x000000ff00000000LL))
             | ((t1&0x00000000ff000000LL)>(r3&0x00000000ff000000LL)?(t1&0x00000000ff000000LL):(r3&0x00000000ff000000LL))
             | ((t1&0x0000000000ff0000LL)>(r3&0x0000000000ff0000LL)?(t1&0x0000000000ff0000LL):(r3&0x0000000000ff0000LL))
             | ((t1&0x000000000000ff00LL)>(r3&0x000000000000ff00LL)?(t1&0x000000000000ff00LL):(r3&0x000000000000ff00LL))
             | ((t1&0x00000000000000ffLL)>(r3&0x00000000000000ffLL)?(t1&0x00000000000000ffLL):(r3&0x00000000000000ffLL));
    break;
  case OP_MMIN3: /* 8bit*8 3in bytewise compare and output minimum */
    t1 = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
       | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
       | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
       | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
       | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
       | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
       | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
       | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    ex1_outd = ((t1&0xff00000000000000LL)<(r3&0xff00000000000000LL)?(t1&0xff00000000000000LL):(r3&0xff00000000000000LL))
             | ((t1&0x00ff000000000000LL)<(r3&0x00ff000000000000LL)?(t1&0x00ff000000000000LL):(r3&0x00ff000000000000LL))
             | ((t1&0x0000ff0000000000LL)<(r3&0x0000ff0000000000LL)?(t1&0x0000ff0000000000LL):(r3&0x0000ff0000000000LL))
             | ((t1&0x000000ff00000000LL)<(r3&0x000000ff00000000LL)?(t1&0x000000ff00000000LL):(r3&0x000000ff00000000LL))
             | ((t1&0x00000000ff000000LL)<(r3&0x00000000ff000000LL)?(t1&0x00000000ff000000LL):(r3&0x00000000ff000000LL))
             | ((t1&0x0000000000ff0000LL)<(r3&0x0000000000ff0000LL)?(t1&0x0000000000ff0000LL):(r3&0x0000000000ff0000LL))
             | ((t1&0x000000000000ff00LL)<(r3&0x000000000000ff00LL)?(t1&0x000000000000ff00LL):(r3&0x000000000000ff00LL))
             | ((t1&0x00000000000000ffLL)<(r3&0x00000000000000ffLL)?(t1&0x00000000000000ffLL):(r3&0x00000000000000ffLL));
    break;
  case OP_MMAX: /* 8bit*8 2in bytewise compare and output maximum */
    ex1_outd = ((r1&0xff00000000000000LL)>(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
             | ((r1&0x00ff000000000000LL)>(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
             | ((r1&0x0000ff0000000000LL)>(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
             | ((r1&0x000000ff00000000LL)>(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
             | ((r1&0x00000000ff000000LL)>(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
             | ((r1&0x0000000000ff0000LL)>(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
             | ((r1&0x000000000000ff00LL)>(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
             | ((r1&0x00000000000000ffLL)>(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    break;
  case OP_MMIN: /* 8bit*8 2in bytewise compare and output minimum */
    ex1_outd = ((r1&0xff00000000000000LL)<(r2&0xff00000000000000LL)?(r1&0xff00000000000000LL):(r2&0xff00000000000000LL))
             | ((r1&0x00ff000000000000LL)<(r2&0x00ff000000000000LL)?(r1&0x00ff000000000000LL):(r2&0x00ff000000000000LL))
             | ((r1&0x0000ff0000000000LL)<(r2&0x0000ff0000000000LL)?(r1&0x0000ff0000000000LL):(r2&0x0000ff0000000000LL))
             | ((r1&0x000000ff00000000LL)<(r2&0x000000ff00000000LL)?(r1&0x000000ff00000000LL):(r2&0x000000ff00000000LL))
             | ((r1&0x00000000ff000000LL)<(r2&0x00000000ff000000LL)?(r1&0x00000000ff000000LL):(r2&0x00000000ff000000LL))
             | ((r1&0x0000000000ff0000LL)<(r2&0x0000000000ff0000LL)?(r1&0x0000000000ff0000LL):(r2&0x0000000000ff0000LL))
             | ((r1&0x000000000000ff00LL)<(r2&0x000000000000ff00LL)?(r1&0x000000000000ff00LL):(r2&0x000000000000ff00LL))
             | ((r1&0x00000000000000ffLL)<(r2&0x00000000000000ffLL)?(r1&0x00000000000000ffLL):(r2&0x00000000000000ffLL));
    break;
  default:
    printf("emax6lib: exe: undefined op_ex1=%d\n", op_ex1);
    break;
  }

  switch (op_ex2) {
  case OP_NOP:
    if (op_ex1 == OP_SFMA)
      softu64(2, ex1_outd_sfma, &ex2_outd, NULL, r1, r2, r3, r4);
    else
      ex2_outd = ex1_outd;
    break;
  case OP_AND: /* 64bit 2in logical and s1&s2 */
    ex2_outd = ex1_outd & r4;
    break;
  case OP_OR: /* 64bit 2in logical or s1|s2 */
    ex2_outd = ex1_outd | r4;
    break;
  case OP_XOR: /* 64bit 2in logical xor s1^s2 */
    ex2_outd = ex1_outd ^ r4;
    break;
  case OP_SUMHH: /* 16bit*4 1in & s1.h3+s1.h2->d.h3, s1.h1+s1.h0->d.h1 */
    t3 = ex1_outd>>48&0x000000000000ffffLL;
    t2 = ex1_outd>>32&0x000000000000ffffLL;
    t1 = ex1_outd>>16&0x000000000000ffffLL;
    t0 = ex1_outd    &0x000000000000ffffLL;
    t3 += t2;
    if (t3 > 0x000000000000ffffLL) t3 = 0x000000000000ffffLL;
    t1 += t0;
    if (t1 > 0x000000000000ffffLL) t1 = 0x000000000000ffffLL;
    ex2_outd = (t3<<48)|(t1<<16);
    break;
  case OP_SUMHL: /* 16bit*4 1in & s1.h3+s1.h2->d.h2, s1.h1+s1.h0->d.h0 */
    t3 = ex1_outd>>48&0x000000000000ffffLL;
    t2 = ex1_outd>>32&0x000000000000ffffLL;
    t1 = ex1_outd>>16&0x000000000000ffffLL;
    t0 = ex1_outd    &0x000000000000ffffLL;
    t2 += t3;
    if (t2 > 0x000000000000ffffLL) t2 = 0x000000000000ffffLL;
    t0 += t1;
    if (t0 > 0x000000000000ffffLL) t0 = 0x000000000000ffffLL;
    ex2_outd = (t2<<32)|(t0);
    break;
//case OP_WSWAP: /* 32bit 2in swap and mask words */
//  ex2_outd = ((ex1_outd<<32)|(ex1_outd>>32)) & r4;
//  break;
  default:
    printf("emax6lib: exe: undefined op_ex2=%d\n", op_ex2);
    break;
  }

  switch (op_ex3) {
  case OP_NOP:
    if (op_ex1 == OP_SFMA)
      softu64(3, NULL, &ex2_outd, d, r1, r2, r3, r4);
    else
      if (d) *d = ex2_outd;
    break;
  case OP_SLL: /* 32bit*2 2in 32bit logical shift to left */
    t1 = (Ull)(ex2_outd    &0xffffffff00000000LL)<<r5;
    t0 = (Ull)(ex2_outd<<r5&0x00000000ffffffffLL);
    if (d) *d = t1 | t0;
    break;
  case OP_SRL: /* 32bit*2 2in 32bit logical shift to right */
    t1 = (Ull)(ex2_outd>>r5&0xffffffff00000000LL);
    t0 = (Ull)(ex2_outd    &0x00000000ffffffffLL)>>r5;
    if (d) *d = t1 | t0;
    break;
  case OP_SRAA: /* 32bit*2 2in 32bit arith shift to right (bit63,31 is ext.) */
    t1 = (Sll)(ex2_outd    )>>r5&0xffffffff00000000LL;
    t0 = (Sll)(ex2_outd<<32)>>r5&0xffffffff00000000LL;
    if (d) *d = t1 | (t0>>32);
    break;
  case OP_SRAB: /* 32bit*2 2in 32bit arith shift to right (bit55,23 is ext.) */
    t1 = (Sll)(ex2_outd<< 8)>>(r5+8)&0xffffffff00000000LL;
    t0 = (Sll)(ex2_outd<<40)>>(r5+8)&0xffffffff00000000LL;
    if (d) *d = t1 | (t0>>32);
    break;
//case OP_SRAC: /* 32bit*2 2in 32bit arith shift to right (bit47,15 is ext.) */
//  t1 = (Sll)(ex2_outd<<16)>>(r5+16)&0xffffffff00000000LL;
//  t0 = (Sll)(ex2_outd<<48)>>(r5+16)&0xffffffff00000000LL;
//  if (d) *d = t1 | (t0>>32);
//  break;
//case OP_SRAD: /* 32bit*2 2in 32bit arith shift to right (bit39,7 is ext.) */
//  t1 = (Sll)(ex2_outd<<24)>>(r5+24)&0xffffffff00000000LL;
//  t0 = (Sll)(ex2_outd<<56)>>(r5+24)&0xffffffff00000000LL;
//  if (d) *d = t1 | (t0>>32);
//  break;
  case OP_SRLM: /* 16bit*4 2in 16bit arith shift to right */
    t3 = (Ull)(ex2_outd    )>>r5&0xffff000000000000LL;
    t2 = (Ull)(ex2_outd<<16)>>r5&0xffff000000000000LL;
    t1 = (Ull)(ex2_outd<<32)>>r5&0xffff000000000000LL;
    t0 = (Ull)(ex2_outd<<48)>>r5&0xffff000000000000LL;
    if (d) *d = t3 | (t2>>16) | (t1>>32) | (t0>>48);
    break;
  default:
    printf("emax6lib: exe: undefined op_ex3=%d\n", op_ex3);
    break;
  }

  return (retval);
}

void /*__attribute__((always_inline))*/
eag(Ull *adr, Ull base, Ull offset, Uchar msk)
{
  switch (msk) {
  case  MSK_D0:
    break;
  case  MSK_W1:		
    offset = offset>>32;
    break;
  case  MSK_W0:
    offset = offset&0x00000000ffffffffLL;
    break;
  case  MSK_H3:
    offset = offset>>48&0x000000000000ffffLL;
    break;
  case  MSK_H2:
    offset = offset>>32&0x000000000000ffffLL;
    break;
  case  MSK_H1:
    offset = offset>>16&0x000000000000ffffLL;
    break;
  case  MSK_H0:
    offset = offset&0x000000000000ffffLL;
    break;
  case  MSK_B7:
    offset = offset>>56&0x00000000000000ffLL;
    break;
  case  MSK_B6:
    offset = offset>>48&0x00000000000000ffLL;
    break;
  case  MSK_B5:
    offset = offset>>40&0x00000000000000ffLL;
    break;
  case  MSK_B4:
    offset = offset>>32&0x00000000000000ffLL;
    break;
  case  MSK_B3:
    offset = offset>>24&0x00000000000000ffLL;
    break;
  case  MSK_B2:
    offset = offset>>16&0x00000000000000ffLL;
    break;
  case  MSK_B1:
    offset = offset>>8&0x00000000000000ffLL;
    break;
  case  MSK_B0:
    offset = offset&0x00000000000000ffLL;
    break;
  default:
    printf("emax6lib: eag: undefined msk=%d\n", msk);
    break;
  }

  *adr = base + offset;
}

void /*__attribute__((always_inline))*/
mop(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr;

  eag(&adr, base, offset, msk);
  mmp(op_mm, ex, d, adr, top, len, blk);
}

void /*__attribute__((always_inline))*/
mo4(Uint op_mm, Ull ex, Ull *d, Ull base, Ull offset, Uchar msk, Ull top, Uint len, Uint blk, Uchar force, Ull ptop, Uint plen)
{
  Ull adr;

  eag(&adr, base, offset, msk);
  mmp(op_mm, ex, d, adr, top, len, blk);
}

int emax6_unaligned_load_valid; /* mop(BR[][][1]adr+8); mop(BR[][][0]adr);Ϣ³��������ꤷ,1�ξ��high��ͭ��,0�ξ��̵��  */
Ull emax6_unaligned_load_high;  /* mop(BR[][][1]adr+8); mop(BR[][][0]adr);Ϣ³��������ꤷ,high¦��켡��¸��low¦��merge */

void /*__attribute__((always_inline))*/
mmp(Uint op_mm, Ull ex, Ull *d, Ull adr, Ull top, Uint len, Uint blk)
{
  Ull c1, c0, load64;

#if defined(__i386)
  adr &= (1LL<<32)-1;
  top &= (1LL<<32)-1;
#endif  

  if (!adr || !top) return; /* NULL skip DMA */
  
#define CHECK_MMP_MARGINE 12
  if (adr < top || adr >= top+len*sizeof(Uint)+CHECK_MMP_MARGINE) {
    printf("mmp: adr=%08.8x_%08.8x out of range (top=%08.8x_%08.8x len=%dB)\n", (Uint)(adr>>32), (Uint)adr, (Uint)(top>>32), (Uint)top, len*sizeof(Uint));
    fflush(stdout);
  }

  c1 = ex>>1&1;
  c0 = ex   &1;

  switch (op_mm) {
  case OP_NOP:
    break;

    /* MOP */
  case OP_LDR: /* 64bit lmm LMM is preloaded, random-access */
    load64 = *(Ull*)(adr&~7LL);
    if ((adr&7) == 0)
      *d = load64;
    else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
      emax6_unaligned_load_valid = 1;
      emax6_unaligned_load_high = load64;
      *d = load64 >> (adr&7)*8;
    }
    else { /* BR[][][0] */
      emax6_unaligned_load_valid = 0; 
      *d = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
    }
    break;
  case OP_LDWR: /* s32bit lmm LMM is preloaded, random-access */
    *d = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
    break;
  case OP_LDUWR: /* u32bit lmm LMM is preloaded, random-access */
    *d = (Ull)*(Uint*)(adr&~3LL)<<32 | (Ull)*(Uint*)(adr&~3LL);
    break;
//case OP_LDHR: /* s16bit lmm LMM is preloaded, random-access */
//  *d = (Ull)(Uint)(int)*(short*)(adr&~1LL)<<32 | (Ull)(Uint)(int)*(short*)(adr&~1LL);
//  break;
//case OP_LDUHR: /* u16bit lmm LMM is preloaded, random-access */
//  *d = (Ull)(Uint)*(Ushort*)(adr&~1LL)<<32 | (Ull)(Uint)*(Ushort*)(adr&~1LL);
//  break;
  case OP_LDBR: /* s8bit lmm LMM is preloaded, random-access */
    *d = (Ull)(Uint)(int)*(char*)adr<<32 | (Ull)(Uint)(int)*(char*)adr;
    break;
  case OP_LDUBR: /* u8bit lmm LMM is preloaded, random-access */
    *d = (Ull)(Uint)*(Uchar*)adr<<32 | (Ull)(Uint)*(Uchar*)adr;
    break;
  case OP_STR: /* 64bit lmm LMM is drained. random-access */
    if (c1) *((Uint*)(adr&~7LL)+1) = *d>>32;
    if (c0) *((Uint*)(adr&~7LL)  ) = *d;
    break;
  case OP_STWR: /* 32bit lmm LMM is drained. random-access */
    if (c0) *(Uint*)(adr&~3LL) = *d;
    break;
//case OP_STHR: /* 16bit lmm LMM is drained. random-access */
//  if (c0) *(Ushort*)(adr&~1LL) = *d;
//  break;
  case OP_STBR: /* 8bit lmm LMM is drained. random-access */
    if (c0) *(Uchar*)adr = *d;
    break;

    /* MO4 */
  case OP_LDRQ: /* 64bit*4 lmm LMM is preloaded, random-access */
    switch (blk) {
    case 0: /* normal */
      /* adr=0,32,64,... */
      *(d+0) = *((Ull*)(adr&~31LL)+0);
      *(d+1) = *((Ull*)(adr&~31LL)+1);
      *(d+2) = *((Ull*)(adr&~31LL)+2);
      *(d+3) = *((Ull*)(adr&~31LL)+3);
      break;
    case 1: /* block_size=16-members */
      /* adr=0,32,64,... memadr = mem(top + (adr/32/16*ptr)) + (adr/32/&15)*4 */
      *(d+0) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/16*sizeof(Ull*))) + (adr/32&15)*4 + 3);
      break;
    case 2: /* block_size=32-members */
      /* adr=0,32,64,... memadr = mem(top + (adr/32/32*ptr)) + (adr/32/&31)*4 */
      *(d+0) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/32*sizeof(Ull*))) + (adr/32&31)*4 + 3);
      break;
    default:/* block_size=64-members */
      /* adr=0,32,64,... memadr = mem(top + (adr/32/64*ptr)) + (adr/32/&63)*4 */
      *(d+0) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 0);
      *(d+1) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 1);
      *(d+2) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 2);
      *(d+3) = *(*(Ull**)(top + (adr/32/64*sizeof(Ull*))) + (adr/32&63)*4 + 3);
      break;
    }
    break;
  case OP_LDDMQ: /* 64bit*4 mem Direct access to MM */
    if (c0) {
      *(d+0) = *((Ull*)(adr&~31LL)+0);
      *(d+1) = *((Ull*)(adr&~31LL)+1);
      *(d+2) = *((Ull*)(adr&~31LL)+2);
      *(d+3) = *((Ull*)(adr&~31LL)+3);
    }
    break;
  case OP_STRQ: /* 64bit*4 lmm LMM is drained. random-access */
    *((Ull*)(adr&~31LL)+0) = *(d+0);
    *((Ull*)(adr&~31LL)+1) = *(d+1);
    *((Ull*)(adr&~31LL)+2) = *(d+2);
    *((Ull*)(adr&~31LL)+3) = *(d+3);
    break;
  case OP_TR: /* 64bit*4 exec Send transaction */
    /* addr��transaction()����˻��� */
    if (c0) {
      Ull (*trans)() = top;
      (trans)(*(d+0), *(d+1), *(d+2), *(d+3));
    }
    break;
  default:
    printf("emax6lib: mmp: undefined op_mm=%d\n", op_mm);
    break;
  }
}
#endif