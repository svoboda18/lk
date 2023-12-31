/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
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
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
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
//	#include <mach/mt_gpio.h>
#endif

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH  										(720)
#define FRAME_HEIGHT 										(1280)
#define LCM_ID                       						(0x1284)

#define REGFLAG_DELAY             							(0XFFFE)
#define REGFLAG_END_OF_TABLE      							(0xFFFF)	// END OF REGISTERS MARKER


#define LCM_DSI_CMD_MODE									0

#ifndef TRUE
    #define TRUE 1
#endif

#ifndef FALSE
    #define FALSE 0
#endif

// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)    								(lcm_util.set_reset_pin((v)))

#define UDELAY(n) 											(lcm_util.udelay(n))
#define MDELAY(n) 											(lcm_util.mdelay(n))

#define LCM_RM68200_ID 		(0x6820)

static unsigned int lcm_esd_test = FALSE;      ///only for ESD test

// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)										lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)					lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)											lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)				lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)

 struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};



	/*
Note :
Data ID will depends on the following rule.
count of parameters > 1      => Data ID = 0x39
count of parameters = 1      => Data ID = 0x15
count of parameters = 0      => Data ID = 0x05
Struclcm_deep_sleep_mode_in_settingture Format :
{DCS command, count of parameters, {parameter list}}
{REGFLAG_DELAY, milliseconds of time, {}},
...

Setting ending by predefined flag
{REGFLAG_END_OF_TABLE, 0x00, {}}
*/
//RM38200+HSD5.94 YKL CODE


