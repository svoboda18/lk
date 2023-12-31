#ifndef BUILD_LK
#include <linux/string.h>
#include <linux/kernel.h>
#endif
#include "lcm_drv.h"

#ifdef BUILD_LK
//#include <platform/upmu_common.h>
//#include <platform/upmu_hw.h>

#include <platform/mt_gpio.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <string.h>
#else
#include <mach/mt_pm_ldo.h> /* hwPowerOn */
#include <mach/upmu_common.h>
#include <mach/upmu_sw.h>
#include <mach/upmu_hw.h>

#include <mach/mt_gpio.h>
#endif
#include <cust_gpio_usage.h>
static LCM_UTIL_FUNCS lcm_util;


#define SET_RESET_PIN(v)                                    (lcm_util.set_reset_pin((v)))
#define MDELAY(n)                                           (lcm_util.mdelay(n))
#define UDELAY(n)                                           (lcm_util.udelay(n))


// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)    lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)       lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)                                      lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)                  lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)                                       lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)               lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)

#ifndef BUILD_LK
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/i2c.h>
#include <linux/irq.h>
//#include <linux/jiffies.h>
#include <linux/uaccess.h>
//#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/platform_device.h>
/*****************************************************************************
 * Define
 *****************************************************************************/
#endif

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------
#define LCM_DSI_CMD_MODE  0

#define FRAME_WIDTH                                         (1920)
#define FRAME_HEIGHT                                        (1200)

#define REGFLAG_DELAY                                           0xFC
#define REGFLAG_UDELAY                                          0xFB

#define REGFLAG_END_OF_TABLE                                    0xFD   // END OF REGISTERS MARKER
#define REGFLAG_RESET_LOW                                       0xFE
#define REGFLAG_RESET_HIGH                                      0xFF




static LCM_DSI_MODE_SWITCH_CMD lcm_switch_mode_cmd;

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef BUILD_LK
static unsigned int lcm_esd_test = FALSE;      ///only for ESD test
#endif
// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

#ifdef GPIO_LCM_PWR_EN
#define GPIO_LCD_PWR_EN      GPIO_LCM_PWR_EN
#else
#define GPIO_LCD_PWR_EN      66
#endif

//#ifdef GPIO_LCM_RST
//#define GPIO_LCD_RST      GPIO_LCM_RST
//#else
//#define GPIO_LCD_RST      63
//#endif

//#ifdef GPIO_LCM_BL_EN
//#define GPIO_LCD_BL_EN      GPIO_LCM_BL_EN
//#else
//#define GPIO_LCD_BL_EN      54
//#endif

#define _LCM_DEBUG_

#ifdef BUILD_LK
#define printk printf
#endif

#ifdef _LCM_DEBUG_
#define lcm_debug(fmt, args...) printk(fmt, ##args)
#else
#define lcm_debug(fmt, args...) do { } while (0)
#endif

#ifdef _LCM_INFO_
#define lcm_info(fmt, args...) printk(fmt, ##args)
#else
#define lcm_info(fmt, args...) do { } while (0)
#endif
#define lcm_err(fmt, args...) printk(fmt, ##args)

// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

struct LCM_setting_table {
	unsigned char cmd;
	unsigned char count;
	unsigned char para_list[64];
};

static struct LCM_setting_table lcm_suspend_setting[] = {
	{0x28,0,{}},
	{0x10,0,{}},
	{REGFLAG_DELAY, 120, {}},
};
#if 0
static struct LCM_setting_table lcm_initialization_setting[] = {
	/*
	Note :

	Data ID will depends on the following rule.

	    count of parameters > 1 => Data ID = 0x39
	    count of parameters = 1 => Data ID = 0x15
	    count of parameters = 0 => Data ID = 0x05

	Structure Format :

	{DCS command, count of parameters, {parameter list}}
	{REGFLAG_DELAY, milliseconds of time, {}},

	...

	Setting ending by predefined flag

	{REGFLAG_END_OF_TABLE, 0x00, {}}
	*/

