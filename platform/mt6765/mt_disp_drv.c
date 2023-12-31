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

#include <string.h>
#include <stdlib.h>
#include <video_fb.h>
#include <libfdt.h>
#include <platform/disp_drv_platform.h>
#include <target/board.h>
#include <env.h>
#include "lcm_drv.h"
#include <platform/mt_gpt.h>
#include <platform/primary_display.h>
#include <arch/arm/mmu.h>
#include <platform/disp_drv_log.h>
#include <platform/mt_disp_drv.h>
#include "memory_layout.h"
#include <platform/boot_mode.h>
#include <pal_log.h>

//#define DFO_DISP
#define FB_LAYER            0
#ifndef MTK_ROUND_CORNER_SUPPORT
#define BOOT_MENU_LAYER     3
#else
#define BOOT_MENU_LAYER     1
#define TOP_LAYER	2
#define BOTTOM_LAYER	3
#endif

unsigned long long  fb_addr_pa_k    = 0;
static unsigned int fb_addr_pa      = 0;
static void  *fb_addr      = NULL;
static void  *logo_db_addr = NULL;
static void  *logo_db_addr_pa = NULL;
static UINT32 fb_size      = 0;
static UINT32 fb_offset_logo = 0; // counter of fb_size
static UINT32 fb_isdirty   = 0;
static UINT32 redoffset_32bit = 1; // ABGR

extern LCM_PARAMS *lcm_params;

extern void disp_log_enable(int enable);
extern void dbi_log_enable(int enable);
extern void * memset(void *,int,unsigned int);
extern void arch_clean_cache_range(addr_t start, size_t len);
extern UINT32 memory_size(void);

UINT32 mt_disp_get_vram_size(void)
{
	return DISP_GetVRamSize();
}


#ifdef DFO_DISP
static disp_dfo_item_t disp_dfo_setting[] = {
	{"LCM_FAKE_WIDTH",  0},
	{"LCM_FAKE_HEIGHT", 0},
	{"DISP_DEBUG_SWITCH",   0}
};

#define MT_DISP_DFO_DEBUG
#ifdef MT_DISP_DFO_DEBUG
#define disp_dfo_printf(string, args...) dprintf(INFO,"[DISP_DFO]"string, ##args)
#else
#define disp_dfo_printf(string, args...) ()
#endif

unsigned int mt_disp_parse_dfo_setting(void)
{
	unsigned int i, j=0 ;
	char tmp[11];
	char *buffer = NULL;
	char *ptr = NULL;

	buffer = (char *)get_env("DFO");
	disp_dfo_printf("env buffer = %s\n", buffer);

	if (buffer != NULL) {
		for (i = 0; i< (sizeof(disp_dfo_setting)/sizeof(disp_dfo_item_t)); i++) {
			j = 0;

			memset((void*)tmp, 0, sizeof(tmp)/sizeof(tmp[0]));

			ptr = strstr(buffer, disp_dfo_setting[i].name);

			if (ptr == NULL) continue;

			disp_dfo_printf("disp_dfo_setting[%d].name = [%s]\n", i, ptr);

			do {} while ((*ptr++) != ',');

			do {tmp[j++] = *ptr++;}
			while (*ptr != ',' && j < sizeof(tmp)/sizeof(tmp[0]));

			disp_dfo_setting[i].value = atoi((const char*)tmp);

			disp_dfo_printf("disp_dfo_setting[%d].name = [%s|%d]\n", i, tmp, disp_dfo_setting[i].value);
		}
	} else {
		disp_dfo_printf("env buffer = NULL\n");
	}

	return 0;
}


int mt_disp_get_dfo_setting(const char *string, unsigned int *value)
{
	char *disp_name;
	int  disp_value;
	unsigned int i = 0;

	if (string == NULL)
		return -1;

	for (i=0; i<(sizeof(disp_dfo_setting)/sizeof(disp_dfo_item_t)); i++) {
		disp_name = disp_dfo_setting[i].name;
		disp_value = disp_dfo_setting[i].value;
		if (!strcmp(disp_name, string)) {
			*value = disp_value;
			disp_dfo_printf("%s = [DEC]%d [HEX]0x%08x\n", disp_name, disp_value, disp_value);
			return 0;
		}
	}

	return 0;
}
#endif

