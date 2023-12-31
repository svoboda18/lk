/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2015. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

#define LOG_TAG "LCM"

#ifndef BUILD_LK
#  include <linux/string.h>
#  include <linux/kernel.h>
#endif

#include "lcm_drv.h"
#include "lcm_util.h"

#ifdef MTK_ROUND_CORNER_SUPPORT
#include "data_hw_roundedpattern.h"
#endif

#ifdef BUILD_LK
#  include <platform/upmu_common.h>
#  include <platform/mt_gpio.h>
#  include <platform/mt_i2c.h>
#  include <platform/mt_pmic.h>
#  include <string.h>
#  ifndef MACH_FPGA
#    include <lcm_pmic.h>
#  endif
#elif defined(BUILD_UBOOT)
#  include <asm/arch/mt_gpio.h>
#else
#  include <mach/mt_pm_ldo.h>
#  include <mach/mt_gpio.h>
#endif

#include <platform/mt_i2c.h>
#include <libfdt.h>

#ifdef BUILD_LK
#  define LCM_LOGI(string, args...)  dprintf(0, "[LK/"LOG_TAG"]"string, ##args)
#  define LCM_LOGD(string, args...)  dprintf(1, "[LK/"LOG_TAG"]"string, ##args)
#else
#  define LCM_LOGI(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#  define LCM_LOGD(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#endif


static LCM_UTIL_FUNCS lcm_util;

#define SET_RESET_PIN(v)	(lcm_util.set_reset_pin((v)))
#define MDELAY(n)		(lcm_util.mdelay(n))
#define UDELAY(n)		(lcm_util.udelay(n))

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update) \
		lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update) \
		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd) lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums) \
		lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)	lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size) \
		lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)

#ifndef BUILD_LK
#  include <linux/kernel.h>
#  include <linux/module.h>
#  include <linux/fs.h>
#  include <linux/slab.h>
#  include <linux/init.h>
#  include <linux/list.h>
#  include <linux/i2c.h>
#  include <linux/irq.h>
#  include <linux/uaccess.h>
#  include <linux/interrupt.h>
#  include <linux/io.h>
#  include <linux/platform_device.h>
#endif

#define FRAME_WIDTH			(1080)
#define FRAME_HEIGHT			(1920)

#define VIRTUAL_WIDTH		(1080)
#define VIRTUAL_HEIGHT	(2160)
#define REGFLAG_DELAY			0xFFFC
#define REGFLAG_UDELAY			0xFFFB
#define REGFLAG_END_OF_TABLE		0xFFFD
#define REGFLAG_RESET_LOW		0xFFFE
#define REGFLAG_RESET_HIGH		0xFFFF

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/* i2c control start */
#define LCM_I2C_MODE    ST_MODE
#define LCM_I2C_SPEED   100
#define LCM_ID_OTM1911A 0x40

static struct mt_i2c_t tps65132_i2c;
static int _lcm_i2c_write_bytes(kal_uint8 addr, kal_uint8 value)
{
	kal_int32 ret_code = I2C_OK;
	kal_uint8 write_data[2];
	kal_uint16 len;
	int id, i2c_addr;

	write_data[0] = addr;
	write_data[1] = value;

	if (lcm_util_get_i2c_lcd_bias(&id, &i2c_addr) < 0)
		return -1;
	tps65132_i2c.id = (U16)id;
	tps65132_i2c.addr = (U16)i2c_addr;
	tps65132_i2c.mode = LCM_I2C_MODE;
	tps65132_i2c.speed = LCM_I2C_SPEED;
	len = 2;

	ret_code = i2c_write(&tps65132_i2c, write_data, len);
	if (ret_code<0)
		dprintf(0, "[LCM][ERROR] %s: %d\n", __func__, ret_code);

	return ret_code;
}

/* i2c control end */

struct LCM_setting_table {
	unsigned int cmd;
	unsigned char count;
	unsigned char para_list[64];
};

static struct LCM_setting_table lcm_suspend_setting[] = {
	{0x28, 0, {} },
	{REGFLAG_DELAY, 20, {} },
	{0x10, 0, {} },
	{REGFLAG_DELAY, 120, {} },
};

static struct LCM_setting_table init_setting_vdo[] = {
//OOTM1911A_H565DAN01_0F_inital_TypeB1_V2.0
		{0x00, 0x1, {0x00} },
		{0xFF, 0x3, {0x19, 0x11, 0x01} },

