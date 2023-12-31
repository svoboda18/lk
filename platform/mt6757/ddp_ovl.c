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

#define LOG_TAG "OVL"

#include "platform/ddp_reg.h"
#include "platform/ddp_matrix_para.h"
#include "platform/ddp_info.h"
#include "platform/ddp_log.h"

#include "platform/ddp_ovl.h"
#include "platform/disp_drv_platform.h"

#define OVL_NUM           (2)
#define OVL_REG_BACK_MAX  (40)

#define OVL_LAYER_OFFSET        (0x20)
#define OVL_RDMA_DEBUG_OFFSET   (0x4)

enum OVL_COLOR_SPACE {
	OVL_COLOR_SPACE_RGB = 0,
	OVL_COLOR_SPACE_YUV,
};

enum OVL_INPUT_FORMAT {
	OVL_INPUT_FORMAT_BGR565     = 0,
	OVL_INPUT_FORMAT_RGB888     = 1,
	OVL_INPUT_FORMAT_RGBA8888   = 2,
	OVL_INPUT_FORMAT_ARGB8888   = 3,
	OVL_INPUT_FORMAT_VYUY       = 4,
	OVL_INPUT_FORMAT_YVYU       = 5,

	OVL_INPUT_FORMAT_RGB565     = 6,
	OVL_INPUT_FORMAT_BGR888     = 7,
	OVL_INPUT_FORMAT_BGRA8888   = 8,
	OVL_INPUT_FORMAT_ABGR8888   = 9,
	OVL_INPUT_FORMAT_UYVY       = 10,
	OVL_INPUT_FORMAT_YUYV       = 11,

	OVL_INPUT_FORMAT_RGBA4444	= 12,
	OVL_INPUT_FORMAT_BGRA4444	= 13,

	OVL_INPUT_FORMAT_UNKNOWN    = 32,
};

typedef struct {
	unsigned int address;
	unsigned int value;
} OVL_REG;

static int reg_back_cnt[OVL_NUM];
static OVL_REG reg_back[OVL_NUM][OVL_REG_BACK_MAX];
static enum OVL_INPUT_FORMAT ovl_input_fmt_convert(DpColorFormat fmt);
static unsigned int ovl_input_fmt_byte_swap(enum OVL_INPUT_FORMAT inputFormat);
static unsigned int ovl_input_fmt_bpp(enum OVL_INPUT_FORMAT inputFormat);
static enum OVL_COLOR_SPACE ovl_input_fmt_color_space(enum OVL_INPUT_FORMAT inputFormat);
static unsigned int ovl_input_fmt_reg_value(enum OVL_INPUT_FORMAT inputFormat);
static void ovl_store_regs(int idx);
static void ovl_restore_regs(int idx,void * handle);

static enum OVL_INPUT_FORMAT ovl_input_fmt_convert(DpColorFormat fmt)
{
	enum OVL_INPUT_FORMAT ovl_fmt = OVL_INPUT_FORMAT_UNKNOWN;
	switch (fmt) {
		case eBGR565:
			ovl_fmt = OVL_INPUT_FORMAT_BGR565;
			break;
		case eRGB565:
			ovl_fmt = OVL_INPUT_FORMAT_RGB565;
			break;
		case eRGB888:
			ovl_fmt = OVL_INPUT_FORMAT_RGB888;
			break;
		case eBGR888:
			ovl_fmt = OVL_INPUT_FORMAT_BGR888;
			break;
		case eRGBA4444:
			ovl_fmt = OVL_INPUT_FORMAT_RGBA4444;
			break;
		case eBGRA4444:
			ovl_fmt = OVL_INPUT_FORMAT_BGRA4444;
			break;
		case eRGBA8888:
			ovl_fmt = OVL_INPUT_FORMAT_RGBA8888;
			break;
		case eBGRA8888:
			ovl_fmt = OVL_INPUT_FORMAT_BGRA8888;
			break;
		case eARGB8888:
			ovl_fmt = OVL_INPUT_FORMAT_ARGB8888;
			break;
		case eABGR8888:
			ovl_fmt = OVL_INPUT_FORMAT_ABGR8888;
			break;
		case eVYUY:
			ovl_fmt = OVL_INPUT_FORMAT_VYUY;
			break;
		case eYVYU:
			ovl_fmt = OVL_INPUT_FORMAT_YVYU;
			break;
		case eUYVY:
			ovl_fmt = OVL_INPUT_FORMAT_UYVY;
			break;
		case eYUY2:
			ovl_fmt = OVL_INPUT_FORMAT_YUYV;
			break;
		default:
			DDPERR("ovl_fmt_convert fmt=%d, ovl_fmt=%d\n", fmt, ovl_fmt);
			break;
	}
	return ovl_fmt;
}

static DpColorFormat ovl_input_fmt(enum OVL_INPUT_FORMAT fmt, int swap)
{
	switch (fmt) {
		case OVL_INPUT_FORMAT_BGR565:
			return swap ? eBGR565 : eRGB565;
		case OVL_INPUT_FORMAT_RGB888:
			return swap ? eRGB888 : eBGR888;
		case OVL_INPUT_FORMAT_RGBA8888:
			return swap ? eRGBA8888 : eBGRA8888;
		case OVL_INPUT_FORMAT_ARGB8888:
			return swap ? eARGB8888 : eABGR8888;
		case OVL_INPUT_FORMAT_VYUY:
			return swap ? eVYUY : eUYVY;
		case OVL_INPUT_FORMAT_YVYU:
			return swap ? eYVYU : eYUY2;
		case OVL_INPUT_FORMAT_RGBA4444:
			return swap ? eRGBA4444 : eBGRA4444;
		default:
			DDPERR("ovl_input_fmt fmt=%d, swap=%d\n", fmt, swap);
			break;
	}
	return eRGB888;
}


