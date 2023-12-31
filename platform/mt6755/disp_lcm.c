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

#include "lcm_drv.h"
#include <platform/ddp_manager.h>
#include <platform/disp_lcm.h>
#include <platform/disp_drv_platform.h>
#include <platform/disp_drv_log.h>
#include <string.h>

// This macro and arrya is designed for multiple LCM support
// for multiple LCM, we should assign I/F Port id in lcm driver, such as DPI0, DSI0/1
static disp_lcm_handle _disp_lcm_driver[MAX_LCM_NUMBER] = {{NULL,NULL,0,0,0,0}};
static LCM_PARAMS _disp_lcm_params;
// these 2 variables are defined in mt65xx_lcm_list.c
extern LCM_DRIVER* lcm_driver_list[];
extern unsigned int lcm_count;

int _lcm_count(void)
{
	return lcm_count;
}

int _is_lcm_inited(disp_lcm_handle *plcm)
{
	if (plcm) {
		if (plcm->params && plcm->drv)
			return 1;
		else
			DISPCHECK("WARNING, uninit lcm params or drv\n");
	} else
		DISPERR("WARNING, invalid lcm handle: 0x%08x\n", (unsigned int)plcm);

	return 0;
}

LCM_PARAMS *_get_lcm_params_by_handle(disp_lcm_handle *plcm)
{
	if (plcm) {
		return plcm->params;
	} else {
		DISPERR("WARNING, invalid lcm handle: 0x%08x\n", (unsigned int)plcm);
		return NULL;
	}
}

LCM_DRIVER *_get_lcm_driver_by_handle(disp_lcm_handle *plcm)
{
	if (plcm) {
		return plcm->drv;
	} else {
		DISPERR("WARNING, invalid lcm handle: 0x%08x\n", (unsigned int)plcm);
		return NULL;
	}
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
		DISPERR("can't find primary path dst module\n");
		return DISP_MODULE_UNKNOWN;
	}
}


disp_path_handle _display_interface_path_init(disp_lcm_handle *plcm)
{
	DISP_MODULE_ENUM dst_module = DISP_MODULE_UNKNOWN;
	disp_ddp_path_config data_config;
	disp_path_handle handle = NULL;

	DISPFUNC();

	if (plcm == NULL) {
		DISPERR("plcm is null\n");
		return NULL;
	}

	handle = dpmgr_create_path(DDP_SCENARIO_DISPLAY_INTERFACE, NULL);
	if (handle) {
		DISPCHECK("dpmgr create path SUCCESS(0x%8p)\n", handle);
	} else {
		DISPCHECK("dpmgr create path FAIL\n");
		return NULL;
	}

	dst_module = _get_dst_module_by_lcm(plcm);
	dpmgr_path_set_dst_module(handle, dst_module);
	DISPCHECK("dpmgr set dst module FINISHED(%s)\n", ddp_get_module_name(dst_module));


	dpmgr_set_lcm_utils(handle, plcm->drv);
	dpmgr_path_init(handle, CMDQ_DISABLE);

	memset((void*)&data_config, 0, sizeof(disp_ddp_path_config));

	memcpy(&(data_config.dsi_config), &(plcm->params->dsi), sizeof(LCM_DSI_PARAMS));

	data_config.dst_w = plcm->params->width;
	data_config.dst_h = plcm->params->height;
	data_config.dst_dirty = 1;

	dpmgr_path_config(handle, &data_config, CMDQ_DISABLE);

	return handle;
}

int _display_interface_path_deinit(disp_path_handle handle)
{
	DISPFUNC();
	if (handle == NULL) {
		DISPERR("handle is null\n");
		return -1;
	}

	dpmgr_path_deinit(handle, CMDQ_DISABLE);
	dpmgr_destroy_path(handle);

	return 0;
}