static struct LCM_setting_table lcm_initialization_setting[] = {
	{0xFE,   1, {0x1}},
{0x24,   1,{0xC0}},
{0x25,   1,{0x53}},
{0x26,   1, {0x0}},
{0x2B,   1,{0xE5}},
{0x27,   1, {0xA}},
{0x29,   1, {0xA}},
{0x2F,   1,{0x44}},
{0x34,   1,{0x59}},
{0x1B,   1, {0x0}},
{0x12,   1, {0x8}},
{0x46,   1,{0x90}},
{0x52,   1,{0x8A}},
{0x53,   1, {0x0}},
{0x54,   1,{0x8A}},
{0x55,   1, {0x0}},
{0x5F,   1,{0x12}},
{0xFE,   1, {0x3}},
{ 0x0,   1, {0x5}},
{ 0x1,   1,{0x16}},
{ 0x2,   1, {0x1}},
{ 0x3,   1, {0x8}},
{ 0x4,   1, {0x0}},
{ 0x5,   1, {0x0}},
{ 0x6,   1,{0x50}},
{ 0x7,   1, {0x0}},
{ 0x8,   1, {0x0}},
{ 0x9,   1, {0x0}},
{ 0xA,   1, {0x0}},
{ 0xB,   1, {0x0}},
{ 0xC,   1, {0x0}},
{ 0xD,   1, {0x0}},
{ 0xE,   1, {0x5}},
{ 0xF,   1, {0x6}},
{0x10,   1, {0x7}},
{0x11,   1, {0x8}},
{0x12,   1, {0x0}},
{0x13,   1,{0x40}},
{0x14,   1, {0x0}},
{0x15,   1,{0xC5}},
{0x16,   1, {0x8}},
{0x17,   1, {0x9}},
{0x18,   1, {0xA}},
{0x19,   1, {0xB}},
{0x1A,   1, {0xC}},
{0x1B,   1, {0x0}},
{0x1C,   1,{0x40}},
{0x1D,   1, {0x0}},
{0x1E,   1,{0x85}},
{0x1F,   1, {0x8}},
{0x20,   1, {0x0}},
{0x21,   1, {0x0}},
{0x22,   1, {0x5}},
{0x23,   1, {0x4}},
{0x24,   1, {0x6}},
{0x25,   1,{0x2D}},
{0x26,   1, {0x0}},
{0x27,   1, {0x8}},
{0x28,   1, {0xA}},
{0x29,   1,{0x2D}},
{0x2A,   1, {0x0}},
{0x2B,   1, {0x0}},
{0x2D,   1, {0x0}},
{0x2F,   1, {0x0}},
{0x30,   1, {0x0}},
{0x31,   1, {0x0}},
{0x32,   1, {0x0}},
{0x33,   1, {0x0}},
{0x34,   1, {0x0}},
{0x35,   1, {0x0}},
{0x36,   1, {0x0}},
{0x37,   1, {0x0}},
{0x38,   1, {0x0}},
{0x39,   1, {0x0}},
{0x3A,   1, {0x0}},
{0x3B,   1, {0x0}},
{0x3D,   1, {0x0}},
{0x3F,   1, {0x0}},
{0x40,   1, {0x0}},
{0x41,   1, {0x0}},
{0x42,   1, {0x0}},
{0x43,   1, {0x0}},
{0x44,   1, {0x0}},
{0x45,   1, {0x0}},
{0x46,   1, {0x0}},
{0x47,   1, {0x0}},
{0x48,   1, {0x0}},
{0x49,   1, {0x0}},
{0x4A,   1, {0x0}},
{0x4B,   1, {0x0}},
{0x4C,   1, {0x0}},
{0x4D,   1, {0x0}},
{0x4E,   1, {0x0}},
{0x4F,   1, {0x0}},
{0x50,   1, {0x0}},
{0x51,   1, {0x0}},
{0x52,   1, {0x0}},
{0x53,   1, {0x0}},
{0x54,   1, {0x0}},
{0x55,   1, {0x0}},
{0x56,   1, {0x0}},
{0x58,   1, {0x0}},
{0x59,   1, {0x0}},
{0x5A,   1, {0x0}},
{0x5B,   1, {0x0}},
{0x5C,   1, {0x0}},
{0x5D,   1, {0x0}},
{0x5E,   1, {0x0}},
{0x5F,   1, {0x0}},
{0x60,   1, {0x0}},
{0x61,   1, {0x0}},
{0x62,   1, {0x0}},
{0x63,   1, {0x0}},
{0x64,   1, {0x0}},
{0x65,   1, {0x0}},
{0x66,   1, {0x0}},
{0x67,   1, {0x0}},
{0x68,   1, {0x0}},
{0x69,   1, {0x0}},
{0x6A,   1, {0x0}},
{0x6B,   1, {0x0}},
{0x6C,   1, {0x0}},
{0x6D,   1, {0x0}},
{0x6E,   1, {0x0}},
{0x6F,   1, {0x0}},
{0x70,   1, {0x0}},
{0x71,   1, {0x0}},
{0x72,   1, {0x0}},
{0x73,   1, {0x0}},
{0x74,   1, {0x1}},
{0x75,   1, {0x1}},
{0x76,   1, {0x1}},
{0x77,   1, {0x1}},
{0x78,   1, {0x1}},
{0x79,   1, {0x1}},
{0x7A,   1, {0x0}},
{0x7B,   1, {0x0}},
{0x7C,   1, {0x0}},
{0x7D,   1, {0x0}},
{0x7E,   1, {0x1}},
{0x7F,   1, {0x9}},
{0x80,   1, {0xB}},
{0x81,   1, {0xD}},
{0x82,   1, {0xF}},
{0x83,   1,{0x3F}},
{0x84,   1,{0x3F}},
{0x85,   1,{0x1C}},
{0x86,   1,{0x1C}},
{0x87,   1,{0x3F}},
{0x88,   1,{0x3F}},
{0x89,   1,{0x3F}},
{0x8A,   1,{0x3F}},
{0x8B,   1,{0x3F}},
{0x8C,   1,{0x3F}},
{0x8D,   1,{0x3F}},
{0x8E,   1,{0x3F}},
{0x8F,   1,{0x3F}},
{0x90,   1,{0x3F}},
{0x91,   1,{0x1D}},
{0x92,   1,{0x1C}},
{0x93,   1, {0x3}},
{0x94,   1, {0x2}},
{0x95,   1,{0x1C}},
{0x96,   1,{0x1D}},
{0x97,   1,{0x3F}},
{0x98,   1,{0x3F}},
{0x99,   1,{0x3F}},
{0x9A,   1,{0x3F}},
{0x9B,   1,{0x3F}},
{0x9C,   1,{0x3F}},
{0x9D,   1,{0x3F}},
{0x9E,   1,{0x3F}},
{0x9F,   1,{0x3F}},
{0xA0,   1,{0x3F}},
{0xA2,   1,{0x1C}},
{0xA3,   1,{0x1C}},
{0xA4,   1,{0x3F}},
{0xA5,   1,{0x3F}},
{0xA6,   1, {0xE}},
{0xA7,   1, {0xC}},
{0xA9,   1, {0xA}},
{0xAA,   1, {0x8}},
{0xAB,   1, {0x0}},
{0xAC,   1, {0x2}},
{0xAD,   1, {0xE}},
{0xAE,   1, {0xC}},
{0xAF,   1, {0xA}},
{0xB0,   1, {0x8}},
{0xB1,   1,{0x3F}},
{0xB2,   1,{0x3F}},
{0xB3,   1,{0x1C}},
{0xB4,   1,{0x1C}},
{0xB5,   1,{0x3F}},
{0xB6,   1,{0x3F}},
{0xB7,   1,{0x3F}},
{0xB8,   1,{0x3F}},
{0xB9,   1,{0x3F}},
{0xBA,   1,{0x3F}},
{0xBB,   1,{0x3F}},
{0xBC,   1,{0x3F}},
{0xBD,   1,{0x3F}},
{0xBE,   1,{0x3F}},
{0xBF,   1,{0x1C}},
{0xC0,   1,{0x1D}},
{0xC1,   1, {0x0}},
{0xC2,   1, {0x1}},
{0xC3,   1,{0x1D}},
{0xC4,   1,{0x1C}},
{0xC5,   1,{0x3F}},
{0xC6,   1,{0x3F}},
{0xC7,   1,{0x3F}},
{0xC8,   1,{0x3F}},
{0xC9,   1,{0x3F}},
{0xCA,   1,{0x3F}},
{0xCB,   1,{0x3F}},
{0xCC,   1,{0x3F}},
{0xCD,   1,{0x3F}},
{0xCE,   1,{0x3F}},
{0xCF,   1,{0x1C}},
{0xD0,   1,{0x1C}},
{0xD1,   1,{0x3F}},
{0xD2,   1,{0x3F}},
{0xD3,   1, {0x9}},
{0xD4,   1, {0xB}},
{0xD5,   1, {0xD}},
{0xD6,   1, {0xF}},
{0xD7,   1, {0x3}},
{0xDF,   1, {0x0}},
{0xDC,   1, {0x2}},
{0xDE,   1, {0x8}},
{0xFE,   1, {0xE}},
{ 0x1,   1,{0x75}},
{0xFE,   1, {0x4}},
{0x60,   1, {0x0}},
{0x61,   1, {0x6}},
{0x62,   1, {0xA}},
{0x63,   1, {0xC}},
{0x64,   1, {0x4}},
{0x65,   1,{0x10}},
{0x66,   1, {0xE}},
{0x67,   1, {0xA}},
{0x68,   1,{0x17}},
{0x69,   1, {0xC}},
{0x6A,   1,{0x10}},
{0x6B,   1, {0x7}},
{0x6C,   1, {0xF}},
{0x6D,   1, {0xB}},
{0x6E,   1, {0x1}},
{0x6F,   1, {0x0}},
{0x70,   1, {0x0}},
{0x71,   1, {0x6}},
{0x72,   1, {0xA}},
{0x73,   1, {0xC}},
{0x74,   1, {0x4}},
{0x75,   1,{0x10}},
{0x76,   1, {0xE}},
{0x77,   1, {0xA}},
{0x78,   1,{0x17}},
{0x79,   1, {0xC}},
{0x7A,   1,{0x10}},
{0x7B,   1, {0x7}},
{0x7C,   1, {0xF}},
{0x7D,   1, {0xB}},
{0x7E,   1, {0x1}},
{0x7F,   1, {0x0}},
{0xFE,   1, {0x0}},
{0x58,   1,{0xA9}},
{0x35,   0,   {0}},
{0x11,   1, {0x0}},
{REGFLAG_DELAY, 120, {}},
{0x29,   1, {0x0}},
{REGFLAG_DELAY, 20, {}},
{REGFLAG_END_OF_TABLE, 0x00, {}}
};

