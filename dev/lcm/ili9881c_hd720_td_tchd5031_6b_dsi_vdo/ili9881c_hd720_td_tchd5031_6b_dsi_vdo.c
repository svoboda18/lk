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
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/

#ifdef BUILD_LK
#include <string.h>
#include <platform/mt_gpio.h>
#include <platform/mt_pmic.h>
#include <platform/upmu_common.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#endif

#include "lcm_drv.h"

/* --------------------------------------------------------------------------- */
/* Local Constants */
/* --------------------------------------------------------------------------- */
#define LCM_DSI_CMD_MODE								0
#define FRAME_WIDTH                                     (720)
#define FRAME_HEIGHT                                    (1280)

#define GPIO_OUT_ONE 1
#define GPIO_OUT_ZERO 0

#ifdef GPIO_LCM_RST
#define GPIO_LCD_RST      GPIO_LCM_RST
#else
#define GPIO_LCD_RST		0xFFFFFFFF
#endif

static LCM_UTIL_FUNCS lcm_util;

#define SET_RESET_PIN(v) (lcm_util.set_reset_pin((v)))

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))

/* --------------------------------------------------------------------------- */
/* Local Functions */
/* --------------------------------------------------------------------------- */
#define dsi_set_cmdq_V2(cmd, count, ppara, force_update) lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update) lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)                          lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)      lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)                           lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)   lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)
/* --------------------------------------------------------------------------- */
/* Local Constants */
/* --------------------------------------------------------------------------- */
#define REGFLAG_DELAY                               0xFC
#define REGFLAG_END_OF_TABLE                        0xFD	/* END OF REGISTERS MARKER */

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/* --------------------------------------------------------------------------- */
/* Local Variables */
/* --------------------------------------------------------------------------- */
static void lcm_set_gpio_output(unsigned int GPIO, unsigned int output)
{
	if (GPIO == 0xFFFFFFFF) {
#ifdef BUILD_LK
		printf("[LK/LCM] GPIO_LCD_RST =   0x%x\n", GPIO_LCD_RST);
#endif
		return;
	}
#ifdef BUILD_LK
	mt_set_gpio_mode(GPIO, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO, (output > 0) ? GPIO_OUT_ONE : GPIO_OUT_ZERO);
#endif
}

struct LCM_setting_table {
	unsigned char cmd;
	unsigned char count;
	unsigned char para_list[64];
};

static struct LCM_setting_table lcm_initialization_setting[] = {
	{0xFF, 3, {0x98, 0x81, 0x03} },
	{0x01, 1, {0x00} },
	{0x02, 1, {0x00} },
	{0x03, 1, {0x53} },
	{0x04, 1, {0x13} },
	{0x05, 1, {0x13} },
	{0x06, 1, {0x06} },
	{0x07, 1, {0x00} },
	{0x08, 1, {0x04} },
	{0x09, 1, {0x00} },
	{0x0a, 1, {0x00} },
	{0x0b, 1, {0x00} },
	{0x0c, 1, {0x00} },
	{0x0d, 1, {0x00} },
	{0x0e, 1, {0x00} },
	{0x0f, 1, {0x00} },
	{0x10, 1, {0x00} },
	{0x11, 1, {0x00} },
	{0x12, 1, {0x00} },
	{0x13, 1, {0x00} },
	{0x14, 1, {0x00} },
	{0x15, 1, {0x00} },
	{0x16, 1, {0x00} },
	{0x17, 1, {0x00} },
	{0x18, 1, {0x00} },
	{0x19, 1, {0x00} },
	{0x1a, 1, {0x00} },
	{0x1b, 1, {0x00} },
	{0x1c, 1, {0x00} },
	{0x1d, 1, {0x00} },

	{0x1e, 1, {0xC0} },
	{0x1f, 1, {0x80} },
	{0x20, 1, {0x04} },
	{0x21, 1, {0x0B} },
	{0x22, 1, {0x00} },
	{0x23, 1, {0x00} },
	{0x24, 1, {0x00} },
	{0x25, 1, {0x00} },
	{0x26, 1, {0x00} },
	{0x27, 1, {0x00} },
	{0x28, 1, {0x55} },
	{0x29, 1, {0x03} },
	{0x2a, 1, {0x00} },
	{0x2b, 1, {0x00} },
	{0x2c, 1, {0x00} },
	{0x2d, 1, {0x00} },
	{0x2e, 1, {0x00} },
	{0x2f, 1, {0x00} },
	{0x30, 1, {0x00} },
	{0x31, 1, {0x00} },
	{0x32, 1, {0x00} },
	{0x33, 1, {0x00} },

	{0x34, 1, {0x04} },
	{0x35, 1, {0x05} },
	{0x36, 1, {0x05} },
	{0x37, 1, {0x00} },
	{0x38, 1, {0x3C} },
	{0x39, 1, {0x00} },
	{0x3a, 1, {0x40} },
	{0x3b, 1, {0x40} },

