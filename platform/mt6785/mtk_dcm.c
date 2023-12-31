/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2018. All rights reserved.
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

#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>
#include <lk_builtin_dtb.h>
#endif

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
#define MCSI_SMC_WRITE(addr, val)  mcsi_reg_write(val, (addr##_PHYS & 0xFFFF))
#define MCSI_SMC_READ(addr)  mcsi_reg_read(addr##_PHYS & 0xFFFF)
#define dcm_smc_msg_send(msg) dcm_smc_msg(msg)

#define dcm_err(fmt, args...)	dprintf(CRITICAL, fmt, ##args)
#define dcm_warn(fmt, args...)	dprintf(CRITICAL, fmt, ##args)
#define dcm_info(fmt, args...)	dprintf(CRITICAL, fmt, ##args)
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
static short dcm_cpu_cluster_stat;
#endif

static unsigned int all_dcm_type = (ARMCORE_DCM_TYPE | MCUSYS_DCM_TYPE
				    | STALL_DCM_TYPE | INFRA_DCM_TYPE
				    | DDRPHY_DCM_TYPE | EMI_DCM_TYPE
				    | DRAMC_DCM_TYPE);

static unsigned int init_dcm_type = (ARMCORE_DCM_TYPE | MCUSYS_DCM_TYPE
				     | STALL_DCM_TYPE |  INFRA_DCM_TYPE);

#ifdef DEVICE_TREE_SUPPORT
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
	dcm_infracfg_ao_infra_bus_dcm(on);

	/* MT6785: Debounce setting, and not DCM really. */
	/* dcm_infracfg_ao_infra_emi_local_dcm(on); */

	dcm_infracfg_ao_infra_rx_p2p_dcm(on);
	dcm_infracfg_ao_peri_bus_dcm(on);
	dcm_infracfg_ao_peri_module_dcm(on);

	/* MT6785: INFRACFG_AO_MEM. It has been enabled in preloader. */
	/* dcm_infracfg_ao_mem_dcm_emi_group(on) */


	return 0;
}

int dcm_peri(ENUM_PERI_DCM on)
{
	return 0;
}

int dcm_armcore(ENUM_ARMCORE_DCM mode)
{
	dcm_mp_cpusys_top_bus_pll_div_dcm(mode);
	dcm_mp_cpusys_top_cpu_pll_div_0_dcm(mode);
	dcm_mp_cpusys_top_cpu_pll_div_1_dcm(mode);

	return 0;
}

int dcm_mcusys(ENUM_MCUSYS_DCM on)
{
	dcm_mp_cpusys_top_adb_dcm(on);
	dcm_mp_cpusys_top_apb_dcm(on);
	dcm_mp_cpusys_top_cpubiu_dbg_cg(on);
	dcm_mp_cpusys_top_cpubiu_dcm(on);
	dcm_mp_cpusys_top_misc_dcm(on);
	dcm_mp_cpusys_top_mp0_qdcm(on);

	dcm_cpccfg_reg_emi_wfifo(on);
	dcm_mp_cpusys_top_last_cor_idle_dcm(on);


	return 0;
}

int dcm_mcusys_preset(int on)
{
	return 0;
}

int dcm_big_core(ENUM_BIG_CORE_DCM on)
{
	return 0;
}

int dcm_stall_preset(int on)
{
	return 0;
}

int dcm_stall(ENUM_STALL_DCM on)
{
#if !defined(MTK_DISABLE_STALL_DCM)
	dcm_mp_cpusys_top_core_stall_dcm(on);
	dcm_mp_cpusys_top_fcm_stall_dcm(on);
/*	dcm_cpccfg_reg_mp_stall_dcm(on); */
#endif

	return 0;
}

int dcm_gic_sync(ENUM_GIC_SYNC_DCM on)
{
	return 0;
}

int dcm_last_core(ENUM_LAST_CORE_DCM on)
{
	return 0;
}

int dcm_rgu(ENUM_RGU_DCM on)
{
	return 0;
}

int dcm_dramc_ao(ENUM_DRAMC_AO_DCM on)
{
	dcm_dramc_ch1_top0_ddrphy(on);
	dcm_dramc_ch0_top0_ddrphy(on);
	return 0;
}

int dcm_ddrphy(ENUM_DDRPHY_DCM on)
{
	dcm_dramc_ch1_top5_ddrphy(on);
	dcm_dramc_ch0_top5_ddrphy(on);
	return 0;
}

