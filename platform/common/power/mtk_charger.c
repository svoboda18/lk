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
#include <kernel/thread.h>
#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_pmic.h>
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
#include <target/cust_battery.h>
#include <libfdt.h>
#include <lk_builtin_dtb.h>
#include "mt_pumpexpress.h"
#include "mtk_battery.h"
#include "mtk_charger.h"
#include "mtk_charger_intf.h"
#include "tcpc_subpmic.h"

#define MAX_SLEEP_LOOP 20
#define VBUS_CHECK_COUNT 3

static struct mtk_charger_info *primary_mchr;

/*****************************************************************************
 *  Global Variable
 ****************************************************************************/
bool enable_mtk_charger = false;
bool g_boot_reason_change = false;
struct charger_custom_data chr_cust_data;

/*****************************************************************************
 *  Externl Variable
 ****************************************************************************/
extern bool g_boot_menu;
extern void mtk_wdt_restart(void);

void mt65xx_bat_init(void){}

void __attribute__((weak)) check_bat_status(void)
{
	dprintf(CRITICAL, "%s: Please implement check_bat_status() if you don't use mtk charger.\n", __func__);
}

void __attribute__((weak)) enable_charging(bool enable)
{
	dprintf(CRITICAL, "%s: Please implement enable_charging() if you don't use mtk charger.\n", __func__);
}

void __attribute__((weak)) enable_power_path(bool enable)
{
	dprintf(CRITICAL, "%s: Please implement enable_power_path() if you don't use mtk charger.\n", __func__);
}

void __attribute__((weak)) enable_wdt(bool enable)
{
	dprintf(CRITICAL, "%s: Please implement enable_wdt() if you don't use mtk charger.\n", __func__);
}

void __attribute__((weak)) charger_start(void)
{
	dprintf(CRITICAL, "%s: Please implement charger_start() if you don't use mtk charger.\n", __func__);
}

int __attribute__((weak)) force_get_tbat(bool update)
{
	dprintf(CRITICAL, "%s: T is not ready.\n", __func__);
	return 25;
}

int __attribute__((weak)) gauge_get_current(bool *curr_sign, int *bat_current)
{
	dprintf(CRITICAL, "%s: IBAT is not ready.\n", __func__);
	*curr_sign = 1;
	*bat_current = 5000;
	return 0;
}

void __attribute__((weak)) mt_disp_show_charging(int index)
{
	dprintf(CRITICAL, "%s: logo is not ready.\n", __func__);
}

void __attribute__((weak)) mt_disp_show_plug_charger(void)
{
	dprintf(CRITICAL, "%s: logo is not ready.\n", __func__);
}

unsigned int chr_fdt_getprop_bool(const void *fdt, int nodeoffset,
						const char *name)
{
	const void *data = NULL;
	int len = 0;

	data = fdt_getprop(fdt, nodeoffset, name, &len);
	if (data)
		return true;
	else
		return false;
}

void chr_fdt_getprop_char_array(const void *fdt, int nodeoffset,
                                const char *name, char *out_value)
{
	const void *data = NULL;
	int len = 0;

	data = fdt_getprop(fdt, nodeoffset, name, &len);
	if (len > 0 && data)
		memcpy(out_value, data, len);
	else
		memset(out_value, 0, len);
}

unsigned int chr_fdt_getprop_u32(const void *fdt, int nodeoffset,
                                 const char *name)
{
	const void *data = NULL;
	int len = 0;

	data = fdt_getprop(fdt, nodeoffset, name, &len);
	if (len > 0 && data)
		return fdt32_to_cpu(*(unsigned int *)data);
	else
		return 0;
}

