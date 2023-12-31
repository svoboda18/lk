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

#include <debug.h>
#include <platform/mt_typedefs.h>
#include <platform/mt_rtc.h>
#include <platform/boot_mode.h>
#include <platform/mt_pmic_wrap_init.h>
#include <target/board.h>
#include <platform/mtk_wdt.h>
#include <platform/mt_rtc_hw.h>

#define DBG_RTC_C(x...) dprintf(CRITICAL, x)
#define DBG_RTC_I(x...) dprintf(INFO, x)
#define DBG_RTC_S(x...) dprintf(SPEW, x)

#define RTC_RELPWR_WHEN_XRST    1   /* BBPU = 0 when xreset_rstb goes low */

extern BOOT_ARGUMENT *g_boot_arg;

static U16 RTC_Read(U16 addr)
{
	U32 rdata=0;
	pwrap_read((U32)addr, &rdata);
	return (U16)rdata;
}

static void RTC_Write(U16 addr, U16 data)
{
	pwrap_write((U32)addr, (U32)data);
}



#define rtc_busy_wait()                 \
do {                            \
    while (RTC_Read(RTC_BBPU) & RTC_BBPU_CBUSY);    \
} while (0)

static unsigned long rtc_mktime(int yea, int mth, int dom, int hou, int min, int sec)
{
	unsigned long d1, d2, d3;

	mth -= 2;
	if (mth <= 0) {
		mth += 12;
		yea -= 1;
	}

	d1 = (yea - 1) * 365 + (yea / 4 - yea / 100 + yea / 400);
	d2 = (367 * mth / 12 - 30) + 59;
	d3 = d1 + d2 + (dom - 1) - 719162;

	return ((d3 * 24 + hou) * 60 + min) * 60 + sec;
}

static void rtc_write_trigger(void)
{
	RTC_Write(RTC_WRTGR, 1);
	rtc_busy_wait();
}

void rtc_writeif_unlock(void)
{
	RTC_Write(RTC_PROT, RTC_PROT_UNLOCK1);
	rtc_write_trigger();
	RTC_Write(RTC_PROT, RTC_PROT_UNLOCK2);
	rtc_write_trigger();
}

void rtc_writeif_lock(void)
{
	RTC_Write(RTC_PROT, 0);
	rtc_write_trigger();
}

static void rtc_xosc_write(U16 val)
{
	RTC_Write(RTC_OSC32CON, RTC_OSC32CON_UNLOCK1);
	mdelay(1);
	RTC_Write(RTC_OSC32CON, RTC_OSC32CON_UNLOCK2);
	mdelay(1);

	RTC_Write(RTC_OSC32CON, val);
	mdelay(1);
}

void rtc_enable_k_eosc(void)
{
	pmic_config_interface(PMIC_RG_SRCLKEN_IN0_HW_MODE_ADDR, 1, PMIC_RG_SRCLKEN_IN0_HW_MODE_MASK, PMIC_RG_SRCLKEN_IN0_HW_MODE_SHIFT);
	pmic_config_interface(PMIC_RG_SRCLKEN_IN1_HW_MODE_ADDR, 1, PMIC_RG_SRCLKEN_IN1_HW_MODE_MASK, PMIC_RG_SRCLKEN_IN1_HW_MODE_SHIFT);
	pmic_config_interface(PMIC_RG_RTC_EOSC32_CK_PDN_ADDR, 0, PMIC_RG_RTC_EOSC32_CK_PDN_MASK, PMIC_RG_RTC_EOSC32_CK_PDN_SHIFT);
	/* If cali eosc every second, needing to add the following configuration, default period is 8 sec */
	/* pmic_config_interface(PMIC_EOSC_CALI_TD_ADDR, 0x3, PMIC_EOSC_CALI_TD_MASK, PMIC_EOSC_CALI_TD_SHIFT); */

	RTC_Write(RTC_BBPU, RTC_Read(RTC_BBPU) | RTC_BBPU_KEY | RTC_BBPU_RELOAD);
	rtc_write_trigger();
	/* Enable K EOSC mode for normal power off and then plug out battery */
	RTC_Write(RTC_AL_YEA, ((RTC_Read(RTC_AL_YEA) | RTC_K_EOSC_RSV_0) & (~RTC_K_EOSC_RSV_1)) | RTC_K_EOSC_RSV_2);
	rtc_write_trigger();

	RTC_Write(RTC_BBPU, RTC_Read(RTC_BBPU) | RTC_BBPU_KEY | RTC_BBPU_RELOAD);
	rtc_write_trigger();
	rtc_xosc_write(RTC_Read(RTC_OSC32CON) | RTC_EMBCK_SRC_SEL);
	DBG_RTC_I("[RTC] k_eosc bbpu = 0x%x, con = 0x%x, osc32con = 0x%x, sec = 0x%x, yea = 0x%x\n", RTC_Read(RTC_BBPU), RTC_Read(RTC_CON), RTC_Read(RTC_OSC32CON), RTC_Read(RTC_AL_SEC), RTC_Read(RTC_AL_YEA));
}

