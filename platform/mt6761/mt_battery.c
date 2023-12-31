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

#include <target/board.h>
#ifdef MTK_KERNEL_POWER_OFF_CHARGING
#define CFG_POWER_CHARGING
#endif
#ifdef CFG_POWER_CHARGING
#include <kernel/thread.h>
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
#include <platform/mt_pumpexpress.h>
//#include <platform/mt_disp_drv.h>
//#include <platform/mtk_wdt.h>
//#include <platform/mtk_key.h>
//#include <platform/mt_logo.h>
#include <platform/mt_leds.h>
#include <printf.h>
#include <sys/types.h>
#include <target/cust_battery.h>
#include <platform/mt_pmic_dlpt.h>

#if defined(MTK_BQ24261_SUPPORT)
#include <platform/bq24261.h>
#endif

#if defined(MTK_BQ24296_SUPPORT)
#include <platform/bq24296.h>
#endif

#if defined(MTK_NCP1854_SUPPORT)
#include <platform/ncp1854.h>
#endif

#if defined(MTK_BQ25896_SUPPORT)
#include <platform/bq25890.h>
#endif

#if defined(MTK_HL7005_SUPPORT)
#include <platform/hl7005.h>
#endif

#ifdef MTK_CHARGER_INTERFACE
#include <platform/mtk_charger_intf.h>
static struct mtk_charger_info *primary_mchr;
#endif


#define V_CHARGER_MAX 6500              // 6.5 V

#undef printf


/*****************************************************************************
 *  Type define
 ****************************************************************************/
#if defined(CUST_BATTERY_LOWVOL_THRESOLD)
#define BATTERY_LOWVOL_THRESOLD CUST_BATTERY_LOWVOL_THRESOLD
#else
#define BATTERY_LOWVOL_THRESOLD             3450
#endif

/*****************************************************************************
 *  Global Variable
 ****************************************************************************/
bool g_boot_reason_change = false;

kal_bool g_fg_is_charging = 0;
extern signed int fg_swocv_v;
extern signed int fg_swocv_i;
extern int shutdown_time;
extern int boot_voltage;
extern BOOT_ARGUMENT *g_boot_arg;

/* battery meter parameter */
#define UNIT_FGCURRENT     (305176)
#define CAR_TUNE_VALUE      1000 //1.00
#define R_FG_VALUE          100

#if defined(STD_AC_LARGE_CURRENT)
int g_std_ac_large_current_en=1;
#else
int g_std_ac_large_current_en=0;
#endif

/*****************************************************************************
 *  Externl Variable
 ****************************************************************************/
extern bool g_boot_menu;
extern void mtk_wdt_restart(void);
extern int get_charging_current(int times);

void kick_charger_wdt(void)
{
	pmic_set_register_value(PMIC_RG_CHRWDT_TD, 3); /* 32s to keep charging for lk to kernel */
	pmic_set_register_value(PMIC_RG_CHRWDT_WR, 1);
	pmic_set_register_value(PMIC_RG_INT_EN_WATCHDOG, 1);
	pmic_set_register_value(PMIC_RG_CHRWDT_EN,1);
	/* pmic_set_register_value(PMIC_RG_CHRWDT_FLAG_WR,1); */
}

#if defined(MTK_BATLOWV_NO_PANEL_ON_EARLY)
kal_bool is_low_battery(kal_int32  val)
{
	static UINT8 g_bat_low = 0xFF;

	//low battery only justice once in lk
	if (0xFF != g_bat_low)
		return g_bat_low;
	else
		g_bat_low = FALSE;

#if defined(SWCHR_POWER_PATH)
	if (0 == val)
		val = get_i_sense_volt(1);
#else
	if (0 == val)
		val = get_bat_sense_volt(1);
#endif

	if (val < BATTERY_LOWVOL_THRESOLD) {
		dprintf(INFO, "%s, TRUE\n", __FUNCTION__);
		g_bat_low = 0x1;
	}

	if (FALSE == g_bat_low)
		dprintf(INFO, "%s, FALSE\n", __FUNCTION__);

	return g_bat_low;
}
#endif