static struct LCM_setting_table lcm_sleep_out_setting[] = {
	// Sleep Out
	{0x11, 0, {0x00}},
	{REGFLAG_DELAY, 120, {}},

	// Display ON
	{0x29, 0, {0x00}},
	{REGFLAG_DELAY, 50, {}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}
};


static struct LCM_setting_table lcm_sleep_in_setting[] = {
	// Display off sequence
	
	{0x28, 0, {0x00}},
	{REGFLAG_DELAY, 50, {}},

	// Sleep Mode On
	{0x10, 1, {0x00}},
	{REGFLAG_DELAY, 150, {}},

	{0x4f, 0, {0x01}},
	{REGFLAG_DELAY, 150, {}},
	

	{REGFLAG_END_OF_TABLE, 0x00, {}}
};

static void push_table(struct LCM_setting_table *table, unsigned int count,
		unsigned char force_update)
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
			dsi_set_cmdq_V2(cmd, table[i].count,
					table[i].para_list, force_update);
		}
	}

}


// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS * util)
{
	memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}


static void lcm_get_params(LCM_PARAMS *params)
{
		memset(params, 0, sizeof(LCM_PARAMS));

	params->dsi.LANE_NUM = 3;
  params->dsi.packet_size = 256;
  params->dsi.vertical_backporch = 14;
  params->dsi.horizontal_sync_active = 4;
  params->dsi.horizontal_frontporch = 8;
  params->dsi.PLL_CLOCK = 236;
  params->type = 2;
  params->dsi.data_format.format = 2;
  params->dsi.PS = 2;
  params->dsi.vertical_sync_active = 2;
  params->width = 720;
  params->dsi.horizontal_active_pixel = 720;
  params->height = 1280;
  params->dsi.vertical_active_line = 1280;
  params->dbi.te_mode = 0;
  params->dbi.te_edge_polarity = 0;
  params->dsi.data_format.color_order = 0;
  params->dsi.data_format.trans_seq = 0;
  params->dsi.data_format.padding = 0;
  params->dsi.intermediat_buffer_num = 0;
  params->dsi.mode = 1;
  params->dsi.esd_check_enable = 1;
  params->dsi.customization_esd_check_enable = 1;
  params->dsi.cont_clock = 1;
  params->dsi.vertical_frontporch = 16;
  params->dsi.horizontal_backporch = 16;
};