void rtc_disable_2sec_reboot(void)
{
	U16 reboot;

	reboot = (RTC_Read(RTC_AL_SEC) & ~RTC_BBPU_2SEC_EN) & ~RTC_BBPU_AUTO_PDN_SEL;
	RTC_Write(RTC_AL_SEC, reboot);
	rtc_write_trigger();
}

static bool rtc_spar_alarm_clear_wait(void)
{
	ulong begin = get_timer(0);

	while (RTC_Read(RTC_BBPU) & RTC_BBPU_CLR)
	{
		if (get_timer(begin) > 1000)
		{
			DBG_RTC_C("[RTC] rtc spar/alarm clear time out!!!!!\n");
			return false;
		}
	}

	return true;
}

void rtc_bbpu_power_down(void)
{
	U16 bbpu;

	rtc_disable_2sec_reboot();
	rtc_enable_k_eosc();
#if 0
	bbpu = RTC_BBPU_KEY | RTC_BBPU_PWREN;
	rtc_writeif_unlock();
	RTC_Write(RTC_BBPU, bbpu);
	rtc_write_trigger();
#else	/* lpsd */
	bbpu = RTC_BBPU_KEY | RTC_BBPU_CLR | RTC_BBPU_PWREN ;
	rtc_writeif_unlock();
	RTC_Write(RTC_BBPU, bbpu);
	RTC_Write(RTC_AL_MASK, RTC_AL_MASK_DOW);	/* mask DOW */
	rtc_write_trigger();
	rtc_spar_alarm_clear_wait();

	RTC_Write(RTC_BBPU, RTC_Read(RTC_BBPU) | RTC_BBPU_KEY | RTC_BBPU_RELOAD);
	rtc_write_trigger();
	DBG_RTC_I("[RTC] %s RTC_AL_MASK= 0x%x RTC_IRQ_EN= 0x%x\n", __func__, RTC_Read(RTC_AL_MASK), RTC_Read(RTC_IRQ_EN));
#endif
	pmic_power_hold(0);
}

U16 rtc_rdwr_uart_bits(U16 *val)
{
	U16 pdn2;

	if (val) {
		pdn2 = RTC_Read(RTC_PDN2) & ~RTC_PDN2_UART_MASK;
		pdn2 |= (*val & (RTC_PDN2_UART_MASK >> RTC_PDN2_UART_SHIFT)) << RTC_PDN2_UART_SHIFT;
		RTC_Write(RTC_PDN2, pdn2);
		rtc_write_trigger();
	}

	return (RTC_Read(RTC_PDN2) & RTC_PDN2_UART_MASK) >> RTC_PDN2_UART_SHIFT;
}