	// Set password
	{0xB9,  3 ,{0xFF, 0x83, 0x94}},

	// Set BA
	{0xBA,  2 ,{0x33, 0x83}},

	// Set B0
	{0xB0,  4 ,{0x00, 0x00, 0x7D, 0x0C}},

	// Set Power
	{
		0xB1,  15 ,{
			0x6c, 0x15, 0x15, 0x24,
			0x04, 0x11, 0xF1, 0x80,
			0xE4, 0x97, 0x23, 0x80,
			0xC0, 0xD2, 0x58
		}
	},

	// Set Display
	{
		0xB2,  11 ,{
			0x00, 0x64, 0x10, 0x07,
			0x22, 0x1C, 0x08, 0x08,
			0x1C, 0x4D,0x00
		}
	},

	// Set CYC
	{
		0xB4,  12 ,{
			0x00, 0xFF, 0x03, 0x5A,
			0x03, 0x5A, 0x03, 0x5A,
			0x01, 0x6a, 0x30, 0x6a
		}
	},

	// Set BC
	{0xBc,  1 ,{0x07}},


	// Set BF
	{0xBF,  3 ,{0x41, 0x0E, 0x01}},

	// Set VCOM
	{0xB6,  2 ,{0x5c, 0x5c}},

	// Set panel
	{0xCC,  1 ,{0x01}},

	// Set D3
	{
		0xD3,  30 ,{
			0x00, 0x06, 0x00, 0x40,
			0x07, 0x08, 0x00, 0x32,
			0x10, 0x07, 0x00, 0x07,
			0x54, 0x15, 0x0F, 0x05,
			0x04, 0x02, 0x12, 0x10,
			0x05, 0x07, 0x33, 0x33,
			0x0B, 0x0B, 0x37, 0x10,
			0x07, 0x07
		}
	},

	// Set GIP
	{
		0xD5,  44 ,{
			0x04, 0x05, 0x06, 0x07,
			0x00, 0x01, 0x02, 0x03,
			0x20, 0x21, 0x22, 0x23,
			0x18, 0x18, 0x18, 0x18,
			0x18, 0x18, 0x18, 0x18,
			0x19, 0x19, 0x18, 0x18,
			0x18, 0x18, 0x1B, 0x1B,
			0x1A, 0x1A, 0x18, 0x18,
			0x18, 0x18, 0x18, 0x18,
			0x18, 0x18, 0x18, 0x18,
			0x18, 0x18, 0x18, 0x18
		}
	},



	// Set D6
	{
		0xD6,  44 ,{
			0x03, 0x02, 0x01, 0x00,
			0x07, 0x06, 0x05, 0x04,
			0x23, 0x22, 0x21, 0x20,
			0x18, 0x18, 0x18, 0x18,
			0x18, 0x18, 0x58, 0x58,
			0x18, 0x18, 0x19, 0x19,
			0x18, 0x18, 0x1B, 0x1B,
			0x1A, 0x1A, 0x18, 0x18,
			0x18, 0x18, 0x18, 0x18,
			0x18, 0x18, 0x18, 0x18,
			0x18, 0x18, 0x18, 0x18
		}
	},

	// Set R Gamma
	{
		0xE0,  42 ,{
			0x00, 0x10, 0x16, 0x2D,
			0x33, 0x3F, 0x23, 0x3E,
			0x07, 0x0B, 0x0D, 0x17,
			0x0E, 0x12, 0x14, 0x12,
			0x13, 0x06, 0x11, 0x13,
			0x18, 0x00, 0x10, 0x16,
			0x2D, 0x33, 0x3F, 0x23,
			0x3E, 0x07, 0x0B, 0x0D,
			0x17, 0x0E, 0x12, 0x14,
			0x12, 0x13, 0x06, 0x11,
			0x13, 0x18
		}
	},

	// Set 0xC0
	{0xC0,  2 ,{0x30, 0x14}},

