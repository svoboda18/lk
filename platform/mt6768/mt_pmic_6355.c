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
#include <platform/mt_gpt.h>
#include <platform/mt_pmic_wrap_init.h>
#include <printf.h>
#include <platform/upmu_hw.h>
#include <platform/upmu_common.h>

//==============================================================================
// Global variable
//==============================================================================
int Enable_PMIC_LOG = 1;

CHARGER_TYPE g_ret = CHARGER_UNKNOWN;
int g_charger_in_flag = 0;
int g_first_check=0;

extern int g_R_BAT_SENSE;
extern int g_R_I_SENSE;
extern int g_R_CHARGER_1;
extern int g_R_CHARGER_2;

//==============================================================================
// PMIC-AUXADC related define
//==============================================================================
#define VOLTAGE_FULL_RANGE      1800
#define ADC_PRECISE     32768   // 15 bits

//==============================================================================
// PMIC-AUXADC global variable
//==============================================================================
kal_int32 count_time_out=10000;
void pmic_auxadc_debug(int index);
//==============================================================================
// PMIC access API
//==============================================================================
U32 pmic_read_interface (U32 RegNum, U32 *val, U32 MASK, U32 SHIFT)
{
	U32 return_value = 0;
	U32 pmic_reg = 0;
	U32 rdata;

	//mt_read_byte(RegNum, &pmic_reg);
	return_value= pwrap_wacs2(0, (RegNum), 0, &rdata);
	pmic_reg=rdata;
	if (return_value!=0) {
		dprintf(INFO, "[pmic_read_interface] Reg[%x]= pmic_wrap read data fail\n", RegNum);
		return return_value;
	}
	//dprintf(INFO, "[pmic_read_interface] Reg[%x]=0x%x\n", RegNum, pmic_reg);

	pmic_reg &= (MASK << SHIFT);
	*val = (pmic_reg >> SHIFT);
	//dprintf(INFO, "[pmic_read_interface] val=0x%x\n", *val);

	return return_value;
}

U32 pmic_config_interface (U32 RegNum, U32 val, U32 MASK, U32 SHIFT)
{
	U32 return_value = 0;
	U32 pmic_reg = 0;
	U32 rdata;

	//1. mt_read_byte(RegNum, &pmic_reg);
	return_value= pwrap_wacs2(0, (RegNum), 0, &rdata);
	pmic_reg=rdata;
	if (return_value!=0) {
		dprintf(INFO, "[pmic_config_interface] Reg[%x]= pmic_wrap read data fail\n", RegNum);
		return return_value;
	}
	//dprintf(INFO, "[pmic_config_interface] Reg[%x]=0x%x\n", RegNum, pmic_reg);

	pmic_reg &= ~(MASK << SHIFT);
	pmic_reg |= (val << SHIFT);

	//2. mt_write_byte(RegNum, pmic_reg);
	return_value= pwrap_wacs2(1, (RegNum), pmic_reg, &rdata);
	if (return_value!=0) {
		dprintf(INFO, "[pmic_config_interface] Reg[%x]= pmic_wrap read data fail\n", RegNum);
		return return_value;
	}
	//dprintf(INFO, "[pmic_config_interface] write Reg[%x]=0x%x\n", RegNum, pmic_reg);

#if 0
	//3. Double Check
	//mt_read_byte(RegNum, &pmic_reg);
	return_value= pwrap_wacs2(0, (RegNum), 0, &rdata);
	pmic_reg=rdata;
	if (return_value!=0) {
		dprintf(INFO, "[pmic_config_interface] Reg[%x]= pmic_wrap write data fail\n", RegNum);
		return return_value;
	}
	dprintf(INFO, "[pmic_config_interface] Reg[%x]=0x%x\n", RegNum, pmic_reg);
#endif

	return return_value;
}


void upmu_set_reg_value(kal_uint32 reg, kal_uint32 reg_val)
{
	U32 ret=0;

	ret=pmic_config_interface(reg, reg_val, 0xFFFF, 0x0);
}

void pmic_power_hold(unsigned int hold)
{
	if (hold > 1)
		dprintf(CRITICAL, "[PMIC]POWER_HOLD hold = %d only 0 or 1\n", hold);

	if (hold)
		dprintf(INFO, "[PMIC]POWER_HOLD ON\n");
	else
		dprintf(INFO, "[PMIC]POWER_HOLD OFF\n");

	/* MT6355 must keep power hold */
	pmic_config_interface(PMIC_RG_PWRHOLD_ADDR, hold, PMIC_RG_PWRHOLD_MASK, PMIC_RG_PWRHOLD_SHIFT);
	dprintf(CRITICAL, "[PMIC]MT6355 PowerHold = 0x%x\n", upmu_get_reg_value(MT6355_PPCCTL0));
}

