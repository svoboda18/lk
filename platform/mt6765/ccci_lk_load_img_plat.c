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
#include <sys/types.h>
#include <stdint.h>
#include <platform/partition.h>
#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <platform/errno.h>
#include <printf.h>
#include <string.h>
#include <malloc.h>
#include <libfdt.h>
#include <platform/mt_gpt.h>
#include <platform/mt_emi_mpu.h>
#include <mtk_secure_api.h>
#include <assert.h>
#include <mt_boot.h>
#include <debug.h>
#define MODULE_NAME "LK_LD_MD"
#include "ccci_ld_md_core.h"
#include "ccci_ld_md_errno.h"

#define CCCI_SMEM_SIZE_DFD (448*1024)
#define CCCI_SMEM_SIZE_CCB_DHL (2*1024*1024)
#define CCCI_SMEM_SIZE_RAW_DHL (20*1024*1024)
#define CCCI_SMEM_SIZE_LWA (0) // (8*1024*1024)
#define CCCI_SMEM_SIZE_PHY_C_L0 (0*1024*1024)
#define CCCI_SMEM_SIZE_PHY_C_L1 (32*1024*1024)
#define CCCI_SMEM_SIZE_PHY_C_L2 (64*1024*1024)
#define CCCI_SMEM_SIZE_PHY_C_L3 (128*1024*1024)
#define CCCI_SMEM_SIZE_PHY_C_L4 (222*1024*1024)
#define CCB_DATA_BUF_DEFAULT_GEAR 1 /* NOTE: This value may be different at different platform */
#define CCB_DATA_BUF_SIZE (CCCI_SMEM_SIZE_CCB_DHL + CCCI_SMEM_SIZE_RAW_DHL)

/***************************************************************************************************
** Feature Option setting part
***************************************************************************************************/
#define ENABLE_EMI_PROTECTION

/***************************************************************************************************
** HW remap section
***************************************************************************************************/
extern unsigned int ddr_enable_4gb(void)__attribute__((weak));
static int is_4gb_ddr_support_en(void)
{
	int ret;
	if (ddr_enable_4gb) {
		ret = ddr_enable_4gb();
		ALWAYS_LOG("ddr_enable_4GB sta:%d\n", ret);
		return ret;
	} else {
		ALWAYS_LOG("ddr 4GB disable\n");
		return 0;
	}
}

/*-------- Register base part -------------------------------*/
/* HW remap for MD1 */

#define INFRA_AO_BASE   (0x10001000)
/* -- MD1 Bank 0 */
#define MD1_BANK0_MAP0 (INFRA_AO_BASE + 0x300)
#define MD1_BANK0_MAP1 (INFRA_AO_BASE + 0x304)
#define MD1_BANK0_MAP2 (INFRA_AO_BASE + 0x308)
#define MD1_BANK0_MAP3 (INFRA_AO_BASE + 0x30C)
/* -- MD1 Bank 1 */
#define MD1_BANK1_MAP0 (INFRA_AO_BASE + 0x310)
#define MD1_BANK1_MAP1 (INFRA_AO_BASE + 0x314)
#define MD1_BANK1_MAP2 (INFRA_AO_BASE + 0x318)
#define MD1_BANK1_MAP3 (INFRA_AO_BASE + 0x31C)

/* -- MD1 Bank 4 */
#define MD1_BANK4_MAP0 (INFRA_AO_BASE + 0x320)
#define MD1_BANK4_MAP1 (INFRA_AO_BASE + 0x324)
#define MD1_BANK4_MAP2 (INFRA_AO_BASE + 0x328)
#define MD1_BANK4_MAP3 (INFRA_AO_BASE + 0x32C)

/* HW remap lock register */
#define MD_HW_REMAP_LOCK (INFRA_AO_BASE + 0xF80)
#define MD1_LOCK         (1<<16)

static int md_mem_ro_rw_remapping(unsigned int md_id, unsigned long long addr)
{
	unsigned long long md_img_start_addr;
	unsigned int hw_remapping_bank0_map0 = 0;
	unsigned int hw_remapping_bank0_map1 = 0;
	unsigned int hw_remapping_bank0_map2 = 0;
	unsigned int hw_remapping_bank0_map3 = 0;
	unsigned int write_val;

	switch (md_id) {
		case 0: // MD1
			hw_remapping_bank0_map0 = MD1_BANK0_MAP0;
			hw_remapping_bank0_map1 = MD1_BANK0_MAP1;
			hw_remapping_bank0_map2 = MD1_BANK0_MAP2;
			hw_remapping_bank0_map3 = MD1_BANK0_MAP3;
			break;
		default:
			ALWAYS_LOG("Invalid md id:%d\n", md_id);
			return -1;
	}

	md_img_start_addr = addr;
	ALWAYS_LOG("---> Map 0x00000000 to 0x%llx for MD%d\n", addr, md_id+1);

	/* For MDx_BANK0_MAP0 */
	write_val = (((md_img_start_addr >> 24) | 0x1) & 0x3FF)
	            + ((((md_img_start_addr + 0x2000000*1) >> 8) | 1<<16) & 0x3FF0000);
	DRV_WriteReg32(hw_remapping_bank0_map0, write_val);
	ALWAYS_LOG("BANK0_MAP0 value:0x%X\n", DRV_Reg32(hw_remapping_bank0_map0));
	/* For MDx_BANK0_MAP1 */
	write_val = ((((md_img_start_addr + 0x2000000*2) >> 24) | 0x1) & 0x3FF)
	            + ((((md_img_start_addr + 0x2000000*3) >> 8) | 1<<16) & 0x3FF0000);
	DRV_WriteReg32(hw_remapping_bank0_map1, write_val);
	ALWAYS_LOG("BANK0_MAP1 value:0x%X\n", DRV_Reg32(hw_remapping_bank0_map1));
	/* For MDx_BANK0_MAP2 */
	write_val = ((((md_img_start_addr + 0x2000000*4) >> 24) | 0x1) & 0x3FF)
	            + ((((md_img_start_addr + 0x2000000*5) >> 8) | 1<<16) & 0x3FF0000);
	DRV_WriteReg32(hw_remapping_bank0_map2, write_val);
	ALWAYS_LOG("BANK0_MAP2 value:0x%X\n", DRV_Reg32(hw_remapping_bank0_map2));
	/* For MDx_BANK0_MAP3 */
	write_val = ((((md_img_start_addr + 0x2000000*6) >> 24) | 0x1) & 0x3FF)
	            + ((((md_img_start_addr + 0x2000000*7) >> 8) | 1<<16) & 0x3FF0000);
	DRV_WriteReg32(hw_remapping_bank0_map3, write_val);
	ALWAYS_LOG("BANK0_MAP3 value:0x%X\n", DRV_Reg32(hw_remapping_bank0_map3));

#ifdef DUMMY_AP_MODE
	/* For 256~512MB */
	if (md_id == MD_SYS1) {
		write_val = ((((md_img_start_addr + 0x2000000*8) >> 24) | 0x1) & 0x3FF)
		            + ((((md_img_start_addr + 0x2000000*9) >> 8) | 1<<16) & 0x3FF0000);
		DRV_WriteReg32(MD1_BANK1_MAP0, write_val);
		ALWAYS_LOG("BANK1_MAP0 value:0x%X\n", DRV_Reg32(MD1_BANK1_MAP0));

		write_val = ((((md_img_start_addr + 0x2000000*10) >> 24) | 0x1) & 0x3FF)
		            + ((((md_img_start_addr + 0x2000000*11) >> 8) | 1<<16) & 0x3FF0000);
		DRV_WriteReg32(MD1_BANK1_MAP1, write_val);
		ALWAYS_LOG("BANK1_MAP1 value:0x%X\n", DRV_Reg32(MD1_BANK1_MAP1));
		write_val = ((((md_img_start_addr + 0x2000000*12) >> 24) | 0x1) & 0x3FF)
		            + ((((md_img_start_addr + 0x2000000*13) >> 8) | 1<<16) & 0x3FF0000);
		DRV_WriteReg32(MD1_BANK1_MAP2, write_val);
		ALWAYS_LOG("BANK1_MAP2 value:0x%X\n", DRV_Reg32(MD1_BANK1_MAP2));

		write_val = ((((md_img_start_addr + 0x2000000*14) >> 24) | 0x1) & 0x3FF)
		            + ((((md_img_start_addr + 0x2000000*15) >> 8) | 1<<16) & 0x3FF0000);
		DRV_WriteReg32(MD1_BANK1_MAP3, write_val);
		ALWAYS_LOG("BANK1_MAP3 value:0x%X\n", DRV_Reg32(MD1_BANK1_MAP3));
	}
#endif

	return 0;
}