static void _mtkfb_draw_block(unsigned int addr, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int color)
{
	unsigned int i = 0;
	unsigned int j = 0;
	void* start_addr = (void*)(addr+ALIGN_TO(CFG_DISPLAY_WIDTH, MTK_FB_ALIGNMENT)*4*y+x*4);
	unsigned int pitch = ALIGN_TO(CFG_DISPLAY_WIDTH, MTK_FB_ALIGNMENT)*4;
	unsigned int* line_addr = start_addr;

	for (j=0; j<h; j++) {
		line_addr = start_addr;
		for (i = 0; i<w; i++) {
			line_addr[i] = color;
		}
		start_addr += pitch;
	}
}

static int _mtkfb_internal_test(unsigned int va, unsigned int w, unsigned int h)
{
	/* this is for debug, used in bring up day */
	unsigned int i = 0;
	unsigned int color = 0;
	int _internal_test_block_size = 120;

	for (i = 0; i < w * h / _internal_test_block_size / _internal_test_block_size; i++) {
		color = (i & 0x1) * 0xff;
		color += 0xff000000U;
		_mtkfb_draw_block(va,
				  i % (w / _internal_test_block_size) * _internal_test_block_size,
				  i / (w / _internal_test_block_size) * _internal_test_block_size,
				  _internal_test_block_size, _internal_test_block_size, color);
	}

	/* primary_display_trigger(1); */
	mt_disp_update(0, 0, 0, 0);

	return 0;
}

static int _mtkfb_internal_test2()
{
	/* this is for debug, used in bring up day */
	unsigned int i = 0;
	unsigned int color;
	unsigned int bar_num=16;
	unsigned int bar_size;

	bar_size = fb_size / bar_num;

	for (i = 0; i < bar_num; i++) {
		color = i%2 ? 0 : 0xff;
		memset(fb_addr + i * bar_size, color, bar_size);
	}

	primary_display_trigger(1);

	return 0;
}

#ifdef MTK_ROUND_CORNER_SUPPORT
void load_image(void *dst, void *src, int h, int picture_w, int w)
{
	int i = 0;
	for (i = 0; i < h; i++)
		memcpy(dst+picture_w*i*2, src+2*w*i, w*2);
}

void assemble_image(void *dst, void *left, void *right, int h, int picture_w, int w)
{
	int i = 0;
	for (i = 0; i < h; i++) {
		memcpy(dst+picture_w*i*2, left+2*w*i, w*2);
		memcpy(dst+(picture_w*(i+1)-w)*2, right+2*w*i, w*2);
	}
}