static char *ovl_intput_format_name(enum OVL_INPUT_FORMAT fmt, int swap)
{
	switch (fmt) {
		case OVL_INPUT_FORMAT_BGR565:
			return swap ? "eBGR565" : "eRGB565";
		case OVL_INPUT_FORMAT_RGB565:
			return "eRGB565";
		case OVL_INPUT_FORMAT_RGB888:
			return swap ? "eRGB888" : "eBGR888";
		case OVL_INPUT_FORMAT_BGR888:
			return "eBGR888";
		case OVL_INPUT_FORMAT_RGBA8888:
			return swap ? "eRGBA8888" : "eBGRA8888";
		case OVL_INPUT_FORMAT_BGRA8888:
			return "eBGRA8888";
		case OVL_INPUT_FORMAT_ARGB8888:
			return swap ? "eARGB8888" : "eABGR8888";
		case OVL_INPUT_FORMAT_ABGR8888:
			return "eABGR8888";
		case OVL_INPUT_FORMAT_VYUY:
			return swap ? "eVYUY" : "eUYVY";
		case OVL_INPUT_FORMAT_UYVY:
			return "eUYVY";
		case OVL_INPUT_FORMAT_YVYU:
			return swap ? "eYVYU" : "eYUY2";
		case OVL_INPUT_FORMAT_YUYV:
			return "eYUY2";
		case OVL_INPUT_FORMAT_RGBA4444:
			return swap ? "eRGBA4444" : "eBGRA4444";
		default:
			DDPERR("ovl_intput_fmt unknow fmt=%d, swap=%d\n", fmt, swap);
			break;
	}
	return "unknow";
}


static unsigned int ovl_index(DISP_MODULE_ENUM module)
{
	int idx = 0;
	switch (module) {
		case DISP_MODULE_OVL0:
			idx = 0;
			break;
		case DISP_MODULE_OVL1:
			idx = 1;
			break;
		case DISP_MODULE_OVL0_2L:
			idx = 2;
			break;
		case DISP_MODULE_OVL1_2L:
			idx = 3;
			break;
		default:
			DDPERR("invalid module=%d \n", module);// invalid module
			ASSERT(0);
	}
	return idx;
}

int OVLStart(DISP_MODULE_ENUM module, void *handle)
{
	int idx = ovl_index(module);

	/* bypass shadow */
#ifdef LK_BYPASS_SHADOW_REG
	DISP_REG_SET_FIELD(handle, EN_FLD_BYPASS_SHADOW,
			   idx*DISP_INDEX_OFFSET + DISP_REG_OVL_EN, 0x1);

	DISP_REG_SET_FIELD(handle, EN_FLD_RD_WRK_REG,
		   idx*DISP_INDEX_OFFSET + DISP_REG_OVL_EN, 0x1);
#endif

	DISP_REG_SET_FIELD(handle, EN_FLD_OVL_EN,
			   idx*DISP_INDEX_OFFSET + DISP_REG_OVL_EN, 0x1);

	DISP_REG_SET(handle, idx*DISP_INDEX_OFFSET + DISP_REG_OVL_INTEN,
		     0x1E | REG_FLD_VAL(INTEN_FLD_ABNORMAL_SOF, 1));

	DISP_REG_SET_FIELD(handle, DATAPATH_CON_FLD_LAYER_SMI_ID_EN,
			   idx*DISP_INDEX_OFFSET + DISP_REG_OVL_DATAPATH_CON, 0x1);

	return 0;
}

int OVLStop(DISP_MODULE_ENUM module, void *handle)
{
	int idx = ovl_index(module);

	DISP_REG_SET(handle,idx*DISP_INDEX_OFFSET+DISP_REG_OVL_INTEN, 0x00);
	DISP_REG_SET(handle,idx*DISP_INDEX_OFFSET+DISP_REG_OVL_EN, 0x00);
	DISP_REG_SET(handle,idx*DISP_INDEX_OFFSET+DISP_REG_OVL_INTSTA, 0x00);

	return 0;
}

int OVLReset(DISP_MODULE_ENUM module, void *handle)
{
#define OVL_IDLE (0x3)
	unsigned int delay_cnt = 0;
	int idx = ovl_index(module);
	/*always use cpu do reset*/
	DISP_CPU_REG_SET(idx*DISP_INDEX_OFFSET+DISP_REG_OVL_RST, 0x1);              // soft reset
	DISP_CPU_REG_SET(idx*DISP_INDEX_OFFSET+DISP_REG_OVL_RST, 0x0);
	while (!(DISP_REG_GET(idx*DISP_INDEX_OFFSET+DISP_REG_OVL_FLOW_CTRL_DBG) & OVL_IDLE)) {
		delay_cnt++;
		udelay(10);
		if (delay_cnt>2000) {
			DDPERR("OVL%dReset() timeout! \n",idx);
			break;
		}
	}
	return 0;
}

int OVLROI(DISP_MODULE_ENUM module,
           unsigned int bgW,
           unsigned int bgH,
           unsigned int bgColor,
           void * handle)
{
	int idx = ovl_index(module);

	if ((bgW > OVL_MAX_WIDTH) || (bgH > OVL_MAX_HEIGHT)) {
		DDPERR("OVLROI(), exceed OVL max size, w=%d, h=%d \n", bgW, bgH);
		ASSERT(0);
	}

	DISP_REG_SET(handle,idx*DISP_INDEX_OFFSET+DISP_REG_OVL_ROI_SIZE, bgH<<16 | bgW);

	DISP_REG_SET(handle,idx*DISP_INDEX_OFFSET+DISP_REG_OVL_ROI_BGCLR, bgColor);

	return 0;
}

int OVLLayerSwitch(DISP_MODULE_ENUM module,
                   unsigned layer,
                   unsigned int en,
                   void * handle)
{
	int idx = ovl_index(module);
	ASSERT(layer<=3);

	switch (layer) {
		case 0:
			DISP_REG_SET_FIELD(handle,SRC_CON_FLD_L0_EN, idx*DISP_INDEX_OFFSET+DISP_REG_OVL_SRC_CON, en);
			break;
		case 1:
			DISP_REG_SET_FIELD(handle,SRC_CON_FLD_L1_EN, idx*DISP_INDEX_OFFSET+DISP_REG_OVL_SRC_CON, en);
			break;
		case 2:
			DISP_REG_SET_FIELD(handle,SRC_CON_FLD_L2_EN, idx*DISP_INDEX_OFFSET+DISP_REG_OVL_SRC_CON, en);
			break;
		case 3:
			DISP_REG_SET_FIELD(handle,SRC_CON_FLD_L3_EN, idx*DISP_INDEX_OFFSET+DISP_REG_OVL_SRC_CON, en);
			break;
		default:
			DDPERR("invalid layer=%d\n", layer);           // invalid layer
			ASSERT(0);
	}

	return 0;
}

