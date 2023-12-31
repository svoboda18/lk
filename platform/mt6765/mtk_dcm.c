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

#include <mtk_dcm.h>

#include <debug.h>
#include <stdlib.h>
#include <string.h>
#include <arch/arm.h>
#include <arch/arm/mmu.h>
#include <arch/ops.h>
#include <target/board.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>
#include <platform/sync_write.h>

#include <mtk_dcm_autogen.h>
#include "mtk_secure_api.h"



#define late_initcall(a)

#define DEFINE_MUTEX(a)
#define mutex_lock(a)
#define mutex_unlock(a)

#define IOMEM(a) (a)

#define dcm_smc_msg(init_type) \
		mt_secure_call(MTK_SIP_KERNEL_DCM, init_type, 0, 0, 0)
#define dcm_smc_read_cnt(type) \
		mt_secure_call(MTK_SIP_KERNEL_DCM, type, 1, 0, 0)
#define __raw_readl(addr)		DRV_Reg32(addr)

#define reg_read(addr)	 __raw_readl(IOMEM(addr))
#define reg_write(addr, val)   mt_reg_sync_writel((val), ((void *)addr))

#define MCUSYS_SMC_WRITE(addr, val)  reg_write(addr, val)
#define dcm_smc_msg_send(msg) dcm_smc_msg(msg)

#define dcm_err(fmt, args...)	dprintf(CRITICAL, fmt, ##args)
#define dcm_warn(fmt, args...)	dprintf(CRITICAL, fmt, ##args)
#define dcm_info(fmt, args...)	dprintf(INFO, fmt, ##args)
#define dcm_dbg(fmt, args...)	dprintf(SPEW, fmt, ##args)
#define dcm_ver(fmt, args...)	dprintf(SPEW, fmt, ##args)

#define REG_DUMP(addr) dcm_info("%-30s(0x%08x): 0x%08x\n", #addr, addr, reg_read(addr))
#define SECURE_REG_DUMP(addr) dcm_info("%-30s(0x%08x): 0x%08lx\n", #addr, addr, mcsi_reg_read(addr##_PHYS & 0xFFFF))

/** macro **/
#define and(v, a) ((v) & (a))
#define or(v, o) ((v) | (o))
#define aor(v, a, o) (((v) & (a)) | (o))

/** global **/
static short dcm_initiated;
#ifdef CTRL_BIGCORE_DCM_IN_KERNEL
/* Not in use.
 * static short dcm_cpu_cluster_stat;
 */
#endif

static unsigned int all_dcm_type = (ARMCORE_DCM_TYPE | MCUSYS_DCM_TYPE | MCSI_DCM_TYPE
				    | STALL_DCM_TYPE | RGU_DCM_TYPE
				    | GIC_SYNC_DCM_TYPE | INFRA_DCM_TYPE
				    | DDRPHY_DCM_TYPE | EMI_DCM_TYPE | DRAMC_DCM_TYPE
				    );
#if 1
static unsigned int init_dcm_type = (ARMCORE_DCM_TYPE | MCUSYS_DCM_TYPE | MCSI_DCM_TYPE
				    | STALL_DCM_TYPE | RGU_DCM_TYPE
				    | GIC_SYNC_DCM_TYPE | INFRA_DCM_TYPE
				    );
#else
static unsigned int init_dcm_type = (INFRA_DCM_TYPE
				    );
#endif

/*****************************************
 * following is implementation per DCM module.
 * 1. per-DCM function is 1-argu with ON/OFF/MODE option.
 *****************************************/
typedef int (*DCM_FUNC)(int);
typedef void (*DCM_PRESET_FUNC)(void);

int dcm_topckg(ENUM_TOPCKG_DCM on)
{
	return 0;
}

void dcm_infracfg_ao_emi_indiv(int on)
{
}

int dcm_infra_preset(int on)
{
	return 0;
}

