/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2016. All rights reserved.
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
 * THAT IT IS RECEIVER\'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER\'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER\'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK\'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK\'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
 * applicable license agreements with MediaTek Inc.
 */

#include <string.h>
#include <printf.h>
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

/* ////////////////////////////////macro///////////////////////////////////////////////////////////////// */
/* COLOR Format */
#define FC_5B         (CS_FG_COL >> 3)
#define FC_6B         (CS_FG_COL >> 2)
#define BC_5B         (CS_BG_COL >> 3)
#define BC_6B         (CS_BG_COL >> 2)

#define DR_TB_0 0x00000000
#define DR_TB_1 0x000000ff
#define DR_TB_3 0x0000ffff
#define DR_TB_7 0x00ffffff
#define DR_TB_8 0xff000000
#define DR_TB_C 0xffff0000
#define DR_TB_E 0xffffff00
#define DR_TB_F 0xffffffff


#include <video_font.h>
#include <video_fb.h>
#include <target/board.h>
#include <stdarg.h>

#define SIZE_X           (pGD->winSizeX)
#define SIZE_Y           (pGD->winSizeY)
#define DATA_FMT         (pGD->gdfIndex)
#define PIXEL_SIZE       (pGD->gdfBytesPP)
#define VDO_CFB_SIZE     (pGD->memSize)
#define VDO_CFB_ADDRS    (pGD->frameAdrs)


#include <platform/mt_disp_drv.h>


#define CFB_HEIGHT  0
#define CFB_WIDTH   0

#define VDO_COLS            SIZE_X
#define VDO_ROWS            SIZE_Y
#define VDO_SIZE            (PIXEL_SIZE*VDO_COLS*VDO_ROWS)
#define LINE_LEN            (PIXEL_SIZE*VDO_COLS)

static unsigned long g_cfb[2];

#define FONT_HEIGHT         (MTK_VFH)
#define CFB_ROW             g_cfb[0]
#define FONT_WIDTH          (MTK_VFW)
#define CFB_COL             g_cfb[1]
#define CFB_ROW_SIZE        (FONT_HEIGHT * LINE_LEN)
#define CFB_SIZE            (CFB_ROW * CFB_ROW_SIZE)
#define CFB_SCROLL_SIZE     (CFB_SIZE - CFB_ROW_SIZE)

#ifdef CFB_LIT_END
#define SWAP16(x)    ((((x) & 0x00ff) << 8) | ((x) >> 8))
#define SHTSWAP32(x)     ((((x) & 0x000000ff) <<  8) | (((x) & 0x0000ff00) >> 8)|\
	      (((x) & 0x00ff0000) <<  8) | (((x) & 0xff000000) >> 8))

#define SWAP32(x)    ((((x) & 0x000000ff) << 24) | (((x) & 0x0000ff00) << 8)|\
		  (((x) & 0x00ff0000) >>  8) | (((x) & 0xff000000) >> 24))

#else
#define SWAP16(x)        (x)
#define SWAP32(x)        (x)
#define SWAP32_16(x)     ((((x) & 0x0000ffff) << 16) | (((x) & 0xffff0000) >> 16))
#define SHTSWAP32(x)     (x)
#endif

/* /////////local variable//////////////////////////////////////////////////////// */
static GraphicDevice *pGD;	/* Pointer-to-Graphic-array */
static void *cfb_buf_addrs;	/* console-buffer-start-address / */
static void *cfb_fb_addrs;	/* frame-buffer-address */
static int cfb_rows;
static int cfb_cols;
/* color pats */
static unsigned int cfb_eorx;
static unsigned int cfb_bgx;
static unsigned int cfb_fgx;
static unsigned int cfb_bg_alpha;
static unsigned int cfb_fg_alpha;
static unsigned int cfb_eorx_default;
static unsigned int cfb_fgx_default;
static unsigned int cfb_bgx_default;
// pixe coordinate
static unsigned int cfb_pixel_position_x;
static unsigned int cfb_pixel_position_y;

static int vdo_fb_height = CFB_HEIGHT;
extern UINT32 DISP_GetScreenHeight(void);
extern UINT32 DISP_GetScreenWidth(void);

void video_set_bgfg_colors(unsigned bg, unsigned fg);
void video_clean_screen_by_bg(void);
void video_set_position(int x, int y);
void video_disp_string(char *str);
void video_set_bold(int id);
void video_display_image(const unsigned int data[],
		unsigned int xpos, unsigned int ypos, unsigned int width, unsigned int height);
void video_clear_image_by_color(const unsigned int data,
		unsigned int xpos, unsigned int ypos, unsigned int width, unsigned int height);
//pixel position
void fbcon_set_position(unsigned int x, unsigned int y );
void fbcon_get_position(unsigned int *x, unsigned int *y);

