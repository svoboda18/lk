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

#include <platform/mt_typedefs.h>
#include <platform/mt_disp_drv.h>
#include <platform/disp_drv.h>
#include <platform/primary_display.h>
#include <platform/mt_logo.h>
#include <platform/disp_drv_platform.h>
#include <env.h>

#include <target/board.h>
#include "lcm_drv.h"

#include <string.h>
#include <stdlib.h>

/* show logo header file */
#include <show_logo_common.h>
#include <decompress_common.h>
#include <show_animation_common.h>

/* Operator number */
#define OPTR_NUM_OP01   1
#define OPTR_NUM_OP02   2
#define OPTR_NUM_OP09   9

/* Count of logos for different charging animations */
#define LOGOS_COUNT_NORMAL_CHARGING_ANIM        38
#define LOGOS_COUNT_FAST_CHARGING_ANIM          18
#define LOGOS_COUNT_WIRELESS_CHARGING_ANIM      29

#define MAX_OPERATOR_SUPPORT    5

LCM_SCREEN_T phical_screen;
void  *logo_addr = NULL;

static LOGO_CUST_IF *logo_cust_if = NULL;

/*
 * Get default operator.
 *
 */

#if defined(MTK_CARRIEREXPRESS_PACK)

#ifdef GLOBAL_DEVICE_DEFAULT_OPTR
static int get_default_operator()
{
	/* Hardcoded values represent operator number. For example,1 means OP01, 2 means OP02.... n means OP0N. */
#if GLOBAL_DEVICE_DEFAULT_OPTR == OPTR_NUM_OP01
	return OPTR_NUM_OP01;
#elif GLOBAL_DEVICE_DEFAULT_OPTR == OPTR_NUM_OP02
	return OPTR_NUM_OP02;
#elif GLOBAL_DEVICE_DEFAULT_OPTR == OPTR_NUM_OP09
	return OPTR_NUM_OP09;
#else
	return 0;
#endif
}
#endif


/*
 * get Logo index when the global device feature is enabled.
 *
 */
static int get_logo_index()
{
	int logo_index = 0;
	int optrs[MAX_OPERATOR_SUPPORT];
	char* active_optr = NULL;
	int i = 0, j = 0, optr_index = -1, optr_number = -1;

#if defined(MTK_CARRIEREXPRESS_PACK_OP01)
	optrs[i++] = OPTR_NUM_OP01;
#endif

#if defined(MTK_CARRIEREXPRESS_PACK_OP02)
	optrs[i++] = OPTR_NUM_OP02;
#endif

#if defined(MTK_CARRIEREXPRESS_PACK_OP09)
	optrs[i++] = OPTR_NUM_OP09;
#endif

	dprintf(INFO, "[lk logo: get_logo_index() - Optr Count: %d]\n",i);

	logo_index = 1; // this is for OM LK logo.
#if !defined(MTK_ALPS_BOX_SUPPORT)
	logo_index += LOGOS_COUNT_NORMAL_CHARGING_ANIM;
#endif
#if defined(MTK_PUMP_EXPRESS_SUPPORT) || defined(MTK_PUMP_EXPRESS_PLUS_SUPPORT)
	logo_index += LOGOS_COUNT_FAST_CHARGING_ANIM;
#endif
#if defined(MTK_WIRELESS_CHARGER_SUPPORT)
	logo_index += LOGOS_COUNT_WIRELESS_CHARGING_ANIM;
#endif

	// sysenv read property.
	active_optr = (char *)get_env("mtk_usp_operator");
	if (active_optr == NULL) {
#if !defined(GLOBAL_DEVICE_DEFAULT_OPTR)
		dprintf(INFO, "[lk logo: get_logo_index() - Show OM]\n");
		return 0;
#else
		dprintf(INFO, "[lk logo: get_logo_index() - Default Operator]\n");
		optr_number = get_default_operator();
#endif
	} else {
		dprintf(INFO, "[lk logo: get_logo_index() - Active Optr Number : %d]\n",atoi(active_optr));
		optr_number = atoi(active_optr);
	}

	for (j = 0; j < i && j < MAX_OPERATOR_SUPPORT; j++) {
		if (optrs[j] == optr_number) {
			dprintf(INFO, "[lk logo: get_logo_index() - Active Optr Index : %d]\n",j);
			optr_index = j;
			break;
		}
	}

	if (optr_index == -1) {
		dprintf(INFO, "[lk logo: get_logo_index() - Operator not present in region : %d]\n",optr_number);
		return 0; //show OM
	}

	dprintf(INFO, "[lk logo: get_logo_index() - Logo index without Optr : %d]\n",logo_index);
	logo_index = logo_index + optr_index*2;  // calculate the LK Logo index#endif
	dprintf(INFO, "[lk logo: get_logo_index() - Logo index with Optr : %d]\n",logo_index);

	return logo_index;
}
#endif

