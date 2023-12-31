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
#include <boot_mode.h>

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

	/* 1. release srcclkena */
	reg_value = *INFRA_AO_MD_SRCCLKENA;
	reg_value &= ~0xFF;
	*INFRA_AO_MD_SRCCLKENA = reg_value;
	dprintf(CRITICAL, "[ccci-off]src clk ena = 0x%X\n", *INFRA_AO_MD_SRCCLKENA);
}

void md_power_off(void)
{
	unsigned int val;

	val = get_devinfo_with_index(6);
	if ((val & (0x1 << 0)) == 0)
		internal_md1_power_down();
	else
		dprintf(CRITICAL, "[ccci-off]md1 effused,no need power off\n");
}

static int load_md_image = -1;
void load_success_notify(int error_no)
{
	load_md_image = 0;
	dprintf(CRITICAL, "[ccci-on]load_md_image = %d\n", load_md_image);
}

#define INFRACFG_AO_BASE    (0x10001000)
#define INFRA_MISC2             (0xF0C)
#define INFRA_SRCCLKENA    (INFRACFG_AO_BASE + INFRA_MISC2)
#define MD1_BOOT_VECTOR_EN   (0x20000024)

static void md_power_on(void)
{
	unsigned int reg_value;

	/* 1. pmic in pre-loader by pmic */
	/* 2. Config. md_srcclkena */
	// MD srcclkena setting: [7:4]=4'h0110, [3:0]=4'h1101
	reg_value = DRV_Reg32(INFRA_SRCCLKENA);
	reg_value &= ~(0xFF);
	reg_value |= 0x21;
	DRV_WriteReg32(INFRA_SRCCLKENA, reg_value);
	dprintf(CRITICAL, "MD srcclkena setting:0x%x\n", DRV_Reg32(INFRA_SRCCLKENA));

	/* 3. power on MD MTCMOS by spm: wendell lin */
	spm_mtcmos_ctrl_md1(STA_POWER_ON);
	dprintf(CRITICAL, "MD1 MTCMOS power on done!\n");

	//default off on 95 ccci_write32(MD_RGU_BASE, WDT_MD_MODE, WDT_MD_MODE_KEY);
	/* 4. Trigger MD MCU to run */
	dprintf(CRITICAL, "Trigger MD run\n");
	DRV_WriteReg32(MD1_BOOT_VECTOR_EN, 1);
}

int md_power_control(BOOTMODE mode)
{
	if (!(mode == RECOVERY_BOOT/* ||
		mode == DOWNLOAD_BOOT ||
		mode == FASTBOOT */
#if defined(MTK_KERNEL_POWER_OFF_CHARGING) || defined(MTK_CHARGER_NEW_ARCH)
		|| mode == KERNEL_POWER_OFF_CHARGING_BOOT
		|| mode == LOW_POWER_OFF_CHARGING_BOOT
#endif
		) && (load_md_image == 0)) {
#if !defined(MACH_FPGA)
		md_power_on();
#endif
	} else {
#if !defined(NO_MD_POWER_DOWN)
	/* In certain platforms (MD:93, public key hash register resides
	 * at modem side, and we need modem power in order to set public
	 * key hash, which is part of modem image loading/verification
	 * process. Please do not move md1_power_down function call to
	 * earlier point at boot.
	 */
		md_power_off();
#endif

	}

	return 0;
}