int dcm_infra(ENUM_INFRA_DCM on)
{
	/*
	 * dcm_infracfg_ao_infra_bus_dcm(on);
	 */
	dcm_infracfg_ao_infra_peri(on);
	/*
	 * dcm_infracfg_ao_infra_emi_local_dcm(on);
	 */
	dcm_infracfg_ao_infra_mem(on);
	/*
	 * dcm_infracfg_ao_infra_rx_p2p_dcm(on);
	 */
	dcm_infracfg_ao_p2p_dsi_csi(on);
	/* 
	 * dcm_infracfg_ao_peri_bus_dcm(on);
	 */
	/* in dcm_infracfg_ao_infra_peri(on); */
	/*
	 * dcm_infracfg_ao_peri_module_dcm(on);
	 */
	dcm_infracfg_ao_audio(on);
	dcm_infracfg_ao_icusb(on);
	dcm_infracfg_ao_ssusb(on);
	
	return 0;
}

int dcm_peri(ENUM_PERI_DCM on)
{
	return 0;
}

int dcm_armcore(ENUM_ARMCORE_DCM mode)
{
	dcm_mcu_misccfg_bus_arm_pll_divider_dcm(mode);
	dcm_mcu_misccfg_mp0_arm_pll_divider_dcm(mode);
	dcm_mcu_misccfg_mp1_arm_pll_divider_dcm(mode);

	return 0;
}

int dcm_mcusys(ENUM_MCUSYS_DCM on)
{
	dcm_mcu_misccfg_adb400_dcm(on);
	dcm_mcu_misccfg_bus_sync_dcm(on);
	dcm_mcu_misccfg_bus_clock_dcm(on);
	dcm_mcu_misccfg_bus_fabric_dcm(on);
	dcm_mcu_misccfg_l2_shared_dcm(on);
	dcm_mcu_misccfg_mp0_sync_dcm_enable(on);
	dcm_mcu_misccfg_mp1_sync_dcm_enable(on);
	dcm_mcu_misccfg_mcu_misc_dcm(on);

	return 0;
}

int dcm_mcusys_preset(int on)
{
	return 0;
}

int dcm_big_core_preset(void)
{
	return 0;
}

int dcm_big_core(ENUM_BIG_CORE_DCM on)
{
	return 0;
}

int dcm_stall_preset(int on)
{
	/* Not gen'ed as Bianco. Check if necessary.
	 * dcm_mcu_misccfg_mp_stall_dcm(on);
	 */
	reg_write(SYNC_DCM_CLUSTER_CONFIG, 0x063f0000);

	return 0;
}

int dcm_stall(ENUM_STALL_DCM on)
{
	dcm_mcu_misccfg_mp0_stall_dcm(on);
	dcm_mcu_misccfg_mp1_stall_dcm(on);

	return 0;
}

int dcm_gic_sync(ENUM_GIC_SYNC_DCM on)
{
	dcm_mcu_misccfg_gic_sync_dcm(on);

	return 0;
}

int dcm_last_core(ENUM_LAST_CORE_DCM on)
{
	return 0;
}

int dcm_rgu(ENUM_RGU_DCM on)
{
	dcm_mp0_cpucfg_mp0_rgu_dcm(on);
	dcm_mp1_cpucfg_mp1_rgu_dcm(on);

	return 0;
}

int dcm_dramc_ao(ENUM_DRAMC_AO_DCM on)
{
	/* Not gen'd, Check why
	dcm_dramc_ch0_top1_dramc_dcm(on);
	dcm_dramc_ch1_top1_dramc_dcm(on);
	*/

	return 0;
}

int dcm_ddrphy(ENUM_DDRPHY_DCM on)
{
	/* Not gen'd, Check why
	dcm_dramc_ch0_top0_ddrphy(on);
	dcm_dramc_ch1_top0_ddrphy(on);
	 */

	return 0;
}

int dcm_emi(ENUM_EMI_DCM on)
{
	/* Not gen'd, Check why
	dcm_emi_dcm_emi_group(on);
	 */
	dcm_chn0_emi_dcm_emi_group(on);
	dcm_chn1_emi_dcm_emi_group(on);

	return 0;
}

int dcm_lpdma(ENUM_LPDMA_DCM on)
{
	return 0;
}

int dcm_pwrap(ENUM_PWRAP_DCM on)
{
	return 0;
}

int dcm_mcsi_preset(int on)
{
	return 0;
}

int dcm_mcsi(ENUM_MCSI_DCM on)
{
	dcm_mcucfg_mcsi_dcm(on);

	return 0;
}

/*****************************************************/
typedef struct _dcm {
	int current_state;
	int saved_state;
	int disable_refcnt;
	int default_state;
	DCM_FUNC func;
	DCM_PRESET_FUNC preset_func;
	int typeid;
	char *name;
} DCM;