static int md_bank4_remapping_by_slot(unsigned int md_id, unsigned long long addr, int slot)
{
	unsigned int hw_remapping_bank4_map0 = 0;
	unsigned int hw_remapping_bank4_map1 = 0;
	unsigned int hw_remapping_bank4_map2 = 0;
	unsigned int hw_remapping_bank4_map3 = 0;
	unsigned int curr_val;

	switch (md_id) {
		case 0: // MD1
			hw_remapping_bank4_map0 = MD1_BANK4_MAP0;
			hw_remapping_bank4_map1 = MD1_BANK4_MAP1;
			hw_remapping_bank4_map2 = MD1_BANK4_MAP2;
			hw_remapping_bank4_map3 = MD1_BANK4_MAP3;
			break;

		default:
			ALWAYS_LOG("Invalid md id:%d\n", md_id);
			return -1;
	}

	switch (slot) {
		case 0:
			curr_val = DRV_Reg32(hw_remapping_bank4_map0);
			curr_val &= ~0x3FF;
			curr_val |= (((addr >> 24) | 0x1) & 0x3FF);
			DRV_WriteReg32(hw_remapping_bank4_map0, curr_val);
			ALWAYS_LOG("BANK4_MAP0 value:0x%X\n", DRV_Reg32(hw_remapping_bank4_map0));
			break;
		case 1:
			curr_val = DRV_Reg32(hw_remapping_bank4_map0);
			curr_val &= ~0x3FF0000;
			curr_val |= (((addr >> 8) | (1<<16)) & 0x3FF0000);
			DRV_WriteReg32(hw_remapping_bank4_map0, curr_val);
			ALWAYS_LOG("BANK4_MAP0 value:0x%X\n", DRV_Reg32(hw_remapping_bank4_map0));
			break;
		case 2:
			curr_val = DRV_Reg32(hw_remapping_bank4_map1);
			curr_val &= ~0x3FF;
			curr_val |= (((addr >> 24) | 0x1) & 0x3FF);
			DRV_WriteReg32(hw_remapping_bank4_map1, curr_val);
			ALWAYS_LOG("BANK4_MAP1 value:0x%X\n", DRV_Reg32(hw_remapping_bank4_map1));
			break;
		case 3:
			curr_val = DRV_Reg32(hw_remapping_bank4_map1);
			curr_val &= ~0x3FF0000;
			curr_val |= (((addr >> 8) | (1<<16)) & 0x3FF0000);
			DRV_WriteReg32(hw_remapping_bank4_map1, curr_val);
			ALWAYS_LOG("BANK4_MAP1 value:0x%X\n", DRV_Reg32(hw_remapping_bank4_map1));
			break;
		case 4:
			curr_val = DRV_Reg32(hw_remapping_bank4_map2);
			curr_val &= ~0x3FF;
			curr_val |= (((addr >> 24) | 0x1) & 0x3FF);
			DRV_WriteReg32(hw_remapping_bank4_map2, curr_val);
			ALWAYS_LOG("BANK4_MAP2 value:0x%X\n", DRV_Reg32(hw_remapping_bank4_map2));
			break;
		case 5:
			curr_val = DRV_Reg32(hw_remapping_bank4_map2);
			curr_val &= ~0x3FF0000;
			curr_val |= (((addr >> 8) | (1<<16)) & 0x3FF0000);
			DRV_WriteReg32(hw_remapping_bank4_map2, curr_val);
			ALWAYS_LOG("BANK4_MAP2 value:0x%X\n", DRV_Reg32(hw_remapping_bank4_map2));
			break;
		case 6:
			curr_val = DRV_Reg32(hw_remapping_bank4_map3);
			curr_val &= ~0x3FF;
			curr_val |= (((addr >> 24) | 0x1) & 0x3FF);
			DRV_WriteReg32(hw_remapping_bank4_map3, curr_val);
			ALWAYS_LOG("BANK4_MAP3 value:0x%X\n", DRV_Reg32(hw_remapping_bank4_map3));
			break;
		case 7:
			curr_val = DRV_Reg32(hw_remapping_bank4_map3);
			curr_val &= ~0x3FF0000;
			curr_val |= (((addr >> 8) | (1<<16)) & 0x3FF0000);
			DRV_WriteReg32(hw_remapping_bank4_map3, curr_val);
			ALWAYS_LOG("BANK4_MAP3 value:0x%X\n", DRV_Reg32(hw_remapping_bank4_map3));
			break;
		default:
			ALWAYS_LOG("Invalid slot id:%d\n", slot);
			return -1;
	}

	return 0;
}

static int md_smem_rw_remapping(unsigned int md_id, unsigned long long addr)
{
	unsigned int i;
	ALWAYS_LOG("---> Map 0x40000000 to 0x%llx for MD%d\n", addr, md_id+1);

	for (i = 0; i < 8; i++)
		md_bank4_remapping_by_slot(md_id, addr + 0x2000000*i, i);

	return 0;
}

static void md_emi_remapping_lock(unsigned int md_id)
{
	unsigned int reg_val;
	unsigned int lock_bit;

	switch (md_id) {
		case 0: // MD1
			lock_bit = MD1_LOCK;
			break;
		default:
			ALWAYS_LOG("Invalid md id:%d for lock\n", md_id);
			return;
	}

	reg_val = DRV_Reg32(MD_HW_REMAP_LOCK);
	ALWAYS_LOG("before hw remap lock: MD1[%d]\n", !!(reg_val&MD1_LOCK));
	DRV_WriteReg32(MD_HW_REMAP_LOCK, (reg_val|lock_bit));
	reg_val = DRV_Reg32(MD_HW_REMAP_LOCK);
	ALWAYS_LOG("before hw remap lock: MD1[%d]\n", !!(reg_val&MD1_LOCK));
}

/* =================================================== */
/* MPU Region defination                               */
/* =================================================== */
/* Note: This structure should sync with Kernel!!!!    */
typedef unsigned long long mpu_att_t;

typedef struct _mpu_cfg {
	unsigned int start;
	unsigned int end;
	int region;
	unsigned int permission[EMI_MPU_DGROUP_NUM];
	int relate_region;
} mpu_cfg_t;