void _dump_lcm_info(disp_lcm_handle *plcm)
{
	LCM_DRIVER *l = NULL;
	LCM_PARAMS *p = NULL;

	if (plcm == NULL) {
		DISPERR("plcm is null\n");
		return;
	}

	l = plcm->drv;
	p = plcm->params;

	DISPCHECK("******** dump lcm driver information ********\n");

	if (l && p) {
		DISPCHECK("[LCM], name: %s\n", l->name);

		DISPCHECK("[LCM] resolution: %d x %d\n", p->width, p->height);
		DISPCHECK("[LCM] physical size: %d x %d\n", p->physical_width, p->physical_height);
		DISPCHECK("[LCM] physical size: %d x %d\n", p->physical_width, p->physical_height);
		DISPCHECK("[LCM] lcm_if:%d, cmd_if:%d\n", p->lcm_if, p->lcm_cmd_if);
		switch (p->lcm_if) {
			case LCM_INTERFACE_DSI0:
				DISPCHECK("[LCM] interface: DSI0\n");
				break;
			case LCM_INTERFACE_DSI1:
				DISPCHECK("[LCM] interface: DSI1\n");
				break;
			case LCM_INTERFACE_DPI0:
				DISPCHECK("[LCM] interface: DPI0\n");
				break;
			case LCM_INTERFACE_DPI1:
				DISPCHECK("[LCM] interface: DPI1\n");
				break;
			case LCM_INTERFACE_DBI0:
				DISPCHECK("[LCM] interface: DBI0\n");
				break;
			default:
				DISPCHECK("[LCM] interface: unknown\n");
				break;
		}

		switch (p->type) {
			case LCM_TYPE_DBI:
				DISPCHECK("[LCM] Type: DBI\n");
				break;
			case LCM_TYPE_DSI:
				DISPCHECK("[LCM] Type: DSI\n");

				break;
			case LCM_TYPE_DPI:
				DISPCHECK("[LCM] Type: DPI\n");
				break;
			default:
				DISPCHECK("[LCM] TYPE: unknown\n");
				break;
		}

		if (p->type == LCM_TYPE_DSI) {
			switch (p->dsi.mode) {
				case CMD_MODE:
					DISPCHECK("[LCM] DSI Mode: CMD_MODE\n");
					break;
				case SYNC_PULSE_VDO_MODE:
					DISPCHECK("[LCM] DSI Mode: SYNC_PULSE_VDO_MODE\n");
					break;
				case SYNC_EVENT_VDO_MODE:
					DISPCHECK("[LCM] DSI Mode: SYNC_EVENT_VDO_MODE\n");
					break;
				case BURST_VDO_MODE:
					DISPCHECK("[LCM] DSI Mode: BURST_VDO_MODE\n");
					break;
				default:
					DISPCHECK("[LCM] DSI Mode: Unknown\n");
					break;
			}
		}

		if (p->type == LCM_TYPE_DSI) {
			DISPCHECK("[LCM] LANE_NUM: LANE_NUM: %d, FORMAT: %d \n",p->dsi.LANE_NUM,p->dsi.data_format.format);
#ifdef MY_TODO
#error
#endif
			DISPCHECK("[LCM] vact: %d, vbp: %d, vfp: %d, vact_line: %d, hact: %d, hbp: %d, hfp: %d, hblankpixel: %d\n",p->dsi.vertical_sync_active, p->dsi.vertical_backporch,p->dsi.vertical_frontporch,p->dsi.vertical_active_line,p->dsi.horizontal_sync_active,p->dsi.horizontal_backporch,p->dsi.horizontal_frontporch,p->dsi.horizontal_blanking_pixel);
			DISPCHECK("[LCM] pll_select: %d, pll_div1: %d, pll_div2: %d, fbk_div: %d,fbk_sel: %d, rg_bir: %d\n",p->dsi.pll_select,p->dsi.pll_div1,p->dsi.pll_div2,p->dsi.fbk_div,p->dsi.fbk_sel,p->dsi.rg_bir);
			DISPCHECK("[LCM] rg_bic: %d, rg_bp: %d,	PLL_CLOCK: %d, dsi_clock: %d, ssc_range: %d,	ssc_disable: %d, compatibility_for_nvk: %d, cont_clock: %d\n", p->dsi.rg_bic,  p->dsi.rg_bp,p->dsi.PLL_CLOCK,p->dsi.dsi_clock,p->dsi.ssc_range,p->dsi.ssc_disable,p->dsi.compatibility_for_nvk,p->dsi.cont_clock);
			DISPCHECK("[LCM] lcm_ext_te_enable: %d, noncont_clock: %d, noncont_clock_period: %d\n", p->dsi.lcm_ext_te_enable,p->dsi.noncont_clock,p->dsi.noncont_clock_period);
		}
	}

	return;
}

// TODO: remove this workaround!!!
extern UINT32 DSI_dcs_read_lcm_reg_v2(DISP_MODULE_ENUM module, void* cmdq, UINT8 cmd, UINT8 *buffer, UINT8 buffer_size);

