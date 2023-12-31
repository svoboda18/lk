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
*/

#include <mtk_dcm.h>

#include <debug.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arch/arm.h>
#include <arch/arm/mmu.h>
#include <arch/ops.h>
#include <target/board.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>
#include <platform/sync_write.h>

#include <mtk_dcm_autogen.h>

#define IOMEM(a) (a)
#define __raw_readl(addr)		DRV_Reg32(addr)
extern unsigned long mt_secure_call(unsigned long, unsigned long, unsigned long, unsigned long);
#define MTK_SIP_KERNEL_MCSI_NS_ACCESS	0x8200028B
#define mcsi_reg_read(offset) \
		mt_secure_call(MTK_SIP_KERNEL_MCSI_NS_ACCESS, 0, offset, 0)
#define mcsi_reg_write(val, offset) \
		mt_secure_call(MTK_SIP_KERNEL_MCSI_NS_ACCESS, 1, offset, val)
#define reg_read(addr)	 __raw_readl(addr)
#define reg_write(addr, val)   mt_reg_sync_writel((val), ((void *)addr))

#define MCUSYS_SMC_WRITE(addr, val)  reg_write(addr, val)
#define MCSI_SMC_WRITE(addr, val)  mcsi_reg_write(val, (addr##_PHYS & 0xFFFF))
#define MCSI_SMC_READ(addr)  mcsi_reg_read(addr##_PHYS & 0xFFFF)

#define INFRACFG_AO_DCM_DFS_MEM_CTRL_REG0_MASK ((0x1 << 0) | \
			(0x1f << 1) | \
			(0x1 << 6) | \
			(0x1 << 7) | \
			(0x1 << 8) | \
			(0x1f << 16) | \
			(0x1f << 21) | \
			(0x1 << 26))
#define INFRACFG_AO_DCM_DFS_MEM_CTRL_REG0_ON ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 6) | \
			(0x1 << 7) | \
			(0x1 << 8) | \
			(0x0 << 16) | \
			(0x1f << 21) | \
			(0x0 << 26))
#define INFRACFG_AO_DCM_DFS_MEM_CTRL_REG0_OFF ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 6) | \
			(0x1 << 7) | \
			(0x1 << 8) | \
			(0x0 << 16) | \
			(0x1f << 21) | \
			(0x0 << 26))

bool dcm_infracfg_ao_dcm_dfs_mem_ctrl_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(DFS_MEM_DCM_CTRL) &
		INFRACFG_AO_DCM_DFS_MEM_CTRL_REG0_MASK) ==
		(unsigned int) INFRACFG_AO_DCM_DFS_MEM_CTRL_REG0_ON);

	return ret;
}

void dcm_infracfg_ao_dcm_dfs_mem_ctrl(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'infracfg_ao_dcm_dfs_mem_ctrl'" */
		reg_write(DFS_MEM_DCM_CTRL,
			(reg_read(DFS_MEM_DCM_CTRL) &
			~INFRACFG_AO_DCM_DFS_MEM_CTRL_REG0_MASK) |
			INFRACFG_AO_DCM_DFS_MEM_CTRL_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'infracfg_ao_dcm_dfs_mem_ctrl'" */
		reg_write(DFS_MEM_DCM_CTRL,
			(reg_read(DFS_MEM_DCM_CTRL) &
			~INFRACFG_AO_DCM_DFS_MEM_CTRL_REG0_MASK) |
			INFRACFG_AO_DCM_DFS_MEM_CTRL_REG0_OFF);
	}
}

#define INFRACFG_AO_DCM_INFRA_BUS_REG0_MASK ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 2) | \
			(0x1 << 3) | \
			(0x1 << 4) | \
			(0x1f << 5) | \
			(0x1f << 10) | \
			(0x1 << 20) | \
			(0x1 << 21) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 30))