#define MPU_REGION_ID_MD1_ROM           9
#define MPU_REGION_ID_MD_DSP1           10 /*DSP RO*/
#define MPU_REGION_ID_MD_DSP2           11 /*DSP RW*/
#define MPU_REGION_ID_MD_DRDI           12
#define MPU_REGION_ID_MD1_MCURW_HWRW    13
#define MPU_REGION_ID_MD1_MCURW_HWRO    14
#define MPU_REGION_ID_MD1_MCURO_HWRW    15
/* #define MPU_REGION_ID_PADDING1          15 */
#define MPU_REGION_ID_PADDING2          16
#define MPU_REGION_ID_PADDING3          17
#define MPU_REGION_ID_PADDING4          18
#define MPU_REGION_ID_PADDING5          19
#define MPU_REGION_ID_MD_PROTECT        30
#define MPU_REGION_ID_MD1_CCB           22
#define MPU_REGION_ID_MD1_SMEM          23

#define MPU_REGION_ID_AP                31
#define MPU_REGION_ID_TOTAL_NUM         (MPU_REGION_ID_AP + 1)

#define MPU_MDOMAIN_ID_AP       0
#define MPU_MDOMAIN_ID_MD1      1
#define MPU_MDOMAIN_ID_MDHW     7
#define MPU_MDOMAIN_ID_TOTAL_NUM    16

static const mpu_att_t mpu_att_default[MPU_REGION_ID_TOTAL_NUM][MPU_MDOMAIN_ID_TOTAL_NUM] = {
	/*===================================================================================================================*/
	/* No |  | D0(AP)    | D1(Rsv)      | D2(CONN) | D3(SCP)  | D4(MM)       | D5(Rsv )      | D6(MFG)      | D7(Rsv)
	    |D8(Rsv)   | D9(MD1)     | D10-D14(Rsv)              | D15(MDHW)  |*/
	/*--------------+----------------------------------------------------------------------------------------------------*/
	/* 0*/{}, /*Secure OS*/
	/* 1*/{}, /*ATF*/
	/* 2*/{}, /*Secure Memory*/
	/* 3*/{}, /*Tinysys-SSPM ROM*/
	/* 4*/{}, /*Tinysys-SSPM share buffer*/
	/* 5*/{}, /*Trusted UI*/
	/* 6*/{}, /*AMMS*/
	/* 7*/{}, /*AMMS*/
	/* 8*/{}, /*Security CCCI share memory*/
	/* 9*/{ SEC_R_NSEC_R,   SEC_R_NSEC_R,  [2 ... 6] = FORBIDDEN, SEC_R_NSEC_R,     [8 ... 15] = FORBIDDEN},
	/*10*/{ SEC_R_NSEC_R,   SEC_R_NSEC_R,  [2 ... 6] = FORBIDDEN, SEC_R_NSEC_R,     [8 ... 15] = FORBIDDEN},
	/*11*/{ SEC_R_NSEC_R,   NO_PROTECTION, [2 ... 6] = FORBIDDEN, NO_PROTECTION,    [8 ... 15] = FORBIDDEN},
	/*12*/{ SEC_R_NSEC_R,   SEC_R_NSEC_R, [2 ... 6] = FORBIDDEN, SEC_R_NSEC_R,    [8 ... 15] = FORBIDDEN}, /*DRDI*/
	/*13*/{ SEC_R_NSEC_R,   NO_PROTECTION, [2 ... 6] = FORBIDDEN, NO_PROTECTION,    [8 ... 15] = FORBIDDEN},
	/*14*/{ SEC_R_NSEC_R,   NO_PROTECTION, [2 ... 6] = FORBIDDEN, SEC_R_NSEC_R,     [8 ... 15] = FORBIDDEN},
	/*15*/{ SEC_R_NSEC_R,   SEC_R_NSEC_R,  [2 ... 6] = FORBIDDEN, NO_PROTECTION,    [8 ... 15] = FORBIDDEN},
	/*16*/{ SEC_R_NSEC_R,   FORBIDDEN,     [2 ... 6] = FORBIDDEN, FORBIDDEN,    [8 ... 15] = FORBIDDEN},
	/*17*/{ SEC_R_NSEC_R,   FORBIDDEN,     [2 ... 6] = FORBIDDEN, FORBIDDEN,    [8 ... 15] = FORBIDDEN},
	/*18*/{ SEC_R_NSEC_R,   FORBIDDEN,     [2 ... 6] = FORBIDDEN, FORBIDDEN,    [8 ... 15] = FORBIDDEN},
	/*19*/{ SEC_R_NSEC_R,   FORBIDDEN,     [2 ... 6] = FORBIDDEN, FORBIDDEN,    [8 ... 15] = FORBIDDEN},
	/*20*/{},
	/*21*/{},/*MD-Consys Direct Path*/
	/*22*/{ NO_PROTECTION,  NO_PROTECTION, [2 ... 6] = FORBIDDEN, NO_PROTECTION,    [8 ... 15] = FORBIDDEN},
	/*23*/{ NO_PROTECTION,  NO_PROTECTION, FORBIDDEN, NO_PROTECTION,[4 ... 6] = FORBIDDEN, NO_PROTECTION,    [8 ... 15] = FORBIDDEN},
	/*24*/{}, /*Set in LK MD Padding1*/
	/*25*/{}, /*Set in LK MD Padding2*/
	/*26*/{}, /*Set in LK MD Padding3*/
	/*27*/{}, /*Set in LK MD Padding4*/
	/*28*/{}, /*Set in LK MD Padding5*/
	/*29*/{}, /*Set in LK MD Protect*/
	/*30*/{ NO_PROTECTION,  SEC_R_NSEC_R,  [2 ... 3] = FORBIDDEN, NO_PROTECTION, FORBIDDEN, SEC_R_NSEC_RW,
		[7 ... 15] = FORBIDDEN
	},
	/*31*/{
		NO_PROTECTION,  FORBIDDEN,  [2 ... 3] = FORBIDDEN, NO_PROTECTION, FORBIDDEN, SEC_R_NSEC_RW,
		[7 ... 15] = FORBIDDEN
	},
};

#define MPU_STR_BUF_SIZE    64

static void get_mpu_attr_str(int lock, unsigned int apc[EMI_MPU_DGROUP_NUM], char buf[], int size)
{
	unsigned long long curr_attr;
	char ch = lock?'L':'U';

	if (EMI_MPU_DGROUP_NUM != 2) {
		ALWAYS_LOG("[error]abnormal mpu domain group number %d\n", EMI_MPU_DGROUP_NUM);
		return;
	}
	curr_attr = ((unsigned long long)apc[1] << 32) | apc[0];
	snprintf(buf, size, "%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld(%c)",
	         curr_attr&7, (curr_attr>>3)&7, (curr_attr>>6)&7, (curr_attr>>9)&7,
	         (curr_attr>>12)&7, (curr_attr>>15)&7, (curr_attr>>18)&7, (curr_attr>>21)&7,
	         (curr_attr>>32)&7, (curr_attr>>35)&7, (curr_attr>>38)&7, (curr_attr>>41)&7,
	         (curr_attr>>44)&7, (curr_attr>>47)&7, (curr_attr>>50)&7, (curr_attr>>53)&7, ch);
}

static const unsigned char region_mapping_at_hdr_md1[] = {
	MPU_REGION_ID_MD1_ROM, MPU_REGION_ID_MD1_MCURO_HWRW, MPU_REGION_ID_MD1_MCURW_HWRO,
	MPU_REGION_ID_MD1_MCURW_HWRW
};