//==============================================================================
// PMIC Usage APIs
//==============================================================================
U32 get_mt6355_pmic_chip_version (void)
{
	U32 ret=0;
	U32 val=0;

	ret=pmic_read_interface( (U32)(MT6355_SWCID),
	                         (&val),
	                         (U32)(PMIC_SWCID_MASK),
	                         (U32)(PMIC_SWCID_SHIFT)
	                       );
	if (ret!=0) dprintf(INFO, "%d", ret);
	return val;
}


kal_uint32 mt6355_upmu_get_rgs_chrdet(void)
{
	kal_uint32 ret=0;
	kal_uint32 val=0;


	ret=pmic_read_interface( (kal_uint32)(MT6355_CHR_CON0),
	                         (&val),
	                         (kal_uint32)(PMIC_RGS_CHRDET_MASK),
	                         (kal_uint32)(PMIC_RGS_CHRDET_SHIFT)
	                       );


	return val;
}

kal_bool upmu_is_chr_det(void)
{
	U32 tmp32=0;

#if 0
	tmp32 = 1; // for bring up
#else
	tmp32 = mt6355_upmu_get_rgs_chrdet();
#endif

	dprintf(CRITICAL, "[upmu_is_chr_det] %d\n", tmp32);

	if (tmp32 == 0) {
		return KAL_FALSE;
	} else {
		return KAL_TRUE;
	}
}

kal_bool pmic_chrdet_status(void)
{
	if ( upmu_is_chr_det() == KAL_TRUE ) {
#ifndef USER_BUILD
		dprintf(INFO, "[pmic_chrdet_status] Charger exist\r\n");
#endif

		return KAL_TRUE;
	} else {
#ifndef USER_BUILD
		dprintf(INFO, "[pmic_chrdet_status] No charger\r\n");
#endif

		return KAL_FALSE;
	}
}

