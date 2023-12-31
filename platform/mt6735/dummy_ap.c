// Dummy AP
#include <platform/boot_mode.h>
#include <debug.h>
#include <dev/uart.h>
#include <platform/mtk_key.h>
#include <target/cust_key.h>
#include <platform/mt_gpio.h>
#include <sys/types.h>
#include <debug.h>
#include <err.h>
#include <reg.h>
#include <string.h>
#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_irq.h>
#include <platform/mt_pmic.h>
#include <platform/timer.h>
#include <sys/types.h>
#include <arch/ops.h>

#define THIS_IS_EVB
#define BOTH_MD_ON
//#define CCIF_DVT
//#define DEFAULT_META
//#define ENABLE_MD_RESET_SPM
//#define ENABLE_MD_RESET_RGU
//#define IGNORE_MD_WDT

#ifdef ENABLE_MD_RESET_SPM
#include <platform/spm.h>
#endif

//#define TEMP_COTSX // request by Sw Huang

#define MAX_MD_NUM			(2)
#define MAX_IMG_NUM			(8)
#define PART_HEADER_MAGIC	(0x58881688)
#define BOOT_ARGS_ADDR		(0x87F00000)
#define IMG_HEADER_ADDR		(0x87F00000+1024)

#define GIC_PRIVATE_SIGNALS	(32)
#define MT_MD_WDT1_IRQ_ID	(253)
#define MT_MD_WDT2_IRQ_ID	(261)

#define MD1_BANK0_MAP0 (0x10000300)
#define MD2_BANK0_MAP0 (0x10000310)
#define C2K_CONFIG (0x10000330)
#define C2K_STATUS (0x10000334)
#define C2K_SPM_CTRL (0x10000338)
#define SLEEP_CLK_CON (0x10006400)
//#define TOPRGU_BASE (0x10212000)
#define TOP_RGU_WDT_MODE (TOPRGU_BASE+0x0)
#define TOP_RGU_WDT_SWRST (TOPRGU_BASE+0x14)
#define TOP_RGU_WDT_SWSYSRST (TOPRGU_BASE+0x18)
#define TOP_RGU_WDT_NONRST_REG (TOPRGU_BASE+0x20)

#define C2K_CHIP_ID (0x3a00b01c)

typedef enum{
	DUMMY_AP_IMG = 0,
	MD1_IMG,
	MD1_RAM_DISK,
	MD2_IMG,
	MD2_RAM_DISK,
	MD_DSP
}img_idx_t;

typedef struct _map
{
	char		name[32];
	img_idx_t	idx;
}map_t;

#if 0
typedef union
{
	struct
	{
		unsigned int magic;	 /* partition magic */
		unsigned int dsize;	 /* partition data size */
		char name[32];		  /* partition name */
		unsigned int maddr;	 /* partition memory address */
	} info;
	unsigned char data[512];
} part_hdr_t;

// Notice for MT6582
// Update LK BOOT_ARGUMENT structure
typedef struct {
	unsigned int  magic_number;
	BOOTMODE	  boot_mode;
	unsigned int  e_flag;
	unsigned int  log_port;
	unsigned int  log_baudrate;
	unsigned char log_enable;
	unsigned char part_num;
	unsigned char reserved[2];
	unsigned int  dram_rank_num;
	unsigned int  dram_rank_size[4];
	unsigned int  boot_reason;
	unsigned int  meta_com_type;
	unsigned int  meta_com_id;
	unsigned int  boot_time;
	da_info_t	 da_info;
	SEC_LIMIT	 sec_limit;	
	part_hdr_t	*part_info;
} BOOT_ARGUMENT;
#endif

extern BOOT_ARGUMENT	*g_boot_arg;
//static BOOT_ARGUMENT	*boot_args=BOOT_ARGS_ADDR;
//static unsigned int	*img_header_array = (unsigned int*)IMG_HEADER_ADDR;
static unsigned int img_load_flag = 0;
static part_hdr_t *img_info_start = NULL;
static unsigned int img_addr_tbl[MAX_IMG_NUM];
static unsigned int img_size_tbl[MAX_IMG_NUM];
static map_t map_tbl[] = 
{
	{"DUMMY_AP",		DUMMY_AP_IMG},
	{"MD_IMG",		MD1_IMG},
	{"MD_RAM_DISK",		MD1_RAM_DISK},
	{"MD_DSP",		MD_DSP},
	{"MD2_IMG",		MD2_IMG},
	{"MD2_RAM_DISK",	MD2_RAM_DISK},
};

extern int mt_set_gpio_mode_chip(unsigned int pin, unsigned int mode);
void pmic_init_sequence(void);
void md_uart_config(int md_id);

int parse_img_header(unsigned int *start_addr, unsigned int img_num)
{
	unsigned int i, j;
	int idx;

	if(start_addr == NULL) {
		printf("parse_img_header get invalid parameters!\n");
		return -1;
	}
	img_info_start = (part_hdr_t*)start_addr;
	for(i=0; i<img_num; i++) {
		if(img_info_start[i].info.magic != PART_HEADER_MAGIC)
			continue;

		for(j=0; j<(sizeof(map_tbl)/sizeof(map_t)); j++) {
			if(strcmp(img_info_start[i].info.name, map_tbl[j].name) == 0) {
				idx = map_tbl[j].idx;
				img_addr_tbl[idx] = img_info_start[i].info.maddr;
				img_size_tbl[idx] = img_info_start[i].info.dsize;
				img_load_flag |= (1<<idx);
				printf("[%s] idx:%d, addr:0x%x, size:0x%x\n", map_tbl[j].name, idx, img_addr_tbl[idx], img_size_tbl[idx]);
			}
		}
	}
	return 0;
}

static int meta_detection(void)
{
	int boot_mode = 0;
	
	if(g_boot_arg->boot_mode != NORMAL_BOOT)
		boot_mode = 1;
	printf("Meta mode: %d, boot_mode: %d\n", boot_mode, g_boot_arg->boot_mode);
	return boot_mode;
}

static void md_gpio_get(GPIO_PIN pin, char *tag)
{
	printf("GPIO(%X)(%s): mode=%d,dir=%d,in=%d,out=%d,pull_en=%d,pull_sel=%d,smt=%d\n",
			pin, tag,
			mt_get_gpio_mode(pin),
			mt_get_gpio_dir(pin),
			mt_get_gpio_in(pin),
			mt_get_gpio_out(pin),
			mt_get_gpio_pull_enable(pin),
			mt_get_gpio_pull_select(pin),
			mt_get_gpio_smt(pin));
}

static void md_gpio_set(GPIO_PIN pin, GPIO_MODE mode, GPIO_DIR dir, GPIO_OUT out, GPIO_PULL_EN pull_en, GPIO_PULL pull, GPIO_SMT smt)
{
	mt_set_gpio_mode(pin, mode);
	if(dir != GPIO_DIR_UNSUPPORTED)
		mt_set_gpio_dir(pin, dir);

	if(dir == GPIO_DIR_OUT) {
		mt_set_gpio_out(pin, out);
	}
	if(dir == GPIO_DIR_IN) {
		mt_set_gpio_smt(pin, smt);
	}
	if(pull_en != GPIO_PULL_EN_UNSUPPORTED) {
		mt_set_gpio_pull_enable(pin, pull_en);
		mt_set_gpio_pull_select(pin, pull);
	}
	md_gpio_get(pin, "-");
}

