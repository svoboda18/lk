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

#define LOG_TAG "ddp_path"

#include "platform/mt_irq.h"
#include "platform/mt_irq.h"

#include "platform/disp_drv_platform.h"
#include "platform/ddp_reg.h"
#include "platform/ddp_path.h"
#include "platform/ddp_info.h"
#include "platform/ddp_log.h"

#define BIT_NUM (8)


typedef struct module_map_s {
	DISP_MODULE_ENUM module;
	int bit;
	int mod_num;
} module_map_t;

typedef struct {
	int m;
	int v;
} m_to_b;

typedef struct mout_s {
	int id;
	m_to_b out_id_bit_map[BIT_NUM];

	volatile unsigned long *reg;
	unsigned int reg_val;
} mout_t;

typedef struct selection_s {
	int id;
	int id_bit_map[BIT_NUM];

	volatile unsigned long *reg;
	unsigned int reg_val;
} sel_t;

#define DDP_ENING_NUM    (20)

#define DDP_MOUT_NUM     10
#define DDP_SEL_OUT_NUM  10
#define DDP_SEL_IN_NUM   20
#define DDP_MUTEX_MAX    5

unsigned int module_list_scenario[DDP_SCENARIO_MAX][DDP_ENING_NUM] = {
	/*PRIMARY_DISP */
	{
		DISP_MODULE_OVL0, DISP_MODULE_OVL0_2L, DISP_MODULE_RDMA0,
		DISP_MODULE_COLOR0, DISP_MODULE_CCORR0, DISP_MODULE_AAL0, DISP_MODULE_GAMMA0, DISP_MODULE_DITHER0,
		DISP_MODULE_PWM0, DISP_MODULE_DSI0,
		-1,
	},

	/*PRIMARY_RDMA0_COLOR0_DISP */
	{
		DISP_MODULE_RDMA0, DISP_MODULE_COLOR0, DISP_MODULE_CCORR0, DISP_MODULE_AAL0,
		DISP_MODULE_GAMMA0, DISP_MODULE_DITHER0, DISP_MODULE_PWM0, DISP_MODULE_DSI0,
		-1,
	},

	/*PRIMARY_RDMA0_DISP */
	{
		DISP_MODULE_RDMA0, DISP_MODULE_PWM0, DISP_MODULE_DSI0,
		-1,
	},

	/* DDP_SCENARIO_PRIMARY_OVL_MEMOUT */
	{
		DISP_MODULE_OVL0, DISP_MODULE_OVL0_2L, DISP_MODULE_WDMA_VIRTUAL0,
		DISP_MODULE_WDMA_VIRTUAL1, DISP_MODULE_WDMA0,
		-1,
	},

	/* DDP_SCENARIO_PRIMARY_ALL */
	{
		DISP_MODULE_OVL0, DISP_MODULE_OVL0_2L, DISP_MODULE_WDMA_VIRTUAL0,
		DISP_MODULE_WDMA_VIRTUAL1, DISP_MODULE_WDMA0, DISP_MODULE_RDMA0,
		DISP_MODULE_COLOR0, DISP_MODULE_CCORR0, DISP_MODULE_AAL0, DISP_MODULE_GAMMA0,
		DISP_MODULE_DITHER0, DISP_MODULE_DSI0,
		-1,
	},

	/* DDP_SCENARIO_SUB_DISP */
	{
		DISP_MODULE_OVL1_2L, DISP_MODULE_RDMA1, DISP_MODULE_DPI,
		-1,
	},

	/* DDP_SCENARIO_SUB_RDMA1_DISP */
	{
		DISP_MODULE_RDMA1, DISP_MODULE_DPI,
		-1,
	},
};

/* 1st para is mout's input, 2nd para is mout's output */
static mout_t mout_map[DDP_MOUT_NUM] = {
	/* OVL_MOUT */
	{DISP_MODULE_OVL0,
		{{DISP_MODULE_RDMA0, 1 << 0}, {DISP_MODULE_WDMA_VIRTUAL0, 1 << 2},
		{DISP_MODULE_OVL0_2L, 1 << 4}, {-1, 0} },
		0, 0},/* bit1 mdp_wrot, bit3 mdp_rsz */

	/* OVL0_2L_MOUT */
	{DISP_MODULE_OVL0_2L,
		{{DISP_MODULE_RDMA0, 1 << 0}, {DISP_MODULE_WDMA_VIRTUAL0, 1 << 2},
		{DISP_MODULE_OVL1_2L, 1 << 4}, {-1, 0} },
		0, 0},

	/* OVL1_2L_MOUT */
	{DISP_MODULE_OVL1_2L,
		{{DISP_MODULE_RDMA0, 1 << 0}, {DISP_MODULE_WDMA_VIRTUAL0, 1 << 2},
		{DISP_MODULE_RDMA1, 1 << 4}, {-1, 0} },
		0, 0},

	/* DITHER0_MOUT */
	{DISP_MODULE_DITHER0,
		{{DISP_MODULE_DSI0, 1 << 0}, {DISP_MODULE_WDMA_VIRTUAL0, 1 << 3},
			{-1, 0} },
		0, 0}
};

static sel_t sel_out_map[DDP_SEL_OUT_NUM] = {
	/* RDMA0_SOUT */
	{DISP_MODULE_RDMA0,
		{DISP_MODULE_DSI0, DISP_MODULE_COLOR0,
		DISP_MODULE_CCORR0}, 0, 0},

	/* RDMA1_SOUT */
	{DISP_MODULE_RDMA1,
		{DISP_MODULE_DPI, DISP_MODULE_DSI0}, 0, 0},
};

/* 1st para is sout's output, 2nd para is sout's input */
static sel_t sel_in_map[DDP_SEL_IN_NUM] = {
	/* COLOR_SEL */
	{DISP_MODULE_CCORR0, {DISP_MODULE_COLOR0, DISP_MODULE_RDMA0, -1}, 0, 0},

	/* RDMA_SEL */
	{DISP_MODULE_RDMA0, {DISP_MODULE_OVL0, DISP_MODULE_OVL0_2L,
		DISP_MODULE_OVL1_2L, -1}, 0, 0},

	/* WDMA_SEL */
	{DISP_MODULE_WDMA_VIRTUAL1, {DISP_MODULE_WDMA_VIRTUAL0,
								DISP_MODULE_DITHER0, -1}, 0, 0},

	/* OVL_TO_WDMA_SEL */
	{DISP_MODULE_WDMA_VIRTUAL0, {DISP_MODULE_OVL0, DISP_MODULE_OVL0_2L,
		DISP_MODULE_OVL1_2L, -1}, 0, 0},

	/* WDMA0_SEL */
	{DISP_MODULE_WDMA0, {DISP_MODULE_NUM, DISP_MODULE_NUM,
						 DISP_MODULE_NUM, DISP_MODULE_WDMA_VIRTUAL1, -1}, 0, 0},
	/* DSI_SEL */
	{DISP_MODULE_DSI0, {DISP_MODULE_DITHER0, DISP_MODULE_RDMA0,
		DISP_MODULE_NUM, DISP_MODULE_RDMA1, -1}, 0, 0},

	/* DPI0_SEL */
	{DISP_MODULE_DPI, {DISP_MODULE_NUM, DISP_MODULE_RDMA0,
		DISP_MODULE_RDMA1, DISP_MODULE_DITHER0, -1}, 0, 0},
};


