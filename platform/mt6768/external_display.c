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

#include <video_fb.h>
#include <target/board.h>
#include <env.h>
#include "lcm_drv.h"
#include <string.h>
#include <stdlib.h>
#include <platform/mt_gpt.h>
#include <platform/disp_drv_platform.h>
#include <platform/disp_drv_log.h>
#include <platform/boot_mode.h>
#include <platform/primary_display.h>
#include <platform/external_display.h>
#include <platform/disp_lcm.h>

//#include<linux/timer.h>

#define DDP_LK_BOOT
#ifndef HZ
#define HZ 100
#endif

#ifdef DDP_LK_BOOT
typedef void * cmdqRecHandle;

#endif

#define ALIGN_TO(x, n)  \
    (((x) + ((n) - 1)) & ~((n) - 1))

int external_display_use_cmdq = CMDQ_DISABLE;
int external_display_use_m4u = 1;
DISP_EXTERNAL_PATH_MODE external_display_mode = EXT_DIRECT_LINK_MODE;
static UINT32 disp_fb_bpp = 32;     ///ARGB8888
static UINT32 disp_fb_pages = 3;     ///double buffer

extern int ddp_dsi_set_lcm_utils(DISP_MODULE_ENUM module, LCM_DRIVER *lcm_drv);
extern int ddp_dsi_dump(DISP_MODULE_ENUM module, int level);
typedef struct {
	int                             state;
	int                         need_trigger_overlay;
	DISP_EXTERNAL_PATH_MODE  mode;
	unsigned int                    last_vsync_tick;
#ifndef DDP_LK_BOOT
	struct mutex                    lock;
#endif
	disp_lcm_handle *               plcm;
	cmdqRecHandle               cmdq_handle_config;
	cmdqRecHandle               cmdq_handle_trigger;
	disp_path_handle                    dpmgr_handle;
	disp_path_handle                ovl2mem_path_handle;
} display_external_path_context;

#define pgc _get_context()

static display_external_path_context* _get_context(void)
{
	static int is_context_inited = 0;
	static display_external_path_context g_context;
	if (!is_context_inited) {
		memset((void*)&g_context, 0, sizeof(display_external_path_context));
		is_context_inited = 1;
	}

	return &g_context;
}

static void _external_path_lock(void)
{
#ifndef DDP_LK_BOOT
	disp_sw_mutex_lock(&(pgc->lock));
#endif
}

static void _external_path_unlock(void)
{
#ifndef DDP_LK_BOOT
	disp_sw_mutex_unlock(&(pgc->lock));
#endif
}

static DISP_MODULE_ENUM _get_dst_module_by_lcm(disp_lcm_handle *plcm)
{
	if (plcm == NULL) {
		DISPERR("plcm is null\n");
		return DISP_MODULE_UNKNOWN;
	}

	if (plcm->params->type == LCM_TYPE_DSI) {
		if (plcm->lcm_if_id == LCM_INTERFACE_DSI0) {
			return DISP_MODULE_DSI0;
		} else if (plcm->lcm_if_id == LCM_INTERFACE_DSI1) {
			return DISP_MODULE_DSI1;
		} else if (plcm->lcm_if_id == LCM_INTERFACE_DSI_DUAL) {
			return DISP_MODULE_DSIDUAL;
		} else {
			return DISP_MODULE_DSI0;
		}
	} else if (plcm->params->type == LCM_TYPE_DPI) {
		return DISP_MODULE_DPI;
	} else {
		DISPERR("can't find external path dst module\n");
		return DISP_MODULE_UNKNOWN;
	}
}

static int _build_path_direct_link(void)
{
	int ret = 0;

	DISP_MODULE_ENUM dst_module = 0;
	DISPFUNC();
	pgc->mode = EXT_DIRECT_LINK_MODE;

	pgc->dpmgr_handle = dpmgr_create_path(DDP_SCENARIO_SECONDARY_DISP, pgc->cmdq_handle_config);
	if (pgc->dpmgr_handle) {
		DISPCHECK("dpmgr create path SUCCESS(0x%08x)\n", pgc->dpmgr_handle);
	} else {
		DISPCHECK("dpmgr create path FAIL\n");
		return -1;
	}

	dst_module = _get_dst_module_by_lcm(pgc->plcm);
	dpmgr_path_set_dst_module(pgc->dpmgr_handle, dst_module);
	DISPCHECK("dpmgr set dst module FINISHED(%s)\n", ddp_get_module_name(dst_module));

	dpmgr_set_lcm_utils(pgc->dpmgr_handle, pgc->plcm->drv);

	return ret;
}

static int _build_path_decouple(void)
{
    return 0;
}

static int _build_path_single_layer(void)
{
    return 0;
}

static int _build_path_debug_rdma1_dsi0(void)
{
	return 0;
}