static const int free_mpu_region[] = {MPU_REGION_ID_PADDING2,
                                      MPU_REGION_ID_PADDING3, MPU_REGION_ID_PADDING4, MPU_REGION_ID_PADDING5, MPU_REGION_ID_MD_PROTECT, -1
                                     };
static int curr_free_mpu_idx;
static int get_free_mpu_region(void)
{
	int ret;
	if (curr_free_mpu_idx < (int)(sizeof(free_mpu_region)/sizeof(int))) {
		ret = free_mpu_region[curr_free_mpu_idx];
		curr_free_mpu_idx++;
	} else
		ret = -LD_ERR_PLAT_MPU_REGION_EMPTY;
	return ret;
}

/*make sure protect region is the last valid region*/
static int get_md_protect_mpu_region(void)
{
	int last_index;

	last_index = (int)(sizeof(free_mpu_region)/sizeof(int)) -1;
	if (free_mpu_region[last_index] < 0)    /*free region end by -1*/
		last_index--;   /*make sure it is index of last valid region*/

	if (curr_free_mpu_idx > last_index)
		return -LD_ERR_PLAT_MPU_REGION_EMPTY;

	return free_mpu_region[last_index];
}

static void get_mpu_region_default_access_att(
	unsigned int apc[EMI_MPU_DGROUP_NUM], int region, int lock)
{
#ifdef ENABLE_EMI_PROTECTION
	SET_ACCESS_PERMISSION(apc, lock,
		mpu_att_default[region][15], mpu_att_default[region][14],
		mpu_att_default[region][13], mpu_att_default[region][12],
		mpu_att_default[region][11], mpu_att_default[region][10],
		mpu_att_default[region][9], mpu_att_default[region][8],
		mpu_att_default[region][7], mpu_att_default[region][6],
		mpu_att_default[region][5], mpu_att_default[region][4],
		mpu_att_default[region][3], mpu_att_default[region][2],
		mpu_att_default[region][1], mpu_att_default[region][0]);
#endif
}

static void mpu_attr_calculate(
	unsigned int apc[EMI_MPU_DGROUP_NUM], int region_id, unsigned int request_attr)
{
	mpu_att_t tmp_mpu_att[MPU_MDOMAIN_ID_TOTAL_NUM], i;
	for (i = 0; i < MPU_MDOMAIN_ID_TOTAL_NUM; i++)
		tmp_mpu_att[i] = mpu_att_default[region_id][i];

	/* AP MD1 MDHW: AP */
	if ((request_attr & 0xF) <= FORBIDDEN)
		tmp_mpu_att[MPU_MDOMAIN_ID_AP] = (request_attr & 0xF);
	/* AP MD1 MDHW: MD1 */
	request_attr = (request_attr >> 4);
	if ((request_attr & 0xF) <= FORBIDDEN)
		tmp_mpu_att[MPU_MDOMAIN_ID_MD1] = (request_attr & 0xF);
	/* AP MD1 MDHW: MDHW */
	request_attr = (request_attr >> 4);
	if ((request_attr & 0xF) <= FORBIDDEN)
		tmp_mpu_att[MPU_MDOMAIN_ID_MDHW] = (request_attr & 0xF);
#ifdef ENABLE_EMI_PROTECTION
	/* MPU region lock */
	SET_ACCESS_PERMISSION(apc, 1,
		tmp_mpu_att[15], tmp_mpu_att[14],
		tmp_mpu_att[13], tmp_mpu_att[12],
		tmp_mpu_att[11], tmp_mpu_att[10],
		tmp_mpu_att[9], tmp_mpu_att[8],
		tmp_mpu_att[7], tmp_mpu_att[6],
		tmp_mpu_att[5], tmp_mpu_att[4],
		tmp_mpu_att[3], tmp_mpu_att[2],
		tmp_mpu_att[1], tmp_mpu_att[0]);
#endif
}

static void ccci_mem_access_cfg(mpu_cfg_t *mpu_cfg_list, int clear)
{
#ifdef ENABLE_EMI_PROTECTION
	mpu_cfg_t *curr;
	struct emi_region_info_t region_info;
	unsigned int curr_attr[EMI_MPU_DGROUP_NUM];
	char buf[MPU_STR_BUF_SIZE];
	int i;

	if (NULL == mpu_cfg_list)
		return;

	SET_ACCESS_PERMISSION(curr_attr, 0,
		NO_PROTECTION, NO_PROTECTION, NO_PROTECTION, NO_PROTECTION,
		NO_PROTECTION, NO_PROTECTION, NO_PROTECTION, NO_PROTECTION,
		NO_PROTECTION, NO_PROTECTION, NO_PROTECTION, NO_PROTECTION,
		NO_PROTECTION, NO_PROTECTION, NO_PROTECTION, NO_PROTECTION);
	for (curr = mpu_cfg_list; curr->region != -1; curr++) {
		if (clear) {
			region_info.region = (unsigned int)curr->region;
			emi_mpu_clear_protection(&region_info);
			get_mpu_attr_str(0, curr_attr, buf, MPU_STR_BUF_SIZE);
			ALWAYS_LOG("Clr MPU:S:0x%x E:0x%x A:<%d>[0~15]%s\n",
				0, 0, curr->region, buf);
		} else {
			region_info.start = curr->start;
			region_info.end = curr->end;
			region_info.region = (unsigned int)curr->region;
			for (i = 0; i < EMI_MPU_DGROUP_NUM; i++)
				region_info.apc[i] = curr->permission[i];
			emi_mpu_set_protection(&region_info);
			get_mpu_attr_str(0, curr->permission, buf, MPU_STR_BUF_SIZE);
			ALWAYS_LOG("Set MPU:S:0x%x E:0x%x A:<%d>[0~15]%s\n",
				curr->start, curr->end, curr->region, buf);
		}
	}
#endif
}

/*--------- Implement one by one -------------------------------------------------------------------------------*/
int plat_get_padding_mpu_num(void)
{
	return (int)(sizeof(free_mpu_region)/sizeof(unsigned int)) - 1;
}

/*---------------------------------------------------------------------------------------------------*/
/* Global variable for share memory                                                                  */
/*---------------------------------------------------------------------------------------------------*/
static unsigned int ap_md1_smem_size_at_lk_env;
static unsigned int md1_md3_smem_size_at_lk_env;
static unsigned int ap_md3_smem_size_at_lk_env;

static unsigned int ap_md1_smem_size_at_img;

#define AP_MD1_SMEM_SIZE    0x100000
#define MAX_SMEM_SIZE       0x4000000 //history: 6M-->256M-->64M
typedef struct _smem_layout {
	unsigned long long base_addr;
	unsigned int ap_md1_smem_offset;
	unsigned int ap_md1_smem_size;
	unsigned int ap_md3_smem_offset;
	unsigned int ap_md3_smem_size;
	unsigned int md1_md3_smem_offset;
	unsigned int md1_md3_smem_size;
	unsigned int total_smem_size;
} smem_layout_t;
static smem_layout_t smem_info;

typedef struct _ccb_layout {
	unsigned long long ccb_data_buffer_addr;
	unsigned int ccb_data_buffer_size;
} ccb_layout_t;
static ccb_layout_t ccb_info;

unsigned int md1_phy_cap_size;

