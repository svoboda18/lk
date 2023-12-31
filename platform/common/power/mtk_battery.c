/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */

/* MediaTek Inc. (C) 2017. All rights reserved.
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

#include <target/board.h>
#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_pmic.h>
#include <platform/mt_pmic_dlpt.h>
#include <platform/upmu_hw.h>
#include <platform/upmu_common.h>
#include <platform/boot_mode.h>
#include <platform/mt_gpt.h>
#include <platform/mt_rtc.h>
#include <platform/mt_rtc_hw.h>
#include <platform/mt_pmic_wrap_init.h>
#include <platform/mt_leds.h>
#include <printf.h>
#include <sys/types.h>
#include <platform/mt_battery.h>
#include <mtk_battery.h>
#include <mtk_charger.h>
#include <libfdt.h>
#include <lk_builtin_dtb.h>

/*****************************************************************************
 *  global Variable
 ****************************************************************************/
bool g_fg_is_charging = 0;
bool g_isbat_init = 0;
struct fuel_gauge_custom_data fg_cust_data;
/*****************************************************************************
 *  Externl Variable
 ****************************************************************************/
extern bool g_boot_menu;
extern int fg_swocv_v;
extern int fg_swocv_i;
extern int shutdown_time;
extern int boot_voltage;

bool mtk_bat_allow_backlight_enable(void)
{
	int bat_vol = 0;
	bat_vol = get_bat_volt(1);
	if (bat_vol > (BATTERY_LOWVOL_THRESOLD + 150))
		return true;
	return false;
}

void gauge_read_IM_current(void *data)
{
	if (g_isbat_init == 0)
		mtk_battery_init();

	fgauge_read_IM_current(data);
}

int mtk_battery_init(void)
{
	init_bat_cust_data();
	init_bat_cust_data_dt();

	if(is_disable_bat())
		dis_gm3_src_sel(true);

	return 0;
}

void check_sw_ocv(void)
{
	unsigned int ptim_bat_vol = 0;
	signed int ptim_R_curr = 0;
	int bat_vol;

	mtk_battery_init();

	if(!is_disable_bat()) {
		shutdown_time = g_boot_arg->shutdown_time;
		boot_voltage = g_boot_arg->boot_voltage;

		charger_enable_charging(false);
		bat_vol = get_bat_volt(1);

		if (upmu_is_chr_det() == true)
			mdelay(50);

		do_ptim_gauge(&ptim_bat_vol, &ptim_R_curr);

		fg_swocv_v = ptim_bat_vol;
		if (g_fg_is_charging == true)
			fg_swocv_i = ptim_R_curr;
		else
			fg_swocv_i = -ptim_R_curr;

		dprintf(CRITICAL, "[check_sw_ocv]%d ptim[%d %d] fg_swocv[%d %d] boot_vbat:%d shutdowntime:%d vbat:%d tmp:%d\n",
			g_fg_is_charging, ptim_bat_vol, ptim_R_curr, fg_swocv_v, fg_swocv_i,
			g_boot_arg->boot_voltage, g_boot_arg->shutdown_time, bat_vol, force_get_tbat(true));

		charger_enable_charging(true);
	}
}



int BattThermistorConverTemp(int Res)
{
	int i = 0;
	int RES1 = 0, RES2 = 0;
	int TBatt_Value = -200, TMP1 = 0, TMP2 = 0;

	if (Res >= Fg_Temperature_Table[0].TemperatureR) {
		TBatt_Value = -40;
	} else if (Res <= Fg_Temperature_Table[20].TemperatureR) {
		TBatt_Value = 60;
	} else {
		RES1 = Fg_Temperature_Table[0].TemperatureR;
		TMP1 = Fg_Temperature_Table[0].BatteryTemp;

		for (i = 0; i <= 20; i++) {
			if (Res >= Fg_Temperature_Table[i].TemperatureR) {
				RES2 = Fg_Temperature_Table[i].TemperatureR;
				TMP2 = Fg_Temperature_Table[i].BatteryTemp;
				break;
			}
			{	/* hidden else */
				RES1 = Fg_Temperature_Table[i].TemperatureR;
				TMP1 = Fg_Temperature_Table[i].BatteryTemp;
			}
		}

		TBatt_Value = (((Res - RES2) * TMP1) + ((RES1 - Res) * TMP2)) / (RES1 - RES2);
	}
	dprintf(INFO, "[BattThermistorConverTemp] %d %d %d %d %d %d\n", RES1, RES2, Res, TMP1, TMP2, TBatt_Value);

	return TBatt_Value;
}