int OVL3DConfig(DISP_MODULE_ENUM module,
                unsigned int layer_id,
                unsigned int en_3d,
                unsigned int landscape,
                unsigned int r_first,
                void *handle)
{

	return 0;
}

int OVLLayerConfig(DISP_MODULE_ENUM module,
                   unsigned int layer,
                   unsigned int source,
                   DpColorFormat format,
                   unsigned int addr,
                   unsigned int src_x,     // ROI x offset
                   unsigned int src_y,     // ROI y offset
                   unsigned int src_pitch,
                   unsigned int dst_x,     // ROI x offset
                   unsigned int dst_y,     // ROI y offset
                   unsigned int dst_w,     // ROT width
                   unsigned int dst_h,     // ROI height
                   unsigned int keyEn,
                   unsigned int key,   // color key
                   unsigned int aen,       // alpha enable
                   unsigned char alpha,
                   void * handle)
{

	int idx = ovl_index(module);
	unsigned int value = 0;
	enum OVL_INPUT_FORMAT fmt  = ovl_input_fmt_convert(format);
	unsigned int bpp           = ovl_input_fmt_bpp(fmt);
	unsigned int input_swap    = ovl_input_fmt_byte_swap(fmt);
	unsigned int input_fmt     = ovl_input_fmt_reg_value(fmt);
	enum OVL_COLOR_SPACE space = ovl_input_fmt_color_space(fmt);
	unsigned int offset = 0;
	/*0100 MTX_JPEG_TO_RGB (YUV FUll TO RGB)*/
	int color_matrix           = 0x4;

	unsigned int idx_offset  = idx*DISP_INDEX_OFFSET;
	unsigned int layer_offset = idx_offset + layer * 0x20;

#ifdef MTK_LCM_PHYSICAL_ROTATION_HW
	unsigned int bg_h, bg_w;
#endif

	ASSERT((dst_w <= OVL_MAX_WIDTH) &&
	       (dst_h <= OVL_MAX_HEIGHT) &&
	       (layer <= 3));

	if (addr == 0) {
		DDPERR("source from memory, but addr is 0!\n");
		ASSERT(0);
	}
	DDPDBG("ovl%d, layer=%d, source=%s, off(x=%d, y=%d), dst(%d, %d, %d, %d),pitch=%d,"
	       "fmt=%s, addr=%lx, keyEn=%d, key=%d, aen=%d, alpha=%d \n",
	       idx,
	       layer,
	       (source==0)?"memory":"constant_color",
	       src_x,
	       src_y,
	       dst_x,
	       dst_y,
	       dst_w,
	       dst_h,
	       src_pitch,
	       ovl_intput_format_name(fmt, input_swap),
	       addr,
	       keyEn,
	       key,
	       aen,
	       alpha);

	if (source==OVL_LAYER_SOURCE_RESERVED) { //==1, means constant color
		if (aen==0) {
			DDPERR("dim layer ahpha enable should be 1!\n");
		}
		if (fmt!=OVL_INPUT_FORMAT_RGB565) {
			DDPERR("dim layer format should be RGB565");
			fmt = OVL_INPUT_FORMAT_RGB565;
		}
	}

	DISP_REG_SET(handle, DISP_REG_OVL_RDMA0_CTRL+layer_offset, 0x1);

	value = (REG_FLD_VAL((L_CON_FLD_LARC), (source))     |
	         REG_FLD_VAL((L_CON_FLD_CFMT), (input_fmt))  |
	         REG_FLD_VAL((L_CON_FLD_AEN), (aen))         |
	         REG_FLD_VAL((L_CON_FLD_APHA), (alpha))      |
	         REG_FLD_VAL((L_CON_FLD_SKEN), (keyEn))     |
	         REG_FLD_VAL((L_CON_FLD_BTSW), (input_swap)));

	if (fmt == OVL_INPUT_FORMAT_RGBA4444)
		value |= REG_FLD_VAL((L_CON_FLD_CLRFMT_MAN), (1));

	if (space == OVL_COLOR_SPACE_YUV)
		value = value | REG_FLD_VAL((L_CON_FLD_MTX), (color_matrix));

#ifdef MTK_LCM_PHYSICAL_ROTATION_HW
	value |= (REG_FLD_VAL((L_CON_FLD_VIRTICAL_FLIP), 1) |
	          REG_FLD_VAL((L_CON_FLD_HORI_FLIP), 1));
#endif

	DISP_REG_SET(handle, DISP_REG_OVL_L0_CON+layer_offset, value);

#ifdef MTK_LCM_PHYSICAL_ROTATION_HW
	bg_h = DISP_REG_GET(idx_offset + DISP_REG_OVL_ROI_SIZE);
	bg_w = bg_h & 0xFFFF;
	bg_h = bg_h >> 16;
	DISP_REG_SET(handle, DISP_REG_OVL_L0_OFFSET+layer_offset,
	             (bg_h-dst_h-dst_y)<<16 | (bg_w-dst_w-dst_x));
	offset = (src_x+dst_w+1)*bpp + (src_y+dst_h-1)*src_pitch - 1;
#else
	DISP_REG_SET(handle, DISP_REG_OVL_L0_OFFSET+layer_offset,
	             dst_y<<16 | dst_x);
	offset = src_x*bpp+src_y*src_pitch;
#endif

	DISP_REG_SET(handle, DISP_REG_OVL_L0_ADDR+layer_offset,
	             addr+offset);
	DISP_REG_SET(handle, DISP_REG_OVL_L0_SRC_SIZE+layer_offset,
	             dst_h<<16 | dst_w);

	DISP_REG_SET(handle, DISP_REG_OVL_L0_SRCKEY+layer_offset,
	             key);

	value = REG_FLD_VAL((L_PITCH_FLD_SRC_PITCH), (src_pitch));
	if (fmt == OVL_INPUT_FORMAT_RGBA4444) {
		value = REG_FLD_VAL(L_PITCH_FLD_SRGB_SEL, (1)) |
			REG_FLD_VAL(L_PITCH_FLD_DRGB_SEL, (2)) |
			REG_FLD_VAL(L_PITCH_FLD_SURFL_EN, (1)) |
			REG_FLD_VAL((L_PITCH_FLD_SRC_PITCH), (src_pitch));
	}

	DISP_REG_SET(handle, DISP_REG_OVL_L0_PITCH+layer_offset, value);
	//DISP_REG_SET(handle, DISP_REG_OVL_RDMA0_MEM_GMC_SETTING+layer_offset, 0x6070);
}