	// Set 0xC7
	{0xC7,  4 ,{0x00, 0xC0, 0x40, 0xC0}},

	// Set 0xdf
	{0xDF,  1 ,{0x8e}},

	// Set 0xd2
	{0xd2,  1 ,{0x66}},


	// Sleep Out
	{0x11, 0, {}},
	{REGFLAG_DELAY, 200, {}},

	// Display ON
	{0x29,0,{}},
	{REGFLAG_DELAY, 50,{}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}
};
#endif


static struct LCM_setting_table lcm_sleep_out_setting[] = {
	// Sleep Out
	{0x11, 0, {0x00}},
	{REGFLAG_DELAY, 150, {}},

	// Display ON
	{0x29, 0, {0x00}},
	{REGFLAG_DELAY, 20, {}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}
};

static struct LCM_setting_table lcm_sleep_in_setting[] = {
	// Display off sequence
	{0x28, 0, {0x00}},
	{REGFLAG_DELAY, 10, {}},

	// Sleep Mode On
	{0x10, 0, {0x00}},
	{REGFLAG_DELAY, 150, {}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}
};

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;

	for (i = 0; i < count; i++) {
		unsigned cmd;
		cmd = table[i].cmd;

		switch (cmd) {

			case REGFLAG_DELAY :
				MDELAY(table[i].count);
				break;

			case REGFLAG_UDELAY :
				UDELAY(table[i].count);
				break;

			case REGFLAG_END_OF_TABLE :
				break;

			default:
				dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
		}
	}
}

// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
	memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}


static void lcm_get_params(LCM_PARAMS *params)
{
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type   = LCM_TYPE_DSI;

	params->width  = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;

#if (LCM_DSI_CMD_MODE)
	params->dsi.mode   = CMD_MODE;
#else
	params->dsi.mode   = SYNC_EVENT_VDO_MODE;       //SYNC_EVENT_VDO_MODE;
#endif

	// DSI
	/* Command mode setting */
	// Three lane or Four lane
	params->dsi.LANE_NUM                                = LCM_FOUR_LANE;

	//The following defined the fomat for data coming from LCD engine.
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

	// Highly depends on LCD driver capability.
	// Not support in MT6573
	params->dsi.packet_size=256;

	// Video mode setting
	params->dsi.intermediat_buffer_num = 0;

	params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;
	params->dsi.word_count=FRAME_WIDTH*3;

	params->dsi.vertical_sync_active                = 2;//10;
	params->dsi.vertical_backporch                  = 15;//20;
	params->dsi.vertical_frontporch                 = 60;//20;/*modified by mtk*/
	params->dsi.vertical_active_line                = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active              = 2;//20;
	params->dsi.horizontal_backporch                = 60;//80;
	params->dsi.horizontal_frontporch               = 80;//80;
	params->dsi.horizontal_active_pixel             = FRAME_WIDTH;

	params->dsi.ssc_disable                         = 1;
	params->dsi.PLL_CLOCK = 455;
	params->dsi.cont_clock= 1;

}

static void lcm_set_gpio_output(unsigned int GPIO, unsigned int output)
{
	mt_set_gpio_mode(GPIO, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO, (output>0)? GPIO_OUT_ONE: GPIO_OUT_ZERO);
}

static void lcm_init_power(void)
{
#ifdef BUILD_LK
	printf("[LK/LCM] lcm_init_power() enter\n");
	//lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ONE);
	//MDELAY(10);
	//pmic_set_register_value(PMIC_RG_VGP1_VOSEL,0x7);
	//mt6392_upmu_set_rg_vgp2_vosel(7);
	mt6392_upmu_set_rg_vgp2_vosel(3);
	mt6392_upmu_set_rg_vgp2_en(0x1);
#else
	printk("[Kernel/LCM] lcm_init_power() enter\n");
	//lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ONE);
	//MDELAY(10);
	hwPowerOn(MT6328_POWER_LDO_VGP1, VOL_3300, "LCM_DRV");

#endif



}