int round_corner_init(unsigned int *top_pa, unsigned int *bottom_pa, LCM_ROUND_CORNER *rc_params)
{
	unsigned int h = rc_params->h;
	unsigned int w = rc_params->w;
	unsigned int h_bot = rc_params->h_bot;
	unsigned int w_bot = rc_params->w_bot;
	unsigned int pitch = DISP_GetScreenWidth();
	unsigned char *left_top = rc_params->lt_addr;
	unsigned char *left_bottom = rc_params->lb_addr;
	unsigned char *right_top = rc_params->rt_addr;
	unsigned char *right_bottom = rc_params->rb_addr;
	unsigned int buf_size = 0;
	unsigned int buf_size_bot = 0;

	static void *top_addr_va = NULL;
	static void *bottom_addr_va = NULL;

	if (rc_params->full_content) {
		if (h == 0 || w == 0 || h_bot == 0 || w_bot == 0 || left_top == NULL || left_bottom == NULL) {
			dprintf(CRITICAL, "the round corner params is invalid, please check the lcm config\n");
			return -1;
		}

		buf_size = h * pitch * 2;
		buf_size_bot = h_bot * pitch * 2;

		*bottom_pa = (unsigned int)(fb_addr_pa + DISP_GetVRamSize() - buf_size);
		bottom_addr_va = fb_addr + DISP_GetVRamSize() - buf_size;
		dprintf(INFO,"bottom_addr_va: 0x%08x, bottom_pa: 0x%08x\n", (unsigned int)bottom_addr_va, *bottom_pa);

		*top_pa = (unsigned int)(fb_addr_pa + DISP_GetVRamSize() - buf_size_bot - buf_size);
		top_addr_va = fb_addr + DISP_GetVRamSize() - buf_size_bot - buf_size;
		dprintf(INFO,"top_addr_va: 0x%08x, top_pa: 0x%08x\n", (unsigned int)top_addr_va, *top_pa);

		load_image((void *)top_addr_va, (void *)left_top, h, pitch, w);
		load_image((void *)bottom_addr_va, (void *)left_bottom, h_bot, pitch, w_bot);
	} else {
		if (h == 0 || w == 0 || left_top == NULL || left_bottom == NULL
			|| right_top == NULL || right_bottom == NULL) {
			dprintf(CRITICAL, "the round corner params is invalid, please check the lcm config\n");
			return -1;
		}

		buf_size = h * pitch * 2;
		*top_pa = (unsigned int)(fb_addr_pa + DISP_GetVRamSize() - 2 * buf_size);
		top_addr_va = fb_addr + DISP_GetVRamSize() - 2 * buf_size;
		dprintf(INFO,"top_addr_va: 0x%08x, top_pa: 0x%08x\n", (unsigned int)top_addr_va, *top_pa);

		*bottom_pa = (unsigned int)(fb_addr_pa + DISP_GetVRamSize() - buf_size);
		bottom_addr_va = fb_addr + DISP_GetVRamSize() - buf_size;
		dprintf(INFO,"bottom_addr_va: 0x%08x, bottom_pa: 0x%08x\n", (unsigned int)bottom_addr_va, *bottom_pa);

		assemble_image((void *)top_addr_va, (void *)left_top, (void *)right_top, h, pitch, w);
		assemble_image((void *)bottom_addr_va, (void *)left_bottom, (void *)right_bottom, h, pitch, w);
	}

	return 0;
}
#endif