void pchr_turn_on_charging(kal_bool bEnable)
{
#ifdef MTK_CHARGER_INTERFACE
	int ret = 0;
	bool enable = bEnable ? true : false;
#endif
	pmic_set_register_value(PMIC_RG_USBDL_RST,1);//force leave USBDL mode
	pmic_set_register_value(PMIC_RG_BC11_RST,1);//BC11_RST
	kick_charger_wdt();

	pmic_set_register_value(PMIC_RG_CS_VTH,0xC); /* 450mA */
	pmic_set_register_value(PMIC_RG_CSDAC_EN,bEnable);
	pmic_set_register_value(PMIC_RG_CHR_EN,bEnable);

	pmic_set_register_value(PMIC_RG_CSDAC_MODE,1);
	pmic_set_register_value(PMIC_RG_CSDAC_EN,1);

#if defined(MTK_BQ24261_SUPPORT)
	bq24261_hw_init();
	bq24261_charging_enable(bEnable);
	bq24261_dump_register();
#endif

#if defined(MTK_BQ24296_SUPPORT)
	bq24296_hw_init();
	bq24296_charging_enable(bEnable);
	bq24296_dump_register();
#endif

#if defined(MTK_NCP1854_SUPPORT)
	ncp1854_hw_init();
	ncp1854_charging_enable(bEnable);
	ncp1854_dump_register();
#endif

#if defined(MTK_BQ25896_SUPPORT)
	bq25890_hw_init();
	bq25890_charging_enable(bEnable);
	bq25890_dump_register();
#endif

#if defined(MTK_HL7005_SUPPORT)
	hl7005_hw_init();
	hl7005_charging_enable();
	hl7005_dump_register();
#endif

#ifdef MTK_CHARGER_INTERFACE
	ret = mtk_charger_enable_charging(primary_mchr, enable);
	if (ret < 0)
		dprintf(CRITICAL, "%s: %s charging failed, ret = %d\n",
			__func__, (enable ? "enable" : "disable"), ret);
	mtk_charger_dump_register(primary_mchr);
	if (ret < 0)
		dprintf(CRITICAL, "%s: dump register failed, ret = %d\n",
			__func__, ret);
#endif
}

void pchr_turn_off_charging(void)
{
	pmic_set_register_value(PMIC_RG_INT_EN_WATCHDOG,0);
	pmic_set_register_value(PMIC_RG_CHRWDT_EN,0);// CHRWDT_EN
	/* pmic_set_register_value(PMIC_RG_CHRWDT_FLAG_WR,0);// CHRWDT_FLAG */
	pmic_set_register_value(PMIC_RG_CSDAC_EN,0);// CSDAC_EN
	pmic_set_register_value(PMIC_RG_CHR_EN,0);// CHR_EN
	pmic_set_register_value(PMIC_RG_HWCV_EN,0);// RG_HWCV_EN
}

/*
*   Switch Charger Power Path switch
*/
void switch_charger_power_path_enable(kal_bool enable)
{
#if defined(MTK_BQ25896_SUPPORT)
	if (enable == KAL_TRUE) {
		bq25890_set_FORCE_VINDPM(1);
		bq25890_set_VINDPM(0x14);
	} else {
		bq25890_set_FORCE_VINDPM(1);
		bq25890_set_VINDPM(0x7F);
	}
#elif defined(MTK_CHARGER_INTERFACE)
	int ret = 0;
	bool _enable = enable ? true : false;

	ret = mtk_charger_enable_power_path(primary_mchr, _enable);
	if (ret < 0)
		dprintf(CRITICAL, "%s: %s power path failed, ret = %d\n",
			__func__, (_enable ? "enable" : "disable"), ret);
#endif
}

int is_charging = 0;