#define INFRACFG_AO_DCM_INFRA_BUS_REG0_ON ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x0 << 2) | \
			(0x0 << 3) | \
			(0x0 << 4) | \
			(0x10 << 5) | \
			(0x10 << 10) | \
			(0x1 << 20) | \
			(0x1 << 21) | \
			(0x1 << 22) | \
			(0x1 << 23) | \
			(0x1 << 30))
#define INFRACFG_AO_DCM_INFRA_BUS_REG0_OFF ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 2) | \
			(0x0 << 3) | \
			(0x0 << 4) | \
			(0x10 << 5) | \
			(0x10 << 10) | \
			(0x0 << 20) | \
			(0x1 << 21) | \
			(0x1 << 22) | \
			(0x0 << 23) | \
			(0x0 << 30))

bool dcm_infracfg_ao_dcm_infra_bus_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(INFRA_BUS_DCM_CTRL) &
		INFRACFG_AO_DCM_INFRA_BUS_REG0_MASK) ==
		(unsigned int) INFRACFG_AO_DCM_INFRA_BUS_REG0_ON);

	return ret;
}

void dcm_infracfg_ao_dcm_infra_bus(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'infracfg_ao_dcm_infra_bus'" */
		reg_write(INFRA_BUS_DCM_CTRL,
			(reg_read(INFRA_BUS_DCM_CTRL) &
			~INFRACFG_AO_DCM_INFRA_BUS_REG0_MASK) |
			INFRACFG_AO_DCM_INFRA_BUS_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'infracfg_ao_dcm_infra_bus'" */
		reg_write(INFRA_BUS_DCM_CTRL,
			(reg_read(INFRA_BUS_DCM_CTRL) &
			~INFRACFG_AO_DCM_INFRA_BUS_REG0_MASK) |
			INFRACFG_AO_DCM_INFRA_BUS_REG0_OFF);
	}
}

#define INFRACFG_AO_DCM_MEM_CTRL_REG0_MASK ((0x1 << 0) | \
			(0x1f << 1) | \
			(0x1 << 6) | \
			(0x1 << 7) | \
			(0x1 << 8) | \
			(0x7f << 9) | \
			(0x1f << 16) | \
			(0x1f << 21) | \
			(0x1 << 26) | \
			(0x1 << 27) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 31))
#define INFRACFG_AO_DCM_MEM_CTRL_REG0_ON ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 6) | \
			(0x1 << 7) | \
			(0x1 << 8) | \
			(0x0 << 9) | \
			(0x0 << 16) | \
			(0x1f << 21) | \
			(0x0 << 26) | \
			(0x1 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 31))
#define INFRACFG_AO_DCM_MEM_CTRL_REG0_OFF ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 6) | \
			(0x1 << 7) | \
			(0x1 << 8) | \
			(0x0 << 9) | \
			(0x0 << 16) | \
			(0x1f << 21) | \
			(0x0 << 26) | \
			(0x1 << 27) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 31))

bool dcm_infracfg_ao_dcm_mem_ctrl_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(MEM_DCM_CTRL) &
		INFRACFG_AO_DCM_MEM_CTRL_REG0_MASK) ==
		(unsigned int) INFRACFG_AO_DCM_MEM_CTRL_REG0_ON);

	return ret;
}

void dcm_infracfg_ao_dcm_mem_ctrl(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'infracfg_ao_dcm_mem_ctrl'" */
		reg_write(MEM_DCM_CTRL,
			(reg_read(MEM_DCM_CTRL) &
			~INFRACFG_AO_DCM_MEM_CTRL_REG0_MASK) |
			INFRACFG_AO_DCM_MEM_CTRL_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'infracfg_ao_dcm_mem_ctrl'" */
		reg_write(MEM_DCM_CTRL,
			(reg_read(MEM_DCM_CTRL) &
			~INFRACFG_AO_DCM_MEM_CTRL_REG0_MASK) |
			INFRACFG_AO_DCM_MEM_CTRL_REG0_OFF);
	}
}