		{0x00, 0x1, {0x80} },
		{0xFF, 0x2, {0x19, 0x11} },
			//RTN=81 @ normal display //0x49 RTN=74
		{0x00, 0x1, {0x80} },
		{0xC0, 0x7, {0x51,0x00,0x08,0x08,0x51,0x04,0x00}},//TCON RTN Setting


		{0x00, 0x1, {0x92}},
		{0xB3, 0x2,{0x18,0x06}},//Panel Mode,  swap G / 0xB392[1] = 1 , Enable SW Resolution setting

		{0x00, 0x1,{0x8B}},
		{0xC0, 0x1,{0x88}},//Panel Driving Mode	 //0x88
		{0x00, 0x1,{0xb0}},
		{0xB3, 0x4,{0x04,0x38,0x08,0x70}},//1080RGBx2160
		//vst
		{0x00, 0x1, {0x80} },
		{0xc2, 0x4,{0x84,0x01,0x33,0x34}},//vst1
		{0x00, 0x1, {0x84} },

		{0xc2, 0x2,{0x00,0x00}},//vst2

		//ckv
		{0x00 ,0x1,{0xb0}},
		{0xc2, 0xE,{0x85,0x05,0x11,0x09,0x00,0x85,0x02,0x22,0x85,0x03,0x33,0x85,0x04,0x00}},
		//ckv1 + ckv2 + ckv3 + ckv4
		{0x00, 0x1,{0xc0}},
		{0xc2, 0xE,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
		//ckv5 + ckv6 + ckv7 + ckv8
		{0x00, 0x1,{0xd0}},
		{0xc2, 0x5,{0x33,0x33,0x00,0x00,0xf0}},//ckv period

		//vend
		{0x00, 0x1,{0xE0}},
		{0xc2, 0x6,{0x02,0x01,0x09,0x07,0x00,0x00}},

		//rst
		{0x00, 0x1,{0xF0}},
		{0xc2, 0x5,{0x80,0xff,0x01,0x08,0x07}},
		//cic
		{0x00, 0x1,{0x90}},
		{0xc2, 0xB,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

		//pch
		{0x00, 0x1,{0xA2}},
		{0xC5, 0x1,{0x00}},

		//pwron/pwrof/lvd
		{0x00, 0x1,{0x90}},
		{0xcb, 0x3,{0x00,0x00,0x00}},

		{0x00, 0x1,{0xc0}},
		{0xcb, 0xC,{0x04,0x04,0x04,0xf4,0x00,0x00,0x04,0x00,0x04,0x00,0x00,0x00}},

		{0x00, 0x1,{0xf0}},// elvin
		{0xcb, 0x4,{0xff,0x30,0x33,0x80}},

		{0x00, 0x1,{0x80}},
		{0xcd, 0x1,{0x01}},//map_sel

		//ckh
		{0x00, 0x1,{0x94}},
		{0xc0, 0x7,{0x00,0x01,0x06,0x00,0x01,0x15,0x05}},//170728 best for pixel column inv.

		{0x00, 0x1,{0x0}},
		{0xD8, 0x2,{0x2B,0x2B}},//GVDDP/GVDDN  0x25=+/-4.7V  0x2B=+/-5.0V

		{0x00, 0x1,{0x00}},//For K16, Vcom by OTP
		{0xD9, 0x2,{0xAD,0x00}},//VCOM=-0.27V

		{0x00, 0x1,{0x00}},
		{0xE0, 0x1,{0x01}},//Gamma Separate Change

//170929-2 foc to2.2
		{0x00, 0x1,{0x00}},
		{0xE1, 0x25,{0x5c,0x88,0xdd,0x13,0x40,0x49,0x72,0xb5,0xe4,0x55,0xca,0xf6,0x1c,0x39,0xa5,0x5c,0x7a,0xe9,0x08,0x9a,0x24,0x42,0x5d,0x7f,0xaa,0xa7,0xaa,0xd9,0x18,0xea,0x3d,0x60,0x9b,0xe3,0xff,0xf4,0x03}},
		//R POS
		{0x00, 0x1,{0x00}},
		{0xE2, 0x25,{0x47,0x88,0xdd,0x13,0x40,0x49,0x72,0xb5,0xe4,0x55,0xca,0xf6,0x1c,0x39,0xa5,0x5c,0x7a,0xe9,0x08,0x9a,0x24,0x42,0x5d,0x7f,0xaa,0xa7,0xaa,0xd9,0x18,0xea,0x3d,0x60,0x9b,0xe3,0xff,0xc4,0x03}},
		//R NEG
		{0x00, 0x1,{0x00}},
		{0xE3, 0x25,{0x5c,0x86,0xdb,0x2a,0x40,0x4f,0x7a,0xb9,0xea,0x55,0xd1,0xfb,0x1f,0x3d,0xa5,0x5e,0x7e,0xed,0x0a,0x9a,0x26,0x45,0x60,0x81,0xaa,0xaa,0xad,0xda,0x17,0xea,0x3c,0x5f,0x9c,0xe4,0xff,0xf4,0x03}},
		//G POS
		{0x00, 0x1,{0x00}},
		{0xE4, 0x25,{0x47,0x86,0xdb,0x2a,0x40,0x4f,0x7a,0xb9,0xea,0x55,0xd1,0xfb,0x1f,0x3d,0xa5,0x5e,0x7e,0xed,0x0a,0x9a,0x26,0x45,0x60,0x81,0xaa,0xaa,0xad,0xda,0x17,0xea,0x3c,0x5f,0x9c,0xe4,0xff,0xc4,0x03}},
		//G NEG
		{0x00, 0x1,{0x00}},
		{0xE5, 0x25,{0x5c,0x9f,0x01,0x46,0x50,0x6c,0x92,0xce,0xfb,0x55,0xe1,0x08,0x2a,0x47,0xa9,0x67,0x84,0xf2,0x0e,0x9a,0x2b,0x49,0x64,0x85,0xaa,0xad,0xb3,0xe4,0x20,0xea,0x43,0x66,0xa0,0xe6,0xff,0xf4,0x03}},
		//B POS
		{0x00, 0x1,{0x00}},
		{0xE6, 0x25,{0x47,0x9f,0x01,0x46,0x50,0x6c,0x92,0xce,0xfb,0x55,0xe1,0x08,0x2a,0x47,0xa9,0x67,0x84,0xf2,0x0e,0x9a,0x2b,0x49,0x64,0x85,0xaa,0xad,0xb3,0xe4,0x20,0xea,0x43,0x66,0xa0,0xe6,0xff,0xc4,0x03}},
		//B POS
//Gamma_End--------------------------
		//--------Down Power  Consumption-----------------

		{0x00, 0x1,{0x90}},
		{0xC5, 0x1,{0x45}},//GAP 8->4 ; AP 8->5, 20160420 For Power Saving Setting Modify

		{0x00, 0x1,{0x91}},
		{0xC5, 0x1,{0xA0}},//SAP 8->A, 20160524 For special pattern horizontal band

		//{0x39, 0, 0, 0, 0, 2,{0x00,0x81}},//VGH  0x05=AVDD*2(default)     0x0F=AVDD*2-AVEE
		//{0x39, 0, 0, 0, 0, 2,{0xC5,0x0F}},

		{0x00, 0x1,{0x83}},//VGH=8.8V  VGH Clamp off
		{0xC5, 0x1,{0x1B}},

		{0x00, 0x1,{0x84}},//VGL  0xAE=-8.6V,  0xC6=-11V
		{0xC5, 0x1,{0xAE}},

		{0x00, 0x1,{0xA0}},//VGHO  0x98=8.5V,  0xAC=10.5V,   0x84=6.5V
		{0xC5, 0x1,{0x98}},

		{0x00, 0x1,{0xA1}},//VGLO  0xA8=-8.0V, 0xBC=-10V,    0x94=-6V
		{0xC5, 0x1,{0xA8}},

		//*******Initial code Fine Tune******

		{0x00, 0x1,{0x90}},
		{0xC3, 0x4,{0x00,0x00,0x00,0x00}},

		{0x00, 0x1,{0x86}},
		{0xC3, 0x1,{0x00}},

		{0x00, 0x1,{0x91}},
		{0xC1, 0x1,{0x0F}},//timeout open

		{0x00, 0x1,{0x80}},
		{0xC4, 0x1,{0x01}},//Source v-blank output min.

		{0x00, 0x1,{0x81}},
		{0xC4, 0x1,{0x02}},//Chop 2line/2frame

		{0x00, 0x1,{0xB1}},
		{0xC5, 0x1,{0x08}},//Gamma Calibration control disable

		{0x00, 0x1,{0xB2}},//Gamma chop = 2line/2frame
		{0xC5, 0x1,{0x22}},

		{0x00, 0x1,{0x80}},
		{0xC3, 0x8,{0x00,0x00,0x00,0x22,0x22,0x00,0x22,0x22}},//gnd eq

		{0x00, 0x1,{0x90}},
		{0xC3, 0x4,{0x20,0x20,0x02,0x02}},//VSP_VSN EQ

//		{0x15, 0, 0, 0, 0, 2,{0x00,0x90}},
//		{0x15, 0, 0, 0, 0, 2,{0xC5,0x80}},//sap

		{0x00, 0x1,{0x92}},
		{0xC5, 0x1,{0x33}},//vdd lvdsvdd //EMI improving

		{0x00, 0x1,{0x81}},
		{0xC1, 0x3,{0xB0,0xC0,0xF0}},//SSC //EMI improving
		 // 20170731 update follow H593 discharge source

		{0x00, 0x1,{0x89}},
		{0xc0, 0x2,{0x10,0x14}},

		{0x00, 0x1,{0x90}},
		{0xcb, 0x3,{0x00,0x00,0x0C}},

		{0x00, 0x1,{0xC0}},
		{0xcb, 0xC,{0x05,0x04,0x04,0xf4,0x00,0x00,0x04,0x00,0x04,0xf3,0x00,0x00}},

		{0x00, 0x1,{0xF0}},
		{0xcb, 0x4,{0xff,0x30,0x33,0x80}},

		{0x00, 0x1,{0x84}},
		{0xF5, 0x1,{0x9A}},//Vcom active region

		//TE with mode 1
		{0x35, 0x1,{0x00}},
		//PWM BL
		{0x51, 0x1,{0xFC}}, //4B=6mA,0C=1mA
		{0x53, 0x1,{0x24}},
		{0x55, 0x1,{0x10}},

		//Sleep Out
		{0x11, 0, {} },
		{REGFLAG_DELAY, 120, {} },
		//Display On
		{0x29, 0, {} },

		{REGFLAG_DELAY, 20, {} },

#if 0
#ifndef LCM_SET_DISPLAY_ON_DELAY
	{REGFLAG_DELAY, 150, {} },

	{0xE9, 0x01, {0xC2} },
	{0xB0, 0x01, {0x01} },
	{0xE9, 0x01, {0x00} },

	{0x29, 0, {} },
	{REGFLAG_DELAY, 50, {} },
#endif
#endif
};

#ifdef LCM_SET_DISPLAY_ON_DELAY
/* to reduce init time, we move 120ms delay to lcm_set_display_on() !! */
static struct LCM_setting_table set_display_on[] = {
	{0xE9, 0x01, {0xC2} },
	{0xB0, 0x01, {0x01} },
	{0xE9, 0x01, {0x00} },

	{0x29, 0, {} },
	{REGFLAG_DELAY, 50, {} },
};
#endif

static struct LCM_setting_table bl_level[] = {
	{0x51, 1, {0xFF} },
	{REGFLAG_END_OF_TABLE, 0x00, {} }
};

static void push_table(struct LCM_setting_table *table, unsigned int count,
		       unsigned char force_update)
{
	unsigned int i;
	unsigned int cmd;

	for (i = 0; i < count; i++) {
		cmd = table[i].cmd;
		switch (cmd) {
		case REGFLAG_DELAY:
			if (table[i].count <= 10)
				MDELAY(table[i].count);
			else
				MDELAY(table[i].count);
			break;
		case REGFLAG_UDELAY:
			UDELAY(table[i].count);
			break;
		case REGFLAG_END_OF_TABLE:
			break;
		default:
			dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list,
					force_update);
			break;
		}
	}
}

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
	memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}