/* Disrupted defined sequence */
static const int lk_cfb_font_dtb24[16][3] = {
	{DR_TB_0, DR_TB_0, DR_TB_0},
	{DR_TB_0, DR_TB_0, DR_TB_7},
	{DR_TB_0, DR_TB_3, DR_TB_8},
	{DR_TB_0, DR_TB_3, DR_TB_F},
	{DR_TB_1, DR_TB_C, DR_TB_0},
	{DR_TB_1, DR_TB_C, DR_TB_7},
	{DR_TB_1, DR_TB_F, DR_TB_8},
	{DR_TB_1, DR_TB_F, DR_TB_F},
	{DR_TB_E, DR_TB_0, DR_TB_0},
	{DR_TB_E, DR_TB_0, DR_TB_7},
	{DR_TB_E, DR_TB_3, DR_TB_8},
	{DR_TB_E, DR_TB_3, DR_TB_F},
	{DR_TB_F, DR_TB_C, DR_TB_0},
	{DR_TB_F, DR_TB_C, DR_TB_7},
	{DR_TB_F, DR_TB_F, DR_TB_8},
	{DR_TB_F, DR_TB_F, DR_TB_F}
};

static const int lk_cfb_font_dtable32[16][4] = {
	{DR_TB_0, DR_TB_0, DR_TB_0, DR_TB_0},
	{DR_TB_0, DR_TB_0, DR_TB_0, DR_TB_7},
	{DR_TB_0, DR_TB_0, DR_TB_7, DR_TB_0},
	{DR_TB_0, DR_TB_0, DR_TB_7, DR_TB_7},
	{DR_TB_0, DR_TB_7, DR_TB_0, DR_TB_0},
	{DR_TB_0, DR_TB_7, DR_TB_0, DR_TB_7},
	{DR_TB_0, DR_TB_7, DR_TB_7, DR_TB_0},
	{DR_TB_0, DR_TB_7, DR_TB_7, DR_TB_7},
	{DR_TB_7, DR_TB_0, DR_TB_0, DR_TB_0},
	{DR_TB_7, DR_TB_0, DR_TB_0, DR_TB_7},
	{DR_TB_7, DR_TB_0, DR_TB_7, DR_TB_0},
	{DR_TB_7, DR_TB_0, DR_TB_7, DR_TB_7},
	{DR_TB_7, DR_TB_7, DR_TB_0, DR_TB_0},
	{DR_TB_7, DR_TB_7, DR_TB_0, DR_TB_7},
	{DR_TB_7, DR_TB_7, DR_TB_7, DR_TB_0},
	{DR_TB_7, DR_TB_7, DR_TB_7, DR_TB_7}
};

static const int lk_cfb_font_dtable16[] = {
#if 0
	0x00000000, 0x0000ffff, 0xffff0000, 0xffffffff
};
#else				/* Jett Patch: RGB565 with Little Endian Table */
	0x00000000, 0xffff0000, 0x0000ffff, 0xffffffff
};
#endif

static const int lk_cfb_font_dtable15[] = {
	0x00000000, 0x00007fff, 0x7fff0000, 0x7fff7fff
};


static const int lk_cfb_font_dtable8[] = {
	0x00000000, 0x000000ff, 0x0000ff00, 0x0000ffff,
	0x00ff0000, 0x00ff00ff, 0x00ffff00, 0x00ffffff,
	0xff000000, 0xff0000ff, 0xff00ff00, 0xff00ffff,
	0xffff0000, 0xffff00ff, 0xffffff00, 0xffffffff
};

static void cfb_memset(int *cfb_p, int cfb_c, int cfb_v)
{
	while (cfb_c--) {
		*cfb_p = cfb_v;
		++cfb_p;
	}
}

static void cfb_memcpy(int *cfb_d, int *cfb_s, int cfb_c)
{
	while (cfb_c--) {
		*cfb_d = *cfb_s;
		++cfb_d;
		++cfb_s;
	}
}

static int get_cols(void)
{
	return cfb_cols;
}

static void set_cols(int value)
{
	cfb_cols = value;
}

static void inc_cols(int value)
{
	cfb_cols += value;
}

static int get_rows(void)
{
	return cfb_rows;
}

static void set_rows(int value)
{
	cfb_rows = value;
}

static void inc_rows(int value)
{
	cfb_rows += value;
}