// if lcm handle already probed, should return lcm handle directly
disp_lcm_handle* disp_lcm_probe(char* plcm_name, LCM_INTERFACE_ID lcm_id)
{
	DISPFUNC();

	bool isLCMFound = false;
	bool isLCMConnected = false;

	LCM_DRIVER *lcm_drv = NULL;
	LCM_PARAMS *lcm_param = NULL;
	disp_lcm_handle *plcm = NULL;

	if (_lcm_count() == 0) {
		DISPERR("no lcm driver defined in linux kernel driver\n");
		return NULL;
	} else if (_lcm_count() == 1) {
		lcm_drv = lcm_driver_list[0];

		isLCMFound = true;
	} else {
		// in lk, plcm_name should always be NULL
		if (plcm_name == NULL) {
			int i = 0;
			disp_path_handle handle = NULL;
			disp_lcm_handle hlcm;
			disp_lcm_handle *plcm = &hlcm;
			LCM_PARAMS hlcm_param;

			for (i=0; i<_lcm_count(); i++) {
				memset((void*)&hlcm, 0, sizeof(disp_lcm_handle));
				memset((void*)&hlcm_param, 0, sizeof(LCM_PARAMS));

				lcm_drv= lcm_driver_list[i];
				lcm_drv->get_params(&hlcm_param);
				plcm->drv = lcm_drv;
				plcm->params = &hlcm_param;
				plcm->lcm_if_id = plcm->params->lcm_if;
				DISPMSG("we will check lcm: %s\n", lcm_drv->name);
				if (lcm_id == LCM_INTERFACE_NOTDEFINED ||(lcm_id != LCM_INTERFACE_NOTDEFINED && plcm->lcm_if_id == lcm_id)) {
					handle = _display_interface_path_init(plcm);
					if (handle == NULL) {
						DISPERR("_display_interface_path_init returns NULL\n");
						goto FAIL;
					}

					if (lcm_drv->init_power) {
						lcm_drv->init_power();
					}

					if (lcm_drv->compare_id != NULL) {
						if (lcm_drv->compare_id() != 0) {
							isLCMFound = true;
							_display_interface_path_deinit(handle);
							dprintf(0,"we will use lcm: %s\n", lcm_drv->name);
							break;
						}
					}

					_display_interface_path_deinit(handle);
				}
			}

			if (isLCMFound == false) {
				DISPERR("we have checked all lcm driver, but no lcm found\n");
				lcm_drv = lcm_driver_list[0];
				isLCMFound = true;
			}
		} else {
			int i = 0;
			for (i=0; i<_lcm_count(); i++) {
				lcm_drv = lcm_driver_list[i];
				if (!strcmp(lcm_drv->name, plcm_name)) {
					isLCMFound = true;
					break;
				}
			}
		}
	}

	if (isLCMFound == false) {
		DISPERR("FATAL ERROR!!!No LCM Driver defined\n");
		return NULL;
	}

	plcm = &_disp_lcm_driver[0];
	lcm_param = &_disp_lcm_params;
	if (plcm && lcm_param) {
		plcm->params = lcm_param;
		plcm->drv = lcm_drv;
	} else {
		DISPERR("FATAL ERROR!!!kzalloc plcm and plcm->params failed\n");
		goto FAIL;
	}

	plcm->drv->get_params(plcm->params);
	plcm->lcm_if_id = plcm->params->lcm_if;
	// below code is for lcm driver forward compatible
	if (plcm->params->type == LCM_TYPE_DSI && plcm->params->lcm_if == LCM_INTERFACE_NOTDEFINED) plcm->lcm_if_id = LCM_INTERFACE_DSI0;
	if (plcm->params->type == LCM_TYPE_DPI && plcm->params->lcm_if == LCM_INTERFACE_NOTDEFINED) plcm->lcm_if_id = LCM_INTERFACE_DPI0;
	if (plcm->params->type == LCM_TYPE_DBI && plcm->params->lcm_if == LCM_INTERFACE_NOTDEFINED) plcm->lcm_if_id = LCM_INTERFACE_DBI0;
#if 1
	plcm->is_connected = isLCMConnected;
#endif

	_dump_lcm_info(plcm);
	return plcm;

FAIL:

	return NULL;
}

extern int ddp_dsi_dump(DISP_MODULE_ENUM module, int level);
extern int DSI_BIST_Pattern_Test(DISP_MODULE_ENUM module, void* cmdq, bool enable, unsigned int color);
extern int ddp_dsi_start(DISP_MODULE_ENUM module, cmdqRecHandle cmdq);