int ddp_path_init(void)
{
	/* mout */
	mout_map[0].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_OVL0_MOUT_EN;
	mout_map[1].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_OVL0_2L_MOUT_EN;
	mout_map[2].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_OVL1_2L_MOUT_EN;
	mout_map[3].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_DITHER_MOUT_EN;

	/* sel_out */
	sel_out_map[0].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_RDMA0_SOUT_SEL_IN;
	sel_out_map[1].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_RDMA1_SOUT_SEL_IN;

	/* sel_in */
	sel_in_map[0].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_COLOR_OUT_SEL_IN;
	sel_in_map[1].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_PATH0_SEL_IN;
	sel_in_map[2].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_WDMA0_PRE_SEL_IN;
	sel_in_map[3].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_OVLTOWDMA_SEL_IN;
	sel_in_map[4].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_WDMA0_SEL_IN;
	sel_in_map[5].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_DSI0_SEL_IN;
	sel_in_map[6].reg = (volatile unsigned long *)DISP_REG_CONFIG_DISP_DPI0_SEL_IN;

	return 0;
}

static module_map_t module_mutex_map[DISP_MODULE_NUM] = {
	{DISP_MODULE_OVL0, 9, 0},
	{DISP_MODULE_OVL1, -1, 0},
	{DISP_MODULE_OVL0_2L, 10, 0},
	{DISP_MODULE_OVL1_2L, 11, 0},
	{DISP_MODULE_OVL0_VIRTUAL, -1, 0},
	{DISP_MODULE_OVL0_2L_VIRTUAL, -1, 0},
	{DISP_MODULE_OVL1_2L_VIRTUAL, -1, 0},

	{DISP_MODULE_RDMA0, 0, 0},
	{DISP_MODULE_RDMA1, 1, 0},
	{DISP_MODULE_RDMA2, -1, 0},

	{DISP_MODULE_WDMA0, 12, 0},
	{DISP_MODULE_WDMA1, -1, 0},
	{DISP_MODULE_WDMA_VIRTUAL0, -1, 0},
	{DISP_MODULE_WDMA_VIRTUAL1, -1, 0},

	{DISP_MODULE_COLOR0, 13, 0},
	{DISP_MODULE_COLOR1, -1, 0},
	{DISP_MODULE_CCORR0, 14, 0},
	{DISP_MODULE_CCORR1, -1, 0},
	{DISP_MODULE_AAL0, 15, 0},
	{DISP_MODULE_AAL1, -1, 0},
	{DISP_MODULE_GAMMA0, 16, 0},
	{DISP_MODULE_GAMMA1, -1, 0},
	{DISP_MODULE_OD, -1, 0},
	{DISP_MODULE_DITHER0, 17, 0},
	{DISP_MODULE_DITHER1, -1, 0},

	{DISP_MODULE_PATH0, -1, 0},
	{DISP_MODULE_PATH1, -1, 0},

	{DISP_MODULE_UFOE, -1, 0},
	{DISP_MODULE_DSC, -1, 0},
	{DISP_MODULE_DSC_2ND, -1, 0},
	{DISP_MODULE_SPLIT0, -1, 0},

	{DISP_MODULE_DPI, 20, 0},

	{DISP_MODULE_DSI0, 19, 0},
	{DISP_MODULE_DSI1, -1, 0},
	{DISP_MODULE_DSIDUAL, -1, 0},

	{DISP_MODULE_PWM0, 18, 0},
	{DISP_MODULE_PWM1, -1, 0},

	{DISP_MODULE_CONFIG, -1, 0},
	{DISP_MODULE_MUTEX, -1, 0},
	{DISP_MODULE_SMI_COMMON, -1, 0},
	{DISP_MODULE_SMI_LARB0, -1, 0},
	{DISP_MODULE_SMI_LARB1, -1, 0},
	{DISP_MODULE_MIPI0, -1, 0},
	{DISP_MODULE_MIPI1, -1, 0},

	{DISP_MODULE_RSZ0, -1, 0},
	{DISP_MODULE_RSZ1, -1, 0},

	{DISP_MODULE_UNKNOWN, -1, 0},
};


/* module can be connect if 1 */
static module_map_t module_can_connect[DISP_MODULE_NUM] = {
	{DISP_MODULE_OVL0, 1, 0},
	{DISP_MODULE_OVL1, 0, 0},
	{DISP_MODULE_OVL0_2L, 1, 0},
	{DISP_MODULE_OVL1_2L, 1, 0},
	{DISP_MODULE_OVL0_VIRTUAL, 0, 0},
	{DISP_MODULE_OVL0_2L_VIRTUAL, 0, 0},
	{DISP_MODULE_OVL1_2L_VIRTUAL, 0, 0},

	{DISP_MODULE_RDMA0, 1, 0},
	{DISP_MODULE_RDMA1, 1, 0},
	{DISP_MODULE_RDMA2, 0, 0},

	{DISP_MODULE_WDMA0, 1, 0},
	{DISP_MODULE_WDMA1, 0, 0},
	{DISP_MODULE_WDMA_VIRTUAL0, 0, 0},
	{DISP_MODULE_WDMA_VIRTUAL1, 0, 0},

	{DISP_MODULE_COLOR0, 1, 0},
	{DISP_MODULE_COLOR1, 0, 0},
	{DISP_MODULE_CCORR0, 1, 0},
	{DISP_MODULE_CCORR1, 0, 0},
	{DISP_MODULE_AAL0, 1, 0},
	{DISP_MODULE_AAL1, 0, 0},
	{DISP_MODULE_GAMMA0, 1, 0},
	{DISP_MODULE_GAMMA1, 0, 0},
	{DISP_MODULE_OD, 0, 0},
	{DISP_MODULE_DITHER0, 1, 0},
	{DISP_MODULE_DITHER1, 0, 0},

	{DISP_MODULE_PATH0, 0, 0},
	{DISP_MODULE_PATH1, 0, 0},

	{DISP_MODULE_UFOE, 0, 0},
	{DISP_MODULE_DSC, 0, 0},
	{DISP_MODULE_DSC_2ND, 0, 0},
	{DISP_MODULE_SPLIT0, 0, 0},

	{DISP_MODULE_DPI, 1, 0},

	{DISP_MODULE_DSI0, 1, 0},
	{DISP_MODULE_DSI1, 0, 0},
	{DISP_MODULE_DSIDUAL, 0, 0},
	{DISP_MODULE_PWM0, 0, 0},
	{DISP_MODULE_PWM1, 0, 0},

	{DISP_MODULE_CONFIG, 0, 0},
	{DISP_MODULE_MUTEX, 0, 0},
	{DISP_MODULE_SMI_COMMON, 0, 0},
	{DISP_MODULE_SMI_LARB0, 0, 0},
	{DISP_MODULE_SMI_LARB1, 0, 0},

	{DISP_MODULE_MIPI0, 0, 0},
	{DISP_MODULE_MIPI1, 0, 0},
	{DISP_MODULE_RSZ0, 0, 0},
	{DISP_MODULE_RSZ1, 0, 0},

	{DISP_MODULE_UNKNOWN, 0, 0},

};