static DCM dcm_array[NR_DCM_TYPE] = {
	{
	 .typeid = ARMCORE_DCM_TYPE,
	 .name = "ARMCORE_DCM",
	 .func = (DCM_FUNC) dcm_armcore,
	 .current_state = ARMCORE_DCM_MODE1,
	 .default_state = ARMCORE_DCM_MODE1,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = MCUSYS_DCM_TYPE,
	 .name = "MCUSYS_DCM",
	 .func = (DCM_FUNC) dcm_mcusys,
	 .preset_func = (DCM_PRESET_FUNC) dcm_mcusys_preset,
	 .current_state = MCUSYS_DCM_ON,
	 .default_state = MCUSYS_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = INFRA_DCM_TYPE,
	 .name = "INFRA_DCM",
	 .func = (DCM_FUNC) dcm_infra,
	 .preset_func = (DCM_PRESET_FUNC) dcm_infra_preset,
	 .current_state = INFRA_DCM_ON,
	 .default_state = INFRA_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = PERI_DCM_TYPE,
	 .name = "PERI_DCM",
	 .func = (DCM_FUNC) dcm_peri,
	 /*.preset_func = (DCM_PRESET_FUNC) dcm_peri_preset,*/
	 .current_state = PERI_DCM_ON,
	 .default_state = PERI_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = EMI_DCM_TYPE,
	 .name = "EMI_DCM",
	 .func = (DCM_FUNC) dcm_emi,
	 .current_state = EMI_DCM_ON,
	 .default_state = EMI_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = DRAMC_DCM_TYPE,
	 .name = "DRAMC_DCM",
	 .func = (DCM_FUNC) dcm_dramc_ao,
	 .current_state = DRAMC_AO_DCM_ON,
	 .default_state = DRAMC_AO_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = DDRPHY_DCM_TYPE,
	 .name = "DDRPHY_DCM",
	 .func = (DCM_FUNC) dcm_ddrphy,
	 .current_state = DDRPHY_DCM_ON,
	 .default_state = DDRPHY_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = STALL_DCM_TYPE,
	 .name = "STALL_DCM",
	 .func = (DCM_FUNC) dcm_stall,
	 .preset_func = (DCM_PRESET_FUNC) dcm_stall_preset,
	 .current_state = STALL_DCM_ON,
	 .default_state = STALL_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = BIG_CORE_DCM_TYPE,
	 .name = "BIG_CORE_DCM",
	 .func = (DCM_FUNC) dcm_big_core,
	 .current_state = BIG_CORE_DCM_ON,
	 .default_state = BIG_CORE_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = GIC_SYNC_DCM_TYPE,
	 .name = "GIC_SYNC_DCM",
	 .func = (DCM_FUNC) dcm_gic_sync,
	 .current_state = GIC_SYNC_DCM_ON,
	 .default_state = GIC_SYNC_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = LAST_CORE_DCM_TYPE,
	 .name = "LAST_CORE_DCM",
	 .func = (DCM_FUNC) dcm_last_core,
	 .current_state = LAST_CORE_DCM_ON,
	 .default_state = LAST_CORE_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = RGU_DCM_TYPE,
	 .name = "RGU_CORE_DCM",
	 .func = (DCM_FUNC) dcm_rgu,
	 .current_state = RGU_DCM_ON,
	 .default_state = RGU_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = TOPCKG_DCM_TYPE,
	 .name = "TOPCKG_DCM",
	 .func = (DCM_FUNC) dcm_topckg,
	 .current_state = TOPCKG_DCM_ON,
	 .default_state = TOPCKG_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = LPDMA_DCM_TYPE,
	 .name = "LPDMA_DCM",
	 .func = (DCM_FUNC) dcm_lpdma,
	 .current_state = LPDMA_DCM_ON,
	 .default_state = LPDMA_DCM_ON,
	 .disable_refcnt = 0,
	 },
	 {
	 .typeid = MCSI_DCM_TYPE,
	 .name = "MCSI_DCM",
	 .func = (DCM_FUNC) dcm_mcsi,
	 /*.preset_func = (DCM_PRESET_FUNC) dcm_mcsi_preset,*/
	 .current_state = MCSI_DCM_ON,
	 .default_state = MCSI_DCM_ON,
	 .disable_refcnt = 0,
	 },
};

