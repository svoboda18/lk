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


/*
 * Panel: 5.46FHD+(1080*1920) AUO
 * Driver IC: R63350A
 * Interface: MIPI  4LANES
 * Test condition :IOVCC=1.8V
 */

/* --------------------------------------------------------------------------- */
/*  Local Constants */
/* --------------------------------------------------------------------------- */

#define LCM_DSI_CMD_MODE                    0
#define FRAME_WIDTH                         (1080)
#define FRAME_HEIGHT                        (1920)
#define GPIO_OUT_ONE                        1
#define GPIO_OUT_ZERO                       0

#define REGFLAG_DELAY                       0xFE
#define REGFLAG_END_OF_TABLE                0xFF

/* GPIO45       panel reset pin for controll */
#ifdef GPIO_LCM_RST
#define GPIO_LCD_RST                        GPIO_LCM_RST
#else
#define GPIO_LCD_RST                        GPIO45
#endif

/* GPIO158       panel 1.8V for controll */
#ifdef GPIO_LCM_PWR_EN
#define GPIO_LCD_PWR_EN                     GPIO_LCM_PWR_EN
#else
#define GPIO_LCD_PWR_EN                     GPIO158
#endif

/* GPIO159       panel 2.8V for controll */
#ifdef GPIO_LCM_PWR2_EN
#define GPIO_LCD_PWR2_EN                    GPIO_LCM_PWR2_EN
#else
#define GPIO_LCD_PWR2_EN                    GPIO159
#endif

/* --------------------------------------------------------------------------- */
/*  Local Variables */
/* --------------------------------------------------------------------------- */
static LCM_UTIL_FUNCS lcm_util = {0};
#define SET_RESET_PIN(v)                    (lcm_util.set_reset_pin((v)))
#define UDELAY(n)                           (lcm_util.udelay(n))
#define MDELAY(n)                           (lcm_util.mdelay(n))

/* --------------------------------------------------------------------------- */
/*  Local Functions */
/* --------------------------------------------------------------------------- */
#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)    lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)       lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)                                      lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)                  lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg                                            lcm_util.dsi_read_reg()
#define read_reg_v2(cmd, buffer, buffer_size)               lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)

#ifdef BUILD_LK
#define LCM_LOGI(string, args...)  dprintf(CRITICAL, "[LK/"LOG_TAG"]"string, ##args)
#define LCM_LOGD(string, args...)  dprintf(INFO, "[LK/"LOG_TAG"]"string, ##args)
#else
#define LCM_LOGI(fmt, args...)  pr_notice("[KERNEL/"LOG_TAG"]"fmt, ##args)
#define LCM_LOGD(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#endif

struct LCM_setting_table {
	unsigned char cmd;
	unsigned char count;
	unsigned char para_list[64];
};

static void lcm_set_gpio_output(unsigned int GPIO, unsigned int output)
{
	printf("[LK/LCM] GPIO_LCD_RST =	0x%x\n", GPIO_LCD_RST);
	printf("[LK/LCM] GPIO_LCD_PWR_EN = 0x%x\n", GPIO_LCD_PWR_EN);
	printf("[LK/LCM] GPIO_LCD_PWR2_EN = 0x%x\n", GPIO_LCD_PWR2_EN);

#ifdef BUILD_LK
	mt_set_gpio_mode(GPIO, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO, output);
#else
	gpio_set_value(GPIO, output);
#endif
}