char *ddp_get_scenario_name(DDP_SCENARIO_ENUM scenario)
{
	switch (scenario) {
	case DDP_SCENARIO_PRIMARY_DISP:
		return "primary_disp";
	case DDP_SCENARIO_PRIMARY_RDMA0_COLOR0_DISP:
		return "primary_rdma0_color0_disp";
	case DDP_SCENARIO_PRIMARY_RDMA0_DISP:
		return "primary_rdma0_disp";
	case DDP_SCENARIO_PRIMARY_OVL_MEMOUT:
		return "primary_ovl_memout";
	case DDP_SCENARIO_SUB_DISP:
		return "sub_disp";
	case DDP_SCENARIO_SUB_RDMA1_DISP:
		return "sub_rdma1_disp";
	case DDP_SCENARIO_SUB_OVL_MEMOUT:
		return "sub_ovl_memout";
	case DDP_SCENARIO_PRIMARY_ALL:
		return "primary_all";
	case DDP_SCENARIO_SUB_ALL:
		return "sub_all";
	default:
		DDPMSG("invalid scenario id=%d\n", scenario);
		return "unknown";
	}
}

int ddp_is_scenario_on_primary(DDP_SCENARIO_ENUM scenario)
{
	int on_primary = 0;
	switch (scenario) {
	case DDP_SCENARIO_PRIMARY_DISP:
	case DDP_SCENARIO_PRIMARY_RDMA0_COLOR0_DISP:
	case DDP_SCENARIO_PRIMARY_RDMA0_DISP:
	case DDP_SCENARIO_PRIMARY_OVL_MEMOUT:
	case DDP_SCENARIO_PRIMARY_ALL:
		on_primary = 1;
		break;
	case DDP_SCENARIO_SUB_DISP:
	case DDP_SCENARIO_SUB_RDMA1_DISP:
	case DDP_SCENARIO_SUB_OVL_MEMOUT:
	case DDP_SCENARIO_SUB_ALL:
		on_primary = 0;
		break;
	default:
		DDPMSG("invalid scenario id=%d\n", scenario);
	}

	return on_primary;

}

char *ddp_get_mutex_sof_name(unsigned int regval)
{
	if (regval == SOF_VAL_MUTEX0_SOF_SINGLE_MODE)
		return "single";
	else if (regval == SOF_VAL_MUTEX0_SOF_FROM_DSI0)
		return "dsi0";
	else if (regval == SOF_VAL_MUTEX0_SOF_FROM_DPI)
		return "dpi";

	DDPDUMP("%s, unknown reg=%d\n", __func__, regval);
	return "unknown";
}

char *ddp_get_mode_name(DDP_MODE ddp_mode)
{
	switch (ddp_mode) {
	case DDP_VIDEO_MODE:
		return "vido_mode";
	case DDP_CMD_MODE:
		return "cmd_mode";
	default:
		DDPMSG("invalid ddp mode =%d\n", ddp_mode);
		return "unknown";
	}
}

static int ddp_get_module_num_l(int *module_list)
{
	unsigned int num = 0;
	while (*(module_list + num) != -1) {
		num++;

		if (num == DDP_ENING_NUM)
			break;
	}
	return num;
}

/* config mout/msel to creat a compelte path */
static void ddp_connect_path_l(int *module_list, void *handle)
{
	unsigned int i, j, k;
	int step = 0;
	unsigned int mout = 0;
	unsigned int reg_mout = 0;
	unsigned int mout_idx = 0;
	unsigned int module_num = ddp_get_module_num_l(module_list);
	DDPDBG("connect_path: %s to %s\n", ddp_get_module_name(module_list[0]),
	       ddp_get_module_name(module_list[module_num - 1]));
	/* connect mout */
	for (i = 0; i < module_num - 1; i++) {
		for (j = 0; j < DDP_MOUT_NUM; j++) {
			if (module_list[i] == mout_map[j].id) {
				/* find next module which can be connected */
				step = i + 1;
				while (module_can_connect[module_list[step]].bit == 0
				       && step < module_num) {
					step++;
				}
				ASSERT(step < module_num);
				mout = mout_map[j].reg_val;
				for (k = 0; k < 5; k++) {
					if (mout_map[j].out_id_bit_map[k].m == -1)
						break;
					if (mout_map[j].out_id_bit_map[k].m == module_list[step]) {
						mout |= mout_map[j].out_id_bit_map[k].v;
						reg_mout |= mout;
						mout_idx = j;
						DDPDBG("connect mout %s to %s  bits 0x%x\n",
						       ddp_get_module_name(module_list[i]),
						       ddp_get_module_name(module_list[step]),
						       reg_mout);
						break;
					}
				}
				mout_map[j].reg_val = mout;
				mout = 0;
			}
		}
		if (reg_mout) {
			DISP_REG_SET(handle, mout_map[mout_idx].reg, reg_mout);
			reg_mout = 0;
			mout_idx = 0;
		}

	}
	/* connect out select */
	for (i = 0; i < module_num - 1; i++) {
		for (j = 0; j < DDP_SEL_OUT_NUM; j++) {
			if (module_list[i] == sel_out_map[j].id) {
				step = i + 1;
				/* find next module which can be connected */
				while (module_can_connect[module_list[step]].bit == 0
				       && step < module_num) {
					step++;
				}
				ASSERT(step < module_num);
				for (k = 0; k < 4; k++) {
					if (sel_out_map[j].id_bit_map[k] == -1)
						break;
					if (sel_out_map[j].id_bit_map[k] == module_list[step]) {
						DDPDBG("connect out_s %s to %s, value=%d\n",
						       ddp_get_module_name(module_list[i]),
						       ddp_get_module_name(module_list[step]), k);
						DISP_REG_SET(handle, sel_out_map[j].reg,
							     (uint16_t) k);
						break;
					}
				}
			}
		}
	}
	/* connect input select */
	for (i = 1; i < module_num; i++) {
		for (j = 0; j < DDP_SEL_IN_NUM; j++) {
			if (module_list[i] == sel_in_map[j].id) {
				int found = 0;
				step = i - 1;
				/* find next module which can be connected */
				while (module_can_connect[module_list[step]].bit == 0 && step > 0)
					step--;

				ASSERT(step >= 0);
				for (k = 0; k < 4; k++) {
					if (sel_in_map[j].id_bit_map[k] == -1)
						break;
					if (sel_in_map[j].id_bit_map[k] == module_list[step]) {
						DDPDBG("connect in_s %s to %s, value=%d\n",
						       ddp_get_module_name(module_list[step]),
						       ddp_get_module_name(module_list[i]), k);
						DISP_REG_SET(handle, sel_in_map[j].reg,
							     (uint16_t) k);
						found = 1;
						break;
					}
				}
				if (!found)
					DDPERR("%s error: %s sel_in not set\n", __func__,
						ddp_get_module_name(module_list[i]));
			}
		}
	}
}