static void lcm_get_params(LCM_PARAMS *params)
{
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type = LCM_TYPE_DSI;

	params->width = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;
	params->virtual_width = VIRTUAL_WIDTH;
	params->virtual_height = VIRTUAL_HEIGHT;
	params->dsi.mode = SYNC_PULSE_VDO_MODE;
	params->dsi.switch_mode = CMD_MODE;
	params->dsi.switch_mode_enable = 0;

	/* DSI */
	/* Command mode setting */
	params->dsi.LANE_NUM = LCM_FOUR_LANE;
	/* The following defined the fomat for data coming from LCD engine. */
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format = LCM_DSI_FORMAT_RGB888;

	/* Highly depends on LCD driver capability. */
	params->dsi.packet_size = 256;
	/* video mode timing */

	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;

	params->dsi.vertical_sync_active = 3;
	params->dsi.vertical_backporch = 15;
	params->dsi.vertical_frontporch = 10;
	params->dsi.vertical_frontporch_for_low_power = 750;//OTM no data
	params->dsi.vertical_active_line = VIRTUAL_HEIGHT;

	params->dsi.horizontal_sync_active = 10;
	params->dsi.horizontal_backporch = 42;
	params->dsi.horizontal_frontporch = 42;
	params->dsi.horizontal_active_pixel = VIRTUAL_WIDTH;
	/* params->dsi.ssc_disable = 1; */
#ifndef MACH_FPGA
	/* this value must be in MTK suggested table */
	params->dsi.PLL_CLOCK = 497;
#else
	params->dsi.pll_div1 = 0;
	params->dsi.pll_div2 = 0;
	params->dsi.fbk_div = 0x1;
#endif
	params->dsi.CLK_HS_POST = 36;
	params->dsi.clk_lp_per_line_enable = 0;
	params->dsi.esd_check_enable = 0;
	params->dsi.customization_esd_check_enable = 0;
	params->dsi.lcm_esd_check_table[0].cmd = 0x0a;
	params->dsi.lcm_esd_check_table[0].count = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9d;

#ifdef MTK_ROUND_CORNER_SUPPORT
	params->round_corner_params.round_corner_en = 1;
	params->round_corner_params.full_content = 0;
	params->round_corner_params.h = ROUND_CORNER_H_TOP;
	params->round_corner_params.h_bot = ROUND_CORNER_H_BOT;
	params->round_corner_params.tp_size = sizeof(top_rc_pattern);
	params->round_corner_params.lt_addr = (void *)top_rc_pattern;
#endif
}

