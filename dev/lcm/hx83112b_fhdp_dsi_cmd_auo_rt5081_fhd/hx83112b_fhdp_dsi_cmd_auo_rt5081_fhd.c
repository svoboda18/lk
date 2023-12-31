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

#define REGFLAG_DELAY			0xFFFC
#define REGFLAG_UDELAY			0xFFFB
#define REGFLAG_END_OF_TABLE		0xFFFD
#define REGFLAG_RESET_LOW		0xFFFE
#define REGFLAG_RESET_HIGH		0xFFFF

#ifndef TRUE
#define TRUE 1
#endif

#define LCM_ID_HX83112B 0x83

#ifndef FALSE
#define FALSE 0
#endif

struct LCM_setting_table {
	unsigned int cmd;
	unsigned char count;
	unsigned char para_list[64];
};

static struct LCM_setting_table lcm_suspend_setting[] = {
	{0x28, 0, {} },
	{REGFLAG_DELAY, 50, {} },
	{0x10, 0, {} },
	{REGFLAG_DELAY, 150, {} },
};

static struct LCM_setting_table init_setting_cmd[] = {
	{0xB9, 0x03, {0x83, 0x11, 0x2B} },
	{0xB1, 0x0A, {0xF8, 0x29, 0x29, 0x00, 0x00, 0x0F, 0x14, 0x0F,
		      0x14, 0x33} },
	{0xD2, 0x02, {0x2C, 0x2C} },
	{0xB2, 0x0B, {0x80, 0x02, 0x00, 0x80, 0x70, 0x00, 0x08, 0x1C,
		      0x05, 0x01, 0x04} },
	{0xE9, 0x01, {0xD1} },
	{0xB2, 0x02, {0x00, 0x08} },
	{0xE9, 0x01, {0x00} },
	{0xE9, 0x01, {0xCE} },
	{0xB2, 0x01, {0xA3} },
	{0xE9, 0x01, {0x00} },
	{0xBD, 0x01, {0x02} },
	{0xB2, 0x02, {0xB5, 0x0A} },
	{0xBD, 0x01, {0x00} },
	{0xDD, 0x08, {0x00, 0x00, 0x08, 0x1C, 0x09, 0x34, 0x34, 0x8B} },
	{0xB4, 0x18, {0x01, 0xD3, 0x00, 0x00, 0x00, 0x00, 0x03, 0xD0,
		      0x00, 0x00, 0x0F, 0xCB, 0x01, 0x00, 0x00, 0x13,
		      0x00, 0x2E, 0x08, 0x01, 0x12, 0x00, 0x00, 0x2E} },
	{0xBD, 0x01, {0x02} },
	{0xB4, 0x01, {0x92} },
	{0xBD, 0x01, {0x00} },
	{0xB6, 0x03, {0x81, 0x81, 0xE3} },
	{0xC0, 0x01, {0x44} },
	{0xCC, 0x01, {0x08} },
	{0xBD, 0x01, {0x03} },
	{0xC1, 0x39, {0xFF, 0xFA, 0xF6, 0xF3, 0xEF, 0xEB, 0xE7, 0xE0,
		      0xDC, 0xD9, 0xD6, 0xD2, 0xCF, 0xCB, 0xC7, 0xC3,
		      0xBF, 0xBB, 0xB7, 0xB0, 0xA8, 0xA1, 0x9A, 0x92,
		      0x89, 0x81, 0x7A, 0x73, 0x6B, 0x63, 0x5A, 0x51,
		      0x48, 0x40, 0x38, 0x31, 0x29, 0x20, 0x16, 0x0D,
		      0x09, 0x07, 0x05, 0x02, 0x00, 0x08, 0x2E, 0xF6,
		      0x20, 0x18, 0x94, 0xF8, 0x6F, 0x59, 0x18, 0xFC,
		      0x00} },
	{0xBD, 0x01, {0x02} },
	{0xC1, 0x39, {0xFF, 0xFA, 0xF6, 0xF3, 0xEF, 0xEB, 0xE7, 0xE0,
		      0xDC, 0xD9, 0xD6, 0xD2, 0xCF, 0xCB, 0xC7, 0xC3,
		      0xBF, 0xBB, 0xB7, 0xB0, 0xA8, 0xA1, 0x9A, 0x92,
		      0x89, 0x81, 0x7A, 0x73, 0x6B, 0x63, 0x5A, 0x51,
		      0x48, 0x40, 0x38, 0x31, 0x29, 0x20, 0x16, 0x0D,
		      0x09, 0x07, 0x05, 0x02, 0x00, 0x08, 0x2E, 0xF6,
		      0x20, 0x18, 0x94, 0xF8, 0x6F, 0x59, 0x18, 0xFC,
		      0x00} },
	{0xBD, 0x01, {0x01} },
	{0xC1, 0x39, {0xFF, 0xFA, 0xF6, 0xF3, 0xEF, 0xEB, 0xE7, 0xE0,
		      0xDC, 0xD9, 0xD6, 0xD2, 0xCF, 0xCB, 0xC7, 0xC3,
		      0xBF, 0xBB, 0xB7, 0xB0, 0xA8, 0xA1, 0x9A, 0x92,
		      0x89, 0x81, 0x7A, 0x73, 0x6B, 0x63, 0x5A, 0x51,
		      0x48, 0x40, 0x38, 0x31, 0x29, 0x20, 0x16, 0x0D,
		      0x09, 0x07, 0x05, 0x02, 0x00, 0x08, 0x2E, 0xF6,
		      0x20, 0x18, 0x94, 0xF8, 0x6F, 0x59, 0x18, 0xFC,
		      0x00} },
	{0xBD, 0x01, {0x00} },
	{0xC1, 0x01, {0x01} },
	{0xD3, 0x16, {0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0A,
		      0x0A, 0x07, 0x00, 0x00, 0x08, 0x09, 0x09, 0x09,
		      0x09, 0x32, 0x10, 0x09, 0x00, 0x09} },
	{0xE9, 0x01, {0xE3} },
	{0xD3, 0x03, {0x05, 0x08, 0x86} },
	{0xE9, 0x01, {0x00} },
	{0xBD, 0x01, {0x01} },
	{0xE9, 0x01, {0xC8} },
	{0xD3, 0x01, {0x81} },
	{0xE9, 0x01, {0x00} },
	{0xBD, 0x01, {0x00} },
	{0xD5, 0x30, {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
		      0x31, 0x31, 0x30, 0x30, 0x2F, 0x2F, 0x31, 0x31,
		      0x30, 0x30, 0x2F, 0x2F, 0xC0, 0x18, 0x40, 0x40,
		      0x01, 0x00, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02,
		      0x21, 0x20, 0x18, 0x18, 0x19, 0x19, 0x18, 0x18,
		      0x03, 0x03, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18} },
	{0xD6, 0x30, {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
		      0x31, 0x31, 0x30, 0x30, 0x2F, 0x2F, 0x31, 0x31,
		      0x30, 0x30, 0x2F, 0x2F, 0xC0, 0x18, 0x40, 0x40,
		      0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x00, 0x01,
		      0x20, 0x21, 0x18, 0x18, 0x18, 0x18, 0x19, 0x19,
		      0x20, 0x20, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18} },
	{0xD8, 0x18, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
	{0xBD, 0x01, {0x01} },
	{0xD8, 0x18, {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA,
		      0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA,
		      0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA} },
	{0xBD, 0x01, {0x02} },
	{0xD8, 0x0C, {0xAF, 0xFF, 0xFA, 0xAA, 0xBA, 0xAA, 0xAA, 0xFF,
		      0xFA, 0xAA, 0xBA, 0xAA} },
	{0xBD, 0x01, {0x03} },
	{0xD8, 0x18, {0xAA, 0xAA, 0xAB, 0xAA, 0xAE, 0xAA, 0xAA, 0xAA,
		      0xAB, 0xAA, 0xAE, 0xAA, 0xAA, 0xFF, 0xFA, 0xAA,
		      0xBA, 0xAA, 0xAA, 0xFF, 0xFA, 0xAA, 0xBA, 0xAA} },
	{0xBD, 0x01, {0x00} },
	{0xE7, 0x19, {0x09, 0x09, 0x00, 0x07, 0xE6, 0x00, 0x27, 0x00,
		      0x07, 0x00, 0x00, 0xE6, 0x2A, 0x00, 0xE6, 0x00,
		      0x0A, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x12,
		      0x04} },
	{0xE9, 0x01, {0xE4} },
	{0xE7, 0x02, {0x17, 0x69} },
	{0xE9, 0x01, {0x00} },
	{0xBD, 0x01, {0x01} },
	{0xE7, 0x09, {0x02, 0x00, 0x01, 0x20, 0x01, 0x0E, 0x08, 0xEE,
		      0x09} },
	{0xBD, 0x01, {0x02} },
	{0xE7, 0x03, {0x20, 0x20, 0x00} },
	{0xBD, 0x01, {0x03} },
	{0xE7, 0x06, {0x00, 0x08, 0x01, 0x00, 0x00, 0x20} },
	{0xE9, 0x01, {0xC9} },
	{0xE7, 0x02, {0x2E, 0xCB} },
	{0xE9, 0x01, {0x00} },
	{0xBD, 0x01, {0x00} },
	{0xD1, 0x01, {0x27} },
	{0xBC, 0x01, {0x07} },
	{0xBD, 0x01, {0x01} },
	{0xE9, 0x01, {0xC2} },
	{0xCB, 0x01, {0x27} },
	{0xE9, 0x01, {0x00} },
	{0xBD, 0x01, {0x00} },
	{0x51, 0x02, {0x0F, 0xFF} },
	{0x53, 0x01, {0x24} },
	{0x55, 0x01, {0x00} },
	{0x35, 0x01, {0x00} },
	{0x44, 0x02, {0x08, 0x66}}, /* set TE event @ line 0x866(2150) */

	{0x11, 0, {} },

#ifndef LCM_SET_DISPLAY_ON_DELAY
	{REGFLAG_DELAY, 150, {} },

	{0xE9, 0x01, {0xC2} },
	{0xB0, 0x01, {0x01} },
	{0xE9, 0x01, {0x00} },

	{0x29, 0, {} },
	{REGFLAG_DELAY, 50, {} },
#endif
};

static struct LCM_setting_table lcm_deep_sleep_mode_in_setting[] = {
	{0x28, 1, {0x00} },
	{REGFLAG_DELAY, 50, {} },
	{0x10, 1, {0x00} },
	{REGFLAG_DELAY, 150, {} },
};

static struct LCM_setting_table lcm_sleep_out_setting[] = {
	{0x11, 1, {0x00} },
	{REGFLAG_DELAY, 120, {} },
	{0x29, 1, {0x00} },
	{REGFLAG_DELAY, 50, {} },
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