static void ddp_check_path_l(int *module_list)
{
	unsigned int i, j, k;
	int step = 0;
	int valid = 0;
	unsigned int mout;
	unsigned int path_error = 0;
	unsigned int module_num = ddp_get_module_num_l(module_list);
	DDPDUMP("check_path: %s to %s\n", ddp_get_module_name(module_list[0])
		, ddp_get_module_name(module_list[module_num - 1]));
	/* check mout */
	for (i = 0; i < module_num - 1; i++) {
		for (j = 0; j < DDP_MOUT_NUM; j++) {
			if (module_list[i] == mout_map[j].id) {
				mout = 0;
				/* find next module which can be connected */
				step = i + 1;
				while (module_can_connect[module_list[step]].bit == 0
				       && step < module_num) {
					step++;
				}
				ASSERT(step < module_num);
				for (k = 0; k < 5; k++) {
					if (mout_map[j].out_id_bit_map[k].m == -1)
						break;
					if (mout_map[j].out_id_bit_map[k].m == module_list[step]) {
						mout |= mout_map[j].out_id_bit_map[k].v;
						valid = 1;
						break;
					}
				}
				if (valid) {
					valid = 0;
					if ((DISP_REG_GET(mout_map[j].reg) & mout) == 0) {
						path_error += 1;
						DDPDUMP("error:%s mout, expect=0x%x, real=0x%x\n",
							ddp_get_module_name(module_list[i]),
							mout, DISP_REG_GET(mout_map[j].reg));
					} else if (DISP_REG_GET(mout_map[j].reg) != mout) {
						DDPDUMP
						    ("warning: %s mout expect=0x%x, real=0x%x\n",
						     ddp_get_module_name(module_list[i]), mout,
						     DISP_REG_GET(mout_map[j].reg));
					}
				}
				break;
			}
		}
	}
	/* check out select */
	for (i = 0; i < module_num - 1; i++) {
		for (j = 0; j < DDP_SEL_OUT_NUM; j++) {
			if (module_list[i] != sel_out_map[j].id)
				continue;
			/* find next module which can be connected */
			step = i + 1;
			while (module_can_connect[module_list[step]].bit == 0
			       && step < module_num) {
				step++;
			}
			ASSERT(step < module_num);
			for (k = 0; k < 4; k++) {
				if (sel_out_map[j].id_bit_map[k] == -1)
					break;
				if (sel_out_map[j].id_bit_map[k] == module_list[step]) {
					if (DISP_REG_GET(sel_out_map[j].reg) != k) {
						path_error += 1;
						DDPDUMP
						    ("error:out_s %s not connect to %s, expect=0x%x, real=0x%x\n",
						     ddp_get_module_name(module_list[i]),
						     ddp_get_module_name(module_list[step]),
						     k, DISP_REG_GET(sel_out_map[j].reg));
					}
					break;
				}
			}
		}
	}
	/* check input select */
	for (i = 1; i < module_num; i++) {
		for (j = 0; j < DDP_SEL_IN_NUM; j++) {
			if (module_list[i] != sel_in_map[j].id)
				continue;
			/* find next module which can be connected */
			step = i - 1;
			while (module_can_connect[module_list[step]].bit == 0 && step > 0)
				step--;
			ASSERT(step >= 0);
			for (k = 0; k < 4; k++) {
				if (sel_in_map[j].id_bit_map[k] == -1)
					break;
				if (sel_in_map[j].id_bit_map[k] == module_list[step]) {
					if (DISP_REG_GET(sel_in_map[j].reg) != k) {
						path_error += 1;
						DDPDUMP("error:in_s %s not conn to %s,expect0x%x,real0x%x\n",
						     ddp_get_module_name(module_list[step]),
						     ddp_get_module_name(module_list[i]), k,
						     DISP_REG_GET(sel_in_map[j].reg));
					}
					break;
				}
			}
		}
	}
	if (path_error == 0) {
		DDPDUMP("path: %s to %s is connected\n", ddp_get_module_name(module_list[0]),
			ddp_get_module_name(module_list[module_num - 1]));
	} else {
		DDPDUMP("path: %s to %s not connected!!!\n", ddp_get_module_name(module_list[0]),
			ddp_get_module_name(module_list[module_num - 1]));
	}
}

static void ddp_disconnect_path_l(int *module_list, void *handle)
{
	unsigned int i, j, k;
	int step = 0;
	unsigned int mout = 0;
	unsigned int reg_mout = 0;
	unsigned int mout_idx = 0;
	unsigned int module_num = ddp_get_module_num_l(module_list);

	DDPDBG("disconnect_path: %s to %s\n", ddp_get_module_name(module_list[0]),
	       ddp_get_module_name(module_list[module_num - 1]));
	for (i = 0; i < module_num - 1; i++) {
		for (j = 0; j < DDP_MOUT_NUM; j++) {
			if (module_list[i] == mout_map[j].id) {
				/* find next module which can be connected */
				step = i + 1;
				while (module_can_connect[module_list[step]].bit == 0
				       && step < module_num) {
					step++;
				}
				ASSERT(step < module_num);
				for (k = 0; k < 5; k++) {
					if (mout_map[j].out_id_bit_map[k].m == -1)
						break;
					if (mout_map[j].out_id_bit_map[k].m == module_list[step]) {
						mout |= mout_map[j].out_id_bit_map[k].v;
						reg_mout |= mout;
						mout_idx = j;
						DDPDBG("disconnect mout %s to %s\n",
						       ddp_get_module_name(module_list[i]),
						       ddp_get_module_name(module_list[step]));
						break;
					}
				}
				/* update mout_value */
				mout_map[j].reg_val &= ~mout;
				mout = 0;
			}
		}
		if (reg_mout) {
			DISP_REG_SET(handle, mout_map[mout_idx].reg, mout_map[mout_idx].reg_val);
			reg_mout = 0;
			mout_idx = 0;
		}
	}
}