static unsigned int ovl_input_fmt_byte_swap(enum OVL_INPUT_FORMAT inputFormat)
{
	int input_swap = 0;
	switch (inputFormat) {
		case OVL_INPUT_FORMAT_BGR565:
		case OVL_INPUT_FORMAT_RGB888:
		case OVL_INPUT_FORMAT_RGBA8888:
		case OVL_INPUT_FORMAT_ARGB8888:
		case OVL_INPUT_FORMAT_BGRA4444:
		case OVL_INPUT_FORMAT_VYUY:
		case OVL_INPUT_FORMAT_YVYU:
			input_swap = 1;
			break;
		case OVL_INPUT_FORMAT_RGB565:
		case OVL_INPUT_FORMAT_BGR888:
		case OVL_INPUT_FORMAT_BGRA8888:
		case OVL_INPUT_FORMAT_ABGR8888:
		case OVL_INPUT_FORMAT_RGBA4444:
		case OVL_INPUT_FORMAT_UYVY:
		case OVL_INPUT_FORMAT_YUYV:
			input_swap = 0;
			break;
		default:
			DDPERR("unknow input ovl format is %d\n", inputFormat);
			ASSERT(0);
	}
	return input_swap;
}

static unsigned int ovl_input_fmt_bpp(enum OVL_INPUT_FORMAT inputFormat)
{
	int bpp = 0;
	switch (inputFormat) {
		case OVL_INPUT_FORMAT_BGR565:
		case OVL_INPUT_FORMAT_RGB565:
		case OVL_INPUT_FORMAT_VYUY:
		case OVL_INPUT_FORMAT_UYVY:
		case OVL_INPUT_FORMAT_YVYU:
		case OVL_INPUT_FORMAT_YUYV:
		case OVL_INPUT_FORMAT_RGBA4444:
		case OVL_INPUT_FORMAT_BGRA4444:
			bpp = 2;
			break;
		case OVL_INPUT_FORMAT_RGB888:
		case OVL_INPUT_FORMAT_BGR888:
			bpp = 3;
			break;
		case OVL_INPUT_FORMAT_RGBA8888:
		case OVL_INPUT_FORMAT_BGRA8888:
		case OVL_INPUT_FORMAT_ARGB8888:
		case OVL_INPUT_FORMAT_ABGR8888:
			bpp = 4;
			break;
		default:
			DDPERR("unknown ovl input format = %d\n", inputFormat);
			ASSERT(0);
	}
	return  bpp;
}

static enum OVL_COLOR_SPACE ovl_input_fmt_color_space(enum OVL_INPUT_FORMAT inputFormat)
{
	enum OVL_COLOR_SPACE space = OVL_COLOR_SPACE_RGB;
	switch (inputFormat) {
		case OVL_INPUT_FORMAT_BGR565:
		case OVL_INPUT_FORMAT_RGB565:
		case OVL_INPUT_FORMAT_RGB888:
		case OVL_INPUT_FORMAT_BGR888:
		case OVL_INPUT_FORMAT_BGRA4444:
		case OVL_INPUT_FORMAT_RGBA4444:
		case OVL_INPUT_FORMAT_RGBA8888:
		case OVL_INPUT_FORMAT_BGRA8888:
		case OVL_INPUT_FORMAT_ARGB8888:
		case OVL_INPUT_FORMAT_ABGR8888:
			space = OVL_COLOR_SPACE_RGB;
			break;
		case OVL_INPUT_FORMAT_VYUY:
		case OVL_INPUT_FORMAT_UYVY:
		case OVL_INPUT_FORMAT_YVYU:
		case OVL_INPUT_FORMAT_YUYV:
			space = OVL_COLOR_SPACE_YUV;
			break;
		default:
			DDPERR("unknown ovl input format = %d\n", inputFormat);
			ASSERT(0);
	}
	return space;
}

static unsigned int ovl_input_fmt_reg_value(enum OVL_INPUT_FORMAT inputFormat)
{
	int reg_value = 0;
	switch (inputFormat) {
		case OVL_INPUT_FORMAT_BGR565:
		case OVL_INPUT_FORMAT_RGB565:
			reg_value = 0x0;
			break;
		case OVL_INPUT_FORMAT_RGB888:
		case OVL_INPUT_FORMAT_BGR888:
			reg_value = 0x1;
			break;
		case OVL_INPUT_FORMAT_RGBA8888:
		case OVL_INPUT_FORMAT_BGRA8888:
			reg_value = 0x2;
			break;
		case OVL_INPUT_FORMAT_ARGB8888:
		case OVL_INPUT_FORMAT_ABGR8888:
			reg_value = 0x3;
			break;
		case OVL_INPUT_FORMAT_VYUY:
		case OVL_INPUT_FORMAT_UYVY:
		case OVL_INPUT_FORMAT_RGBA4444:
		case OVL_INPUT_FORMAT_BGRA4444:
			reg_value = 0x4;
			break;
		case OVL_INPUT_FORMAT_YVYU:
		case OVL_INPUT_FORMAT_YUYV:
			reg_value = 0x5;
			break;
		default:
			DDPERR("unknow ovl input format is %d\n", inputFormat);
			ASSERT(0);
	}
	return reg_value;
}