void init_charger_custom_data(void)
{
	chr_cust_data.disable_charger = false;
	chr_cust_data.power_path_support = true;
	chr_cust_data.enable_pe_plus = true;
	chr_cust_data.max_charger_voltage = 6500;
	chr_cust_data.min_charger_voltage = 4000;
	chr_cust_data.fast_charge_voltage = 3000;

	/* charging current */
	chr_cust_data.usb_charger_current = 500;
	chr_cust_data.ac_charger_current = 2050;
	chr_cust_data.ac_charger_input_current = 3200;
	chr_cust_data.non_std_ac_charger_current = 500;
	chr_cust_data.charging_host_charger_current = 500;
	chr_cust_data.ta_ac_charger_current = 3000;
	chr_cust_data.pd_charger_current = 500;

	/* temperature protection ref sw jeita */
	chr_cust_data.temp_t4_threshold = 50;
	chr_cust_data.temp_t3_threshold = 45;
	chr_cust_data.temp_t1_threshold = 0;

	/* charging anime */
	chr_cust_data.enable_anime = false;
	chr_cust_data.led_brightness = 20;
	chr_cust_data.blinking_times = 6;
	chr_cust_data.blinking_period = 1500;

	/* vbus resistance */
	chr_cust_data.r_charger_1 = 330;
	chr_cust_data.r_charger_2 = 39;
}

int init_cust_data_from_dt(void)
{
	int offset, val;
	offset = fdt_node_offset_by_compatible(get_lk_overlayed_dtb(), -1, "mediatek,lk_charger");

	if (offset >= 0) {
		val = chr_fdt_getprop_bool(get_lk_overlayed_dtb(), offset, "disable_charger");
		if (val)
			chr_cust_data.disable_charger = true;
		else
			chr_cust_data.disable_charger = false;

		val = chr_fdt_getprop_bool(get_lk_overlayed_dtb(), offset, "enable_pe_plus");
		if (val)
			chr_cust_data.enable_pe_plus = true;
		else
			chr_cust_data.enable_pe_plus = false;

		val = chr_fdt_getprop_bool(get_lk_overlayed_dtb(), offset, "enable_pd20_reset");
		if (val)
			chr_cust_data.enable_pd20_reset = true;
		else
			chr_cust_data.enable_pd20_reset = false;

		val = chr_fdt_getprop_bool(get_lk_overlayed_dtb(), offset, "power_path_support");
		if (val)
			chr_cust_data.power_path_support = true;
		else
			chr_cust_data.power_path_support = false;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "max_charger_voltage");
		if (val)
			chr_cust_data.max_charger_voltage = val / 1000;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "min_charger_voltage");
		if (val)
			chr_cust_data.min_charger_voltage = val / 1000;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "fast_charge_voltage");
		if (val)
			chr_cust_data.fast_charge_voltage = val / 1000;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "usb_charger_current");
		if (val)
			chr_cust_data.usb_charger_current = val / 1000;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "ac_charger_current");
		if (val)
			chr_cust_data.ac_charger_current = val / 1000;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "ac_charger_input_current");
		if (val)
			chr_cust_data.ac_charger_input_current = val / 1000;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "non_std_ac_charger_current");
		if (val)
			chr_cust_data.non_std_ac_charger_current = val / 1000;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "charging_host_charger_current");
		if (val)
			chr_cust_data.charging_host_charger_current = val / 1000;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "ta_ac_charger_current");
		if (val)
			chr_cust_data.ta_ac_charger_current = val / 1000;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "pd_charger_current");
		if (val)
			chr_cust_data.pd_charger_current = val / 1000;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "temp_t4_threshold");
		if (val)
			chr_cust_data.temp_t4_threshold = val;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "temp_t3_threshold");
		if (val)
			chr_cust_data.temp_t3_threshold = val;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "temp_t1_threshold");
		if (val)
			chr_cust_data.temp_t1_threshold = val;

		val = chr_fdt_getprop_bool(get_lk_overlayed_dtb(), offset, "enable_anime");
		if (val)
			chr_cust_data.enable_anime = true;
		else
			chr_cust_data.enable_anime = false;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "led_brightness");
		if (val)
			chr_cust_data.led_brightness = val;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "blinking_times");
		if (val)
			chr_cust_data.blinking_times = val;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "blinking_period");
		if (val)
			chr_cust_data.blinking_period = val;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "r_charger_1");
		if (val)
			chr_cust_data.r_charger_1 = val;

		val = chr_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "r_charger_2");
		if (val)
			chr_cust_data.r_charger_2 = val;

		dprintf(CRITICAL, "[%s]:chroff:%d,pe:%d,powpath:%d,vchrmax:%d,vchrmin:%d,vfast:%d,"
			"usb:%d,ac:%d %d,nac:%d,cdp:%d,ta:%d,pd:%d,t:%d %d %d\n", __func__,
			chr_cust_data.disable_charger, chr_cust_data.enable_pe_plus,
			chr_cust_data.power_path_support, chr_cust_data.max_charger_voltage,
			chr_cust_data.min_charger_voltage, chr_cust_data.fast_charge_voltage,
			chr_cust_data.usb_charger_current, chr_cust_data.ac_charger_current,
			chr_cust_data.ac_charger_input_current, chr_cust_data.non_std_ac_charger_current,
			chr_cust_data.charging_host_charger_current, chr_cust_data.ta_ac_charger_current,
			chr_cust_data.pd_charger_current, chr_cust_data.temp_t4_threshold,
			chr_cust_data.temp_t3_threshold, chr_cust_data.temp_t1_threshold);

		enable_mtk_charger = true;
		return 0;
	}
	else {
		dprintf(CRITICAL, "[%s]: lk_charger is not found in dts!\n", __func__);
		enable_mtk_charger = false;
		return 1;
	}
}

