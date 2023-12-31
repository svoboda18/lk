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

#define LOG_TAG "SPLIT"

#include "platform/ddp_log.h"
#include "platform/ddp_info.h"
#include "platform/ddp_reg.h"
//#include "platform/ddp_split.h"

//#include <mach/mt_clkmgr.h>
//#include <linux/delay.h>


static char *split_state(unsigned int state)
{
	switch (state) {
		case 1:
			return "idle";
		case 2:
			return "wait";
		case 4:
			return "busy";
		default:
			return "unknow";
	}
}

static int split_clock_on(DISP_MODULE_ENUM module, void *handle)
{
	ddp_enable_module_clock(module);
	return 0;
}

static int split_clock_off(DISP_MODULE_ENUM module, void *handle)
{
	ddp_disable_module_clock(module);
	return 0;
}

static int split_init(DISP_MODULE_ENUM module, void *handle)
{
	ddp_enable_module_clock(module);
	return 0;
}

static int split_deinit(DISP_MODULE_ENUM module, void *handle)
{
	ddp_enable_module_clock(module);
	return 0;
}

static int split_start(DISP_MODULE_ENUM module, void *handle)
{
	DISP_REG_SET(handle, DISP_REG_SPLIT_ENABLE, 0x01);
	return 0;
}

static int split_stop(DISP_MODULE_ENUM module, void *handle)
{
	DISP_REG_SET(handle, DISP_REG_SPLIT_ENABLE, 0x0);
	return 0;
}

static int split_config(DISP_MODULE_ENUM module, disp_ddp_path_config *pConfig, void *handle)
{
	DISP_REG_SET(handle, DISP_REG_SPLIT_CFG, 0x00);/* 0: even pixel first, 1: odd pexel first */
	DISP_REG_SET(handle, DISP_REG_SPLIT_DEBUG, 0x80000000);/* 0: even pixel first, 1: odd pexel first */

	return 0;
}

static int split_busy(DISP_MODULE_ENUM module)
{
	unsigned int state = DISP_REG_GET_FIELD(DEBUG_FLD_SPLIT_FSM, DISP_REG_SPLIT_DEBUG);

	return (state & 0x4);
}

static int split_idle(DISP_MODULE_ENUM module)
{
	unsigned int state = DISP_REG_GET_FIELD(DEBUG_FLD_SPLIT_FSM, DISP_REG_SPLIT_DEBUG);

	return (state & 0x3);
}

int split_reset(DISP_MODULE_ENUM module,void *handle)
{
	unsigned int delay_cnt = 0;

	DISP_REG_SET(handle, DISP_REG_SPLIT_SW_RESET, 0x1);
	DISP_REG_SET(handle, DISP_REG_SPLIT_SW_RESET, 0x0);
	/*always use cpu do reset*/
	while ((DISP_REG_GET_FIELD(DEBUG_FLD_SPLIT_FSM, DISP_REG_SPLIT_DEBUG) & 0x3) == 0) {
		delay_cnt++;
		//udelay(10);
		if (delay_cnt > 2000) {
			DDPERR("split_reset() timeout!\n");
			break;
		}
	}
	return 0;
}

static int split_dump_regs(DISP_MODULE_ENUM module)
{
	DDPMSG("== DISP SPLIT ==\n");
	DDPMSG("(0x000)S_ENABLE       =0x%x\n", DISP_REG_GET(DISP_REG_SPLIT_ENABLE));
	DDPMSG("(0x004)S_SW_RST       =0x%x\n", DISP_REG_GET(DISP_REG_SPLIT_SW_RESET));
	DDPMSG("(0x008)S_DEBUG        =0x%x\n", DISP_REG_GET(DISP_REG_SPLIT_DEBUG));
	return 0;
}

static int split_dump_analysis(DISP_MODULE_ENUM module)
{
	unsigned int pixel = DISP_REG_GET_FIELD(DEBUG_FLD_IN_PIXEL_CNT, DISP_REG_SPLIT_DEBUG);
	unsigned int state = DISP_REG_GET_FIELD(DEBUG_FLD_SPLIT_FSM, DISP_REG_SPLIT_DEBUG);

	DDPMSG("== DISP SPLIT0 ANALYSIS ==\n");
	DDPMSG("cur_pixel %u, state %s\n", pixel, split_state(state));
	return 0;
}

static int split_dump(DISP_MODULE_ENUM module, int level)
{
	split_dump_analysis(module);
	split_dump_regs(module);

	return 0;
}


static int split_debug(DISP_MODULE_ENUM module)
{
	unsigned int pixel = DISP_REG_GET_FIELD(DEBUG_FLD_IN_PIXEL_CNT, DISP_REG_SPLIT_DEBUG);
	unsigned int state = DISP_REG_GET_FIELD(DEBUG_FLD_SPLIT_FSM, DISP_REG_SPLIT_DEBUG);

	DDPMSG("== DISP¡¡PLIT¡¡DEBUG INFO  ==\n");

	DDPMSG("cur_pixel %u, state %s\n", pixel, split_state(state));
	return 0;
}

DDP_MODULE_DRIVER ddp_driver_split = {
	.module          = DISP_MODULE_SPLIT0,
	.init            = split_init,
	.deinit          = split_deinit,
	.config          = split_config,
	.start           = split_start,
	.trigger         = NULL,
	.stop            = split_stop,
	.reset           = split_reset,
	.power_on        = split_clock_on,
	.power_off       = split_clock_off,
	.is_idle         = split_idle,
	.is_busy         = split_busy,
	.dump_info       = split_dump,
	.bypass          = NULL,
	.build_cmdq      = NULL,
	.set_lcm_utils   = NULL,
};