void plat_notify_secure(unsigned long base_addr)
{
	unsigned long addr_get;

	mt_secure_call(MTK_SIP_LK_AMMS_MD_BASE_ADDR_AARCH32, base_addr, 0, 0, 0);
	addr_get = mt_secure_call(MTK_SIP_LK_AMMS_GET_MD_BASE_ADDR_AARCH32, 0, 0, 0, 0);
	ALWAYS_LOG("mt_secure_call: set_addr = 0x%lx, get_addr = 0x%lx\n", base_addr, addr_get);
}

/*---------------------------------------------------------------------------------------------------*/
/* HW remap function implement                                      */
/*---------------------------------------------------------------------------------------------------*/
int plat_apply_hw_remap_for_md_ro_rw(void* info)
{
	modem_info_t *md_ld_info = (modem_info_t *)info;

	plat_notify_secure(md_ld_info->base_addr);
	return md_mem_ro_rw_remapping((unsigned int)md_ld_info->md_id, md_ld_info->base_addr);
}

int plat_apply_hw_remap_for_md_smem(void *addr, int size)
{
	/* For share memory final size depends on MD number, just store start address and size
	** actual setting will do later
	*/
	smem_info.base_addr = (unsigned long long)((unsigned long)addr);
	return 0;
}

enum SMEM_USER_ID {
	SMEM_USER_RAW_DFD = 0,
	SMEM_USER_MAX,
};

int get_ccci_md_view_smem_addr_size(unsigned int user_id,
		unsigned long long *ap_addr, unsigned int *md_addr, unsigned int *size)
{
	int ret = 0;
	switch(user_id){
		case SMEM_USER_RAW_DFD:
			*size = CCCI_SMEM_SIZE_DFD;
			if (ap_addr)
				*ap_addr = smem_info.base_addr + smem_info.ap_md1_smem_offset + 0x100000;
			else
				ret = -2;
			if (md_addr)
				*md_addr = 0x40000000 + smem_info.ap_md1_smem_offset + 0x100000;
			else
				ret = -3;
			break;
		default:
			ret = -1;
	}
	if (ret >= 0)
		ALWAYS_LOG("[ccci]get_md_view_smem: user_id = 0x%x, ap_addr = 0x%llx, md_addr = 0x%x, size = 0x%x\n",
			user_id, *ap_addr, *md_addr, *size);
	else
		ALWAYS_LOG("[ccci]get_md_view_smem: param error, ret = %d\n", ret);
	return ret;
}

/*---------------------------------------------------------------------------------------------------*/
/* check header info collection by plat_post_hdr_info                                                */
/*---------------------------------------------------------------------------------------------------*/
void plat_post_hdr_info(void* hdr, int ver, int id)
{
	if (id == MD_SYS1) {
		ap_md1_smem_size_at_img = ((struct md_check_header_v6*)hdr)->ap_md_smem_size;
	}
}

/*---------------------------------------------------------------------------------------------------*/
/* MPU static global variable and mpu relate function implement                                      */
/*---------------------------------------------------------------------------------------------------*/
#define MPU_REGION_TOTAL_NUM    (16) /* = MD1+MD3 */
static mpu_cfg_t mpu_tbl[MPU_REGION_TOTAL_NUM];
static int s_g_curr_mpu_num;
/*
** if set start=0x0, end=0x10000, the actural protected area will be 0x0-0x1FFFF,
** here we use 64KB align, MPU actually request 32KB align since MT6582, but this works...
** we assume emi_mpu_set_region_protection will round end address down to 64KB align.
*/
static void dump_received_pure_mpu_setting(struct image_section_desc *mem_info, int item_num)
{
	int i;
	for (i =0; i < item_num; i++)
		MPU_DBG_LOG("mpu sec dec %d: offset:%x, size:%x, mpu_attr:%x, ext_flag:%x, relate_idx:%x\n", i,
		            mem_info[i].offset, mem_info[i].size, mem_info[i].mpu_attr,
		            mem_info[i].ext_flag, mem_info[i].relate_idx);
}
static int find_bind_mpu_region(mpu_cfg_t *mpu_tbl_hdr, int item_num, unsigned int bind_key)
{
	int i;
	for (i = 0; i < item_num; i++) {
		if (mpu_tbl_hdr[i].relate_region == (int)bind_key)
			return i;
	}

	return -1;
}
static int md1_mpu_setting_process(void *p_md_ld_info, void *p_mem_info, mpu_cfg_t *mpu_tbl_hdr)
{
	modem_info_t *md_ld_info = (modem_info_t *)p_md_ld_info;
	struct image_section_desc *mem_info = (struct image_section_desc *)p_mem_info;
	int normal_region_num = 0;
	int total_region_num = 0;
	int curr_idx = 0;
	int i, j;
	int all_range_region_idx = -1;
	int bind_idx;
	int free_region_id;
	int didi_region_idx = -1;

	/* Calculate mpu num and padding num */
	for (i = 0; i < MPU_REGION_TOTAL_NUM; i++) {
		if ((mem_info[i].offset == 0) && (mem_info[i].size == 0))
			break;

		if (mem_info[i].ext_flag & MD_ALL_RANGE)
			all_range_region_idx = i;
		if (mem_info[i].ext_flag & MD_DRDI_REGION)
			didi_region_idx = i;
	}
	total_region_num = i;

	dump_received_pure_mpu_setting(mem_info, total_region_num);

	for (i = 0; i < total_region_num; i++) {
		if (mem_info[i].ext_flag & (MD_DRDI_REGION|MD_ALL_RANGE|NEED_REMOVE|NEED_MPU_MORE))
			continue;
		/* Process normal case first */
		if (curr_idx >= (int)(sizeof(region_mapping_at_hdr_md1)/sizeof(unsigned char))) {
			ALWAYS_LOG("[error]md%d: mpu region too more %d\n", md_ld_info->md_id+1,
			           (int)(sizeof(region_mapping_at_hdr_md1)/sizeof(unsigned char)));
			return -LD_ERR_PLAT_MPU_REGION_TOO_MORE;
		}
		mpu_tbl_hdr[curr_idx].start = (unsigned int)md_ld_info->base_addr + mem_info[i].offset;
		mpu_tbl_hdr[curr_idx].end = mpu_tbl_hdr[curr_idx].start + mem_info[i].size;
		mpu_tbl_hdr[curr_idx].end = ((mpu_tbl_hdr[curr_idx].end + 0xFFFF)&(~0xFFFF)) - 1;/* 64K align */
		mpu_attr_calculate(
			mpu_tbl_hdr[curr_idx].permission, region_mapping_at_hdr_md1[curr_idx], mem_info[i].mpu_attr);
		mpu_tbl_hdr[curr_idx].region = (int)region_mapping_at_hdr_md1[curr_idx];
		mpu_tbl_hdr[curr_idx].relate_region = mem_info[i].relate_idx;
		curr_idx++;
		normal_region_num++;
	}
	if (normal_region_num != (int)(sizeof(region_mapping_at_hdr_md1)/sizeof(unsigned char))) {
		ALWAYS_LOG("[error]md%d: mpu region not sync %d:%d\n", md_ld_info->md_id+1, normal_region_num,
		           (int)(sizeof(region_mapping_at_hdr_md1)/sizeof(unsigned char)));
		return -LD_ERR_PLAT_MPU_REGION_NUM_NOT_SYNC;
	}
	for (i = 0; i < total_region_num; i++) {
		if (mem_info[i].ext_flag & NEED_MPU_MORE) {
			bind_idx = find_bind_mpu_region(mpu_tbl_hdr, curr_idx, mem_info[i].relate_idx);
			if (bind_idx >= 0) {
				mpu_tbl_hdr[curr_idx].start = (unsigned int)md_ld_info->base_addr + mem_info[i].offset;
				mpu_tbl_hdr[curr_idx].end = mpu_tbl_hdr[curr_idx].start + mem_info[i].size;
				/* 64K align */
				mpu_tbl_hdr[curr_idx].end = ((mpu_tbl_hdr[curr_idx].end + 0xFFFF)&(~0xFFFF)) - 1;
				for (j = 0; j < EMI_MPU_DGROUP_NUM; j++)
					mpu_tbl_hdr[curr_idx].permission[j] = mpu_tbl_hdr[bind_idx].permission[j];
				/* setting relate region */
				free_region_id = get_free_mpu_region();
				if (free_region_id < 0) {
					ALWAYS_LOG("[error]abnormal free region id %d +\n", free_region_id);
					return -LD_ERR_PLAT_ABNORMAL_FREE_REGION;
				}
				mpu_tbl_hdr[curr_idx].region = free_region_id;
				mpu_tbl_hdr[curr_idx].relate_region = mem_info[i].relate_idx;
				mpu_tbl_hdr[bind_idx].relate_region = free_region_id;
				curr_idx++;
			} else {
				ALWAYS_LOG("md%d: padding array abnormal\n", md_ld_info->md_id+1);
				return -LD_ERR_PLAT_ABNORMAL_PAD_ARRAY;
			}
		}
	}

	/* Apply DRDI if needed */
	if (didi_region_idx >= 0) {
		get_mpu_region_default_access_att(mpu_tbl_hdr[curr_idx].permission, MPU_REGION_ID_MD_DRDI, 1);
		mpu_tbl_hdr[curr_idx].start = (unsigned int)md_ld_info->base_addr + mem_info[didi_region_idx].offset;
		mpu_tbl_hdr[curr_idx].end = mpu_tbl_hdr[curr_idx].start + mem_info[didi_region_idx].size;
		/* 64K align */
		mpu_tbl_hdr[curr_idx].end = ((mpu_tbl_hdr[curr_idx].end + 0xFFFF)&(~0xFFFF)) - 1;
		mpu_tbl_hdr[curr_idx].region = MPU_REGION_ID_MD_DRDI;
		mpu_tbl_hdr[curr_idx].relate_region = 0;
		curr_idx++;
	}

	/* Apply MD all range mpu protect setting */
	free_region_id = get_md_protect_mpu_region(); //get_free_mpu_region();
	if (free_region_id < 0) {
		ALWAYS_LOG("[error]no more free region\n");
		return -LD_ERR_PLAT_NO_MORE_FREE_REGION;
	}
	get_mpu_region_default_access_att(mpu_tbl_hdr[curr_idx].permission, free_region_id, 1);
	mpu_tbl_hdr[curr_idx].start = (unsigned int)md_ld_info->base_addr + mem_info[all_range_region_idx].offset;
	/*mpu_tbl_hdr[curr_idx].end = mpu_tbl_hdr[curr_idx].start + mem_info[all_range_region_idx].size;*/
	mpu_tbl_hdr[curr_idx].end = mpu_tbl_hdr[curr_idx].start + 256 * 1024 * 1024;
	/* 64K align */
	mpu_tbl_hdr[curr_idx].end = ((mpu_tbl_hdr[curr_idx].end + 0xFFFF)&(~0xFFFF)) - 1;
	mpu_tbl_hdr[curr_idx].region = free_region_id;
	mpu_tbl_hdr[curr_idx].relate_region = 0;
	curr_idx++;

	/* Clear logic relate index to 0 to mark as end */
	for (i = 0; i < curr_idx; i++) {
		if (mpu_tbl_hdr[i].relate_region >= LOGIC_BINDING_IDX_START)
			mpu_tbl_hdr[i].relate_region = 0;
	}
	return curr_idx;
}