void chr_power_off(void)
{
#ifdef MTK_PMIC_POWER_OFF
	mt_power_off();
#else
	mt6575_power_off();
#endif
}

int get_chr_volt(void)
{
	unsigned int val = 0;

#if defined(MACH_TYPE_MT6779) || defined(MACH_TYPE_MT6785) || defined(MACH_TYPE_MT6885)
	mtk_charger_get_vbus(primary_mchr, &val);
	val /= 1000;
	dprintf(CRITICAL, "%s: vbus = %d mV\n", __func__, val);
#else
	val = pmic_get_auxadc_value(AUXADC_LIST_VCDT);
	val = (((chr_cust_data.r_charger_1 + chr_cust_data.r_charger_2) * 100 * val)
		/ chr_cust_data.r_charger_2) / 100;
#endif
	return val;
}

int get_bat_volt(int times)
{
	int bat_vol;

	if (chr_cust_data.power_path_support == true)
		bat_vol = get_i_sense_volt(times);
	else
		bat_vol = get_bat_sense_volt(times);

	return bat_vol;
}

bool is_power_path_supported(void)
{
	return chr_cust_data.power_path_support;
}

bool is_disable_charger(void)
{
	return chr_cust_data.disable_charger;
}

bool is_battery_on(void)
{
	/* FIXME: Need to replace with general PMIC interface */
	pmic_set_register_value(PMIC_RG_BATON_EN, 1);
#if defined(MACH_TYPE_MT6765) || defined(MACH_TYPE_MT6761) || defined(MACH_TYPE_MT8168)
	if (pmic_get_register_value(PMIC_RGS_BATON_UNDET) == 1)
#else
	if (pmic_get_register_value(PMIC_AD_BATON_UNDET) == 1)
#endif
		return false;
	else
		return true;
}

bool is_low_battery(int val)
{
	static unsigned char g_bat_low = 0xFF;

	//low battery only just once in lk
	if (0 == val) {
		if (0xFF != g_bat_low)
			return g_bat_low;
		else
			g_bat_low = false;
		val = get_bat_volt(1);
	}

	if (val < BATTERY_LOWVOL_THRESOLD) {
		dprintf(INFO, "%s, TRUE\n", __func__);
		g_bat_low = true;
	}
	else {
		dprintf(INFO, "%s, FALSE\n", __func__);
		g_bat_low = false;
	}

	return g_bat_low;
}

static void select_charging_current_limit(void)
{
	int input_current_limit;
	int charging_current_limit;
	CHARGER_TYPE chr_type = g_boot_arg->charger_type;

	dprintf(INFO, "charger_type: %d\n", chr_type);

	if (chr_type == STANDARD_HOST) {
		input_current_limit = chr_cust_data.usb_charger_current;
		charging_current_limit = chr_cust_data.usb_charger_current;
	} else if (chr_type == NONSTANDARD_CHARGER) {
		input_current_limit = chr_cust_data.non_std_ac_charger_current;
		charging_current_limit = chr_cust_data.non_std_ac_charger_current;
	} else if (chr_type == STANDARD_CHARGER) {
		input_current_limit = chr_cust_data.ac_charger_input_current;
		charging_current_limit = chr_cust_data.ac_charger_current;
	} else if (chr_type == CHARGING_HOST) {
		input_current_limit = chr_cust_data.charging_host_charger_current;
		charging_current_limit = chr_cust_data.charging_host_charger_current;
	} else {
		input_current_limit = chr_cust_data.usb_charger_current;
		charging_current_limit = chr_cust_data.usb_charger_current;
	}

	mtk_charger_set_aicr(primary_mchr, input_current_limit);
	mtk_charger_set_ichg(primary_mchr, charging_current_limit);
}