int pmic_detect_powerkey(void)
{
	U32 ret=0;
	U32 val=0;

	ret=pmic_read_interface( (U32)(MT6355_TOPSTATUS),
	                         (&val),
	                         (U32)(PMIC_PWRKEY_DEB_MASK),
	                         (U32)(PMIC_PWRKEY_DEB_SHIFT)
	                       );

	if (Enable_PMIC_LOG>1)
		dprintf(INFO, "%d", ret);

	if (val==1) {
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
	U32 ret=0;
	U32 val=0;

	ret=pmic_read_interface( (U32)(MT6355_TOPSTATUS),
	                         (&val),
	                         (U32)(PMIC_HOMEKEY_DEB_MASK),
	                         (U32)(PMIC_HOMEKEY_DEB_SHIFT)
	                       );

	if (Enable_PMIC_LOG>1)
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

kal_uint32 upmu_get_reg_value(kal_uint32 reg)
{
	U32 ret=0;
	U32 temp_val=0;

	ret=pmic_read_interface(reg, &temp_val, 0xFFFF, 0x0);

	if (Enable_PMIC_LOG>1)
		dprintf(INFO, "%d", ret);

	return temp_val;
}

//==============================================================================
// PMIC Init Code
//==============================================================================
void PMIC_INIT_SETTING_V1(void)
{
	//dprintf(INFO, "[LK_PMIC_INIT_SETTING_V1] Done\n");
}

void PMIC_CUSTOM_SETTING_V1(void)
{
	//dprintf(INFO, "[LK_PMIC_CUSTOM_SETTING_V1] Done\n");
}

void pmic_auxadc_init(void)
{
	/* set 15 bits sample times = 128*/
	pmic_set_register_value(PMIC_AUXADC_AVG_NUM_LARGE, 6); /* 1.28 ms */
	/* set 12 bits sample times  = 8 */
	pmic_set_register_value(PMIC_AUXADC_AVG_NUM_SMALL, 2); /* 0.08 ms */

	/* set channel 0, 7 as 15 bits, others = 12 bits  000001000001*/
	pmic_set_register_value(PMIC_AUXADC_AVG_NUM_SEL, 0x41);

	pmic_set_register_value(PMIC_AUXADC_CK_AON, 0);
	pmic_set_register_value(PMIC_AUXADC_CK_AON_MD, 0);
	pmic_set_register_value(PMIC_AUXADC_CK_AON_GPS, 0);
	pmic_set_register_value(PMIC_AUXADC_DATA_REUSE_SEL, 0);
	pmic_set_register_value(PMIC_AUXADC_DATA_REUSE_EN, 1);

	/* setting of ADC not being reset in Sleep mode */
	pmic_set_register_value(PMIC_RG_STRUP_AUXADC_RSTB_SW, 1);
	pmic_set_register_value(PMIC_RG_STRUP_AUXADC_RSTB_SEL, 1);

}

U32 pmic_init (void)
{
	U32 ret_code = PMIC_TEST_PASS, ret, val;
	U32 i;

	dprintf(INFO, "[pmic_init] LK Start..................\n");
	dprintf(INFO, "[pmic_init] MT6355 CHIP Code = 0x%x\n", get_mt6355_pmic_chip_version());
	/*pmic_auxadc_debug(2);*/
	pmic_auxadc_init();
	PMIC_INIT_SETTING_V1();
	PMIC_CUSTOM_SETTING_V1();

#if 1
	//mt6311_driver_probe();
#endif
	ret = pmic_read_interface(MT6355_TOP_RST_MISC, &val, 0xFFFF, 0x0);
	dprintf(INFO, "[pmic_init] TOP_RST_MISC:0x%x\n",val);

	dprintf(INFO, "[pmic_init] Done\n");
	/*pmic_auxadc_debug(3);*/

	return ret_code;
}

//==============================================================================
// PMIC API for LK : AUXADC
//==============================================================================
#define MT6355_AUXADC_DEBUG(_reg)                                       \
{                                                                       \
        value = pmic_get_register_value(_reg);                          \
	dprintf(INFO, "[%s] %s = 0x%x\n", __func__, #_reg, value);      \
}

void pmic_auxadc_debug(int index)
{
	int value;

	MT6355_AUXADC_DEBUG(PMIC_RG_STRUP_AUXADC_RSTB_SEL);
	MT6355_AUXADC_DEBUG(PMIC_RG_STRUP_AUXADC_RSTB_SW);
	MT6355_AUXADC_DEBUG(PMIC_RG_STRUP_AUXADC_START_SEL);
	MT6355_AUXADC_DEBUG(PMIC_AUXADC_MDRT_DET_EN);
	MT6355_AUXADC_DEBUG(PMIC_AUXADC_MDRT_DET_PRD);
	MT6355_AUXADC_DEBUG(PMIC_AUXADC_MDRT_DET_WKUP_EN);
	MT6355_AUXADC_DEBUG(PMIC_AUXADC_MDRT_DET_SRCLKEN_IND);
	MT6355_AUXADC_DEBUG(PMIC_AUXADC_CK_AON);
	MT6355_AUXADC_DEBUG(PMIC_AUXADC_DATA_REUSE_SEL);
	MT6355_AUXADC_DEBUG(PMIC_AUXADC_DATA_REUSE_EN);
}

struct pmic_auxadc_channel {
	u8 resolution;
	u8 r_val;
	unsigned int channel_rqst;
	unsigned int channel_rdy;
	unsigned int channel_out;
};

struct pmic_auxadc_channel mt6355_auxadc_channel[] = {
	{15, 3, PMIC_AUXADC_RQST_CH0, /* BATADC */
		PMIC_AUXADC_ADC_RDY_CH0_BY_AP, PMIC_AUXADC_ADC_OUT_CH0_BY_AP},
	{12, 1, PMIC_AUXADC_RQST_CH2, /* VCDT */
		PMIC_AUXADC_ADC_RDY_CH2, PMIC_AUXADC_ADC_OUT_CH2},
	{12, 2, PMIC_AUXADC_RQST_CH3, /* BAT TEMP */
		PMIC_AUXADC_ADC_RDY_CH3, PMIC_AUXADC_ADC_OUT_CH3},
	{12, 2, PMIC_AUXADC_RQST_BATID, /* BATID */
		PMIC_AUXADC_ADC_RDY_BATID, PMIC_AUXADC_ADC_OUT_BATID},
	{12, 1, PMIC_AUXADC_RQST_CH11, /* VBIF */
		PMIC_AUXADC_ADC_RDY_CH11, PMIC_AUXADC_ADC_OUT_CH11},
	{12, 1, PMIC_AUXADC_RQST_CH4, /* CHIP TEMP */
		PMIC_AUXADC_ADC_RDY_CH4, PMIC_AUXADC_ADC_OUT_CH4},
	{12, 1, PMIC_AUXADC_RQST_CH4, /* DCXO */
		PMIC_AUXADC_ADC_RDY_CH4, PMIC_AUXADC_ADC_OUT_CH4},
	{12, 1, PMIC_AUXADC_RQST_CH5, /* ACCDET Multi-Key */
		PMIC_AUXADC_ADC_RDY_CH5, PMIC_AUXADC_ADC_OUT_CH5},
	{15, 1, PMIC_AUXADC_RQST_CH7, /* TSX */
		PMIC_AUXADC_ADC_RDY_CH7_BY_AP, PMIC_AUXADC_ADC_OUT_CH7_BY_AP},
	{12, 1, PMIC_AUXADC_RQST_CH9, /* HP OFFSET CAL */
		PMIC_AUXADC_ADC_RDY_CH9, PMIC_AUXADC_ADC_OUT_CH9},
};

int pmic_get_auxadc_value(PMIC_AUXADC_LIST list)
{
	int count = 0;
	signed int adc_result = 0, reg_val = 0;
	struct pmic_auxadc_channel *auxadc_channel;

	if (list < AUXADC_LIST_BATADC && list > AUXADC_LIST_TSX) {
		dprintf(INFO, "[%s] Invalid list(%d)\n", __func__, list);
		return -1;
	}
	auxadc_channel = &mt6355_auxadc_channel[list];

	if (list == AUXADC_LIST_DCXO)
		pmic_set_register_value(PMIC_AUXADC_DCXO_CH4_MUX_AP_SEL, 1);
	if (list == AUXADC_LIST_CHIP_TEMP)
		pmic_set_register_value(PMIC_AUXADC_DCXO_CH4_MUX_AP_SEL, 0);

	pmic_set_register_value(auxadc_channel->channel_rqst, 1);
	udelay(10);

	while (pmic_get_register_value(auxadc_channel->channel_rdy) != 1) {
		udelay(1300);
		if ((count++) > count_time_out) {
			dprintf(INFO, "[%s] (%d) Time out!\n", __func__, list);
			break;
		}
	}
	reg_val = pmic_get_register_value(auxadc_channel->channel_out);

	if (auxadc_channel->resolution == 12)
		adc_result = (reg_val * auxadc_channel->r_val *
				VOLTAGE_FULL_RANGE) / 4096;
	else if (auxadc_channel->resolution == 15)
		adc_result = (reg_val * auxadc_channel->r_val *
				VOLTAGE_FULL_RANGE) / 32768;

	dprintf(INFO, "[%s] reg_val = 0x%x, adc_result = %d\n",
			__func__, reg_val, adc_result);
	return adc_result;
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
	return pmic_get_auxadc_value(AUXADC_LIST_BATADC);
}

#define R_CHARGER_1 330
#define R_CHARGER_2 39


int get_charger_volt(int times)
{
	kal_int32 val;
	val = pmic_get_auxadc_value(AUXADC_LIST_VCDT);
	val = (((R_CHARGER_1+R_CHARGER_2)*100*val)/R_CHARGER_2)/100;
	return val;
}

int get_tbat_volt(int times)
{
	return pmic_get_auxadc_value(AUXADC_LIST_BATTEMP);
}

#define CUST_R_SENSE         68

int get_charging_current(int times)
{
	int ret;
	kal_int32 ADC_I_SENSE=1;   // 1 measure time
	kal_int32 ADC_BAT_SENSE=1; // 1 measure time
	int ICharging=0;

	ADC_I_SENSE=get_i_sense_volt(1);
	ADC_BAT_SENSE=get_bat_sense_volt(1);

	ICharging = (ADC_I_SENSE - ADC_BAT_SENSE )*1000/CUST_R_SENSE;

	return ICharging;
}

void vibr_Enable_HW(void)
{
	dprintf(CRITICAL, "[vibr_Enable_HW] none \n");
}

void vibr_Disable_HW(void)
{
	dprintf(CRITICAL, "[bibr_Disable_HW] none \n");
}

void lcm_Enable_HW(int powerVolt)
{
	dprintf(CRITICAL, "[lcm_Enable_HW] powerVolt=%d none \n", powerVolt);
}

void lcm_Disable_HW(void)
{
	dprintf(CRITICAL, "[lcm_Disable_HW] none \n");
}
