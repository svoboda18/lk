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
#include <platform/mt_pmic.h>
#include <platform/mt_pmic_dlpt.h>
#include <platform/mt_gpt.h>
#include <platform/boot_mode.h>
#include <platform/mt_gpio.h>
#include <printf.h>
#include <platform/upmu_common.h>
#ifdef MTK_CHARGER_NEW_ARCH
#include <mtk_charger.h>
#endif

#ifdef MTK_KERNEL_POWER_OFF_CHARGING
#define CFG_POWER_CHARGING
#endif

int imix_r = 170;
#ifdef CFG_POWER_CHARGING
/*****************************************************************************
 *  Global Variable
 ****************************************************************************/
static unsigned int count_time_out_adc_imp = 36;

/*****************************************************************************
 *  DLPT service
 ****************************************************************************/
void do_ptim(unsigned int *bat, signed int *cur)
{
	unsigned int vbat_reg;
	unsigned int count_adc_imp = 0;

	/* initial setting */
#if PMIC_ISENSE_SUPPORT && defined(SWCHR_POWER_PATH)
	/* For PMIC which supports ISENSE */
	pmic_set_register_value(PMIC_AUXADC_IMPEDANCE_CHSEL, 1);
#else
	/* For PMIC which do not support ISENSE */
	pmic_set_register_value(PMIC_AUXADC_IMPEDANCE_CHSEL, 0);
#endif
	pmic_set_register_value(PMIC_AUXADC_IMPEDANCE_CNT, 1);
	pmic_set_register_value(PMIC_AUXADC_IMPEDANCE_MODE, 1);
	pmic_set_register_value(PMIC_AUXADC_IMP_AUTORPT_PRD, 6);

	/* enable setting */
	pmic_set_register_value(PMIC_AUXADC_IMP_CK_SW_MODE, 1);
	pmic_set_register_value(PMIC_AUXADC_IMP_CK_SW_EN, 1);

	/* start setting */
	pmic_set_register_value(PMIC_AUXADC_IMP_AUTORPT_EN, 1);

	while (pmic_get_register_value(PMIC_AUXADC_IMPEDANCE_IRQ_STATUS) == 0) {
		if (count_adc_imp > count_time_out_adc_imp) {
			dprintf(CRITICAL, "do_ptim over %d times/ms\n", count_adc_imp);
			dprintf(CRITICAL, "AUXADC_IMPEDANCE_MODE=0x%x\n",
				pmic_get_register_value(PMIC_AUXADC_IMPEDANCE_MODE));
			dprintf(CRITICAL, "AUXADC_CLR_IMP_CNT_STOP=0x%x\n",
				pmic_get_register_value(PMIC_AUXADC_CLR_IMP_CNT_STOP));
			dprintf(CRITICAL, "AUXADC_IMPEDANCE_IRQ_STATUS=0x%x\n",
				pmic_get_register_value(PMIC_AUXADC_IMPEDANCE_IRQ_STATUS));
			dprintf(CRITICAL, "AUXADC_IMPEDANCE_IRQ_CLR=0x%x\n",
				pmic_get_register_value(PMIC_AUXADC_IMPEDANCE_IRQ_CLR));
			dprintf(CRITICAL, "AUXADC_IMPEDANCE_CHSEL=0x%x\n",
				pmic_get_register_value(PMIC_AUXADC_IMPEDANCE_CHSEL));
			dprintf(CRITICAL, "AUXADC_IMPEDANCE_CNT=0x%x\n",
				pmic_get_register_value(PMIC_AUXADC_IMPEDANCE_CNT));
			dprintf(CRITICAL, "AUXADC_IMP_AUTORPT_EN=0x%x\n",
				pmic_get_register_value(PMIC_AUXADC_IMP_AUTORPT_EN));
			dprintf(CRITICAL, "AUXADC_IMP_AUTORPT_PRD=0x%x\n",
				pmic_get_register_value(PMIC_AUXADC_IMP_AUTORPT_PRD));
			dprintf(CRITICAL, "RG_AUXADC_AO_1M_CK_PDN=0x%x\n",
				pmic_get_register_value(PMIC_RG_AUXADC_AO_1M_CK_PDN));
			dprintf(CRITICAL, "RG_AUXADC_1M_CK_PDN=0x%x\n",
				pmic_get_register_value(PMIC_RG_AUXADC_1M_CK_PDN));
			dprintf(CRITICAL, "RG_AUXADC_CK_PDN_HWEN=0x%x\n",
				pmic_get_register_value(PMIC_RG_AUXADC_CK_PDN_HWEN));
			dprintf(CRITICAL, "RG_AUXADC_CK_PDN=0x%x\n",
				pmic_get_register_value(PMIC_RG_AUXADC_CK_PDN));
			dprintf(CRITICAL, "RG_AUXADC_RNG_CK_PDN_HWEN=0x%x\n",
				pmic_get_register_value(PMIC_RG_AUXADC_RNG_CK_PDN_HWEN));
			dprintf(CRITICAL, "RG_AUXADC_RNG_CK_PDN=0x%x\n",
				pmic_get_register_value(PMIC_RG_AUXADC_RNG_CK_PDN));
			dprintf(CRITICAL, "RG_AUXADC_32K_CK_PDN_HWEN=0x%x\n",
				pmic_get_register_value(PMIC_RG_AUXADC_32K_CK_PDN_HWEN));
			dprintf(CRITICAL, "RG_AUXADC_32K_CK_PDN=0x%x\n",
				pmic_get_register_value(PMIC_RG_AUXADC_32K_CK_PDN));
			dprintf(CRITICAL, "RG_AUXADC_1K_CK_PDN=0x%x\n",
				pmic_get_register_value(PMIC_RG_AUXADC_1K_CK_PDN));
			dprintf(CRITICAL, "RG_HK_INTRP_CK_PDN_HWEN=0x%x\n",
				pmic_get_register_value(PMIC_RG_HK_INTRP_CK_PDN_HWEN));
			dprintf(CRITICAL, "RG_HK_INTRP_CK_PDN=0x%x\n",
				pmic_get_register_value(PMIC_RG_HK_INTRP_CK_PDN));
			dprintf(CRITICAL, "AUXADC_CK_AON=0x%x\n",
				pmic_get_register_value(PMIC_AUXADC_CK_AON));
			dprintf(CRITICAL, "AUXADC_IMP_CK_SW_MODE=0x%x\n",
				pmic_get_register_value(PMIC_AUXADC_IMP_CK_SW_MODE));
			dprintf(CRITICAL, "AUXADC_IMP_CK_SW_EN=0x%x\n",
				pmic_get_register_value(PMIC_AUXADC_IMP_CK_SW_EN));
			dprintf(CRITICAL, "RG_STRUP_AUXADC_RSTB_SEL=0x%x\n",
				pmic_get_register_value(PMIC_RG_STRUP_AUXADC_RSTB_SEL));
			dprintf(CRITICAL, "RG_STRUP_AUXADC_RSTB_SW=0x%x\n",
				pmic_get_register_value(PMIC_RG_STRUP_AUXADC_RSTB_SW));
			break;
		}
		count_adc_imp++;
		mdelay(1);
	}
	vbat_reg = pmic_get_register_value(PMIC_AUXADC_ADC_OUT_IMP);

	/* clear irq */
	pmic_set_register_value(PMIC_AUXADC_CLR_IMP_CNT_STOP, 1);
	pmic_set_register_value(PMIC_AUXADC_IMPEDANCE_IRQ_CLR, 1);
	pmic_set_register_value(PMIC_AUXADC_CLR_IMP_CNT_STOP, 0);
	pmic_set_register_value(PMIC_AUXADC_IMPEDANCE_IRQ_CLR, 0);

	/* stop setting */
	pmic_set_register_value(PMIC_AUXADC_IMP_AUTORPT_EN, 0);

	/* disable setting */
	pmic_set_register_value(PMIC_AUXADC_IMP_CK_SW_MODE, 0);
	pmic_set_register_value(PMIC_AUXADC_IMP_CK_SW_EN, 1);

	if (count_adc_imp <= count_time_out_adc_imp)
		*bat = (vbat_reg * 3 * 18000) / 32768;
	else {
#if PMIC_ISENSE_SUPPORT && defined(SWCHR_POWER_PATH)
		/* For PMIC which supports ISENSE */
		*bat = pmic_get_auxadc_value(AUXADC_LIST_ISENSE) * 10;
#else
		/* For PMIC which do not support ISENSE */
		*bat = pmic_get_auxadc_value(AUXADC_LIST_BATADC) * 10;
#endif
	}

	gauge_read_IM_current((void *)cur);

	dprintf(INFO, "[do_ptim] bat %d cur %d\n", *bat, *cur);
}