	{0x3c, 1, {0x00} },
	{0x3d, 1, {0x00} },
	{0x3e, 1, {0x00} },
	{0x3f, 1, {0x00} },
	{0x40, 1, {0x00} },
	{0x41, 1, {0x00} },
	{0x42, 1, {0x00} },
	{0x43, 1, {0x00} },
	{0x44, 1, {0x00} },

	{0x50, 1, {0x01} },
	{0x51, 1, {0x23} },
	{0x52, 1, {0x45} },
	{0x53, 1, {0x67} },
	{0x54, 1, {0x89} },
	{0x55, 1, {0xAB} },
	{0x56, 1, {0x01} },
	{0x57, 1, {0x23} },
	{0x58, 1, {0x45} },
	{0x59, 1, {0x67} },
	{0x5A, 1, {0x89} },
	{0x5B, 1, {0xAB} },
	{0x5C, 1, {0xCD} },
	{0x5D, 1, {0xEF} },

	{0x5E, 1, {0x01} },
	{0x5F, 1, {0x14} },
	{0x60, 1, {0x15} },
	{0x61, 1, {0x0C} },
	{0x62, 1, {0x0D} },
	{0x63, 1, {0x0E} },
	{0x64, 1, {0x0F} },
	{0x65, 1, {0x10} },
	{0x66, 1, {0x11} },
	{0x67, 1, {0x08} },
	{0x68, 1, {0x02} },
	{0x69, 1, {0x0A} },
	{0x6A, 1, {0x02} },
	{0x6B, 1, {0x02} },
	{0x6C, 1, {0x02} },
	{0x6D, 1, {0x02} },
	{0x6E, 1, {0x02} },
	{0x6F, 1, {0x02} },
	{0x70, 1, {0x02} },
	{0x71, 1, {0x02} },
	{0x72, 1, {0x06} },
	{0x73, 1, {0x02} },
	{0x74, 1, {0x02} },
	{0x75, 1, {0x14} },
	{0x76, 1, {0x15} },
	{0x77, 1, {0x11} },
	{0x78, 1, {0x10} },
	{0x79, 1, {0x0F} },
	{0x7A, 1, {0x0E} },
	{0x7B, 1, {0x0D} },
	{0x7C, 1, {0x0C} },
	{0x7D, 1, {0x06} },
	{0x7E, 1, {0x02} },
	{0x7F, 1, {0x0A} },
	{0x80, 1, {0x02} },
	{0x81, 1, {0x02} },
	{0x82, 1, {0x02} },
	{0x83, 1, {0x02} },
	{0x84, 1, {0x02} },
	{0x85, 1, {0x02} },
	{0x86, 1, {0x02} },
	{0x87, 1, {0x02} },
	{0x88, 1, {0x08} },
	{0x89, 1, {0x02} },
	{0x8A, 1, {0x02} },

	{0xFF, 3, {0x98, 0x81, 0x04} },
	{0x6C, 1, {0x15} },
	{0x6E, 1, {0x3B} },
	{0x6F, 1, {0x53} },
	{0x3A, 1, {0xA4} },
	{0x8D, 1, {0x15} },
	{0x87, 1, {0xBA} },
	{0x26, 1, {0x76} },
	{0XB2, 1, {0XD1} },
	{0X88, 1, {0X0B} },

	{0xFF, 3, {0x98, 0x81, 0x01} },
	{0x22, 1, {0x0A} },
	{0x31, 1, {0x00} },
	{0x53, 1, {0x96} },
	{0x55, 1, {0x88} },
	{0x50, 1, {0x96} },
	{0x51, 1, {0x96} },
	{0x60, 1, {0x14} },

	{0xA0, 1, {0x08} },
	{0xA1, 1, {0x1C} },
	{0xA2, 1, {0x29} },
	{0xA3, 1, {0x13} },
	{0xA4, 1, {0x16} },
	{0xA5, 1, {0x28} },
	{0xA6, 1, {0x1C} },
	{0xA7, 1, {0x1D} },
	{0xA8, 1, {0x80} },
	{0xA9, 1, {0x1a} },
	{0xAA, 1, {0x27} },
	{0xAB, 1, {0x6A} },
	{0xAC, 1, {0x1a} },
	{0xAD, 1, {0x19} },
	{0xAE, 1, {0x4b} },
	{0xAF, 1, {0x21} },
	{0xB0, 1, {0x25} },
	{0xB1, 1, {0x4A} },
	{0xB2, 1, {0x59} },
	{0xB3, 1, {0x2C} },