static void cfb_lk_dchars(int xx, int yy, unsigned char *s, int count)
{
	unsigned char *pos = NULL;
	unsigned char *tdest = NULL;
	unsigned char *pdest = NULL;
	unsigned char *pfont = NULL;
	int row = 0;
	unsigned int data_fmt = 0;
	int offs = 0;

	pdest = cfb_fb_addrs + yy * LINE_LEN + xx * PIXEL_SIZE;
	data_fmt = DATA_FMT;

	pfont = mtk_vdo_fntdata;

	switch (data_fmt) {

	case CFB_555RGB_15BIT:
		while (count--) {
			offs = (*s++) * MTK_VFH;
			pos = pfont + offs;
			row = MTK_VFH;
			for (tdest = pdest; row--; tdest += LINE_LEN) {
				unsigned char bits = *pos++;
				((unsigned int *)tdest)[0] =
				    SHTSWAP32((lk_cfb_font_dtable15[bits >> 6] & cfb_eorx) ^
					      cfb_bgx);
				((unsigned int *)tdest)[1] =
				    SHTSWAP32((lk_cfb_font_dtable15[bits >> 4 & 3] & cfb_eorx) ^
					      cfb_bgx);
				((unsigned int *)tdest)[2] =
				    SHTSWAP32((lk_cfb_font_dtable15[bits >> 2 & 3] & cfb_eorx) ^
					      cfb_bgx);
				((unsigned int *)tdest)[3] =
				    SHTSWAP32((lk_cfb_font_dtable15[bits & 3] & cfb_eorx) ^
					      cfb_bgx);
			}
			pdest = pdest + MTK_VFW * PIXEL_SIZE;
		}
		break;

	case CFB_565RGB_16BIT:
		while (count--) {
			offs = (*s++) * MTK_VFH;
			pos = pfont + offs;
			row = MTK_VFH;
			if (0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "180", 3)) {
				for (tdest = pdest + row * LINE_LEN; row--; tdest -= LINE_LEN) {
					unsigned char bits = *pos++;
					((unsigned int *)tdest)[0] =
					    SWAP32_16((lk_cfb_font_dtable16[bits & 3] & cfb_eorx) ^
						      cfb_bgx);
					((unsigned int *)tdest)[1] =
					    SWAP32_16((lk_cfb_font_dtable16[bits >> 2 & 3] &
						       cfb_eorx) ^ cfb_bgx);
					((unsigned int *)tdest)[2] =
					    SWAP32_16((lk_cfb_font_dtable16[bits >> 4 & 3] &
						       cfb_eorx) ^ cfb_bgx);
					((unsigned int *)tdest)[3] =
					    SWAP32_16((lk_cfb_font_dtable16[bits >> 6] & cfb_eorx) ^
						      cfb_bgx);
				}
				pdest = pdest + MTK_VFW * PIXEL_SIZE;
			} else {
				for (tdest = pdest; row--; tdest += LINE_LEN) {
					unsigned char bits = *pos++;
					((unsigned int *)tdest)[0] =
					    SHTSWAP32((lk_cfb_font_dtable16[bits >> 6] & cfb_eorx) ^
						      cfb_bgx);
					((unsigned int *)tdest)[1] =
					    SHTSWAP32((lk_cfb_font_dtable16[bits >> 4 & 3] &
						       cfb_eorx) ^ cfb_bgx);
					((unsigned int *)tdest)[2] =
					    SHTSWAP32((lk_cfb_font_dtable16[bits >> 2 & 3] &
						       cfb_eorx) ^ cfb_bgx);
					((unsigned int *)tdest)[3] =
					    SHTSWAP32((lk_cfb_font_dtable16[bits & 3] & cfb_eorx) ^
						      cfb_bgx);
				}
				pdest = pdest + MTK_VFW * PIXEL_SIZE;
			}
		}
		break;
	case CFB_332RGB_8BIT:
	case CFB_FMT_8BIT:
		while (count--) {
			offs = (*s++) * MTK_VFH;
			pos = pfont + offs;
			row = MTK_VFH;
			for (tdest = pdest; row--; tdest += LINE_LEN) {
				unsigned char bits = *pos++;
				((unsigned int *)tdest)[0] =
				    (lk_cfb_font_dtable8[bits >> 4] & cfb_eorx) ^ cfb_bgx;
				((unsigned int *)tdest)[1] =
				    (lk_cfb_font_dtable8[bits & 15] & cfb_eorx) ^ cfb_bgx;
			}
			pdest = pdest + MTK_VFW * PIXEL_SIZE;
		}
		break;

	case CFB_888RGB_24BIT:
		while (count--) {
			offs = (*s++) * MTK_VFH;
			pos = pfont + offs;
			row = MTK_VFH;
			for (tdest = pdest; row--; tdest += LINE_LEN) {
				unsigned char bits = *pos++;

				((unsigned int *)tdest)[0] =
				    (lk_cfb_font_dtb24[bits >> 4][0] & cfb_eorx) ^ cfb_bgx;
				((unsigned int *)tdest)[1] =
				    (lk_cfb_font_dtb24[bits >> 4][1] & cfb_eorx) ^ cfb_bgx;
				((unsigned int *)tdest)[2] =
				    (lk_cfb_font_dtb24[bits >> 4][2] & cfb_eorx) ^ cfb_bgx;
				((unsigned int *)tdest)[3] =
				    (lk_cfb_font_dtb24[bits & 15][0] & cfb_eorx) ^ cfb_bgx;
				((unsigned int *)tdest)[4] =
				    (lk_cfb_font_dtb24[bits & 15][1] & cfb_eorx) ^ cfb_bgx;
				((unsigned int *)tdest)[5] =
				    (lk_cfb_font_dtb24[bits & 15][2] & cfb_eorx) ^ cfb_bgx;
			}
			pdest = pdest + MTK_VFW * PIXEL_SIZE;
		}
		break;

	case CFB_X888RGB_32BIT:
		while (count--) {
			offs = (*s++) * MTK_VFH;
			pos = pfont + offs;
			row = MTK_VFH;
			if (0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "90", 2)) {
				for (tdest = pdest + row * PIXEL_SIZE; row--; tdest -= PIXEL_SIZE) {
					unsigned char bits = *pos++;
					((unsigned int *)tdest)[0 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][0] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[1 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][1] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[2 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][2] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[3 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][3] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[4 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][0] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[5 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][1] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[6 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][2] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[7 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][3] & cfb_eorx) ^
						   cfb_bgx);
				}
				pdest = pdest + MTK_VFH * PIXEL_SIZE;
			} else if (0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "180", 3)) {
				for (tdest = pdest + row * LINE_LEN; row--; tdest -= LINE_LEN) {
					unsigned char bits = *pos++;
					((unsigned int *)tdest)[7] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][0] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[6] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][1] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[5] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][2] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[4] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][3] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[3] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][0] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[2] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][1] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[1] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][2] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[0] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][3] & cfb_eorx) ^
						   cfb_bgx);
				}
				pdest = pdest + MTK_VFW * PIXEL_SIZE;
			} else if (0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "270", 3)) {
				for (tdest = pdest; row--; tdest += PIXEL_SIZE) {
					unsigned char bits = *pos++;
					((unsigned int *)tdest)[7 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][0] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[6 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][1] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[5 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][2] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[4 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][3] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[3 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][0] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[2 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][1] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[1 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][2] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[0 * VDO_COLS + MTK_VFH * VDO_COLS] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][3] & cfb_eorx) ^
						   cfb_bgx);
				}
				pdest = pdest + MTK_VFH * PIXEL_SIZE;
			} else {
				for (tdest = pdest; row--; tdest += LINE_LEN) {
					unsigned char bits = *pos++;
					((unsigned int *)tdest)[0] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][0] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[1] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][1] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[2] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][2] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[3] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits >> 4][3] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[4] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][0] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[5] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][1] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[6] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][2] & cfb_eorx) ^
						   cfb_bgx);
					((unsigned int *)tdest)[7] =
					    0xff000000 |
					    SWAP32((lk_cfb_font_dtable32[bits & 15][3] & cfb_eorx) ^
						   cfb_bgx);
				}
				pdest = pdest + MTK_VFW * PIXEL_SIZE;
			}
		}
		break;

	default:
		break;
	}

}