int plat_send_mpu_info_to_platorm(void *p_md_ld_info, void *p_mem_info)
{
	modem_info_t *md_ld_info = (modem_info_t *)p_md_ld_info;
	struct image_section_desc *mem_info = (struct image_section_desc *)p_mem_info;
	int md_id = md_ld_info->md_id;
	int ret;
	int i;
	char buf[MPU_STR_BUF_SIZE];

	if (md_id == MD_SYS1) {
		ret = md1_mpu_setting_process(p_md_ld_info, p_mem_info, &mpu_tbl[s_g_curr_mpu_num]);
		if (ret > 0)
			s_g_curr_mpu_num += ret;
	} else if (md_id == MD1_DSP) {
		/* RO part */
		get_mpu_region_default_access_att(mpu_tbl[s_g_curr_mpu_num].permission, MPU_REGION_ID_MD_DSP1, 1);
		mpu_tbl[s_g_curr_mpu_num].start = (unsigned int)md_ld_info->base_addr + mem_info[0].offset;
		mpu_tbl[s_g_curr_mpu_num].end = mpu_tbl[s_g_curr_mpu_num].start + mem_info[0].size;
		mpu_tbl[s_g_curr_mpu_num].region = MPU_REGION_ID_MD_DSP1;
		/* 64K align */
		mpu_tbl[s_g_curr_mpu_num].end = ((mpu_tbl[s_g_curr_mpu_num].end + 0xFFFF)&(~0xFFFF)) - 1;
		s_g_curr_mpu_num++;

		/* RW part */
		get_mpu_region_default_access_att(mpu_tbl[s_g_curr_mpu_num].permission, MPU_REGION_ID_MD_DSP2, 1);
		mpu_tbl[s_g_curr_mpu_num].start = (unsigned int)md_ld_info->base_addr + mem_info[1].offset;
		mpu_tbl[s_g_curr_mpu_num].end = mpu_tbl[s_g_curr_mpu_num].start + mem_info[1].size;
		mpu_tbl[s_g_curr_mpu_num].region = MPU_REGION_ID_MD_DSP2;
		/* 64K align */
		mpu_tbl[s_g_curr_mpu_num].end = ((mpu_tbl[s_g_curr_mpu_num].end + 0xFFFF)&(~0xFFFF)) - 1;
		s_g_curr_mpu_num++;
	}

	for (i =0; i < s_g_curr_mpu_num; i++) {
		get_mpu_attr_str(0, mpu_tbl[i].permission, buf, MPU_STR_BUF_SIZE);
		MPU_DBG_LOG("plat mpu dec %d: region:%d[%d], start:0x%x, end:0x%x, attr:%s\n", i,
		            mpu_tbl[i].region, mpu_tbl[i].relate_region, mpu_tbl[i].start, mpu_tbl[i].end, buf);
	}

	return 0;
}

static void set_ccb_gear_val(unsigned int gear_id)
{
	int ret;
	char env_buf[12];

	memset(env_buf, 0, sizeof(env_buf));
	snprintf(env_buf, sizeof(env_buf), "%u", gear_id);
	ret = set_env("md1_ccb_cap_gear", env_buf);
	if (ret < 0) {
		ALWAYS_LOG("set env[md1_ccb_cap_gear]fail, ret=%d\n", ret);
		assert(0);
	} else
		ALWAYS_LOG("set env[md1_ccb_cap_gear]%d\n", gear_id);
}