static void _build_cmdq_trigger_loop(void)
{
#ifndef DDP_LK_BOOT

	int ret = 0;
	cmdqRecCreate(CMDQ_SCENARIO_TRIGGER_LOOP, &(pgc->cmdq_handle_trigger));
	DISPMSG("external path trigger thread cmd handle=0x%08x\n", pgc->cmdq_handle_trigger);
	cmdqRecReset(pgc->cmdq_handle_trigger);

	if (external_display_is_video_mode()) {
		// wait and clear stream_done
		ret = cmdqRecWait(pgc->cmdq_handle_trigger,
								dpmgr_path_get_mutex(pgc->dpmgr_handle) + CMDQ_EVENT_MUTEX0_STREAM_EOF);
		dpmgr_path_build_cmdq(pgc->dpmgr_handle, pgc->cmdq_handle_trigger, CMDQ_AFTER_STREAM_EOF);
		//ret = cmdqRecSetEventToken(pgc->cmdq_handle_trigger, CMDQ_SYNC_TOKEN_CONFIG_ALLOW);
	} else {
		// only in DSI Command mode we need to wait these
		ret = cmdqRecWait(pgc->cmdq_handle_trigger, CMDQ_SYNC_TOKEN_EXT_CONFIG_DIRTY);
		// no internal te on fpga now.
		//ret = cmdqRecWait(pgc->cmdq_handle_trigger, CMDQ_EVENT_MDP_DSI0_TE_SOF);
		dpmgr_path_build_cmdq(pgc->dpmgr_handle, pgc->cmdq_handle_trigger, CMDQ_BEFORE_STREAM_SOF);

		// block config threads, we'll about to update frame
		ret = cmdqRecClearEventToken(pgc->cmdq_handle_trigger, CMDQ_SYNC_TOKEN_EXT_CONFIG_ALLOW);

		// only in DSI command mode we need to enable mutex explicitly
		// WRITE mutex enable
		dpmgr_path_trigger(pgc->dpmgr_handle, pgc->cmdq_handle_trigger,external_display_use_cmdq);
		//ret = cmdqRecWrite(pgc->cmdq_handle_trigger, (unsigned int)(DISP_REG_CONFIG_MUTEX_EN(0))&0x1fffffff, 1, ~0);

		dpmgr_path_build_cmdq(pgc->dpmgr_handle, pgc->cmdq_handle_trigger, CMDQ_WAIT_STREAM_EOF_EVENT);
		dpmgr_path_build_cmdq(pgc->dpmgr_handle, pgc->cmdq_handle_trigger, CMDQ_CHECK_IDLE_AFTER_STREAM_EOF);

		dpmgr_path_build_cmdq(pgc->dpmgr_handle, pgc->cmdq_handle_trigger, CMDQ_AFTER_STREAM_EOF);

		//ret = cmdqRecWait(pgc->cmdq_handle_trigger, CMDQ_EVENT_DISP_RDMA0_EOF);
		// polling DSI idle
		//ret = cmdqRecPoll(pgc->cmdq_handle_trigger, 0x1401b00c, 0, 0x80000000);
		// polling wdma frame done
		//ret = cmdqRecPoll(pgc->cmdq_handle_trigger, 0x140060A0, 1, 0x1);

		ret = cmdqRecSetEventToken(pgc->cmdq_handle_trigger, CMDQ_SYNC_TOKEN_EXT_CONFIG_ALLOW);

		/*********************/
		/***build cmdq finished***/
		/*********************/
		// TODO:
		// cmdqRecDumphandle(pgc->cmdq_handle_trigger);

		// RUN forever!!!!
		BUG_ON(ret < 0);
	}

#endif

}

static void _start_cmdq_trigger_loop(void)
{
#ifndef DDP_LK_BOOT

	int ret = 0;

	// this should be called only once because trigger loop will nevet stop
	cmdqCoreSetEvent(CMDQ_SYNC_TOKEN_EXT_CONFIG_ALLOW);
	ret = cmdqRecStartLoop(pgc->cmdq_handle_trigger);
#endif
}

static void _set_cmdq_config_handle_dirty(void)
{
#ifndef DDP_LK_BOOT

	ddp_insert_config_dirty_rec(pgc->cmdq_handle_config);
	cmdqRecFlush(pgc->cmdq_handle_config);
#endif
}

static void _reset_cmdq_config_handle(void)
{
#ifndef DDP_LK_BOOT

	cmdqRecReset(pgc->cmdq_handle_config);
	ddp_insert_config_allow_rec(pgc->cmdq_handle_config);
#endif
}