/*****************************************
 * DCM driver will provide regular APIs :
 * 1. dcm_restore(type) to recovery CURRENT_STATE before any power-off reset.
 * 2. dcm_set_default(type) to reset as cold-power-on init state.
 * 3. dcm_disable(type) to disable all dcm.
 * 4. dcm_set_state(type) to set dcm state.
 * 5. dcm_dump_state(type) to show CURRENT_STATE.
 * 6. /sys/power/dcm_state interface:  'restore', 'disable', 'dump', 'set'. 4 commands.
 *
 * spsecified APIs for workaround:
 * 1. (definitely no workaround now)
 *****************************************/
void dcm_set_default(unsigned int type)
{
	int i;
	DCM *dcm;

#ifndef ENABLE_DCM_IN_LK
	dcm_warn("[%s]type:0x%X, init_dcm_type=0x%X\n", __func__, type, init_dcm_type);
#else
	dcm_warn("[%s]type:0x%X, init_dcm_type=0x%X, INIT_DCM_TYPE_BY_K=0x%X\n",
		 __func__, type, init_dcm_type, INIT_DCM_TYPE_BY_K);
#endif

	mutex_lock(&dcm_lock);

	for (i = 0, dcm = &dcm_array[0]; i < NR_DCM_TYPE; i++, dcm++) {
		if (type & dcm->typeid) {
			dcm->saved_state = dcm->default_state;
			dcm->current_state = dcm->default_state;
			dcm->disable_refcnt = 0;
#ifdef ENABLE_DCM_IN_LK
			if (INIT_DCM_TYPE_BY_K & dcm->typeid) {
#endif
				if (dcm->preset_func)
					dcm->preset_func();
				dcm->func(dcm->current_state);
#ifdef ENABLE_DCM_IN_LK
			}
#endif

			dcm_info("[%s 0x%X] current state:%d (%d)\n",
				 dcm->name, dcm->typeid, dcm->current_state,
				 dcm->disable_refcnt);
		}
	}

	dcm_smc_msg_send(init_dcm_type);

	mutex_unlock(&dcm_lock);
}

void dcm_set_state(unsigned int type, int state)
{
	int i;
	DCM *dcm;
	unsigned int init_dcm_type_pre = init_dcm_type;

	dcm_warn("[%s]type:0x%X, set:%d, init_dcm_type_pre=0x%X\n",
		 __func__, type, state, init_dcm_type_pre);

	mutex_lock(&dcm_lock);

	for (i = 0, dcm = &dcm_array[0]; type && (i < NR_DCM_TYPE); i++, dcm++) {
		if (type & dcm->typeid) {
			type &= ~(dcm->typeid);

			dcm->saved_state = state;
			if (dcm->disable_refcnt == 0) {
				if (state)
					init_dcm_type |= dcm->typeid;
				else
					init_dcm_type &= ~(dcm->typeid);

				dcm->current_state = state;
				dcm->func(dcm->current_state);
			}

			dcm_info("[%s 0x%X] current state:%d (%d)\n",
				 dcm->name, dcm->typeid, dcm->current_state,
				 dcm->disable_refcnt);

		}
	}

	if (init_dcm_type_pre != init_dcm_type) {
		dcm_warn("[%s]type:0x%X, set:%d, init_dcm_type=0x%X->0x%X\n",
			 __func__, type, state, init_dcm_type_pre, init_dcm_type);
		dcm_smc_msg_send(init_dcm_type);
	}

	mutex_unlock(&dcm_lock);
}


void dcm_disable(unsigned int type)
{
	int i;
	DCM *dcm;
	unsigned int init_dcm_type_pre = init_dcm_type;

	dcm_warn("[%s]type:0x%X\n", __func__, type);

	mutex_lock(&dcm_lock);

	for (i = 0, dcm = &dcm_array[0]; type && (i < NR_DCM_TYPE); i++, dcm++) {
		if (type & dcm->typeid) {
			type &= ~(dcm->typeid);

			dcm->current_state = DCM_OFF;
			if (dcm->disable_refcnt++ == 0)
				init_dcm_type &= ~(dcm->typeid);
			dcm->func(dcm->current_state);

			dcm_info("[%s 0x%X] current state:%d (%d)\n",
				 dcm->name, dcm->typeid, dcm->current_state,
				 dcm->disable_refcnt);

		}
	}

	if (init_dcm_type_pre != init_dcm_type) {
		dcm_warn("[%s]type:0x%X, init_dcm_type=0x%X->0x%X\n",
			 __func__, type, init_dcm_type_pre, init_dcm_type);
		dcm_smc_msg_send(init_dcm_type);
	}

	mutex_unlock(&dcm_lock);

}