static struct LCM_setting_table lcm_initialization_setting[] = {
	{0xB0, 1, {0x00} },
	{0xD6, 1, {0x01} },
	{0xB3, 6, {0x14, 0x00, 0x00, 0x00, 0x00, 0x00} },
	{0xB4, 2, {0x0C, 0x00} },
	{0xB6, 3, {0x4B, 0xDB, 0x16} },/* 0xCB,0x16 */
	{0xBE, 2, {0x00, 0x04} },
	{0xC0, 1, {0x00} },
	{0xC1, 34, {0x04, 0x60, 0x00, 0x20, 0xA9, 0x30, 0x20, 0x63,
				0xF0, 0xFF, 0xFF, 0x9B, 0x7B, 0xCF, 0xB5, 0xFF,
				0xFF, 0x87, 0x8C, 0x41, 0x22, 0x54, 0x02, 0x00,
				0x00, 0x00, 0x00, 0x00, 0x22, 0x33, 0x03, 0x22,
				0x00, 0xFF} },
	{0xC2, 8, {0x31, 0xf7, 0x80, 0x06, 0x04, 0x00, 0x00, 0x08} },
	{0xC3, 3, {0x00, 0x00, 0x00} },
	{0xC4, 11, {0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				0x00, 0x00, 0x02} },
	/* reduce noise*/
	/* {0xC4, 11, {0x70, 0x00, 0x00, 0x44, 0x44, 0x44, 0x44, 0x44,
				0x44, 0x00, 0x04} }, */
	{0xC5, 1, {0x00} },
	{0xC6, 21, {0xC8, 0x3C, 0x3C, 0x07, 0x01, 0x07, 0x01, 0x00,
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				0x00, 0x0E, 0x1A, 0x07, 0xC8} },
	{0xC7, 30, {0x03, 0x15, 0x1F, 0x2A, 0x39, 0x46, 0x4E, 0x5B,
				0x3D, 0x45, 0x52, 0x5F, 0x68, 0x6D, 0x72, 0x01,
				0x15, 0x1F, 0x2A, 0x39, 0x46, 0x4E, 0x5B, 0x3D,
				0x45, 0x52, 0x5F, 0x68, 0x6D, 0x78} },
	{0xCB, 15, {0xFF, 0xE1, 0x87, 0xFF, 0x00, 0x00, 0x00, 0x00,
				0xFF, 0xE1, 0x87, 0xFF, 0xE8, 0x00, 0x00} },
	{0xCC, 1, {0x34} },
	{0xD0, 10, {0x11, 0x00, 0x00, 0x56, 0xD5, 0x40, 0x19, 0x19,
				0x09, 0x00} },
	{0xD1, 4, {0x00, 0x48, 0x16, 0x0F} },
	{0xD2, 3, {0x5C, 0x00, 0x00} },
	{0xD3, 26, {0x1B, 0x33, 0xBB, 0xBB, 0xB3, 0x33, 0x33, 0x33,
				0x33, 0x00, 0x01, 0x00, 0x00, 0xD8, 0xA0, 0x0C,
				0x4D, 0x4D, 0x33, 0x33, 0x72, 0x12, 0x8A, 0x57,
				0x3D, 0xBC} },
	{0xD5, 7, {0x06, 0x00, 0x00, 0x01, 0x39, 0x01, 0x39} },
	{0xD8, 3, {0x00, 0x00, 0x00} },
	{0xD9, 3, {0x00, 0x00, 0x00} },
	{0xFD, 4, {0x00, 0x00, 0x00, 0x30} },
	{0x35, 1, {0x00} },
	/* Test revert */
	/* {0x36, 1, {0xC0} }, */
	{0x51, 1, {0xff} },
	/*  Write CTRL Display */
	{0x53, 1, {0x24} },
	/* Write Display Brightness */
	{0x55, 1, {0x00} },
	{0x29, 0, {} },
	{REGFLAG_DELAY, 50, {} },
	{0x11, 0, {} },
	{REGFLAG_DELAY, 120, {} },
	{REGFLAG_END_OF_TABLE, 0x00, {} }
};

static struct LCM_setting_table lcm_resume_setting[] = {
	/* Exit sleep mode */
	{0x11, 0, {} },
	{REGFLAG_DELAY, 150, {} },

	/* DISPLAY ON */
	{0x29, 0, {} },
	{REGFLAG_DELAY, 50, {} },
	{REGFLAG_END_OF_TABLE, 0x00, {} }
};

static struct LCM_setting_table lcm_suspend_setting[] = {
	/* DISPLAY OFF */
	{0x28, 0, {} },
	{REGFLAG_DELAY, 50, {} },
	/* Enter sleep mode */
	{0x10, 0, {} },
	{REGFLAG_DELAY, 150, {} },
	{REGFLAG_END_OF_TABLE, 0x00, {} }
};

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;

	for (i = 0; i < count; i++) {
		unsigned cmd;

		cmd = table[i].cmd;
		switch (cmd) {
		case REGFLAG_DELAY:
			MDELAY(table[i].count);
			break;

		case REGFLAG_END_OF_TABLE:
			break;

		default:
			dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
		}
	}
}

/* --------------------------------------------------------------------------- */
/*  LCM Driver Implementations */
/* --------------------------------------------------------------------------- */
static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
	memcpy((void*)&lcm_util, (void*)util, sizeof(LCM_UTIL_FUNCS));
}