extern int wk_vbat_cali(int vbat_out, int vthr);

void do_ptim_gauge(unsigned int *bat, signed int *cur)
{
	unsigned int ptim_bat_vol = 0;
	signed int ptim_R_curr = 0;
	unsigned int volt[5] = {0};
	int curr[5] = {0};
	int i, j;
	int arraySize = sizeof(volt)/sizeof(volt[0]);

	for (i = 0; i < arraySize; i++) {
		do_ptim(&ptim_bat_vol, &ptim_R_curr);

		/* insertion sort */
		for (j = i; j > 0; j--) {
			if (ptim_bat_vol < volt[j - 1])
				volt[j] = volt[j - 1];
			else
				break;
		}
		volt[j] = ptim_bat_vol;

		/* insertion sort */
		for (j = i; j > 0; j--) {
			if (ptim_R_curr < curr[j - 1])
				curr[j] = curr[j - 1];
			else
				break;
		}
		curr[j] = ptim_R_curr;
	}

	*bat = volt[arraySize >> 1];
	*cur = curr[arraySize >> 1];
	*bat = wk_vbat_cali(*bat, pmic_get_auxadc_value(AUXADC_LIST_CHIP_TEMP));
	dprintf(CRITICAL, "%s, %d(%d, %d, %d, %d, %d), %d(%d, %d, %d, %d, %d)\n",
		__func__, *bat, volt[0], volt[1], volt[2], volt[3], volt[4],
		*cur, curr[0], curr[1], curr[2], curr[3], curr[4]);
}

