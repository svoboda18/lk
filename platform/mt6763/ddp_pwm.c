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

#define LOG_TAG "PWM"
#include <string.h>
#include <platform/sync_write.h>
#include <cust_leds.h>
#include <debug.h>
#include <platform/ddp_reg.h>
#include <platform/ddp_pwm.h>
#include "platform/ddp_info.h"
#include <platform/disp_drv_log.h>


extern int ddp_enable_module_clock(DISP_MODULE_ENUM module);
extern void udelay(unsigned long usec);

//#define BYPASS_CLK_SOURCE_SETTING

#ifndef CLK_CFG_7
#define CLK_CFG_7 0x100000B0
#endif

#ifndef CLK_CFG_7_SET
#define CLK_CFG_7_SET 0x100000B4
#endif

#ifndef CLK_CFG_7_CLR
#define CLK_CFG_7_CLR 0x100000B8
#endif

#define MUX_UPDATE_ADDR 0x10000004

#define PWM_MSG(fmt, arg...) DISPDBG("[PWM] " fmt "\n", ##arg)

#define PWM_REG_SET(reg, value) do { \
        mt65xx_reg_sync_writel(value, (volatile unsigned int*)(reg)); \
        PWM_MSG("set reg[0x%08x] = 0x%08x", (unsigned int)reg, (unsigned int)value); \
    } while (0)

#define PWM_REG_GET(reg) *((volatile unsigned int*)reg)

#define OSC_REG_SET(reg, value) mt65xx_reg_sync_writel(value, (volatile unsigned int*)(reg))
#define OSC_REG_GET(reg) *((volatile unsigned int*)reg)

#define PWM_DEFAULT_DIV_VALUE 0x0

#define pwm_get_reg_base(id) (DISPSYS_PWM0_BASE)

#define index_of_pwm(id) ((id == DISP_PWM0) ? 0 : 1)

/* ULPOSC control register addr */
#define PLL_OSC_CON0		(0x1000C700)
#define PLL_OSC_CON1		(0x1000C704)
#define OSC_ULPOSC_DBG		(0x10006000)
#define ULPOSC_CON		(0x10006458)
#define FQMTR_CK_EN		(0x10000220)    /* Enable fqmeter reference clk */
#define SET_DIV_CNT		(0x10000104)    /* Set fqmeter div count */
#define AD_OSC_CLK_DBG		(0x1000010c)    /* Select debug for AD_OSC_CLK */
#define FQMTR_OUTPUT		(0x10000224)    /* Check the result [15:0] */
#define DEFAULT_CALI		(0x00AD6E2B)

/* ULPOSC frequency target */
#define ULP_FQMTR_MIDDLE	(0x49D8)
#define ULP_FQMTR_CEIL		(0x513B)
#define ULP_FQMTR_FLOOR		(0x4277)

/* DISP_PWM_MUX setting */
#define DISP_PWM_MUX_SEL_BIT	(27)
#define DISP_PWM_SRC_OSC_D4	(2)
#define DISP_PWM_SRC_OSC_D16 (3)

static bool g_ulposc_cali_done = false;

static int g_pwm_inited = 0;
static disp_pwm_id_t g_pwm_main_id = DISP_PWM0;

static void disp_pwm_ulposc_power_on(void)
{
  /*unlock ulposc control reg, SPM power cfg is set before we use */
	PWM_MSG("disp_pwm_ulposc_power_on : unlock ulposc control reg, ULPOSC_CON_LOCK	  0x%x", PWM_REG_GET(OSC_ULPOSC_DBG));

	PWM_MSG("disp_pwm_ulposc_power_on : before OSC_REG_SET 0x1, ULPOSC_CON	  0x%x", PWM_REG_GET(ULPOSC_CON));
	OSC_REG_SET(ULPOSC_CON	, 0x1);
	PWM_MSG("disp_pwm_ulposc_power_on : after OSC_REG_SET 0x1, ULPOSC_CON	  0x%x", PWM_REG_GET(ULPOSC_CON));
	udelay(30);
	PWM_MSG("disp_pwm_ulposc_power_on : before OSC_REG_SET 0x5, ULPOSC_CON	  0x%x", PWM_REG_GET(ULPOSC_CON));
	OSC_REG_SET(ULPOSC_CON	, 0x5);
	PWM_MSG("disp_pwm_ulposc_power_on : after OSC_REG_SET 0x5, ULPOSC_CON	  0x%x", PWM_REG_GET(ULPOSC_CON));
}