static void lcm_get_params(LCM_PARAMS *params)
{
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type   = LCM_TYPE_DSI;

	params->width  = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;

#if (LCM_DSI_CMD_MODE)
	params->dsi.mode = CMD_MODE;
#else
	params->dsi.mode = SYNC_PULSE_VDO_MODE;
#endif

	params->dsi.LANE_NUM                = LCM_FOUR_LANE;
	/* The following defined the fomat for data coming from LCD engine. */
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

	/* Highly depends on LCD driver capability. */
	/* Not support in MT6573 */
	params->dsi.packet_size = 256;

	/* Video mode setting */
	params->dsi.intermediat_buffer_num = 0;

	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;
	params->dsi.word_count = FRAME_WIDTH * 3;

	params->dsi.vertical_sync_active	= 2;
	params->dsi.vertical_backporch		= 4;
	params->dsi.vertical_frontporch		= 10;
	params->dsi.vertical_active_line	= FRAME_HEIGHT;

	params->dsi.horizontal_sync_active	= 20;
	params->dsi.horizontal_backporch	= 60;
	params->dsi.horizontal_frontporch	= 90;
	params->dsi.horizontal_active_pixel	= FRAME_WIDTH;

	params->dsi.PLL_CLOCK			= 463;
	params->dsi.cont_clock			= 1;
}

static void lcm_init_power(void)
{
#ifdef BUILD_LK
	printf("[LK/LCM] lcm_init_power() enter\n");

	lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ONE);
	MDELAY(20);

	lcm_set_gpio_output(GPIO_LCD_PWR2_EN, GPIO_OUT_ONE);
	MDELAY(20);

	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ZERO);
	MDELAY(5);

	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(20);
#else
	pr_err("[KERNEL/LCM] lcm_init_power() enter\n");
#endif
}

static void lcm_suspend_power(void)
{
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ZERO);
	MDELAY(10);

	lcm_set_gpio_output(GPIO_LCD_PWR2_EN, GPIO_OUT_ZERO);
	MDELAY(20);

	lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ZERO);
	MDELAY(20);
}

static void lcm_resume_power(void)
{
	lcm_set_gpio_output(GPIO_LCD_PWR_EN, GPIO_OUT_ONE);
	MDELAY(20);

	lcm_set_gpio_output(GPIO_LCD_PWR2_EN, GPIO_OUT_ONE);
	MDELAY(20);

	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(20);
}

static unsigned int lcm_compare_id(void)
{
	int   array[4];
	char  buffer[5];
	char  id0 = 0;
	char  id1 = 0;
	char  id2 = 0;
	char  id3 = 0;
	char  id4 = 0;

	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(2);
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ZERO);
	UDELAY(11);
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(6);

	array[0] = 0x00053700;
	dsi_set_cmdq(array, 1, 1);
	read_reg_v2(0xBF, buffer, 5);

	id0 = buffer[0]; /* should be 0x02 */
	id1 = buffer[1]; /* should be 0x3C */
	id2 = buffer[2]; /* should be 0x33 */
	id3 = buffer[3]; /* should be 0x50 */
	id4 = buffer[4]; /* should be 0x00 */

	printf("%s, id0 = 0x%08x\n", __func__, id0);
	printf("%s, id1 = 0x%08x\n", __func__, id1);
	printf("%s, id2 = 0x%08x\n", __func__, id2);
	printf("%s, id3 = 0x%08x\n", __func__, id3);
	printf("%s, id4 = 0x%08x\n", __func__, id4);

	return (id2 == 0x33 && id3 == 0x50) ? 1 : 0;
}

static void lcm_init(void)
{
	printf("--------[LK] r63350a lcm_init enter--------\n");
	lcm_compare_id();
	push_table(lcm_initialization_setting,
			sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
	printf("--------[LK] r63350a lcm_init exit--------\n");
}

static void lcm_suspend(void)
{
	push_table(lcm_suspend_setting,
			sizeof(lcm_suspend_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_resume(void)
{
	lcm_init();
}

LCM_DRIVER r63350a_fhd_dsi_vdo_truly_lcm_drv = {
	.name           = "r63350a_fhd_dsi_vdo_truly",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	.init_power     = lcm_init_power,
	.resume_power   = lcm_resume_power,
	.suspend_power  = lcm_suspend_power,
	.compare_id     = lcm_compare_id,
};