/********** show_animationm_ver:  charging animation version  ************/
/*                                                                       */
/* version 0: show 4 recatangle growing animation without battery number */
/* version 1: show wave animation with  battery number                   */
/*                                                                       */
/***                                                                   ***/

int show_animationm_ver = 0;


/*
 * Get the defined charging animation version
 *
 */
void sync_anim_version()
{
	dprintf(INFO, "[lk logo: %s %d]\n",__FUNCTION__,__LINE__);

#ifdef ANIMATION_NEW
	show_animationm_ver = 1 ;
#else
	show_animationm_ver = 0 ;
	dprintf(INFO, "[lk logo %s %d]not define ANIMATION_NEW:show old animation \n",__FUNCTION__,__LINE__);
#endif

}

/*
 * Initliaze charging animation parameters
 *
 */
void init_fb_screen()
{
	dprintf(INFO, "[lk logo: %s %d]\n",__FUNCTION__,__LINE__);
	unsigned int fb_size = mt_get_fb_size();
	logo_addr = mt_get_logo_db_addr();

	phical_screen.width = CFG_DISPLAY_WIDTH;
	phical_screen.height = CFG_DISPLAY_HEIGHT;
	phical_screen.fb_size = fb_size;
	phical_screen.fill_dst_bits = CFG_DISPLAY_BPP;
	phical_screen.bits_per_pixel = CFG_DISPLAY_BPP;

	// in JB2.MP need to allign width and height to 32 ,but jb5.mp needn't
	phical_screen.needAllign = 1;
	phical_screen.allignWidth = ALIGN_TO(CFG_DISPLAY_WIDTH, MTK_FB_ALIGNMENT);

	/* In GB, no need to adjust 180 showing logo ,for fb driver dealing the change */
	/* but in JB, need adjust it for screen 180 roration           */
	phical_screen.need180Adjust = 0;   // need sync with chip driver

	dprintf(INFO, "[lk logo: %s %d]MTK_LCM_PHYSICAL_ROTATION = %s\n",__FUNCTION__,__LINE__, MTK_LCM_PHYSICAL_ROTATION);

	if (0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "270", 3)) {
		phical_screen.rotation = 270;
	} else if (0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "90", 2)) {
		phical_screen.rotation = 90;
	} else if (0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "180", 3) && (phical_screen.need180Adjust == 1)) {
		phical_screen.rotation = 180;
	} else {
		phical_screen.rotation = 0;
	}

	sync_anim_version();
	if (show_animationm_ver == 1) {
		unsigned int logonum;
		unsigned int *db_addr = logo_addr;

		unsigned int *pinfo = (unsigned int*)db_addr;

		logonum = pinfo[0];
		dprintf(INFO, "[lk logo: %s %d]pinfo[0]=0x%08x, pinfo[1]=0x%08x, pinfo[2]=%d\n", __FUNCTION__,__LINE__,
		        pinfo[0], pinfo[1], pinfo[2]);

		dprintf(INFO, "[lk logo: %s %d]define ANIMATION_NEW:show new animation with capacity num\n",__FUNCTION__,__LINE__);
		dprintf(INFO, "[lk logo: %s %d]CAPACITY_LEFT =%d, CAPACITY_TOP =%d \n",__FUNCTION__,__LINE__,(CAPACITY_LEFT) ,(CAPACITY_TOP) );
		dprintf(INFO, "[lk logo: %s %d]LCM_HEIGHT=%d, LCM_WIDTH=%d \n",__FUNCTION__,__LINE__,(CAPACITY_RIGHT),(CAPACITY_BOTTOM));
		if (logonum < 6) {
			show_animationm_ver = 0 ;
		} else {
			show_animationm_ver = 1 ;
		}
	}

}


/*
 * Custom interface
 *
 */
void mt_logo_get_custom_if(void)
{
	if (logo_cust_if == NULL) {
		logo_cust_if = (LOGO_CUST_IF *)LOGO_GetCustomIF();
	}
}


/*
 * Show first boot logo when phone boot up
 *
 */