static int ddp_get_mutex_src(DISP_MODULE_ENUM dest_module, DDP_MODE ddp_mode,
			     unsigned int *SOF_src, unsigned int *EOF_src)
{
	unsigned int src_from_dst_module = 0;

	if (dest_module == DISP_MODULE_WDMA0 || dest_module == DISP_MODULE_WDMA1) {

		if (ddp_mode == DDP_VIDEO_MODE)
			DISP_LOG_W("%s: dst_mode=%s, but is video mode !!\n", __func__,
				   ddp_get_module_name(dest_module));

		*SOF_src = *EOF_src = SOF_VAL_MUTEX0_SOF_SINGLE_MODE;
		return 0;
	}

	if (dest_module == DISP_MODULE_DSI0 || dest_module == DISP_MODULE_DSIDUAL) {
		src_from_dst_module = SOF_VAL_MUTEX0_SOF_FROM_DSI0;
	} else if (dest_module == DISP_MODULE_DPI) {
		src_from_dst_module = SOF_VAL_MUTEX0_SOF_FROM_DPI;
	} else {
		DDPERR("get mutex sof, invalid param dst module = %s(%d), dsi mode %s\n",
		       ddp_get_module_name(dest_module), dest_module, ddp_get_mode_name(ddp_mode));
		ASSERT(0);
	}

	if (ddp_mode == DDP_CMD_MODE) {
		*SOF_src = SOF_VAL_MUTEX0_SOF_SINGLE_MODE;
		if (0/*disp_helper_get_option(DISP_OPT_MUTEX_EOF_EN_FOR_CMD_MODE)*/)
			*EOF_src = src_from_dst_module;
		else
			*EOF_src = SOF_VAL_MUTEX0_EOF_DISABLE;

	} else {
		*SOF_src = *EOF_src = src_from_dst_module;
	}

	return 0;
}

/* id: mutex ID, 0~5 */
static int ddp_mutex_set_l(int mutex_id, int *module_list, DDP_MODE ddp_mode, void *handle)
{
	int i = 0;
	unsigned int value0 = 0;
	unsigned int value1 = 0;
	unsigned int sof_val;
	unsigned int sof_src, eof_src;
	int module_num = ddp_get_module_num_l(module_list);

	ddp_get_mutex_src(module_list[module_num - 1], ddp_mode, &sof_src, &eof_src);
	if (mutex_id < DISP_MUTEX_DDP_FIRST || mutex_id > DISP_MUTEX_DDP_LAST) {
		DDPERR("exceed mutex max (0 ~ %d)\n", DISP_MUTEX_DDP_LAST);
		return -1;
	}
	for (i = 0; i < module_num; i++) {
		if (module_mutex_map[module_list[i]].bit != -1) {
			DDPDBG("module %s added to mutex %d\n", ddp_get_module_name(module_list[i]),
			       mutex_id);
			if (module_mutex_map[module_list[i]].mod_num == 0) {
				value0 |= (1 << module_mutex_map[module_list[i]].bit);
			} else if (module_mutex_map[module_list[i]].mod_num == 1) {
				/* DISP_MODULE_DSIDUAL is special */
				if (DISP_MODULE_DSIDUAL == module_mutex_map[module_list[i]].module) {
					value1 |= (1 << module_mutex_map[DISP_MODULE_DSI0].bit); /* DISP MODULE enum must start from 0 */
					value1 |= (1 << module_mutex_map[DISP_MODULE_DSI1].bit);
				} else {
					value1 |= (1 << module_mutex_map[module_list[i]].bit);
				}
			}
		} else {
			DDPDBG("module %s not added to mutex %d\n",
			       ddp_get_module_name(module_list[i]), mutex_id);
		}
	}
	DISP_REG_SET(handle, DISP_REG_CONFIG_MUTEX_MOD0(mutex_id), value0);

	sof_val = REG_FLD_VAL(SOF_FLD_MUTEX0_SOF, sof_src);
	sof_val |= REG_FLD_VAL(SOF_FLD_MUTEX0_EOF, eof_src);
	DISP_REG_SET(handle, DISP_REG_CONFIG_MUTEX_SOF(mutex_id), sof_val);

	DDPDBG("mutex %d value=0x%x, sof=%s, eof=%s\n", mutex_id,
	       value0, ddp_get_mutex_sof_name(sof_src), ddp_get_mutex_sof_name(eof_src));
	return 0;
}

static void ddp_check_mutex_l(int mutex_id, int *module_list, DDP_MODE ddp_mode)
{
	int i = 0;
	uint32_t real_value0 = 0;
	uint32_t real_value1 = 0;
	uint32_t expect_value0 = 0;
	uint32_t expect_value1 = 0;
	unsigned int real_sof, real_eof, val;
	unsigned int expect_sof, expect_eof;
	int module_num = ddp_get_module_num_l(module_list);
	if (mutex_id < DISP_MUTEX_DDP_FIRST || mutex_id > DISP_MUTEX_DDP_LAST) {
		DDPDUMP("error:check mutex fail:exceed mutex max (0 ~ %d)\n", DISP_MUTEX_DDP_LAST);
		return;
	}
	real_value0 = DISP_REG_GET(DISP_REG_CONFIG_MUTEX_MOD0(mutex_id));
	for (i = 0; i < module_num; i++) {
		if (module_mutex_map[module_list[i]].bit != -1) {
			if (module_mutex_map[module_list[i]].mod_num == 0) {
				expect_value0 |= (1 << module_mutex_map[module_list[i]].bit);
			} else if (module_mutex_map[module_list[i]].mod_num == 1) {
				if (DISP_MODULE_DSIDUAL == module_mutex_map[module_list[i]].module) {
					expect_value1 |= (1 << module_mutex_map[DISP_MODULE_DSI0].bit); /* DISP MODULE enum must start from 0 */
					expect_value1 |= (1 << module_mutex_map[DISP_MODULE_DSI1].bit);
				} else {
					expect_value1 |= (1 << module_mutex_map[module_list[i]].bit);
				}
			}
		}
	}
	if (expect_value0 != real_value0)
		DDPDUMP("error:mutex %d error: expect0 0x%x, real0 0x%x\n", mutex_id, expect_value0,
			real_value0);

	if (expect_value1 != real_value1)
		DDPDUMP("error:mutex %d error: expect1 0x%x, real1 0x%x\n", mutex_id, expect_value1,
			real_value1);

	val = DISP_REG_GET(DISP_REG_CONFIG_MUTEX_SOF(mutex_id));
	real_sof = REG_FLD_VAL_GET(SOF_FLD_MUTEX0_SOF, val);
	real_eof = REG_FLD_VAL_GET(SOF_FLD_MUTEX0_EOF, val);
	ddp_get_mutex_src(module_list[module_num - 1], ddp_mode, &expect_sof, &expect_eof);
	if (expect_sof != real_sof)
		DDPDUMP("error:mutex %d sof error: expect %s, real %s\n", mutex_id,
			ddp_get_mutex_sof_name(expect_sof), ddp_get_mutex_sof_name(real_sof));
	if (expect_eof != real_eof)
		DDPDUMP("error:mutex %d eof error: expect %s, real %s\n", mutex_id,
			ddp_get_mutex_sof_name(expect_eof), ddp_get_mutex_sof_name(real_eof));

}

