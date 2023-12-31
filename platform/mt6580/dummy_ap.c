// Dummy AP
#include <platform/boot_mode.h>
#include <debug.h>
#include <dev/uart.h>
#include <platform/mtk_key.h>
#include <target/cust_key.h>
#include <platform/mt_gpio.h>

// Feature on/off config
//#define ENABLE_MD_RESET
#define ENABLE_DUMMY_AP_FOR_MD1
//#define ENABLE_DUMMY_AP_FOR_MD2

#ifdef ENABLE_MD_RESET
#include <platform/spm.h>
#endif

#define MAX_MD_NUM            (2)
#define MAX_IMG_NUM            (8)
#define PART_HEADER_MAGIC    (0x58881688)
#define BOOT_ARGS_ADDR        (0x87F00000)
#define IMG_HEADER_ADDR        (0x87F00000+1024)

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
    char        name[32];
    img_idx_t    idx;
}map_t;

//typedef union
//{
//    struct
//    {
//        unsigned int magic;     /* partition magic */
//        unsigned int dsize;     /* partition data size */
//        char name[32];          /* partition name */
//        unsigned int maddr;     /* partition memory address */
//    } info;
//    unsigned char data[512];
//} part_hdr_t;


// Notice for MT6582
// Update LK BOOT_ARGUMENT structure
/*
typedef struct {
    unsigned int  magic_number;
    BOOTMODE      boot_mode;
    unsigned int  e_flag;
    unsigned int  log_port;
    unsigned int  log_baudrate;
    unsigned char log_enable;
    unsigned char part_num; //<<<-------
    unsigned char reserved[2]; //<<<-------
    unsigned int  dram_rank_num;
    unsigned int  dram_rank_size[4];
    unsigned int  boot_reason;
    unsigned int  meta_com_type;
    unsigned int  meta_com_id;
    unsigned int  boot_time;
    da_info_t     da_info;
    SEC_LIMIT     sec_limit;    
    part_hdr_t    *part_info; //<<<------
} BOOT_ARGUMENT;
*/
extern BOOT_ARGUMENT    *g_boot_arg; //<<<-----
//static BOOT_ARGUMENT    *boot_args=BOOT_ARGS_ADDR;
//static unsigned int    *img_header_array = (unsigned int*)IMG_HEADER_ADDR;
static unsigned int        img_load_flag = 0;
static part_hdr_t        *img_info_start = NULL;
static unsigned int        img_addr_tbl[MAX_IMG_NUM];
static unsigned int        img_size_tbl[MAX_IMG_NUM];
static map_t            map_tbl[] = 
                        {
                            {"DUMMY_AP",        DUMMY_AP_IMG},
                            {"MD_IMG",          MD1_IMG},
                            {"MD_RAM_DISK",     MD1_RAM_DISK},
                            {"MD_DSP",          MD_DSP},
                            {"MD2_IMG",         MD2_IMG},
                            {"MD2_RAM_DISK",    MD2_RAM_DISK},
                        };

extern int mt_set_gpio_mode_chip(unsigned int pin, unsigned int mode);