int dcm_emi(ENUM_EMI_DCM on)
{
	dcm_chn0_emi_chn_emi_dcm(on);
	dcm_emi_emi_dcm(on);
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

int dcm_mcsi(int on)
{
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


/*
 * "DoE" relys on this array defintion and order. Don't modify/change this array.
 */
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
	 .current_state = MCUSYS_DCM_ON,
	 .default_state = MCUSYS_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = INFRA_DCM_TYPE,
	 .name = "INFRA_DCM",
	 .func = (DCM_FUNC) dcm_infra,
	 .current_state = INFRA_DCM_ON,
	 .default_state = INFRA_DCM_ON,
	 .disable_refcnt = 0,
	 },
	{
	 .typeid = PERI_DCM_TYPE,
	 .name = "PERI_DCM",
	 .func = (DCM_FUNC) dcm_peri,
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
	 .current_state = GIC_SYNC_DCM_OFF,
	 .default_state = GIC_SYNC_DCM_OFF,
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
	 .name = "RGU_DCM",
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
			if (!INIT_DCM_TYPE_BY_K && dcm->typeid) {
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
	/* mcusys */
	REG_DUMP(MP_CPUSYS_TOP_MP0_DCM_CFG0);
	REG_DUMP(MP_CPUSYS_TOP_MP0_DCM_CFG7);
	REG_DUMP(MP_CPUSYS_TOP_MP_MISC_DCM_CFG0);
	REG_DUMP(MP_CPUSYS_TOP_MP_ADB_DCM_CFG4);
	REG_DUMP(MP_CPUSYS_TOP_MCUSYS_DCM_CFG0);
	REG_DUMP(MP_CPUSYS_TOP_CPU_PLLDIV_CFG0);
	REG_DUMP(MP_CPUSYS_TOP_CPU_PLLDIV_CFG1);
	REG_DUMP(MP_CPUSYS_TOP_BUS_PLLDIV_CFG);
	REG_DUMP(MP_CPUSYS_TOP_MCSI_CFG2);
	REG_DUMP(MP_CPUSYS_TOP_MCSIC_DCM0);
	REG_DUMP(CPCCFG_REG_EMI_WFIFO);

	/* infra_ao */
	REG_DUMP(INFRA_BUS_DCM_CTRL);
	REG_DUMP(PERI_BUS_DCM_CTRL);
	REG_DUMP(MEM_DCM_CTRL);
	REG_DUMP(P2P_RX_CLK_ON);
	REG_DUMP(INFRA_AXIMEM_IDLE_BIT_EN_0);

	/* infra emi */
	REG_DUMP(INFRA_EMI_DCM_CFG0);
	REG_DUMP(INFRA_EMI_DCM_CFG1);
	REG_DUMP(INFRA_EMI_DCM_CFG3);
	REG_DUMP(TOP_CK_ANCHOR_CFG);

	/* emi */
	REG_DUMP(EMI_CONM);
	REG_DUMP(EMI_CONN);
	REG_DUMP(EMI_THRO_CTRL0);
	REG_DUMP(CHN0_EMI_CHN_EMI_CONB);

	/* dramc */
	REG_DUMP(DRAMC_CH0_TOP0_DRAMC_PD_CTRL);
	REG_DUMP(DRAMC_CH0_TOP0_CLKAR);
	REG_DUMP(DRAMC_CH1_TOP0_DRAMC_PD_CTRL);
	REG_DUMP(DRAMC_CH1_TOP0_CLKAR);

	/* ddrphy */
	REG_DUMP(DRAMC_CH0_TOP5_MISC_CG_CTRL0);
	REG_DUMP(DRAMC_CH0_TOP5_MISC_CG_CTRL2);
	REG_DUMP(DRAMC_CH0_TOP5_MISC_CTRL2);
	REG_DUMP(DRAMC_CH1_TOP5_MISC_CG_CTRL0);
	REG_DUMP(DRAMC_CH1_TOP5_MISC_CG_CTRL2);
	REG_DUMP(DRAMC_CH1_TOP5_MISC_CTRL2);

}

static int mt_dcm_dts_map(void)
{
	return 0;
}

#ifdef DEVICE_TREE_SUPPORT
static unsigned int disabled_by_dts(char *prop)
{
	int nodeoffset;
	unsigned int *data = NULL;
	int len = 0;
	void *lk_drv_fdt = get_lk_overlayed_dtb();

	if (lk_drv_fdt == NULL)
		panic("lk driver fdt is NULL!\n");

	nodeoffset = fdt_node_offset_by_compatible(lk_drv_fdt, -1, "mediatek,dcm");
	if (nodeoffset < 0) {
		dcm_warn("[DCM] mediatek,dcm not found in DTS!\n");
		return 0;
	}

	data = (unsigned int *) fdt_getprop(lk_drv_fdt, nodeoffset, prop, &len);
	if (data == NULL) {
		dcm_warn("[DCM] get property info fail in DTS.\n");
		return 0;
	}

	return fdt32_to_cpu(*(unsigned int *)data);
}
#endif


int mt_dcm_init(void)
{
	unsigned int mcu_disabled = 0;
	unsigned int infra_disabled = 0;

#ifdef DCM_BRINGUP
	dcm_warn("%s: skipped for bring up\n", __func__);
	return 0;
#endif

	if (dcm_initiated) {
		dcm_err("%s: failed due to initial again\n", __func__);
		return 0;
	}

	if (mt_dcm_dts_map()) {
		dcm_err("%s: failed due to DTS failed\n", __func__);
		return -1;
	}

#ifndef DCM_DEFAULT_ALL_OFF
#ifdef DEVICE_TREE_SUPPORT
	/* for DOE(debug 2.0) support */
	mcu_disabled = disabled_by_dts("mcu_disable");	/* get dts node from DTS */
	infra_disabled = disabled_by_dts("infra_disable");
	if (mcu_disabled && infra_disabled) {
		/* "MCU DCMs" includes ARMCORE_DCM_TYPE, MCUSYS_DCM_TYPE, and STALL_DCM_TYPE */
		dcm_warn("[DCM] Infra DCM is disabled by DTS\n");
		dcm_warn("[DCM] MCU DCM is disabled by DTS\n");
		dcm_set_state(ARMCORE_DCM_TYPE | MCUSYS_DCM_TYPE | STALL_DCM_TYPE | INFRA_DCM_TYPE, DCM_OFF);
	} else if (mcu_disabled) {
		dcm_warn("[DCM] MCU DCM is disabled by DTS\n");
		dcm_set_state(ARMCORE_DCM_TYPE | MCUSYS_DCM_TYPE | STALL_DCM_TYPE,  DCM_OFF);
	} else if (infra_disabled) {
		dcm_warn("[DCM] Infra DCM is disabled by DTS\n");
		dcm_set_state(INFRA_DCM_TYPE, DCM_OFF);
	}
#endif
	dcm_set_default(init_dcm_type);		/** enable init dcm **/

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