static int ddp_mutex_enable_l(int mutex_idx, void *handle)
{
	DDPDBG("mutex %d enable\n", mutex_idx);
	DISP_REG_SET(handle, DISP_REG_CONFIG_MUTEX_CFG, 0);
	DISP_REG_SET(handle, DISP_REG_CONFIG_MUTEX_EN(mutex_idx), 1);

	return 0;
}

int ddp_get_module_num(DDP_SCENARIO_ENUM scenario)
{
	return ddp_get_module_num_l(module_list_scenario[scenario]);
}

static void ddp_print_scenario(DDP_SCENARIO_ENUM scenario)
{
	int i =0;
	char path[512]= {'\0'};
	int num = ddp_get_module_num(scenario);
	for (i = 0; i < num; i++)
		strncat(path, ddp_get_module_name(module_list_scenario[scenario][i]), sizeof(path));
	DDPMSG("scenario %s have modules: %s\n",ddp_get_scenario_name(scenario),path);
}

static int ddp_find_module_index(DDP_SCENARIO_ENUM ddp_scenario, DISP_MODULE_ENUM module)
{
	int i = 0;

	for (i = 0; i < DDP_ENING_NUM; i++) {
		if (module_list_scenario[ddp_scenario][i] == module)
			return i;

	}
	DDPDBG("find module: can not find module %s on scenario %s\n", ddp_get_module_name(module),
	       ddp_get_scenario_name(ddp_scenario));
	return -1;
}

/* set display interface when kernel init */
int ddp_set_dst_module(DDP_SCENARIO_ENUM scenario, DISP_MODULE_ENUM dst_module)
{
	int i = 0;

	DDPMSG("ddp_set_dst_module, scenario=%s, dst_module=%s\n",
	       ddp_get_scenario_name(scenario), ddp_get_module_name(dst_module));
	if (ddp_find_module_index(scenario, dst_module) > 0) {
		DDPDBG("%s is already on path\n", ddp_get_module_name(dst_module));
		return 0;
	}
	i = ddp_get_module_num_l(module_list_scenario[scenario]) - 1;
	ASSERT(i >= 0);
	if (dst_module == DISP_MODULE_DSIDUAL) {
		if (i < (DDP_ENING_NUM - 1)) {
			module_list_scenario[scenario][i++] = DISP_MODULE_SPLIT0;
		} else {
			DDPERR("set dst module over up bound\n");
			return -1;
		}
	} else {
		if (ddp_get_dst_module(scenario) == DISP_MODULE_DSIDUAL) {
			if (i >= 1) {
				module_list_scenario[scenario][i--] = -1;
			} else {
				DDPERR("set dst module over low bound\n");
				return -1;
			}
		}
	}
	module_list_scenario[scenario][i] = dst_module;
	if (scenario == DDP_SCENARIO_PRIMARY_ALL)
		ddp_set_dst_module(DDP_SCENARIO_PRIMARY_DISP, dst_module);
	else if (scenario == DDP_SCENARIO_SUB_ALL)
		ddp_set_dst_module(DDP_SCENARIO_SUB_RDMA1_DISP, dst_module);

	ddp_print_scenario(scenario);
	return 0;
}

DISP_MODULE_ENUM ddp_get_dst_module(DDP_SCENARIO_ENUM ddp_scenario)
{
	DISP_MODULE_ENUM module_name = DISP_MODULE_UNKNOWN;
	int module_num = ddp_get_module_num_l(module_list_scenario[ddp_scenario]) - 1;

	if (module_num >= 0)
		module_name = module_list_scenario[ddp_scenario][module_num];

	return module_name;
}

unsigned int *ddp_get_scenario_list(DDP_SCENARIO_ENUM ddp_scenario)
{
	return module_list_scenario[ddp_scenario];
}

int ddp_is_module_in_scenario(DDP_SCENARIO_ENUM ddp_scenario, DISP_MODULE_ENUM module)
{
	int i = 0;

	for (i = 0; i < DDP_ENING_NUM; i++) {
		if (module_list_scenario[ddp_scenario][i] == module)
			return 1;

	}
	return 0;
}

int ddp_insert_module(DDP_SCENARIO_ENUM ddp_scenario, DISP_MODULE_ENUM place,
		      DISP_MODULE_ENUM module)
{
	int i = DDP_ENING_NUM - 1;
	int idx = ddp_find_module_index(ddp_scenario, place);

	if (idx < 0) {
		DDPERR("error: ddp_insert_module , place=%s is not in scenario %s!\n",
		       ddp_get_module_name(place), ddp_get_scenario_name(ddp_scenario));
		return -1;
	}

	for (i = 0; i < DDP_ENING_NUM; i++) {
		if (module_list_scenario[ddp_scenario][i] == module) {
			DDPERR("error: ddp_insert_module , module=%s is already in scenario %s!\n",
			       ddp_get_module_name(module), ddp_get_scenario_name(ddp_scenario));
			return -1;
		}
	}

	/* should have empty room for insert */
	ASSERT(module_list_scenario[ddp_scenario][DDP_ENING_NUM - 1] == -1);

	for (i = DDP_ENING_NUM - 2; i >= idx; i--)
		module_list_scenario[ddp_scenario][i + 1] = module_list_scenario[ddp_scenario][i];
	module_list_scenario[ddp_scenario][idx] = module;

	{
		int *modules = ddp_get_scenario_list(ddp_scenario);
		int module_num = ddp_get_module_num(ddp_scenario);

		DDPMSG("after insert module, module list is:\n");
		for (i = 0; i < module_num; i++)
			DDPMSG("%s-", ddp_get_module_name(modules[i]));
	}

	return 0;
}