#define INFRACFG_AO_DCM_PERI_BUS_REG0_MASK ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 3) | \
			(0x1 << 4) | \
			(0x1f << 5) | \
			(0x1f << 10) | \
			(0x1f << 15) | \
			(0x1 << 20) | \
			(0x1 << 21) | \
			(0x1 << 22) | \
			(0x1f << 23) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 31))
#define INFRACFG_AO_DCM_PERI_BUS_REG0_ON ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x0 << 3) | \
			(0x0 << 4) | \
			(0x1f << 5) | \
			(0x0 << 10) | \
			(0x1f << 15) | \
			(0x1 << 20) | \
			(0x1 << 21) | \
			(0x1 << 22) | \
			(0x0 << 23) | \
			(0x1 << 28) | \
			(0x1 << 29) | \
			(0x1 << 31))
#define INFRACFG_AO_DCM_PERI_BUS_REG0_OFF ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 3) | \
			(0x0 << 4) | \
			(0x1f << 5) | \
			(0x1f << 10) | \
			(0x0 << 15) | \
			(0x0 << 20) | \
			(0x0 << 21) | \
			(0x0 << 22) | \
			(0x0 << 23) | \
			(0x0 << 28) | \
			(0x0 << 29) | \
			(0x0 << 31))

bool dcm_infracfg_ao_dcm_peri_bus_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(PERI_BUS_DCM_CTRL) &
		INFRACFG_AO_DCM_PERI_BUS_REG0_MASK) ==
		(unsigned int) INFRACFG_AO_DCM_PERI_BUS_REG0_ON);

	return ret;
}

void dcm_infracfg_ao_dcm_peri_bus(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'infracfg_ao_dcm_peri_bus'" */
		reg_write(PERI_BUS_DCM_CTRL,
			(reg_read(PERI_BUS_DCM_CTRL) &
			~INFRACFG_AO_DCM_PERI_BUS_REG0_MASK) |
			INFRACFG_AO_DCM_PERI_BUS_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'infracfg_ao_dcm_peri_bus'" */
		reg_write(PERI_BUS_DCM_CTRL,
			(reg_read(PERI_BUS_DCM_CTRL) &
			~INFRACFG_AO_DCM_PERI_BUS_REG0_MASK) |
			INFRACFG_AO_DCM_PERI_BUS_REG0_OFF);
	}
}

#define INFRACFG_AO_DCM_TOP_P2P_RX_CK_REG0_MASK ((0xf << 0))
#define INFRACFG_AO_DCM_TOP_P2P_RX_CK_REG0_ON ((0x0 << 0))
#define INFRACFG_AO_DCM_TOP_P2P_RX_CK_REG0_OFF ((0xf << 0))

bool dcm_infracfg_ao_dcm_top_p2p_rx_ck_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(P2P_RX_CLK_ON) &
		INFRACFG_AO_DCM_TOP_P2P_RX_CK_REG0_MASK) ==
		(unsigned int) INFRACFG_AO_DCM_TOP_P2P_RX_CK_REG0_ON);

	return ret;
}

void dcm_infracfg_ao_dcm_top_p2p_rx_ck(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'infracfg_ao_dcm_top_p2p_rx_ck'" */
		reg_write(P2P_RX_CLK_ON,
			(reg_read(P2P_RX_CLK_ON) &
			~INFRACFG_AO_DCM_TOP_P2P_RX_CK_REG0_MASK) |
			INFRACFG_AO_DCM_TOP_P2P_RX_CK_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'infracfg_ao_dcm_top_p2p_rx_ck'" */
		reg_write(P2P_RX_CLK_ON,
			(reg_read(P2P_RX_CLK_ON) &
			~INFRACFG_AO_DCM_TOP_P2P_RX_CK_REG0_MASK) |
			INFRACFG_AO_DCM_TOP_P2P_RX_CK_REG0_OFF);
	}
}