int BattVoltToTemp(int dwVolt, int volt_cali)
{
	long long TRes_temp;
	long long TRes;
	int sBaTTMP = -100;

	int vbif28 = RBAT_PULL_UP_VOLT;	/* 2 side: BattVoltToTemp, TempToBattVolt */
	int delta_v;

	TRes_temp = (RBAT_PULL_UP_R * (long long) dwVolt);
#ifdef RBAT_PULL_UP_VOLT_BY_BIF
	vbif28 = pmic_get_auxadc_value(AUXADC_LIST_VBIF) + volt_cali;
	/* delta_v = abs(vbif28 - dwVolt); */
	delta_v = vbif28 - dwVolt;

	if(delta_v < 0)
		delta_v = delta_v * -1;

	/* avoid divide 0 case */
	if (delta_v == 0)
		delta_v = 1;

	/*do_div(TRes_temp, delta_v); */
	TRes_temp = TRes_temp / delta_v;

	if (vbif28 > 3000 || vbif28 < 2500)
		dprintf(CRITICAL, "[RBAT_PULL_UP_VOLT_BY_BIF] vbif28:%d\n", pmic_get_auxadc_value(AUXADC_LIST_VBIF));
#else
	/* delta_v = abs(RBAT_PULL_UP_VOLT - dwVolt); */
	delta_v = RBAT_PULL_UP_VOLT - dwVolt;
	if(delta_v < 0)
		delta_v = delta_v * -1;

	if (delta_v == 0)
		delta_v = 1;

	/* do_div(TRes_temp, delta_v); */
	TRes_temp = TRes_temp / delta_v;
#endif

#ifdef RBAT_PULL_DOWN_R
	TRes = (TRes_temp * RBAT_PULL_DOWN_R);
	/* do_div(TRes, abs(RBAT_PULL_DOWN_R - TRes_temp)); */

	if ( (RBAT_PULL_DOWN_R - TRes_temp) > 0 )
		TRes = TRes / (RBAT_PULL_DOWN_R - TRes_temp);
	else if( (RBAT_PULL_DOWN_R - TRes_temp) < 0)
		TRes = TRes / (RBAT_PULL_DOWN_R - TRes_temp) * -1;
	else if ((RBAT_PULL_DOWN_R - TRes_temp) == 0)
		TRes = TRes;

#else
	TRes = TRes_temp;
#endif

	/* convert register to temperature */
	if (!pmic_is_bif_exist())
		sBaTTMP = BattThermistorConverTemp((int)TRes);
	else
		sBaTTMP = BattThermistorConverTemp((int)TRes - BIF_NTC_R);

	dprintf(INFO, "[BattVoltToTemp] %d %d %d %d\n", dwVolt, RBAT_PULL_UP_R, vbif28, volt_cali);
	return sBaTTMP;
}


int force_get_tbat(bool update)
{
	int bat_temper_volt = 1;
	int bat_temper_value = 0;
	static int pre_bat_temper_val = -1;
	int fg_r_value = 0;
	int fg_meter_res_value = 0;
	int fg_current_temp = 0;
	bool fg_current_state = 0;
	int bat_temper_volt_temp = 0;
	int vol_cali = 0;

	static int pre_bat_temper_volt_temp, pre_bat_temper_volt;
	static int pre_fg_current_temp;
	static int pre_fg_current_state;
	static int pre_fg_r_value;
	static int pre_bat_temper_val2;

	if (g_isbat_init == 0) {
		dprintf(CRITICAL, "[force_get_tbat] ERROR! bat not init!\n");
		return 25;
	}

	if(is_disable_bat())
		return 25;

	if (update == true || pre_bat_temper_val == -1) {
		/* Get V_BAT_Temperature */
		bat_temper_volt = pmic_get_v_bat_temp();

		if (bat_temper_volt != 0) {
			fg_r_value = fg_cust_data.r_fg_value;
			fg_meter_res_value = fg_cust_data.fg_meter_resistance;

			gauge_get_current(&fg_current_state, &fg_current_temp);
			fg_current_temp = fg_current_temp / 10;

			if (fg_current_state == 1) {
				bat_temper_volt_temp = bat_temper_volt;
				bat_temper_volt =
				bat_temper_volt - ((fg_current_temp * (fg_meter_res_value + fg_r_value)) / 10000);
				vol_cali = -((fg_current_temp * (fg_meter_res_value + fg_r_value)) / 10000);
			} else {
				bat_temper_volt_temp = bat_temper_volt;
				bat_temper_volt =
				bat_temper_volt + ((fg_current_temp * (fg_meter_res_value + fg_r_value)) / 10000);
				vol_cali = ((fg_current_temp * (fg_meter_res_value + fg_r_value)) / 10000);
			}

			bat_temper_value = BattVoltToTemp(bat_temper_volt, vol_cali);
		}

#ifdef CONFIG_MTK_BIF_SUPPORT
		/*	battery_charging_control(CHARGING_CMD_GET_BIF_TBAT, &bat_temper_value); */
#endif
		dprintf(CRITICAL, "[force_get_tbat] %d,%d,%d,%d,%d,temp:%d r:%d %d\n",
		bat_temper_volt_temp, bat_temper_volt,
		fg_current_state, fg_current_temp,
		fg_r_value, bat_temper_value,
		fg_meter_res_value, fg_r_value);

		if (pre_bat_temper_val2 == 0) {
			pre_bat_temper_volt_temp = bat_temper_volt_temp;
			pre_bat_temper_volt = bat_temper_volt;
			pre_fg_current_temp = fg_current_temp;
			pre_fg_current_state = fg_current_state;
			pre_fg_r_value = fg_r_value;
			pre_bat_temper_val2 = bat_temper_value;
		} else {

			pre_bat_temper_volt_temp = bat_temper_volt_temp;
			pre_bat_temper_volt = bat_temper_volt;
			pre_fg_current_temp = fg_current_temp;
			pre_fg_current_state = fg_current_state;
			pre_fg_r_value = fg_r_value;
			pre_bat_temper_val2 = bat_temper_value;
			dprintf(INFO, "[force_get_tbat] current:%d,%d,%d,%d,%d,%d pre:%d,%d,%d,%d,%d,%d\n",
			bat_temper_volt_temp, bat_temper_volt, fg_current_state, fg_current_temp,
			fg_r_value, bat_temper_value, pre_bat_temper_volt_temp, pre_bat_temper_volt,
			pre_fg_current_state, pre_fg_current_temp, pre_fg_r_value,
			pre_bat_temper_val2);
		}
	} else {
		bat_temper_value = pre_bat_temper_val;
	}

	return bat_temper_value;
}