/*
* enter this function when low battery with charger
* For BQ25896, power path support can provide current and voltage for cell phone to boot directly to kernel.
*/
void check_bat_protect_status()
{
	kal_int32 bat_val = 0;
	int chr_volt;
#if !defined(SWCHR_POWER_PATH)
	int current,cnt=0,i;
#endif

#if defined(SWCHR_POWER_PATH)
	bat_val = get_i_sense_volt(5);
#else
	bat_val = get_bat_sense_volt(5);
#endif

	dprintf(CRITICAL, "[%s]: check VBAT=%d mV with %d mV, start charging... \n", __FUNCTION__, bat_val, BATTERY_LOWVOL_THRESOLD);

	while (bat_val < BATTERY_LOWVOL_THRESOLD) {
		mtk_wdt_restart();
		if (upmu_is_chr_det() == KAL_FALSE) {
			dprintf(CRITICAL, "[BATTERY] No Charger, Power OFF !\n");
			mt_power_off();
			while (1);
		}


		chr_volt= get_charger_volt(1);

		if (chr_volt>V_CHARGER_MAX) {
			dprintf(CRITICAL, "[BATTERY] charger voltage is too high :%d , threshold is %d !\n",chr_volt,V_CHARGER_MAX);
#if defined(SWCHR_POWER_PATH)
			mt_power_off();
#endif
			break;
		}

		/* pmic_set_register_value(PMIC_BATON_TDET_EN, 1); */
		pmic_set_register_value(PMIC_RG_BATON_EN, 1);
		if (pmic_get_register_value(PMIC_RGS_BATON_UNDET) == 1) {
			dprintf(CRITICAL, "[BATTERY] No battry plug-in. Power Off.");
			mt_power_off();
			break;
		}

		dprintf(CRITICAL, "[%s]: check VBAT=%d mV with %d mV, start charging... \n", __FUNCTION__, bat_val, BATTERY_LOWVOL_THRESOLD);

		is_charging = 1;
		pchr_turn_on_charging(KAL_TRUE);

#if defined(SWCHR_POWER_PATH)
		thread_sleep(5000);
#else
		cnt=0;
		for (i=0; i<10; i++) {
			current=get_charging_current(1);
			chr_volt=get_charger_volt(1);
			if (current<100 && chr_volt<4400) {
				cnt++;
				dprintf(CRITICAL, "[BATTERY] charging current=%d charger volt=%d\n\r",current,chr_volt);
			} else {
				dprintf(CRITICAL, "[BATTERY] charging current=%d charger volt=%d\n\r",current,chr_volt);
				cnt=0;
			}
		}

		if (cnt>=8) {

			dprintf(CRITICAL, "[BATTERY] charging current and charger volt too low: %d\n",cnt);

			pchr_turn_off_charging();
#ifndef NO_POWER_OFF
			mt_power_off();
#endif
			while (1) {
				dprintf(CRITICAL, "If you see the log, please check with RTC power off API\n\r");
			}
		}
		thread_sleep(5000);
#endif



#if defined(SWCHR_POWER_PATH)
		bat_val = get_i_sense_volt(5);
#else
		bat_val = get_bat_sense_volt(5);
#endif
		dprintf(CRITICAL, "[%s]: check VBAT=%d mV  \n", __FUNCTION__, bat_val);
	}
	mtk_wdt_restart();

	dprintf(CRITICAL, "[%s]: check VBAT=%d mV with %d mV, stop charging... \n", __FUNCTION__, bat_val, BATTERY_LOWVOL_THRESOLD);
}

bool mtk_bat_allow_backlight_enable(void)
{
	int bat_vol = 0;
#if defined(SWCHR_POWER_PATH)
	bat_vol = get_i_sense_volt(1);
#else
	bat_vol = get_bat_sense_volt(1);
#endif
	if (bat_vol > (BATTERY_LOWVOL_THRESOLD + 150))
		return true;
	return false;
}