#define TOPCKGEN_AO_MCU_ARMPLL_CA7LL_REG0_MASK ((0x1 << 2))
#define TOPCKGEN_AO_MCU_ARMPLL_CA7LL_REG0_ON ((0x1 << 2))
#define TOPCKGEN_AO_MCU_ARMPLL_CA7LL_REG0_OFF ((0x0 << 2))

bool dcm_topckgen_ao_mcu_armpll_ca7ll_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(INFRA_TOPCKGEN_DCMCTL) &
		TOPCKGEN_AO_MCU_ARMPLL_CA7LL_REG0_MASK) ==
		(unsigned int) TOPCKGEN_AO_MCU_ARMPLL_CA7LL_REG0_ON);

	return ret;
}

void dcm_topckgen_ao_mcu_armpll_ca7ll(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'topckgen_ao_mcu_armpll_ca7ll'" */
		reg_write(INFRA_TOPCKGEN_DCMCTL,
			(reg_read(INFRA_TOPCKGEN_DCMCTL) &
			~TOPCKGEN_AO_MCU_ARMPLL_CA7LL_REG0_MASK) |
			TOPCKGEN_AO_MCU_ARMPLL_CA7LL_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'topckgen_ao_mcu_armpll_ca7ll'" */
		reg_write(INFRA_TOPCKGEN_DCMCTL,
			(reg_read(INFRA_TOPCKGEN_DCMCTL) &
			~TOPCKGEN_AO_MCU_ARMPLL_CA7LL_REG0_MASK) |
			TOPCKGEN_AO_MCU_ARMPLL_CA7LL_REG0_OFF);
	}
}

#define DRAMC_DRAMC_DCM_REG0_MASK ((0x1 << 25) | \
			(0x1 << 26) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_DRAMC_DCM_REG0_ON ((0x1 << 25) | \
			(0x0 << 26) | \
			(0x1 << 30) | \
			(0x1 << 31))
#define DRAMC_DRAMC_DCM_REG0_OFF ((0x0 << 25) | \
			(0x1 << 26) | \
			(0x0 << 30) | \
			(0x0 << 31))

bool dcm_dramc_dramc_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(DRAMC_DRAMC_PD_CTRL) &
		DRAMC_DRAMC_DCM_REG0_MASK) ==
		(unsigned int) DRAMC_DRAMC_DCM_REG0_ON);

	return ret;
}

void dcm_dramc_dramc_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'dramc_dramc_dcm'" */
		reg_write(DRAMC_DRAMC_PD_CTRL,
			(reg_read(DRAMC_DRAMC_PD_CTRL) &
			~DRAMC_DRAMC_DCM_REG0_MASK) |
			DRAMC_DRAMC_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'dramc_dramc_dcm'" */
		reg_write(DRAMC_DRAMC_PD_CTRL,
			(reg_read(DRAMC_DRAMC_PD_CTRL) &
			~DRAMC_DRAMC_DCM_REG0_MASK) |
			DRAMC_DRAMC_DCM_REG0_OFF);
	}
}

#define MCUCFG_BUS_CLOCK_DCM_REG0_MASK ((0x1 << 8))
#define MCUCFG_BUS_CLOCK_DCM_REG0_ON ((0x1 << 8))
#define MCUCFG_BUS_CLOCK_DCM_REG0_OFF ((0x0 << 8))

bool dcm_mcucfg_bus_clock_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(CCI_CLK_CTRL) &
		MCUCFG_BUS_CLOCK_DCM_REG0_MASK) ==
		(unsigned int) MCUCFG_BUS_CLOCK_DCM_REG0_ON);

	return ret;
}

void dcm_mcucfg_bus_clock_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcucfg_bus_clock_dcm'" */
		reg_write(CCI_CLK_CTRL,
			(reg_read(CCI_CLK_CTRL) &
			~MCUCFG_BUS_CLOCK_DCM_REG0_MASK) |
			MCUCFG_BUS_CLOCK_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcucfg_bus_clock_dcm'" */
		reg_write(CCI_CLK_CTRL,
			(reg_read(CCI_CLK_CTRL) &
			~MCUCFG_BUS_CLOCK_DCM_REG0_MASK) |
			MCUCFG_BUS_CLOCK_DCM_REG0_OFF);
	}
}