void dcm_restore(unsigned int type)
{
	int i;
	DCM *dcm;
	unsigned int init_dcm_type_pre = init_dcm_type;

	dcm_warn("[%s]type:0x%X\n", __func__, type);

	mutex_lock(&dcm_lock);

	for (i = 0, dcm = &dcm_array[0]; type && (i < NR_DCM_TYPE); i++, dcm++) {
		if (type & dcm->typeid) {
			type &= ~(dcm->typeid);

			if (dcm->disable_refcnt > 0)
				dcm->disable_refcnt--;
			if (dcm->disable_refcnt == 0) {
				if (dcm->saved_state)
					init_dcm_type |= dcm->typeid;
				else
					init_dcm_type &= ~(dcm->typeid);

				dcm->current_state = dcm->saved_state;
				dcm->func(dcm->current_state);
			}

			dcm_info("[%s 0x%X] current state:%d (%d)\n",
				 dcm->name, dcm->typeid, dcm->current_state,
				 dcm->disable_refcnt);

		}
	}

	if (init_dcm_type_pre != init_dcm_type) {
		dcm_warn("[%s]type:0x%X, init_dcm_type=0x%X->0x%X\n",
			 __func__, type, init_dcm_type_pre, init_dcm_type);
		dcm_smc_msg_send(init_dcm_type);
	}

	mutex_unlock(&dcm_lock);
}


void dcm_dump_state(int type)
{
	int i;
	DCM *dcm;

	dcm_info("\n******** dcm dump state *********\n");
	for (i = 0, dcm = &dcm_array[0]; i < NR_DCM_TYPE; i++, dcm++) {
		if (type & dcm->typeid) {
			dcm_info("[%s 0x%X] current state:%d (%d)\n",
				 dcm->name, dcm->typeid, dcm->current_state,
				 dcm->disable_refcnt);
		}
	}
}

