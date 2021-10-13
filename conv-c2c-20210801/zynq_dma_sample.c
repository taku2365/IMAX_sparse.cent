#define SRC_PHYS_ADDR	(0x400000000ULL)	// FPD-PL (HPM0)
#define DST_PHYS_ADDR	(0x800000000ULL)	// DDR High

int main(int argc, char *argv[])
{
  int result = EXIT_FAILURE;

  /* open UIO devices. */
  const int fd_bram = open("/dev/uio8", O_RDWR | O_SYNC);
  if (fd_bram == -1) {
    printf("open(\"/dev/uio8\", ...) failed.\n");
    goto err_open_bram;
  }
  const int fd_ddr = open("/dev/uio9", O_RDWR | O_SYNC);
  if (fd_ddr == -1) {
    printf("open(\"/dev/uio9\", ...) failed.\n");
    goto err_open_ddr;
  }

  /* mmap for the verification. */
  uint8_t * const src = mmap(NULL, SRC_MAX_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd_bram, 0);
  if (src == MAP_FAILED) {
    printf("src mmap() failed.\n");
    goto err_mmap_src;
  }
  uint8_t * const dst = mmap(NULL, DST_MAX_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd_ddr, 0);
  if (dst == MAP_FAILED) {
    printf("dst mmap() failed.\n");
    goto err_mmap_dst;
  }
  /* memcpy. */
  printf("  1 *     memcpy(0x%09llx, 0x%09llx, 0x%09zx)\t... ", DST_PHYS_ADDR, SRC_PHYS_ADDR, (size_t)SRC_MAX_SIZE);
  memcpy(dst, src, SRC_MAX_SIZE);

  /* dma_memcpy. */
  {
    /* Initialize DMA (optional). */
    dma_memcpy_init();
    for (size_t dma_size = 4096; dma_size <= SRC_MAX_SIZE; dma_size *= 2) {
      printf("%3llu * dma_memcpy(0x%09llx, 0x%09llx, 0x%09zx)\t... ", SRC_MAX_SIZE / dma_size, DST_PHYS_ADDR, SRC_PHYS_ADDR, dma_size);
      for (int loop = 0; loop < SRC_MAX_SIZE / dma_size; ++loop)
	dma_memcpy(DST_PHYS_ADDR + loop * dma_size, SRC_PHYS_ADDR + loop * dma_size, dma_size);
    }
    /* Terminate DMA (optional). */
    dma_memcpy_term();
  }
  result = EXIT_SUCCESS;
  return result;
}

// Number of FPD-DMA channels.
#define FPD_DMA_NUM_CHANNELS			(8)

// Registers offsets.
#define ZDMA_CH_CTRL0_OFFSET			(0x110U)		// Channel Control Register 0
#define ZDMA_CH_STATUS_OFFSET			(0x11CU)		// Channel Status Register
#define ZDMA_CH_SRC_DSCR_WORD0_OFFSET	(0x128U)		// SRC DSCR Word 0
#define ZDMA_CH_SRC_DSCR_WORD1_OFFSET	(0x12CU)		// SRC DSCR Word 1
#define ZDMA_CH_SRC_DSCR_WORD2_OFFSET	(0x130U)		// SRC DSCR Word 2
#define ZDMA_CH_DST_DSCR_WORD0_OFFSET	(0x138U)		// DST DSCR Word 0
#define ZDMA_CH_DST_DSCR_WORD1_OFFSET	(0x13CU)		// DST DSCR Word 1
#define ZDMA_CH_CTRL2_OFFSET			(0x200U)		// Channel Control Register 2

// Channel Control0 register bit masks.
#define ZDMA_CTRL0_POINT_TYPE_MASK		(0x00000040U)	// Pointer type mask.

// Channel Status register bit masks.
#define ZDMA_STS_DONE_ERR_MASK			(0x00000003U)	// Done with errors mask.
#define ZDMA_STS_DONE_MASK				(0x00000000U)	// ZDMA done mask.
#define ZDMA_STS_ALL_MASK				(0x00000003U)	// ZDMA status mask.

// Channel Source/Destination Word0 register bit mask.
#define ZDMA_WORD0_LSB_MASK				(0xFFFFFFFFU)	// LSB Address mask.

// Channel Source/Destination Word1 register bit mask and shift.
#define ZDMA_WORD1_MSB_MASK				(0x0001FFFFU)	// MSB Address mask.
#define ZDMA_WORD1_MSB_SHIFT			(32U)			// MSB Address shift.

// Channel Source/Destination Word2 register bit mask.
#define ZDMA_WORD2_SIZE_MASK			(0x3FFFFFFFU)	// Size mask.