#define MCUCFG_BUS_FABRIC_DCM_REG0_MASK ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 8) | \
			(0x1 << 9) | \
			(0x1 << 18))
#define MCUCFG_BUS_FABRIC_DCM_REG0_ON ((0x1 << 0) | \
			(0x1 << 1) | \
			(0x1 << 8) | \
			(0x1 << 9) | \
			(0x1 << 18))
#define MCUCFG_BUS_FABRIC_DCM_REG0_OFF ((0x0 << 0) | \
			(0x0 << 1) | \
			(0x0 << 8) | \
			(0x0 << 9) | \
			(0x0 << 18))

bool dcm_mcucfg_bus_fabric_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(BUS_FABRIC_DCM_CTRL) &
		MCUCFG_BUS_FABRIC_DCM_REG0_MASK) ==
		(unsigned int) MCUCFG_BUS_FABRIC_DCM_REG0_ON);

	return ret;
}

void dcm_mcucfg_bus_fabric_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcucfg_bus_fabric_dcm'" */
		reg_write(BUS_FABRIC_DCM_CTRL,
			(reg_read(BUS_FABRIC_DCM_CTRL) &
			~MCUCFG_BUS_FABRIC_DCM_REG0_MASK) |
			MCUCFG_BUS_FABRIC_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcucfg_bus_fabric_dcm'" */
		reg_write(BUS_FABRIC_DCM_CTRL,
			(reg_read(BUS_FABRIC_DCM_CTRL) &
			~MCUCFG_BUS_FABRIC_DCM_REG0_MASK) |
			MCUCFG_BUS_FABRIC_DCM_REG0_OFF);
	}
}

#define MCUCFG_L2_SHARED_DCM_REG0_MASK ((0x1 << 0))
#define MCUCFG_L2_SHARED_DCM_REG0_ON ((0x1 << 0))
#define MCUCFG_L2_SHARED_DCM_REG0_OFF ((0x0 << 0))

bool dcm_mcucfg_l2_shared_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(L2C_SRAM_CTRL) &
		MCUCFG_L2_SHARED_DCM_REG0_MASK) ==
		(unsigned int) MCUCFG_L2_SHARED_DCM_REG0_ON);

	return ret;
}

void dcm_mcucfg_l2_shared_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcucfg_l2_shared_dcm'" */
		reg_write(L2C_SRAM_CTRL,
			(reg_read(L2C_SRAM_CTRL) &
			~MCUCFG_L2_SHARED_DCM_REG0_MASK) |
			MCUCFG_L2_SHARED_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcucfg_l2_shared_dcm'" */
		reg_write(L2C_SRAM_CTRL,
			(reg_read(L2C_SRAM_CTRL) &
			~MCUCFG_L2_SHARED_DCM_REG0_MASK) |
			MCUCFG_L2_SHARED_DCM_REG0_OFF);
	}
}

#define MCUCFG_MCU_MISC_DCM_REG0_MASK ((0x1 << 0))
#define MCUCFG_MCU_MISC_DCM_REG0_ON ((0x1 << 0))
#define MCUCFG_MCU_MISC_DCM_REG0_OFF ((0x0 << 0))

bool dcm_mcucfg_mcu_misc_dcm_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(MCU_MISC_DCM_CTRL) &
		MCUCFG_MCU_MISC_DCM_REG0_MASK) ==
		(unsigned int) MCUCFG_MCU_MISC_DCM_REG0_ON);

	return ret;
}