#define MAKE_TWO_RGB565_COLOR(high, low)  (((low) << 16) | (high))
static void cfg_lk_dchar_scale(unsigned int x, unsigned int y, int font_scale, char c)
{
	unsigned char ch = *((unsigned char *)&c);
	const unsigned char *cdat;
	unsigned char *dest;
	int rows, cols;
	int cols_mul, rows_mul;
	unsigned char *pfont = NULL;

	int font_draw_table16[4];

	if (x > (CFG_DISPLAY_WIDTH - MTK_VFW * font_scale)) {
		printf("draw width too large,x=%d\n", x);
		return;
	}
	if (y > (CFG_DISPLAY_HEIGHT - MTK_VFH * font_scale)) {
		printf("draw hight too large,y=%d\n", y);
		return;
	}

	dest = cfb_fb_addrs + y * LINE_LEN + x * PIXEL_SIZE;

	pfont = mtk_vdo_fntdata;

	switch (PIXEL_SIZE) {
	case 2:
		font_draw_table16[0] =
			MAKE_TWO_RGB565_COLOR(cfb_bgx, cfb_bgx);
		font_draw_table16[1] =
			MAKE_TWO_RGB565_COLOR(cfb_bgx, cfb_fgx);
		font_draw_table16[2] =
			MAKE_TWO_RGB565_COLOR(cfb_fgx, cfb_bgx);
		font_draw_table16[3] =
			MAKE_TWO_RGB565_COLOR(cfb_fgx, cfb_fgx);

		cdat = (const unsigned char *)pfont + ch * MTK_VFH;

		for (rows = MTK_VFH; rows--; dest += LINE_LEN) {
			unsigned char bits = *cdat++;

			((UINT32 *)dest)[0] =
				font_draw_table16[bits >> 6];
			((UINT32 *)dest)[1] =
				font_draw_table16[bits >> 4 & 3];
			((UINT32 *)dest)[2] =
				font_draw_table16[bits >> 2 & 3];
			((UINT32 *)dest)[3] =
				font_draw_table16[bits & 3];
		}
		break;
	case 3:
		cdat = (const unsigned char *)pfont + ch * MTK_VFH;
		for (rows = MTK_VFH; rows--; dest += LINE_LEN*font_scale) {
			unsigned char bits = *cdat++;
			unsigned char *temp_row = dest;

			for (rows_mul = 0; rows_mul < font_scale; rows_mul++) {
				unsigned char *tmp = temp_row;

				for (cols = 0; cols < 8; ++cols) {
					UINT32 color = ((bits >> (7 - cols)) & 0x1) ? cfb_fgx : cfb_bgx;

					for (cols_mul = 0; cols_mul < font_scale; cols_mul++) {
						((unsigned char *)tmp)[0] =
							color & 0xff;
						((unsigned char *)tmp)[1] =
							(color >> 8) & 0xff;
						((unsigned char *)tmp)[2] =
							(color >> 16) & 0xff;
						tmp += 3;
					}
				}
				temp_row += LINE_LEN;
			}
		}
		break;
	case 4:
		cdat = (const unsigned char *)pfont + ch * MTK_VFH;
		for (rows = MTK_VFH; rows--; dest += LINE_LEN*font_scale) {
			unsigned char bits = *cdat++;
			unsigned char *temp_row = dest;

			for (rows_mul = 0; rows_mul < font_scale; rows_mul++) {
				unsigned char *tmp = temp_row;

				for (cols = 0; cols < 8; ++cols) {
					unsigned int color = ((bits >> (7 - cols)) & 0x1) ? cfb_fgx : cfb_bgx;

					for (cols_mul = 0; cols_mul < font_scale; cols_mul++) {
						((unsigned char *)tmp)[0] =
							color & 0xff;
						((unsigned char *)tmp)[1] =
							(color >> 8) & 0xff;
						((unsigned char *)tmp)[2] =
							(color >> 16) & 0xff;
						((unsigned char *)tmp)[3] =
							(color >> 24) | 0xff;
						tmp += 4;
					}
				}
				temp_row += LINE_LEN;
			}
		}
		break;
	default:
		printf("draw char fail,PIXEL_SIZE=%d\n", PIXEL_SIZE);
	}
}