void dcm_dump_regs(void)
{
	dcm_info("\n******** dcm dump register *********\n");
	/*
	REG_DUMP(CPUSYS_RGU_SYNC_DCM);
	 */
	REG_DUMP(L2C_SRAM_CTRL);
	REG_DUMP(CCI_CLK_CTRL);
	REG_DUMP(BUS_FABRIC_DCM_CTRL);
	REG_DUMP(MCU_MISC_DCM_CTRL);
	REG_DUMP(CCI_ADB400_DCM_CONFIG);
	REG_DUMP(SYNC_DCM_CONFIG);
	REG_DUMP(SYNC_DCM_CLUSTER_CONFIG);
	REG_DUMP(MP_GIC_RGU_SYNC_DCM);
	REG_DUMP(MP0_PLL_DIVIDER_CFG);
	REG_DUMP(MP1_PLL_DIVIDER_CFG);
	REG_DUMP(BUS_PLL_DIVIDER_CFG);
	REG_DUMP(MCSIA_DCM_EN);

	REG_DUMP(INFRA_BUS_DCM_CTRL);
	REG_DUMP(PERI_BUS_DCM_CTRL);
	REG_DUMP(MEM_DCM_CTRL);
	REG_DUMP(P2P_RX_CLK_ON);

	/* Not gen'ed
	REG_DUMP(EMI_CONM);
	REG_DUMP(EMI_CONN);
	 */
	REG_DUMP(CHN0_EMI_CHN_EMI_CONB);
	REG_DUMP(CHN1_EMI_CHN_EMI_CONB);

	/* Not gen'ed
	REG_DUMP(DRAMC_CH0_TOP1_DRAMC_PD_CTRL);
	REG_DUMP(DRAMC_CH0_TOP1_CLKAR);
	REG_DUMP(DRAMC_CH1_TOP1_DRAMC_PD_CTRL);
	REG_DUMP(DRAMC_CH1_TOP1_CLKAR);

	REG_DUMP(DRAMC_CH0_TOP0_MISC_CG_CTRL0);
	REG_DUMP(DRAMC_CH0_TOP0_MISC_CG_CTRL2);
	REG_DUMP(DRAMC_CH0_TOP0_MISC_CTRL3);
	REG_DUMP(DRAMC_CH0_TOP0_SHU1_B0_DQ8);
	REG_DUMP(DRAMC_CH0_TOP0_SHU1_B1_DQ8);
	REG_DUMP(DRAMC_CH0_TOP0_SHU1_CA_CMD8);
	REG_DUMP(DRAMC_CH0_TOP0_SHU2_B0_DQ8);
	REG_DUMP(DRAMC_CH0_TOP0_SHU2_B1_DQ8);
	REG_DUMP(DRAMC_CH0_TOP0_SHU2_CA_CMD8);
	REG_DUMP(DRAMC_CH0_TOP0_SHU3_B0_DQ8);
	REG_DUMP(DRAMC_CH0_TOP0_SHU3_B1_DQ8);
	REG_DUMP(DRAMC_CH0_TOP0_SHU3_CA_CMD8);
	REG_DUMP(DRAMC_CH0_TOP0_SHU4_B0_DQ8);
	REG_DUMP(DRAMC_CH0_TOP0_SHU4_B1_DQ8);
	REG_DUMP(DRAMC_CH0_TOP0_SHU4_CA_CMD8);
	REG_DUMP(DRAMC_CH1_TOP0_MISC_CG_CTRL0);
	REG_DUMP(DRAMC_CH1_TOP0_MISC_CG_CTRL2);
	REG_DUMP(DRAMC_CH1_TOP0_MISC_CTRL3);
	REG_DUMP(DRAMC_CH1_TOP0_SHU1_B0_DQ8);
	REG_DUMP(DRAMC_CH1_TOP0_SHU1_B1_DQ8);
	REG_DUMP(DRAMC_CH1_TOP0_SHU1_CA_CMD8);
	REG_DUMP(DRAMC_CH1_TOP0_SHU2_B0_DQ8);
	REG_DUMP(DRAMC_CH1_TOP0_SHU2_B1_DQ8);
	REG_DUMP(DRAMC_CH1_TOP0_SHU2_CA_CMD8);
	REG_DUMP(DRAMC_CH1_TOP0_SHU3_B0_DQ8);
	REG_DUMP(DRAMC_CH1_TOP0_SHU3_B1_DQ8);
	REG_DUMP(DRAMC_CH1_TOP0_SHU3_CA_CMD8);
	REG_DUMP(DRAMC_CH1_TOP0_SHU4_B0_DQ8);
	REG_DUMP(DRAMC_CH1_TOP0_SHU4_B1_DQ8);
	REG_DUMP(DRAMC_CH1_TOP0_SHU4_CA_CMD8);
	 */

	REG_DUMP(MP0_CPUCFG_MP0_RGU_DCM_CONFIG);
	REG_DUMP(MP1_CPUCFG_MP1_RGU_DCM_CONFIG);
}

static int mt_dcm_dts_map(void)
{
	return 0;
}

int mt_dcm_init(void)
{
#ifdef DCM_BRINGUP
	dcm_warn("%s: skipped for bring up\n", __func__);
	return 0;
#endif

	if (dcm_initiated)
		return 0;

	if (mt_dcm_dts_map()) {
		dcm_err("%s: failed due to DTS failed\n", __func__);
		return -1;
	}

#if 0 /* WORKAROUND: Disable big core reg protection */
	reg_write(0x10202008, aor(reg_read(0x10202008), ~(0x3), 0x1));
	dcm_info("%s: 0x10202008=0x%x\n", __func__, reg_read(0x10202008));
#endif

#if 0
#ifdef CTRL_BIGCORE_DCM_IN_KERNEL
	/* big ext buck iso power on */
	reg_write(0x10B00260, reg_read(0x10B00260) & ~(0x1 << 2));
	dcm_info("%s: 0x10B00260=0x%x\n", __func__, reg_read(0x10B00260));
	dcm_cpu_cluster_stat |= DCM_CPU_CLUSTER_B;
#endif
#endif

#ifndef DCM_DEFAULT_ALL_OFF
	/** enable all dcm **/
	dcm_set_default(init_dcm_type);
#else /* DCM_DEFAULT_ALL_OFF */
	dcm_set_state(all_dcm_type, DCM_OFF);
#endif /* #ifndef DCM_DEFAULT_ALL_OFF */

	dcm_dump_regs();

	dcm_initiated = 1;

	return 0;
}
late_initcall(mt_dcm_init);