void OVLRegStore(DISP_MODULE_ENUM module)
{
	int i =0;
	int idx = ovl_index(module);

	static const unsigned int regs[] = {
		//start
		DISP_REG_OVL_INTEN       , DISP_REG_OVL_EN         ,DISP_REG_OVL_DATAPATH_CON,
		// roi
		DISP_REG_OVL_ROI_SIZE    , DISP_REG_OVL_ROI_BGCLR  ,
		//layers enable
		DISP_REG_OVL_SRC_CON,
		//layer0
		DISP_REG_OVL_RDMA0_CTRL  , DISP_REG_OVL_L0_CON     ,DISP_REG_OVL_L0_SRC_SIZE,
		DISP_REG_OVL_L0_OFFSET   , DISP_REG_OVL_L0_ADDR    ,DISP_REG_OVL_L0_PITCH,
		DISP_REG_OVL_L0_SRCKEY   ,
		//layer1
		DISP_REG_OVL_RDMA1_CTRL  , DISP_REG_OVL_L1_CON     ,DISP_REG_OVL_L1_SRC_SIZE,
		DISP_REG_OVL_L1_OFFSET   , DISP_REG_OVL_L1_ADDR    ,DISP_REG_OVL_L1_PITCH,
		DISP_REG_OVL_L1_SRCKEY   ,
		//layer2
		DISP_REG_OVL_RDMA2_CTRL  , DISP_REG_OVL_L2_CON     ,DISP_REG_OVL_L2_SRC_SIZE,
		DISP_REG_OVL_L2_OFFSET   , DISP_REG_OVL_L2_ADDR    ,DISP_REG_OVL_L2_PITCH,
		DISP_REG_OVL_L2_SRCKEY   ,
		//layer3
		DISP_REG_OVL_RDMA3_CTRL  , DISP_REG_OVL_L3_CON     ,DISP_REG_OVL_L3_SRC_SIZE,
		DISP_REG_OVL_L3_OFFSET   , DISP_REG_OVL_L3_ADDR    ,DISP_REG_OVL_L3_PITCH,
		DISP_REG_OVL_L3_SRCKEY   ,
	};

	reg_back_cnt[idx] = sizeof(regs)/sizeof(unsigned int);
	ASSERT(reg_back_cnt[idx]  <= OVL_REG_BACK_MAX);


	for (i =0; i< reg_back_cnt[idx]; i++) {
		reg_back[idx][i].address = regs[i];
		reg_back[idx][i].value   = DISP_REG_GET(regs[i]);
	}
	DDPDBG("store % cnt registers on ovl %d",reg_back_cnt[idx],idx);

}

void OVLRegRestore(DISP_MODULE_ENUM module,void * handle)
{
	int idx = ovl_index(module);
	int i = reg_back_cnt[idx];
	while (i > 0) {
		i--;
		DISP_REG_SET(handle,reg_back[idx][i].address, reg_back[idx][i].value);
	}
	DDPDBG("restore %d cnt registers on ovl %d",reg_back_cnt[idx],idx);
	reg_back_cnt[idx] = 0;
}


void  OVLClockOn(DISP_MODULE_ENUM module,void * handle)
{
	int idx = ovl_index(module);
	ddp_enable_module_clock(module);
	DDPMSG("OVL%dClockOn CG 0x%x \n",idx, DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON0));
	return;
}

void  OVLClockOff(DISP_MODULE_ENUM module,void * handle)
{
	int idx = ovl_index(module);
	DDPMSG("OVL%dClockOff\n",idx);
	//store registers
	// OVLRegRestore(module,handle);
	DISP_REG_SET(handle, idx * DISP_INDEX_OFFSET + DISP_REG_OVL_EN, 0x00);
	OVLReset(module,handle);
	DISP_REG_SET(handle,idx*DISP_INDEX_OFFSET+DISP_REG_OVL_INTEN, 0x00);
	DISP_REG_SET(handle, idx * DISP_INDEX_OFFSET + DISP_REG_OVL_INTSTA, 0x00);
	ddp_disable_module_clock(module);
	return;
}

void  OVLInit(DISP_MODULE_ENUM module,void * handle)
{
	//power on, no need to care clock
	int idx = ovl_index(module);
	ddp_enable_module_clock(module);
	return;
}

void  OVLDeInit(DISP_MODULE_ENUM module,void * handle)
{
	int idx = ovl_index(module);
	DDPMSG("OVL%dDeInit close CG \n",idx);
	ddp_disable_module_clock(module);
	return;
}

static inline int is_module_ovl(DISP_MODULE_ENUM module)
{
	if (module == DISP_MODULE_OVL0 ||
	    module == DISP_MODULE_OVL1 ||
	    module == DISP_MODULE_OVL0_2L ||
	    module == DISP_MODULE_OVL1_2L)
		return 1;
	else
		return 0;
}

int OVLConnect(DISP_MODULE_ENUM module, DISP_MODULE_ENUM prev,
		DISP_MODULE_ENUM next, int connect, void *handle)
{
	int idx = ovl_index(module);

	if (connect && is_module_ovl(prev))
		DISP_REG_SET_FIELD(handle, DATAPATH_CON_FLD_BGCLR_IN_SEL,
				   idx * DISP_INDEX_OFFSET + DISP_REG_OVL_DATAPATH_CON, 1);
	else
		DISP_REG_SET_FIELD(handle, DATAPATH_CON_FLD_BGCLR_IN_SEL,
				   idx * DISP_INDEX_OFFSET + DISP_REG_OVL_DATAPATH_CON, 0);
	return 0;
}