void video_drawstr_scale(int font_scale, const char *s)
{
	unsigned int cfb_count = strlen(s);
	int i = 0;

	while (cfb_count--) {
		cfg_lk_dchar_scale((get_cols() + i * font_scale) * MTK_VFW, get_rows() * MTK_VFH, font_scale, *s);
		s++;
		i++;
	}

	mt_disp_update(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
}

void video_drawstr_scale_by_pixel(unsigned int x, unsigned int y, int font_scale, const char *s)
{
	unsigned int cfb_count = strlen(s);
	int i = 0;

	while (cfb_count--) {
		cfg_lk_dchar_scale(x + i * font_scale * MTK_VFW, y, font_scale, *s);
		s++;
		i++;
	}

	mt_disp_update(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
}

static inline void cfb_lk_drawstr(int this_xx, int this_yy, unsigned char *this_s)
{
	cfb_lk_dchars(this_xx, this_yy, this_s, strlen((char *)this_s));
}

static void cfb_lk_putchar(int this_xx, int this_yy, unsigned char this_c)
{
	cfb_lk_dchars(this_xx, vdo_fb_height + this_yy, &this_c, 1);
}

static void cfb_lk_scrollup(void)
{
	/* * *copy* up *rows* ignoring *the* first *one */
	cfb_memcpy((int *)cfb_buf_addrs, (int *)((char *)cfb_buf_addrs + CFB_ROW_SIZE), CFB_SCROLL_SIZE >> 2);
	cfb_memset((int *)((char *)cfb_buf_addrs - CFB_ROW_SIZE + CFB_SIZE), CFB_ROW_SIZE >> 2, CS_BG_COL);
}

static void cfb_lk_backsp(void)
{
	inc_cols(-1);

	if (get_cols() < 0) {
		set_cols(CFB_COL - 1);
		inc_rows(-1);

		if (get_rows() < 0)
			set_rows(0);
	}

	cfb_lk_putchar(get_cols() * MTK_VFW, get_rows() * MTK_VFH, ' ');
}

static void cfb_lk_newline(void)
{
	/* Check if last character in the line was just drawn. If so, cursor was */
	/* overwriten and need not to be cleared. Cursor clearing without this */
	/* check causes overwriting the 1st character of the line if line lenght */
	/* is >= CFB_COL */

	inc_rows(1);
	set_cols(0);

	/* -Check if  we need to scrol the terminal */
	if (get_rows() >= (int)(CFB_ROW)) {

		cfb_lk_scrollup();
		inc_rows(-1);
	}
}

static void cfb_lk_colback(void)
{
	set_cols(0);
}

void video_putc(const char c)
{
	static int next_line = 1;

	/* Jett: check newline here in order to */
	/* scroll the screen immediately for the first time video_printf() */

	if (cfb_cols >= (int)(CFB_COL))
		cfb_lk_newline();

	switch (c) {
	case 13:
		/* back to first column */
		cfb_lk_colback();
		break;

	case '\n':
		/* next line */
		if (cfb_cols || (!cfb_cols && next_line))
			cfb_lk_newline();
		next_line = 1;
		break;

	case 8:
		/* back space */
		cfb_lk_backsp();
		break;

	case 9:
		/* tab-8 */
		cfb_cols |= 0x0008;
		cfb_cols &= ~0x0007;
		if (get_cols() >= (int)(CFB_COL))
			cfb_lk_newline();
		break;

	default:
		/* draw-the-char */
		if (0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "90", 2))
			cfb_lk_putchar((CFB_ROW - get_rows()) * MTK_VFH, get_cols() * MTK_VFW, c);
		else if (0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "180", 3))
			cfb_lk_putchar((CFB_COL - get_cols() - 1) * MTK_VFW,
				       (CFB_ROW - get_rows()) * MTK_VFH, c);
		else if (0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "270", 3))
			cfb_lk_putchar((CFB_COL - CFB_ROW + get_rows()) * MTK_VFH,
				       (CFB_ROW - get_cols() - 10) * MTK_VFW, c);
		else
			cfb_lk_putchar(get_cols() * MTK_VFW, get_rows() * MTK_VFH, c);
		inc_cols(1);

		/* check-for-newline */
		if (get_cols() >= (int)(CFB_COL)) {
			cfb_lk_newline();
			next_line = 0;
		}
	}
}