static unsigned int get_ccb_gear_val(void)
{
	unsigned int md1_ccb_cap_gear;

	if (g_boot_mode == META_BOOT || true == get_atm_enable_status()) {
		ALWAYS_LOG("meta mode[md1_ccb_cap_gear]%d\n", CCB_DATA_BUF_DEFAULT_GEAR);
		set_ccb_gear_val(CCB_DATA_BUF_DEFAULT_GEAR);
		return CCB_DATA_BUF_DEFAULT_GEAR;
	}
	md1_ccb_cap_gear = str2uint(get_env("md1_ccb_cap_gear"));
	if (md1_ccb_cap_gear != 0) {
		ALWAYS_LOG("get env[md1_ccb_cap_gear]%d\n", md1_ccb_cap_gear);
		return md1_ccb_cap_gear;
	} else {
#ifdef MTK_DYNAMIC_CCB_BUFFER_GEAR_ID
		md1_ccb_cap_gear = MTK_DYNAMIC_CCB_BUFFER_GEAR_ID;
#else
		md1_ccb_cap_gear = CCB_DATA_BUF_DEFAULT_GEAR;
#endif
		set_ccb_gear_val(md1_ccb_cap_gear);
		return md1_ccb_cap_gear;
	}
}

static void set_gear_id_list()
{
	int ret;

	ret = set_env("md1_ccb_gear_list",
		"1(2,20);2(2,10);3(0,0);11(2,2)");

	if (ret) {
		ALWAYS_LOG("set_gear_id_list error: %x\n", ret);
	}
}

/*------------------------------------------------------------------------------------------------*/
/* Suppor function for share memory calculate */
/*------------------------------------------------------------------------------------------------*/
static int cal_share_mem_layout(int load_flag)
{
	unsigned int md1_phy_cap_gear, md1_ccb_cap_gear;
	unsigned int md1_bank4_cache_offset;
	unsigned int md1_ccb_size = CCB_DATA_BUF_SIZE;
	unsigned char * ccb_data_buf = NULL;
	ap_md1_smem_size_at_lk_env = str2uint(get_env("apmd1_smem"));
	md1_md3_smem_size_at_lk_env = str2uint(get_env("md1md3_smem"));
	ap_md3_smem_size_at_lk_env = str2uint(get_env("apmd3_smem"));
	md1_phy_cap_gear = str2uint(get_env("md1_phy_cap_gear"));
	ALWAYS_LOG("env[apmd1_smem]%x.\n", ap_md1_smem_size_at_lk_env);
	ALWAYS_LOG("env[md1md3_smem]%x.\n", md1_md3_smem_size_at_lk_env);
	ALWAYS_LOG("env[apmd3_smem]%x.\n", ap_md3_smem_size_at_lk_env);
	ALWAYS_LOG("env[md1_phy_cap_gear]%x.\n", md1_phy_cap_gear);

	md1_ccb_cap_gear = get_ccb_gear_val();

	switch(md1_ccb_cap_gear)
	{
	case 0: /* none, using default*/
		md1_ccb_size = CCB_DATA_BUF_SIZE;
		break;
	case 1:
		md1_ccb_size = 22 * 1024 * 1024;
		break;
	case 2:
		md1_ccb_size = 12 * 1024 * 1024;
		break;
	case 3:
		md1_ccb_size = 0 * 1024 * 1024;
		break;
	case 11:
		md1_ccb_size = 4 * 1024 * 1024;
		break;
	default:
		md1_ccb_size = CCB_DATA_BUF_SIZE;
		break;
	}
	ALWAYS_LOG("allocate ccb data buffer0x%x\n", md1_ccb_size);

	set_gear_id_list();

	if (md1_ccb_size != 0)
		ccb_data_buf = ccci_request_mem(md1_ccb_size, 0x80000000LL, 0x2000000L);
	if (ccb_data_buf == NULL) {
		ccb_info.ccb_data_buffer_addr = 0;
		ccb_info.ccb_data_buffer_size = 0;
		ALWAYS_LOG("allocate ccb data buffer share memory fail\n");
	} else {
		ccb_info.ccb_data_buffer_addr = (unsigned long long)((unsigned long)ccb_data_buf);
		ccb_info.ccb_data_buffer_size = md1_ccb_size;

		if (insert_ccci_tag_inf("ccb_info", (char*)&ccb_info, sizeof(ccb_layout_t)) < 0)
			ALWAYS_LOG("insert ccb_info fail\n");

		ALWAYS_LOG("ccb_info.ccb_data_buffer_addr: %x\n", (unsigned int)ccb_info.ccb_data_buffer_addr);
		ALWAYS_LOG("ccb_info.ccb_data_buffer_size: %x\n", ccb_info.ccb_data_buffer_size);
		/* CCB must in last 32M */
		md1_bank4_cache_offset = 224 * 1024 * 1024;
		if (insert_ccci_tag_inf("md1_smem_cahce_offset", (char*)&md1_bank4_cache_offset,
		                        sizeof(md1_bank4_cache_offset)) < 0)
			ALWAYS_LOG("insert md1_smem_cahce_offset fail\n");
	}

	switch (md1_phy_cap_gear) {
		case 0:
			md1_phy_cap_size = CCCI_SMEM_SIZE_PHY_C_L0;
			break;
		case 1:
			md1_phy_cap_size = CCCI_SMEM_SIZE_PHY_C_L1;
			break;
		case 2:
			md1_phy_cap_size = CCCI_SMEM_SIZE_PHY_C_L2;
			break;
		case 3:
			md1_phy_cap_size = CCCI_SMEM_SIZE_PHY_C_L3;
			break;
		case 4:
			md1_phy_cap_size = CCCI_SMEM_SIZE_PHY_C_L4;
			break;
		default:
			md1_phy_cap_size = CCCI_SMEM_SIZE_PHY_C_L0;
			break;
	}
	ALWAYS_LOG("md1 phy capture size: %x\n", md1_phy_cap_size);
	if (insert_ccci_tag_inf("md1_phy_cap", (char*)&md1_phy_cap_size, sizeof(md1_phy_cap_size)) < 0)
		ALWAYS_LOG("insert md1_phy_cap fail\n");

	/* MD Share memory layout */
	/*    AP    <-->   MD1    */
	{
		smem_info.ap_md1_smem_offset = 0;
		if (ap_md1_smem_size_at_lk_env)
			smem_info.ap_md1_smem_size = ap_md1_smem_size_at_lk_env;
		else if (ap_md1_smem_size_at_img)
			smem_info.ap_md1_smem_size = ap_md1_smem_size_at_img;
		else
			smem_info.ap_md1_smem_size  = AP_MD1_SMEM_SIZE;

		smem_info.md1_md3_smem_offset = 0;
		smem_info.md1_md3_smem_size = 0;
		smem_info.ap_md3_smem_offset = 0;
		smem_info.ap_md3_smem_size = 0;
		/*
		   add dfd size to ap_md1_smem_size
		   kernel only ioremap ap_md1_smem_size
		   Otherwise,KE happen in clear_smem_region
		 */
		smem_info.ap_md1_smem_size += CCCI_SMEM_SIZE_DFD;
		/* add 2M for SIB header to avoid MD MPU violation if SIB exist */
		if(md1_phy_cap_size != CCCI_SMEM_SIZE_PHY_C_L0)
			smem_info.ap_md1_smem_size += 2 * 1024 * 1024;
		smem_info.total_smem_size = smem_info.ap_md1_smem_size;
	}

	/* insert share memory layout to lk info */
	if (insert_ccci_tag_inf("smem_layout", (char*)&smem_info, sizeof(smem_layout_t)) < 0)
		ALWAYS_LOG("insert smem_layout fail\n");

	ALWAYS_LOG("smem_info.base_addr: %x\n", (unsigned int)smem_info.base_addr);
	ALWAYS_LOG("smem_info.ap_md1_smem_offset: %x\n", smem_info.ap_md1_smem_offset);
	ALWAYS_LOG("smem_info.ap_md1_smem_size: %x\n", smem_info.ap_md1_smem_size);
	ALWAYS_LOG("smem_info.ap_md3_smem_offset: %x\n", smem_info.ap_md3_smem_offset);
	ALWAYS_LOG("smem_info.ap_md3_smem_size: %x\n", smem_info.ap_md3_smem_size);
	ALWAYS_LOG("smem_info.md1_md3_smem_offset: %x\n", smem_info.md1_md3_smem_offset);
	ALWAYS_LOG("smem_info.md1_md3_smem_size: %x\n", smem_info.md1_md3_smem_size);
	ALWAYS_LOG("smem_info.total_smem_size: %x\n", smem_info.total_smem_size);

	return (int)smem_info.total_smem_size + md1_phy_cap_size;
}

