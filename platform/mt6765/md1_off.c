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
#include <platform/upmu_hw.h>
#include <platform/sec_devinfo.h>
#include <platform/spm.h>
#include <debug.h>
#define UINT32P         (volatile unsigned int *)
#define INFRA_AO_BASE				(0x10001000)
#define INFRA_AO_MD_SRCCLKENA		(UINT32P (INFRA_AO_BASE+0x0F0C))

#define AP_TOP_CLK_GEN_BASE				(0x10000000)
#define REG_MD_CLK_SETTING			(UINT32P (AP_TOP_CLK_GEN_BASE+0x0000))

#define STA_POWER_DOWN  0
#define STA_POWER_ON    1
static void internal_md1_power_down(void)
{
	unsigned int reg_value;
	/* 0. power on md */
	spm_mtcmos_ctrl_md1(STA_POWER_DOWN);

	/* 1. md clock setting: gating */
	*REG_MD_CLK_SETTING |= ((1<<8)|(1<<9));

	/* 2. mixedsys topsm init, for release srcclkena in kernel */
	reg_value = *INFRA_AO_MD_SRCCLKENA;
	reg_value &= ~0xFF;
	*INFRA_AO_MD_SRCCLKENA = reg_value;
	dprintf(CRITICAL, "[ccci-off]src clk ena = 0x%X\n", *INFRA_AO_MD_SRCCLKENA);
}

void md_power_down(void)
{
	unsigned int val;

	val = get_devinfo_with_index(6);
	if ((val & (0x1 << 0)) == 0)
		internal_md1_power_down();
	else
		dprintf(CRITICAL, "[ccci-off]md1 effused,no need power off\n");
}
