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

#include "platform/mt_typedefs.h"
#include "platform/mtk_smi.h"
#include "platform/spm.h"

#define SMI_DEBUG_LEVEL	1
#define SMIDBG(level, fmt, args...) \
	do { \
		if ((level) > SMI_DEBUG_LEVEL)  \
			dprintf(INFO, "[SMI]"fmt, ##args); \
	} while (0)

#define SMI_MMSYS_ADDR	0x14000000
#define SMI_COMMON_ADDR	0x14002000
#define SMI_LARB0_ADDR	0x14003000

#define SMI_MASTER_SETTING_NUM	2
#define SMI_COMMON_REG_NUM	2
#define SMI_LARB0_REG_NUM	11

struct smi_reg_info {
	unsigned int offset;
	unsigned int value;
};

struct smi_master_info {
	unsigned long base_addr;
	int reg_num;
	struct smi_reg_info *reg_list;
};

static struct smi_reg_info smi_common_reg[SMI_COMMON_REG_NUM] = {
	{0x100, 0xb}, {0x444, 0x1}
};

static struct smi_reg_info smi_larb0_reg[SMI_LARB0_REG_NUM] = {
	{0x40, 0x1},
	{0x100, 0xb}, {0x104, 0xb}, {0x108, 0xb}, {0x10c, 0xb}, {0x110, 0xb},
	{0x380, 0x3}, {0x384, 0x3}, {0x388, 0x3}, {0x38c, 0x3}, {0x390, 0x3}
};

static struct smi_master_info smi_regs[SMI_MASTER_SETTING_NUM] = {
	{SMI_COMMON_ADDR, SMI_COMMON_REG_NUM, smi_common_reg},
	{SMI_LARB0_ADDR, SMI_LARB0_REG_NUM, smi_larb0_reg},
};

static inline unsigned int smi_read_reg(unsigned int base, unsigned int offset)
{
	return DRV_Reg32(base + offset);
}

static void smi_write_reg(unsigned int base, unsigned int offset,
	unsigned int value)
{
	unsigned int address = base + offset, prev = smi_read_reg(base, offset);

	DRV_WriteReg32(address, value);
	SMIDBG(INFO, "%#x = %#x -- %#x --> %#x\n",
		address, prev, value, smi_read_reg(base, offset));
}

static void smi_clk_enable(void)
{
	smi_write_reg(SMI_MMSYS_ADDR, 0x108, 0x1f); /* set */
	SMIDBG(INFO, "enable mmsys clk, reg=%#x\n",
		smi_read_reg(SMI_MMSYS_ADDR, 0x100));
}

static void smi_clk_disable(void)
{
	smi_write_reg(SMI_MMSYS_ADDR, 0x104, 0x1f); /* clear */
	SMIDBG(INFO, "disable mmsys clk, reg=%#x\n",
		smi_read_reg(SMI_MMSYS_ADDR, 0x100));
}

void smi_apply_register_setting(void)
{
	int i, j;
	/* write SMI non on-the-fly register before DISP init
	 * when larb and common are idle */
	spm_mtcmos_ctrl_dis(1);
	smi_clk_enable();
	for (i = 0; i < SMI_MASTER_SETTING_NUM; i++)
		for (j = 0; j < smi_regs[i].reg_num; j++)
			smi_write_reg(smi_regs[i].base_addr,
				smi_regs[i].reg_list[j].offset,
				smi_regs[i].reg_list[j].value);
	smi_clk_disable();
}