static void reset_default_charging_current_limit(void)
{
	int input_current_limit;
	int charging_current_limit;

	input_current_limit = chr_cust_data.usb_charger_current;
	charging_current_limit = chr_cust_data.usb_charger_current;

	mtk_charger_set_aicr(primary_mchr, input_current_limit);
	mtk_charger_set_ichg(primary_mchr, charging_current_limit);
}

static void show_plug_out_notify(void)
{
	mt65xx_backlight_on();
	mt_disp_show_charger_ov_logo();
	thread_sleep(4000);
	mt65xx_backlight_off();
}

static void show_low_battery_notify(void)
{
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_LCD, chr_cust_data.led_brightness);
	mt_disp_show_plug_charger();
	thread_sleep(4000);
	mt65xx_backlight_off();
}

static void check_charger_battery_on(void)
{
	if (upmu_is_chr_det() == false) {
		dprintf(CRITICAL, "[BATTERY] No Charger, Power OFF !\n");
		show_low_battery_notify();
		chr_power_off();
	}

	if (!is_battery_on()) {
		dprintf(CRITICAL, "[BATTERY] No battry plug-in. Power Off.");
		chr_power_off();
	}
	mtk_charger_check_charging_mode(primary_mchr);
}

static void show_charging_anime(void)
{
	int i,j;
	bool stop = false;
	/* set LCD brightness */
	mt65xx_leds_brightness_set(MT65XX_LED_TYPE_LCD, chr_cust_data.led_brightness);

	/* set blinking times */
	for (i = 0; i < chr_cust_data.blinking_times && !stop; i++) {
		mtk_wdt_restart();
		mt_disp_show_charging(i % 2);

		for (j = 0; j < 2 && !stop; j++) {
			/* set blinking period */
			thread_sleep(chr_cust_data.blinking_period);
			check_charger_battery_on();
			if(get_powerkey_pressed_status()) {
				clear_powerkey_pressed_status();
				stop = true;
			}
		}
	}
	mt65xx_backlight_off();
	mt_disp_show_charging(0);
	mtk_charger_reset_wdt(primary_mchr);
}

void check_charger_volt(void)
{
	int i;
	int chr_volt;

	if (g_boot_mode == KERNEL_POWER_OFF_CHARGING_BOOT ||
	    g_boot_mode == LOW_POWER_OFF_CHARGING_BOOT) {
		for (i = 0; i < VBUS_CHECK_COUNT; i++) {
			chr_volt = get_chr_volt();
			if (chr_volt < chr_cust_data.min_charger_voltage) {
				dprintf(INFO, "vbus is less than %dmv, power off\n",
					chr_cust_data.min_charger_voltage);
				chr_power_off();
			}
		}
	}

	if (chr_cust_data.power_path_support == true) {
		chr_volt = get_chr_volt();
		if (chr_volt > chr_cust_data.max_charger_voltage) {
			dprintf(CRITICAL, "Charger Over Voltage:%d\n, power off...", chr_volt);
			show_plug_out_notify();
			chr_power_off();
		}
	}
}