static void lcm_suspend_power(void)
{
#ifdef BUILD_LK
	printf("[LK/LCM] lcm_suspend_power() enter\n");
	//lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ZERO);
	//MDELAY(10);
	//pmic_set_register_value(PMIC_RG_VGP1_VOSEL,0);
	mt6392_upmu_set_rg_vgp2_vosel(3);
	mt6392_upmu_set_rg_vgp2_en(0x0);

#else
	printk("[Kernel/LCM] lcm_suspend_power() enter\n");
	//lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ZERO);
	//MDELAY(20);
	hwPowerDown(MT6328_POWER_LDO_VGP1, "LCM_DRV");



#endif
}

static void lcm_resume_power(void)
{
#ifdef BUILD_LK
	printf("[LK/LCM] lcm_resume_power() enter\n");
	//lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ONE);
	//MDELAY(10);
	//pmic_set_register_value(PMIC_RG_VGP1_VOSEL,0x7);
	mt6392_upmu_set_rg_vgp2_vosel(3);
	mt6392_upmu_set_rg_vgp2_en(0x1);
#else
	printk("[Kernel/LCM] lcm_resume_power() enter\n");
	//lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ONE);
	//MDELAY(10);
	hwPowerOn(MT6328_POWER_LDO_VGP1, VOL_3300, "LCM_DRV");

#endif
}


static void init_lcm_registers(void)
{
	unsigned int data_array[16];

#ifdef BUILD_LK
	printf("%s, LK \n", __func__);
#else
	printk("%s, kernel", __func__);
#endif

	//data_array[0] = 0x00110500;  //software reset
	//dsi_set_cmdq(data_array, 1, 1);
	MDELAY(10);
	//DSI_clk_HS_mode(1);
	MDELAY(80);

	//data_array[0] = 0x00290500;  //display on
	//dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00003200;  //display on
	dsi_set_cmdq(data_array, 1, 1);


}
static void lcm_init(void)
{
#ifdef BUILD_LK
	printf("[LK/LCM] lcm_init() enter\n");
	//lcm_set_gpio_output(59, GPIO_OUT_ONE);
	lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ONE);
#if 0 //Neostra lixiaolong add for lcm reset change to gpio63
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(5);
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ZERO);
	MDELAY(50);
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(5);
#else
	SET_RESET_PIN(1);
	MDELAY(10);

	SET_RESET_PIN(0);
	MDELAY(10);

	SET_RESET_PIN(1);
	MDELAY(10);
#endif

	MDELAY(10);

	mt6392_upmu_set_rg_vgp2_vosel(3);
	mt6392_upmu_set_rg_vgp2_en(0x1);
	MDELAY(10);

	// when phone initial , config output high, enable backlight drv chip
	//push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);

	init_lcm_registers();


	printf("[LK/LCM] lcm_init() end\n");
#else
	printk("[LK/LCM] lcm_init() enter\n");
	lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ONE);
#if 0 //Neostra lixiaolong add for lcm reset change to gpio63
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(5);
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ZERO);
	MDELAY(50);
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(5);
#else
	SET_RESET_PIN(1);
	MDELAY(10);

	SET_RESET_PIN(0);
	MDELAY(10);

	SET_RESET_PIN(1);
	MDELAY(10);
#endif

	MDELAY(10);

	hwPowerOn(MT6328_POWER_LDO_VGP1, VOL_3300, "LCM_DRV");
	MDELAY(10);

	// when phone initial , config output high, enable backlight drv chip
	//push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);

	init_lcm_registers();



	printk("[Kernel/LCM] lcm_init() enter\n");

#endif


}


static void lcm_suspend(void)
{
#ifdef BUILD_LK
	printf("[LK/LCM] lcm_suspend() enter\n");


	push_table(lcm_suspend_setting, sizeof(lcm_suspend_setting) / sizeof(struct LCM_setting_table), 1);

	//SET_RESET_PIN(0);
	MDELAY(10);

	lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ZERO);
	MDELAY(10);

	mt6392_upmu_set_rg_vgp2_vosel(3);
	mt6392_upmu_set_rg_vgp2_en(0x0);
	MDELAY(10);