int ddp_remove_module(DDP_SCENARIO_ENUM ddp_scenario, DISP_MODULE_ENUM module)
{
	int i = 0;
	int idx = ddp_find_module_index(ddp_scenario, module);

	if (idx < 0) {
		DDPERR("ddp_remove_module, can not find module %s in scenario %s\n",
		       ddp_get_module_name(module), ddp_get_scenario_name(ddp_scenario));
		return -1;
	}

	for (i = idx; i < DDP_ENING_NUM - 1; i++)
		module_list_scenario[ddp_scenario][i] = module_list_scenario[ddp_scenario][i + 1];
	module_list_scenario[ddp_scenario][DDP_ENING_NUM - 1] = -1;

	{
		int *modules = ddp_get_scenario_list(ddp_scenario);
		int module_num = ddp_get_module_num(ddp_scenario);

		DDPMSG("after remove module, module list is:\n");
		for (i = 0; i < module_num; i++)
			DDPMSG("%s-", ddp_get_module_name(modules[i]));
	}
	return 0;
}

void ddp_connect_path(DDP_SCENARIO_ENUM scenario, void *handle)
{
	DDPDBG("path connect on scenario %s\n", ddp_get_scenario_name(scenario));
	if (scenario == DDP_SCENARIO_PRIMARY_ALL) {
		ddp_connect_path_l(module_list_scenario[DDP_SCENARIO_PRIMARY_DISP], handle);
		ddp_connect_path_l(module_list_scenario[DDP_SCENARIO_PRIMARY_OVL_MEMOUT], handle);
	} else if (scenario == DDP_SCENARIO_SUB_ALL) {
		ddp_connect_path_l(module_list_scenario[DDP_SCENARIO_SUB_DISP], handle);
		ddp_connect_path_l(module_list_scenario[DDP_SCENARIO_SUB_OVL_MEMOUT], handle);
	} else {
		ddp_connect_path_l(module_list_scenario[scenario], handle);
	}
	return;
}

void ddp_disconnect_path(DDP_SCENARIO_ENUM scenario, void *handle)
{
	DDPDBG("path disconnect on scenario %s\n", ddp_get_scenario_name(scenario));

	if (scenario == DDP_SCENARIO_PRIMARY_ALL) {
		ddp_disconnect_path_l(module_list_scenario[DDP_SCENARIO_PRIMARY_DISP], handle);
		ddp_disconnect_path_l(module_list_scenario[DDP_SCENARIO_PRIMARY_OVL_MEMOUT],
				      handle);
	} else if (scenario == DDP_SCENARIO_SUB_ALL) {
		ddp_disconnect_path_l(module_list_scenario[DDP_SCENARIO_SUB_DISP], handle);
		ddp_disconnect_path_l(module_list_scenario[DDP_SCENARIO_SUB_OVL_MEMOUT], handle);
	} else {
		ddp_disconnect_path_l(module_list_scenario[scenario], handle);
	}
	return;
}

void ddp_check_path(DDP_SCENARIO_ENUM scenario)
{
	DDPDBG("path check path on scenario %s\n", ddp_get_scenario_name(scenario));

	if (scenario == DDP_SCENARIO_PRIMARY_ALL) {
		ddp_check_path_l(module_list_scenario[DDP_SCENARIO_PRIMARY_DISP]);
		ddp_check_path_l(module_list_scenario[DDP_SCENARIO_PRIMARY_OVL_MEMOUT]);
	} else if (scenario == DDP_SCENARIO_SUB_ALL) {
		ddp_check_path_l(module_list_scenario[DDP_SCENARIO_SUB_DISP]);
		ddp_check_path_l(module_list_scenario[DDP_SCENARIO_SUB_OVL_MEMOUT]);
	} else {
		ddp_check_path_l(module_list_scenario[scenario]);
	}
	return;
}

void ddp_check_mutex(int mutex_id, DDP_SCENARIO_ENUM scenario, DDP_MODE mode)
{
	DDPDBG("check mutex %d on scenario %s\n", mutex_id, ddp_get_scenario_name(scenario));
	ddp_check_mutex_l(mutex_id, module_list_scenario[scenario], mode);
}

int ddp_mutex_set(int mutex_id, DDP_SCENARIO_ENUM scenario, DDP_MODE mode, void *handle)
{
	if (scenario < DDP_SCENARIO_MAX) {
		return ddp_mutex_set_l(mutex_id, module_list_scenario[scenario], mode, handle);
	} else {
		DDPERR("Invalid scenario %d when setting mutex\n", scenario);
		return -1;
	}
	return 0;
}

int ddp_mutex_Interrupt_enable(int mutex_id, void *handle)
{

	DDPDBG("mutex %d interrupt enable\n", mutex_id);
	DISP_REG_MASK(handle, DISP_REG_CONFIG_MUTEX_INTEN, 0x1 << mutex_id, 0x1 << mutex_id);
	DISP_REG_MASK(handle, DISP_REG_CONFIG_MUTEX_INTEN, 1 << (mutex_id + DISP_MUTEX_TOTAL),
		      0x1 << (mutex_id + DISP_MUTEX_TOTAL));
	return 0;
}

int ddp_mutex_Interrupt_disable(int mutex_id, void *handle)
{
	DDPDBG("mutex %d interrupt disenable\n", mutex_id);
	DISP_REG_MASK(handle, DISP_REG_CONFIG_MUTEX_INTEN, 0, 0x1 << mutex_id);
	DISP_REG_MASK(handle, DISP_REG_CONFIG_MUTEX_INTEN, 0, 0x1 << (mutex_id + DISP_MUTEX_TOTAL));
	return 0;
}

int ddp_mutex_reset(int mutex_id, void *handle)
{
	DDPDBG("mutex %d reset\n", mutex_id);
	DISP_REG_SET(handle, DISP_REG_CONFIG_MUTEX_RST(mutex_id), 1);
	DISP_REG_SET(handle, DISP_REG_CONFIG_MUTEX_RST(mutex_id), 0);

	return 0;
}