/**** public APIs *****/
void mt_dcm_disable(void)
{
	if (!dcm_initiated)
		return;

	dcm_disable(all_dcm_type);
}

void mt_dcm_restore(void)
{
	if (!dcm_initiated)
		return;

	dcm_restore(all_dcm_type);
}

unsigned int sync_dcm_convert_freq2div(unsigned int freq)
{
	unsigned int div = 0, min_freq = SYNC_DCM_CLK_MIN_FREQ;

	if (freq < min_freq)
		return 0;

	/* max divided ratio = Floor (CPU Frequency / (4 or 5) * system timer Frequency) */
	div = (freq / min_freq) - 1;
	if (div > SYNC_DCM_MAX_DIV_VAL)
		return SYNC_DCM_MAX_DIV_VAL;

	return div;
}

int sync_dcm_set_cci_div(unsigned int cci)
{
	if (!dcm_initiated)
		return -1;

	/*
	 * 1. set xxx_sync_dcm_div first
	 * 2. set xxx_sync_dcm_tog from 0 to 1 for making sure it is toggled
	 */
	reg_write(MCUCFG_SYNC_DCM_CCI_REG,
		  aor(reg_read(MCUCFG_SYNC_DCM_CCI_REG),
		      ~MCUCFG_SYNC_DCM_SEL_CCI_MASK,
		      cci << MCUCFG_SYNC_DCM_SEL_CCI));
	reg_write(MCUCFG_SYNC_DCM_CCI_REG, aor(reg_read(MCUCFG_SYNC_DCM_CCI_REG),
				       ~MCUCFG_SYNC_DCM_CCI_TOGMASK,
				       MCUCFG_SYNC_DCM_CCI_TOG0));
	reg_write(MCUCFG_SYNC_DCM_CCI_REG, aor(reg_read(MCUCFG_SYNC_DCM_CCI_REG),
				       ~MCUCFG_SYNC_DCM_CCI_TOGMASK,
				       MCUCFG_SYNC_DCM_CCI_TOG1));
	dcm_dbg("%s: MCUCFG_SYNC_DCM_CCI_REG=0x%X, cci_div_sel=%u/%u\n",
		 __func__, reg_read(MCUCFG_SYNC_DCM_CCI_REG),
		 (and(reg_read(MCUCFG_SYNC_DCM_CCI_REG),
		      MCUCFG_SYNC_DCM_SEL_CCI_MASK) >> MCUCFG_SYNC_DCM_SEL_CCI),
		 cci);

	return 0;
}

int sync_dcm_set_cci_freq(unsigned int cci)
{
	dcm_dbg("%s: cci=%u\n", __func__, cci);
	sync_dcm_set_cci_div(sync_dcm_convert_freq2div(cci));

	return 0;
}