#ifdef MTK_DLPT_SUPPORT
static void enable_dummy_load(unsigned int en)
{
	if (en == 1) {
		/* enable isink step */
		pmic_set_register_value(PMIC_ISINK_CH0_STEP, 0x7);
		pmic_set_register_value(PMIC_ISINK_CH1_STEP, 0x7);

		/* enable isink */
		pmic_set_register_value(PMIC_ISINK_CH0_BIAS_EN, 0x1);
		pmic_set_register_value(PMIC_ISINK_CH1_BIAS_EN, 0x1);
		pmic_set_register_value(PMIC_ISINK_CH0_EN, 0x1);
		pmic_set_register_value(PMIC_ISINK_CH1_EN, 0x1);
		/*PMICLOG("[enable dummy load]\n"); */
	} else {
		/* disable isink */
		pmic_set_register_value(PMIC_ISINK_CH0_EN, 0);
		pmic_set_register_value(PMIC_ISINK_CH1_EN, 0);
		pmic_set_register_value(PMIC_ISINK_CH0_BIAS_EN, 0);
		pmic_set_register_value(PMIC_ISINK_CH1_BIAS_EN, 0);
		/*PMICLOG("[disable dummy load]\n"); */
	}
}

static int get_rac_val(void)
{
	unsigned int ptim_bat_vol = 0;
	signed int ptim_R_curr = 0;
	int volt_1 = 0;
	int volt_2 = 0;
	int curr_1 = 0;
	int curr_2 = 0;
	int rac_cal = 0;
	int ret = 0;
	kal_bool retry_state = KAL_FALSE;
	int retry_count = 0;

	do {
		/*adc and fg-------------------------------------------------------- */
		do_ptim(&ptim_bat_vol, &ptim_R_curr);

		dprintf(INFO, "[1,Trigger ADC PTIM mode] volt1=%d, curr_1=%d\n", ptim_bat_vol, ptim_R_curr);
		volt_1 = ptim_bat_vol;
		curr_1 = ptim_R_curr;

		dprintf(INFO, "[2,enable dummy load]\n");
		enable_dummy_load(1);
		/* debug to measure bat volt & Isense */
		/* pmic_set_register_value(PMIC_RG_VIBR_EN, 0x1); */
		mdelay(1);
		/*Wait --------------------------------------------------------------*/

		/*adc and fg-------------------------------------------------------- */
		do_ptim(&ptim_bat_vol, &ptim_R_curr);

		dprintf(INFO, "[3,Trigger ADC PTIM mode again] volt2=%d, curr_2=%d\n", ptim_bat_vol, ptim_R_curr);
		volt_2 = ptim_bat_vol;
		curr_2 = ptim_R_curr;

		/*Disable dummy load-------------------------------------------------*/
		enable_dummy_load(0);
		/* debug to measure bat volt & Isense */

		/*Calculate Rac------------------------------------------------------ */
		if ((curr_2 - curr_1) >= 700 && (curr_2 - curr_1) <= 1200
		    && (volt_1 - volt_2) >= 80 && (volt_1 - volt_2) <= 2000) {
			/*40.0mA */
			rac_cal = ((volt_1 - volt_2) * 1000) / (curr_2 - curr_1);	/*m-ohm */

			if (rac_cal < 0)
				ret = (rac_cal - (rac_cal * 2)) * 1;
			else
				ret = rac_cal * 1;
		} else {
			ret = -1;
			dprintf(CRITICAL, "[4,Calculate Rac] bypass due to (curr_x-curr_y) < 40mA\n");
		}

		dprintf(INFO, "[5,Calculate Rac] volt_1=%d,volt_2=%d,curr_1=%d,curr_2=%d,rac_cal=%d,ret=%d,retry_count=%d,volt_diff=%d,curr_diff=%d\n",
		        volt_1, volt_2, curr_1, curr_2, rac_cal, ret, retry_count, (volt_1 - volt_2), (curr_2 - curr_1));

		retry_count++;

		if ((retry_count < 3) && (ret == -1))
			retry_state = KAL_TRUE;
		else
			retry_state = KAL_FALSE;

	} while (retry_state == KAL_TRUE);

	return ret;
}