void video_puts(const char *s)
{
	unsigned int cfb_count = strlen(s);

	while (cfb_count--) {
		video_putc(*s);
		s++;
	}

	mt_disp_update(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
}

void video_printf(const char *fmt, ...)
{
#ifdef CFB_CONSOLE_ON
	va_list args;
	/* unsigned int i; */
	char printbuffer[CONFIG_SYS_PBSIZE];

	va_start(args, fmt);

	/* /For this to work, printbuffer must be larger than */
	/* anything we ever want to print. */
	/*  */
	vsprintf(printbuffer, fmt, args);
	va_end(args);

	/* Print the string */
	video_puts(printbuffer);
#else
	printf("%s\n", fmt);
#endif
}

static int video_lk_init(void)
{
	unsigned char color8bit = 0;
	unsigned int data_fmt = 0;

	pGD = video_hw_init();
	if (pGD == NULL)
		return -1;

	if (0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "90", 2)
	    || 0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "270", 3)) {
		g_cfb[0] = (SIZE_Y / FONT_WIDTH);
		g_cfb[1] = (SIZE_X / FONT_HEIGHT);
	} else {
		g_cfb[0] = (SIZE_Y / FONT_HEIGHT);
		g_cfb[1] = (SIZE_X / FONT_WIDTH);
	}

	cfb_fb_addrs = (void *)VDO_CFB_ADDRS;
	data_fmt = DATA_FMT;
	/* Init  drawing pats */
	switch (data_fmt) {
	case CFB_555RGB_15BIT:
		cfb_fgx = ((FC_5B << 26) | (FC_5B << 21) | (FC_5B << 16) |	/* high 16 0555 */
			   (FC_5B << 10) | (FC_5B << 5) | FC_5B);	/* / low 16 0555 */
		cfb_bgx = ((BC_5B << 26) | (BC_5B << 21) | (BC_5B << 16) |	/* high 16 0555 */
			   (BC_5B << 10) | (BC_5B << 5) | BC_5B);	/* low 16 0555 */
		break;
	case CFB_565RGB_16BIT:
		cfb_fgx = ((FC_5B << 27) | (FC_6B << 21) | (FC_5B << 16) |	/* high 16 565 */
			   (FC_5B << 11) | (FC_6B << 5) | FC_5B);	/* low 16 565 */
		cfb_bgx = ((BC_5B << 27) | (BC_6B << 21) | (BC_5B << 16) |	/* high 16 565 */
			   (BC_5B << 11) | (BC_6B << 5) | BC_5B);	/* low 16 565 */
		break;
	case CFB_FMT_8BIT:
		video_set_lut(0x01, CS_FG_COL, CS_FG_COL, CS_FG_COL);
		video_set_lut(0x00, CS_BG_COL, CS_BG_COL, CS_BG_COL);
		cfb_fgx = 0x01010101;
		cfb_bgx = 0x00000000;
		break;
	case CFB_X888RGB_32BIT:
		cfb_fgx = (CS_FG_COL << 16) | (CS_FG_COL << 8) | CS_FG_COL;
		cfb_bgx = (CS_BG_COL << 16) | (CS_BG_COL << 8) | CS_BG_COL;
		break;
	case CFB_332RGB_8BIT:
		color8bit = ((CS_FG_COL & 0xe0) | ((CS_FG_COL >> 3) & 0x1c) | CS_FG_COL >> 6);
		cfb_fgx = (color8bit << 24) | (color8bit << 16) | (color8bit << 8) | color8bit;
		color8bit = ((CS_BG_COL & 0xe0) | ((CS_BG_COL >> 3) & 0x1c) | CS_BG_COL >> 6);
		cfb_bgx = (color8bit << 24) | (color8bit << 16) | (color8bit << 8) | color8bit;
		break;
	case CFB_888RGB_24BIT:
		cfb_fgx = (CS_FG_COL << 24) | (CS_FG_COL << 16) | (CS_FG_COL << 8) | CS_FG_COL;
		cfb_bgx = (CS_BG_COL << 24) | (CS_BG_COL << 16) | (CS_BG_COL << 8) | CS_BG_COL;
		break;

	default:
		break;
	}
	cfb_eorx = cfb_fgx ^ cfb_bgx;

	cfb_eorx_default = cfb_eorx;
	cfb_fgx_default = cfb_fgx;
	cfb_bgx_default = cfb_bgx;

	cfb_buf_addrs = cfb_fb_addrs;
	/* Initialize cfb char position */
	set_cols(0);
	set_rows(0);

	return 0;
}