static int _convert_disp_input_to_rdma(RDMA_CONFIG_STRUCT *dst, disp_input_config* src)
{
	if (src && dst) {
		dst->inputFormat = src->fmt;
		dst->address = src->addr;
		dst->width = src->src_w;
		dst->height = src->src_h;
		dst->pitch = src->src_pitch;

		return 0;
	} else {
		DISPERR("src(0x%08x) or dst(0x%08x) is null\n", src, dst);
		return -1;
	}
}

static int _convert_disp_input_to_ovl(OVL_CONFIG_STRUCT *dst, disp_input_config* src)
{
	if (src && dst) {
		dst->layer = src->layer;
		dst->layer_en = src->layer_en;
		dst->fmt = src->fmt;
		dst->addr = src->addr;
		dst->vaddr = src->vaddr;
		dst->src_x = src->src_x;
		dst->src_y = src->src_y;
		dst->src_w = src->src_w;
		dst->src_h = src->src_h;
		dst->src_pitch = src->src_pitch;
		dst->dst_x = src->dst_x;
		dst->dst_y = src->dst_y;
		dst->dst_w = src->dst_w;
		dst->dst_h = src->dst_h;
		dst->keyEn = src->keyEn;
		dst->key = src->key;
		dst->aen = src->aen;
		dst->alpha = src->alpha;

		dst->isDirty = src->isDirty;

		dst->buff_idx = src->buff_idx;
		dst->identity = src->identity;
		dst->connected_type = src->connected_type;
		dst->security = src->security;

		return 0;
	} else {
		DISPERR("src(0x%08x) or dst(0x%08x) is null\n", src, dst);
		return -1;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int external_display_is_lcm_connected(void)
{
	return pgc->plcm->is_connected;
}

const char* external_display_get_lcm_name(void)
{
	return disp_lcm_get_name(pgc->plcm);
}

int external_display_change_lcm_resolution(unsigned int width, unsigned int height)
{
	if (pgc->plcm) {
		DISPMSG("LCM Resolution will be changed, original: %dx%d, now: %dx%d\n", pgc->plcm->params->width, pgc->plcm->params->height, width, height);
		// align with 4 is the minimal check, to ensure we can boot up into kernel, and could modify dfo setting again using meta tool
		// otherwise we will have a panic in lk(root cause unknown).
		if (width >pgc->plcm->params->width || height > pgc->plcm->params->height || width == 0 || height == 0 || width %4 || height %2) {
			DISPERR("Invalid resolution: %dx%d\n", width, height);
			return -1;
		}

		if (external_display_is_video_mode()) {
			DISPERR("Warning!!!Video Mode can't support multiple resolution!\n");
			return -1;
		}

		pgc->plcm->params->width = width;
		pgc->plcm->params->height = height;

		return 0;
	} else {
		return -1;
	}
}

int external_display_init(char *lcm_name)
{
	DISPFUNC();
	DISP_STATUS ret = DISP_STATUS_OK;
	DISP_MODULE_ENUM dst_module = 0;

	unsigned int lcm_fake_width = 0;
	unsigned int lcm_fake_height = 0;
	LCM_PARAMS *lcm_param = NULL;
	LCM_INTERFACE_ID lcm_id = LCM_INTERFACE_NOTDEFINED;

	dpmgr_init();
#ifndef DDP_LK_BOOT
	mutex_init(&(pgc->lock));
#endif
	_external_path_lock();

	if (pgc->plcm == NULL)
		pgc->plcm = disp_ext_lcm_probe( lcm_name, LCM_INTERFACE_NOTDEFINED);

	if (pgc->plcm == NULL) {
		DISPCHECK("disp_ext_lcm_probe returns null\n");
		ret = DISP_STATUS_ERROR;
		goto done;
	} else {
		DISPCHECK("disp_ext_lcm_probe SUCCESS\n");
	}


	lcm_param = disp_lcm_get_params(pgc->plcm);

	if (lcm_param == NULL) {
		DISPERR("get lcm params FAILED\n");
		ret = DISP_STATUS_ERROR;
		goto done;
	}

	if (external_display_mode == EXT_DIRECT_LINK_MODE) {
		_build_path_direct_link();

		DISPCHECK("external display is DIRECT LINK MODE\n");
	} else if (external_display_mode == EXT_DECOUPLE_MODE) {
		_build_path_decouple();

		DISPCHECK("external display is DECOUPLE MODE\n");
	} else if (external_display_mode == EXT_SINGLE_LAYER_MODE) {
		_build_path_single_layer();

		DISPCHECK("external display is SINGLE LAYER MODE\n");
	} else if (external_display_mode == EXT_DEBUG_RDMA1_DSI1_MODE) {
		_build_path_debug_rdma1_dsi0();

		DISPCHECK("external display is DEBUG RDMA1 DSI1 MODE\n");
	} else {
		DISPCHECK("external display mode is WRONG\n");
	}

	_build_cmdq_trigger_loop();

	DISPCHECK("external display BUILD cmdq trigger loop finished\n");

	_start_cmdq_trigger_loop();

	DISPCHECK("external display START cmdq trigger loop finished\n");

	dpmgr_path_set_video_mode(pgc->dpmgr_handle, external_display_is_video_mode());

	dpmgr_path_init(pgc->dpmgr_handle, CMDQ_DISABLE);

	disp_ddp_path_config data_config;
	memset((void*)&data_config, 0, sizeof(disp_ddp_path_config));

	memcpy(&(data_config.dsi_config), &(lcm_param->dsi), sizeof(LCM_DSI_PARAMS));

	data_config.dst_w = disp_lcm_width(pgc->plcm);
	data_config.dst_h = disp_lcm_height(pgc->plcm);
	if (lcm_param->type == LCM_TYPE_DSI) {
		if (lcm_param->dsi.data_format.format == LCM_DSI_FORMAT_RGB888)
			data_config.lcm_bpp = 24;
		else if (lcm_param->dsi.data_format.format == LCM_DSI_FORMAT_RGB565)
			data_config.lcm_bpp = 16;
		else if (lcm_param->dsi.data_format.format == LCM_DSI_FORMAT_RGB666)
			data_config.lcm_bpp = 18;
	} else if (lcm_param->type == LCM_TYPE_DPI) {
		if ( lcm_param->dpi.format == LCM_DPI_FORMAT_RGB888)
			data_config.lcm_bpp = 24;
		else if ( lcm_param->dpi.format == LCM_DPI_FORMAT_RGB565)
			data_config.lcm_bpp = 16;
		if ( lcm_param->dpi.format == LCM_DPI_FORMAT_RGB666)
			data_config.lcm_bpp = 18;
	}
	data_config.dst_dirty = 1;

	ret = dpmgr_path_config(pgc->dpmgr_handle, &data_config, CMDQ_DISABLE);
	ret = disp_lcm_init(pgc->plcm);

	if (external_display_is_video_mode()) {
		if (lcm_param->dsi.lfr_enable == 1) {
			dpmgr_map_event_to_irq(pgc->dpmgr_handle, DISP_PATH_EVENT_IF_VSYNC, DDP_IRQ_DSI0_FRAME_DONE);
		} else {
			dpmgr_map_event_to_irq(pgc->dpmgr_handle, DISP_PATH_EVENT_IF_VSYNC, DDP_IRQ_RDMA0_DONE);
		}
	} else {

	}

	dpmgr_enable_event(pgc->dpmgr_handle, DISP_PATH_EVENT_IF_VSYNC);
	dpmgr_enable_event(pgc->dpmgr_handle, DISP_PATH_EVENT_FRAME_DONE);

	pgc->state = 1;

done:

	_external_path_unlock();
	return ret;
}

// register rdma done event
int external_display_wait_for_idle(void)
{
	DISP_STATUS ret = DISP_STATUS_OK;

	DISPFUNC();

	_external_path_lock();

done:
	_external_path_unlock();
	return ret;
}

int external_display_wait_for_dump(void)
{
	return 0;
}

static long int get_current_time_us(void)
{
	return get_timer(0);
}

int external_display_wait_for_vsync(void)
{
	int ret = 0;
	ret = dpmgr_wait_event(pgc->dpmgr_handle, DISP_PATH_EVENT_IF_VSYNC);
	if (ret == -2) {
		DISPCHECK("vsync for external display path not enabled yet\n");
		return -1;
	}

//	pgc->last_vsync_tick = get_current_time_us();
	pgc->last_vsync_tick = 0;

	return 0;
}

int external_display_suspend(void)
{
	DISP_STATUS ret = DISP_STATUS_OK;

	DISPFUNC();
	_external_path_lock();

	dpmgr_path_stop(pgc->dpmgr_handle, CMDQ_DISABLE);
	dpmgr_path_reset(pgc->dpmgr_handle, CMDQ_DISABLE);
	/* If need close the LCM, when exit lk. We need do disp_lcm_suspend */
/*	disp_lcm_suspend(pgc->plcm); */

	dpmgr_path_power_off(pgc->dpmgr_handle, CMDQ_DISABLE);
#ifndef DDP_LK_BOOT
	cmdqRecStopLoop(pgc->cmdq_handle_trigger);
#endif
/*	disp_path_clock_off("External Display Path"); */
	pgc->state = 0;
done:
	_external_path_unlock();
	return ret;
}

int external_display_resume(void)
{
	DISP_STATUS ret = DISP_STATUS_OK;

	DISPFUNC();

	_external_path_lock();

	disp_path_clock_on("External Display Path");
	pgc->state = 1;
done:
	_external_path_unlock();
	return ret;
}

int external_display_is_alive(void)
{
	unsigned int temp = 0;
	DISPFUNC();
	_external_path_lock();
	temp = pgc->state;
	_external_path_unlock();

	return temp;
}
int external_display_is_sleepd(void)
{
	unsigned int temp = 0;
	DISPFUNC();
	_external_path_lock();
	temp = !pgc->state;
	_external_path_unlock();

	return temp;
}



int external_display_get_width(void)
{
	if (pgc->plcm == NULL) {
		pgc->plcm = disp_ext_lcm_probe(NULL, LCM_INTERFACE_NOTDEFINED);
		DISPMSG("lcm handle is null, after probe:0x%08x\n",pgc->plcm);
		if (pgc->plcm == NULL)
			return 0;
	}

	if (pgc->plcm->params) {
		return pgc->plcm->params->width;
	} else {
		DISPERR("lcm_params is null!\n");
		return 0;
	}
}

int external_display_get_height(void)
{
	if (pgc->plcm == NULL) {
		pgc->plcm = disp_ext_lcm_probe(NULL, LCM_INTERFACE_NOTDEFINED);
		DISPMSG("lcm handle is null, after probe:0x%08x\n",pgc->plcm);
		if (pgc->plcm == NULL)
			return 0;
	}

	if (pgc->plcm->params) {
		return pgc->plcm->params->height;
	} else {
		DISPERR("lcm_params is null!\n");
		return 0;
	}
}

int external_display_get_bpp(void)
{
	return 32;
}

int external_display_get_info(void *dispif_info)
{
#if 0
	memset((void*)dispif_info, 0, sizeof(mtk_dispif_info_t));

	switch (pgc->lcm_param->type) {
		case LCM_TYPE_DBI: {
			dispif_info->displayType = DISPIF_TYPE_DBI;
			dispif_info->displayMode = DISPIF_MODE_COMMAND;
			dispif_info->isHwVsyncAvailable = 1;
			DISPMSG("DISP Info: DBI, CMD Mode, HW Vsync enable\n");
			break;
		}
		case LCM_TYPE_DPI: {
			dispif_info->displayType = DISPIF_TYPE_DPI0;
			dispif_info->displayMode = DISPIF_MODE_VIDEO;
			dispif_info->isHwVsyncAvailable = 1;
			DISPMSG("DISP Info: DPI, VDO Mode, HW Vsync enable\n");
			break;
		}
		case LCM_TYPE_DSI: {
			dispif_info->displayType = DISPIF_TYPE_DSI0;
			if (pgc->lcm_param->dsi.mode == CMD_MODE) {
				dispif_info->displayMode = DISPIF_MODE_COMMAND;
				dispif_info->isHwVsyncAvailable = 1;
				DISPMSG("DISP Info: DSI, CMD Mode, HW Vsync enable\n");
			} else {
				dispif_info->displayMode = DISPIF_MODE_VIDEO;
				dispif_info->isHwVsyncAvailable = 1;
				DISPMSG("DISP Info: DSI, VDO Mode, HW Vsync enable\n");
			}

			break;
		}
		default:
			break;
	}

#ifdef MY_TODO
#error
	if (disp_if_drv->get_panel_color_format()) {
		switch (disp_if_drv->get_panel_color_format()) {
			case PANEL_COLOR_FORMAT_RGB565:
				dispif_info->displayFormat = DISPIF_FORMAT_RGB565;
			case PANEL_COLOR_FORMAT_RGB666:
				dispif_info->displayFormat = DISPIF_FORMAT_RGB666;
			case PANEL_COLOR_FORMAT_RGB888:
				dispif_info->displayFormat = DISPIF_FORMAT_RGB888;
			default:
				break;
		}
	}
#endif

	dispif_info->displayWidth = external_display_get_width();
	dispif_info->displayHeight = external_display_get_height();

#ifdef MY_TODO
#error
	dispif_info->vsyncFPS = lcd_fps;
#endif

	if (dispif_info->displayWidth * dispif_info->displayHeight <= 240*432) {
		dispif_info->physicalHeight= dispif_info->physicalWidth= 0;
	} else if (dispif_info->displayWidth * dispif_info->displayHeight <= 320*480) {
		dispif_info->physicalHeight= dispif_info->physicalWidth= 0;
	} else if (dispif_info->displayWidth * dispif_info->displayHeight <= 480*854) {
		dispif_info->physicalHeight= dispif_info->physicalWidth= 0;
	} else {
		dispif_info->physicalHeight= dispif_info->physicalWidth= 0;
	}

	dispif_info->isConnected = 1;

#ifdef MY_TODO
#error
	{
		LCM_PARAMS lcm_params_temp;
		memset((void*)&lcm_params_temp, 0, sizeof(lcm_params_temp));
		if (lcm_drv) {
			lcm_drv->get_params(&lcm_params_temp);
			dispif_info->lcmOriginalWidth = lcm_params_temp.width;
			dispif_info->lcmOriginalHeight = lcm_params_temp.height;
			DISPMSG("DISP Info: LCM Panel Original Resolution(For DFO Only): %d x %d\n", dispif_info->lcmOriginalWidth, dispif_info->lcmOriginalHeight);
		} else {
			DISPMSG("DISP Info: Fatal Error!!, lcm_drv is null\n");
		}
	}
#endif

#endif
	return 0;
}

int external_display_get_pages(void)
{
	return 3;
}

int external_display_config_output()
{
	return 0;
}
int external_display_diagnose(void)
{
	int ret = 0;
	dpmgr_check_status(pgc->dpmgr_handle);
	return ret;
}

int external_display_trigger(int blocking)
{
	int ret = 0;
	DISPFUNC();
	int x=0, y=0;
	int width = 0, height =0;
	x = disp_lcm_x(pgc->plcm);
	y = disp_lcm_y(pgc->plcm);
	width = disp_lcm_width(pgc->plcm);
	height = disp_lcm_height(pgc->plcm);

	_external_path_lock();
	if (pgc->mode == EXT_DIRECT_LINK_MODE || pgc->mode == EXT_SINGLE_LAYER_MODE) {
		if (dpmgr_path_is_busy(pgc->dpmgr_handle)) {
			if (external_display_is_video_mode()) {
				_external_path_unlock();
				return 0;
			}

			dpmgr_wait_event_timeout(pgc->dpmgr_handle, DISP_PATH_EVENT_FRAME_DONE, HZ*1);
		}
		DISPCHECK("trigger mode: %s\n", (pgc->mode == EXT_DIRECT_LINK_MODE)?"DIRECT_LINK":"SINGLE_LAYER");
		disp_lcm_update(pgc->plcm, x, y, width, height, 0);
		dpmgr_path_start(pgc->dpmgr_handle, external_display_use_cmdq);
		if (external_display_use_cmdq == CMDQ_DISABLE) {
			dpmgr_path_trigger(pgc->dpmgr_handle, NULL,external_display_use_cmdq);
		}

		//_set_cmdq_config_handle_dirty();
		//_reset_cmdq_config_handle();

		//if(blocking)
		{
			//dpmgr_wait_event_timeout(pgc->dpmgr_handle, DISP_PATH_EVENT_FRAME_DONE, HZ*2);
		}
	} else if (pgc->mode == EXT_DECOUPLE_MODE) {
		DISPCHECK("trigger mode: DECOUPLE\n");
		if (pgc->need_trigger_overlay) {
			dpmgr_path_trigger(pgc->ovl2mem_path_handle, NULL,external_display_use_cmdq);

			if (blocking) {
				dpmgr_wait_event_timeout(pgc->ovl2mem_path_handle, DISP_PATH_EVENT_FRAME_DONE, HZ*2);
			}
		} else {
			if (dpmgr_path_is_busy(pgc->dpmgr_handle) == 0) {
				// this request of trigger should be called by AAL or ovl2mem done event
				disp_lcm_update(pgc->plcm, x, y, width, height, 0);
				dpmgr_path_start(pgc->dpmgr_handle, external_display_use_cmdq);
			}

			_set_cmdq_config_handle_dirty();
			_reset_cmdq_config_handle();

			if (blocking) {
				dpmgr_wait_event_timeout(pgc->dpmgr_handle, DISP_PATH_EVENT_FRAME_DONE, HZ*2);
			}
		}
	} else if (pgc->mode == EXT_DEBUG_RDMA1_DSI1_MODE) {
		if (!external_display_is_video_mode() && dpmgr_path_is_busy(pgc->dpmgr_handle) == 0) {
			DISPCHECK("trigger mode: DEBUG_RDMA1_DSI0\n");
			disp_lcm_update(pgc->plcm, x, y, width, height, 0);
			dpmgr_path_start(pgc->dpmgr_handle, CMDQ_DISABLE);
			dpmgr_path_trigger(pgc->dpmgr_handle, NULL,external_display_use_cmdq);
		}

		if (blocking) {
			ret = dpmgr_wait_event_timeout(pgc->dpmgr_handle, DISP_PATH_EVENT_FRAME_DONE, HZ*5);
		}
	} else {
		DISPCHECK("external display mode is WRONG(%d)\n", (unsigned int)pgc->mode);
	}

	_external_path_unlock();
	//external_display_diagnose();
	return ret;
}

int external_display_config_input(disp_input_config* input)
{
	int ret = 0;
	int i=0;
	int layer =0;
	DISPFUNC();

	disp_ddp_path_config data_config;

	// all dirty should be cleared in dpmgr_path_get_last_config()
	memcpy((void*)&data_config, (void*)dpmgr_path_get_last_config(pgc->dpmgr_handle), sizeof(disp_ddp_path_config));

	// no need do this dirty = 0; dpmgr_path_get_last_config do this.
	data_config.dst_dirty = 0;
	data_config.ovl_dirty = 0;
	data_config.rdma_dirty = 0;
	data_config.wdma_dirty = 0;

	_external_path_lock();

	if (pgc->mode == EXT_DIRECT_LINK_MODE || pgc->mode == EXT_DECOUPLE_MODE) {
		if (dpmgr_path_is_busy(pgc->dpmgr_handle)) {
			if (external_display_is_video_mode()) {
				dpmgr_wait_event_timeout(pgc->dpmgr_handle, DISP_PATH_EVENT_FRAME_DONE, HZ*1);
			}
		}
		ret = _convert_disp_input_to_ovl(&(data_config.ovl_config[input->layer]), input);
		data_config.ovl_dirty = 1;
		ret = dpmgr_path_config(pgc->dpmgr_handle, &data_config, external_display_use_cmdq);

		// this is used for decouple mode, to indicate whether we need to trigger ovl
		pgc->need_trigger_overlay = 1;
	} else if (pgc->mode == EXT_SINGLE_LAYER_MODE) {
		ret = _convert_disp_input_to_rdma(&data_config.rdma_config, input);
		data_config.rdma_dirty= 1;
		ret = dpmgr_path_config(pgc->dpmgr_handle, &data_config, external_display_use_cmdq);
	} else if (pgc->mode == EXT_DEBUG_RDMA1_DSI1_MODE) {
		ret = _convert_disp_input_to_rdma(&(data_config.rdma_config), input);
		data_config.rdma_dirty= 1;
		if (external_display_is_video_mode() && dpmgr_path_is_busy(pgc->dpmgr_handle) == 1) {
			// TODO: should use wait_event_timeout_or_idle
			dpmgr_wait_event_timeout(pgc->dpmgr_handle, DISP_PATH_EVENT_FRAME_DONE, HZ*5);
		}
		ret = dpmgr_path_config(pgc->dpmgr_handle, &data_config, CMDQ_DISABLE);
	} else {
		DISPCHECK("external display mode is WRONG(%d)\n", (unsigned int)pgc->mode);
	}

	_external_path_unlock();

	return ret;
}

int external_display_is_video_mode(void)
{
	//we should store the video/cmd mode in runtime, because  will support cmd/vdo dynamic switch
	return disp_lcm_is_video_mode(pgc->plcm);
}

int external_display_get_vsync_interval(void)
{
	int ret = 0;
	unsigned int time0 = 0;
	unsigned int time1 = 0;
	unsigned int lcd_time = 0;

	pgc->plcm->is_connected = false;

	ret = dpmgr_wait_event_timeout(pgc->dpmgr_handle, DISP_PATH_EVENT_IF_VSYNC,1000);
	if (ret <= 0)
		goto fail;

	ret = dpmgr_wait_event_timeout(pgc->dpmgr_handle, DISP_PATH_EVENT_IF_VSYNC,1000);
	if (ret <= 0)
		goto fail;

	// because we are polling irq status, so the first event should be ignored
	time0 = gpt4_tick2time_us(gpt4_get_current_tick());
	//DISPMSG("vsync signaled:%d\n", gpt4_tick2time_us(gpt4_get_current_tick()));

	ret = dpmgr_wait_event_timeout(pgc->dpmgr_handle, DISP_PATH_EVENT_IF_VSYNC,1000);
	if (ret <= 0)
		goto fail;
	//DISPMSG("vsync signaled:%d\n", gpt4_tick2time_us(gpt4_get_current_tick()));

	ret = dpmgr_wait_event_timeout(pgc->dpmgr_handle, DISP_PATH_EVENT_IF_VSYNC,1000);
	if (ret > 0) {
		time1 = gpt4_tick2time_us(gpt4_get_current_tick());
	} else
		goto fail;

	lcd_time = (time1 - time0)/2;

	pgc->plcm->is_connected = true;

	if (0 != lcd_time)
		return (100000000/lcd_time);
	else
		return (6000);
fail:
	DISPERR("wait event fail\n");
	return 0;
}

int external_display_setbacklight(unsigned int level)
{
	DISPMSG("lk %s level=%d\n",__func__,level);
	int ret=0;
	if (pgc->dpmgr_handle == NULL) {
		DISPCHECK("lk set backlight early!\n");
		return 0;
	}
	if (dpmgr_path_is_busy(pgc->dpmgr_handle)) {
		DISPCHECK("external display path is busy\n");
		ret = dpmgr_wait_event_timeout(pgc->dpmgr_handle, DISP_PATH_EVENT_FRAME_DONE, HZ*1);
		DISPCHECK("wait frame done ret:%d\n", ret);
	}
	disp_lcm_set_backlight(pgc->plcm,level);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/***********************/
/*****Legacy DISP API*****/
/***********************/
UINT32 EXT_DISP_GetScreenWidth(void)
{
	return external_display_get_width();
}

UINT32 EXT_DISP_GetScreenHeight(void)
{
	return external_display_get_height();
}
UINT32 EXT_DISP_GetActiveHeight(void)
{
	if (pgc->plcm == NULL) {
		pgc->plcm = disp_ext_lcm_probe(NULL, LCM_INTERFACE_NOTDEFINED);
		DISPERR("lcm handle is null, after probe:0x%08x\n",pgc->plcm);
		if (pgc->plcm == NULL)return 0;
	}

	if (pgc->plcm->params) {
		return pgc->plcm->params->physical_height;
	} else {
		DISPERR("lcm_params is null!\n");
		return 0;
	}
}

UINT32 EXT_DISP_GetActiveWidth(void)
{
	if (pgc->plcm == NULL) {
		pgc->plcm = disp_ext_lcm_probe(NULL, LCM_INTERFACE_NOTDEFINED);
		DISPERR("lcm handle is null, after probe:0x%08x\n",pgc->plcm);
		if (pgc->plcm == NULL)return 0;
	}

	if (pgc->plcm->params) {
		return pgc->plcm->params->physical_width;
	} else {
		DISPERR("lcm_params is null!\n");
		return 0;
	}
}

int external_display_capture_framebuffer(unsigned int *pbuf)
{
	return 0;
}

UINT32 EXT_DISP_GetPanelBPP(void)
{
#if 0
	PANEL_COLOR_FORMAT fmt;
	disp_drv_init_context();

	if (disp_if_drv->get_panel_color_format == NULL) {
		return DISP_STATUS_NOT_IMPLEMENTED;
	}

	fmt = disp_if_drv->get_panel_color_format();
	switch (fmt) {
		case PANEL_COLOR_FORMAT_RGB332:
			return 8;
		case PANEL_COLOR_FORMAT_RGB444:
			return 12;
		case PANEL_COLOR_FORMAT_RGB565:
			return 16;
		case PANEL_COLOR_FORMAT_RGB666:
			return 18;
		case PANEL_COLOR_FORMAT_RGB888:
			return 24;
		default:
			return 0;
	}
#endif
	return 0;
}

UINT32 EXT_DISP_GetScreenBpp(void)
{
	return disp_fb_bpp;
}

UINT32 EXT_DISP_GetPages(void)
{
	return disp_fb_pages;   // Double Buffers
}

//  could we use the same header file between lk/kernel to avoid definition non-match issue?
#define DAL_BPP                 (2)
#define EXT_DAL_WIDTH           (EXT_DISP_GetScreenWidth())
#define EXT_DAL_HEIGHT          (EXT_DISP_GetScreenHeight())

UINT32 EXT_DAL_GetLayerSize(void)
{
	return EXT_DAL_WIDTH * EXT_DAL_HEIGHT * DAL_BPP + 4096;
}

UINT32 EXT_DISP_GetFBRamSize(void)
{
	return ALIGN_TO(EXT_DISP_GetScreenWidth(), MTK_FB_ALIGNMENT) * ALIGN_TO(EXT_DISP_GetScreenHeight(), MTK_FB_ALIGNMENT) * ((EXT_DISP_GetScreenBpp() + 7) >> 3) * EXT_DISP_GetPages();
}

unsigned int EXT_DISP_GetVRamSize(void)
{
	static UINT32 vramSize = 0;
	unsigned int fb_ram_size =0;
	//FB RAM(n blocks)+(Assert layer size)
	if (0 == vramSize) {
		vramSize = EXT_DISP_GetFBRamSize();
		DISPMSG("^^ DISP_GetFBRamSize: %u bytes\n", vramSize);
		fb_ram_size = vramSize;
		vramSize += EXT_DAL_GetLayerSize();
		DISPMSG("^^ DAL_GetLayerSize: %u bytes\n", vramSize-fb_ram_size);
#if 0
		if (g_is_64bit_kernel) {
			vramSize = ALIGN_TO(vramSize, 0x400000);  // both start addr and size needs 2MB align, so size must 4MB align
		} else {
			vramSize = ALIGN_TO(vramSize, 0x100000);  // both start addr and size needs 2MB align, so size must 4MB align
		}
#else
		vramSize = ALIGN_TO(vramSize, 0x10000);  // just align to 64KB is OK
#endif
		DISPMSG("^^ DISP_GetVRamSize: %u bytes\n", vramSize);
	}

	return vramSize;
}
