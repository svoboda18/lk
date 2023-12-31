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

#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_pmic.h>
#include <platform/mt_rtc.h>
#include <platform/mt_gpt.h>
#include <platform/mt_pmic_wrap_init.h>
#include <platform/primary_display.h>
#include <printf.h>
#include <platform/upmu_hw.h>
#include <platform/upmu_common.h>
#ifdef MTK_CHARGER_NEW_ARCH
#include <mtk_charger.h>
#endif
#ifdef MTK_MT6360_PMIC_SUPPORT
#include <mt6360_pmic.h>
#endif /* MTK_MT6360_PMIC_SUPPORT */
#include "log_store_lk.h"

//==============================================================================
// Global variable
//==============================================================================
int Enable_PMIC_LOG = 1;

CHARGER_TYPE g_ret = CHARGER_UNKNOWN;
int g_charger_in_flag = 0;
int g_first_check = 0;
unsigned int g_is_smart_rst;
unsigned int g_has_bat_removed;

extern int g_R_BAT_SENSE;
extern int g_R_I_SENSE;
extern int g_R_CHARGER_1;
extern int g_R_CHARGER_2;

//==============================================================================
// PMIC-AUXADC related define
//==============================================================================
#define VOLT_FULL	1800

//==============================================================================
// PMIC-AUXADC global variable
//==============================================================================
kal_int32 count_time_out = 100;
void pmic_auxadc_debug(int index);
//==============================================================================
// PMIC access API
//==============================================================================
U32 pmic_read_interface(U32 RegNum, U32 *val, U32 MASK, U32 SHIFT)
{
	U32 return_value = 0;
	U32 pmic_reg = 0;

	return_value = pwrap_read(RegNum, &pmic_reg);
	if (return_value != 0) {
		dprintf(CRITICAL, "[pmic_read_interface] Reg[0x%x]= pmic_wrap read data fail\n", RegNum);
		return return_value;
	}
	//dprintf(INFO, "[pmic_read_interface] Reg[%x]=0x%x\n", RegNum, pmic_reg);

	pmic_reg &= (MASK << SHIFT);
	*val = (pmic_reg >> SHIFT);
	//dprintf(INFO, "[pmic_read_interface] val=0x%x\n", *val);

	return return_value;
}

U32 pmic_config_interface(U32 RegNum, U32 val, U32 MASK, U32 SHIFT)
{
	U32 return_value = 0;
	U32 pmic_reg = 0;

	return_value = pwrap_read(RegNum, &pmic_reg);
	if (return_value != 0) {
		dprintf(CRITICAL, "[pmic_config_interface] Reg[0x%x]= pmic_wrap read data fail\n", RegNum);
		return return_value;
	}
	//dprintf(INFO, "[pmic_config_interface] Reg[%x]=0x%x\n", RegNum, pmic_reg);

	pmic_reg &= ~(MASK << SHIFT);
	pmic_reg |= (val << SHIFT);

	return_value = pwrap_write(RegNum, pmic_reg);

	if (return_value != 0) {
		dprintf(CRITICAL, "[pmic_config_interface] Reg[0x%x]= pmic_wrap write data fail\n", RegNum);
		return return_value;
	}
	//dprintf(INFO, "[pmic_config_interface] write Reg[%x]=0x%x\n", RegNum, pmic_reg);

	return return_value;
}

U32 upmu_get_reg_value(U32 reg)
{
	U32 ret = 0;
	U32 temp_val = 0;

	ret = pmic_read_interface(reg, &temp_val, 0xFFFF, 0x0);
	if (Enable_PMIC_LOG > 1)
		dprintf(INFO, "%d", ret);

	return temp_val;
}

U32 upmu_set_reg_value(U32 reg, U32 reg_val)
{
	U32 ret = 0;

	ret = pmic_config_interface(reg, reg_val, 0xFFFF, 0x0);

	return ret;
}

//==============================================================================
// PMIC Exported APIs
//==============================================================================
void pmic_cold_reset(void)
{
#ifdef MTK_MT6360_PMIC_SUPPORT
	mt6360_pmic_enable_poweroff_seq(true);
#endif /* MTK_MT6360_PMIC_SUPPORT */
	pmic_set_register_value(PMIC_RG_CRST, 1);
}