bool rtc_boot_check(bool can_alarm_boot)
{
	U16 irqsta, pdn1, pdn2, spar0, spar1;

	irqsta = RTC_Read(RTC_IRQ_STA); /* read clear */
	pdn1 = RTC_Read(RTC_PDN1);
	pdn2 = RTC_Read(RTC_PDN2);
	spar0 = RTC_Read(RTC_SPAR0);
	spar1 = RTC_Read(RTC_SPAR1);
	/*printf("irqsta = 0x%x, pdn1 = 0x%x, pdn2 = 0x%x, spar0 = 0x%x, spar1 = 0x%x\n",
	       irqsta, pdn1, pdn2, spar0, spar1);*/

	if (irqsta & RTC_IRQ_STA_AL) {
#if RTC_RELPWR_WHEN_XRST
		/* set AUTO bit because AUTO = 0 when PWREN = 1 and alarm occurs */
		U16 bbpu = RTC_Read(RTC_BBPU) | RTC_BBPU_KEY;
		RTC_Write(RTC_BBPU, bbpu);
		rtc_write_trigger();
#endif

		if (pdn1 & RTC_PDN1_PWRON_TIME) {   /* power-on time is available */
			U16 now_sec, now_min, now_hou, now_dom, now_mth, now_yea;
			U16 irqen, sec, min, hou, dom, mth, yea;
			unsigned long now_time, time;

			now_sec = RTC_Read(RTC_TC_SEC);
			now_min = RTC_Read(RTC_TC_MIN);
			now_hou = RTC_Read(RTC_TC_HOU);
			now_dom = RTC_Read(RTC_TC_DOM);
			now_mth = RTC_Read(RTC_TC_MTH);
			now_yea = RTC_Read(RTC_TC_YEA) + RTC_MIN_YEAR;
			if (RTC_Read(RTC_TC_SEC) < now_sec) {   /* SEC has carried */
				now_sec = RTC_Read(RTC_TC_SEC);
				now_min = RTC_Read(RTC_TC_MIN);
				now_hou = RTC_Read(RTC_TC_HOU);
				now_dom = RTC_Read(RTC_TC_DOM);
				now_mth = RTC_Read(RTC_TC_MTH);
				now_yea = RTC_Read(RTC_TC_YEA) + RTC_MIN_YEAR;
			}

			sec = ((spar0 & RTC_SPAR0_PWRON_SEC_MASK) >> RTC_SPAR0_PWRON_SEC_SHIFT);
			min = ((spar1 & RTC_SPAR1_PWRON_MIN_MASK) >> RTC_SPAR1_PWRON_MIN_SHIFT);
			hou = ((spar1 & RTC_SPAR1_PWRON_HOU_MASK) >> RTC_SPAR1_PWRON_HOU_SHIFT);
			dom = ((spar1 & RTC_SPAR1_PWRON_DOM_MASK) >> RTC_SPAR1_PWRON_DOM_SHIFT);
			mth = ((pdn2  & RTC_PDN2_PWRON_MTH_MASK) >> RTC_PDN2_PWRON_MTH_SHIFT);
			yea = ((pdn2  & RTC_PDN2_PWRON_YEA_MASK) >> RTC_PDN2_PWRON_YEA_SHIFT) + RTC_MIN_YEAR;

			now_time = rtc_mktime(now_yea, now_mth, now_dom, now_hou, now_min, now_sec);
			time = rtc_mktime(yea, mth, dom, hou, min, sec);

			DBG_RTC_I("[RTC] now = %d/%d/%d %d:%d:%d (%lu)\n",
			          now_yea, now_mth, now_dom, now_hou, now_min, now_sec, now_time);
			DBG_RTC_I("[RTC] power-on = %d/%d/%d %d:%d:%d (%lu)\n",
			          yea, mth, dom, hou, min, sec, time);

			if (now_time >= time - 1 && now_time <= time + 4) { /* power on */
				pdn1 &= ~(RTC_PDN1_PWRON_TIME | RTC_PDN1_FAC_RESET | RTC_PDN1_BYPASS_PWR);
				RTC_Write(RTC_PDN1, pdn1);
				RTC_Write(RTC_PDN2, pdn2 | RTC_PDN2_PWRON_ALARM);
				rtc_write_trigger();
				if (can_alarm_boot &&
				        !(pdn2 & RTC_PDN2_PWRON_LOGO)) {        /* no logo means ALARM_BOOT */
					g_boot_mode = ALARM_BOOT;
				}
				return true;
			} else if (now_time < time) {   /* set power-on alarm */
				RTC_Write(RTC_AL_YEA,  (RTC_Read(RTC_AL_YEA) & ~(RTC_AL_YEA_MASK)) | ((yea - RTC_MIN_YEAR) & RTC_AL_YEA_MASK));
				RTC_Write(RTC_AL_MTH, (RTC_Read(RTC_AL_MTH)&RTC_NEW_SPARE3)|mth);
				RTC_Write(RTC_AL_DOM, (RTC_Read(RTC_AL_DOM)&RTC_NEW_SPARE1)|dom);
				RTC_Write(RTC_AL_HOU, (RTC_Read(RTC_AL_HOU)&RTC_AL_HOU_FG_MASK)|hou);
				RTC_Write(RTC_AL_MIN, min);
				RTC_Write(RTC_AL_SEC, (RTC_Read(RTC_AL_SEC) & (~RTC_AL_SEC_MASK)) | (sec & RTC_AL_SEC_MASK));
				RTC_Write(RTC_AL_MASK, RTC_AL_MASK_DOW);    /* mask DOW */
				rtc_write_trigger();
				irqen = RTC_Read(RTC_IRQ_EN) | RTC_IRQ_EN_ONESHOT_AL;
				RTC_Write(RTC_IRQ_EN, irqen);
				rtc_write_trigger();
			}
		}
	}

	if ((pdn1 & RTC_PDN1_RECOVERY_MASK) == RTC_PDN1_FAC_RESET) {    /* factory data reset */
		RTC_Write(RTC_PDN1, pdn1 & ~RTC_PDN1_FAC_RESET);
		rtc_write_trigger();
		return true;
	}

	if (pdn1 & RTC_PDN1_BYPASS_PWR) {   /* bypass power key detection */
		RTC_Write(RTC_PDN1, pdn1 & ~RTC_PDN1_BYPASS_PWR);
		rtc_write_trigger();
		return true;
	}

	return false;
}