void dcm_mcucfg_mcu_misc_dcm(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'mcucfg_mcu_misc_dcm'" */
		reg_write(MCU_MISC_DCM_CTRL,
			(reg_read(MCU_MISC_DCM_CTRL) &
			~MCUCFG_MCU_MISC_DCM_REG0_MASK) |
			MCUCFG_MCU_MISC_DCM_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'mcucfg_mcu_misc_dcm'" */
		reg_write(MCU_MISC_DCM_CTRL,
			(reg_read(MCU_MISC_DCM_CTRL) &
			~MCUCFG_MCU_MISC_DCM_REG0_MASK) |
			MCUCFG_MCU_MISC_DCM_REG0_OFF);
	}
}

#define EMI_DCM_EMI_GROUP_REG0_MASK ((0xff << 24))
#define EMI_DCM_EMI_GROUP_REG1_MASK ((0xff << 24))
#define EMI_DCM_EMI_GROUP_REG0_ON ((0x0 << 24))
#define EMI_DCM_EMI_GROUP_REG1_ON ((0x0 << 24))
#define EMI_DCM_EMI_GROUP_REG0_OFF ((0xff << 24))
#define EMI_DCM_EMI_GROUP_REG1_OFF ((0xff << 24))

bool dcm_emi_dcm_emi_group_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(EMI_CONM) &
		EMI_DCM_EMI_GROUP_REG0_MASK) ==
		(unsigned int) EMI_DCM_EMI_GROUP_REG0_ON);
	ret &= ((reg_read(EMI_CONN) &
		EMI_DCM_EMI_GROUP_REG1_MASK) ==
		(unsigned int) EMI_DCM_EMI_GROUP_REG1_ON);

	return ret;
}

void dcm_emi_dcm_emi_group(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'emi_dcm_emi_group'" */
		reg_write(EMI_CONM,
			(reg_read(EMI_CONM) &
			~EMI_DCM_EMI_GROUP_REG0_MASK) |
			EMI_DCM_EMI_GROUP_REG0_ON);
		reg_write(EMI_CONN,
			(reg_read(EMI_CONN) &
			~EMI_DCM_EMI_GROUP_REG1_MASK) |
			EMI_DCM_EMI_GROUP_REG1_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'emi_dcm_emi_group'" */
		reg_write(EMI_CONM,
			(reg_read(EMI_CONM) &
			~EMI_DCM_EMI_GROUP_REG0_MASK) |
			EMI_DCM_EMI_GROUP_REG0_OFF);
		reg_write(EMI_CONN,
			(reg_read(EMI_CONN) &
			~EMI_DCM_EMI_GROUP_REG1_MASK) |
			EMI_DCM_EMI_GROUP_REG1_OFF);
	}
}

#define CHN0_EMI_DCM_EMI_GROUP_REG0_MASK ((0xff << 24))
#define CHN0_EMI_DCM_EMI_GROUP_REG0_ON ((0x0 << 24))
#define CHN0_EMI_DCM_EMI_GROUP_REG0_OFF ((0xff << 24))

bool dcm_chn0_emi_dcm_emi_group_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(CHN0_EMI_CHN_EMI_CONB) &
		CHN0_EMI_DCM_EMI_GROUP_REG0_MASK) ==
		(unsigned int) CHN0_EMI_DCM_EMI_GROUP_REG0_ON);

	return ret;
}

void dcm_chn0_emi_dcm_emi_group(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'chn0_emi_dcm_emi_group'" */
		reg_write(CHN0_EMI_CHN_EMI_CONB,
			(reg_read(CHN0_EMI_CHN_EMI_CONB) &
			~CHN0_EMI_DCM_EMI_GROUP_REG0_MASK) |
			CHN0_EMI_DCM_EMI_GROUP_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'chn0_emi_dcm_emi_group'" */
		reg_write(CHN0_EMI_CHN_EMI_CONB,
			(reg_read(CHN0_EMI_CHN_EMI_CONB) &
			~CHN0_EMI_DCM_EMI_GROUP_REG0_MASK) |
			CHN0_EMI_DCM_EMI_GROUP_REG0_OFF);
	}
}