unsigned int pmic_power_hold(unsigned int hold)
{
	if (hold > 1) {
		dprintf(CRITICAL, "[PMIC]POWER_HOLD hold = %d only 0 or 1\n", hold);
		return 1;
	}

	if (hold)
		dprintf(INFO, "[PMIC]POWER_HOLD ON\n");
	else
		dprintf(INFO, "[PMIC]POWER_HOLD OFF\n");
	pmic_config_interface(PMIC_RG_PWRHOLD_ADDR, hold,
		PMIC_RG_PWRHOLD_MASK, PMIC_RG_PWRHOLD_SHIFT);

	dprintf(INFO, "[PMIC] PowerHold = 0x%x\n", pmic_get_register_value(PMIC_RG_PWRHOLD));
	return 0;
}

const char *smart_reset_check(void)
{
	if (g_is_smart_rst)
		return "SMART RESET: TRUE";
	return "SMART RESET: FALSE";
}

void mt_power_off(void)
{
#ifdef MTK_MT6360_PMIC_SUPPORT
	mt6360_pmic_enable_poweroff_seq(true);
#endif /* MTK_MT6360_PMIC_SUPPORT */

#ifndef NO_POWER_OFF
	dprintf(CRITICAL, "mt_power_off new\n");

	primary_display_suspend();
	/*save pl lk log to analyze exception power off case */
	save_pllk_log();

#ifdef MTK_CHARGER_NEW_ARCH
	charger_enable_wdt(false);
#endif
	rtc_bbpu_power_down();
#endif

}

//==============================================================================
// PMIC Usage APIs
//==============================================================================
bool get_powerkey_pressed_status(void)
{
	unsigned short val;

	val = pmic_get_register_value(PMIC_RG_INT_STATUS_PWRKEY);
	if (val)
		return true;
	return false;
}

void clear_powerkey_pressed_status(void)
{
	pmic_set_register_value(PMIC_RG_INT_STATUS_PWRKEY, 1);
}

U32 get_pmic_chip_version(void)
{
	U32 val = 0;

	val = pmic_get_register_value(PMIC_SWCID);
	return val;
}

U32 pmic_upmu_get_rgs_chrdet(void)
{
	U32 ret = 0;
	U32 val = 0;

	ret = pmic_read_interface((U32)(PMIC_RGS_CHRDET_ADDR), (&val),
		(U32)(PMIC_RGS_CHRDET_MASK),
		(U32)(PMIC_RGS_CHRDET_SHIFT));
	if (ret != 0)
		dprintf(CRITICAL, "[%s] error return value: %d\n", __func__, ret);
	return val;
}

kal_bool upmu_is_chr_det(void)
{
	U32 tmp32=0;

#if 0
	tmp32 = 1; // for bring up
#else
	tmp32 = pmic_upmu_get_rgs_chrdet();
#endif

	dprintf(CRITICAL, "[upmu_is_chr_det] %d\n", tmp32);

	if (tmp32 == 0) {
		return KAL_FALSE;
	} else {
		return KAL_TRUE;
	}
}

/*
 * same as upmu_is_chr_det, this API is used for legacy mt6575_power_off
 * Must be removed after mt_power_off is defined
 */
kal_bool pmic_chrdet_status(void)
{
	return upmu_is_chr_det();
}

int pmic_detect_powerkey(void)
{
	U32 ret = 0;
	U32 val = 0;

	ret = pmic_read_interface((U32)(PMIC_PWRKEY_DEB_ADDR), (&val),
		(U32)(PMIC_PWRKEY_DEB_MASK),
		(U32)(PMIC_PWRKEY_DEB_SHIFT));

	if (Enable_PMIC_LOG > 1)
		dprintf(INFO, "%d", ret);

	if (val == 1) {
#ifndef USER_BUILD
		dprintf(INFO, "LK pmic powerkey Release\n");
#endif
		return 0;
	} else {
#ifndef USER_BUILD
		dprintf(INFO, "LK pmic powerkey Press\n");
#endif
		return 1;
	}
}

int pmic_detect_homekey(void)
{
	U32 ret = 0;
	U32 val = 0;

	ret = pmic_read_interface((U32)(PMIC_HOMEKEY_DEB_ADDR), (&val),
		(U32)(PMIC_HOMEKEY_DEB_MASK),
		(U32)(PMIC_HOMEKEY_DEB_SHIFT));

	if (Enable_PMIC_LOG > 1)
		dprintf(INFO, "%d", ret);

	if (val==1) {
#ifndef USER_BUILD
		dprintf(INFO, "LK pmic HOMEKEY Release\n");
#endif
		return 0;
	} else {
#ifndef USER_BUILD
		dprintf(INFO, "LK pmic HOMEKEY Press\n");
#endif
		return 1;
	}
}