void OVLDump(DISP_MODULE_ENUM module)
{
	int idx = ovl_index(module);
	unsigned long offset = DISP_INDEX_OFFSET*idx;
	unsigned int src_on = DISP_REG_GET(DISP_REG_OVL_SRC_CON + offset);
	DDPDUMP("== DISP %s REGS ==\n", ddp_get_module_name(module));
	DDPDUMP("OVL:0x000=0x%08x,0x004=0x%08x,0x008=0x%08x,0x00c=0x%08x\n",
		DISP_REG_GET(DISP_REG_OVL_STA + offset),
		DISP_REG_GET(DISP_REG_OVL_INTEN + offset),
		DISP_REG_GET(DISP_REG_OVL_INTSTA + offset), DISP_REG_GET(DISP_REG_OVL_EN + offset));
	DDPDUMP("OVL:0x010=0x%08x,0x014=0x%08x,0x020=0x%08x,0x024=0x%08x\n",
		DISP_REG_GET(DISP_REG_OVL_TRIG + offset),
		DISP_REG_GET(DISP_REG_OVL_RST + offset),
		DISP_REG_GET(DISP_REG_OVL_ROI_SIZE + offset),
		DISP_REG_GET(DISP_REG_OVL_DATAPATH_CON + offset));
	DDPDUMP("OVL:0x028=0x%08x,0x02c=0x%08x\n",
		DISP_REG_GET(DISP_REG_OVL_ROI_BGCLR + offset),
		DISP_REG_GET(DISP_REG_OVL_SRC_CON + offset));

	if (src_on & 0x1) {
		DDPDUMP("OVL:0x030=0x%08x,0x034=0x%08x,0x038=0x%08x,0x03c=0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_L0_CON + offset),
			DISP_REG_GET(DISP_REG_OVL_L0_SRCKEY + offset),
			DISP_REG_GET(DISP_REG_OVL_L0_SRC_SIZE + offset),
			DISP_REG_GET(DISP_REG_OVL_L0_OFFSET + offset));

		DDPDUMP("OVL:0xf40=0x%08x,0x044=0x%08x,0x0c0=0x%08x,0x0c8=0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_L0_ADDR + offset),
			DISP_REG_GET(DISP_REG_OVL_L0_PITCH + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA0_CTRL + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA0_MEM_GMC_SETTING + offset));

		DDPDUMP("OVL:0x0d0=0x%08x,0x1e0=0x%08x,0x24c=0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_RDMA0_FIFO_CTRL + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA0_MEM_GMC_S2 + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA0_DBG + offset));
	}
	if (src_on & 0x2) {
		DDPDUMP("OVL:0x050=0x%08x,0x054=0x%08x,0x058=0x%08x,0x05c=0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_L1_CON + offset),
			DISP_REG_GET(DISP_REG_OVL_L1_SRCKEY + offset),
			DISP_REG_GET(DISP_REG_OVL_L1_SRC_SIZE + offset),
			DISP_REG_GET(DISP_REG_OVL_L1_OFFSET + offset));

		DDPDUMP("OVL:0xf60=0x%08x,0x064=0x%08x,0x0e0=0x%08x,0x0e8=0x%08x,0x0f0=0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_L1_ADDR + offset),
			DISP_REG_GET(DISP_REG_OVL_L1_PITCH + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA1_CTRL + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA1_MEM_GMC_SETTING + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA1_FIFO_CTRL + offset));

		DDPDUMP("OVL:0x1e4=0x%08x,0x250=0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_RDMA1_MEM_GMC_S2 + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA1_DBG + offset));
	}
	if (src_on & 0x4) {
		DDPDUMP("OVL:0x070=0x%08x,0x074=0x%08x,0x078=0x%08x,0x07c=0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_L2_CON + offset),
			DISP_REG_GET(DISP_REG_OVL_L2_SRCKEY + offset),
			DISP_REG_GET(DISP_REG_OVL_L2_SRC_SIZE + offset),
			DISP_REG_GET(DISP_REG_OVL_L2_OFFSET + offset));

		DDPDUMP("OVL:0xf80=0x%08x,0x084=0x%08x,0x100=0x%08x,0x110=0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_L2_ADDR + offset),
			DISP_REG_GET(DISP_REG_OVL_L2_PITCH + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA2_CTRL + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA2_FIFO_CTRL + offset));

		DDPDUMP("OVL:0x1e8=0x%08x,0x254=0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_RDMA2_MEM_GMC_S2 + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA2_DBG + offset));
	}
	if (src_on & 0x8) {
		DDPDUMP("OVL:0x090=0x%08x,0x094=0x%08x,0x098=0x%08x,0x09c=0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_L3_CON + offset),
			DISP_REG_GET(DISP_REG_OVL_L3_SRCKEY + offset),
			DISP_REG_GET(DISP_REG_OVL_L3_SRC_SIZE + offset),
			DISP_REG_GET(DISP_REG_OVL_L3_OFFSET + offset));

		DDPDUMP("OVL:0xfa0=0x%08x,0x0a4=0x%08x,0x120=0x%08x,0x130=0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_L3_ADDR + offset),
			DISP_REG_GET(DISP_REG_OVL_L3_PITCH + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA3_CTRL + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA3_FIFO_CTRL + offset));

		DDPDUMP("OVL:0x1ec=0x%08x,0x258=0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_RDMA3_MEM_GMC_S2 + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA3_DBG + offset));
	}
	DDPDUMP("OVL:0x1d4=0x%08x,0x1f8=0x%08x,0x1fc=0x%08x,0x200=0x%08x,0x20c=0x%08x\n"
		"0x210=0x%08x,0x214=0x%08x,0x218=0x%08x,0x21c=0x%08x\n"
		"0x230=0x%08x,0x234=0x%08x,0x240=0x%08x,0x244=0x%08x,0x2A0=0x%08x,0x2A4=0x%08x\n",
		DISP_REG_GET(DISP_REG_OVL_DEBUG_MON_SEL + offset),
		DISP_REG_GET(DISP_REG_OVL_RDMA_GREQ_NUM + offset),
		DISP_REG_GET(DISP_REG_OVL_RDMA_GREQ_URG_NUM + offset),
		DISP_REG_GET(DISP_REG_OVL_DUMMY_REG + offset),
		DISP_REG_GET(DISP_REG_OVL_RDMA_ULTRA_SRC + offset),

		DISP_REG_GET(DISP_REG_OVL_RDMAn_BUF_LOW(0) + offset),
		DISP_REG_GET(DISP_REG_OVL_RDMAn_BUF_LOW(1) + offset),
		DISP_REG_GET(DISP_REG_OVL_RDMAn_BUF_LOW(2) + offset),
		DISP_REG_GET(DISP_REG_OVL_RDMAn_BUF_LOW(3) + offset),

		DISP_REG_GET(DISP_REG_OVL_SMI_DBG + offset),
		DISP_REG_GET(DISP_REG_OVL_GREQ_LAYER_CNT + offset),
		DISP_REG_GET(DISP_REG_OVL_FLOW_CTRL_DBG + offset),
		DISP_REG_GET(DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET(DISP_REG_OVL_FUNC_DCM0 + offset),
		DISP_REG_GET(DISP_REG_OVL_FUNC_DCM1 + offset));
}

static void ovl_printf_status(unsigned int status)
{
	DDPDUMP("=OVL_FLOW_CONTROL_DEBUG=:\n");
	DDPDUMP("addcon_idle:%d,blend_idle:%d,out_valid:%d,out_ready:%d,out_idle:%d\n",
		(status >> 10) & (0x1),
		(status >> 11) & (0x1),
		(status >> 12) & (0x1), (status >> 13) & (0x1), (status >> 15) & (0x1)
	    );
	DDPDUMP("rdma3_idle:%d,rdma2_idle:%d,rdma1_idle:%d, rdma0_idle:%d,rst:%d\n",
		(status >> 16) & (0x1),
		(status >> 17) & (0x1),
		(status >> 18) & (0x1), (status >> 19) & (0x1), (status >> 20) & (0x1)
	    );
	DDPDUMP("trig:%d,frame_hwrst_done:%d,frame_swrst_done:%d,frame_underrun:%d,frame_done:%d\n",
		(status >> 21) & (0x1),
		(status >> 23) & (0x1),
		(status >> 24) & (0x1), (status >> 25) & (0x1), (status >> 26) & (0x1)
	    );
	DDPDUMP("ovl_running:%d,ovl_start:%d,ovl_clr:%d,reg_update:%d,ovl_upd_reg:%d\n",
		(status >> 27) & (0x1),
		(status >> 28) & (0x1),
		(status >> 29) & (0x1), (status >> 30) & (0x1), (status >> 31) & (0x1)
	    );

	DDPDUMP("ovl_fms_state:\n");
	switch (status & 0x3ff) {
	case 0x1:
		DDPDUMP("idle\n");
		break;
	case 0x2:
		DDPDUMP("wait_SOF\n");
		break;
	case 0x4:
		DDPDUMP("prepare\n");
		break;
	case 0x8:
		DDPDUMP("reg_update\n");
		break;
	case 0x10:
		DDPDUMP("eng_clr(internal reset)\n");
		break;
	case 0x20:
		DDPDUMP("eng_act(processing)\n");
		break;
	case 0x40:
		DDPDUMP("h_wait_w_rst\n");
		break;
	case 0x80:
		DDPDUMP("s_wait_w_rst\n");
		break;
	case 0x100:
		DDPDUMP("h_w_rst\n");
		break;
	case 0x200:
		DDPDUMP("s_w_rst\n");
		break;
	default:
		DDPDUMP("ovl_fsm_unknown\n");
		break;
	}

}

static void ovl_print_ovl_rdma_status(unsigned int status)
{
	DDPDUMP("wram_rst_cs:0x%x,layer_greq:0x%x,out_data:0x%x,",
		status & 0x7, (status >> 3) & 0x1, (status >> 4) & 0xffffff);
	DDPDUMP("out_ready:0x%x,out_valid:0x%x,smi_busy:0x%x,smi_greq:0x%x\n",
		(status >> 28) & 0x1, (status >> 29) & 0x1, (status >> 30) & 0x1,
		(status >> 31) & 0x1);
}


static void ovl_dump_layer_info(int layer, unsigned long layer_offset)
{
	DDPDUMP("layer%d: w=%d,h=%d,off(x=%d,y=%d),pitch=%d,addr=0x%x,fmt=%s,source=%s,aen=%d,alpha=%d\n",
	     layer, DISP_REG_GET(layer_offset + DISP_REG_OVL_L0_SRC_SIZE) & 0xfff,
	     (DISP_REG_GET(layer_offset + DISP_REG_OVL_L0_SRC_SIZE) >> 16) & 0xfff,
	     DISP_REG_GET(layer_offset + DISP_REG_OVL_L0_OFFSET) & 0xfff,
	     (DISP_REG_GET(layer_offset + DISP_REG_OVL_L0_OFFSET) >> 16) & 0xfff,
	     DISP_REG_GET(layer_offset + DISP_REG_OVL_L0_PITCH) & 0xffff,
	     DISP_REG_GET(layer_offset + DISP_REG_OVL_L0_ADDR),
	     ovl_intput_format_name(
			           DISP_REG_GET_FIELD(L_CON_FLD_CFMT, DISP_REG_OVL_L0_CON+layer_offset),
			           DISP_REG_GET_FIELD(L_CON_FLD_BTSW, DISP_REG_OVL_L0_CON+layer_offset)),

	     (DISP_REG_GET_FIELD(L_CON_FLD_LARC, DISP_REG_OVL_L0_CON + layer_offset) ==
	      0) ? "memory" : "constant_color", DISP_REG_GET_FIELD(L_CON_FLD_AEN,
								   DISP_REG_OVL_L0_CON +
								   layer_offset),

	     DISP_REG_GET_FIELD(L_CON_FLD_APHA, DISP_REG_OVL_L0_CON + layer_offset)
	    );
}


void ovl_dump_analysis(DISP_MODULE_ENUM module)
{
	int i = 0;
	unsigned int layer_offset = 0;
	unsigned int rdma_offset = 0;
	int idx = ovl_index(module);
	unsigned int offset = idx * DISP_INDEX_OFFSET;
	unsigned int src_on = DISP_REG_GET(DISP_REG_OVL_SRC_CON+offset);
	unsigned int rdma_ctrl;

	DDPDUMP("==DISP %s ANALYSIS==\n", ddp_get_module_name(module));
	DDPDUMP("ovl_en=%d,layer_enable(%d,%d,%d,%d),bg(w=%d, h=%d),",
		DISP_REG_GET(DISP_REG_OVL_EN + offset),
		DISP_REG_GET(DISP_REG_OVL_SRC_CON + offset) & 0x1,
		(DISP_REG_GET(DISP_REG_OVL_SRC_CON + offset) >> 1) & 0x1,
		(DISP_REG_GET(DISP_REG_OVL_SRC_CON + offset) >> 2) & 0x1,
		(DISP_REG_GET(DISP_REG_OVL_SRC_CON + offset) >> 3) & 0x1,
		DISP_REG_GET(DISP_REG_OVL_ROI_SIZE + offset) & 0xfff,
		(DISP_REG_GET(DISP_REG_OVL_ROI_SIZE + offset) >> 16) & 0xfff);
	DDPDUMP("cur_pos(x=%d,y=%d),layer_hit(%d,%d,%d,%d),bg_mode=%s,sta=0x%x\n",
		DISP_REG_GET_FIELD(ADDCON_DBG_FLD_ROI_X, DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET_FIELD(ADDCON_DBG_FLD_ROI_Y, DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET_FIELD(ADDCON_DBG_FLD_L0_WIN_HIT, DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET_FIELD(ADDCON_DBG_FLD_L1_WIN_HIT, DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET_FIELD(ADDCON_DBG_FLD_L2_WIN_HIT, DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET_FIELD(ADDCON_DBG_FLD_L3_WIN_HIT, DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET_FIELD(DATAPATH_CON_FLD_BGCLR_IN_SEL,
				   DISP_REG_OVL_DATAPATH_CON + offset) ? "directlink" : "const",
		DISP_REG_GET(DISP_REG_OVL_STA + offset)
	    );
	for (i = 0; i < 4; i++) {
		layer_offset = i * OVL_LAYER_OFFSET + offset;
		rdma_offset = i * OVL_RDMA_DEBUG_OFFSET + offset;
		if (src_on & (0x1 << i))
			ovl_dump_layer_info(i, layer_offset);
		else
			DDPDUMP("layer%d: disabled\n", i);

		rdma_ctrl = DISP_REG_GET(layer_offset + DISP_REG_OVL_RDMA0_CTRL);

		DDPDUMP("ovl rdma%d status:(en=%d, fifo_used %d, GMC=0x%x)\n", i,
			REG_FLD_VAL_GET(RDMA0_CTRL_FLD_RDMA_EN, rdma_ctrl),
			REG_FLD_VAL_GET(RDMA0_CTRL_FLD_RMDA_FIFO_USED_SZ, rdma_ctrl),
			DISP_REG_GET(layer_offset + DISP_REG_OVL_RDMA0_MEM_GMC_SETTING));
		ovl_print_ovl_rdma_status(DISP_REG_GET(DISP_REG_OVL_RDMA0_DBG + rdma_offset));
	}
	ovl_printf_status(DISP_REG_GET(DISP_REG_OVL_FLOW_CTRL_DBG + offset));
}

static inline unsigned long ovl_layer_num(DISP_MODULE_ENUM module)
{
	switch (module) {
	case DISP_MODULE_OVL0:
		return 4;
	case DISP_MODULE_OVL1:
		return 2;
	case DISP_MODULE_OVL0_2L:
		return 2;
	case DISP_MODULE_OVL1_2L:
		return 2;
	default:
		DDPERR("invalid ovl module=%d\n", module);
		ASSERT(0);
	}
	return 0;
}

static int OVLConfig_l(DISP_MODULE_ENUM module, disp_ddp_path_config* pConfig, void* handle)
{
	int i=0;
	int enabled_layers = 0;
	int local_layer = 0, global_layer = 0;
	int idx = ovl_index(module);

	if (pConfig->dst_dirty) {
		OVLROI(module,
		       pConfig->dst_w, // width
		       pConfig->dst_h, // height
		       0xFF000000,    // background color
		       handle);
	}

	if (!pConfig->ovl_dirty) {
		return 0;
	}

	for (global_layer = 0; global_layer < TOTAL_OVL_LAYER_NUM; global_layer++) {
		if (!(pConfig->ovl_layer_scanned & (1 << global_layer)))
			break;
	}
	if (global_layer > TOTAL_OVL_LAYER_NUM - ovl_layer_num(module)) {
		DDPERR("%s: %s scan error, layer_scanned=%u\n", __func__,
		       ddp_get_module_name(module), pConfig->ovl_layer_scanned);
		ASSERT(0);
	}

	for (local_layer = 0; local_layer < ovl_layer_num(module); local_layer++, global_layer++) {
		OVL_CONFIG_STRUCT *ovl_cfg = &pConfig->ovl_config[global_layer];

		pConfig->ovl_layer_scanned |= (1 << global_layer);

		if (ovl_cfg->layer_en == 0)
			continue;
		if (ovl_cfg->addr==0 || ovl_cfg->dst_w==0 || ovl_cfg->dst_h==0) {
			DDPERR("ovl parameter invalidate, addr=0x%x, w=%d, h=%d \n",
			       ovl_cfg->addr,
			       ovl_cfg->dst_w,
			       ovl_cfg->dst_h);
			return -1;
		}

		DDPDBG("module %d, layer=%d, en=%d, src=%d, fmt=%d, addr=0x%x, x=%d, y=%d, pitch=%d, dst(%d, %d, %d, %d),keyEn=%d, key=%d, aen=%d, alpha=%d\n",
		       module,
		       local_layer,
		       ovl_cfg->layer_en,
		       ovl_cfg->source,   // data source (0=memory)
		       ovl_cfg->fmt,
		       ovl_cfg->addr, // addr
		       ovl_cfg->src_x,  // x
		       ovl_cfg->src_y,  // y
		       ovl_cfg->src_pitch, //pitch, pixel number
		       ovl_cfg->dst_x,  // x
		       ovl_cfg->dst_y,  // y
		       ovl_cfg->dst_w, // width
		       ovl_cfg->dst_h, // height
		       ovl_cfg->keyEn,  //color key
		       ovl_cfg->key,  //color key
		       ovl_cfg->aen, // alpha enable
		       ovl_cfg->alpha);
		OVLLayerConfig(module,
			       local_layer,
			       ovl_cfg->source,
			       ovl_cfg->fmt,
			       ovl_cfg->addr,
			       ovl_cfg->src_x,
			       ovl_cfg->src_y,
			       ovl_cfg->src_pitch,
			       ovl_cfg->dst_x,
			       ovl_cfg->dst_y,
			       ovl_cfg->dst_w,
			       ovl_cfg->dst_h,
			       ovl_cfg->keyEn,
			       ovl_cfg->key,
			       ovl_cfg->aen,
			       ovl_cfg->alpha,
			       handle);
//	 	print_layer_config_args(module, local_layer, ovl_cfg);
//		ovl_layer_config(module, local_layer, has_sec_layer, ovl_cfg, handle);

		enabled_layers |= 1 << local_layer;

	}

	DISP_REG_SET(handle, idx * DISP_INDEX_OFFSET + DISP_REG_OVL_SRC_CON, enabled_layers);

	return 0;
}

DDP_MODULE_DRIVER ddp_driver_ovl = {
	.module          = DISP_MODULE_OVL0,
	.init            = OVLInit,
	.deinit          = OVLDeInit,
	.config          = OVLConfig_l,
	.start           = OVLStart,
	.trigger         = NULL,
	.stop            = OVLStop,
	.reset           = NULL,
	.power_on        = OVLClockOn,
	.power_off       = OVLClockOff,
	.is_idle         = NULL,
	.is_busy         = NULL,
	.dump_info       = NULL,
	.bypass          = NULL,
	.build_cmdq      = NULL,
	.set_lcm_utils   = NULL,
	.connect         = OVLConnect,
};