	{0xC0, 1, {0x08} },
	{0xC1, 1, {0x1C} },
	{0xC2, 1, {0x29} },
	{0xC3, 1, {0x13} },
	{0xC4, 1, {0x17} },
	{0xC5, 1, {0x28} },
	{0xC6, 1, {0x1C} },
	{0xC7, 1, {0x1D} },
	{0xC8, 1, {0x80} },
	{0xC9, 1, {0x1a} },
	{0xCA, 1, {0x27} },
	{0xCB, 1, {0x6A} },
	{0xCC, 1, {0x1A} },
	{0xCD, 1, {0x19} },
	{0xCE, 1, {0x4b} },
	{0xCF, 1, {0x21} },
	{0xD0, 1, {0x25} },
	{0xD1, 1, {0x4A} },
	{0xD2, 1, {0x5B} },
	{0xD3, 1, {0x2C} },

	{0xFF, 3, {0x98, 0x81, 0x00} },

	{0x35, 1, {0x00} },

	{0x11, 0, {} },
	{REGFLAG_DELAY, 120, {} },
	{0x29, 0, {} },
	{REGFLAG_DELAY, 20, {} },
	{REGFLAG_END_OF_TABLE, 0x00, {} }
};

static void dsi_send_cmdq_tinno(unsigned cmd, unsigned char count, unsigned char *para_list,
				unsigned char force_update)
{
	unsigned int item[16];
	unsigned char dsi_cmd = (unsigned char)cmd;
	unsigned char dc;
	int index = 0, length = 0;

	memset(item, 0, sizeof(item));
	if (count + 1 > 60)
		return;

	if (count == 0) {
		item[0] = 0x0500 | (dsi_cmd << 16);
		length = 1;
	} else if (count == 1) {
		item[0] = 0x1500 | (dsi_cmd << 16) | (para_list[0] << 24);
		length = 1;
	} else {
		item[0] = 0x3902 | ((count + 1) << 16);	/* Count include command. */
		++length;
		while (1) {
			if (index == count + 1)
				break;
			if (index == 0)
				dc = cmd;
			else
				dc = para_list[index - 1];
			/* an item make up of 4data. */
			item[index / 4 + 1] |= (dc << (8 * (index % 4)));
			if (index % 4 == 0)
				++length;
			++index;
		}
	}

	dsi_set_cmdq(item, length, force_update);
}


static void push_table(struct LCM_setting_table *table, unsigned int count,
		       unsigned char force_update)
{
	unsigned int i;
	unsigned cmd;

	for (i = 0; i < count; i++) {
		cmd = table[i].cmd;
		switch (cmd) {
		case REGFLAG_DELAY:
			MDELAY(table[i].count);
			break;

		case REGFLAG_END_OF_TABLE:
			break;

		default:
			dsi_send_cmdq_tinno(cmd, table[i].count, table[i].para_list, force_update);
			/* dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update); */
		}
	}
}

static void init_lcm_registers(void)
{
	push_table(lcm_initialization_setting,
		   sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}

/* --------------------------------------------------------------------------- */
/* LCM Driver Implementations */
/* --------------------------------------------------------------------------- */
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

#if (LCM_DSI_CMD_MODE)
	params->dsi.mode = CMD_MODE;
#else
	params->dsi.mode = SYNC_PULSE_VDO_MODE;
#endif

	/* DSI */
	/* Command mode setting */
	params->dsi.LANE_NUM = LCM_FOUR_LANE;
	/* The following defined the fomat for data coming from LCD engine. */
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format = LCM_DSI_FORMAT_RGB888;

	params->dsi.intermediat_buffer_num = 2;
	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;

#ifndef BUILD_LK
	params->dsi.esd_check_enable = 1;
	params->dsi.customization_esd_check_enable = 1;
	params->dsi.lcm_esd_check_table[0].cmd = 0x0A;
	params->dsi.lcm_esd_check_table[0].count = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9c;
#endif
	params->dsi.vertical_sync_active = 4;
	params->dsi.vertical_backporch = 16;
	params->dsi.vertical_frontporch = 40;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 20;
	params->dsi.horizontal_backporch = 80;
	params->dsi.horizontal_frontporch = 80;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;

	/* video mode timing */
	params->dsi.word_count = FRAME_WIDTH * 3;

	params->dsi.PLL_CLOCK = 270;
}

static void lcm_init_lcm(void)
{
#ifdef BUILD_LK
	printf("[LK/LCM] lcm_init() enter\n");

	mt6392_upmu_set_rg_vgp2_vosel(7);
	mt6392_upmu_set_rg_vgp2_en(0x1);
	MDELAY(10);

	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ZERO);
	MDELAY(10);

	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);

	init_lcm_registers();
#endif
}

void lcm_suspend(void)
{
#ifdef BUILD_LK
	printf("[LK/LCM] lcm_suspend() enter\n");
#endif
}

void lcm_resume(void)
{
#ifdef BUILD_LK
		printf("[LK/LCM] lcm_resume() enter\n");
#endif
}

#if (LCM_DSI_CMD_MODE)
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
#endif

LCM_DRIVER ili9881c_hd720_td_tchd5031_6b_dsi_vdo_lcm_drv = {
	.name = "ili9881c_hd720_td_tchd5031_6b_dsi_vdo",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init_lcm,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
};