/*
* enter this function when low battery with charger
*/
void check_bat_protect_status(void)
{
	int ret = 0;
	int bat_val = 0;
	int i;
	int temperature;
	int bat_current = 0;
	bool curr_sign = 0;
	static bool is_first = 1;

	if (enable_mtk_charger == false) {
		check_bat_status();
		return;
	}

	ret = mtk_charger_enable_charging(primary_mchr, false);
	if (ret < 0)
		dprintf(CRITICAL, "%s: disable charging failed, ret = %d\n", __func__, ret);

	bat_val = get_bat_volt(5);
	dprintf(CRITICAL, "[%s]: check VBAT=%d mV with %d mV\n", __func__,
		bat_val, BATTERY_LOWVOL_THRESOLD);

	clear_powerkey_pressed_status();

	unsigned int time_charging;
	time_charging = get_timer(0);
	//unsigned int time_sleeping;

	while (bat_val < BATTERY_LOWVOL_THRESOLD) {
		mtk_wdt_restart();
		mtk_charger_reset_wdt(primary_mchr);

		check_charger_battery_on();
		check_charger_volt();

		temperature = force_get_tbat(true);
		dprintf(INFO, "%s: T=%d\n", __func__, temperature);
		if(temperature > chr_cust_data.temp_t4_threshold) {
			dprintf(CRITICAL,"[BATTERY] Battery over Temperature or NTC fail %d %d!!\n\r", temperature,
				chr_cust_data.temp_t4_threshold);
			break;
		}

		if (bat_val < chr_cust_data.fast_charge_voltage ||
			temperature > chr_cust_data.temp_t3_threshold ||
			temperature < chr_cust_data.temp_t1_threshold)
			reset_default_charging_current_limit();
		else
			select_charging_current_limit();

		ret = mtk_charger_enable_charging(primary_mchr, true);
		if (ret < 0)
			dprintf(CRITICAL, "%s: enable charging failed, ret = %d\n", __func__, ret);

		//time_sleeping = get_timer(0);
		if (chr_cust_data.enable_anime && bat_val > chr_cust_data.fast_charge_voltage) {
			if (is_first) {
				show_charging_anime();
				is_first = 0;
			}
			for (i = 0; i < MAX_SLEEP_LOOP; i++) {
				mtk_wdt_restart();
				check_charger_battery_on();
				/* set polling period */
				thread_sleep(1000);
				if(get_powerkey_pressed_status()) {
					clear_powerkey_pressed_status();
					show_charging_anime();
				}
			}
		} else {
			for (i = 0; i < MAX_SLEEP_LOOP; i++) {
				mtk_wdt_restart();
				check_charger_battery_on();
				/* set polling period */
				thread_sleep(1000);
			}
		}
		//dprintf(CRITICAL, "[PROFILE] ------- charging %d ms -------- \n", (int)get_timer(time_sleeping));

		if (is_battery_on()) {
			gauge_get_current(&curr_sign, &bat_current);
			bat_current = bat_current / 10;
			dprintf(INFO, "%s:IBAT=%d\n", __func__, curr_sign ? bat_current : -1 * bat_current);
		}

		if (g_boot_arg->charger_type == STANDARD_CHARGER && bat_val > chr_cust_data.fast_charge_voltage) {
			ret = mtk_charger_enable_charging(primary_mchr, false);
			if (ret < 0)
				dprintf(INFO, "%s: disable charging failed, ret = %d\n", __func__, ret);
		}
		bat_val = get_bat_volt(5);
		dprintf(INFO, "[%s]: check VBAT=%d mV with %d mV, start charging...\n", __func__,
			bat_val, BATTERY_LOWVOL_THRESOLD);
	}
	dprintf(INFO, "[PROFILE] ------- Charging takes %d ms -------- \n", (int)get_timer(time_charging));
	mtk_wdt_restart();
	reset_default_charging_current_limit();
}

void check_low_battery(void)
{
	int bat_vol;
	bat_vol = get_bat_volt(1);

	if (is_low_battery(bat_vol)) {
		if (g_boot_mode == KERNEL_POWER_OFF_CHARGING_BOOT && upmu_is_chr_det() == true) {
			dprintf(CRITICAL, "[%s] Kernel Low Battery Power Off Charging Mode\n", __func__);
			g_boot_mode = LOW_POWER_OFF_CHARGING_BOOT;

			check_bat_protect_status();

		} else {
			dprintf(CRITICAL, "[BATTERY] battery voltage(%dmV) <= CLV ! Can not Boot Linux Kernel !! \n\r",bat_vol);
			show_low_battery_notify();
			chr_power_off();
		}
	}
}

void reset_pd_adapter(void)
{
	int chr_volt;

	if (!chr_cust_data.enable_pd20_reset)
		return;
	chr_volt = get_chr_volt();
	/* Try reset pd charger TA */
	if (chr_volt > chr_cust_data.max_charger_voltage) {
		dprintf(CRITICAL,
			"[mt65xx_bat_init] Try reset pd20 charger TA\n");
		pd_reset_adapter();
	}
}