static uint32_t disp_pwm_get_ulposc_meter_val(uint32_t cali_val)
{
	uint32_t result = 0, polling_result = 0;
	uint32_t rsv_fqmtr_ck_en, rsv_div_cnt, rsv_osc_con;

	rsv_fqmtr_ck_en = OSC_REG_GET(FQMTR_CK_EN);

	rsv_osc_con = OSC_REG_GET(PLL_OSC_CON0);
	OSC_REG_SET(PLL_OSC_CON0, (rsv_osc_con & ~0x3F) | cali_val);
	OSC_REG_SET(FQMTR_CK_EN, 0x00001000);
	rsv_div_cnt = OSC_REG_GET(SET_DIV_CNT);
	OSC_REG_SET(SET_DIV_CNT, ~(0xff<<24) & rsv_div_cnt);
	OSC_REG_SET(AD_OSC_CLK_DBG, 0x00260000);
	OSC_REG_SET(FQMTR_CK_EN, 0x00001010);
	do {
		polling_result = OSC_REG_GET(FQMTR_CK_EN) & 0x10;
		udelay(50);
	} while (polling_result != 0);
	result = OSC_REG_GET(FQMTR_OUTPUT) & 0xffff;

	OSC_REG_SET(FQMTR_CK_EN, rsv_fqmtr_ck_en);
	OSC_REG_SET(SET_DIV_CNT, rsv_div_cnt);
	PWM_MSG("get_cali_val 0x%x 0x%x\n", cali_val, result);

	return result;
}

static bool disp_pwm_is_frequency_correct(uint32_t meter_val)
{
	if (meter_val > ULP_FQMTR_FLOOR && meter_val < ULP_FQMTR_CEIL)
		return true;
	else
		return false;
}

static void disp_pwm_cali_done(uint32_t meter_val)
{
	PWM_MSG("final cali_val: 0x%x\n", meter_val);

	g_ulposc_cali_done = true;
}

static void disp_pwm_ulposc_cali(void)
{
	uint32_t cali_val = 0, meter_val = 0;
	uint32_t left = 0x1f, right = 0x3f, middle;
	uint32_t diff_left = 0, diff_right = 0xffff;

	if (g_ulposc_cali_done == true) {
		/* calibration is already done */
		return;
	}

	OSC_REG_SET(PLL_OSC_CON0, DEFAULT_CALI);
	OSC_REG_SET(PLL_OSC_CON1, 0x4);

	disp_pwm_ulposc_power_on();

	cali_val = DEFAULT_CALI & 0x3F;
	meter_val = disp_pwm_get_ulposc_meter_val(cali_val);

	if (disp_pwm_is_frequency_correct(meter_val) == true) {
		disp_pwm_cali_done(meter_val);
		return;
	}

	do {
		middle = (left + right) / 2;
		if (middle == left)
			break;

		cali_val = middle;
		meter_val = disp_pwm_get_ulposc_meter_val(cali_val);

		if (disp_pwm_is_frequency_correct(meter_val) == true) {
			disp_pwm_cali_done(meter_val);
			return;
		} else if (meter_val > ULP_FQMTR_MIDDLE)
			right = middle;
		else
			left = middle;
	} while (left <= right);

	cali_val = left;
	meter_val = disp_pwm_get_ulposc_meter_val(cali_val);
	if (meter_val > ULP_FQMTR_MIDDLE)
		diff_left = meter_val - ULP_FQMTR_MIDDLE;
	else
		diff_left = ULP_FQMTR_MIDDLE - meter_val;

	cali_val = right;
	meter_val = disp_pwm_get_ulposc_meter_val(cali_val);
	if (meter_val > ULP_FQMTR_MIDDLE)
		diff_right = meter_val - ULP_FQMTR_MIDDLE;
	else
		diff_right = ULP_FQMTR_MIDDLE - meter_val;

	if (diff_left < diff_right)
		cali_val = left;
	else
		cali_val = right;
	meter_val = disp_pwm_get_ulposc_meter_val(cali_val);

	disp_pwm_cali_done(meter_val);
}

void disp_pwm_clkmux_update(void)
{
	unsigned int regsrc = PWM_REG_GET(MUX_UPDATE_ADDR);
	regsrc = regsrc | (0x1 << DISP_PWM_MUX_SEL_BIT);
	/* write 1 to update the change of pwm clock source selection */
	PWM_REG_SET(MUX_UPDATE_ADDR, regsrc);
}