/* turn on gate ic & control voltage to 5.5V */
static void lcm_init_power(void)
{
	if (lcm_util.set_gpio_lcd_enp_bias) {
		lcm_util.set_gpio_lcd_enp_bias(1);
		_lcm_i2c_write_bytes(0x0, 0xf);
		_lcm_i2c_write_bytes(0x1, 0xf);
	}
	else
		LCM_LOGI("set_gpio_lcd_enp_bias not defined\n");
}

static void lcm_suspend_power(void)
{
	SET_RESET_PIN(0);
	if (lcm_util.set_gpio_lcd_enp_bias)
		lcm_util.set_gpio_lcd_enp_bias(0);
	else
		LCM_LOGI("set_gpio_lcd_enp_bias not defined\n");
}

static void lcm_resume_power(void)
{
	SET_RESET_PIN(0);
	lcm_init_power();
}

#ifdef LCM_SET_DISPLAY_ON_DELAY
static U32 lcm_init_tick = 0;
static int is_display_on = 0;
#endif

static void lcm_init(void)
{
	SET_RESET_PIN(0);
	MDELAY(15);
	SET_RESET_PIN(1);
	MDELAY(1);

	SET_RESET_PIN(0);
	MDELAY(10);
	SET_RESET_PIN(1);
	MDELAY(10);



	push_table(init_setting_vdo, sizeof(init_setting_vdo) /
		   sizeof(struct LCM_setting_table), 1);

#ifdef LCM_SET_DISPLAY_ON_DELAY
	lcm_init_tick = gpt4_get_current_tick();
	is_display_on = 0;
#endif
}

