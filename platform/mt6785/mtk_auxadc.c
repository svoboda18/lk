/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2019. All rights reserved.
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    mtk_auxadc.c
 *
 * Project:
 * --------
 *   Android_Software
 *
 * Description:
 * ------------
 *   This Module defines functions of mtk AUXADC
 *
 * Author:
 * -------
 * James Lo
 *
 ****************************************************************************/
#include <stdio.h>
#include <platform/mt_gpt.h>
#include <platform/mtk_auxadc_sw.h>
#include <platform/mtk_auxadc_hw.h>

static s32 cali_oe;
static s32 cali_ge;

static void mt_auxadc_update_cali(void)
{
	u32 cali_reg;
	u32 cali_ge_a;
	u32 cali_oe_a;

	cali_reg = (*(unsigned int *const)(ADC_CALI_EN_A_REG));

	if (((cali_reg & ADC_CALI_EN_A_MASK) >> ADC_CALI_EN_A_SHIFT) != 0) {
		cali_oe_a = (cali_reg & ADC_OE_A_MASK) >> ADC_OE_A_SHIFT;
		cali_ge_a = ((cali_reg & ADC_GE_A_MASK) >> ADC_GE_A_SHIFT);
		/* In sw implement guide, ge should div 4096. But we don't do that now due to it will multi 4096 later */
		cali_ge = cali_ge_a - 512;
		cali_oe = cali_oe_a - 512;
		dprintf(CRITICAL, "[adc_api]: cali_ge = 0x%x, cali_oe = 0x%x\n", cali_ge, cali_oe);
	} else {
		cali_oe = 0;
		cali_ge = 0;
		dprintf(CRITICAL, "[adc_api]: No efuse data");
	}
}

static int mt_auxadc_read_raw(int dwChannel, int *rawdata)
{
	unsigned int channel[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int idle_count = 0;
	int data_ready_count = 0;
	unsigned int raw;

	/* step1 check con2 if auxadc is busy */
	while ((*(volatile unsigned short *)AUXADC_CON2) & 0x01) {
		dprintf(CRITICAL, "[adc_api]: wait for module idle\n");
		udelay(10000);
		idle_count++;
		if (idle_count > 30) {
			//wait for idle time out
			dprintf(CRITICAL, "[adc_api]: wait for aux/adc idle time out\n");
			return -1;
		}
	}

	/* step2 clear bit */
	*(volatile unsigned short *)AUXADC_CON1 = *(volatile unsigned short *)AUXADC_CON1 & (~(1 << dwChannel));

	/* step3 read channel and make sure old ready bit == 0 */
	while ((*(volatile unsigned short *)(AUXADC_DAT0 + dwChannel * 0x04)) & (1<<12)) {
		dprintf(CRITICAL, "[adc_api]: wait for channel[%d] ready bit clear\n", dwChannel);
		udelay(10000);
		data_ready_count++;
		if (data_ready_count > 30) {
			dprintf(CRITICAL, "[adc_api]: wait for channel[%d] ready bit clear time out\n", dwChannel);
			return -2;
		}
	}

	/* step4 set bit  to trigger sample */
	*(volatile unsigned short *)AUXADC_CON1 = *(volatile unsigned short *)AUXADC_CON1 | (1 << dwChannel);

	/* step5 read channel and make sure  ready bit == 1 */
	udelay(25); /* we must dealay here for hw sample cahnnel data */
	while (0==((*(volatile unsigned short *)(AUXADC_DAT0 + dwChannel * 0x04)) & (1<<12))) {
		dprintf(CRITICAL, "[adc_api]: wait for channel[%d] ready bit == 1\n", dwChannel);
		udelay(10000);
		data_ready_count++;
		if (data_ready_count > 30) {
			//wait for idle time out
			dprintf(CRITICAL, "[adc_api]: wait for channel[%d] data ready time out\n", dwChannel);
			return -3;
		}
	}

	/* step6 read data */
	channel[dwChannel] = (*(volatile unsigned short *)(AUXADC_DAT0 + dwChannel * 0x04)) & 0x0FFF;

	*rawdata = channel[dwChannel];

	return 0;
}

int iio_read_channel_processed(int channel, int *val)
{
	static bool cali_read = false;
	unsigned int raw;
	int ret;

	if (cali_read == false) {
		mt_auxadc_update_cali();
		cali_read = true;
	}

	ret = mt_auxadc_read_raw(channel, &raw);
	if (ret) {
		dprintf(CRITICAL, "[adc_api]:%s get raw value error %d \n", __func__, ret);
		return -1;
	}

	*val = (4096 * (raw - cali_oe)) / (4096 + cali_ge);

	return 0;
}