void mt_disp_init(void *lcdbase)
{
#ifdef DFO_DISP
	unsigned int lcm_fake_width = 0;
	unsigned int lcm_fake_height = 0;
#endif
	UINT32 boot_mode_addr = 0;

#ifdef MTK_ROUND_CORNER_SUPPORT
	int ret = -1;
	unsigned int top_addr_pa = 0;
	unsigned int bottom_addr_pa = 0;
	LCM_ROUND_CORNER *round_corner = primary_display_get_corner_params();

	if (round_corner == NULL)
		return;
#endif
	/// fb base pa and va
	fb_addr_pa_k = arm_mmu_va2pa((unsigned int)lcdbase);

	fb_addr_pa = (unsigned int)(fb_addr_pa_k & 0xffffffffull);
	fb_addr      = lcdbase;

	dprintf(0,"fb_va: 0x%08x, fb_pa: 0x%08x, fb_pa_k: 0x%llx\n", (unsigned int)fb_addr, fb_addr_pa, (unsigned long long int)fb_addr_pa_k);

	fb_size = ALIGN_TO(CFG_DISPLAY_WIDTH, MTK_FB_ALIGNMENT) * ALIGN_TO(CFG_DISPLAY_HEIGHT, MTK_FB_ALIGNMENT) * CFG_DISPLAY_BPP / 8;
	// pa;
	boot_mode_addr = (fb_addr_pa + fb_size);

	logo_db_addr_pa = (void *)(u32)mblock_reserve_ext(&g_boot_arg->mblock_info,
		LK_LOGO_MAX_SIZE, PAGE_SIZE, 0x80000000, 0, "logo_db_addr_pa");

	if (!logo_db_addr_pa) {
		pal_log_err("Warning! logo_db_addr_pa is not taken from mb\n");
		assert(0);
	}

	// va;
	logo_db_addr = logo_db_addr_pa;

	fb_offset_logo = 0;

	primary_display_init(NULL);
	memset((void*)lcdbase, 0x0, DISP_GetVRamSize());

	disp_input_config input;

#ifdef MTK_ROUND_CORNER_SUPPORT
	if (round_corner->round_corner_en) {
		if (round_corner != NULL)
			ret = round_corner_init(&top_addr_pa, &bottom_addr_pa, round_corner);

		if (ret == 0) {
			memset(&input, 0, sizeof(input));
			input.layer     = TOP_LAYER;
			input.layer_en  = 1;
			input.fmt       = eRGBA4444;
			input.addr      = top_addr_pa;
			input.src_x     = 0;
			input.src_y     = 0;
			input.src_w     = CFG_DISPLAY_WIDTH;
			input.src_h     = round_corner->h;
			input.src_pitch = CFG_DISPLAY_WIDTH*2;
			input.dst_x     = 0;
			input.dst_y     = 0;
			input.dst_w     = CFG_DISPLAY_WIDTH;
			input.dst_h     = round_corner->h;
			input.aen       = 1;
			input.alpha     = 0xff;

			primary_display_config_input(&input);

			memset(&input, 0, sizeof(input));
			input.layer     = BOTTOM_LAYER;
			input.layer_en  = 1;
			input.fmt       = eRGBA4444;
			input.addr      = bottom_addr_pa;
			input.src_x     = 0;
			input.src_y     = 0;
			input.src_w     = CFG_DISPLAY_WIDTH;
			input.src_h     = round_corner->h;
			input.src_pitch = CFG_DISPLAY_WIDTH*2;
			input.dst_x     = 0;
			input.dst_y     = CFG_DISPLAY_HEIGHT-round_corner->h;
			input.dst_w     = CFG_DISPLAY_WIDTH;
			input.dst_h     = round_corner->h;
			input.aen       = 1;
			input.alpha     = 0xff;

			if (round_corner->full_content) {
				input.src_h     = round_corner->h_bot;
				input.dst_y     = CFG_DISPLAY_HEIGHT-round_corner->h_bot;
				input.dst_h     = round_corner->h_bot;
			}
			primary_display_config_input(&input);
		}
	}
#endif
	memset(&input, 0, sizeof(disp_input_config));
	input.layer     = BOOT_MENU_LAYER;
	input.layer_en  = 1;
	input.fmt       = redoffset_32bit ? eBGRA8888 : eRGBA8888;
	input.addr      = boot_mode_addr;
	input.src_x     = 0;
	input.src_y     = 0;
	input.src_w     = CFG_DISPLAY_WIDTH;
	input.src_h     = CFG_DISPLAY_HEIGHT;
	input.src_pitch = CFG_DISPLAY_WIDTH*4;
	input.dst_x     = 0;
	input.dst_y     = 0;
	input.dst_w     = CFG_DISPLAY_WIDTH;
	input.dst_h     = CFG_DISPLAY_HEIGHT;
	input.aen       = 1;
	input.alpha     = 0xff;

	primary_display_config_input(&input);

	memset(&input, 0, sizeof(disp_input_config));
	input.layer     = FB_LAYER;
	input.layer_en  = 1;
	input.fmt       = redoffset_32bit ? eBGRA8888 : eRGBA8888;
	input.addr      = fb_addr_pa;
	input.src_x     = 0;
	input.src_y     = 0;
	input.src_w     = CFG_DISPLAY_WIDTH;
	input.src_h     = CFG_DISPLAY_HEIGHT;
	input.src_pitch = ALIGN_TO(CFG_DISPLAY_WIDTH, MTK_FB_ALIGNMENT)*4;
	input.dst_x     = 0;
	input.dst_y     = 0;
	input.dst_w     = CFG_DISPLAY_WIDTH;
	input.dst_h     = CFG_DISPLAY_HEIGHT;

	input.aen       = 1;
	input.alpha     = 0xff;
	primary_display_config_input(&input);

#if 0
	/* debug for bringup */
	dprintf(CRITICAL, "display show background\n");
	mt_disp_update(0, 0, 0, 0);
	mdelay(100);
	primary_display_diagnose();

	while(0) {
		primary_display_trigger(TRUE);
		if (!primary_display_is_video_mode()) {
			/*video mode no need to wait*/
			dprintf(CRITICAL,"cmd mode trigger wait\n");
			mdelay(100);
		}
		primary_display_diagnose();
	}

	dprintf(CRITICAL, "display internal test\n");
	_mtkfb_internal_test(fb_addr, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
	mdelay(100);
	primary_display_diagnose();

#endif

#ifdef DFO_DISP
	mt_disp_parse_dfo_setting();

	if ((0 == mt_disp_get_dfo_setting("LCM_FAKE_WIDTH", &lcm_fake_width)) && (0 == mt_disp_get_dfo_setting("LCM_FAKE_HEIGHT", &lcm_fake_height))) {
		if (DISP_STATUS_OK != DISP_Change_LCM_Resolution(lcm_fake_width, lcm_fake_height)) {
			dprintf(INFO,"[DISP_DFO]WARNING!!! Change LCM Resolution FAILED!!!\n");
		}
	}
#endif
	DISPMSG("mt_disp_init() done\n");

}


void mt_disp_power(BOOL on)
{
	dprintf(0,"mt_disp_power %d\n",on);
	return;
}

void mt_free_logo_from_mblock(void)
{
	if (logo_db_addr_pa) {
		mblock_create(&g_boot_arg->mblock_info,
			&g_boot_arg->orig_dram_info,
			(u64)(unsigned long)logo_db_addr_pa, (u64)(LK_LOGO_MAX_SIZE));

		logo_db_addr_pa = NULL;
		logo_db_addr = NULL;
	}
}

void* mt_get_logo_db_addr(void)
{
	dprintf(0,"mt_get_logo_db_addr: 0x%08x\n",(unsigned int)logo_db_addr);
	return logo_db_addr;
}

void* mt_get_logo_db_addr_pa(void)
{
	dprintf(0,"mt_get_logo_db_addr_pa: 0x%08x\n",(unsigned int)logo_db_addr_pa);
	return logo_db_addr_pa;
}

void* mt_get_fb_addr(void)
{
	fb_isdirty = 1;
	return (void*)((UINT32)fb_addr + fb_offset_logo * fb_size);
}

void* mt_get_tempfb_addr(void)
{
	//use offset = 2 as tempfb for decompress logo
	dprintf(0,"mt_get_tempfb_addr: 0x%08x ,fb_addr 0x%08x\n",(unsigned int)((UINT32)fb_addr + 2*fb_size),(unsigned int)fb_addr);
	return (void*)((UINT32)fb_addr + 2*fb_size);
}

UINT32 mt_get_fb_size(void)
{
	return fb_size;
}


void mt_disp_update(UINT32 x, UINT32 y, UINT32 width, UINT32 height)
{

	unsigned int va = (unsigned int)fb_addr;
	dprintf(CRITICAL,"fb dump: 0x%08x, 0x%08x, 0x%08x, 0x%08x\n",
	        *(unsigned int*)va, *(unsigned int*)(va+4), *(unsigned int*)(va+8), *(unsigned int*)(va+0xC));

	arch_clean_cache_range((unsigned int)fb_addr, DISP_GetFBRamSize());
	primary_display_trigger(TRUE);
	if (!primary_display_is_video_mode()) {
		/*video mode no need to wait*/
		dprintf(CRITICAL,"cmd mode trigger wait\n");
		mdelay(30);
	}
}

static void mt_disp_adjusting_hardware_addr(void)
{
	dprintf(CRITICAL,"mt_disp_adjusting_hardware_addr fb_offset_logo = %d fb_size=%d\n",fb_offset_logo,fb_size);
	if (fb_offset_logo == 0) {
		mt_get_fb_addr();
		memcpy(fb_addr,(void *)((UINT32)fb_addr + 3 * fb_size),fb_size);
		mt_disp_update(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
	}
}

UINT32 mt_disp_get_lcd_time(void)
{
	static unsigned int fps = 0;

	if (!fps) {
		fps = primary_display_get_vsync_interval();

		dprintf(CRITICAL, "%s, fps=%d\n", __func__, fps);

		if (!fps)
			fps = 6000;
	}

	return fps;
}

int mt_disp_config_frame_buffer(void *fdt)
{
	extern unsigned int g_fb_base;
	extern unsigned int g_fb_size;
	unsigned int fb_base_h = 0;
	unsigned int fb_base_l = g_fb_base & 0xffffffff;
	int offset;
	int ret;

	fb_base_h = cpu_to_fdt32(fb_base_h);
	fb_base_l = cpu_to_fdt32(fb_base_l);
	g_fb_size = cpu_to_fdt32(g_fb_size);
	/* placed in the DT chosen node */
	offset = fdt_path_offset(fdt, "/chosen");
	if (offset < 0) {
		dprintf(CRITICAL, "can not find chosen node\n");
		return -1;
	}

	ret = fdt_setprop(fdt, offset, "atag,videolfb-fb_base_h", &fb_base_h, sizeof(fb_base_h));
	ret = fdt_setprop(fdt, offset, "atag,videolfb-fb_base_l", &fb_base_l, sizeof(fb_base_l));
	ret = fdt_setprop(fdt, offset, "atag,videolfb-vramSize", &g_fb_size, sizeof(g_fb_size));

	return ret;
}

// Attention: this api indicates whether the lcm is connected
int DISP_IsLcmFound(void)
{
	return primary_display_is_lcm_connected();
}

const char* mt_disp_get_lcm_id(void)
{
	return primary_display_get_lcm_name();
}


void disp_get_fb_address(UINT32 *fbVirAddr, UINT32 *fbPhysAddr)
{
	*fbVirAddr = (UINT32)fb_addr;
	*fbPhysAddr = (UINT32)fb_addr;
}

UINT32 mt_disp_get_redoffset_32bit(void)
{
	return redoffset_32bit;
}


// ---------------------------------------------------------------------------
//  Export Functions - Console
// ---------------------------------------------------------------------------

#ifdef CONFIG_CFB_CONSOLE
//  video_hw_init -- called by drv_video_init() for framebuffer console

void *video_hw_init (void)
{
	static GraphicDevice s_mt65xx_gd;

	memset(&s_mt65xx_gd, 0, sizeof(GraphicDevice));

	s_mt65xx_gd.frameAdrs  = (UINT32)fb_addr+fb_size;
	s_mt65xx_gd.winSizeX   = CFG_DISPLAY_WIDTH;
	s_mt65xx_gd.winSizeY   = CFG_DISPLAY_HEIGHT;
	s_mt65xx_gd.gdfIndex   = CFB_X888RGB_32BIT;
	dprintf(0, "s_mt65xx_gd.gdfIndex=%d", s_mt65xx_gd.gdfIndex);
	s_mt65xx_gd.gdfBytesPP = CFG_DISPLAY_BPP / 8;
	s_mt65xx_gd.memSize    = s_mt65xx_gd.winSizeX * s_mt65xx_gd.winSizeY * s_mt65xx_gd.gdfBytesPP;

	return &s_mt65xx_gd;
}


void video_set_lut(unsigned int index,  /* color number */
                   unsigned char r,     /* red */
                   unsigned char g,     /* green */
                   unsigned char b)     /* blue */
{
	dprintf(CRITICAL, "%s\n", __func__);

}

#endif  // CONFIG_CFB_CONSOLE