int disp_lcm_init(disp_lcm_handle *plcm)
{
	DISPFUNC();
	LCM_DRIVER *lcm_drv = NULL;
	bool isLCMConnected = false;

	if (_is_lcm_inited(plcm)) {
		lcm_drv = plcm->drv;

		if (lcm_drv->init_power) {
			DISPCHECK("lcm init_power \n");
			lcm_drv->init_power();
		}

		if (lcm_drv->init) {
			if (!disp_lcm_is_inited(plcm)) {
				DISPCHECK("lcm init \n");
				lcm_drv->init();
			}
		} else {
			DISPERR("FATAL ERROR, lcm_drv->init is null\n");
			return -1;
		}

#ifndef MACH_FPGA
		if (LCM_TYPE_DSI == plcm->params->type) {
			int ret = 0;
			char buffer = 0;

			ret = DSI_dcs_read_lcm_reg_v2(_get_dst_module_by_lcm(plcm), NULL, 0x0A, (UINT8 *)&buffer,1);
			if (ret == 0) {
				isLCMConnected = 0;
				DISPMSG("lcm is not connected\n");
			} else {
				isLCMConnected = 1;
				DISPMSG("lcm is connected\n");
			}
		}
		if (plcm->params->dsi.edp_panel == 1) {
			isLCMConnected = 1;
		}

#else
		isLCMConnected = 1;
#endif
		plcm->is_connected = isLCMConnected;

		//ddp_dsi_start(DISP_MODULE_DSI0, NULL);
		//DSI_BIST_Pattern_Test(DISP_MODULE_DSI0,NULL,true, 0x00ffff00);
		//ddp_dsi_dump(DISP_MODULE_DSI0, 2);
		return 0;
	} else {
		DISPERR("plcm is null\n");
		return -1;
	}
}

LCM_PARAMS* disp_lcm_get_params(disp_lcm_handle *plcm)
{
	DISPFUNC();

	if (_is_lcm_inited(plcm))
		return plcm->params;
	else
		return NULL;
}

const char* disp_lcm_get_name(disp_lcm_handle *plcm)
{
	DISPFUNC();

	if (_is_lcm_inited(plcm))
		return plcm->drv->name;
	else
		return NULL;
}

int disp_lcm_width(disp_lcm_handle *plcm)
{
	LCM_PARAMS *plcm_param = NULL;
	int w = 0;
	if (_is_lcm_inited(plcm))
		plcm_param = _get_lcm_params_by_handle(plcm);
	if (plcm_param == NULL) {
		DISPERR("plcm_param is null\n");
		return 0;
	}

	w = plcm_param->virtual_width;
	if (w == 0)
		w = plcm_param->width;

	return w;
}

int disp_lcm_height(disp_lcm_handle *plcm)
{
	LCM_PARAMS *plcm_param = NULL;
	int h = 0;
	if (_is_lcm_inited(plcm))
		plcm_param = _get_lcm_params_by_handle(plcm);
	if (plcm_param == NULL) {
		DISPERR("plcm_param is null\n");
		return 0;
	}

	h = plcm_param->virtual_height;
	if (h == 0)
		h = plcm_param->height;

	return h;
}

int disp_lcm_x(disp_lcm_handle *plcm)
{
	LCM_PARAMS *plcm_param = NULL;
	if (_is_lcm_inited(plcm))
		plcm_param = _get_lcm_params_by_handle(plcm);
	if (plcm_param == NULL) {
		DISPERR("plcm_param is null\n");
		return 0;
	}
	return plcm_param->lcm_x;
}

int disp_lcm_y(disp_lcm_handle *plcm)
{
	LCM_PARAMS *plcm_param = NULL;
	if (_is_lcm_inited(plcm))
		plcm_param = _get_lcm_params_by_handle(plcm);
	if (plcm_param == NULL) {
		DISPERR("plcm_param is null\n");
		return 0;
	}
	return plcm_param->lcm_y;
}


LCM_INTERFACE_ID disp_lcm_get_interface_id(disp_lcm_handle *plcm)
{
	DISPFUNC();

	if (_is_lcm_inited(plcm))
		return plcm->lcm_if_id;
	else
		return LCM_INTERFACE_NOTDEFINED;
}

int disp_lcm_update(disp_lcm_handle *plcm, int x, int y, int w, int h, int force)
{

	LCM_DRIVER *lcm_drv = NULL;

	if (_is_lcm_inited(plcm)) {
		DISPCHECK("(x=%d,y=%d),(w=%d,h=%d)\n",x,y,w,h);
		lcm_drv = plcm->drv;
		if (lcm_drv->update) {
			lcm_drv->update(x, y, w, h);
		} else {
			if (disp_lcm_is_video_mode(plcm)) {
				// do nothing
			} else {
				DISPERR("FATAL ERROR, lcm is cmd mode lcm_drv->update is null\n");
			}
			return -1;
		}

		return 0;
	} else {
		DISPERR("lcm_drv is null\n");
		return -1;
	}
}