static void lcm_init(void)
{

	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(50);
	SET_RESET_PIN(1);
	MDELAY(120);

	push_table(lcm_initialization_setting,sizeof(lcm_initialization_setting) /sizeof(struct LCM_setting_table), 1);
}

static void lcm_suspend(void)
{
	unsigned int array[16];
	array[0] = 0x00FE1500;
	dsi_set_cmdq(array, 1, 1);
	MDELAY(50);
	array[0] = 0x00011500;
	dsi_set_cmdq(array, 1, 1);
	MDELAY(50);
	array[0] = 0x00280500;
	dsi_set_cmdq(array, 1, 1);
	MDELAY(50);
	array[0] = 0x00100500;
	dsi_set_cmdq(array, 1, 1);
	MDELAY(50);
	array[0] = 0x014F1500;
	dsi_set_cmdq(array, 1, 1);
	MDELAY(50);
}


static void lcm_resume(void)
{   
	lcm_init();
}


static void lcm_update(unsigned int x, unsigned int y,
		unsigned int width, unsigned int height)
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
	data_array[1] =
		(x1_MSB << 24) | (x0_LSB << 16) | (x0_MSB << 8) | 0x2a;
	data_array[2] = (x1_LSB);
	data_array[3] = 0x00053902;
	data_array[4] =
		(y1_MSB << 24) | (y0_LSB << 16) | (y0_MSB << 8) | 0x2b;
	data_array[5] = (y1_LSB);
	data_array[6] = 0x002c3909;

	dsi_set_cmdq(data_array, 7, 0);

}