void init_bat_cust_data(void)
{
	fg_cust_data.disable_mtkbattery = 0;
	fg_cust_data.car_tune_value = CAR_TUNE_VALUE;
	fg_cust_data.fg_meter_resistance = FG_METER_RESISTANCE;
	fg_cust_data.r_fg_value = R_FG_VALUE;
	fg_cust_data.pmic_min_vol = PMIC_MIN_VOL;
	fg_cust_data.poweron_system_iboot = POWERON_SYSTEM_IBOOT;
	g_isbat_init = 1;
	/* dprintf(CRITICAL, "[init_bat_cust_data] done!!\n"); */
}

int init_bat_cust_data_dt(void)
{
	int offset, val;
	offset = fdt_node_offset_by_compatible(get_lk_overlayed_dtb(), -1, "mediatek,bat_gm30");
	if (offset >= 0) {
		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "DISABLE_MTKBATTERY");
		if (val)
			fg_cust_data.disable_mtkbattery = val;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "CAR_TUNE_VALUE");
		if (val)
			fg_cust_data.car_tune_value = val * UNIT_TRANS_10;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "FG_METER_RESISTANCE");
		if (val)
			fg_cust_data.fg_meter_resistance = val;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "R_FG_VALUE");
		if (val)
			fg_cust_data.r_fg_value = val * UNIT_TRANS_10;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "PMIC_MIN_VOL");
		if (val)
			fg_cust_data.pmic_min_vol = val;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "POWERON_SYSTEM_IBOOT");
		if (val)
			fg_cust_data.poweron_system_iboot = val;


		dprintf(CRITICAL,"[%s]disable:%d, car_tune:%d,fg_meter_r %d,rfg:%d, gauge0[%d %d]\n",
			__func__, fg_cust_data.disable_mtkbattery, fg_cust_data.car_tune_value,
			fg_cust_data.fg_meter_resistance, fg_cust_data.r_fg_value,
			fg_cust_data.pmic_min_vol, fg_cust_data.poweron_system_iboot);

		g_isbat_init = 1;
		return 0;
	} else {
		dprintf(CRITICAL, "[%s]: battery:no device tree !use default values\n", __func__);
		return 1;
	}

}

bool pmic_is_bif_exist(void)
{
	return false;
}

int pmic_get_v_bat_temp(void)
{
	int adc = 0;
	bool is_disable = is_disable_bat();

	if (is_disable)
		return adc;

	adc = pmic_get_auxadc_value(AUXADC_LIST_BATTEMP);
	return adc;
}

bool is_disable_bat(void)
{
	return fg_cust_data.disable_mtkbattery;
}


int gauge_get_current(bool *is_charging, int *battery_current)
{
	fgauge_get_current(is_charging, battery_current);
	return 0;
}