void video_set_cursor(int row, int col)
{
	if (row >= 0 && row < (int)(CFB_ROW) && col >= 0 && col <= (int)(CFB_COL)) {
		cfb_rows = row;
		cfb_cols = col;
	}
}

void video_set_fg_color(unsigned char r, unsigned char g, unsigned char b)
{
	unsigned char color8bit = 0;
	unsigned int data_fmt = 0;
	unsigned char r_5B = r >> 3;
	unsigned char g_5B = g >> 3;
	unsigned char g_6B = g >> 2;
	unsigned char b_5B = b >> 3;

	data_fmt = DATA_FMT;
	printf("%s,(r-%u,g-%u,b-%u)\n",__func__, r, g, b);

	switch (data_fmt) {
		case CFB_555RGB_15BIT:
			cfb_fgx = ((r_5B << 26) | (g_5B << 21) | (b_5B << 16) |	/* high 16 0555 */
				   (r_5B << 10) | (r_5B << 5) | b_5B);	/* / low 16 0555 */
			break;
		case CFB_565RGB_16BIT:
			cfb_fgx = ((r_5B << 27) | (g_6B << 21) | (b_5B << 16) |	/* high 16 565 */
				   (r_5B << 11) | (g_6B << 5) | b_5B);	/* low 16 565 */
			break;
		case CFB_X888RGB_32BIT:
			cfb_fgx = (r << 16) | (g << 8) | b;
			break;
		case CFB_332RGB_8BIT:
			color8bit = ((r & 0xe0) | ((g >> 3) & 0x1c) | b >> 6);
			cfb_fgx = (color8bit << 24) | (color8bit << 16) | (color8bit << 8) | color8bit;
			break;
		default:
			printf("%s,not supported data_fmt:%u\n",__func__,data_fmt);
			break;
	}
	cfb_eorx = cfb_fgx ^ cfb_bgx;

}
void video_set_bg_color(unsigned char r, unsigned char g, unsigned char b)
{
	unsigned char color8bit = 0;
	unsigned int data_fmt = 0;
	unsigned char r_5B = r >> 3;
	unsigned char g_5B = g >> 3;
	unsigned char g_6B = g >> 2;
	unsigned char b_5B = b >> 3;

	data_fmt = DATA_FMT;
	printf("%s,(r-%u,g-%u,b-%u)\n",__func__, r, g, b);

	switch (data_fmt) {
		case CFB_555RGB_15BIT:
			cfb_bgx = ((r_5B << 26) | (g_5B << 21) | (b_5B << 16) |	/* high 16 0555 */
				   (r_5B << 10) | (r_5B << 5) | b_5B);	/* / low 16 0555 */
			break;
		case CFB_565RGB_16BIT:
			cfb_bgx = ((r_5B << 27) | (g_6B << 21) | (b_5B << 16) |	/* high 16 565 */
				   (r_5B << 11) | (g_6B << 5) | b_5B);	/* low 16 565 */
			break;
		case CFB_X888RGB_32BIT:
			cfb_bgx = (r << 16) | (g << 8) | b;
			break;
		case CFB_332RGB_8BIT:
			color8bit = ((r & 0xe0) | ((g >> 3) & 0x1c) | b >> 6);
			cfb_bgx = (color8bit << 24) | (color8bit << 16) | (color8bit << 8) | color8bit;
			break;
		default:
			printf("%s,not supported data_fmt:%u\n",__func__,data_fmt);
			break;
	}
	cfb_eorx = cfb_fgx ^ cfb_bgx;
}

void video_set_default_color(void)
{
	printf("%s\n",__func__);

	cfb_eorx = cfb_eorx_default;
	cfb_fgx = cfb_fgx_default;
	cfb_bgx = cfb_bgx_default;

}
int video_get_rows(void)
{
	return CFB_ROW;
}

int video_get_colums(void)
{
	return CFB_COL;
}

void video_clean_screen(void)
{
	memset((void *)VDO_CFB_ADDRS, 0, VDO_CFB_SIZE);
	mt_disp_update(0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT);
}