static void boot_to_dummy_ap_mode(int load_md_flag);
/*------------------------------------------------------------------------------------------------*/
/* Note: This function using global variable
** if set start=0x0, end=0x10000, the actural protected area will be 0x0-0x1FFFF,
** here we use 64KB align, MPU actually request 32KB align since MT6582, but this works...
** we assume emi_mpu_set_region_protection will round end address down to 64KB align.
*/
int plat_apply_platform_setting(int load_md_flag)
{
	int smem_final_size;

#ifdef DUMMY_AP_MODE
	/* This function will never return */
	ALWAYS_LOG("boot to dummy ap mode!!!\n");
	boot_to_dummy_ap_mode(load_md_flag);
	return 0;
#endif

	/* Check loading validation */
	if (((load_md_flag & (1<<MD_SYS1)) == 0) && (load_md_flag & (1<<MD_SYS3))) {
		ALWAYS_LOG("md3 depends on md1,but md1 not loaded\n");
		return -LD_ERR_PLAT_MD1_NOT_RDY;
	}
	if ((load_md_flag & ((1<<MD_SYS1)|(1<<MD_SYS3))) == 0) {
		ALWAYS_LOG("both md1 and md3 not enable\n");
		return 0;
	}

	smem_final_size = cal_share_mem_layout(load_md_flag);
	ALWAYS_LOG("ap md1 share mem MPU need configure\n");
	mpu_tbl[s_g_curr_mpu_num].region = MPU_REGION_ID_MD1_SMEM;
	get_mpu_region_default_access_att(mpu_tbl[s_g_curr_mpu_num].permission, MPU_REGION_ID_MD1_SMEM, 0);
	mpu_tbl[s_g_curr_mpu_num].start = (unsigned int)smem_info.base_addr + smem_info.ap_md1_smem_offset;
	mpu_tbl[s_g_curr_mpu_num].end = (unsigned int)smem_info.base_addr + smem_info.ap_md1_smem_offset
	                                + smem_final_size;
	mpu_tbl[s_g_curr_mpu_num].end = ((mpu_tbl[s_g_curr_mpu_num].end + 0xFFFF)&(~0xFFFF)) - 1;
	s_g_curr_mpu_num++;

	/* add for ccb data buffer mpu */
	mpu_tbl[s_g_curr_mpu_num].region = MPU_REGION_ID_MD1_CCB;
	get_mpu_region_default_access_att(mpu_tbl[s_g_curr_mpu_num].permission, MPU_REGION_ID_MD1_CCB, 0);
	mpu_tbl[s_g_curr_mpu_num].start = (unsigned int)ccb_info.ccb_data_buffer_addr;
	mpu_tbl[s_g_curr_mpu_num].end = (unsigned int)ccb_info.ccb_data_buffer_addr + ccb_info.ccb_data_buffer_size;
	mpu_tbl[s_g_curr_mpu_num].end = ((mpu_tbl[s_g_curr_mpu_num].end + 0xFFFF)&(~0xFFFF)) - 1;
	s_g_curr_mpu_num++;


	mpu_tbl[s_g_curr_mpu_num].region = -1; /* mark for end */
	/* Insert mpu tag info */
	if (insert_ccci_tag_inf("md_mpu_inf", (char*)mpu_tbl, sizeof(mpu_cfg_t)*s_g_curr_mpu_num) < 0)
		ALWAYS_LOG("insert md_mpu_inf fail\n");
	if (insert_ccci_tag_inf("md_mpu_num", (char*)&s_g_curr_mpu_num, sizeof(int)) < 0)
		ALWAYS_LOG("insert md_mpu_num fail\n");

	/* Apply all MPU setting */
	ccci_mem_access_cfg(mpu_tbl, 0);

	/* Apply share memory HW remap setting and lock it */
	if (load_md_flag & (1<<MD_SYS1)) {
		md_smem_rw_remapping(MD_SYS1, (unsigned int)(smem_info.base_addr + smem_info.ap_md1_smem_offset));
		/* remapping CCB to last 32M in bank4 */
		md_bank4_remapping_by_slot(MD_SYS1, ccb_info.ccb_data_buffer_addr, 7);
		md_emi_remapping_lock(MD_SYS1);
	}

	return smem_final_size;
}

/*------------------------------------------------------------------------------------------------*/
/* platform configure setting info.                                                               */
/*------------------------------------------------------------------------------------------------*/
long long plat_ccci_get_ld_md_plat_setting(char cfg_name[])
{
	if (strcmp(cfg_name, "share_memory_size") == 0) {

#ifdef DUMMY_AP_MODE
		return 0x200000;
#endif
		return (long long)(MAX_SMEM_SIZE);
	}

	if (strcmp(cfg_name, "share_mem_limit") == 0)
		return 0x80000000LL;

	if (strcmp(cfg_name, "ro_rw_mem_limit") == 0) {
#ifdef DUMMY_AP_MODE
		return 0xA0000000LL;
#endif
		return 0xA0000000LL;
	}

	if (strcmp(cfg_name, "ro_rw_mem_align") == 0)
		return 0x2000000LL;

	if (strcmp(cfg_name, "share_mem_align") == 0)
		return 0x2000000LL;

	if (strcmp(cfg_name, "ld_version") == 0) {

#ifdef DUMMY_AP_MODE
		return 0x20001;
#endif
		return 0x20000;/* xxxx_yyyy, xxxx: main id, yyyy sub id */
	}

	if (strcmp(cfg_name, "rat_plat_ver") == 0)
		return RAT_VER_93;

	return -1LL;
}

#ifdef DUMMY_AP_MODE
#include <platform/mt_irq.h>
extern void dummy_ap_boot_up_md(int md_en_flag);
extern void load_modem_image(void);
extern int dummy_ap_irq_helper(unsigned int);

/* Remember add this function to file platform.c(platform code) */
void dummy_ap_entry(void)
{
	load_modem_image();
}

/* Remember add this function to file interrupts.c(platform code) */
void dummy_ap_irq_handler(unsigned int irq)
{
	if (dummy_ap_irq_helper(irq)) {
		mt_irq_ack(irq);
		mt_irq_unmask(irq);
	}
}

void boot_to_dummy_ap_mode(int load_md_flag)
{
	md_smem_rw_remapping(MD_SYS1, smem_info.base_addr);
	/* Before boot dummy AP, clear share memory */
	memset((void*)((unsigned long)smem_info.base_addr), 0, 0x200000);

	dummy_ap_boot_up_md(load_md_flag);
}

#endif