static void pwrkey_dbg_status(void)
{
	U32 val = 0;

	pmic_read_interface(PMIC_PWRKEY_LONG_PRESS_COUNT_ADDR, &val,
			    PMIC_PWRKEY_LONG_PRESS_COUNT_MASK,
			    PMIC_PWRKEY_LONG_PRESS_COUNT_SHIFT);


	dprintf(INFO, "[%s] lk powerkey:%d count=%d(ms)\n"
		     , __func__
		     , pmic_detect_powerkey()
		     , val << 5);
}

//==============================================================================
// PMIC Init Code
//==============================================================================
U32 pmic_init (void)
{
	U32 ret_code = PMIC_TEST_PASS;

	if ((upmu_get_reg_value(MT6359_TOP_RST_STATUS) & 0x7) != 0x7)
		g_has_bat_removed = 1;
	upmu_set_reg_value(MT6359_TOP_RST_STATUS, 0x4F);
	if (g_has_bat_removed)
		cmdline_append("has_battery_removed=1");
	else
		cmdline_append("has_battery_removed=0");

	g_is_smart_rst = pmic_get_register_value(PMIC_JUST_SMART_RST);
	if (g_is_smart_rst) {
		pmic_set_register_value(PMIC_RG_CLR_JUST_SMART_RST, 1);
		udelay(62);
		pmic_set_register_value(PMIC_RG_CLR_JUST_SMART_RST, 0);
	}
	dprintf(INFO, "[pmic_init] PMIC CHIP Code = 0x%x, Done\n",
		get_pmic_chip_version());

	pwrkey_dbg_status();

	return ret_code;
}