int sync_dcm_set_mp0_div(unsigned int mp0)
{
	if (!dcm_initiated)
		return -1;

	/*
	 * 1. set xxx_sync_dcm_div first
	 * 2. set xxx_sync_dcm_tog from 0 to 1 for making sure it is toggled
	 */
	reg_write(MCUCFG_SYNC_DCM_MP0_REG,
		  aor(reg_read(MCUCFG_SYNC_DCM_MP0_REG),
		      ~MCUCFG_SYNC_DCM_SEL_MP0_MASK,
		      mp0 << MCUCFG_SYNC_DCM_SEL_MP0));
	reg_write(MCUCFG_SYNC_DCM_MP0_REG, aor(reg_read(MCUCFG_SYNC_DCM_MP0_REG),
				       ~MCUCFG_SYNC_DCM_MP0_TOGMASK,
				       MCUCFG_SYNC_DCM_MP0_TOG0));
	reg_write(MCUCFG_SYNC_DCM_MP0_REG, aor(reg_read(MCUCFG_SYNC_DCM_MP0_REG),
				       ~MCUCFG_SYNC_DCM_MP0_TOGMASK,
				       MCUCFG_SYNC_DCM_MP0_TOG1));
#ifdef __KERNEL__
	dcm_dbg("%s: MCUCFG_SYNC_DCM_MP0_REG=0x%08x, mp0_div_sel=%u, mp0 =%u\n",
#else
	dcm_dbg("%s: MCUCFG_SYNC_DCM_MP0_REG=0x%X, mp0_div_sel=%u, mp0 =%u\n",
#endif
		 __func__, reg_read(MCUCFG_SYNC_DCM_MP0_REG),
		 (and(reg_read(MCUCFG_SYNC_DCM_MP0_REG),
		      MCUCFG_SYNC_DCM_SEL_MP0_MASK) >> MCUCFG_SYNC_DCM_SEL_MP0),
		 mp0);

	return 0;
}

int sync_dcm_set_mp0_freq(unsigned int mp0)
{
	dcm_dbg("%s: mp0=%u\n", __func__, mp0);
	sync_dcm_set_mp0_div(sync_dcm_convert_freq2div(mp0));

	return 0;
}

int sync_dcm_set_mp1_div(unsigned int mp1)
{
	if (!dcm_initiated)
		return -1;

	/*
	 * 1. set xxx_sync_dcm_div first
	 * 2. set xxx_sync_dcm_tog from 0 to 1 for making sure it is toggled
	 */
	reg_write(MCUCFG_SYNC_DCM_MP1_REG,
		  aor(reg_read(MCUCFG_SYNC_DCM_MP1_REG),
			  ~MCUCFG_SYNC_DCM_SEL_MP1_MASK,
			  mp1 << MCUCFG_SYNC_DCM_SEL_MP1));
	reg_write(MCUCFG_SYNC_DCM_MP1_REG, aor(reg_read(MCUCFG_SYNC_DCM_MP1_REG),
					   ~MCUCFG_SYNC_DCM_MP1_TOGMASK,
					   MCUCFG_SYNC_DCM_MP1_TOG0));
	reg_write(MCUCFG_SYNC_DCM_MP1_REG, aor(reg_read(MCUCFG_SYNC_DCM_MP1_REG),
					   ~MCUCFG_SYNC_DCM_MP1_TOGMASK,
					   MCUCFG_SYNC_DCM_MP1_TOG1));
#ifdef __KERNEL__
	dcm_dbg("%s: MCUCFG_SYNC_DCM_MP1_REG=0x%08x, mp1_div_sel=%u, mp1 =%u\n",
#else
	dcm_dbg("%s: MCUCFG_SYNC_DCM_MP1_REG=0x%X, mp1_div_sel=%u, mp1 =%u\n",
#endif
		 __func__, reg_read(MCUCFG_SYNC_DCM_MP1_REG),
		 (and(reg_read(MCUCFG_SYNC_DCM_MP1_REG),
			  MCUCFG_SYNC_DCM_SEL_MP1_MASK) >> MCUCFG_SYNC_DCM_SEL_MP1),
		 mp1);

	return 0;
}

int sync_dcm_set_mp1_freq(unsigned int mp1)
{
	dcm_dbg("%s: mp1=%u\n", __func__, mp1);
	sync_dcm_set_mp1_div(sync_dcm_convert_freq2div(mp1));

	return 0;
}

int sync_dcm_set_mp2_div(unsigned int mp2)
{
	return 0;
}

int sync_dcm_set_mp2_freq(unsigned int mp2)
{
	return 0;
}

/* unit of frequency is MHz */
int sync_dcm_set_cpu_freq(unsigned int cci, unsigned int mp0, unsigned int mp1, unsigned int mp2)
{
	sync_dcm_set_cci_freq(cci);
	sync_dcm_set_mp0_freq(mp0);
	sync_dcm_set_mp1_freq(mp1);
	sync_dcm_set_mp2_freq(mp2);

	return 0;
}

int sync_dcm_set_cpu_div(unsigned int cci, unsigned int mp0, unsigned int mp1, unsigned int mp2)
{
	sync_dcm_set_cci_div(cci);
	sync_dcm_set_mp0_div(mp0);
	sync_dcm_set_mp1_div(mp1);
	sync_dcm_set_mp2_div(mp2);

	return 0;
}