#else
	printk("[Kernel/LCM] lcm_suspend() enter\n");


	push_table(lcm_suspend_setting, sizeof(lcm_suspend_setting) / sizeof(struct LCM_setting_table), 1);

	//SET_RESET_PIN(0);
	MDELAY(10);
	lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ZERO);
	MDELAY(10);

	hwPowerDown(MT6328_POWER_LDO_VGP1, "LCM_DRV");
	MDELAY(10);
	printk("[Kernel/LCM] lcm_suspend() end\n");

#endif

}

static void lcm_resume(void)
{
//	lcm_init();
	lcm_set_gpio_output(GPIO_LCD_PWR_EN, 1);
#if 0 //Neostra lixiaolong add for lcm reset change to gpio63
	lcm_set_gpio_output(GPIO_LCD_RST, 1);
	MDELAY(5);
	lcm_set_gpio_output(GPIO_LCD_RST, 0);
	MDELAY(50);
	lcm_set_gpio_output(GPIO_LCD_RST, 1);
	MDELAY(5);
#else
	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(10);
	SET_RESET_PIN(1);
	MDELAY(20);
#endif
	push_table(lcm_sleep_out_setting,
	           sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);
//	init_lcm_registers();


}

#if (LCM_DSI_CMD_MODE)
static void lcm_update(unsigned int x, unsigned int y,
                       unsigned int width, unsigned int height)
{
	unsigned int x0 = x;
	unsigned int y0 = y;
	unsigned int x1 = x0 + width - 1;
	unsigned int y1 = y0 + height - 1;

	unsigned char x0_MSB = ((x0>>8)&0xFF);
	unsigned char x0_LSB = (x0&0xFF);
	unsigned char x1_MSB = ((x1>>8)&0xFF);
	unsigned char x1_LSB = (x1&0xFF);
	unsigned char y0_MSB = ((y0>>8)&0xFF);
	unsigned char y0_LSB = (y0&0xFF);
	unsigned char y1_MSB = ((y1>>8)&0xFF);
	unsigned char y1_LSB = (y1&0xFF);

	unsigned int data_array[16];

	data_array[0]= 0x00053902;
	data_array[1]= (x1_MSB<<24)|(x0_LSB<<16)|(x0_MSB<<8)|0x2a;
	data_array[2]= (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0]= 0x00053902;
	data_array[1]= (y1_MSB<<24)|(y0_LSB<<16)|(y0_MSB<<8)|0x2b;
	data_array[2]= (y1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0]= 0x002c3909;
	dsi_set_cmdq(data_array, 1, 0);

}
#endif