// Channel control2 register bit mask.
#define ZDMA_CH_CTRL2_EN_MASK			(0x00000001U)	// Channel enable mask.


//=============================================================================
// Variable Definitions.
//=============================================================================
static int num_valid_channels = 0;
static void *reg_addr[FPD_DMA_NUM_CHANNELS];
static size_t reg_size[FPD_DMA_NUM_CHANNELS];


//=============================================================================
// Function Prototypes.
//=============================================================================
static int filter(const struct dirent *dir);
static void trim(char *d_name);
static bool is_dma_dev(char *d_name);
static size_t get_reg_size(char *d_name);
static uint32_t reg_read32(const void *addr, uint32_t offset);
static void reg_write32(const void *addr, uint32_t offset, uint32_t value);
static void dma_memcpy_reset(uint8_t chan);


//=============================================================================
// Function Definitions.
//=============================================================================
/**
* dma_memcpy_init - Create pointers to mapped DMA registers.
*/
void dma_memcpy_init(void)
{
  if (num_valid_channels > 0)
    return;

  struct dirent **namelist;
  const int num_dirs = scandir("/sys/class/uio", &namelist, filter, alphasort);
  if (num_dirs == -1)
    return;

  for (int dir = 0; dir < num_dirs; ++dir) {
    trim(namelist[dir]->d_name);

    if (!is_dma_dev(namelist[dir]->d_name)) {
      free(namelist[dir]);
      continue;
    }

    reg_size[num_valid_channels] = get_reg_size(namelist[dir]->d_name);
    if (reg_size[num_valid_channels] == 0) {
      free(namelist[dir]);
      continue;
    }

    char path[32];
    sprintf(path, "/dev/%s", namelist[dir]->d_name);
    free(namelist[dir]);

    const int fd = open(path, O_RDWR | O_SYNC);
    if (fd == -1)
      continue;

    reg_addr[num_valid_channels] = mmap(NULL, reg_size[num_valid_channels], PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    if (reg_addr[num_valid_channels] != MAP_FAILED)
      ++num_valid_channels;
    if (num_valid_channels == FPD_DMA_NUM_CHANNELS)
      break;
  }

  free(namelist);
}

/**
* dma_memcpy_term - Delete pointers to mapped DMA registers.
*/
void dma_memcpy_term(void)
{
  if (num_valid_channels <= 0)
    return;

  for (int chan = 0; chan < num_valid_channels; ++chan) {
    munmap(reg_addr[chan], reg_size[chan]);
  }

  num_valid_channels = 0;
}

/**
* dma_memcpy_simple - Simple mode data transfer.
*/
size_t dma_memcpy_simple(uint8_t chan, uint64_t dest, uint64_t src, size_t n)
{
  dma_memcpy_init();

  if (chan >= num_valid_channels)
    return 0;
  
  dma_memcpy_reset(chan);

  /* UG1085 - Step 1. */
  while (true) {
    const uint32_t value = reg_read32(reg_addr[chan], ZDMA_CH_STATUS_OFFSET) & ZDMA_STS_ALL_MASK;
    if (value == ZDMA_STS_DONE_MASK)
      break;
    if (value == ZDMA_STS_DONE_ERR_MASK)
      break;
    return 0;
  }

  /* UG1085 - Step 2. */
  reg_write32(reg_addr[chan], ZDMA_CH_CTRL0_OFFSET, reg_read32(reg_addr[chan], ZDMA_CH_CTRL0_OFFSET) & ~ZDMA_CTRL0_POINT_TYPE_MASK);
  reg_write32(reg_addr[chan], ZDMA_CH_SRC_DSCR_WORD0_OFFSET, src & ZDMA_WORD0_LSB_MASK);
  reg_write32(reg_addr[chan], ZDMA_CH_SRC_DSCR_WORD1_OFFSET, (src >> ZDMA_WORD1_MSB_SHIFT) & ZDMA_WORD1_MSB_MASK);

  /* UG1085 - Step 3. */
  reg_write32(reg_addr[chan], ZDMA_CH_DST_DSCR_WORD0_OFFSET, dest & ZDMA_WORD0_LSB_MASK);
  reg_write32(reg_addr[chan], ZDMA_CH_DST_DSCR_WORD1_OFFSET, (dest >> ZDMA_WORD1_MSB_SHIFT) & ZDMA_WORD1_MSB_MASK);

  /* UG1085 - Step 4. */
  reg_write32(reg_addr[chan], ZDMA_CH_SRC_DSCR_WORD2_OFFSET, n & ZDMA_WORD2_SIZE_MASK);

  /* UG1085 - Step 7. */
  reg_write32(reg_addr[chan], ZDMA_CH_CTRL2_OFFSET, ZDMA_CH_CTRL2_EN_MASK);

  /* Wait for completion. */
  while (true) {
    const uint32_t value = reg_read32(reg_addr[chan], ZDMA_CH_STATUS_OFFSET) & ZDMA_STS_ALL_MASK;
    if (value == ZDMA_STS_DONE_MASK)
      break;
    if (value == ZDMA_STS_DONE_ERR_MASK)
      return 0;
  }

  return n;
}

/**
 * dma_memcpy - Data transfer wrapper function.
 */
size_t dma_memcpy(uint64_t dest, uint64_t src, size_t n)
{
  for (uint8_t chan = 0; chan < FPD_DMA_NUM_CHANNELS; ++chan) {
    if (dma_memcpy_simple(chan, dest, src, n) == n)
      return n;
  }
  return 0;
}

/**
 * filter - Directory entry filter.
 */
static int filter(const struct dirent *dir)
{
  return dir->d_name[0] == '.' ? 0 : 1;
}

/**
 * trim - Trim '\n'.
 */
static void trim(char *d_name)
{
  char * const p = strchr(d_name, '\n');

  if (p != NULL)
    *p = '\0';
}

/**
 * is_dma_dev - Is the targe UIO a DMA device?
 */
static bool is_dma_dev(char *d_name)
{
  char path[32];
  sprintf(path, "/sys/class/uio/%s/name", d_name);

  FILE * const fp = fopen(path, "r");
  if (fp == NULL)
    return false;
  
  char name[32];
  const char *result = fgets(name, sizeof(name), fp);
  fclose(fp);

  if (result == NULL)
    return false;

  if (strcmp(name, "dma\n") != 0)
    return false;

  return true;
}

/**
 * get_reg_size - Get size of register.
 */
static size_t get_reg_size(char *d_name)
{
  char path[32];
  sprintf(path, "/sys/class/uio/%s/maps/map0/size", d_name);
  
  FILE *fp = fopen(path, "r");
  if (fp == NULL)
    return 0;
  
  char size[32];
  if (fgets(size, sizeof(size), fp) == NULL) {
    fclose(fp);
    return 0;
  }
  
  fclose(fp);
  return strtoull(size, NULL, 16);
}

/**
 * reg_read32 - Read a 32-bit register.
 */
static uint32_t reg_read32(const void *addr, uint32_t offset)
{
  return *(volatile uint32_t *)(addr + offset);
}
/**
 * reg_write32 - Write a 32-bit register.
 */
static void reg_write32(const void *addr, uint32_t offset, uint32_t value)
{
  volatile uint32_t * const local_addr = (volatile uint32_t *)(addr + offset);
  *local_addr = value;
}

/**
 * dma_memcpy_reset - Reset a DMA register.
 *
 * See: https://japan.xilinx.com/html_docs/registers/ug1087/mod___zdma.html
 */
static void dma_memcpy_reset(uint8_t chan)
{
  if (chan >= num_valid_channels || reg_addr[chan] == 0)
    return;

  reg_write32(reg_addr[chan], 0x00000000, 0x00000001);
  reg_write32(reg_addr[chan], 0x00000100, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000104, 0x00000FFF);
  reg_write32(reg_addr[chan], 0x00000108, 0x00000000);
  reg_write32(reg_addr[chan], 0x0000010C, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000110, 0x00000080);
  reg_write32(reg_addr[chan], 0x00000114, 0x000003FF);
  reg_write32(reg_addr[chan], 0x00000118, 0x00000000);
  reg_write32(reg_addr[chan], 0x0000011C, 0x00000000);
  
  /* Note - AxCACHE: 0011 value recomended by Xilinx. */
  reg_write32(reg_addr[chan], 0x00000120, 0x04C3D30F);
	
  reg_write32(reg_addr[chan], 0x00000124, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000128, 0x00000000);
  reg_write32(reg_addr[chan], 0x0000012C, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000130, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000134, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000138, 0x00000000);
  reg_write32(reg_addr[chan], 0x0000013C, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000140, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000144, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000148, 0x00000000);
  reg_write32(reg_addr[chan], 0x0000014C, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000150, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000154, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000158, 0x00000000);
  reg_write32(reg_addr[chan], 0x0000015C, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000160, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000164, 0x00000000);
  reg_write32(reg_addr[chan], 0x0000018C, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000190, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000194, 0x00000000);
  reg_write32(reg_addr[chan], 0x00000200, 0x00000000);
}