static unsigned int lcm_compare_id(void)
{
		int array[4];
		char buffer[5];
		char id_high=0;
		char id_low=0;
		int id1=0;
		int id2=0;

		SET_RESET_PIN(1);
		MDELAY(10);
		SET_RESET_PIN(0);
		MDELAY(10);
		SET_RESET_PIN(1);
		MDELAY(200);
		array[0]=0x01FE1500;
		dsi_set_cmdq(array,1, 1);

		array[0] = 0x00013700;
		dsi_set_cmdq(array, 1, 1);
		read_reg_v2(0xde, buffer, 1);

		id_high = buffer[0];
		read_reg_v2(0xdf, buffer, 1);
		id_low = buffer[0];
		id1 = (id_high<<8) | id_low;

		#if defined(BUILD_LK)
		printf("rm68200a %s id1 = 0x%04x, id2 = 0x%04x\n", __func__, id1,id2);
		#else
		printk("rm68200a %s id1 = 0x%04x, id2 = 0x%04x\n", __func__, id1,id2);
		#endif
		return (LCM_RM68200_ID == id1)?1:0;

}
//no use
static unsigned int lcm_esd_recover(void)
{
    unsigned char para = 0;
	unsigned int data_array1[16];

#ifndef BUILD_LK
    printk("RM68190 lcm_esd_recover enter\n");
#endif
    

    SET_RESET_PIN(1);
    MDELAY(10);
    SET_RESET_PIN(0);
    MDELAY(30);
    SET_RESET_PIN(1);
    MDELAY(130);
    #if 0
	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
	MDELAY(10);
	push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);
    	MDELAY(10);
    #else
        lcm_init();
    #endif
   
   data_array1[0]= 0x00320500;
   dsi_set_cmdq(data_array1, 1, 1);
   MDELAY(50);

    return 1;
}
static unsigned int lcm_esd_check(void)
{
    unsigned char buffer[1] ={0};
    //unsigned int data_array[1];
   // data_array[0] = 0x00013700;// read id return two byte,version and id 3 byte 
  // dsi_set_cmdq(&data_array, 1, 1);
   read_reg_v2(0x0a, buffer, 1);
   
#ifndef BUILD_LK
    printk("RM68190 lcm_esd_check enter %x\n",buffer[0]);
#endif
#ifndef BUILD_LK
        if(buffer[0] == 0x9C)
        {
          #ifndef BUILD_LK
          printk("RM68190 lcm_esd_check false \n");
          #endif

            return false;
        }
        else
        {      
           #ifndef BUILD_LK
          printk("RM68190 lcm_esd_check true \n");
          #endif
           //lcm_esd_recover();
            return true;
        }
#endif
}
// ---------------------------------------------------------------------------
//  Get LCM Driver Hooks
// ---------------------------------------------------------------------------
LCM_DRIVER hct_rm68200_dsi_vdo_hd_cpt = 
{
	.name			= "hct_rm68200_dsi_vdo_hd_cpt",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,	
	.compare_id     = lcm_compare_id,	
    .esd_check   	= lcm_esd_check,	
    .esd_recover   	= lcm_esd_recover,	
#if (LCM_DSI_CMD_MODE)
    .update         = lcm_update,
#endif	//wqtao
};