static unsigned int lcm_compare_id(void)
{
	unsigned int data_array[16];
	char  buffer[3];
	lcm_init();

	data_array[0] = 0x00043902;
	data_array[1] = 0x9483FFB9;
	dsi_set_cmdq(&data_array, 2, 1);
	MDELAY(10);

	data_array[0] = 0x00033902;
	data_array[1]=0x008331BA;
	dsi_set_cmdq(&data_array, 2, 1);
	MDELAY(10);

	data_array[0] = 0x00033700;// read id return 3 byte
	dsi_set_cmdq(data_array, 1, 1);
	read_reg_v2(0xa1, buffer, 3);

	printf("lcm_compare_id_1287 enter\n");
#ifdef BUILD_LK
	printf("%s, =======zhangyx==== nt71397 id = %x\n", __func__, (((buffer[0]<<8)&0xff00)|(buffer[1]&0xff)));
#endif
	printf("%s, =======zhangyx====nt71397 buffer[0] id = %x\n", __func__, buffer[0]);
	printf("%s, =======zhangyx====nt71397 buffer[1] id = %x\n", __func__, buffer[1]);
	printf("%s, =======zhangyx====nt71397 buffer[2] id = %x\n", __func__, buffer[2]);
	printf("%s, =======zhangyx====nt71397 buffer[3] id = %x\n", __func__, buffer[3]);
//	if(0x8394==(((buffer[0]<<8)&0xff00)|(buffer[1]&0xff)))
	if ((0x01==buffer[0])&&(0x8b==buffer[1])) {
#ifdef BUILD_LK
		printf("======zhangyx=====nt71397  compare id ok!!\n");
#endif
		return 1;
	} else
		return 0;
}
static unsigned int lcm_esd_check(void)
{
#ifndef BUILD_LK
	unsigned char buffer[1];
	unsigned int data_array[16];
#ifdef BUILD_LK
	printf("[cabc] nt71397: lcm_esd_check enter\n");
#else
	printk("[cabc] nt71397: lcm_esd_check enter\n");
#endif

	data_array[0] = 0x00013700;// read id return two byte,version and id
	dsi_set_cmdq(data_array, 1, 1);
//	id = read_reg(0xF4);
	read_reg_v2(0x0A, buffer, 1);
#ifdef BUILD_LK
	printf("lcm_esd_check  0x0A = %x\n",buffer[0]);
#else
	printk("lcm_esd_check  0x0A = %x\n",buffer[0]);
#endif
	if (buffer[0] != 0x9C) {
		return 1;
	}

	data_array[0] = 0x00013700;// read id return two byte,version and id
	dsi_set_cmdq(data_array, 1, 1);
//	id = read_reg(0xF4);
	read_reg_v2(0x0D, buffer, 1);
#ifdef BUILD_LK
	printf("lcm_esd_check 0x0D =%x\n",buffer[0]);
#else
	printk("lcm_esd_check 0x0D =%x\n",buffer[0]);
#endif
	if (buffer[0] != 0x00) {
		return 1;
	}
	data_array[0] = 0x00013700;// read id return two byte,version and id
	dsi_set_cmdq(data_array, 1, 1);
//	id = read_reg(0xF4);
	read_reg_v2(0x0E, buffer, 1);
#ifdef BUILD_LK
	printf("lcm_esd_check  0x0E = %x\n",buffer[0]);
#else
	printk("lcm_esd_check  0x0E = %x\n",buffer[0]);
#endif
	if (buffer[0] != 0x80) {
		return 1;
	}

#ifdef BUILD_LK
	printf("[cabc] nt71397: lcm_esd_check exit\n");
#else
	printk("[cabc] nt71397: lcm_esd_check exit\n");
#endif

	return 0;
#endif
}
static unsigned int lcm_esd_recover(void)
{
	unsigned int data_array[16];

#ifdef BUILD_LK
	printf("lcm_esd_recover enter");
#else
	printk("lcm_esd_recover enter");
#endif

	lcm_init();
	data_array[0]=0x00110500;
	dsi_set_cmdq(&data_array, 1, 1);
	MDELAY(50);

	data_array[0]=0x00290500;
	dsi_set_cmdq(&data_array, 1, 1);

	data_array[0]= 0x00023902;
	data_array[1]= 0xFF51;
	dsi_set_cmdq(&data_array, 2, 1);
	MDELAY(10);

	return TRUE;
}
#if 0
static unsigned int lcm_esd_check(void)
{
#ifndef BUILD_LK
	char  buffer;

	if (lcm_esd_test) {
		lcm_esd_test = FALSE;
		return TRUE;
	}


	read_reg_v2(0x0a, &buffer, 1);
	printk("%s, kernel debug: reg = 0x%08x\n", __func__, buffer);

	return FALSE;

#else
	return FALSE;
#endif

}

static unsigned int lcm_esd_recover(void)
{
	lcm_init();

	return TRUE;
}
#endif

LCM_DRIVER nt71397_wuxga_dsi_vdo_nt65902_lcm_drv = {
	.name           = "nt71397_wuxga_dsi_vdo_nt65902",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	.init_power = lcm_init_power,
	.resume_power  = lcm_resume_power,
	.suspend_power = lcm_suspend_power,
};