	params->dsi.mode = CMD_MODE;
	params->dsi.switch_mode = SYNC_PULSE_VDO_MODE;
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

	params->dsi.vertical_sync_active = 2;
	params->dsi.vertical_backporch = 8;
	params->dsi.vertical_frontporch = 20;
	params->dsi.vertical_frontporch_for_low_power = 620;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 10;
	params->dsi.horizontal_backporch = 20;
	params->dsi.horizontal_frontporch = 40;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	/* params->dsi.ssc_disable = 1; */
#ifndef MACH_FPGA
	/* this value must be in MTK suggested table */
	params->dsi.PLL_CLOCK = 480;
#else
	params->dsi.pll_div1 = 0;
	params->dsi.pll_div2 = 0;
	params->dsi.fbk_div = 0x1;
#endif
	params->dsi.CLK_HS_POST = 36;
	params->dsi.clk_lp_per_line_enable = 0;
	params->dsi.esd_check_enable = 1;
	params->dsi.customization_esd_check_enable = 0;
	params->dsi.lcm_esd_check_table[0].cmd = 0x0a;
	params->dsi.lcm_esd_check_table[0].count = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9c;

}

/* turn on gate ic & control voltage to 5.5V */
static void lcm_init_power(void)
{
	int ret = 0;

#ifndef MACH_FPGA
	/* config rt5081 register 0xB2[7:6]=0x3, that is set db_delay=4ms.*/
	ret = PMU_REG_MASK(0xB2, (0x3 << 6), (0x3 << 6));

	/* set AVDD 5.5v, (4v+30*0.05v) */
	/* ret = RT5081_write_byte(0xB3, (1 << 6) | 28);*/
	ret = PMU_REG_MASK(0xB3, 30, (0x3F << 0));
	if (ret < 0)
		LCM_LOGI("otm1911a_fhdp_dsi_vdo----cmd=%0x--i2c write error----\n", 0xB3);
	else
		LCM_LOGI("otm1911a_fhdp_dsi_vdo-----cmd=%0x--i2c write success----\n", 0xB3);

	/* set AVEE */
	/* ret = RT5081_write_byte(0xB4, (1 << 6) | 28); */
	ret = PMU_REG_MASK(0xB4, 30, (0x3F << 0));
	if (ret < 0)
		LCM_LOGI("otm1911a_fhdp_dsi_vdo----cmd=%0x--i2c write error----\n", 0xB4);
	else
		LCM_LOGI("otm1911a_fhdp_dsi_vdo----cmd=%0x--i2c write success----\n", 0xB4);

	/* enable AVDD & AVEE */
	/* 0x12--default value; bit3--Vneg; bit6--Vpos; */
	/* ret = RT5081_write_byte(0xB1, 0x12 | (1<<3) | (1<<6)); */
	ret = PMU_REG_MASK(0xB1, (1<<3) | (1<<6), (1<<3) | (1<<6));
	if (ret < 0)
		LCM_LOGI("otm1911a_fhdp_dsi_vdo----cmd=%0x--i2c write error----\n", 0xB1);
	else
		LCM_LOGI("otm1911a_fhdp_dsi_vdo----cmd=%0x--i2c write success----\n", 0xB1);

#endif
}

static void lcm_suspend_power(void)
{

}

static void lcm_resume_power(void)
{

}

#ifdef LCM_SET_DISPLAY_ON_DELAY
static U32 lcm_init_tick = 0;
static int is_display_on = 0;
#endif

static void lcm_init(void)
{
	int ret = 0;

	SET_RESET_PIN(0);

#ifndef MACH_FPGA
	/* config rt5081 register 0xB2[7:6]=0x3, that is set db_delay=4ms.*/
	ret = PMU_REG_MASK(0xB2, (0x3 << 6), (0x3 << 6));

	/* set AVDD 5.5v, (4v+30*0.05v) */
	/* ret = RT5081_write_byte(0xB3, (1 << 6) | 28);*/
	ret = PMU_REG_MASK(0xB3, 30, (0x3F << 0));
	if (ret < 0)
		LCM_LOGI("hx83112b_fhdp----tps6132----cmd=%0x--i2c write error----\n", 0xB3);
	else
		LCM_LOGI("hx83112b_fhdp----tps6132----cmd=%0x--i2c write success----\n", 0xB3);

	/* set AVEE */
	/* ret = RT5081_write_byte(0xB4, (1 << 6) | 28); */
	ret = PMU_REG_MASK(0xB4, 30, (0x3F << 0));
	if (ret < 0)
		LCM_LOGI("hx83112b_fhdp----tps6132----cmd=%0x--i2c write error----\n", 0xB4);
	else
		LCM_LOGI("hx83112b_fhdp----tps6132----cmd=%0x--i2c write success----\n", 0xB4);

	/* enable AVDD & AVEE */
	/* 0x12--default value; bit3--Vneg; bit6--Vpos; */
	/* ret = RT5081_write_byte(0xB1, 0x12 | (1<<3) | (1<<6)); */
	ret = PMU_REG_MASK(0xB1, (1<<3) | (1<<6), (1<<3) | (1<<6));
	if (ret < 0)
		LCM_LOGI("hx83112b_fhdp----tps6132----cmd=%0x--i2c write error----\n", 0xB1);
	else
		LCM_LOGI("hx83112b_fhdp----tps6132----cmd=%0x--i2c write success----\n", 0xB1);

	MDELAY(15);
#endif
	SET_RESET_PIN(1);
	MDELAY(1);
	SET_RESET_PIN(0);
	MDELAY(10);

	SET_RESET_PIN(1);
	MDELAY(10);

	push_table(init_setting_cmd, sizeof(init_setting_cmd) /
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
			LCM_LOGI("hx83112b %s error: i=%u,lcm_init_tick=%u,cur_tick=%u\n",
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
	int ret;

	push_table(lcm_suspend_setting, sizeof(lcm_suspend_setting) /
		   sizeof(struct LCM_setting_table), 1);
#ifndef MACH_FPGA
	/* enable AVDD & AVEE */
	/* 0x12--default value; bit3--Vneg; bit6--Vpos; */
	/* ret = RT5081_write_byte(0xB1, 0x12); */
	ret = PMU_REG_MASK(0xB1, (0<<3) | (0<<6), (1<<3) | (1<<6));
	if (ret < 0)
		LCM_LOGI("hx83112b_fhdp----tps6132----cmd=%0x--i2c write error----\n", 0xB1);
	else
		LCM_LOGI("hx83112b_fhdp----tps6132----cmd=%0x--i2c write success----\n", 0xB1);

	MDELAY(5);
#endif

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
	unsigned int x0 = x;
	unsigned int y0 = y;
	unsigned int x1 = x0 + width - 1;
	unsigned int y1 = y0 + height - 1;

	unsigned char x0_MSB = ((x0 >> 8) & 0xFF);
	unsigned char x0_LSB = (x0 & 0xFF);
	unsigned char x1_MSB = ((x1 >> 8) & 0xFF);
	unsigned char x1_LSB = (x1 & 0xFF);
	unsigned char y0_MSB = ((y0 >> 8) & 0xFF);
	unsigned char y0_LSB = (y0 & 0xFF);
	unsigned char y1_MSB = ((y1 >> 8) & 0xFF);
	unsigned char y1_LSB = (y1 & 0xFF);

	unsigned int data_array[16];

#ifdef LCM_SET_DISPLAY_ON_DELAY
	lcm_set_display_on();
#endif

	data_array[0] = 0x00053902;
	data_array[1] = (x1_MSB << 24) | (x0_LSB << 16) | (x0_MSB << 8) | 0x2a;
	data_array[2] = (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x00053902;
	data_array[1] = (y1_MSB << 24) | (y0_LSB << 16) | (y0_MSB << 8) | 0x2b;
	data_array[2] = (y1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x002c3909;
	dsi_set_cmdq(data_array, 1, 0);
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
	LCM_LOGI("%s,hx83112b backlight: level = %d\n", __func__, level);

	bl_level[0].para_list[0] = level;

	push_table(bl_level, sizeof(bl_level) /
		   sizeof(struct LCM_setting_table), 1);
}

static void lcm_setbacklight(unsigned int level)
{
	LCM_LOGI("%s,hx83112b backlight: level = %d\n", __func__, level);

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
	id = buffer[0];     /* we only need ID */

	LCM_LOGI("%s,hx83112b id = 0x%08x\n", __func__, id);

	if (id == LCM_ID_HX83112B)
		return 1;
	else
		return 0;

}

LCM_DRIVER hx83112b_fhdp_dsi_cmd_auo_rt5081_fhd_lcm_drv = {
	.name = "hx83112b_fhdp_dsi_cmd_auo_rt5081_fhd_drv",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.init_power = lcm_init_power,
	.resume_power = lcm_resume_power,
	.suspend_power = lcm_suspend_power,
	.compare_id = lcm_compare_id,
	.set_backlight = lcm_setbacklight,
	.ata_check = lcm_ata_check,
	.update = lcm_update,
};