void Set_Clr_RTC_PDN1_bit13(bool flag)
{
	U16 pdn1;

	rtc_writeif_unlock();
	//use PDN1 bit13 for LK
	pdn1 = RTC_Read(RTC_PDN1);
	if (flag==true)
		pdn1 = pdn1 | RTC_PDN1_FAST_BOOT;
	else if (flag==false)
		pdn1 = pdn1 & ~RTC_PDN1_FAST_BOOT;
	RTC_Write(RTC_PDN1, pdn1);
	rtc_write_trigger();
}

bool Check_RTC_PDN1_bit13(void)
{
	U16 pdn1;

	pdn1 = RTC_Read(RTC_PDN1);
	if (pdn1 & RTC_PDN1_FAST_BOOT)
		return true;
	else
		return false;
}

bool Check_RTC_Recovery_Mode(void)
{
	U16 pdn1;

	pdn1 = RTC_Read(RTC_PDN1);
	if ( (pdn1 & RTC_PDN1_RECOVERY_MASK)==RTC_PDN1_FAC_RESET )
		return true;
	else
		return false;
}
#if 1
bool rtc_2sec_boot_check(void)
{
	int boot_reason;

	if (g_boot_arg->maggic_number == BOOT_ARGUMENT_MAGIC) {
		boot_reason = g_boot_arg->boot_reason;

		if (boot_reason == BR_2SEC_REBOOT)
			return true;
	}

	return false;
}
#endif

void Set_RTC_Recovery_Mode(bool flag)
{
	U16 pdn1;
	rtc_writeif_unlock();
	pdn1 = RTC_Read(RTC_PDN1);
	if (flag==true)
		pdn1 = pdn1 | RTC_PDN1_FAC_RESET;
	else if (flag==false)
		pdn1 = pdn1 & ~RTC_PDN1_FAC_RESET;
	RTC_Write(RTC_PDN1, pdn1);
	rtc_write_trigger();
	DBG_RTC_I("Set_RTC_Fastboot_Mode\n");
}

static void rtc_get_tick(struct rtc_time *tm)
{
	tm->tm_sec = RTC_Read(RTC_TC_SEC);
	tm->tm_min = RTC_Read(RTC_TC_MIN);
	tm->tm_hour = RTC_Read(RTC_TC_HOU);
	tm->tm_mday = RTC_Read(RTC_TC_DOM);
	tm->tm_mon = RTC_Read(RTC_TC_MTH);
	tm->tm_year = RTC_Read(RTC_TC_YEA);
}

void rtc_get_time(struct rtc_time *tm) {
	rtc_get_tick(tm);
	if (RTC_Read(RTC_TC_SEC) < tm->tm_sec) {	/* SEC has carried */
		rtc_get_tick(tm);
	}
	tm->tm_year += RTC_MIN_YEAR;
}