#ifdef LCM_SET_DISPLAY_ON_DELAY
static int lcm_set_display_on(void)
{
	U32 timeout_tick, i = 0;

	if (is_display_on)
		return 0;

	/* we need to wait 150ms after lcm init to set display on */
	timeout_tick = gpt4_time2tick_ms(150);

	while (!gpt4_timeout_tick(lcm_init_tick, timeout_tick)) {
		i++;
		if (i % 1000 == 0) {
			LCM_LOGI("otm1911a %s error: i=%u,lcm_init_tick=%u,cur_tick=%u\n",
				 __func__, i, lcm_init_tick, gpt4_get_current_tick());
		}
	}

	push_table(set_display_on, sizeof(set_display_on) /
		   sizeof(struct LCM_setting_table), 1);

	is_display_on = 1;
	return 0;
}
#endif

static void lcm_suspend(void)
{
	push_table(lcm_suspend_setting, sizeof(lcm_suspend_setting) /
		   sizeof(struct LCM_setting_table), 1);

	SET_RESET_PIN(0);
	MDELAY(10);
}

static void lcm_resume(void)
{
	lcm_init();
}

#if 1
static void lcm_update(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
#ifdef LCM_SET_DISPLAY_ON_DELAY
	lcm_set_display_on();
#endif
}
#else
static void lcm_update(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
#ifdef LCM_SET_DISPLAY_ON_DELAY
	lcm_set_display_on();
#endif
}
#endif