static void md_gpio_config(unsigned int boot_md_id)
{
	// init sim1
	mt_set_gpio_dir(GPIO_SIM1_SCLK, GPIO_DIR_OUT);
	mt_set_gpio_dir(GPIO_SIM1_SRST, GPIO_DIR_OUT);	
	mt_set_gpio_pull_enable(GPIO_SIM1_SIO, GPIO_PULL_ENABLE);
	mt_set_gpio_pull_select(GPIO_SIM1_SIO, GPIO_PULL_UP);
	mt_set_gpio_dir(GPIO_SIM1_SIO, GPIO_DIR_IN);
	mt_set_gpio_pull_enable(GPIO_SIM1_HOT_PLUG, GPIO_PULL_ENABLE);
	mt_set_gpio_pull_select(GPIO_SIM1_HOT_PLUG, GPIO_PULL_UP);
	mt_set_gpio_dir(GPIO_SIM1_HOT_PLUG, GPIO_DIR_IN);
	// init sim2
	mt_set_gpio_dir(GPIO_SIM2_SCLK, GPIO_DIR_OUT);
	mt_set_gpio_dir(GPIO_SIM2_SRST, GPIO_DIR_OUT);	 
	mt_set_gpio_pull_enable(GPIO_SIM2_SIO, GPIO_PULL_ENABLE);
	mt_set_gpio_pull_select(GPIO_SIM2_SIO, GPIO_PULL_UP);
	mt_set_gpio_dir(GPIO_SIM2_SIO, GPIO_DIR_IN);
	mt_set_gpio_pull_enable(GPIO_SIM2_HOT_PLUG, GPIO_PULL_ENABLE);
	mt_set_gpio_pull_select(GPIO_SIM2_HOT_PLUG, GPIO_PULL_UP);
	mt_set_gpio_dir(GPIO_SIM2_HOT_PLUG, GPIO_DIR_IN);

	switch(boot_md_id) {
	case 0: 
		//SIM1=> MD1 SIM1IF		   
		mt_set_gpio_mode(GPIO_SIM1_SCLK, GPIO_SIM1_SCLK_M_CLK);
		mt_set_gpio_mode(GPIO_SIM1_SRST, GPIO_SIM1_SRST_M_MD_SIM1_SRST);
		mt_set_gpio_mode(GPIO_SIM1_SIO, GPIO_SIM1_SIO_M_MD_SIM1_SDAT);
		mt_set_gpio_mode(GPIO_SIM1_HOT_PLUG, GPIO_SIM1_HOT_PLUG_M_MDEINT);
		//SIM2=> MD1 SIM2IF
		mt_set_gpio_mode(GPIO_SIM2_SCLK, GPIO_SIM2_SCLK_M_CLK);
		mt_set_gpio_mode(GPIO_SIM2_SRST, GPIO_SIM2_SRST_M_MD_SIM2_SRST);
		mt_set_gpio_mode(GPIO_SIM2_SIO, GPIO_SIM2_SIO_M_MD_SIM2_SDAT);
		mt_set_gpio_mode(GPIO_SIM2_HOT_PLUG, GPIO_SIM2_HOT_PLUG_M_MDEINT);
		break;
	case 1:
		//SIM1=> MD2 UIM0IF
		mt_set_gpio_mode(GPIO_SIM1_SCLK, GPIO_SIM1_SCLK_M_UIM0_CLK);
		mt_set_gpio_mode(GPIO_SIM1_SRST, GPIO_SIM1_SRST_M_UIM0_RST);
		mt_set_gpio_mode(GPIO_SIM1_SIO, GPIO_SIM1_SIO_M_UIM0_IO);
		mt_set_gpio_mode(GPIO_SIM1_HOT_PLUG, GPIO_SIM1_HOT_PLUG_M_C2K_UIM0_HOT_PLUG_IN);
		//SIM2=> MD2 UIM1IF
		mt_set_gpio_mode(GPIO_SIM2_SCLK, GPIO_SIM2_SIO_M_UIM1_IO);
		mt_set_gpio_mode(GPIO_SIM2_SRST, GPIO_SIM2_SRST_M_UIM1_RST);
		mt_set_gpio_mode(GPIO_SIM2_SIO, GPIO_SIM2_SIO_M_UIM1_IO);
		mt_set_gpio_mode(GPIO_SIM2_HOT_PLUG, GPIO_SIM2_HOT_PLUG_M_C2K_UIM1_HOT_PLUG_IN);
		break;
	case 2:
		//SIM1=> MD1 SIM1IF
		mt_set_gpio_mode(GPIO_SIM1_SCLK, GPIO_SIM1_SCLK_M_CLK);
		mt_set_gpio_mode(GPIO_SIM1_SRST, GPIO_SIM1_SRST_M_MD_SIM1_SRST);
		mt_set_gpio_mode(GPIO_SIM1_SIO, GPIO_SIM1_SIO_M_MD_SIM1_SDAT);
		mt_set_gpio_mode(GPIO_SIM1_HOT_PLUG, GPIO_SIM1_HOT_PLUG_M_MDEINT);
		//SIM2=> MD2 UIM0IF
		mt_set_gpio_mode(GPIO_SIM2_SCLK, GPIO_SIM2_SCLK_M_UIM0_CLK);
		mt_set_gpio_mode(GPIO_SIM2_SRST, GPIO_SIM2_SRST_M_UIM0_RST);
		mt_set_gpio_mode(GPIO_SIM2_SIO, GPIO_SIM2_SIO_M_UIM0_IO);
		mt_set_gpio_mode(GPIO_SIM2_HOT_PLUG, GPIO_SIM2_HOT_PLUG_M_C2K_UIM1_HOT_PLUG_IN);
		break;
	default:
		break;
	}
	
	md_gpio_get(GPIO_SIM1_SCLK, "sclk");
	md_gpio_get(GPIO_SIM1_SRST, "srst");
	md_gpio_get(GPIO_SIM1_SIO, "sio");
	md_gpio_get(GPIO_SIM1_HOT_PLUG, "hp");
	md_gpio_get(GPIO_SIM2_SCLK, "sclk2");
	md_gpio_get(GPIO_SIM2_SRST, "srst2");
	md_gpio_get(GPIO_SIM2_SIO, "sio2");
	md_gpio_get(GPIO_SIM2_HOT_PLUG, "hp2");

#ifndef MACH_TYPE_MT6735M // only for D-1&3
	if(boot_md_id == 1) {
		// BPI
#ifndef BOTH_MD_ON
		md_gpio_set(GPIO87, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO88, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO89, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO90, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO91, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO92, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO93, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO94, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO95, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO96, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
#endif
		// ARM GPIO/GPINT
		md_gpio_set(GPIO3, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO2, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO1, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO0, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		// DSPM GPIO
		md_gpio_set(GPIO4, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		// ARM legacy JATG
		md_gpio_set(GPIO82, GPIO_MODE_05, GPIO_DIR_IN, GPIO_OUT_UNSUPPORTED, GPIO_PULL_ENABLE, GPIO_PULL_DOWN, GPIO_SMT_ENABLE);
		md_gpio_set(GPIO81, GPIO_MODE_05, GPIO_DIR_IN, GPIO_OUT_UNSUPPORTED, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_ENABLE);
		md_gpio_set(GPIO83, GPIO_MODE_05, GPIO_DIR_IN, GPIO_OUT_UNSUPPORTED, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_DISABLE);
		md_gpio_set(GPIO85, GPIO_MODE_05, GPIO_DIR_IN, GPIO_OUT_UNSUPPORTED, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_DISABLE);
		md_gpio_set(GPIO84, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO86, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		// DSP JTAG
#ifdef THIS_IS_EVB
		md_gpio_set(GPIO199, GPIO_MODE_07, GPIO_DIR_IN, GPIO_OUT_UNSUPPORTED, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_ENABLE);
		md_gpio_set(GPIO198, GPIO_MODE_07, GPIO_DIR_IN, GPIO_OUT_UNSUPPORTED, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_DISABLE);
		md_gpio_set(GPIO200, GPIO_MODE_07, GPIO_DIR_IN, GPIO_OUT_UNSUPPORTED, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_DISABLE);
		md_gpio_set(GPIO201, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO202, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
#else
		md_gpio_set(GPIO71, GPIO_MODE_06, GPIO_DIR_IN, GPIO_OUT_UNSUPPORTED, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_ENABLE);
		md_gpio_set(GPIO70, GPIO_MODE_06, GPIO_DIR_IN, GPIO_OUT_UNSUPPORTED, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_DISABLE);
		md_gpio_set(GPIO72, GPIO_MODE_06, GPIO_DIR_IN, GPIO_OUT_UNSUPPORTED, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_DISABLE);
		md_gpio_set(GPIO73, GPIO_MODE_06, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO46, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
#endif
		// C2K UART0
#ifdef THIS_IS_EVB
		// covered in uart config
		//md_gpio_set(GPIO75, GPIO_MODE_05, GPIO_DIR_OUT, GPIO_OUT_ONE, GPIO_PULL_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		//md_gpio_set(GPIO74, GPIO_MODE_05, GPIO_DIR_IN, GPIO_OUT_UNSUPPORTED, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_DISABLE);
#else
		md_uart_config(-1);
		md_gpio_set(GPIO199, GPIO_MODE_03, GPIO_DIR_OUT, GPIO_OUT_ONE, GPIO_PULL_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO198, GPIO_MODE_03, GPIO_DIR_IN, GPIO_OUT_UNSUPPORTED, GPIO_PULL_ENABLE, GPIO_PULL_UP, GPIO_SMT_DISABLE);
#endif
		// C2K DropZone assert
		md_gpio_set(GPIO63, GPIO_MODE_00, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		// debug port
#ifdef THIS_IS_EVB
		md_gpio_set(GPIO13, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO14, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO15, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO16, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO17, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO18, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO19, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO20, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO21, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO42, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO43, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO44, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO45, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO57, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO58, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO59, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO60, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO61, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO62, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO63, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO64, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO65, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO66, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO67, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO68, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO78, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO79, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO80, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO120, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		md_gpio_set(GPIO10, GPIO_MODE_07, GPIO_DIR_OUT, GPIO_OUT_ZERO, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
#endif
	}
#endif
}

static void md_emi_remapping(unsigned int boot_md_id)
{
	unsigned int md_img_start_addr = 0;
	unsigned int md_emi_remapping_addr = 0;

	switch(boot_md_id) {
	case 0: // MD1
		md_img_start_addr = img_addr_tbl[MD1_IMG] - 0x40000000;
		md_emi_remapping_addr = MD1_BANK0_MAP0;
		break;
	case 1: // MD2
		md_img_start_addr = img_addr_tbl[MD2_IMG] - 0x40000000;
		md_emi_remapping_addr = MD2_BANK0_MAP0;
		break;
	default:
		break;
	}

	printf("---> Map 0x00000000 to 0x%x for MD%d\n", md_img_start_addr+0x40000000, boot_md_id+1);
	
	// For MDx_BANK0_MAP0 
	*((volatile unsigned int*)md_emi_remapping_addr) = (((md_img_start_addr >> 24) | 1) & 0xFF) \
	+ ((((md_img_start_addr + 0x02000000) >> 16) | 1<<8) & 0xFF00) \
	+ ((((md_img_start_addr + 0x04000000) >> 8) | 1<<16) & 0xFF0000) \
	+ ((((md_img_start_addr + 0x06000000) >> 0) | 1<<24) & 0xFF000000);
	
	// For MDx_BANK0_MAP1
	*((volatile unsigned int*)(md_emi_remapping_addr + 0x4)) = ((((md_img_start_addr + 0x08000000) >> 24) | 1) & 0xFF) \
	+ ((((md_img_start_addr + 0x0A000000) >> 16) | 1<<8) & 0xFF00) \
	+ ((((md_img_start_addr + 0x0C000000) >> 8) | 1<<16) & 0xFF0000) \
	+ ((((md_img_start_addr + 0x0E000000) >> 0) | 1<<24) & 0xFF000000);
	
	printf("---> MD_BANK0_MAP0=0x%x, MD_BANK0_MAP1=0x%x\n",
		*((volatile unsigned int*)md_emi_remapping_addr),
		*((volatile unsigned int*)(md_emi_remapping_addr + 0x4)));
}

static void md_power_up_mtcmos(unsigned int boot_md_id)
{
	volatile unsigned int loop = 10000;
	
	loop =10000;
	while(loop-->0);

	switch(boot_md_id) {
	case 0://MD 1
#ifdef ENABLE_MD_RESET_SPM
		spm_mtcmos_ctrl_mdsys1(STA_POWER_ON);
#else
		// default on
#endif
		break;		
	case 1:// MD2
#ifdef ENABLE_MD_RESET_SPM
		spm_mtcmos_ctrl_mdsys2(STA_POWER_ON);
#else
		// YP Lin will power it on in preloader
#endif
		break;
	default:
		break;  
	}
}

static void md_common_setting(int boot_md_id)
{
	// Put special setting here if needed, ex. Disable WDT
	volatile unsigned int *md_wdt;

	switch(boot_md_id) {
	case 0:
		md_wdt = (volatile unsigned int*)0x20050000;
		printf("Disable MD1 WDT\n");
		*md_wdt = 0x220E;
		mdelay(5);
		break;
	case 1:
		// C2K MD's WDT is dsiabled by default
		break;
	default:
		break;
	}
}

static void md_boot_up(unsigned int boot_md_id, unsigned int is_meta_mode)
{
	unsigned int reg_value;
	
	switch(boot_md_id) {
	case 0:// For MD1
#ifdef TEMP_COTSX 
		pmic_config_interface(0x0F08, 0x8040, 0xFFFF, 0x0);
		pmic_config_interface(0x0F0E, 0x8040, 0xFFFF, 0x0);
		pmic_config_interface(0x0F12, 0x0004, 0xFFFF, 0x0);
#endif
		// step 1: enable VSRAM
		md_gpio_set(GPIO_LTE_VSRAM_EXT_POWER_EN_PIN, GPIO_MODE_00, GPIO_DIR_OUT, GPIO_OUT_ONE, GPIO_PULL_EN_UNSUPPORTED, GPIO_PULL_UNSUPPORTED, GPIO_SMT_UNSUPPORTED);
		// step 2: md1_srcclkena and md2_srcclkena in C2K_SPM_CTRL
		*((volatile unsigned int*)C2K_SPM_CTRL) &= ~(0xF<<2);
		*((volatile unsigned int*)C2K_SPM_CTRL) |= (0x9<<2);
		printf("C2K_SPM_CTRL = 0x%x\n", *((volatile unsigned int*)C2K_SPM_CTRL));
		// MD1 will init and configure PMIC by itself
		// step 3: set META Register
		if(is_meta_mode) {	
			*((volatile unsigned int*)0x20000010) |= 0x1; // Bit0, Meta mode flag, this need sync with MD init owner
		}
		// step 4: set boot slave
		*((volatile unsigned int*)0x2019379C) = 0x3567C766; // Key Register
		*((volatile unsigned int*)0x20190000) = 0x0;		 // Vector Register
		*((volatile unsigned int*)0x20195488) = 0xA3B66175; // Slave En Register
		break;
	case 1:// For MD2
		// C2K MD does not need META mode
		// step 1: set C2K boot mode
		reg_value = *((volatile unsigned int*)C2K_CONFIG);
		*((volatile unsigned int*)C2K_CONFIG) = (reg_value&(~(0x7<<8)))|(0x5<<8);
		printf("C2K_CONFIG = 0x%x\n", *((volatile unsigned int*)C2K_CONFIG));
		// step 2: config srcclkena selection mask
		*((volatile unsigned int*)C2K_SPM_CTRL) &= ~(0xF<<2);
		*((volatile unsigned int*)C2K_SPM_CTRL) |= (0x9<<2);
		printf("C2K_SPM_CTRL = 0x%x\n", *((volatile unsigned int*)C2K_SPM_CTRL));
		*((volatile unsigned int*)SLEEP_CLK_CON) |= 0xc;
		*((volatile unsigned int*)SLEEP_CLK_CON) &= ~(0x1<<14);
		*((volatile unsigned int*)SLEEP_CLK_CON) |= (0x1<<12);
		*((volatile unsigned int*)SLEEP_CLK_CON) |= (0x1<<27);
		printf("SLEEP_CLK_CON = 0x%x\n", *((volatile unsigned int*)SLEEP_CLK_CON));
		// step 3: PMIC VTCXO_1 VRF18_1 VIO18 enable
		pmic_init_sequence();
		pmic_config_interface(0x0A02, 0xA12E, 0xFFFF, 0x0);
		pmic_config_interface(0x0A16, 0x8102, 0xFFFF, 0x0);
		pmic_config_interface(0x0A36, 0x8102, 0xFFFF, 0x0);
		// step 4: reset C2K
		reg_value = *((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST);
		*((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST) = (reg_value|0x88000000)&(~(0x1<<15));
		printf("TOP_RGU_WDT_SWSYSRST = 0x%x, TOPRGU_BASE(0x%x)\n", *((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST), TOPRGU_BASE);
		// step 5: wake up C2K
		*((volatile unsigned int*)C2K_SPM_CTRL) |= 0x1;
		while(!((*((volatile unsigned int*)C2K_STATUS)>>1)&0x1)){
			printf("C2K_STATUS = 0x%x\n", *((volatile unsigned int*)C2K_STATUS));
		}
		*((volatile unsigned int*)C2K_SPM_CTRL) &= ~0x1;
		printf("C2K_SPM_CTRL = 0x%x, C2K_STATUS = 0x%x\n", *((volatile unsigned int*)C2K_SPM_CTRL), *((volatile unsigned int*)C2K_STATUS));
		while(*((volatile unsigned int*)C2K_CHIP_ID) != 0x020AC000) {
			printf("C2K_CHIP_ID = 0x%x\n", *((volatile unsigned int*)C2K_CHIP_ID));
		}
		printf("C2K_CHIP_ID = 0x%x!!\n", *((volatile unsigned int*)C2K_CHIP_ID));
		break;
	default:
		break;
	}
}

int md_jtag_config(int boot_md_id)
{
	return 0;
}

int get_input(void)
{
	return uart_getc();
}

void apply_env_setting(int case_id)
{
	printf("Apply case:%d setting for dummy AP!\n", case_id);
}

void md_uart_config(int type_id)
{
	switch(type_id) {
	case -1: // for AP only
	case 0: // for AP & MD1
	case 1: // for AP & MD2
	case 2: // for both MD1 and MD2
		printf("md_uart_config:%d, UART1->MD3, UART2->MD1, UART3->AP, UART4->disabled\n", type_id);
		mt_set_gpio_mode(GPIO_UART_URXD0_PIN, GPIO_UART_URXD0_PIN_M_C2K_UART0_RXD);
		mt_set_gpio_mode(GPIO_UART_UTXD0_PIN, GPIO_UART_UTXD0_PIN_M_C2K_UART0_TXD);
		mt_set_gpio_mode(GPIO_UART_URXD1_PIN, GPIO_UART_URXD1_PIN_M_MD_URXD);
		mt_set_gpio_mode(GPIO_UART_UTXD1_PIN, GPIO_UART_UTXD1_PIN_M_MD_UTXD);
		mt_set_gpio_mode(GPIO_UART_URXD2_PIN, GPIO_UART_URXD2_PIN_M_URXD);
		mt_set_gpio_mode(GPIO_UART_UTXD2_PIN, GPIO_UART_UTXD2_PIN_M_UTXD);
		mt_set_gpio_mode(GPIO_UART_URXD3_PIN, GPIO_UART_URXD3_PIN_M_GPIO);
		mt_set_gpio_mode(GPIO_UART_UTXD3_PIN, GPIO_UART_UTXD3_PIN_M_GPIO);
		break;
	default:
		break;
	}
}

static void let_md_go(int md_id)
{
	unsigned int is_meta_mode = 0;
	
	// 1, Configure EMI remapping setting
	printf("Step 1: Configure EMI remapping...\n");
	md_emi_remapping(md_id);

	// 2, Power up MD MTCMOS
	//printf("Step 3: Power up MD!\n");
	md_power_up_mtcmos(md_id);

	// 3, Configure DAP for ICE to connect to MD
	printf("Step 2: Configure DAP for ICE to connect to MD!\n");
	md_jtag_config(md_id);

	// 4, Check boot Mode
#ifdef DEFAULT_META
	is_meta_mode = 1;
#else
	is_meta_mode = meta_detection();
#endif
	printf("Step 3: Notify MD enter %s mode!\n", is_meta_mode ? "META" : "NORMAL");

	// 5, MD register setting
	printf("Step 4: MD Common setting!\n");
	md_common_setting(md_id);

	// 6, Boot up MD
	printf("Step 5: MD%d boot up with meta(%d)!\n", md_id+1, is_meta_mode);
	md_boot_up(md_id, is_meta_mode);

	printf("\nmd%d boot up done!\n", md_id + 1);
}

void md_wdt_init(void)
{
	if(img_load_flag &(1<<MD1_IMG)) {	
		mt_irq_set_sens(MT_MD_WDT1_IRQ_ID, MT65xx_EDGE_SENSITIVE);
		mt_irq_set_polarity(MT_MD_WDT1_IRQ_ID, MT65xx_POLARITY_LOW);
		mt_irq_unmask(MT_MD_WDT1_IRQ_ID);
	}
	if(img_load_flag &(1<<MD2_IMG)) {	
		mt_irq_set_sens(MT_MD_WDT2_IRQ_ID, MT65xx_EDGE_SENSITIVE);
		mt_irq_set_polarity(MT_MD_WDT2_IRQ_ID, MT65xx_POLARITY_LOW);
		mt_irq_unmask(MT_MD_WDT2_IRQ_ID);
	}
}

#ifdef CCIF_DVT
/******************************************************************************/
#define ccif_debug(fmt, args...) printf("ts_ccif: "fmt, ##args)
#define ccif_error(fmt, args...) printf("[CCIF][Error] "fmt, ##args)
#define __IO_WRITE32(a, v) *((volatile unsigned int*)a)=(v)
#define __IO_READ32(a) (*((volatile unsigned int*)a))

#define CCIF_IRQ_ID   171
#define CCIF_REG_BASE 0x10218000
#define CCIF_MAX_PHY 16
#define CCIF_DATA_REG_LENGTH (512) 
#define CCIF_CON             (CCIF_REG_BASE + 0x0000)
#define CCIF_BUSY            (CCIF_REG_BASE + 0x0004)
#define CCIF_START           (CCIF_REG_BASE + 0x0008)
#define CCIF_TCHNUM          (CCIF_REG_BASE + 0x000c)
#define CCIF_RCHNUM          (CCIF_REG_BASE + 0x0010)
#define CCIF_ACK             (CCIF_REG_BASE + 0x0014)
#define CCIF_DATA            (CCIF_REG_BASE + 0x0100)
#define CCIF_TXCHDATA_OFFSET (0)
#define CCIF_RXCHDATA_OFFSET (CCIF_DATA_REG_LENGTH/2)
#define CCIF_TXCHDATA (CCIF_DATA+CCIF_TXCHDATA_OFFSET)
#define CCIF_RXCHDATA (CCIF_DATA + CCIF_RXCHDATA_OFFSET)

typedef struct
{
    unsigned int data[2];
    unsigned int channel;
    unsigned int reserved;
} CCCI_BUFF_T;

typedef struct
{
    unsigned int ap_state;
    unsigned int md_state;
    unsigned int test_case;
}sync_flag;

enum {    AP_NOT_READY=0x9abcdef, AP_READY, AP_SYNC_ID_DONE, AP_WAIT_BEGIN, AP_BEGIN,
    AP_REQUST, AP_REQUST_ONGOING, AP_REQUST_DONE
};
enum {    MD_NOT_READY=0xfedcba9, MD_READY, MD_SYNC_ID_DONE, MD_WAIT_BEGIN, MD_GEGIN,
    MD_WAIT_REQUST, MD_ACK_DONE
};

enum {    TC_00=0,
    TC_01=1, TC_02, TC_03, TC_04, TC_05, TC_06, TC_07, TC_08, TC_09, TC_10, 
    TC_11, TC_12, TC_13, TC_14, TC_15, TC_16, TC_17, TC_18, TC_19, TC_20, 
    TC_21, TC_22, TC_23, TC_24, TC_25, TC_26, TC_27, TC_28, TC_29, TC_30,
};

static CCCI_BUFF_T ccif_msg[CCIF_MAX_PHY];
static volatile unsigned int *test_heap_ptr;
static volatile unsigned int *test_nc_heap_ptr;
static void (*CCIF_isr_process_func)(void);
static void(*CCIF_call_back_func)(unsigned int);
static unsigned int using_user_isr=0;
static unsigned int rx_ch_flag = 1;
static unsigned int rx_ch_index = 0;
static volatile unsigned int *ap_md_share_heap_ptr;
static volatile sync_flag *sync_data_region;
static unsigned int *AP_MD_Result_Share_Region;
static const unsigned int phy_ch_seq_mode_seq[CCIF_MAX_PHY] = { 13, 5, 7, 11, 4,12, 0, 6, 3, 14, 9,2, 15,8,10,1 };
static const unsigned int data_pattern[] = {
    0x500af0f0, 0x501af0f0, 0x502af0f0, 0x503af0f0, 0x504af0f0,0x505af0f0,0x506af0f0,0x507af0f0,
    0x508af0f0, 0x509af0f0, 0x50aaf0f0, 0x50baf0f0, 0x50caf0f0,0x50daf0f0,0x50eaf0f0,0x50faf0f0,
    0x510af0f0, 0x511af0f0, 0x512af0f0, 0x513af0f0, 0x514af0f0,0x515af0f0,0x516af0f0,0x517af0f0,
    0x518af0f0, 0x519af0f0, 0x51aaf0f0, 0x51baf0f0, 0x51caf0f0,0x51daf0f0,0x51eaf0f0,0x51faf0f0,
};
static const unsigned int channel_bits_map[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000};
static volatile unsigned int isr_work_done[30];
static const unsigned int result_unknow = 0;
static const unsigned int result_pass = 1<<16;
static const unsigned int result_fail = 2<<16;
static unsigned int rx_seq_for_isr = 0;
static unsigned int rx_last_time_val = 0;
static unsigned int irq_is_masked = 0;
static const int ccif_phy_arb_mode_seq[CCIF_MAX_PHY] = { 12, 3, 15, 1, 11, 8, 14, 2, 13, 4, 10, 7, 9, 5, 0, 6};

static void CCIF_arb_isr_func(void)
{
    // 1. Get channel
    unsigned int ch_flag = __IO_READ32(CCIF_RCHNUM);
    ccif_debug("CCIF_arb_isr_func() ch:%d\n", ch_flag);

    while(ch_flag){
        if(ch_flag & rx_ch_flag){
            // 2. Call callback function
            if(CCIF_call_back_func)
                (*CCIF_call_back_func)(rx_ch_index);
    
            // 3. Ack channel
            __IO_WRITE32(CCIF_ACK, rx_ch_flag);
            
            // 4. Clear rx channel flag
            ch_flag &= (~rx_ch_flag);
        }
        
        // 5. Updata index and ch flag
        rx_ch_index++;
        rx_ch_index &= 0xf;

        rx_ch_flag =1<<rx_ch_index;   
    }
}

static void CCIF_default_seq_cb_func()
{
    // 1. Get channel
    unsigned int ch = __IO_READ32(CCIF_RCHNUM);
    ccif_debug("CCIF_default_seq_cb_func() ch:%d\n", ch);
	
    // 2. Call callback function
    if(CCIF_call_back_func)
        (*CCIF_call_back_func)(ch);
    
    // 3. Ack channel
    __IO_WRITE32(CCIF_ACK, channel_bits_map[ch]);
}

void CCIF_Set_Con(unsigned int setting)
{
    __IO_WRITE32(CCIF_CON, setting);

    if(using_user_isr)
        return;

    if(setting&0x1){    // arb mode
        CCIF_isr_process_func = CCIF_arb_isr_func;
    }else{            // seq mode
        CCIF_isr_process_func = CCIF_default_seq_cb_func;
    }
}

void CCIF_Register_User_Isr(void(*pfunc)(void))
{
    static void (*pfunc_bak)(void);
    if(pfunc){
        using_user_isr = 1;
        pfunc_bak = CCIF_isr_process_func;
        CCIF_isr_process_func = pfunc;
    }else{
        using_user_isr = 0;
        CCIF_isr_process_func = pfunc_bak;
    }
}

int CCIF_Register(void(*pfunc)(unsigned int))
{
    CCIF_call_back_func = pfunc;
    return 0;
}

unsigned int CCIF_Get_Busy(void)
{
    return __IO_READ32(CCIF_BUSY);
}

unsigned int CCIF_Get_Start(void)
{
    return __IO_READ32(CCIF_START);
}

void CCIF_Set_Busy(unsigned int setting)
{
    __IO_WRITE32(CCIF_BUSY, setting);
}

void CCIF_Set_TxData(unsigned int ch, char buff[])
{
    unsigned int *src_ptr;
    unsigned int *des_ptr;
    int i;

    src_ptr = (unsigned int *)&buff[0];
    des_ptr = (unsigned int *)(CCIF_TXCHDATA + (16*ch));

    for(i=0; i<4; i++)
        des_ptr[i] = src_ptr[i];
}

void CCIF_Set_Tch_Num(unsigned int ch)
{
    __IO_WRITE32(CCIF_TCHNUM, ch);
}

int CCIF_Init()
{
    // 1. Mask CCIF Irq
    CCIF_Mask_Irq(CCIF_IRQ_ID);
    
    // 2. Set to arb mode
    CCIF_Set_Con(1);
    
    // 3. Ack all channel
    //CCIF_Set_Ack(0xff);
    
    // 4. Register interrupt to system
    //IRQ_Register_LISR(CCIF_IRQ_ID, CCIF_Isr, "CCIF");  // FIXME
    mt_irq_set_sens(CCIF_IRQ_ID, MT65xx_LEVEL_SENSITIVE);
    mt_irq_set_polarity(CCIF_IRQ_ID, MT65xx_POLARITY_LOW);
    //IRQClearInt(CCIF_IRQ_ID);

    // 5. Un-mask Irq
    CCIF_UnMask_Irq(CCIF_IRQ_ID);
}

void CCIF_Set_ShareData(unsigned int offset, unsigned int setting)
{
    __IO_WRITE32((CCIF_DATA+(offset&(~0x003))), setting);
}

unsigned int CCIF_Get_ShareData(unsigned int offset)
{
    return __IO_READ32( (CCIF_DATA+(offset&(~0x003))) );
}

void CCIF_Get_RxData(unsigned int ch, char buff[])
{
    unsigned int *src_ptr;
    unsigned int *des_ptr;
    int i;

    des_ptr = (unsigned int *)&buff[0];
    src_ptr = (unsigned int *)(CCIF_RXCHDATA + (16*ch));

    for(i=0; i<4; i++)
        des_ptr[i] = src_ptr[i];
}

void CCIF_Isr(unsigned int irq)
{
	if(irq == CCIF_IRQ_ID) {
		printf("CCIF ISR enter!\n");
    	(*CCIF_isr_process_func)();
		mt_irq_ack(CCIF_IRQ_ID);
		mt_irq_unmask(CCIF_IRQ_ID);
		printf("CCIF ISR exit!\n");
	}
}

void CCIF_Mask_Irq()
{
    mt_irq_mask(CCIF_IRQ_ID);
    irq_is_masked = 1;
}
void CCIF_UnMask_Irq()
{
    mt_irq_unmask(CCIF_IRQ_ID);
    irq_is_masked = 0;
}

void CCIF_Set_Ack(unsigned int ch)
{
    __IO_WRITE32(CCIF_ACK, ch);
}

unsigned int CCIF_Get_Tch_Num()
{
    return __IO_READ32(CCIF_TCHNUM);
}

unsigned int CCIF_Get_Rch_Num(void)
{
    return __IO_READ32(CCIF_RCHNUM);
}

void AP_MD_Test_Sync_Init(unsigned int addr)
{
    ccif_debug("AP_MD_Test_Sync_Init 10 \n");
    sync_data_region = (sync_flag *)addr;
    sync_data_region->ap_state = AP_NOT_READY;
    sync_data_region->md_state = MD_NOT_READY;
    sync_data_region->test_case = 0;
    ccif_debug("AP_MD_Test_Sync_Init 99 \n");
}

void Set_AP_MD_Sync_Share_Memory(unsigned int ptr)
{
    enum {AP_IN_INIT_DONE=0x12345678, AP_WRITE_DATA_DONE};
    enum {MD_IN_INIT_DONE=0x87654321, MD_GET_DATA_DONE};

    ccif_debug("Check if MD init done 0x%x\n", CCIF_Get_ShareData(CCIF_RXCHDATA_OFFSET));
    // 1. Notify MD that AP init done
    ccif_debug("Notify MD that AP init done, addr:0x%x, value:0x%x\n", CCIF_DATA,AP_IN_INIT_DONE);
    CCIF_Set_ShareData(CCIF_TXCHDATA_OFFSET, AP_IN_INIT_DONE);
    // 2. Check MD is init done
    ccif_debug("Check if MD init done, addr:0x%x, value:0x%x\n", (CCIF_DATA + (CCIF_RXCHDATA_OFFSET & (~0x003))), MD_IN_INIT_DONE);
    while(CCIF_Get_ShareData(CCIF_RXCHDATA_OFFSET)!=MD_IN_INIT_DONE);
    ccif_debug("Check if MD init done 0x%x\n", CCIF_Get_ShareData(CCIF_RXCHDATA_OFFSET));

    // 3. MD ready, notify share memory start addr
    ccif_debug("AP MD share memroy start addr:%x\n", (unsigned int)ptr);

    ptr -= img_addr_tbl[MD2_IMG]; // FIXME, hardcode;
    
    CCIF_Set_ShareData(CCIF_TXCHDATA_OFFSET+4, (unsigned int)(ptr));
    ccif_debug("Notify MD get share memroy start addr:0x%x\n",(unsigned int) ptr);
    CCIF_Set_ShareData(0, AP_WRITE_DATA_DONE);
    
    // 4. Wait MD get data done
    ccif_debug("Check if MD get data done\n");
    while(CCIF_Get_ShareData(CCIF_RXCHDATA_OFFSET)!=MD_GET_DATA_DONE);
    
    // 5. Set share memory done, clear ccif shareram
    ccif_debug("Set_AP_MD_Sync_Share_Memory done\n");
    CCIF_Set_ShareData(CCIF_TXCHDATA_OFFSET, 0);
    CCIF_Set_ShareData(CCIF_TXCHDATA_OFFSET+4, 0);
    CCIF_Set_ShareData(CCIF_RXCHDATA_OFFSET, 0);
}

void CCIF_Test_Env_Init(unsigned int ptr)
{
    ccif_debug("CCIF_Test_Env_Init 1\n");
    AP_MD_Test_Sync_Init(ptr);

    ccif_debug("CCIF_Test_Env_Init 2\n");
    Set_AP_MD_Sync_Share_Memory(ptr);

    ccif_debug("CCIF_Test_Env_Init 3\n");
    //INFRA_disable_clock(MT65XX_PDN_INFRA_CCIF0);
    
    ccif_debug("CCIF_Test_Env_Init 4\n");
    AP_MD_Result_Share_Region = (unsigned int*)(ptr+sizeof(sync_flag)*2);
}

int ts_init_handler()
{
    int ret_val = 0;
    unsigned int *ptr, *nc_ptr;
	
    memset(ccif_msg,0,sizeof(ccif_msg));
    ccif_debug("TC init\n");

    test_heap_ptr=(unsigned int *)malloc(1024*2);
    test_nc_heap_ptr=(unsigned int *)malloc(1024*2);

    ccif_debug("\tTC init step 3\n");    
	CCIF_Init();
    ccif_debug("\tTC init step 4\n");
    ap_md_share_heap_ptr = (void *)(img_addr_tbl[MD2_IMG]+0x100000); // FIXME, hardcode
    ccif_debug("\tTC init step 5\n");
    //Let_MD_to_Run();
    ccif_debug("\tTC init step 6\n");
    CCIF_Test_Env_Init((unsigned int)ap_md_share_heap_ptr);
    ccif_debug("TC init done.\n");
    return ret_val;
}

void AP_MD_test_case_sync_AP_Side(unsigned int tc)
{
    int i =0;
    ccif_debug("Enter set_ccif_test_case_sync \n");
    // 1. Notify MD that AP ready
    ccif_debug("Notify MD that AP ready, addr:0x%x, val:0x%x, disr:0x%x\n",(unsigned int)(&(sync_data_region->ap_state)), sync_data_region->ap_state, AP_READY);
    sync_data_region->ap_state = AP_READY;
	//arch_sync_cache_range(&sync_data_region, sizeof(sync_data_region));

    // 2. Check MD is ready
    ccif_debug("Check if MD is ready, addr:0x%x, val:0x%x, disr:0x%x\n", (unsigned int)(&(sync_data_region->md_state)),sync_data_region->md_state, AP_READY);
    while(sync_data_region->md_state!=MD_READY) {
        ccif_debug("Check AP addr:0x%x, State:%x\n", &(sync_data_region->ap_state),
                            sync_data_region->ap_state);
        ccif_debug("Check MD addr:0x%x, State:%x, expeted:0x%x\n", &(sync_data_region->md_state),
                            sync_data_region->md_state, MD_READY);
    };
    // 3. MD ready, notify MD test case ID
    sync_data_region->test_case = tc;
    ccif_debug("Notify MD test id :%x\n", tc);
    sync_data_region->ap_state = AP_SYNC_ID_DONE;

    // 4. Wait MD get tc id done
    ccif_debug("Check if MD ready to test\n");
    while(sync_data_region->md_state!=MD_SYNC_ID_DONE){
       ccif_debug("Check AP 2 addr:0x%x, State:%x\n", &(sync_data_region->ap_state),
                            sync_data_region->ap_state);
        ccif_debug("Wait MD get TC id Done: addr:0x%x, State:%x, expeted:0x%x\n", &(sync_data_region->md_state),
                            sync_data_region->md_state, MD_SYNC_ID_DONE);
    };

    // 5. Finish sysn
    ccif_debug("AP_MD_test_case_sync_AP_Side done\n");
}

void AP_MD_Ready_to_Test_Sync_AP_Side()
{
    ccif_debug("Enter AP_MD_Ready_to_Test_Sync_AP_Side \n");
    // 1. Notify MD that AP ready
    ccif_debug("Notify MD that AP ready\n");
    sync_data_region->ap_state = AP_WAIT_BEGIN;

    // 2. Check MD is ready
    ccif_debug("Check if MD is ready\n");
    while(sync_data_region->md_state!=MD_WAIT_BEGIN);
    sync_data_region->ap_state=AP_NOT_READY;
    sync_data_region->md_state=MD_NOT_READY;
    // 3. MD also ready
    ccif_debug("Begin to test\n");
}

int AP_Get_MD_Test_Result(unsigned int buf[], unsigned int length)
{
    int act_get = 0;
    unsigned int j;
    ccif_debug("Enter AP_Get_MD_Test_Result \n");
    // 1. Notify MD that AP request test result
    ccif_debug("Notify MD that AP request test result\n");
    sync_data_region->ap_state = AP_REQUST;

    // 2. Check MD is wait request
    ccif_debug("Check if MD is wait send result\n");
    while(sync_data_region->md_state!=MD_WAIT_REQUST);

    sync_data_region->ap_state = AP_REQUST_ONGOING;
    // 3. Wait MD write result done
    ccif_debug("Wait MD write result done\n");
    while(sync_data_region->md_state!=MD_ACK_DONE);

    // 4. Get Test result
    for(j=0; (j<AP_MD_Result_Share_Region[0])&&(j<length); j++)
        buf[j] = AP_MD_Result_Share_Region[j+1];
    
    // 5. Notify MD AP get result done
    ccif_debug("Notify MD AP get result done buf[0](%d)\n", buf[0]);
    sync_data_region->ap_state = AP_REQUST_DONE;
    
    return j;
}

void Set_Isr_Work_Done(unsigned int tc)
{
	printf("CCIF ISR done for TC%d\n", tc);
    isr_work_done[tc] = 1;
}
void Reset_Isr_Work_State(unsigned int tc)
{
    isr_work_done[tc] = 0;
}
int Is_Isr_Work_Done(unsigned int tc)
{
    return isr_work_done[tc];
}

static void ccif_seq_isr_cb_for_tc02(unsigned int ch)
{
    unsigned int data[4];
    unsigned int seq = test_heap_ptr[0];
    unsigned int mis_match = 0;

    // 1. Read Data Send from MD
    CCIF_Get_RxData(ch, (unsigned char*)data);

    // 2. Check sequence
    if(ch != phy_ch_seq_mode_seq[seq])
    {
        mis_match = (1<<0);
        ccif_error("AP <== MD seq mode channel seq mis-match(%d!=%d), seq:%d\n",ch,phy_ch_seq_mode_seq[seq], seq);
    }
    // 3. Check rx data
    if( (data[0]==data[1])&&(data[1]==data[2])&&(data[2]==data[3])&&
        (data[3]==(data_pattern[TC_02]+ch))&&(result_unknow==test_heap_ptr[ch+1]) )
        test_heap_ptr[ch+1] = result_pass;
    else
        {
            test_heap_ptr[ch+1] = result_fail;
            ccif_error("%x != %x \r\n",data[0],data_pattern[TC_02]+ch);
        }

    // 4 Update mis-match info
    if(mis_match){
        test_heap_ptr[ch+1] += 1;
        mis_match = 0;
    }

    // 5. Check whether test done
    seq++;
    test_heap_ptr[0] = seq;
    if(test_heap_ptr[0] == CCIF_MAX_PHY)
        Set_Isr_Work_Done(TC_02);
}

static void ccif_arb_isr_for_tc04()
{
    unsigned int ch;
    // 1. Get Channel
    ch = CCIF_Get_Rch_Num();
    if (ch < 1) {
        ccif_debug("ch = 0, exit abr isr\r\n");
        return ;
    }
    // 2. Check Rx seq
    if(ch!=rx_last_time_val){
        // Has new data
        // if( (ch^rx_last_time_val)==(unsigned int)(1<<ccif_phy_arb_mode_seq[rx_seq_for_isr]) )
        //     rx_seq_for_isr++;
        if( (ch)==(unsigned int)(1<<ccif_phy_arb_mode_seq[rx_seq_for_isr]) )
            rx_seq_for_isr++;
        rx_last_time_val = ch;
        CCIF_Set_Ack(ch);
        CCIF_Get_Rch_Num();
        CCIF_Get_Rch_Num();
    }
    // 3. Check if RX all channel have data
    if((ch==0xFFFF) ||(rx_seq_for_isr == CCIF_MAX_PHY)){
        Set_Isr_Work_Done(TC_04);
        CCIF_Mask_Irq();
        // CCIF_Set_Ack(0xFFFFFFFF);
        ccif_debug("Output: seq_for_isr:0x%x\r\n", rx_seq_for_isr);
    }
}

int ccif_ap_test_case_01(void)
{
    unsigned int irq, data[4], phy;
    int i;
    unsigned int md_result;
    unsigned int reg_busy=0, reg_start=0;
    unsigned int tmp_busy, tmp_start;
    unsigned int ret=0;
    unsigned int last_busy_val=0;

    ccif_debug("[TC01]AP ==> MD sequence test\n");
    AP_MD_test_case_sync_AP_Side(TC_01);
    CCIF_Set_Con(0);
    CCIF_Register(0);
    AP_MD_Ready_to_Test_Sync_AP_Side();

    for (i = 0; i < CCIF_MAX_PHY; i++) {        
        phy = phy_ch_seq_mode_seq[i];
        data[0] = data[1] = data[2] = data[3] = data_pattern[TC_01]+phy;
        // 1. Busy bit should be zero
        tmp_busy = CCIF_Get_Busy();
        tmp_start = CCIF_Get_Start();
        if(tmp_busy&(1<<phy)){
            ccif_error("\tphysical ch %d busy now, abnormal\n", phy);
            ret=(1<<0);
        }
        if(tmp_start&(1<<phy)){
            ccif_error("\tphysical ch %d start bit is 1 now, abnormal\n", phy);
            ret=(1<<1);
        }

        // 2. Busy bits for this channel will change to 1
        CCIF_Set_Busy(1 << phy);
        reg_busy |= 1<<phy;
        if( (reg_busy&CCIF_Get_Busy())!= CCIF_Get_Busy() ){
            ccif_error("\tphysical ch %d busy bit change to 1 fail\n", phy);
            ret=(1<<3);
        }
        CCIF_Set_TxData(phy, (unsigned char*)data);
        CCIF_Set_Tch_Num(phy);
        //CTP_Wait_msec(1000);
        ccif_debug("send data to physical ch %d, data:0x%x, 0x%x, 0x%x, 0x%x\n", phy, data[0], data[1], data[2], data[3]);

        // 3. Start bit for this ch should change to 1
        reg_start|= 1<<phy;
        if( (reg_start&CCIF_Get_Start())!= CCIF_Get_Start() ){
            ccif_error("physical ch %d start bit change to 1 fail\n", phy);
            ret=(1<<4);
        }
    }
    last_busy_val = reg_busy;

    i=20;
    // while(i-- && (last_busy_val=CCIF_Get_Busy())) {delay_a_while(500000) ;}
    while(i-- && (last_busy_val=CCIF_Get_Busy())) {mdelay(200) ; ccif_debug("[TC01]Test,2 CCIF_Get_Busy():0x%x \n", CCIF_Get_Busy());}
    if (last_busy_val)
    {
        ccif_error("last_busy_val=%x  Failed to clear \n",last_busy_val);
        ret=(1<<5);
    }
    AP_Get_MD_Test_Result(&md_result, 1);
    if( (0==md_result)&&(0==ret) ){
        ccif_debug("[TC01]Test pass\n");
        return 0;
    }else{
        ccif_error("[TC01]Test fail,md_result=%d,ap_result=%d\n",md_result,ret);
        return -1;
    }
}

int ccif_ap_test_case_02(void)
{
    int i;
    unsigned int md_result=0;
    int error_val=0;

    ccif_debug("[TC02]AP <== MD sequence test\n");
    AP_MD_test_case_sync_AP_Side(TC_02);
    CCIF_Set_Con(0);
    CCIF_Register(0);
    for(i=1; i<=CCIF_MAX_PHY; i++)
        test_heap_ptr[i] = result_unknow;
    test_heap_ptr[0] = 0;
    Reset_Isr_Work_State(TC_02);

    CCIF_Register(ccif_seq_isr_cb_for_tc02);

    CCIF_Mask_Irq(CCIF_IRQ_ID);

    AP_MD_Ready_to_Test_Sync_AP_Side();

    // Sleep 500ms to let MD side send all 8 channel data done
    //CTP_Wait_msec(500);

    CCIF_UnMask_Irq(CCIF_IRQ_ID);

    // Waiting test done
    ccif_debug("\tWaiting md test done\n");
    while(!Is_Isr_Work_Done(TC_02));

    // Check result
    ccif_debug("\tCheck AP <== MD result\n");
    for(i=1; i<=CCIF_MAX_PHY; i++){
        if(result_fail == (test_heap_ptr[i]&0xffff0000)){
            ccif_error("\tAP <== MD seq mode data check fail\n");
            error_val = -1;
            goto _Result;
        }
        if(0 != (test_heap_ptr[i]&0x0000ffff)){
            ccif_error("\tAP <== MD seq mode check seq fail\n");
            error_val = -2;
            goto _Result;
        }
    }
    if(i!=CCIF_MAX_PHY+1){
        ccif_error("\tAP <== MD seq mode channel num fail\n");
        error_val = -3;
    }

_Result:
    ccif_debug("\tCheck AP ==> MD result\n");
    AP_Get_MD_Test_Result(&md_result, 1);
    if( (0==md_result)&&(0==error_val) ){
        ccif_debug("[TC02]Test pass\n");
        return 0;
    }else{
        ccif_error("[TC02]Test fail,md_result=%d,ret=\n",md_result,error_val);
        return -1;
    }
}

int ccif_ap_test_case_03(void)
{
    unsigned int irq, data[4], phy;
    unsigned int i;
    unsigned int reg_busy=0, reg_start=0;
    unsigned int tmp_busy, tmp_start;
    unsigned int ret=0,md_result = 0;
    unsigned int last_busy_val=0;

    ccif_debug("[TC03]AP ==> MD arbitration test\n");
    CCIF_Set_Con(1);
    AP_MD_test_case_sync_AP_Side(TC_03);
    
    CCIF_Register(0);
    AP_MD_Ready_to_Test_Sync_AP_Side();

    for (i = 0; i < CCIF_MAX_PHY; i++) {
            data[0] = data[1] = data[2] = data[3] = data_pattern[TC_03]+i;
            phy = ccif_phy_arb_mode_seq[i];

        // 1. Busy bit should be zero
        tmp_busy = CCIF_Get_Busy();
        tmp_start = CCIF_Get_Start();
        if(tmp_busy&(1<<phy)){
            ccif_error("\tphysical ch %d busy now, abnormal\n", phy);
            ret=(1<<0);
        }
        if(tmp_start&(1<<phy)){
            ccif_error("\tphysical ch %d start bit is 1 now, abnormal\n", phy);
            ret=(1<<1);
        }

        // 2. Busy bits for this channel will change to 1
        CCIF_Set_Busy(1<<phy);
        reg_busy |= 1<<phy;
        if( (reg_busy&CCIF_Get_Busy())!= CCIF_Get_Busy() ){
            ccif_error("\tphysical ch %d busy bit change to 1 fail\n", phy);
            ret=(1<<2);
        }

        CCIF_Set_TxData(phy, (unsigned char*)data);
        CCIF_Set_Tch_Num(phy);
        ccif_debug("send data to physical ch %d\n", phy);

        // 3. Start bit for this ch should change to 1
        reg_start|= 1<<phy;
        if( (reg_start&CCIF_Get_Start())!= CCIF_Get_Start() ){
            ccif_error("\tphysical ch %d start bit change to 1 fail\n", phy);
            ret=(1<<3);
        }
    }
    last_busy_val = reg_busy;

    i=20;
    while(i-- && (last_busy_val=CCIF_Get_Busy())) {mdelay(20);}
    if (last_busy_val)
    {
        ccif_debug("last_busy_val=%x  Failed to clear \n",last_busy_val);
        ret=(1<<4);
    }
    AP_Get_MD_Test_Result(&md_result, 1);

    if(ret||md_result){
        ccif_error("[TC03]Test fail, md_result=%d,ret=%d\n",md_result,ret);
        return -1;
    }else{
        ccif_debug("[TC03]Test pass\n");
        return 0;
    }
}


int ccif_ap_test_case_04(void)
{
    unsigned int irq, data[4], phy;
    int i;
    unsigned int ret=0, md_result=0;
    ccif_debug("[TC04]AP <== MD arbitration test\n");
    rx_seq_for_isr = 0;
    rx_last_time_val = 0;
    //CCIF_CHECK_POINT_IN_BEGIN();
    AP_MD_test_case_sync_AP_Side(TC_04);
    CCIF_Set_Con(1);
    CCIF_UnMask_Irq();
    mdelay(1000);
    ccif_debug("delay for some time \n");
    CCIF_Register(0);
    for(i=1; i<=CCIF_MAX_PHY; i++)
        test_heap_ptr[i] = result_unknow;
    test_heap_ptr[0] = 0;
    Reset_Isr_Work_State(TC_04);

    ccif_debug("\tCCIF_Register_User_Isr \n");
    CCIF_Register_User_Isr(ccif_arb_isr_for_tc04);

    ccif_debug("\tAP_MD_Ready_to_Test_Sync_AP_Side \n");
    AP_MD_Ready_to_Test_Sync_AP_Side();

    // Waiting test done
    while(!Is_Isr_Work_Done(TC_04));
    
    ccif_debug("\tIsr work done \n");

    // Check Data
    for(i=0; i<CCIF_MAX_PHY; i++){
        CCIF_Get_RxData(ccif_phy_arb_mode_seq[i], (unsigned char*)data);
        if( (data[0]==data[1])&&(data[1]==data[2])&&(data[2]==data[3])&&
            (data[3]==(data_pattern[TC_04]+i)) );
        else{
            ret=1;
        }
        // Ack AP
        CCIF_Set_Ack(1<<ccif_phy_arb_mode_seq[i]);
        mdelay(1);
    }

    CCIF_Register_User_Isr(0);
    rx_seq_for_isr = 0;
    rx_last_time_val = 0;

    AP_Get_MD_Test_Result(&md_result, 1);
    //CCIF_CHECK_POINT_IN_END();
    if(ret||md_result){
        ccif_error("[TC04]Test fail,md_result=%d,ret=%d\n",md_result,ret);
        return -1;
    }else{
        ccif_debug("[TC04]Test pass\n");
        return 0;
    }
}


/******************************************************************************/
#endif

void dummy_ap_entry(void)
{
	int md_check_tbl[] = {1<<MD1_IMG, 1<<MD2_IMG};
	int i=0;
	int get_val=0;
#if 0
	volatile unsigned int	count;
	volatile unsigned int	count1;
#endif
	// reinit UART, overwrite DWS setting
	md_uart_config(-1);

	// Disable AP WDT
	*(volatile unsigned int *)(TOPRGU_BASE) = 0x22000000; 

	printf("Welcome to use dummy AP!\n");
	//get_val = get_input();

	apply_env_setting(get_val);

	// 0, Parse header info
	printf("Parsing image info!\n");
	parse_img_header((unsigned int*)g_boot_arg->part_info, (unsigned int)g_boot_arg->part_num);

	printf("Begin to configure MD run env!\n");

	// 1, Setup special GPIO request (RF/SIM/UART ... etc)
	printf("Configure GPIO!\n");
	if((img_load_flag&((1<<MD1_IMG)|(1<<MD2_IMG))) == ((1<<MD1_IMG)|(1<<MD2_IMG))) {
		md_gpio_config(2);
	} else if (img_load_flag & (1<<MD1_IMG)) {
		md_gpio_config(0);
	} else if (img_load_flag & (1<<MD2_IMG)) {
		md_gpio_config(1);
	}

	// 2, Setup per-MD env and boot up MD
	for(i=0; i<MAX_MD_NUM; i++) {
		if(img_load_flag & md_check_tbl[i]) {
			printf("MD%d Enabled\n", i+1);
			let_md_go(i);
		}
	}

	// 3, Config UART
	printf("Config UART!\n");
	if((img_load_flag&((1<<MD1_IMG)|(1<<MD2_IMG))) == ((1<<MD1_IMG)|(1<<MD2_IMG))) {
		md_uart_config(2);
	} else if (img_load_flag & (1<<MD1_IMG)) {
		md_uart_config(0);
	} else if (img_load_flag & (1<<MD2_IMG)) {
		md_uart_config(1);
	}

	printf("All dummy AP config done\n");
	md_wdt_init();
#if 0
	count = 1;
	while(count--) {
		count1 = 0x80000000;
		while(count1--);
	}
	printf("Write MD WDT SWRST\n");
	*((volatile unsigned int *)0x2005001C) = 0x1209; 
	count = 1;
	while(count--) {
		count1 = 0x08000000;
		while(count1--);
	}
	printf("Read back STA:%x!!\n", *((volatile unsigned int*)0x2005000C));
#endif
#if CCIF_DVT
	arch_disable_cache(UCACHE);
	ts_init_handler();
	while(1) {
		printf("select test case:\n");
		get_val = get_input();
		uart_putc(get_val);
		switch(get_val) {
		case '1':
			ccif_ap_test_case_01();
			break;
		case '2':
			ccif_ap_test_case_02();
			break;
		case '3':
			ccif_ap_test_case_03();
			break;
		case '4':
			ccif_ap_test_case_04();
			break;
		case 'q':
			goto nothing;
		default:
			break;
		};
	};
#endif
nothing:
	printf("enter while(1), Yeah!!\n");
	while(1);
}

void md_wdt_irq_handler(unsigned int irq)
{
	unsigned int reg_value;
	
#if defined(ENABLE_MD_RESET_SPM) || defined(ENABLE_MD_RESET_RGU)
	// update counter
	unsigned int cnt = *(volatile unsigned int *)(TOP_RGU_WDT_NONRST_REG);
	*(volatile unsigned int *)(TOP_RGU_WDT_NONRST_REG) = cnt+1;
	// reset UART config
	md_uart_config(-1);
	
	if(irq == MT_MD_WDT1_IRQ_ID) {
#ifdef ENABLE_MD_RESET_SPM
		printf("MD1 power off\n");
		spm_mtcmos_ctrl_mdsys1(STA_POWER_DOWN);
		mdelay(5);
#endif
#ifdef ENABLE_MD_RESET_RGU
		printf("MD1 reset\n");
		reg_value = *((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST);
		*((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST) = reg_value|0x88000000|(0x1<<7);
		mdelay(5);
		reg_value = *((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST);
		*((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST) = (reg_value|0x88000000)&(~(0x1<<7));
#endif
		let_md_go(0);
	}
	if(irq == MT_MD_WDT2_IRQ_ID) {
#ifdef ENABLE_MD_RESET_SPM
		printf("MD2 power off\n");
		spm_mtcmos_ctrl_mdsys2(STA_POWER_DOWN);
		mdelay(5);
#endif
#ifdef ENABLE_MD_RESET_RGU
		printf("MD2 reset\n");
		reg_value = *((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST);
		*((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST) = reg_value|0x88000000|(0x1<<15);
		mdelay(5);
		reg_value = *((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST);
		*((volatile unsigned int*)TOP_RGU_WDT_SWSYSRST) = (reg_value|0x88000000)&(~(0x1<<15));
#endif
		let_md_go(1);
	}

	printf("Config UART after MD WDT!\n");
	if((img_load_flag&((1<<MD1_IMG)|(1<<MD2_IMG))) == ((1<<MD1_IMG)|(1<<MD2_IMG))) {
		md_uart_config(2);
	} else if (img_load_flag & (1<<MD1_IMG)) {
		md_uart_config(0);
	} else if (img_load_flag & (1<<MD2_IMG)) {
		md_uart_config(1);
	}
#else
	md_uart_config(-1);
	printf("Get MD WDT irq, STA:%x!!\n", *((volatile unsigned int*)0x2005000C));
#ifdef IGNORE_MD_WDT
	printf("ignore MD WDT\n");
#else
	printf("whole system reboot\n");
	*(volatile unsigned int *)(TOP_RGU_WDT_MODE) = 0x22000000;
	*(volatile unsigned int *)(TOP_RGU_WDT_SWRST) = 0x1209;
	while(1);
#endif
#endif	
}

void dummy_ap_irq_handler(unsigned int irq)
{
#ifdef CCIF_DVT
	CCIF_Isr(irq);
#endif

	switch(irq) {
	case MT_MD_WDT1_IRQ_ID:
		if(img_load_flag &(1<<MD1_IMG)) {
			md_wdt_irq_handler(MT_MD_WDT1_IRQ_ID);
			mt_irq_ack(MT_MD_WDT1_IRQ_ID);
			mt_irq_unmask(MT_MD_WDT1_IRQ_ID);
		}
		break;
	case MT_MD_WDT2_IRQ_ID:
		if(img_load_flag &(1<<MD2_IMG)) {
			md_wdt_irq_handler(MT_MD_WDT2_IRQ_ID);
			mt_irq_ack(MT_MD_WDT2_IRQ_ID);
			mt_irq_unmask(MT_MD_WDT2_IRQ_ID);
		}
		break;
	default:
		break;
	}
}

void pmic_init_sequence(void)
{
	// PMIC wrapper is inited in preloader
	// provided by Wy Chuang, updated 12/03
	pmic_config_interface(0x4,0x1,0x1,4); // [4:4]: RG_EN_DRVSEL; Ricky
	pmic_config_interface(0xA,0x1,0x1,0); // [0:0]: DDUVLO_DEB_EN; Ricky
	pmic_config_interface(0xC,0x1,0x1,0); // [0:0]: VPROC_PG_H2L_EN; Ricky
	pmic_config_interface(0xC,0x1,0x1,1); // [1:1]: VAUX18_PG_H2L_EN; Ricky
	pmic_config_interface(0xC,0x1,0x1,4); // [4:4]: VCORE1_PG_H2L_EN; Ricky
	pmic_config_interface(0xC,0x1,0x1,5); // [5:5]: VSYS22_PG_H2L_EN; Ricky
	pmic_config_interface(0xC,0x1,0x1,6); // [6:6]: VLTE_PG_H2L_EN; Ricky
	pmic_config_interface(0xC,0x1,0x1,7); // [7:7]: VIO18_PG_H2L_EN; Ricky
	pmic_config_interface(0xC,0x1,0x1,8); // [8:8]: VAUD28_PG_H2L_EN; Ricky
	pmic_config_interface(0xC,0x1,0x1,9); // [9:9]: VTCXO_PG_H2L_EN; Ricky
	pmic_config_interface(0xC,0x1,0x1,10); // [10:10]: VUSB_PG_H2L_EN; Ricky
	pmic_config_interface(0xC,0x1,0x1,11); // [11:11]: VSRAM_PG_H2L_EN; Ricky
	pmic_config_interface(0xC,0x1,0x1,12); // [12:12]: VIO28_PG_H2L_EN; Ricky
	pmic_config_interface(0xC,0x1,0x1,13); // [13:13]: VM_PG_H2L_EN; Ricky
	pmic_config_interface(0xE,0x1,0x1,10); // [10:10]: VUSB_PG_ENB; Ricky E1 workaround
	pmic_config_interface(0x10,0x1,0x1,5); // [5:5]: UVLO_L2H_DEB_EN; Ricky
	pmic_config_interface(0x16,0x1,0x1,0); // [0:0]: STRUP_PWROFF_SEQ_EN; Ricky
	pmic_config_interface(0x16,0x1,0x1,1); // [1:1]: STRUP_PWROFF_PREOFF_EN; Ricky
	pmic_config_interface(0x1E,0x0,0x1,11); // [11:11]: RG_TESTMODE_SWEN; CC: Test mode, first command
	pmic_config_interface(0x40,0x1,0x1,12); // [12:12]: RG_RST_DRVSEL; Ricky
	pmic_config_interface(0x204,0x1,0x1,4); // [4:4]: RG_SRCLKEN_IN0_HW_MODE; Juinn-Ting
	pmic_config_interface(0x204,0x1,0x1,5); // [5:5]: RG_SRCLKEN_IN1_HW_MODE; Juinn-Ting
	pmic_config_interface(0x204,0x1,0x1,6); // [6:6]: RG_OSC_SEL_HW_MODE; Juinn-Ting: E1 only
	pmic_config_interface(0x226,0x1,0x1,0); // [0:0]: RG_SMT_WDTRSTB_IN; Ricky
	pmic_config_interface(0x226,0x1,0x1,2); // [2:2]: RG_SMT_SRCLKEN_IN0; Ricky
	pmic_config_interface(0x226,0x1,0x1,3); // [3:3]: RG_SMT_SRCLKEN_IN1; Ricky
	pmic_config_interface(0x242,0x1,0x1,2); // [2:2]: RG_RTC_75K_CK_PDN; Juinn-Ting
	pmic_config_interface(0x242,0x1,0x1,3); // [3:3]: RG_RTCDET_CK_PDN; Juinn-Ting
	pmic_config_interface(0x248,0x1,0x1,13); // [13:13]: RG_RTC_EOSC32_CK_PDN; Juinn-Ting
	pmic_config_interface(0x248,0x1,0x1,14); // [14:14]: RG_TRIM_75K_CK_PDN; Juinn-Ting
	pmic_config_interface(0x25A,0x1,0x1,9); // [9:9]: RG_75K_32K_SEL; Angela
	pmic_config_interface(0x278,0x1,0x1,10); // [10:10]: RG_AUXADC_26M_CK_PDN_HWEN; ZF
	pmic_config_interface(0x278,0x1,0x1,11); // [11:11]: RG_AUXADC_CK_CKSEL_HWEN; ZF
	pmic_config_interface(0x422,0x1,0x1,0); // [0:0]: VSRAM_TRACK_SLEEP_CTRL; SRAM Tracking,Fandy
	pmic_config_interface(0x422,0x1,0x1,1); // [1:1]: VSRAM_TRACK_ON_CTRL; SRAM Tracking,Fandy
	pmic_config_interface(0x422,0x1,0x1,2); // [2:2]: VPROC_TRACK_ON_CTRL; SRAM Tracking,Fandy
	pmic_config_interface(0x424,0x0,0x7F,0); // [6:0]: VSRAM_VOSEL_DELTA; SRAM Tracking,Fandy
	pmic_config_interface(0x424,0x10,0x7F,8); // [14:8]: VSRAM_VOSEL_OFFSET; SRAM Tracking,Fandy
	pmic_config_interface(0x426,0x48,0x7F,0); // [6:0]: VSRAM_VOSEL_ON_LB; SRAM Tracking,Fandy
	pmic_config_interface(0x426,0x78,0x7F,8); // [14:8]: VSRAM_VOSEL_ON_HB; SRAM Tracking,Fandy
	pmic_config_interface(0x428,0x28,0x7F,0); // [6:0]: VSRAM_VOSEL_SLEEP_LB; SRAM Tracking,Fandy
	pmic_config_interface(0x42E,0x1,0x1FF,0); // [8:0]: RG_SMPS_TESTMODE_B; 
	pmic_config_interface(0x462,0x3,0x3,10); // [11:10]: RG_VPA_SLP; Seven,Stability
	pmic_config_interface(0x482,0x1,0x1,1); // [1:1]: VPROC_VOSEL_CTRL; ShangYing
	pmic_config_interface(0x488,0x11,0x7F,0); // [6:0]: VPROC_SFCHG_FRATE; 11/20 DVFS raising slewrate,SY
	pmic_config_interface(0x488,0x1,0x1,7); // [7:7]: VPROC_SFCHG_FEN; VSRAM tracking,Fandy
	pmic_config_interface(0x488,0x4,0x7F,8); // [14:8]: VPROC_SFCHG_RRATE; 11/20 DVFS raising slewrate,SY
	pmic_config_interface(0x488,0x1,0x1,15); // [15:15]: VPROC_SFCHG_REN; VSRAM tracking,Fandy
	pmic_config_interface(0x48E,0x28,0x7F,0); // [6:0]: VPROC_VOSEL_SLEEP; 11/20 Sleep mode 0.85V
	pmic_config_interface(0x498,0x3,0x3,0); // [1:0]: VPROC_TRANS_TD; ShangYing
	pmic_config_interface(0x498,0x1,0x3,4); // [5:4]: VPROC_TRANS_CTRL; ShangYing
	pmic_config_interface(0x498,0x1,0x1,8); // [8:8]: VPROC_VSLEEP_EN; 11/20 sleep mode by SRCLKEN
	pmic_config_interface(0x49A,0x0,0x3,4); // [5:4]: VPROC_OSC_SEL_SRCLKEN_SEL; ShangYing
	pmic_config_interface(0x49A,0x0,0x3,8); // [9:8]: VPROC_R2R_PDN_SRCLKEN_SEL; ShangYing
	pmic_config_interface(0x49A,0x0,0x3,14); // [15:14]: VPROC_VSLEEP_SRCLKEN_SEL; ShangYing
	pmic_config_interface(0x4AA,0x1,0x1,1); // [1:1]: VSRAM_VOSEL_CTRL; SRAM tracking,Fandy
	pmic_config_interface(0x4B0,0x8,0x7F,0); // [6:0]: VSRAM_SFCHG_FRATE; SRAM tracking,Fandy
	pmic_config_interface(0x4B0,0x1,0x1,7); // [7:7]: VSRAM_SFCHG_FEN; SRAM tracking,Fandy
	pmic_config_interface(0x4B0,0x8,0x7F,8); // [14:8]: VSRAM_SFCHG_RRATE; SRAM tracking,Fandy
	pmic_config_interface(0x4B0,0x1,0x1,15); // [15:15]: VSRAM_SFCHG_REN; SRAM tracking,Fandy
	pmic_config_interface(0x4B4,0x40,0x7F,0); // [6:0]: VSRAM_VOSEL_ON; SRAM tracking,Fandy
	pmic_config_interface(0x4D2,0x1,0x1,1); // [1:1]: VLTE_VOSEL_CTRL; ShangYing
	pmic_config_interface(0x4D8,0x11,0x7F,0); // [6:0]: VLTE_SFCHG_FRATE; 11/20 DVFS falling slewrate
	pmic_config_interface(0x4D8,0x4,0x7F,8); // [14:8]: VLTE_SFCHG_RRATE; 11/20 DVFS raising slewrate
	pmic_config_interface(0x4DE,0x28,0x7F,0); // [6:0]: VLTE_VOSEL_SLEEP; 11/20 Sleep mode 0.85V
	pmic_config_interface(0x4E8,0x3,0x3,0); // [1:0]: VLTE_TRANS_TD; ShangYing
	pmic_config_interface(0x4E8,0x1,0x1,8); // [8:8]: VLTE_VSLEEP_EN; 11/20 sleep mode by SRCLKEN
	pmic_config_interface(0x4EA,0x0,0x3,4); // [5:4]: VLTE_OSC_SEL_SRCLKEN_SEL; 
	pmic_config_interface(0x4EA,0x0,0x3,8); // [9:8]: VLTE_R2R_PDN_SRCLKEN_SEL; 
	pmic_config_interface(0x4EA,0x0,0x3,14); // [15:14]: VLTE_VSLEEP_SRCLKEN_SEL; 
	pmic_config_interface(0x60E,0x1,0x1,1); // [1:1]: VCORE1_VOSEL_CTRL; ShangYing
	pmic_config_interface(0x614,0x11,0x7F,0); // [6:0]: VCORE1_SFCHG_FRATE; 11/20 DVS falling slewrate
	pmic_config_interface(0x614,0x4,0x7F,8); // [14:8]: VCORE1_SFCHG_RRATE; 11/20 DVS rising slewrate
	pmic_config_interface(0x61A,0x28,0x7F,0); // [6:0]: VCORE1_VOSEL_SLEEP; 11/20 sleep mode 0.85V
	pmic_config_interface(0x624,0x3,0x3,0); // [1:0]: VCORE1_TRANS_TD; ShangYing
	pmic_config_interface(0x624,0x1,0x1,8); // [8:8]: VCORE1_VSLEEP_EN; 11/20 sleep mode control by SRCLKEN
	pmic_config_interface(0x626,0x0,0x3,4); // [5:4]: VCORE1_OSC_SEL_SRCLKEN_SEL; ShangYing
	pmic_config_interface(0x626,0x0,0x3,8); // [9:8]: VCORE1_R2R_PDN_SRCLKEN_SEL; ShangYing
	pmic_config_interface(0x626,0x0,0x3,14); // [15:14]: VCORE1_VSLEEP_SRCLKEN_SEL; ShangYing
	pmic_config_interface(0x646,0x5,0x7,0); // [2:0]: VSYS22_BURST; Seven
	pmic_config_interface(0x664,0x2,0x7F,0); // [6:0]: VPA_SFCHG_FRATE; Seven
	pmic_config_interface(0x664,0x0,0x1,7); // [7:7]: VPA_SFCHG_FEN; Seven
	pmic_config_interface(0x664,0x2,0x7F,8); // [14:8]: VPA_SFCHG_RRATE; Seven
	pmic_config_interface(0x664,0x0,0x1,15); // [15:15]: VPA_SFCHG_REN; Seven
	pmic_config_interface(0x67E,0x3,0x3,4); // [5:4]: VPA_DVS_TRANS_CTRL; Seven
	pmic_config_interface(0xA02,0x1,0x1,3); // [3:3]: RG_VTCXO_1_ON_CTRL; by RF request 11/02,Luke
	pmic_config_interface(0xA06,0x1,0x1,6); // [6:6]: RG_VAUX18_AUXADC_PWDB_EN; Chuan-Hung
	pmic_config_interface(0xA30,0x0,0x1,0); // [0:0]: RG_VEFUSE_MODE_SET; Fandy:Disable VEFUSE
	pmic_config_interface(0xA44,0x1,0x1,1); // [1:1]: RG_TREF_EN; Tim
	pmic_config_interface(0xA46,0x0,0x1,14); // [14:14]: QI_VM_STB; Fandy, disable
	pmic_config_interface(0xC14,0x1,0x1,0); // [0:0]: RG_SKIP_OTP_OUT; Fandy: for CORE power(VDVFS1x, VCOREx, VSRAM_DVFS) max voltage limitation.
	pmic_config_interface(0xCBC,0x1,0x1,8); // [8:8]: FG_SLP_EN; Ricky
	pmic_config_interface(0xCBC,0x1,0x1,9); // [9:9]: FG_ZCV_DET_EN; Ricky
	pmic_config_interface(0xCC0,0x24,0xFFFF,0); // [15:0]: FG_SLP_CUR_TH; Ricky
	pmic_config_interface(0xCC2,0x14,0xFF,0); // [7:0]: FG_SLP_TIME; Ricky
	pmic_config_interface(0xCC4,0xFF,0xFF,8); // [15:8]: FG_DET_TIME; Ricky
	pmic_config_interface(0xE94,0x0,0x1,13); // [13:13]: AUXADC_CK_AON_GPS; YP Niou, sync with golden setting
	pmic_config_interface(0xE94,0x0,0x1,14); // [14:14]: AUXADC_CK_AON_MD; YP Niou, sync with golden setting
	pmic_config_interface(0xE94,0x0,0x1,15); // [15:15]: AUXADC_CK_AON; YP Niou, sync with golden setting
	pmic_config_interface(0xEA4,0x1,0x3,4); // [5:4]: AUXADC_TRIM_CH2_SEL; Ricky
	pmic_config_interface(0xEA4,0x1,0x3,6); // [7:6]: AUXADC_TRIM_CH3_SEL; Ricky
	pmic_config_interface(0xEA4,0x1,0x3,8); // [9:8]: AUXADC_TRIM_CH4_SEL; Ricky
	pmic_config_interface(0xEA4,0x1,0x3,10); // [11:10]: AUXADC_TRIM_CH5_SEL; Ricky
	pmic_config_interface(0xEA4,0x1,0x3,12); // [13:12]: AUXADC_TRIM_CH6_SEL; Ricky
	pmic_config_interface(0xEA4,0x2,0x3,14); // [15:14]: AUXADC_TRIM_CH7_SEL; Ricky
	pmic_config_interface(0xEA6,0x1,0x3,0); // [1:0]: AUXADC_TRIM_CH8_SEL; Ricky
	pmic_config_interface(0xEA6,0x1,0x3,2); // [3:2]: AUXADC_TRIM_CH9_SEL; Ricky
	pmic_config_interface(0xEA6,0x1,0x3,4); // [5:4]: AUXADC_TRIM_CH10_SEL; Ricky
	pmic_config_interface(0xEA6,0x1,0x3,6); // [7:6]: AUXADC_TRIM_CH11_SEL; Ricky
	pmic_config_interface(0xEB8,0x1,0x1,14); // [14:14]: AUXADC_START_SHADE_EN; Chuan-Hung
	pmic_config_interface(0xF4A,0xB,0xF,4); // [7:4]: RG_VCDT_HV_VTH; Tim:VCDT_HV_th=7V
	pmic_config_interface(0xF54,0x0,0x7,1); // [3:1]: RG_VBAT_OV_VTH; Tim:for 4.35 battery
	pmic_config_interface(0xF62,0x3,0xF,0); // [3:0]: RG_CHRWDT_TD; Tim:WDT=32s
	pmic_config_interface(0xF6C,0x2,0x1F,0); // [4:0]: RG_LBAT_INT_VTH; Ricky: E1 only
	pmic_config_interface(0xF70,0x1,0x1,1); // [1:1]: RG_BC11_RST; Tim:Disable BC1.1 timer
	pmic_config_interface(0xF74,0x0,0x7,4); // [6:4]: RG_CSDAC_STP_DEC; Tim:Reduce ICHG current ripple (align 6323)
	pmic_config_interface(0xF7A,0x1,0x1,2); // [2:2]: RG_CSDAC_MODE; Tim:Align 6323
	pmic_config_interface(0xF7A,0x1,0x1,6); // [6:6]: RG_HWCV_EN; Tim:Align 6323
	pmic_config_interface(0xF7A,0x1,0x1,7); // [7:7]: RG_ULC_DET_EN; Tim:Align 6323
}