int parse_img_header(unsigned int *start_addr, unsigned int img_num) //<<<------
{
    int i, j;
    int idx;

    if(start_addr == NULL) {
        printf("parse_img_header get invalid parameters!\n");
        return -1;
    }
    img_info_start = (part_hdr_t*)start_addr;
    for(i=0; i<img_num; i++) //<<<------
    {
        if(img_info_start[i].info.magic != PART_HEADER_MAGIC)
            continue;

        for(j=0; j<(sizeof(map_tbl)/sizeof(map_t)); j++)
        {
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
    // Put check bootmode code here
    if(g_boot_arg->boot_mode != NORMAL_BOOT)
        boot_mode = 1;
    printf("Meta mode: %d, boot_mode: %d-v1)\n", boot_mode, g_boot_arg->boot_mode);
    return boot_mode;
}

static void md_gpio_config(unsigned int boot_md_id)
{
    switch(boot_md_id)
    {
        #ifdef ENABLE_DUMMY_AP_FOR_MD1
        case 0:
            //SIM1=> MD1 SIM1IF
            mt_set_gpio_mode(GPIO22,1);
            mt_set_gpio_mode(GPIO23,1);
            //SIM2=> MD1 SIM2IF
            mt_set_gpio_mode(GPIO24,1);
            mt_set_gpio_mode(GPIO25,1);
            break;
        #endif

        #ifdef ENABLE_DUMMY_AP_FOR_MD2
        case 1:
            //SIM1=> MD2 SIM1IF
            mt_set_gpio_mode(GPIO_SIM1_SCLK,2);
            mt_set_gpio_mode(GPIO_SIM1_SRST,2);
            mt_set_gpio_mode(GPIO_SIM1_SIO ,2);
            //SIM2=> MD2 SIM2IF
            mt_set_gpio_mode(GPIO_SIM2_SCLK,2);
            mt_set_gpio_mode(GPIO_SIM2_SRST,2);
            mt_set_gpio_mode(GPIO_SIM2_SIO ,2);
            break;
        #endif

       default:
           printf("@md_gpio_config, MD%d not enable!!!\n", boot_md_id+1);
           return;
    }

}

static void md_emi_remapping(unsigned int boot_md_id)
{
    unsigned int md_img_start_addr = 0;
    unsigned int md_emi_remapping_addr = 0;

    switch(boot_md_id)
    {
        #ifdef ENABLE_DUMMY_AP_FOR_MD1
        case 0: // MD1
            md_img_start_addr = img_addr_tbl[MD1_IMG] - 0x80000000;
            md_emi_remapping_addr = 0x10001300; // MD1 BANK0_MAP0
            break;
        #endif

        #ifdef ENABLE_DUMMY_AP_FOR_MD2
        case 1: // MD2
            md_img_start_addr = img_addr_tbl[MD2_IMG] - 0x40000000;
            md_emi_remapping_addr = 0x10001310; // MD2 BANK0_MAP0
            break;
        #endif
            
        default:
            printf("@md_emi_remapping, MD%d not enable!!!\n", boot_md_id+1);
            return;
    }

    printf("  ---> Map 0x00000000 to %x for MD%d\n", md_img_start_addr, boot_md_id+1);
    
    // For MDx BANK0_MAP0 
    *((volatile unsigned int*)md_emi_remapping_addr) = (((md_img_start_addr >> 24) | 1) & 0xFF) \
    + ((((md_img_start_addr + 0x02000000) >> 16) | 1<<8) & 0xFF00) \
    + ((((md_img_start_addr + 0x04000000) >> 8) | 1<<16) & 0xFF0000) \
    + ((((md_img_start_addr + 0x06000000) >> 0) | 1<<24) & 0xFF000000);
    
    // For MDx BANK0_MAP1
    *((volatile unsigned int*)(md_emi_remapping_addr + 0x4)) = ((((md_img_start_addr + 0x08000000) >> 24) | 1) & 0xFF) \
    + ((((md_img_start_addr + 0x0A000000) >> 16) | 1<<8) & 0xFF00) \
    + ((((md_img_start_addr + 0x0C000000) >> 8) | 1<<16) & 0xFF0000) \
    + ((((md_img_start_addr + 0x0E000000) >> 0) | 1<<24) & 0xFF000000);
}

static void md_power_up_mtcmos(unsigned int boot_md_id)
{
#if 0 // Chao ????????? Wait YP api ready
    volatile unsigned int loop = 10000;

    loop =10000;
    while(loop-->0);

    switch(boot_md_id)
    {
        case 0://MD 1
#ifdef ENABLE_MD_RESET        	
        	spm_mtcmos_ctrl_mdsys1(STA_POWER_ON);
#endif
            break;
            
        case 1:// MD2
            break;
        
    }
#endif
}

static void md_common_setting(int boot_md_id)
{
    volatile unsigned int *md_wdt;
    unsigned int r_md_wdt = 0;
    
    switch(boot_md_id)
    {
        #ifdef ENABLE_DUMMY_AP_FOR_MD1
        case 0:
            // Put special setting here if needed
            //; ## Disable WDT
            //print "Disable MD1 WDT"
            md_wdt = (volatile unsigned int*)0x20050000;
            printf("Disable MD1 WDT\n");
            r_md_wdt = *md_wdt;
            r_md_wdt &= 0xFFFFFFFE;
            r_md_wdt |= 0x2200;
            mdelay(5);
            *md_wdt = r_md_wdt;

            //SRCLKEN_O1 = 1 for MD_VRF18. Requested by Terry.Chang.
            //Need to fix. Ask Terry for API. We shoudl just call SPM's API here.

            break;
        #endif

        #ifdef ENABLE_DUMMY_AP_FOR_MD2
        case 1:
            // Put special setting here if needed
            //; ## Disable WDT
            //print "Disable MD1 WDT"
            md_wdt = (volatile unsigned int*)0x30050000;
            printf("Disable MD2 WDT\n");
            r_md_wdt = *md_wdt;
            r_md_wdt &= 0xFFFFFFFE;
            r_md_wdt |= 0x2200;
            mdelay(5);
            *md_wdt = r_md_wdt;

            //SRCLKEN_O1 = 1 for MD_VRF18. Requested by Terry.Chang.
            //Need to fix. Ask Terry for API. We shoudl just call SPM's API here.
            *(volatile unsigned int *)(0x10006000) = 0x0B160001;
            *(volatile unsigned int *)(0x10006014) = (*(volatile unsigned int *)(0x10006014)) | (0x1 << 21);
            break;
        #endif

        default:
            printf("@md_common_setting, MD%d not enable!!!\n", boot_md_id+1);
            return;
        }
}

static void md_boot_up(unsigned int boot_md_id, unsigned int is_meta_mode)
{
    unsigned int reg_value;
    switch(boot_md_id){
        #ifdef ENABLE_DUMMY_AP_FOR_MD1
        case 0:// For MD1
            if(is_meta_mode)
            {
                // Put META Register setting here
                *((volatile unsigned int*)0x20000010) |= 0x1; // Bit0, Meta mode flag, this need sync with MD init owner
            }
            // Set boot slave to let MD to run
            *((volatile unsigned int*)0x2019379C) = 0x3567C766; // Key Register
            *((volatile unsigned int*)0x20190000) = 0x0;         // Vector Register
            *((volatile unsigned int*)0x20195488) = 0xA3B66175; // Slave En Register
            break;
        #endif

        #ifdef ENABLE_DUMMY_AP_FOR_MD2
        case 1:// For MD2
            printf("md_bootup: md2 set VTCXO_1 on,bit3=1\n");
            pmic_config_interface(0x0A02, 0x1, 0x1, 3); //bit:3: =>b1
            printf("md_bootup: md2 set SRCLK_EN_SEL on,bit(13,12)=(0,1)\n");
            pmic_config_interface(0x0A02, 0x1, 0x3, 12);//bit:13:12=>b01
            
            reg_value = *((volatile unsigned int*)0x10001F00);
            reg_value &= ~(0x1E000000);
            reg_value |= 0x12000000;
            *((volatile unsigned int*)0x10001F00) = reg_value;
            printf("md_bootup: md2 enable, set SRCLKEN infra_misc(0x1000_1F00), bit(28,27,26,25)=0x%x\n",(*((volatile unsigned int*)0x10001F00)&0x1E000000));           
            reg_value = *((volatile unsigned int*)0x10001F08);
            reg_value &= ~(0x001F0078);
            reg_value |= 0x001B0048;
            *((volatile unsigned int*)0x10001F08) = reg_value;
            printf("md_bootup: md2 set PLL misc_config(0x1000_1F08), bit(20,19,18,17,16,6,5,4,3)=0x%x\n",(*((volatile unsigned int*)0x10001F08)&0x001F0078)); 
            mdelay(3);// sleep 3            
            *((volatile unsigned int*)0x1000C004) = 0x00000101;
            printf("md_bootup: md2 set AP_PLL_CON1(0x1000C004)=0x%x\n",(*((volatile unsigned int*)0x1000C004)&0x00000101));
            mdelay(1);
            *((volatile unsigned int*)0x1000C004) = 0x00000103;
            printf("md_bootup: md2 set AP_PLL_CON1(0x1000C004)=0x%x\n",(*((volatile unsigned int*)0x1000C004)&0x00000103)); 

            if(is_meta_mode)
            {
                // Put META Register setting here
                *((volatile unsigned int*)0x30000010) |= 0x1; // Bit0, Meta mode flag, this need sync with MD init owner
            }
            // Set boot slave to let MD to run
            *((volatile unsigned int*)0x3019379C) = 0x3567C766; // Key Register
            *((volatile unsigned int*)0x30190000) = 0x0;         // Vector Register
            *((volatile unsigned int*)0x30195488) = 0xA3B66175; // Slave En Register

            break;
        #endif

        default:
            printf("@md_boot_up, MD%d not enable!!!\n", boot_md_id+1);
            return;
    }

}

int md_jtag_config(int boot_md_id)
{
    // Add Jtag setting here
    return 0;
}

int get_input(void)
{
    return 0;
}

void apply_env_setting(int case_id)
{
    printf("Apply case:%d setting for dummy AP!\n", case_id);
}

void md_uart_config(int md_id)
{
    switch(md_id)
    {
        #ifdef ENABLE_DUMMY_AP_FOR_MD1
        case 0:

            // UART pin mux description
            // GPIOID--------M0--------M1--------M2--------M3--------M4--------M5--------M6--------M7
            //   8                   URXD2              MD_URXD3
            //  65                                                          MD_UTXD3
            //  67                                                          MD_URXD3
            //  77                   URXD1               URXD2              MD_URXD3
            //  78                   UTXD1               UTXD2              MD_UTXD3
            // Switch AP UART to MD1 uart
            // Disable 65 and 67 for mode priority
            mt_set_gpio_mode(GPIO65, 0);
            mt_set_gpio_dir(GPIO65, GPIO_DIR_IN);
            mt_set_gpio_mode(GPIO67, 0);
            mt_set_gpio_dir(GPIO67, GPIO_DIR_IN);
            //RX
            mt_set_gpio_mode(GPIO77,5);
            mt_set_gpio_dir(GPIO77, GPIO_DIR_IN);
            mt_set_gpio_pull_enable(GPIO77, GPIO_PULL_ENABLE); 
            mt_set_gpio_pull_select(GPIO77, GPIO_PULL_UP);
            //TX
            mt_set_gpio_mode(GPIO78,5);
            mt_set_gpio_dir(GPIO78, GPIO_DIR_OUT);

            break;
        #endif

        #ifdef ENABLE_DUMMY_AP_FOR_MD2
        case 1:

            printf("md_uart_config:%d,enable md2, disable AP & MD1 uart!\n", md_id);
            //disable AP uart
            //RX
            mt_set_gpio_mode(GPIO136,GPIO_MODE_GPIO);
            mt_set_gpio_dir(GPIO136, GPIO_DIR_IN);
            mt_set_gpio_pull_enable(GPIO136, GPIO_PULL_DISABLE);
            //TX
            mt_set_gpio_mode(GPIO137,GPIO_MODE_GPIO);
            mt_set_gpio_dir(GPIO137, GPIO_DIR_IN);
            mt_set_gpio_pull_enable(GPIO137, GPIO_PULL_DISABLE); 

            //disable MD1 uart
            //RX
            mt_set_gpio_mode(GPIO144,GPIO_MODE_GPIO);
            mt_set_gpio_dir(GPIO144, GPIO_DIR_IN);
            mt_set_gpio_pull_enable(GPIO144, GPIO_PULL_DISABLE); 
            //TX
            mt_set_gpio_mode(GPIO145,GPIO_MODE_GPIO);
            mt_set_gpio_dir(GPIO145, GPIO_DIR_IN);
            mt_set_gpio_pull_enable(GPIO15, GPIO_PULL_DISABLE); 
             
            //enable  MD2 uart 
            //RX
            mt_set_gpio_mode(GPIO14,4);
            mt_set_gpio_dir(GPIO14, GPIO_DIR_IN);
            mt_set_gpio_pull_enable(GPIO14, GPIO_PULL_ENABLE); 
            mt_set_gpio_pull_select(GPIO14, GPIO_PULL_UP);
            //TX
            mt_set_gpio_mode(GPIO15,4);
            mt_set_gpio_dir(GPIO15, GPIO_DIR_OUT);

            break;
        #endif

        default:
            printf("@md_uart_config, MD%d not enable!!!\n", md_id+1);
            return;

    }
}
static void let_md_go(int md_id)
{
		unsigned int    is_meta_mode = 0;
    // 1, Setup special GPIO request (RF/SIM/UART ... etc)
    printf("Step 1: Configure GPIO!\n");
    md_gpio_config(md_id);

    // 2, Configure EMI remapping setting
    printf("Step 2: Configure EMI remapping...\n");
    md_emi_remapping(md_id);

    // 3, Power up MD MTCMOS
    //printf("Step 3: Power up MD!\n");
    md_power_up_mtcmos(md_id);

    // 4, Configure DAP for ICE to connect to MD
    printf("Step 4: Configure DAP for ICE to connect to MD!\n");
    md_jtag_config(md_id);

    // 5, Check boot Mode
    is_meta_mode = meta_detection();
    printf("Step 5: Notify MD enter %s mode!\n", is_meta_mode ? "META" : "NORMAL");

    // 6, MD register setting
    printf("Step 6: MD Common setting!\n");
    md_common_setting(md_id);

    // 7, Boot up MD
    printf("Step 7: MD%d boot up with meta(%d)!\n", md_id+1, is_meta_mode);
    md_boot_up(md_id, is_meta_mode);

    printf("\nmd%d boot up done!\n", md_id + 1);
    printf("\nmd%d switch uart,then enter while(1)!\n", md_id + 1);
    md_uart_config(md_id);
}
void md_wdt_init(void);
void dummy_ap_entry(void)
{
    int                md_check_tbl[] = {1<<MD1_IMG, 1<<MD2_IMG};
    int                i=0;
    int                get_val;

    volatile unsigned int    count;
    volatile unsigned int    count1;

    // Disable AP WDT
    *(volatile unsigned int *)(0x10007000) = 0x22000000; 

    printf("Welcome to use dummy AP!\n");
    get_val = get_input();

    apply_env_setting(get_val);

    // 0, Parse header info
    printf("Parsing image info!\n");
    //parse_img_header(img_header_array); //<<<------
    parse_img_header((unsigned int*)g_boot_arg->part_info, (unsigned int)g_boot_arg->part_num);

    printf("Begin to configure MD run env!\n");
    for(i=0; i<MAX_MD_NUM; i++) {
        if(img_load_flag & md_check_tbl[i]) {
            printf("MD%d Enabled\n", i+1);
            let_md_go(i);
        }
    }

    printf("All dummy AP config done, enter while(1), ^0^!!!!!\n");
    while(1);
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
    while(1);
}

// EXT functions
#include <sys/types.h>
#include <debug.h>
#include <err.h>
#include <reg.h>
#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_irq.h>
#include <sys/types.h>

#define GIC_PRIVATE_SIGNALS    (32)
#define MT_MD_WDT1_IRQ_ID    (184)

#define TOPRGU_BASE (0x10007000)
#define TOP_RGU_MODE_ADDR (TOPRGU_BASE+0x0)
#define TOP_RGU_SW_WDT_ADDR (TOPRGU_BASE+0x14)
#define TOP_RGU_COUNT_ADDR (TOPRGU_BASE+0x20)

void md_wdt_irq_handler(unsigned int irq)
{
#ifdef ENABLE_MD_RESET 
	  if(irq==MT_MD_WDT1_IRQ_ID)
	  {
	    unsigned int cnt = *(volatile unsigned int *)(TOP_RGU_COUNT_ADDR);
            *(volatile unsigned int *)(TOP_RGU_COUNT_ADDR) = cnt+1;
	    //disable MD1 uart
	    //RX
	    mt_set_gpio_mode(GPIO144,GPIO_MODE_GPIO);
	    mt_set_gpio_dir(GPIO144, GPIO_DIR_IN);
	    mt_set_gpio_pull_enable(GPIO144, GPIO_PULL_DISABLE); 
	    //TX
	    mt_set_gpio_mode(GPIO145,GPIO_MODE_GPIO);
	    mt_set_gpio_dir(GPIO145, GPIO_DIR_IN);
	    mt_set_gpio_pull_enable(GPIO15, GPIO_PULL_DISABLE); 
	    //disable MD2 uart
	    //RX
	    mt_set_gpio_mode(GPIO14,GPIO_MODE_GPIO);
	    mt_set_gpio_dir(GPIO14, GPIO_DIR_IN);
	    mt_set_gpio_pull_enable(GPIO14, GPIO_PULL_DISABLE); 
	    //TX
	    mt_set_gpio_mode(GPIO15,GPIO_MODE_GPIO);
	    mt_set_gpio_dir(GPIO15, GPIO_DIR_IN);
	    mt_set_gpio_pull_enable(GPIO15, GPIO_PULL_DISABLE);	  	
      //enable AP uart
      //RX
      mt_set_gpio_mode(GPIO136,GPIO_MODE_GPIO);
      mt_set_gpio_dir(GPIO136, GPIO_DIR_IN);
      mt_set_gpio_pull_enable(GPIO136, GPIO_PULL_DISABLE);
      //TX
      mt_set_gpio_mode(GPIO137,GPIO_MODE_GPIO);
      mt_set_gpio_dir(GPIO137, GPIO_DIR_IN);
      mt_set_gpio_pull_enable(GPIO137, GPIO_PULL_DISABLE);
      
      //RX
      mt_set_gpio_mode(GPIO136,2);
      mt_set_gpio_dir(GPIO136, GPIO_DIR_IN);
      mt_set_gpio_pull_enable(GPIO136, GPIO_PULL_ENABLE); 
      mt_set_gpio_pull_select(GPIO136, GPIO_PULL_UP);
      //TX
      mt_set_gpio_mode(GPIO137,2);
      mt_set_gpio_dir(GPIO137, GPIO_DIR_OUT);
      printf("MD1 power off\n");
			spm_mtcmos_ctrl_mdsys1(STA_POWER_DOWN);
			mdelay(5);
			let_md_go(0);
		}
#else
    //printf("Get MD WDT irq, STA:%x!!\n", *((volatile unsigned int*)0x2005000C));
    *(volatile unsigned int *)(TOP_RGU_MODE_ADDR) = 0x22000000;
    *(volatile unsigned int *)(TOP_RGU_SW_WDT_ADDR) = 0x1209;
    while(1);
#endif    
}

void dummy_ap_irq_handler(unsigned int irq)
{
    switch(irq){
    case MT_MD_WDT1_IRQ_ID:
        if(img_load_flag &(1<<MD1_IMG)) {
            md_wdt_irq_handler(MT_MD_WDT1_IRQ_ID);
            mt_irq_ack(MT_MD_WDT1_IRQ_ID);
            mt_irq_unmask(MT_MD_WDT1_IRQ_ID);
        }
        break;
    default:
        break;
    }
}

void md_wdt_init(void)
{
    if(img_load_flag &(1<<MD1_IMG)) {    
        mt_irq_set_sens(MT_MD_WDT1_IRQ_ID, MT65xx_EDGE_SENSITIVE);
        mt_irq_set_polarity(MT_MD_WDT1_IRQ_ID, MT65xx_POLARITY_LOW);
        mt_irq_unmask(MT_MD_WDT1_IRQ_ID);
    }
}