//==============================================================================
// PMIC API for LK : AUXADC
//==============================================================================
#define PMIC_AUXADC_DEBUG(_reg)		\
{	\
	value = pmic_get_register_value(_reg);	\
	dprintf(INFO, "[%s] %s = 0x%x\n", __func__, #_reg, value);	\
}

void pmic_auxadc_debug(int index)
{
	int value;

	PMIC_AUXADC_DEBUG(PMIC_RG_HK_STRUP_AUXADC_RSTB_SEL);
	PMIC_AUXADC_DEBUG(PMIC_RG_HK_STRUP_AUXADC_RSTB_SW);
	PMIC_AUXADC_DEBUG(PMIC_RG_HK_STRUP_AUXADC_START_SEL);
	PMIC_AUXADC_DEBUG(PMIC_AUXADC_MDRT_DET_EN);
	PMIC_AUXADC_DEBUG(PMIC_AUXADC_MDRT_DET_PRD_SEL);
	PMIC_AUXADC_DEBUG(PMIC_AUXADC_MDRT_DET_WKUP_EN);
	PMIC_AUXADC_DEBUG(PMIC_AUXADC_MDRT_DET_SRCLKEN_IND);
	PMIC_AUXADC_DEBUG(PMIC_AUXADC_CK_AON);
	PMIC_AUXADC_DEBUG(PMIC_AUXADC_DATA_REUSE_SEL);
	PMIC_AUXADC_DEBUG(PMIC_AUXADC_DATA_REUSE_EN);
}

/* extend r_val to 10 times from PMIC MT6359 */
struct pmic_auxadc_channel_new pmic_auxadc_channel[] = {
	/* BATADC */
	PMIC_AUXADC_GEN(15, 35, 0, PMIC_AUXADC_RQST_CH0,
		PMIC_AUXADC_ADC_RDY_CH0_BY_AP, PMIC_AUXADC_ADC_OUT_CH0_BY_AP),
	/* BAT TEMP */
	PMIC_AUXADC_GEN(12, 25, 3, PMIC_AUXADC_RQST_CH3,
		PMIC_AUXADC_ADC_RDY_CH3, PMIC_AUXADC_ADC_OUT_CH3),
	/* CHIP TEMP */
	PMIC_AUXADC_GEN(12, 10, 4, PMIC_AUXADC_RQST_CH4,
		PMIC_AUXADC_ADC_RDY_CH4, PMIC_AUXADC_ADC_OUT_CH4),
	/* VCORE_TEMP */
	PMIC_AUXADC_GEN(12, 10, 4, PMIC_AUXADC_RQST_CH4_BY_THR1,
		PMIC_AUXADC_ADC_RDY_CH4_BY_THR1, PMIC_AUXADC_ADC_OUT_CH4_BY_THR1),
	/* VPROC_TEMP */
	PMIC_AUXADC_GEN(12, 10, 4, PMIC_AUXADC_RQST_CH4_BY_THR2,
		PMIC_AUXADC_ADC_RDY_CH4_BY_THR2, PMIC_AUXADC_ADC_OUT_CH4_BY_THR2),
	/* VGPU_TEMP */
	PMIC_AUXADC_GEN(12, 10, 4, PMIC_AUXADC_RQST_CH4_BY_THR3,
		PMIC_AUXADC_ADC_RDY_CH4_BY_THR3, PMIC_AUXADC_ADC_OUT_CH4_BY_THR3),
	/* ACCDET Multi-Key */
	PMIC_AUXADC_GEN(12, 10, 5, PMIC_AUXADC_RQST_CH5,
		PMIC_AUXADC_ADC_RDY_CH5, PMIC_AUXADC_ADC_OUT_CH5),
	/* DCXO voltage */
	PMIC_AUXADC_GEN(12, 15, 6, PMIC_AUXADC_RQST_CH6,
		PMIC_AUXADC_ADC_RDY_CH6, PMIC_AUXADC_ADC_OUT_CH6),
	/* TSX TEMP(GPS) */
	PMIC_AUXADC_GEN(15, 10, 7, PMIC_AUXADC_RQST_CH7_BY_GPS,
		PMIC_AUXADC_ADC_RDY_CH7_BY_GPS, PMIC_AUXADC_ADC_OUT_CH7_BY_GPS),
	/* HP OFFSET CAL */
	PMIC_AUXADC_GEN(15, 10, 9, PMIC_AUXADC_RQST_CH9,
		PMIC_AUXADC_ADC_RDY_CH9, PMIC_AUXADC_ADC_OUT_CH9),
	/* DCXO TEMP */
	PMIC_AUXADC_GEN(15, 10, 10, PMIC_AUXADC_RQST_DCXO_BY_GPS,
		PMIC_AUXADC_ADC_RDY_DCXO_BY_GPS, PMIC_AUXADC_ADC_OUT_DCXO_BY_GPS),
	/* VBIF */
	PMIC_AUXADC_GEN(12, 25, 11, PMIC_AUXADC_RQST_CH11,
		PMIC_AUXADC_ADC_RDY_CH11, PMIC_AUXADC_ADC_OUT_CH11),
};

bool is_isense_supported(void)
{
	/* PMIC MT6359 does not support ISENSE */
	return false;
}

int pmic_get_auxadc_value(unsigned short channel)
{
	int count = 0;
	signed int adc_result = 0, reg_val = 0;
	struct pmic_auxadc_channel_new *auxadc_channel;

	if (channel >= AUXADC_LIST_MAX) {
		dprintf(INFO, "[%s] Invalid channel(%d)\n", __func__, channel);
		return -1;
	}
	auxadc_channel = &pmic_auxadc_channel[channel];

	pmic_set_register_value(auxadc_channel->channel_rqst, 1);
	udelay(10);

	while (pmic_get_register_value(auxadc_channel->channel_rdy) != 1) {
		udelay(1300);
		count++;
		if (count > count_time_out) {
			dprintf(INFO, "[%s] (%d) Time out!\n",
				__func__, auxadc_channel->ch_num);
			break;
		}
	}
	reg_val = pmic_get_register_value(auxadc_channel->channel_out);

	/* Audio request HPOFS to return raw data */
	if (channel == AUXADC_LIST_HPOFS_CAL)
		adc_result = reg_val;
	else
		adc_result = ((reg_val * auxadc_channel->r_val * VOLT_FULL) / 10)
				>> auxadc_channel->resolution;

	dprintf(INFO, "[%s] channel = %d, reg_val = 0x%x, adc_result = %d\n",
			__func__, auxadc_channel->ch_num, reg_val, adc_result);
	return adc_result;
}

unsigned int pmic_get_auxadc_r_val(unsigned short channel)
{
	struct pmic_auxadc_channel_new *auxadc_channel;

	if (channel >= AUXADC_LIST_MAX) {
		dprintf(INFO, "[%s] Invalid channel(%d)\n", __func__, channel);
		return -1;
	}
	auxadc_channel = &pmic_auxadc_channel[channel];

	return auxadc_channel->r_val;
}

//==============================================================================
// PMIC-AUXADC
//==============================================================================



int get_bat_sense_volt(int times)
{
	return pmic_get_auxadc_value(AUXADC_LIST_BATADC);
}

int get_i_sense_volt(int times)
{
	if (is_isense_supported())
		return pmic_get_auxadc_value(AUXADC_LIST_ISENSE);
	else
		return pmic_get_auxadc_value(AUXADC_LIST_BATADC);
}

int get_tbat_volt(int times)
{
	return pmic_get_auxadc_value(AUXADC_LIST_BATTEMP);
}