void reset_pe_adapter(void)
{
	if (chr_cust_data.enable_pe_plus == true) {
		int chr_volt;
		int rc = 0;

		/*Try to reset PE+ adapter once abnormal voltage is found*/
		chr_volt = get_chr_volt();
		while (chr_volt > chr_cust_data.max_charger_voltage) {
			dprintf(CRITICAL, "[mt65xx_bat_init] PE+ adpater should be reset to 5V now\n");

			pumpex_reset_adapter_enable(1);
			mdelay(250);
			pumpex_reset_adapter_enable(0);

			chr_volt = get_chr_volt();
			rc++;
			if (rc == 3)
				break;
		}
	}
}

void charger_enable_charging(bool enable)
{
	int ret = 0;

	if (enable_mtk_charger == false) {
		enable_charging(enable);
		return;
	}

	primary_mchr = mtk_charger_get_by_name("primary_charger");
	if (!primary_mchr) {
		dprintf(CRITICAL, "%s: get primary charger failed\n", __func__);
		return;
	}

	ret = mtk_charger_enable_charging(primary_mchr, enable);
	if (ret < 0)
		dprintf(CRITICAL, "%s: enable/disable charging failed, ret = %d\n", __func__, ret);
	else {
		if(enable)
			dprintf(INFO, "%s: enable charging\n", __func__);
		else
			dprintf(INFO, "%s: disable charging\n", __func__);
	}
}

void charger_enable_power_path(bool enable)
{
	int ret = 0;

	if (enable_mtk_charger == false) {
		enable_power_path(enable);
		return;
	}

	if (is_battery_on()) {
		primary_mchr = mtk_charger_get_by_name("primary_charger");
		if (!primary_mchr) {
			dprintf(CRITICAL, "%s: get primary charger failed\n", __func__);
			return;
		}

		ret = mtk_charger_enable_power_path(primary_mchr, enable);
		if (ret < 0)
			dprintf(CRITICAL, "%s: enable/disable power path failed, ret = %d\n", __func__, ret);
	}
	else
		dprintf(CRITICAL, "%s: no battery plug-in, skip power path control\n", __func__);
}

void charger_enable_wdt(bool enable)
{
	int ret = 0;

	if (enable_mtk_charger == false) {
		enable_wdt(enable);
		return;
	}

	primary_mchr = mtk_charger_get_by_name("primary_charger");
	if (!primary_mchr) {
		dprintf(CRITICAL, "%s: get primary charger failed\n", __func__);
		return;
	}

	ret = mtk_charger_enable_wdt(primary_mchr, enable);
	if (ret < 0)
		dprintf(CRITICAL, "%s: enable/disable wdt failed, ret = %d\n", __func__, ret);
	else {
		if(enable)
			dprintf(INFO, "%s: enable wdt\n", __func__);
		else
			dprintf(INFO, "%s: disable wdt\n", __func__);
	}
}

void mtk_charger_start(void)
{
	if (enable_mtk_charger == false) {
		charger_start();
		return;
	}

	if (chr_cust_data.disable_charger == false) {
		int ret = 0;
		/* Get charger interface */
		primary_mchr = mtk_charger_get_by_name("primary_charger");
		if (!primary_mchr) {
			dprintf(CRITICAL, "%s: get primary charger failed\n", __func__);
			return;
		}

		reset_pe_adapter();
		reset_pd_adapter();
		check_charger_volt();

		if (g_boot_mode == KERNEL_POWER_OFF_CHARGING_BOOT && pmic_detect_powerkey()) {
			dprintf(CRITICAL, "[mt65xx_bat_init] KPOC+PWRKEY => change boot mode\n");
			g_boot_reason_change = true;
		}

		check_low_battery();

		if (g_boot_mode != META_BOOT && g_boot_mode != FACTORY_BOOT && g_boot_mode != ATE_FACTORY_BOOT) {
			if (!is_battery_on()) {
				dprintf(CRITICAL, "[BATTERY] No battry plug-in. Power Off.");
				chr_power_off();
			}
		}

		/* disable wdt in case entering fastboot later... */
		ret = mtk_charger_enable_wdt(primary_mchr, false);
		if (ret < 0)
			dprintf(CRITICAL, "%s: disable wdt fail\n", __func__);
	}
	else
		dprintf(CRITICAL, "%s: skip mtk_charger_start\n", __func__);
}