int ddp_is_moudule_in_mutex(int mutex_id, DISP_MODULE_ENUM module)
{
	int ret = 0;
	uint32_t real_value = 0;

	if (mutex_id < DISP_MUTEX_DDP_FIRST || mutex_id > DISP_MUTEX_DDP_LAST) {
		DDPDUMP("error:check_moudule_in_mute fail:exceed mutex max (0 ~ %d)\n",
			DISP_MUTEX_DDP_LAST);
		return ret;
	}

	if (module_mutex_map[module].mod_num == 0) {
		real_value = DISP_REG_GET(DISP_REG_CONFIG_MUTEX_MOD0(mutex_id));
	} else if (module_mutex_map[module].mod_num == 1) {
		real_value = DISP_REG_GET(DISP_REG_CONFIG_MUTEX_MOD1(mutex_id));
	}

	if (1 == ((real_value >> module_mutex_map[module].bit) & 0x01))
		ret = 1;

	return ret;
}


int ddp_mutex_add_module(int mutex_id, DISP_MODULE_ENUM module, void *handle)
{
	int value = 0;

	if (module < DISP_MODULE_UNKNOWN) {
		if (module_mutex_map[module].bit != -1) {
			DDPDBG("module %s added to mutex %d\n", ddp_get_module_name(module),
			       mutex_id);
			value |= (1 << module_mutex_map[module].bit);
			if (module_mutex_map[module].mod_num == 0) {
				DISP_REG_MASK(handle, DISP_REG_CONFIG_MUTEX_MOD0(mutex_id), value, value);
			} else if (module_mutex_map[module].mod_num == 1) {
				DISP_REG_MASK(handle, DISP_REG_CONFIG_MUTEX_MOD1(mutex_id), value, value);
			}
		}
	}
	return 0;
}

int ddp_mutex_remove_module(int mutex_id, DISP_MODULE_ENUM module, void *handle)
{
	int value = 0;

	if (module < DISP_MODULE_UNKNOWN) {
		if (module_mutex_map[module].bit != -1) {
			DDPDBG("module %s added to mutex %d\n", ddp_get_module_name(module),
			       mutex_id);
			value |= (1 << module_mutex_map[module].bit);
			if (module_mutex_map[module].mod_num == 0) {
				DISP_REG_MASK(handle, DISP_REG_CONFIG_MUTEX_MOD0(mutex_id), 0, value);
			} else if (module_mutex_map[module].mod_num == 1) {
				DISP_REG_MASK(handle, DISP_REG_CONFIG_MUTEX_MOD1(mutex_id), 0, value);
			}
		}

	}
	return 0;
}

int ddp_mutex_clear(int mutex_id, void *handle)
{
	DDPDBG("mutex %d clear\n", mutex_id);
	DISP_REG_SET(handle, DISP_REG_CONFIG_MUTEX_MOD0(mutex_id), 0);
	/*DISP_REG_SET(handle, DISP_REG_CONFIG_MUTEX_MOD1(mutex_id), 0);*/
	DISP_REG_SET(handle, DISP_REG_CONFIG_MUTEX_SOF(mutex_id), 0);
	/* enough or not */

	/*reset mutex */
	ddp_mutex_reset(mutex_id, handle);
	return 0;
}

int ddp_mutex_enable(int mutex_id, DDP_SCENARIO_ENUM scenario, void *handle)
{
	return ddp_mutex_enable_l(mutex_id, handle);
}

int ddp_mutex_disable(int mutex_id, DDP_SCENARIO_ENUM scenario, void *handle)
{
	DDPDBG("mutex %d disable\n", mutex_id);
	DISP_REG_SET(handle, DISP_REG_CONFIG_MUTEX_EN(mutex_id), 0);
	return 0;
}
int ddp_mutex_get(int mutex_id, DDP_SCENARIO_ENUM scenario, void *handle)
{
	DDPDBG("mutex %d get\n", mutex_id);
	DISP_REG_SET(handle, DISP_REG_CONFIG_MUTEX_GET(mutex_id), 1);
	return 0;
}

int ddp_mutex_release(int mutex_id, DDP_SCENARIO_ENUM scenario, void *handle)
{
	DDPDBG("mutex %d release\n", mutex_id);
	DISP_REG_SET(handle, DISP_REG_CONFIG_MUTEX_GET(mutex_id), 0);
	return 0;
}

int ddp_mutex_set_sof_wait(int mutex_id, cmdqRecHandle handle, int wait)
{
	if (mutex_id < DISP_MUTEX_DDP_FIRST || mutex_id > DISP_MUTEX_DDP_LAST) {
		DDPERR("exceed mutex max (0 ~ %d)\n", DISP_MUTEX_DDP_LAST);
		return -1;
	}

	DISP_REG_SET_FIELD(handle, SOF_FLD_MUTEX0_SOF_WAIT, DISP_REG_CONFIG_MUTEX_SOF(mutex_id), wait);
	return 0;
}

int ddp_check_engine_status(int mutexID)
{
	/* check engines' clock bit &  enable bit & status bit before unlock mutex */
	/* should not needed, in comdq do? */
	int result = 0;
	return result;
}

int ddp_path_top_clock_on(void)
{
	DDPMSG("ddp path top clock on\n");
	ddp_enable_module_clock(DISP_MODULE_SMI_COMMON);
	ddp_enable_module_clock(DISP_MODULE_SMI_LARB0);
	ddp_enable_module_clock(DISP_MODULE_SMI_LARB1);
	DDPMSG("ddp CG0:%x CG1:%x\n", DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON0),
		DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON1));
	return 0;
}

int ddp_path_top_clock_off(void)
{
	DDPMSG("ddp path top clock off\n");
	ddp_disable_module_clock(DISP_MODULE_SMI_LARB0);
	ddp_disable_module_clock(DISP_MODULE_SMI_LARB1);
	ddp_disable_module_clock(DISP_MODULE_SMI_COMMON);
	DDPMSG("ddp CG0:%x CG1:%x\n", DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON0),
		DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON1));
	return 0;
}

int ddp_path_m4u_off(void)
{
	int i;

#ifdef MTKFB_NO_M4U
	/* display ports bypass m4u.
	==== FBI WARNING: ==========
	This function is hard code of m4u port setting !!!
	Please ask M4U owner about it for new chip porting !!!
	*/

	/*
		M4U_PORT_DISP_OVL0,
		M4U_PORT_DISP_2L_OVL0_LARB0,
		M4U_PORT_DISP_2L_OVL1_LARB0,
		M4U_PORT_DISP_RDMA0,
		M4U_PORT_DISP_RDMA1,
		M4U_PORT_DISP_WDMA0,
	*/
	for (i=0; i<6; i++)
		DISP_REG_SET_FIELD(0, REG_FLD_MMU_EN, DISP_REG_SMI_LARB0_MMU_EN + i*4, 0);
#endif
	return 0;
}