static unsigned int lcm_ata_check(unsigned char *buffer)
{
#ifndef BUILD_LK
	unsigned int ret = 0;
	unsigned int x0 = FRAME_WIDTH / 4;
	unsigned int x1 = FRAME_WIDTH * 3 / 4;

	unsigned char x0_MSB = ((x0 >> 8) & 0xFF);
	unsigned char x0_LSB = (x0 & 0xFF);
	unsigned char x1_MSB = ((x1 >> 8) & 0xFF);
	unsigned char x1_LSB = (x1 & 0xFF);

	unsigned int data_array[3];
	unsigned char read_buf[4];

	LCM_LOGI("ATA check size = 0x%x,0x%x,0x%x,0x%x\n",
		 x0_MSB, x0_LSB, x1_MSB, x1_LSB);
	data_array[0] = 0x0005390A; /* HS packet */
	data_array[1] = (x1_MSB << 24) | (x0_LSB << 16) | (x0_MSB << 8) | 0x2a;
	data_array[2] = (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x00043700; /* read id return two byte,version and id */
	dsi_set_cmdq(data_array, 1, 1);

	read_reg_v2(0x2A, read_buf, 4);

	if ((read_buf[0] == x0_MSB) && (read_buf[1] == x0_LSB) &&
	    (read_buf[2] == x1_MSB) && (read_buf[3] == x1_LSB))
		ret = 1;
	else
		ret = 0;

	x0 = 0;
	x1 = FRAME_WIDTH - 1;

	x0_MSB = ((x0 >> 8) & 0xFF);
	x0_LSB = (x0 & 0xFF);
	x1_MSB = ((x1 >> 8) & 0xFF);
	x1_LSB = (x1 & 0xFF);

	data_array[0] = 0x0005390A; /* HS packet */
	data_array[1] = (x1_MSB << 24) | (x0_LSB << 16) | (x0_MSB << 8) | 0x2a;
	data_array[2] = (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);
	return ret;
#else
	return 0;
#endif
}

static void lcm_setbacklight_cmdq(void *handle, unsigned int level)
{
	LCM_LOGI("%s,otm1911a backlight: level = %d\n", __func__, level);

	bl_level[0].para_list[0] = level;

	push_table(bl_level, sizeof(bl_level) /
		   sizeof(struct LCM_setting_table), 1);
}

static void lcm_setbacklight(unsigned int level)
{
	LCM_LOGI("%s,otm1911a backlight: level = %d\n", __func__, level);

	bl_level[0].para_list[0] = level;

	push_table(bl_level, sizeof(bl_level) /
		   sizeof(struct LCM_setting_table), 1);
}

static unsigned int lcm_compare_id(void)
{
	unsigned int id = 0;
	unsigned char buffer[1];
	unsigned int array[16];

	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);

	SET_RESET_PIN(1);
	MDELAY(20);

	array[0] = 0x00013700;  /* read id return 1byte */
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0xDA, buffer, 1);
	id = buffer[0];

	LCM_LOGI("%s,otm1911a id = 0x%08x\n", __func__, id);

	if (id == LCM_ID_OTM1911A)
		return 1;
	else
		return 0;

}

LCM_DRIVER otm1911a_fhdp_dsi_vdo_fhd_truly_rt4801_lcm_drv = {
	.name = "otm1911a_fhdp_dsi_vdo_fhd_truly_rt4801_drv",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,
	.resume_power = lcm_resume_power,
	.suspend_power = lcm_suspend_power,
	.set_backlight = lcm_setbacklight,
	.ata_check = lcm_ata_check,
	.update = lcm_update,
};

