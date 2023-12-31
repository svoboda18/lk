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

#ifndef BUILD_LK
#include <linux/string.h>
#endif

#include "lcm_drv.h"

#ifdef BUILD_LK
#include <platform/mt_gpio.h>
#include <string.h>
#elif defined(BUILD_UBOOT)
#include <asm/arch/mt_gpio.h>
#else
#include <mach/mt_gpio.h>
#endif
#include "lcm_drv.h"

/* ----------------------------------------------------------------- */
/* Local Constants */
/* ----------------------------------------------------------------- */
#define FRAME_WIDTH		(1080)
#define FRAME_HEIGHT		(1920)
#define GPIO_OUT_ONE		1
#define GPIO_OUT_ZERO		0

#define REGFLAG_DELAY		0xFE
#define REGFLAG_END_OF_TABLE	0xFF

#define LCM_DSI_CMD_MODE	0
#define LCM_ID_NT35532		0x80

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/* GPIO45       panel reset pin for controll */
#ifdef GPIO_LCM_RST
#define GPIO_LCD_RST		GPIO_LCM_RST
#else
#define GPIO_LCD_RST		GPIO45
#endif

/* GPIO158       panel 1.8V for controll */
#ifdef GPIO_LCM_PWR_EN
#define GPIO_LCD_PWR_EN		GPIO_LCM_PWR_EN
#else
#define GPIO_LCD_PWR_EN		GPIO158
#endif

/* GPIO159       panel 2.8V for controll */
#ifdef GPIO_LCM_PWR2_EN
#define GPIO_LCD_PWR2_EN	GPIO_LCM_PWR2_EN
#else
#define GPIO_LCD_PWR2_EN	GPIO159
#endif

/* ----------------------------------------------------------------- */
/* Local Variables */
/* ----------------------------------------------------------------- */
static LCM_UTIL_FUNCS lcm_util = {0};
#define SET_RESET_PIN(v)	(lcm_util.set_reset_pin((v)))
#define UDELAY(n)		(lcm_util.udelay(n))
#define MDELAY(n)		(lcm_util.mdelay(n))

/* ----------------------------------------------------------------- */
/* Local Functions */
/* ----------------------------------------------------------------- */
#define dsi_set_cmdq_V2(cmd, count, ppara, force_update) \
		lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update) \
		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)	lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums) \
		lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg	lcm_util.dsi_read_reg()
#define read_reg_v2(cmd, buffer, buffer_size) \
		lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)

/* ----------------------------------------------------------------- */
/* LCM Driver Implementations */
/* ----------------------------------------------------------------- */
struct LCM_setting_table {
    unsigned char cmd;
    unsigned char count;
    unsigned char para_list[64];
};

static void lcm_set_gpio_output(unsigned int GPIO, unsigned int output)
{
#ifdef BUILD_LK
	mt_set_gpio_mode(GPIO, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO, output);
#else
	gpio_set_value(GPIO, output);
#endif
}

static struct LCM_setting_table lcm_initialization_setting[] = {
	/* Select page command*/
	{0xFF, 1, { 0x00 } },
	/* Non-reload command */
	{0xFB, 1, { 0x01 } },
	{REGFLAG_DELAY, 23, { } },

	/* Select page command*/
	{0xFF, 1, { 0x00 } },
	{0xD3, 1, { 0x08 } },
	{0xD4, 1, { 0x0E } },

	/* Sleep out*/
	{0x11, 0, { } },
	{REGFLAG_DELAY, 120, { } },

	/* Display on */
	{0x29, 0, { } },
	{REGFLAG_DELAY, 20, { } },

	/* Set LED light */
	{0x51, 1, { 0xFF } },
	/* Set LED on */
	{0x53, 1, { 0x2C } },
	/* Set CABC on */
	{0x55, 1, { 0x03 } },
};

static struct LCM_setting_table lcm_suspend_setting[] = {
	/* Turn off backlight */
	{0x53, 1, { 0x00 } },
	{REGFLAG_DELAY, 1, { } },