void fgauge_read_IM_current(void *data)
{
		unsigned short uvalue16 = 0;
		signed int dvalue = 0;
		/*int m = 0;*/
		long long Temp_Value = 0;
		/*unsigned int ret = 0;*/

		uvalue16 = pmic_get_register_value(PMIC_FG_R_CURR);
		dprintf(CRITICAL,"[fgauge_read_IM_current] : FG_CURRENT = %x\r\n",
			 uvalue16);

		/*calculate the real world data    */
		dvalue = (unsigned int) uvalue16;
		if (dvalue == 0) {
			Temp_Value = (long long) dvalue;
			g_fg_is_charging = false;
		} else if (dvalue > 32767) {
			/* > 0x8000 */
			Temp_Value = (long long) (dvalue - 65535);
			Temp_Value = Temp_Value - (Temp_Value * 2);
			g_fg_is_charging = false;
		} else {
			Temp_Value = (long long) dvalue;
			g_fg_is_charging = true;
		}

		Temp_Value = Temp_Value * UNIT_FGCURRENT;
		Temp_Value=Temp_Value/100000;
		dvalue = (unsigned int) Temp_Value;

		if (g_fg_is_charging == true)
			dprintf(CRITICAL,
			"[fgauge_read_IM_current] current(charging) = %d mA\r\n",
			dvalue);
		else
			dprintf(CRITICAL,
			"[fgauge_read_IM_current] current(discharging) = %d mA\r\n",
			dvalue);

		/* Auto adjust value */
		if (R_FG_VALUE != 100) {
			dprintf(CRITICAL,
			"[fgauge_read_IM_current] Auto adjust value due to the Rfg is %d\n Ori current=%d, ",
			R_FG_VALUE, dvalue);

			dvalue = (dvalue * 100) / R_FG_VALUE;

			dprintf(CRITICAL,"[fgauge_read_IM_current] new current=%d\n",
			dvalue);
		}

		dprintf(CRITICAL,"[fgauge_read_IM_current] ori current=%d\n", dvalue);

		dvalue = ((dvalue * CAR_TUNE_VALUE) / 1000);

		dprintf(CRITICAL,"[fgauge_read_IM_current] final current=%d (ratio=%d)\n",
			 dvalue, CAR_TUNE_VALUE);

		*(signed int *) (data) = dvalue;

}

void check_sw_ocv(int bat_vol)
{
	unsigned int ptim_bat_vol = 0;
	signed int ptim_R_curr = 0;

	pchr_turn_on_charging(KAL_FALSE);
	mdelay(50);

	do_ptim_gauge(&ptim_bat_vol, &ptim_R_curr);

	fg_swocv_v = ptim_bat_vol;
	if (g_fg_is_charging == true)
		fg_swocv_i = ptim_R_curr;
	else
		fg_swocv_i = -ptim_R_curr;

	dprintf(CRITICAL, "[check_sw_ocv]%d ptim[%d %d] fg_swocv[%d %d] boot_vbat:%d shutdowntime:%d vbat:%d\n",
	g_fg_is_charging,
	ptim_bat_vol, ptim_R_curr, fg_swocv_v, fg_swocv_i, g_boot_arg->boot_voltage, g_boot_arg->shutdown_time,
	bat_vol);

	shutdown_time = g_boot_arg->shutdown_time;
	boot_voltage = g_boot_arg->boot_voltage;

	pchr_turn_on_charging(KAL_TRUE);
}