static void video_draw_image(void *addr, unsigned int x, unsigned int y,
		unsigned int w, unsigned int h, const unsigned int *color)
{
	unsigned int i = 0;
	unsigned int j = 0;
	void *start_addr = addr + y * LINE_LEN + x * PIXEL_SIZE;
	unsigned int *line_addr = start_addr;

	for (j=0; j<h; j++) {
		line_addr = start_addr;
		for (i = 0; i<w; i++) {
			line_addr[i] = (color[j * w + i] & 0xFFFFFF) | 0xFF000000;
		}
		start_addr += LINE_LEN;
	}
	mt_disp_update(0, 0, 0, 0);
}

static void video_clear_image(void *addr, unsigned int x, unsigned int y,
		unsigned int w, unsigned int h, const unsigned int color)
{
	unsigned int i = 0;
	unsigned int j = 0;
	void *start_addr = addr + y * LINE_LEN + x * PIXEL_SIZE;
	unsigned int *line_addr = start_addr;

	for (j=0; j<h; j++) {
		line_addr = start_addr;
		for (i = 0; i<w; i++) {
			line_addr[i] = color | 0xFF000000;
		}
		start_addr += LINE_LEN;
	}
	mt_disp_update(0, 0, 0, 0);
}

//set bg & fg colors, now only support color format ARGB
void video_set_bgfg_colors(unsigned int bg, unsigned int fg)
{
	unsigned char r,g,b;

	r = bg >> 16 & 0xFF;
	g = bg >> 8 & 0xFF;
	b = bg & 0xFF;
	cfb_bg_alpha = bg & 0xFF000000;

	video_set_bg_color(r, g, b);

	r = fg >> 16 & 0xFF;
	g = fg >> 8 & 0xFF;
	b = fg & 0xFF;
	cfb_fg_alpha = fg & 0xFF000000;

	video_set_fg_color(r, g, b);
}

//set fg colors, now only support color format ARGB
void video_set_fgcolor(unsigned int fg)
{
	unsigned char r,g,b;

	r = fg >> 16 & 0xFF;
	g = fg >> 8 & 0xFF;
	b = fg & 0xFF;
	cfb_fg_alpha = fg & 0xFF000000;

	video_set_fg_color(r, g, b);
}

//set bg color, now only support color format ARGB
void video_set_bgcolor(unsigned int bg)
{
	unsigned char r,g,b;

	r = bg >> 16 & 0xFF;
	g = bg >> 8 & 0xFF;
	b = bg & 0xFF;
	cfb_bg_alpha = bg & 0xFF000000;

	video_set_bg_color(r, g, b);
}

//clear screen by bg
void video_clean_screen_by_bg(void)
{
	video_clear_image(cfb_fb_addrs, 0, 0, CFG_DISPLAY_WIDTH, CFG_DISPLAY_HEIGHT, cfb_bgx | cfb_bg_alpha);
}

//set x & y
void video_set_position(int x, int y)
{
	video_set_cursor(y, x);
}

//show string
void video_disp_string(char *str)
{
	video_printf("%s\n", str);
}

//show image
void fbcon_display_image(const unsigned int data[],
		unsigned int xpos, unsigned int ypos, unsigned int width, unsigned int height)
{
	video_draw_image(cfb_fb_addrs, xpos, ypos, width, height, data);
}

//clear image
void video_clear_image_by_color(const unsigned int data,
		unsigned int xpos, unsigned int ypos, unsigned int width, unsigned int height)
{
	video_clear_image(cfb_fb_addrs, xpos, ypos, width, height, data);
}

//package second
void fbcon_set_color(unsigned int bg, unsigned int fg)
{
	video_set_bgfg_colors(bg, fg);
	return;
}

void fbcon_clear(void)
{
	video_clean_screen_by_bg();
	return;
}

void fbcon_set_position(unsigned int x, unsigned int y)
{
	if ((x > CFG_DISPLAY_WIDTH) || (y > CFG_DISPLAY_HEIGHT)) {
		printf("coordinate set error \n");
	}

	cfb_pixel_position_x = x;
	cfb_pixel_position_y = y;
	return;
}

void fbcon_get_position(unsigned int *x, unsigned int *y)
{
	if((x == NULL ) || (y == NULL)) {
		printf("ERROR, pointer is NULL\n");
		return;
	}
	*x = cfb_pixel_position_x;
	*y = cfb_pixel_position_y;
}

void fbcon_disp_string(int font_scale,const char *s)
{
	unsigned int x = 0, y = 0;
	if(font_scale < 1){
		printf("font_scale error\n");
		return;
	}
	if(s == NULL){
		printf("error, string is null\n");
		return;
	}
	fbcon_get_position(&x, &y);
	video_drawstr_scale_by_pixel(x, y, font_scale, s);
	return;
}

void fbcon_clear_image(const unsigned int data,
		unsigned int xpos, unsigned int ypos, unsigned int width, unsigned int height)
{
	video_clear_image_by_color(data, xpos, ypos, width, height);
	return;
}

int drv_video_init(void)
{
	if (video_lk_init() == -1)
		return 0;

	/* Jett: set cursor to the right-bottom corner */
	/* scroll screen immediately for the first time video_printf() */

	video_set_cursor(CFB_ROW - 1, CFB_COL);
	return 0;
}