void get_dlpt_imix_r(void)
{
	int rac_val[5], rac_val_sum = 0;
	int i;
	int validcnt = 0;
	int min = 1000, max = 0;

	/* if fast meta mode detected, skip DLPT to speed up */
	if ((g_boot_mode == META_BOOT) && !mt_get_gpio_in(g_boot_arg->fast_meta_gpio))
		return;
#ifdef MTK_CHARGER_NEW_ARCH
	if(!is_disable_charger()) {
		charger_enable_charging(false);
		charger_enable_power_path(false);
		mdelay(50);
#endif

	for (i = 0; i < 5; i++) {
		rac_val[i] = get_rac_val();
		if (rac_val[i] <= min && rac_val[i] != -1)
			min = rac_val[i];
		if (rac_val[i] >= max)
			max = rac_val[i];
		if (rac_val[i]!=-1) {
			rac_val_sum += rac_val[i];
			validcnt++;
		}
	}

	if (validcnt >= 4) {
		rac_val_sum = rac_val_sum - min - max;
		imix_r = rac_val_sum / (validcnt - 2);
	} else if (validcnt != 0) {
		imix_r = rac_val_sum / validcnt;
	}

	dprintf(CRITICAL, "[dlpt_R] rac_val:%d,%d,%d,%d,%d [%d:%d:%d], imix_r:%d\n",
		rac_val[0], rac_val[1], rac_val[2], rac_val[3], rac_val[4],
		min, max, validcnt, imix_r);

#ifdef MTK_CHARGER_NEW_ARCH
		charger_enable_power_path(true);
		check_bat_protect_status();
		charger_enable_charging(true);
	}
#endif

	return;
}
#endif /* end of #ifdef MTK_DLPT_SUPPORT */
#endif /* end of #ifdef CFG_POWER_CHARGING */