void disp_pwm_init(disp_pwm_id_t id)
{
	struct cust_mt65xx_led *cust_led_list;
	struct cust_mt65xx_led *cust;
	struct PWM_config *config_data;
	unsigned int pwm_div;
	unsigned int reg_base = pwm_get_reg_base(id);

	if (g_pwm_inited & id)
		return;

	if (id & DISP_PWM0)
		ddp_enable_module_clock(DISP_MODULE_PWM0);
	if (id & DISP_PWM1)
		ASSERT(0);
#ifndef BYPASS_CLK_SOURCE_SETTING
	disp_pwm_ulposc_cali();
#else
	disp_pwm_ulposc_power_on();
#endif
	pwm_div = PWM_DEFAULT_DIV_VALUE;
	cust_led_list = get_cust_led_list();
	if (cust_led_list) {
		/* WARNING: may overflow if MT65XX_LED_TYPE_LCD not configured properly */
		cust = &cust_led_list[MT65XX_LED_TYPE_LCD];
		if ((strcmp(cust->name,"lcd-backlight") == 0) && (cust->mode == MT65XX_LED_MODE_CUST_BLS_PWM)) {
			config_data = &cust->config_data;
			if (config_data->clock_source >= 0 && config_data->clock_source <= 3) {
				unsigned int reg_val = DISP_REG_GET(CLK_CFG_7);
				PWM_REG_SET(CLK_CFG_7_CLR, 0x3);
				PWM_REG_SET(CLK_CFG_7_SET, 0x3 & config_data->clock_source);
				PWM_MSG("disp_pwm_init : CLK_CFG_7 0x%x => 0x%x", reg_val, PWM_REG_GET(CLK_CFG_7));
			}
			/* Some backlight chip/PMIC(e.g. MT6332) only accept slower clock */
			pwm_div = (config_data->div == 0) ? PWM_DEFAULT_DIV_VALUE : config_data->div;
			pwm_div &= 0x3FF;

			if ((config_data->clock_source == DISP_PWM_SRC_OSC_D4 || config_data->clock_source == DISP_PWM_SRC_OSC_D16)
				&& (pwm_div < 0x3FF)) {
				/* add PWM clock division, due to ULPOSC frequency is too high */
				pwm_div += 1;
			}
			PWM_MSG("disp_pwm_init : PWM config data (%d,%d)", config_data->clock_source, config_data->div);

			/*
			After config clock source register, pwm hardware doesn't switch to new setting yet.
			Api function "disp_pwm_clkmux_update" need to be called for trigger pwm hardware
			to accept new clock source setting.
			*/
			disp_pwm_clkmux_update();
		}
	}

	PWM_REG_SET(reg_base + DISP_PWM_CON_0_OFF, pwm_div << 16);

	PWM_REG_SET(reg_base + DISP_PWM_CON_1_OFF, 1023); /* 1024 levels */

	g_pwm_inited |= id;
}


disp_pwm_id_t disp_pwm_get_main(void)
{
	return g_pwm_main_id;
}


int disp_pwm_is_enabled(disp_pwm_id_t id)
{
	unsigned int reg_base = pwm_get_reg_base(id);
	return (PWM_REG_GET(reg_base + DISP_PWM_EN_OFF) & 0x1);
}


static void disp_pwm_set_enabled(disp_pwm_id_t id, int enabled)
{
	unsigned int reg_base = pwm_get_reg_base(id);
	if (enabled) {
		if (!disp_pwm_is_enabled(id)) {
			PWM_REG_SET(reg_base + DISP_PWM_EN_OFF, 0x1);
			PWM_MSG("disp_pwm_set_enabled: PWN_EN = 0x1");
		}
	} else {
		PWM_REG_SET(reg_base + DISP_PWM_EN_OFF, 0x0);
	}
}


/* For backward compatible */
int disp_bls_set_backlight(int level_256)
{
	int level_1024 = 0;

	if (level_256 <= 0)
		level_1024 = 0;
	else if (level_256 >= 255)
		level_1024 = 1023;
	else {
		level_1024 = (level_256 << 2) + 2;
	}

	return disp_pwm_set_backlight(disp_pwm_get_main(), level_1024);
}


static int disp_pwm_level_remap(disp_pwm_id_t id, int level_1024)
{
	return level_1024;
}


int disp_pwm_set_backlight(disp_pwm_id_t id, int level_1024)
{
	unsigned int reg_base;
	unsigned int offset;

	if ((DISP_PWM_ALL & id) == 0) {
		PWM_MSG("[ERROR] disp_pwm_set_backlight: invalid PWM ID = 0x%x", id);
		return -1;
	}

	disp_pwm_init(id);

	PWM_MSG("disp_pwm_set_backlight(id = 0x%x, level_1024 = %d)", id, level_1024);

	reg_base = pwm_get_reg_base(id);

	level_1024 = disp_pwm_level_remap(id, level_1024);

	PWM_REG_SET(reg_base + DISP_PWM_COMMIT_OFF, 0);
	PWM_REG_SET(reg_base + DISP_PWM_CON_1_OFF, (level_1024 << 16) | 0x3ff);

	if (level_1024 > 0) {
		disp_pwm_set_enabled(id, 1);
	} else {
		disp_pwm_set_enabled(id, 0); /* To save power */
	}

	PWM_REG_SET(reg_base + DISP_PWM_COMMIT_OFF, 1);
	PWM_REG_SET(reg_base + DISP_PWM_COMMIT_OFF, 0);

	for (offset = 0x0; offset <= 0x28; offset += 4) {
		PWM_MSG("reg[0x%08x] = 0x%08x", (reg_base + offset), PWM_REG_GET(reg_base + offset));
	}

	return 0;
}