void mt_disp_show_boot_logo(void)
{
	int logo_index = 0;
	dprintf(INFO, "[lk logo: %s %d]\n",__FUNCTION__,__LINE__);
	mt_logo_get_custom_if();

#if defined(MTK_CARRIEREXPRESS_PACK)
#if 0   // test
	test = (char *)get_env("VAIBHAV");
	if (test == NULL) {
		dprintf(INFO, "[lk logo: SysEnv is not set]\n");
		if (set_env("VAIBHAV","5") == 0) {
			dprintf(INFO, "[lk logo: SysEnv set to 5 Succesfully]\n");
			x = 1;
		} else {
			dprintf(INFO, "[lk logo: SysEnv set fails!!!]\n");
			return;
		}
	} else {
		dprintf(INFO, "[lk logo: SysEnv already set to %d]\n",atoi(test));
	}
#endif
	logo_index = get_logo_index();
	/*if(x == 1){
	    logo_index = 0;
	    dprintf(INFO, "[lk logo: First Boot So show OM logo]\n");
	}*/
	dprintf(INFO, "[lk logo: Final logo_index: %d]\n",logo_index);
#endif

	if (logo_cust_if->show_boot_logo) {
		logo_cust_if->show_boot_logo();
	} else {
		///show_logo(0);
		init_fb_screen();
		fill_animation_logo(logo_index, mt_get_fb_addr(), mt_get_tempfb_addr(), logo_addr, phical_screen);
		mt_disp_update(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
	}

	return;
}

/*
 * Custom interface : charging state
 *
 */
void mt_disp_enter_charging_state(void)
{
	mt_logo_get_custom_if();

	if (logo_cust_if->enter_charging_state) {
		logo_cust_if->enter_charging_state();
	} else {
		dprintf(INFO, "[lk logo: %s %d]do nothing \n",__FUNCTION__,__LINE__);
	}

	return;
}


/*
 * Show full battery when poweroff charging
 *
 */
void mt_disp_show_battery_full(void)
{
	dprintf(INFO, "[lk logo: %s %d]\n",__FUNCTION__,__LINE__);
	mt_disp_show_battery_capacity(100);
}


/*
 * Show animation when poweroff charging
 *
 */
void mt_disp_show_battery_capacity(UINT32 capacity)
{
	dprintf(INFO, "[lk logo: %s %d]capacity =%d\n",__FUNCTION__,__LINE__, capacity);
	mt_logo_get_custom_if();

	if (logo_cust_if->show_battery_capacity) {
		logo_cust_if->show_battery_capacity(capacity);
	} else {
		init_fb_screen();

		fill_animation_battery_by_ver(capacity, mt_get_fb_addr(), mt_get_tempfb_addr(), logo_addr, phical_screen, show_animationm_ver);

		mt_disp_update(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
	}

}

/*
 * Show charging over logo
 *
 */
void mt_disp_show_charger_ov_logo(void)
{
	dprintf(INFO, "[lk logo: %s %d]\n",__FUNCTION__,__LINE__);
	mt_logo_get_custom_if();

	if (logo_cust_if->show_boot_logo) {
		logo_cust_if->show_boot_logo();
	} else {
		init_fb_screen();
		fill_animation_logo(CHARGER_OV_INDEX, mt_get_fb_addr(), mt_get_tempfb_addr(), logo_addr, phical_screen);
		mt_disp_update(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
	}

	return;
}

/*
 * Show low battery logo
 *
 */
void mt_disp_show_low_battery(void)
{
	dprintf(INFO, "[lk logo: %s %d]\n",__FUNCTION__,__LINE__);
	mt_logo_get_custom_if();

	if (logo_cust_if->show_boot_logo) {
		logo_cust_if->show_boot_logo();
	} else {
		init_fb_screen();
		//show_logo(2);
		fill_animation_logo(LOW_BATTERY_INDEX, mt_get_fb_addr(), mt_get_tempfb_addr(), logo_addr, phical_screen);
		mt_disp_update(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
	}

	return;
}


/*
 * Fill rectangle region for with black  or other color
 *
 */
void mt_disp_fill_rect(UINT32 left, UINT32 top,
                       UINT32 right, UINT32 bottom,
                       UINT32 color)
{
	dprintf(INFO, "[lk logo: %s %d]\n",__FUNCTION__,__LINE__);
	init_fb_screen();
	RECT_REGION_T rect = {left, top, right, bottom};

	fill_rect_with_color(mt_get_fb_addr(), rect, color, phical_screen);
}