void mt65xx_bat_init(void)
{
#ifdef MTK_CHARGER_INTERFACE
	int ret = 0;
#endif /* MTK_CHARGER_INTERFACE */
	kal_int32 bat_vol;
#if defined(SWCHR_POWER_PATH) || defined(MTK_PUMP_EXPRESS_PLUS_SUPPORT)
	kal_int32 chr_volt;
#endif
#if defined(MTK_PUMP_EXPRESS_PLUS_SUPPORT) || defined(MTK_PUMP_EXPRESS_PLUS_20_SUPPORT)
	kal_int32 rc = 0;
#endif
	// Low Battery Safety Booting

	/* Get charger interface */
#ifdef MTK_CHARGER_INTERFACE
	mtk_charger_init();
	primary_mchr = mtk_charger_get_by_name("primary_charger");
	if (!primary_mchr)
		dprintf(CRITICAL, "%s: get primary charger failed\n", __func__);
#endif

#if defined(SWCHR_POWER_PATH)
	bat_vol = get_i_sense_volt(1);
#else
	bat_vol = get_bat_sense_volt(1);
#endif
	check_sw_ocv(bat_vol);

	//pchr_turn_on_charging(KAL_TRUE);
	dprintf(INFO, "[mt65xx_bat_init] check VBAT=%d mV with %d mV\n", bat_vol, BATTERY_LOWVOL_THRESOLD);

#if defined(MTK_PUMP_EXPRESS_PLUS_SUPPORT) || defined(MTK_PUMP_EXPRESS_PLUS_20_SUPPORT)
	/*Try to reset PE+ adapter once abnormal voltage is found*/
	chr_volt = get_charger_volt(1);
	while (chr_volt > V_CHARGER_MAX) {
		dprintf(CRITICAL, "[mt65xx_bat_init] PE+ adpater should be reset to 5V now\n");

		pumpex_reset_adapter_enble(1);
		mdelay(250);
		pumpex_reset_adapter_enble(0);

		chr_volt = get_charger_volt(1);
		rc++;
		if (rc == 3)
			break;
	}
#endif

	if (g_boot_mode == KERNEL_POWER_OFF_CHARGING_BOOT && (pmic_get_register_value(PMIC_PWRKEY_DEB)==0) ) {
		dprintf(CRITICAL, "[mt65xx_bat_init] KPOC+PWRKEY => change boot mode\n");
		g_boot_reason_change = true;
	}
	rtc_boot_check(false);

#ifndef MTK_DISABLE_POWER_ON_OFF_VOLTAGE_LIMITATION
#ifndef MTK_BATLOWV_NO_PANEL_ON_EARLY
	if (bat_vol < BATTERY_LOWVOL_THRESOLD)
#else
	if (is_low_battery(bat_vol))
#endif
	{
		if (g_boot_mode == KERNEL_POWER_OFF_CHARGING_BOOT && upmu_is_chr_det() == KAL_TRUE) {
			dprintf(CRITICAL, "[%s] Kernel Low Battery Power Off Charging Mode\n", __func__);
			g_boot_mode = LOW_POWER_OFF_CHARGING_BOOT;

			check_bat_protect_status();

		} else {
			dprintf(CRITICAL, "[BATTERY] battery voltage(%dmV) <= CLV ! Can not Boot Linux Kernel !! \n\r",bat_vol);
#ifndef NO_POWER_OFF
			mt_power_off();
#endif
			while (1) {
				dprintf(CRITICAL, "If you see the log, please check with RTC power off API\n\r");
			}
		}
	}
#endif

#if defined(SWCHR_POWER_PATH)
	chr_volt = get_charger_volt(1);
	if (chr_volt > V_CHARGER_MAX) {
		dprintf(CRITICAL, "Charger Over Voltage:%d\n, power off...", chr_volt);
		mt_power_off();
	}
#endif

#if defined(MTK_DLPT_SUPPORT)

	if (g_boot_mode != META_BOOT && g_boot_mode != FACTORY_BOOT && g_boot_mode != ATE_FACTORY_BOOT) {
		/* pmic_set_register_value(PMIC_BATON_TDET_EN, 1); */
		pmic_set_register_value(PMIC_RG_BATON_EN, 1);
		if (pmic_get_register_value(PMIC_RGS_BATON_UNDET) == 1) {
			dprintf(CRITICAL, "[BATTERY] No battry plug-in. Power Off.");
			mt_power_off();
		}
	}
	pchr_turn_on_charging(KAL_FALSE);
	/* disable SW charger power path */
	switch_charger_power_path_enable(KAL_FALSE);
	mdelay(50);
	get_dlpt_imix_r();
	/* after get imix, re-enable SW charger power path */
	switch_charger_power_path_enable(KAL_TRUE);
	if (is_charging == 1) {
		check_bat_protect_status();
		pchr_turn_on_charging(KAL_TRUE);
		dprintf(CRITICAL, "turn on charging \n\r");
	}
#endif //#if defined(MTK_DLPT_SUPPORT)
#ifdef MTK_CHARGER_INTERFACE
	/* disable wdt in case entering fastboot later... */
	ret = mtk_charger_enable_wdt(primary_mchr, false);
	if (ret < 0)
		dprintf(CRITICAL, "%s: disable wdt fail\n", __func__);

	/* set bl/db driver */
	ret = mtk_charger_set_bl_driver(primary_mchr);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set bl/db driver fail\n", __func__);
#endif /* MTK_CHARGER_INTERFACE */

	return;
}

#else

#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <printf.h>

void mt65xx_bat_init(void)
{
	dprintf(CRITICAL, "[BATTERY] Skip mt65xx_bat_init !!\n\r");
	dprintf(CRITICAL, "[BATTERY] If you want to enable power off charging, \n\r");
	dprintf(CRITICAL, "[BATTERY] Please #define CFG_POWER_CHARGING!!\n\r");
}

#endif