#define EFUSEC_DCM_EFUSE_AF_REG0_MASK ((0x1 << 2))
#define EFUSEC_DCM_EFUSE_AF_REG0_ON ((0x1 << 2))
#define EFUSEC_DCM_EFUSE_AF_REG0_OFF ((0x0 << 2))

bool dcm_efusec_dcm_efuse_af_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(EFUSEC_DCM_ON) &
		EFUSEC_DCM_EFUSE_AF_REG0_MASK) ==
		(unsigned int) EFUSEC_DCM_EFUSE_AF_REG0_ON);

	return ret;
}

void dcm_efusec_dcm_efuse_af(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'efusec_dcm_efuse_af'" */
		reg_write(EFUSEC_DCM_ON,
			(reg_read(EFUSEC_DCM_ON) &
			~EFUSEC_DCM_EFUSE_AF_REG0_MASK) |
			EFUSEC_DCM_EFUSE_AF_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'efusec_dcm_efuse_af'" */
		reg_write(EFUSEC_DCM_ON,
			(reg_read(EFUSEC_DCM_ON) &
			~EFUSEC_DCM_EFUSE_AF_REG0_MASK) |
			EFUSEC_DCM_EFUSE_AF_REG0_OFF);
	}
}

#define EFUSEC_DCM_EFUSE_BG_REG0_MASK ((0x1 << 1))
#define EFUSEC_DCM_EFUSE_BG_REG0_ON ((0x1 << 1))
#define EFUSEC_DCM_EFUSE_BG_REG0_OFF ((0x0 << 1))

bool dcm_efusec_dcm_efuse_bg_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(EFUSEC_DCM_ON) &
		EFUSEC_DCM_EFUSE_BG_REG0_MASK) ==
		(unsigned int) EFUSEC_DCM_EFUSE_BG_REG0_ON);

	return ret;
}

void dcm_efusec_dcm_efuse_bg(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'efusec_dcm_efuse_bg'" */
		reg_write(EFUSEC_DCM_ON,
			(reg_read(EFUSEC_DCM_ON) &
			~EFUSEC_DCM_EFUSE_BG_REG0_MASK) |
			EFUSEC_DCM_EFUSE_BG_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'efusec_dcm_efuse_bg'" */
		reg_write(EFUSEC_DCM_ON,
			(reg_read(EFUSEC_DCM_ON) &
			~EFUSEC_DCM_EFUSE_BG_REG0_MASK) |
			EFUSEC_DCM_EFUSE_BG_REG0_OFF);
	}
}

#define EFUSEC_DCM_EFUSE_COMMON_REG0_MASK ((0x1 << 0))
#define EFUSEC_DCM_EFUSE_COMMON_REG0_ON ((0x1 << 0))
#define EFUSEC_DCM_EFUSE_COMMON_REG0_OFF ((0x0 << 0))

bool dcm_efusec_dcm_efuse_common_is_on(void)
{
	bool ret = true;

	ret &= ((reg_read(EFUSEC_DCM_ON) &
		EFUSEC_DCM_EFUSE_COMMON_REG0_MASK) ==
		(unsigned int) EFUSEC_DCM_EFUSE_COMMON_REG0_ON);

	return ret;
}

void dcm_efusec_dcm_efuse_common(int on)
{
	if (on) {
		/* TINFO = "Turn ON DCM 'efusec_dcm_efuse_common'" */
		reg_write(EFUSEC_DCM_ON,
			(reg_read(EFUSEC_DCM_ON) &
			~EFUSEC_DCM_EFUSE_COMMON_REG0_MASK) |
			EFUSEC_DCM_EFUSE_COMMON_REG0_ON);
	} else {
		/* TINFO = "Turn OFF DCM 'efusec_dcm_efuse_common'" */
		reg_write(EFUSEC_DCM_ON,
			(reg_read(EFUSEC_DCM_ON) &
			~EFUSEC_DCM_EFUSE_COMMON_REG0_MASK) |
			EFUSEC_DCM_EFUSE_COMMON_REG0_OFF);
	}
}