int disp_lcm_esd_check(disp_lcm_handle *plcm)
{
	DISPFUNC();
	LCM_DRIVER *lcm_drv = NULL;

	if (_is_lcm_inited(plcm)) {
		lcm_drv = plcm->drv;
		if (lcm_drv->esd_check) {
			lcm_drv->esd_check();
		} else {
			DISPERR("FATAL ERROR, lcm_drv->esd_check is null\n");
			return -1;
		}

		return 0;
	} else {
		DISPERR("lcm_drv is null\n");
		return -1;
	}
}



int disp_lcm_esd_recover(disp_lcm_handle *plcm)
{
	DISPFUNC();
	LCM_DRIVER *lcm_drv = NULL;

	if (_is_lcm_inited(plcm)) {
		lcm_drv = plcm->drv;
		if (lcm_drv->esd_recover) {
			lcm_drv->esd_recover();
		} else {
			DISPERR("FATAL ERROR, lcm_drv->esd_check is null\n");
			return -1;
		}

		return 0;
	} else {
		DISPERR("lcm_drv is null\n");
		return -1;
	}
}

int disp_lcm_suspend(disp_lcm_handle *plcm)
{
	DISPFUNC();
	LCM_DRIVER *lcm_drv = NULL;

	if (_is_lcm_inited(plcm)) {
		lcm_drv = plcm->drv;
		if (lcm_drv->suspend) {
			lcm_drv->suspend();
		} else {
			DISPERR("FATAL ERROR, lcm_drv->suspend is null\n");
			return -1;
		}

		if (lcm_drv->suspend_power) {
			lcm_drv->suspend_power();
		}

		return 0;
	} else {
		DISPERR("lcm_drv is null\n");
		return -1;
	}
}

int disp_lcm_resume(disp_lcm_handle *plcm)
{
	DISPFUNC();
	LCM_DRIVER *lcm_drv = NULL;

	if (_is_lcm_inited(plcm)) {
		lcm_drv = plcm->drv;

		if (lcm_drv->resume_power) {
			lcm_drv->resume_power();
		}

		if (lcm_drv->resume) {
			lcm_drv->resume();
		} else {
			DISPERR("FATAL ERROR, lcm_drv->resume is null\n");
			return -1;
		}

		return 0;
	} else {
		DISPERR("lcm_drv is null\n");
		return -1;
	}
}



#ifdef MY_TODO
#error "maybe CABC can be moved into lcm_ioctl??"
#endif
int disp_lcm_set_backlight(disp_lcm_handle *plcm, int level)
{
	DISPFUNC();
	LCM_DRIVER *lcm_drv = NULL;

	if (_is_lcm_inited(plcm)) {
		lcm_drv = plcm->drv;
		if (lcm_drv->set_backlight) {
			lcm_drv->set_backlight(level);
		} else {
			DISPERR("FATAL ERROR, lcm_drv->esd_check is null\n");
			return -1;
		}

		return 0;
	} else {
		DISPERR("lcm_drv is null\n");
		return -1;
	}
}




int disp_lcm_ioctl(disp_lcm_handle *plcm, LCM_IOCTL ioctl, unsigned int arg)
{
	return 0;
}

int disp_lcm_is_inited(disp_lcm_handle *plcm)
{
	if (_is_lcm_inited(plcm))
		return plcm->is_inited;
	else
		return 0;
}

int disp_lcm_is_video_mode(disp_lcm_handle *plcm)
{
	DISPFUNC();
	LCM_PARAMS *lcm_param = NULL;

	if (_is_lcm_inited(plcm))
		lcm_param =  plcm->params;
	else
		ASSERT(0);

	switch (lcm_param->type) {
		case LCM_TYPE_DBI:
			return FALSE;
			break;
		case LCM_TYPE_DSI:
			break;
		case LCM_TYPE_DPI:
			return TRUE;
			break;
		default:
			DISPMSG("[LCM] TYPE: unknown\n");
			break;
	}

	if (lcm_param->type == LCM_TYPE_DSI) {
		switch (lcm_param->dsi.mode) {
			case CMD_MODE:
				DISPCHECK("LCM CMD_MODE\n");
				return FALSE;
				break;
			case SYNC_PULSE_VDO_MODE:
			case SYNC_EVENT_VDO_MODE:
			case BURST_VDO_MODE:
				DISPCHECK("LCM VDO_MODE %d\n",lcm_param->dsi.mode);
				return TRUE;
				break;
			default:
				DISPMSG("[LCM] DSI Mode: Unknown\n");
				break;
		}
	}

	ASSERT(0);
}