	/* Display off */
	{0x28, 0, { } },
	{REGFLAG_DELAY, 20, { } },

	/* Sleep in */
	{0x10, 0, { } },
	{REGFLAG_DELAY, 120, { } },

	/* Select page command */
	{0xFF, 1, { 0x00 } },
	{REGFLAG_DELAY, 1, { } },
};

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;

	for(i = 0; i < count; i++) {
		unsigned cmd;
		cmd = table[i].cmd;

		switch (cmd) {
		case REGFLAG_DELAY:
			if(table[i].count <= 10)
				MDELAY(table[i].count);
			else
				MDELAY(table[i].count);
			break;

		case REGFLAG_END_OF_TABLE:
			break;

		default:
			dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
		}
	}
}

static unsigned int lcm_compare_id(void)
{
	unsigned int id = 0;
	/* unsigned int id0 = 0, id1 = 0, id2 = 0; */
	unsigned char buffer[2];
	unsigned int array[16];

    printf("[LK/LCM] %s enter\n", __func__);

	/* Page enable*/
	array[0] = 0x00043902;
	array[1] = 0x9983FFB9;
	dsi_set_cmdq(&array, 2, 1);
	MDELAY(10);

	array[0] = 0x00013700;
	dsi_set_cmdq(&array, 1, 1);
	read_reg_v2(0xDB, buffer, 1);
	id = buffer[0];
    printf("[LK/LCM] lcm_id = 0x%x\n", id);

#if 0 /* the second para is id, same as the result read by 0x4*/
	array[0] = 0x00033700;
	dsi_set_cmdq(array, 1, 1);
	read_reg_v2(0x04, buffer, 3);
	id0 = buffer[0];
	id1 = buffer[1];
	id2 = buffer[2];
    printf("[LK/LCM] id0 = %d, id1 = %d, id2 = %d\n", id0, id1, id2);
#endif

	return (LCM_ID_NT35532 == id) ? 1 : 0;
}

/* ----------------------------------------------------------------- */
/* LCM Driver Implementations */
/* ----------------------------------------------------------------- */
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
	params->dsi.mode   = SYNC_PULSE_VDO_MODE;
#endif

    params->dsi.LANE_NUM			= LCM_FOUR_LANE;
	params->dsi.data_format.color_order	= LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq	= LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding		= LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format		= LCM_DSI_FORMAT_RGB888;

	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;

	params->dsi.vertical_sync_active	= 2;
	params->dsi.vertical_backporch		= 6;
	params->dsi.vertical_frontporch		= 14;
	params->dsi.vertical_active_line	= FRAME_HEIGHT;

	params->dsi.horizontal_sync_active	= 8;
	params->dsi.horizontal_backporch	= 16;
	params->dsi.horizontal_frontporch	= 72;
	params->dsi.horizontal_active_pixel	= FRAME_WIDTH;

    params->dsi.PLL_CLOCK		= 430;
}

static void lcm_init(void)
{
	unsigned int array[16];

	printf("[LK/LCM] %s enter\n", __func__);
	push_table(lcm_initialization_setting,
		sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table),
		1);
}

static void lcm_init_power(void)
{
#ifdef BUILD_LK
	printf("[LK/LCM] %s enter\n", __func__);

	lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ONE);
	MDELAY(10);
	lcm_set_gpio_output(GPIO_LCD_PWR2_EN, GPIO_OUT_ONE);
	MDELAY(10);

	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(30);
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ZERO);
	MDELAY(2);
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(5);
#else
	pr_notice("[KERNEL/LCM] %s enter\n", __func__);
#endif
}

LCM_DRIVER nt35532_fhd_dsi_vdo_sharp_lcm_drv =
{
	.name		= "nt35532_fhd_dsi_vdo_sharp_lcm_drv",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.init_power     = lcm_init_power,
	.compare_id 	= lcm_compare_id,
};


