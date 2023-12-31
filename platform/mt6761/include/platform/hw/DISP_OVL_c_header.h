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
#ifndef __DISP_OVL0_REGS_H__
#define __DISP_OVL0_REGS_H__


#ifdef __cplusplus
extern "C" {
#endif

#ifndef REG_BASE_C_MODULE
// ----------------- DISP_OVL0 Bit Field Definitions -------------------

#define PACKING
typedef unsigned int FIELD;

typedef PACKING union
{
    PACKING struct
    {
        FIELD OVL_RUN                   : 1;
        FIELD RDMA0_IDLE                : 1;
        FIELD RDMA1_IDLE                : 1;
        FIELD RDMA2_IDLE                : 1;
        FIELD RDMA3_IDLE                : 1;
        FIELD rsv_5                     : 27;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_STA, *PDISP_OVL0_REG_OVL_STA;

typedef PACKING union
{
    PACKING struct
    {
        FIELD OVL_REG_CMT_INTEN         : 1;
        FIELD OVL_FME_CPL_INTEN         : 1;
        FIELD OVL_FME_UND_INTEN         : 1;
        FIELD OVL_FME_SWRST_DONE_INTEN  : 1;
        FIELD OVL_FME_HWRST_DONE_INTEN  : 1;
        FIELD RDMA0_EOF_ABNORMAL_INTEN  : 1;
        FIELD RDMA1_EOF_ABNORMAL_INTEN  : 1;
        FIELD RDMA2_EOF_ABNORMAL_INTEN  : 1;
        FIELD RDMA3_EOF_ABNORMAL_INTEN  : 1;
        FIELD RDMA0_SMI_UNDERFLOW_INTEN : 1;
        FIELD RDMA1_SMI_UNDERFLOW_INTEN : 1;
        FIELD RDMA2_SMI_UNDERFLOW_INTEN : 1;
        FIELD RDMA3_SMI_UNDERFLOW_INTEN : 1;
        FIELD ABNORMAL_SOF_INTEN        : 1;
        FIELD OVL_START_INTEN           : 1;
        FIELD rsv_15                    : 17;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_INTEN, *PDISP_OVL0_REG_OVL_INTEN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD OVL_REG_CMT_INTSTA        : 1;
        FIELD OVL_FME_CPL_INTSTA        : 1;
        FIELD OVL_FME_UND_INTSTA        : 1;
        FIELD OVL_FME_SWRST_DONE_INTSTA : 1;
        FIELD OVL_FME_HWRST_DONE_INTSTA : 1;
        FIELD RDMA0_EOF_ABNORMAL_INTSTA : 1;
        FIELD RDMA1_EOF_ABNORMAL_INTSTA : 1;
        FIELD RDMA2_EOF_ABNORMAL_INTSTA : 1;
        FIELD RDMA3_EOF_ABNORMAL_INTSTA : 1;
        FIELD RDMA0_SMI_UNDERFLOW_INTSTA : 1;
        FIELD RDMA1_SMI_UNDERFLOW_INTSTA : 1;
        FIELD RDMA2_SMI_UNDERFLOW_INTSTA : 1;
        FIELD RDMA3_SMI_UNDERFLOW_INTSTA : 1;
        FIELD ABNORMAL_SOF_INTSTA       : 1;
        FIELD OVL_START_INTSTA          : 1;
        FIELD rsv_15                    : 17;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_INTSTA, *PDISP_OVL0_REG_OVL_INTSTA;

typedef PACKING union
{
    PACKING struct
    {
        FIELD OVL_EN                    : 1;
        FIELD rsv_1                     : 7;
        FIELD HG_FOVL_CK_ON             : 1;
        FIELD HG_FSMI_CK_ON             : 1;
        FIELD HF_FOVL_CK_ON             : 1;
        FIELD rsv_11                    : 5;
        FIELD IGNORE_ABNORMAL_SOF       : 1;
        FIELD rsv_17                    : 1;
        FIELD BLOCK_EXT_ULTRA           : 1;
        FIELD BLOCK_EXT_PREULTRA        : 1;
        FIELD rsv_20                    : 12;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EN, *PDISP_OVL0_REG_OVL_EN;

typedef PACKING union
{
    PACKING struct
    {
        FIELD OVL_SW_TRIG               : 1;
        FIELD rsv_1                     : 7;
        FIELD CRC_EN                    : 1;
        FIELD CRC_CLR                   : 1;
        FIELD rsv_10                    : 22;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_TRIG, *PDISP_OVL0_REG_OVL_TRIG;

typedef PACKING union
{
    PACKING struct
    {
        FIELD OVL_RST                   : 1;
        FIELD rsv_1                     : 27;
        FIELD OVL_SMI_RST               : 1;
        FIELD OVL_SMI_HARD_RST          : 1;
        FIELD OVL_SMI_IOBUF_RST         : 1;
        FIELD OVL_SMI_IOBUF_HARD_RST    : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RST, *PDISP_OVL0_REG_OVL_RST;

typedef PACKING union
{
    PACKING struct
    {
        FIELD ROI_W                     : 13;
        FIELD rsv_13                    : 3;
        FIELD ROI_H                     : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_ROI_SIZE, *PDISP_OVL0_REG_OVL_ROI_SIZE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD LAYER_SMI_ID_EN           : 1;
        FIELD OVL_RANDOM_BGCLR_EN       : 1;
        FIELD BGCLR_IN_SEL              : 1;
        FIELD OUTPUT_NO_RND             : 1;
        FIELD rsv_4                     : 4;
        FIELD L0_GPU_MODE               : 1;
        FIELD L1_GPU_MODE               : 1;
        FIELD L2_GPU_MODE               : 1;
        FIELD L3_GPU_MODE               : 1;
        FIELD ADOBE_MODE                : 1;
        FIELD ADOBE_LAYER               : 2;
        FIELD OVL_GAMMA_OUT             : 1;
        FIELD PQ_OUT_SEL                : 2;
        FIELD rsv_18                    : 2;
        FIELD RDMA0_OUT_SEL             : 1;
        FIELD RDMA1_OUT_SEL             : 1;
        FIELD RDMA2_OUT_SEL             : 1;
        FIELD RDMA3_OUT_SEL             : 1;
        FIELD GCLAST_EN                 : 1;
        FIELD rsv_25                    : 1;
        FIELD OUTPUT_CLAMP              : 1;
        FIELD OUTPUT_INTERLACE          : 1;
        FIELD rsv_28                    : 3;
        FIELD WIDE_GAMUT_EN             : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_DATAPATH_CON, *PDISP_OVL0_REG_OVL_DATAPATH_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD BLUE                      : 8;
        FIELD GREEN                     : 8;
        FIELD RED                       : 8;
        FIELD ALPHA                     : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_ROI_BGCLR, *PDISP_OVL0_REG_OVL_ROI_BGCLR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L0_EN                     : 1;
        FIELD L1_EN                     : 1;
        FIELD L2_EN                     : 1;
        FIELD L3_EN                     : 1;
        FIELD LC_EN                     : 1;
        FIELD rsv_5                     : 3;
        FIELD FORCE_RELAY_MODE          : 1;
        FIELD RELAY_MODE_EN             : 1;
        FIELD rsv_10                    : 22;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_SRC_CON, *PDISP_OVL0_REG_OVL_SRC_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD ALPHA                     : 8;
        FIELD ALPHA_EN                  : 1;
        FIELD VERTICAL_FLIP_EN          : 1;
        FIELD HORIZONTAL_FLIP_EN        : 1;
        FIELD EXT_MTX_EN                : 1;
        FIELD CLRFMT                    : 4;
        FIELD INT_MTX_SEL               : 4;
        FIELD EN_3D                     : 1;
        FIELD LANDSCAPE                 : 1;
        FIELD R_FIRST                   : 1;
        FIELD CLRFMT_MAN                : 1;
        FIELD BYTE_SWAP                 : 1;
        FIELD RGB_SWAP                  : 1;
        FIELD MTX_AUTO_DIS              : 1;
        FIELD MTX_EN                    : 1;
        FIELD LAYER_SRC                 : 2;
        FIELD SRCKEY_EN                 : 1;
        FIELD DSTKEY_EN                 : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_CON, *PDISP_OVL0_REG_OVL_L0_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD SRCKEY                    : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_SRCKEY, *PDISP_OVL0_REG_OVL_L0_SRCKEY;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L0_SRC_W                  : 13;
        FIELD rsv_13                    : 3;
        FIELD L0_SRC_H                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_SRC_SIZE, *PDISP_OVL0_REG_OVL_L0_SRC_SIZE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L0_XOFF                   : 13;
        FIELD rsv_13                    : 3;
        FIELD L0_YOFF                   : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_OFFSET, *PDISP_OVL0_REG_OVL_L0_OFFSET;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L0_SRC_PITCH              : 16;
        FIELD L0_SA_SEL                 : 2;
        FIELD L0_SRGB_SEL               : 2;
        FIELD L0_DA_SEL                 : 2;
        FIELD L0_DRGB_SEL               : 2;
        FIELD L0_SA_SEL_EXT             : 1;
        FIELD L0_SRGB_SEL_EXT           : 1;
        FIELD L0_DA_SEL_EXT             : 1;
        FIELD L0_DRGB_SEL_EXT           : 1;
        FIELD L0_CONST_BLD              : 1;
        FIELD L0_SRGB_SEL_EXT2          : 1;
        FIELD L0_BLEND_RND_SHT          : 1;
        FIELD SURFL_EN                  : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_PITCH, *PDISP_OVL0_REG_OVL_L0_PITCH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD TILE_HEIGHT               : 20;
        FIELD TILE_WIDTH_SEL            : 1;
        FIELD TILE_EN                   : 1;
        FIELD rsv_22                    : 2;
        FIELD TILE_HORI_BLOCK_NUM       : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_TILE, *PDISP_OVL0_REG_OVL_L0_TILE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L0_SRC_LEFT_CLIP          : 8;
        FIELD L0_SRC_RIGHT_CLIP         : 8;
        FIELD L0_SRC_TOP_CLIP           : 8;
        FIELD L0_SRC_BOTTOM_CLIP        : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_CLIP, *PDISP_OVL0_REG_OVL_L0_CLIP;

typedef PACKING union
{
    PACKING struct
    {
        FIELD ALPHA                     : 8;
        FIELD ALPHA_EN                  : 1;
        FIELD VERTICAL_FLIP_EN          : 1;
        FIELD HORIZONTAL_FLIP_EN        : 1;
        FIELD EXT_MTX_EN                : 1;
        FIELD CLRFMT                    : 4;
        FIELD INT_MTX_SEL               : 4;
        FIELD EN_3D                     : 1;
        FIELD LANDSCAPE                 : 1;
        FIELD R_FIRST                   : 1;
        FIELD CLRFMT_MAN                : 1;
        FIELD BYTE_SWAP                 : 1;
        FIELD RGB_SWAP                  : 1;
        FIELD MTX_AUTO_DIS              : 1;
        FIELD MTX_EN                    : 1;
        FIELD LAYER_SRC                 : 2;
        FIELD SRCKEY_EN                 : 1;
        FIELD DSTKEY_EN                 : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_CON, *PDISP_OVL0_REG_OVL_L1_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD SRCKEY                    : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_SRCKEY, *PDISP_OVL0_REG_OVL_L1_SRCKEY;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L1_SRC_W                  : 13;
        FIELD rsv_13                    : 3;
        FIELD L1_SRC_H                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_SRC_SIZE, *PDISP_OVL0_REG_OVL_L1_SRC_SIZE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L1_XOFF                   : 13;
        FIELD rsv_13                    : 3;
        FIELD L1_YOFF                   : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_OFFSET, *PDISP_OVL0_REG_OVL_L1_OFFSET;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L1_SRC_PITCH              : 16;
        FIELD L1_SA_SEL                 : 2;
        FIELD L1_SRGB_SEL               : 2;
        FIELD L1_DA_SEL                 : 2;
        FIELD L1_DRGB_SEL               : 2;
        FIELD L1_SA_SEL_EXT             : 1;
        FIELD L1_SRGB_SEL_EXT           : 1;
        FIELD L1_DA_SEL_EXT             : 1;
        FIELD L1_DRGB_SEL_EXT           : 1;
        FIELD L1_CONST_BLD              : 1;
        FIELD L1_SRGB_SEL_EXT2          : 1;
        FIELD L1_BLEND_RND_SHT          : 1;
        FIELD SURFL_EN                  : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_PITCH, *PDISP_OVL0_REG_OVL_L1_PITCH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD TILE_HEIGHT               : 20;
        FIELD TILE_WIDTH_SEL            : 1;
        FIELD TILE_EN                   : 1;
        FIELD rsv_22                    : 2;
        FIELD TILE_HORI_BLOCK_NUM       : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_TILE, *PDISP_OVL0_REG_OVL_L1_TILE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L1_SRC_LEFT_CLIP          : 8;
        FIELD L1_SRC_RIGHT_CLIP         : 8;
        FIELD L1_SRC_TOP_CLIP           : 8;
        FIELD L1_SRC_BOTTOM_CLIP        : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_CLIP, *PDISP_OVL0_REG_OVL_L1_CLIP;

typedef PACKING union
{
    PACKING struct
    {
        FIELD ALPHA                     : 8;
        FIELD ALPHA_EN                  : 1;
        FIELD VERTICAL_FLIP_EN          : 1;
        FIELD HORIZONTAL_FLIP_EN        : 1;
        FIELD EXT_MTX_EN                : 1;
        FIELD CLRFMT                    : 4;
        FIELD INT_MTX_SEL               : 4;
        FIELD EN_3D                     : 1;
        FIELD LANDSCAPE                 : 1;
        FIELD R_FIRST                   : 1;
        FIELD CLRFMT_MAN                : 1;
        FIELD BYTE_SWAP                 : 1;
        FIELD RGB_SWAP                  : 1;
        FIELD MTX_AUTO_DIS              : 1;
        FIELD MTX_EN                    : 1;
        FIELD LAYER_SRC                 : 2;
        FIELD SRCKEY_EN                 : 1;
        FIELD DSTKEY_EN                 : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_CON, *PDISP_OVL0_REG_OVL_L2_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD SRCKEY                    : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_SRCKEY, *PDISP_OVL0_REG_OVL_L2_SRCKEY;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L2_SRC_W                  : 13;
        FIELD rsv_13                    : 3;
        FIELD L2_SRC_H                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_SRC_SIZE, *PDISP_OVL0_REG_OVL_L2_SRC_SIZE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L2_XOFF                   : 13;
        FIELD rsv_13                    : 3;
        FIELD L2_YOFF                   : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_OFFSET, *PDISP_OVL0_REG_OVL_L2_OFFSET;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L2_SRC_PITCH              : 16;
        FIELD L2_SA_SEL                 : 2;
        FIELD L2_SRGB_SEL               : 2;
        FIELD L2_DA_SEL                 : 2;
        FIELD L2_DRGB_SEL               : 2;
        FIELD L2_SA_SEL_EXT             : 1;
        FIELD L2_SRGB_SEL_EXT           : 1;
        FIELD L2_DA_SEL_EXT             : 1;
        FIELD L2_DRGB_SEL_EXT           : 1;
        FIELD L2_CONST_BLD              : 1;
        FIELD L2_SRGB_SEL_EXT2          : 1;
        FIELD L2_BLEND_RND_SHT          : 1;
        FIELD SURFL_EN                  : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_PITCH, *PDISP_OVL0_REG_OVL_L2_PITCH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD TILE_HEIGHT               : 20;
        FIELD TILE_WIDTH_SEL            : 1;
        FIELD TILE_EN                   : 1;
        FIELD rsv_22                    : 2;
        FIELD TILE_HORI_BLOCK_NUM       : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_TILE, *PDISP_OVL0_REG_OVL_L2_TILE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L2_SRC_LEFT_CLIP          : 8;
        FIELD L2_SRC_RIGHT_CLIP         : 8;
        FIELD L2_SRC_TOP_CLIP           : 8;
        FIELD L2_SRC_BOTTOM_CLIP        : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_CLIP, *PDISP_OVL0_REG_OVL_L2_CLIP;

typedef PACKING union
{
    PACKING struct
    {
        FIELD ALPHA                     : 8;
        FIELD ALPHA_EN                  : 1;
        FIELD VERTICAL_FLIP_EN          : 1;
        FIELD HORIZONTAL_FLIP_EN        : 1;
        FIELD EXT_MTX_EN                : 1;
        FIELD CLRFMT                    : 4;
        FIELD INT_MTX_SEL               : 4;
        FIELD EN_3D                     : 1;
        FIELD LANDSCAPE                 : 1;
        FIELD R_FIRST                   : 1;
        FIELD CLRFMT_MAN                : 1;
        FIELD BYTE_SWAP                 : 1;
        FIELD RGB_SWAP                  : 1;
        FIELD MTX_AUTO_DIS              : 1;
        FIELD MTX_EN                    : 1;
        FIELD LAYER_SRC                 : 2;
        FIELD SRCKEY_EN                 : 1;
        FIELD DSTKEY_EN                 : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_CON, *PDISP_OVL0_REG_OVL_L3_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD SRCKEY                    : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_SRCKEY, *PDISP_OVL0_REG_OVL_L3_SRCKEY;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L3_SRC_W                  : 13;
        FIELD rsv_13                    : 3;
        FIELD L3_SRC_H                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_SRC_SIZE, *PDISP_OVL0_REG_OVL_L3_SRC_SIZE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L3_XOFF                   : 13;
        FIELD rsv_13                    : 3;
        FIELD L3_YOFF                   : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_OFFSET, *PDISP_OVL0_REG_OVL_L3_OFFSET;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L3_SRC_PITCH              : 16;
        FIELD L3_SA_SEL                 : 2;
        FIELD L3_SRGB_SEL               : 2;
        FIELD L3_DA_SEL                 : 2;
        FIELD L3_DRGB_SEL               : 2;
        FIELD L3_SA_SEL_EXT             : 1;
        FIELD L3_SRGB_SEL_EXT           : 1;
        FIELD L3_DA_SEL_EXT             : 1;
        FIELD L3_DRGB_SEL_EXT           : 1;
        FIELD L3_CONST_BLD              : 1;
        FIELD L3_SRGB_SEL_EXT2          : 1;
        FIELD L3_BLEND_RND_SHT          : 1;
        FIELD SURFL_EN                  : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_PITCH, *PDISP_OVL0_REG_OVL_L3_PITCH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD TILE_HEIGHT               : 20;
        FIELD TILE_WIDTH_SEL            : 1;
        FIELD TILE_EN                   : 1;
        FIELD rsv_22                    : 2;
        FIELD TILE_HORI_BLOCK_NUM       : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_TILE, *PDISP_OVL0_REG_OVL_L3_TILE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L3_SRC_LEFT_CLIP          : 8;
        FIELD L3_SRC_RIGHT_CLIP         : 8;
        FIELD L3_SRC_TOP_CLIP           : 8;
        FIELD L3_SRC_BOTTOM_CLIP        : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_CLIP, *PDISP_OVL0_REG_OVL_L3_CLIP;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA0_EN                  : 1;
        FIELD rsv_1                     : 3;
        FIELD RDMA0_INTERLACE           : 1;
        FIELD rsv_5                     : 11;
        FIELD RDMA0_FIFO_USED_SIZE      : 12;
        FIELD rsv_28                    : 4;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA0_CTRL, *PDISP_OVL0_REG_OVL_RDMA0_CTRL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA0_OSTD_ULTRA_TH       : 10;
        FIELD rsv_10                    : 6;
        FIELD RDMA0_OSTD_PREULTRA_TH    : 10;
        FIELD rsv_26                    : 2;
        FIELD RDMA0_ULTRA_THRESHOLD_HIGH_OFS : 1;
        FIELD rsv_29                    : 2;
        FIELD RDMA0_PRE_ULTRA_THRESHOLD_HIGH_OFS : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA0_MEM_GMC_SETTING1, *PDISP_OVL0_REG_OVL_RDMA0_MEM_GMC_SETTING1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA0_SLOW_EN             : 1;
        FIELD rsv_1                     : 15;
        FIELD RDMA0_SLOW_CNT            : 16;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA0_MEM_SLOW_CON, *PDISP_OVL0_REG_OVL_RDMA0_MEM_SLOW_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA0_FIFO_THRD           : 10;
        FIELD rsv_10                    : 6;
        FIELD RDMA0_FIFO_SIZE           : 12;
        FIELD rsv_28                    : 3;
        FIELD RDMA0_FIFO_UND_EN         : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA0_FIFO_CTRL, *PDISP_OVL0_REG_OVL_RDMA0_FIFO_CTRL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA1_EN                  : 1;
        FIELD rsv_1                     : 3;
        FIELD RDMA1_INTERLACE           : 1;
        FIELD rsv_5                     : 11;
        FIELD RDMA1_FIFO_USED_SIZE      : 12;
        FIELD rsv_28                    : 4;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA1_CTRL, *PDISP_OVL0_REG_OVL_RDMA1_CTRL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA1_OSTD_ULTRA_TH       : 10;
        FIELD rsv_10                    : 6;
        FIELD RDMA1_OSTD_PREULTRA_TH    : 10;
        FIELD rsv_26                    : 2;
        FIELD RDMA1_ULTRA_THRESHOLD_HIGH_OFS : 1;
        FIELD rsv_29                    : 2;
        FIELD RDMA1_PRE_ULTRA_THRESHOLD_HIGH_OFS : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA1_MEM_GMC_SETTING1, *PDISP_OVL0_REG_OVL_RDMA1_MEM_GMC_SETTING1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA1_SLOW_EN             : 1;
        FIELD rsv_1                     : 15;
        FIELD RDMA1_SLOW_CNT            : 16;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA1_MEM_SLOW_CON, *PDISP_OVL0_REG_OVL_RDMA1_MEM_SLOW_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA1_FIFO_THRD           : 10;
        FIELD rsv_10                    : 6;
        FIELD RDMA1_FIFO_SIZE           : 12;
        FIELD rsv_28                    : 3;
        FIELD RDMA1_FIFO_UND_EN         : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA1_FIFO_CTRL, *PDISP_OVL0_REG_OVL_RDMA1_FIFO_CTRL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA2_EN                  : 1;
        FIELD rsv_1                     : 3;
        FIELD RDMA2_INTERLACE           : 1;
        FIELD rsv_5                     : 11;
        FIELD RDMA2_FIFO_USED_SIZE      : 12;
        FIELD rsv_28                    : 4;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA2_CTRL, *PDISP_OVL0_REG_OVL_RDMA2_CTRL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA2_OSTD_ULTRA_TH       : 10;
        FIELD rsv_10                    : 6;
        FIELD RDMA2_OSTD_PREULTRA_TH    : 10;
        FIELD rsv_26                    : 2;
        FIELD RDMA2_ULTRA_THRESHOLD_HIGH_OFS : 1;
        FIELD rsv_29                    : 2;
        FIELD RDMA2_PRE_ULTRA_THRESHOLD_HIGH_OFS : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA2_MEM_GMC_SETTING1, *PDISP_OVL0_REG_OVL_RDMA2_MEM_GMC_SETTING1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA2_SLOW_EN             : 1;
        FIELD rsv_1                     : 15;
        FIELD RDMA2_SLOW_CNT            : 16;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA2_MEM_SLOW_CON, *PDISP_OVL0_REG_OVL_RDMA2_MEM_SLOW_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA2_FIFO_THRD           : 10;
        FIELD rsv_10                    : 6;
        FIELD RDMA2_FIFO_SIZE           : 12;
        FIELD rsv_28                    : 3;
        FIELD RDMA2_FIFO_UND_EN         : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA2_FIFO_CTRL, *PDISP_OVL0_REG_OVL_RDMA2_FIFO_CTRL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA3_EN                  : 1;
        FIELD rsv_1                     : 3;
        FIELD RDMA3_INTERLACE           : 1;
        FIELD rsv_5                     : 11;
        FIELD RDMA3_FIFO_USED_SIZE      : 12;
        FIELD rsv_28                    : 4;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA3_CTRL, *PDISP_OVL0_REG_OVL_RDMA3_CTRL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA3_OSTD_ULTRA_TH       : 10;
        FIELD rsv_10                    : 6;
        FIELD RDMA3_OSTD_PREULTRA_TH    : 10;
        FIELD rsv_26                    : 2;
        FIELD RDMA3_ULTRA_THRESHOLD_HIGH_OFS : 1;
        FIELD rsv_29                    : 2;
        FIELD RDMA3_PRE_ULTRA_THRESHOLD_HIGH_OFS : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA3_MEM_GMC_SETTING1, *PDISP_OVL0_REG_OVL_RDMA3_MEM_GMC_SETTING1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA3_SLOW_EN             : 1;
        FIELD rsv_1                     : 15;
        FIELD RDMA3_SLOW_CNT            : 16;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA3_MEM_SLOW_CON, *PDISP_OVL0_REG_OVL_RDMA3_MEM_SLOW_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA3_FIFO_THRD           : 10;
        FIELD rsv_10                    : 6;
        FIELD RDMA3_FIFO_SIZE           : 12;
        FIELD rsv_28                    : 3;
        FIELD RDMA3_FIFO_UND_EN         : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA3_FIFO_CTRL, *PDISP_OVL0_REG_OVL_RDMA3_FIFO_CTRL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_RMY                  : 13;
        FIELD rsv_13                    : 3;
        FIELD C_CF_RMU                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_Y2R_PARA_R0, *PDISP_OVL0_REG_OVL_L0_Y2R_PARA_R0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_RMV                  : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_Y2R_PARA_R1, *PDISP_OVL0_REG_OVL_L0_Y2R_PARA_R1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_GMY                  : 13;
        FIELD rsv_13                    : 3;
        FIELD C_CF_GMU                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_Y2R_PARA_G0, *PDISP_OVL0_REG_OVL_L0_Y2R_PARA_G0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_GMV                  : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_Y2R_PARA_G1, *PDISP_OVL0_REG_OVL_L0_Y2R_PARA_G1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_BMY                  : 13;
        FIELD rsv_13                    : 3;
        FIELD C_CF_BMU                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_Y2R_PARA_B0, *PDISP_OVL0_REG_OVL_L0_Y2R_PARA_B0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_BMV                  : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_Y2R_PARA_B1, *PDISP_OVL0_REG_OVL_L0_Y2R_PARA_B1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_YA                   : 9;
        FIELD rsv_9                     : 7;
        FIELD C_CF_UA                   : 9;
        FIELD rsv_25                    : 7;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_Y2R_PARA_YUV_A_0, *PDISP_OVL0_REG_OVL_L0_Y2R_PARA_YUV_A_0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_VA                   : 9;
        FIELD rsv_9                     : 23;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_Y2R_PARA_YUV_A_1, *PDISP_OVL0_REG_OVL_L0_Y2R_PARA_YUV_A_1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_RA                   : 9;
        FIELD rsv_9                     : 7;
        FIELD C_CF_GA                   : 9;
        FIELD rsv_25                    : 7;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_Y2R_PARA_RGB_A_0, *PDISP_OVL0_REG_OVL_L0_Y2R_PARA_RGB_A_0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_BA                   : 9;
        FIELD rsv_9                     : 23;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_Y2R_PARA_RGB_A_1, *PDISP_OVL0_REG_OVL_L0_Y2R_PARA_RGB_A_1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_RMY                  : 13;
        FIELD rsv_13                    : 3;
        FIELD C_CF_RMU                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_Y2R_PARA_R0, *PDISP_OVL0_REG_OVL_L1_Y2R_PARA_R0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_RMV                  : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_Y2R_PARA_R1, *PDISP_OVL0_REG_OVL_L1_Y2R_PARA_R1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_GMY                  : 13;
        FIELD rsv_13                    : 3;
        FIELD C_CF_GMU                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_Y2R_PARA_G0, *PDISP_OVL0_REG_OVL_L1_Y2R_PARA_G0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_GMV                  : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_Y2R_PARA_G1, *PDISP_OVL0_REG_OVL_L1_Y2R_PARA_G1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_BMY                  : 13;
        FIELD rsv_13                    : 3;
        FIELD C_CF_BMU                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_Y2R_PARA_B0, *PDISP_OVL0_REG_OVL_L1_Y2R_PARA_B0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_BMV                  : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_Y2R_PARA_B1, *PDISP_OVL0_REG_OVL_L1_Y2R_PARA_B1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_YA                   : 9;
        FIELD rsv_9                     : 7;
        FIELD C_CF_UA                   : 9;
        FIELD rsv_25                    : 7;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_Y2R_PARA_YUV_A_0, *PDISP_OVL0_REG_OVL_L1_Y2R_PARA_YUV_A_0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_VA                   : 9;
        FIELD rsv_9                     : 23;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_Y2R_PARA_YUV_A_1, *PDISP_OVL0_REG_OVL_L1_Y2R_PARA_YUV_A_1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_RA                   : 9;
        FIELD rsv_9                     : 7;
        FIELD C_CF_GA                   : 9;
        FIELD rsv_25                    : 7;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_Y2R_PARA_RGB_A_0, *PDISP_OVL0_REG_OVL_L1_Y2R_PARA_RGB_A_0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_BA                   : 9;
        FIELD rsv_9                     : 23;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_Y2R_PARA_RGB_A_1, *PDISP_OVL0_REG_OVL_L1_Y2R_PARA_RGB_A_1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_RMY                  : 13;
        FIELD rsv_13                    : 3;
        FIELD C_CF_RMU                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_Y2R_PARA_R0, *PDISP_OVL0_REG_OVL_L2_Y2R_PARA_R0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_RMV                  : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_Y2R_PARA_R1, *PDISP_OVL0_REG_OVL_L2_Y2R_PARA_R1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_GMY                  : 13;
        FIELD rsv_13                    : 3;
        FIELD C_CF_GMU                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_Y2R_PARA_G0, *PDISP_OVL0_REG_OVL_L2_Y2R_PARA_G0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_GMV                  : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_Y2R_PARA_G1, *PDISP_OVL0_REG_OVL_L2_Y2R_PARA_G1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_BMY                  : 13;
        FIELD rsv_13                    : 3;
        FIELD C_CF_BMU                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_Y2R_PARA_B0, *PDISP_OVL0_REG_OVL_L2_Y2R_PARA_B0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_BMV                  : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_Y2R_PARA_B1, *PDISP_OVL0_REG_OVL_L2_Y2R_PARA_B1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_YA                   : 9;
        FIELD rsv_9                     : 7;
        FIELD C_CF_UA                   : 9;
        FIELD rsv_25                    : 7;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_Y2R_PARA_YUV_A_0, *PDISP_OVL0_REG_OVL_L2_Y2R_PARA_YUV_A_0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_VA                   : 9;
        FIELD rsv_9                     : 23;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_Y2R_PARA_YUV_A_1, *PDISP_OVL0_REG_OVL_L2_Y2R_PARA_YUV_A_1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_RA                   : 9;
        FIELD rsv_9                     : 7;
        FIELD C_CF_GA                   : 9;
        FIELD rsv_25                    : 7;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_Y2R_PARA_RGB_A_0, *PDISP_OVL0_REG_OVL_L2_Y2R_PARA_RGB_A_0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_BA                   : 9;
        FIELD rsv_9                     : 23;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_Y2R_PARA_RGB_A_1, *PDISP_OVL0_REG_OVL_L2_Y2R_PARA_RGB_A_1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_RMY                  : 13;
        FIELD rsv_13                    : 3;
        FIELD C_CF_RMU                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_Y2R_PARA_R0, *PDISP_OVL0_REG_OVL_L3_Y2R_PARA_R0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_RMV                  : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_Y2R_PARA_R1, *PDISP_OVL0_REG_OVL_L3_Y2R_PARA_R1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_GMY                  : 13;
        FIELD rsv_13                    : 3;
        FIELD C_CF_GMU                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_Y2R_PARA_G0, *PDISP_OVL0_REG_OVL_L3_Y2R_PARA_G0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_GMV                  : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_Y2R_PARA_G1, *PDISP_OVL0_REG_OVL_L3_Y2R_PARA_G1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_BMY                  : 13;
        FIELD rsv_13                    : 3;
        FIELD C_CF_BMU                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_Y2R_PARA_B0, *PDISP_OVL0_REG_OVL_L3_Y2R_PARA_B0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_BMV                  : 13;
        FIELD rsv_13                    : 19;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_Y2R_PARA_B1, *PDISP_OVL0_REG_OVL_L3_Y2R_PARA_B1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_YA                   : 9;
        FIELD rsv_9                     : 7;
        FIELD C_CF_UA                   : 9;
        FIELD rsv_25                    : 7;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_Y2R_PARA_YUV_A_0, *PDISP_OVL0_REG_OVL_L3_Y2R_PARA_YUV_A_0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_VA                   : 9;
        FIELD rsv_9                     : 23;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_Y2R_PARA_YUV_A_1, *PDISP_OVL0_REG_OVL_L3_Y2R_PARA_YUV_A_1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_RA                   : 9;
        FIELD rsv_9                     : 7;
        FIELD C_CF_GA                   : 9;
        FIELD rsv_25                    : 7;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_Y2R_PARA_RGB_A_0, *PDISP_OVL0_REG_OVL_L3_Y2R_PARA_RGB_A_0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD C_CF_BA                   : 9;
        FIELD rsv_9                     : 23;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_Y2R_PARA_RGB_A_1, *PDISP_OVL0_REG_OVL_L3_Y2R_PARA_RGB_A_1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD DBG_MON_SEL               : 4;
        FIELD rsv_4                     : 28;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_DEBUG_MON_SEL, *PDISP_OVL0_REG_OVL_DEBUG_MON_SEL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L0_MINUS_BLD              : 1;
        FIELD L1_MINUS_BLD              : 1;
        FIELD L2_MINUS_BLD              : 1;
        FIELD L3_MINUS_BLD              : 1;
        FIELD LC_MINUS_BLD              : 1;
        FIELD EL0_MINUS_BLD             : 1;
        FIELD EL1_MINUS_BLD             : 1;
        FIELD EL2_MINUS_BLD             : 1;
        FIELD rsv_8                     : 24;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_BLD_EXT, *PDISP_OVL0_REG_OVL_BLD_EXT;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA0_ISSUE_REQ_THRESHOLD : 12;
        FIELD rsv_12                    : 4;
        FIELD RDMA0_ISSUE_REQ_THRESHOLD_URG : 12;
        FIELD RDMA0_REQ_THRESHOLD_PREULTRA : 1;
        FIELD RDMA0_REQ_THRESHOLD_ULTRA : 1;
        FIELD RDMA0_FORCE_REQ_THRESHOLD : 1;
        FIELD rsv_31                    : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA0_MEM_GMC_SETTING2, *PDISP_OVL0_REG_OVL_RDMA0_MEM_GMC_SETTING2;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA1_ISSUE_REQ_THRESHOLD : 12;
        FIELD rsv_12                    : 4;
        FIELD RDMA1_ISSUE_REQ_THRESHOLD_URG : 12;
        FIELD RDMA1_REQ_THRESHOLD_PREULTRA : 1;
        FIELD RDMA1_REQ_THRESHOLD_ULTRA : 1;
        FIELD RDMA1_FORCE_REQ_THRESHOLD : 1;
        FIELD rsv_31                    : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA1_MEM_GMC_SETTING2, *PDISP_OVL0_REG_OVL_RDMA1_MEM_GMC_SETTING2;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA2_ISSUE_REQ_THRESHOLD : 12;
        FIELD rsv_12                    : 4;
        FIELD RDMA2_ISSUE_REQ_THRESHOLD_URG : 12;
        FIELD RDMA2_REQ_THRESHOLD_PREULTRA : 1;
        FIELD RDMA2_REQ_THRESHOLD_ULTRA : 1;
        FIELD RDMA2_FORCE_REQ_THRESHOLD : 1;
        FIELD rsv_31                    : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA2_MEM_GMC_SETTING2, *PDISP_OVL0_REG_OVL_RDMA2_MEM_GMC_SETTING2;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA3_ISSUE_REQ_THRESHOLD : 12;
        FIELD rsv_12                    : 4;
        FIELD RDMA3_ISSUE_REQ_THRESHOLD_URG : 12;
        FIELD RDMA3_REQ_THRESHOLD_PREULTRA : 1;
        FIELD RDMA3_REQ_THRESHOLD_ULTRA : 1;
        FIELD RDMA3_FORCE_REQ_THRESHOLD : 1;
        FIELD rsv_31                    : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA3_MEM_GMC_SETTING2, *PDISP_OVL0_REG_OVL_RDMA3_MEM_GMC_SETTING2;

typedef PACKING union
{
    PACKING struct
    {
        FIELD BURST9A_32B               : 3;
        FIELD rsv_3                     : 1;
        FIELD BURST10A_32B              : 3;
        FIELD rsv_7                     : 1;
        FIELD BURST11A_32B              : 3;
        FIELD rsv_11                    : 1;
        FIELD BURST12A_32B              : 3;
        FIELD rsv_15                    : 1;
        FIELD BURST13A_32B              : 3;
        FIELD rsv_19                    : 1;
        FIELD BURST14A_32B              : 3;
        FIELD rsv_23                    : 1;
        FIELD BURST15A_32B              : 3;
        FIELD rsv_27                    : 1;
        FIELD BURST_128B_BOUND          : 1;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA_BURST_CON0, *PDISP_OVL0_REG_OVL_RDMA_BURST_CON0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD BURST9A_N32B              : 3;
        FIELD rsv_3                     : 1;
        FIELD BURST10A_N32B             : 3;
        FIELD rsv_7                     : 1;
        FIELD BURST11A_N32B             : 3;
        FIELD rsv_11                    : 1;
        FIELD BURST12A_N32B             : 3;
        FIELD rsv_15                    : 1;
        FIELD BURST13A_N32B             : 3;
        FIELD rsv_19                    : 1;
        FIELD BURST14A_N32B             : 3;
        FIELD rsv_23                    : 1;
        FIELD BURST15A_N32B             : 3;
        FIELD rsv_27                    : 5;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA_BURST_CON1, *PDISP_OVL0_REG_OVL_RDMA_BURST_CON1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD LAYER0_GREQ_NUM           : 4;
        FIELD LAYER1_GREQ_NUM           : 4;
        FIELD LAYER2_GREQ_NUM           : 4;
        FIELD LAYER3_GREQ_NUM           : 4;
        FIELD OSTD_GREQ_NUM             : 8;
        FIELD GREQ_DIS_CNT              : 3;
        FIELD GREQ_STOP_EN              : 1;
        FIELD GRP_END_STOP              : 1;
        FIELD GRP_BRK_STOP              : 1;
        FIELD IOBUF_FLUSH_PREULTRA      : 1;
        FIELD IOBUF_FLUSH_ULTRA         : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA_GREQ_NUM, *PDISP_OVL0_REG_OVL_RDMA_GREQ_NUM;

typedef PACKING union
{
    PACKING struct
    {
        FIELD LAYER0_GREQ_URG_NUM       : 4;
        FIELD LAYER1_GREQ_URG_NUM       : 4;
        FIELD LAYER2_GREQ_URG_NUM       : 4;
        FIELD LAYER3_GREQ_URG_NUM       : 4;
        FIELD ARG_GREQ_URG_TH           : 10;
        FIELD rsv_26                    : 2;
        FIELD ARG_URG_BIAS              : 1;
        FIELD GREQ_NUM_SHT_VAL          : 1;
        FIELD GREQ_NUM_SHT              : 2;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA_GREQ_URG_NUM, *PDISP_OVL0_REG_OVL_RDMA_GREQ_URG_NUM;

typedef PACKING union
{
    PACKING struct
    {
        FIELD OVERLAY_DUMMY             : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_DUMMY_REG, *PDISP_OVL0_REG_OVL_DUMMY_REG;

typedef PACKING union
{
    PACKING struct
    {
        FIELD GDRDY_PRD                 : 24;
        FIELD rsv_24                    : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_GDRDY_PRD, *PDISP_OVL0_REG_OVL_GDRDY_PRD;

typedef PACKING union
{
    PACKING struct
    {
        FIELD PREULTRA_BUF_SRC          : 2;
        FIELD PREULTRA_SMI_SRC          : 2;
        FIELD PREULTRA_ROI_END_SRC      : 2;
        FIELD PREULTRA_RDMA_SRC         : 2;
        FIELD ULTRA_BUF_SRC             : 2;
        FIELD ULTRA_SMI_SRC             : 2;
        FIELD ULTRA_ROI_END_SRC         : 2;
        FIELD ULTRA_RDMA_SRC            : 2;
        FIELD rsv_16                    : 16;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA_ULTRA_SRC, *PDISP_OVL0_REG_OVL_RDMA_ULTRA_SRC;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA0_ULTRA_LOW_TH        : 12;
        FIELD RDMA0_PREULTRA_LOW_TH     : 12;
        FIELD rsv_24                    : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA0_BUF_LOW_TH, *PDISP_OVL0_REG_OVL_RDMA0_BUF_LOW_TH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA1_ULTRA_LOW_TH        : 12;
        FIELD RDMA1_PREULTRA_LOW_TH     : 12;
        FIELD rsv_24                    : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA1_BUF_LOW_TH, *PDISP_OVL0_REG_OVL_RDMA1_BUF_LOW_TH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA2_ULTRA_LOW_TH        : 12;
        FIELD RDMA2_PREULTRA_LOW_TH     : 12;
        FIELD rsv_24                    : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA2_BUF_LOW_TH, *PDISP_OVL0_REG_OVL_RDMA2_BUF_LOW_TH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA3_ULTRA_LOW_TH        : 12;
        FIELD RDMA3_PREULTRA_LOW_TH     : 12;
        FIELD rsv_24                    : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA3_BUF_LOW_TH, *PDISP_OVL0_REG_OVL_RDMA3_BUF_LOW_TH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD rsv_0                     : 12;
        FIELD RDMA0_PREULTRA_HIGH_TH    : 12;
        FIELD rsv_24                    : 7;
        FIELD RDMA0_PREULTRA_HIGH_DIS   : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA0_BUF_HIGH_TH, *PDISP_OVL0_REG_OVL_RDMA0_BUF_HIGH_TH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD rsv_0                     : 12;
        FIELD RDMA1_PREULTRA_HIGH_TH    : 12;
        FIELD rsv_24                    : 7;
        FIELD RDMA1_PREULTRA_HIGH_DIS   : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA1_BUF_HIGH_TH, *PDISP_OVL0_REG_OVL_RDMA1_BUF_HIGH_TH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD rsv_0                     : 12;
        FIELD RDMA2_PREULTRA_HIGH_TH    : 12;
        FIELD rsv_24                    : 7;
        FIELD RDMA2_PREULTRA_HIGH_DIS   : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA2_BUF_HIGH_TH, *PDISP_OVL0_REG_OVL_RDMA2_BUF_HIGH_TH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD rsv_0                     : 12;
        FIELD RDMA3_PREULTRA_HIGH_TH    : 12;
        FIELD rsv_24                    : 7;
        FIELD RDMA3_PREULTRA_HIGH_DIS   : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA3_BUF_HIGH_TH, *PDISP_OVL0_REG_OVL_RDMA3_BUF_HIGH_TH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD SMI_FSM                   : 10;
        FIELD rsv_10                    : 22;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_SMI_DBG, *PDISP_OVL0_REG_OVL_SMI_DBG;

typedef PACKING union
{
    PACKING struct
    {
        FIELD LAYER0_GREQ_CNT           : 6;
        FIELD rsv_6                     : 2;
        FIELD LAYER1_GREQ_CNT           : 6;
        FIELD rsv_14                    : 2;
        FIELD LAYER2_GREQ_CNT           : 6;
        FIELD rsv_22                    : 2;
        FIELD LAYER3_GREQ_CNT           : 6;
        FIELD rsv_30                    : 2;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_GREQ_LAYER_CNT, *PDISP_OVL0_REG_OVL_GREQ_LAYER_CNT;

typedef PACKING union
{
    PACKING struct
    {
        FIELD GDRDY_PRD_NUM             : 24;
        FIELD rsv_24                    : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_GDRDY_PRD_NUM, *PDISP_OVL0_REG_OVL_GDRDY_PRD_NUM;

typedef PACKING union
{
    PACKING struct
    {
        FIELD FSM_STATE                 : 10;
        FIELD ADDCON_IDLE               : 1;
        FIELD BLEND_IDLE                : 1;
        FIELD OVL_OUT_VALID             : 1;
        FIELD OVL_OUT_READY             : 1;
        FIELD rsv_14                    : 1;
        FIELD OUT_IDLE                  : 1;
        FIELD RDMA3_IDLE                : 1;
        FIELD RDMA2_IDLE                : 1;
        FIELD RDMA1_IDLE                : 1;
        FIELD RDMA0_IDLE                : 1;
        FIELD RST                       : 1;
        FIELD TRIG                      : 1;
        FIELD rsv_22                    : 1;
        FIELD FRAME_HWRST_DONE          : 1;
        FIELD FRAME_SWRST_DONE          : 1;
        FIELD FRAME_UNDERRUN            : 1;
        FIELD FRAME_DONE                : 1;
        FIELD OVL_RUNNING               : 1;
        FIELD OVL_START                 : 1;
        FIELD OVL_CLR                   : 1;
        FIELD REG_UPDATE                : 1;
        FIELD OVL_UPD_REG               : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_FLOW_CTRL_DBG, *PDISP_OVL0_REG_OVL_FLOW_CTRL_DBG;

typedef PACKING union
{
    PACKING struct
    {
        FIELD ROI_X                     : 13;
        FIELD rsv_13                    : 1;
        FIELD L0_WIN_HIT                : 1;
        FIELD L1_WIN_HIT                : 1;
        FIELD ROI_Y                     : 13;
        FIELD rsv_29                    : 1;
        FIELD L2_WIN_HIT                : 1;
        FIELD L3_WIN_HIT                : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_ADDCON_DBG, *PDISP_OVL0_REG_OVL_ADDCON_DBG;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA0_WRAM_RST_CS         : 3;
        FIELD RDMA0_LAYER_GREQ          : 1;
        FIELD RDMA0_OUT_DATA            : 24;
        FIELD RDMA0_OUT_READY           : 1;
        FIELD RDMA0_OUT_VALID           : 1;
        FIELD RDMA0_SMI_BUSY            : 1;
        FIELD SMI_GREQ                  : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA0_DBG, *PDISP_OVL0_REG_OVL_RDMA0_DBG;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA1_WRAM_RST_CS         : 3;
        FIELD RDMA1_LAYER_GREQ          : 1;
        FIELD RDMA1_OUT_DATA            : 24;
        FIELD RDMA1_OUT_READY           : 1;
        FIELD RDMA1_OUT_VALID           : 1;
        FIELD RDMA1_SMI_BUSY            : 1;
        FIELD SMI_GREQ                  : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA1_DBG, *PDISP_OVL0_REG_OVL_RDMA1_DBG;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA2_WRAM_RST_CS         : 3;
        FIELD RDMA2_LAYER_GREQ          : 1;
        FIELD RDMA2_OUT_DATA            : 24;
        FIELD RDMA2_OUT_READY           : 1;
        FIELD RDMA2_OUT_VALID           : 1;
        FIELD RDMA2_SMI_BUSY            : 1;
        FIELD SMI_GREQ                  : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA2_DBG, *PDISP_OVL0_REG_OVL_RDMA2_DBG;

typedef PACKING union
{
    PACKING struct
    {
        FIELD RDMA3_WRAM_RST_CS         : 3;
        FIELD RDMA3_LAYER_GREQ          : 1;
        FIELD RDMA3_OUT_DATA            : 24;
        FIELD RDMA3_OUT_READY           : 1;
        FIELD RDMA3_OUT_VALID           : 1;
        FIELD RDMA3_SMI_BUSY            : 1;
        FIELD SMI_GREQ                  : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_RDMA3_DBG, *PDISP_OVL0_REG_OVL_RDMA3_DBG;

typedef PACKING union
{
    PACKING struct
    {
        FIELD BLUE                      : 8;
        FIELD GREEN                     : 8;
        FIELD RED                       : 8;
        FIELD ALPHA                     : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_CLR, *PDISP_OVL0_REG_OVL_L0_CLR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD BLUE                      : 8;
        FIELD GREEN                     : 8;
        FIELD RED                       : 8;
        FIELD ALPHA                     : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_CLR, *PDISP_OVL0_REG_OVL_L1_CLR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD BLUE                      : 8;
        FIELD GREEN                     : 8;
        FIELD RED                       : 8;
        FIELD ALPHA                     : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_CLR, *PDISP_OVL0_REG_OVL_L2_CLR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD BLUE                      : 8;
        FIELD GREEN                     : 8;
        FIELD RED                       : 8;
        FIELD ALPHA                     : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_CLR, *PDISP_OVL0_REG_OVL_L3_CLR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD BLUE                      : 8;
        FIELD GREEN                     : 8;
        FIELD RED                       : 8;
        FIELD ALPHA                     : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_LC_CLR, *PDISP_OVL0_REG_OVL_LC_CLR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD CRC_OUT                   : 31;
        FIELD CRC_RDY                   : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_CRC, *PDISP_OVL0_REG_OVL_CRC;

typedef PACKING union
{
    PACKING struct
    {
        FIELD ALPHA                     : 8;
        FIELD ALPHA_EN                  : 1;
        FIELD rsv_9                     : 11;
        FIELD EN_3D                     : 1;
        FIELD LANDSCAPE                 : 1;
        FIELD R_FIRST                   : 1;
        FIELD rsv_23                    : 5;
        FIELD LAYER_SRC                 : 2;
        FIELD SRCKEY_EN                 : 1;
        FIELD DSTKEY_EN                 : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_LC_CON, *PDISP_OVL0_REG_OVL_LC_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD SRCKEY                    : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_LC_SRCKEY, *PDISP_OVL0_REG_OVL_LC_SRCKEY;

typedef PACKING union
{
    PACKING struct
    {
        FIELD LC_SRC_W                  : 13;
        FIELD rsv_13                    : 3;
        FIELD LC_SRC_H                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_LC_SRC_SIZE, *PDISP_OVL0_REG_OVL_LC_SRC_SIZE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD LC_XOFF                   : 12;
        FIELD rsv_12                    : 4;
        FIELD LC_YOFF                   : 12;
        FIELD rsv_28                    : 4;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_LC_OFFSET, *PDISP_OVL0_REG_OVL_LC_OFFSET;

typedef PACKING union
{
    PACKING struct
    {
        FIELD CONST_LAYER_SEL           : 3;
        FIELD rsv_3                     : 13;
        FIELD LC_SA_SEL                 : 2;
        FIELD LC_SRGB_SEL               : 2;
        FIELD LC_DA_SEL                 : 2;
        FIELD LC_DRGB_SEL               : 2;
        FIELD LC_SA_SEL_EXT             : 1;
        FIELD LC_SRGB_SEL_EXT           : 1;
        FIELD LC_DA_SEL_EXT             : 1;
        FIELD LC_DRGB_SEL_EXT           : 1;
        FIELD LC_CONST_BLD              : 1;
        FIELD LC_SRGB_SEL_EXT2          : 1;
        FIELD LC_BLEND_RND_SHT          : 1;
        FIELD SURFL_EN                  : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_LC_SRC_SEL, *PDISP_OVL0_REG_OVL_LC_SRC_SEL;

typedef PACKING union
{
    PACKING struct
    {
        FIELD OVL_BANK_CON              : 5;
        FIELD rsv_5                     : 27;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_BANK_CON, *PDISP_OVL0_REG_OVL_BANK_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD OVL_FUNC_DCM0             : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_FUNC_DCM0, *PDISP_OVL0_REG_OVL_FUNC_DCM0;

typedef PACKING union
{
    PACKING struct
    {
        FIELD OVL_FUNC_DCM1             : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_FUNC_DCM1, *PDISP_OVL0_REG_OVL_FUNC_DCM1;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L0_DVFS_ROI_TB            : 13;
        FIELD rsv_13                    : 3;
        FIELD L0_DVFS_ROI_BB            : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_DVFS_L0_ROI, *PDISP_OVL0_REG_OVL_DVFS_L0_ROI;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L1_DVFS_ROI_TB            : 13;
        FIELD rsv_13                    : 3;
        FIELD L1_DVFS_ROI_BB            : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_DVFS_L1_ROI, *PDISP_OVL0_REG_OVL_DVFS_L1_ROI;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L2_DVFS_ROI_TB            : 13;
        FIELD rsv_13                    : 3;
        FIELD L2_DVFS_ROI_BB            : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_DVFS_L2_ROI, *PDISP_OVL0_REG_OVL_DVFS_L2_ROI;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L3_DVFS_ROI_TB            : 13;
        FIELD rsv_13                    : 3;
        FIELD L3_DVFS_ROI_BB            : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_DVFS_L3_ROI, *PDISP_OVL0_REG_OVL_DVFS_L3_ROI;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL0_DVFS_ROI_TB           : 13;
        FIELD rsv_13                    : 3;
        FIELD EL0_DVFS_ROI_BB           : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_DVFS_EL0_ROI, *PDISP_OVL0_REG_OVL_DVFS_EL0_ROI;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL1_DVFS_ROI_TB           : 13;
        FIELD rsv_13                    : 3;
        FIELD EL1_DVFS_ROI_BB           : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_DVFS_EL1_ROI, *PDISP_OVL0_REG_OVL_DVFS_EL1_ROI;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL2_DVFS_ROI_TB           : 13;
        FIELD rsv_13                    : 3;
        FIELD EL2_DVFS_ROI_BB           : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_DVFS_EL2_ROI, *PDISP_OVL0_REG_OVL_DVFS_EL2_ROI;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL0_EN                    : 1;
        FIELD EL1_EN                    : 1;
        FIELD EL2_EN                    : 1;
        FIELD rsv_3                     : 5;
        FIELD EL0_GPU_MODE              : 1;
        FIELD EL1_GPU_MODE              : 1;
        FIELD EL2_GPU_MODE              : 1;
        FIELD rsv_11                    : 5;
        FIELD EL0_LAYER_SEL             : 3;
        FIELD rsv_19                    : 1;
        FIELD EL1_LAYER_SEL             : 3;
        FIELD rsv_23                    : 1;
        FIELD EL2_LAYER_SEL             : 3;
        FIELD rsv_27                    : 5;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_DATAPATH_EXT_CON, *PDISP_OVL0_REG_OVL_DATAPATH_EXT_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD ALPHA                     : 8;
        FIELD ALPHA_EN                  : 1;
        FIELD VERTICAL_FLIP_EN          : 1;
        FIELD HORIZONTAL_FLIP_EN        : 1;
        FIELD EXT_MTX_EN                : 1;
        FIELD CLRFMT                    : 4;
        FIELD INT_MTX_SEL               : 4;
        FIELD EN_3D                     : 1;
        FIELD LANDSCAPE                 : 1;
        FIELD R_FIRST                   : 1;
        FIELD CLRFMT_MAN                : 1;
        FIELD BYTE_SWAP                 : 1;
        FIELD RGB_SWAP                  : 1;
        FIELD MTX_AUTO_DIS              : 1;
        FIELD MTX_EN                    : 1;
        FIELD LAYER_SRC                 : 2;
        FIELD SRCKEY_EN                 : 1;
        FIELD DSTKEY_EN                 : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL0_CON, *PDISP_OVL0_REG_OVL_EL0_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD SRCKEY                    : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL0_SRCKEY, *PDISP_OVL0_REG_OVL_EL0_SRCKEY;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL0_SRC_W                 : 13;
        FIELD rsv_13                    : 3;
        FIELD EL0_SRC_H                 : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL0_SRC_SIZE, *PDISP_OVL0_REG_OVL_EL0_SRC_SIZE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL0_XOFF                  : 13;
        FIELD rsv_13                    : 3;
        FIELD EL0_YOFF                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL0_OFFSET, *PDISP_OVL0_REG_OVL_EL0_OFFSET;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL0_SRC_PITCH             : 16;
        FIELD EL0_SA_SEL                : 2;
        FIELD EL0_SRGB_SEL              : 2;
        FIELD EL0_DA_SEL                : 2;
        FIELD EL0_DRGB_SEL              : 2;
        FIELD EL0_SA_SEL_EXT            : 1;
        FIELD EL0_SRGB_SEL_EXT          : 1;
        FIELD EL0_DA_SEL_EXT            : 1;
        FIELD EL0_DRGB_SEL_EXT          : 1;
        FIELD EL0_CONST_BLD             : 1;
        FIELD EL0_SRGB_SEL_EXT2         : 1;
        FIELD EL0_BLEND_RND_SHT         : 1;
        FIELD SURFL_EN                  : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL0_PITCH, *PDISP_OVL0_REG_OVL_EL0_PITCH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD TILE_HEIGHT               : 20;
        FIELD TILE_WIDTH_SEL            : 1;
        FIELD TILE_EN                   : 1;
        FIELD rsv_22                    : 2;
        FIELD TILE_HORI_BLOCK_NUM       : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL0_TILE, *PDISP_OVL0_REG_OVL_EL0_TILE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL0_SRC_LEFT_CLIP         : 8;
        FIELD EL0_SRC_RIGHT_CLIP        : 8;
        FIELD EL0_SRC_TOP_CLIP          : 8;
        FIELD EL0_SRC_BOTTOM_CLIP       : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL0_CLIP, *PDISP_OVL0_REG_OVL_EL0_CLIP;

typedef PACKING union
{
    PACKING struct
    {
        FIELD ALPHA                     : 8;
        FIELD ALPHA_EN                  : 1;
        FIELD VERTICAL_FLIP_EN          : 1;
        FIELD HORIZONTAL_FLIP_EN        : 1;
        FIELD EXT_MTX_EN                : 1;
        FIELD CLRFMT                    : 4;
        FIELD INT_MTX_SEL               : 4;
        FIELD EN_3D                     : 1;
        FIELD LANDSCAPE                 : 1;
        FIELD R_FIRST                   : 1;
        FIELD CLRFMT_MAN                : 1;
        FIELD BYTE_SWAP                 : 1;
        FIELD RGB_SWAP                  : 1;
        FIELD MTX_AUTO_DIS              : 1;
        FIELD MTX_EN                    : 1;
        FIELD LAYER_SRC                 : 2;
        FIELD SRCKEY_EN                 : 1;
        FIELD DSTKEY_EN                 : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL1_CON, *PDISP_OVL0_REG_OVL_EL1_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD SRCKEY                    : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL1_SRCKEY, *PDISP_OVL0_REG_OVL_EL1_SRCKEY;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL1_SRC_W                 : 13;
        FIELD rsv_13                    : 3;
        FIELD EL1_SRC_H                 : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL1_SRC_SIZE, *PDISP_OVL0_REG_OVL_EL1_SRC_SIZE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL1_XOFF                  : 13;
        FIELD rsv_13                    : 3;
        FIELD EL1_YOFF                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL1_OFFSET, *PDISP_OVL0_REG_OVL_EL1_OFFSET;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL1_SRC_PITCH             : 16;
        FIELD EL1_SA_SEL                : 2;
        FIELD EL1_SRGB_SEL              : 2;
        FIELD EL1_DA_SEL                : 2;
        FIELD EL1_DRGB_SEL              : 2;
        FIELD EL1_SA_SEL_EXT            : 1;
        FIELD EL1_SRGB_SEL_EXT          : 1;
        FIELD EL1_DA_SEL_EXT            : 1;
        FIELD EL1_DRGB_SEL_EXT          : 1;
        FIELD EL1_CONST_BLD             : 1;
        FIELD EL1_SRGB_SEL_EXT2         : 1;
        FIELD EL1_BLEND_RND_SHT         : 1;
        FIELD SURFL_EN                  : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL1_PITCH, *PDISP_OVL0_REG_OVL_EL1_PITCH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD TILE_HEIGHT               : 20;
        FIELD TILE_WIDTH_SEL            : 1;
        FIELD TILE_EN                   : 1;
        FIELD rsv_22                    : 2;
        FIELD TILE_HORI_BLOCK_NUM       : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL1_TILE, *PDISP_OVL0_REG_OVL_EL1_TILE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL1_SRC_LEFT_CLIP         : 8;
        FIELD EL1_SRC_RIGHT_CLIP        : 8;
        FIELD EL1_SRC_TOP_CLIP          : 8;
        FIELD EL1_SRC_BOTTOM_CLIP       : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL1_CLIP, *PDISP_OVL0_REG_OVL_EL1_CLIP;

typedef PACKING union
{
    PACKING struct
    {
        FIELD ALPHA                     : 8;
        FIELD ALPHA_EN                  : 1;
        FIELD VERTICAL_FLIP_EN          : 1;
        FIELD HORIZONTAL_FLIP_EN        : 1;
        FIELD EXT_MTX_EN                : 1;
        FIELD CLRFMT                    : 4;
        FIELD INT_MTX_SEL               : 4;
        FIELD EN_3D                     : 1;
        FIELD LANDSCAPE                 : 1;
        FIELD R_FIRST                   : 1;
        FIELD CLRFMT_MAN                : 1;
        FIELD BYTE_SWAP                 : 1;
        FIELD RGB_SWAP                  : 1;
        FIELD MTX_AUTO_DIS              : 1;
        FIELD MTX_EN                    : 1;
        FIELD LAYER_SRC                 : 2;
        FIELD SRCKEY_EN                 : 1;
        FIELD DSTKEY_EN                 : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL2_CON, *PDISP_OVL0_REG_OVL_EL2_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD SRCKEY                    : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL2_SRCKEY, *PDISP_OVL0_REG_OVL_EL2_SRCKEY;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL2_SRC_W                 : 13;
        FIELD rsv_13                    : 3;
        FIELD EL2_SRC_H                 : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL2_SRC_SIZE, *PDISP_OVL0_REG_OVL_EL2_SRC_SIZE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL2_XOFF                  : 13;
        FIELD rsv_13                    : 3;
        FIELD EL2_YOFF                  : 13;
        FIELD rsv_29                    : 3;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL2_OFFSET, *PDISP_OVL0_REG_OVL_EL2_OFFSET;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL2_SRC_PITCH             : 16;
        FIELD EL2_SA_SEL                : 2;
        FIELD EL2_SRGB_SEL              : 2;
        FIELD EL2_DA_SEL                : 2;
        FIELD EL2_DRGB_SEL              : 2;
        FIELD EL2_SA_SEL_EXT            : 1;
        FIELD EL2_SRGB_SEL_EXT          : 1;
        FIELD EL2_DA_SEL_EXT            : 1;
        FIELD EL2_DRGB_SEL_EXT          : 1;
        FIELD EL2_CONST_BLD             : 1;
        FIELD EL2_SRGB_SEL_EXT2         : 1;
        FIELD EL2_BLEND_RND_SHT         : 1;
        FIELD SURFL_EN                  : 1;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL2_PITCH, *PDISP_OVL0_REG_OVL_EL2_PITCH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD TILE_HEIGHT               : 20;
        FIELD TILE_WIDTH_SEL            : 1;
        FIELD TILE_EN                   : 1;
        FIELD rsv_22                    : 2;
        FIELD TILE_HORI_BLOCK_NUM       : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL2_TILE, *PDISP_OVL0_REG_OVL_EL2_TILE;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL2_SRC_LEFT_CLIP         : 8;
        FIELD EL2_SRC_RIGHT_CLIP        : 8;
        FIELD EL2_SRC_TOP_CLIP          : 8;
        FIELD EL2_SRC_BOTTOM_CLIP       : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL2_CLIP, *PDISP_OVL0_REG_OVL_EL2_CLIP;

typedef PACKING union
{
    PACKING struct
    {
        FIELD BLUE                      : 8;
        FIELD GREEN                     : 8;
        FIELD RED                       : 8;
        FIELD ALPHA                     : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL0_CLR, *PDISP_OVL0_REG_OVL_EL0_CLR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD BLUE                      : 8;
        FIELD GREEN                     : 8;
        FIELD RED                       : 8;
        FIELD ALPHA                     : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL1_CLR, *PDISP_OVL0_REG_OVL_EL1_CLR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD BLUE                      : 8;
        FIELD GREEN                     : 8;
        FIELD RED                       : 8;
        FIELD ALPHA                     : 8;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL2_CLR, *PDISP_OVL0_REG_OVL_EL2_CLR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L0_SBCH_UPDATE            : 1;
        FIELD rsv_1                     : 3;
        FIELD L1_SBCH_UPDATE            : 1;
        FIELD rsv_5                     : 3;
        FIELD L2_SBCH_UPDATE            : 1;
        FIELD rsv_9                     : 3;
        FIELD L3_SBCH_UPDATE            : 1;
        FIELD rsv_13                    : 3;
        FIELD L0_SBCH_TRANS_EN          : 1;
        FIELD L0_SBCH_CNST_EN           : 1;
        FIELD rsv_18                    : 2;
        FIELD L1_SBCH_TRANS_EN          : 1;
        FIELD L1_SBCH_CNST_EN           : 1;
        FIELD rsv_22                    : 2;
        FIELD L2_SBCH_TRANS_EN          : 1;
        FIELD L2_SBCH_CNST_EN           : 1;
        FIELD rsv_26                    : 2;
        FIELD L3_SBCH_TRANS_EN          : 1;
        FIELD L3_SBCH_CNST_EN           : 1;
        FIELD rsv_30                    : 2;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_SBCH, *PDISP_OVL0_REG_OVL_SBCH;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL0_SBCH_UPDATE           : 1;
        FIELD rsv_1                     : 3;
        FIELD EL1_SBCH_UPDATE           : 1;
        FIELD rsv_5                     : 3;
        FIELD EL2_SBCH_UPDATE           : 1;
        FIELD rsv_9                     : 7;
        FIELD EL0_SBCH_TRANS_EN         : 1;
        FIELD EL0_SBCH_CNST_EN          : 1;
        FIELD rsv_18                    : 2;
        FIELD EL1_SBCH_TRANS_EN         : 1;
        FIELD EL1_SBCH_CNST_EN          : 1;
        FIELD rsv_22                    : 2;
        FIELD EL2_SBCH_TRANS_EN         : 1;
        FIELD EL2_SBCH_CNST_EN          : 1;
        FIELD rsv_26                    : 6;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_SBCH_EXT, *PDISP_OVL0_REG_OVL_SBCH_EXT;

typedef PACKING union
{
    PACKING struct
    {
        FIELD rsv_0                     : 16;
        FIELD L0_SBCH_TRANS_INVALID     : 1;
        FIELD L1_SBCH_TRANS_INVALID     : 1;
        FIELD L2_SBCH_TRANS_INVALID     : 1;
        FIELD L3_SBCH_TRANS_INVALID     : 1;
        FIELD EL0_SBCH_TRANS_INVALID    : 1;
        FIELD EL1_SBCH_TRANS_INVALID    : 1;
        FIELD EL2_SBCH_TRANS_INVALID    : 1;
        FIELD rsv_23                    : 9;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_SBCH_CON, *PDISP_OVL0_REG_OVL_SBCH_CON;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L0_ADDR                   : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L0_ADDR, *PDISP_OVL0_REG_OVL_L0_ADDR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L1_ADDR                   : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L1_ADDR, *PDISP_OVL0_REG_OVL_L1_ADDR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L2_ADDR                   : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L2_ADDR, *PDISP_OVL0_REG_OVL_L2_ADDR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L3_ADDR                   : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_L3_ADDR, *PDISP_OVL0_REG_OVL_L3_ADDR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL0_ADDR                  : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL0_ADDR, *PDISP_OVL0_REG_OVL_EL0_ADDR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL1_ADDR                  : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL1_ADDR, *PDISP_OVL0_REG_OVL_EL1_ADDR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD EL2_ADDR                  : 32;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_EL2_ADDR, *PDISP_OVL0_REG_OVL_EL2_ADDR;

typedef PACKING union
{
    PACKING struct
    {
        FIELD L0_SECURE                 : 1;
        FIELD L1_SECURE                 : 1;
        FIELD L2_SECURE                 : 1;
        FIELD L3_SECURE                 : 1;
        FIELD rsv_4                     : 28;
    } Bits;
    UINT32 Raw;
} DISP_OVL0_REG_OVL_SECURE, *PDISP_OVL0_REG_OVL_SECURE;

// ----------------- DISP_OVL0  Grouping Definitions -------------------
typedef struct
{
    DISP_OVL0_REG_OVL_INTEN         OVL_INTEN;           //1400B004
    DISP_OVL0_REG_OVL_TRIG          OVL_TRIG;            //1400B010
    DISP_OVL0_REG_OVL_RST           OVL_RST;             //1400B014
    DISP_OVL0_REG_OVL_ROI_SIZE      OVL_ROI_SIZE;        //1400B020
    DISP_OVL0_REG_OVL_DATAPATH_CON  OVL_DATAPATH_CON;    //1400B024
    DISP_OVL0_REG_OVL_ROI_BGCLR     OVL_ROI_BGCLR;       //1400B028
    DISP_OVL0_REG_OVL_SRC_CON       OVL_SRC_CON;         //1400B02C
    DISP_OVL0_REG_OVL_L0_CON        OVL_L0_CON;          //1400B030
    DISP_OVL0_REG_OVL_L0_SRCKEY     OVL_L0_SRCKEY;       //1400B034
    DISP_OVL0_REG_OVL_L0_SRC_SIZE   OVL_L0_SRC_SIZE;     //1400B038
    DISP_OVL0_REG_OVL_L0_OFFSET     OVL_L0_OFFSET;       //1400B03C
    DISP_OVL0_REG_OVL_L0_PITCH      OVL_L0_PITCH;        //1400B044
    DISP_OVL0_REG_OVL_L0_TILE       OVL_L0_TILE;         //1400B048
    DISP_OVL0_REG_OVL_L0_CLIP       OVL_L0_CLIP;         //1400B04C
    DISP_OVL0_REG_OVL_L1_CON        OVL_L1_CON;          //1400B050
    DISP_OVL0_REG_OVL_L1_SRCKEY     OVL_L1_SRCKEY;       //1400B054
    DISP_OVL0_REG_OVL_L1_SRC_SIZE   OVL_L1_SRC_SIZE;     //1400B058
    DISP_OVL0_REG_OVL_L1_OFFSET     OVL_L1_OFFSET;       //1400B05C
    DISP_OVL0_REG_OVL_L1_PITCH      OVL_L1_PITCH;        //1400B064
    DISP_OVL0_REG_OVL_L1_TILE       OVL_L1_TILE;         //1400B068
    DISP_OVL0_REG_OVL_L1_CLIP       OVL_L1_CLIP;         //1400B06C
    DISP_OVL0_REG_OVL_L2_CON        OVL_L2_CON;          //1400B070
    DISP_OVL0_REG_OVL_L2_SRCKEY     OVL_L2_SRCKEY;       //1400B074
    DISP_OVL0_REG_OVL_L2_SRC_SIZE   OVL_L2_SRC_SIZE;     //1400B078
    DISP_OVL0_REG_OVL_L2_OFFSET     OVL_L2_OFFSET;       //1400B07C
    DISP_OVL0_REG_OVL_L2_PITCH      OVL_L2_PITCH;        //1400B084
    DISP_OVL0_REG_OVL_L2_TILE       OVL_L2_TILE;         //1400B088
    DISP_OVL0_REG_OVL_L2_CLIP       OVL_L2_CLIP;         //1400B08C
    DISP_OVL0_REG_OVL_L3_CON        OVL_L3_CON;          //1400B090
    DISP_OVL0_REG_OVL_L3_SRCKEY     OVL_L3_SRCKEY;       //1400B094
    DISP_OVL0_REG_OVL_L3_SRC_SIZE   OVL_L3_SRC_SIZE;     //1400B098
    DISP_OVL0_REG_OVL_L3_OFFSET     OVL_L3_OFFSET;       //1400B09C
    DISP_OVL0_REG_OVL_L3_PITCH      OVL_L3_PITCH;        //1400B0A4
    DISP_OVL0_REG_OVL_L3_TILE       OVL_L3_TILE;         //1400B0A8
    DISP_OVL0_REG_OVL_L3_CLIP       OVL_L3_CLIP;         //1400B0AC
    DISP_OVL0_REG_OVL_RDMA0_CTRL    OVL_RDMA0_CTRL;      //1400B0C0
    DISP_OVL0_REG_OVL_RDMA0_MEM_GMC_SETTING1 OVL_RDMA0_MEM_GMC_SETTING1; //1400B0C8
    DISP_OVL0_REG_OVL_RDMA0_MEM_SLOW_CON OVL_RDMA0_MEM_SLOW_CON; //1400B0CC
    DISP_OVL0_REG_OVL_RDMA0_FIFO_CTRL OVL_RDMA0_FIFO_CTRL; //1400B0D0
    DISP_OVL0_REG_OVL_RDMA1_CTRL    OVL_RDMA1_CTRL;      //1400B0E0
    DISP_OVL0_REG_OVL_RDMA1_MEM_GMC_SETTING1 OVL_RDMA1_MEM_GMC_SETTING1; //1400B0E8
    DISP_OVL0_REG_OVL_RDMA1_MEM_SLOW_CON OVL_RDMA1_MEM_SLOW_CON; //1400B0EC
    DISP_OVL0_REG_OVL_RDMA1_FIFO_CTRL OVL_RDMA1_FIFO_CTRL; //1400B0F0
    DISP_OVL0_REG_OVL_RDMA2_CTRL    OVL_RDMA2_CTRL;      //1400B100
    DISP_OVL0_REG_OVL_RDMA2_MEM_GMC_SETTING1 OVL_RDMA2_MEM_GMC_SETTING1; //1400B108
    DISP_OVL0_REG_OVL_RDMA2_MEM_SLOW_CON OVL_RDMA2_MEM_SLOW_CON; //1400B10C
    DISP_OVL0_REG_OVL_RDMA2_FIFO_CTRL OVL_RDMA2_FIFO_CTRL; //1400B110
    DISP_OVL0_REG_OVL_RDMA3_CTRL    OVL_RDMA3_CTRL;      //1400B120
    DISP_OVL0_REG_OVL_RDMA3_MEM_GMC_SETTING1 OVL_RDMA3_MEM_GMC_SETTING1; //1400B128
    DISP_OVL0_REG_OVL_RDMA3_MEM_SLOW_CON OVL_RDMA3_MEM_SLOW_CON; //1400B12C
    DISP_OVL0_REG_OVL_RDMA3_FIFO_CTRL OVL_RDMA3_FIFO_CTRL; //1400B130
    DISP_OVL0_REG_OVL_L0_Y2R_PARA_R0 OVL_L0_Y2R_PARA_R0;  //1400B134
    DISP_OVL0_REG_OVL_L0_Y2R_PARA_R1 OVL_L0_Y2R_PARA_R1;  //1400B138
    DISP_OVL0_REG_OVL_L0_Y2R_PARA_G0 OVL_L0_Y2R_PARA_G0;  //1400B13C
    DISP_OVL0_REG_OVL_L0_Y2R_PARA_G1 OVL_L0_Y2R_PARA_G1;  //1400B140
    DISP_OVL0_REG_OVL_L0_Y2R_PARA_B0 OVL_L0_Y2R_PARA_B0;  //1400B144
    DISP_OVL0_REG_OVL_L0_Y2R_PARA_B1 OVL_L0_Y2R_PARA_B1;  //1400B148
    DISP_OVL0_REG_OVL_L0_Y2R_PARA_YUV_A_0 OVL_L0_Y2R_PARA_YUV_A_0; //1400B14C
    DISP_OVL0_REG_OVL_L0_Y2R_PARA_YUV_A_1 OVL_L0_Y2R_PARA_YUV_A_1; //1400B150
    DISP_OVL0_REG_OVL_L0_Y2R_PARA_RGB_A_0 OVL_L0_Y2R_PARA_RGB_A_0; //1400B154
    DISP_OVL0_REG_OVL_L0_Y2R_PARA_RGB_A_1 OVL_L0_Y2R_PARA_RGB_A_1; //1400B158
    DISP_OVL0_REG_OVL_L1_Y2R_PARA_R0 OVL_L1_Y2R_PARA_R0;  //1400B15C
    DISP_OVL0_REG_OVL_L1_Y2R_PARA_R1 OVL_L1_Y2R_PARA_R1;  //1400B160
    DISP_OVL0_REG_OVL_L1_Y2R_PARA_G0 OVL_L1_Y2R_PARA_G0;  //1400B164
    DISP_OVL0_REG_OVL_L1_Y2R_PARA_G1 OVL_L1_Y2R_PARA_G1;  //1400B168
    DISP_OVL0_REG_OVL_L1_Y2R_PARA_B0 OVL_L1_Y2R_PARA_B0;  //1400B16C
    DISP_OVL0_REG_OVL_L1_Y2R_PARA_B1 OVL_L1_Y2R_PARA_B1;  //1400B170
    DISP_OVL0_REG_OVL_L1_Y2R_PARA_YUV_A_0 OVL_L1_Y2R_PARA_YUV_A_0; //1400B174
    DISP_OVL0_REG_OVL_L1_Y2R_PARA_YUV_A_1 OVL_L1_Y2R_PARA_YUV_A_1; //1400B178
    DISP_OVL0_REG_OVL_L1_Y2R_PARA_RGB_A_0 OVL_L1_Y2R_PARA_RGB_A_0; //1400B17C
    DISP_OVL0_REG_OVL_L1_Y2R_PARA_RGB_A_1 OVL_L1_Y2R_PARA_RGB_A_1; //1400B180
    DISP_OVL0_REG_OVL_L2_Y2R_PARA_R0 OVL_L2_Y2R_PARA_R0;  //1400B184
    DISP_OVL0_REG_OVL_L2_Y2R_PARA_R1 OVL_L2_Y2R_PARA_R1;  //1400B188
    DISP_OVL0_REG_OVL_L2_Y2R_PARA_G0 OVL_L2_Y2R_PARA_G0;  //1400B18C
    DISP_OVL0_REG_OVL_L2_Y2R_PARA_G1 OVL_L2_Y2R_PARA_G1;  //1400B190
    DISP_OVL0_REG_OVL_L2_Y2R_PARA_B0 OVL_L2_Y2R_PARA_B0;  //1400B194
    DISP_OVL0_REG_OVL_L2_Y2R_PARA_B1 OVL_L2_Y2R_PARA_B1;  //1400B198
    DISP_OVL0_REG_OVL_L2_Y2R_PARA_YUV_A_0 OVL_L2_Y2R_PARA_YUV_A_0; //1400B19C
    DISP_OVL0_REG_OVL_L2_Y2R_PARA_YUV_A_1 OVL_L2_Y2R_PARA_YUV_A_1; //1400B1A0
    DISP_OVL0_REG_OVL_L2_Y2R_PARA_RGB_A_0 OVL_L2_Y2R_PARA_RGB_A_0; //1400B1A4
    DISP_OVL0_REG_OVL_L2_Y2R_PARA_RGB_A_1 OVL_L2_Y2R_PARA_RGB_A_1; //1400B1A8
    DISP_OVL0_REG_OVL_L3_Y2R_PARA_R0 OVL_L3_Y2R_PARA_R0;  //1400B1AC
    DISP_OVL0_REG_OVL_L3_Y2R_PARA_R1 OVL_L3_Y2R_PARA_R1;  //1400B1B0
    DISP_OVL0_REG_OVL_L3_Y2R_PARA_G0 OVL_L3_Y2R_PARA_G0;  //1400B1B4
    DISP_OVL0_REG_OVL_L3_Y2R_PARA_G1 OVL_L3_Y2R_PARA_G1;  //1400B1B8
    DISP_OVL0_REG_OVL_L3_Y2R_PARA_B0 OVL_L3_Y2R_PARA_B0;  //1400B1BC
    DISP_OVL0_REG_OVL_L3_Y2R_PARA_B1 OVL_L3_Y2R_PARA_B1;  //1400B1C0
    DISP_OVL0_REG_OVL_L3_Y2R_PARA_YUV_A_0 OVL_L3_Y2R_PARA_YUV_A_0; //1400B1C4
    DISP_OVL0_REG_OVL_L3_Y2R_PARA_YUV_A_1 OVL_L3_Y2R_PARA_YUV_A_1; //1400B1C8
    DISP_OVL0_REG_OVL_L3_Y2R_PARA_RGB_A_0 OVL_L3_Y2R_PARA_RGB_A_0; //1400B1CC
    DISP_OVL0_REG_OVL_L3_Y2R_PARA_RGB_A_1 OVL_L3_Y2R_PARA_RGB_A_1; //1400B1D0
    DISP_OVL0_REG_OVL_DEBUG_MON_SEL OVL_DEBUG_MON_SEL;   //1400B1D4
    DISP_OVL0_REG_OVL_BLD_EXT       OVL_BLD_EXT;         //1400B1DC
    DISP_OVL0_REG_OVL_RDMA0_MEM_GMC_SETTING2 OVL_RDMA0_MEM_GMC_SETTING2; //1400B1E0
    DISP_OVL0_REG_OVL_RDMA1_MEM_GMC_SETTING2 OVL_RDMA1_MEM_GMC_SETTING2; //1400B1E4
    DISP_OVL0_REG_OVL_RDMA2_MEM_GMC_SETTING2 OVL_RDMA2_MEM_GMC_SETTING2; //1400B1E8
    DISP_OVL0_REG_OVL_RDMA3_MEM_GMC_SETTING2 OVL_RDMA3_MEM_GMC_SETTING2; //1400B1EC
    DISP_OVL0_REG_OVL_RDMA_BURST_CON0 OVL_RDMA_BURST_CON0; //1400B1F0
    DISP_OVL0_REG_OVL_RDMA_BURST_CON1 OVL_RDMA_BURST_CON1; //1400B1F4
    DISP_OVL0_REG_OVL_RDMA_GREQ_NUM OVL_RDMA_GREQ_NUM;   //1400B1F8
    DISP_OVL0_REG_OVL_RDMA_GREQ_URG_NUM OVL_RDMA_GREQ_URG_NUM; //1400B1FC
    DISP_OVL0_REG_OVL_DUMMY_REG     OVL_DUMMY_REG;       //1400B200
    DISP_OVL0_REG_OVL_GDRDY_PRD     OVL_GDRDY_PRD;       //1400B208
    DISP_OVL0_REG_OVL_RDMA_ULTRA_SRC OVL_RDMA_ULTRA_SRC;  //1400B20C
    DISP_OVL0_REG_OVL_RDMA0_BUF_LOW_TH OVL_RDMA0_BUF_LOW_TH; //1400B210
    DISP_OVL0_REG_OVL_RDMA1_BUF_LOW_TH OVL_RDMA1_BUF_LOW_TH; //1400B214
    DISP_OVL0_REG_OVL_RDMA2_BUF_LOW_TH OVL_RDMA2_BUF_LOW_TH; //1400B218
    DISP_OVL0_REG_OVL_RDMA3_BUF_LOW_TH OVL_RDMA3_BUF_LOW_TH; //1400B21C
    DISP_OVL0_REG_OVL_RDMA0_BUF_HIGH_TH OVL_RDMA0_BUF_HIGH_TH; //1400B220
    DISP_OVL0_REG_OVL_RDMA1_BUF_HIGH_TH OVL_RDMA1_BUF_HIGH_TH; //1400B224
    DISP_OVL0_REG_OVL_RDMA2_BUF_HIGH_TH OVL_RDMA2_BUF_HIGH_TH; //1400B228
    DISP_OVL0_REG_OVL_RDMA3_BUF_HIGH_TH OVL_RDMA3_BUF_HIGH_TH; //1400B22C
    DISP_OVL0_REG_OVL_SMI_DBG       OVL_SMI_DBG;         //1400B230
    DISP_OVL0_REG_OVL_GREQ_LAYER_CNT OVL_GREQ_LAYER_CNT;  //1400B234
    DISP_OVL0_REG_OVL_GDRDY_PRD_NUM OVL_GDRDY_PRD_NUM;   //1400B238
    DISP_OVL0_REG_OVL_L0_CLR        OVL_L0_CLR;          //1400B25C
    DISP_OVL0_REG_OVL_L1_CLR        OVL_L1_CLR;          //1400B260
    DISP_OVL0_REG_OVL_L2_CLR        OVL_L2_CLR;          //1400B264
    DISP_OVL0_REG_OVL_L3_CLR        OVL_L3_CLR;          //1400B268
    DISP_OVL0_REG_OVL_LC_CLR        OVL_LC_CLR;          //1400B26C
    DISP_OVL0_REG_OVL_CRC           OVL_CRC;             //1400B270
    DISP_OVL0_REG_OVL_LC_CON        OVL_LC_CON;          //1400B280
    DISP_OVL0_REG_OVL_LC_SRCKEY     OVL_LC_SRCKEY;       //1400B284
    DISP_OVL0_REG_OVL_LC_SRC_SIZE   OVL_LC_SRC_SIZE;     //1400B288
    DISP_OVL0_REG_OVL_LC_OFFSET     OVL_LC_OFFSET;       //1400B28C
    DISP_OVL0_REG_OVL_LC_SRC_SEL    OVL_LC_SRC_SEL;      //1400B290
    DISP_OVL0_REG_OVL_BANK_CON      OVL_BANK_CON;        //1400B29C
    DISP_OVL0_REG_OVL_FUNC_DCM0     OVL_FUNC_DCM0;       //1400B2A0
    DISP_OVL0_REG_OVL_FUNC_DCM1     OVL_FUNC_DCM1;       //1400B2A4
    DISP_OVL0_REG_OVL_DVFS_L0_ROI   OVL_DVFS_L0_ROI;     //1400B2B0
    DISP_OVL0_REG_OVL_DVFS_L1_ROI   OVL_DVFS_L1_ROI;     //1400B2B4
    DISP_OVL0_REG_OVL_DVFS_L2_ROI   OVL_DVFS_L2_ROI;     //1400B2B8
    DISP_OVL0_REG_OVL_DVFS_L3_ROI   OVL_DVFS_L3_ROI;     //1400B2BC
    DISP_OVL0_REG_OVL_DVFS_EL0_ROI  OVL_DVFS_EL0_ROI;    //1400B2C0
    DISP_OVL0_REG_OVL_DVFS_EL1_ROI  OVL_DVFS_EL1_ROI;    //1400B2C4
    DISP_OVL0_REG_OVL_DVFS_EL2_ROI  OVL_DVFS_EL2_ROI;    //1400B2C8
    DISP_OVL0_REG_OVL_DATAPATH_EXT_CON OVL_DATAPATH_EXT_CON; //1400B324
    DISP_OVL0_REG_OVL_EL0_CON       OVL_EL0_CON;         //1400B330
    DISP_OVL0_REG_OVL_EL0_SRCKEY    OVL_EL0_SRCKEY;      //1400B334
    DISP_OVL0_REG_OVL_EL0_SRC_SIZE  OVL_EL0_SRC_SIZE;    //1400B338
    DISP_OVL0_REG_OVL_EL0_OFFSET    OVL_EL0_OFFSET;      //1400B33C
    DISP_OVL0_REG_OVL_EL0_PITCH     OVL_EL0_PITCH;       //1400B344
    DISP_OVL0_REG_OVL_EL0_TILE      OVL_EL0_TILE;        //1400B348
    DISP_OVL0_REG_OVL_EL0_CLIP      OVL_EL0_CLIP;        //1400B34C
    DISP_OVL0_REG_OVL_EL1_CON       OVL_EL1_CON;         //1400B350
    DISP_OVL0_REG_OVL_EL1_SRCKEY    OVL_EL1_SRCKEY;      //1400B354
    DISP_OVL0_REG_OVL_EL1_SRC_SIZE  OVL_EL1_SRC_SIZE;    //1400B358
    DISP_OVL0_REG_OVL_EL1_OFFSET    OVL_EL1_OFFSET;      //1400B35C
    DISP_OVL0_REG_OVL_EL1_PITCH     OVL_EL1_PITCH;       //1400B364
    DISP_OVL0_REG_OVL_EL1_TILE      OVL_EL1_TILE;        //1400B368
    DISP_OVL0_REG_OVL_EL1_CLIP      OVL_EL1_CLIP;        //1400B36C
    DISP_OVL0_REG_OVL_EL2_CON       OVL_EL2_CON;         //1400B370
    DISP_OVL0_REG_OVL_EL2_SRCKEY    OVL_EL2_SRCKEY;      //1400B374
    DISP_OVL0_REG_OVL_EL2_SRC_SIZE  OVL_EL2_SRC_SIZE;    //1400B378
    DISP_OVL0_REG_OVL_EL2_OFFSET    OVL_EL2_OFFSET;      //1400B37C
    DISP_OVL0_REG_OVL_EL2_PITCH     OVL_EL2_PITCH;       //1400B384
    DISP_OVL0_REG_OVL_EL2_TILE      OVL_EL2_TILE;        //1400B388
    DISP_OVL0_REG_OVL_EL2_CLIP      OVL_EL2_CLIP;        //1400B38C
    DISP_OVL0_REG_OVL_EL0_CLR       OVL_EL0_CLR;         //1400B390
    DISP_OVL0_REG_OVL_EL1_CLR       OVL_EL1_CLR;         //1400B394
    DISP_OVL0_REG_OVL_EL2_CLR       OVL_EL2_CLR;         //1400B398
    DISP_OVL0_REG_OVL_SBCH          OVL_SBCH;            //1400B3A0
    DISP_OVL0_REG_OVL_SBCH_EXT      OVL_SBCH_EXT;        //1400B3A4
    DISP_OVL0_REG_OVL_SBCH_CON      OVL_SBCH_CON;        //1400B3A8
    DISP_OVL0_REG_OVL_L0_ADDR       OVL_L0_ADDR;         //1400BF40
    DISP_OVL0_REG_OVL_L1_ADDR       OVL_L1_ADDR;         //1400BF60
    DISP_OVL0_REG_OVL_L2_ADDR       OVL_L2_ADDR;         //1400BF80
    DISP_OVL0_REG_OVL_L3_ADDR       OVL_L3_ADDR;         //1400BFA0
    DISP_OVL0_REG_OVL_EL0_ADDR      OVL_EL0_ADDR;        //1400BFB0
    DISP_OVL0_REG_OVL_EL1_ADDR      OVL_EL1_ADDR;        //1400BFB4
    DISP_OVL0_REG_OVL_EL2_ADDR      OVL_EL2_ADDR;        //1400BFB8
    DISP_OVL0_REG_OVL_SECURE        OVL_SECURE;          //1400BFC0
}DISP_OVL0_OVL_CFG, *PDISP_OVL0_OVL_CFG;

typedef struct
{
    DISP_OVL0_REG_OVL_STA           OVL_STA;             //1400B000
    DISP_OVL0_REG_OVL_INTSTA        OVL_INTSTA;          //1400B008
}DISP_OVL0_OVL_STATUS, *PDISP_OVL0_OVL_STATUS;

typedef struct
{
    DISP_OVL0_REG_OVL_EN            OVL_EN;              //1400B00C
}DISP_OVL0_OVL_START, *PDISP_OVL0_OVL_START;

// ----------------- DISP_OVL0 Register Definition -------------------
/* modify by RD */
typedef volatile PACKING struct
{
	DISP_OVL0_REG_OVL_STA           OVL_STA;             //14008000    
	DISP_OVL0_REG_OVL_INTEN         OVL_INTEN;           //14008004
	DISP_OVL0_REG_OVL_INTSTA        OVL_INTSTA;          //14008008
	DISP_OVL0_REG_OVL_EN			OVL_EN; 			 //1400800C
	DISP_OVL0_REG_OVL_TRIG          OVL_TRIG;            //14008010
	DISP_OVL0_REG_OVL_RST           OVL_RST;             //14008014
	UINT32                          rsv_8018[2];         //14008018..801C
	DISP_OVL0_REG_OVL_ROI_SIZE      OVL_ROI_SIZE;        //14008020
	DISP_OVL0_REG_OVL_DATAPATH_CON  OVL_DATAPATH_CON;    //14008024
	DISP_OVL0_REG_OVL_ROI_BGCLR     OVL_ROI_BGCLR;       //14008028
	DISP_OVL0_REG_OVL_SRC_CON       OVL_SRC_CON;         //1400802C
	DISP_OVL0_REG_OVL_L0_CON        OVL_L0_CON;          //14008030
	DISP_OVL0_REG_OVL_L0_SRCKEY     OVL_L0_SRCKEY;       //14008034
	DISP_OVL0_REG_OVL_L0_SRC_SIZE   OVL_L0_SRC_SIZE;     //14008038
	DISP_OVL0_REG_OVL_L0_OFFSET     OVL_L0_OFFSET;       //1400803C
	UINT32                          rsv_8040;         	 //14008040
	DISP_OVL0_REG_OVL_L0_PITCH      OVL_L0_PITCH;        //14008044
	DISP_OVL0_REG_OVL_L0_TILE       OVL_L0_TILE;         //14008048
	DISP_OVL0_REG_OVL_L0_CLIP       OVL_L0_CLIP;         //1400804C
	DISP_OVL0_REG_OVL_L1_CON        OVL_L1_CON;          //14008050
	DISP_OVL0_REG_OVL_L1_SRCKEY     OVL_L1_SRCKEY;       //14008054
	DISP_OVL0_REG_OVL_L1_SRC_SIZE   OVL_L1_SRC_SIZE;     //14008058
	DISP_OVL0_REG_OVL_L1_OFFSET     OVL_L1_OFFSET;       //1400805C 
	UINT32                          rsv_8060;         	 //14008060
	DISP_OVL0_REG_OVL_L1_PITCH      OVL_L1_PITCH;        //14008064
	DISP_OVL0_REG_OVL_L1_TILE       OVL_L1_TILE;         //14008068
	DISP_OVL0_REG_OVL_L1_CLIP       OVL_L1_CLIP;         //1400806C
	DISP_OVL0_REG_OVL_L2_CON        OVL_L2_CON;          //14008070
	DISP_OVL0_REG_OVL_L2_SRCKEY     OVL_L2_SRCKEY;       //14008074
	DISP_OVL0_REG_OVL_L2_SRC_SIZE   OVL_L2_SRC_SIZE;     //14008078
	DISP_OVL0_REG_OVL_L2_OFFSET     OVL_L2_OFFSET;       //1400807C
	UINT32                          rsv_8080;         	 //14008080
	DISP_OVL0_REG_OVL_L2_PITCH      OVL_L2_PITCH;        //14008084
	DISP_OVL0_REG_OVL_L2_TILE       OVL_L2_TILE;         //14008088
	DISP_OVL0_REG_OVL_L2_CLIP       OVL_L2_CLIP;         //1400808C
	DISP_OVL0_REG_OVL_L3_CON        OVL_L3_CON;          //14008090
	DISP_OVL0_REG_OVL_L3_SRCKEY     OVL_L3_SRCKEY;       //14008094
	DISP_OVL0_REG_OVL_L3_SRC_SIZE   OVL_L3_SRC_SIZE;     //14008098
	DISP_OVL0_REG_OVL_L3_OFFSET     OVL_L3_OFFSET;       //1400809C
	UINT32                          rsv_80A0;         	 //140080A0
	DISP_OVL0_REG_OVL_L3_PITCH      OVL_L3_PITCH;        //140080A4
	DISP_OVL0_REG_OVL_L3_TILE       OVL_L3_TILE;         //140080A8
	DISP_OVL0_REG_OVL_L3_CLIP       OVL_L3_CLIP;         //140080AC
	UINT32                          rsv_80B0[4];      	 //140080B0..80BC
	DISP_OVL0_REG_OVL_RDMA0_CTRL    OVL_RDMA0_CTRL;      //140080C0
	UINT32                          rsv_80C4;         	 //140080C4
	DISP_OVL0_REG_OVL_RDMA0_MEM_GMC_SETTING1 OVL_RDMA0_MEM_GMC_SETTING1; //140080C8
	DISP_OVL0_REG_OVL_RDMA0_MEM_SLOW_CON OVL_RDMA0_MEM_SLOW_CON; //140080CC
	DISP_OVL0_REG_OVL_RDMA0_FIFO_CTRL OVL_RDMA0_FIFO_CTRL; //140080D0
	UINT32                          rsv_80D4[3];           //140080D4..80DC
	DISP_OVL0_REG_OVL_RDMA1_CTRL    OVL_RDMA1_CTRL;        //140080E0
	UINT32                          rsv_80E4;        	   //140080E4
	DISP_OVL0_REG_OVL_RDMA1_MEM_GMC_SETTING1 OVL_RDMA1_MEM_GMC_SETTING1; //140080E8
	DISP_OVL0_REG_OVL_RDMA1_MEM_SLOW_CON OVL_RDMA1_MEM_SLOW_CON; //140080EC
	DISP_OVL0_REG_OVL_RDMA1_FIFO_CTRL OVL_RDMA1_FIFO_CTRL; //140080F0  
	UINT32                          rsv_80F4[3];      	   //140080F4..80FC
	DISP_OVL0_REG_OVL_RDMA2_CTRL    OVL_RDMA2_CTRL;        //14008100
	UINT32                          rsv_8104;        	   //14008104
	DISP_OVL0_REG_OVL_RDMA2_MEM_GMC_SETTING1 OVL_RDMA2_MEM_GMC_SETTING1; //14008108
	DISP_OVL0_REG_OVL_RDMA2_MEM_SLOW_CON OVL_RDMA2_MEM_SLOW_CON; //1400810C
	DISP_OVL0_REG_OVL_RDMA2_FIFO_CTRL OVL_RDMA2_FIFO_CTRL; //14008110  
	UINT32                          rsv_8114[3];           //14008114..811C
	DISP_OVL0_REG_OVL_RDMA3_CTRL    OVL_RDMA3_CTRL;        //14008120
	UINT32                          rsv_8124;          	   //14008124
	DISP_OVL0_REG_OVL_RDMA3_MEM_GMC_SETTING1 OVL_RDMA3_MEM_GMC_SETTING1; //14008128
	DISP_OVL0_REG_OVL_RDMA3_MEM_SLOW_CON OVL_RDMA3_MEM_SLOW_CON; //1400812C
	DISP_OVL0_REG_OVL_RDMA3_FIFO_CTRL OVL_RDMA3_FIFO_CTRL;  //14008130
	DISP_OVL0_REG_OVL_L0_Y2R_PARA_R0 OVL_L0_Y2R_PARA_R0;	//14008134
	DISP_OVL0_REG_OVL_L0_Y2R_PARA_R1 OVL_L0_Y2R_PARA_R1;	//14008138
	DISP_OVL0_REG_OVL_L0_Y2R_PARA_G0 OVL_L0_Y2R_PARA_G0;	//1400813C
	DISP_OVL0_REG_OVL_L0_Y2R_PARA_G1 OVL_L0_Y2R_PARA_G1;	//14008140
	DISP_OVL0_REG_OVL_L0_Y2R_PARA_B0 OVL_L0_Y2R_PARA_B0;	//14008144
	DISP_OVL0_REG_OVL_L0_Y2R_PARA_B1 OVL_L0_Y2R_PARA_B1;	//14008148
	DISP_OVL0_REG_OVL_L0_Y2R_PARA_YUV_A_0 OVL_L0_Y2R_PARA_YUV_A_0; //1400814C
	DISP_OVL0_REG_OVL_L0_Y2R_PARA_YUV_A_1 OVL_L0_Y2R_PARA_YUV_A_1; //14008150
	DISP_OVL0_REG_OVL_L0_Y2R_PARA_RGB_A_0 OVL_L0_Y2R_PARA_RGB_A_0; //14008154
	DISP_OVL0_REG_OVL_L0_Y2R_PARA_RGB_A_1 OVL_L0_Y2R_PARA_RGB_A_1; //14008158
	DISP_OVL0_REG_OVL_L1_Y2R_PARA_R0 OVL_L1_Y2R_PARA_R0;	//1400815C
	DISP_OVL0_REG_OVL_L1_Y2R_PARA_R1 OVL_L1_Y2R_PARA_R1;	//14008160
	DISP_OVL0_REG_OVL_L1_Y2R_PARA_G0 OVL_L1_Y2R_PARA_G0;	//14008164
	DISP_OVL0_REG_OVL_L1_Y2R_PARA_G1 OVL_L1_Y2R_PARA_G1;	//14008168
	DISP_OVL0_REG_OVL_L1_Y2R_PARA_B0 OVL_L1_Y2R_PARA_B0;	//1400816C
	DISP_OVL0_REG_OVL_L1_Y2R_PARA_B1 OVL_L1_Y2R_PARA_B1;	//14008170
	DISP_OVL0_REG_OVL_L1_Y2R_PARA_YUV_A_0 OVL_L1_Y2R_PARA_YUV_A_0; //14008174
	DISP_OVL0_REG_OVL_L1_Y2R_PARA_YUV_A_1 OVL_L1_Y2R_PARA_YUV_A_1; //14008178
	DISP_OVL0_REG_OVL_L1_Y2R_PARA_RGB_A_0 OVL_L1_Y2R_PARA_RGB_A_0; //1400817C
	DISP_OVL0_REG_OVL_L1_Y2R_PARA_RGB_A_1 OVL_L1_Y2R_PARA_RGB_A_1; //14008180
	DISP_OVL0_REG_OVL_L2_Y2R_PARA_R0 OVL_L2_Y2R_PARA_R0;	//14008184
	DISP_OVL0_REG_OVL_L2_Y2R_PARA_R1 OVL_L2_Y2R_PARA_R1;	//14008188
	DISP_OVL0_REG_OVL_L2_Y2R_PARA_G0 OVL_L2_Y2R_PARA_G0;	//1400818C
	DISP_OVL0_REG_OVL_L2_Y2R_PARA_G1 OVL_L2_Y2R_PARA_G1;	//14008190
	DISP_OVL0_REG_OVL_L2_Y2R_PARA_B0 OVL_L2_Y2R_PARA_B0;	//14008194
	DISP_OVL0_REG_OVL_L2_Y2R_PARA_B1 OVL_L2_Y2R_PARA_B1;	//14008198
	DISP_OVL0_REG_OVL_L2_Y2R_PARA_YUV_A_0 OVL_L2_Y2R_PARA_YUV_A_0; //1400819C
	DISP_OVL0_REG_OVL_L2_Y2R_PARA_YUV_A_1 OVL_L2_Y2R_PARA_YUV_A_1; //140081A0
	DISP_OVL0_REG_OVL_L2_Y2R_PARA_RGB_A_0 OVL_L2_Y2R_PARA_RGB_A_0; //140081A4
	DISP_OVL0_REG_OVL_L2_Y2R_PARA_RGB_A_1 OVL_L2_Y2R_PARA_RGB_A_1; //140081A8
	DISP_OVL0_REG_OVL_L3_Y2R_PARA_R0 OVL_L3_Y2R_PARA_R0;	//140081AC
	DISP_OVL0_REG_OVL_L3_Y2R_PARA_R1 OVL_L3_Y2R_PARA_R1;	//140081B0
	DISP_OVL0_REG_OVL_L3_Y2R_PARA_G0 OVL_L3_Y2R_PARA_G0;	//140081B4
	DISP_OVL0_REG_OVL_L3_Y2R_PARA_G1 OVL_L3_Y2R_PARA_G1;	//140081B8
	DISP_OVL0_REG_OVL_L3_Y2R_PARA_B0 OVL_L3_Y2R_PARA_B0;	//140081BC
	DISP_OVL0_REG_OVL_L3_Y2R_PARA_B1 OVL_L3_Y2R_PARA_B1;	//140081C0
	DISP_OVL0_REG_OVL_L3_Y2R_PARA_YUV_A_0 OVL_L3_Y2R_PARA_YUV_A_0; //140081C4
	DISP_OVL0_REG_OVL_L3_Y2R_PARA_YUV_A_1 OVL_L3_Y2R_PARA_YUV_A_1; //140081C8
	DISP_OVL0_REG_OVL_L3_Y2R_PARA_RGB_A_0 OVL_L3_Y2R_PARA_RGB_A_0; //140081CC
	DISP_OVL0_REG_OVL_L3_Y2R_PARA_RGB_A_1 OVL_L3_Y2R_PARA_RGB_A_1; //140081D0
	DISP_OVL0_REG_OVL_DEBUG_MON_SEL OVL_DEBUG_MON_SEL; 				 //140081D4
	UINT32                          rsv_81D8;         				 //140081D8
	DISP_OVL0_REG_OVL_BLD_EXT       OVL_BLD_EXT;         		     //140081DC
	DISP_OVL0_REG_OVL_RDMA0_MEM_GMC_SETTING2 OVL_RDMA0_MEM_GMC_SETTING2; //140081E0
	DISP_OVL0_REG_OVL_RDMA1_MEM_GMC_SETTING2 OVL_RDMA1_MEM_GMC_SETTING2; //140081E4
	DISP_OVL0_REG_OVL_RDMA2_MEM_GMC_SETTING2 OVL_RDMA2_MEM_GMC_SETTING2; //140081E8
	DISP_OVL0_REG_OVL_RDMA3_MEM_GMC_SETTING2 OVL_RDMA3_MEM_GMC_SETTING2; //140081EC
	DISP_OVL0_REG_OVL_RDMA_BURST_CON0 OVL_RDMA_BURST_CON0; //140081F0
	DISP_OVL0_REG_OVL_RDMA_BURST_CON1 OVL_RDMA_BURST_CON1; //140081F4
	DISP_OVL0_REG_OVL_RDMA_GREQ_NUM OVL_RDMA_GREQ_NUM;     //140081F8
	DISP_OVL0_REG_OVL_RDMA_GREQ_URG_NUM OVL_RDMA_GREQ_URG_NUM; //140081FC
	DISP_OVL0_REG_OVL_DUMMY_REG     OVL_DUMMY_REG;       //14008200
	UINT32                          rsv_8204;            //14008204
	DISP_OVL0_REG_OVL_GDRDY_PRD 	OVL_GDRDY_PRD;		 //14008208
	DISP_OVL0_REG_OVL_RDMA_ULTRA_SRC OVL_RDMA_ULTRA_SRC; //1400820C
	DISP_OVL0_REG_OVL_RDMA0_BUF_LOW_TH OVL_RDMA0_BUF_LOW;	 //14008210
	DISP_OVL0_REG_OVL_RDMA1_BUF_LOW_TH OVL_RDMA1_BUF_LOW;	 //14008214
	DISP_OVL0_REG_OVL_RDMA2_BUF_LOW_TH OVL_RDMA2_BUF_LOW;	 //14008218
	DISP_OVL0_REG_OVL_RDMA3_BUF_LOW_TH OVL_RDMA3_BUF_LOW;	 //1400821C
	UINT32                          rsv_8220[4];         //14008220..822C
	DISP_OVL0_REG_OVL_SMI_DBG		OVL_SMI_DBG;		 //14008230
	DISP_OVL0_REG_OVL_GREQ_LAYER_CNT OVL_GREQ_LAYER_CNT; //14008234
	DISP_OVL0_REG_OVL_GDRDY_PRD_NUM OVL_GDRDY_PRD_NUM;	 //14008238	
	UINT32                          rsv_823C;         	 //1400823C
	DISP_OVL0_REG_OVL_FLOW_CTRL_DBG OVL_FLOW_CTRL_DBG;   //14008240
	DISP_OVL0_REG_OVL_ADDCON_DBG    OVL_ADDCON_DBG;      //14008244
	UINT32                          rsv_8248;         	 //14008248
	DISP_OVL0_REG_OVL_RDMA0_DBG     OVL_RDMA0_DBG;    	 //1400824C
	DISP_OVL0_REG_OVL_RDMA1_DBG     OVL_RDMA1_DBG;    	 //14008250
	DISP_OVL0_REG_OVL_RDMA2_DBG     OVL_RDMA2_DBG;    	 //14008254
	DISP_OVL0_REG_OVL_RDMA3_DBG     OVL_RDMA3_DBG;    	 //14008258
	DISP_OVL0_REG_OVL_L0_CLR		OVL_L0_CLR; 		 //1400825C
	DISP_OVL0_REG_OVL_L1_CLR 	   OVL_L1_CLR;			 //14008260
	DISP_OVL0_REG_OVL_L2_CLR 	   OVL_L2_CLR;			 //14008264
	DISP_OVL0_REG_OVL_L3_CLR 	   OVL_L3_CLR;			 //14008268
	DISP_OVL0_REG_OVL_LC_CLR 	   OVL_LC_CLR;			 //1400826C
	DISP_OVL0_REG_OVL_CRC		   OVL_CRC; 			 //14008270	
	UINT32                          rsv_8274[3];      	 //14008274..827C
	DISP_OVL0_REG_OVL_LC_CON        OVL_LC_CON;          //14008280
	DISP_OVL0_REG_OVL_LC_SRCKEY     OVL_LC_SRCKEY;       //14008284
	DISP_OVL0_REG_OVL_LC_SRC_SIZE   OVL_LC_SRC_SIZE;     //14008288
	DISP_OVL0_REG_OVL_LC_OFFSET     OVL_LC_OFFSET;       //1400828C
	DISP_OVL0_REG_OVL_LC_SRC_SEL    OVL_LC_SRC_SEL;      //14008290  
	UINT32                          rsv_8294[2];      	 //14008294..8298
	DISP_OVL0_REG_OVL_BANK_CON		OVL_BANK_CON;		 //1400829C
	DISP_OVL0_REG_OVL_FUNC_DCM0 	OVL_FUNC_DCM0;		 //140082A0
	DISP_OVL0_REG_OVL_FUNC_DCM1 	OVL_FUNC_DCM1;		 //140082A4	
	UINT32                          rsv_82A8[2];      	 //140082A8..82AC
	DISP_OVL0_REG_OVL_DVFS_L0_ROI	OVL_DVFS_L0_ROI;	 //140082B0
	DISP_OVL0_REG_OVL_DVFS_L1_ROI	OVL_DVFS_L1_ROI;	 //140082B4
	DISP_OVL0_REG_OVL_DVFS_L2_ROI	OVL_DVFS_L2_ROI;	 //140082B8
	DISP_OVL0_REG_OVL_DVFS_L3_ROI	OVL_DVFS_L3_ROI;	 //140082BC
	DISP_OVL0_REG_OVL_DVFS_EL0_ROI	OVL_DVFS_EL0_ROI;	 //140082C0
	DISP_OVL0_REG_OVL_DVFS_EL1_ROI	OVL_DVFS_EL1_ROI;	 //140082C4
	DISP_OVL0_REG_OVL_DVFS_EL2_ROI	OVL_DVFS_EL2_ROI;	 //140082C8	
	UINT32                          rsv_82CC[22];     		 //140082CC..8320
	DISP_OVL0_REG_OVL_DATAPATH_EXT_CON OVL_DATAPATH_EXT_CON; //14008324	
	UINT32                          rsv_8328[2];      		 //14008328..832C
	DISP_OVL0_REG_OVL_EL0_CON		OVL_EL0_CON;		 	 //14008330
	DISP_OVL0_REG_OVL_EL0_SRCKEY	OVL_EL0_SRCKEY; 	 //14008334
	DISP_OVL0_REG_OVL_EL0_SRC_SIZE	OVL_EL0_SRC_SIZE;	 //14008338
	DISP_OVL0_REG_OVL_EL0_OFFSET	OVL_EL0_OFFSET; 	 //1400833C	
	UINT32                          rsv_8340;         	 //14008340
	DISP_OVL0_REG_OVL_EL0_PITCH     OVL_EL0_PITCH;       //14008344
	DISP_OVL0_REG_OVL_EL0_TILE      OVL_EL0_TILE;        //14008348
	DISP_OVL0_REG_OVL_EL0_CLIP      OVL_EL0_CLIP;        //1400834C
	DISP_OVL0_REG_OVL_EL1_CON       OVL_EL1_CON;         //14008350
	DISP_OVL0_REG_OVL_EL1_SRCKEY    OVL_EL1_SRCKEY;      //14008354
	DISP_OVL0_REG_OVL_EL1_SRC_SIZE  OVL_EL1_SRC_SIZE;    //14008358
	DISP_OVL0_REG_OVL_EL1_OFFSET    OVL_EL1_OFFSET;      //1400835C  
	UINT32                          rsv_8360;         	 //14008360
	DISP_OVL0_REG_OVL_EL1_PITCH 	OVL_EL1_PITCH;		 //14008364
	DISP_OVL0_REG_OVL_EL1_TILE	   OVL_EL1_TILE;		 //14008368
	DISP_OVL0_REG_OVL_EL1_CLIP	   OVL_EL1_CLIP;		 //1400836C
	DISP_OVL0_REG_OVL_EL2_CON	   OVL_EL2_CON; 		 //14008370
	DISP_OVL0_REG_OVL_EL2_SRCKEY    OVL_EL2_SRCKEY;		 //14008374
	DISP_OVL0_REG_OVL_EL2_SRC_SIZE  OVL_EL2_SRC_SIZE;	 //14008378
	DISP_OVL0_REG_OVL_EL2_OFFSET    OVL_EL2_OFFSET;		 //1400837C	
	UINT32                          rsv_8380;            //14008380
	DISP_OVL0_REG_OVL_EL2_PITCH 	OVL_EL2_PITCH;		 //14008384
	DISP_OVL0_REG_OVL_EL2_TILE		OVL_EL2_TILE;		 //14008388
	DISP_OVL0_REG_OVL_EL2_CLIP		OVL_EL2_CLIP;		 //1400838C
	DISP_OVL0_REG_OVL_EL0_CLR		OVL_EL0_CLR;		 //14008390
	DISP_OVL0_REG_OVL_EL1_CLR		OVL_EL1_CLR;		 //14008394
	DISP_OVL0_REG_OVL_EL2_CLR		OVL_EL2_CLR;		 //14008398
	UINT32                          rsv_839C;            //1400839C
	DISP_OVL0_REG_OVL_SBCH			OVL_SBCH;		 	 //140083A0 
	DISP_OVL0_REG_OVL_SBCH_EXT		OVL_SBCH_EXT;		 //140083A4
	DISP_OVL0_REG_OVL_SBCH_CON		OVL_SBCH_CON;		 //140083A8
	UINT32                         rsv_83AC[741];    	 //140083AC..8F3C
	DISP_OVL0_REG_OVL_L0_ADDR		OVL_L0_ADDR;		 //14008F40
	UINT32                         rsv_8F44[7];          //14008F44..8F5C
	DISP_OVL0_REG_OVL_L1_ADDR	   OVL_L1_ADDR; 		 //14008F60
	UINT32                         rsv_8F64[7];          //14008F64..8F7C
	DISP_OVL0_REG_OVL_L2_ADDR	   OVL_L2_ADDR; 		 //14008F80
	UINT32                         rsv_8F84[7];          //14008F84..8F9C
	DISP_OVL0_REG_OVL_L3_ADDR	   OVL_L3_ADDR; 		 //14008FA0
	UINT32                         rsv_8FA4[3];      	 //14008FA4..8FAC
	DISP_OVL0_REG_OVL_EL0_ADDR	   OVL_EL0_ADDR;		 //14008FB0
	DISP_OVL0_REG_OVL_EL1_ADDR	   OVL_EL1_ADDR;		 //14008FB4
	DISP_OVL0_REG_OVL_EL2_ADDR	   OVL_EL2_ADDR;		 //14008FB8
	UINT32                         rsv_8FBC;             //14008FBC
	DISP_OVL0_REG_OVL_SECURE 	   OVL_SECURE;			 //14008FC0
}DISP_OVL0_REGS, *PDISP_OVL0_REGS;

// ---------- DISP_OVL0 Enum Definitions      ----------
// ---------- DISP_OVL0 C Macro Definitions   ----------
extern PDISP_OVL0_REGS g_DISP_OVL0_BASE;

#define DISP_OVL0_BASE                                         (g_DISP_OVL0_BASE)

#define DISP_OVL0_OVL_STA                                      (U32)(&DISP_OVL0_BASE->OVL_STA) // 8000
#define DISP_OVL0_OVL_INTEN                                    (U32)(&DISP_OVL0_BASE->OVL_INTEN) // 8004
#define DISP_OVL0_OVL_INTSTA                                   (U32)(&DISP_OVL0_BASE->OVL_INTSTA) // 8008
#define DISP_OVL0_OVL_EN                                       (U32)(&DISP_OVL0_BASE->OVL_EN) // 800C
#define DISP_OVL0_OVL_TRIG                                     (U32)(&DISP_OVL0_BASE->OVL_TRIG) // 8010
#define DISP_OVL0_OVL_RST                                      (U32)(&DISP_OVL0_BASE->OVL_RST) // 8014
#define DISP_OVL0_OVL_ROI_SIZE                                 (U32)(&DISP_OVL0_BASE->OVL_ROI_SIZE) // 8020
#define DISP_OVL0_OVL_DATAPATH_CON                             (U32)(&DISP_OVL0_BASE->OVL_DATAPATH_CON) // 8024
#define DISP_OVL0_OVL_ROI_BGCLR                                (U32)(&DISP_OVL0_BASE->OVL_ROI_BGCLR) // 8028
#define DISP_OVL0_OVL_SRC_CON                                  (U32)(&DISP_OVL0_BASE->OVL_SRC_CON) // 802C
#define DISP_OVL0_OVL_L0_CON                                   (U32)(&DISP_OVL0_BASE->OVL_L0_CON) // 8030
#define DISP_OVL0_OVL_L0_SRCKEY                                (U32)(&DISP_OVL0_BASE->OVL_L0_SRCKEY) // 8034
#define DISP_OVL0_OVL_L0_SRC_SIZE                              (U32)(&DISP_OVL0_BASE->OVL_L0_SRC_SIZE) // 8038
#define DISP_OVL0_OVL_L0_OFFSET                                (U32)(&DISP_OVL0_BASE->OVL_L0_OFFSET) // 803C
#define DISP_OVL0_OVL_L0_PITCH                                 (U32)(&DISP_OVL0_BASE->OVL_L0_PITCH) // 8044
#define DISP_OVL0_OVL_L0_TILE                                  (U32)(&DISP_OVL0_BASE->OVL_L0_TILE) // 8048
#define DISP_OVL0_OVL_L0_CLIP                                  (U32)(&DISP_OVL0_BASE->OVL_L0_CLIP) // 804C
#define DISP_OVL0_OVL_L1_CON                                   (U32)(&DISP_OVL0_BASE->OVL_L1_CON) // 8050
#define DISP_OVL0_OVL_L1_SRCKEY                                (U32)(&DISP_OVL0_BASE->OVL_L1_SRCKEY) // 8054
#define DISP_OVL0_OVL_L1_SRC_SIZE                              (U32)(&DISP_OVL0_BASE->OVL_L1_SRC_SIZE) // 8058
#define DISP_OVL0_OVL_L1_OFFSET                                (U32)(&DISP_OVL0_BASE->OVL_L1_OFFSET) // 805C
#define DISP_OVL0_OVL_L1_PITCH                                 (U32)(&DISP_OVL0_BASE->OVL_L1_PITCH) // 8064
#define DISP_OVL0_OVL_L1_TILE                                  (U32)(&DISP_OVL0_BASE->OVL_L1_TILE) // 8068
#define DISP_OVL0_OVL_L1_CLIP                                  (U32)(&DISP_OVL0_BASE->OVL_L1_CLIP) // 806C
#define DISP_OVL0_OVL_L2_CON                                   (U32)(&DISP_OVL0_BASE->OVL_L2_CON) // 8070
#define DISP_OVL0_OVL_L2_SRCKEY                                (U32)(&DISP_OVL0_BASE->OVL_L2_SRCKEY) // 8074
#define DISP_OVL0_OVL_L2_SRC_SIZE                              (U32)(&DISP_OVL0_BASE->OVL_L2_SRC_SIZE) // 8078
#define DISP_OVL0_OVL_L2_OFFSET                                (U32)(&DISP_OVL0_BASE->OVL_L2_OFFSET) // 807C
#define DISP_OVL0_OVL_L2_PITCH                                 (U32)(&DISP_OVL0_BASE->OVL_L2_PITCH) // 8084
#define DISP_OVL0_OVL_L2_TILE                                  (U32)(&DISP_OVL0_BASE->OVL_L2_TILE) // 8088
#define DISP_OVL0_OVL_L2_CLIP                                  (U32)(&DISP_OVL0_BASE->OVL_L2_CLIP) // 808C
#define DISP_OVL0_OVL_L3_CON                                   (U32)(&DISP_OVL0_BASE->OVL_L3_CON) // 8090
#define DISP_OVL0_OVL_L3_SRCKEY                                (U32)(&DISP_OVL0_BASE->OVL_L3_SRCKEY) // 8094
#define DISP_OVL0_OVL_L3_SRC_SIZE                              (U32)(&DISP_OVL0_BASE->OVL_L3_SRC_SIZE) // 8098
#define DISP_OVL0_OVL_L3_OFFSET                                (U32)(&DISP_OVL0_BASE->OVL_L3_OFFSET) // 809C
#define DISP_OVL0_OVL_L3_PITCH                                 (U32)(&DISP_OVL0_BASE->OVL_L3_PITCH) // 80A4
#define DISP_OVL0_OVL_L3_TILE                                  (U32)(&DISP_OVL0_BASE->OVL_L3_TILE) // 80A8
#define DISP_OVL0_OVL_L3_CLIP                                  (U32)(&DISP_OVL0_BASE->OVL_L3_CLIP) // 80AC
#define DISP_OVL0_OVL_RDMA0_CTRL                               (U32)(&DISP_OVL0_BASE->OVL_RDMA0_CTRL) // 80C0
#define DISP_OVL0_OVL_RDMA0_MEM_GMC_SETTING1                   (U32)(&DISP_OVL0_BASE->OVL_RDMA0_MEM_GMC_SETTING1) // 80C8
#define DISP_OVL0_OVL_RDMA0_MEM_SLOW_CON                       (U32)(&DISP_OVL0_BASE->OVL_RDMA0_MEM_SLOW_CON) // 80CC
#define DISP_OVL0_OVL_RDMA0_FIFO_CTRL                          (U32)(&DISP_OVL0_BASE->OVL_RDMA0_FIFO_CTRL) // 80D0
#define DISP_OVL0_OVL_RDMA1_CTRL                               (U32)(&DISP_OVL0_BASE->OVL_RDMA1_CTRL) // 80E0
#define DISP_OVL0_OVL_RDMA1_MEM_GMC_SETTING1                   (U32)(&DISP_OVL0_BASE->OVL_RDMA1_MEM_GMC_SETTING1) // 80E8
#define DISP_OVL0_OVL_RDMA1_MEM_SLOW_CON                       (U32)(&DISP_OVL0_BASE->OVL_RDMA1_MEM_SLOW_CON) // 80EC
#define DISP_OVL0_OVL_RDMA1_FIFO_CTRL                          (U32)(&DISP_OVL0_BASE->OVL_RDMA1_FIFO_CTRL) // 80F0
#define DISP_OVL0_OVL_RDMA2_CTRL                               (U32)(&DISP_OVL0_BASE->OVL_RDMA2_CTRL) // 8100
#define DISP_OVL0_OVL_RDMA2_MEM_GMC_SETTING1                   (U32)(&DISP_OVL0_BASE->OVL_RDMA2_MEM_GMC_SETTING1) // 8108
#define DISP_OVL0_OVL_RDMA2_MEM_SLOW_CON                       (U32)(&DISP_OVL0_BASE->OVL_RDMA2_MEM_SLOW_CON) // 810C
#define DISP_OVL0_OVL_RDMA2_FIFO_CTRL                          (U32)(&DISP_OVL0_BASE->OVL_RDMA2_FIFO_CTRL) // 8110
#define DISP_OVL0_OVL_RDMA3_CTRL                               (U32)(&DISP_OVL0_BASE->OVL_RDMA3_CTRL) // 8120
#define DISP_OVL0_OVL_RDMA3_MEM_GMC_SETTING1                   (U32)(&DISP_OVL0_BASE->OVL_RDMA3_MEM_GMC_SETTING1) // 8128
#define DISP_OVL0_OVL_RDMA3_MEM_SLOW_CON                       (U32)(&DISP_OVL0_BASE->OVL_RDMA3_MEM_SLOW_CON) // 812C
#define DISP_OVL0_OVL_RDMA3_FIFO_CTRL                          (U32)(&DISP_OVL0_BASE->OVL_RDMA3_FIFO_CTRL) // 8130
#define DISP_OVL0_OVL_L0_Y2R_PARA_R0                           (U32)(&DISP_OVL0_BASE->OVL_L0_Y2R_PARA_R0) // 8134
#define DISP_OVL0_OVL_L0_Y2R_PARA_R1                           (U32)(&DISP_OVL0_BASE->OVL_L0_Y2R_PARA_R1) // 8138
#define DISP_OVL0_OVL_L0_Y2R_PARA_G0                           (U32)(&DISP_OVL0_BASE->OVL_L0_Y2R_PARA_G0) // 813C
#define DISP_OVL0_OVL_L0_Y2R_PARA_G1                           (U32)(&DISP_OVL0_BASE->OVL_L0_Y2R_PARA_G1) // 8140
#define DISP_OVL0_OVL_L0_Y2R_PARA_B0                           (U32)(&DISP_OVL0_BASE->OVL_L0_Y2R_PARA_B0) // 8144
#define DISP_OVL0_OVL_L0_Y2R_PARA_B1                           (U32)(&DISP_OVL0_BASE->OVL_L0_Y2R_PARA_B1) // 8148
#define DISP_OVL0_OVL_L0_Y2R_PARA_YUV_A_0                      (U32)(&DISP_OVL0_BASE->OVL_L0_Y2R_PARA_YUV_A_0) // 814C
#define DISP_OVL0_OVL_L0_Y2R_PARA_YUV_A_1                      (U32)(&DISP_OVL0_BASE->OVL_L0_Y2R_PARA_YUV_A_1) // 8150
#define DISP_OVL0_OVL_L0_Y2R_PARA_RGB_A_0                      (U32)(&DISP_OVL0_BASE->OVL_L0_Y2R_PARA_RGB_A_0) // 8154
#define DISP_OVL0_OVL_L0_Y2R_PARA_RGB_A_1                      (U32)(&DISP_OVL0_BASE->OVL_L0_Y2R_PARA_RGB_A_1) // 8158
#define DISP_OVL0_OVL_L1_Y2R_PARA_R0                           (U32)(&DISP_OVL0_BASE->OVL_L1_Y2R_PARA_R0) // 815C
#define DISP_OVL0_OVL_L1_Y2R_PARA_R1                           (U32)(&DISP_OVL0_BASE->OVL_L1_Y2R_PARA_R1) // 8160
#define DISP_OVL0_OVL_L1_Y2R_PARA_G0                           (U32)(&DISP_OVL0_BASE->OVL_L1_Y2R_PARA_G0) // 8164
#define DISP_OVL0_OVL_L1_Y2R_PARA_G1                           (U32)(&DISP_OVL0_BASE->OVL_L1_Y2R_PARA_G1) // 8168
#define DISP_OVL0_OVL_L1_Y2R_PARA_B0                           (U32)(&DISP_OVL0_BASE->OVL_L1_Y2R_PARA_B0) // 816C
#define DISP_OVL0_OVL_L1_Y2R_PARA_B1                           (U32)(&DISP_OVL0_BASE->OVL_L1_Y2R_PARA_B1) // 8170
#define DISP_OVL0_OVL_L1_Y2R_PARA_YUV_A_0                      (U32)(&DISP_OVL0_BASE->OVL_L1_Y2R_PARA_YUV_A_0) // 8174
#define DISP_OVL0_OVL_L1_Y2R_PARA_YUV_A_1                      (U32)(&DISP_OVL0_BASE->OVL_L1_Y2R_PARA_YUV_A_1) // 8178
#define DISP_OVL0_OVL_L1_Y2R_PARA_RGB_A_0                      (U32)(&DISP_OVL0_BASE->OVL_L1_Y2R_PARA_RGB_A_0) // 817C
#define DISP_OVL0_OVL_L1_Y2R_PARA_RGB_A_1                      (U32)(&DISP_OVL0_BASE->OVL_L1_Y2R_PARA_RGB_A_1) // 8180
#define DISP_OVL0_OVL_L2_Y2R_PARA_R0                           (U32)(&DISP_OVL0_BASE->OVL_L2_Y2R_PARA_R0) // 8184
#define DISP_OVL0_OVL_L2_Y2R_PARA_R1                           (U32)(&DISP_OVL0_BASE->OVL_L2_Y2R_PARA_R1) // 8188
#define DISP_OVL0_OVL_L2_Y2R_PARA_G0                           (U32)(&DISP_OVL0_BASE->OVL_L2_Y2R_PARA_G0) // 818C
#define DISP_OVL0_OVL_L2_Y2R_PARA_G1                           (U32)(&DISP_OVL0_BASE->OVL_L2_Y2R_PARA_G1) // 8190
#define DISP_OVL0_OVL_L2_Y2R_PARA_B0                           (U32)(&DISP_OVL0_BASE->OVL_L2_Y2R_PARA_B0) // 8194
#define DISP_OVL0_OVL_L2_Y2R_PARA_B1                           (U32)(&DISP_OVL0_BASE->OVL_L2_Y2R_PARA_B1) // 8198
#define DISP_OVL0_OVL_L2_Y2R_PARA_YUV_A_0                      (U32)(&DISP_OVL0_BASE->OVL_L2_Y2R_PARA_YUV_A_0) // 819C
#define DISP_OVL0_OVL_L2_Y2R_PARA_YUV_A_1                      (U32)(&DISP_OVL0_BASE->OVL_L2_Y2R_PARA_YUV_A_1) // 81A0
#define DISP_OVL0_OVL_L2_Y2R_PARA_RGB_A_0                      (U32)(&DISP_OVL0_BASE->OVL_L2_Y2R_PARA_RGB_A_0) // 81A4
#define DISP_OVL0_OVL_L2_Y2R_PARA_RGB_A_1                      (U32)(&DISP_OVL0_BASE->OVL_L2_Y2R_PARA_RGB_A_1) // 81A8
#define DISP_OVL0_OVL_L3_Y2R_PARA_R0                           (U32)(&DISP_OVL0_BASE->OVL_L3_Y2R_PARA_R0) // 81AC
#define DISP_OVL0_OVL_L3_Y2R_PARA_R1                           (U32)(&DISP_OVL0_BASE->OVL_L3_Y2R_PARA_R1) // 81B0
#define DISP_OVL0_OVL_L3_Y2R_PARA_G0                           (U32)(&DISP_OVL0_BASE->OVL_L3_Y2R_PARA_G0) // 81B4
#define DISP_OVL0_OVL_L3_Y2R_PARA_G1                           (U32)(&DISP_OVL0_BASE->OVL_L3_Y2R_PARA_G1) // 81B8
#define DISP_OVL0_OVL_L3_Y2R_PARA_B0                           (U32)(&DISP_OVL0_BASE->OVL_L3_Y2R_PARA_B0) // 81BC
#define DISP_OVL0_OVL_L3_Y2R_PARA_B1                           (U32)(&DISP_OVL0_BASE->OVL_L3_Y2R_PARA_B1) // 81C0
#define DISP_OVL0_OVL_L3_Y2R_PARA_YUV_A_0                      (U32)(&DISP_OVL0_BASE->OVL_L3_Y2R_PARA_YUV_A_0) // 81C4
#define DISP_OVL0_OVL_L3_Y2R_PARA_YUV_A_1                      (U32)(&DISP_OVL0_BASE->OVL_L3_Y2R_PARA_YUV_A_1) // 81C8
#define DISP_OVL0_OVL_L3_Y2R_PARA_RGB_A_0                      (U32)(&DISP_OVL0_BASE->OVL_L3_Y2R_PARA_RGB_A_0) // 81CC
#define DISP_OVL0_OVL_L3_Y2R_PARA_RGB_A_1                      (U32)(&DISP_OVL0_BASE->OVL_L3_Y2R_PARA_RGB_A_1) // 81D0
#define DISP_OVL0_OVL_DEBUG_MON_SEL                            (U32)(&DISP_OVL0_BASE->OVL_DEBUG_MON_SEL) // 81D4
#define DISP_OVL0_OVL_BLD_EXT                                  (U32)(&DISP_OVL0_BASE->OVL_BLD_EXT) // 81DC
#define DISP_OVL0_OVL_RDMA0_MEM_GMC_SETTING2                   (U32)(&DISP_OVL0_BASE->OVL_RDMA0_MEM_GMC_SETTING2) // 81E0
#define DISP_OVL0_OVL_RDMA1_MEM_GMC_SETTING2                   (U32)(&DISP_OVL0_BASE->OVL_RDMA1_MEM_GMC_SETTING2) // 81E4
#define DISP_OVL0_OVL_RDMA2_MEM_GMC_SETTING2                   (U32)(&DISP_OVL0_BASE->OVL_RDMA2_MEM_GMC_SETTING2) // 81E8
#define DISP_OVL0_OVL_RDMA3_MEM_GMC_SETTING2                   (U32)(&DISP_OVL0_BASE->OVL_RDMA3_MEM_GMC_SETTING2) // 81EC
#define DISP_OVL0_OVL_RDMA_BURST_CON0                          (U32)(&DISP_OVL0_BASE->OVL_RDMA_BURST_CON0) // 81F0
#define DISP_OVL0_OVL_RDMA_BURST_CON1                          (U32)(&DISP_OVL0_BASE->OVL_RDMA_BURST_CON1) // 81F4
#define DISP_OVL0_OVL_RDMA_GREQ_NUM                            (U32)(&DISP_OVL0_BASE->OVL_RDMA_GREQ_NUM) // 81F8
#define DISP_OVL0_OVL_RDMA_GREQ_URG_NUM                        (U32)(&DISP_OVL0_BASE->OVL_RDMA_GREQ_URG_NUM) // 81FC
#define DISP_OVL0_OVL_DUMMY_REG                                (U32)(&DISP_OVL0_BASE->OVL_DUMMY_REG) // 8200
#define DISP_OVL0_OVL_GDRDY_PRD                                (U32)(&DISP_OVL0_BASE->OVL_GDRDY_PRD) // 8208
#define DISP_OVL0_OVL_RDMA_ULTRA_SRC                           (U32)(&DISP_OVL0_BASE->OVL_RDMA_ULTRA_SRC) // 820C
#define DISP_OVL0_OVL_RDMA0_BUF_LOW                            (U32)(&DISP_OVL0_BASE->OVL_RDMA0_BUF_LOW_TH) // 8210
#define DISP_OVL0_OVL_RDMA1_BUF_LOW                            (U32)(&DISP_OVL0_BASE->OVL_RDMA1_BUF_LOW_TH) // 8214
#define DISP_OVL0_OVL_RDMA2_BUF_LOW                            (U32)(&DISP_OVL0_BASE->OVL_RDMA2_BUF_LOW_TH) // 8218
#define DISP_OVL0_OVL_RDMA3_BUF_LOW                            (U32)(&DISP_OVL0_BASE->OVL_RDMA3_BUF_LOW_TH) // 821C
#define DISP_OVL0_OVL_RDMA0_BUF_HIGH_TH                        (U32)(&DISP_OVL0_BASE->OVL_RDMA0_BUF_HIGH_TH) // B220
#define DISP_OVL0_OVL_RDMA1_BUF_HIGH_TH                        (U32)(&DISP_OVL0_BASE->OVL_RDMA1_BUF_HIGH_TH) // B224
#define DISP_OVL0_OVL_RDMA2_BUF_HIGH_TH                        (U32)(&DISP_OVL0_BASE->OVL_RDMA2_BUF_HIGH_TH) // B228
#define DISP_OVL0_OVL_RDMA3_BUF_HIGH_TH                        (U32)(&DISP_OVL0_BASE->OVL_RDMA3_BUF_HIGH_TH) // B22C
#define DISP_OVL0_OVL_SMI_DBG                                  (U32)(&DISP_OVL0_BASE->OVL_SMI_DBG) // 8230
#define DISP_OVL0_OVL_GREQ_LAYER_CNT                           (U32)(&DISP_OVL0_BASE->OVL_GREQ_LAYER_CNT) // 8234
#define DISP_OVL0_OVL_GDRDY_PRD_NUM                            (U32)(&DISP_OVL0_BASE->OVL_GDRDY_PRD_NUM) // 8238
#define DISP_OVL0_OVL_FLOW_CTRL_DBG                            (U32)(&DISP_OVL0_BASE->OVL_FLOW_CTRL_DBG) // 8240
#define DISP_OVL0_OVL_ADDCON_DBG                               (U32)(&DISP_OVL0_BASE->OVL_ADDCON_DBG) // 8244
#define DISP_OVL0_OVL_RDMA0_DBG                                (U32)(&DISP_OVL0_BASE->OVL_RDMA0_DBG) // 824C
#define DISP_OVL0_OVL_RDMA1_DBG                                (U32)(&DISP_OVL0_BASE->OVL_RDMA1_DBG) // 8250
#define DISP_OVL0_OVL_RDMA2_DBG                                (U32)(&DISP_OVL0_BASE->OVL_RDMA2_DBG) // 8254
#define DISP_OVL0_OVL_RDMA3_DBG                                (U32)(&DISP_OVL0_BASE->OVL_RDMA3_DBG) // 8258
#define DISP_OVL0_OVL_L0_CLR                                   (U32)(&DISP_OVL0_BASE->OVL_L0_CLR) // 825C
#define DISP_OVL0_OVL_L1_CLR                                   (U32)(&DISP_OVL0_BASE->OVL_L1_CLR) // 8260
#define DISP_OVL0_OVL_L2_CLR                                   (U32)(&DISP_OVL0_BASE->OVL_L2_CLR) // 8264
#define DISP_OVL0_OVL_L3_CLR                                   (U32)(&DISP_OVL0_BASE->OVL_L3_CLR) // 8268
#define DISP_OVL0_OVL_LC_CLR                                   (U32)(&DISP_OVL0_BASE->OVL_LC_CLR) // 826C
#define DISP_OVL0_OVL_CRC                                      (U32)(&DISP_OVL0_BASE->OVL_CRC) // 8270
#define DISP_OVL0_OVL_LC_CON                                   (U32)(&DISP_OVL0_BASE->OVL_LC_CON) // 8280
#define DISP_OVL0_OVL_LC_SRCKEY                                (U32)(&DISP_OVL0_BASE->OVL_LC_SRCKEY) // 8284
#define DISP_OVL0_OVL_LC_SRC_SIZE                              (U32)(&DISP_OVL0_BASE->OVL_LC_SRC_SIZE) // 8288
#define DISP_OVL0_OVL_LC_OFFSET                                (U32)(&DISP_OVL0_BASE->OVL_LC_OFFSET) // 828C
#define DISP_OVL0_OVL_LC_SRC_SEL                               (U32)(&DISP_OVL0_BASE->OVL_LC_SRC_SEL) // 8290
#define DISP_OVL0_OVL_BANK_CON                                 (U32)(&DISP_OVL0_BASE->OVL_BANK_CON) // 829C
#define DISP_OVL0_OVL_FUNC_DCM0                                (U32)(&DISP_OVL0_BASE->OVL_FUNC_DCM0) // 82A0
#define DISP_OVL0_OVL_FUNC_DCM1                                (U32)(&DISP_OVL0_BASE->OVL_FUNC_DCM1) // 82A4
#define DISP_OVL0_OVL_DVFS_L0_ROI                              (U32)(&DISP_OVL0_BASE->OVL_DVFS_L0_ROI) // 82B0
#define DISP_OVL0_OVL_DVFS_L1_ROI                              (U32)(&DISP_OVL0_BASE->OVL_DVFS_L1_ROI) // 82B4
#define DISP_OVL0_OVL_DVFS_L2_ROI                              (U32)(&DISP_OVL0_BASE->OVL_DVFS_L2_ROI) // 82B8
#define DISP_OVL0_OVL_DVFS_L3_ROI                              (U32)(&DISP_OVL0_BASE->OVL_DVFS_L3_ROI) // 82BC
#define DISP_OVL0_OVL_DVFS_EL0_ROI                             (U32)(&DISP_OVL0_BASE->OVL_DVFS_EL0_ROI) // 82C0
#define DISP_OVL0_OVL_DVFS_EL1_ROI                             (U32)(&DISP_OVL0_BASE->OVL_DVFS_EL1_ROI) // 82C4
#define DISP_OVL0_OVL_DVFS_EL2_ROI                             (U32)(&DISP_OVL0_BASE->OVL_DVFS_EL2_ROI) // 82C8
#define DISP_OVL0_OVL_DATAPATH_EXT_CON                         (U32)(&DISP_OVL0_BASE->OVL_DATAPATH_EXT_CON) // 8324
#define DISP_OVL0_OVL_EL0_CON                                  (U32)(&DISP_OVL0_BASE->OVL_EL0_CON) // 8330
#define DISP_OVL0_OVL_EL0_SRCKEY                               (U32)(&DISP_OVL0_BASE->OVL_EL0_SRCKEY) // 8334
#define DISP_OVL0_OVL_EL0_SRC_SIZE                             (U32)(&DISP_OVL0_BASE->OVL_EL0_SRC_SIZE) // 8338
#define DISP_OVL0_OVL_EL0_OFFSET                               (U32)(&DISP_OVL0_BASE->OVL_EL0_OFFSET) // 833C
#define DISP_OVL0_OVL_EL0_PITCH                                (U32)(&DISP_OVL0_BASE->OVL_EL0_PITCH) // 8344
#define DISP_OVL0_OVL_EL0_TILE                                 (U32)(&DISP_OVL0_BASE->OVL_EL0_TILE) // 8348
#define DISP_OVL0_OVL_EL0_CLIP                                 (U32)(&DISP_OVL0_BASE->OVL_EL0_CLIP) // 834C
#define DISP_OVL0_OVL_EL1_CON                                  (U32)(&DISP_OVL0_BASE->OVL_EL1_CON) // 8350
#define DISP_OVL0_OVL_EL1_SRCKEY                               (U32)(&DISP_OVL0_BASE->OVL_EL1_SRCKEY) // 8354
#define DISP_OVL0_OVL_EL1_SRC_SIZE                             (U32)(&DISP_OVL0_BASE->OVL_EL1_SRC_SIZE) // 8358
#define DISP_OVL0_OVL_EL1_OFFSET                               (U32)(&DISP_OVL0_BASE->OVL_EL1_OFFSET) // 835C
#define DISP_OVL0_OVL_EL1_PITCH                                (U32)(&DISP_OVL0_BASE->OVL_EL1_PITCH) // 8364
#define DISP_OVL0_OVL_EL1_TILE                                 (U32)(&DISP_OVL0_BASE->OVL_EL1_TILE) // 8368
#define DISP_OVL0_OVL_EL1_CLIP                                 (U32)(&DISP_OVL0_BASE->OVL_EL1_CLIP) // 836C
#define DISP_OVL0_OVL_EL2_CON                                  (U32)(&DISP_OVL0_BASE->OVL_EL2_CON) // 8370
#define DISP_OVL0_OVL_EL2_SRCKEY                               (U32)(&DISP_OVL0_BASE->OVL_EL2_SRCKEY) // 8374
#define DISP_OVL0_OVL_EL2_SRC_SIZE                             (U32)(&DISP_OVL0_BASE->OVL_EL2_SRC_SIZE) // 8378
#define DISP_OVL0_OVL_EL2_OFFSET                               (U32)(&DISP_OVL0_BASE->OVL_EL2_OFFSET) // 837C
#define DISP_OVL0_OVL_EL2_PITCH                                (U32)(&DISP_OVL0_BASE->OVL_EL2_PITCH) // 8384
#define DISP_OVL0_OVL_EL2_TILE                                 (U32)(&DISP_OVL0_BASE->OVL_EL2_TILE) // 8388
#define DISP_OVL0_OVL_EL2_CLIP                                 (U32)(&DISP_OVL0_BASE->OVL_EL2_CLIP) // 838C
#define DISP_OVL0_OVL_EL0_CLR                                  (U32)(&DISP_OVL0_BASE->OVL_EL0_CLR) // 8390
#define DISP_OVL0_OVL_EL1_CLR                                  (U32)(&DISP_OVL0_BASE->OVL_EL1_CLR) // 8394
#define DISP_OVL0_OVL_EL2_CLR                                  (U32)(&DISP_OVL0_BASE->OVL_EL2_CLR) // 8398
#define DISP_OVL0_OVL_SBCH                                     (U32)(&DISP_OVL0_BASE->OVL_SBCH ) // 83A0
#define DISP_OVL0_OVL_SBCH_EXT                                 (U32)(&DISP_OVL0_BASE->OVL_SBCH_EXT ) // 83A4
#define DISP_OVL0_OVL_SBCH_CON                                 (U32)(&DISP_OVL0_BASE->OVL_SBCH_CON ) // 83A8
#define DISP_OVL0_OVL_L0_ADDR                                  (U32)(&DISP_OVL0_BASE->OVL_L0_ADDR) // 8F40
#define DISP_OVL0_OVL_L1_ADDR                                  (U32)(&DISP_OVL0_BASE->OVL_L1_ADDR) // 8F60
#define DISP_OVL0_OVL_L2_ADDR                                  (U32)(&DISP_OVL0_BASE->OVL_L2_ADDR) // 8F80
#define DISP_OVL0_OVL_L3_ADDR                                  (U32)(&DISP_OVL0_BASE->OVL_L3_ADDR) // 8FA0
#define DISP_OVL0_OVL_EL0_ADDR                                 (U32)(&DISP_OVL0_BASE->OVL_EL0_ADDR) // 8FB0
#define DISP_OVL0_OVL_EL1_ADDR                                 (U32)(&DISP_OVL0_BASE->OVL_EL1_ADDR) // 8FB4
#define DISP_OVL0_OVL_EL2_ADDR                                 (U32)(&DISP_OVL0_BASE->OVL_EL2_ADDR) // 8FB8
#define DISP_OVL0_OVL_SECURE                                   (U32)(&DISP_OVL0_BASE->OVL_SECURE) // 8FC0




#endif


#define OVL_STA_FLD_RDMA3_IDLE                                 REG_FLD(1, 4)
#define OVL_STA_FLD_RDMA2_IDLE                                 REG_FLD(1, 3)
#define OVL_STA_FLD_RDMA1_IDLE                                 REG_FLD(1, 2)
#define OVL_STA_FLD_RDMA0_IDLE                                 REG_FLD(1, 1)
#define OVL_STA_FLD_OVL_RUN                                    REG_FLD(1, 0)

#define OVL_INTEN_FLD_OVL_START_INTEN                          REG_FLD(1, 14)
#define OVL_INTEN_FLD_ABNORMAL_SOF_INTEN                       REG_FLD(1, 13)
#define OVL_INTEN_FLD_RDMA3_SMI_UNDERFLOW_INTEN                REG_FLD(1, 12)
#define OVL_INTEN_FLD_RDMA2_SMI_UNDERFLOW_INTEN                REG_FLD(1, 11)
#define OVL_INTEN_FLD_RDMA1_SMI_UNDERFLOW_INTEN                REG_FLD(1, 10)
#define OVL_INTEN_FLD_RDMA0_SMI_UNDERFLOW_INTEN                REG_FLD(1, 9)
#define OVL_INTEN_FLD_RDMA3_EOF_ABNORMAL_INTEN                 REG_FLD(1, 8)
#define OVL_INTEN_FLD_RDMA2_EOF_ABNORMAL_INTEN                 REG_FLD(1, 7)
#define OVL_INTEN_FLD_RDMA1_EOF_ABNORMAL_INTEN                 REG_FLD(1, 6)
#define OVL_INTEN_FLD_RDMA0_EOF_ABNORMAL_INTEN                 REG_FLD(1, 5)
#define OVL_INTEN_FLD_OVL_FME_HWRST_DONE_INTEN                 REG_FLD(1, 4)
#define OVL_INTEN_FLD_OVL_FME_SWRST_DONE_INTEN                 REG_FLD(1, 3)
#define OVL_INTEN_FLD_OVL_FME_UND_INTEN                        REG_FLD(1, 2)
#define OVL_INTEN_FLD_OVL_FME_CPL_INTEN                        REG_FLD(1, 1)
#define OVL_INTEN_FLD_OVL_REG_CMT_INTEN                        REG_FLD(1, 0)

#define OVL_INTSTA_FLD_OVL_START_INTSTA                        REG_FLD(1, 14)
#define OVL_INTSTA_FLD_ABNORMAL_SOF_INTSTA                     REG_FLD(1, 13)
#define OVL_INTSTA_FLD_RDMA3_SMI_UNDERFLOW_INTSTA              REG_FLD(1, 12)
#define OVL_INTSTA_FLD_RDMA2_SMI_UNDERFLOW_INTSTA              REG_FLD(1, 11)
#define OVL_INTSTA_FLD_RDMA1_SMI_UNDERFLOW_INTSTA              REG_FLD(1, 10)
#define OVL_INTSTA_FLD_RDMA0_SMI_UNDERFLOW_INTSTA              REG_FLD(1, 9)
#define OVL_INTSTA_FLD_RDMA3_EOF_ABNORMAL_INTSTA               REG_FLD(1, 8)
#define OVL_INTSTA_FLD_RDMA2_EOF_ABNORMAL_INTSTA               REG_FLD(1, 7)
#define OVL_INTSTA_FLD_RDMA1_EOF_ABNORMAL_INTSTA               REG_FLD(1, 6)
#define OVL_INTSTA_FLD_RDMA0_EOF_ABNORMAL_INTSTA               REG_FLD(1, 5)
#define OVL_INTSTA_FLD_OVL_FME_HWRST_DONE_INTSTA               REG_FLD(1, 4)
#define OVL_INTSTA_FLD_OVL_FME_SWRST_DONE_INTSTA               REG_FLD(1, 3)
#define OVL_INTSTA_FLD_OVL_FME_UND_INTSTA                      REG_FLD(1, 2)
#define OVL_INTSTA_FLD_OVL_FME_CPL_INTSTA                      REG_FLD(1, 1)
#define OVL_INTSTA_FLD_OVL_REG_CMT_INTSTA                      REG_FLD(1, 0)

#define OVL_EN_FLD_BLOCK_EXT_PREULTRA                          REG_FLD(1, 19)
#define OVL_EN_FLD_BLOCK_EXT_ULTRA                             REG_FLD(1, 18)
#define OVL_EN_FLD_IGNORE_ABNORMAL_SOF                         REG_FLD(1, 16)
#define OVL_EN_FLD_HF_FOVL_CK_ON                               REG_FLD(1, 10)
#define OVL_EN_FLD_HG_FSMI_CK_ON                               REG_FLD(1, 9)
#define OVL_EN_FLD_HG_FOVL_CK_ON                               REG_FLD(1, 8)
#define OVL_EN_FLD_OVL_EN                                      REG_FLD(1, 0)

#define OVL_TRIG_FLD_CRC_CLR                                   REG_FLD(1, 9)
#define OVL_TRIG_FLD_CRC_EN                                    REG_FLD(1, 8)
#define OVL_TRIG_FLD_OVL_SW_TRIG                               REG_FLD(1, 0)

#define OVL_RST_FLD_OVL_SMI_IOBUF_HARD_RST                     REG_FLD(1, 31)
#define OVL_RST_FLD_OVL_SMI_IOBUF_RST                          REG_FLD(1, 30)
#define OVL_RST_FLD_OVL_SMI_HARD_RST                           REG_FLD(1, 29)
#define OVL_RST_FLD_OVL_SMI_RST                                REG_FLD(1, 28)
#define OVL_RST_FLD_OVL_RST                                    REG_FLD(1, 0)

#define OVL_ROI_SIZE_FLD_ROI_H                                 REG_FLD(13, 16)
#define OVL_ROI_SIZE_FLD_ROI_W                                 REG_FLD(13, 0)

#define OVL_DATAPATH_CON_FLD_WIDE_GAMUT_EN                     REG_FLD(1, 31)
#define OVL_DATAPATH_CON_FLD_OUTPUT_INTERLACE                  REG_FLD(1, 27)
#define OVL_DATAPATH_CON_FLD_OUTPUT_CLAMP                      REG_FLD(1, 26)
#define OVL_DATAPATH_CON_FLD_GCLAST_EN                         REG_FLD(1, 24)
#define OVL_DATAPATH_CON_FLD_RDMA3_OUT_SEL                     REG_FLD(1, 23)
#define OVL_DATAPATH_CON_FLD_RDMA2_OUT_SEL                     REG_FLD(1, 22)
#define OVL_DATAPATH_CON_FLD_RDMA1_OUT_SEL                     REG_FLD(1, 21)
#define OVL_DATAPATH_CON_FLD_RDMA0_OUT_SEL                     REG_FLD(1, 20)
#define OVL_DATAPATH_CON_FLD_PQ_OUT_SEL                        REG_FLD(2, 16)
#define OVL_DATAPATH_CON_FLD_OVL_GAMMA_OUT                     REG_FLD(1, 15)
#define OVL_DATAPATH_CON_FLD_ADOBE_LAYER                       REG_FLD(2, 13)
#define OVL_DATAPATH_CON_FLD_ADOBE_MODE                        REG_FLD(1, 12)
#define OVL_DATAPATH_CON_FLD_L3_GPU_MODE                       REG_FLD(1, 11)
#define OVL_DATAPATH_CON_FLD_L2_GPU_MODE                       REG_FLD(1, 10)
#define OVL_DATAPATH_CON_FLD_L1_GPU_MODE                       REG_FLD(1, 9)
#define OVL_DATAPATH_CON_FLD_L0_GPU_MODE                       REG_FLD(1, 8)
#define OVL_DATAPATH_CON_FLD_OUTPUT_NO_RND                     REG_FLD(1, 3)
#define OVL_DATAPATH_CON_FLD_BGCLR_IN_SEL                      REG_FLD(1, 2)
#define OVL_DATAPATH_CON_FLD_OVL_RANDOM_BGCLR_EN               REG_FLD(1, 1)
#define OVL_DATAPATH_CON_FLD_LAYER_SMI_ID_EN                   REG_FLD(1, 0)

#define OVL_ROI_BGCLR_FLD_ALPHA                                REG_FLD(8, 24)
#define OVL_ROI_BGCLR_FLD_RED                                  REG_FLD(8, 16)
#define OVL_ROI_BGCLR_FLD_GREEN                                REG_FLD(8, 8)
#define OVL_ROI_BGCLR_FLD_BLUE                                 REG_FLD(8, 0)

#define OVL_SRC_CON_FLD_RELAY_MODE_EN                          REG_FLD(1, 9)
#define OVL_SRC_CON_FLD_FORCE_RELAY_MODE                       REG_FLD(1, 8)
#define OVL_SRC_CON_FLD_LC_EN                                  REG_FLD(1, 4)
#define OVL_SRC_CON_FLD_L3_EN                                  REG_FLD(1, 3)
#define OVL_SRC_CON_FLD_L2_EN                                  REG_FLD(1, 2)
#define OVL_SRC_CON_FLD_L1_EN                                  REG_FLD(1, 1)
#define OVL_SRC_CON_FLD_L0_EN                                  REG_FLD(1, 0)

#define OVL_L0_CON_FLD_DSTKEY_EN                               REG_FLD(1, 31)
#define OVL_L0_CON_FLD_SRCKEY_EN                               REG_FLD(1, 30)
#define OVL_L0_CON_FLD_LAYER_SRC                               REG_FLD(2, 28)
#define OVL_L0_CON_FLD_MTX_EN                                  REG_FLD(1, 27)
#define OVL_L0_CON_FLD_MTX_AUTO_DIS                            REG_FLD(1, 26)
#define OVL_L0_CON_FLD_RGB_SWAP                                REG_FLD(1, 25)
#define OVL_L0_CON_FLD_BYTE_SWAP                               REG_FLD(1, 24)
#define OVL_L0_CON_FLD_CLRFMT_MAN                              REG_FLD(1, 23)
#define OVL_L0_CON_FLD_R_FIRST                                 REG_FLD(1, 22)
#define OVL_L0_CON_FLD_LANDSCAPE                               REG_FLD(1, 21)
#define OVL_L0_CON_FLD_EN_3D                                   REG_FLD(1, 20)
#define OVL_L0_CON_FLD_INT_MTX_SEL                             REG_FLD(4, 16)
#define OVL_L0_CON_FLD_CLRFMT                                  REG_FLD(4, 12)
#define OVL_L0_CON_FLD_EXT_MTX_EN                              REG_FLD(1, 11)
#define OVL_L0_CON_FLD_HORIZONTAL_FLIP_EN                      REG_FLD(1, 10)
#define OVL_L0_CON_FLD_VERTICAL_FLIP_EN                        REG_FLD(1, 9)
#define OVL_L0_CON_FLD_ALPHA_EN                                REG_FLD(1, 8)
#define OVL_L0_CON_FLD_ALPHA                                   REG_FLD(8, 0)

#define OVL_L0_SRCKEY_FLD_SRCKEY                               REG_FLD(32, 0)

#define OVL_L0_SRC_SIZE_FLD_L0_SRC_H                           REG_FLD(13, 16)
#define OVL_L0_SRC_SIZE_FLD_L0_SRC_W                           REG_FLD(13, 0)

#define OVL_L0_OFFSET_FLD_L0_YOFF                              REG_FLD(13, 16)
#define OVL_L0_OFFSET_FLD_L0_XOFF                              REG_FLD(13, 0)

#define OVL_L0_PITCH_FLD_SURFL_EN                              REG_FLD(1, 31)
#define OVL_L0_PITCH_FLD_L0_BLEND_RND_SHT                      REG_FLD(1, 30)
#define OVL_L0_PITCH_FLD_L0_SRGB_SEL_EXT2                      REG_FLD(1, 29)
#define OVL_L0_PITCH_FLD_L0_CONST_BLD                          REG_FLD(1, 28)
#define OVL_L0_PITCH_FLD_L0_DRGB_SEL_EXT                       REG_FLD(1, 27)
#define OVL_L0_PITCH_FLD_L0_DA_SEL_EXT                         REG_FLD(1, 26)
#define OVL_L0_PITCH_FLD_L0_SRGB_SEL_EXT                       REG_FLD(1, 25)
#define OVL_L0_PITCH_FLD_L0_SA_SEL_EXT                         REG_FLD(1, 24)
#define OVL_L0_PITCH_FLD_L0_DRGB_SEL                           REG_FLD(2, 22)
#define OVL_L0_PITCH_FLD_L0_DA_SEL                             REG_FLD(2, 20)
#define OVL_L0_PITCH_FLD_L0_SRGB_SEL                           REG_FLD(2, 18)
#define OVL_L0_PITCH_FLD_L0_SA_SEL                             REG_FLD(2, 16)
#define OVL_L0_PITCH_FLD_L0_SRC_PITCH                          REG_FLD(16, 0)

#define OVL_L0_TILE_FLD_TILE_HORI_BLOCK_NUM                    REG_FLD(8, 24)
#define OVL_L0_TILE_FLD_TILE_EN                                REG_FLD(1, 21)
#define OVL_L0_TILE_FLD_TILE_WIDTH_SEL                         REG_FLD(1, 20)
#define OVL_L0_TILE_FLD_TILE_HEIGHT                            REG_FLD(20, 0)

#define OVL_L0_CLIP_FLD_L0_SRC_BOTTOM_CLIP                     REG_FLD(8, 24)
#define OVL_L0_CLIP_FLD_L0_SRC_TOP_CLIP                        REG_FLD(8, 16)
#define OVL_L0_CLIP_FLD_L0_SRC_RIGHT_CLIP                      REG_FLD(8, 8)
#define OVL_L0_CLIP_FLD_L0_SRC_LEFT_CLIP                       REG_FLD(8, 0)

#define OVL_L1_CON_FLD_DSTKEY_EN                               REG_FLD(1, 31)
#define OVL_L1_CON_FLD_SRCKEY_EN                               REG_FLD(1, 30)
#define OVL_L1_CON_FLD_LAYER_SRC                               REG_FLD(2, 28)
#define OVL_L1_CON_FLD_MTX_EN                                  REG_FLD(1, 27)
#define OVL_L1_CON_FLD_MTX_AUTO_DIS                            REG_FLD(1, 26)
#define OVL_L1_CON_FLD_RGB_SWAP                                REG_FLD(1, 25)
#define OVL_L1_CON_FLD_BYTE_SWAP                               REG_FLD(1, 24)
#define OVL_L1_CON_FLD_CLRFMT_MAN                              REG_FLD(1, 23)
#define OVL_L1_CON_FLD_R_FIRST                                 REG_FLD(1, 22)
#define OVL_L1_CON_FLD_LANDSCAPE                               REG_FLD(1, 21)
#define OVL_L1_CON_FLD_EN_3D                                   REG_FLD(1, 20)
#define OVL_L1_CON_FLD_INT_MTX_SEL                             REG_FLD(4, 16)
#define OVL_L1_CON_FLD_CLRFMT                                  REG_FLD(4, 12)
#define OVL_L1_CON_FLD_EXT_MTX_EN                              REG_FLD(1, 11)
#define OVL_L1_CON_FLD_HORIZONTAL_FLIP_EN                      REG_FLD(1, 10)
#define OVL_L1_CON_FLD_VERTICAL_FLIP_EN                        REG_FLD(1, 9)
#define OVL_L1_CON_FLD_ALPHA_EN                                REG_FLD(1, 8)
#define OVL_L1_CON_FLD_ALPHA                                   REG_FLD(8, 0)

#define OVL_L1_SRCKEY_FLD_SRCKEY                               REG_FLD(32, 0)

#define OVL_L1_SRC_SIZE_FLD_L1_SRC_H                           REG_FLD(13, 16)
#define OVL_L1_SRC_SIZE_FLD_L1_SRC_W                           REG_FLD(13, 0)

#define OVL_L1_OFFSET_FLD_L1_YOFF                              REG_FLD(13, 16)
#define OVL_L1_OFFSET_FLD_L1_XOFF                              REG_FLD(13, 0)

#define OVL_L1_PITCH_FLD_SURFL_EN                              REG_FLD(1, 31)
#define OVL_L1_PITCH_FLD_L1_BLEND_RND_SHT                      REG_FLD(1, 30)
#define OVL_L1_PITCH_FLD_L1_SRGB_SEL_EXT2                      REG_FLD(1, 29)
#define OVL_L1_PITCH_FLD_L1_CONST_BLD                          REG_FLD(1, 28)
#define OVL_L1_PITCH_FLD_L1_DRGB_SEL_EXT                       REG_FLD(1, 27)
#define OVL_L1_PITCH_FLD_L1_DA_SEL_EXT                         REG_FLD(1, 26)
#define OVL_L1_PITCH_FLD_L1_SRGB_SEL_EXT                       REG_FLD(1, 25)
#define OVL_L1_PITCH_FLD_L1_SA_SEL_EXT                         REG_FLD(1, 24)
#define OVL_L1_PITCH_FLD_L1_DRGB_SEL                           REG_FLD(2, 22)
#define OVL_L1_PITCH_FLD_L1_DA_SEL                             REG_FLD(2, 20)
#define OVL_L1_PITCH_FLD_L1_SRGB_SEL                           REG_FLD(2, 18)
#define OVL_L1_PITCH_FLD_L1_SA_SEL                             REG_FLD(2, 16)
#define OVL_L1_PITCH_FLD_L1_SRC_PITCH                          REG_FLD(16, 0)

#define OVL_L1_TILE_FLD_TILE_HORI_BLOCK_NUM                    REG_FLD(8, 24)
#define OVL_L1_TILE_FLD_TILE_EN                                REG_FLD(1, 21)
#define OVL_L1_TILE_FLD_TILE_WIDTH_SEL                         REG_FLD(1, 20)
#define OVL_L1_TILE_FLD_TILE_HEIGHT                            REG_FLD(20, 0)

#define OVL_L1_CLIP_FLD_L1_SRC_BOTTOM_CLIP                     REG_FLD(8, 24)
#define OVL_L1_CLIP_FLD_L1_SRC_TOP_CLIP                        REG_FLD(8, 16)
#define OVL_L1_CLIP_FLD_L1_SRC_RIGHT_CLIP                      REG_FLD(8, 8)
#define OVL_L1_CLIP_FLD_L1_SRC_LEFT_CLIP                       REG_FLD(8, 0)

#define OVL_L2_CON_FLD_DSTKEY_EN                               REG_FLD(1, 31)
#define OVL_L2_CON_FLD_SRCKEY_EN                               REG_FLD(1, 30)
#define OVL_L2_CON_FLD_LAYER_SRC                               REG_FLD(2, 28)
#define OVL_L2_CON_FLD_MTX_EN                                  REG_FLD(1, 27)
#define OVL_L2_CON_FLD_MTX_AUTO_DIS                            REG_FLD(1, 26)
#define OVL_L2_CON_FLD_RGB_SWAP                                REG_FLD(1, 25)
#define OVL_L2_CON_FLD_BYTE_SWAP                               REG_FLD(1, 24)
#define OVL_L2_CON_FLD_CLRFMT_MAN                              REG_FLD(1, 23)
#define OVL_L2_CON_FLD_R_FIRST                                 REG_FLD(1, 22)
#define OVL_L2_CON_FLD_LANDSCAPE                               REG_FLD(1, 21)
#define OVL_L2_CON_FLD_EN_3D                                   REG_FLD(1, 20)
#define OVL_L2_CON_FLD_INT_MTX_SEL                             REG_FLD(4, 16)
#define OVL_L2_CON_FLD_CLRFMT                                  REG_FLD(4, 12)
#define OVL_L2_CON_FLD_EXT_MTX_EN                              REG_FLD(1, 11)
#define OVL_L2_CON_FLD_HORIZONTAL_FLIP_EN                      REG_FLD(1, 10)
#define OVL_L2_CON_FLD_VERTICAL_FLIP_EN                        REG_FLD(1, 9)
#define OVL_L2_CON_FLD_ALPHA_EN                                REG_FLD(1, 8)
#define OVL_L2_CON_FLD_ALPHA                                   REG_FLD(8, 0)

#define OVL_L2_SRCKEY_FLD_SRCKEY                               REG_FLD(32, 0)

#define OVL_L2_SRC_SIZE_FLD_L2_SRC_H                           REG_FLD(13, 16)
#define OVL_L2_SRC_SIZE_FLD_L2_SRC_W                           REG_FLD(13, 0)

#define OVL_L2_OFFSET_FLD_L2_YOFF                              REG_FLD(13, 16)
#define OVL_L2_OFFSET_FLD_L2_XOFF                              REG_FLD(13, 0)

#define OVL_L2_PITCH_FLD_SURFL_EN                              REG_FLD(1, 31)
#define OVL_L2_PITCH_FLD_L2_BLEND_RND_SHT                      REG_FLD(1, 30)
#define OVL_L2_PITCH_FLD_L2_SRGB_SEL_EXT2                      REG_FLD(1, 29)
#define OVL_L2_PITCH_FLD_L2_CONST_BLD                          REG_FLD(1, 28)
#define OVL_L2_PITCH_FLD_L2_DRGB_SEL_EXT                       REG_FLD(1, 27)
#define OVL_L2_PITCH_FLD_L2_DA_SEL_EXT                         REG_FLD(1, 26)
#define OVL_L2_PITCH_FLD_L2_SRGB_SEL_EXT                       REG_FLD(1, 25)
#define OVL_L2_PITCH_FLD_L2_SA_SEL_EXT                         REG_FLD(1, 24)
#define OVL_L2_PITCH_FLD_L2_DRGB_SEL                           REG_FLD(2, 22)
#define OVL_L2_PITCH_FLD_L2_DA_SEL                             REG_FLD(2, 20)
#define OVL_L2_PITCH_FLD_L2_SRGB_SEL                           REG_FLD(2, 18)
#define OVL_L2_PITCH_FLD_L2_SA_SEL                             REG_FLD(2, 16)
#define OVL_L2_PITCH_FLD_L2_SRC_PITCH                          REG_FLD(16, 0)

#define OVL_L2_TILE_FLD_TILE_HORI_BLOCK_NUM                    REG_FLD(8, 24)
#define OVL_L2_TILE_FLD_TILE_EN                                REG_FLD(1, 21)
#define OVL_L2_TILE_FLD_TILE_WIDTH_SEL                         REG_FLD(1, 20)
#define OVL_L2_TILE_FLD_TILE_HEIGHT                            REG_FLD(20, 0)

#define OVL_L2_CLIP_FLD_L2_SRC_BOTTOM_CLIP                     REG_FLD(8, 24)
#define OVL_L2_CLIP_FLD_L2_SRC_TOP_CLIP                        REG_FLD(8, 16)
#define OVL_L2_CLIP_FLD_L2_SRC_RIGHT_CLIP                      REG_FLD(8, 8)
#define OVL_L2_CLIP_FLD_L2_SRC_LEFT_CLIP                       REG_FLD(8, 0)

#define OVL_L3_CON_FLD_DSTKEY_EN                               REG_FLD(1, 31)
#define OVL_L3_CON_FLD_SRCKEY_EN                               REG_FLD(1, 30)
#define OVL_L3_CON_FLD_LAYER_SRC                               REG_FLD(2, 28)
#define OVL_L3_CON_FLD_MTX_EN                                  REG_FLD(1, 27)
#define OVL_L3_CON_FLD_MTX_AUTO_DIS                            REG_FLD(1, 26)
#define OVL_L3_CON_FLD_RGB_SWAP                                REG_FLD(1, 25)
#define OVL_L3_CON_FLD_BYTE_SWAP                               REG_FLD(1, 24)
#define OVL_L3_CON_FLD_CLRFMT_MAN                              REG_FLD(1, 23)
#define OVL_L3_CON_FLD_R_FIRST                                 REG_FLD(1, 22)
#define OVL_L3_CON_FLD_LANDSCAPE                               REG_FLD(1, 21)
#define OVL_L3_CON_FLD_EN_3D                                   REG_FLD(1, 20)
#define OVL_L3_CON_FLD_INT_MTX_SEL                             REG_FLD(4, 16)
#define OVL_L3_CON_FLD_CLRFMT                                  REG_FLD(4, 12)
#define OVL_L3_CON_FLD_EXT_MTX_EN                              REG_FLD(1, 11)
#define OVL_L3_CON_FLD_HORIZONTAL_FLIP_EN                      REG_FLD(1, 10)
#define OVL_L3_CON_FLD_VERTICAL_FLIP_EN                        REG_FLD(1, 9)
#define OVL_L3_CON_FLD_ALPHA_EN                                REG_FLD(1, 8)
#define OVL_L3_CON_FLD_ALPHA                                   REG_FLD(8, 0)

#define OVL_L3_SRCKEY_FLD_SRCKEY                               REG_FLD(32, 0)

#define OVL_L3_SRC_SIZE_FLD_L3_SRC_H                           REG_FLD(13, 16)
#define OVL_L3_SRC_SIZE_FLD_L3_SRC_W                           REG_FLD(13, 0)

#define OVL_L3_OFFSET_FLD_L3_YOFF                              REG_FLD(13, 16)
#define OVL_L3_OFFSET_FLD_L3_XOFF                              REG_FLD(13, 0)

#define OVL_L3_PITCH_FLD_SURFL_EN                              REG_FLD(1, 31)
#define OVL_L3_PITCH_FLD_L3_BLEND_RND_SHT                      REG_FLD(1, 30)
#define OVL_L3_PITCH_FLD_L3_SRGB_SEL_EXT2                      REG_FLD(1, 29)
#define OVL_L3_PITCH_FLD_L3_CONST_BLD                          REG_FLD(1, 28)
#define OVL_L3_PITCH_FLD_L3_DRGB_SEL_EXT                       REG_FLD(1, 27)
#define OVL_L3_PITCH_FLD_L3_DA_SEL_EXT                         REG_FLD(1, 26)
#define OVL_L3_PITCH_FLD_L3_SRGB_SEL_EXT                       REG_FLD(1, 25)
#define OVL_L3_PITCH_FLD_L3_SA_SEL_EXT                         REG_FLD(1, 24)
#define OVL_L3_PITCH_FLD_L3_DRGB_SEL                           REG_FLD(2, 22)
#define OVL_L3_PITCH_FLD_L3_DA_SEL                             REG_FLD(2, 20)
#define OVL_L3_PITCH_FLD_L3_SRGB_SEL                           REG_FLD(2, 18)
#define OVL_L3_PITCH_FLD_L3_SA_SEL                             REG_FLD(2, 16)
#define OVL_L3_PITCH_FLD_L3_SRC_PITCH                          REG_FLD(16, 0)

#define OVL_L3_TILE_FLD_TILE_HORI_BLOCK_NUM                    REG_FLD(8, 24)
#define OVL_L3_TILE_FLD_TILE_EN                                REG_FLD(1, 21)
#define OVL_L3_TILE_FLD_TILE_WIDTH_SEL                         REG_FLD(1, 20)
#define OVL_L3_TILE_FLD_TILE_HEIGHT                            REG_FLD(20, 0)

#define OVL_L3_CLIP_FLD_L3_SRC_BOTTOM_CLIP                     REG_FLD(8, 24)
#define OVL_L3_CLIP_FLD_L3_SRC_TOP_CLIP                        REG_FLD(8, 16)
#define OVL_L3_CLIP_FLD_L3_SRC_RIGHT_CLIP                      REG_FLD(8, 8)
#define OVL_L3_CLIP_FLD_L3_SRC_LEFT_CLIP                       REG_FLD(8, 0)

#define OVL_RDMA0_CTRL_FLD_RDMA0_FIFO_USED_SIZE                REG_FLD(12, 16)
#define OVL_RDMA0_CTRL_FLD_RDMA0_INTERLACE                     REG_FLD(1, 4)
#define OVL_RDMA0_CTRL_FLD_RDMA0_EN                            REG_FLD(1, 0)

#define OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_PRE_ULTRA_THRESHOLD_HIGH_OFS REG_FLD(1, 31)
#define OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_ULTRA_THRESHOLD_HIGH_OFS REG_FLD(1, 28)
#define OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_OSTD_PREULTRA_TH  REG_FLD(10, 16)
#define OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_OSTD_ULTRA_TH     REG_FLD(10, 0)

#define OVL_RDMA0_MEM_SLOW_CON_FLD_RDMA0_SLOW_CNT              REG_FLD(16, 16)
#define OVL_RDMA0_MEM_SLOW_CON_FLD_RDMA0_SLOW_EN               REG_FLD(1, 0)

#define OVL_RDMA0_FIFO_CTRL_FLD_RDMA0_FIFO_UND_EN              REG_FLD(1, 31)
#define OVL_RDMA0_FIFO_CTRL_FLD_RDMA0_FIFO_SIZE                REG_FLD(12, 16)
#define OVL_RDMA0_FIFO_CTRL_FLD_RDMA0_FIFO_THRD                REG_FLD(10, 0)

#define OVL_RDMA1_CTRL_FLD_RDMA1_FIFO_USED_SIZE                REG_FLD(12, 16)
#define OVL_RDMA1_CTRL_FLD_RDMA1_INTERLACE                     REG_FLD(1, 4)
#define OVL_RDMA1_CTRL_FLD_RDMA1_EN                            REG_FLD(1, 0)

#define OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_PRE_ULTRA_THRESHOLD_HIGH_OFS REG_FLD(1, 31)
#define OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_ULTRA_THRESHOLD_HIGH_OFS REG_FLD(1, 28)
#define OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_OSTD_PREULTRA_TH  REG_FLD(10, 16)
#define OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_OSTD_ULTRA_TH     REG_FLD(10, 0)

#define OVL_RDMA1_MEM_SLOW_CON_FLD_RDMA1_SLOW_CNT              REG_FLD(16, 16)
#define OVL_RDMA1_MEM_SLOW_CON_FLD_RDMA1_SLOW_EN               REG_FLD(1, 0)

#define OVL_RDMA1_FIFO_CTRL_FLD_RDMA1_FIFO_UND_EN              REG_FLD(1, 31)
#define OVL_RDMA1_FIFO_CTRL_FLD_RDMA1_FIFO_SIZE                REG_FLD(12, 16)
#define OVL_RDMA1_FIFO_CTRL_FLD_RDMA1_FIFO_THRD                REG_FLD(10, 0)

#define OVL_RDMA2_CTRL_FLD_RDMA2_FIFO_USED_SIZE                REG_FLD(12, 16)
#define OVL_RDMA2_CTRL_FLD_RDMA2_INTERLACE                     REG_FLD(1, 4)
#define OVL_RDMA2_CTRL_FLD_RDMA2_EN                            REG_FLD(1, 0)

#define OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_PRE_ULTRA_THRESHOLD_HIGH_OFS REG_FLD(1, 31)
#define OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_ULTRA_THRESHOLD_HIGH_OFS REG_FLD(1, 28)
#define OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_OSTD_PREULTRA_TH  REG_FLD(10, 16)
#define OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_OSTD_ULTRA_TH     REG_FLD(10, 0)

#define OVL_RDMA2_MEM_SLOW_CON_FLD_RDMA2_SLOW_CNT              REG_FLD(16, 16)
#define OVL_RDMA2_MEM_SLOW_CON_FLD_RDMA2_SLOW_EN               REG_FLD(1, 0)

#define OVL_RDMA2_FIFO_CTRL_FLD_RDMA2_FIFO_UND_EN              REG_FLD(1, 31)
#define OVL_RDMA2_FIFO_CTRL_FLD_RDMA2_FIFO_SIZE                REG_FLD(12, 16)
#define OVL_RDMA2_FIFO_CTRL_FLD_RDMA2_FIFO_THRD                REG_FLD(10, 0)

#define OVL_RDMA3_CTRL_FLD_RDMA3_FIFO_USED_SIZE                REG_FLD(12, 16)
#define OVL_RDMA3_CTRL_FLD_RDMA3_INTERLACE                     REG_FLD(1, 4)
#define OVL_RDMA3_CTRL_FLD_RDMA3_EN                            REG_FLD(1, 0)

#define OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_PRE_ULTRA_THRESHOLD_HIGH_OFS REG_FLD(1, 31)
#define OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_ULTRA_THRESHOLD_HIGH_OFS REG_FLD(1, 28)
#define OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_OSTD_PREULTRA_TH  REG_FLD(10, 16)
#define OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_OSTD_ULTRA_TH     REG_FLD(10, 0)

#define OVL_RDMA3_MEM_SLOW_CON_FLD_RDMA3_SLOW_CNT              REG_FLD(16, 16)
#define OVL_RDMA3_MEM_SLOW_CON_FLD_RDMA3_SLOW_EN               REG_FLD(1, 0)

#define OVL_RDMA3_FIFO_CTRL_FLD_RDMA3_FIFO_UND_EN              REG_FLD(1, 31)
#define OVL_RDMA3_FIFO_CTRL_FLD_RDMA3_FIFO_SIZE                REG_FLD(12, 16)
#define OVL_RDMA3_FIFO_CTRL_FLD_RDMA3_FIFO_THRD                REG_FLD(10, 0)

#define OVL_L0_Y2R_PARA_R0_FLD_C_CF_RMU                        REG_FLD(13, 16)
#define OVL_L0_Y2R_PARA_R0_FLD_C_CF_RMY                        REG_FLD(13, 0)

#define OVL_L0_Y2R_PARA_R1_FLD_C_CF_RMV                        REG_FLD(13, 0)

#define OVL_L0_Y2R_PARA_G0_FLD_C_CF_GMU                        REG_FLD(13, 16)
#define OVL_L0_Y2R_PARA_G0_FLD_C_CF_GMY                        REG_FLD(13, 0)

#define OVL_L0_Y2R_PARA_G1_FLD_C_CF_GMV                        REG_FLD(13, 0)

#define OVL_L0_Y2R_PARA_B0_FLD_C_CF_BMU                        REG_FLD(13, 16)
#define OVL_L0_Y2R_PARA_B0_FLD_C_CF_BMY                        REG_FLD(13, 0)

#define OVL_L0_Y2R_PARA_B1_FLD_C_CF_BMV                        REG_FLD(13, 0)

#define OVL_L0_Y2R_PARA_YUV_A_0_FLD_C_CF_UA                    REG_FLD(9, 16)
#define OVL_L0_Y2R_PARA_YUV_A_0_FLD_C_CF_YA                    REG_FLD(9, 0)

#define OVL_L0_Y2R_PARA_YUV_A_1_FLD_C_CF_VA                    REG_FLD(9, 0)

#define OVL_L0_Y2R_PARA_RGB_A_0_FLD_C_CF_GA                    REG_FLD(9, 16)
#define OVL_L0_Y2R_PARA_RGB_A_0_FLD_C_CF_RA                    REG_FLD(9, 0)

#define OVL_L0_Y2R_PARA_RGB_A_1_FLD_C_CF_BA                    REG_FLD(9, 0)

#define OVL_L1_Y2R_PARA_R0_FLD_C_CF_RMU                        REG_FLD(13, 16)
#define OVL_L1_Y2R_PARA_R0_FLD_C_CF_RMY                        REG_FLD(13, 0)

#define OVL_L1_Y2R_PARA_R1_FLD_C_CF_RMV                        REG_FLD(13, 0)

#define OVL_L1_Y2R_PARA_G0_FLD_C_CF_GMU                        REG_FLD(13, 16)
#define OVL_L1_Y2R_PARA_G0_FLD_C_CF_GMY                        REG_FLD(13, 0)

#define OVL_L1_Y2R_PARA_G1_FLD_C_CF_GMV                        REG_FLD(13, 0)

#define OVL_L1_Y2R_PARA_B0_FLD_C_CF_BMU                        REG_FLD(13, 16)
#define OVL_L1_Y2R_PARA_B0_FLD_C_CF_BMY                        REG_FLD(13, 0)

#define OVL_L1_Y2R_PARA_B1_FLD_C_CF_BMV                        REG_FLD(13, 0)

#define OVL_L1_Y2R_PARA_YUV_A_0_FLD_C_CF_UA                    REG_FLD(9, 16)
#define OVL_L1_Y2R_PARA_YUV_A_0_FLD_C_CF_YA                    REG_FLD(9, 0)

#define OVL_L1_Y2R_PARA_YUV_A_1_FLD_C_CF_VA                    REG_FLD(9, 0)

#define OVL_L1_Y2R_PARA_RGB_A_0_FLD_C_CF_GA                    REG_FLD(9, 16)
#define OVL_L1_Y2R_PARA_RGB_A_0_FLD_C_CF_RA                    REG_FLD(9, 0)

#define OVL_L1_Y2R_PARA_RGB_A_1_FLD_C_CF_BA                    REG_FLD(9, 0)

#define OVL_L2_Y2R_PARA_R0_FLD_C_CF_RMU                        REG_FLD(13, 16)
#define OVL_L2_Y2R_PARA_R0_FLD_C_CF_RMY                        REG_FLD(13, 0)

#define OVL_L2_Y2R_PARA_R1_FLD_C_CF_RMV                        REG_FLD(13, 0)

#define OVL_L2_Y2R_PARA_G0_FLD_C_CF_GMU                        REG_FLD(13, 16)
#define OVL_L2_Y2R_PARA_G0_FLD_C_CF_GMY                        REG_FLD(13, 0)

#define OVL_L2_Y2R_PARA_G1_FLD_C_CF_GMV                        REG_FLD(13, 0)

#define OVL_L2_Y2R_PARA_B0_FLD_C_CF_BMU                        REG_FLD(13, 16)
#define OVL_L2_Y2R_PARA_B0_FLD_C_CF_BMY                        REG_FLD(13, 0)

#define OVL_L2_Y2R_PARA_B1_FLD_C_CF_BMV                        REG_FLD(13, 0)

#define OVL_L2_Y2R_PARA_YUV_A_0_FLD_C_CF_UA                    REG_FLD(9, 16)
#define OVL_L2_Y2R_PARA_YUV_A_0_FLD_C_CF_YA                    REG_FLD(9, 0)

#define OVL_L2_Y2R_PARA_YUV_A_1_FLD_C_CF_VA                    REG_FLD(9, 0)

#define OVL_L2_Y2R_PARA_RGB_A_0_FLD_C_CF_GA                    REG_FLD(9, 16)
#define OVL_L2_Y2R_PARA_RGB_A_0_FLD_C_CF_RA                    REG_FLD(9, 0)

#define OVL_L2_Y2R_PARA_RGB_A_1_FLD_C_CF_BA                    REG_FLD(9, 0)

#define OVL_L3_Y2R_PARA_R0_FLD_C_CF_RMU                        REG_FLD(13, 16)
#define OVL_L3_Y2R_PARA_R0_FLD_C_CF_RMY                        REG_FLD(13, 0)

#define OVL_L3_Y2R_PARA_R1_FLD_C_CF_RMV                        REG_FLD(13, 0)

#define OVL_L3_Y2R_PARA_G0_FLD_C_CF_GMU                        REG_FLD(13, 16)
#define OVL_L3_Y2R_PARA_G0_FLD_C_CF_GMY                        REG_FLD(13, 0)

#define OVL_L3_Y2R_PARA_G1_FLD_C_CF_GMV                        REG_FLD(13, 0)

#define OVL_L3_Y2R_PARA_B0_FLD_C_CF_BMU                        REG_FLD(13, 16)
#define OVL_L3_Y2R_PARA_B0_FLD_C_CF_BMY                        REG_FLD(13, 0)

#define OVL_L3_Y2R_PARA_B1_FLD_C_CF_BMV                        REG_FLD(13, 0)

#define OVL_L3_Y2R_PARA_YUV_A_0_FLD_C_CF_UA                    REG_FLD(9, 16)
#define OVL_L3_Y2R_PARA_YUV_A_0_FLD_C_CF_YA                    REG_FLD(9, 0)

#define OVL_L3_Y2R_PARA_YUV_A_1_FLD_C_CF_VA                    REG_FLD(9, 0)

#define OVL_L3_Y2R_PARA_RGB_A_0_FLD_C_CF_GA                    REG_FLD(9, 16)
#define OVL_L3_Y2R_PARA_RGB_A_0_FLD_C_CF_RA                    REG_FLD(9, 0)

#define OVL_L3_Y2R_PARA_RGB_A_1_FLD_C_CF_BA                    REG_FLD(9, 0)

#define OVL_DEBUG_MON_SEL_FLD_DBG_MON_SEL                      REG_FLD(4, 0)

#define OVL_BLD_EXT_FLD_EL2_MINUS_BLD                          REG_FLD(1, 7)
#define OVL_BLD_EXT_FLD_EL1_MINUS_BLD                          REG_FLD(1, 6)
#define OVL_BLD_EXT_FLD_EL0_MINUS_BLD                          REG_FLD(1, 5)
#define OVL_BLD_EXT_FLD_LC_MINUS_BLD                           REG_FLD(1, 4)
#define OVL_BLD_EXT_FLD_L3_MINUS_BLD                           REG_FLD(1, 3)
#define OVL_BLD_EXT_FLD_L2_MINUS_BLD                           REG_FLD(1, 2)
#define OVL_BLD_EXT_FLD_L1_MINUS_BLD                           REG_FLD(1, 1)
#define OVL_BLD_EXT_FLD_L0_MINUS_BLD                           REG_FLD(1, 0)

#define OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_FORCE_REQ_THRESHOLD REG_FLD(1, 30)
#define OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_REQ_THRESHOLD_ULTRA REG_FLD(1, 29)
#define OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_REQ_THRESHOLD_PREULTRA REG_FLD(1, 28)
#define OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_ISSUE_REQ_THRESHOLD_URG REG_FLD(12, 16)
#define OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_ISSUE_REQ_THRESHOLD REG_FLD(12, 0)

#define OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_FORCE_REQ_THRESHOLD REG_FLD(1, 30)
#define OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_REQ_THRESHOLD_ULTRA REG_FLD(1, 29)
#define OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_REQ_THRESHOLD_PREULTRA REG_FLD(1, 28)
#define OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_ISSUE_REQ_THRESHOLD_URG REG_FLD(12, 16)
#define OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_ISSUE_REQ_THRESHOLD REG_FLD(12, 0)

#define OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_FORCE_REQ_THRESHOLD REG_FLD(1, 30)
#define OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_REQ_THRESHOLD_ULTRA REG_FLD(1, 29)
#define OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_REQ_THRESHOLD_PREULTRA REG_FLD(1, 28)
#define OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_ISSUE_REQ_THRESHOLD_URG REG_FLD(12, 16)
#define OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_ISSUE_REQ_THRESHOLD REG_FLD(12, 0)

#define OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_FORCE_REQ_THRESHOLD REG_FLD(1, 30)
#define OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_REQ_THRESHOLD_ULTRA REG_FLD(1, 29)
#define OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_REQ_THRESHOLD_PREULTRA REG_FLD(1, 28)
#define OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_ISSUE_REQ_THRESHOLD_URG REG_FLD(12, 16)
#define OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_ISSUE_REQ_THRESHOLD REG_FLD(12, 0)

#define OVL_RDMA_BURST_CON0_FLD_BURST_128B_BOUND               REG_FLD(1, 28)
#define OVL_RDMA_BURST_CON0_FLD_BURST15A_32B                   REG_FLD(3, 24)
#define OVL_RDMA_BURST_CON0_FLD_BURST14A_32B                   REG_FLD(3, 20)
#define OVL_RDMA_BURST_CON0_FLD_BURST13A_32B                   REG_FLD(3, 16)
#define OVL_RDMA_BURST_CON0_FLD_BURST12A_32B                   REG_FLD(3, 12)
#define OVL_RDMA_BURST_CON0_FLD_BURST11A_32B                   REG_FLD(3, 8)
#define OVL_RDMA_BURST_CON0_FLD_BURST10A_32B                   REG_FLD(3, 4)
#define OVL_RDMA_BURST_CON0_FLD_BURST9A_32B                    REG_FLD(3, 0)

#define OVL_RDMA_BURST_CON1_FLD_BURST15A_N32B                  REG_FLD(3, 24)
#define OVL_RDMA_BURST_CON1_FLD_BURST14A_N32B                  REG_FLD(3, 20)
#define OVL_RDMA_BURST_CON1_FLD_BURST13A_N32B                  REG_FLD(3, 16)
#define OVL_RDMA_BURST_CON1_FLD_BURST12A_N32B                  REG_FLD(3, 12)
#define OVL_RDMA_BURST_CON1_FLD_BURST11A_N32B                  REG_FLD(3, 8)
#define OVL_RDMA_BURST_CON1_FLD_BURST10A_N32B                  REG_FLD(3, 4)
#define OVL_RDMA_BURST_CON1_FLD_BURST9A_N32B                   REG_FLD(3, 0)

#define OVL_RDMA_GREQ_NUM_FLD_IOBUF_FLUSH_ULTRA                REG_FLD(1, 31)
#define OVL_RDMA_GREQ_NUM_FLD_IOBUF_FLUSH_PREULTRA             REG_FLD(1, 30)
#define OVL_RDMA_GREQ_NUM_FLD_GRP_BRK_STOP                     REG_FLD(1, 29)
#define OVL_RDMA_GREQ_NUM_FLD_GRP_END_STOP                     REG_FLD(1, 28)
#define OVL_RDMA_GREQ_NUM_FLD_GREQ_STOP_EN                     REG_FLD(1, 27)
#define OVL_RDMA_GREQ_NUM_FLD_GREQ_DIS_CNT                     REG_FLD(3, 24)
#define OVL_RDMA_GREQ_NUM_FLD_OSTD_GREQ_NUM                    REG_FLD(8, 16)
#define OVL_RDMA_GREQ_NUM_FLD_LAYER3_GREQ_NUM                  REG_FLD(4, 12)
#define OVL_RDMA_GREQ_NUM_FLD_LAYER2_GREQ_NUM                  REG_FLD(4, 8)
#define OVL_RDMA_GREQ_NUM_FLD_LAYER1_GREQ_NUM                  REG_FLD(4, 4)
#define OVL_RDMA_GREQ_NUM_FLD_LAYER0_GREQ_NUM                  REG_FLD(4, 0)

#define OVL_RDMA_GREQ_URG_NUM_FLD_GREQ_NUM_SHT                 REG_FLD(2, 30)
#define OVL_RDMA_GREQ_URG_NUM_FLD_GREQ_NUM_SHT_VAL             REG_FLD(1, 29)
#define OVL_RDMA_GREQ_URG_NUM_FLD_ARG_URG_BIAS                 REG_FLD(1, 28)
#define OVL_RDMA_GREQ_URG_NUM_FLD_ARG_GREQ_URG_TH              REG_FLD(10, 16)
#define OVL_RDMA_GREQ_URG_NUM_FLD_LAYER3_GREQ_URG_NUM          REG_FLD(4, 12)
#define OVL_RDMA_GREQ_URG_NUM_FLD_LAYER2_GREQ_URG_NUM          REG_FLD(4, 8)
#define OVL_RDMA_GREQ_URG_NUM_FLD_LAYER1_GREQ_URG_NUM          REG_FLD(4, 4)
#define OVL_RDMA_GREQ_URG_NUM_FLD_LAYER0_GREQ_URG_NUM          REG_FLD(4, 0)

#define OVL_DUMMY_REG_FLD_OVERLAY_DUMMY                        REG_FLD(32, 0)

#define OVL_GDRDY_PRD_FLD_GDRDY_PRD                            REG_FLD(24, 0)

#define OVL_RDMA_ULTRA_SRC_FLD_ULTRA_RDMA_SRC                  REG_FLD(2, 14)
#define OVL_RDMA_ULTRA_SRC_FLD_ULTRA_ROI_END_SRC               REG_FLD(2, 12)
#define OVL_RDMA_ULTRA_SRC_FLD_ULTRA_SMI_SRC                   REG_FLD(2, 10)
#define OVL_RDMA_ULTRA_SRC_FLD_ULTRA_BUF_SRC                   REG_FLD(2, 8)
#define OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_RDMA_SRC               REG_FLD(2, 6)
#define OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_ROI_END_SRC            REG_FLD(2, 4)
#define OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_SMI_SRC                REG_FLD(2, 2)
#define OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_BUF_SRC                REG_FLD(2, 0)

#define OVL_RDMA0_BUF_LOW_TH_FLD_RDMA0_PREULTRA_LOW_TH         REG_FLD(12, 12)
#define OVL_RDMA0_BUF_LOW_TH_FLD_RDMA0_ULTRA_LOW_TH            REG_FLD(12, 0)

#define OVL_RDMA1_BUF_LOW_TH_FLD_RDMA1_PREULTRA_LOW_TH         REG_FLD(12, 12)
#define OVL_RDMA1_BUF_LOW_TH_FLD_RDMA1_ULTRA_LOW_TH            REG_FLD(12, 0)

#define OVL_RDMA2_BUF_LOW_TH_FLD_RDMA2_PREULTRA_LOW_TH         REG_FLD(12, 12)
#define OVL_RDMA2_BUF_LOW_TH_FLD_RDMA2_ULTRA_LOW_TH            REG_FLD(12, 0)

#define OVL_RDMA3_BUF_LOW_TH_FLD_RDMA3_PREULTRA_LOW_TH         REG_FLD(12, 12)
#define OVL_RDMA3_BUF_LOW_TH_FLD_RDMA3_ULTRA_LOW_TH            REG_FLD(12, 0)

#define OVL_RDMA0_BUF_HIGH_TH_FLD_RDMA0_PREULTRA_HIGH_DIS      REG_FLD(1, 31)
#define OVL_RDMA0_BUF_HIGH_TH_FLD_RDMA0_PREULTRA_HIGH_TH       REG_FLD(12, 12)

#define OVL_RDMA1_BUF_HIGH_TH_FLD_RDMA1_PREULTRA_HIGH_DIS      REG_FLD(1, 31)
#define OVL_RDMA1_BUF_HIGH_TH_FLD_RDMA1_PREULTRA_HIGH_TH       REG_FLD(12, 12)

#define OVL_RDMA2_BUF_HIGH_TH_FLD_RDMA2_PREULTRA_HIGH_DIS      REG_FLD(1, 31)
#define OVL_RDMA2_BUF_HIGH_TH_FLD_RDMA2_PREULTRA_HIGH_TH       REG_FLD(12, 12)

#define OVL_RDMA3_BUF_HIGH_TH_FLD_RDMA3_PREULTRA_HIGH_DIS      REG_FLD(1, 31)
#define OVL_RDMA3_BUF_HIGH_TH_FLD_RDMA3_PREULTRA_HIGH_TH       REG_FLD(12, 12)

#define OVL_SMI_DBG_FLD_SMI_FSM                                REG_FLD(10, 0)

#define OVL_GREQ_LAYER_CNT_FLD_LAYER3_GREQ_CNT                 REG_FLD(6, 24)
#define OVL_GREQ_LAYER_CNT_FLD_LAYER2_GREQ_CNT                 REG_FLD(6, 16)
#define OVL_GREQ_LAYER_CNT_FLD_LAYER1_GREQ_CNT                 REG_FLD(6, 8)
#define OVL_GREQ_LAYER_CNT_FLD_LAYER0_GREQ_CNT                 REG_FLD(6, 0)

#define OVL_GDRDY_PRD_NUM_FLD_GDRDY_PRD_NUM                    REG_FLD(24, 0)

#define OVL_FLOW_CTRL_DBG_FLD_OVL_UPD_REG                      REG_FLD(1, 31)
#define OVL_FLOW_CTRL_DBG_FLD_REG_UPDATE                       REG_FLD(1, 30)
#define OVL_FLOW_CTRL_DBG_FLD_OVL_CLR                          REG_FLD(1, 29)
#define OVL_FLOW_CTRL_DBG_FLD_OVL_START                        REG_FLD(1, 28)
#define OVL_FLOW_CTRL_DBG_FLD_OVL_RUNNING                      REG_FLD(1, 27)
#define OVL_FLOW_CTRL_DBG_FLD_FRAME_DONE                       REG_FLD(1, 26)
#define OVL_FLOW_CTRL_DBG_FLD_FRAME_UNDERRUN                   REG_FLD(1, 25)
#define OVL_FLOW_CTRL_DBG_FLD_FRAME_SWRST_DONE                 REG_FLD(1, 24)
#define OVL_FLOW_CTRL_DBG_FLD_FRAME_HWRST_DONE                 REG_FLD(1, 23)
#define OVL_FLOW_CTRL_DBG_FLD_TRIG                             REG_FLD(1, 21)
#define OVL_FLOW_CTRL_DBG_FLD_RST                              REG_FLD(1, 20)
#define OVL_FLOW_CTRL_DBG_FLD_RDMA0_IDLE                       REG_FLD(1, 19)
#define OVL_FLOW_CTRL_DBG_FLD_RDMA1_IDLE                       REG_FLD(1, 18)
#define OVL_FLOW_CTRL_DBG_FLD_RDMA2_IDLE                       REG_FLD(1, 17)
#define OVL_FLOW_CTRL_DBG_FLD_RDMA3_IDLE                       REG_FLD(1, 16)
#define OVL_FLOW_CTRL_DBG_FLD_OUT_IDLE                         REG_FLD(1, 15)
#define OVL_FLOW_CTRL_DBG_FLD_OVL_OUT_READY                    REG_FLD(1, 13)
#define OVL_FLOW_CTRL_DBG_FLD_OVL_OUT_VALID                    REG_FLD(1, 12)
#define OVL_FLOW_CTRL_DBG_FLD_BLEND_IDLE                       REG_FLD(1, 11)
#define OVL_FLOW_CTRL_DBG_FLD_ADDCON_IDLE                      REG_FLD(1, 10)
#define OVL_FLOW_CTRL_DBG_FLD_FSM_STATE                        REG_FLD(10, 0)

#define OVL_ADDCON_DBG_FLD_L3_WIN_HIT                          REG_FLD(1, 31)
#define OVL_ADDCON_DBG_FLD_L2_WIN_HIT                          REG_FLD(1, 30)
#define OVL_ADDCON_DBG_FLD_ROI_Y                               REG_FLD(13, 16)
#define OVL_ADDCON_DBG_FLD_L1_WIN_HIT                          REG_FLD(1, 15)
#define OVL_ADDCON_DBG_FLD_L0_WIN_HIT                          REG_FLD(1, 14)
#define OVL_ADDCON_DBG_FLD_ROI_X                               REG_FLD(13, 0)

#define OVL_RDMA0_DBG_FLD_SMI_GREQ                             REG_FLD(1, 31)
#define OVL_RDMA0_DBG_FLD_RDMA0_SMI_BUSY                       REG_FLD(1, 30)
#define OVL_RDMA0_DBG_FLD_RDMA0_OUT_VALID                      REG_FLD(1, 29)
#define OVL_RDMA0_DBG_FLD_RDMA0_OUT_READY                      REG_FLD(1, 28)
#define OVL_RDMA0_DBG_FLD_RDMA0_OUT_DATA                       REG_FLD(24, 4)
#define OVL_RDMA0_DBG_FLD_RDMA0_LAYER_GREQ                     REG_FLD(1, 3)
#define OVL_RDMA0_DBG_FLD_RDMA0_WRAM_RST_CS                    REG_FLD(3, 0)

#define OVL_RDMA1_DBG_FLD_SMI_GREQ                             REG_FLD(1, 31)
#define OVL_RDMA1_DBG_FLD_RDMA1_SMI_BUSY                       REG_FLD(1, 30)
#define OVL_RDMA1_DBG_FLD_RDMA1_OUT_VALID                      REG_FLD(1, 29)
#define OVL_RDMA1_DBG_FLD_RDMA1_OUT_READY                      REG_FLD(1, 28)
#define OVL_RDMA1_DBG_FLD_RDMA1_OUT_DATA                       REG_FLD(24, 4)
#define OVL_RDMA1_DBG_FLD_RDMA1_LAYER_GREQ                     REG_FLD(1, 3)
#define OVL_RDMA1_DBG_FLD_RDMA1_WRAM_RST_CS                    REG_FLD(3, 0)

#define OVL_RDMA2_DBG_FLD_SMI_GREQ                             REG_FLD(1, 31)
#define OVL_RDMA2_DBG_FLD_RDMA2_SMI_BUSY                       REG_FLD(1, 30)
#define OVL_RDMA2_DBG_FLD_RDMA2_OUT_VALID                      REG_FLD(1, 29)
#define OVL_RDMA2_DBG_FLD_RDMA2_OUT_READY                      REG_FLD(1, 28)
#define OVL_RDMA2_DBG_FLD_RDMA2_OUT_DATA                       REG_FLD(24, 4)
#define OVL_RDMA2_DBG_FLD_RDMA2_LAYER_GREQ                     REG_FLD(1, 3)
#define OVL_RDMA2_DBG_FLD_RDMA2_WRAM_RST_CS                    REG_FLD(3, 0)

#define OVL_RDMA3_DBG_FLD_SMI_GREQ                             REG_FLD(1, 31)
#define OVL_RDMA3_DBG_FLD_RDMA3_SMI_BUSY                       REG_FLD(1, 30)
#define OVL_RDMA3_DBG_FLD_RDMA3_OUT_VALID                      REG_FLD(1, 29)
#define OVL_RDMA3_DBG_FLD_RDMA3_OUT_READY                      REG_FLD(1, 28)
#define OVL_RDMA3_DBG_FLD_RDMA3_OUT_DATA                       REG_FLD(24, 4)
#define OVL_RDMA3_DBG_FLD_RDMA3_LAYER_GREQ                     REG_FLD(1, 3)
#define OVL_RDMA3_DBG_FLD_RDMA3_WRAM_RST_CS                    REG_FLD(3, 0)

#define OVL_L0_CLR_FLD_ALPHA                                   REG_FLD(8, 24)
#define OVL_L0_CLR_FLD_RED                                     REG_FLD(8, 16)
#define OVL_L0_CLR_FLD_GREEN                                   REG_FLD(8, 8)
#define OVL_L0_CLR_FLD_BLUE                                    REG_FLD(8, 0)

#define OVL_L1_CLR_FLD_ALPHA                                   REG_FLD(8, 24)
#define OVL_L1_CLR_FLD_RED                                     REG_FLD(8, 16)
#define OVL_L1_CLR_FLD_GREEN                                   REG_FLD(8, 8)
#define OVL_L1_CLR_FLD_BLUE                                    REG_FLD(8, 0)

#define OVL_L2_CLR_FLD_ALPHA                                   REG_FLD(8, 24)
#define OVL_L2_CLR_FLD_RED                                     REG_FLD(8, 16)
#define OVL_L2_CLR_FLD_GREEN                                   REG_FLD(8, 8)
#define OVL_L2_CLR_FLD_BLUE                                    REG_FLD(8, 0)

#define OVL_L3_CLR_FLD_ALPHA                                   REG_FLD(8, 24)
#define OVL_L3_CLR_FLD_RED                                     REG_FLD(8, 16)
#define OVL_L3_CLR_FLD_GREEN                                   REG_FLD(8, 8)
#define OVL_L3_CLR_FLD_BLUE                                    REG_FLD(8, 0)

#define OVL_LC_CLR_FLD_ALPHA                                   REG_FLD(8, 24)
#define OVL_LC_CLR_FLD_RED                                     REG_FLD(8, 16)
#define OVL_LC_CLR_FLD_GREEN                                   REG_FLD(8, 8)
#define OVL_LC_CLR_FLD_BLUE                                    REG_FLD(8, 0)

#define OVL_CRC_FLD_CRC_RDY                                    REG_FLD(1, 31)
#define OVL_CRC_FLD_CRC_OUT                                    REG_FLD(31, 0)

#define OVL_LC_CON_FLD_DSTKEY_EN                               REG_FLD(1, 31)
#define OVL_LC_CON_FLD_SRCKEY_EN                               REG_FLD(1, 30)
#define OVL_LC_CON_FLD_LAYER_SRC                               REG_FLD(2, 28)
#define OVL_LC_CON_FLD_R_FIRST                                 REG_FLD(1, 22)
#define OVL_LC_CON_FLD_LANDSCAPE                               REG_FLD(1, 21)
#define OVL_LC_CON_FLD_EN_3D                                   REG_FLD(1, 20)
#define OVL_LC_CON_FLD_ALPHA_EN                                REG_FLD(1, 8)
#define OVL_LC_CON_FLD_ALPHA                                   REG_FLD(8, 0)

#define OVL_LC_SRCKEY_FLD_SRCKEY                               REG_FLD(32, 0)

#define OVL_LC_SRC_SIZE_FLD_LC_SRC_H                           REG_FLD(13, 16)
#define OVL_LC_SRC_SIZE_FLD_LC_SRC_W                           REG_FLD(13, 0)

#define OVL_LC_OFFSET_FLD_LC_YOFF                              REG_FLD(12, 16)
#define OVL_LC_OFFSET_FLD_LC_XOFF                              REG_FLD(12, 0)

#define OVL_LC_SRC_SEL_FLD_SURFL_EN                            REG_FLD(1, 31)
#define OVL_LC_SRC_SEL_FLD_LC_BLEND_RND_SHT                    REG_FLD(1, 30)
#define OVL_LC_SRC_SEL_FLD_LC_SRGB_SEL_EXT2                    REG_FLD(1, 29)
#define OVL_LC_SRC_SEL_FLD_LC_CONST_BLD                        REG_FLD(1, 28)
#define OVL_LC_SRC_SEL_FLD_LC_DRGB_SEL_EXT                     REG_FLD(1, 27)
#define OVL_LC_SRC_SEL_FLD_LC_DA_SEL_EXT                       REG_FLD(1, 26)
#define OVL_LC_SRC_SEL_FLD_LC_SRGB_SEL_EXT                     REG_FLD(1, 25)
#define OVL_LC_SRC_SEL_FLD_LC_SA_SEL_EXT                       REG_FLD(1, 24)
#define OVL_LC_SRC_SEL_FLD_LC_DRGB_SEL                         REG_FLD(2, 22)
#define OVL_LC_SRC_SEL_FLD_LC_DA_SEL                           REG_FLD(2, 20)
#define OVL_LC_SRC_SEL_FLD_LC_SRGB_SEL                         REG_FLD(2, 18)
#define OVL_LC_SRC_SEL_FLD_LC_SA_SEL                           REG_FLD(2, 16)
#define OVL_LC_SRC_SEL_FLD_CONST_LAYER_SEL                     REG_FLD(3, 0)

#define OVL_BANK_CON_FLD_OVL_BANK_CON                          REG_FLD(5, 0)

#define OVL_FUNC_DCM0_FLD_OVL_FUNC_DCM0                        REG_FLD(32, 0)

#define OVL_FUNC_DCM1_FLD_OVL_FUNC_DCM1                        REG_FLD(32, 0)

#define OVL_DVFS_L0_ROI_FLD_L0_DVFS_ROI_BB                     REG_FLD(13, 16)
#define OVL_DVFS_L0_ROI_FLD_L0_DVFS_ROI_TB                     REG_FLD(13, 0)

#define OVL_DVFS_L1_ROI_FLD_L1_DVFS_ROI_BB                     REG_FLD(13, 16)
#define OVL_DVFS_L1_ROI_FLD_L1_DVFS_ROI_TB                     REG_FLD(13, 0)

#define OVL_DVFS_L2_ROI_FLD_L2_DVFS_ROI_BB                     REG_FLD(13, 16)
#define OVL_DVFS_L2_ROI_FLD_L2_DVFS_ROI_TB                     REG_FLD(13, 0)

#define OVL_DVFS_L3_ROI_FLD_L3_DVFS_ROI_BB                     REG_FLD(13, 16)
#define OVL_DVFS_L3_ROI_FLD_L3_DVFS_ROI_TB                     REG_FLD(13, 0)

#define OVL_DVFS_EL0_ROI_FLD_EL0_DVFS_ROI_BB                   REG_FLD(13, 16)
#define OVL_DVFS_EL0_ROI_FLD_EL0_DVFS_ROI_TB                   REG_FLD(13, 0)

#define OVL_DVFS_EL1_ROI_FLD_EL1_DVFS_ROI_BB                   REG_FLD(13, 16)
#define OVL_DVFS_EL1_ROI_FLD_EL1_DVFS_ROI_TB                   REG_FLD(13, 0)

#define OVL_DVFS_EL2_ROI_FLD_EL2_DVFS_ROI_BB                   REG_FLD(13, 16)
#define OVL_DVFS_EL2_ROI_FLD_EL2_DVFS_ROI_TB                   REG_FLD(13, 0)

#define OVL_DATAPATH_EXT_CON_FLD_EL2_LAYER_SEL                 REG_FLD(3, 24)
#define OVL_DATAPATH_EXT_CON_FLD_EL1_LAYER_SEL                 REG_FLD(3, 20)
#define OVL_DATAPATH_EXT_CON_FLD_EL0_LAYER_SEL                 REG_FLD(3, 16)
#define OVL_DATAPATH_EXT_CON_FLD_EL2_GPU_MODE                  REG_FLD(1, 10)
#define OVL_DATAPATH_EXT_CON_FLD_EL1_GPU_MODE                  REG_FLD(1, 9)
#define OVL_DATAPATH_EXT_CON_FLD_EL0_GPU_MODE                  REG_FLD(1, 8)
#define OVL_DATAPATH_EXT_CON_FLD_EL2_EN                        REG_FLD(1, 2)
#define OVL_DATAPATH_EXT_CON_FLD_EL1_EN                        REG_FLD(1, 1)
#define OVL_DATAPATH_EXT_CON_FLD_EL0_EN                        REG_FLD(1, 0)

#define OVL_EL0_CON_FLD_DSTKEY_EN                              REG_FLD(1, 31)
#define OVL_EL0_CON_FLD_SRCKEY_EN                              REG_FLD(1, 30)
#define OVL_EL0_CON_FLD_LAYER_SRC                              REG_FLD(2, 28)
#define OVL_EL0_CON_FLD_MTX_EN                                 REG_FLD(1, 27)
#define OVL_EL0_CON_FLD_MTX_AUTO_DIS                           REG_FLD(1, 26)
#define OVL_EL0_CON_FLD_RGB_SWAP                               REG_FLD(1, 25)
#define OVL_EL0_CON_FLD_BYTE_SWAP                              REG_FLD(1, 24)
#define OVL_EL0_CON_FLD_CLRFMT_MAN                             REG_FLD(1, 23)
#define OVL_EL0_CON_FLD_R_FIRST                                REG_FLD(1, 22)
#define OVL_EL0_CON_FLD_LANDSCAPE                              REG_FLD(1, 21)
#define OVL_EL0_CON_FLD_EN_3D                                  REG_FLD(1, 20)
#define OVL_EL0_CON_FLD_INT_MTX_SEL                            REG_FLD(4, 16)
#define OVL_EL0_CON_FLD_CLRFMT                                 REG_FLD(4, 12)
#define OVL_EL0_CON_FLD_EXT_MTX_EN                             REG_FLD(1, 11)
#define OVL_EL0_CON_FLD_HORIZONTAL_FLIP_EN                     REG_FLD(1, 10)
#define OVL_EL0_CON_FLD_VERTICAL_FLIP_EN                       REG_FLD(1, 9)
#define OVL_EL0_CON_FLD_ALPHA_EN                               REG_FLD(1, 8)
#define OVL_EL0_CON_FLD_ALPHA                                  REG_FLD(8, 0)

#define OVL_EL0_SRCKEY_FLD_SRCKEY                              REG_FLD(32, 0)

#define OVL_EL0_SRC_SIZE_FLD_EL0_SRC_H                         REG_FLD(13, 16)
#define OVL_EL0_SRC_SIZE_FLD_EL0_SRC_W                         REG_FLD(13, 0)

#define OVL_EL0_OFFSET_FLD_EL0_YOFF                            REG_FLD(13, 16)
#define OVL_EL0_OFFSET_FLD_EL0_XOFF                            REG_FLD(13, 0)

#define OVL_EL0_PITCH_FLD_SURFL_EN                             REG_FLD(1, 31)
#define OVL_EL0_PITCH_FLD_EL0_BLEND_RND_SHT                    REG_FLD(1, 30)
#define OVL_EL0_PITCH_FLD_EL0_SRGB_SEL_EXT2                    REG_FLD(1, 29)
#define OVL_EL0_PITCH_FLD_EL0_CONST_BLD                        REG_FLD(1, 28)
#define OVL_EL0_PITCH_FLD_EL0_DRGB_SEL_EXT                     REG_FLD(1, 27)
#define OVL_EL0_PITCH_FLD_EL0_DA_SEL_EXT                       REG_FLD(1, 26)
#define OVL_EL0_PITCH_FLD_EL0_SRGB_SEL_EXT                     REG_FLD(1, 25)
#define OVL_EL0_PITCH_FLD_EL0_SA_SEL_EXT                       REG_FLD(1, 24)
#define OVL_EL0_PITCH_FLD_EL0_DRGB_SEL                         REG_FLD(2, 22)
#define OVL_EL0_PITCH_FLD_EL0_DA_SEL                           REG_FLD(2, 20)
#define OVL_EL0_PITCH_FLD_EL0_SRGB_SEL                         REG_FLD(2, 18)
#define OVL_EL0_PITCH_FLD_EL0_SA_SEL                           REG_FLD(2, 16)
#define OVL_EL0_PITCH_FLD_EL0_SRC_PITCH                        REG_FLD(16, 0)

#define OVL_EL0_TILE_FLD_TILE_HORI_BLOCK_NUM                   REG_FLD(8, 24)
#define OVL_EL0_TILE_FLD_TILE_EN                               REG_FLD(1, 21)
#define OVL_EL0_TILE_FLD_TILE_WIDTH_SEL                        REG_FLD(1, 20)
#define OVL_EL0_TILE_FLD_TILE_HEIGHT                           REG_FLD(20, 0)

#define OVL_EL0_CLIP_FLD_EL0_SRC_BOTTOM_CLIP                   REG_FLD(8, 24)
#define OVL_EL0_CLIP_FLD_EL0_SRC_TOP_CLIP                      REG_FLD(8, 16)
#define OVL_EL0_CLIP_FLD_EL0_SRC_RIGHT_CLIP                    REG_FLD(8, 8)
#define OVL_EL0_CLIP_FLD_EL0_SRC_LEFT_CLIP                     REG_FLD(8, 0)

#define OVL_EL1_CON_FLD_DSTKEY_EN                              REG_FLD(1, 31)
#define OVL_EL1_CON_FLD_SRCKEY_EN                              REG_FLD(1, 30)
#define OVL_EL1_CON_FLD_LAYER_SRC                              REG_FLD(2, 28)
#define OVL_EL1_CON_FLD_MTX_EN                                 REG_FLD(1, 27)
#define OVL_EL1_CON_FLD_MTX_AUTO_DIS                           REG_FLD(1, 26)
#define OVL_EL1_CON_FLD_RGB_SWAP                               REG_FLD(1, 25)
#define OVL_EL1_CON_FLD_BYTE_SWAP                              REG_FLD(1, 24)
#define OVL_EL1_CON_FLD_CLRFMT_MAN                             REG_FLD(1, 23)
#define OVL_EL1_CON_FLD_R_FIRST                                REG_FLD(1, 22)
#define OVL_EL1_CON_FLD_LANDSCAPE                              REG_FLD(1, 21)
#define OVL_EL1_CON_FLD_EN_3D                                  REG_FLD(1, 20)
#define OVL_EL1_CON_FLD_INT_MTX_SEL                            REG_FLD(4, 16)
#define OVL_EL1_CON_FLD_CLRFMT                                 REG_FLD(4, 12)
#define OVL_EL1_CON_FLD_EXT_MTX_EN                             REG_FLD(1, 11)
#define OVL_EL1_CON_FLD_HORIZONTAL_FLIP_EN                     REG_FLD(1, 10)
#define OVL_EL1_CON_FLD_VERTICAL_FLIP_EN                       REG_FLD(1, 9)
#define OVL_EL1_CON_FLD_ALPHA_EN                               REG_FLD(1, 8)
#define OVL_EL1_CON_FLD_ALPHA                                  REG_FLD(8, 0)

#define OVL_EL1_SRCKEY_FLD_SRCKEY                              REG_FLD(32, 0)

#define OVL_EL1_SRC_SIZE_FLD_EL1_SRC_H                         REG_FLD(13, 16)
#define OVL_EL1_SRC_SIZE_FLD_EL1_SRC_W                         REG_FLD(13, 0)

#define OVL_EL1_OFFSET_FLD_EL1_YOFF                            REG_FLD(13, 16)
#define OVL_EL1_OFFSET_FLD_EL1_XOFF                            REG_FLD(13, 0)

#define OVL_EL1_PITCH_FLD_SURFL_EN                             REG_FLD(1, 31)
#define OVL_EL1_PITCH_FLD_EL1_BLEND_RND_SHT                    REG_FLD(1, 30)
#define OVL_EL1_PITCH_FLD_EL1_SRGB_SEL_EXT2                    REG_FLD(1, 29)
#define OVL_EL1_PITCH_FLD_EL1_CONST_BLD                        REG_FLD(1, 28)
#define OVL_EL1_PITCH_FLD_EL1_DRGB_SEL_EXT                     REG_FLD(1, 27)
#define OVL_EL1_PITCH_FLD_EL1_DA_SEL_EXT                       REG_FLD(1, 26)
#define OVL_EL1_PITCH_FLD_EL1_SRGB_SEL_EXT                     REG_FLD(1, 25)
#define OVL_EL1_PITCH_FLD_EL1_SA_SEL_EXT                       REG_FLD(1, 24)
#define OVL_EL1_PITCH_FLD_EL1_DRGB_SEL                         REG_FLD(2, 22)
#define OVL_EL1_PITCH_FLD_EL1_DA_SEL                           REG_FLD(2, 20)
#define OVL_EL1_PITCH_FLD_EL1_SRGB_SEL                         REG_FLD(2, 18)
#define OVL_EL1_PITCH_FLD_EL1_SA_SEL                           REG_FLD(2, 16)
#define OVL_EL1_PITCH_FLD_EL1_SRC_PITCH                        REG_FLD(16, 0)

#define OVL_EL1_TILE_FLD_TILE_HORI_BLOCK_NUM                   REG_FLD(8, 24)
#define OVL_EL1_TILE_FLD_TILE_EN                               REG_FLD(1, 21)
#define OVL_EL1_TILE_FLD_TILE_WIDTH_SEL                        REG_FLD(1, 20)
#define OVL_EL1_TILE_FLD_TILE_HEIGHT                           REG_FLD(20, 0)

#define OVL_EL1_CLIP_FLD_EL1_SRC_BOTTOM_CLIP                   REG_FLD(8, 24)
#define OVL_EL1_CLIP_FLD_EL1_SRC_TOP_CLIP                      REG_FLD(8, 16)
#define OVL_EL1_CLIP_FLD_EL1_SRC_RIGHT_CLIP                    REG_FLD(8, 8)
#define OVL_EL1_CLIP_FLD_EL1_SRC_LEFT_CLIP                     REG_FLD(8, 0)

#define OVL_EL2_CON_FLD_DSTKEY_EN                              REG_FLD(1, 31)
#define OVL_EL2_CON_FLD_SRCKEY_EN                              REG_FLD(1, 30)
#define OVL_EL2_CON_FLD_LAYER_SRC                              REG_FLD(2, 28)
#define OVL_EL2_CON_FLD_MTX_EN                                 REG_FLD(1, 27)
#define OVL_EL2_CON_FLD_MTX_AUTO_DIS                           REG_FLD(1, 26)
#define OVL_EL2_CON_FLD_RGB_SWAP                               REG_FLD(1, 25)
#define OVL_EL2_CON_FLD_BYTE_SWAP                              REG_FLD(1, 24)
#define OVL_EL2_CON_FLD_CLRFMT_MAN                             REG_FLD(1, 23)
#define OVL_EL2_CON_FLD_R_FIRST                                REG_FLD(1, 22)
#define OVL_EL2_CON_FLD_LANDSCAPE                              REG_FLD(1, 21)
#define OVL_EL2_CON_FLD_EN_3D                                  REG_FLD(1, 20)
#define OVL_EL2_CON_FLD_INT_MTX_SEL                            REG_FLD(4, 16)
#define OVL_EL2_CON_FLD_CLRFMT                                 REG_FLD(4, 12)
#define OVL_EL2_CON_FLD_EXT_MTX_EN                             REG_FLD(1, 11)
#define OVL_EL2_CON_FLD_HORIZONTAL_FLIP_EN                     REG_FLD(1, 10)
#define OVL_EL2_CON_FLD_VERTICAL_FLIP_EN                       REG_FLD(1, 9)
#define OVL_EL2_CON_FLD_ALPHA_EN                               REG_FLD(1, 8)
#define OVL_EL2_CON_FLD_ALPHA                                  REG_FLD(8, 0)

#define OVL_EL2_SRCKEY_FLD_SRCKEY                              REG_FLD(32, 0)

#define OVL_EL2_SRC_SIZE_FLD_EL2_SRC_H                         REG_FLD(13, 16)
#define OVL_EL2_SRC_SIZE_FLD_EL2_SRC_W                         REG_FLD(13, 0)

#define OVL_EL2_OFFSET_FLD_EL2_YOFF                            REG_FLD(13, 16)
#define OVL_EL2_OFFSET_FLD_EL2_XOFF                            REG_FLD(13, 0)

#define OVL_EL2_PITCH_FLD_SURFL_EN                             REG_FLD(1, 31)
#define OVL_EL2_PITCH_FLD_EL2_BLEND_RND_SHT                    REG_FLD(1, 30)
#define OVL_EL2_PITCH_FLD_EL2_SRGB_SEL_EXT2                    REG_FLD(1, 29)
#define OVL_EL2_PITCH_FLD_EL2_CONST_BLD                        REG_FLD(1, 28)
#define OVL_EL2_PITCH_FLD_EL2_DRGB_SEL_EXT                     REG_FLD(1, 27)
#define OVL_EL2_PITCH_FLD_EL2_DA_SEL_EXT                       REG_FLD(1, 26)
#define OVL_EL2_PITCH_FLD_EL2_SRGB_SEL_EXT                     REG_FLD(1, 25)
#define OVL_EL2_PITCH_FLD_EL2_SA_SEL_EXT                       REG_FLD(1, 24)
#define OVL_EL2_PITCH_FLD_EL2_DRGB_SEL                         REG_FLD(2, 22)
#define OVL_EL2_PITCH_FLD_EL2_DA_SEL                           REG_FLD(2, 20)
#define OVL_EL2_PITCH_FLD_EL2_SRGB_SEL                         REG_FLD(2, 18)
#define OVL_EL2_PITCH_FLD_EL2_SA_SEL                           REG_FLD(2, 16)
#define OVL_EL2_PITCH_FLD_EL2_SRC_PITCH                        REG_FLD(16, 0)

#define OVL_EL2_TILE_FLD_TILE_HORI_BLOCK_NUM                   REG_FLD(8, 24)
#define OVL_EL2_TILE_FLD_TILE_EN                               REG_FLD(1, 21)
#define OVL_EL2_TILE_FLD_TILE_WIDTH_SEL                        REG_FLD(1, 20)
#define OVL_EL2_TILE_FLD_TILE_HEIGHT                           REG_FLD(20, 0)

#define OVL_EL2_CLIP_FLD_EL2_SRC_BOTTOM_CLIP                   REG_FLD(8, 24)
#define OVL_EL2_CLIP_FLD_EL2_SRC_TOP_CLIP                      REG_FLD(8, 16)
#define OVL_EL2_CLIP_FLD_EL2_SRC_RIGHT_CLIP                    REG_FLD(8, 8)
#define OVL_EL2_CLIP_FLD_EL2_SRC_LEFT_CLIP                     REG_FLD(8, 0)

#define OVL_EL0_CLR_FLD_ALPHA                                  REG_FLD(8, 24)
#define OVL_EL0_CLR_FLD_RED                                    REG_FLD(8, 16)
#define OVL_EL0_CLR_FLD_GREEN                                  REG_FLD(8, 8)
#define OVL_EL0_CLR_FLD_BLUE                                   REG_FLD(8, 0)

#define OVL_EL1_CLR_FLD_ALPHA                                  REG_FLD(8, 24)
#define OVL_EL1_CLR_FLD_RED                                    REG_FLD(8, 16)
#define OVL_EL1_CLR_FLD_GREEN                                  REG_FLD(8, 8)
#define OVL_EL1_CLR_FLD_BLUE                                   REG_FLD(8, 0)

#define OVL_EL2_CLR_FLD_ALPHA                                  REG_FLD(8, 24)
#define OVL_EL2_CLR_FLD_RED                                    REG_FLD(8, 16)
#define OVL_EL2_CLR_FLD_GREEN                                  REG_FLD(8, 8)
#define OVL_EL2_CLR_FLD_BLUE                                   REG_FLD(8, 0)

#define OVL_SBCH_FLD_L3_SBCH_CNST_EN                           REG_FLD(1, 29)
#define OVL_SBCH_FLD_L3_SBCH_TRANS_EN                          REG_FLD(1, 28)
#define OVL_SBCH_FLD_L2_SBCH_CNST_EN                           REG_FLD(1, 25)
#define OVL_SBCH_FLD_L2_SBCH_TRANS_EN                          REG_FLD(1, 24)
#define OVL_SBCH_FLD_L1_SBCH_CNST_EN                           REG_FLD(1, 21)
#define OVL_SBCH_FLD_L1_SBCH_TRANS_EN                          REG_FLD(1, 20)
#define OVL_SBCH_FLD_L0_SBCH_CNST_EN                           REG_FLD(1, 17)
#define OVL_SBCH_FLD_L0_SBCH_TRANS_EN                          REG_FLD(1, 16)
#define OVL_SBCH_FLD_L3_SBCH_UPDATE                            REG_FLD(1, 12)
#define OVL_SBCH_FLD_L2_SBCH_UPDATE                            REG_FLD(1, 8)
#define OVL_SBCH_FLD_L1_SBCH_UPDATE                            REG_FLD(1, 4)
#define OVL_SBCH_FLD_L0_SBCH_UPDATE                            REG_FLD(1, 0)

#define OVL_SBCH_EXT_FLD_EL2_SBCH_CNST_EN                      REG_FLD(1, 25)
#define OVL_SBCH_EXT_FLD_EL2_SBCH_TRANS_EN                     REG_FLD(1, 24)
#define OVL_SBCH_EXT_FLD_EL1_SBCH_CNST_EN                      REG_FLD(1, 21)
#define OVL_SBCH_EXT_FLD_EL1_SBCH_TRANS_EN                     REG_FLD(1, 20)
#define OVL_SBCH_EXT_FLD_EL0_SBCH_CNST_EN                      REG_FLD(1, 17)
#define OVL_SBCH_EXT_FLD_EL0_SBCH_TRANS_EN                     REG_FLD(1, 16)
#define OVL_SBCH_EXT_FLD_EL2_SBCH_UPDATE                       REG_FLD(1, 8)
#define OVL_SBCH_EXT_FLD_EL1_SBCH_UPDATE                       REG_FLD(1, 4)
#define OVL_SBCH_EXT_FLD_EL0_SBCH_UPDATE                       REG_FLD(1, 0)

#define OVL_SBCH_CON_FLD_EL2_SBCH_TRANS_INVALID                REG_FLD(1, 22)
#define OVL_SBCH_CON_FLD_EL1_SBCH_TRANS_INVALID                REG_FLD(1, 21)
#define OVL_SBCH_CON_FLD_EL0_SBCH_TRANS_INVALID                REG_FLD(1, 20)
#define OVL_SBCH_CON_FLD_L3_SBCH_TRANS_INVALID                 REG_FLD(1, 19)
#define OVL_SBCH_CON_FLD_L2_SBCH_TRANS_INVALID                 REG_FLD(1, 18)
#define OVL_SBCH_CON_FLD_L1_SBCH_TRANS_INVALID                 REG_FLD(1, 17)
#define OVL_SBCH_CON_FLD_L0_SBCH_TRANS_INVALID                 REG_FLD(1, 16)

#define OVL_L0_ADDR_FLD_L0_ADDR                                REG_FLD(32, 0)

#define OVL_L1_ADDR_FLD_L1_ADDR                                REG_FLD(32, 0)

#define OVL_L2_ADDR_FLD_L2_ADDR                                REG_FLD(32, 0)

#define OVL_L3_ADDR_FLD_L3_ADDR                                REG_FLD(32, 0)

#define OVL_EL0_ADDR_FLD_EL0_ADDR                              REG_FLD(32, 0)

#define OVL_EL1_ADDR_FLD_EL1_ADDR                              REG_FLD(32, 0)

#define OVL_EL2_ADDR_FLD_EL2_ADDR                              REG_FLD(32, 0)

#define OVL_SECURE_FLD_L3_SECURE                               REG_FLD(1, 3)
#define OVL_SECURE_FLD_L2_SECURE                               REG_FLD(1, 2)
#define OVL_SECURE_FLD_L1_SECURE                               REG_FLD(1, 1)
#define OVL_SECURE_FLD_L0_SECURE                               REG_FLD(1, 0)

#define OVL_STA_GET_RDMA3_IDLE(reg32)                          REG_FLD_GET(OVL_STA_FLD_RDMA3_IDLE, (reg32))
#define OVL_STA_GET_RDMA2_IDLE(reg32)                          REG_FLD_GET(OVL_STA_FLD_RDMA2_IDLE, (reg32))
#define OVL_STA_GET_RDMA1_IDLE(reg32)                          REG_FLD_GET(OVL_STA_FLD_RDMA1_IDLE, (reg32))
#define OVL_STA_GET_RDMA0_IDLE(reg32)                          REG_FLD_GET(OVL_STA_FLD_RDMA0_IDLE, (reg32))
#define OVL_STA_GET_OVL_RUN(reg32)                             REG_FLD_GET(OVL_STA_FLD_OVL_RUN, (reg32))

#define OVL_INTEN_GET_OVL_START_INTEN(reg32)                   REG_FLD_GET(OVL_INTEN_FLD_OVL_START_INTEN, (reg32))
#define OVL_INTEN_GET_ABNORMAL_SOF_INTEN(reg32)                REG_FLD_GET(OVL_INTEN_FLD_ABNORMAL_SOF_INTEN, (reg32))
#define OVL_INTEN_GET_RDMA3_SMI_UNDERFLOW_INTEN(reg32)         REG_FLD_GET(OVL_INTEN_FLD_RDMA3_SMI_UNDERFLOW_INTEN, (reg32))
#define OVL_INTEN_GET_RDMA2_SMI_UNDERFLOW_INTEN(reg32)         REG_FLD_GET(OVL_INTEN_FLD_RDMA2_SMI_UNDERFLOW_INTEN, (reg32))
#define OVL_INTEN_GET_RDMA1_SMI_UNDERFLOW_INTEN(reg32)         REG_FLD_GET(OVL_INTEN_FLD_RDMA1_SMI_UNDERFLOW_INTEN, (reg32))
#define OVL_INTEN_GET_RDMA0_SMI_UNDERFLOW_INTEN(reg32)         REG_FLD_GET(OVL_INTEN_FLD_RDMA0_SMI_UNDERFLOW_INTEN, (reg32))
#define OVL_INTEN_GET_RDMA3_EOF_ABNORMAL_INTEN(reg32)          REG_FLD_GET(OVL_INTEN_FLD_RDMA3_EOF_ABNORMAL_INTEN, (reg32))
#define OVL_INTEN_GET_RDMA2_EOF_ABNORMAL_INTEN(reg32)          REG_FLD_GET(OVL_INTEN_FLD_RDMA2_EOF_ABNORMAL_INTEN, (reg32))
#define OVL_INTEN_GET_RDMA1_EOF_ABNORMAL_INTEN(reg32)          REG_FLD_GET(OVL_INTEN_FLD_RDMA1_EOF_ABNORMAL_INTEN, (reg32))
#define OVL_INTEN_GET_RDMA0_EOF_ABNORMAL_INTEN(reg32)          REG_FLD_GET(OVL_INTEN_FLD_RDMA0_EOF_ABNORMAL_INTEN, (reg32))
#define OVL_INTEN_GET_OVL_FME_HWRST_DONE_INTEN(reg32)          REG_FLD_GET(OVL_INTEN_FLD_OVL_FME_HWRST_DONE_INTEN, (reg32))
#define OVL_INTEN_GET_OVL_FME_SWRST_DONE_INTEN(reg32)          REG_FLD_GET(OVL_INTEN_FLD_OVL_FME_SWRST_DONE_INTEN, (reg32))
#define OVL_INTEN_GET_OVL_FME_UND_INTEN(reg32)                 REG_FLD_GET(OVL_INTEN_FLD_OVL_FME_UND_INTEN, (reg32))
#define OVL_INTEN_GET_OVL_FME_CPL_INTEN(reg32)                 REG_FLD_GET(OVL_INTEN_FLD_OVL_FME_CPL_INTEN, (reg32))
#define OVL_INTEN_GET_OVL_REG_CMT_INTEN(reg32)                 REG_FLD_GET(OVL_INTEN_FLD_OVL_REG_CMT_INTEN, (reg32))

#define OVL_INTSTA_GET_OVL_START_INTSTA(reg32)                 REG_FLD_GET(OVL_INTSTA_FLD_OVL_START_INTSTA, (reg32))
#define OVL_INTSTA_GET_ABNORMAL_SOF_INTSTA(reg32)              REG_FLD_GET(OVL_INTSTA_FLD_ABNORMAL_SOF_INTSTA, (reg32))
#define OVL_INTSTA_GET_RDMA3_SMI_UNDERFLOW_INTSTA(reg32)       REG_FLD_GET(OVL_INTSTA_FLD_RDMA3_SMI_UNDERFLOW_INTSTA, (reg32))
#define OVL_INTSTA_GET_RDMA2_SMI_UNDERFLOW_INTSTA(reg32)       REG_FLD_GET(OVL_INTSTA_FLD_RDMA2_SMI_UNDERFLOW_INTSTA, (reg32))
#define OVL_INTSTA_GET_RDMA1_SMI_UNDERFLOW_INTSTA(reg32)       REG_FLD_GET(OVL_INTSTA_FLD_RDMA1_SMI_UNDERFLOW_INTSTA, (reg32))
#define OVL_INTSTA_GET_RDMA0_SMI_UNDERFLOW_INTSTA(reg32)       REG_FLD_GET(OVL_INTSTA_FLD_RDMA0_SMI_UNDERFLOW_INTSTA, (reg32))
#define OVL_INTSTA_GET_RDMA3_EOF_ABNORMAL_INTSTA(reg32)        REG_FLD_GET(OVL_INTSTA_FLD_RDMA3_EOF_ABNORMAL_INTSTA, (reg32))
#define OVL_INTSTA_GET_RDMA2_EOF_ABNORMAL_INTSTA(reg32)        REG_FLD_GET(OVL_INTSTA_FLD_RDMA2_EOF_ABNORMAL_INTSTA, (reg32))
#define OVL_INTSTA_GET_RDMA1_EOF_ABNORMAL_INTSTA(reg32)        REG_FLD_GET(OVL_INTSTA_FLD_RDMA1_EOF_ABNORMAL_INTSTA, (reg32))
#define OVL_INTSTA_GET_RDMA0_EOF_ABNORMAL_INTSTA(reg32)        REG_FLD_GET(OVL_INTSTA_FLD_RDMA0_EOF_ABNORMAL_INTSTA, (reg32))
#define OVL_INTSTA_GET_OVL_FME_HWRST_DONE_INTSTA(reg32)        REG_FLD_GET(OVL_INTSTA_FLD_OVL_FME_HWRST_DONE_INTSTA, (reg32))
#define OVL_INTSTA_GET_OVL_FME_SWRST_DONE_INTSTA(reg32)        REG_FLD_GET(OVL_INTSTA_FLD_OVL_FME_SWRST_DONE_INTSTA, (reg32))
#define OVL_INTSTA_GET_OVL_FME_UND_INTSTA(reg32)               REG_FLD_GET(OVL_INTSTA_FLD_OVL_FME_UND_INTSTA, (reg32))
#define OVL_INTSTA_GET_OVL_FME_CPL_INTSTA(reg32)               REG_FLD_GET(OVL_INTSTA_FLD_OVL_FME_CPL_INTSTA, (reg32))
#define OVL_INTSTA_GET_OVL_REG_CMT_INTSTA(reg32)               REG_FLD_GET(OVL_INTSTA_FLD_OVL_REG_CMT_INTSTA, (reg32))

#define OVL_EN_GET_BLOCK_EXT_PREULTRA(reg32)                   REG_FLD_GET(OVL_EN_FLD_BLOCK_EXT_PREULTRA, (reg32))
#define OVL_EN_GET_BLOCK_EXT_ULTRA(reg32)                      REG_FLD_GET(OVL_EN_FLD_BLOCK_EXT_ULTRA, (reg32))
#define OVL_EN_GET_IGNORE_ABNORMAL_SOF(reg32)                  REG_FLD_GET(OVL_EN_FLD_IGNORE_ABNORMAL_SOF, (reg32))
#define OVL_EN_GET_HF_FOVL_CK_ON(reg32)                        REG_FLD_GET(OVL_EN_FLD_HF_FOVL_CK_ON, (reg32))
#define OVL_EN_GET_HG_FSMI_CK_ON(reg32)                        REG_FLD_GET(OVL_EN_FLD_HG_FSMI_CK_ON, (reg32))
#define OVL_EN_GET_HG_FOVL_CK_ON(reg32)                        REG_FLD_GET(OVL_EN_FLD_HG_FOVL_CK_ON, (reg32))
#define OVL_EN_GET_OVL_EN(reg32)                               REG_FLD_GET(OVL_EN_FLD_OVL_EN, (reg32))

#define OVL_TRIG_GET_CRC_CLR(reg32)                            REG_FLD_GET(OVL_TRIG_FLD_CRC_CLR, (reg32))
#define OVL_TRIG_GET_CRC_EN(reg32)                             REG_FLD_GET(OVL_TRIG_FLD_CRC_EN, (reg32))
#define OVL_TRIG_GET_OVL_SW_TRIG(reg32)                        REG_FLD_GET(OVL_TRIG_FLD_OVL_SW_TRIG, (reg32))

#define OVL_RST_GET_OVL_SMI_IOBUF_HARD_RST(reg32)              REG_FLD_GET(OVL_RST_FLD_OVL_SMI_IOBUF_HARD_RST, (reg32))
#define OVL_RST_GET_OVL_SMI_IOBUF_RST(reg32)                   REG_FLD_GET(OVL_RST_FLD_OVL_SMI_IOBUF_RST, (reg32))
#define OVL_RST_GET_OVL_SMI_HARD_RST(reg32)                    REG_FLD_GET(OVL_RST_FLD_OVL_SMI_HARD_RST, (reg32))
#define OVL_RST_GET_OVL_SMI_RST(reg32)                         REG_FLD_GET(OVL_RST_FLD_OVL_SMI_RST, (reg32))
#define OVL_RST_GET_OVL_RST(reg32)                             REG_FLD_GET(OVL_RST_FLD_OVL_RST, (reg32))

#define OVL_ROI_SIZE_GET_ROI_H(reg32)                          REG_FLD_GET(OVL_ROI_SIZE_FLD_ROI_H, (reg32))
#define OVL_ROI_SIZE_GET_ROI_W(reg32)                          REG_FLD_GET(OVL_ROI_SIZE_FLD_ROI_W, (reg32))

#define OVL_DATAPATH_CON_GET_WIDE_GAMUT_EN(reg32)              REG_FLD_GET(OVL_DATAPATH_CON_FLD_WIDE_GAMUT_EN, (reg32))
#define OVL_DATAPATH_CON_GET_OUTPUT_INTERLACE(reg32)           REG_FLD_GET(OVL_DATAPATH_CON_FLD_OUTPUT_INTERLACE, (reg32))
#define OVL_DATAPATH_CON_GET_OUTPUT_CLAMP(reg32)               REG_FLD_GET(OVL_DATAPATH_CON_FLD_OUTPUT_CLAMP, (reg32))
#define OVL_DATAPATH_CON_GET_GCLAST_EN(reg32)                  REG_FLD_GET(OVL_DATAPATH_CON_FLD_GCLAST_EN, (reg32))
#define OVL_DATAPATH_CON_GET_RDMA3_OUT_SEL(reg32)              REG_FLD_GET(OVL_DATAPATH_CON_FLD_RDMA3_OUT_SEL, (reg32))
#define OVL_DATAPATH_CON_GET_RDMA2_OUT_SEL(reg32)              REG_FLD_GET(OVL_DATAPATH_CON_FLD_RDMA2_OUT_SEL, (reg32))
#define OVL_DATAPATH_CON_GET_RDMA1_OUT_SEL(reg32)              REG_FLD_GET(OVL_DATAPATH_CON_FLD_RDMA1_OUT_SEL, (reg32))
#define OVL_DATAPATH_CON_GET_RDMA0_OUT_SEL(reg32)              REG_FLD_GET(OVL_DATAPATH_CON_FLD_RDMA0_OUT_SEL, (reg32))
#define OVL_DATAPATH_CON_GET_PQ_OUT_SEL(reg32)                 REG_FLD_GET(OVL_DATAPATH_CON_FLD_PQ_OUT_SEL, (reg32))
#define OVL_DATAPATH_CON_GET_OVL_GAMMA_OUT(reg32)              REG_FLD_GET(OVL_DATAPATH_CON_FLD_OVL_GAMMA_OUT, (reg32))
#define OVL_DATAPATH_CON_GET_ADOBE_LAYER(reg32)                REG_FLD_GET(OVL_DATAPATH_CON_FLD_ADOBE_LAYER, (reg32))
#define OVL_DATAPATH_CON_GET_ADOBE_MODE(reg32)                 REG_FLD_GET(OVL_DATAPATH_CON_FLD_ADOBE_MODE, (reg32))
#define OVL_DATAPATH_CON_GET_L3_GPU_MODE(reg32)                REG_FLD_GET(OVL_DATAPATH_CON_FLD_L3_GPU_MODE, (reg32))
#define OVL_DATAPATH_CON_GET_L2_GPU_MODE(reg32)                REG_FLD_GET(OVL_DATAPATH_CON_FLD_L2_GPU_MODE, (reg32))
#define OVL_DATAPATH_CON_GET_L1_GPU_MODE(reg32)                REG_FLD_GET(OVL_DATAPATH_CON_FLD_L1_GPU_MODE, (reg32))
#define OVL_DATAPATH_CON_GET_L0_GPU_MODE(reg32)                REG_FLD_GET(OVL_DATAPATH_CON_FLD_L0_GPU_MODE, (reg32))
#define OVL_DATAPATH_CON_GET_OUTPUT_NO_RND(reg32)              REG_FLD_GET(OVL_DATAPATH_CON_FLD_OUTPUT_NO_RND, (reg32))
#define OVL_DATAPATH_CON_GET_BGCLR_IN_SEL(reg32)               REG_FLD_GET(OVL_DATAPATH_CON_FLD_BGCLR_IN_SEL, (reg32))
#define OVL_DATAPATH_CON_GET_OVL_RANDOM_BGCLR_EN(reg32)        REG_FLD_GET(OVL_DATAPATH_CON_FLD_OVL_RANDOM_BGCLR_EN, (reg32))
#define OVL_DATAPATH_CON_GET_LAYER_SMI_ID_EN(reg32)            REG_FLD_GET(OVL_DATAPATH_CON_FLD_LAYER_SMI_ID_EN, (reg32))

#define OVL_ROI_BGCLR_GET_ALPHA(reg32)                         REG_FLD_GET(OVL_ROI_BGCLR_FLD_ALPHA, (reg32))
#define OVL_ROI_BGCLR_GET_RED(reg32)                           REG_FLD_GET(OVL_ROI_BGCLR_FLD_RED, (reg32))
#define OVL_ROI_BGCLR_GET_GREEN(reg32)                         REG_FLD_GET(OVL_ROI_BGCLR_FLD_GREEN, (reg32))
#define OVL_ROI_BGCLR_GET_BLUE(reg32)                          REG_FLD_GET(OVL_ROI_BGCLR_FLD_BLUE, (reg32))

#define OVL_SRC_CON_GET_RELAY_MODE_EN(reg32)                   REG_FLD_GET(OVL_SRC_CON_FLD_RELAY_MODE_EN, (reg32))
#define OVL_SRC_CON_GET_FORCE_RELAY_MODE(reg32)                REG_FLD_GET(OVL_SRC_CON_FLD_FORCE_RELAY_MODE, (reg32))
#define OVL_SRC_CON_GET_LC_EN(reg32)                           REG_FLD_GET(OVL_SRC_CON_FLD_LC_EN, (reg32))
#define OVL_SRC_CON_GET_L3_EN(reg32)                           REG_FLD_GET(OVL_SRC_CON_FLD_L3_EN, (reg32))
#define OVL_SRC_CON_GET_L2_EN(reg32)                           REG_FLD_GET(OVL_SRC_CON_FLD_L2_EN, (reg32))
#define OVL_SRC_CON_GET_L1_EN(reg32)                           REG_FLD_GET(OVL_SRC_CON_FLD_L1_EN, (reg32))
#define OVL_SRC_CON_GET_L0_EN(reg32)                           REG_FLD_GET(OVL_SRC_CON_FLD_L0_EN, (reg32))

#define OVL_L0_CON_GET_DSTKEY_EN(reg32)                        REG_FLD_GET(OVL_L0_CON_FLD_DSTKEY_EN, (reg32))
#define OVL_L0_CON_GET_SRCKEY_EN(reg32)                        REG_FLD_GET(OVL_L0_CON_FLD_SRCKEY_EN, (reg32))
#define OVL_L0_CON_GET_LAYER_SRC(reg32)                        REG_FLD_GET(OVL_L0_CON_FLD_LAYER_SRC, (reg32))
#define OVL_L0_CON_GET_MTX_EN(reg32)                           REG_FLD_GET(OVL_L0_CON_FLD_MTX_EN, (reg32))
#define OVL_L0_CON_GET_MTX_AUTO_DIS(reg32)                     REG_FLD_GET(OVL_L0_CON_FLD_MTX_AUTO_DIS, (reg32))
#define OVL_L0_CON_GET_RGB_SWAP(reg32)                         REG_FLD_GET(OVL_L0_CON_FLD_RGB_SWAP, (reg32))
#define OVL_L0_CON_GET_BYTE_SWAP(reg32)                        REG_FLD_GET(OVL_L0_CON_FLD_BYTE_SWAP, (reg32))
#define OVL_L0_CON_GET_CLRFMT_MAN(reg32)                       REG_FLD_GET(OVL_L0_CON_FLD_CLRFMT_MAN, (reg32))
#define OVL_L0_CON_GET_R_FIRST(reg32)                          REG_FLD_GET(OVL_L0_CON_FLD_R_FIRST, (reg32))
#define OVL_L0_CON_GET_LANDSCAPE(reg32)                        REG_FLD_GET(OVL_L0_CON_FLD_LANDSCAPE, (reg32))
#define OVL_L0_CON_GET_EN_3D(reg32)                            REG_FLD_GET(OVL_L0_CON_FLD_EN_3D, (reg32))
#define OVL_L0_CON_GET_INT_MTX_SEL(reg32)                      REG_FLD_GET(OVL_L0_CON_FLD_INT_MTX_SEL, (reg32))
#define OVL_L0_CON_GET_CLRFMT(reg32)                           REG_FLD_GET(OVL_L0_CON_FLD_CLRFMT, (reg32))
#define OVL_L0_CON_GET_EXT_MTX_EN(reg32)                       REG_FLD_GET(OVL_L0_CON_FLD_EXT_MTX_EN, (reg32))
#define OVL_L0_CON_GET_HORIZONTAL_FLIP_EN(reg32)               REG_FLD_GET(OVL_L0_CON_FLD_HORIZONTAL_FLIP_EN, (reg32))
#define OVL_L0_CON_GET_VERTICAL_FLIP_EN(reg32)                 REG_FLD_GET(OVL_L0_CON_FLD_VERTICAL_FLIP_EN, (reg32))
#define OVL_L0_CON_GET_ALPHA_EN(reg32)                         REG_FLD_GET(OVL_L0_CON_FLD_ALPHA_EN, (reg32))
#define OVL_L0_CON_GET_ALPHA(reg32)                            REG_FLD_GET(OVL_L0_CON_FLD_ALPHA, (reg32))

#define OVL_L0_SRCKEY_GET_SRCKEY(reg32)                        REG_FLD_GET(OVL_L0_SRCKEY_FLD_SRCKEY, (reg32))

#define OVL_L0_SRC_SIZE_GET_L0_SRC_H(reg32)                    REG_FLD_GET(OVL_L0_SRC_SIZE_FLD_L0_SRC_H, (reg32))
#define OVL_L0_SRC_SIZE_GET_L0_SRC_W(reg32)                    REG_FLD_GET(OVL_L0_SRC_SIZE_FLD_L0_SRC_W, (reg32))

#define OVL_L0_OFFSET_GET_L0_YOFF(reg32)                       REG_FLD_GET(OVL_L0_OFFSET_FLD_L0_YOFF, (reg32))
#define OVL_L0_OFFSET_GET_L0_XOFF(reg32)                       REG_FLD_GET(OVL_L0_OFFSET_FLD_L0_XOFF, (reg32))

#define OVL_L0_PITCH_GET_SURFL_EN(reg32)                       REG_FLD_GET(OVL_L0_PITCH_FLD_SURFL_EN, (reg32))
#define OVL_L0_PITCH_GET_L0_BLEND_RND_SHT(reg32)               REG_FLD_GET(OVL_L0_PITCH_FLD_L0_BLEND_RND_SHT, (reg32))
#define OVL_L0_PITCH_GET_L0_SRGB_SEL_EXT2(reg32)               REG_FLD_GET(OVL_L0_PITCH_FLD_L0_SRGB_SEL_EXT2, (reg32))
#define OVL_L0_PITCH_GET_L0_CONST_BLD(reg32)                   REG_FLD_GET(OVL_L0_PITCH_FLD_L0_CONST_BLD, (reg32))
#define OVL_L0_PITCH_GET_L0_DRGB_SEL_EXT(reg32)                REG_FLD_GET(OVL_L0_PITCH_FLD_L0_DRGB_SEL_EXT, (reg32))
#define OVL_L0_PITCH_GET_L0_DA_SEL_EXT(reg32)                  REG_FLD_GET(OVL_L0_PITCH_FLD_L0_DA_SEL_EXT, (reg32))
#define OVL_L0_PITCH_GET_L0_SRGB_SEL_EXT(reg32)                REG_FLD_GET(OVL_L0_PITCH_FLD_L0_SRGB_SEL_EXT, (reg32))
#define OVL_L0_PITCH_GET_L0_SA_SEL_EXT(reg32)                  REG_FLD_GET(OVL_L0_PITCH_FLD_L0_SA_SEL_EXT, (reg32))
#define OVL_L0_PITCH_GET_L0_DRGB_SEL(reg32)                    REG_FLD_GET(OVL_L0_PITCH_FLD_L0_DRGB_SEL, (reg32))
#define OVL_L0_PITCH_GET_L0_DA_SEL(reg32)                      REG_FLD_GET(OVL_L0_PITCH_FLD_L0_DA_SEL, (reg32))
#define OVL_L0_PITCH_GET_L0_SRGB_SEL(reg32)                    REG_FLD_GET(OVL_L0_PITCH_FLD_L0_SRGB_SEL, (reg32))
#define OVL_L0_PITCH_GET_L0_SA_SEL(reg32)                      REG_FLD_GET(OVL_L0_PITCH_FLD_L0_SA_SEL, (reg32))
#define OVL_L0_PITCH_GET_L0_SRC_PITCH(reg32)                   REG_FLD_GET(OVL_L0_PITCH_FLD_L0_SRC_PITCH, (reg32))

#define OVL_L0_TILE_GET_TILE_HORI_BLOCK_NUM(reg32)             REG_FLD_GET(OVL_L0_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32))
#define OVL_L0_TILE_GET_TILE_EN(reg32)                         REG_FLD_GET(OVL_L0_TILE_FLD_TILE_EN, (reg32))
#define OVL_L0_TILE_GET_TILE_WIDTH_SEL(reg32)                  REG_FLD_GET(OVL_L0_TILE_FLD_TILE_WIDTH_SEL, (reg32))
#define OVL_L0_TILE_GET_TILE_HEIGHT(reg32)                     REG_FLD_GET(OVL_L0_TILE_FLD_TILE_HEIGHT, (reg32))

#define OVL_L0_CLIP_GET_L0_SRC_BOTTOM_CLIP(reg32)              REG_FLD_GET(OVL_L0_CLIP_FLD_L0_SRC_BOTTOM_CLIP, (reg32))
#define OVL_L0_CLIP_GET_L0_SRC_TOP_CLIP(reg32)                 REG_FLD_GET(OVL_L0_CLIP_FLD_L0_SRC_TOP_CLIP, (reg32))
#define OVL_L0_CLIP_GET_L0_SRC_RIGHT_CLIP(reg32)               REG_FLD_GET(OVL_L0_CLIP_FLD_L0_SRC_RIGHT_CLIP, (reg32))
#define OVL_L0_CLIP_GET_L0_SRC_LEFT_CLIP(reg32)                REG_FLD_GET(OVL_L0_CLIP_FLD_L0_SRC_LEFT_CLIP, (reg32))

#define OVL_L1_CON_GET_DSTKEY_EN(reg32)                        REG_FLD_GET(OVL_L1_CON_FLD_DSTKEY_EN, (reg32))
#define OVL_L1_CON_GET_SRCKEY_EN(reg32)                        REG_FLD_GET(OVL_L1_CON_FLD_SRCKEY_EN, (reg32))
#define OVL_L1_CON_GET_LAYER_SRC(reg32)                        REG_FLD_GET(OVL_L1_CON_FLD_LAYER_SRC, (reg32))
#define OVL_L1_CON_GET_MTX_EN(reg32)                           REG_FLD_GET(OVL_L1_CON_FLD_MTX_EN, (reg32))
#define OVL_L1_CON_GET_MTX_AUTO_DIS(reg32)                     REG_FLD_GET(OVL_L1_CON_FLD_MTX_AUTO_DIS, (reg32))
#define OVL_L1_CON_GET_RGB_SWAP(reg32)                         REG_FLD_GET(OVL_L1_CON_FLD_RGB_SWAP, (reg32))
#define OVL_L1_CON_GET_BYTE_SWAP(reg32)                        REG_FLD_GET(OVL_L1_CON_FLD_BYTE_SWAP, (reg32))
#define OVL_L1_CON_GET_CLRFMT_MAN(reg32)                       REG_FLD_GET(OVL_L1_CON_FLD_CLRFMT_MAN, (reg32))
#define OVL_L1_CON_GET_R_FIRST(reg32)                          REG_FLD_GET(OVL_L1_CON_FLD_R_FIRST, (reg32))
#define OVL_L1_CON_GET_LANDSCAPE(reg32)                        REG_FLD_GET(OVL_L1_CON_FLD_LANDSCAPE, (reg32))
#define OVL_L1_CON_GET_EN_3D(reg32)                            REG_FLD_GET(OVL_L1_CON_FLD_EN_3D, (reg32))
#define OVL_L1_CON_GET_INT_MTX_SEL(reg32)                      REG_FLD_GET(OVL_L1_CON_FLD_INT_MTX_SEL, (reg32))
#define OVL_L1_CON_GET_CLRFMT(reg32)                           REG_FLD_GET(OVL_L1_CON_FLD_CLRFMT, (reg32))
#define OVL_L1_CON_GET_EXT_MTX_EN(reg32)                       REG_FLD_GET(OVL_L1_CON_FLD_EXT_MTX_EN, (reg32))
#define OVL_L1_CON_GET_HORIZONTAL_FLIP_EN(reg32)               REG_FLD_GET(OVL_L1_CON_FLD_HORIZONTAL_FLIP_EN, (reg32))
#define OVL_L1_CON_GET_VERTICAL_FLIP_EN(reg32)                 REG_FLD_GET(OVL_L1_CON_FLD_VERTICAL_FLIP_EN, (reg32))
#define OVL_L1_CON_GET_ALPHA_EN(reg32)                         REG_FLD_GET(OVL_L1_CON_FLD_ALPHA_EN, (reg32))
#define OVL_L1_CON_GET_ALPHA(reg32)                            REG_FLD_GET(OVL_L1_CON_FLD_ALPHA, (reg32))

#define OVL_L1_SRCKEY_GET_SRCKEY(reg32)                        REG_FLD_GET(OVL_L1_SRCKEY_FLD_SRCKEY, (reg32))

#define OVL_L1_SRC_SIZE_GET_L1_SRC_H(reg32)                    REG_FLD_GET(OVL_L1_SRC_SIZE_FLD_L1_SRC_H, (reg32))
#define OVL_L1_SRC_SIZE_GET_L1_SRC_W(reg32)                    REG_FLD_GET(OVL_L1_SRC_SIZE_FLD_L1_SRC_W, (reg32))

#define OVL_L1_OFFSET_GET_L1_YOFF(reg32)                       REG_FLD_GET(OVL_L1_OFFSET_FLD_L1_YOFF, (reg32))
#define OVL_L1_OFFSET_GET_L1_XOFF(reg32)                       REG_FLD_GET(OVL_L1_OFFSET_FLD_L1_XOFF, (reg32))

#define OVL_L1_PITCH_GET_SURFL_EN(reg32)                       REG_FLD_GET(OVL_L1_PITCH_FLD_SURFL_EN, (reg32))
#define OVL_L1_PITCH_GET_L1_BLEND_RND_SHT(reg32)               REG_FLD_GET(OVL_L1_PITCH_FLD_L1_BLEND_RND_SHT, (reg32))
#define OVL_L1_PITCH_GET_L1_SRGB_SEL_EXT2(reg32)               REG_FLD_GET(OVL_L1_PITCH_FLD_L1_SRGB_SEL_EXT2, (reg32))
#define OVL_L1_PITCH_GET_L1_CONST_BLD(reg32)                   REG_FLD_GET(OVL_L1_PITCH_FLD_L1_CONST_BLD, (reg32))
#define OVL_L1_PITCH_GET_L1_DRGB_SEL_EXT(reg32)                REG_FLD_GET(OVL_L1_PITCH_FLD_L1_DRGB_SEL_EXT, (reg32))
#define OVL_L1_PITCH_GET_L1_DA_SEL_EXT(reg32)                  REG_FLD_GET(OVL_L1_PITCH_FLD_L1_DA_SEL_EXT, (reg32))
#define OVL_L1_PITCH_GET_L1_SRGB_SEL_EXT(reg32)                REG_FLD_GET(OVL_L1_PITCH_FLD_L1_SRGB_SEL_EXT, (reg32))
#define OVL_L1_PITCH_GET_L1_SA_SEL_EXT(reg32)                  REG_FLD_GET(OVL_L1_PITCH_FLD_L1_SA_SEL_EXT, (reg32))
#define OVL_L1_PITCH_GET_L1_DRGB_SEL(reg32)                    REG_FLD_GET(OVL_L1_PITCH_FLD_L1_DRGB_SEL, (reg32))
#define OVL_L1_PITCH_GET_L1_DA_SEL(reg32)                      REG_FLD_GET(OVL_L1_PITCH_FLD_L1_DA_SEL, (reg32))
#define OVL_L1_PITCH_GET_L1_SRGB_SEL(reg32)                    REG_FLD_GET(OVL_L1_PITCH_FLD_L1_SRGB_SEL, (reg32))
#define OVL_L1_PITCH_GET_L1_SA_SEL(reg32)                      REG_FLD_GET(OVL_L1_PITCH_FLD_L1_SA_SEL, (reg32))
#define OVL_L1_PITCH_GET_L1_SRC_PITCH(reg32)                   REG_FLD_GET(OVL_L1_PITCH_FLD_L1_SRC_PITCH, (reg32))

#define OVL_L1_TILE_GET_TILE_HORI_BLOCK_NUM(reg32)             REG_FLD_GET(OVL_L1_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32))
#define OVL_L1_TILE_GET_TILE_EN(reg32)                         REG_FLD_GET(OVL_L1_TILE_FLD_TILE_EN, (reg32))
#define OVL_L1_TILE_GET_TILE_WIDTH_SEL(reg32)                  REG_FLD_GET(OVL_L1_TILE_FLD_TILE_WIDTH_SEL, (reg32))
#define OVL_L1_TILE_GET_TILE_HEIGHT(reg32)                     REG_FLD_GET(OVL_L1_TILE_FLD_TILE_HEIGHT, (reg32))

#define OVL_L1_CLIP_GET_L1_SRC_BOTTOM_CLIP(reg32)              REG_FLD_GET(OVL_L1_CLIP_FLD_L1_SRC_BOTTOM_CLIP, (reg32))
#define OVL_L1_CLIP_GET_L1_SRC_TOP_CLIP(reg32)                 REG_FLD_GET(OVL_L1_CLIP_FLD_L1_SRC_TOP_CLIP, (reg32))
#define OVL_L1_CLIP_GET_L1_SRC_RIGHT_CLIP(reg32)               REG_FLD_GET(OVL_L1_CLIP_FLD_L1_SRC_RIGHT_CLIP, (reg32))
#define OVL_L1_CLIP_GET_L1_SRC_LEFT_CLIP(reg32)                REG_FLD_GET(OVL_L1_CLIP_FLD_L1_SRC_LEFT_CLIP, (reg32))

#define OVL_L2_CON_GET_DSTKEY_EN(reg32)                        REG_FLD_GET(OVL_L2_CON_FLD_DSTKEY_EN, (reg32))
#define OVL_L2_CON_GET_SRCKEY_EN(reg32)                        REG_FLD_GET(OVL_L2_CON_FLD_SRCKEY_EN, (reg32))
#define OVL_L2_CON_GET_LAYER_SRC(reg32)                        REG_FLD_GET(OVL_L2_CON_FLD_LAYER_SRC, (reg32))
#define OVL_L2_CON_GET_MTX_EN(reg32)                           REG_FLD_GET(OVL_L2_CON_FLD_MTX_EN, (reg32))
#define OVL_L2_CON_GET_MTX_AUTO_DIS(reg32)                     REG_FLD_GET(OVL_L2_CON_FLD_MTX_AUTO_DIS, (reg32))
#define OVL_L2_CON_GET_RGB_SWAP(reg32)                         REG_FLD_GET(OVL_L2_CON_FLD_RGB_SWAP, (reg32))
#define OVL_L2_CON_GET_BYTE_SWAP(reg32)                        REG_FLD_GET(OVL_L2_CON_FLD_BYTE_SWAP, (reg32))
#define OVL_L2_CON_GET_CLRFMT_MAN(reg32)                       REG_FLD_GET(OVL_L2_CON_FLD_CLRFMT_MAN, (reg32))
#define OVL_L2_CON_GET_R_FIRST(reg32)                          REG_FLD_GET(OVL_L2_CON_FLD_R_FIRST, (reg32))
#define OVL_L2_CON_GET_LANDSCAPE(reg32)                        REG_FLD_GET(OVL_L2_CON_FLD_LANDSCAPE, (reg32))
#define OVL_L2_CON_GET_EN_3D(reg32)                            REG_FLD_GET(OVL_L2_CON_FLD_EN_3D, (reg32))
#define OVL_L2_CON_GET_INT_MTX_SEL(reg32)                      REG_FLD_GET(OVL_L2_CON_FLD_INT_MTX_SEL, (reg32))
#define OVL_L2_CON_GET_CLRFMT(reg32)                           REG_FLD_GET(OVL_L2_CON_FLD_CLRFMT, (reg32))
#define OVL_L2_CON_GET_EXT_MTX_EN(reg32)                       REG_FLD_GET(OVL_L2_CON_FLD_EXT_MTX_EN, (reg32))
#define OVL_L2_CON_GET_HORIZONTAL_FLIP_EN(reg32)               REG_FLD_GET(OVL_L2_CON_FLD_HORIZONTAL_FLIP_EN, (reg32))
#define OVL_L2_CON_GET_VERTICAL_FLIP_EN(reg32)                 REG_FLD_GET(OVL_L2_CON_FLD_VERTICAL_FLIP_EN, (reg32))
#define OVL_L2_CON_GET_ALPHA_EN(reg32)                         REG_FLD_GET(OVL_L2_CON_FLD_ALPHA_EN, (reg32))
#define OVL_L2_CON_GET_ALPHA(reg32)                            REG_FLD_GET(OVL_L2_CON_FLD_ALPHA, (reg32))

#define OVL_L2_SRCKEY_GET_SRCKEY(reg32)                        REG_FLD_GET(OVL_L2_SRCKEY_FLD_SRCKEY, (reg32))

#define OVL_L2_SRC_SIZE_GET_L2_SRC_H(reg32)                    REG_FLD_GET(OVL_L2_SRC_SIZE_FLD_L2_SRC_H, (reg32))
#define OVL_L2_SRC_SIZE_GET_L2_SRC_W(reg32)                    REG_FLD_GET(OVL_L2_SRC_SIZE_FLD_L2_SRC_W, (reg32))

#define OVL_L2_OFFSET_GET_L2_YOFF(reg32)                       REG_FLD_GET(OVL_L2_OFFSET_FLD_L2_YOFF, (reg32))
#define OVL_L2_OFFSET_GET_L2_XOFF(reg32)                       REG_FLD_GET(OVL_L2_OFFSET_FLD_L2_XOFF, (reg32))

#define OVL_L2_PITCH_GET_SURFL_EN(reg32)                       REG_FLD_GET(OVL_L2_PITCH_FLD_SURFL_EN, (reg32))
#define OVL_L2_PITCH_GET_L2_BLEND_RND_SHT(reg32)               REG_FLD_GET(OVL_L2_PITCH_FLD_L2_BLEND_RND_SHT, (reg32))
#define OVL_L2_PITCH_GET_L2_SRGB_SEL_EXT2(reg32)               REG_FLD_GET(OVL_L2_PITCH_FLD_L2_SRGB_SEL_EXT2, (reg32))
#define OVL_L2_PITCH_GET_L2_CONST_BLD(reg32)                   REG_FLD_GET(OVL_L2_PITCH_FLD_L2_CONST_BLD, (reg32))
#define OVL_L2_PITCH_GET_L2_DRGB_SEL_EXT(reg32)                REG_FLD_GET(OVL_L2_PITCH_FLD_L2_DRGB_SEL_EXT, (reg32))
#define OVL_L2_PITCH_GET_L2_DA_SEL_EXT(reg32)                  REG_FLD_GET(OVL_L2_PITCH_FLD_L2_DA_SEL_EXT, (reg32))
#define OVL_L2_PITCH_GET_L2_SRGB_SEL_EXT(reg32)                REG_FLD_GET(OVL_L2_PITCH_FLD_L2_SRGB_SEL_EXT, (reg32))
#define OVL_L2_PITCH_GET_L2_SA_SEL_EXT(reg32)                  REG_FLD_GET(OVL_L2_PITCH_FLD_L2_SA_SEL_EXT, (reg32))
#define OVL_L2_PITCH_GET_L2_DRGB_SEL(reg32)                    REG_FLD_GET(OVL_L2_PITCH_FLD_L2_DRGB_SEL, (reg32))
#define OVL_L2_PITCH_GET_L2_DA_SEL(reg32)                      REG_FLD_GET(OVL_L2_PITCH_FLD_L2_DA_SEL, (reg32))
#define OVL_L2_PITCH_GET_L2_SRGB_SEL(reg32)                    REG_FLD_GET(OVL_L2_PITCH_FLD_L2_SRGB_SEL, (reg32))
#define OVL_L2_PITCH_GET_L2_SA_SEL(reg32)                      REG_FLD_GET(OVL_L2_PITCH_FLD_L2_SA_SEL, (reg32))
#define OVL_L2_PITCH_GET_L2_SRC_PITCH(reg32)                   REG_FLD_GET(OVL_L2_PITCH_FLD_L2_SRC_PITCH, (reg32))

#define OVL_L2_TILE_GET_TILE_HORI_BLOCK_NUM(reg32)             REG_FLD_GET(OVL_L2_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32))
#define OVL_L2_TILE_GET_TILE_EN(reg32)                         REG_FLD_GET(OVL_L2_TILE_FLD_TILE_EN, (reg32))
#define OVL_L2_TILE_GET_TILE_WIDTH_SEL(reg32)                  REG_FLD_GET(OVL_L2_TILE_FLD_TILE_WIDTH_SEL, (reg32))
#define OVL_L2_TILE_GET_TILE_HEIGHT(reg32)                     REG_FLD_GET(OVL_L2_TILE_FLD_TILE_HEIGHT, (reg32))

#define OVL_L2_CLIP_GET_L2_SRC_BOTTOM_CLIP(reg32)              REG_FLD_GET(OVL_L2_CLIP_FLD_L2_SRC_BOTTOM_CLIP, (reg32))
#define OVL_L2_CLIP_GET_L2_SRC_TOP_CLIP(reg32)                 REG_FLD_GET(OVL_L2_CLIP_FLD_L2_SRC_TOP_CLIP, (reg32))
#define OVL_L2_CLIP_GET_L2_SRC_RIGHT_CLIP(reg32)               REG_FLD_GET(OVL_L2_CLIP_FLD_L2_SRC_RIGHT_CLIP, (reg32))
#define OVL_L2_CLIP_GET_L2_SRC_LEFT_CLIP(reg32)                REG_FLD_GET(OVL_L2_CLIP_FLD_L2_SRC_LEFT_CLIP, (reg32))

#define OVL_L3_CON_GET_DSTKEY_EN(reg32)                        REG_FLD_GET(OVL_L3_CON_FLD_DSTKEY_EN, (reg32))
#define OVL_L3_CON_GET_SRCKEY_EN(reg32)                        REG_FLD_GET(OVL_L3_CON_FLD_SRCKEY_EN, (reg32))
#define OVL_L3_CON_GET_LAYER_SRC(reg32)                        REG_FLD_GET(OVL_L3_CON_FLD_LAYER_SRC, (reg32))
#define OVL_L3_CON_GET_MTX_EN(reg32)                           REG_FLD_GET(OVL_L3_CON_FLD_MTX_EN, (reg32))
#define OVL_L3_CON_GET_MTX_AUTO_DIS(reg32)                     REG_FLD_GET(OVL_L3_CON_FLD_MTX_AUTO_DIS, (reg32))
#define OVL_L3_CON_GET_RGB_SWAP(reg32)                         REG_FLD_GET(OVL_L3_CON_FLD_RGB_SWAP, (reg32))
#define OVL_L3_CON_GET_BYTE_SWAP(reg32)                        REG_FLD_GET(OVL_L3_CON_FLD_BYTE_SWAP, (reg32))
#define OVL_L3_CON_GET_CLRFMT_MAN(reg32)                       REG_FLD_GET(OVL_L3_CON_FLD_CLRFMT_MAN, (reg32))
#define OVL_L3_CON_GET_R_FIRST(reg32)                          REG_FLD_GET(OVL_L3_CON_FLD_R_FIRST, (reg32))
#define OVL_L3_CON_GET_LANDSCAPE(reg32)                        REG_FLD_GET(OVL_L3_CON_FLD_LANDSCAPE, (reg32))
#define OVL_L3_CON_GET_EN_3D(reg32)                            REG_FLD_GET(OVL_L3_CON_FLD_EN_3D, (reg32))
#define OVL_L3_CON_GET_INT_MTX_SEL(reg32)                      REG_FLD_GET(OVL_L3_CON_FLD_INT_MTX_SEL, (reg32))
#define OVL_L3_CON_GET_CLRFMT(reg32)                           REG_FLD_GET(OVL_L3_CON_FLD_CLRFMT, (reg32))
#define OVL_L3_CON_GET_EXT_MTX_EN(reg32)                       REG_FLD_GET(OVL_L3_CON_FLD_EXT_MTX_EN, (reg32))
#define OVL_L3_CON_GET_HORIZONTAL_FLIP_EN(reg32)               REG_FLD_GET(OVL_L3_CON_FLD_HORIZONTAL_FLIP_EN, (reg32))
#define OVL_L3_CON_GET_VERTICAL_FLIP_EN(reg32)                 REG_FLD_GET(OVL_L3_CON_FLD_VERTICAL_FLIP_EN, (reg32))
#define OVL_L3_CON_GET_ALPHA_EN(reg32)                         REG_FLD_GET(OVL_L3_CON_FLD_ALPHA_EN, (reg32))
#define OVL_L3_CON_GET_ALPHA(reg32)                            REG_FLD_GET(OVL_L3_CON_FLD_ALPHA, (reg32))

#define OVL_L3_SRCKEY_GET_SRCKEY(reg32)                        REG_FLD_GET(OVL_L3_SRCKEY_FLD_SRCKEY, (reg32))

#define OVL_L3_SRC_SIZE_GET_L3_SRC_H(reg32)                    REG_FLD_GET(OVL_L3_SRC_SIZE_FLD_L3_SRC_H, (reg32))
#define OVL_L3_SRC_SIZE_GET_L3_SRC_W(reg32)                    REG_FLD_GET(OVL_L3_SRC_SIZE_FLD_L3_SRC_W, (reg32))

#define OVL_L3_OFFSET_GET_L3_YOFF(reg32)                       REG_FLD_GET(OVL_L3_OFFSET_FLD_L3_YOFF, (reg32))
#define OVL_L3_OFFSET_GET_L3_XOFF(reg32)                       REG_FLD_GET(OVL_L3_OFFSET_FLD_L3_XOFF, (reg32))

#define OVL_L3_PITCH_GET_SURFL_EN(reg32)                       REG_FLD_GET(OVL_L3_PITCH_FLD_SURFL_EN, (reg32))
#define OVL_L3_PITCH_GET_L3_BLEND_RND_SHT(reg32)               REG_FLD_GET(OVL_L3_PITCH_FLD_L3_BLEND_RND_SHT, (reg32))
#define OVL_L3_PITCH_GET_L3_SRGB_SEL_EXT2(reg32)               REG_FLD_GET(OVL_L3_PITCH_FLD_L3_SRGB_SEL_EXT2, (reg32))
#define OVL_L3_PITCH_GET_L3_CONST_BLD(reg32)                   REG_FLD_GET(OVL_L3_PITCH_FLD_L3_CONST_BLD, (reg32))
#define OVL_L3_PITCH_GET_L3_DRGB_SEL_EXT(reg32)                REG_FLD_GET(OVL_L3_PITCH_FLD_L3_DRGB_SEL_EXT, (reg32))
#define OVL_L3_PITCH_GET_L3_DA_SEL_EXT(reg32)                  REG_FLD_GET(OVL_L3_PITCH_FLD_L3_DA_SEL_EXT, (reg32))
#define OVL_L3_PITCH_GET_L3_SRGB_SEL_EXT(reg32)                REG_FLD_GET(OVL_L3_PITCH_FLD_L3_SRGB_SEL_EXT, (reg32))
#define OVL_L3_PITCH_GET_L3_SA_SEL_EXT(reg32)                  REG_FLD_GET(OVL_L3_PITCH_FLD_L3_SA_SEL_EXT, (reg32))
#define OVL_L3_PITCH_GET_L3_DRGB_SEL(reg32)                    REG_FLD_GET(OVL_L3_PITCH_FLD_L3_DRGB_SEL, (reg32))
#define OVL_L3_PITCH_GET_L3_DA_SEL(reg32)                      REG_FLD_GET(OVL_L3_PITCH_FLD_L3_DA_SEL, (reg32))
#define OVL_L3_PITCH_GET_L3_SRGB_SEL(reg32)                    REG_FLD_GET(OVL_L3_PITCH_FLD_L3_SRGB_SEL, (reg32))
#define OVL_L3_PITCH_GET_L3_SA_SEL(reg32)                      REG_FLD_GET(OVL_L3_PITCH_FLD_L3_SA_SEL, (reg32))
#define OVL_L3_PITCH_GET_L3_SRC_PITCH(reg32)                   REG_FLD_GET(OVL_L3_PITCH_FLD_L3_SRC_PITCH, (reg32))

#define OVL_L3_TILE_GET_TILE_HORI_BLOCK_NUM(reg32)             REG_FLD_GET(OVL_L3_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32))
#define OVL_L3_TILE_GET_TILE_EN(reg32)                         REG_FLD_GET(OVL_L3_TILE_FLD_TILE_EN, (reg32))
#define OVL_L3_TILE_GET_TILE_WIDTH_SEL(reg32)                  REG_FLD_GET(OVL_L3_TILE_FLD_TILE_WIDTH_SEL, (reg32))
#define OVL_L3_TILE_GET_TILE_HEIGHT(reg32)                     REG_FLD_GET(OVL_L3_TILE_FLD_TILE_HEIGHT, (reg32))

#define OVL_L3_CLIP_GET_L3_SRC_BOTTOM_CLIP(reg32)              REG_FLD_GET(OVL_L3_CLIP_FLD_L3_SRC_BOTTOM_CLIP, (reg32))
#define OVL_L3_CLIP_GET_L3_SRC_TOP_CLIP(reg32)                 REG_FLD_GET(OVL_L3_CLIP_FLD_L3_SRC_TOP_CLIP, (reg32))
#define OVL_L3_CLIP_GET_L3_SRC_RIGHT_CLIP(reg32)               REG_FLD_GET(OVL_L3_CLIP_FLD_L3_SRC_RIGHT_CLIP, (reg32))
#define OVL_L3_CLIP_GET_L3_SRC_LEFT_CLIP(reg32)                REG_FLD_GET(OVL_L3_CLIP_FLD_L3_SRC_LEFT_CLIP, (reg32))

#define OVL_RDMA0_CTRL_GET_RDMA0_FIFO_USED_SIZE(reg32)         REG_FLD_GET(OVL_RDMA0_CTRL_FLD_RDMA0_FIFO_USED_SIZE, (reg32))
#define OVL_RDMA0_CTRL_GET_RDMA0_INTERLACE(reg32)              REG_FLD_GET(OVL_RDMA0_CTRL_FLD_RDMA0_INTERLACE, (reg32))
#define OVL_RDMA0_CTRL_GET_RDMA0_EN(reg32)                     REG_FLD_GET(OVL_RDMA0_CTRL_FLD_RDMA0_EN, (reg32))

#define OVL_RDMA0_MEM_GMC_SETTING1_GET_RDMA0_PRE_ULTRA_THRESHOLD_HIGH_OFS(reg32) REG_FLD_GET(OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_PRE_ULTRA_THRESHOLD_HIGH_OFS, (reg32))
#define OVL_RDMA0_MEM_GMC_SETTING1_GET_RDMA0_ULTRA_THRESHOLD_HIGH_OFS(reg32) REG_FLD_GET(OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_ULTRA_THRESHOLD_HIGH_OFS, (reg32))
#define OVL_RDMA0_MEM_GMC_SETTING1_GET_RDMA0_OSTD_PREULTRA_TH(reg32) REG_FLD_GET(OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_OSTD_PREULTRA_TH, (reg32))
#define OVL_RDMA0_MEM_GMC_SETTING1_GET_RDMA0_OSTD_ULTRA_TH(reg32) REG_FLD_GET(OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_OSTD_ULTRA_TH, (reg32))

#define OVL_RDMA0_MEM_SLOW_CON_GET_RDMA0_SLOW_CNT(reg32)       REG_FLD_GET(OVL_RDMA0_MEM_SLOW_CON_FLD_RDMA0_SLOW_CNT, (reg32))
#define OVL_RDMA0_MEM_SLOW_CON_GET_RDMA0_SLOW_EN(reg32)        REG_FLD_GET(OVL_RDMA0_MEM_SLOW_CON_FLD_RDMA0_SLOW_EN, (reg32))

#define OVL_RDMA0_FIFO_CTRL_GET_RDMA0_FIFO_UND_EN(reg32)       REG_FLD_GET(OVL_RDMA0_FIFO_CTRL_FLD_RDMA0_FIFO_UND_EN, (reg32))
#define OVL_RDMA0_FIFO_CTRL_GET_RDMA0_FIFO_SIZE(reg32)         REG_FLD_GET(OVL_RDMA0_FIFO_CTRL_FLD_RDMA0_FIFO_SIZE, (reg32))
#define OVL_RDMA0_FIFO_CTRL_GET_RDMA0_FIFO_THRD(reg32)         REG_FLD_GET(OVL_RDMA0_FIFO_CTRL_FLD_RDMA0_FIFO_THRD, (reg32))

#define OVL_RDMA1_CTRL_GET_RDMA1_FIFO_USED_SIZE(reg32)         REG_FLD_GET(OVL_RDMA1_CTRL_FLD_RDMA1_FIFO_USED_SIZE, (reg32))
#define OVL_RDMA1_CTRL_GET_RDMA1_INTERLACE(reg32)              REG_FLD_GET(OVL_RDMA1_CTRL_FLD_RDMA1_INTERLACE, (reg32))
#define OVL_RDMA1_CTRL_GET_RDMA1_EN(reg32)                     REG_FLD_GET(OVL_RDMA1_CTRL_FLD_RDMA1_EN, (reg32))

#define OVL_RDMA1_MEM_GMC_SETTING1_GET_RDMA1_PRE_ULTRA_THRESHOLD_HIGH_OFS(reg32) REG_FLD_GET(OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_PRE_ULTRA_THRESHOLD_HIGH_OFS, (reg32))
#define OVL_RDMA1_MEM_GMC_SETTING1_GET_RDMA1_ULTRA_THRESHOLD_HIGH_OFS(reg32) REG_FLD_GET(OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_ULTRA_THRESHOLD_HIGH_OFS, (reg32))
#define OVL_RDMA1_MEM_GMC_SETTING1_GET_RDMA1_OSTD_PREULTRA_TH(reg32) REG_FLD_GET(OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_OSTD_PREULTRA_TH, (reg32))
#define OVL_RDMA1_MEM_GMC_SETTING1_GET_RDMA1_OSTD_ULTRA_TH(reg32) REG_FLD_GET(OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_OSTD_ULTRA_TH, (reg32))

#define OVL_RDMA1_MEM_SLOW_CON_GET_RDMA1_SLOW_CNT(reg32)       REG_FLD_GET(OVL_RDMA1_MEM_SLOW_CON_FLD_RDMA1_SLOW_CNT, (reg32))
#define OVL_RDMA1_MEM_SLOW_CON_GET_RDMA1_SLOW_EN(reg32)        REG_FLD_GET(OVL_RDMA1_MEM_SLOW_CON_FLD_RDMA1_SLOW_EN, (reg32))

#define OVL_RDMA1_FIFO_CTRL_GET_RDMA1_FIFO_UND_EN(reg32)       REG_FLD_GET(OVL_RDMA1_FIFO_CTRL_FLD_RDMA1_FIFO_UND_EN, (reg32))
#define OVL_RDMA1_FIFO_CTRL_GET_RDMA1_FIFO_SIZE(reg32)         REG_FLD_GET(OVL_RDMA1_FIFO_CTRL_FLD_RDMA1_FIFO_SIZE, (reg32))
#define OVL_RDMA1_FIFO_CTRL_GET_RDMA1_FIFO_THRD(reg32)         REG_FLD_GET(OVL_RDMA1_FIFO_CTRL_FLD_RDMA1_FIFO_THRD, (reg32))

#define OVL_RDMA2_CTRL_GET_RDMA2_FIFO_USED_SIZE(reg32)         REG_FLD_GET(OVL_RDMA2_CTRL_FLD_RDMA2_FIFO_USED_SIZE, (reg32))
#define OVL_RDMA2_CTRL_GET_RDMA2_INTERLACE(reg32)              REG_FLD_GET(OVL_RDMA2_CTRL_FLD_RDMA2_INTERLACE, (reg32))
#define OVL_RDMA2_CTRL_GET_RDMA2_EN(reg32)                     REG_FLD_GET(OVL_RDMA2_CTRL_FLD_RDMA2_EN, (reg32))

#define OVL_RDMA2_MEM_GMC_SETTING1_GET_RDMA2_PRE_ULTRA_THRESHOLD_HIGH_OFS(reg32) REG_FLD_GET(OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_PRE_ULTRA_THRESHOLD_HIGH_OFS, (reg32))
#define OVL_RDMA2_MEM_GMC_SETTING1_GET_RDMA2_ULTRA_THRESHOLD_HIGH_OFS(reg32) REG_FLD_GET(OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_ULTRA_THRESHOLD_HIGH_OFS, (reg32))
#define OVL_RDMA2_MEM_GMC_SETTING1_GET_RDMA2_OSTD_PREULTRA_TH(reg32) REG_FLD_GET(OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_OSTD_PREULTRA_TH, (reg32))
#define OVL_RDMA2_MEM_GMC_SETTING1_GET_RDMA2_OSTD_ULTRA_TH(reg32) REG_FLD_GET(OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_OSTD_ULTRA_TH, (reg32))

#define OVL_RDMA2_MEM_SLOW_CON_GET_RDMA2_SLOW_CNT(reg32)       REG_FLD_GET(OVL_RDMA2_MEM_SLOW_CON_FLD_RDMA2_SLOW_CNT, (reg32))
#define OVL_RDMA2_MEM_SLOW_CON_GET_RDMA2_SLOW_EN(reg32)        REG_FLD_GET(OVL_RDMA2_MEM_SLOW_CON_FLD_RDMA2_SLOW_EN, (reg32))

#define OVL_RDMA2_FIFO_CTRL_GET_RDMA2_FIFO_UND_EN(reg32)       REG_FLD_GET(OVL_RDMA2_FIFO_CTRL_FLD_RDMA2_FIFO_UND_EN, (reg32))
#define OVL_RDMA2_FIFO_CTRL_GET_RDMA2_FIFO_SIZE(reg32)         REG_FLD_GET(OVL_RDMA2_FIFO_CTRL_FLD_RDMA2_FIFO_SIZE, (reg32))
#define OVL_RDMA2_FIFO_CTRL_GET_RDMA2_FIFO_THRD(reg32)         REG_FLD_GET(OVL_RDMA2_FIFO_CTRL_FLD_RDMA2_FIFO_THRD, (reg32))

#define OVL_RDMA3_CTRL_GET_RDMA3_FIFO_USED_SIZE(reg32)         REG_FLD_GET(OVL_RDMA3_CTRL_FLD_RDMA3_FIFO_USED_SIZE, (reg32))
#define OVL_RDMA3_CTRL_GET_RDMA3_INTERLACE(reg32)              REG_FLD_GET(OVL_RDMA3_CTRL_FLD_RDMA3_INTERLACE, (reg32))
#define OVL_RDMA3_CTRL_GET_RDMA3_EN(reg32)                     REG_FLD_GET(OVL_RDMA3_CTRL_FLD_RDMA3_EN, (reg32))

#define OVL_RDMA3_MEM_GMC_SETTING1_GET_RDMA3_PRE_ULTRA_THRESHOLD_HIGH_OFS(reg32) REG_FLD_GET(OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_PRE_ULTRA_THRESHOLD_HIGH_OFS, (reg32))
#define OVL_RDMA3_MEM_GMC_SETTING1_GET_RDMA3_ULTRA_THRESHOLD_HIGH_OFS(reg32) REG_FLD_GET(OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_ULTRA_THRESHOLD_HIGH_OFS, (reg32))
#define OVL_RDMA3_MEM_GMC_SETTING1_GET_RDMA3_OSTD_PREULTRA_TH(reg32) REG_FLD_GET(OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_OSTD_PREULTRA_TH, (reg32))
#define OVL_RDMA3_MEM_GMC_SETTING1_GET_RDMA3_OSTD_ULTRA_TH(reg32) REG_FLD_GET(OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_OSTD_ULTRA_TH, (reg32))

#define OVL_RDMA3_MEM_SLOW_CON_GET_RDMA3_SLOW_CNT(reg32)       REG_FLD_GET(OVL_RDMA3_MEM_SLOW_CON_FLD_RDMA3_SLOW_CNT, (reg32))
#define OVL_RDMA3_MEM_SLOW_CON_GET_RDMA3_SLOW_EN(reg32)        REG_FLD_GET(OVL_RDMA3_MEM_SLOW_CON_FLD_RDMA3_SLOW_EN, (reg32))

#define OVL_RDMA3_FIFO_CTRL_GET_RDMA3_FIFO_UND_EN(reg32)       REG_FLD_GET(OVL_RDMA3_FIFO_CTRL_FLD_RDMA3_FIFO_UND_EN, (reg32))
#define OVL_RDMA3_FIFO_CTRL_GET_RDMA3_FIFO_SIZE(reg32)         REG_FLD_GET(OVL_RDMA3_FIFO_CTRL_FLD_RDMA3_FIFO_SIZE, (reg32))
#define OVL_RDMA3_FIFO_CTRL_GET_RDMA3_FIFO_THRD(reg32)         REG_FLD_GET(OVL_RDMA3_FIFO_CTRL_FLD_RDMA3_FIFO_THRD, (reg32))

#define OVL_L0_Y2R_PARA_R0_GET_C_CF_RMU(reg32)                 REG_FLD_GET(OVL_L0_Y2R_PARA_R0_FLD_C_CF_RMU, (reg32))
#define OVL_L0_Y2R_PARA_R0_GET_C_CF_RMY(reg32)                 REG_FLD_GET(OVL_L0_Y2R_PARA_R0_FLD_C_CF_RMY, (reg32))

#define OVL_L0_Y2R_PARA_R1_GET_C_CF_RMV(reg32)                 REG_FLD_GET(OVL_L0_Y2R_PARA_R1_FLD_C_CF_RMV, (reg32))

#define OVL_L0_Y2R_PARA_G0_GET_C_CF_GMU(reg32)                 REG_FLD_GET(OVL_L0_Y2R_PARA_G0_FLD_C_CF_GMU, (reg32))
#define OVL_L0_Y2R_PARA_G0_GET_C_CF_GMY(reg32)                 REG_FLD_GET(OVL_L0_Y2R_PARA_G0_FLD_C_CF_GMY, (reg32))

#define OVL_L0_Y2R_PARA_G1_GET_C_CF_GMV(reg32)                 REG_FLD_GET(OVL_L0_Y2R_PARA_G1_FLD_C_CF_GMV, (reg32))

#define OVL_L0_Y2R_PARA_B0_GET_C_CF_BMU(reg32)                 REG_FLD_GET(OVL_L0_Y2R_PARA_B0_FLD_C_CF_BMU, (reg32))
#define OVL_L0_Y2R_PARA_B0_GET_C_CF_BMY(reg32)                 REG_FLD_GET(OVL_L0_Y2R_PARA_B0_FLD_C_CF_BMY, (reg32))

#define OVL_L0_Y2R_PARA_B1_GET_C_CF_BMV(reg32)                 REG_FLD_GET(OVL_L0_Y2R_PARA_B1_FLD_C_CF_BMV, (reg32))

#define OVL_L0_Y2R_PARA_YUV_A_0_GET_C_CF_UA(reg32)             REG_FLD_GET(OVL_L0_Y2R_PARA_YUV_A_0_FLD_C_CF_UA, (reg32))
#define OVL_L0_Y2R_PARA_YUV_A_0_GET_C_CF_YA(reg32)             REG_FLD_GET(OVL_L0_Y2R_PARA_YUV_A_0_FLD_C_CF_YA, (reg32))

#define OVL_L0_Y2R_PARA_YUV_A_1_GET_C_CF_VA(reg32)             REG_FLD_GET(OVL_L0_Y2R_PARA_YUV_A_1_FLD_C_CF_VA, (reg32))

#define OVL_L0_Y2R_PARA_RGB_A_0_GET_C_CF_GA(reg32)             REG_FLD_GET(OVL_L0_Y2R_PARA_RGB_A_0_FLD_C_CF_GA, (reg32))
#define OVL_L0_Y2R_PARA_RGB_A_0_GET_C_CF_RA(reg32)             REG_FLD_GET(OVL_L0_Y2R_PARA_RGB_A_0_FLD_C_CF_RA, (reg32))

#define OVL_L0_Y2R_PARA_RGB_A_1_GET_C_CF_BA(reg32)             REG_FLD_GET(OVL_L0_Y2R_PARA_RGB_A_1_FLD_C_CF_BA, (reg32))

#define OVL_L1_Y2R_PARA_R0_GET_C_CF_RMU(reg32)                 REG_FLD_GET(OVL_L1_Y2R_PARA_R0_FLD_C_CF_RMU, (reg32))
#define OVL_L1_Y2R_PARA_R0_GET_C_CF_RMY(reg32)                 REG_FLD_GET(OVL_L1_Y2R_PARA_R0_FLD_C_CF_RMY, (reg32))

#define OVL_L1_Y2R_PARA_R1_GET_C_CF_RMV(reg32)                 REG_FLD_GET(OVL_L1_Y2R_PARA_R1_FLD_C_CF_RMV, (reg32))

#define OVL_L1_Y2R_PARA_G0_GET_C_CF_GMU(reg32)                 REG_FLD_GET(OVL_L1_Y2R_PARA_G0_FLD_C_CF_GMU, (reg32))
#define OVL_L1_Y2R_PARA_G0_GET_C_CF_GMY(reg32)                 REG_FLD_GET(OVL_L1_Y2R_PARA_G0_FLD_C_CF_GMY, (reg32))

#define OVL_L1_Y2R_PARA_G1_GET_C_CF_GMV(reg32)                 REG_FLD_GET(OVL_L1_Y2R_PARA_G1_FLD_C_CF_GMV, (reg32))

#define OVL_L1_Y2R_PARA_B0_GET_C_CF_BMU(reg32)                 REG_FLD_GET(OVL_L1_Y2R_PARA_B0_FLD_C_CF_BMU, (reg32))
#define OVL_L1_Y2R_PARA_B0_GET_C_CF_BMY(reg32)                 REG_FLD_GET(OVL_L1_Y2R_PARA_B0_FLD_C_CF_BMY, (reg32))

#define OVL_L1_Y2R_PARA_B1_GET_C_CF_BMV(reg32)                 REG_FLD_GET(OVL_L1_Y2R_PARA_B1_FLD_C_CF_BMV, (reg32))

#define OVL_L1_Y2R_PARA_YUV_A_0_GET_C_CF_UA(reg32)             REG_FLD_GET(OVL_L1_Y2R_PARA_YUV_A_0_FLD_C_CF_UA, (reg32))
#define OVL_L1_Y2R_PARA_YUV_A_0_GET_C_CF_YA(reg32)             REG_FLD_GET(OVL_L1_Y2R_PARA_YUV_A_0_FLD_C_CF_YA, (reg32))

#define OVL_L1_Y2R_PARA_YUV_A_1_GET_C_CF_VA(reg32)             REG_FLD_GET(OVL_L1_Y2R_PARA_YUV_A_1_FLD_C_CF_VA, (reg32))

#define OVL_L1_Y2R_PARA_RGB_A_0_GET_C_CF_GA(reg32)             REG_FLD_GET(OVL_L1_Y2R_PARA_RGB_A_0_FLD_C_CF_GA, (reg32))
#define OVL_L1_Y2R_PARA_RGB_A_0_GET_C_CF_RA(reg32)             REG_FLD_GET(OVL_L1_Y2R_PARA_RGB_A_0_FLD_C_CF_RA, (reg32))

#define OVL_L1_Y2R_PARA_RGB_A_1_GET_C_CF_BA(reg32)             REG_FLD_GET(OVL_L1_Y2R_PARA_RGB_A_1_FLD_C_CF_BA, (reg32))

#define OVL_L2_Y2R_PARA_R0_GET_C_CF_RMU(reg32)                 REG_FLD_GET(OVL_L2_Y2R_PARA_R0_FLD_C_CF_RMU, (reg32))
#define OVL_L2_Y2R_PARA_R0_GET_C_CF_RMY(reg32)                 REG_FLD_GET(OVL_L2_Y2R_PARA_R0_FLD_C_CF_RMY, (reg32))

#define OVL_L2_Y2R_PARA_R1_GET_C_CF_RMV(reg32)                 REG_FLD_GET(OVL_L2_Y2R_PARA_R1_FLD_C_CF_RMV, (reg32))

#define OVL_L2_Y2R_PARA_G0_GET_C_CF_GMU(reg32)                 REG_FLD_GET(OVL_L2_Y2R_PARA_G0_FLD_C_CF_GMU, (reg32))
#define OVL_L2_Y2R_PARA_G0_GET_C_CF_GMY(reg32)                 REG_FLD_GET(OVL_L2_Y2R_PARA_G0_FLD_C_CF_GMY, (reg32))

#define OVL_L2_Y2R_PARA_G1_GET_C_CF_GMV(reg32)                 REG_FLD_GET(OVL_L2_Y2R_PARA_G1_FLD_C_CF_GMV, (reg32))

#define OVL_L2_Y2R_PARA_B0_GET_C_CF_BMU(reg32)                 REG_FLD_GET(OVL_L2_Y2R_PARA_B0_FLD_C_CF_BMU, (reg32))
#define OVL_L2_Y2R_PARA_B0_GET_C_CF_BMY(reg32)                 REG_FLD_GET(OVL_L2_Y2R_PARA_B0_FLD_C_CF_BMY, (reg32))

#define OVL_L2_Y2R_PARA_B1_GET_C_CF_BMV(reg32)                 REG_FLD_GET(OVL_L2_Y2R_PARA_B1_FLD_C_CF_BMV, (reg32))

#define OVL_L2_Y2R_PARA_YUV_A_0_GET_C_CF_UA(reg32)             REG_FLD_GET(OVL_L2_Y2R_PARA_YUV_A_0_FLD_C_CF_UA, (reg32))
#define OVL_L2_Y2R_PARA_YUV_A_0_GET_C_CF_YA(reg32)             REG_FLD_GET(OVL_L2_Y2R_PARA_YUV_A_0_FLD_C_CF_YA, (reg32))

#define OVL_L2_Y2R_PARA_YUV_A_1_GET_C_CF_VA(reg32)             REG_FLD_GET(OVL_L2_Y2R_PARA_YUV_A_1_FLD_C_CF_VA, (reg32))

#define OVL_L2_Y2R_PARA_RGB_A_0_GET_C_CF_GA(reg32)             REG_FLD_GET(OVL_L2_Y2R_PARA_RGB_A_0_FLD_C_CF_GA, (reg32))
#define OVL_L2_Y2R_PARA_RGB_A_0_GET_C_CF_RA(reg32)             REG_FLD_GET(OVL_L2_Y2R_PARA_RGB_A_0_FLD_C_CF_RA, (reg32))

#define OVL_L2_Y2R_PARA_RGB_A_1_GET_C_CF_BA(reg32)             REG_FLD_GET(OVL_L2_Y2R_PARA_RGB_A_1_FLD_C_CF_BA, (reg32))

#define OVL_L3_Y2R_PARA_R0_GET_C_CF_RMU(reg32)                 REG_FLD_GET(OVL_L3_Y2R_PARA_R0_FLD_C_CF_RMU, (reg32))
#define OVL_L3_Y2R_PARA_R0_GET_C_CF_RMY(reg32)                 REG_FLD_GET(OVL_L3_Y2R_PARA_R0_FLD_C_CF_RMY, (reg32))

#define OVL_L3_Y2R_PARA_R1_GET_C_CF_RMV(reg32)                 REG_FLD_GET(OVL_L3_Y2R_PARA_R1_FLD_C_CF_RMV, (reg32))

#define OVL_L3_Y2R_PARA_G0_GET_C_CF_GMU(reg32)                 REG_FLD_GET(OVL_L3_Y2R_PARA_G0_FLD_C_CF_GMU, (reg32))
#define OVL_L3_Y2R_PARA_G0_GET_C_CF_GMY(reg32)                 REG_FLD_GET(OVL_L3_Y2R_PARA_G0_FLD_C_CF_GMY, (reg32))

#define OVL_L3_Y2R_PARA_G1_GET_C_CF_GMV(reg32)                 REG_FLD_GET(OVL_L3_Y2R_PARA_G1_FLD_C_CF_GMV, (reg32))

#define OVL_L3_Y2R_PARA_B0_GET_C_CF_BMU(reg32)                 REG_FLD_GET(OVL_L3_Y2R_PARA_B0_FLD_C_CF_BMU, (reg32))
#define OVL_L3_Y2R_PARA_B0_GET_C_CF_BMY(reg32)                 REG_FLD_GET(OVL_L3_Y2R_PARA_B0_FLD_C_CF_BMY, (reg32))

#define OVL_L3_Y2R_PARA_B1_GET_C_CF_BMV(reg32)                 REG_FLD_GET(OVL_L3_Y2R_PARA_B1_FLD_C_CF_BMV, (reg32))

#define OVL_L3_Y2R_PARA_YUV_A_0_GET_C_CF_UA(reg32)             REG_FLD_GET(OVL_L3_Y2R_PARA_YUV_A_0_FLD_C_CF_UA, (reg32))
#define OVL_L3_Y2R_PARA_YUV_A_0_GET_C_CF_YA(reg32)             REG_FLD_GET(OVL_L3_Y2R_PARA_YUV_A_0_FLD_C_CF_YA, (reg32))

#define OVL_L3_Y2R_PARA_YUV_A_1_GET_C_CF_VA(reg32)             REG_FLD_GET(OVL_L3_Y2R_PARA_YUV_A_1_FLD_C_CF_VA, (reg32))

#define OVL_L3_Y2R_PARA_RGB_A_0_GET_C_CF_GA(reg32)             REG_FLD_GET(OVL_L3_Y2R_PARA_RGB_A_0_FLD_C_CF_GA, (reg32))
#define OVL_L3_Y2R_PARA_RGB_A_0_GET_C_CF_RA(reg32)             REG_FLD_GET(OVL_L3_Y2R_PARA_RGB_A_0_FLD_C_CF_RA, (reg32))

#define OVL_L3_Y2R_PARA_RGB_A_1_GET_C_CF_BA(reg32)             REG_FLD_GET(OVL_L3_Y2R_PARA_RGB_A_1_FLD_C_CF_BA, (reg32))

#define OVL_DEBUG_MON_SEL_GET_DBG_MON_SEL(reg32)               REG_FLD_GET(OVL_DEBUG_MON_SEL_FLD_DBG_MON_SEL, (reg32))

#define OVL_BLD_EXT_GET_EL2_MINUS_BLD(reg32)                   REG_FLD_GET(OVL_BLD_EXT_FLD_EL2_MINUS_BLD, (reg32))
#define OVL_BLD_EXT_GET_EL1_MINUS_BLD(reg32)                   REG_FLD_GET(OVL_BLD_EXT_FLD_EL1_MINUS_BLD, (reg32))
#define OVL_BLD_EXT_GET_EL0_MINUS_BLD(reg32)                   REG_FLD_GET(OVL_BLD_EXT_FLD_EL0_MINUS_BLD, (reg32))
#define OVL_BLD_EXT_GET_LC_MINUS_BLD(reg32)                    REG_FLD_GET(OVL_BLD_EXT_FLD_LC_MINUS_BLD, (reg32))
#define OVL_BLD_EXT_GET_L3_MINUS_BLD(reg32)                    REG_FLD_GET(OVL_BLD_EXT_FLD_L3_MINUS_BLD, (reg32))
#define OVL_BLD_EXT_GET_L2_MINUS_BLD(reg32)                    REG_FLD_GET(OVL_BLD_EXT_FLD_L2_MINUS_BLD, (reg32))
#define OVL_BLD_EXT_GET_L1_MINUS_BLD(reg32)                    REG_FLD_GET(OVL_BLD_EXT_FLD_L1_MINUS_BLD, (reg32))
#define OVL_BLD_EXT_GET_L0_MINUS_BLD(reg32)                    REG_FLD_GET(OVL_BLD_EXT_FLD_L0_MINUS_BLD, (reg32))

#define OVL_RDMA0_MEM_GMC_SETTING2_GET_RDMA0_FORCE_REQ_THRESHOLD(reg32) REG_FLD_GET(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_FORCE_REQ_THRESHOLD, (reg32))
#define OVL_RDMA0_MEM_GMC_SETTING2_GET_RDMA0_REQ_THRESHOLD_ULTRA(reg32) REG_FLD_GET(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_REQ_THRESHOLD_ULTRA, (reg32))
#define OVL_RDMA0_MEM_GMC_SETTING2_GET_RDMA0_REQ_THRESHOLD_PREULTRA(reg32) REG_FLD_GET(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_REQ_THRESHOLD_PREULTRA, (reg32))
#define OVL_RDMA0_MEM_GMC_SETTING2_GET_RDMA0_ISSUE_REQ_THRESHOLD_URG(reg32) REG_FLD_GET(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_ISSUE_REQ_THRESHOLD_URG, (reg32))
#define OVL_RDMA0_MEM_GMC_SETTING2_GET_RDMA0_ISSUE_REQ_THRESHOLD(reg32) REG_FLD_GET(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_ISSUE_REQ_THRESHOLD, (reg32))

#define OVL_RDMA1_MEM_GMC_SETTING2_GET_RDMA1_FORCE_REQ_THRESHOLD(reg32) REG_FLD_GET(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_FORCE_REQ_THRESHOLD, (reg32))
#define OVL_RDMA1_MEM_GMC_SETTING2_GET_RDMA1_REQ_THRESHOLD_ULTRA(reg32) REG_FLD_GET(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_REQ_THRESHOLD_ULTRA, (reg32))
#define OVL_RDMA1_MEM_GMC_SETTING2_GET_RDMA1_REQ_THRESHOLD_PREULTRA(reg32) REG_FLD_GET(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_REQ_THRESHOLD_PREULTRA, (reg32))
#define OVL_RDMA1_MEM_GMC_SETTING2_GET_RDMA1_ISSUE_REQ_THRESHOLD_URG(reg32) REG_FLD_GET(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_ISSUE_REQ_THRESHOLD_URG, (reg32))
#define OVL_RDMA1_MEM_GMC_SETTING2_GET_RDMA1_ISSUE_REQ_THRESHOLD(reg32) REG_FLD_GET(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_ISSUE_REQ_THRESHOLD, (reg32))

#define OVL_RDMA2_MEM_GMC_SETTING2_GET_RDMA2_FORCE_REQ_THRESHOLD(reg32) REG_FLD_GET(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_FORCE_REQ_THRESHOLD, (reg32))
#define OVL_RDMA2_MEM_GMC_SETTING2_GET_RDMA2_REQ_THRESHOLD_ULTRA(reg32) REG_FLD_GET(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_REQ_THRESHOLD_ULTRA, (reg32))
#define OVL_RDMA2_MEM_GMC_SETTING2_GET_RDMA2_REQ_THRESHOLD_PREULTRA(reg32) REG_FLD_GET(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_REQ_THRESHOLD_PREULTRA, (reg32))
#define OVL_RDMA2_MEM_GMC_SETTING2_GET_RDMA2_ISSUE_REQ_THRESHOLD_URG(reg32) REG_FLD_GET(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_ISSUE_REQ_THRESHOLD_URG, (reg32))
#define OVL_RDMA2_MEM_GMC_SETTING2_GET_RDMA2_ISSUE_REQ_THRESHOLD(reg32) REG_FLD_GET(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_ISSUE_REQ_THRESHOLD, (reg32))

#define OVL_RDMA3_MEM_GMC_SETTING2_GET_RDMA3_FORCE_REQ_THRESHOLD(reg32) REG_FLD_GET(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_FORCE_REQ_THRESHOLD, (reg32))
#define OVL_RDMA3_MEM_GMC_SETTING2_GET_RDMA3_REQ_THRESHOLD_ULTRA(reg32) REG_FLD_GET(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_REQ_THRESHOLD_ULTRA, (reg32))
#define OVL_RDMA3_MEM_GMC_SETTING2_GET_RDMA3_REQ_THRESHOLD_PREULTRA(reg32) REG_FLD_GET(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_REQ_THRESHOLD_PREULTRA, (reg32))
#define OVL_RDMA3_MEM_GMC_SETTING2_GET_RDMA3_ISSUE_REQ_THRESHOLD_URG(reg32) REG_FLD_GET(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_ISSUE_REQ_THRESHOLD_URG, (reg32))
#define OVL_RDMA3_MEM_GMC_SETTING2_GET_RDMA3_ISSUE_REQ_THRESHOLD(reg32) REG_FLD_GET(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_ISSUE_REQ_THRESHOLD, (reg32))

#define OVL_RDMA_BURST_CON0_GET_BURST_128B_BOUND(reg32)        REG_FLD_GET(OVL_RDMA_BURST_CON0_FLD_BURST_128B_BOUND, (reg32))
#define OVL_RDMA_BURST_CON0_GET_BURST15A_32B(reg32)            REG_FLD_GET(OVL_RDMA_BURST_CON0_FLD_BURST15A_32B, (reg32))
#define OVL_RDMA_BURST_CON0_GET_BURST14A_32B(reg32)            REG_FLD_GET(OVL_RDMA_BURST_CON0_FLD_BURST14A_32B, (reg32))
#define OVL_RDMA_BURST_CON0_GET_BURST13A_32B(reg32)            REG_FLD_GET(OVL_RDMA_BURST_CON0_FLD_BURST13A_32B, (reg32))
#define OVL_RDMA_BURST_CON0_GET_BURST12A_32B(reg32)            REG_FLD_GET(OVL_RDMA_BURST_CON0_FLD_BURST12A_32B, (reg32))
#define OVL_RDMA_BURST_CON0_GET_BURST11A_32B(reg32)            REG_FLD_GET(OVL_RDMA_BURST_CON0_FLD_BURST11A_32B, (reg32))
#define OVL_RDMA_BURST_CON0_GET_BURST10A_32B(reg32)            REG_FLD_GET(OVL_RDMA_BURST_CON0_FLD_BURST10A_32B, (reg32))
#define OVL_RDMA_BURST_CON0_GET_BURST9A_32B(reg32)             REG_FLD_GET(OVL_RDMA_BURST_CON0_FLD_BURST9A_32B, (reg32))

#define OVL_RDMA_BURST_CON1_GET_BURST15A_N32B(reg32)           REG_FLD_GET(OVL_RDMA_BURST_CON1_FLD_BURST15A_N32B, (reg32))
#define OVL_RDMA_BURST_CON1_GET_BURST14A_N32B(reg32)           REG_FLD_GET(OVL_RDMA_BURST_CON1_FLD_BURST14A_N32B, (reg32))
#define OVL_RDMA_BURST_CON1_GET_BURST13A_N32B(reg32)           REG_FLD_GET(OVL_RDMA_BURST_CON1_FLD_BURST13A_N32B, (reg32))
#define OVL_RDMA_BURST_CON1_GET_BURST12A_N32B(reg32)           REG_FLD_GET(OVL_RDMA_BURST_CON1_FLD_BURST12A_N32B, (reg32))
#define OVL_RDMA_BURST_CON1_GET_BURST11A_N32B(reg32)           REG_FLD_GET(OVL_RDMA_BURST_CON1_FLD_BURST11A_N32B, (reg32))
#define OVL_RDMA_BURST_CON1_GET_BURST10A_N32B(reg32)           REG_FLD_GET(OVL_RDMA_BURST_CON1_FLD_BURST10A_N32B, (reg32))
#define OVL_RDMA_BURST_CON1_GET_BURST9A_N32B(reg32)            REG_FLD_GET(OVL_RDMA_BURST_CON1_FLD_BURST9A_N32B, (reg32))

#define OVL_RDMA_GREQ_NUM_GET_IOBUF_FLUSH_ULTRA(reg32)         REG_FLD_GET(OVL_RDMA_GREQ_NUM_FLD_IOBUF_FLUSH_ULTRA, (reg32))
#define OVL_RDMA_GREQ_NUM_GET_IOBUF_FLUSH_PREULTRA(reg32)      REG_FLD_GET(OVL_RDMA_GREQ_NUM_FLD_IOBUF_FLUSH_PREULTRA, (reg32))
#define OVL_RDMA_GREQ_NUM_GET_GRP_BRK_STOP(reg32)              REG_FLD_GET(OVL_RDMA_GREQ_NUM_FLD_GRP_BRK_STOP, (reg32))
#define OVL_RDMA_GREQ_NUM_GET_GRP_END_STOP(reg32)              REG_FLD_GET(OVL_RDMA_GREQ_NUM_FLD_GRP_END_STOP, (reg32))
#define OVL_RDMA_GREQ_NUM_GET_GREQ_STOP_EN(reg32)              REG_FLD_GET(OVL_RDMA_GREQ_NUM_FLD_GREQ_STOP_EN, (reg32))
#define OVL_RDMA_GREQ_NUM_GET_GREQ_DIS_CNT(reg32)              REG_FLD_GET(OVL_RDMA_GREQ_NUM_FLD_GREQ_DIS_CNT, (reg32))
#define OVL_RDMA_GREQ_NUM_GET_OSTD_GREQ_NUM(reg32)             REG_FLD_GET(OVL_RDMA_GREQ_NUM_FLD_OSTD_GREQ_NUM, (reg32))
#define OVL_RDMA_GREQ_NUM_GET_LAYER3_GREQ_NUM(reg32)           REG_FLD_GET(OVL_RDMA_GREQ_NUM_FLD_LAYER3_GREQ_NUM, (reg32))
#define OVL_RDMA_GREQ_NUM_GET_LAYER2_GREQ_NUM(reg32)           REG_FLD_GET(OVL_RDMA_GREQ_NUM_FLD_LAYER2_GREQ_NUM, (reg32))
#define OVL_RDMA_GREQ_NUM_GET_LAYER1_GREQ_NUM(reg32)           REG_FLD_GET(OVL_RDMA_GREQ_NUM_FLD_LAYER1_GREQ_NUM, (reg32))
#define OVL_RDMA_GREQ_NUM_GET_LAYER0_GREQ_NUM(reg32)           REG_FLD_GET(OVL_RDMA_GREQ_NUM_FLD_LAYER0_GREQ_NUM, (reg32))

#define OVL_RDMA_GREQ_URG_NUM_GET_GREQ_NUM_SHT(reg32)          REG_FLD_GET(OVL_RDMA_GREQ_URG_NUM_FLD_GREQ_NUM_SHT, (reg32))
#define OVL_RDMA_GREQ_URG_NUM_GET_GREQ_NUM_SHT_VAL(reg32)      REG_FLD_GET(OVL_RDMA_GREQ_URG_NUM_FLD_GREQ_NUM_SHT_VAL, (reg32))
#define OVL_RDMA_GREQ_URG_NUM_GET_ARG_URG_BIAS(reg32)          REG_FLD_GET(OVL_RDMA_GREQ_URG_NUM_FLD_ARG_URG_BIAS, (reg32))
#define OVL_RDMA_GREQ_URG_NUM_GET_ARG_GREQ_URG_TH(reg32)       REG_FLD_GET(OVL_RDMA_GREQ_URG_NUM_FLD_ARG_GREQ_URG_TH, (reg32))
#define OVL_RDMA_GREQ_URG_NUM_GET_LAYER3_GREQ_URG_NUM(reg32)   REG_FLD_GET(OVL_RDMA_GREQ_URG_NUM_FLD_LAYER3_GREQ_URG_NUM, (reg32))
#define OVL_RDMA_GREQ_URG_NUM_GET_LAYER2_GREQ_URG_NUM(reg32)   REG_FLD_GET(OVL_RDMA_GREQ_URG_NUM_FLD_LAYER2_GREQ_URG_NUM, (reg32))
#define OVL_RDMA_GREQ_URG_NUM_GET_LAYER1_GREQ_URG_NUM(reg32)   REG_FLD_GET(OVL_RDMA_GREQ_URG_NUM_FLD_LAYER1_GREQ_URG_NUM, (reg32))
#define OVL_RDMA_GREQ_URG_NUM_GET_LAYER0_GREQ_URG_NUM(reg32)   REG_FLD_GET(OVL_RDMA_GREQ_URG_NUM_FLD_LAYER0_GREQ_URG_NUM, (reg32))

#define OVL_DUMMY_REG_GET_OVERLAY_DUMMY(reg32)                 REG_FLD_GET(OVL_DUMMY_REG_FLD_OVERLAY_DUMMY, (reg32))

#define OVL_GDRDY_PRD_GET_GDRDY_PRD(reg32)                     REG_FLD_GET(OVL_GDRDY_PRD_FLD_GDRDY_PRD, (reg32))

#define OVL_RDMA_ULTRA_SRC_GET_ULTRA_RDMA_SRC(reg32)           REG_FLD_GET(OVL_RDMA_ULTRA_SRC_FLD_ULTRA_RDMA_SRC, (reg32))
#define OVL_RDMA_ULTRA_SRC_GET_ULTRA_ROI_END_SRC(reg32)        REG_FLD_GET(OVL_RDMA_ULTRA_SRC_FLD_ULTRA_ROI_END_SRC, (reg32))
#define OVL_RDMA_ULTRA_SRC_GET_ULTRA_SMI_SRC(reg32)            REG_FLD_GET(OVL_RDMA_ULTRA_SRC_FLD_ULTRA_SMI_SRC, (reg32))
#define OVL_RDMA_ULTRA_SRC_GET_ULTRA_BUF_SRC(reg32)            REG_FLD_GET(OVL_RDMA_ULTRA_SRC_FLD_ULTRA_BUF_SRC, (reg32))
#define OVL_RDMA_ULTRA_SRC_GET_PREULTRA_RDMA_SRC(reg32)        REG_FLD_GET(OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_RDMA_SRC, (reg32))
#define OVL_RDMA_ULTRA_SRC_GET_PREULTRA_ROI_END_SRC(reg32)     REG_FLD_GET(OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_ROI_END_SRC, (reg32))
#define OVL_RDMA_ULTRA_SRC_GET_PREULTRA_SMI_SRC(reg32)         REG_FLD_GET(OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_SMI_SRC, (reg32))
#define OVL_RDMA_ULTRA_SRC_GET_PREULTRA_BUF_SRC(reg32)         REG_FLD_GET(OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_BUF_SRC, (reg32))

#define OVL_RDMA0_BUF_LOW_TH_GET_RDMA0_PREULTRA_LOW_TH(reg32)  REG_FLD_GET(OVL_RDMA0_BUF_LOW_TH_FLD_RDMA0_PREULTRA_LOW_TH, (reg32))
#define OVL_RDMA0_BUF_LOW_TH_GET_RDMA0_ULTRA_LOW_TH(reg32)     REG_FLD_GET(OVL_RDMA0_BUF_LOW_TH_FLD_RDMA0_ULTRA_LOW_TH, (reg32))

#define OVL_RDMA1_BUF_LOW_TH_GET_RDMA1_PREULTRA_LOW_TH(reg32)  REG_FLD_GET(OVL_RDMA1_BUF_LOW_TH_FLD_RDMA1_PREULTRA_LOW_TH, (reg32))
#define OVL_RDMA1_BUF_LOW_TH_GET_RDMA1_ULTRA_LOW_TH(reg32)     REG_FLD_GET(OVL_RDMA1_BUF_LOW_TH_FLD_RDMA1_ULTRA_LOW_TH, (reg32))

#define OVL_RDMA2_BUF_LOW_TH_GET_RDMA2_PREULTRA_LOW_TH(reg32)  REG_FLD_GET(OVL_RDMA2_BUF_LOW_TH_FLD_RDMA2_PREULTRA_LOW_TH, (reg32))
#define OVL_RDMA2_BUF_LOW_TH_GET_RDMA2_ULTRA_LOW_TH(reg32)     REG_FLD_GET(OVL_RDMA2_BUF_LOW_TH_FLD_RDMA2_ULTRA_LOW_TH, (reg32))

#define OVL_RDMA3_BUF_LOW_TH_GET_RDMA3_PREULTRA_LOW_TH(reg32)  REG_FLD_GET(OVL_RDMA3_BUF_LOW_TH_FLD_RDMA3_PREULTRA_LOW_TH, (reg32))
#define OVL_RDMA3_BUF_LOW_TH_GET_RDMA3_ULTRA_LOW_TH(reg32)     REG_FLD_GET(OVL_RDMA3_BUF_LOW_TH_FLD_RDMA3_ULTRA_LOW_TH, (reg32))

#define OVL_RDMA0_BUF_HIGH_TH_GET_RDMA0_PREULTRA_HIGH_DIS(reg32) REG_FLD_GET(OVL_RDMA0_BUF_HIGH_TH_FLD_RDMA0_PREULTRA_HIGH_DIS, (reg32))
#define OVL_RDMA0_BUF_HIGH_TH_GET_RDMA0_PREULTRA_HIGH_TH(reg32) REG_FLD_GET(OVL_RDMA0_BUF_HIGH_TH_FLD_RDMA0_PREULTRA_HIGH_TH, (reg32))

#define OVL_RDMA1_BUF_HIGH_TH_GET_RDMA1_PREULTRA_HIGH_DIS(reg32) REG_FLD_GET(OVL_RDMA1_BUF_HIGH_TH_FLD_RDMA1_PREULTRA_HIGH_DIS, (reg32))
#define OVL_RDMA1_BUF_HIGH_TH_GET_RDMA1_PREULTRA_HIGH_TH(reg32) REG_FLD_GET(OVL_RDMA1_BUF_HIGH_TH_FLD_RDMA1_PREULTRA_HIGH_TH, (reg32))

#define OVL_RDMA2_BUF_HIGH_TH_GET_RDMA2_PREULTRA_HIGH_DIS(reg32) REG_FLD_GET(OVL_RDMA2_BUF_HIGH_TH_FLD_RDMA2_PREULTRA_HIGH_DIS, (reg32))
#define OVL_RDMA2_BUF_HIGH_TH_GET_RDMA2_PREULTRA_HIGH_TH(reg32) REG_FLD_GET(OVL_RDMA2_BUF_HIGH_TH_FLD_RDMA2_PREULTRA_HIGH_TH, (reg32))

#define OVL_RDMA3_BUF_HIGH_TH_GET_RDMA3_PREULTRA_HIGH_DIS(reg32) REG_FLD_GET(OVL_RDMA3_BUF_HIGH_TH_FLD_RDMA3_PREULTRA_HIGH_DIS, (reg32))
#define OVL_RDMA3_BUF_HIGH_TH_GET_RDMA3_PREULTRA_HIGH_TH(reg32) REG_FLD_GET(OVL_RDMA3_BUF_HIGH_TH_FLD_RDMA3_PREULTRA_HIGH_TH, (reg32))

#define OVL_SMI_DBG_GET_SMI_FSM(reg32)                         REG_FLD_GET(OVL_SMI_DBG_FLD_SMI_FSM, (reg32))

#define OVL_GREQ_LAYER_CNT_GET_LAYER3_GREQ_CNT(reg32)          REG_FLD_GET(OVL_GREQ_LAYER_CNT_FLD_LAYER3_GREQ_CNT, (reg32))
#define OVL_GREQ_LAYER_CNT_GET_LAYER2_GREQ_CNT(reg32)          REG_FLD_GET(OVL_GREQ_LAYER_CNT_FLD_LAYER2_GREQ_CNT, (reg32))
#define OVL_GREQ_LAYER_CNT_GET_LAYER1_GREQ_CNT(reg32)          REG_FLD_GET(OVL_GREQ_LAYER_CNT_FLD_LAYER1_GREQ_CNT, (reg32))
#define OVL_GREQ_LAYER_CNT_GET_LAYER0_GREQ_CNT(reg32)          REG_FLD_GET(OVL_GREQ_LAYER_CNT_FLD_LAYER0_GREQ_CNT, (reg32))

#define OVL_GDRDY_PRD_NUM_GET_GDRDY_PRD_NUM(reg32)             REG_FLD_GET(OVL_GDRDY_PRD_NUM_FLD_GDRDY_PRD_NUM, (reg32))

#define OVL_FLOW_CTRL_DBG_GET_OVL_UPD_REG(reg32)               REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_OVL_UPD_REG, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_REG_UPDATE(reg32)                REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_REG_UPDATE, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_OVL_CLR(reg32)                   REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_OVL_CLR, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_OVL_START(reg32)                 REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_OVL_START, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_OVL_RUNNING(reg32)               REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_OVL_RUNNING, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_FRAME_DONE(reg32)                REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_FRAME_DONE, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_FRAME_UNDERRUN(reg32)            REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_FRAME_UNDERRUN, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_FRAME_SWRST_DONE(reg32)          REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_FRAME_SWRST_DONE, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_FRAME_HWRST_DONE(reg32)          REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_FRAME_HWRST_DONE, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_TRIG(reg32)                      REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_TRIG, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_RST(reg32)                       REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_RST, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_RDMA0_IDLE(reg32)                REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_RDMA0_IDLE, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_RDMA1_IDLE(reg32)                REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_RDMA1_IDLE, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_RDMA2_IDLE(reg32)                REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_RDMA2_IDLE, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_RDMA3_IDLE(reg32)                REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_RDMA3_IDLE, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_OUT_IDLE(reg32)                  REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_OUT_IDLE, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_OVL_OUT_READY(reg32)             REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_OVL_OUT_READY, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_OVL_OUT_VALID(reg32)             REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_OVL_OUT_VALID, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_BLEND_IDLE(reg32)                REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_BLEND_IDLE, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_ADDCON_IDLE(reg32)               REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_ADDCON_IDLE, (reg32))
#define OVL_FLOW_CTRL_DBG_GET_FSM_STATE(reg32)                 REG_FLD_GET(OVL_FLOW_CTRL_DBG_FLD_FSM_STATE, (reg32))

#define OVL_ADDCON_DBG_GET_L3_WIN_HIT(reg32)                   REG_FLD_GET(OVL_ADDCON_DBG_FLD_L3_WIN_HIT, (reg32))
#define OVL_ADDCON_DBG_GET_L2_WIN_HIT(reg32)                   REG_FLD_GET(OVL_ADDCON_DBG_FLD_L2_WIN_HIT, (reg32))
#define OVL_ADDCON_DBG_GET_ROI_Y(reg32)                        REG_FLD_GET(OVL_ADDCON_DBG_FLD_ROI_Y, (reg32))
#define OVL_ADDCON_DBG_GET_L1_WIN_HIT(reg32)                   REG_FLD_GET(OVL_ADDCON_DBG_FLD_L1_WIN_HIT, (reg32))
#define OVL_ADDCON_DBG_GET_L0_WIN_HIT(reg32)                   REG_FLD_GET(OVL_ADDCON_DBG_FLD_L0_WIN_HIT, (reg32))
#define OVL_ADDCON_DBG_GET_ROI_X(reg32)                        REG_FLD_GET(OVL_ADDCON_DBG_FLD_ROI_X, (reg32))

#define OVL_RDMA0_DBG_GET_SMI_GREQ(reg32)                      REG_FLD_GET(OVL_RDMA0_DBG_FLD_SMI_GREQ, (reg32))
#define OVL_RDMA0_DBG_GET_RDMA0_SMI_BUSY(reg32)                REG_FLD_GET(OVL_RDMA0_DBG_FLD_RDMA0_SMI_BUSY, (reg32))
#define OVL_RDMA0_DBG_GET_RDMA0_OUT_VALID(reg32)               REG_FLD_GET(OVL_RDMA0_DBG_FLD_RDMA0_OUT_VALID, (reg32))
#define OVL_RDMA0_DBG_GET_RDMA0_OUT_READY(reg32)               REG_FLD_GET(OVL_RDMA0_DBG_FLD_RDMA0_OUT_READY, (reg32))
#define OVL_RDMA0_DBG_GET_RDMA0_OUT_DATA(reg32)                REG_FLD_GET(OVL_RDMA0_DBG_FLD_RDMA0_OUT_DATA, (reg32))
#define OVL_RDMA0_DBG_GET_RDMA0_LAYER_GREQ(reg32)              REG_FLD_GET(OVL_RDMA0_DBG_FLD_RDMA0_LAYER_GREQ, (reg32))
#define OVL_RDMA0_DBG_GET_RDMA0_WRAM_RST_CS(reg32)             REG_FLD_GET(OVL_RDMA0_DBG_FLD_RDMA0_WRAM_RST_CS, (reg32))

#define OVL_RDMA1_DBG_GET_SMI_GREQ(reg32)                      REG_FLD_GET(OVL_RDMA1_DBG_FLD_SMI_GREQ, (reg32))
#define OVL_RDMA1_DBG_GET_RDMA1_SMI_BUSY(reg32)                REG_FLD_GET(OVL_RDMA1_DBG_FLD_RDMA1_SMI_BUSY, (reg32))
#define OVL_RDMA1_DBG_GET_RDMA1_OUT_VALID(reg32)               REG_FLD_GET(OVL_RDMA1_DBG_FLD_RDMA1_OUT_VALID, (reg32))
#define OVL_RDMA1_DBG_GET_RDMA1_OUT_READY(reg32)               REG_FLD_GET(OVL_RDMA1_DBG_FLD_RDMA1_OUT_READY, (reg32))
#define OVL_RDMA1_DBG_GET_RDMA1_OUT_DATA(reg32)                REG_FLD_GET(OVL_RDMA1_DBG_FLD_RDMA1_OUT_DATA, (reg32))
#define OVL_RDMA1_DBG_GET_RDMA1_LAYER_GREQ(reg32)              REG_FLD_GET(OVL_RDMA1_DBG_FLD_RDMA1_LAYER_GREQ, (reg32))
#define OVL_RDMA1_DBG_GET_RDMA1_WRAM_RST_CS(reg32)             REG_FLD_GET(OVL_RDMA1_DBG_FLD_RDMA1_WRAM_RST_CS, (reg32))

#define OVL_RDMA2_DBG_GET_SMI_GREQ(reg32)                      REG_FLD_GET(OVL_RDMA2_DBG_FLD_SMI_GREQ, (reg32))
#define OVL_RDMA2_DBG_GET_RDMA2_SMI_BUSY(reg32)                REG_FLD_GET(OVL_RDMA2_DBG_FLD_RDMA2_SMI_BUSY, (reg32))
#define OVL_RDMA2_DBG_GET_RDMA2_OUT_VALID(reg32)               REG_FLD_GET(OVL_RDMA2_DBG_FLD_RDMA2_OUT_VALID, (reg32))
#define OVL_RDMA2_DBG_GET_RDMA2_OUT_READY(reg32)               REG_FLD_GET(OVL_RDMA2_DBG_FLD_RDMA2_OUT_READY, (reg32))
#define OVL_RDMA2_DBG_GET_RDMA2_OUT_DATA(reg32)                REG_FLD_GET(OVL_RDMA2_DBG_FLD_RDMA2_OUT_DATA, (reg32))
#define OVL_RDMA2_DBG_GET_RDMA2_LAYER_GREQ(reg32)              REG_FLD_GET(OVL_RDMA2_DBG_FLD_RDMA2_LAYER_GREQ, (reg32))
#define OVL_RDMA2_DBG_GET_RDMA2_WRAM_RST_CS(reg32)             REG_FLD_GET(OVL_RDMA2_DBG_FLD_RDMA2_WRAM_RST_CS, (reg32))

#define OVL_RDMA3_DBG_GET_SMI_GREQ(reg32)                      REG_FLD_GET(OVL_RDMA3_DBG_FLD_SMI_GREQ, (reg32))
#define OVL_RDMA3_DBG_GET_RDMA3_SMI_BUSY(reg32)                REG_FLD_GET(OVL_RDMA3_DBG_FLD_RDMA3_SMI_BUSY, (reg32))
#define OVL_RDMA3_DBG_GET_RDMA3_OUT_VALID(reg32)               REG_FLD_GET(OVL_RDMA3_DBG_FLD_RDMA3_OUT_VALID, (reg32))
#define OVL_RDMA3_DBG_GET_RDMA3_OUT_READY(reg32)               REG_FLD_GET(OVL_RDMA3_DBG_FLD_RDMA3_OUT_READY, (reg32))
#define OVL_RDMA3_DBG_GET_RDMA3_OUT_DATA(reg32)                REG_FLD_GET(OVL_RDMA3_DBG_FLD_RDMA3_OUT_DATA, (reg32))
#define OVL_RDMA3_DBG_GET_RDMA3_LAYER_GREQ(reg32)              REG_FLD_GET(OVL_RDMA3_DBG_FLD_RDMA3_LAYER_GREQ, (reg32))
#define OVL_RDMA3_DBG_GET_RDMA3_WRAM_RST_CS(reg32)             REG_FLD_GET(OVL_RDMA3_DBG_FLD_RDMA3_WRAM_RST_CS, (reg32))

#define OVL_L0_CLR_GET_ALPHA(reg32)                            REG_FLD_GET(OVL_L0_CLR_FLD_ALPHA, (reg32))
#define OVL_L0_CLR_GET_RED(reg32)                              REG_FLD_GET(OVL_L0_CLR_FLD_RED, (reg32))
#define OVL_L0_CLR_GET_GREEN(reg32)                            REG_FLD_GET(OVL_L0_CLR_FLD_GREEN, (reg32))
#define OVL_L0_CLR_GET_BLUE(reg32)                             REG_FLD_GET(OVL_L0_CLR_FLD_BLUE, (reg32))

#define OVL_L1_CLR_GET_ALPHA(reg32)                            REG_FLD_GET(OVL_L1_CLR_FLD_ALPHA, (reg32))
#define OVL_L1_CLR_GET_RED(reg32)                              REG_FLD_GET(OVL_L1_CLR_FLD_RED, (reg32))
#define OVL_L1_CLR_GET_GREEN(reg32)                            REG_FLD_GET(OVL_L1_CLR_FLD_GREEN, (reg32))
#define OVL_L1_CLR_GET_BLUE(reg32)                             REG_FLD_GET(OVL_L1_CLR_FLD_BLUE, (reg32))

#define OVL_L2_CLR_GET_ALPHA(reg32)                            REG_FLD_GET(OVL_L2_CLR_FLD_ALPHA, (reg32))
#define OVL_L2_CLR_GET_RED(reg32)                              REG_FLD_GET(OVL_L2_CLR_FLD_RED, (reg32))
#define OVL_L2_CLR_GET_GREEN(reg32)                            REG_FLD_GET(OVL_L2_CLR_FLD_GREEN, (reg32))
#define OVL_L2_CLR_GET_BLUE(reg32)                             REG_FLD_GET(OVL_L2_CLR_FLD_BLUE, (reg32))

#define OVL_L3_CLR_GET_ALPHA(reg32)                            REG_FLD_GET(OVL_L3_CLR_FLD_ALPHA, (reg32))
#define OVL_L3_CLR_GET_RED(reg32)                              REG_FLD_GET(OVL_L3_CLR_FLD_RED, (reg32))
#define OVL_L3_CLR_GET_GREEN(reg32)                            REG_FLD_GET(OVL_L3_CLR_FLD_GREEN, (reg32))
#define OVL_L3_CLR_GET_BLUE(reg32)                             REG_FLD_GET(OVL_L3_CLR_FLD_BLUE, (reg32))

#define OVL_LC_CLR_GET_ALPHA(reg32)                            REG_FLD_GET(OVL_LC_CLR_FLD_ALPHA, (reg32))
#define OVL_LC_CLR_GET_RED(reg32)                              REG_FLD_GET(OVL_LC_CLR_FLD_RED, (reg32))
#define OVL_LC_CLR_GET_GREEN(reg32)                            REG_FLD_GET(OVL_LC_CLR_FLD_GREEN, (reg32))
#define OVL_LC_CLR_GET_BLUE(reg32)                             REG_FLD_GET(OVL_LC_CLR_FLD_BLUE, (reg32))

#define OVL_CRC_GET_CRC_RDY(reg32)                             REG_FLD_GET(OVL_CRC_FLD_CRC_RDY, (reg32))
#define OVL_CRC_GET_CRC_OUT(reg32)                             REG_FLD_GET(OVL_CRC_FLD_CRC_OUT, (reg32))

#define OVL_LC_CON_GET_DSTKEY_EN(reg32)                        REG_FLD_GET(OVL_LC_CON_FLD_DSTKEY_EN, (reg32))
#define OVL_LC_CON_GET_SRCKEY_EN(reg32)                        REG_FLD_GET(OVL_LC_CON_FLD_SRCKEY_EN, (reg32))
#define OVL_LC_CON_GET_LAYER_SRC(reg32)                        REG_FLD_GET(OVL_LC_CON_FLD_LAYER_SRC, (reg32))
#define OVL_LC_CON_GET_R_FIRST(reg32)                          REG_FLD_GET(OVL_LC_CON_FLD_R_FIRST, (reg32))
#define OVL_LC_CON_GET_LANDSCAPE(reg32)                        REG_FLD_GET(OVL_LC_CON_FLD_LANDSCAPE, (reg32))
#define OVL_LC_CON_GET_EN_3D(reg32)                            REG_FLD_GET(OVL_LC_CON_FLD_EN_3D, (reg32))
#define OVL_LC_CON_GET_ALPHA_EN(reg32)                         REG_FLD_GET(OVL_LC_CON_FLD_ALPHA_EN, (reg32))
#define OVL_LC_CON_GET_ALPHA(reg32)                            REG_FLD_GET(OVL_LC_CON_FLD_ALPHA, (reg32))

#define OVL_LC_SRCKEY_GET_SRCKEY(reg32)                        REG_FLD_GET(OVL_LC_SRCKEY_FLD_SRCKEY, (reg32))

#define OVL_LC_SRC_SIZE_GET_LC_SRC_H(reg32)                    REG_FLD_GET(OVL_LC_SRC_SIZE_FLD_LC_SRC_H, (reg32))
#define OVL_LC_SRC_SIZE_GET_LC_SRC_W(reg32)                    REG_FLD_GET(OVL_LC_SRC_SIZE_FLD_LC_SRC_W, (reg32))

#define OVL_LC_OFFSET_GET_LC_YOFF(reg32)                       REG_FLD_GET(OVL_LC_OFFSET_FLD_LC_YOFF, (reg32))
#define OVL_LC_OFFSET_GET_LC_XOFF(reg32)                       REG_FLD_GET(OVL_LC_OFFSET_FLD_LC_XOFF, (reg32))

#define OVL_LC_SRC_SEL_GET_SURFL_EN(reg32)                     REG_FLD_GET(OVL_LC_SRC_SEL_FLD_SURFL_EN, (reg32))
#define OVL_LC_SRC_SEL_GET_LC_BLEND_RND_SHT(reg32)             REG_FLD_GET(OVL_LC_SRC_SEL_FLD_LC_BLEND_RND_SHT, (reg32))
#define OVL_LC_SRC_SEL_GET_LC_SRGB_SEL_EXT2(reg32)             REG_FLD_GET(OVL_LC_SRC_SEL_FLD_LC_SRGB_SEL_EXT2, (reg32))
#define OVL_LC_SRC_SEL_GET_LC_CONST_BLD(reg32)                 REG_FLD_GET(OVL_LC_SRC_SEL_FLD_LC_CONST_BLD, (reg32))
#define OVL_LC_SRC_SEL_GET_LC_DRGB_SEL_EXT(reg32)              REG_FLD_GET(OVL_LC_SRC_SEL_FLD_LC_DRGB_SEL_EXT, (reg32))
#define OVL_LC_SRC_SEL_GET_LC_DA_SEL_EXT(reg32)                REG_FLD_GET(OVL_LC_SRC_SEL_FLD_LC_DA_SEL_EXT, (reg32))
#define OVL_LC_SRC_SEL_GET_LC_SRGB_SEL_EXT(reg32)              REG_FLD_GET(OVL_LC_SRC_SEL_FLD_LC_SRGB_SEL_EXT, (reg32))
#define OVL_LC_SRC_SEL_GET_LC_SA_SEL_EXT(reg32)                REG_FLD_GET(OVL_LC_SRC_SEL_FLD_LC_SA_SEL_EXT, (reg32))
#define OVL_LC_SRC_SEL_GET_LC_DRGB_SEL(reg32)                  REG_FLD_GET(OVL_LC_SRC_SEL_FLD_LC_DRGB_SEL, (reg32))
#define OVL_LC_SRC_SEL_GET_LC_DA_SEL(reg32)                    REG_FLD_GET(OVL_LC_SRC_SEL_FLD_LC_DA_SEL, (reg32))
#define OVL_LC_SRC_SEL_GET_LC_SRGB_SEL(reg32)                  REG_FLD_GET(OVL_LC_SRC_SEL_FLD_LC_SRGB_SEL, (reg32))
#define OVL_LC_SRC_SEL_GET_LC_SA_SEL(reg32)                    REG_FLD_GET(OVL_LC_SRC_SEL_FLD_LC_SA_SEL, (reg32))
#define OVL_LC_SRC_SEL_GET_CONST_LAYER_SEL(reg32)              REG_FLD_GET(OVL_LC_SRC_SEL_FLD_CONST_LAYER_SEL, (reg32))

#define OVL_BANK_CON_GET_OVL_BANK_CON(reg32)                   REG_FLD_GET(OVL_BANK_CON_FLD_OVL_BANK_CON, (reg32))

#define OVL_FUNC_DCM0_GET_OVL_FUNC_DCM0(reg32)                 REG_FLD_GET(OVL_FUNC_DCM0_FLD_OVL_FUNC_DCM0, (reg32))

#define OVL_FUNC_DCM1_GET_OVL_FUNC_DCM1(reg32)                 REG_FLD_GET(OVL_FUNC_DCM1_FLD_OVL_FUNC_DCM1, (reg32))

#define OVL_DVFS_L0_ROI_GET_L0_DVFS_ROI_BB(reg32)              REG_FLD_GET(OVL_DVFS_L0_ROI_FLD_L0_DVFS_ROI_BB, (reg32))
#define OVL_DVFS_L0_ROI_GET_L0_DVFS_ROI_TB(reg32)              REG_FLD_GET(OVL_DVFS_L0_ROI_FLD_L0_DVFS_ROI_TB, (reg32))

#define OVL_DVFS_L1_ROI_GET_L1_DVFS_ROI_BB(reg32)              REG_FLD_GET(OVL_DVFS_L1_ROI_FLD_L1_DVFS_ROI_BB, (reg32))
#define OVL_DVFS_L1_ROI_GET_L1_DVFS_ROI_TB(reg32)              REG_FLD_GET(OVL_DVFS_L1_ROI_FLD_L1_DVFS_ROI_TB, (reg32))

#define OVL_DVFS_L2_ROI_GET_L2_DVFS_ROI_BB(reg32)              REG_FLD_GET(OVL_DVFS_L2_ROI_FLD_L2_DVFS_ROI_BB, (reg32))
#define OVL_DVFS_L2_ROI_GET_L2_DVFS_ROI_TB(reg32)              REG_FLD_GET(OVL_DVFS_L2_ROI_FLD_L2_DVFS_ROI_TB, (reg32))

#define OVL_DVFS_L3_ROI_GET_L3_DVFS_ROI_BB(reg32)              REG_FLD_GET(OVL_DVFS_L3_ROI_FLD_L3_DVFS_ROI_BB, (reg32))
#define OVL_DVFS_L3_ROI_GET_L3_DVFS_ROI_TB(reg32)              REG_FLD_GET(OVL_DVFS_L3_ROI_FLD_L3_DVFS_ROI_TB, (reg32))

#define OVL_DVFS_EL0_ROI_GET_EL0_DVFS_ROI_BB(reg32)            REG_FLD_GET(OVL_DVFS_EL0_ROI_FLD_EL0_DVFS_ROI_BB, (reg32))
#define OVL_DVFS_EL0_ROI_GET_EL0_DVFS_ROI_TB(reg32)            REG_FLD_GET(OVL_DVFS_EL0_ROI_FLD_EL0_DVFS_ROI_TB, (reg32))

#define OVL_DVFS_EL1_ROI_GET_EL1_DVFS_ROI_BB(reg32)            REG_FLD_GET(OVL_DVFS_EL1_ROI_FLD_EL1_DVFS_ROI_BB, (reg32))
#define OVL_DVFS_EL1_ROI_GET_EL1_DVFS_ROI_TB(reg32)            REG_FLD_GET(OVL_DVFS_EL1_ROI_FLD_EL1_DVFS_ROI_TB, (reg32))

#define OVL_DVFS_EL2_ROI_GET_EL2_DVFS_ROI_BB(reg32)            REG_FLD_GET(OVL_DVFS_EL2_ROI_FLD_EL2_DVFS_ROI_BB, (reg32))
#define OVL_DVFS_EL2_ROI_GET_EL2_DVFS_ROI_TB(reg32)            REG_FLD_GET(OVL_DVFS_EL2_ROI_FLD_EL2_DVFS_ROI_TB, (reg32))

#define OVL_DATAPATH_EXT_CON_GET_EL2_LAYER_SEL(reg32)          REG_FLD_GET(OVL_DATAPATH_EXT_CON_FLD_EL2_LAYER_SEL, (reg32))
#define OVL_DATAPATH_EXT_CON_GET_EL1_LAYER_SEL(reg32)          REG_FLD_GET(OVL_DATAPATH_EXT_CON_FLD_EL1_LAYER_SEL, (reg32))
#define OVL_DATAPATH_EXT_CON_GET_EL0_LAYER_SEL(reg32)          REG_FLD_GET(OVL_DATAPATH_EXT_CON_FLD_EL0_LAYER_SEL, (reg32))
#define OVL_DATAPATH_EXT_CON_GET_EL2_GPU_MODE(reg32)           REG_FLD_GET(OVL_DATAPATH_EXT_CON_FLD_EL2_GPU_MODE, (reg32))
#define OVL_DATAPATH_EXT_CON_GET_EL1_GPU_MODE(reg32)           REG_FLD_GET(OVL_DATAPATH_EXT_CON_FLD_EL1_GPU_MODE, (reg32))
#define OVL_DATAPATH_EXT_CON_GET_EL0_GPU_MODE(reg32)           REG_FLD_GET(OVL_DATAPATH_EXT_CON_FLD_EL0_GPU_MODE, (reg32))
#define OVL_DATAPATH_EXT_CON_GET_EL2_EN(reg32)                 REG_FLD_GET(OVL_DATAPATH_EXT_CON_FLD_EL2_EN, (reg32))
#define OVL_DATAPATH_EXT_CON_GET_EL1_EN(reg32)                 REG_FLD_GET(OVL_DATAPATH_EXT_CON_FLD_EL1_EN, (reg32))
#define OVL_DATAPATH_EXT_CON_GET_EL0_EN(reg32)                 REG_FLD_GET(OVL_DATAPATH_EXT_CON_FLD_EL0_EN, (reg32))

#define OVL_EL0_CON_GET_DSTKEY_EN(reg32)                       REG_FLD_GET(OVL_EL0_CON_FLD_DSTKEY_EN, (reg32))
#define OVL_EL0_CON_GET_SRCKEY_EN(reg32)                       REG_FLD_GET(OVL_EL0_CON_FLD_SRCKEY_EN, (reg32))
#define OVL_EL0_CON_GET_LAYER_SRC(reg32)                       REG_FLD_GET(OVL_EL0_CON_FLD_LAYER_SRC, (reg32))
#define OVL_EL0_CON_GET_MTX_EN(reg32)                          REG_FLD_GET(OVL_EL0_CON_FLD_MTX_EN, (reg32))
#define OVL_EL0_CON_GET_MTX_AUTO_DIS(reg32)                    REG_FLD_GET(OVL_EL0_CON_FLD_MTX_AUTO_DIS, (reg32))
#define OVL_EL0_CON_GET_RGB_SWAP(reg32)                        REG_FLD_GET(OVL_EL0_CON_FLD_RGB_SWAP, (reg32))
#define OVL_EL0_CON_GET_BYTE_SWAP(reg32)                       REG_FLD_GET(OVL_EL0_CON_FLD_BYTE_SWAP, (reg32))
#define OVL_EL0_CON_GET_CLRFMT_MAN(reg32)                      REG_FLD_GET(OVL_EL0_CON_FLD_CLRFMT_MAN, (reg32))
#define OVL_EL0_CON_GET_R_FIRST(reg32)                         REG_FLD_GET(OVL_EL0_CON_FLD_R_FIRST, (reg32))
#define OVL_EL0_CON_GET_LANDSCAPE(reg32)                       REG_FLD_GET(OVL_EL0_CON_FLD_LANDSCAPE, (reg32))
#define OVL_EL0_CON_GET_EN_3D(reg32)                           REG_FLD_GET(OVL_EL0_CON_FLD_EN_3D, (reg32))
#define OVL_EL0_CON_GET_INT_MTX_SEL(reg32)                     REG_FLD_GET(OVL_EL0_CON_FLD_INT_MTX_SEL, (reg32))
#define OVL_EL0_CON_GET_CLRFMT(reg32)                          REG_FLD_GET(OVL_EL0_CON_FLD_CLRFMT, (reg32))
#define OVL_EL0_CON_GET_EXT_MTX_EN(reg32)                      REG_FLD_GET(OVL_EL0_CON_FLD_EXT_MTX_EN, (reg32))
#define OVL_EL0_CON_GET_HORIZONTAL_FLIP_EN(reg32)              REG_FLD_GET(OVL_EL0_CON_FLD_HORIZONTAL_FLIP_EN, (reg32))
#define OVL_EL0_CON_GET_VERTICAL_FLIP_EN(reg32)                REG_FLD_GET(OVL_EL0_CON_FLD_VERTICAL_FLIP_EN, (reg32))
#define OVL_EL0_CON_GET_ALPHA_EN(reg32)                        REG_FLD_GET(OVL_EL0_CON_FLD_ALPHA_EN, (reg32))
#define OVL_EL0_CON_GET_ALPHA(reg32)                           REG_FLD_GET(OVL_EL0_CON_FLD_ALPHA, (reg32))

#define OVL_EL0_SRCKEY_GET_SRCKEY(reg32)                       REG_FLD_GET(OVL_EL0_SRCKEY_FLD_SRCKEY, (reg32))

#define OVL_EL0_SRC_SIZE_GET_EL0_SRC_H(reg32)                  REG_FLD_GET(OVL_EL0_SRC_SIZE_FLD_EL0_SRC_H, (reg32))
#define OVL_EL0_SRC_SIZE_GET_EL0_SRC_W(reg32)                  REG_FLD_GET(OVL_EL0_SRC_SIZE_FLD_EL0_SRC_W, (reg32))

#define OVL_EL0_OFFSET_GET_EL0_YOFF(reg32)                     REG_FLD_GET(OVL_EL0_OFFSET_FLD_EL0_YOFF, (reg32))
#define OVL_EL0_OFFSET_GET_EL0_XOFF(reg32)                     REG_FLD_GET(OVL_EL0_OFFSET_FLD_EL0_XOFF, (reg32))

#define OVL_EL0_PITCH_GET_SURFL_EN(reg32)                      REG_FLD_GET(OVL_EL0_PITCH_FLD_SURFL_EN, (reg32))
#define OVL_EL0_PITCH_GET_EL0_BLEND_RND_SHT(reg32)             REG_FLD_GET(OVL_EL0_PITCH_FLD_EL0_BLEND_RND_SHT, (reg32))
#define OVL_EL0_PITCH_GET_EL0_SRGB_SEL_EXT2(reg32)             REG_FLD_GET(OVL_EL0_PITCH_FLD_EL0_SRGB_SEL_EXT2, (reg32))
#define OVL_EL0_PITCH_GET_EL0_CONST_BLD(reg32)                 REG_FLD_GET(OVL_EL0_PITCH_FLD_EL0_CONST_BLD, (reg32))
#define OVL_EL0_PITCH_GET_EL0_DRGB_SEL_EXT(reg32)              REG_FLD_GET(OVL_EL0_PITCH_FLD_EL0_DRGB_SEL_EXT, (reg32))
#define OVL_EL0_PITCH_GET_EL0_DA_SEL_EXT(reg32)                REG_FLD_GET(OVL_EL0_PITCH_FLD_EL0_DA_SEL_EXT, (reg32))
#define OVL_EL0_PITCH_GET_EL0_SRGB_SEL_EXT(reg32)              REG_FLD_GET(OVL_EL0_PITCH_FLD_EL0_SRGB_SEL_EXT, (reg32))
#define OVL_EL0_PITCH_GET_EL0_SA_SEL_EXT(reg32)                REG_FLD_GET(OVL_EL0_PITCH_FLD_EL0_SA_SEL_EXT, (reg32))
#define OVL_EL0_PITCH_GET_EL0_DRGB_SEL(reg32)                  REG_FLD_GET(OVL_EL0_PITCH_FLD_EL0_DRGB_SEL, (reg32))
#define OVL_EL0_PITCH_GET_EL0_DA_SEL(reg32)                    REG_FLD_GET(OVL_EL0_PITCH_FLD_EL0_DA_SEL, (reg32))
#define OVL_EL0_PITCH_GET_EL0_SRGB_SEL(reg32)                  REG_FLD_GET(OVL_EL0_PITCH_FLD_EL0_SRGB_SEL, (reg32))
#define OVL_EL0_PITCH_GET_EL0_SA_SEL(reg32)                    REG_FLD_GET(OVL_EL0_PITCH_FLD_EL0_SA_SEL, (reg32))
#define OVL_EL0_PITCH_GET_EL0_SRC_PITCH(reg32)                 REG_FLD_GET(OVL_EL0_PITCH_FLD_EL0_SRC_PITCH, (reg32))

#define OVL_EL0_TILE_GET_TILE_HORI_BLOCK_NUM(reg32)            REG_FLD_GET(OVL_EL0_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32))
#define OVL_EL0_TILE_GET_TILE_EN(reg32)                        REG_FLD_GET(OVL_EL0_TILE_FLD_TILE_EN, (reg32))
#define OVL_EL0_TILE_GET_TILE_WIDTH_SEL(reg32)                 REG_FLD_GET(OVL_EL0_TILE_FLD_TILE_WIDTH_SEL, (reg32))
#define OVL_EL0_TILE_GET_TILE_HEIGHT(reg32)                    REG_FLD_GET(OVL_EL0_TILE_FLD_TILE_HEIGHT, (reg32))

#define OVL_EL0_CLIP_GET_EL0_SRC_BOTTOM_CLIP(reg32)            REG_FLD_GET(OVL_EL0_CLIP_FLD_EL0_SRC_BOTTOM_CLIP, (reg32))
#define OVL_EL0_CLIP_GET_EL0_SRC_TOP_CLIP(reg32)               REG_FLD_GET(OVL_EL0_CLIP_FLD_EL0_SRC_TOP_CLIP, (reg32))
#define OVL_EL0_CLIP_GET_EL0_SRC_RIGHT_CLIP(reg32)             REG_FLD_GET(OVL_EL0_CLIP_FLD_EL0_SRC_RIGHT_CLIP, (reg32))
#define OVL_EL0_CLIP_GET_EL0_SRC_LEFT_CLIP(reg32)              REG_FLD_GET(OVL_EL0_CLIP_FLD_EL0_SRC_LEFT_CLIP, (reg32))

#define OVL_EL1_CON_GET_DSTKEY_EN(reg32)                       REG_FLD_GET(OVL_EL1_CON_FLD_DSTKEY_EN, (reg32))
#define OVL_EL1_CON_GET_SRCKEY_EN(reg32)                       REG_FLD_GET(OVL_EL1_CON_FLD_SRCKEY_EN, (reg32))
#define OVL_EL1_CON_GET_LAYER_SRC(reg32)                       REG_FLD_GET(OVL_EL1_CON_FLD_LAYER_SRC, (reg32))
#define OVL_EL1_CON_GET_MTX_EN(reg32)                          REG_FLD_GET(OVL_EL1_CON_FLD_MTX_EN, (reg32))
#define OVL_EL1_CON_GET_MTX_AUTO_DIS(reg32)                    REG_FLD_GET(OVL_EL1_CON_FLD_MTX_AUTO_DIS, (reg32))
#define OVL_EL1_CON_GET_RGB_SWAP(reg32)                        REG_FLD_GET(OVL_EL1_CON_FLD_RGB_SWAP, (reg32))
#define OVL_EL1_CON_GET_BYTE_SWAP(reg32)                       REG_FLD_GET(OVL_EL1_CON_FLD_BYTE_SWAP, (reg32))
#define OVL_EL1_CON_GET_CLRFMT_MAN(reg32)                      REG_FLD_GET(OVL_EL1_CON_FLD_CLRFMT_MAN, (reg32))
#define OVL_EL1_CON_GET_R_FIRST(reg32)                         REG_FLD_GET(OVL_EL1_CON_FLD_R_FIRST, (reg32))
#define OVL_EL1_CON_GET_LANDSCAPE(reg32)                       REG_FLD_GET(OVL_EL1_CON_FLD_LANDSCAPE, (reg32))
#define OVL_EL1_CON_GET_EN_3D(reg32)                           REG_FLD_GET(OVL_EL1_CON_FLD_EN_3D, (reg32))
#define OVL_EL1_CON_GET_INT_MTX_SEL(reg32)                     REG_FLD_GET(OVL_EL1_CON_FLD_INT_MTX_SEL, (reg32))
#define OVL_EL1_CON_GET_CLRFMT(reg32)                          REG_FLD_GET(OVL_EL1_CON_FLD_CLRFMT, (reg32))
#define OVL_EL1_CON_GET_EXT_MTX_EN(reg32)                      REG_FLD_GET(OVL_EL1_CON_FLD_EXT_MTX_EN, (reg32))
#define OVL_EL1_CON_GET_HORIZONTAL_FLIP_EN(reg32)              REG_FLD_GET(OVL_EL1_CON_FLD_HORIZONTAL_FLIP_EN, (reg32))
#define OVL_EL1_CON_GET_VERTICAL_FLIP_EN(reg32)                REG_FLD_GET(OVL_EL1_CON_FLD_VERTICAL_FLIP_EN, (reg32))
#define OVL_EL1_CON_GET_ALPHA_EN(reg32)                        REG_FLD_GET(OVL_EL1_CON_FLD_ALPHA_EN, (reg32))
#define OVL_EL1_CON_GET_ALPHA(reg32)                           REG_FLD_GET(OVL_EL1_CON_FLD_ALPHA, (reg32))

#define OVL_EL1_SRCKEY_GET_SRCKEY(reg32)                       REG_FLD_GET(OVL_EL1_SRCKEY_FLD_SRCKEY, (reg32))

#define OVL_EL1_SRC_SIZE_GET_EL1_SRC_H(reg32)                  REG_FLD_GET(OVL_EL1_SRC_SIZE_FLD_EL1_SRC_H, (reg32))
#define OVL_EL1_SRC_SIZE_GET_EL1_SRC_W(reg32)                  REG_FLD_GET(OVL_EL1_SRC_SIZE_FLD_EL1_SRC_W, (reg32))

#define OVL_EL1_OFFSET_GET_EL1_YOFF(reg32)                     REG_FLD_GET(OVL_EL1_OFFSET_FLD_EL1_YOFF, (reg32))
#define OVL_EL1_OFFSET_GET_EL1_XOFF(reg32)                     REG_FLD_GET(OVL_EL1_OFFSET_FLD_EL1_XOFF, (reg32))

#define OVL_EL1_PITCH_GET_SURFL_EN(reg32)                      REG_FLD_GET(OVL_EL1_PITCH_FLD_SURFL_EN, (reg32))
#define OVL_EL1_PITCH_GET_EL1_BLEND_RND_SHT(reg32)             REG_FLD_GET(OVL_EL1_PITCH_FLD_EL1_BLEND_RND_SHT, (reg32))
#define OVL_EL1_PITCH_GET_EL1_SRGB_SEL_EXT2(reg32)             REG_FLD_GET(OVL_EL1_PITCH_FLD_EL1_SRGB_SEL_EXT2, (reg32))
#define OVL_EL1_PITCH_GET_EL1_CONST_BLD(reg32)                 REG_FLD_GET(OVL_EL1_PITCH_FLD_EL1_CONST_BLD, (reg32))
#define OVL_EL1_PITCH_GET_EL1_DRGB_SEL_EXT(reg32)              REG_FLD_GET(OVL_EL1_PITCH_FLD_EL1_DRGB_SEL_EXT, (reg32))
#define OVL_EL1_PITCH_GET_EL1_DA_SEL_EXT(reg32)                REG_FLD_GET(OVL_EL1_PITCH_FLD_EL1_DA_SEL_EXT, (reg32))
#define OVL_EL1_PITCH_GET_EL1_SRGB_SEL_EXT(reg32)              REG_FLD_GET(OVL_EL1_PITCH_FLD_EL1_SRGB_SEL_EXT, (reg32))
#define OVL_EL1_PITCH_GET_EL1_SA_SEL_EXT(reg32)                REG_FLD_GET(OVL_EL1_PITCH_FLD_EL1_SA_SEL_EXT, (reg32))
#define OVL_EL1_PITCH_GET_EL1_DRGB_SEL(reg32)                  REG_FLD_GET(OVL_EL1_PITCH_FLD_EL1_DRGB_SEL, (reg32))
#define OVL_EL1_PITCH_GET_EL1_DA_SEL(reg32)                    REG_FLD_GET(OVL_EL1_PITCH_FLD_EL1_DA_SEL, (reg32))
#define OVL_EL1_PITCH_GET_EL1_SRGB_SEL(reg32)                  REG_FLD_GET(OVL_EL1_PITCH_FLD_EL1_SRGB_SEL, (reg32))
#define OVL_EL1_PITCH_GET_EL1_SA_SEL(reg32)                    REG_FLD_GET(OVL_EL1_PITCH_FLD_EL1_SA_SEL, (reg32))
#define OVL_EL1_PITCH_GET_EL1_SRC_PITCH(reg32)                 REG_FLD_GET(OVL_EL1_PITCH_FLD_EL1_SRC_PITCH, (reg32))

#define OVL_EL1_TILE_GET_TILE_HORI_BLOCK_NUM(reg32)            REG_FLD_GET(OVL_EL1_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32))
#define OVL_EL1_TILE_GET_TILE_EN(reg32)                        REG_FLD_GET(OVL_EL1_TILE_FLD_TILE_EN, (reg32))
#define OVL_EL1_TILE_GET_TILE_WIDTH_SEL(reg32)                 REG_FLD_GET(OVL_EL1_TILE_FLD_TILE_WIDTH_SEL, (reg32))
#define OVL_EL1_TILE_GET_TILE_HEIGHT(reg32)                    REG_FLD_GET(OVL_EL1_TILE_FLD_TILE_HEIGHT, (reg32))

#define OVL_EL1_CLIP_GET_EL1_SRC_BOTTOM_CLIP(reg32)            REG_FLD_GET(OVL_EL1_CLIP_FLD_EL1_SRC_BOTTOM_CLIP, (reg32))
#define OVL_EL1_CLIP_GET_EL1_SRC_TOP_CLIP(reg32)               REG_FLD_GET(OVL_EL1_CLIP_FLD_EL1_SRC_TOP_CLIP, (reg32))
#define OVL_EL1_CLIP_GET_EL1_SRC_RIGHT_CLIP(reg32)             REG_FLD_GET(OVL_EL1_CLIP_FLD_EL1_SRC_RIGHT_CLIP, (reg32))
#define OVL_EL1_CLIP_GET_EL1_SRC_LEFT_CLIP(reg32)              REG_FLD_GET(OVL_EL1_CLIP_FLD_EL1_SRC_LEFT_CLIP, (reg32))

#define OVL_EL2_CON_GET_DSTKEY_EN(reg32)                       REG_FLD_GET(OVL_EL2_CON_FLD_DSTKEY_EN, (reg32))
#define OVL_EL2_CON_GET_SRCKEY_EN(reg32)                       REG_FLD_GET(OVL_EL2_CON_FLD_SRCKEY_EN, (reg32))
#define OVL_EL2_CON_GET_LAYER_SRC(reg32)                       REG_FLD_GET(OVL_EL2_CON_FLD_LAYER_SRC, (reg32))
#define OVL_EL2_CON_GET_MTX_EN(reg32)                          REG_FLD_GET(OVL_EL2_CON_FLD_MTX_EN, (reg32))
#define OVL_EL2_CON_GET_MTX_AUTO_DIS(reg32)                    REG_FLD_GET(OVL_EL2_CON_FLD_MTX_AUTO_DIS, (reg32))
#define OVL_EL2_CON_GET_RGB_SWAP(reg32)                        REG_FLD_GET(OVL_EL2_CON_FLD_RGB_SWAP, (reg32))
#define OVL_EL2_CON_GET_BYTE_SWAP(reg32)                       REG_FLD_GET(OVL_EL2_CON_FLD_BYTE_SWAP, (reg32))
#define OVL_EL2_CON_GET_CLRFMT_MAN(reg32)                      REG_FLD_GET(OVL_EL2_CON_FLD_CLRFMT_MAN, (reg32))
#define OVL_EL2_CON_GET_R_FIRST(reg32)                         REG_FLD_GET(OVL_EL2_CON_FLD_R_FIRST, (reg32))
#define OVL_EL2_CON_GET_LANDSCAPE(reg32)                       REG_FLD_GET(OVL_EL2_CON_FLD_LANDSCAPE, (reg32))
#define OVL_EL2_CON_GET_EN_3D(reg32)                           REG_FLD_GET(OVL_EL2_CON_FLD_EN_3D, (reg32))
#define OVL_EL2_CON_GET_INT_MTX_SEL(reg32)                     REG_FLD_GET(OVL_EL2_CON_FLD_INT_MTX_SEL, (reg32))
#define OVL_EL2_CON_GET_CLRFMT(reg32)                          REG_FLD_GET(OVL_EL2_CON_FLD_CLRFMT, (reg32))
#define OVL_EL2_CON_GET_EXT_MTX_EN(reg32)                      REG_FLD_GET(OVL_EL2_CON_FLD_EXT_MTX_EN, (reg32))
#define OVL_EL2_CON_GET_HORIZONTAL_FLIP_EN(reg32)              REG_FLD_GET(OVL_EL2_CON_FLD_HORIZONTAL_FLIP_EN, (reg32))
#define OVL_EL2_CON_GET_VERTICAL_FLIP_EN(reg32)                REG_FLD_GET(OVL_EL2_CON_FLD_VERTICAL_FLIP_EN, (reg32))
#define OVL_EL2_CON_GET_ALPHA_EN(reg32)                        REG_FLD_GET(OVL_EL2_CON_FLD_ALPHA_EN, (reg32))
#define OVL_EL2_CON_GET_ALPHA(reg32)                           REG_FLD_GET(OVL_EL2_CON_FLD_ALPHA, (reg32))

#define OVL_EL2_SRCKEY_GET_SRCKEY(reg32)                       REG_FLD_GET(OVL_EL2_SRCKEY_FLD_SRCKEY, (reg32))

#define OVL_EL2_SRC_SIZE_GET_EL2_SRC_H(reg32)                  REG_FLD_GET(OVL_EL2_SRC_SIZE_FLD_EL2_SRC_H, (reg32))
#define OVL_EL2_SRC_SIZE_GET_EL2_SRC_W(reg32)                  REG_FLD_GET(OVL_EL2_SRC_SIZE_FLD_EL2_SRC_W, (reg32))

#define OVL_EL2_OFFSET_GET_EL2_YOFF(reg32)                     REG_FLD_GET(OVL_EL2_OFFSET_FLD_EL2_YOFF, (reg32))
#define OVL_EL2_OFFSET_GET_EL2_XOFF(reg32)                     REG_FLD_GET(OVL_EL2_OFFSET_FLD_EL2_XOFF, (reg32))

#define OVL_EL2_PITCH_GET_SURFL_EN(reg32)                      REG_FLD_GET(OVL_EL2_PITCH_FLD_SURFL_EN, (reg32))
#define OVL_EL2_PITCH_GET_EL2_BLEND_RND_SHT(reg32)             REG_FLD_GET(OVL_EL2_PITCH_FLD_EL2_BLEND_RND_SHT, (reg32))
#define OVL_EL2_PITCH_GET_EL2_SRGB_SEL_EXT2(reg32)             REG_FLD_GET(OVL_EL2_PITCH_FLD_EL2_SRGB_SEL_EXT2, (reg32))
#define OVL_EL2_PITCH_GET_EL2_CONST_BLD(reg32)                 REG_FLD_GET(OVL_EL2_PITCH_FLD_EL2_CONST_BLD, (reg32))
#define OVL_EL2_PITCH_GET_EL2_DRGB_SEL_EXT(reg32)              REG_FLD_GET(OVL_EL2_PITCH_FLD_EL2_DRGB_SEL_EXT, (reg32))
#define OVL_EL2_PITCH_GET_EL2_DA_SEL_EXT(reg32)                REG_FLD_GET(OVL_EL2_PITCH_FLD_EL2_DA_SEL_EXT, (reg32))
#define OVL_EL2_PITCH_GET_EL2_SRGB_SEL_EXT(reg32)              REG_FLD_GET(OVL_EL2_PITCH_FLD_EL2_SRGB_SEL_EXT, (reg32))
#define OVL_EL2_PITCH_GET_EL2_SA_SEL_EXT(reg32)                REG_FLD_GET(OVL_EL2_PITCH_FLD_EL2_SA_SEL_EXT, (reg32))
#define OVL_EL2_PITCH_GET_EL2_DRGB_SEL(reg32)                  REG_FLD_GET(OVL_EL2_PITCH_FLD_EL2_DRGB_SEL, (reg32))
#define OVL_EL2_PITCH_GET_EL2_DA_SEL(reg32)                    REG_FLD_GET(OVL_EL2_PITCH_FLD_EL2_DA_SEL, (reg32))
#define OVL_EL2_PITCH_GET_EL2_SRGB_SEL(reg32)                  REG_FLD_GET(OVL_EL2_PITCH_FLD_EL2_SRGB_SEL, (reg32))
#define OVL_EL2_PITCH_GET_EL2_SA_SEL(reg32)                    REG_FLD_GET(OVL_EL2_PITCH_FLD_EL2_SA_SEL, (reg32))
#define OVL_EL2_PITCH_GET_EL2_SRC_PITCH(reg32)                 REG_FLD_GET(OVL_EL2_PITCH_FLD_EL2_SRC_PITCH, (reg32))

#define OVL_EL2_TILE_GET_TILE_HORI_BLOCK_NUM(reg32)            REG_FLD_GET(OVL_EL2_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32))
#define OVL_EL2_TILE_GET_TILE_EN(reg32)                        REG_FLD_GET(OVL_EL2_TILE_FLD_TILE_EN, (reg32))
#define OVL_EL2_TILE_GET_TILE_WIDTH_SEL(reg32)                 REG_FLD_GET(OVL_EL2_TILE_FLD_TILE_WIDTH_SEL, (reg32))
#define OVL_EL2_TILE_GET_TILE_HEIGHT(reg32)                    REG_FLD_GET(OVL_EL2_TILE_FLD_TILE_HEIGHT, (reg32))

#define OVL_EL2_CLIP_GET_EL2_SRC_BOTTOM_CLIP(reg32)            REG_FLD_GET(OVL_EL2_CLIP_FLD_EL2_SRC_BOTTOM_CLIP, (reg32))
#define OVL_EL2_CLIP_GET_EL2_SRC_TOP_CLIP(reg32)               REG_FLD_GET(OVL_EL2_CLIP_FLD_EL2_SRC_TOP_CLIP, (reg32))
#define OVL_EL2_CLIP_GET_EL2_SRC_RIGHT_CLIP(reg32)             REG_FLD_GET(OVL_EL2_CLIP_FLD_EL2_SRC_RIGHT_CLIP, (reg32))
#define OVL_EL2_CLIP_GET_EL2_SRC_LEFT_CLIP(reg32)              REG_FLD_GET(OVL_EL2_CLIP_FLD_EL2_SRC_LEFT_CLIP, (reg32))

#define OVL_EL0_CLR_GET_ALPHA(reg32)                           REG_FLD_GET(OVL_EL0_CLR_FLD_ALPHA, (reg32))
#define OVL_EL0_CLR_GET_RED(reg32)                             REG_FLD_GET(OVL_EL0_CLR_FLD_RED, (reg32))
#define OVL_EL0_CLR_GET_GREEN(reg32)                           REG_FLD_GET(OVL_EL0_CLR_FLD_GREEN, (reg32))
#define OVL_EL0_CLR_GET_BLUE(reg32)                            REG_FLD_GET(OVL_EL0_CLR_FLD_BLUE, (reg32))

#define OVL_EL1_CLR_GET_ALPHA(reg32)                           REG_FLD_GET(OVL_EL1_CLR_FLD_ALPHA, (reg32))
#define OVL_EL1_CLR_GET_RED(reg32)                             REG_FLD_GET(OVL_EL1_CLR_FLD_RED, (reg32))
#define OVL_EL1_CLR_GET_GREEN(reg32)                           REG_FLD_GET(OVL_EL1_CLR_FLD_GREEN, (reg32))
#define OVL_EL1_CLR_GET_BLUE(reg32)                            REG_FLD_GET(OVL_EL1_CLR_FLD_BLUE, (reg32))

#define OVL_EL2_CLR_GET_ALPHA(reg32)                           REG_FLD_GET(OVL_EL2_CLR_FLD_ALPHA, (reg32))
#define OVL_EL2_CLR_GET_RED(reg32)                             REG_FLD_GET(OVL_EL2_CLR_FLD_RED, (reg32))
#define OVL_EL2_CLR_GET_GREEN(reg32)                           REG_FLD_GET(OVL_EL2_CLR_FLD_GREEN, (reg32))
#define OVL_EL2_CLR_GET_BLUE(reg32)                            REG_FLD_GET(OVL_EL2_CLR_FLD_BLUE, (reg32))

#define OVL_SBCH_GET_L3_SBCH_CNST_EN(reg32)                    REG_FLD_GET(OVL_SBCH_FLD_L3_SBCH_CNST_EN, (reg32))
#define OVL_SBCH_GET_L3_SBCH_TRANS_EN(reg32)                   REG_FLD_GET(OVL_SBCH_FLD_L3_SBCH_TRANS_EN, (reg32))
#define OVL_SBCH_GET_L2_SBCH_CNST_EN(reg32)                    REG_FLD_GET(OVL_SBCH_FLD_L2_SBCH_CNST_EN, (reg32))
#define OVL_SBCH_GET_L2_SBCH_TRANS_EN(reg32)                   REG_FLD_GET(OVL_SBCH_FLD_L2_SBCH_TRANS_EN, (reg32))
#define OVL_SBCH_GET_L1_SBCH_CNST_EN(reg32)                    REG_FLD_GET(OVL_SBCH_FLD_L1_SBCH_CNST_EN, (reg32))
#define OVL_SBCH_GET_L1_SBCH_TRANS_EN(reg32)                   REG_FLD_GET(OVL_SBCH_FLD_L1_SBCH_TRANS_EN, (reg32))
#define OVL_SBCH_GET_L0_SBCH_CNST_EN(reg32)                    REG_FLD_GET(OVL_SBCH_FLD_L0_SBCH_CNST_EN, (reg32))
#define OVL_SBCH_GET_L0_SBCH_TRANS_EN(reg32)                   REG_FLD_GET(OVL_SBCH_FLD_L0_SBCH_TRANS_EN, (reg32))
#define OVL_SBCH_GET_L3_SBCH_UPDATE(reg32)                     REG_FLD_GET(OVL_SBCH_FLD_L3_SBCH_UPDATE, (reg32))
#define OVL_SBCH_GET_L2_SBCH_UPDATE(reg32)                     REG_FLD_GET(OVL_SBCH_FLD_L2_SBCH_UPDATE, (reg32))
#define OVL_SBCH_GET_L1_SBCH_UPDATE(reg32)                     REG_FLD_GET(OVL_SBCH_FLD_L1_SBCH_UPDATE, (reg32))
#define OVL_SBCH_GET_L0_SBCH_UPDATE(reg32)                     REG_FLD_GET(OVL_SBCH_FLD_L0_SBCH_UPDATE, (reg32))

#define OVL_SBCH_EXT_GET_EL2_SBCH_CNST_EN(reg32)               REG_FLD_GET(OVL_SBCH_EXT_FLD_EL2_SBCH_CNST_EN, (reg32))
#define OVL_SBCH_EXT_GET_EL2_SBCH_TRANS_EN(reg32)              REG_FLD_GET(OVL_SBCH_EXT_FLD_EL2_SBCH_TRANS_EN, (reg32))
#define OVL_SBCH_EXT_GET_EL1_SBCH_CNST_EN(reg32)               REG_FLD_GET(OVL_SBCH_EXT_FLD_EL1_SBCH_CNST_EN, (reg32))
#define OVL_SBCH_EXT_GET_EL1_SBCH_TRANS_EN(reg32)              REG_FLD_GET(OVL_SBCH_EXT_FLD_EL1_SBCH_TRANS_EN, (reg32))
#define OVL_SBCH_EXT_GET_EL0_SBCH_CNST_EN(reg32)               REG_FLD_GET(OVL_SBCH_EXT_FLD_EL0_SBCH_CNST_EN, (reg32))
#define OVL_SBCH_EXT_GET_EL0_SBCH_TRANS_EN(reg32)              REG_FLD_GET(OVL_SBCH_EXT_FLD_EL0_SBCH_TRANS_EN, (reg32))
#define OVL_SBCH_EXT_GET_EL2_SBCH_UPDATE(reg32)                REG_FLD_GET(OVL_SBCH_EXT_FLD_EL2_SBCH_UPDATE, (reg32))
#define OVL_SBCH_EXT_GET_EL1_SBCH_UPDATE(reg32)                REG_FLD_GET(OVL_SBCH_EXT_FLD_EL1_SBCH_UPDATE, (reg32))
#define OVL_SBCH_EXT_GET_EL0_SBCH_UPDATE(reg32)                REG_FLD_GET(OVL_SBCH_EXT_FLD_EL0_SBCH_UPDATE, (reg32))

#define OVL_SBCH_CON_GET_EL2_SBCH_TRANS_INVALID(reg32)         REG_FLD_GET(OVL_SBCH_CON_FLD_EL2_SBCH_TRANS_INVALID, (reg32))
#define OVL_SBCH_CON_GET_EL1_SBCH_TRANS_INVALID(reg32)         REG_FLD_GET(OVL_SBCH_CON_FLD_EL1_SBCH_TRANS_INVALID, (reg32))
#define OVL_SBCH_CON_GET_EL0_SBCH_TRANS_INVALID(reg32)         REG_FLD_GET(OVL_SBCH_CON_FLD_EL0_SBCH_TRANS_INVALID, (reg32))
#define OVL_SBCH_CON_GET_L3_SBCH_TRANS_INVALID(reg32)          REG_FLD_GET(OVL_SBCH_CON_FLD_L3_SBCH_TRANS_INVALID, (reg32))
#define OVL_SBCH_CON_GET_L2_SBCH_TRANS_INVALID(reg32)          REG_FLD_GET(OVL_SBCH_CON_FLD_L2_SBCH_TRANS_INVALID, (reg32))
#define OVL_SBCH_CON_GET_L1_SBCH_TRANS_INVALID(reg32)          REG_FLD_GET(OVL_SBCH_CON_FLD_L1_SBCH_TRANS_INVALID, (reg32))
#define OVL_SBCH_CON_GET_L0_SBCH_TRANS_INVALID(reg32)          REG_FLD_GET(OVL_SBCH_CON_FLD_L0_SBCH_TRANS_INVALID, (reg32))

#define OVL_L0_ADDR_GET_L0_ADDR(reg32)                         REG_FLD_GET(OVL_L0_ADDR_FLD_L0_ADDR, (reg32))

#define OVL_L1_ADDR_GET_L1_ADDR(reg32)                         REG_FLD_GET(OVL_L1_ADDR_FLD_L1_ADDR, (reg32))

#define OVL_L2_ADDR_GET_L2_ADDR(reg32)                         REG_FLD_GET(OVL_L2_ADDR_FLD_L2_ADDR, (reg32))

#define OVL_L3_ADDR_GET_L3_ADDR(reg32)                         REG_FLD_GET(OVL_L3_ADDR_FLD_L3_ADDR, (reg32))

#define OVL_EL0_ADDR_GET_EL0_ADDR(reg32)                       REG_FLD_GET(OVL_EL0_ADDR_FLD_EL0_ADDR, (reg32))

#define OVL_EL1_ADDR_GET_EL1_ADDR(reg32)                       REG_FLD_GET(OVL_EL1_ADDR_FLD_EL1_ADDR, (reg32))

#define OVL_EL2_ADDR_GET_EL2_ADDR(reg32)                       REG_FLD_GET(OVL_EL2_ADDR_FLD_EL2_ADDR, (reg32))

#define OVL_SECURE_GET_L3_SECURE(reg32)                        REG_FLD_GET(OVL_SECURE_FLD_L3_SECURE, (reg32))
#define OVL_SECURE_GET_L2_SECURE(reg32)                        REG_FLD_GET(OVL_SECURE_FLD_L2_SECURE, (reg32))
#define OVL_SECURE_GET_L1_SECURE(reg32)                        REG_FLD_GET(OVL_SECURE_FLD_L1_SECURE, (reg32))
#define OVL_SECURE_GET_L0_SECURE(reg32)                        REG_FLD_GET(OVL_SECURE_FLD_L0_SECURE, (reg32))

#define OVL_STA_SET_RDMA3_IDLE(reg32, val)                     REG_FLD_SET(OVL_STA_FLD_RDMA3_IDLE, (reg32), (val))
#define OVL_STA_SET_RDMA2_IDLE(reg32, val)                     REG_FLD_SET(OVL_STA_FLD_RDMA2_IDLE, (reg32), (val))
#define OVL_STA_SET_RDMA1_IDLE(reg32, val)                     REG_FLD_SET(OVL_STA_FLD_RDMA1_IDLE, (reg32), (val))
#define OVL_STA_SET_RDMA0_IDLE(reg32, val)                     REG_FLD_SET(OVL_STA_FLD_RDMA0_IDLE, (reg32), (val))
#define OVL_STA_SET_OVL_RUN(reg32, val)                        REG_FLD_SET(OVL_STA_FLD_OVL_RUN, (reg32), (val))

#define OVL_INTEN_SET_OVL_START_INTEN(reg32, val)              REG_FLD_SET(OVL_INTEN_FLD_OVL_START_INTEN, (reg32), (val))
#define OVL_INTEN_SET_ABNORMAL_SOF_INTEN(reg32, val)           REG_FLD_SET(OVL_INTEN_FLD_ABNORMAL_SOF_INTEN, (reg32), (val))
#define OVL_INTEN_SET_RDMA3_SMI_UNDERFLOW_INTEN(reg32, val)    REG_FLD_SET(OVL_INTEN_FLD_RDMA3_SMI_UNDERFLOW_INTEN, (reg32), (val))
#define OVL_INTEN_SET_RDMA2_SMI_UNDERFLOW_INTEN(reg32, val)    REG_FLD_SET(OVL_INTEN_FLD_RDMA2_SMI_UNDERFLOW_INTEN, (reg32), (val))
#define OVL_INTEN_SET_RDMA1_SMI_UNDERFLOW_INTEN(reg32, val)    REG_FLD_SET(OVL_INTEN_FLD_RDMA1_SMI_UNDERFLOW_INTEN, (reg32), (val))
#define OVL_INTEN_SET_RDMA0_SMI_UNDERFLOW_INTEN(reg32, val)    REG_FLD_SET(OVL_INTEN_FLD_RDMA0_SMI_UNDERFLOW_INTEN, (reg32), (val))
#define OVL_INTEN_SET_RDMA3_EOF_ABNORMAL_INTEN(reg32, val)     REG_FLD_SET(OVL_INTEN_FLD_RDMA3_EOF_ABNORMAL_INTEN, (reg32), (val))
#define OVL_INTEN_SET_RDMA2_EOF_ABNORMAL_INTEN(reg32, val)     REG_FLD_SET(OVL_INTEN_FLD_RDMA2_EOF_ABNORMAL_INTEN, (reg32), (val))
#define OVL_INTEN_SET_RDMA1_EOF_ABNORMAL_INTEN(reg32, val)     REG_FLD_SET(OVL_INTEN_FLD_RDMA1_EOF_ABNORMAL_INTEN, (reg32), (val))
#define OVL_INTEN_SET_RDMA0_EOF_ABNORMAL_INTEN(reg32, val)     REG_FLD_SET(OVL_INTEN_FLD_RDMA0_EOF_ABNORMAL_INTEN, (reg32), (val))
#define OVL_INTEN_SET_OVL_FME_HWRST_DONE_INTEN(reg32, val)     REG_FLD_SET(OVL_INTEN_FLD_OVL_FME_HWRST_DONE_INTEN, (reg32), (val))
#define OVL_INTEN_SET_OVL_FME_SWRST_DONE_INTEN(reg32, val)     REG_FLD_SET(OVL_INTEN_FLD_OVL_FME_SWRST_DONE_INTEN, (reg32), (val))
#define OVL_INTEN_SET_OVL_FME_UND_INTEN(reg32, val)            REG_FLD_SET(OVL_INTEN_FLD_OVL_FME_UND_INTEN, (reg32), (val))
#define OVL_INTEN_SET_OVL_FME_CPL_INTEN(reg32, val)            REG_FLD_SET(OVL_INTEN_FLD_OVL_FME_CPL_INTEN, (reg32), (val))
#define OVL_INTEN_SET_OVL_REG_CMT_INTEN(reg32, val)            REG_FLD_SET(OVL_INTEN_FLD_OVL_REG_CMT_INTEN, (reg32), (val))

#define OVL_INTSTA_SET_OVL_START_INTSTA(reg32, val)            REG_FLD_SET(OVL_INTSTA_FLD_OVL_START_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_ABNORMAL_SOF_INTSTA(reg32, val)         REG_FLD_SET(OVL_INTSTA_FLD_ABNORMAL_SOF_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_RDMA3_SMI_UNDERFLOW_INTSTA(reg32, val)  REG_FLD_SET(OVL_INTSTA_FLD_RDMA3_SMI_UNDERFLOW_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_RDMA2_SMI_UNDERFLOW_INTSTA(reg32, val)  REG_FLD_SET(OVL_INTSTA_FLD_RDMA2_SMI_UNDERFLOW_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_RDMA1_SMI_UNDERFLOW_INTSTA(reg32, val)  REG_FLD_SET(OVL_INTSTA_FLD_RDMA1_SMI_UNDERFLOW_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_RDMA0_SMI_UNDERFLOW_INTSTA(reg32, val)  REG_FLD_SET(OVL_INTSTA_FLD_RDMA0_SMI_UNDERFLOW_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_RDMA3_EOF_ABNORMAL_INTSTA(reg32, val)   REG_FLD_SET(OVL_INTSTA_FLD_RDMA3_EOF_ABNORMAL_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_RDMA2_EOF_ABNORMAL_INTSTA(reg32, val)   REG_FLD_SET(OVL_INTSTA_FLD_RDMA2_EOF_ABNORMAL_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_RDMA1_EOF_ABNORMAL_INTSTA(reg32, val)   REG_FLD_SET(OVL_INTSTA_FLD_RDMA1_EOF_ABNORMAL_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_RDMA0_EOF_ABNORMAL_INTSTA(reg32, val)   REG_FLD_SET(OVL_INTSTA_FLD_RDMA0_EOF_ABNORMAL_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_OVL_FME_HWRST_DONE_INTSTA(reg32, val)   REG_FLD_SET(OVL_INTSTA_FLD_OVL_FME_HWRST_DONE_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_OVL_FME_SWRST_DONE_INTSTA(reg32, val)   REG_FLD_SET(OVL_INTSTA_FLD_OVL_FME_SWRST_DONE_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_OVL_FME_UND_INTSTA(reg32, val)          REG_FLD_SET(OVL_INTSTA_FLD_OVL_FME_UND_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_OVL_FME_CPL_INTSTA(reg32, val)          REG_FLD_SET(OVL_INTSTA_FLD_OVL_FME_CPL_INTSTA, (reg32), (val))
#define OVL_INTSTA_SET_OVL_REG_CMT_INTSTA(reg32, val)          REG_FLD_SET(OVL_INTSTA_FLD_OVL_REG_CMT_INTSTA, (reg32), (val))

#define OVL_EN_SET_BLOCK_EXT_PREULTRA(reg32, val)              REG_FLD_SET(OVL_EN_FLD_BLOCK_EXT_PREULTRA, (reg32), (val))
#define OVL_EN_SET_BLOCK_EXT_ULTRA(reg32, val)                 REG_FLD_SET(OVL_EN_FLD_BLOCK_EXT_ULTRA, (reg32), (val))
#define OVL_EN_SET_IGNORE_ABNORMAL_SOF(reg32, val)             REG_FLD_SET(OVL_EN_FLD_IGNORE_ABNORMAL_SOF, (reg32), (val))
#define OVL_EN_SET_HF_FOVL_CK_ON(reg32, val)                   REG_FLD_SET(OVL_EN_FLD_HF_FOVL_CK_ON, (reg32), (val))
#define OVL_EN_SET_HG_FSMI_CK_ON(reg32, val)                   REG_FLD_SET(OVL_EN_FLD_HG_FSMI_CK_ON, (reg32), (val))
#define OVL_EN_SET_HG_FOVL_CK_ON(reg32, val)                   REG_FLD_SET(OVL_EN_FLD_HG_FOVL_CK_ON, (reg32), (val))
#define OVL_EN_SET_OVL_EN(reg32, val)                          REG_FLD_SET(OVL_EN_FLD_OVL_EN, (reg32), (val))

#define OVL_TRIG_SET_CRC_CLR(reg32, val)                       REG_FLD_SET(OVL_TRIG_FLD_CRC_CLR, (reg32), (val))
#define OVL_TRIG_SET_CRC_EN(reg32, val)                        REG_FLD_SET(OVL_TRIG_FLD_CRC_EN, (reg32), (val))
#define OVL_TRIG_SET_OVL_SW_TRIG(reg32, val)                   REG_FLD_SET(OVL_TRIG_FLD_OVL_SW_TRIG, (reg32), (val))

#define OVL_RST_SET_OVL_SMI_IOBUF_HARD_RST(reg32, val)         REG_FLD_SET(OVL_RST_FLD_OVL_SMI_IOBUF_HARD_RST, (reg32), (val))
#define OVL_RST_SET_OVL_SMI_IOBUF_RST(reg32, val)              REG_FLD_SET(OVL_RST_FLD_OVL_SMI_IOBUF_RST, (reg32), (val))
#define OVL_RST_SET_OVL_SMI_HARD_RST(reg32, val)               REG_FLD_SET(OVL_RST_FLD_OVL_SMI_HARD_RST, (reg32), (val))
#define OVL_RST_SET_OVL_SMI_RST(reg32, val)                    REG_FLD_SET(OVL_RST_FLD_OVL_SMI_RST, (reg32), (val))
#define OVL_RST_SET_OVL_RST(reg32, val)                        REG_FLD_SET(OVL_RST_FLD_OVL_RST, (reg32), (val))

#define OVL_ROI_SIZE_SET_ROI_H(reg32, val)                     REG_FLD_SET(OVL_ROI_SIZE_FLD_ROI_H, (reg32), (val))
#define OVL_ROI_SIZE_SET_ROI_W(reg32, val)                     REG_FLD_SET(OVL_ROI_SIZE_FLD_ROI_W, (reg32), (val))

#define OVL_DATAPATH_CON_SET_WIDE_GAMUT_EN(reg32, val)         REG_FLD_SET(OVL_DATAPATH_CON_FLD_WIDE_GAMUT_EN, (reg32), (val))
#define OVL_DATAPATH_CON_SET_OUTPUT_INTERLACE(reg32, val)      REG_FLD_SET(OVL_DATAPATH_CON_FLD_OUTPUT_INTERLACE, (reg32), (val))
#define OVL_DATAPATH_CON_SET_OUTPUT_CLAMP(reg32, val)          REG_FLD_SET(OVL_DATAPATH_CON_FLD_OUTPUT_CLAMP, (reg32), (val))
#define OVL_DATAPATH_CON_SET_GCLAST_EN(reg32, val)             REG_FLD_SET(OVL_DATAPATH_CON_FLD_GCLAST_EN, (reg32), (val))
#define OVL_DATAPATH_CON_SET_RDMA3_OUT_SEL(reg32, val)         REG_FLD_SET(OVL_DATAPATH_CON_FLD_RDMA3_OUT_SEL, (reg32), (val))
#define OVL_DATAPATH_CON_SET_RDMA2_OUT_SEL(reg32, val)         REG_FLD_SET(OVL_DATAPATH_CON_FLD_RDMA2_OUT_SEL, (reg32), (val))
#define OVL_DATAPATH_CON_SET_RDMA1_OUT_SEL(reg32, val)         REG_FLD_SET(OVL_DATAPATH_CON_FLD_RDMA1_OUT_SEL, (reg32), (val))
#define OVL_DATAPATH_CON_SET_RDMA0_OUT_SEL(reg32, val)         REG_FLD_SET(OVL_DATAPATH_CON_FLD_RDMA0_OUT_SEL, (reg32), (val))
#define OVL_DATAPATH_CON_SET_PQ_OUT_SEL(reg32, val)            REG_FLD_SET(OVL_DATAPATH_CON_FLD_PQ_OUT_SEL, (reg32), (val))
#define OVL_DATAPATH_CON_SET_OVL_GAMMA_OUT(reg32, val)         REG_FLD_SET(OVL_DATAPATH_CON_FLD_OVL_GAMMA_OUT, (reg32), (val))
#define OVL_DATAPATH_CON_SET_ADOBE_LAYER(reg32, val)           REG_FLD_SET(OVL_DATAPATH_CON_FLD_ADOBE_LAYER, (reg32), (val))
#define OVL_DATAPATH_CON_SET_ADOBE_MODE(reg32, val)            REG_FLD_SET(OVL_DATAPATH_CON_FLD_ADOBE_MODE, (reg32), (val))
#define OVL_DATAPATH_CON_SET_L3_GPU_MODE(reg32, val)           REG_FLD_SET(OVL_DATAPATH_CON_FLD_L3_GPU_MODE, (reg32), (val))
#define OVL_DATAPATH_CON_SET_L2_GPU_MODE(reg32, val)           REG_FLD_SET(OVL_DATAPATH_CON_FLD_L2_GPU_MODE, (reg32), (val))
#define OVL_DATAPATH_CON_SET_L1_GPU_MODE(reg32, val)           REG_FLD_SET(OVL_DATAPATH_CON_FLD_L1_GPU_MODE, (reg32), (val))
#define OVL_DATAPATH_CON_SET_L0_GPU_MODE(reg32, val)           REG_FLD_SET(OVL_DATAPATH_CON_FLD_L0_GPU_MODE, (reg32), (val))
#define OVL_DATAPATH_CON_SET_OUTPUT_NO_RND(reg32, val)         REG_FLD_SET(OVL_DATAPATH_CON_FLD_OUTPUT_NO_RND, (reg32), (val))
#define OVL_DATAPATH_CON_SET_BGCLR_IN_SEL(reg32, val)          REG_FLD_SET(OVL_DATAPATH_CON_FLD_BGCLR_IN_SEL, (reg32), (val))
#define OVL_DATAPATH_CON_SET_OVL_RANDOM_BGCLR_EN(reg32, val)   REG_FLD_SET(OVL_DATAPATH_CON_FLD_OVL_RANDOM_BGCLR_EN, (reg32), (val))
#define OVL_DATAPATH_CON_SET_LAYER_SMI_ID_EN(reg32, val)       REG_FLD_SET(OVL_DATAPATH_CON_FLD_LAYER_SMI_ID_EN, (reg32), (val))

#define OVL_ROI_BGCLR_SET_ALPHA(reg32, val)                    REG_FLD_SET(OVL_ROI_BGCLR_FLD_ALPHA, (reg32), (val))
#define OVL_ROI_BGCLR_SET_RED(reg32, val)                      REG_FLD_SET(OVL_ROI_BGCLR_FLD_RED, (reg32), (val))
#define OVL_ROI_BGCLR_SET_GREEN(reg32, val)                    REG_FLD_SET(OVL_ROI_BGCLR_FLD_GREEN, (reg32), (val))
#define OVL_ROI_BGCLR_SET_BLUE(reg32, val)                     REG_FLD_SET(OVL_ROI_BGCLR_FLD_BLUE, (reg32), (val))

#define OVL_SRC_CON_SET_RELAY_MODE_EN(reg32, val)              REG_FLD_SET(OVL_SRC_CON_FLD_RELAY_MODE_EN, (reg32), (val))
#define OVL_SRC_CON_SET_FORCE_RELAY_MODE(reg32, val)           REG_FLD_SET(OVL_SRC_CON_FLD_FORCE_RELAY_MODE, (reg32), (val))
#define OVL_SRC_CON_SET_LC_EN(reg32, val)                      REG_FLD_SET(OVL_SRC_CON_FLD_LC_EN, (reg32), (val))
#define OVL_SRC_CON_SET_L3_EN(reg32, val)                      REG_FLD_SET(OVL_SRC_CON_FLD_L3_EN, (reg32), (val))
#define OVL_SRC_CON_SET_L2_EN(reg32, val)                      REG_FLD_SET(OVL_SRC_CON_FLD_L2_EN, (reg32), (val))
#define OVL_SRC_CON_SET_L1_EN(reg32, val)                      REG_FLD_SET(OVL_SRC_CON_FLD_L1_EN, (reg32), (val))
#define OVL_SRC_CON_SET_L0_EN(reg32, val)                      REG_FLD_SET(OVL_SRC_CON_FLD_L0_EN, (reg32), (val))

#define OVL_L0_CON_SET_DSTKEY_EN(reg32, val)                   REG_FLD_SET(OVL_L0_CON_FLD_DSTKEY_EN, (reg32), (val))
#define OVL_L0_CON_SET_SRCKEY_EN(reg32, val)                   REG_FLD_SET(OVL_L0_CON_FLD_SRCKEY_EN, (reg32), (val))
#define OVL_L0_CON_SET_LAYER_SRC(reg32, val)                   REG_FLD_SET(OVL_L0_CON_FLD_LAYER_SRC, (reg32), (val))
#define OVL_L0_CON_SET_MTX_EN(reg32, val)                      REG_FLD_SET(OVL_L0_CON_FLD_MTX_EN, (reg32), (val))
#define OVL_L0_CON_SET_MTX_AUTO_DIS(reg32, val)                REG_FLD_SET(OVL_L0_CON_FLD_MTX_AUTO_DIS, (reg32), (val))
#define OVL_L0_CON_SET_RGB_SWAP(reg32, val)                    REG_FLD_SET(OVL_L0_CON_FLD_RGB_SWAP, (reg32), (val))
#define OVL_L0_CON_SET_BYTE_SWAP(reg32, val)                   REG_FLD_SET(OVL_L0_CON_FLD_BYTE_SWAP, (reg32), (val))
#define OVL_L0_CON_SET_CLRFMT_MAN(reg32, val)                  REG_FLD_SET(OVL_L0_CON_FLD_CLRFMT_MAN, (reg32), (val))
#define OVL_L0_CON_SET_R_FIRST(reg32, val)                     REG_FLD_SET(OVL_L0_CON_FLD_R_FIRST, (reg32), (val))
#define OVL_L0_CON_SET_LANDSCAPE(reg32, val)                   REG_FLD_SET(OVL_L0_CON_FLD_LANDSCAPE, (reg32), (val))
#define OVL_L0_CON_SET_EN_3D(reg32, val)                       REG_FLD_SET(OVL_L0_CON_FLD_EN_3D, (reg32), (val))
#define OVL_L0_CON_SET_INT_MTX_SEL(reg32, val)                 REG_FLD_SET(OVL_L0_CON_FLD_INT_MTX_SEL, (reg32), (val))
#define OVL_L0_CON_SET_CLRFMT(reg32, val)                      REG_FLD_SET(OVL_L0_CON_FLD_CLRFMT, (reg32), (val))
#define OVL_L0_CON_SET_EXT_MTX_EN(reg32, val)                  REG_FLD_SET(OVL_L0_CON_FLD_EXT_MTX_EN, (reg32), (val))
#define OVL_L0_CON_SET_HORIZONTAL_FLIP_EN(reg32, val)          REG_FLD_SET(OVL_L0_CON_FLD_HORIZONTAL_FLIP_EN, (reg32), (val))
#define OVL_L0_CON_SET_VERTICAL_FLIP_EN(reg32, val)            REG_FLD_SET(OVL_L0_CON_FLD_VERTICAL_FLIP_EN, (reg32), (val))
#define OVL_L0_CON_SET_ALPHA_EN(reg32, val)                    REG_FLD_SET(OVL_L0_CON_FLD_ALPHA_EN, (reg32), (val))
#define OVL_L0_CON_SET_ALPHA(reg32, val)                       REG_FLD_SET(OVL_L0_CON_FLD_ALPHA, (reg32), (val))

#define OVL_L0_SRCKEY_SET_SRCKEY(reg32, val)                   REG_FLD_SET(OVL_L0_SRCKEY_FLD_SRCKEY, (reg32), (val))

#define OVL_L0_SRC_SIZE_SET_L0_SRC_H(reg32, val)               REG_FLD_SET(OVL_L0_SRC_SIZE_FLD_L0_SRC_H, (reg32), (val))
#define OVL_L0_SRC_SIZE_SET_L0_SRC_W(reg32, val)               REG_FLD_SET(OVL_L0_SRC_SIZE_FLD_L0_SRC_W, (reg32), (val))

#define OVL_L0_OFFSET_SET_L0_YOFF(reg32, val)                  REG_FLD_SET(OVL_L0_OFFSET_FLD_L0_YOFF, (reg32), (val))
#define OVL_L0_OFFSET_SET_L0_XOFF(reg32, val)                  REG_FLD_SET(OVL_L0_OFFSET_FLD_L0_XOFF, (reg32), (val))

#define OVL_L0_PITCH_SET_SURFL_EN(reg32, val)                  REG_FLD_SET(OVL_L0_PITCH_FLD_SURFL_EN, (reg32), (val))
#define OVL_L0_PITCH_SET_L0_BLEND_RND_SHT(reg32, val)          REG_FLD_SET(OVL_L0_PITCH_FLD_L0_BLEND_RND_SHT, (reg32), (val))
#define OVL_L0_PITCH_SET_L0_SRGB_SEL_EXT2(reg32, val)          REG_FLD_SET(OVL_L0_PITCH_FLD_L0_SRGB_SEL_EXT2, (reg32), (val))
#define OVL_L0_PITCH_SET_L0_CONST_BLD(reg32, val)              REG_FLD_SET(OVL_L0_PITCH_FLD_L0_CONST_BLD, (reg32), (val))
#define OVL_L0_PITCH_SET_L0_DRGB_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_L0_PITCH_FLD_L0_DRGB_SEL_EXT, (reg32), (val))
#define OVL_L0_PITCH_SET_L0_DA_SEL_EXT(reg32, val)             REG_FLD_SET(OVL_L0_PITCH_FLD_L0_DA_SEL_EXT, (reg32), (val))
#define OVL_L0_PITCH_SET_L0_SRGB_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_L0_PITCH_FLD_L0_SRGB_SEL_EXT, (reg32), (val))
#define OVL_L0_PITCH_SET_L0_SA_SEL_EXT(reg32, val)             REG_FLD_SET(OVL_L0_PITCH_FLD_L0_SA_SEL_EXT, (reg32), (val))
#define OVL_L0_PITCH_SET_L0_DRGB_SEL(reg32, val)               REG_FLD_SET(OVL_L0_PITCH_FLD_L0_DRGB_SEL, (reg32), (val))
#define OVL_L0_PITCH_SET_L0_DA_SEL(reg32, val)                 REG_FLD_SET(OVL_L0_PITCH_FLD_L0_DA_SEL, (reg32), (val))
#define OVL_L0_PITCH_SET_L0_SRGB_SEL(reg32, val)               REG_FLD_SET(OVL_L0_PITCH_FLD_L0_SRGB_SEL, (reg32), (val))
#define OVL_L0_PITCH_SET_L0_SA_SEL(reg32, val)                 REG_FLD_SET(OVL_L0_PITCH_FLD_L0_SA_SEL, (reg32), (val))
#define OVL_L0_PITCH_SET_L0_SRC_PITCH(reg32, val)              REG_FLD_SET(OVL_L0_PITCH_FLD_L0_SRC_PITCH, (reg32), (val))

#define OVL_L0_TILE_SET_TILE_HORI_BLOCK_NUM(reg32, val)        REG_FLD_SET(OVL_L0_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32), (val))
#define OVL_L0_TILE_SET_TILE_EN(reg32, val)                    REG_FLD_SET(OVL_L0_TILE_FLD_TILE_EN, (reg32), (val))
#define OVL_L0_TILE_SET_TILE_WIDTH_SEL(reg32, val)             REG_FLD_SET(OVL_L0_TILE_FLD_TILE_WIDTH_SEL, (reg32), (val))
#define OVL_L0_TILE_SET_TILE_HEIGHT(reg32, val)                REG_FLD_SET(OVL_L0_TILE_FLD_TILE_HEIGHT, (reg32), (val))

#define OVL_L0_CLIP_SET_L0_SRC_BOTTOM_CLIP(reg32, val)         REG_FLD_SET(OVL_L0_CLIP_FLD_L0_SRC_BOTTOM_CLIP, (reg32), (val))
#define OVL_L0_CLIP_SET_L0_SRC_TOP_CLIP(reg32, val)            REG_FLD_SET(OVL_L0_CLIP_FLD_L0_SRC_TOP_CLIP, (reg32), (val))
#define OVL_L0_CLIP_SET_L0_SRC_RIGHT_CLIP(reg32, val)          REG_FLD_SET(OVL_L0_CLIP_FLD_L0_SRC_RIGHT_CLIP, (reg32), (val))
#define OVL_L0_CLIP_SET_L0_SRC_LEFT_CLIP(reg32, val)           REG_FLD_SET(OVL_L0_CLIP_FLD_L0_SRC_LEFT_CLIP, (reg32), (val))

#define OVL_L1_CON_SET_DSTKEY_EN(reg32, val)                   REG_FLD_SET(OVL_L1_CON_FLD_DSTKEY_EN, (reg32), (val))
#define OVL_L1_CON_SET_SRCKEY_EN(reg32, val)                   REG_FLD_SET(OVL_L1_CON_FLD_SRCKEY_EN, (reg32), (val))
#define OVL_L1_CON_SET_LAYER_SRC(reg32, val)                   REG_FLD_SET(OVL_L1_CON_FLD_LAYER_SRC, (reg32), (val))
#define OVL_L1_CON_SET_MTX_EN(reg32, val)                      REG_FLD_SET(OVL_L1_CON_FLD_MTX_EN, (reg32), (val))
#define OVL_L1_CON_SET_MTX_AUTO_DIS(reg32, val)                REG_FLD_SET(OVL_L1_CON_FLD_MTX_AUTO_DIS, (reg32), (val))
#define OVL_L1_CON_SET_RGB_SWAP(reg32, val)                    REG_FLD_SET(OVL_L1_CON_FLD_RGB_SWAP, (reg32), (val))
#define OVL_L1_CON_SET_BYTE_SWAP(reg32, val)                   REG_FLD_SET(OVL_L1_CON_FLD_BYTE_SWAP, (reg32), (val))
#define OVL_L1_CON_SET_CLRFMT_MAN(reg32, val)                  REG_FLD_SET(OVL_L1_CON_FLD_CLRFMT_MAN, (reg32), (val))
#define OVL_L1_CON_SET_R_FIRST(reg32, val)                     REG_FLD_SET(OVL_L1_CON_FLD_R_FIRST, (reg32), (val))
#define OVL_L1_CON_SET_LANDSCAPE(reg32, val)                   REG_FLD_SET(OVL_L1_CON_FLD_LANDSCAPE, (reg32), (val))
#define OVL_L1_CON_SET_EN_3D(reg32, val)                       REG_FLD_SET(OVL_L1_CON_FLD_EN_3D, (reg32), (val))
#define OVL_L1_CON_SET_INT_MTX_SEL(reg32, val)                 REG_FLD_SET(OVL_L1_CON_FLD_INT_MTX_SEL, (reg32), (val))
#define OVL_L1_CON_SET_CLRFMT(reg32, val)                      REG_FLD_SET(OVL_L1_CON_FLD_CLRFMT, (reg32), (val))
#define OVL_L1_CON_SET_EXT_MTX_EN(reg32, val)                  REG_FLD_SET(OVL_L1_CON_FLD_EXT_MTX_EN, (reg32), (val))
#define OVL_L1_CON_SET_HORIZONTAL_FLIP_EN(reg32, val)          REG_FLD_SET(OVL_L1_CON_FLD_HORIZONTAL_FLIP_EN, (reg32), (val))
#define OVL_L1_CON_SET_VERTICAL_FLIP_EN(reg32, val)            REG_FLD_SET(OVL_L1_CON_FLD_VERTICAL_FLIP_EN, (reg32), (val))
#define OVL_L1_CON_SET_ALPHA_EN(reg32, val)                    REG_FLD_SET(OVL_L1_CON_FLD_ALPHA_EN, (reg32), (val))
#define OVL_L1_CON_SET_ALPHA(reg32, val)                       REG_FLD_SET(OVL_L1_CON_FLD_ALPHA, (reg32), (val))

#define OVL_L1_SRCKEY_SET_SRCKEY(reg32, val)                   REG_FLD_SET(OVL_L1_SRCKEY_FLD_SRCKEY, (reg32), (val))

#define OVL_L1_SRC_SIZE_SET_L1_SRC_H(reg32, val)               REG_FLD_SET(OVL_L1_SRC_SIZE_FLD_L1_SRC_H, (reg32), (val))
#define OVL_L1_SRC_SIZE_SET_L1_SRC_W(reg32, val)               REG_FLD_SET(OVL_L1_SRC_SIZE_FLD_L1_SRC_W, (reg32), (val))

#define OVL_L1_OFFSET_SET_L1_YOFF(reg32, val)                  REG_FLD_SET(OVL_L1_OFFSET_FLD_L1_YOFF, (reg32), (val))
#define OVL_L1_OFFSET_SET_L1_XOFF(reg32, val)                  REG_FLD_SET(OVL_L1_OFFSET_FLD_L1_XOFF, (reg32), (val))

#define OVL_L1_PITCH_SET_SURFL_EN(reg32, val)                  REG_FLD_SET(OVL_L1_PITCH_FLD_SURFL_EN, (reg32), (val))
#define OVL_L1_PITCH_SET_L1_BLEND_RND_SHT(reg32, val)          REG_FLD_SET(OVL_L1_PITCH_FLD_L1_BLEND_RND_SHT, (reg32), (val))
#define OVL_L1_PITCH_SET_L1_SRGB_SEL_EXT2(reg32, val)          REG_FLD_SET(OVL_L1_PITCH_FLD_L1_SRGB_SEL_EXT2, (reg32), (val))
#define OVL_L1_PITCH_SET_L1_CONST_BLD(reg32, val)              REG_FLD_SET(OVL_L1_PITCH_FLD_L1_CONST_BLD, (reg32), (val))
#define OVL_L1_PITCH_SET_L1_DRGB_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_L1_PITCH_FLD_L1_DRGB_SEL_EXT, (reg32), (val))
#define OVL_L1_PITCH_SET_L1_DA_SEL_EXT(reg32, val)             REG_FLD_SET(OVL_L1_PITCH_FLD_L1_DA_SEL_EXT, (reg32), (val))
#define OVL_L1_PITCH_SET_L1_SRGB_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_L1_PITCH_FLD_L1_SRGB_SEL_EXT, (reg32), (val))
#define OVL_L1_PITCH_SET_L1_SA_SEL_EXT(reg32, val)             REG_FLD_SET(OVL_L1_PITCH_FLD_L1_SA_SEL_EXT, (reg32), (val))
#define OVL_L1_PITCH_SET_L1_DRGB_SEL(reg32, val)               REG_FLD_SET(OVL_L1_PITCH_FLD_L1_DRGB_SEL, (reg32), (val))
#define OVL_L1_PITCH_SET_L1_DA_SEL(reg32, val)                 REG_FLD_SET(OVL_L1_PITCH_FLD_L1_DA_SEL, (reg32), (val))
#define OVL_L1_PITCH_SET_L1_SRGB_SEL(reg32, val)               REG_FLD_SET(OVL_L1_PITCH_FLD_L1_SRGB_SEL, (reg32), (val))
#define OVL_L1_PITCH_SET_L1_SA_SEL(reg32, val)                 REG_FLD_SET(OVL_L1_PITCH_FLD_L1_SA_SEL, (reg32), (val))
#define OVL_L1_PITCH_SET_L1_SRC_PITCH(reg32, val)              REG_FLD_SET(OVL_L1_PITCH_FLD_L1_SRC_PITCH, (reg32), (val))

#define OVL_L1_TILE_SET_TILE_HORI_BLOCK_NUM(reg32, val)        REG_FLD_SET(OVL_L1_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32), (val))
#define OVL_L1_TILE_SET_TILE_EN(reg32, val)                    REG_FLD_SET(OVL_L1_TILE_FLD_TILE_EN, (reg32), (val))
#define OVL_L1_TILE_SET_TILE_WIDTH_SEL(reg32, val)             REG_FLD_SET(OVL_L1_TILE_FLD_TILE_WIDTH_SEL, (reg32), (val))
#define OVL_L1_TILE_SET_TILE_HEIGHT(reg32, val)                REG_FLD_SET(OVL_L1_TILE_FLD_TILE_HEIGHT, (reg32), (val))

#define OVL_L1_CLIP_SET_L1_SRC_BOTTOM_CLIP(reg32, val)         REG_FLD_SET(OVL_L1_CLIP_FLD_L1_SRC_BOTTOM_CLIP, (reg32), (val))
#define OVL_L1_CLIP_SET_L1_SRC_TOP_CLIP(reg32, val)            REG_FLD_SET(OVL_L1_CLIP_FLD_L1_SRC_TOP_CLIP, (reg32), (val))
#define OVL_L1_CLIP_SET_L1_SRC_RIGHT_CLIP(reg32, val)          REG_FLD_SET(OVL_L1_CLIP_FLD_L1_SRC_RIGHT_CLIP, (reg32), (val))
#define OVL_L1_CLIP_SET_L1_SRC_LEFT_CLIP(reg32, val)           REG_FLD_SET(OVL_L1_CLIP_FLD_L1_SRC_LEFT_CLIP, (reg32), (val))

#define OVL_L2_CON_SET_DSTKEY_EN(reg32, val)                   REG_FLD_SET(OVL_L2_CON_FLD_DSTKEY_EN, (reg32), (val))
#define OVL_L2_CON_SET_SRCKEY_EN(reg32, val)                   REG_FLD_SET(OVL_L2_CON_FLD_SRCKEY_EN, (reg32), (val))
#define OVL_L2_CON_SET_LAYER_SRC(reg32, val)                   REG_FLD_SET(OVL_L2_CON_FLD_LAYER_SRC, (reg32), (val))
#define OVL_L2_CON_SET_MTX_EN(reg32, val)                      REG_FLD_SET(OVL_L2_CON_FLD_MTX_EN, (reg32), (val))
#define OVL_L2_CON_SET_MTX_AUTO_DIS(reg32, val)                REG_FLD_SET(OVL_L2_CON_FLD_MTX_AUTO_DIS, (reg32), (val))
#define OVL_L2_CON_SET_RGB_SWAP(reg32, val)                    REG_FLD_SET(OVL_L2_CON_FLD_RGB_SWAP, (reg32), (val))
#define OVL_L2_CON_SET_BYTE_SWAP(reg32, val)                   REG_FLD_SET(OVL_L2_CON_FLD_BYTE_SWAP, (reg32), (val))
#define OVL_L2_CON_SET_CLRFMT_MAN(reg32, val)                  REG_FLD_SET(OVL_L2_CON_FLD_CLRFMT_MAN, (reg32), (val))
#define OVL_L2_CON_SET_R_FIRST(reg32, val)                     REG_FLD_SET(OVL_L2_CON_FLD_R_FIRST, (reg32), (val))
#define OVL_L2_CON_SET_LANDSCAPE(reg32, val)                   REG_FLD_SET(OVL_L2_CON_FLD_LANDSCAPE, (reg32), (val))
#define OVL_L2_CON_SET_EN_3D(reg32, val)                       REG_FLD_SET(OVL_L2_CON_FLD_EN_3D, (reg32), (val))
#define OVL_L2_CON_SET_INT_MTX_SEL(reg32, val)                 REG_FLD_SET(OVL_L2_CON_FLD_INT_MTX_SEL, (reg32), (val))
#define OVL_L2_CON_SET_CLRFMT(reg32, val)                      REG_FLD_SET(OVL_L2_CON_FLD_CLRFMT, (reg32), (val))
#define OVL_L2_CON_SET_EXT_MTX_EN(reg32, val)                  REG_FLD_SET(OVL_L2_CON_FLD_EXT_MTX_EN, (reg32), (val))
#define OVL_L2_CON_SET_HORIZONTAL_FLIP_EN(reg32, val)          REG_FLD_SET(OVL_L2_CON_FLD_HORIZONTAL_FLIP_EN, (reg32), (val))
#define OVL_L2_CON_SET_VERTICAL_FLIP_EN(reg32, val)            REG_FLD_SET(OVL_L2_CON_FLD_VERTICAL_FLIP_EN, (reg32), (val))
#define OVL_L2_CON_SET_ALPHA_EN(reg32, val)                    REG_FLD_SET(OVL_L2_CON_FLD_ALPHA_EN, (reg32), (val))
#define OVL_L2_CON_SET_ALPHA(reg32, val)                       REG_FLD_SET(OVL_L2_CON_FLD_ALPHA, (reg32), (val))

#define OVL_L2_SRCKEY_SET_SRCKEY(reg32, val)                   REG_FLD_SET(OVL_L2_SRCKEY_FLD_SRCKEY, (reg32), (val))

#define OVL_L2_SRC_SIZE_SET_L2_SRC_H(reg32, val)               REG_FLD_SET(OVL_L2_SRC_SIZE_FLD_L2_SRC_H, (reg32), (val))
#define OVL_L2_SRC_SIZE_SET_L2_SRC_W(reg32, val)               REG_FLD_SET(OVL_L2_SRC_SIZE_FLD_L2_SRC_W, (reg32), (val))

#define OVL_L2_OFFSET_SET_L2_YOFF(reg32, val)                  REG_FLD_SET(OVL_L2_OFFSET_FLD_L2_YOFF, (reg32), (val))
#define OVL_L2_OFFSET_SET_L2_XOFF(reg32, val)                  REG_FLD_SET(OVL_L2_OFFSET_FLD_L2_XOFF, (reg32), (val))

#define OVL_L2_PITCH_SET_SURFL_EN(reg32, val)                  REG_FLD_SET(OVL_L2_PITCH_FLD_SURFL_EN, (reg32), (val))
#define OVL_L2_PITCH_SET_L2_BLEND_RND_SHT(reg32, val)          REG_FLD_SET(OVL_L2_PITCH_FLD_L2_BLEND_RND_SHT, (reg32), (val))
#define OVL_L2_PITCH_SET_L2_SRGB_SEL_EXT2(reg32, val)          REG_FLD_SET(OVL_L2_PITCH_FLD_L2_SRGB_SEL_EXT2, (reg32), (val))
#define OVL_L2_PITCH_SET_L2_CONST_BLD(reg32, val)              REG_FLD_SET(OVL_L2_PITCH_FLD_L2_CONST_BLD, (reg32), (val))
#define OVL_L2_PITCH_SET_L2_DRGB_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_L2_PITCH_FLD_L2_DRGB_SEL_EXT, (reg32), (val))
#define OVL_L2_PITCH_SET_L2_DA_SEL_EXT(reg32, val)             REG_FLD_SET(OVL_L2_PITCH_FLD_L2_DA_SEL_EXT, (reg32), (val))
#define OVL_L2_PITCH_SET_L2_SRGB_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_L2_PITCH_FLD_L2_SRGB_SEL_EXT, (reg32), (val))
#define OVL_L2_PITCH_SET_L2_SA_SEL_EXT(reg32, val)             REG_FLD_SET(OVL_L2_PITCH_FLD_L2_SA_SEL_EXT, (reg32), (val))
#define OVL_L2_PITCH_SET_L2_DRGB_SEL(reg32, val)               REG_FLD_SET(OVL_L2_PITCH_FLD_L2_DRGB_SEL, (reg32), (val))
#define OVL_L2_PITCH_SET_L2_DA_SEL(reg32, val)                 REG_FLD_SET(OVL_L2_PITCH_FLD_L2_DA_SEL, (reg32), (val))
#define OVL_L2_PITCH_SET_L2_SRGB_SEL(reg32, val)               REG_FLD_SET(OVL_L2_PITCH_FLD_L2_SRGB_SEL, (reg32), (val))
#define OVL_L2_PITCH_SET_L2_SA_SEL(reg32, val)                 REG_FLD_SET(OVL_L2_PITCH_FLD_L2_SA_SEL, (reg32), (val))
#define OVL_L2_PITCH_SET_L2_SRC_PITCH(reg32, val)              REG_FLD_SET(OVL_L2_PITCH_FLD_L2_SRC_PITCH, (reg32), (val))

#define OVL_L2_TILE_SET_TILE_HORI_BLOCK_NUM(reg32, val)        REG_FLD_SET(OVL_L2_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32), (val))
#define OVL_L2_TILE_SET_TILE_EN(reg32, val)                    REG_FLD_SET(OVL_L2_TILE_FLD_TILE_EN, (reg32), (val))
#define OVL_L2_TILE_SET_TILE_WIDTH_SEL(reg32, val)             REG_FLD_SET(OVL_L2_TILE_FLD_TILE_WIDTH_SEL, (reg32), (val))
#define OVL_L2_TILE_SET_TILE_HEIGHT(reg32, val)                REG_FLD_SET(OVL_L2_TILE_FLD_TILE_HEIGHT, (reg32), (val))

#define OVL_L2_CLIP_SET_L2_SRC_BOTTOM_CLIP(reg32, val)         REG_FLD_SET(OVL_L2_CLIP_FLD_L2_SRC_BOTTOM_CLIP, (reg32), (val))
#define OVL_L2_CLIP_SET_L2_SRC_TOP_CLIP(reg32, val)            REG_FLD_SET(OVL_L2_CLIP_FLD_L2_SRC_TOP_CLIP, (reg32), (val))
#define OVL_L2_CLIP_SET_L2_SRC_RIGHT_CLIP(reg32, val)          REG_FLD_SET(OVL_L2_CLIP_FLD_L2_SRC_RIGHT_CLIP, (reg32), (val))
#define OVL_L2_CLIP_SET_L2_SRC_LEFT_CLIP(reg32, val)           REG_FLD_SET(OVL_L2_CLIP_FLD_L2_SRC_LEFT_CLIP, (reg32), (val))

#define OVL_L3_CON_SET_DSTKEY_EN(reg32, val)                   REG_FLD_SET(OVL_L3_CON_FLD_DSTKEY_EN, (reg32), (val))
#define OVL_L3_CON_SET_SRCKEY_EN(reg32, val)                   REG_FLD_SET(OVL_L3_CON_FLD_SRCKEY_EN, (reg32), (val))
#define OVL_L3_CON_SET_LAYER_SRC(reg32, val)                   REG_FLD_SET(OVL_L3_CON_FLD_LAYER_SRC, (reg32), (val))
#define OVL_L3_CON_SET_MTX_EN(reg32, val)                      REG_FLD_SET(OVL_L3_CON_FLD_MTX_EN, (reg32), (val))
#define OVL_L3_CON_SET_MTX_AUTO_DIS(reg32, val)                REG_FLD_SET(OVL_L3_CON_FLD_MTX_AUTO_DIS, (reg32), (val))
#define OVL_L3_CON_SET_RGB_SWAP(reg32, val)                    REG_FLD_SET(OVL_L3_CON_FLD_RGB_SWAP, (reg32), (val))
#define OVL_L3_CON_SET_BYTE_SWAP(reg32, val)                   REG_FLD_SET(OVL_L3_CON_FLD_BYTE_SWAP, (reg32), (val))
#define OVL_L3_CON_SET_CLRFMT_MAN(reg32, val)                  REG_FLD_SET(OVL_L3_CON_FLD_CLRFMT_MAN, (reg32), (val))
#define OVL_L3_CON_SET_R_FIRST(reg32, val)                     REG_FLD_SET(OVL_L3_CON_FLD_R_FIRST, (reg32), (val))
#define OVL_L3_CON_SET_LANDSCAPE(reg32, val)                   REG_FLD_SET(OVL_L3_CON_FLD_LANDSCAPE, (reg32), (val))
#define OVL_L3_CON_SET_EN_3D(reg32, val)                       REG_FLD_SET(OVL_L3_CON_FLD_EN_3D, (reg32), (val))
#define OVL_L3_CON_SET_INT_MTX_SEL(reg32, val)                 REG_FLD_SET(OVL_L3_CON_FLD_INT_MTX_SEL, (reg32), (val))
#define OVL_L3_CON_SET_CLRFMT(reg32, val)                      REG_FLD_SET(OVL_L3_CON_FLD_CLRFMT, (reg32), (val))
#define OVL_L3_CON_SET_EXT_MTX_EN(reg32, val)                  REG_FLD_SET(OVL_L3_CON_FLD_EXT_MTX_EN, (reg32), (val))
#define OVL_L3_CON_SET_HORIZONTAL_FLIP_EN(reg32, val)          REG_FLD_SET(OVL_L3_CON_FLD_HORIZONTAL_FLIP_EN, (reg32), (val))
#define OVL_L3_CON_SET_VERTICAL_FLIP_EN(reg32, val)            REG_FLD_SET(OVL_L3_CON_FLD_VERTICAL_FLIP_EN, (reg32), (val))
#define OVL_L3_CON_SET_ALPHA_EN(reg32, val)                    REG_FLD_SET(OVL_L3_CON_FLD_ALPHA_EN, (reg32), (val))
#define OVL_L3_CON_SET_ALPHA(reg32, val)                       REG_FLD_SET(OVL_L3_CON_FLD_ALPHA, (reg32), (val))

#define OVL_L3_SRCKEY_SET_SRCKEY(reg32, val)                   REG_FLD_SET(OVL_L3_SRCKEY_FLD_SRCKEY, (reg32), (val))

#define OVL_L3_SRC_SIZE_SET_L3_SRC_H(reg32, val)               REG_FLD_SET(OVL_L3_SRC_SIZE_FLD_L3_SRC_H, (reg32), (val))
#define OVL_L3_SRC_SIZE_SET_L3_SRC_W(reg32, val)               REG_FLD_SET(OVL_L3_SRC_SIZE_FLD_L3_SRC_W, (reg32), (val))

#define OVL_L3_OFFSET_SET_L3_YOFF(reg32, val)                  REG_FLD_SET(OVL_L3_OFFSET_FLD_L3_YOFF, (reg32), (val))
#define OVL_L3_OFFSET_SET_L3_XOFF(reg32, val)                  REG_FLD_SET(OVL_L3_OFFSET_FLD_L3_XOFF, (reg32), (val))

#define OVL_L3_PITCH_SET_SURFL_EN(reg32, val)                  REG_FLD_SET(OVL_L3_PITCH_FLD_SURFL_EN, (reg32), (val))
#define OVL_L3_PITCH_SET_L3_BLEND_RND_SHT(reg32, val)          REG_FLD_SET(OVL_L3_PITCH_FLD_L3_BLEND_RND_SHT, (reg32), (val))
#define OVL_L3_PITCH_SET_L3_SRGB_SEL_EXT2(reg32, val)          REG_FLD_SET(OVL_L3_PITCH_FLD_L3_SRGB_SEL_EXT2, (reg32), (val))
#define OVL_L3_PITCH_SET_L3_CONST_BLD(reg32, val)              REG_FLD_SET(OVL_L3_PITCH_FLD_L3_CONST_BLD, (reg32), (val))
#define OVL_L3_PITCH_SET_L3_DRGB_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_L3_PITCH_FLD_L3_DRGB_SEL_EXT, (reg32), (val))
#define OVL_L3_PITCH_SET_L3_DA_SEL_EXT(reg32, val)             REG_FLD_SET(OVL_L3_PITCH_FLD_L3_DA_SEL_EXT, (reg32), (val))
#define OVL_L3_PITCH_SET_L3_SRGB_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_L3_PITCH_FLD_L3_SRGB_SEL_EXT, (reg32), (val))
#define OVL_L3_PITCH_SET_L3_SA_SEL_EXT(reg32, val)             REG_FLD_SET(OVL_L3_PITCH_FLD_L3_SA_SEL_EXT, (reg32), (val))
#define OVL_L3_PITCH_SET_L3_DRGB_SEL(reg32, val)               REG_FLD_SET(OVL_L3_PITCH_FLD_L3_DRGB_SEL, (reg32), (val))
#define OVL_L3_PITCH_SET_L3_DA_SEL(reg32, val)                 REG_FLD_SET(OVL_L3_PITCH_FLD_L3_DA_SEL, (reg32), (val))
#define OVL_L3_PITCH_SET_L3_SRGB_SEL(reg32, val)               REG_FLD_SET(OVL_L3_PITCH_FLD_L3_SRGB_SEL, (reg32), (val))
#define OVL_L3_PITCH_SET_L3_SA_SEL(reg32, val)                 REG_FLD_SET(OVL_L3_PITCH_FLD_L3_SA_SEL, (reg32), (val))
#define OVL_L3_PITCH_SET_L3_SRC_PITCH(reg32, val)              REG_FLD_SET(OVL_L3_PITCH_FLD_L3_SRC_PITCH, (reg32), (val))

#define OVL_L3_TILE_SET_TILE_HORI_BLOCK_NUM(reg32, val)        REG_FLD_SET(OVL_L3_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32), (val))
#define OVL_L3_TILE_SET_TILE_EN(reg32, val)                    REG_FLD_SET(OVL_L3_TILE_FLD_TILE_EN, (reg32), (val))
#define OVL_L3_TILE_SET_TILE_WIDTH_SEL(reg32, val)             REG_FLD_SET(OVL_L3_TILE_FLD_TILE_WIDTH_SEL, (reg32), (val))
#define OVL_L3_TILE_SET_TILE_HEIGHT(reg32, val)                REG_FLD_SET(OVL_L3_TILE_FLD_TILE_HEIGHT, (reg32), (val))

#define OVL_L3_CLIP_SET_L3_SRC_BOTTOM_CLIP(reg32, val)         REG_FLD_SET(OVL_L3_CLIP_FLD_L3_SRC_BOTTOM_CLIP, (reg32), (val))
#define OVL_L3_CLIP_SET_L3_SRC_TOP_CLIP(reg32, val)            REG_FLD_SET(OVL_L3_CLIP_FLD_L3_SRC_TOP_CLIP, (reg32), (val))
#define OVL_L3_CLIP_SET_L3_SRC_RIGHT_CLIP(reg32, val)          REG_FLD_SET(OVL_L3_CLIP_FLD_L3_SRC_RIGHT_CLIP, (reg32), (val))
#define OVL_L3_CLIP_SET_L3_SRC_LEFT_CLIP(reg32, val)           REG_FLD_SET(OVL_L3_CLIP_FLD_L3_SRC_LEFT_CLIP, (reg32), (val))

#define OVL_RDMA0_CTRL_SET_RDMA0_FIFO_USED_SIZE(reg32, val)    REG_FLD_SET(OVL_RDMA0_CTRL_FLD_RDMA0_FIFO_USED_SIZE, (reg32), (val))
#define OVL_RDMA0_CTRL_SET_RDMA0_INTERLACE(reg32, val)         REG_FLD_SET(OVL_RDMA0_CTRL_FLD_RDMA0_INTERLACE, (reg32), (val))
#define OVL_RDMA0_CTRL_SET_RDMA0_EN(reg32, val)                REG_FLD_SET(OVL_RDMA0_CTRL_FLD_RDMA0_EN, (reg32), (val))

#define OVL_RDMA0_MEM_GMC_SETTING1_SET_RDMA0_PRE_ULTRA_THRESHOLD_HIGH_OFS(reg32, val) REG_FLD_SET(OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_PRE_ULTRA_THRESHOLD_HIGH_OFS, (reg32), (val))
#define OVL_RDMA0_MEM_GMC_SETTING1_SET_RDMA0_ULTRA_THRESHOLD_HIGH_OFS(reg32, val) REG_FLD_SET(OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_ULTRA_THRESHOLD_HIGH_OFS, (reg32), (val))
#define OVL_RDMA0_MEM_GMC_SETTING1_SET_RDMA0_OSTD_PREULTRA_TH(reg32, val) REG_FLD_SET(OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_OSTD_PREULTRA_TH, (reg32), (val))
#define OVL_RDMA0_MEM_GMC_SETTING1_SET_RDMA0_OSTD_ULTRA_TH(reg32, val) REG_FLD_SET(OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_OSTD_ULTRA_TH, (reg32), (val))

#define OVL_RDMA0_MEM_SLOW_CON_SET_RDMA0_SLOW_CNT(reg32, val)  REG_FLD_SET(OVL_RDMA0_MEM_SLOW_CON_FLD_RDMA0_SLOW_CNT, (reg32), (val))
#define OVL_RDMA0_MEM_SLOW_CON_SET_RDMA0_SLOW_EN(reg32, val)   REG_FLD_SET(OVL_RDMA0_MEM_SLOW_CON_FLD_RDMA0_SLOW_EN, (reg32), (val))

#define OVL_RDMA0_FIFO_CTRL_SET_RDMA0_FIFO_UND_EN(reg32, val)  REG_FLD_SET(OVL_RDMA0_FIFO_CTRL_FLD_RDMA0_FIFO_UND_EN, (reg32), (val))
#define OVL_RDMA0_FIFO_CTRL_SET_RDMA0_FIFO_SIZE(reg32, val)    REG_FLD_SET(OVL_RDMA0_FIFO_CTRL_FLD_RDMA0_FIFO_SIZE, (reg32), (val))
#define OVL_RDMA0_FIFO_CTRL_SET_RDMA0_FIFO_THRD(reg32, val)    REG_FLD_SET(OVL_RDMA0_FIFO_CTRL_FLD_RDMA0_FIFO_THRD, (reg32), (val))

#define OVL_RDMA1_CTRL_SET_RDMA1_FIFO_USED_SIZE(reg32, val)    REG_FLD_SET(OVL_RDMA1_CTRL_FLD_RDMA1_FIFO_USED_SIZE, (reg32), (val))
#define OVL_RDMA1_CTRL_SET_RDMA1_INTERLACE(reg32, val)         REG_FLD_SET(OVL_RDMA1_CTRL_FLD_RDMA1_INTERLACE, (reg32), (val))
#define OVL_RDMA1_CTRL_SET_RDMA1_EN(reg32, val)                REG_FLD_SET(OVL_RDMA1_CTRL_FLD_RDMA1_EN, (reg32), (val))

#define OVL_RDMA1_MEM_GMC_SETTING1_SET_RDMA1_PRE_ULTRA_THRESHOLD_HIGH_OFS(reg32, val) REG_FLD_SET(OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_PRE_ULTRA_THRESHOLD_HIGH_OFS, (reg32), (val))
#define OVL_RDMA1_MEM_GMC_SETTING1_SET_RDMA1_ULTRA_THRESHOLD_HIGH_OFS(reg32, val) REG_FLD_SET(OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_ULTRA_THRESHOLD_HIGH_OFS, (reg32), (val))
#define OVL_RDMA1_MEM_GMC_SETTING1_SET_RDMA1_OSTD_PREULTRA_TH(reg32, val) REG_FLD_SET(OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_OSTD_PREULTRA_TH, (reg32), (val))
#define OVL_RDMA1_MEM_GMC_SETTING1_SET_RDMA1_OSTD_ULTRA_TH(reg32, val) REG_FLD_SET(OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_OSTD_ULTRA_TH, (reg32), (val))

#define OVL_RDMA1_MEM_SLOW_CON_SET_RDMA1_SLOW_CNT(reg32, val)  REG_FLD_SET(OVL_RDMA1_MEM_SLOW_CON_FLD_RDMA1_SLOW_CNT, (reg32), (val))
#define OVL_RDMA1_MEM_SLOW_CON_SET_RDMA1_SLOW_EN(reg32, val)   REG_FLD_SET(OVL_RDMA1_MEM_SLOW_CON_FLD_RDMA1_SLOW_EN, (reg32), (val))

#define OVL_RDMA1_FIFO_CTRL_SET_RDMA1_FIFO_UND_EN(reg32, val)  REG_FLD_SET(OVL_RDMA1_FIFO_CTRL_FLD_RDMA1_FIFO_UND_EN, (reg32), (val))
#define OVL_RDMA1_FIFO_CTRL_SET_RDMA1_FIFO_SIZE(reg32, val)    REG_FLD_SET(OVL_RDMA1_FIFO_CTRL_FLD_RDMA1_FIFO_SIZE, (reg32), (val))
#define OVL_RDMA1_FIFO_CTRL_SET_RDMA1_FIFO_THRD(reg32, val)    REG_FLD_SET(OVL_RDMA1_FIFO_CTRL_FLD_RDMA1_FIFO_THRD, (reg32), (val))

#define OVL_RDMA2_CTRL_SET_RDMA2_FIFO_USED_SIZE(reg32, val)    REG_FLD_SET(OVL_RDMA2_CTRL_FLD_RDMA2_FIFO_USED_SIZE, (reg32), (val))
#define OVL_RDMA2_CTRL_SET_RDMA2_INTERLACE(reg32, val)         REG_FLD_SET(OVL_RDMA2_CTRL_FLD_RDMA2_INTERLACE, (reg32), (val))
#define OVL_RDMA2_CTRL_SET_RDMA2_EN(reg32, val)                REG_FLD_SET(OVL_RDMA2_CTRL_FLD_RDMA2_EN, (reg32), (val))

#define OVL_RDMA2_MEM_GMC_SETTING1_SET_RDMA2_PRE_ULTRA_THRESHOLD_HIGH_OFS(reg32, val) REG_FLD_SET(OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_PRE_ULTRA_THRESHOLD_HIGH_OFS, (reg32), (val))
#define OVL_RDMA2_MEM_GMC_SETTING1_SET_RDMA2_ULTRA_THRESHOLD_HIGH_OFS(reg32, val) REG_FLD_SET(OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_ULTRA_THRESHOLD_HIGH_OFS, (reg32), (val))
#define OVL_RDMA2_MEM_GMC_SETTING1_SET_RDMA2_OSTD_PREULTRA_TH(reg32, val) REG_FLD_SET(OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_OSTD_PREULTRA_TH, (reg32), (val))
#define OVL_RDMA2_MEM_GMC_SETTING1_SET_RDMA2_OSTD_ULTRA_TH(reg32, val) REG_FLD_SET(OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_OSTD_ULTRA_TH, (reg32), (val))

#define OVL_RDMA2_MEM_SLOW_CON_SET_RDMA2_SLOW_CNT(reg32, val)  REG_FLD_SET(OVL_RDMA2_MEM_SLOW_CON_FLD_RDMA2_SLOW_CNT, (reg32), (val))
#define OVL_RDMA2_MEM_SLOW_CON_SET_RDMA2_SLOW_EN(reg32, val)   REG_FLD_SET(OVL_RDMA2_MEM_SLOW_CON_FLD_RDMA2_SLOW_EN, (reg32), (val))

#define OVL_RDMA2_FIFO_CTRL_SET_RDMA2_FIFO_UND_EN(reg32, val)  REG_FLD_SET(OVL_RDMA2_FIFO_CTRL_FLD_RDMA2_FIFO_UND_EN, (reg32), (val))
#define OVL_RDMA2_FIFO_CTRL_SET_RDMA2_FIFO_SIZE(reg32, val)    REG_FLD_SET(OVL_RDMA2_FIFO_CTRL_FLD_RDMA2_FIFO_SIZE, (reg32), (val))
#define OVL_RDMA2_FIFO_CTRL_SET_RDMA2_FIFO_THRD(reg32, val)    REG_FLD_SET(OVL_RDMA2_FIFO_CTRL_FLD_RDMA2_FIFO_THRD, (reg32), (val))

#define OVL_RDMA3_CTRL_SET_RDMA3_FIFO_USED_SIZE(reg32, val)    REG_FLD_SET(OVL_RDMA3_CTRL_FLD_RDMA3_FIFO_USED_SIZE, (reg32), (val))
#define OVL_RDMA3_CTRL_SET_RDMA3_INTERLACE(reg32, val)         REG_FLD_SET(OVL_RDMA3_CTRL_FLD_RDMA3_INTERLACE, (reg32), (val))
#define OVL_RDMA3_CTRL_SET_RDMA3_EN(reg32, val)                REG_FLD_SET(OVL_RDMA3_CTRL_FLD_RDMA3_EN, (reg32), (val))

#define OVL_RDMA3_MEM_GMC_SETTING1_SET_RDMA3_PRE_ULTRA_THRESHOLD_HIGH_OFS(reg32, val) REG_FLD_SET(OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_PRE_ULTRA_THRESHOLD_HIGH_OFS, (reg32), (val))
#define OVL_RDMA3_MEM_GMC_SETTING1_SET_RDMA3_ULTRA_THRESHOLD_HIGH_OFS(reg32, val) REG_FLD_SET(OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_ULTRA_THRESHOLD_HIGH_OFS, (reg32), (val))
#define OVL_RDMA3_MEM_GMC_SETTING1_SET_RDMA3_OSTD_PREULTRA_TH(reg32, val) REG_FLD_SET(OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_OSTD_PREULTRA_TH, (reg32), (val))
#define OVL_RDMA3_MEM_GMC_SETTING1_SET_RDMA3_OSTD_ULTRA_TH(reg32, val) REG_FLD_SET(OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_OSTD_ULTRA_TH, (reg32), (val))

#define OVL_RDMA3_MEM_SLOW_CON_SET_RDMA3_SLOW_CNT(reg32, val)  REG_FLD_SET(OVL_RDMA3_MEM_SLOW_CON_FLD_RDMA3_SLOW_CNT, (reg32), (val))
#define OVL_RDMA3_MEM_SLOW_CON_SET_RDMA3_SLOW_EN(reg32, val)   REG_FLD_SET(OVL_RDMA3_MEM_SLOW_CON_FLD_RDMA3_SLOW_EN, (reg32), (val))

#define OVL_RDMA3_FIFO_CTRL_SET_RDMA3_FIFO_UND_EN(reg32, val)  REG_FLD_SET(OVL_RDMA3_FIFO_CTRL_FLD_RDMA3_FIFO_UND_EN, (reg32), (val))
#define OVL_RDMA3_FIFO_CTRL_SET_RDMA3_FIFO_SIZE(reg32, val)    REG_FLD_SET(OVL_RDMA3_FIFO_CTRL_FLD_RDMA3_FIFO_SIZE, (reg32), (val))
#define OVL_RDMA3_FIFO_CTRL_SET_RDMA3_FIFO_THRD(reg32, val)    REG_FLD_SET(OVL_RDMA3_FIFO_CTRL_FLD_RDMA3_FIFO_THRD, (reg32), (val))

#define OVL_L0_Y2R_PARA_R0_SET_C_CF_RMU(reg32, val)            REG_FLD_SET(OVL_L0_Y2R_PARA_R0_FLD_C_CF_RMU, (reg32), (val))
#define OVL_L0_Y2R_PARA_R0_SET_C_CF_RMY(reg32, val)            REG_FLD_SET(OVL_L0_Y2R_PARA_R0_FLD_C_CF_RMY, (reg32), (val))

#define OVL_L0_Y2R_PARA_R1_SET_C_CF_RMV(reg32, val)            REG_FLD_SET(OVL_L0_Y2R_PARA_R1_FLD_C_CF_RMV, (reg32), (val))

#define OVL_L0_Y2R_PARA_G0_SET_C_CF_GMU(reg32, val)            REG_FLD_SET(OVL_L0_Y2R_PARA_G0_FLD_C_CF_GMU, (reg32), (val))
#define OVL_L0_Y2R_PARA_G0_SET_C_CF_GMY(reg32, val)            REG_FLD_SET(OVL_L0_Y2R_PARA_G0_FLD_C_CF_GMY, (reg32), (val))

#define OVL_L0_Y2R_PARA_G1_SET_C_CF_GMV(reg32, val)            REG_FLD_SET(OVL_L0_Y2R_PARA_G1_FLD_C_CF_GMV, (reg32), (val))

#define OVL_L0_Y2R_PARA_B0_SET_C_CF_BMU(reg32, val)            REG_FLD_SET(OVL_L0_Y2R_PARA_B0_FLD_C_CF_BMU, (reg32), (val))
#define OVL_L0_Y2R_PARA_B0_SET_C_CF_BMY(reg32, val)            REG_FLD_SET(OVL_L0_Y2R_PARA_B0_FLD_C_CF_BMY, (reg32), (val))

#define OVL_L0_Y2R_PARA_B1_SET_C_CF_BMV(reg32, val)            REG_FLD_SET(OVL_L0_Y2R_PARA_B1_FLD_C_CF_BMV, (reg32), (val))

#define OVL_L0_Y2R_PARA_YUV_A_0_SET_C_CF_UA(reg32, val)        REG_FLD_SET(OVL_L0_Y2R_PARA_YUV_A_0_FLD_C_CF_UA, (reg32), (val))
#define OVL_L0_Y2R_PARA_YUV_A_0_SET_C_CF_YA(reg32, val)        REG_FLD_SET(OVL_L0_Y2R_PARA_YUV_A_0_FLD_C_CF_YA, (reg32), (val))

#define OVL_L0_Y2R_PARA_YUV_A_1_SET_C_CF_VA(reg32, val)        REG_FLD_SET(OVL_L0_Y2R_PARA_YUV_A_1_FLD_C_CF_VA, (reg32), (val))

#define OVL_L0_Y2R_PARA_RGB_A_0_SET_C_CF_GA(reg32, val)        REG_FLD_SET(OVL_L0_Y2R_PARA_RGB_A_0_FLD_C_CF_GA, (reg32), (val))
#define OVL_L0_Y2R_PARA_RGB_A_0_SET_C_CF_RA(reg32, val)        REG_FLD_SET(OVL_L0_Y2R_PARA_RGB_A_0_FLD_C_CF_RA, (reg32), (val))

#define OVL_L0_Y2R_PARA_RGB_A_1_SET_C_CF_BA(reg32, val)        REG_FLD_SET(OVL_L0_Y2R_PARA_RGB_A_1_FLD_C_CF_BA, (reg32), (val))

#define OVL_L1_Y2R_PARA_R0_SET_C_CF_RMU(reg32, val)            REG_FLD_SET(OVL_L1_Y2R_PARA_R0_FLD_C_CF_RMU, (reg32), (val))
#define OVL_L1_Y2R_PARA_R0_SET_C_CF_RMY(reg32, val)            REG_FLD_SET(OVL_L1_Y2R_PARA_R0_FLD_C_CF_RMY, (reg32), (val))

#define OVL_L1_Y2R_PARA_R1_SET_C_CF_RMV(reg32, val)            REG_FLD_SET(OVL_L1_Y2R_PARA_R1_FLD_C_CF_RMV, (reg32), (val))

#define OVL_L1_Y2R_PARA_G0_SET_C_CF_GMU(reg32, val)            REG_FLD_SET(OVL_L1_Y2R_PARA_G0_FLD_C_CF_GMU, (reg32), (val))
#define OVL_L1_Y2R_PARA_G0_SET_C_CF_GMY(reg32, val)            REG_FLD_SET(OVL_L1_Y2R_PARA_G0_FLD_C_CF_GMY, (reg32), (val))

#define OVL_L1_Y2R_PARA_G1_SET_C_CF_GMV(reg32, val)            REG_FLD_SET(OVL_L1_Y2R_PARA_G1_FLD_C_CF_GMV, (reg32), (val))

#define OVL_L1_Y2R_PARA_B0_SET_C_CF_BMU(reg32, val)            REG_FLD_SET(OVL_L1_Y2R_PARA_B0_FLD_C_CF_BMU, (reg32), (val))
#define OVL_L1_Y2R_PARA_B0_SET_C_CF_BMY(reg32, val)            REG_FLD_SET(OVL_L1_Y2R_PARA_B0_FLD_C_CF_BMY, (reg32), (val))

#define OVL_L1_Y2R_PARA_B1_SET_C_CF_BMV(reg32, val)            REG_FLD_SET(OVL_L1_Y2R_PARA_B1_FLD_C_CF_BMV, (reg32), (val))

#define OVL_L1_Y2R_PARA_YUV_A_0_SET_C_CF_UA(reg32, val)        REG_FLD_SET(OVL_L1_Y2R_PARA_YUV_A_0_FLD_C_CF_UA, (reg32), (val))
#define OVL_L1_Y2R_PARA_YUV_A_0_SET_C_CF_YA(reg32, val)        REG_FLD_SET(OVL_L1_Y2R_PARA_YUV_A_0_FLD_C_CF_YA, (reg32), (val))

#define OVL_L1_Y2R_PARA_YUV_A_1_SET_C_CF_VA(reg32, val)        REG_FLD_SET(OVL_L1_Y2R_PARA_YUV_A_1_FLD_C_CF_VA, (reg32), (val))

#define OVL_L1_Y2R_PARA_RGB_A_0_SET_C_CF_GA(reg32, val)        REG_FLD_SET(OVL_L1_Y2R_PARA_RGB_A_0_FLD_C_CF_GA, (reg32), (val))
#define OVL_L1_Y2R_PARA_RGB_A_0_SET_C_CF_RA(reg32, val)        REG_FLD_SET(OVL_L1_Y2R_PARA_RGB_A_0_FLD_C_CF_RA, (reg32), (val))

#define OVL_L1_Y2R_PARA_RGB_A_1_SET_C_CF_BA(reg32, val)        REG_FLD_SET(OVL_L1_Y2R_PARA_RGB_A_1_FLD_C_CF_BA, (reg32), (val))

#define OVL_L2_Y2R_PARA_R0_SET_C_CF_RMU(reg32, val)            REG_FLD_SET(OVL_L2_Y2R_PARA_R0_FLD_C_CF_RMU, (reg32), (val))
#define OVL_L2_Y2R_PARA_R0_SET_C_CF_RMY(reg32, val)            REG_FLD_SET(OVL_L2_Y2R_PARA_R0_FLD_C_CF_RMY, (reg32), (val))

#define OVL_L2_Y2R_PARA_R1_SET_C_CF_RMV(reg32, val)            REG_FLD_SET(OVL_L2_Y2R_PARA_R1_FLD_C_CF_RMV, (reg32), (val))

#define OVL_L2_Y2R_PARA_G0_SET_C_CF_GMU(reg32, val)            REG_FLD_SET(OVL_L2_Y2R_PARA_G0_FLD_C_CF_GMU, (reg32), (val))
#define OVL_L2_Y2R_PARA_G0_SET_C_CF_GMY(reg32, val)            REG_FLD_SET(OVL_L2_Y2R_PARA_G0_FLD_C_CF_GMY, (reg32), (val))

#define OVL_L2_Y2R_PARA_G1_SET_C_CF_GMV(reg32, val)            REG_FLD_SET(OVL_L2_Y2R_PARA_G1_FLD_C_CF_GMV, (reg32), (val))

#define OVL_L2_Y2R_PARA_B0_SET_C_CF_BMU(reg32, val)            REG_FLD_SET(OVL_L2_Y2R_PARA_B0_FLD_C_CF_BMU, (reg32), (val))
#define OVL_L2_Y2R_PARA_B0_SET_C_CF_BMY(reg32, val)            REG_FLD_SET(OVL_L2_Y2R_PARA_B0_FLD_C_CF_BMY, (reg32), (val))

#define OVL_L2_Y2R_PARA_B1_SET_C_CF_BMV(reg32, val)            REG_FLD_SET(OVL_L2_Y2R_PARA_B1_FLD_C_CF_BMV, (reg32), (val))

#define OVL_L2_Y2R_PARA_YUV_A_0_SET_C_CF_UA(reg32, val)        REG_FLD_SET(OVL_L2_Y2R_PARA_YUV_A_0_FLD_C_CF_UA, (reg32), (val))
#define OVL_L2_Y2R_PARA_YUV_A_0_SET_C_CF_YA(reg32, val)        REG_FLD_SET(OVL_L2_Y2R_PARA_YUV_A_0_FLD_C_CF_YA, (reg32), (val))

#define OVL_L2_Y2R_PARA_YUV_A_1_SET_C_CF_VA(reg32, val)        REG_FLD_SET(OVL_L2_Y2R_PARA_YUV_A_1_FLD_C_CF_VA, (reg32), (val))

#define OVL_L2_Y2R_PARA_RGB_A_0_SET_C_CF_GA(reg32, val)        REG_FLD_SET(OVL_L2_Y2R_PARA_RGB_A_0_FLD_C_CF_GA, (reg32), (val))
#define OVL_L2_Y2R_PARA_RGB_A_0_SET_C_CF_RA(reg32, val)        REG_FLD_SET(OVL_L2_Y2R_PARA_RGB_A_0_FLD_C_CF_RA, (reg32), (val))

#define OVL_L2_Y2R_PARA_RGB_A_1_SET_C_CF_BA(reg32, val)        REG_FLD_SET(OVL_L2_Y2R_PARA_RGB_A_1_FLD_C_CF_BA, (reg32), (val))

#define OVL_L3_Y2R_PARA_R0_SET_C_CF_RMU(reg32, val)            REG_FLD_SET(OVL_L3_Y2R_PARA_R0_FLD_C_CF_RMU, (reg32), (val))
#define OVL_L3_Y2R_PARA_R0_SET_C_CF_RMY(reg32, val)            REG_FLD_SET(OVL_L3_Y2R_PARA_R0_FLD_C_CF_RMY, (reg32), (val))

#define OVL_L3_Y2R_PARA_R1_SET_C_CF_RMV(reg32, val)            REG_FLD_SET(OVL_L3_Y2R_PARA_R1_FLD_C_CF_RMV, (reg32), (val))

#define OVL_L3_Y2R_PARA_G0_SET_C_CF_GMU(reg32, val)            REG_FLD_SET(OVL_L3_Y2R_PARA_G0_FLD_C_CF_GMU, (reg32), (val))
#define OVL_L3_Y2R_PARA_G0_SET_C_CF_GMY(reg32, val)            REG_FLD_SET(OVL_L3_Y2R_PARA_G0_FLD_C_CF_GMY, (reg32), (val))

#define OVL_L3_Y2R_PARA_G1_SET_C_CF_GMV(reg32, val)            REG_FLD_SET(OVL_L3_Y2R_PARA_G1_FLD_C_CF_GMV, (reg32), (val))

#define OVL_L3_Y2R_PARA_B0_SET_C_CF_BMU(reg32, val)            REG_FLD_SET(OVL_L3_Y2R_PARA_B0_FLD_C_CF_BMU, (reg32), (val))
#define OVL_L3_Y2R_PARA_B0_SET_C_CF_BMY(reg32, val)            REG_FLD_SET(OVL_L3_Y2R_PARA_B0_FLD_C_CF_BMY, (reg32), (val))

#define OVL_L3_Y2R_PARA_B1_SET_C_CF_BMV(reg32, val)            REG_FLD_SET(OVL_L3_Y2R_PARA_B1_FLD_C_CF_BMV, (reg32), (val))

#define OVL_L3_Y2R_PARA_YUV_A_0_SET_C_CF_UA(reg32, val)        REG_FLD_SET(OVL_L3_Y2R_PARA_YUV_A_0_FLD_C_CF_UA, (reg32), (val))
#define OVL_L3_Y2R_PARA_YUV_A_0_SET_C_CF_YA(reg32, val)        REG_FLD_SET(OVL_L3_Y2R_PARA_YUV_A_0_FLD_C_CF_YA, (reg32), (val))

#define OVL_L3_Y2R_PARA_YUV_A_1_SET_C_CF_VA(reg32, val)        REG_FLD_SET(OVL_L3_Y2R_PARA_YUV_A_1_FLD_C_CF_VA, (reg32), (val))

#define OVL_L3_Y2R_PARA_RGB_A_0_SET_C_CF_GA(reg32, val)        REG_FLD_SET(OVL_L3_Y2R_PARA_RGB_A_0_FLD_C_CF_GA, (reg32), (val))
#define OVL_L3_Y2R_PARA_RGB_A_0_SET_C_CF_RA(reg32, val)        REG_FLD_SET(OVL_L3_Y2R_PARA_RGB_A_0_FLD_C_CF_RA, (reg32), (val))

#define OVL_L3_Y2R_PARA_RGB_A_1_SET_C_CF_BA(reg32, val)        REG_FLD_SET(OVL_L3_Y2R_PARA_RGB_A_1_FLD_C_CF_BA, (reg32), (val))

#define OVL_DEBUG_MON_SEL_SET_DBG_MON_SEL(reg32, val)          REG_FLD_SET(OVL_DEBUG_MON_SEL_FLD_DBG_MON_SEL, (reg32), (val))

#define OVL_BLD_EXT_SET_EL2_MINUS_BLD(reg32, val)              REG_FLD_SET(OVL_BLD_EXT_FLD_EL2_MINUS_BLD, (reg32), (val))
#define OVL_BLD_EXT_SET_EL1_MINUS_BLD(reg32, val)              REG_FLD_SET(OVL_BLD_EXT_FLD_EL1_MINUS_BLD, (reg32), (val))
#define OVL_BLD_EXT_SET_EL0_MINUS_BLD(reg32, val)              REG_FLD_SET(OVL_BLD_EXT_FLD_EL0_MINUS_BLD, (reg32), (val))
#define OVL_BLD_EXT_SET_LC_MINUS_BLD(reg32, val)               REG_FLD_SET(OVL_BLD_EXT_FLD_LC_MINUS_BLD, (reg32), (val))
#define OVL_BLD_EXT_SET_L3_MINUS_BLD(reg32, val)               REG_FLD_SET(OVL_BLD_EXT_FLD_L3_MINUS_BLD, (reg32), (val))
#define OVL_BLD_EXT_SET_L2_MINUS_BLD(reg32, val)               REG_FLD_SET(OVL_BLD_EXT_FLD_L2_MINUS_BLD, (reg32), (val))
#define OVL_BLD_EXT_SET_L1_MINUS_BLD(reg32, val)               REG_FLD_SET(OVL_BLD_EXT_FLD_L1_MINUS_BLD, (reg32), (val))
#define OVL_BLD_EXT_SET_L0_MINUS_BLD(reg32, val)               REG_FLD_SET(OVL_BLD_EXT_FLD_L0_MINUS_BLD, (reg32), (val))

#define OVL_RDMA0_MEM_GMC_SETTING2_SET_RDMA0_FORCE_REQ_THRESHOLD(reg32, val) REG_FLD_SET(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_FORCE_REQ_THRESHOLD, (reg32), (val))
#define OVL_RDMA0_MEM_GMC_SETTING2_SET_RDMA0_REQ_THRESHOLD_ULTRA(reg32, val) REG_FLD_SET(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_REQ_THRESHOLD_ULTRA, (reg32), (val))
#define OVL_RDMA0_MEM_GMC_SETTING2_SET_RDMA0_REQ_THRESHOLD_PREULTRA(reg32, val) REG_FLD_SET(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_REQ_THRESHOLD_PREULTRA, (reg32), (val))
#define OVL_RDMA0_MEM_GMC_SETTING2_SET_RDMA0_ISSUE_REQ_THRESHOLD_URG(reg32, val) REG_FLD_SET(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_ISSUE_REQ_THRESHOLD_URG, (reg32), (val))
#define OVL_RDMA0_MEM_GMC_SETTING2_SET_RDMA0_ISSUE_REQ_THRESHOLD(reg32, val) REG_FLD_SET(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_ISSUE_REQ_THRESHOLD, (reg32), (val))

#define OVL_RDMA1_MEM_GMC_SETTING2_SET_RDMA1_FORCE_REQ_THRESHOLD(reg32, val) REG_FLD_SET(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_FORCE_REQ_THRESHOLD, (reg32), (val))
#define OVL_RDMA1_MEM_GMC_SETTING2_SET_RDMA1_REQ_THRESHOLD_ULTRA(reg32, val) REG_FLD_SET(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_REQ_THRESHOLD_ULTRA, (reg32), (val))
#define OVL_RDMA1_MEM_GMC_SETTING2_SET_RDMA1_REQ_THRESHOLD_PREULTRA(reg32, val) REG_FLD_SET(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_REQ_THRESHOLD_PREULTRA, (reg32), (val))
#define OVL_RDMA1_MEM_GMC_SETTING2_SET_RDMA1_ISSUE_REQ_THRESHOLD_URG(reg32, val) REG_FLD_SET(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_ISSUE_REQ_THRESHOLD_URG, (reg32), (val))
#define OVL_RDMA1_MEM_GMC_SETTING2_SET_RDMA1_ISSUE_REQ_THRESHOLD(reg32, val) REG_FLD_SET(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_ISSUE_REQ_THRESHOLD, (reg32), (val))

#define OVL_RDMA2_MEM_GMC_SETTING2_SET_RDMA2_FORCE_REQ_THRESHOLD(reg32, val) REG_FLD_SET(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_FORCE_REQ_THRESHOLD, (reg32), (val))
#define OVL_RDMA2_MEM_GMC_SETTING2_SET_RDMA2_REQ_THRESHOLD_ULTRA(reg32, val) REG_FLD_SET(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_REQ_THRESHOLD_ULTRA, (reg32), (val))
#define OVL_RDMA2_MEM_GMC_SETTING2_SET_RDMA2_REQ_THRESHOLD_PREULTRA(reg32, val) REG_FLD_SET(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_REQ_THRESHOLD_PREULTRA, (reg32), (val))
#define OVL_RDMA2_MEM_GMC_SETTING2_SET_RDMA2_ISSUE_REQ_THRESHOLD_URG(reg32, val) REG_FLD_SET(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_ISSUE_REQ_THRESHOLD_URG, (reg32), (val))
#define OVL_RDMA2_MEM_GMC_SETTING2_SET_RDMA2_ISSUE_REQ_THRESHOLD(reg32, val) REG_FLD_SET(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_ISSUE_REQ_THRESHOLD, (reg32), (val))

#define OVL_RDMA3_MEM_GMC_SETTING2_SET_RDMA3_FORCE_REQ_THRESHOLD(reg32, val) REG_FLD_SET(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_FORCE_REQ_THRESHOLD, (reg32), (val))
#define OVL_RDMA3_MEM_GMC_SETTING2_SET_RDMA3_REQ_THRESHOLD_ULTRA(reg32, val) REG_FLD_SET(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_REQ_THRESHOLD_ULTRA, (reg32), (val))
#define OVL_RDMA3_MEM_GMC_SETTING2_SET_RDMA3_REQ_THRESHOLD_PREULTRA(reg32, val) REG_FLD_SET(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_REQ_THRESHOLD_PREULTRA, (reg32), (val))
#define OVL_RDMA3_MEM_GMC_SETTING2_SET_RDMA3_ISSUE_REQ_THRESHOLD_URG(reg32, val) REG_FLD_SET(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_ISSUE_REQ_THRESHOLD_URG, (reg32), (val))
#define OVL_RDMA3_MEM_GMC_SETTING2_SET_RDMA3_ISSUE_REQ_THRESHOLD(reg32, val) REG_FLD_SET(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_ISSUE_REQ_THRESHOLD, (reg32), (val))

#define OVL_RDMA_BURST_CON0_SET_BURST_128B_BOUND(reg32, val)   REG_FLD_SET(OVL_RDMA_BURST_CON0_FLD_BURST_128B_BOUND, (reg32), (val))
#define OVL_RDMA_BURST_CON0_SET_BURST15A_32B(reg32, val)       REG_FLD_SET(OVL_RDMA_BURST_CON0_FLD_BURST15A_32B, (reg32), (val))
#define OVL_RDMA_BURST_CON0_SET_BURST14A_32B(reg32, val)       REG_FLD_SET(OVL_RDMA_BURST_CON0_FLD_BURST14A_32B, (reg32), (val))
#define OVL_RDMA_BURST_CON0_SET_BURST13A_32B(reg32, val)       REG_FLD_SET(OVL_RDMA_BURST_CON0_FLD_BURST13A_32B, (reg32), (val))
#define OVL_RDMA_BURST_CON0_SET_BURST12A_32B(reg32, val)       REG_FLD_SET(OVL_RDMA_BURST_CON0_FLD_BURST12A_32B, (reg32), (val))
#define OVL_RDMA_BURST_CON0_SET_BURST11A_32B(reg32, val)       REG_FLD_SET(OVL_RDMA_BURST_CON0_FLD_BURST11A_32B, (reg32), (val))
#define OVL_RDMA_BURST_CON0_SET_BURST10A_32B(reg32, val)       REG_FLD_SET(OVL_RDMA_BURST_CON0_FLD_BURST10A_32B, (reg32), (val))
#define OVL_RDMA_BURST_CON0_SET_BURST9A_32B(reg32, val)        REG_FLD_SET(OVL_RDMA_BURST_CON0_FLD_BURST9A_32B, (reg32), (val))

#define OVL_RDMA_BURST_CON1_SET_BURST15A_N32B(reg32, val)      REG_FLD_SET(OVL_RDMA_BURST_CON1_FLD_BURST15A_N32B, (reg32), (val))
#define OVL_RDMA_BURST_CON1_SET_BURST14A_N32B(reg32, val)      REG_FLD_SET(OVL_RDMA_BURST_CON1_FLD_BURST14A_N32B, (reg32), (val))
#define OVL_RDMA_BURST_CON1_SET_BURST13A_N32B(reg32, val)      REG_FLD_SET(OVL_RDMA_BURST_CON1_FLD_BURST13A_N32B, (reg32), (val))
#define OVL_RDMA_BURST_CON1_SET_BURST12A_N32B(reg32, val)      REG_FLD_SET(OVL_RDMA_BURST_CON1_FLD_BURST12A_N32B, (reg32), (val))
#define OVL_RDMA_BURST_CON1_SET_BURST11A_N32B(reg32, val)      REG_FLD_SET(OVL_RDMA_BURST_CON1_FLD_BURST11A_N32B, (reg32), (val))
#define OVL_RDMA_BURST_CON1_SET_BURST10A_N32B(reg32, val)      REG_FLD_SET(OVL_RDMA_BURST_CON1_FLD_BURST10A_N32B, (reg32), (val))
#define OVL_RDMA_BURST_CON1_SET_BURST9A_N32B(reg32, val)       REG_FLD_SET(OVL_RDMA_BURST_CON1_FLD_BURST9A_N32B, (reg32), (val))

#define OVL_RDMA_GREQ_NUM_SET_IOBUF_FLUSH_ULTRA(reg32, val)    REG_FLD_SET(OVL_RDMA_GREQ_NUM_FLD_IOBUF_FLUSH_ULTRA, (reg32), (val))
#define OVL_RDMA_GREQ_NUM_SET_IOBUF_FLUSH_PREULTRA(reg32, val) REG_FLD_SET(OVL_RDMA_GREQ_NUM_FLD_IOBUF_FLUSH_PREULTRA, (reg32), (val))
#define OVL_RDMA_GREQ_NUM_SET_GRP_BRK_STOP(reg32, val)         REG_FLD_SET(OVL_RDMA_GREQ_NUM_FLD_GRP_BRK_STOP, (reg32), (val))
#define OVL_RDMA_GREQ_NUM_SET_GRP_END_STOP(reg32, val)         REG_FLD_SET(OVL_RDMA_GREQ_NUM_FLD_GRP_END_STOP, (reg32), (val))
#define OVL_RDMA_GREQ_NUM_SET_GREQ_STOP_EN(reg32, val)         REG_FLD_SET(OVL_RDMA_GREQ_NUM_FLD_GREQ_STOP_EN, (reg32), (val))
#define OVL_RDMA_GREQ_NUM_SET_GREQ_DIS_CNT(reg32, val)         REG_FLD_SET(OVL_RDMA_GREQ_NUM_FLD_GREQ_DIS_CNT, (reg32), (val))
#define OVL_RDMA_GREQ_NUM_SET_OSTD_GREQ_NUM(reg32, val)        REG_FLD_SET(OVL_RDMA_GREQ_NUM_FLD_OSTD_GREQ_NUM, (reg32), (val))
#define OVL_RDMA_GREQ_NUM_SET_LAYER3_GREQ_NUM(reg32, val)      REG_FLD_SET(OVL_RDMA_GREQ_NUM_FLD_LAYER3_GREQ_NUM, (reg32), (val))
#define OVL_RDMA_GREQ_NUM_SET_LAYER2_GREQ_NUM(reg32, val)      REG_FLD_SET(OVL_RDMA_GREQ_NUM_FLD_LAYER2_GREQ_NUM, (reg32), (val))
#define OVL_RDMA_GREQ_NUM_SET_LAYER1_GREQ_NUM(reg32, val)      REG_FLD_SET(OVL_RDMA_GREQ_NUM_FLD_LAYER1_GREQ_NUM, (reg32), (val))
#define OVL_RDMA_GREQ_NUM_SET_LAYER0_GREQ_NUM(reg32, val)      REG_FLD_SET(OVL_RDMA_GREQ_NUM_FLD_LAYER0_GREQ_NUM, (reg32), (val))

#define OVL_RDMA_GREQ_URG_NUM_SET_GREQ_NUM_SHT(reg32, val)     REG_FLD_SET(OVL_RDMA_GREQ_URG_NUM_FLD_GREQ_NUM_SHT, (reg32), (val))
#define OVL_RDMA_GREQ_URG_NUM_SET_GREQ_NUM_SHT_VAL(reg32, val) REG_FLD_SET(OVL_RDMA_GREQ_URG_NUM_FLD_GREQ_NUM_SHT_VAL, (reg32), (val))
#define OVL_RDMA_GREQ_URG_NUM_SET_ARG_URG_BIAS(reg32, val)     REG_FLD_SET(OVL_RDMA_GREQ_URG_NUM_FLD_ARG_URG_BIAS, (reg32), (val))
#define OVL_RDMA_GREQ_URG_NUM_SET_ARG_GREQ_URG_TH(reg32, val)  REG_FLD_SET(OVL_RDMA_GREQ_URG_NUM_FLD_ARG_GREQ_URG_TH, (reg32), (val))
#define OVL_RDMA_GREQ_URG_NUM_SET_LAYER3_GREQ_URG_NUM(reg32, val) REG_FLD_SET(OVL_RDMA_GREQ_URG_NUM_FLD_LAYER3_GREQ_URG_NUM, (reg32), (val))
#define OVL_RDMA_GREQ_URG_NUM_SET_LAYER2_GREQ_URG_NUM(reg32, val) REG_FLD_SET(OVL_RDMA_GREQ_URG_NUM_FLD_LAYER2_GREQ_URG_NUM, (reg32), (val))
#define OVL_RDMA_GREQ_URG_NUM_SET_LAYER1_GREQ_URG_NUM(reg32, val) REG_FLD_SET(OVL_RDMA_GREQ_URG_NUM_FLD_LAYER1_GREQ_URG_NUM, (reg32), (val))
#define OVL_RDMA_GREQ_URG_NUM_SET_LAYER0_GREQ_URG_NUM(reg32, val) REG_FLD_SET(OVL_RDMA_GREQ_URG_NUM_FLD_LAYER0_GREQ_URG_NUM, (reg32), (val))

#define OVL_DUMMY_REG_SET_OVERLAY_DUMMY(reg32, val)            REG_FLD_SET(OVL_DUMMY_REG_FLD_OVERLAY_DUMMY, (reg32), (val))

#define OVL_GDRDY_PRD_SET_GDRDY_PRD(reg32, val)                REG_FLD_SET(OVL_GDRDY_PRD_FLD_GDRDY_PRD, (reg32), (val))

#define OVL_RDMA_ULTRA_SRC_SET_ULTRA_RDMA_SRC(reg32, val)      REG_FLD_SET(OVL_RDMA_ULTRA_SRC_FLD_ULTRA_RDMA_SRC, (reg32), (val))
#define OVL_RDMA_ULTRA_SRC_SET_ULTRA_ROI_END_SRC(reg32, val)   REG_FLD_SET(OVL_RDMA_ULTRA_SRC_FLD_ULTRA_ROI_END_SRC, (reg32), (val))
#define OVL_RDMA_ULTRA_SRC_SET_ULTRA_SMI_SRC(reg32, val)       REG_FLD_SET(OVL_RDMA_ULTRA_SRC_FLD_ULTRA_SMI_SRC, (reg32), (val))
#define OVL_RDMA_ULTRA_SRC_SET_ULTRA_BUF_SRC(reg32, val)       REG_FLD_SET(OVL_RDMA_ULTRA_SRC_FLD_ULTRA_BUF_SRC, (reg32), (val))
#define OVL_RDMA_ULTRA_SRC_SET_PREULTRA_RDMA_SRC(reg32, val)   REG_FLD_SET(OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_RDMA_SRC, (reg32), (val))
#define OVL_RDMA_ULTRA_SRC_SET_PREULTRA_ROI_END_SRC(reg32, val) REG_FLD_SET(OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_ROI_END_SRC, (reg32), (val))
#define OVL_RDMA_ULTRA_SRC_SET_PREULTRA_SMI_SRC(reg32, val)    REG_FLD_SET(OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_SMI_SRC, (reg32), (val))
#define OVL_RDMA_ULTRA_SRC_SET_PREULTRA_BUF_SRC(reg32, val)    REG_FLD_SET(OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_BUF_SRC, (reg32), (val))

#define OVL_RDMA0_BUF_LOW_TH_SET_RDMA0_PREULTRA_LOW_TH(reg32, val) REG_FLD_SET(OVL_RDMA0_BUF_LOW_TH_FLD_RDMA0_PREULTRA_LOW_TH, (reg32), (val))
#define OVL_RDMA0_BUF_LOW_TH_SET_RDMA0_ULTRA_LOW_TH(reg32, val) REG_FLD_SET(OVL_RDMA0_BUF_LOW_TH_FLD_RDMA0_ULTRA_LOW_TH, (reg32), (val))

#define OVL_RDMA1_BUF_LOW_TH_SET_RDMA1_PREULTRA_LOW_TH(reg32, val) REG_FLD_SET(OVL_RDMA1_BUF_LOW_TH_FLD_RDMA1_PREULTRA_LOW_TH, (reg32), (val))
#define OVL_RDMA1_BUF_LOW_TH_SET_RDMA1_ULTRA_LOW_TH(reg32, val) REG_FLD_SET(OVL_RDMA1_BUF_LOW_TH_FLD_RDMA1_ULTRA_LOW_TH, (reg32), (val))

#define OVL_RDMA2_BUF_LOW_TH_SET_RDMA2_PREULTRA_LOW_TH(reg32, val) REG_FLD_SET(OVL_RDMA2_BUF_LOW_TH_FLD_RDMA2_PREULTRA_LOW_TH, (reg32), (val))
#define OVL_RDMA2_BUF_LOW_TH_SET_RDMA2_ULTRA_LOW_TH(reg32, val) REG_FLD_SET(OVL_RDMA2_BUF_LOW_TH_FLD_RDMA2_ULTRA_LOW_TH, (reg32), (val))

#define OVL_RDMA3_BUF_LOW_TH_SET_RDMA3_PREULTRA_LOW_TH(reg32, val) REG_FLD_SET(OVL_RDMA3_BUF_LOW_TH_FLD_RDMA3_PREULTRA_LOW_TH, (reg32), (val))
#define OVL_RDMA3_BUF_LOW_TH_SET_RDMA3_ULTRA_LOW_TH(reg32, val) REG_FLD_SET(OVL_RDMA3_BUF_LOW_TH_FLD_RDMA3_ULTRA_LOW_TH, (reg32), (val))

#define OVL_RDMA0_BUF_HIGH_TH_SET_RDMA0_PREULTRA_HIGH_DIS(reg32, val) REG_FLD_SET(OVL_RDMA0_BUF_HIGH_TH_FLD_RDMA0_PREULTRA_HIGH_DIS, (reg32), (val))
#define OVL_RDMA0_BUF_HIGH_TH_SET_RDMA0_PREULTRA_HIGH_TH(reg32, val) REG_FLD_SET(OVL_RDMA0_BUF_HIGH_TH_FLD_RDMA0_PREULTRA_HIGH_TH, (reg32), (val))

#define OVL_RDMA1_BUF_HIGH_TH_SET_RDMA1_PREULTRA_HIGH_DIS(reg32, val) REG_FLD_SET(OVL_RDMA1_BUF_HIGH_TH_FLD_RDMA1_PREULTRA_HIGH_DIS, (reg32), (val))
#define OVL_RDMA1_BUF_HIGH_TH_SET_RDMA1_PREULTRA_HIGH_TH(reg32, val) REG_FLD_SET(OVL_RDMA1_BUF_HIGH_TH_FLD_RDMA1_PREULTRA_HIGH_TH, (reg32), (val))

#define OVL_RDMA2_BUF_HIGH_TH_SET_RDMA2_PREULTRA_HIGH_DIS(reg32, val) REG_FLD_SET(OVL_RDMA2_BUF_HIGH_TH_FLD_RDMA2_PREULTRA_HIGH_DIS, (reg32), (val))
#define OVL_RDMA2_BUF_HIGH_TH_SET_RDMA2_PREULTRA_HIGH_TH(reg32, val) REG_FLD_SET(OVL_RDMA2_BUF_HIGH_TH_FLD_RDMA2_PREULTRA_HIGH_TH, (reg32), (val))

#define OVL_RDMA3_BUF_HIGH_TH_SET_RDMA3_PREULTRA_HIGH_DIS(reg32, val) REG_FLD_SET(OVL_RDMA3_BUF_HIGH_TH_FLD_RDMA3_PREULTRA_HIGH_DIS, (reg32), (val))
#define OVL_RDMA3_BUF_HIGH_TH_SET_RDMA3_PREULTRA_HIGH_TH(reg32, val) REG_FLD_SET(OVL_RDMA3_BUF_HIGH_TH_FLD_RDMA3_PREULTRA_HIGH_TH, (reg32), (val))

#define OVL_SMI_DBG_SET_SMI_FSM(reg32, val)                    REG_FLD_SET(OVL_SMI_DBG_FLD_SMI_FSM, (reg32), (val))

#define OVL_GREQ_LAYER_CNT_SET_LAYER3_GREQ_CNT(reg32, val)     REG_FLD_SET(OVL_GREQ_LAYER_CNT_FLD_LAYER3_GREQ_CNT, (reg32), (val))
#define OVL_GREQ_LAYER_CNT_SET_LAYER2_GREQ_CNT(reg32, val)     REG_FLD_SET(OVL_GREQ_LAYER_CNT_FLD_LAYER2_GREQ_CNT, (reg32), (val))
#define OVL_GREQ_LAYER_CNT_SET_LAYER1_GREQ_CNT(reg32, val)     REG_FLD_SET(OVL_GREQ_LAYER_CNT_FLD_LAYER1_GREQ_CNT, (reg32), (val))
#define OVL_GREQ_LAYER_CNT_SET_LAYER0_GREQ_CNT(reg32, val)     REG_FLD_SET(OVL_GREQ_LAYER_CNT_FLD_LAYER0_GREQ_CNT, (reg32), (val))

#define OVL_GDRDY_PRD_NUM_SET_GDRDY_PRD_NUM(reg32, val)        REG_FLD_SET(OVL_GDRDY_PRD_NUM_FLD_GDRDY_PRD_NUM, (reg32), (val))

#define OVL_FLOW_CTRL_DBG_SET_OVL_UPD_REG(reg32, val)          REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_OVL_UPD_REG, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_REG_UPDATE(reg32, val)           REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_REG_UPDATE, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_OVL_CLR(reg32, val)              REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_OVL_CLR, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_OVL_START(reg32, val)            REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_OVL_START, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_OVL_RUNNING(reg32, val)          REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_OVL_RUNNING, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_FRAME_DONE(reg32, val)           REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_FRAME_DONE, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_FRAME_UNDERRUN(reg32, val)       REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_FRAME_UNDERRUN, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_FRAME_SWRST_DONE(reg32, val)     REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_FRAME_SWRST_DONE, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_FRAME_HWRST_DONE(reg32, val)     REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_FRAME_HWRST_DONE, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_TRIG(reg32, val)                 REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_TRIG, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_RST(reg32, val)                  REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_RST, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_RDMA0_IDLE(reg32, val)           REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_RDMA0_IDLE, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_RDMA1_IDLE(reg32, val)           REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_RDMA1_IDLE, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_RDMA2_IDLE(reg32, val)           REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_RDMA2_IDLE, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_RDMA3_IDLE(reg32, val)           REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_RDMA3_IDLE, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_OUT_IDLE(reg32, val)             REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_OUT_IDLE, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_OVL_OUT_READY(reg32, val)        REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_OVL_OUT_READY, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_OVL_OUT_VALID(reg32, val)        REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_OVL_OUT_VALID, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_BLEND_IDLE(reg32, val)           REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_BLEND_IDLE, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_ADDCON_IDLE(reg32, val)          REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_ADDCON_IDLE, (reg32), (val))
#define OVL_FLOW_CTRL_DBG_SET_FSM_STATE(reg32, val)            REG_FLD_SET(OVL_FLOW_CTRL_DBG_FLD_FSM_STATE, (reg32), (val))

#define OVL_ADDCON_DBG_SET_L3_WIN_HIT(reg32, val)              REG_FLD_SET(OVL_ADDCON_DBG_FLD_L3_WIN_HIT, (reg32), (val))
#define OVL_ADDCON_DBG_SET_L2_WIN_HIT(reg32, val)              REG_FLD_SET(OVL_ADDCON_DBG_FLD_L2_WIN_HIT, (reg32), (val))
#define OVL_ADDCON_DBG_SET_ROI_Y(reg32, val)                   REG_FLD_SET(OVL_ADDCON_DBG_FLD_ROI_Y, (reg32), (val))
#define OVL_ADDCON_DBG_SET_L1_WIN_HIT(reg32, val)              REG_FLD_SET(OVL_ADDCON_DBG_FLD_L1_WIN_HIT, (reg32), (val))
#define OVL_ADDCON_DBG_SET_L0_WIN_HIT(reg32, val)              REG_FLD_SET(OVL_ADDCON_DBG_FLD_L0_WIN_HIT, (reg32), (val))
#define OVL_ADDCON_DBG_SET_ROI_X(reg32, val)                   REG_FLD_SET(OVL_ADDCON_DBG_FLD_ROI_X, (reg32), (val))

#define OVL_RDMA0_DBG_SET_SMI_GREQ(reg32, val)                 REG_FLD_SET(OVL_RDMA0_DBG_FLD_SMI_GREQ, (reg32), (val))
#define OVL_RDMA0_DBG_SET_RDMA0_SMI_BUSY(reg32, val)           REG_FLD_SET(OVL_RDMA0_DBG_FLD_RDMA0_SMI_BUSY, (reg32), (val))
#define OVL_RDMA0_DBG_SET_RDMA0_OUT_VALID(reg32, val)          REG_FLD_SET(OVL_RDMA0_DBG_FLD_RDMA0_OUT_VALID, (reg32), (val))
#define OVL_RDMA0_DBG_SET_RDMA0_OUT_READY(reg32, val)          REG_FLD_SET(OVL_RDMA0_DBG_FLD_RDMA0_OUT_READY, (reg32), (val))
#define OVL_RDMA0_DBG_SET_RDMA0_OUT_DATA(reg32, val)           REG_FLD_SET(OVL_RDMA0_DBG_FLD_RDMA0_OUT_DATA, (reg32), (val))
#define OVL_RDMA0_DBG_SET_RDMA0_LAYER_GREQ(reg32, val)         REG_FLD_SET(OVL_RDMA0_DBG_FLD_RDMA0_LAYER_GREQ, (reg32), (val))
#define OVL_RDMA0_DBG_SET_RDMA0_WRAM_RST_CS(reg32, val)        REG_FLD_SET(OVL_RDMA0_DBG_FLD_RDMA0_WRAM_RST_CS, (reg32), (val))

#define OVL_RDMA1_DBG_SET_SMI_GREQ(reg32, val)                 REG_FLD_SET(OVL_RDMA1_DBG_FLD_SMI_GREQ, (reg32), (val))
#define OVL_RDMA1_DBG_SET_RDMA1_SMI_BUSY(reg32, val)           REG_FLD_SET(OVL_RDMA1_DBG_FLD_RDMA1_SMI_BUSY, (reg32), (val))
#define OVL_RDMA1_DBG_SET_RDMA1_OUT_VALID(reg32, val)          REG_FLD_SET(OVL_RDMA1_DBG_FLD_RDMA1_OUT_VALID, (reg32), (val))
#define OVL_RDMA1_DBG_SET_RDMA1_OUT_READY(reg32, val)          REG_FLD_SET(OVL_RDMA1_DBG_FLD_RDMA1_OUT_READY, (reg32), (val))
#define OVL_RDMA1_DBG_SET_RDMA1_OUT_DATA(reg32, val)           REG_FLD_SET(OVL_RDMA1_DBG_FLD_RDMA1_OUT_DATA, (reg32), (val))
#define OVL_RDMA1_DBG_SET_RDMA1_LAYER_GREQ(reg32, val)         REG_FLD_SET(OVL_RDMA1_DBG_FLD_RDMA1_LAYER_GREQ, (reg32), (val))
#define OVL_RDMA1_DBG_SET_RDMA1_WRAM_RST_CS(reg32, val)        REG_FLD_SET(OVL_RDMA1_DBG_FLD_RDMA1_WRAM_RST_CS, (reg32), (val))

#define OVL_RDMA2_DBG_SET_SMI_GREQ(reg32, val)                 REG_FLD_SET(OVL_RDMA2_DBG_FLD_SMI_GREQ, (reg32), (val))
#define OVL_RDMA2_DBG_SET_RDMA2_SMI_BUSY(reg32, val)           REG_FLD_SET(OVL_RDMA2_DBG_FLD_RDMA2_SMI_BUSY, (reg32), (val))
#define OVL_RDMA2_DBG_SET_RDMA2_OUT_VALID(reg32, val)          REG_FLD_SET(OVL_RDMA2_DBG_FLD_RDMA2_OUT_VALID, (reg32), (val))
#define OVL_RDMA2_DBG_SET_RDMA2_OUT_READY(reg32, val)          REG_FLD_SET(OVL_RDMA2_DBG_FLD_RDMA2_OUT_READY, (reg32), (val))
#define OVL_RDMA2_DBG_SET_RDMA2_OUT_DATA(reg32, val)           REG_FLD_SET(OVL_RDMA2_DBG_FLD_RDMA2_OUT_DATA, (reg32), (val))
#define OVL_RDMA2_DBG_SET_RDMA2_LAYER_GREQ(reg32, val)         REG_FLD_SET(OVL_RDMA2_DBG_FLD_RDMA2_LAYER_GREQ, (reg32), (val))
#define OVL_RDMA2_DBG_SET_RDMA2_WRAM_RST_CS(reg32, val)        REG_FLD_SET(OVL_RDMA2_DBG_FLD_RDMA2_WRAM_RST_CS, (reg32), (val))

#define OVL_RDMA3_DBG_SET_SMI_GREQ(reg32, val)                 REG_FLD_SET(OVL_RDMA3_DBG_FLD_SMI_GREQ, (reg32), (val))
#define OVL_RDMA3_DBG_SET_RDMA3_SMI_BUSY(reg32, val)           REG_FLD_SET(OVL_RDMA3_DBG_FLD_RDMA3_SMI_BUSY, (reg32), (val))
#define OVL_RDMA3_DBG_SET_RDMA3_OUT_VALID(reg32, val)          REG_FLD_SET(OVL_RDMA3_DBG_FLD_RDMA3_OUT_VALID, (reg32), (val))
#define OVL_RDMA3_DBG_SET_RDMA3_OUT_READY(reg32, val)          REG_FLD_SET(OVL_RDMA3_DBG_FLD_RDMA3_OUT_READY, (reg32), (val))
#define OVL_RDMA3_DBG_SET_RDMA3_OUT_DATA(reg32, val)           REG_FLD_SET(OVL_RDMA3_DBG_FLD_RDMA3_OUT_DATA, (reg32), (val))
#define OVL_RDMA3_DBG_SET_RDMA3_LAYER_GREQ(reg32, val)         REG_FLD_SET(OVL_RDMA3_DBG_FLD_RDMA3_LAYER_GREQ, (reg32), (val))
#define OVL_RDMA3_DBG_SET_RDMA3_WRAM_RST_CS(reg32, val)        REG_FLD_SET(OVL_RDMA3_DBG_FLD_RDMA3_WRAM_RST_CS, (reg32), (val))

#define OVL_L0_CLR_SET_ALPHA(reg32, val)                       REG_FLD_SET(OVL_L0_CLR_FLD_ALPHA, (reg32), (val))
#define OVL_L0_CLR_SET_RED(reg32, val)                         REG_FLD_SET(OVL_L0_CLR_FLD_RED, (reg32), (val))
#define OVL_L0_CLR_SET_GREEN(reg32, val)                       REG_FLD_SET(OVL_L0_CLR_FLD_GREEN, (reg32), (val))
#define OVL_L0_CLR_SET_BLUE(reg32, val)                        REG_FLD_SET(OVL_L0_CLR_FLD_BLUE, (reg32), (val))

#define OVL_L1_CLR_SET_ALPHA(reg32, val)                       REG_FLD_SET(OVL_L1_CLR_FLD_ALPHA, (reg32), (val))
#define OVL_L1_CLR_SET_RED(reg32, val)                         REG_FLD_SET(OVL_L1_CLR_FLD_RED, (reg32), (val))
#define OVL_L1_CLR_SET_GREEN(reg32, val)                       REG_FLD_SET(OVL_L1_CLR_FLD_GREEN, (reg32), (val))
#define OVL_L1_CLR_SET_BLUE(reg32, val)                        REG_FLD_SET(OVL_L1_CLR_FLD_BLUE, (reg32), (val))

#define OVL_L2_CLR_SET_ALPHA(reg32, val)                       REG_FLD_SET(OVL_L2_CLR_FLD_ALPHA, (reg32), (val))
#define OVL_L2_CLR_SET_RED(reg32, val)                         REG_FLD_SET(OVL_L2_CLR_FLD_RED, (reg32), (val))
#define OVL_L2_CLR_SET_GREEN(reg32, val)                       REG_FLD_SET(OVL_L2_CLR_FLD_GREEN, (reg32), (val))
#define OVL_L2_CLR_SET_BLUE(reg32, val)                        REG_FLD_SET(OVL_L2_CLR_FLD_BLUE, (reg32), (val))

#define OVL_L3_CLR_SET_ALPHA(reg32, val)                       REG_FLD_SET(OVL_L3_CLR_FLD_ALPHA, (reg32), (val))
#define OVL_L3_CLR_SET_RED(reg32, val)                         REG_FLD_SET(OVL_L3_CLR_FLD_RED, (reg32), (val))
#define OVL_L3_CLR_SET_GREEN(reg32, val)                       REG_FLD_SET(OVL_L3_CLR_FLD_GREEN, (reg32), (val))
#define OVL_L3_CLR_SET_BLUE(reg32, val)                        REG_FLD_SET(OVL_L3_CLR_FLD_BLUE, (reg32), (val))

#define OVL_LC_CLR_SET_ALPHA(reg32, val)                       REG_FLD_SET(OVL_LC_CLR_FLD_ALPHA, (reg32), (val))
#define OVL_LC_CLR_SET_RED(reg32, val)                         REG_FLD_SET(OVL_LC_CLR_FLD_RED, (reg32), (val))
#define OVL_LC_CLR_SET_GREEN(reg32, val)                       REG_FLD_SET(OVL_LC_CLR_FLD_GREEN, (reg32), (val))
#define OVL_LC_CLR_SET_BLUE(reg32, val)                        REG_FLD_SET(OVL_LC_CLR_FLD_BLUE, (reg32), (val))

#define OVL_CRC_SET_CRC_RDY(reg32, val)                        REG_FLD_SET(OVL_CRC_FLD_CRC_RDY, (reg32), (val))
#define OVL_CRC_SET_CRC_OUT(reg32, val)                        REG_FLD_SET(OVL_CRC_FLD_CRC_OUT, (reg32), (val))

#define OVL_LC_CON_SET_DSTKEY_EN(reg32, val)                   REG_FLD_SET(OVL_LC_CON_FLD_DSTKEY_EN, (reg32), (val))
#define OVL_LC_CON_SET_SRCKEY_EN(reg32, val)                   REG_FLD_SET(OVL_LC_CON_FLD_SRCKEY_EN, (reg32), (val))
#define OVL_LC_CON_SET_LAYER_SRC(reg32, val)                   REG_FLD_SET(OVL_LC_CON_FLD_LAYER_SRC, (reg32), (val))
#define OVL_LC_CON_SET_R_FIRST(reg32, val)                     REG_FLD_SET(OVL_LC_CON_FLD_R_FIRST, (reg32), (val))
#define OVL_LC_CON_SET_LANDSCAPE(reg32, val)                   REG_FLD_SET(OVL_LC_CON_FLD_LANDSCAPE, (reg32), (val))
#define OVL_LC_CON_SET_EN_3D(reg32, val)                       REG_FLD_SET(OVL_LC_CON_FLD_EN_3D, (reg32), (val))
#define OVL_LC_CON_SET_ALPHA_EN(reg32, val)                    REG_FLD_SET(OVL_LC_CON_FLD_ALPHA_EN, (reg32), (val))
#define OVL_LC_CON_SET_ALPHA(reg32, val)                       REG_FLD_SET(OVL_LC_CON_FLD_ALPHA, (reg32), (val))

#define OVL_LC_SRCKEY_SET_SRCKEY(reg32, val)                   REG_FLD_SET(OVL_LC_SRCKEY_FLD_SRCKEY, (reg32), (val))

#define OVL_LC_SRC_SIZE_SET_LC_SRC_H(reg32, val)               REG_FLD_SET(OVL_LC_SRC_SIZE_FLD_LC_SRC_H, (reg32), (val))
#define OVL_LC_SRC_SIZE_SET_LC_SRC_W(reg32, val)               REG_FLD_SET(OVL_LC_SRC_SIZE_FLD_LC_SRC_W, (reg32), (val))

#define OVL_LC_OFFSET_SET_LC_YOFF(reg32, val)                  REG_FLD_SET(OVL_LC_OFFSET_FLD_LC_YOFF, (reg32), (val))
#define OVL_LC_OFFSET_SET_LC_XOFF(reg32, val)                  REG_FLD_SET(OVL_LC_OFFSET_FLD_LC_XOFF, (reg32), (val))

#define OVL_LC_SRC_SEL_SET_SURFL_EN(reg32, val)                REG_FLD_SET(OVL_LC_SRC_SEL_FLD_SURFL_EN, (reg32), (val))
#define OVL_LC_SRC_SEL_SET_LC_BLEND_RND_SHT(reg32, val)        REG_FLD_SET(OVL_LC_SRC_SEL_FLD_LC_BLEND_RND_SHT, (reg32), (val))
#define OVL_LC_SRC_SEL_SET_LC_SRGB_SEL_EXT2(reg32, val)        REG_FLD_SET(OVL_LC_SRC_SEL_FLD_LC_SRGB_SEL_EXT2, (reg32), (val))
#define OVL_LC_SRC_SEL_SET_LC_CONST_BLD(reg32, val)            REG_FLD_SET(OVL_LC_SRC_SEL_FLD_LC_CONST_BLD, (reg32), (val))
#define OVL_LC_SRC_SEL_SET_LC_DRGB_SEL_EXT(reg32, val)         REG_FLD_SET(OVL_LC_SRC_SEL_FLD_LC_DRGB_SEL_EXT, (reg32), (val))
#define OVL_LC_SRC_SEL_SET_LC_DA_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_LC_SRC_SEL_FLD_LC_DA_SEL_EXT, (reg32), (val))
#define OVL_LC_SRC_SEL_SET_LC_SRGB_SEL_EXT(reg32, val)         REG_FLD_SET(OVL_LC_SRC_SEL_FLD_LC_SRGB_SEL_EXT, (reg32), (val))
#define OVL_LC_SRC_SEL_SET_LC_SA_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_LC_SRC_SEL_FLD_LC_SA_SEL_EXT, (reg32), (val))
#define OVL_LC_SRC_SEL_SET_LC_DRGB_SEL(reg32, val)             REG_FLD_SET(OVL_LC_SRC_SEL_FLD_LC_DRGB_SEL, (reg32), (val))
#define OVL_LC_SRC_SEL_SET_LC_DA_SEL(reg32, val)               REG_FLD_SET(OVL_LC_SRC_SEL_FLD_LC_DA_SEL, (reg32), (val))
#define OVL_LC_SRC_SEL_SET_LC_SRGB_SEL(reg32, val)             REG_FLD_SET(OVL_LC_SRC_SEL_FLD_LC_SRGB_SEL, (reg32), (val))
#define OVL_LC_SRC_SEL_SET_LC_SA_SEL(reg32, val)               REG_FLD_SET(OVL_LC_SRC_SEL_FLD_LC_SA_SEL, (reg32), (val))
#define OVL_LC_SRC_SEL_SET_CONST_LAYER_SEL(reg32, val)         REG_FLD_SET(OVL_LC_SRC_SEL_FLD_CONST_LAYER_SEL, (reg32), (val))

#define OVL_BANK_CON_SET_OVL_BANK_CON(reg32, val)              REG_FLD_SET(OVL_BANK_CON_FLD_OVL_BANK_CON, (reg32), (val))

#define OVL_FUNC_DCM0_SET_OVL_FUNC_DCM0(reg32, val)            REG_FLD_SET(OVL_FUNC_DCM0_FLD_OVL_FUNC_DCM0, (reg32), (val))

#define OVL_FUNC_DCM1_SET_OVL_FUNC_DCM1(reg32, val)            REG_FLD_SET(OVL_FUNC_DCM1_FLD_OVL_FUNC_DCM1, (reg32), (val))

#define OVL_DVFS_L0_ROI_SET_L0_DVFS_ROI_BB(reg32, val)         REG_FLD_SET(OVL_DVFS_L0_ROI_FLD_L0_DVFS_ROI_BB, (reg32), (val))
#define OVL_DVFS_L0_ROI_SET_L0_DVFS_ROI_TB(reg32, val)         REG_FLD_SET(OVL_DVFS_L0_ROI_FLD_L0_DVFS_ROI_TB, (reg32), (val))

#define OVL_DVFS_L1_ROI_SET_L1_DVFS_ROI_BB(reg32, val)         REG_FLD_SET(OVL_DVFS_L1_ROI_FLD_L1_DVFS_ROI_BB, (reg32), (val))
#define OVL_DVFS_L1_ROI_SET_L1_DVFS_ROI_TB(reg32, val)         REG_FLD_SET(OVL_DVFS_L1_ROI_FLD_L1_DVFS_ROI_TB, (reg32), (val))

#define OVL_DVFS_L2_ROI_SET_L2_DVFS_ROI_BB(reg32, val)         REG_FLD_SET(OVL_DVFS_L2_ROI_FLD_L2_DVFS_ROI_BB, (reg32), (val))
#define OVL_DVFS_L2_ROI_SET_L2_DVFS_ROI_TB(reg32, val)         REG_FLD_SET(OVL_DVFS_L2_ROI_FLD_L2_DVFS_ROI_TB, (reg32), (val))

#define OVL_DVFS_L3_ROI_SET_L3_DVFS_ROI_BB(reg32, val)         REG_FLD_SET(OVL_DVFS_L3_ROI_FLD_L3_DVFS_ROI_BB, (reg32), (val))
#define OVL_DVFS_L3_ROI_SET_L3_DVFS_ROI_TB(reg32, val)         REG_FLD_SET(OVL_DVFS_L3_ROI_FLD_L3_DVFS_ROI_TB, (reg32), (val))

#define OVL_DVFS_EL0_ROI_SET_EL0_DVFS_ROI_BB(reg32, val)       REG_FLD_SET(OVL_DVFS_EL0_ROI_FLD_EL0_DVFS_ROI_BB, (reg32), (val))
#define OVL_DVFS_EL0_ROI_SET_EL0_DVFS_ROI_TB(reg32, val)       REG_FLD_SET(OVL_DVFS_EL0_ROI_FLD_EL0_DVFS_ROI_TB, (reg32), (val))

#define OVL_DVFS_EL1_ROI_SET_EL1_DVFS_ROI_BB(reg32, val)       REG_FLD_SET(OVL_DVFS_EL1_ROI_FLD_EL1_DVFS_ROI_BB, (reg32), (val))
#define OVL_DVFS_EL1_ROI_SET_EL1_DVFS_ROI_TB(reg32, val)       REG_FLD_SET(OVL_DVFS_EL1_ROI_FLD_EL1_DVFS_ROI_TB, (reg32), (val))

#define OVL_DVFS_EL2_ROI_SET_EL2_DVFS_ROI_BB(reg32, val)       REG_FLD_SET(OVL_DVFS_EL2_ROI_FLD_EL2_DVFS_ROI_BB, (reg32), (val))
#define OVL_DVFS_EL2_ROI_SET_EL2_DVFS_ROI_TB(reg32, val)       REG_FLD_SET(OVL_DVFS_EL2_ROI_FLD_EL2_DVFS_ROI_TB, (reg32), (val))

#define OVL_DATAPATH_EXT_CON_SET_EL2_LAYER_SEL(reg32, val)     REG_FLD_SET(OVL_DATAPATH_EXT_CON_FLD_EL2_LAYER_SEL, (reg32), (val))
#define OVL_DATAPATH_EXT_CON_SET_EL1_LAYER_SEL(reg32, val)     REG_FLD_SET(OVL_DATAPATH_EXT_CON_FLD_EL1_LAYER_SEL, (reg32), (val))
#define OVL_DATAPATH_EXT_CON_SET_EL0_LAYER_SEL(reg32, val)     REG_FLD_SET(OVL_DATAPATH_EXT_CON_FLD_EL0_LAYER_SEL, (reg32), (val))
#define OVL_DATAPATH_EXT_CON_SET_EL2_GPU_MODE(reg32, val)      REG_FLD_SET(OVL_DATAPATH_EXT_CON_FLD_EL2_GPU_MODE, (reg32), (val))
#define OVL_DATAPATH_EXT_CON_SET_EL1_GPU_MODE(reg32, val)      REG_FLD_SET(OVL_DATAPATH_EXT_CON_FLD_EL1_GPU_MODE, (reg32), (val))
#define OVL_DATAPATH_EXT_CON_SET_EL0_GPU_MODE(reg32, val)      REG_FLD_SET(OVL_DATAPATH_EXT_CON_FLD_EL0_GPU_MODE, (reg32), (val))
#define OVL_DATAPATH_EXT_CON_SET_EL2_EN(reg32, val)            REG_FLD_SET(OVL_DATAPATH_EXT_CON_FLD_EL2_EN, (reg32), (val))
#define OVL_DATAPATH_EXT_CON_SET_EL1_EN(reg32, val)            REG_FLD_SET(OVL_DATAPATH_EXT_CON_FLD_EL1_EN, (reg32), (val))
#define OVL_DATAPATH_EXT_CON_SET_EL0_EN(reg32, val)            REG_FLD_SET(OVL_DATAPATH_EXT_CON_FLD_EL0_EN, (reg32), (val))

#define OVL_EL0_CON_SET_DSTKEY_EN(reg32, val)                  REG_FLD_SET(OVL_EL0_CON_FLD_DSTKEY_EN, (reg32), (val))
#define OVL_EL0_CON_SET_SRCKEY_EN(reg32, val)                  REG_FLD_SET(OVL_EL0_CON_FLD_SRCKEY_EN, (reg32), (val))
#define OVL_EL0_CON_SET_LAYER_SRC(reg32, val)                  REG_FLD_SET(OVL_EL0_CON_FLD_LAYER_SRC, (reg32), (val))
#define OVL_EL0_CON_SET_MTX_EN(reg32, val)                     REG_FLD_SET(OVL_EL0_CON_FLD_MTX_EN, (reg32), (val))
#define OVL_EL0_CON_SET_MTX_AUTO_DIS(reg32, val)               REG_FLD_SET(OVL_EL0_CON_FLD_MTX_AUTO_DIS, (reg32), (val))
#define OVL_EL0_CON_SET_RGB_SWAP(reg32, val)                   REG_FLD_SET(OVL_EL0_CON_FLD_RGB_SWAP, (reg32), (val))
#define OVL_EL0_CON_SET_BYTE_SWAP(reg32, val)                  REG_FLD_SET(OVL_EL0_CON_FLD_BYTE_SWAP, (reg32), (val))
#define OVL_EL0_CON_SET_CLRFMT_MAN(reg32, val)                 REG_FLD_SET(OVL_EL0_CON_FLD_CLRFMT_MAN, (reg32), (val))
#define OVL_EL0_CON_SET_R_FIRST(reg32, val)                    REG_FLD_SET(OVL_EL0_CON_FLD_R_FIRST, (reg32), (val))
#define OVL_EL0_CON_SET_LANDSCAPE(reg32, val)                  REG_FLD_SET(OVL_EL0_CON_FLD_LANDSCAPE, (reg32), (val))
#define OVL_EL0_CON_SET_EN_3D(reg32, val)                      REG_FLD_SET(OVL_EL0_CON_FLD_EN_3D, (reg32), (val))
#define OVL_EL0_CON_SET_INT_MTX_SEL(reg32, val)                REG_FLD_SET(OVL_EL0_CON_FLD_INT_MTX_SEL, (reg32), (val))
#define OVL_EL0_CON_SET_CLRFMT(reg32, val)                     REG_FLD_SET(OVL_EL0_CON_FLD_CLRFMT, (reg32), (val))
#define OVL_EL0_CON_SET_EXT_MTX_EN(reg32, val)                 REG_FLD_SET(OVL_EL0_CON_FLD_EXT_MTX_EN, (reg32), (val))
#define OVL_EL0_CON_SET_HORIZONTAL_FLIP_EN(reg32, val)         REG_FLD_SET(OVL_EL0_CON_FLD_HORIZONTAL_FLIP_EN, (reg32), (val))
#define OVL_EL0_CON_SET_VERTICAL_FLIP_EN(reg32, val)           REG_FLD_SET(OVL_EL0_CON_FLD_VERTICAL_FLIP_EN, (reg32), (val))
#define OVL_EL0_CON_SET_ALPHA_EN(reg32, val)                   REG_FLD_SET(OVL_EL0_CON_FLD_ALPHA_EN, (reg32), (val))
#define OVL_EL0_CON_SET_ALPHA(reg32, val)                      REG_FLD_SET(OVL_EL0_CON_FLD_ALPHA, (reg32), (val))

#define OVL_EL0_SRCKEY_SET_SRCKEY(reg32, val)                  REG_FLD_SET(OVL_EL0_SRCKEY_FLD_SRCKEY, (reg32), (val))

#define OVL_EL0_SRC_SIZE_SET_EL0_SRC_H(reg32, val)             REG_FLD_SET(OVL_EL0_SRC_SIZE_FLD_EL0_SRC_H, (reg32), (val))
#define OVL_EL0_SRC_SIZE_SET_EL0_SRC_W(reg32, val)             REG_FLD_SET(OVL_EL0_SRC_SIZE_FLD_EL0_SRC_W, (reg32), (val))

#define OVL_EL0_OFFSET_SET_EL0_YOFF(reg32, val)                REG_FLD_SET(OVL_EL0_OFFSET_FLD_EL0_YOFF, (reg32), (val))
#define OVL_EL0_OFFSET_SET_EL0_XOFF(reg32, val)                REG_FLD_SET(OVL_EL0_OFFSET_FLD_EL0_XOFF, (reg32), (val))

#define OVL_EL0_PITCH_SET_SURFL_EN(reg32, val)                 REG_FLD_SET(OVL_EL0_PITCH_FLD_SURFL_EN, (reg32), (val))
#define OVL_EL0_PITCH_SET_EL0_BLEND_RND_SHT(reg32, val)        REG_FLD_SET(OVL_EL0_PITCH_FLD_EL0_BLEND_RND_SHT, (reg32), (val))
#define OVL_EL0_PITCH_SET_EL0_SRGB_SEL_EXT2(reg32, val)        REG_FLD_SET(OVL_EL0_PITCH_FLD_EL0_SRGB_SEL_EXT2, (reg32), (val))
#define OVL_EL0_PITCH_SET_EL0_CONST_BLD(reg32, val)            REG_FLD_SET(OVL_EL0_PITCH_FLD_EL0_CONST_BLD, (reg32), (val))
#define OVL_EL0_PITCH_SET_EL0_DRGB_SEL_EXT(reg32, val)         REG_FLD_SET(OVL_EL0_PITCH_FLD_EL0_DRGB_SEL_EXT, (reg32), (val))
#define OVL_EL0_PITCH_SET_EL0_DA_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_EL0_PITCH_FLD_EL0_DA_SEL_EXT, (reg32), (val))
#define OVL_EL0_PITCH_SET_EL0_SRGB_SEL_EXT(reg32, val)         REG_FLD_SET(OVL_EL0_PITCH_FLD_EL0_SRGB_SEL_EXT, (reg32), (val))
#define OVL_EL0_PITCH_SET_EL0_SA_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_EL0_PITCH_FLD_EL0_SA_SEL_EXT, (reg32), (val))
#define OVL_EL0_PITCH_SET_EL0_DRGB_SEL(reg32, val)             REG_FLD_SET(OVL_EL0_PITCH_FLD_EL0_DRGB_SEL, (reg32), (val))
#define OVL_EL0_PITCH_SET_EL0_DA_SEL(reg32, val)               REG_FLD_SET(OVL_EL0_PITCH_FLD_EL0_DA_SEL, (reg32), (val))
#define OVL_EL0_PITCH_SET_EL0_SRGB_SEL(reg32, val)             REG_FLD_SET(OVL_EL0_PITCH_FLD_EL0_SRGB_SEL, (reg32), (val))
#define OVL_EL0_PITCH_SET_EL0_SA_SEL(reg32, val)               REG_FLD_SET(OVL_EL0_PITCH_FLD_EL0_SA_SEL, (reg32), (val))
#define OVL_EL0_PITCH_SET_EL0_SRC_PITCH(reg32, val)            REG_FLD_SET(OVL_EL0_PITCH_FLD_EL0_SRC_PITCH, (reg32), (val))

#define OVL_EL0_TILE_SET_TILE_HORI_BLOCK_NUM(reg32, val)       REG_FLD_SET(OVL_EL0_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32), (val))
#define OVL_EL0_TILE_SET_TILE_EN(reg32, val)                   REG_FLD_SET(OVL_EL0_TILE_FLD_TILE_EN, (reg32), (val))
#define OVL_EL0_TILE_SET_TILE_WIDTH_SEL(reg32, val)            REG_FLD_SET(OVL_EL0_TILE_FLD_TILE_WIDTH_SEL, (reg32), (val))
#define OVL_EL0_TILE_SET_TILE_HEIGHT(reg32, val)               REG_FLD_SET(OVL_EL0_TILE_FLD_TILE_HEIGHT, (reg32), (val))

#define OVL_EL0_CLIP_SET_EL0_SRC_BOTTOM_CLIP(reg32, val)       REG_FLD_SET(OVL_EL0_CLIP_FLD_EL0_SRC_BOTTOM_CLIP, (reg32), (val))
#define OVL_EL0_CLIP_SET_EL0_SRC_TOP_CLIP(reg32, val)          REG_FLD_SET(OVL_EL0_CLIP_FLD_EL0_SRC_TOP_CLIP, (reg32), (val))
#define OVL_EL0_CLIP_SET_EL0_SRC_RIGHT_CLIP(reg32, val)        REG_FLD_SET(OVL_EL0_CLIP_FLD_EL0_SRC_RIGHT_CLIP, (reg32), (val))
#define OVL_EL0_CLIP_SET_EL0_SRC_LEFT_CLIP(reg32, val)         REG_FLD_SET(OVL_EL0_CLIP_FLD_EL0_SRC_LEFT_CLIP, (reg32), (val))

#define OVL_EL1_CON_SET_DSTKEY_EN(reg32, val)                  REG_FLD_SET(OVL_EL1_CON_FLD_DSTKEY_EN, (reg32), (val))
#define OVL_EL1_CON_SET_SRCKEY_EN(reg32, val)                  REG_FLD_SET(OVL_EL1_CON_FLD_SRCKEY_EN, (reg32), (val))
#define OVL_EL1_CON_SET_LAYER_SRC(reg32, val)                  REG_FLD_SET(OVL_EL1_CON_FLD_LAYER_SRC, (reg32), (val))
#define OVL_EL1_CON_SET_MTX_EN(reg32, val)                     REG_FLD_SET(OVL_EL1_CON_FLD_MTX_EN, (reg32), (val))
#define OVL_EL1_CON_SET_MTX_AUTO_DIS(reg32, val)               REG_FLD_SET(OVL_EL1_CON_FLD_MTX_AUTO_DIS, (reg32), (val))
#define OVL_EL1_CON_SET_RGB_SWAP(reg32, val)                   REG_FLD_SET(OVL_EL1_CON_FLD_RGB_SWAP, (reg32), (val))
#define OVL_EL1_CON_SET_BYTE_SWAP(reg32, val)                  REG_FLD_SET(OVL_EL1_CON_FLD_BYTE_SWAP, (reg32), (val))
#define OVL_EL1_CON_SET_CLRFMT_MAN(reg32, val)                 REG_FLD_SET(OVL_EL1_CON_FLD_CLRFMT_MAN, (reg32), (val))
#define OVL_EL1_CON_SET_R_FIRST(reg32, val)                    REG_FLD_SET(OVL_EL1_CON_FLD_R_FIRST, (reg32), (val))
#define OVL_EL1_CON_SET_LANDSCAPE(reg32, val)                  REG_FLD_SET(OVL_EL1_CON_FLD_LANDSCAPE, (reg32), (val))
#define OVL_EL1_CON_SET_EN_3D(reg32, val)                      REG_FLD_SET(OVL_EL1_CON_FLD_EN_3D, (reg32), (val))
#define OVL_EL1_CON_SET_INT_MTX_SEL(reg32, val)                REG_FLD_SET(OVL_EL1_CON_FLD_INT_MTX_SEL, (reg32), (val))
#define OVL_EL1_CON_SET_CLRFMT(reg32, val)                     REG_FLD_SET(OVL_EL1_CON_FLD_CLRFMT, (reg32), (val))
#define OVL_EL1_CON_SET_EXT_MTX_EN(reg32, val)                 REG_FLD_SET(OVL_EL1_CON_FLD_EXT_MTX_EN, (reg32), (val))
#define OVL_EL1_CON_SET_HORIZONTAL_FLIP_EN(reg32, val)         REG_FLD_SET(OVL_EL1_CON_FLD_HORIZONTAL_FLIP_EN, (reg32), (val))
#define OVL_EL1_CON_SET_VERTICAL_FLIP_EN(reg32, val)           REG_FLD_SET(OVL_EL1_CON_FLD_VERTICAL_FLIP_EN, (reg32), (val))
#define OVL_EL1_CON_SET_ALPHA_EN(reg32, val)                   REG_FLD_SET(OVL_EL1_CON_FLD_ALPHA_EN, (reg32), (val))
#define OVL_EL1_CON_SET_ALPHA(reg32, val)                      REG_FLD_SET(OVL_EL1_CON_FLD_ALPHA, (reg32), (val))

#define OVL_EL1_SRCKEY_SET_SRCKEY(reg32, val)                  REG_FLD_SET(OVL_EL1_SRCKEY_FLD_SRCKEY, (reg32), (val))

#define OVL_EL1_SRC_SIZE_SET_EL1_SRC_H(reg32, val)             REG_FLD_SET(OVL_EL1_SRC_SIZE_FLD_EL1_SRC_H, (reg32), (val))
#define OVL_EL1_SRC_SIZE_SET_EL1_SRC_W(reg32, val)             REG_FLD_SET(OVL_EL1_SRC_SIZE_FLD_EL1_SRC_W, (reg32), (val))

#define OVL_EL1_OFFSET_SET_EL1_YOFF(reg32, val)                REG_FLD_SET(OVL_EL1_OFFSET_FLD_EL1_YOFF, (reg32), (val))
#define OVL_EL1_OFFSET_SET_EL1_XOFF(reg32, val)                REG_FLD_SET(OVL_EL1_OFFSET_FLD_EL1_XOFF, (reg32), (val))

#define OVL_EL1_PITCH_SET_SURFL_EN(reg32, val)                 REG_FLD_SET(OVL_EL1_PITCH_FLD_SURFL_EN, (reg32), (val))
#define OVL_EL1_PITCH_SET_EL1_BLEND_RND_SHT(reg32, val)        REG_FLD_SET(OVL_EL1_PITCH_FLD_EL1_BLEND_RND_SHT, (reg32), (val))
#define OVL_EL1_PITCH_SET_EL1_SRGB_SEL_EXT2(reg32, val)        REG_FLD_SET(OVL_EL1_PITCH_FLD_EL1_SRGB_SEL_EXT2, (reg32), (val))
#define OVL_EL1_PITCH_SET_EL1_CONST_BLD(reg32, val)            REG_FLD_SET(OVL_EL1_PITCH_FLD_EL1_CONST_BLD, (reg32), (val))
#define OVL_EL1_PITCH_SET_EL1_DRGB_SEL_EXT(reg32, val)         REG_FLD_SET(OVL_EL1_PITCH_FLD_EL1_DRGB_SEL_EXT, (reg32), (val))
#define OVL_EL1_PITCH_SET_EL1_DA_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_EL1_PITCH_FLD_EL1_DA_SEL_EXT, (reg32), (val))
#define OVL_EL1_PITCH_SET_EL1_SRGB_SEL_EXT(reg32, val)         REG_FLD_SET(OVL_EL1_PITCH_FLD_EL1_SRGB_SEL_EXT, (reg32), (val))
#define OVL_EL1_PITCH_SET_EL1_SA_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_EL1_PITCH_FLD_EL1_SA_SEL_EXT, (reg32), (val))
#define OVL_EL1_PITCH_SET_EL1_DRGB_SEL(reg32, val)             REG_FLD_SET(OVL_EL1_PITCH_FLD_EL1_DRGB_SEL, (reg32), (val))
#define OVL_EL1_PITCH_SET_EL1_DA_SEL(reg32, val)               REG_FLD_SET(OVL_EL1_PITCH_FLD_EL1_DA_SEL, (reg32), (val))
#define OVL_EL1_PITCH_SET_EL1_SRGB_SEL(reg32, val)             REG_FLD_SET(OVL_EL1_PITCH_FLD_EL1_SRGB_SEL, (reg32), (val))
#define OVL_EL1_PITCH_SET_EL1_SA_SEL(reg32, val)               REG_FLD_SET(OVL_EL1_PITCH_FLD_EL1_SA_SEL, (reg32), (val))
#define OVL_EL1_PITCH_SET_EL1_SRC_PITCH(reg32, val)            REG_FLD_SET(OVL_EL1_PITCH_FLD_EL1_SRC_PITCH, (reg32), (val))

#define OVL_EL1_TILE_SET_TILE_HORI_BLOCK_NUM(reg32, val)       REG_FLD_SET(OVL_EL1_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32), (val))
#define OVL_EL1_TILE_SET_TILE_EN(reg32, val)                   REG_FLD_SET(OVL_EL1_TILE_FLD_TILE_EN, (reg32), (val))
#define OVL_EL1_TILE_SET_TILE_WIDTH_SEL(reg32, val)            REG_FLD_SET(OVL_EL1_TILE_FLD_TILE_WIDTH_SEL, (reg32), (val))
#define OVL_EL1_TILE_SET_TILE_HEIGHT(reg32, val)               REG_FLD_SET(OVL_EL1_TILE_FLD_TILE_HEIGHT, (reg32), (val))

#define OVL_EL1_CLIP_SET_EL1_SRC_BOTTOM_CLIP(reg32, val)       REG_FLD_SET(OVL_EL1_CLIP_FLD_EL1_SRC_BOTTOM_CLIP, (reg32), (val))
#define OVL_EL1_CLIP_SET_EL1_SRC_TOP_CLIP(reg32, val)          REG_FLD_SET(OVL_EL1_CLIP_FLD_EL1_SRC_TOP_CLIP, (reg32), (val))
#define OVL_EL1_CLIP_SET_EL1_SRC_RIGHT_CLIP(reg32, val)        REG_FLD_SET(OVL_EL1_CLIP_FLD_EL1_SRC_RIGHT_CLIP, (reg32), (val))
#define OVL_EL1_CLIP_SET_EL1_SRC_LEFT_CLIP(reg32, val)         REG_FLD_SET(OVL_EL1_CLIP_FLD_EL1_SRC_LEFT_CLIP, (reg32), (val))

#define OVL_EL2_CON_SET_DSTKEY_EN(reg32, val)                  REG_FLD_SET(OVL_EL2_CON_FLD_DSTKEY_EN, (reg32), (val))
#define OVL_EL2_CON_SET_SRCKEY_EN(reg32, val)                  REG_FLD_SET(OVL_EL2_CON_FLD_SRCKEY_EN, (reg32), (val))
#define OVL_EL2_CON_SET_LAYER_SRC(reg32, val)                  REG_FLD_SET(OVL_EL2_CON_FLD_LAYER_SRC, (reg32), (val))
#define OVL_EL2_CON_SET_MTX_EN(reg32, val)                     REG_FLD_SET(OVL_EL2_CON_FLD_MTX_EN, (reg32), (val))
#define OVL_EL2_CON_SET_MTX_AUTO_DIS(reg32, val)               REG_FLD_SET(OVL_EL2_CON_FLD_MTX_AUTO_DIS, (reg32), (val))
#define OVL_EL2_CON_SET_RGB_SWAP(reg32, val)                   REG_FLD_SET(OVL_EL2_CON_FLD_RGB_SWAP, (reg32), (val))
#define OVL_EL2_CON_SET_BYTE_SWAP(reg32, val)                  REG_FLD_SET(OVL_EL2_CON_FLD_BYTE_SWAP, (reg32), (val))
#define OVL_EL2_CON_SET_CLRFMT_MAN(reg32, val)                 REG_FLD_SET(OVL_EL2_CON_FLD_CLRFMT_MAN, (reg32), (val))
#define OVL_EL2_CON_SET_R_FIRST(reg32, val)                    REG_FLD_SET(OVL_EL2_CON_FLD_R_FIRST, (reg32), (val))
#define OVL_EL2_CON_SET_LANDSCAPE(reg32, val)                  REG_FLD_SET(OVL_EL2_CON_FLD_LANDSCAPE, (reg32), (val))
#define OVL_EL2_CON_SET_EN_3D(reg32, val)                      REG_FLD_SET(OVL_EL2_CON_FLD_EN_3D, (reg32), (val))
#define OVL_EL2_CON_SET_INT_MTX_SEL(reg32, val)                REG_FLD_SET(OVL_EL2_CON_FLD_INT_MTX_SEL, (reg32), (val))
#define OVL_EL2_CON_SET_CLRFMT(reg32, val)                     REG_FLD_SET(OVL_EL2_CON_FLD_CLRFMT, (reg32), (val))
#define OVL_EL2_CON_SET_EXT_MTX_EN(reg32, val)                 REG_FLD_SET(OVL_EL2_CON_FLD_EXT_MTX_EN, (reg32), (val))
#define OVL_EL2_CON_SET_HORIZONTAL_FLIP_EN(reg32, val)         REG_FLD_SET(OVL_EL2_CON_FLD_HORIZONTAL_FLIP_EN, (reg32), (val))
#define OVL_EL2_CON_SET_VERTICAL_FLIP_EN(reg32, val)           REG_FLD_SET(OVL_EL2_CON_FLD_VERTICAL_FLIP_EN, (reg32), (val))
#define OVL_EL2_CON_SET_ALPHA_EN(reg32, val)                   REG_FLD_SET(OVL_EL2_CON_FLD_ALPHA_EN, (reg32), (val))
#define OVL_EL2_CON_SET_ALPHA(reg32, val)                      REG_FLD_SET(OVL_EL2_CON_FLD_ALPHA, (reg32), (val))

#define OVL_EL2_SRCKEY_SET_SRCKEY(reg32, val)                  REG_FLD_SET(OVL_EL2_SRCKEY_FLD_SRCKEY, (reg32), (val))

#define OVL_EL2_SRC_SIZE_SET_EL2_SRC_H(reg32, val)             REG_FLD_SET(OVL_EL2_SRC_SIZE_FLD_EL2_SRC_H, (reg32), (val))
#define OVL_EL2_SRC_SIZE_SET_EL2_SRC_W(reg32, val)             REG_FLD_SET(OVL_EL2_SRC_SIZE_FLD_EL2_SRC_W, (reg32), (val))

#define OVL_EL2_OFFSET_SET_EL2_YOFF(reg32, val)                REG_FLD_SET(OVL_EL2_OFFSET_FLD_EL2_YOFF, (reg32), (val))
#define OVL_EL2_OFFSET_SET_EL2_XOFF(reg32, val)                REG_FLD_SET(OVL_EL2_OFFSET_FLD_EL2_XOFF, (reg32), (val))

#define OVL_EL2_PITCH_SET_SURFL_EN(reg32, val)                 REG_FLD_SET(OVL_EL2_PITCH_FLD_SURFL_EN, (reg32), (val))
#define OVL_EL2_PITCH_SET_EL2_BLEND_RND_SHT(reg32, val)        REG_FLD_SET(OVL_EL2_PITCH_FLD_EL2_BLEND_RND_SHT, (reg32), (val))
#define OVL_EL2_PITCH_SET_EL2_SRGB_SEL_EXT2(reg32, val)        REG_FLD_SET(OVL_EL2_PITCH_FLD_EL2_SRGB_SEL_EXT2, (reg32), (val))
#define OVL_EL2_PITCH_SET_EL2_CONST_BLD(reg32, val)            REG_FLD_SET(OVL_EL2_PITCH_FLD_EL2_CONST_BLD, (reg32), (val))
#define OVL_EL2_PITCH_SET_EL2_DRGB_SEL_EXT(reg32, val)         REG_FLD_SET(OVL_EL2_PITCH_FLD_EL2_DRGB_SEL_EXT, (reg32), (val))
#define OVL_EL2_PITCH_SET_EL2_DA_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_EL2_PITCH_FLD_EL2_DA_SEL_EXT, (reg32), (val))
#define OVL_EL2_PITCH_SET_EL2_SRGB_SEL_EXT(reg32, val)         REG_FLD_SET(OVL_EL2_PITCH_FLD_EL2_SRGB_SEL_EXT, (reg32), (val))
#define OVL_EL2_PITCH_SET_EL2_SA_SEL_EXT(reg32, val)           REG_FLD_SET(OVL_EL2_PITCH_FLD_EL2_SA_SEL_EXT, (reg32), (val))
#define OVL_EL2_PITCH_SET_EL2_DRGB_SEL(reg32, val)             REG_FLD_SET(OVL_EL2_PITCH_FLD_EL2_DRGB_SEL, (reg32), (val))
#define OVL_EL2_PITCH_SET_EL2_DA_SEL(reg32, val)               REG_FLD_SET(OVL_EL2_PITCH_FLD_EL2_DA_SEL, (reg32), (val))
#define OVL_EL2_PITCH_SET_EL2_SRGB_SEL(reg32, val)             REG_FLD_SET(OVL_EL2_PITCH_FLD_EL2_SRGB_SEL, (reg32), (val))
#define OVL_EL2_PITCH_SET_EL2_SA_SEL(reg32, val)               REG_FLD_SET(OVL_EL2_PITCH_FLD_EL2_SA_SEL, (reg32), (val))
#define OVL_EL2_PITCH_SET_EL2_SRC_PITCH(reg32, val)            REG_FLD_SET(OVL_EL2_PITCH_FLD_EL2_SRC_PITCH, (reg32), (val))

#define OVL_EL2_TILE_SET_TILE_HORI_BLOCK_NUM(reg32, val)       REG_FLD_SET(OVL_EL2_TILE_FLD_TILE_HORI_BLOCK_NUM, (reg32), (val))
#define OVL_EL2_TILE_SET_TILE_EN(reg32, val)                   REG_FLD_SET(OVL_EL2_TILE_FLD_TILE_EN, (reg32), (val))
#define OVL_EL2_TILE_SET_TILE_WIDTH_SEL(reg32, val)            REG_FLD_SET(OVL_EL2_TILE_FLD_TILE_WIDTH_SEL, (reg32), (val))
#define OVL_EL2_TILE_SET_TILE_HEIGHT(reg32, val)               REG_FLD_SET(OVL_EL2_TILE_FLD_TILE_HEIGHT, (reg32), (val))

#define OVL_EL2_CLIP_SET_EL2_SRC_BOTTOM_CLIP(reg32, val)       REG_FLD_SET(OVL_EL2_CLIP_FLD_EL2_SRC_BOTTOM_CLIP, (reg32), (val))
#define OVL_EL2_CLIP_SET_EL2_SRC_TOP_CLIP(reg32, val)          REG_FLD_SET(OVL_EL2_CLIP_FLD_EL2_SRC_TOP_CLIP, (reg32), (val))
#define OVL_EL2_CLIP_SET_EL2_SRC_RIGHT_CLIP(reg32, val)        REG_FLD_SET(OVL_EL2_CLIP_FLD_EL2_SRC_RIGHT_CLIP, (reg32), (val))
#define OVL_EL2_CLIP_SET_EL2_SRC_LEFT_CLIP(reg32, val)         REG_FLD_SET(OVL_EL2_CLIP_FLD_EL2_SRC_LEFT_CLIP, (reg32), (val))

#define OVL_EL0_CLR_SET_ALPHA(reg32, val)                      REG_FLD_SET(OVL_EL0_CLR_FLD_ALPHA, (reg32), (val))
#define OVL_EL0_CLR_SET_RED(reg32, val)                        REG_FLD_SET(OVL_EL0_CLR_FLD_RED, (reg32), (val))
#define OVL_EL0_CLR_SET_GREEN(reg32, val)                      REG_FLD_SET(OVL_EL0_CLR_FLD_GREEN, (reg32), (val))
#define OVL_EL0_CLR_SET_BLUE(reg32, val)                       REG_FLD_SET(OVL_EL0_CLR_FLD_BLUE, (reg32), (val))

#define OVL_EL1_CLR_SET_ALPHA(reg32, val)                      REG_FLD_SET(OVL_EL1_CLR_FLD_ALPHA, (reg32), (val))
#define OVL_EL1_CLR_SET_RED(reg32, val)                        REG_FLD_SET(OVL_EL1_CLR_FLD_RED, (reg32), (val))
#define OVL_EL1_CLR_SET_GREEN(reg32, val)                      REG_FLD_SET(OVL_EL1_CLR_FLD_GREEN, (reg32), (val))
#define OVL_EL1_CLR_SET_BLUE(reg32, val)                       REG_FLD_SET(OVL_EL1_CLR_FLD_BLUE, (reg32), (val))

#define OVL_EL2_CLR_SET_ALPHA(reg32, val)                      REG_FLD_SET(OVL_EL2_CLR_FLD_ALPHA, (reg32), (val))
#define OVL_EL2_CLR_SET_RED(reg32, val)                        REG_FLD_SET(OVL_EL2_CLR_FLD_RED, (reg32), (val))
#define OVL_EL2_CLR_SET_GREEN(reg32, val)                      REG_FLD_SET(OVL_EL2_CLR_FLD_GREEN, (reg32), (val))
#define OVL_EL2_CLR_SET_BLUE(reg32, val)                       REG_FLD_SET(OVL_EL2_CLR_FLD_BLUE, (reg32), (val))

#define OVL_SBCH_SET_L3_SBCH_CNST_EN(reg32, val)               REG_FLD_SET(OVL_SBCH_FLD_L3_SBCH_CNST_EN, (reg32), (val))
#define OVL_SBCH_SET_L3_SBCH_TRANS_EN(reg32, val)              REG_FLD_SET(OVL_SBCH_FLD_L3_SBCH_TRANS_EN, (reg32), (val))
#define OVL_SBCH_SET_L2_SBCH_CNST_EN(reg32, val)               REG_FLD_SET(OVL_SBCH_FLD_L2_SBCH_CNST_EN, (reg32), (val))
#define OVL_SBCH_SET_L2_SBCH_TRANS_EN(reg32, val)              REG_FLD_SET(OVL_SBCH_FLD_L2_SBCH_TRANS_EN, (reg32), (val))
#define OVL_SBCH_SET_L1_SBCH_CNST_EN(reg32, val)               REG_FLD_SET(OVL_SBCH_FLD_L1_SBCH_CNST_EN, (reg32), (val))
#define OVL_SBCH_SET_L1_SBCH_TRANS_EN(reg32, val)              REG_FLD_SET(OVL_SBCH_FLD_L1_SBCH_TRANS_EN, (reg32), (val))
#define OVL_SBCH_SET_L0_SBCH_CNST_EN(reg32, val)               REG_FLD_SET(OVL_SBCH_FLD_L0_SBCH_CNST_EN, (reg32), (val))
#define OVL_SBCH_SET_L0_SBCH_TRANS_EN(reg32, val)              REG_FLD_SET(OVL_SBCH_FLD_L0_SBCH_TRANS_EN, (reg32), (val))
#define OVL_SBCH_SET_L3_SBCH_UPDATE(reg32, val)                REG_FLD_SET(OVL_SBCH_FLD_L3_SBCH_UPDATE, (reg32), (val))
#define OVL_SBCH_SET_L2_SBCH_UPDATE(reg32, val)                REG_FLD_SET(OVL_SBCH_FLD_L2_SBCH_UPDATE, (reg32), (val))
#define OVL_SBCH_SET_L1_SBCH_UPDATE(reg32, val)                REG_FLD_SET(OVL_SBCH_FLD_L1_SBCH_UPDATE, (reg32), (val))
#define OVL_SBCH_SET_L0_SBCH_UPDATE(reg32, val)                REG_FLD_SET(OVL_SBCH_FLD_L0_SBCH_UPDATE, (reg32), (val))

#define OVL_SBCH_EXT_SET_EL2_SBCH_CNST_EN(reg32, val)          REG_FLD_SET(OVL_SBCH_EXT_FLD_EL2_SBCH_CNST_EN, (reg32), (val))
#define OVL_SBCH_EXT_SET_EL2_SBCH_TRANS_EN(reg32, val)         REG_FLD_SET(OVL_SBCH_EXT_FLD_EL2_SBCH_TRANS_EN, (reg32), (val))
#define OVL_SBCH_EXT_SET_EL1_SBCH_CNST_EN(reg32, val)          REG_FLD_SET(OVL_SBCH_EXT_FLD_EL1_SBCH_CNST_EN, (reg32), (val))
#define OVL_SBCH_EXT_SET_EL1_SBCH_TRANS_EN(reg32, val)         REG_FLD_SET(OVL_SBCH_EXT_FLD_EL1_SBCH_TRANS_EN, (reg32), (val))
#define OVL_SBCH_EXT_SET_EL0_SBCH_CNST_EN(reg32, val)          REG_FLD_SET(OVL_SBCH_EXT_FLD_EL0_SBCH_CNST_EN, (reg32), (val))
#define OVL_SBCH_EXT_SET_EL0_SBCH_TRANS_EN(reg32, val)         REG_FLD_SET(OVL_SBCH_EXT_FLD_EL0_SBCH_TRANS_EN, (reg32), (val))
#define OVL_SBCH_EXT_SET_EL2_SBCH_UPDATE(reg32, val)           REG_FLD_SET(OVL_SBCH_EXT_FLD_EL2_SBCH_UPDATE, (reg32), (val))
#define OVL_SBCH_EXT_SET_EL1_SBCH_UPDATE(reg32, val)           REG_FLD_SET(OVL_SBCH_EXT_FLD_EL1_SBCH_UPDATE, (reg32), (val))
#define OVL_SBCH_EXT_SET_EL0_SBCH_UPDATE(reg32, val)           REG_FLD_SET(OVL_SBCH_EXT_FLD_EL0_SBCH_UPDATE, (reg32), (val))

#define OVL_SBCH_CON_SET_EL2_SBCH_TRANS_INVALID(reg32, val)    REG_FLD_SET(OVL_SBCH_CON_FLD_EL2_SBCH_TRANS_INVALID, (reg32), (val))
#define OVL_SBCH_CON_SET_EL1_SBCH_TRANS_INVALID(reg32, val)    REG_FLD_SET(OVL_SBCH_CON_FLD_EL1_SBCH_TRANS_INVALID, (reg32), (val))
#define OVL_SBCH_CON_SET_EL0_SBCH_TRANS_INVALID(reg32, val)    REG_FLD_SET(OVL_SBCH_CON_FLD_EL0_SBCH_TRANS_INVALID, (reg32), (val))
#define OVL_SBCH_CON_SET_L3_SBCH_TRANS_INVALID(reg32, val)     REG_FLD_SET(OVL_SBCH_CON_FLD_L3_SBCH_TRANS_INVALID, (reg32), (val))
#define OVL_SBCH_CON_SET_L2_SBCH_TRANS_INVALID(reg32, val)     REG_FLD_SET(OVL_SBCH_CON_FLD_L2_SBCH_TRANS_INVALID, (reg32), (val))
#define OVL_SBCH_CON_SET_L1_SBCH_TRANS_INVALID(reg32, val)     REG_FLD_SET(OVL_SBCH_CON_FLD_L1_SBCH_TRANS_INVALID, (reg32), (val))
#define OVL_SBCH_CON_SET_L0_SBCH_TRANS_INVALID(reg32, val)     REG_FLD_SET(OVL_SBCH_CON_FLD_L0_SBCH_TRANS_INVALID, (reg32), (val))

#define OVL_L0_ADDR_SET_L0_ADDR(reg32, val)                    REG_FLD_SET(OVL_L0_ADDR_FLD_L0_ADDR, (reg32), (val))

#define OVL_L1_ADDR_SET_L1_ADDR(reg32, val)                    REG_FLD_SET(OVL_L1_ADDR_FLD_L1_ADDR, (reg32), (val))

#define OVL_L2_ADDR_SET_L2_ADDR(reg32, val)                    REG_FLD_SET(OVL_L2_ADDR_FLD_L2_ADDR, (reg32), (val))

#define OVL_L3_ADDR_SET_L3_ADDR(reg32, val)                    REG_FLD_SET(OVL_L3_ADDR_FLD_L3_ADDR, (reg32), (val))

#define OVL_EL0_ADDR_SET_EL0_ADDR(reg32, val)                  REG_FLD_SET(OVL_EL0_ADDR_FLD_EL0_ADDR, (reg32), (val))

#define OVL_EL1_ADDR_SET_EL1_ADDR(reg32, val)                  REG_FLD_SET(OVL_EL1_ADDR_FLD_EL1_ADDR, (reg32), (val))

#define OVL_EL2_ADDR_SET_EL2_ADDR(reg32, val)                  REG_FLD_SET(OVL_EL2_ADDR_FLD_EL2_ADDR, (reg32), (val))

#define OVL_SECURE_SET_L3_SECURE(reg32, val)                   REG_FLD_SET(OVL_SECURE_FLD_L3_SECURE, (reg32), (val))
#define OVL_SECURE_SET_L2_SECURE(reg32, val)                   REG_FLD_SET(OVL_SECURE_FLD_L2_SECURE, (reg32), (val))
#define OVL_SECURE_SET_L1_SECURE(reg32, val)                   REG_FLD_SET(OVL_SECURE_FLD_L1_SECURE, (reg32), (val))
#define OVL_SECURE_SET_L0_SECURE(reg32, val)                   REG_FLD_SET(OVL_SECURE_FLD_L0_SECURE, (reg32), (val))

#define OVL_STA_VAL_RDMA3_IDLE(val)                            REG_FLD_VAL(OVL_STA_FLD_RDMA3_IDLE, (val))
#define OVL_STA_VAL_RDMA2_IDLE(val)                            REG_FLD_VAL(OVL_STA_FLD_RDMA2_IDLE, (val))
#define OVL_STA_VAL_RDMA1_IDLE(val)                            REG_FLD_VAL(OVL_STA_FLD_RDMA1_IDLE, (val))
#define OVL_STA_VAL_RDMA0_IDLE(val)                            REG_FLD_VAL(OVL_STA_FLD_RDMA0_IDLE, (val))
#define OVL_STA_VAL_OVL_RUN(val)                               REG_FLD_VAL(OVL_STA_FLD_OVL_RUN, (val))

#define OVL_INTEN_VAL_OVL_START_INTEN(val)                     REG_FLD_VAL(OVL_INTEN_FLD_OVL_START_INTEN, (val))
#define OVL_INTEN_VAL_ABNORMAL_SOF_INTEN(val)                  REG_FLD_VAL(OVL_INTEN_FLD_ABNORMAL_SOF_INTEN, (val))
#define OVL_INTEN_VAL_RDMA3_SMI_UNDERFLOW_INTEN(val)           REG_FLD_VAL(OVL_INTEN_FLD_RDMA3_SMI_UNDERFLOW_INTEN, (val))
#define OVL_INTEN_VAL_RDMA2_SMI_UNDERFLOW_INTEN(val)           REG_FLD_VAL(OVL_INTEN_FLD_RDMA2_SMI_UNDERFLOW_INTEN, (val))
#define OVL_INTEN_VAL_RDMA1_SMI_UNDERFLOW_INTEN(val)           REG_FLD_VAL(OVL_INTEN_FLD_RDMA1_SMI_UNDERFLOW_INTEN, (val))
#define OVL_INTEN_VAL_RDMA0_SMI_UNDERFLOW_INTEN(val)           REG_FLD_VAL(OVL_INTEN_FLD_RDMA0_SMI_UNDERFLOW_INTEN, (val))
#define OVL_INTEN_VAL_RDMA3_EOF_ABNORMAL_INTEN(val)            REG_FLD_VAL(OVL_INTEN_FLD_RDMA3_EOF_ABNORMAL_INTEN, (val))
#define OVL_INTEN_VAL_RDMA2_EOF_ABNORMAL_INTEN(val)            REG_FLD_VAL(OVL_INTEN_FLD_RDMA2_EOF_ABNORMAL_INTEN, (val))
#define OVL_INTEN_VAL_RDMA1_EOF_ABNORMAL_INTEN(val)            REG_FLD_VAL(OVL_INTEN_FLD_RDMA1_EOF_ABNORMAL_INTEN, (val))
#define OVL_INTEN_VAL_RDMA0_EOF_ABNORMAL_INTEN(val)            REG_FLD_VAL(OVL_INTEN_FLD_RDMA0_EOF_ABNORMAL_INTEN, (val))
#define OVL_INTEN_VAL_OVL_FME_HWRST_DONE_INTEN(val)            REG_FLD_VAL(OVL_INTEN_FLD_OVL_FME_HWRST_DONE_INTEN, (val))
#define OVL_INTEN_VAL_OVL_FME_SWRST_DONE_INTEN(val)            REG_FLD_VAL(OVL_INTEN_FLD_OVL_FME_SWRST_DONE_INTEN, (val))
#define OVL_INTEN_VAL_OVL_FME_UND_INTEN(val)                   REG_FLD_VAL(OVL_INTEN_FLD_OVL_FME_UND_INTEN, (val))
#define OVL_INTEN_VAL_OVL_FME_CPL_INTEN(val)                   REG_FLD_VAL(OVL_INTEN_FLD_OVL_FME_CPL_INTEN, (val))
#define OVL_INTEN_VAL_OVL_REG_CMT_INTEN(val)                   REG_FLD_VAL(OVL_INTEN_FLD_OVL_REG_CMT_INTEN, (val))

#define OVL_INTSTA_VAL_OVL_START_INTSTA(val)                   REG_FLD_VAL(OVL_INTSTA_FLD_OVL_START_INTSTA, (val))
#define OVL_INTSTA_VAL_ABNORMAL_SOF_INTSTA(val)                REG_FLD_VAL(OVL_INTSTA_FLD_ABNORMAL_SOF_INTSTA, (val))
#define OVL_INTSTA_VAL_RDMA3_SMI_UNDERFLOW_INTSTA(val)         REG_FLD_VAL(OVL_INTSTA_FLD_RDMA3_SMI_UNDERFLOW_INTSTA, (val))
#define OVL_INTSTA_VAL_RDMA2_SMI_UNDERFLOW_INTSTA(val)         REG_FLD_VAL(OVL_INTSTA_FLD_RDMA2_SMI_UNDERFLOW_INTSTA, (val))
#define OVL_INTSTA_VAL_RDMA1_SMI_UNDERFLOW_INTSTA(val)         REG_FLD_VAL(OVL_INTSTA_FLD_RDMA1_SMI_UNDERFLOW_INTSTA, (val))
#define OVL_INTSTA_VAL_RDMA0_SMI_UNDERFLOW_INTSTA(val)         REG_FLD_VAL(OVL_INTSTA_FLD_RDMA0_SMI_UNDERFLOW_INTSTA, (val))
#define OVL_INTSTA_VAL_RDMA3_EOF_ABNORMAL_INTSTA(val)          REG_FLD_VAL(OVL_INTSTA_FLD_RDMA3_EOF_ABNORMAL_INTSTA, (val))
#define OVL_INTSTA_VAL_RDMA2_EOF_ABNORMAL_INTSTA(val)          REG_FLD_VAL(OVL_INTSTA_FLD_RDMA2_EOF_ABNORMAL_INTSTA, (val))
#define OVL_INTSTA_VAL_RDMA1_EOF_ABNORMAL_INTSTA(val)          REG_FLD_VAL(OVL_INTSTA_FLD_RDMA1_EOF_ABNORMAL_INTSTA, (val))
#define OVL_INTSTA_VAL_RDMA0_EOF_ABNORMAL_INTSTA(val)          REG_FLD_VAL(OVL_INTSTA_FLD_RDMA0_EOF_ABNORMAL_INTSTA, (val))
#define OVL_INTSTA_VAL_OVL_FME_HWRST_DONE_INTSTA(val)          REG_FLD_VAL(OVL_INTSTA_FLD_OVL_FME_HWRST_DONE_INTSTA, (val))
#define OVL_INTSTA_VAL_OVL_FME_SWRST_DONE_INTSTA(val)          REG_FLD_VAL(OVL_INTSTA_FLD_OVL_FME_SWRST_DONE_INTSTA, (val))
#define OVL_INTSTA_VAL_OVL_FME_UND_INTSTA(val)                 REG_FLD_VAL(OVL_INTSTA_FLD_OVL_FME_UND_INTSTA, (val))
#define OVL_INTSTA_VAL_OVL_FME_CPL_INTSTA(val)                 REG_FLD_VAL(OVL_INTSTA_FLD_OVL_FME_CPL_INTSTA, (val))
#define OVL_INTSTA_VAL_OVL_REG_CMT_INTSTA(val)                 REG_FLD_VAL(OVL_INTSTA_FLD_OVL_REG_CMT_INTSTA, (val))

#define OVL_EN_VAL_BLOCK_EXT_PREULTRA(val)                     REG_FLD_VAL(OVL_EN_FLD_BLOCK_EXT_PREULTRA, (val))
#define OVL_EN_VAL_BLOCK_EXT_ULTRA(val)                        REG_FLD_VAL(OVL_EN_FLD_BLOCK_EXT_ULTRA, (val))
#define OVL_EN_VAL_IGNORE_ABNORMAL_SOF(val)                    REG_FLD_VAL(OVL_EN_FLD_IGNORE_ABNORMAL_SOF, (val))
#define OVL_EN_VAL_HF_FOVL_CK_ON(val)                          REG_FLD_VAL(OVL_EN_FLD_HF_FOVL_CK_ON, (val))
#define OVL_EN_VAL_HG_FSMI_CK_ON(val)                          REG_FLD_VAL(OVL_EN_FLD_HG_FSMI_CK_ON, (val))
#define OVL_EN_VAL_HG_FOVL_CK_ON(val)                          REG_FLD_VAL(OVL_EN_FLD_HG_FOVL_CK_ON, (val))
#define OVL_EN_VAL_OVL_EN(val)                                 REG_FLD_VAL(OVL_EN_FLD_OVL_EN, (val))

#define OVL_TRIG_VAL_CRC_CLR(val)                              REG_FLD_VAL(OVL_TRIG_FLD_CRC_CLR, (val))
#define OVL_TRIG_VAL_CRC_EN(val)                               REG_FLD_VAL(OVL_TRIG_FLD_CRC_EN, (val))
#define OVL_TRIG_VAL_OVL_SW_TRIG(val)                          REG_FLD_VAL(OVL_TRIG_FLD_OVL_SW_TRIG, (val))

#define OVL_RST_VAL_OVL_SMI_IOBUF_HARD_RST(val)                REG_FLD_VAL(OVL_RST_FLD_OVL_SMI_IOBUF_HARD_RST, (val))
#define OVL_RST_VAL_OVL_SMI_IOBUF_RST(val)                     REG_FLD_VAL(OVL_RST_FLD_OVL_SMI_IOBUF_RST, (val))
#define OVL_RST_VAL_OVL_SMI_HARD_RST(val)                      REG_FLD_VAL(OVL_RST_FLD_OVL_SMI_HARD_RST, (val))
#define OVL_RST_VAL_OVL_SMI_RST(val)                           REG_FLD_VAL(OVL_RST_FLD_OVL_SMI_RST, (val))
#define OVL_RST_VAL_OVL_RST(val)                               REG_FLD_VAL(OVL_RST_FLD_OVL_RST, (val))

#define OVL_ROI_SIZE_VAL_ROI_H(val)                            REG_FLD_VAL(OVL_ROI_SIZE_FLD_ROI_H, (val))
#define OVL_ROI_SIZE_VAL_ROI_W(val)                            REG_FLD_VAL(OVL_ROI_SIZE_FLD_ROI_W, (val))

#define OVL_DATAPATH_CON_VAL_WIDE_GAMUT_EN(val)                REG_FLD_VAL(OVL_DATAPATH_CON_FLD_WIDE_GAMUT_EN, (val))
#define OVL_DATAPATH_CON_VAL_OUTPUT_INTERLACE(val)             REG_FLD_VAL(OVL_DATAPATH_CON_FLD_OUTPUT_INTERLACE, (val))
#define OVL_DATAPATH_CON_VAL_OUTPUT_CLAMP(val)                 REG_FLD_VAL(OVL_DATAPATH_CON_FLD_OUTPUT_CLAMP, (val))
#define OVL_DATAPATH_CON_VAL_GCLAST_EN(val)                    REG_FLD_VAL(OVL_DATAPATH_CON_FLD_GCLAST_EN, (val))
#define OVL_DATAPATH_CON_VAL_RDMA3_OUT_SEL(val)                REG_FLD_VAL(OVL_DATAPATH_CON_FLD_RDMA3_OUT_SEL, (val))
#define OVL_DATAPATH_CON_VAL_RDMA2_OUT_SEL(val)                REG_FLD_VAL(OVL_DATAPATH_CON_FLD_RDMA2_OUT_SEL, (val))
#define OVL_DATAPATH_CON_VAL_RDMA1_OUT_SEL(val)                REG_FLD_VAL(OVL_DATAPATH_CON_FLD_RDMA1_OUT_SEL, (val))
#define OVL_DATAPATH_CON_VAL_RDMA0_OUT_SEL(val)                REG_FLD_VAL(OVL_DATAPATH_CON_FLD_RDMA0_OUT_SEL, (val))
#define OVL_DATAPATH_CON_VAL_PQ_OUT_SEL(val)                   REG_FLD_VAL(OVL_DATAPATH_CON_FLD_PQ_OUT_SEL, (val))
#define OVL_DATAPATH_CON_VAL_OVL_GAMMA_OUT(val)                REG_FLD_VAL(OVL_DATAPATH_CON_FLD_OVL_GAMMA_OUT, (val))
#define OVL_DATAPATH_CON_VAL_ADOBE_LAYER(val)                  REG_FLD_VAL(OVL_DATAPATH_CON_FLD_ADOBE_LAYER, (val))
#define OVL_DATAPATH_CON_VAL_ADOBE_MODE(val)                   REG_FLD_VAL(OVL_DATAPATH_CON_FLD_ADOBE_MODE, (val))
#define OVL_DATAPATH_CON_VAL_L3_GPU_MODE(val)                  REG_FLD_VAL(OVL_DATAPATH_CON_FLD_L3_GPU_MODE, (val))
#define OVL_DATAPATH_CON_VAL_L2_GPU_MODE(val)                  REG_FLD_VAL(OVL_DATAPATH_CON_FLD_L2_GPU_MODE, (val))
#define OVL_DATAPATH_CON_VAL_L1_GPU_MODE(val)                  REG_FLD_VAL(OVL_DATAPATH_CON_FLD_L1_GPU_MODE, (val))
#define OVL_DATAPATH_CON_VAL_L0_GPU_MODE(val)                  REG_FLD_VAL(OVL_DATAPATH_CON_FLD_L0_GPU_MODE, (val))
#define OVL_DATAPATH_CON_VAL_OUTPUT_NO_RND(val)                REG_FLD_VAL(OVL_DATAPATH_CON_FLD_OUTPUT_NO_RND, (val))
#define OVL_DATAPATH_CON_VAL_BGCLR_IN_SEL(val)                 REG_FLD_VAL(OVL_DATAPATH_CON_FLD_BGCLR_IN_SEL, (val))
#define OVL_DATAPATH_CON_VAL_OVL_RANDOM_BGCLR_EN(val)          REG_FLD_VAL(OVL_DATAPATH_CON_FLD_OVL_RANDOM_BGCLR_EN, (val))
#define OVL_DATAPATH_CON_VAL_LAYER_SMI_ID_EN(val)              REG_FLD_VAL(OVL_DATAPATH_CON_FLD_LAYER_SMI_ID_EN, (val))

#define OVL_ROI_BGCLR_VAL_ALPHA(val)                           REG_FLD_VAL(OVL_ROI_BGCLR_FLD_ALPHA, (val))
#define OVL_ROI_BGCLR_VAL_RED(val)                             REG_FLD_VAL(OVL_ROI_BGCLR_FLD_RED, (val))
#define OVL_ROI_BGCLR_VAL_GREEN(val)                           REG_FLD_VAL(OVL_ROI_BGCLR_FLD_GREEN, (val))
#define OVL_ROI_BGCLR_VAL_BLUE(val)                            REG_FLD_VAL(OVL_ROI_BGCLR_FLD_BLUE, (val))

#define OVL_SRC_CON_VAL_RELAY_MODE_EN(val)                     REG_FLD_VAL(OVL_SRC_CON_FLD_RELAY_MODE_EN, (val))
#define OVL_SRC_CON_VAL_FORCE_RELAY_MODE(val)                  REG_FLD_VAL(OVL_SRC_CON_FLD_FORCE_RELAY_MODE, (val))
#define OVL_SRC_CON_VAL_LC_EN(val)                             REG_FLD_VAL(OVL_SRC_CON_FLD_LC_EN, (val))
#define OVL_SRC_CON_VAL_L3_EN(val)                             REG_FLD_VAL(OVL_SRC_CON_FLD_L3_EN, (val))
#define OVL_SRC_CON_VAL_L2_EN(val)                             REG_FLD_VAL(OVL_SRC_CON_FLD_L2_EN, (val))
#define OVL_SRC_CON_VAL_L1_EN(val)                             REG_FLD_VAL(OVL_SRC_CON_FLD_L1_EN, (val))
#define OVL_SRC_CON_VAL_L0_EN(val)                             REG_FLD_VAL(OVL_SRC_CON_FLD_L0_EN, (val))

#define OVL_L0_CON_VAL_DSTKEY_EN(val)                          REG_FLD_VAL(OVL_L0_CON_FLD_DSTKEY_EN, (val))
#define OVL_L0_CON_VAL_SRCKEY_EN(val)                          REG_FLD_VAL(OVL_L0_CON_FLD_SRCKEY_EN, (val))
#define OVL_L0_CON_VAL_LAYER_SRC(val)                          REG_FLD_VAL(OVL_L0_CON_FLD_LAYER_SRC, (val))
#define OVL_L0_CON_VAL_MTX_EN(val)                             REG_FLD_VAL(OVL_L0_CON_FLD_MTX_EN, (val))
#define OVL_L0_CON_VAL_MTX_AUTO_DIS(val)                       REG_FLD_VAL(OVL_L0_CON_FLD_MTX_AUTO_DIS, (val))
#define OVL_L0_CON_VAL_RGB_SWAP(val)                           REG_FLD_VAL(OVL_L0_CON_FLD_RGB_SWAP, (val))
#define OVL_L0_CON_VAL_BYTE_SWAP(val)                          REG_FLD_VAL(OVL_L0_CON_FLD_BYTE_SWAP, (val))
#define OVL_L0_CON_VAL_CLRFMT_MAN(val)                         REG_FLD_VAL(OVL_L0_CON_FLD_CLRFMT_MAN, (val))
#define OVL_L0_CON_VAL_R_FIRST(val)                            REG_FLD_VAL(OVL_L0_CON_FLD_R_FIRST, (val))
#define OVL_L0_CON_VAL_LANDSCAPE(val)                          REG_FLD_VAL(OVL_L0_CON_FLD_LANDSCAPE, (val))
#define OVL_L0_CON_VAL_EN_3D(val)                              REG_FLD_VAL(OVL_L0_CON_FLD_EN_3D, (val))
#define OVL_L0_CON_VAL_INT_MTX_SEL(val)                        REG_FLD_VAL(OVL_L0_CON_FLD_INT_MTX_SEL, (val))
#define OVL_L0_CON_VAL_CLRFMT(val)                             REG_FLD_VAL(OVL_L0_CON_FLD_CLRFMT, (val))
#define OVL_L0_CON_VAL_EXT_MTX_EN(val)                         REG_FLD_VAL(OVL_L0_CON_FLD_EXT_MTX_EN, (val))
#define OVL_L0_CON_VAL_HORIZONTAL_FLIP_EN(val)                 REG_FLD_VAL(OVL_L0_CON_FLD_HORIZONTAL_FLIP_EN, (val))
#define OVL_L0_CON_VAL_VERTICAL_FLIP_EN(val)                   REG_FLD_VAL(OVL_L0_CON_FLD_VERTICAL_FLIP_EN, (val))
#define OVL_L0_CON_VAL_ALPHA_EN(val)                           REG_FLD_VAL(OVL_L0_CON_FLD_ALPHA_EN, (val))
#define OVL_L0_CON_VAL_ALPHA(val)                              REG_FLD_VAL(OVL_L0_CON_FLD_ALPHA, (val))

#define OVL_L0_SRCKEY_VAL_SRCKEY(val)                          REG_FLD_VAL(OVL_L0_SRCKEY_FLD_SRCKEY, (val))

#define OVL_L0_SRC_SIZE_VAL_L0_SRC_H(val)                      REG_FLD_VAL(OVL_L0_SRC_SIZE_FLD_L0_SRC_H, (val))
#define OVL_L0_SRC_SIZE_VAL_L0_SRC_W(val)                      REG_FLD_VAL(OVL_L0_SRC_SIZE_FLD_L0_SRC_W, (val))

#define OVL_L0_OFFSET_VAL_L0_YOFF(val)                         REG_FLD_VAL(OVL_L0_OFFSET_FLD_L0_YOFF, (val))
#define OVL_L0_OFFSET_VAL_L0_XOFF(val)                         REG_FLD_VAL(OVL_L0_OFFSET_FLD_L0_XOFF, (val))

#define OVL_L0_PITCH_VAL_SURFL_EN(val)                         REG_FLD_VAL(OVL_L0_PITCH_FLD_SURFL_EN, (val))
#define OVL_L0_PITCH_VAL_L0_BLEND_RND_SHT(val)                 REG_FLD_VAL(OVL_L0_PITCH_FLD_L0_BLEND_RND_SHT, (val))
#define OVL_L0_PITCH_VAL_L0_SRGB_SEL_EXT2(val)                 REG_FLD_VAL(OVL_L0_PITCH_FLD_L0_SRGB_SEL_EXT2, (val))
#define OVL_L0_PITCH_VAL_L0_CONST_BLD(val)                     REG_FLD_VAL(OVL_L0_PITCH_FLD_L0_CONST_BLD, (val))
#define OVL_L0_PITCH_VAL_L0_DRGB_SEL_EXT(val)                  REG_FLD_VAL(OVL_L0_PITCH_FLD_L0_DRGB_SEL_EXT, (val))
#define OVL_L0_PITCH_VAL_L0_DA_SEL_EXT(val)                    REG_FLD_VAL(OVL_L0_PITCH_FLD_L0_DA_SEL_EXT, (val))
#define OVL_L0_PITCH_VAL_L0_SRGB_SEL_EXT(val)                  REG_FLD_VAL(OVL_L0_PITCH_FLD_L0_SRGB_SEL_EXT, (val))
#define OVL_L0_PITCH_VAL_L0_SA_SEL_EXT(val)                    REG_FLD_VAL(OVL_L0_PITCH_FLD_L0_SA_SEL_EXT, (val))
#define OVL_L0_PITCH_VAL_L0_DRGB_SEL(val)                      REG_FLD_VAL(OVL_L0_PITCH_FLD_L0_DRGB_SEL, (val))
#define OVL_L0_PITCH_VAL_L0_DA_SEL(val)                        REG_FLD_VAL(OVL_L0_PITCH_FLD_L0_DA_SEL, (val))
#define OVL_L0_PITCH_VAL_L0_SRGB_SEL(val)                      REG_FLD_VAL(OVL_L0_PITCH_FLD_L0_SRGB_SEL, (val))
#define OVL_L0_PITCH_VAL_L0_SA_SEL(val)                        REG_FLD_VAL(OVL_L0_PITCH_FLD_L0_SA_SEL, (val))
#define OVL_L0_PITCH_VAL_L0_SRC_PITCH(val)                     REG_FLD_VAL(OVL_L0_PITCH_FLD_L0_SRC_PITCH, (val))

#define OVL_L0_TILE_VAL_TILE_HORI_BLOCK_NUM(val)               REG_FLD_VAL(OVL_L0_TILE_FLD_TILE_HORI_BLOCK_NUM, (val))
#define OVL_L0_TILE_VAL_TILE_EN(val)                           REG_FLD_VAL(OVL_L0_TILE_FLD_TILE_EN, (val))
#define OVL_L0_TILE_VAL_TILE_WIDTH_SEL(val)                    REG_FLD_VAL(OVL_L0_TILE_FLD_TILE_WIDTH_SEL, (val))
#define OVL_L0_TILE_VAL_TILE_HEIGHT(val)                       REG_FLD_VAL(OVL_L0_TILE_FLD_TILE_HEIGHT, (val))

#define OVL_L0_CLIP_VAL_L0_SRC_BOTTOM_CLIP(val)                REG_FLD_VAL(OVL_L0_CLIP_FLD_L0_SRC_BOTTOM_CLIP, (val))
#define OVL_L0_CLIP_VAL_L0_SRC_TOP_CLIP(val)                   REG_FLD_VAL(OVL_L0_CLIP_FLD_L0_SRC_TOP_CLIP, (val))
#define OVL_L0_CLIP_VAL_L0_SRC_RIGHT_CLIP(val)                 REG_FLD_VAL(OVL_L0_CLIP_FLD_L0_SRC_RIGHT_CLIP, (val))
#define OVL_L0_CLIP_VAL_L0_SRC_LEFT_CLIP(val)                  REG_FLD_VAL(OVL_L0_CLIP_FLD_L0_SRC_LEFT_CLIP, (val))

#define OVL_L1_CON_VAL_DSTKEY_EN(val)                          REG_FLD_VAL(OVL_L1_CON_FLD_DSTKEY_EN, (val))
#define OVL_L1_CON_VAL_SRCKEY_EN(val)                          REG_FLD_VAL(OVL_L1_CON_FLD_SRCKEY_EN, (val))
#define OVL_L1_CON_VAL_LAYER_SRC(val)                          REG_FLD_VAL(OVL_L1_CON_FLD_LAYER_SRC, (val))
#define OVL_L1_CON_VAL_MTX_EN(val)                             REG_FLD_VAL(OVL_L1_CON_FLD_MTX_EN, (val))
#define OVL_L1_CON_VAL_MTX_AUTO_DIS(val)                       REG_FLD_VAL(OVL_L1_CON_FLD_MTX_AUTO_DIS, (val))
#define OVL_L1_CON_VAL_RGB_SWAP(val)                           REG_FLD_VAL(OVL_L1_CON_FLD_RGB_SWAP, (val))
#define OVL_L1_CON_VAL_BYTE_SWAP(val)                          REG_FLD_VAL(OVL_L1_CON_FLD_BYTE_SWAP, (val))
#define OVL_L1_CON_VAL_CLRFMT_MAN(val)                         REG_FLD_VAL(OVL_L1_CON_FLD_CLRFMT_MAN, (val))
#define OVL_L1_CON_VAL_R_FIRST(val)                            REG_FLD_VAL(OVL_L1_CON_FLD_R_FIRST, (val))
#define OVL_L1_CON_VAL_LANDSCAPE(val)                          REG_FLD_VAL(OVL_L1_CON_FLD_LANDSCAPE, (val))
#define OVL_L1_CON_VAL_EN_3D(val)                              REG_FLD_VAL(OVL_L1_CON_FLD_EN_3D, (val))
#define OVL_L1_CON_VAL_INT_MTX_SEL(val)                        REG_FLD_VAL(OVL_L1_CON_FLD_INT_MTX_SEL, (val))
#define OVL_L1_CON_VAL_CLRFMT(val)                             REG_FLD_VAL(OVL_L1_CON_FLD_CLRFMT, (val))
#define OVL_L1_CON_VAL_EXT_MTX_EN(val)                         REG_FLD_VAL(OVL_L1_CON_FLD_EXT_MTX_EN, (val))
#define OVL_L1_CON_VAL_HORIZONTAL_FLIP_EN(val)                 REG_FLD_VAL(OVL_L1_CON_FLD_HORIZONTAL_FLIP_EN, (val))
#define OVL_L1_CON_VAL_VERTICAL_FLIP_EN(val)                   REG_FLD_VAL(OVL_L1_CON_FLD_VERTICAL_FLIP_EN, (val))
#define OVL_L1_CON_VAL_ALPHA_EN(val)                           REG_FLD_VAL(OVL_L1_CON_FLD_ALPHA_EN, (val))
#define OVL_L1_CON_VAL_ALPHA(val)                              REG_FLD_VAL(OVL_L1_CON_FLD_ALPHA, (val))

#define OVL_L1_SRCKEY_VAL_SRCKEY(val)                          REG_FLD_VAL(OVL_L1_SRCKEY_FLD_SRCKEY, (val))

#define OVL_L1_SRC_SIZE_VAL_L1_SRC_H(val)                      REG_FLD_VAL(OVL_L1_SRC_SIZE_FLD_L1_SRC_H, (val))
#define OVL_L1_SRC_SIZE_VAL_L1_SRC_W(val)                      REG_FLD_VAL(OVL_L1_SRC_SIZE_FLD_L1_SRC_W, (val))

#define OVL_L1_OFFSET_VAL_L1_YOFF(val)                         REG_FLD_VAL(OVL_L1_OFFSET_FLD_L1_YOFF, (val))
#define OVL_L1_OFFSET_VAL_L1_XOFF(val)                         REG_FLD_VAL(OVL_L1_OFFSET_FLD_L1_XOFF, (val))

#define OVL_L1_PITCH_VAL_SURFL_EN(val)                         REG_FLD_VAL(OVL_L1_PITCH_FLD_SURFL_EN, (val))
#define OVL_L1_PITCH_VAL_L1_BLEND_RND_SHT(val)                 REG_FLD_VAL(OVL_L1_PITCH_FLD_L1_BLEND_RND_SHT, (val))
#define OVL_L1_PITCH_VAL_L1_SRGB_SEL_EXT2(val)                 REG_FLD_VAL(OVL_L1_PITCH_FLD_L1_SRGB_SEL_EXT2, (val))
#define OVL_L1_PITCH_VAL_L1_CONST_BLD(val)                     REG_FLD_VAL(OVL_L1_PITCH_FLD_L1_CONST_BLD, (val))
#define OVL_L1_PITCH_VAL_L1_DRGB_SEL_EXT(val)                  REG_FLD_VAL(OVL_L1_PITCH_FLD_L1_DRGB_SEL_EXT, (val))
#define OVL_L1_PITCH_VAL_L1_DA_SEL_EXT(val)                    REG_FLD_VAL(OVL_L1_PITCH_FLD_L1_DA_SEL_EXT, (val))
#define OVL_L1_PITCH_VAL_L1_SRGB_SEL_EXT(val)                  REG_FLD_VAL(OVL_L1_PITCH_FLD_L1_SRGB_SEL_EXT, (val))
#define OVL_L1_PITCH_VAL_L1_SA_SEL_EXT(val)                    REG_FLD_VAL(OVL_L1_PITCH_FLD_L1_SA_SEL_EXT, (val))
#define OVL_L1_PITCH_VAL_L1_DRGB_SEL(val)                      REG_FLD_VAL(OVL_L1_PITCH_FLD_L1_DRGB_SEL, (val))
#define OVL_L1_PITCH_VAL_L1_DA_SEL(val)                        REG_FLD_VAL(OVL_L1_PITCH_FLD_L1_DA_SEL, (val))
#define OVL_L1_PITCH_VAL_L1_SRGB_SEL(val)                      REG_FLD_VAL(OVL_L1_PITCH_FLD_L1_SRGB_SEL, (val))
#define OVL_L1_PITCH_VAL_L1_SA_SEL(val)                        REG_FLD_VAL(OVL_L1_PITCH_FLD_L1_SA_SEL, (val))
#define OVL_L1_PITCH_VAL_L1_SRC_PITCH(val)                     REG_FLD_VAL(OVL_L1_PITCH_FLD_L1_SRC_PITCH, (val))

#define OVL_L1_TILE_VAL_TILE_HORI_BLOCK_NUM(val)               REG_FLD_VAL(OVL_L1_TILE_FLD_TILE_HORI_BLOCK_NUM, (val))
#define OVL_L1_TILE_VAL_TILE_EN(val)                           REG_FLD_VAL(OVL_L1_TILE_FLD_TILE_EN, (val))
#define OVL_L1_TILE_VAL_TILE_WIDTH_SEL(val)                    REG_FLD_VAL(OVL_L1_TILE_FLD_TILE_WIDTH_SEL, (val))
#define OVL_L1_TILE_VAL_TILE_HEIGHT(val)                       REG_FLD_VAL(OVL_L1_TILE_FLD_TILE_HEIGHT, (val))

#define OVL_L1_CLIP_VAL_L1_SRC_BOTTOM_CLIP(val)                REG_FLD_VAL(OVL_L1_CLIP_FLD_L1_SRC_BOTTOM_CLIP, (val))
#define OVL_L1_CLIP_VAL_L1_SRC_TOP_CLIP(val)                   REG_FLD_VAL(OVL_L1_CLIP_FLD_L1_SRC_TOP_CLIP, (val))
#define OVL_L1_CLIP_VAL_L1_SRC_RIGHT_CLIP(val)                 REG_FLD_VAL(OVL_L1_CLIP_FLD_L1_SRC_RIGHT_CLIP, (val))
#define OVL_L1_CLIP_VAL_L1_SRC_LEFT_CLIP(val)                  REG_FLD_VAL(OVL_L1_CLIP_FLD_L1_SRC_LEFT_CLIP, (val))

#define OVL_L2_CON_VAL_DSTKEY_EN(val)                          REG_FLD_VAL(OVL_L2_CON_FLD_DSTKEY_EN, (val))
#define OVL_L2_CON_VAL_SRCKEY_EN(val)                          REG_FLD_VAL(OVL_L2_CON_FLD_SRCKEY_EN, (val))
#define OVL_L2_CON_VAL_LAYER_SRC(val)                          REG_FLD_VAL(OVL_L2_CON_FLD_LAYER_SRC, (val))
#define OVL_L2_CON_VAL_MTX_EN(val)                             REG_FLD_VAL(OVL_L2_CON_FLD_MTX_EN, (val))
#define OVL_L2_CON_VAL_MTX_AUTO_DIS(val)                       REG_FLD_VAL(OVL_L2_CON_FLD_MTX_AUTO_DIS, (val))
#define OVL_L2_CON_VAL_RGB_SWAP(val)                           REG_FLD_VAL(OVL_L2_CON_FLD_RGB_SWAP, (val))
#define OVL_L2_CON_VAL_BYTE_SWAP(val)                          REG_FLD_VAL(OVL_L2_CON_FLD_BYTE_SWAP, (val))
#define OVL_L2_CON_VAL_CLRFMT_MAN(val)                         REG_FLD_VAL(OVL_L2_CON_FLD_CLRFMT_MAN, (val))
#define OVL_L2_CON_VAL_R_FIRST(val)                            REG_FLD_VAL(OVL_L2_CON_FLD_R_FIRST, (val))
#define OVL_L2_CON_VAL_LANDSCAPE(val)                          REG_FLD_VAL(OVL_L2_CON_FLD_LANDSCAPE, (val))
#define OVL_L2_CON_VAL_EN_3D(val)                              REG_FLD_VAL(OVL_L2_CON_FLD_EN_3D, (val))
#define OVL_L2_CON_VAL_INT_MTX_SEL(val)                        REG_FLD_VAL(OVL_L2_CON_FLD_INT_MTX_SEL, (val))
#define OVL_L2_CON_VAL_CLRFMT(val)                             REG_FLD_VAL(OVL_L2_CON_FLD_CLRFMT, (val))
#define OVL_L2_CON_VAL_EXT_MTX_EN(val)                         REG_FLD_VAL(OVL_L2_CON_FLD_EXT_MTX_EN, (val))
#define OVL_L2_CON_VAL_HORIZONTAL_FLIP_EN(val)                 REG_FLD_VAL(OVL_L2_CON_FLD_HORIZONTAL_FLIP_EN, (val))
#define OVL_L2_CON_VAL_VERTICAL_FLIP_EN(val)                   REG_FLD_VAL(OVL_L2_CON_FLD_VERTICAL_FLIP_EN, (val))
#define OVL_L2_CON_VAL_ALPHA_EN(val)                           REG_FLD_VAL(OVL_L2_CON_FLD_ALPHA_EN, (val))
#define OVL_L2_CON_VAL_ALPHA(val)                              REG_FLD_VAL(OVL_L2_CON_FLD_ALPHA, (val))

#define OVL_L2_SRCKEY_VAL_SRCKEY(val)                          REG_FLD_VAL(OVL_L2_SRCKEY_FLD_SRCKEY, (val))

#define OVL_L2_SRC_SIZE_VAL_L2_SRC_H(val)                      REG_FLD_VAL(OVL_L2_SRC_SIZE_FLD_L2_SRC_H, (val))
#define OVL_L2_SRC_SIZE_VAL_L2_SRC_W(val)                      REG_FLD_VAL(OVL_L2_SRC_SIZE_FLD_L2_SRC_W, (val))

#define OVL_L2_OFFSET_VAL_L2_YOFF(val)                         REG_FLD_VAL(OVL_L2_OFFSET_FLD_L2_YOFF, (val))
#define OVL_L2_OFFSET_VAL_L2_XOFF(val)                         REG_FLD_VAL(OVL_L2_OFFSET_FLD_L2_XOFF, (val))

#define OVL_L2_PITCH_VAL_SURFL_EN(val)                         REG_FLD_VAL(OVL_L2_PITCH_FLD_SURFL_EN, (val))
#define OVL_L2_PITCH_VAL_L2_BLEND_RND_SHT(val)                 REG_FLD_VAL(OVL_L2_PITCH_FLD_L2_BLEND_RND_SHT, (val))
#define OVL_L2_PITCH_VAL_L2_SRGB_SEL_EXT2(val)                 REG_FLD_VAL(OVL_L2_PITCH_FLD_L2_SRGB_SEL_EXT2, (val))
#define OVL_L2_PITCH_VAL_L2_CONST_BLD(val)                     REG_FLD_VAL(OVL_L2_PITCH_FLD_L2_CONST_BLD, (val))
#define OVL_L2_PITCH_VAL_L2_DRGB_SEL_EXT(val)                  REG_FLD_VAL(OVL_L2_PITCH_FLD_L2_DRGB_SEL_EXT, (val))
#define OVL_L2_PITCH_VAL_L2_DA_SEL_EXT(val)                    REG_FLD_VAL(OVL_L2_PITCH_FLD_L2_DA_SEL_EXT, (val))
#define OVL_L2_PITCH_VAL_L2_SRGB_SEL_EXT(val)                  REG_FLD_VAL(OVL_L2_PITCH_FLD_L2_SRGB_SEL_EXT, (val))
#define OVL_L2_PITCH_VAL_L2_SA_SEL_EXT(val)                    REG_FLD_VAL(OVL_L2_PITCH_FLD_L2_SA_SEL_EXT, (val))
#define OVL_L2_PITCH_VAL_L2_DRGB_SEL(val)                      REG_FLD_VAL(OVL_L2_PITCH_FLD_L2_DRGB_SEL, (val))
#define OVL_L2_PITCH_VAL_L2_DA_SEL(val)                        REG_FLD_VAL(OVL_L2_PITCH_FLD_L2_DA_SEL, (val))
#define OVL_L2_PITCH_VAL_L2_SRGB_SEL(val)                      REG_FLD_VAL(OVL_L2_PITCH_FLD_L2_SRGB_SEL, (val))
#define OVL_L2_PITCH_VAL_L2_SA_SEL(val)                        REG_FLD_VAL(OVL_L2_PITCH_FLD_L2_SA_SEL, (val))
#define OVL_L2_PITCH_VAL_L2_SRC_PITCH(val)                     REG_FLD_VAL(OVL_L2_PITCH_FLD_L2_SRC_PITCH, (val))

#define OVL_L2_TILE_VAL_TILE_HORI_BLOCK_NUM(val)               REG_FLD_VAL(OVL_L2_TILE_FLD_TILE_HORI_BLOCK_NUM, (val))
#define OVL_L2_TILE_VAL_TILE_EN(val)                           REG_FLD_VAL(OVL_L2_TILE_FLD_TILE_EN, (val))
#define OVL_L2_TILE_VAL_TILE_WIDTH_SEL(val)                    REG_FLD_VAL(OVL_L2_TILE_FLD_TILE_WIDTH_SEL, (val))
#define OVL_L2_TILE_VAL_TILE_HEIGHT(val)                       REG_FLD_VAL(OVL_L2_TILE_FLD_TILE_HEIGHT, (val))

#define OVL_L2_CLIP_VAL_L2_SRC_BOTTOM_CLIP(val)                REG_FLD_VAL(OVL_L2_CLIP_FLD_L2_SRC_BOTTOM_CLIP, (val))
#define OVL_L2_CLIP_VAL_L2_SRC_TOP_CLIP(val)                   REG_FLD_VAL(OVL_L2_CLIP_FLD_L2_SRC_TOP_CLIP, (val))
#define OVL_L2_CLIP_VAL_L2_SRC_RIGHT_CLIP(val)                 REG_FLD_VAL(OVL_L2_CLIP_FLD_L2_SRC_RIGHT_CLIP, (val))
#define OVL_L2_CLIP_VAL_L2_SRC_LEFT_CLIP(val)                  REG_FLD_VAL(OVL_L2_CLIP_FLD_L2_SRC_LEFT_CLIP, (val))

#define OVL_L3_CON_VAL_DSTKEY_EN(val)                          REG_FLD_VAL(OVL_L3_CON_FLD_DSTKEY_EN, (val))
#define OVL_L3_CON_VAL_SRCKEY_EN(val)                          REG_FLD_VAL(OVL_L3_CON_FLD_SRCKEY_EN, (val))
#define OVL_L3_CON_VAL_LAYER_SRC(val)                          REG_FLD_VAL(OVL_L3_CON_FLD_LAYER_SRC, (val))
#define OVL_L3_CON_VAL_MTX_EN(val)                             REG_FLD_VAL(OVL_L3_CON_FLD_MTX_EN, (val))
#define OVL_L3_CON_VAL_MTX_AUTO_DIS(val)                       REG_FLD_VAL(OVL_L3_CON_FLD_MTX_AUTO_DIS, (val))
#define OVL_L3_CON_VAL_RGB_SWAP(val)                           REG_FLD_VAL(OVL_L3_CON_FLD_RGB_SWAP, (val))
#define OVL_L3_CON_VAL_BYTE_SWAP(val)                          REG_FLD_VAL(OVL_L3_CON_FLD_BYTE_SWAP, (val))
#define OVL_L3_CON_VAL_CLRFMT_MAN(val)                         REG_FLD_VAL(OVL_L3_CON_FLD_CLRFMT_MAN, (val))
#define OVL_L3_CON_VAL_R_FIRST(val)                            REG_FLD_VAL(OVL_L3_CON_FLD_R_FIRST, (val))
#define OVL_L3_CON_VAL_LANDSCAPE(val)                          REG_FLD_VAL(OVL_L3_CON_FLD_LANDSCAPE, (val))
#define OVL_L3_CON_VAL_EN_3D(val)                              REG_FLD_VAL(OVL_L3_CON_FLD_EN_3D, (val))
#define OVL_L3_CON_VAL_INT_MTX_SEL(val)                        REG_FLD_VAL(OVL_L3_CON_FLD_INT_MTX_SEL, (val))
#define OVL_L3_CON_VAL_CLRFMT(val)                             REG_FLD_VAL(OVL_L3_CON_FLD_CLRFMT, (val))
#define OVL_L3_CON_VAL_EXT_MTX_EN(val)                         REG_FLD_VAL(OVL_L3_CON_FLD_EXT_MTX_EN, (val))
#define OVL_L3_CON_VAL_HORIZONTAL_FLIP_EN(val)                 REG_FLD_VAL(OVL_L3_CON_FLD_HORIZONTAL_FLIP_EN, (val))
#define OVL_L3_CON_VAL_VERTICAL_FLIP_EN(val)                   REG_FLD_VAL(OVL_L3_CON_FLD_VERTICAL_FLIP_EN, (val))
#define OVL_L3_CON_VAL_ALPHA_EN(val)                           REG_FLD_VAL(OVL_L3_CON_FLD_ALPHA_EN, (val))
#define OVL_L3_CON_VAL_ALPHA(val)                              REG_FLD_VAL(OVL_L3_CON_FLD_ALPHA, (val))

#define OVL_L3_SRCKEY_VAL_SRCKEY(val)                          REG_FLD_VAL(OVL_L3_SRCKEY_FLD_SRCKEY, (val))

#define OVL_L3_SRC_SIZE_VAL_L3_SRC_H(val)                      REG_FLD_VAL(OVL_L3_SRC_SIZE_FLD_L3_SRC_H, (val))
#define OVL_L3_SRC_SIZE_VAL_L3_SRC_W(val)                      REG_FLD_VAL(OVL_L3_SRC_SIZE_FLD_L3_SRC_W, (val))

#define OVL_L3_OFFSET_VAL_L3_YOFF(val)                         REG_FLD_VAL(OVL_L3_OFFSET_FLD_L3_YOFF, (val))
#define OVL_L3_OFFSET_VAL_L3_XOFF(val)                         REG_FLD_VAL(OVL_L3_OFFSET_FLD_L3_XOFF, (val))

#define OVL_L3_PITCH_VAL_SURFL_EN(val)                         REG_FLD_VAL(OVL_L3_PITCH_FLD_SURFL_EN, (val))
#define OVL_L3_PITCH_VAL_L3_BLEND_RND_SHT(val)                 REG_FLD_VAL(OVL_L3_PITCH_FLD_L3_BLEND_RND_SHT, (val))
#define OVL_L3_PITCH_VAL_L3_SRGB_SEL_EXT2(val)                 REG_FLD_VAL(OVL_L3_PITCH_FLD_L3_SRGB_SEL_EXT2, (val))
#define OVL_L3_PITCH_VAL_L3_CONST_BLD(val)                     REG_FLD_VAL(OVL_L3_PITCH_FLD_L3_CONST_BLD, (val))
#define OVL_L3_PITCH_VAL_L3_DRGB_SEL_EXT(val)                  REG_FLD_VAL(OVL_L3_PITCH_FLD_L3_DRGB_SEL_EXT, (val))
#define OVL_L3_PITCH_VAL_L3_DA_SEL_EXT(val)                    REG_FLD_VAL(OVL_L3_PITCH_FLD_L3_DA_SEL_EXT, (val))
#define OVL_L3_PITCH_VAL_L3_SRGB_SEL_EXT(val)                  REG_FLD_VAL(OVL_L3_PITCH_FLD_L3_SRGB_SEL_EXT, (val))
#define OVL_L3_PITCH_VAL_L3_SA_SEL_EXT(val)                    REG_FLD_VAL(OVL_L3_PITCH_FLD_L3_SA_SEL_EXT, (val))
#define OVL_L3_PITCH_VAL_L3_DRGB_SEL(val)                      REG_FLD_VAL(OVL_L3_PITCH_FLD_L3_DRGB_SEL, (val))
#define OVL_L3_PITCH_VAL_L3_DA_SEL(val)                        REG_FLD_VAL(OVL_L3_PITCH_FLD_L3_DA_SEL, (val))
#define OVL_L3_PITCH_VAL_L3_SRGB_SEL(val)                      REG_FLD_VAL(OVL_L3_PITCH_FLD_L3_SRGB_SEL, (val))
#define OVL_L3_PITCH_VAL_L3_SA_SEL(val)                        REG_FLD_VAL(OVL_L3_PITCH_FLD_L3_SA_SEL, (val))
#define OVL_L3_PITCH_VAL_L3_SRC_PITCH(val)                     REG_FLD_VAL(OVL_L3_PITCH_FLD_L3_SRC_PITCH, (val))

#define OVL_L3_TILE_VAL_TILE_HORI_BLOCK_NUM(val)               REG_FLD_VAL(OVL_L3_TILE_FLD_TILE_HORI_BLOCK_NUM, (val))
#define OVL_L3_TILE_VAL_TILE_EN(val)                           REG_FLD_VAL(OVL_L3_TILE_FLD_TILE_EN, (val))
#define OVL_L3_TILE_VAL_TILE_WIDTH_SEL(val)                    REG_FLD_VAL(OVL_L3_TILE_FLD_TILE_WIDTH_SEL, (val))
#define OVL_L3_TILE_VAL_TILE_HEIGHT(val)                       REG_FLD_VAL(OVL_L3_TILE_FLD_TILE_HEIGHT, (val))

#define OVL_L3_CLIP_VAL_L3_SRC_BOTTOM_CLIP(val)                REG_FLD_VAL(OVL_L3_CLIP_FLD_L3_SRC_BOTTOM_CLIP, (val))
#define OVL_L3_CLIP_VAL_L3_SRC_TOP_CLIP(val)                   REG_FLD_VAL(OVL_L3_CLIP_FLD_L3_SRC_TOP_CLIP, (val))
#define OVL_L3_CLIP_VAL_L3_SRC_RIGHT_CLIP(val)                 REG_FLD_VAL(OVL_L3_CLIP_FLD_L3_SRC_RIGHT_CLIP, (val))
#define OVL_L3_CLIP_VAL_L3_SRC_LEFT_CLIP(val)                  REG_FLD_VAL(OVL_L3_CLIP_FLD_L3_SRC_LEFT_CLIP, (val))

#define OVL_RDMA0_CTRL_VAL_RDMA0_FIFO_USED_SIZE(val)           REG_FLD_VAL(OVL_RDMA0_CTRL_FLD_RDMA0_FIFO_USED_SIZE, (val))
#define OVL_RDMA0_CTRL_VAL_RDMA0_INTERLACE(val)                REG_FLD_VAL(OVL_RDMA0_CTRL_FLD_RDMA0_INTERLACE, (val))
#define OVL_RDMA0_CTRL_VAL_RDMA0_EN(val)                       REG_FLD_VAL(OVL_RDMA0_CTRL_FLD_RDMA0_EN, (val))

#define OVL_RDMA0_MEM_GMC_SETTING1_VAL_RDMA0_PRE_ULTRA_THRESHOLD_HIGH_OFS(val) REG_FLD_VAL(OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_PRE_ULTRA_THRESHOLD_HIGH_OFS, (val))
#define OVL_RDMA0_MEM_GMC_SETTING1_VAL_RDMA0_ULTRA_THRESHOLD_HIGH_OFS(val) REG_FLD_VAL(OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_ULTRA_THRESHOLD_HIGH_OFS, (val))
#define OVL_RDMA0_MEM_GMC_SETTING1_VAL_RDMA0_OSTD_PREULTRA_TH(val) REG_FLD_VAL(OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_OSTD_PREULTRA_TH, (val))
#define OVL_RDMA0_MEM_GMC_SETTING1_VAL_RDMA0_OSTD_ULTRA_TH(val) REG_FLD_VAL(OVL_RDMA0_MEM_GMC_SETTING1_FLD_RDMA0_OSTD_ULTRA_TH, (val))

#define OVL_RDMA0_MEM_SLOW_CON_VAL_RDMA0_SLOW_CNT(val)         REG_FLD_VAL(OVL_RDMA0_MEM_SLOW_CON_FLD_RDMA0_SLOW_CNT, (val))
#define OVL_RDMA0_MEM_SLOW_CON_VAL_RDMA0_SLOW_EN(val)          REG_FLD_VAL(OVL_RDMA0_MEM_SLOW_CON_FLD_RDMA0_SLOW_EN, (val))

#define OVL_RDMA0_FIFO_CTRL_VAL_RDMA0_FIFO_UND_EN(val)         REG_FLD_VAL(OVL_RDMA0_FIFO_CTRL_FLD_RDMA0_FIFO_UND_EN, (val))
#define OVL_RDMA0_FIFO_CTRL_VAL_RDMA0_FIFO_SIZE(val)           REG_FLD_VAL(OVL_RDMA0_FIFO_CTRL_FLD_RDMA0_FIFO_SIZE, (val))
#define OVL_RDMA0_FIFO_CTRL_VAL_RDMA0_FIFO_THRD(val)           REG_FLD_VAL(OVL_RDMA0_FIFO_CTRL_FLD_RDMA0_FIFO_THRD, (val))

#define OVL_RDMA1_CTRL_VAL_RDMA1_FIFO_USED_SIZE(val)           REG_FLD_VAL(OVL_RDMA1_CTRL_FLD_RDMA1_FIFO_USED_SIZE, (val))
#define OVL_RDMA1_CTRL_VAL_RDMA1_INTERLACE(val)                REG_FLD_VAL(OVL_RDMA1_CTRL_FLD_RDMA1_INTERLACE, (val))
#define OVL_RDMA1_CTRL_VAL_RDMA1_EN(val)                       REG_FLD_VAL(OVL_RDMA1_CTRL_FLD_RDMA1_EN, (val))

#define OVL_RDMA1_MEM_GMC_SETTING1_VAL_RDMA1_PRE_ULTRA_THRESHOLD_HIGH_OFS(val) REG_FLD_VAL(OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_PRE_ULTRA_THRESHOLD_HIGH_OFS, (val))
#define OVL_RDMA1_MEM_GMC_SETTING1_VAL_RDMA1_ULTRA_THRESHOLD_HIGH_OFS(val) REG_FLD_VAL(OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_ULTRA_THRESHOLD_HIGH_OFS, (val))
#define OVL_RDMA1_MEM_GMC_SETTING1_VAL_RDMA1_OSTD_PREULTRA_TH(val) REG_FLD_VAL(OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_OSTD_PREULTRA_TH, (val))
#define OVL_RDMA1_MEM_GMC_SETTING1_VAL_RDMA1_OSTD_ULTRA_TH(val) REG_FLD_VAL(OVL_RDMA1_MEM_GMC_SETTING1_FLD_RDMA1_OSTD_ULTRA_TH, (val))

#define OVL_RDMA1_MEM_SLOW_CON_VAL_RDMA1_SLOW_CNT(val)         REG_FLD_VAL(OVL_RDMA1_MEM_SLOW_CON_FLD_RDMA1_SLOW_CNT, (val))
#define OVL_RDMA1_MEM_SLOW_CON_VAL_RDMA1_SLOW_EN(val)          REG_FLD_VAL(OVL_RDMA1_MEM_SLOW_CON_FLD_RDMA1_SLOW_EN, (val))

#define OVL_RDMA1_FIFO_CTRL_VAL_RDMA1_FIFO_UND_EN(val)         REG_FLD_VAL(OVL_RDMA1_FIFO_CTRL_FLD_RDMA1_FIFO_UND_EN, (val))
#define OVL_RDMA1_FIFO_CTRL_VAL_RDMA1_FIFO_SIZE(val)           REG_FLD_VAL(OVL_RDMA1_FIFO_CTRL_FLD_RDMA1_FIFO_SIZE, (val))
#define OVL_RDMA1_FIFO_CTRL_VAL_RDMA1_FIFO_THRD(val)           REG_FLD_VAL(OVL_RDMA1_FIFO_CTRL_FLD_RDMA1_FIFO_THRD, (val))

#define OVL_RDMA2_CTRL_VAL_RDMA2_FIFO_USED_SIZE(val)           REG_FLD_VAL(OVL_RDMA2_CTRL_FLD_RDMA2_FIFO_USED_SIZE, (val))
#define OVL_RDMA2_CTRL_VAL_RDMA2_INTERLACE(val)                REG_FLD_VAL(OVL_RDMA2_CTRL_FLD_RDMA2_INTERLACE, (val))
#define OVL_RDMA2_CTRL_VAL_RDMA2_EN(val)                       REG_FLD_VAL(OVL_RDMA2_CTRL_FLD_RDMA2_EN, (val))

#define OVL_RDMA2_MEM_GMC_SETTING1_VAL_RDMA2_PRE_ULTRA_THRESHOLD_HIGH_OFS(val) REG_FLD_VAL(OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_PRE_ULTRA_THRESHOLD_HIGH_OFS, (val))
#define OVL_RDMA2_MEM_GMC_SETTING1_VAL_RDMA2_ULTRA_THRESHOLD_HIGH_OFS(val) REG_FLD_VAL(OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_ULTRA_THRESHOLD_HIGH_OFS, (val))
#define OVL_RDMA2_MEM_GMC_SETTING1_VAL_RDMA2_OSTD_PREULTRA_TH(val) REG_FLD_VAL(OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_OSTD_PREULTRA_TH, (val))
#define OVL_RDMA2_MEM_GMC_SETTING1_VAL_RDMA2_OSTD_ULTRA_TH(val) REG_FLD_VAL(OVL_RDMA2_MEM_GMC_SETTING1_FLD_RDMA2_OSTD_ULTRA_TH, (val))

#define OVL_RDMA2_MEM_SLOW_CON_VAL_RDMA2_SLOW_CNT(val)         REG_FLD_VAL(OVL_RDMA2_MEM_SLOW_CON_FLD_RDMA2_SLOW_CNT, (val))
#define OVL_RDMA2_MEM_SLOW_CON_VAL_RDMA2_SLOW_EN(val)          REG_FLD_VAL(OVL_RDMA2_MEM_SLOW_CON_FLD_RDMA2_SLOW_EN, (val))

#define OVL_RDMA2_FIFO_CTRL_VAL_RDMA2_FIFO_UND_EN(val)         REG_FLD_VAL(OVL_RDMA2_FIFO_CTRL_FLD_RDMA2_FIFO_UND_EN, (val))
#define OVL_RDMA2_FIFO_CTRL_VAL_RDMA2_FIFO_SIZE(val)           REG_FLD_VAL(OVL_RDMA2_FIFO_CTRL_FLD_RDMA2_FIFO_SIZE, (val))
#define OVL_RDMA2_FIFO_CTRL_VAL_RDMA2_FIFO_THRD(val)           REG_FLD_VAL(OVL_RDMA2_FIFO_CTRL_FLD_RDMA2_FIFO_THRD, (val))

#define OVL_RDMA3_CTRL_VAL_RDMA3_FIFO_USED_SIZE(val)           REG_FLD_VAL(OVL_RDMA3_CTRL_FLD_RDMA3_FIFO_USED_SIZE, (val))
#define OVL_RDMA3_CTRL_VAL_RDMA3_INTERLACE(val)                REG_FLD_VAL(OVL_RDMA3_CTRL_FLD_RDMA3_INTERLACE, (val))
#define OVL_RDMA3_CTRL_VAL_RDMA3_EN(val)                       REG_FLD_VAL(OVL_RDMA3_CTRL_FLD_RDMA3_EN, (val))

#define OVL_RDMA3_MEM_GMC_SETTING1_VAL_RDMA3_PRE_ULTRA_THRESHOLD_HIGH_OFS(val) REG_FLD_VAL(OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_PRE_ULTRA_THRESHOLD_HIGH_OFS, (val))
#define OVL_RDMA3_MEM_GMC_SETTING1_VAL_RDMA3_ULTRA_THRESHOLD_HIGH_OFS(val) REG_FLD_VAL(OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_ULTRA_THRESHOLD_HIGH_OFS, (val))
#define OVL_RDMA3_MEM_GMC_SETTING1_VAL_RDMA3_OSTD_PREULTRA_TH(val) REG_FLD_VAL(OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_OSTD_PREULTRA_TH, (val))
#define OVL_RDMA3_MEM_GMC_SETTING1_VAL_RDMA3_OSTD_ULTRA_TH(val) REG_FLD_VAL(OVL_RDMA3_MEM_GMC_SETTING1_FLD_RDMA3_OSTD_ULTRA_TH, (val))

#define OVL_RDMA3_MEM_SLOW_CON_VAL_RDMA3_SLOW_CNT(val)         REG_FLD_VAL(OVL_RDMA3_MEM_SLOW_CON_FLD_RDMA3_SLOW_CNT, (val))
#define OVL_RDMA3_MEM_SLOW_CON_VAL_RDMA3_SLOW_EN(val)          REG_FLD_VAL(OVL_RDMA3_MEM_SLOW_CON_FLD_RDMA3_SLOW_EN, (val))

#define OVL_RDMA3_FIFO_CTRL_VAL_RDMA3_FIFO_UND_EN(val)         REG_FLD_VAL(OVL_RDMA3_FIFO_CTRL_FLD_RDMA3_FIFO_UND_EN, (val))
#define OVL_RDMA3_FIFO_CTRL_VAL_RDMA3_FIFO_SIZE(val)           REG_FLD_VAL(OVL_RDMA3_FIFO_CTRL_FLD_RDMA3_FIFO_SIZE, (val))
#define OVL_RDMA3_FIFO_CTRL_VAL_RDMA3_FIFO_THRD(val)           REG_FLD_VAL(OVL_RDMA3_FIFO_CTRL_FLD_RDMA3_FIFO_THRD, (val))

#define OVL_L0_Y2R_PARA_R0_VAL_C_CF_RMU(val)                   REG_FLD_VAL(OVL_L0_Y2R_PARA_R0_FLD_C_CF_RMU, (val))
#define OVL_L0_Y2R_PARA_R0_VAL_C_CF_RMY(val)                   REG_FLD_VAL(OVL_L0_Y2R_PARA_R0_FLD_C_CF_RMY, (val))

#define OVL_L0_Y2R_PARA_R1_VAL_C_CF_RMV(val)                   REG_FLD_VAL(OVL_L0_Y2R_PARA_R1_FLD_C_CF_RMV, (val))

#define OVL_L0_Y2R_PARA_G0_VAL_C_CF_GMU(val)                   REG_FLD_VAL(OVL_L0_Y2R_PARA_G0_FLD_C_CF_GMU, (val))
#define OVL_L0_Y2R_PARA_G0_VAL_C_CF_GMY(val)                   REG_FLD_VAL(OVL_L0_Y2R_PARA_G0_FLD_C_CF_GMY, (val))

#define OVL_L0_Y2R_PARA_G1_VAL_C_CF_GMV(val)                   REG_FLD_VAL(OVL_L0_Y2R_PARA_G1_FLD_C_CF_GMV, (val))

#define OVL_L0_Y2R_PARA_B0_VAL_C_CF_BMU(val)                   REG_FLD_VAL(OVL_L0_Y2R_PARA_B0_FLD_C_CF_BMU, (val))
#define OVL_L0_Y2R_PARA_B0_VAL_C_CF_BMY(val)                   REG_FLD_VAL(OVL_L0_Y2R_PARA_B0_FLD_C_CF_BMY, (val))

#define OVL_L0_Y2R_PARA_B1_VAL_C_CF_BMV(val)                   REG_FLD_VAL(OVL_L0_Y2R_PARA_B1_FLD_C_CF_BMV, (val))

#define OVL_L0_Y2R_PARA_YUV_A_0_VAL_C_CF_UA(val)               REG_FLD_VAL(OVL_L0_Y2R_PARA_YUV_A_0_FLD_C_CF_UA, (val))
#define OVL_L0_Y2R_PARA_YUV_A_0_VAL_C_CF_YA(val)               REG_FLD_VAL(OVL_L0_Y2R_PARA_YUV_A_0_FLD_C_CF_YA, (val))

#define OVL_L0_Y2R_PARA_YUV_A_1_VAL_C_CF_VA(val)               REG_FLD_VAL(OVL_L0_Y2R_PARA_YUV_A_1_FLD_C_CF_VA, (val))

#define OVL_L0_Y2R_PARA_RGB_A_0_VAL_C_CF_GA(val)               REG_FLD_VAL(OVL_L0_Y2R_PARA_RGB_A_0_FLD_C_CF_GA, (val))
#define OVL_L0_Y2R_PARA_RGB_A_0_VAL_C_CF_RA(val)               REG_FLD_VAL(OVL_L0_Y2R_PARA_RGB_A_0_FLD_C_CF_RA, (val))

#define OVL_L0_Y2R_PARA_RGB_A_1_VAL_C_CF_BA(val)               REG_FLD_VAL(OVL_L0_Y2R_PARA_RGB_A_1_FLD_C_CF_BA, (val))

#define OVL_L1_Y2R_PARA_R0_VAL_C_CF_RMU(val)                   REG_FLD_VAL(OVL_L1_Y2R_PARA_R0_FLD_C_CF_RMU, (val))
#define OVL_L1_Y2R_PARA_R0_VAL_C_CF_RMY(val)                   REG_FLD_VAL(OVL_L1_Y2R_PARA_R0_FLD_C_CF_RMY, (val))

#define OVL_L1_Y2R_PARA_R1_VAL_C_CF_RMV(val)                   REG_FLD_VAL(OVL_L1_Y2R_PARA_R1_FLD_C_CF_RMV, (val))

#define OVL_L1_Y2R_PARA_G0_VAL_C_CF_GMU(val)                   REG_FLD_VAL(OVL_L1_Y2R_PARA_G0_FLD_C_CF_GMU, (val))
#define OVL_L1_Y2R_PARA_G0_VAL_C_CF_GMY(val)                   REG_FLD_VAL(OVL_L1_Y2R_PARA_G0_FLD_C_CF_GMY, (val))

#define OVL_L1_Y2R_PARA_G1_VAL_C_CF_GMV(val)                   REG_FLD_VAL(OVL_L1_Y2R_PARA_G1_FLD_C_CF_GMV, (val))

#define OVL_L1_Y2R_PARA_B0_VAL_C_CF_BMU(val)                   REG_FLD_VAL(OVL_L1_Y2R_PARA_B0_FLD_C_CF_BMU, (val))
#define OVL_L1_Y2R_PARA_B0_VAL_C_CF_BMY(val)                   REG_FLD_VAL(OVL_L1_Y2R_PARA_B0_FLD_C_CF_BMY, (val))

#define OVL_L1_Y2R_PARA_B1_VAL_C_CF_BMV(val)                   REG_FLD_VAL(OVL_L1_Y2R_PARA_B1_FLD_C_CF_BMV, (val))

#define OVL_L1_Y2R_PARA_YUV_A_0_VAL_C_CF_UA(val)               REG_FLD_VAL(OVL_L1_Y2R_PARA_YUV_A_0_FLD_C_CF_UA, (val))
#define OVL_L1_Y2R_PARA_YUV_A_0_VAL_C_CF_YA(val)               REG_FLD_VAL(OVL_L1_Y2R_PARA_YUV_A_0_FLD_C_CF_YA, (val))

#define OVL_L1_Y2R_PARA_YUV_A_1_VAL_C_CF_VA(val)               REG_FLD_VAL(OVL_L1_Y2R_PARA_YUV_A_1_FLD_C_CF_VA, (val))

#define OVL_L1_Y2R_PARA_RGB_A_0_VAL_C_CF_GA(val)               REG_FLD_VAL(OVL_L1_Y2R_PARA_RGB_A_0_FLD_C_CF_GA, (val))
#define OVL_L1_Y2R_PARA_RGB_A_0_VAL_C_CF_RA(val)               REG_FLD_VAL(OVL_L1_Y2R_PARA_RGB_A_0_FLD_C_CF_RA, (val))

#define OVL_L1_Y2R_PARA_RGB_A_1_VAL_C_CF_BA(val)               REG_FLD_VAL(OVL_L1_Y2R_PARA_RGB_A_1_FLD_C_CF_BA, (val))

#define OVL_L2_Y2R_PARA_R0_VAL_C_CF_RMU(val)                   REG_FLD_VAL(OVL_L2_Y2R_PARA_R0_FLD_C_CF_RMU, (val))
#define OVL_L2_Y2R_PARA_R0_VAL_C_CF_RMY(val)                   REG_FLD_VAL(OVL_L2_Y2R_PARA_R0_FLD_C_CF_RMY, (val))

#define OVL_L2_Y2R_PARA_R1_VAL_C_CF_RMV(val)                   REG_FLD_VAL(OVL_L2_Y2R_PARA_R1_FLD_C_CF_RMV, (val))

#define OVL_L2_Y2R_PARA_G0_VAL_C_CF_GMU(val)                   REG_FLD_VAL(OVL_L2_Y2R_PARA_G0_FLD_C_CF_GMU, (val))
#define OVL_L2_Y2R_PARA_G0_VAL_C_CF_GMY(val)                   REG_FLD_VAL(OVL_L2_Y2R_PARA_G0_FLD_C_CF_GMY, (val))

#define OVL_L2_Y2R_PARA_G1_VAL_C_CF_GMV(val)                   REG_FLD_VAL(OVL_L2_Y2R_PARA_G1_FLD_C_CF_GMV, (val))

#define OVL_L2_Y2R_PARA_B0_VAL_C_CF_BMU(val)                   REG_FLD_VAL(OVL_L2_Y2R_PARA_B0_FLD_C_CF_BMU, (val))
#define OVL_L2_Y2R_PARA_B0_VAL_C_CF_BMY(val)                   REG_FLD_VAL(OVL_L2_Y2R_PARA_B0_FLD_C_CF_BMY, (val))

#define OVL_L2_Y2R_PARA_B1_VAL_C_CF_BMV(val)                   REG_FLD_VAL(OVL_L2_Y2R_PARA_B1_FLD_C_CF_BMV, (val))

#define OVL_L2_Y2R_PARA_YUV_A_0_VAL_C_CF_UA(val)               REG_FLD_VAL(OVL_L2_Y2R_PARA_YUV_A_0_FLD_C_CF_UA, (val))
#define OVL_L2_Y2R_PARA_YUV_A_0_VAL_C_CF_YA(val)               REG_FLD_VAL(OVL_L2_Y2R_PARA_YUV_A_0_FLD_C_CF_YA, (val))

#define OVL_L2_Y2R_PARA_YUV_A_1_VAL_C_CF_VA(val)               REG_FLD_VAL(OVL_L2_Y2R_PARA_YUV_A_1_FLD_C_CF_VA, (val))

#define OVL_L2_Y2R_PARA_RGB_A_0_VAL_C_CF_GA(val)               REG_FLD_VAL(OVL_L2_Y2R_PARA_RGB_A_0_FLD_C_CF_GA, (val))
#define OVL_L2_Y2R_PARA_RGB_A_0_VAL_C_CF_RA(val)               REG_FLD_VAL(OVL_L2_Y2R_PARA_RGB_A_0_FLD_C_CF_RA, (val))

#define OVL_L2_Y2R_PARA_RGB_A_1_VAL_C_CF_BA(val)               REG_FLD_VAL(OVL_L2_Y2R_PARA_RGB_A_1_FLD_C_CF_BA, (val))

#define OVL_L3_Y2R_PARA_R0_VAL_C_CF_RMU(val)                   REG_FLD_VAL(OVL_L3_Y2R_PARA_R0_FLD_C_CF_RMU, (val))
#define OVL_L3_Y2R_PARA_R0_VAL_C_CF_RMY(val)                   REG_FLD_VAL(OVL_L3_Y2R_PARA_R0_FLD_C_CF_RMY, (val))

#define OVL_L3_Y2R_PARA_R1_VAL_C_CF_RMV(val)                   REG_FLD_VAL(OVL_L3_Y2R_PARA_R1_FLD_C_CF_RMV, (val))

#define OVL_L3_Y2R_PARA_G0_VAL_C_CF_GMU(val)                   REG_FLD_VAL(OVL_L3_Y2R_PARA_G0_FLD_C_CF_GMU, (val))
#define OVL_L3_Y2R_PARA_G0_VAL_C_CF_GMY(val)                   REG_FLD_VAL(OVL_L3_Y2R_PARA_G0_FLD_C_CF_GMY, (val))

#define OVL_L3_Y2R_PARA_G1_VAL_C_CF_GMV(val)                   REG_FLD_VAL(OVL_L3_Y2R_PARA_G1_FLD_C_CF_GMV, (val))

#define OVL_L3_Y2R_PARA_B0_VAL_C_CF_BMU(val)                   REG_FLD_VAL(OVL_L3_Y2R_PARA_B0_FLD_C_CF_BMU, (val))
#define OVL_L3_Y2R_PARA_B0_VAL_C_CF_BMY(val)                   REG_FLD_VAL(OVL_L3_Y2R_PARA_B0_FLD_C_CF_BMY, (val))

#define OVL_L3_Y2R_PARA_B1_VAL_C_CF_BMV(val)                   REG_FLD_VAL(OVL_L3_Y2R_PARA_B1_FLD_C_CF_BMV, (val))

#define OVL_L3_Y2R_PARA_YUV_A_0_VAL_C_CF_UA(val)               REG_FLD_VAL(OVL_L3_Y2R_PARA_YUV_A_0_FLD_C_CF_UA, (val))
#define OVL_L3_Y2R_PARA_YUV_A_0_VAL_C_CF_YA(val)               REG_FLD_VAL(OVL_L3_Y2R_PARA_YUV_A_0_FLD_C_CF_YA, (val))

#define OVL_L3_Y2R_PARA_YUV_A_1_VAL_C_CF_VA(val)               REG_FLD_VAL(OVL_L3_Y2R_PARA_YUV_A_1_FLD_C_CF_VA, (val))

#define OVL_L3_Y2R_PARA_RGB_A_0_VAL_C_CF_GA(val)               REG_FLD_VAL(OVL_L3_Y2R_PARA_RGB_A_0_FLD_C_CF_GA, (val))
#define OVL_L3_Y2R_PARA_RGB_A_0_VAL_C_CF_RA(val)               REG_FLD_VAL(OVL_L3_Y2R_PARA_RGB_A_0_FLD_C_CF_RA, (val))

#define OVL_L3_Y2R_PARA_RGB_A_1_VAL_C_CF_BA(val)               REG_FLD_VAL(OVL_L3_Y2R_PARA_RGB_A_1_FLD_C_CF_BA, (val))

#define OVL_DEBUG_MON_SEL_VAL_DBG_MON_SEL(val)                 REG_FLD_VAL(OVL_DEBUG_MON_SEL_FLD_DBG_MON_SEL, (val))

#define OVL_BLD_EXT_VAL_EL2_MINUS_BLD(val)                     REG_FLD_VAL(OVL_BLD_EXT_FLD_EL2_MINUS_BLD, (val))
#define OVL_BLD_EXT_VAL_EL1_MINUS_BLD(val)                     REG_FLD_VAL(OVL_BLD_EXT_FLD_EL1_MINUS_BLD, (val))
#define OVL_BLD_EXT_VAL_EL0_MINUS_BLD(val)                     REG_FLD_VAL(OVL_BLD_EXT_FLD_EL0_MINUS_BLD, (val))
#define OVL_BLD_EXT_VAL_LC_MINUS_BLD(val)                      REG_FLD_VAL(OVL_BLD_EXT_FLD_LC_MINUS_BLD, (val))
#define OVL_BLD_EXT_VAL_L3_MINUS_BLD(val)                      REG_FLD_VAL(OVL_BLD_EXT_FLD_L3_MINUS_BLD, (val))
#define OVL_BLD_EXT_VAL_L2_MINUS_BLD(val)                      REG_FLD_VAL(OVL_BLD_EXT_FLD_L2_MINUS_BLD, (val))
#define OVL_BLD_EXT_VAL_L1_MINUS_BLD(val)                      REG_FLD_VAL(OVL_BLD_EXT_FLD_L1_MINUS_BLD, (val))
#define OVL_BLD_EXT_VAL_L0_MINUS_BLD(val)                      REG_FLD_VAL(OVL_BLD_EXT_FLD_L0_MINUS_BLD, (val))

#define OVL_RDMA0_MEM_GMC_SETTING2_VAL_RDMA0_FORCE_REQ_THRESHOLD(val) REG_FLD_VAL(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_FORCE_REQ_THRESHOLD, (val))
#define OVL_RDMA0_MEM_GMC_SETTING2_VAL_RDMA0_REQ_THRESHOLD_ULTRA(val) REG_FLD_VAL(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_REQ_THRESHOLD_ULTRA, (val))
#define OVL_RDMA0_MEM_GMC_SETTING2_VAL_RDMA0_REQ_THRESHOLD_PREULTRA(val) REG_FLD_VAL(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_REQ_THRESHOLD_PREULTRA, (val))
#define OVL_RDMA0_MEM_GMC_SETTING2_VAL_RDMA0_ISSUE_REQ_THRESHOLD_URG(val) REG_FLD_VAL(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_ISSUE_REQ_THRESHOLD_URG, (val))
#define OVL_RDMA0_MEM_GMC_SETTING2_VAL_RDMA0_ISSUE_REQ_THRESHOLD(val) REG_FLD_VAL(OVL_RDMA0_MEM_GMC_SETTING2_FLD_RDMA0_ISSUE_REQ_THRESHOLD, (val))

#define OVL_RDMA1_MEM_GMC_SETTING2_VAL_RDMA1_FORCE_REQ_THRESHOLD(val) REG_FLD_VAL(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_FORCE_REQ_THRESHOLD, (val))
#define OVL_RDMA1_MEM_GMC_SETTING2_VAL_RDMA1_REQ_THRESHOLD_ULTRA(val) REG_FLD_VAL(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_REQ_THRESHOLD_ULTRA, (val))
#define OVL_RDMA1_MEM_GMC_SETTING2_VAL_RDMA1_REQ_THRESHOLD_PREULTRA(val) REG_FLD_VAL(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_REQ_THRESHOLD_PREULTRA, (val))
#define OVL_RDMA1_MEM_GMC_SETTING2_VAL_RDMA1_ISSUE_REQ_THRESHOLD_URG(val) REG_FLD_VAL(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_ISSUE_REQ_THRESHOLD_URG, (val))
#define OVL_RDMA1_MEM_GMC_SETTING2_VAL_RDMA1_ISSUE_REQ_THRESHOLD(val) REG_FLD_VAL(OVL_RDMA1_MEM_GMC_SETTING2_FLD_RDMA1_ISSUE_REQ_THRESHOLD, (val))

#define OVL_RDMA2_MEM_GMC_SETTING2_VAL_RDMA2_FORCE_REQ_THRESHOLD(val) REG_FLD_VAL(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_FORCE_REQ_THRESHOLD, (val))
#define OVL_RDMA2_MEM_GMC_SETTING2_VAL_RDMA2_REQ_THRESHOLD_ULTRA(val) REG_FLD_VAL(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_REQ_THRESHOLD_ULTRA, (val))
#define OVL_RDMA2_MEM_GMC_SETTING2_VAL_RDMA2_REQ_THRESHOLD_PREULTRA(val) REG_FLD_VAL(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_REQ_THRESHOLD_PREULTRA, (val))
#define OVL_RDMA2_MEM_GMC_SETTING2_VAL_RDMA2_ISSUE_REQ_THRESHOLD_URG(val) REG_FLD_VAL(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_ISSUE_REQ_THRESHOLD_URG, (val))
#define OVL_RDMA2_MEM_GMC_SETTING2_VAL_RDMA2_ISSUE_REQ_THRESHOLD(val) REG_FLD_VAL(OVL_RDMA2_MEM_GMC_SETTING2_FLD_RDMA2_ISSUE_REQ_THRESHOLD, (val))

#define OVL_RDMA3_MEM_GMC_SETTING2_VAL_RDMA3_FORCE_REQ_THRESHOLD(val) REG_FLD_VAL(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_FORCE_REQ_THRESHOLD, (val))
#define OVL_RDMA3_MEM_GMC_SETTING2_VAL_RDMA3_REQ_THRESHOLD_ULTRA(val) REG_FLD_VAL(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_REQ_THRESHOLD_ULTRA, (val))
#define OVL_RDMA3_MEM_GMC_SETTING2_VAL_RDMA3_REQ_THRESHOLD_PREULTRA(val) REG_FLD_VAL(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_REQ_THRESHOLD_PREULTRA, (val))
#define OVL_RDMA3_MEM_GMC_SETTING2_VAL_RDMA3_ISSUE_REQ_THRESHOLD_URG(val) REG_FLD_VAL(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_ISSUE_REQ_THRESHOLD_URG, (val))
#define OVL_RDMA3_MEM_GMC_SETTING2_VAL_RDMA3_ISSUE_REQ_THRESHOLD(val) REG_FLD_VAL(OVL_RDMA3_MEM_GMC_SETTING2_FLD_RDMA3_ISSUE_REQ_THRESHOLD, (val))

#define OVL_RDMA_BURST_CON0_VAL_BURST_128B_BOUND(val)          REG_FLD_VAL(OVL_RDMA_BURST_CON0_FLD_BURST_128B_BOUND, (val))
#define OVL_RDMA_BURST_CON0_VAL_BURST15A_32B(val)              REG_FLD_VAL(OVL_RDMA_BURST_CON0_FLD_BURST15A_32B, (val))
#define OVL_RDMA_BURST_CON0_VAL_BURST14A_32B(val)              REG_FLD_VAL(OVL_RDMA_BURST_CON0_FLD_BURST14A_32B, (val))
#define OVL_RDMA_BURST_CON0_VAL_BURST13A_32B(val)              REG_FLD_VAL(OVL_RDMA_BURST_CON0_FLD_BURST13A_32B, (val))
#define OVL_RDMA_BURST_CON0_VAL_BURST12A_32B(val)              REG_FLD_VAL(OVL_RDMA_BURST_CON0_FLD_BURST12A_32B, (val))
#define OVL_RDMA_BURST_CON0_VAL_BURST11A_32B(val)              REG_FLD_VAL(OVL_RDMA_BURST_CON0_FLD_BURST11A_32B, (val))
#define OVL_RDMA_BURST_CON0_VAL_BURST10A_32B(val)              REG_FLD_VAL(OVL_RDMA_BURST_CON0_FLD_BURST10A_32B, (val))
#define OVL_RDMA_BURST_CON0_VAL_BURST9A_32B(val)               REG_FLD_VAL(OVL_RDMA_BURST_CON0_FLD_BURST9A_32B, (val))

#define OVL_RDMA_BURST_CON1_VAL_BURST15A_N32B(val)             REG_FLD_VAL(OVL_RDMA_BURST_CON1_FLD_BURST15A_N32B, (val))
#define OVL_RDMA_BURST_CON1_VAL_BURST14A_N32B(val)             REG_FLD_VAL(OVL_RDMA_BURST_CON1_FLD_BURST14A_N32B, (val))
#define OVL_RDMA_BURST_CON1_VAL_BURST13A_N32B(val)             REG_FLD_VAL(OVL_RDMA_BURST_CON1_FLD_BURST13A_N32B, (val))
#define OVL_RDMA_BURST_CON1_VAL_BURST12A_N32B(val)             REG_FLD_VAL(OVL_RDMA_BURST_CON1_FLD_BURST12A_N32B, (val))
#define OVL_RDMA_BURST_CON1_VAL_BURST11A_N32B(val)             REG_FLD_VAL(OVL_RDMA_BURST_CON1_FLD_BURST11A_N32B, (val))
#define OVL_RDMA_BURST_CON1_VAL_BURST10A_N32B(val)             REG_FLD_VAL(OVL_RDMA_BURST_CON1_FLD_BURST10A_N32B, (val))
#define OVL_RDMA_BURST_CON1_VAL_BURST9A_N32B(val)              REG_FLD_VAL(OVL_RDMA_BURST_CON1_FLD_BURST9A_N32B, (val))

#define OVL_RDMA_GREQ_NUM_VAL_IOBUF_FLUSH_ULTRA(val)           REG_FLD_VAL(OVL_RDMA_GREQ_NUM_FLD_IOBUF_FLUSH_ULTRA, (val))
#define OVL_RDMA_GREQ_NUM_VAL_IOBUF_FLUSH_PREULTRA(val)        REG_FLD_VAL(OVL_RDMA_GREQ_NUM_FLD_IOBUF_FLUSH_PREULTRA, (val))
#define OVL_RDMA_GREQ_NUM_VAL_GRP_BRK_STOP(val)                REG_FLD_VAL(OVL_RDMA_GREQ_NUM_FLD_GRP_BRK_STOP, (val))
#define OVL_RDMA_GREQ_NUM_VAL_GRP_END_STOP(val)                REG_FLD_VAL(OVL_RDMA_GREQ_NUM_FLD_GRP_END_STOP, (val))
#define OVL_RDMA_GREQ_NUM_VAL_GREQ_STOP_EN(val)                REG_FLD_VAL(OVL_RDMA_GREQ_NUM_FLD_GREQ_STOP_EN, (val))
#define OVL_RDMA_GREQ_NUM_VAL_GREQ_DIS_CNT(val)                REG_FLD_VAL(OVL_RDMA_GREQ_NUM_FLD_GREQ_DIS_CNT, (val))
#define OVL_RDMA_GREQ_NUM_VAL_OSTD_GREQ_NUM(val)               REG_FLD_VAL(OVL_RDMA_GREQ_NUM_FLD_OSTD_GREQ_NUM, (val))
#define OVL_RDMA_GREQ_NUM_VAL_LAYER3_GREQ_NUM(val)             REG_FLD_VAL(OVL_RDMA_GREQ_NUM_FLD_LAYER3_GREQ_NUM, (val))
#define OVL_RDMA_GREQ_NUM_VAL_LAYER2_GREQ_NUM(val)             REG_FLD_VAL(OVL_RDMA_GREQ_NUM_FLD_LAYER2_GREQ_NUM, (val))
#define OVL_RDMA_GREQ_NUM_VAL_LAYER1_GREQ_NUM(val)             REG_FLD_VAL(OVL_RDMA_GREQ_NUM_FLD_LAYER1_GREQ_NUM, (val))
#define OVL_RDMA_GREQ_NUM_VAL_LAYER0_GREQ_NUM(val)             REG_FLD_VAL(OVL_RDMA_GREQ_NUM_FLD_LAYER0_GREQ_NUM, (val))

#define OVL_RDMA_GREQ_URG_NUM_VAL_GREQ_NUM_SHT(val)            REG_FLD_VAL(OVL_RDMA_GREQ_URG_NUM_FLD_GREQ_NUM_SHT, (val))
#define OVL_RDMA_GREQ_URG_NUM_VAL_GREQ_NUM_SHT_VAL(val)        REG_FLD_VAL(OVL_RDMA_GREQ_URG_NUM_FLD_GREQ_NUM_SHT_VAL, (val))
#define OVL_RDMA_GREQ_URG_NUM_VAL_ARG_URG_BIAS(val)            REG_FLD_VAL(OVL_RDMA_GREQ_URG_NUM_FLD_ARG_URG_BIAS, (val))
#define OVL_RDMA_GREQ_URG_NUM_VAL_ARG_GREQ_URG_TH(val)         REG_FLD_VAL(OVL_RDMA_GREQ_URG_NUM_FLD_ARG_GREQ_URG_TH, (val))
#define OVL_RDMA_GREQ_URG_NUM_VAL_LAYER3_GREQ_URG_NUM(val)     REG_FLD_VAL(OVL_RDMA_GREQ_URG_NUM_FLD_LAYER3_GREQ_URG_NUM, (val))
#define OVL_RDMA_GREQ_URG_NUM_VAL_LAYER2_GREQ_URG_NUM(val)     REG_FLD_VAL(OVL_RDMA_GREQ_URG_NUM_FLD_LAYER2_GREQ_URG_NUM, (val))
#define OVL_RDMA_GREQ_URG_NUM_VAL_LAYER1_GREQ_URG_NUM(val)     REG_FLD_VAL(OVL_RDMA_GREQ_URG_NUM_FLD_LAYER1_GREQ_URG_NUM, (val))
#define OVL_RDMA_GREQ_URG_NUM_VAL_LAYER0_GREQ_URG_NUM(val)     REG_FLD_VAL(OVL_RDMA_GREQ_URG_NUM_FLD_LAYER0_GREQ_URG_NUM, (val))

#define OVL_DUMMY_REG_VAL_OVERLAY_DUMMY(val)                   REG_FLD_VAL(OVL_DUMMY_REG_FLD_OVERLAY_DUMMY, (val))

#define OVL_GDRDY_PRD_VAL_GDRDY_PRD(val)                       REG_FLD_VAL(OVL_GDRDY_PRD_FLD_GDRDY_PRD, (val))

#define OVL_RDMA_ULTRA_SRC_VAL_ULTRA_RDMA_SRC(val)             REG_FLD_VAL(OVL_RDMA_ULTRA_SRC_FLD_ULTRA_RDMA_SRC, (val))
#define OVL_RDMA_ULTRA_SRC_VAL_ULTRA_ROI_END_SRC(val)          REG_FLD_VAL(OVL_RDMA_ULTRA_SRC_FLD_ULTRA_ROI_END_SRC, (val))
#define OVL_RDMA_ULTRA_SRC_VAL_ULTRA_SMI_SRC(val)              REG_FLD_VAL(OVL_RDMA_ULTRA_SRC_FLD_ULTRA_SMI_SRC, (val))
#define OVL_RDMA_ULTRA_SRC_VAL_ULTRA_BUF_SRC(val)              REG_FLD_VAL(OVL_RDMA_ULTRA_SRC_FLD_ULTRA_BUF_SRC, (val))
#define OVL_RDMA_ULTRA_SRC_VAL_PREULTRA_RDMA_SRC(val)          REG_FLD_VAL(OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_RDMA_SRC, (val))
#define OVL_RDMA_ULTRA_SRC_VAL_PREULTRA_ROI_END_SRC(val)       REG_FLD_VAL(OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_ROI_END_SRC, (val))
#define OVL_RDMA_ULTRA_SRC_VAL_PREULTRA_SMI_SRC(val)           REG_FLD_VAL(OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_SMI_SRC, (val))
#define OVL_RDMA_ULTRA_SRC_VAL_PREULTRA_BUF_SRC(val)           REG_FLD_VAL(OVL_RDMA_ULTRA_SRC_FLD_PREULTRA_BUF_SRC, (val))

#define OVL_RDMA0_BUF_LOW_TH_VAL_RDMA0_PREULTRA_LOW_TH(val)    REG_FLD_VAL(OVL_RDMA0_BUF_LOW_TH_FLD_RDMA0_PREULTRA_LOW_TH, (val))
#define OVL_RDMA0_BUF_LOW_TH_VAL_RDMA0_ULTRA_LOW_TH(val)       REG_FLD_VAL(OVL_RDMA0_BUF_LOW_TH_FLD_RDMA0_ULTRA_LOW_TH, (val))

#define OVL_RDMA1_BUF_LOW_TH_VAL_RDMA1_PREULTRA_LOW_TH(val)    REG_FLD_VAL(OVL_RDMA1_BUF_LOW_TH_FLD_RDMA1_PREULTRA_LOW_TH, (val))
#define OVL_RDMA1_BUF_LOW_TH_VAL_RDMA1_ULTRA_LOW_TH(val)       REG_FLD_VAL(OVL_RDMA1_BUF_LOW_TH_FLD_RDMA1_ULTRA_LOW_TH, (val))

#define OVL_RDMA2_BUF_LOW_TH_VAL_RDMA2_PREULTRA_LOW_TH(val)    REG_FLD_VAL(OVL_RDMA2_BUF_LOW_TH_FLD_RDMA2_PREULTRA_LOW_TH, (val))
#define OVL_RDMA2_BUF_LOW_TH_VAL_RDMA2_ULTRA_LOW_TH(val)       REG_FLD_VAL(OVL_RDMA2_BUF_LOW_TH_FLD_RDMA2_ULTRA_LOW_TH, (val))

#define OVL_RDMA3_BUF_LOW_TH_VAL_RDMA3_PREULTRA_LOW_TH(val)    REG_FLD_VAL(OVL_RDMA3_BUF_LOW_TH_FLD_RDMA3_PREULTRA_LOW_TH, (val))
#define OVL_RDMA3_BUF_LOW_TH_VAL_RDMA3_ULTRA_LOW_TH(val)       REG_FLD_VAL(OVL_RDMA3_BUF_LOW_TH_FLD_RDMA3_ULTRA_LOW_TH, (val))

#define OVL_RDMA0_BUF_HIGH_TH_VAL_RDMA0_PREULTRA_HIGH_DIS(val) REG_FLD_VAL(OVL_RDMA0_BUF_HIGH_TH_FLD_RDMA0_PREULTRA_HIGH_DIS, (val))
#define OVL_RDMA0_BUF_HIGH_TH_VAL_RDMA0_PREULTRA_HIGH_TH(val)  REG_FLD_VAL(OVL_RDMA0_BUF_HIGH_TH_FLD_RDMA0_PREULTRA_HIGH_TH, (val))

#define OVL_RDMA1_BUF_HIGH_TH_VAL_RDMA1_PREULTRA_HIGH_DIS(val) REG_FLD_VAL(OVL_RDMA1_BUF_HIGH_TH_FLD_RDMA1_PREULTRA_HIGH_DIS, (val))
#define OVL_RDMA1_BUF_HIGH_TH_VAL_RDMA1_PREULTRA_HIGH_TH(val)  REG_FLD_VAL(OVL_RDMA1_BUF_HIGH_TH_FLD_RDMA1_PREULTRA_HIGH_TH, (val))

#define OVL_RDMA2_BUF_HIGH_TH_VAL_RDMA2_PREULTRA_HIGH_DIS(val) REG_FLD_VAL(OVL_RDMA2_BUF_HIGH_TH_FLD_RDMA2_PREULTRA_HIGH_DIS, (val))
#define OVL_RDMA2_BUF_HIGH_TH_VAL_RDMA2_PREULTRA_HIGH_TH(val)  REG_FLD_VAL(OVL_RDMA2_BUF_HIGH_TH_FLD_RDMA2_PREULTRA_HIGH_TH, (val))

#define OVL_RDMA3_BUF_HIGH_TH_VAL_RDMA3_PREULTRA_HIGH_DIS(val) REG_FLD_VAL(OVL_RDMA3_BUF_HIGH_TH_FLD_RDMA3_PREULTRA_HIGH_DIS, (val))
#define OVL_RDMA3_BUF_HIGH_TH_VAL_RDMA3_PREULTRA_HIGH_TH(val)  REG_FLD_VAL(OVL_RDMA3_BUF_HIGH_TH_FLD_RDMA3_PREULTRA_HIGH_TH, (val))

#define OVL_SMI_DBG_VAL_SMI_FSM(val)                           REG_FLD_VAL(OVL_SMI_DBG_FLD_SMI_FSM, (val))

#define OVL_GREQ_LAYER_CNT_VAL_LAYER3_GREQ_CNT(val)            REG_FLD_VAL(OVL_GREQ_LAYER_CNT_FLD_LAYER3_GREQ_CNT, (val))
#define OVL_GREQ_LAYER_CNT_VAL_LAYER2_GREQ_CNT(val)            REG_FLD_VAL(OVL_GREQ_LAYER_CNT_FLD_LAYER2_GREQ_CNT, (val))
#define OVL_GREQ_LAYER_CNT_VAL_LAYER1_GREQ_CNT(val)            REG_FLD_VAL(OVL_GREQ_LAYER_CNT_FLD_LAYER1_GREQ_CNT, (val))
#define OVL_GREQ_LAYER_CNT_VAL_LAYER0_GREQ_CNT(val)            REG_FLD_VAL(OVL_GREQ_LAYER_CNT_FLD_LAYER0_GREQ_CNT, (val))

#define OVL_GDRDY_PRD_NUM_VAL_GDRDY_PRD_NUM(val)               REG_FLD_VAL(OVL_GDRDY_PRD_NUM_FLD_GDRDY_PRD_NUM, (val))

#define OVL_FLOW_CTRL_DBG_VAL_OVL_UPD_REG(val)                 REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_OVL_UPD_REG, (val))
#define OVL_FLOW_CTRL_DBG_VAL_REG_UPDATE(val)                  REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_REG_UPDATE, (val))
#define OVL_FLOW_CTRL_DBG_VAL_OVL_CLR(val)                     REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_OVL_CLR, (val))
#define OVL_FLOW_CTRL_DBG_VAL_OVL_START(val)                   REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_OVL_START, (val))
#define OVL_FLOW_CTRL_DBG_VAL_OVL_RUNNING(val)                 REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_OVL_RUNNING, (val))
#define OVL_FLOW_CTRL_DBG_VAL_FRAME_DONE(val)                  REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_FRAME_DONE, (val))
#define OVL_FLOW_CTRL_DBG_VAL_FRAME_UNDERRUN(val)              REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_FRAME_UNDERRUN, (val))
#define OVL_FLOW_CTRL_DBG_VAL_FRAME_SWRST_DONE(val)            REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_FRAME_SWRST_DONE, (val))
#define OVL_FLOW_CTRL_DBG_VAL_FRAME_HWRST_DONE(val)            REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_FRAME_HWRST_DONE, (val))
#define OVL_FLOW_CTRL_DBG_VAL_TRIG(val)                        REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_TRIG, (val))
#define OVL_FLOW_CTRL_DBG_VAL_RST(val)                         REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_RST, (val))
#define OVL_FLOW_CTRL_DBG_VAL_RDMA0_IDLE(val)                  REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_RDMA0_IDLE, (val))
#define OVL_FLOW_CTRL_DBG_VAL_RDMA1_IDLE(val)                  REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_RDMA1_IDLE, (val))
#define OVL_FLOW_CTRL_DBG_VAL_RDMA2_IDLE(val)                  REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_RDMA2_IDLE, (val))
#define OVL_FLOW_CTRL_DBG_VAL_RDMA3_IDLE(val)                  REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_RDMA3_IDLE, (val))
#define OVL_FLOW_CTRL_DBG_VAL_OUT_IDLE(val)                    REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_OUT_IDLE, (val))
#define OVL_FLOW_CTRL_DBG_VAL_OVL_OUT_READY(val)               REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_OVL_OUT_READY, (val))
#define OVL_FLOW_CTRL_DBG_VAL_OVL_OUT_VALID(val)               REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_OVL_OUT_VALID, (val))
#define OVL_FLOW_CTRL_DBG_VAL_BLEND_IDLE(val)                  REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_BLEND_IDLE, (val))
#define OVL_FLOW_CTRL_DBG_VAL_ADDCON_IDLE(val)                 REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_ADDCON_IDLE, (val))
#define OVL_FLOW_CTRL_DBG_VAL_FSM_STATE(val)                   REG_FLD_VAL(OVL_FLOW_CTRL_DBG_FLD_FSM_STATE, (val))

#define OVL_ADDCON_DBG_VAL_L3_WIN_HIT(val)                     REG_FLD_VAL(OVL_ADDCON_DBG_FLD_L3_WIN_HIT, (val))
#define OVL_ADDCON_DBG_VAL_L2_WIN_HIT(val)                     REG_FLD_VAL(OVL_ADDCON_DBG_FLD_L2_WIN_HIT, (val))
#define OVL_ADDCON_DBG_VAL_ROI_Y(val)                          REG_FLD_VAL(OVL_ADDCON_DBG_FLD_ROI_Y, (val))
#define OVL_ADDCON_DBG_VAL_L1_WIN_HIT(val)                     REG_FLD_VAL(OVL_ADDCON_DBG_FLD_L1_WIN_HIT, (val))
#define OVL_ADDCON_DBG_VAL_L0_WIN_HIT(val)                     REG_FLD_VAL(OVL_ADDCON_DBG_FLD_L0_WIN_HIT, (val))
#define OVL_ADDCON_DBG_VAL_ROI_X(val)                          REG_FLD_VAL(OVL_ADDCON_DBG_FLD_ROI_X, (val))

#define OVL_RDMA0_DBG_VAL_SMI_GREQ(val)                        REG_FLD_VAL(OVL_RDMA0_DBG_FLD_SMI_GREQ, (val))
#define OVL_RDMA0_DBG_VAL_RDMA0_SMI_BUSY(val)                  REG_FLD_VAL(OVL_RDMA0_DBG_FLD_RDMA0_SMI_BUSY, (val))
#define OVL_RDMA0_DBG_VAL_RDMA0_OUT_VALID(val)                 REG_FLD_VAL(OVL_RDMA0_DBG_FLD_RDMA0_OUT_VALID, (val))
#define OVL_RDMA0_DBG_VAL_RDMA0_OUT_READY(val)                 REG_FLD_VAL(OVL_RDMA0_DBG_FLD_RDMA0_OUT_READY, (val))
#define OVL_RDMA0_DBG_VAL_RDMA0_OUT_DATA(val)                  REG_FLD_VAL(OVL_RDMA0_DBG_FLD_RDMA0_OUT_DATA, (val))
#define OVL_RDMA0_DBG_VAL_RDMA0_LAYER_GREQ(val)                REG_FLD_VAL(OVL_RDMA0_DBG_FLD_RDMA0_LAYER_GREQ, (val))
#define OVL_RDMA0_DBG_VAL_RDMA0_WRAM_RST_CS(val)               REG_FLD_VAL(OVL_RDMA0_DBG_FLD_RDMA0_WRAM_RST_CS, (val))

#define OVL_RDMA1_DBG_VAL_SMI_GREQ(val)                        REG_FLD_VAL(OVL_RDMA1_DBG_FLD_SMI_GREQ, (val))
#define OVL_RDMA1_DBG_VAL_RDMA1_SMI_BUSY(val)                  REG_FLD_VAL(OVL_RDMA1_DBG_FLD_RDMA1_SMI_BUSY, (val))
#define OVL_RDMA1_DBG_VAL_RDMA1_OUT_VALID(val)                 REG_FLD_VAL(OVL_RDMA1_DBG_FLD_RDMA1_OUT_VALID, (val))
#define OVL_RDMA1_DBG_VAL_RDMA1_OUT_READY(val)                 REG_FLD_VAL(OVL_RDMA1_DBG_FLD_RDMA1_OUT_READY, (val))
#define OVL_RDMA1_DBG_VAL_RDMA1_OUT_DATA(val)                  REG_FLD_VAL(OVL_RDMA1_DBG_FLD_RDMA1_OUT_DATA, (val))
#define OVL_RDMA1_DBG_VAL_RDMA1_LAYER_GREQ(val)                REG_FLD_VAL(OVL_RDMA1_DBG_FLD_RDMA1_LAYER_GREQ, (val))
#define OVL_RDMA1_DBG_VAL_RDMA1_WRAM_RST_CS(val)               REG_FLD_VAL(OVL_RDMA1_DBG_FLD_RDMA1_WRAM_RST_CS, (val))

#define OVL_RDMA2_DBG_VAL_SMI_GREQ(val)                        REG_FLD_VAL(OVL_RDMA2_DBG_FLD_SMI_GREQ, (val))
#define OVL_RDMA2_DBG_VAL_RDMA2_SMI_BUSY(val)                  REG_FLD_VAL(OVL_RDMA2_DBG_FLD_RDMA2_SMI_BUSY, (val))
#define OVL_RDMA2_DBG_VAL_RDMA2_OUT_VALID(val)                 REG_FLD_VAL(OVL_RDMA2_DBG_FLD_RDMA2_OUT_VALID, (val))
#define OVL_RDMA2_DBG_VAL_RDMA2_OUT_READY(val)                 REG_FLD_VAL(OVL_RDMA2_DBG_FLD_RDMA2_OUT_READY, (val))
#define OVL_RDMA2_DBG_VAL_RDMA2_OUT_DATA(val)                  REG_FLD_VAL(OVL_RDMA2_DBG_FLD_RDMA2_OUT_DATA, (val))
#define OVL_RDMA2_DBG_VAL_RDMA2_LAYER_GREQ(val)                REG_FLD_VAL(OVL_RDMA2_DBG_FLD_RDMA2_LAYER_GREQ, (val))
#define OVL_RDMA2_DBG_VAL_RDMA2_WRAM_RST_CS(val)               REG_FLD_VAL(OVL_RDMA2_DBG_FLD_RDMA2_WRAM_RST_CS, (val))

#define OVL_RDMA3_DBG_VAL_SMI_GREQ(val)                        REG_FLD_VAL(OVL_RDMA3_DBG_FLD_SMI_GREQ, (val))
#define OVL_RDMA3_DBG_VAL_RDMA3_SMI_BUSY(val)                  REG_FLD_VAL(OVL_RDMA3_DBG_FLD_RDMA3_SMI_BUSY, (val))
#define OVL_RDMA3_DBG_VAL_RDMA3_OUT_VALID(val)                 REG_FLD_VAL(OVL_RDMA3_DBG_FLD_RDMA3_OUT_VALID, (val))
#define OVL_RDMA3_DBG_VAL_RDMA3_OUT_READY(val)                 REG_FLD_VAL(OVL_RDMA3_DBG_FLD_RDMA3_OUT_READY, (val))
#define OVL_RDMA3_DBG_VAL_RDMA3_OUT_DATA(val)                  REG_FLD_VAL(OVL_RDMA3_DBG_FLD_RDMA3_OUT_DATA, (val))
#define OVL_RDMA3_DBG_VAL_RDMA3_LAYER_GREQ(val)                REG_FLD_VAL(OVL_RDMA3_DBG_FLD_RDMA3_LAYER_GREQ, (val))
#define OVL_RDMA3_DBG_VAL_RDMA3_WRAM_RST_CS(val)               REG_FLD_VAL(OVL_RDMA3_DBG_FLD_RDMA3_WRAM_RST_CS, (val))

#define OVL_L0_CLR_VAL_ALPHA(val)                              REG_FLD_VAL(OVL_L0_CLR_FLD_ALPHA, (val))
#define OVL_L0_CLR_VAL_RED(val)                                REG_FLD_VAL(OVL_L0_CLR_FLD_RED, (val))
#define OVL_L0_CLR_VAL_GREEN(val)                              REG_FLD_VAL(OVL_L0_CLR_FLD_GREEN, (val))
#define OVL_L0_CLR_VAL_BLUE(val)                               REG_FLD_VAL(OVL_L0_CLR_FLD_BLUE, (val))

#define OVL_L1_CLR_VAL_ALPHA(val)                              REG_FLD_VAL(OVL_L1_CLR_FLD_ALPHA, (val))
#define OVL_L1_CLR_VAL_RED(val)                                REG_FLD_VAL(OVL_L1_CLR_FLD_RED, (val))
#define OVL_L1_CLR_VAL_GREEN(val)                              REG_FLD_VAL(OVL_L1_CLR_FLD_GREEN, (val))
#define OVL_L1_CLR_VAL_BLUE(val)                               REG_FLD_VAL(OVL_L1_CLR_FLD_BLUE, (val))

#define OVL_L2_CLR_VAL_ALPHA(val)                              REG_FLD_VAL(OVL_L2_CLR_FLD_ALPHA, (val))
#define OVL_L2_CLR_VAL_RED(val)                                REG_FLD_VAL(OVL_L2_CLR_FLD_RED, (val))
#define OVL_L2_CLR_VAL_GREEN(val)                              REG_FLD_VAL(OVL_L2_CLR_FLD_GREEN, (val))
#define OVL_L2_CLR_VAL_BLUE(val)                               REG_FLD_VAL(OVL_L2_CLR_FLD_BLUE, (val))

#define OVL_L3_CLR_VAL_ALPHA(val)                              REG_FLD_VAL(OVL_L3_CLR_FLD_ALPHA, (val))
#define OVL_L3_CLR_VAL_RED(val)                                REG_FLD_VAL(OVL_L3_CLR_FLD_RED, (val))
#define OVL_L3_CLR_VAL_GREEN(val)                              REG_FLD_VAL(OVL_L3_CLR_FLD_GREEN, (val))
#define OVL_L3_CLR_VAL_BLUE(val)                               REG_FLD_VAL(OVL_L3_CLR_FLD_BLUE, (val))

#define OVL_LC_CLR_VAL_ALPHA(val)                              REG_FLD_VAL(OVL_LC_CLR_FLD_ALPHA, (val))
#define OVL_LC_CLR_VAL_RED(val)                                REG_FLD_VAL(OVL_LC_CLR_FLD_RED, (val))
#define OVL_LC_CLR_VAL_GREEN(val)                              REG_FLD_VAL(OVL_LC_CLR_FLD_GREEN, (val))
#define OVL_LC_CLR_VAL_BLUE(val)                               REG_FLD_VAL(OVL_LC_CLR_FLD_BLUE, (val))

#define OVL_CRC_VAL_CRC_RDY(val)                               REG_FLD_VAL(OVL_CRC_FLD_CRC_RDY, (val))
#define OVL_CRC_VAL_CRC_OUT(val)                               REG_FLD_VAL(OVL_CRC_FLD_CRC_OUT, (val))

#define OVL_LC_CON_VAL_DSTKEY_EN(val)                          REG_FLD_VAL(OVL_LC_CON_FLD_DSTKEY_EN, (val))
#define OVL_LC_CON_VAL_SRCKEY_EN(val)                          REG_FLD_VAL(OVL_LC_CON_FLD_SRCKEY_EN, (val))
#define OVL_LC_CON_VAL_LAYER_SRC(val)                          REG_FLD_VAL(OVL_LC_CON_FLD_LAYER_SRC, (val))
#define OVL_LC_CON_VAL_R_FIRST(val)                            REG_FLD_VAL(OVL_LC_CON_FLD_R_FIRST, (val))
#define OVL_LC_CON_VAL_LANDSCAPE(val)                          REG_FLD_VAL(OVL_LC_CON_FLD_LANDSCAPE, (val))
#define OVL_LC_CON_VAL_EN_3D(val)                              REG_FLD_VAL(OVL_LC_CON_FLD_EN_3D, (val))
#define OVL_LC_CON_VAL_ALPHA_EN(val)                           REG_FLD_VAL(OVL_LC_CON_FLD_ALPHA_EN, (val))
#define OVL_LC_CON_VAL_ALPHA(val)                              REG_FLD_VAL(OVL_LC_CON_FLD_ALPHA, (val))

#define OVL_LC_SRCKEY_VAL_SRCKEY(val)                          REG_FLD_VAL(OVL_LC_SRCKEY_FLD_SRCKEY, (val))

#define OVL_LC_SRC_SIZE_VAL_LC_SRC_H(val)                      REG_FLD_VAL(OVL_LC_SRC_SIZE_FLD_LC_SRC_H, (val))
#define OVL_LC_SRC_SIZE_VAL_LC_SRC_W(val)                      REG_FLD_VAL(OVL_LC_SRC_SIZE_FLD_LC_SRC_W, (val))

#define OVL_LC_OFFSET_VAL_LC_YOFF(val)                         REG_FLD_VAL(OVL_LC_OFFSET_FLD_LC_YOFF, (val))
#define OVL_LC_OFFSET_VAL_LC_XOFF(val)                         REG_FLD_VAL(OVL_LC_OFFSET_FLD_LC_XOFF, (val))

#define OVL_LC_SRC_SEL_VAL_SURFL_EN(val)                       REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_SURFL_EN, (val))
#define OVL_LC_SRC_SEL_VAL_LC_BLEND_RND_SHT(val)               REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_LC_BLEND_RND_SHT, (val))
#define OVL_LC_SRC_SEL_VAL_LC_SRGB_SEL_EXT2(val)               REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_LC_SRGB_SEL_EXT2, (val))
#define OVL_LC_SRC_SEL_VAL_LC_CONST_BLD(val)                   REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_LC_CONST_BLD, (val))
#define OVL_LC_SRC_SEL_VAL_LC_DRGB_SEL_EXT(val)                REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_LC_DRGB_SEL_EXT, (val))
#define OVL_LC_SRC_SEL_VAL_LC_DA_SEL_EXT(val)                  REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_LC_DA_SEL_EXT, (val))
#define OVL_LC_SRC_SEL_VAL_LC_SRGB_SEL_EXT(val)                REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_LC_SRGB_SEL_EXT, (val))
#define OVL_LC_SRC_SEL_VAL_LC_SA_SEL_EXT(val)                  REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_LC_SA_SEL_EXT, (val))
#define OVL_LC_SRC_SEL_VAL_LC_DRGB_SEL(val)                    REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_LC_DRGB_SEL, (val))
#define OVL_LC_SRC_SEL_VAL_LC_DA_SEL(val)                      REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_LC_DA_SEL, (val))
#define OVL_LC_SRC_SEL_VAL_LC_SRGB_SEL(val)                    REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_LC_SRGB_SEL, (val))
#define OVL_LC_SRC_SEL_VAL_LC_SA_SEL(val)                      REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_LC_SA_SEL, (val))
#define OVL_LC_SRC_SEL_VAL_CONST_LAYER_SEL(val)                REG_FLD_VAL(OVL_LC_SRC_SEL_FLD_CONST_LAYER_SEL, (val))

#define OVL_BANK_CON_VAL_OVL_BANK_CON(val)                     REG_FLD_VAL(OVL_BANK_CON_FLD_OVL_BANK_CON, (val))

#define OVL_FUNC_DCM0_VAL_OVL_FUNC_DCM0(val)                   REG_FLD_VAL(OVL_FUNC_DCM0_FLD_OVL_FUNC_DCM0, (val))

#define OVL_FUNC_DCM1_VAL_OVL_FUNC_DCM1(val)                   REG_FLD_VAL(OVL_FUNC_DCM1_FLD_OVL_FUNC_DCM1, (val))

#define OVL_DVFS_L0_ROI_VAL_L0_DVFS_ROI_BB(val)                REG_FLD_VAL(OVL_DVFS_L0_ROI_FLD_L0_DVFS_ROI_BB, (val))
#define OVL_DVFS_L0_ROI_VAL_L0_DVFS_ROI_TB(val)                REG_FLD_VAL(OVL_DVFS_L0_ROI_FLD_L0_DVFS_ROI_TB, (val))

#define OVL_DVFS_L1_ROI_VAL_L1_DVFS_ROI_BB(val)                REG_FLD_VAL(OVL_DVFS_L1_ROI_FLD_L1_DVFS_ROI_BB, (val))
#define OVL_DVFS_L1_ROI_VAL_L1_DVFS_ROI_TB(val)                REG_FLD_VAL(OVL_DVFS_L1_ROI_FLD_L1_DVFS_ROI_TB, (val))

#define OVL_DVFS_L2_ROI_VAL_L2_DVFS_ROI_BB(val)                REG_FLD_VAL(OVL_DVFS_L2_ROI_FLD_L2_DVFS_ROI_BB, (val))
#define OVL_DVFS_L2_ROI_VAL_L2_DVFS_ROI_TB(val)                REG_FLD_VAL(OVL_DVFS_L2_ROI_FLD_L2_DVFS_ROI_TB, (val))

#define OVL_DVFS_L3_ROI_VAL_L3_DVFS_ROI_BB(val)                REG_FLD_VAL(OVL_DVFS_L3_ROI_FLD_L3_DVFS_ROI_BB, (val))
#define OVL_DVFS_L3_ROI_VAL_L3_DVFS_ROI_TB(val)                REG_FLD_VAL(OVL_DVFS_L3_ROI_FLD_L3_DVFS_ROI_TB, (val))

#define OVL_DVFS_EL0_ROI_VAL_EL0_DVFS_ROI_BB(val)              REG_FLD_VAL(OVL_DVFS_EL0_ROI_FLD_EL0_DVFS_ROI_BB, (val))
#define OVL_DVFS_EL0_ROI_VAL_EL0_DVFS_ROI_TB(val)              REG_FLD_VAL(OVL_DVFS_EL0_ROI_FLD_EL0_DVFS_ROI_TB, (val))

#define OVL_DVFS_EL1_ROI_VAL_EL1_DVFS_ROI_BB(val)              REG_FLD_VAL(OVL_DVFS_EL1_ROI_FLD_EL1_DVFS_ROI_BB, (val))
#define OVL_DVFS_EL1_ROI_VAL_EL1_DVFS_ROI_TB(val)              REG_FLD_VAL(OVL_DVFS_EL1_ROI_FLD_EL1_DVFS_ROI_TB, (val))

#define OVL_DVFS_EL2_ROI_VAL_EL2_DVFS_ROI_BB(val)              REG_FLD_VAL(OVL_DVFS_EL2_ROI_FLD_EL2_DVFS_ROI_BB, (val))
#define OVL_DVFS_EL2_ROI_VAL_EL2_DVFS_ROI_TB(val)              REG_FLD_VAL(OVL_DVFS_EL2_ROI_FLD_EL2_DVFS_ROI_TB, (val))

#define OVL_DATAPATH_EXT_CON_VAL_EL2_LAYER_SEL(val)            REG_FLD_VAL(OVL_DATAPATH_EXT_CON_FLD_EL2_LAYER_SEL, (val))
#define OVL_DATAPATH_EXT_CON_VAL_EL1_LAYER_SEL(val)            REG_FLD_VAL(OVL_DATAPATH_EXT_CON_FLD_EL1_LAYER_SEL, (val))
#define OVL_DATAPATH_EXT_CON_VAL_EL0_LAYER_SEL(val)            REG_FLD_VAL(OVL_DATAPATH_EXT_CON_FLD_EL0_LAYER_SEL, (val))
#define OVL_DATAPATH_EXT_CON_VAL_EL2_GPU_MODE(val)             REG_FLD_VAL(OVL_DATAPATH_EXT_CON_FLD_EL2_GPU_MODE, (val))
#define OVL_DATAPATH_EXT_CON_VAL_EL1_GPU_MODE(val)             REG_FLD_VAL(OVL_DATAPATH_EXT_CON_FLD_EL1_GPU_MODE, (val))
#define OVL_DATAPATH_EXT_CON_VAL_EL0_GPU_MODE(val)             REG_FLD_VAL(OVL_DATAPATH_EXT_CON_FLD_EL0_GPU_MODE, (val))
#define OVL_DATAPATH_EXT_CON_VAL_EL2_EN(val)                   REG_FLD_VAL(OVL_DATAPATH_EXT_CON_FLD_EL2_EN, (val))
#define OVL_DATAPATH_EXT_CON_VAL_EL1_EN(val)                   REG_FLD_VAL(OVL_DATAPATH_EXT_CON_FLD_EL1_EN, (val))
#define OVL_DATAPATH_EXT_CON_VAL_EL0_EN(val)                   REG_FLD_VAL(OVL_DATAPATH_EXT_CON_FLD_EL0_EN, (val))

#define OVL_EL0_CON_VAL_DSTKEY_EN(val)                         REG_FLD_VAL(OVL_EL0_CON_FLD_DSTKEY_EN, (val))
#define OVL_EL0_CON_VAL_SRCKEY_EN(val)                         REG_FLD_VAL(OVL_EL0_CON_FLD_SRCKEY_EN, (val))
#define OVL_EL0_CON_VAL_LAYER_SRC(val)                         REG_FLD_VAL(OVL_EL0_CON_FLD_LAYER_SRC, (val))
#define OVL_EL0_CON_VAL_MTX_EN(val)                            REG_FLD_VAL(OVL_EL0_CON_FLD_MTX_EN, (val))
#define OVL_EL0_CON_VAL_MTX_AUTO_DIS(val)                      REG_FLD_VAL(OVL_EL0_CON_FLD_MTX_AUTO_DIS, (val))
#define OVL_EL0_CON_VAL_RGB_SWAP(val)                          REG_FLD_VAL(OVL_EL0_CON_FLD_RGB_SWAP, (val))
#define OVL_EL0_CON_VAL_BYTE_SWAP(val)                         REG_FLD_VAL(OVL_EL0_CON_FLD_BYTE_SWAP, (val))
#define OVL_EL0_CON_VAL_CLRFMT_MAN(val)                        REG_FLD_VAL(OVL_EL0_CON_FLD_CLRFMT_MAN, (val))
#define OVL_EL0_CON_VAL_R_FIRST(val)                           REG_FLD_VAL(OVL_EL0_CON_FLD_R_FIRST, (val))
#define OVL_EL0_CON_VAL_LANDSCAPE(val)                         REG_FLD_VAL(OVL_EL0_CON_FLD_LANDSCAPE, (val))
#define OVL_EL0_CON_VAL_EN_3D(val)                             REG_FLD_VAL(OVL_EL0_CON_FLD_EN_3D, (val))
#define OVL_EL0_CON_VAL_INT_MTX_SEL(val)                       REG_FLD_VAL(OVL_EL0_CON_FLD_INT_MTX_SEL, (val))
#define OVL_EL0_CON_VAL_CLRFMT(val)                            REG_FLD_VAL(OVL_EL0_CON_FLD_CLRFMT, (val))
#define OVL_EL0_CON_VAL_EXT_MTX_EN(val)                        REG_FLD_VAL(OVL_EL0_CON_FLD_EXT_MTX_EN, (val))
#define OVL_EL0_CON_VAL_HORIZONTAL_FLIP_EN(val)                REG_FLD_VAL(OVL_EL0_CON_FLD_HORIZONTAL_FLIP_EN, (val))
#define OVL_EL0_CON_VAL_VERTICAL_FLIP_EN(val)                  REG_FLD_VAL(OVL_EL0_CON_FLD_VERTICAL_FLIP_EN, (val))
#define OVL_EL0_CON_VAL_ALPHA_EN(val)                          REG_FLD_VAL(OVL_EL0_CON_FLD_ALPHA_EN, (val))
#define OVL_EL0_CON_VAL_ALPHA(val)                             REG_FLD_VAL(OVL_EL0_CON_FLD_ALPHA, (val))

#define OVL_EL0_SRCKEY_VAL_SRCKEY(val)                         REG_FLD_VAL(OVL_EL0_SRCKEY_FLD_SRCKEY, (val))

#define OVL_EL0_SRC_SIZE_VAL_EL0_SRC_H(val)                    REG_FLD_VAL(OVL_EL0_SRC_SIZE_FLD_EL0_SRC_H, (val))
#define OVL_EL0_SRC_SIZE_VAL_EL0_SRC_W(val)                    REG_FLD_VAL(OVL_EL0_SRC_SIZE_FLD_EL0_SRC_W, (val))

#define OVL_EL0_OFFSET_VAL_EL0_YOFF(val)                       REG_FLD_VAL(OVL_EL0_OFFSET_FLD_EL0_YOFF, (val))
#define OVL_EL0_OFFSET_VAL_EL0_XOFF(val)                       REG_FLD_VAL(OVL_EL0_OFFSET_FLD_EL0_XOFF, (val))

#define OVL_EL0_PITCH_VAL_SURFL_EN(val)                        REG_FLD_VAL(OVL_EL0_PITCH_FLD_SURFL_EN, (val))
#define OVL_EL0_PITCH_VAL_EL0_BLEND_RND_SHT(val)               REG_FLD_VAL(OVL_EL0_PITCH_FLD_EL0_BLEND_RND_SHT, (val))
#define OVL_EL0_PITCH_VAL_EL0_SRGB_SEL_EXT2(val)               REG_FLD_VAL(OVL_EL0_PITCH_FLD_EL0_SRGB_SEL_EXT2, (val))
#define OVL_EL0_PITCH_VAL_EL0_CONST_BLD(val)                   REG_FLD_VAL(OVL_EL0_PITCH_FLD_EL0_CONST_BLD, (val))
#define OVL_EL0_PITCH_VAL_EL0_DRGB_SEL_EXT(val)                REG_FLD_VAL(OVL_EL0_PITCH_FLD_EL0_DRGB_SEL_EXT, (val))
#define OVL_EL0_PITCH_VAL_EL0_DA_SEL_EXT(val)                  REG_FLD_VAL(OVL_EL0_PITCH_FLD_EL0_DA_SEL_EXT, (val))
#define OVL_EL0_PITCH_VAL_EL0_SRGB_SEL_EXT(val)                REG_FLD_VAL(OVL_EL0_PITCH_FLD_EL0_SRGB_SEL_EXT, (val))
#define OVL_EL0_PITCH_VAL_EL0_SA_SEL_EXT(val)                  REG_FLD_VAL(OVL_EL0_PITCH_FLD_EL0_SA_SEL_EXT, (val))
#define OVL_EL0_PITCH_VAL_EL0_DRGB_SEL(val)                    REG_FLD_VAL(OVL_EL0_PITCH_FLD_EL0_DRGB_SEL, (val))
#define OVL_EL0_PITCH_VAL_EL0_DA_SEL(val)                      REG_FLD_VAL(OVL_EL0_PITCH_FLD_EL0_DA_SEL, (val))
#define OVL_EL0_PITCH_VAL_EL0_SRGB_SEL(val)                    REG_FLD_VAL(OVL_EL0_PITCH_FLD_EL0_SRGB_SEL, (val))
#define OVL_EL0_PITCH_VAL_EL0_SA_SEL(val)                      REG_FLD_VAL(OVL_EL0_PITCH_FLD_EL0_SA_SEL, (val))
#define OVL_EL0_PITCH_VAL_EL0_SRC_PITCH(val)                   REG_FLD_VAL(OVL_EL0_PITCH_FLD_EL0_SRC_PITCH, (val))

#define OVL_EL0_TILE_VAL_TILE_HORI_BLOCK_NUM(val)              REG_FLD_VAL(OVL_EL0_TILE_FLD_TILE_HORI_BLOCK_NUM, (val))
#define OVL_EL0_TILE_VAL_TILE_EN(val)                          REG_FLD_VAL(OVL_EL0_TILE_FLD_TILE_EN, (val))
#define OVL_EL0_TILE_VAL_TILE_WIDTH_SEL(val)                   REG_FLD_VAL(OVL_EL0_TILE_FLD_TILE_WIDTH_SEL, (val))
#define OVL_EL0_TILE_VAL_TILE_HEIGHT(val)                      REG_FLD_VAL(OVL_EL0_TILE_FLD_TILE_HEIGHT, (val))

#define OVL_EL0_CLIP_VAL_EL0_SRC_BOTTOM_CLIP(val)              REG_FLD_VAL(OVL_EL0_CLIP_FLD_EL0_SRC_BOTTOM_CLIP, (val))
#define OVL_EL0_CLIP_VAL_EL0_SRC_TOP_CLIP(val)                 REG_FLD_VAL(OVL_EL0_CLIP_FLD_EL0_SRC_TOP_CLIP, (val))
#define OVL_EL0_CLIP_VAL_EL0_SRC_RIGHT_CLIP(val)               REG_FLD_VAL(OVL_EL0_CLIP_FLD_EL0_SRC_RIGHT_CLIP, (val))
#define OVL_EL0_CLIP_VAL_EL0_SRC_LEFT_CLIP(val)                REG_FLD_VAL(OVL_EL0_CLIP_FLD_EL0_SRC_LEFT_CLIP, (val))

#define OVL_EL1_CON_VAL_DSTKEY_EN(val)                         REG_FLD_VAL(OVL_EL1_CON_FLD_DSTKEY_EN, (val))
#define OVL_EL1_CON_VAL_SRCKEY_EN(val)                         REG_FLD_VAL(OVL_EL1_CON_FLD_SRCKEY_EN, (val))
#define OVL_EL1_CON_VAL_LAYER_SRC(val)                         REG_FLD_VAL(OVL_EL1_CON_FLD_LAYER_SRC, (val))
#define OVL_EL1_CON_VAL_MTX_EN(val)                            REG_FLD_VAL(OVL_EL1_CON_FLD_MTX_EN, (val))
#define OVL_EL1_CON_VAL_MTX_AUTO_DIS(val)                      REG_FLD_VAL(OVL_EL1_CON_FLD_MTX_AUTO_DIS, (val))
#define OVL_EL1_CON_VAL_RGB_SWAP(val)                          REG_FLD_VAL(OVL_EL1_CON_FLD_RGB_SWAP, (val))
#define OVL_EL1_CON_VAL_BYTE_SWAP(val)                         REG_FLD_VAL(OVL_EL1_CON_FLD_BYTE_SWAP, (val))
#define OVL_EL1_CON_VAL_CLRFMT_MAN(val)                        REG_FLD_VAL(OVL_EL1_CON_FLD_CLRFMT_MAN, (val))
#define OVL_EL1_CON_VAL_R_FIRST(val)                           REG_FLD_VAL(OVL_EL1_CON_FLD_R_FIRST, (val))
#define OVL_EL1_CON_VAL_LANDSCAPE(val)                         REG_FLD_VAL(OVL_EL1_CON_FLD_LANDSCAPE, (val))
#define OVL_EL1_CON_VAL_EN_3D(val)                             REG_FLD_VAL(OVL_EL1_CON_FLD_EN_3D, (val))
#define OVL_EL1_CON_VAL_INT_MTX_SEL(val)                       REG_FLD_VAL(OVL_EL1_CON_FLD_INT_MTX_SEL, (val))
#define OVL_EL1_CON_VAL_CLRFMT(val)                            REG_FLD_VAL(OVL_EL1_CON_FLD_CLRFMT, (val))
#define OVL_EL1_CON_VAL_EXT_MTX_EN(val)                        REG_FLD_VAL(OVL_EL1_CON_FLD_EXT_MTX_EN, (val))
#define OVL_EL1_CON_VAL_HORIZONTAL_FLIP_EN(val)                REG_FLD_VAL(OVL_EL1_CON_FLD_HORIZONTAL_FLIP_EN, (val))
#define OVL_EL1_CON_VAL_VERTICAL_FLIP_EN(val)                  REG_FLD_VAL(OVL_EL1_CON_FLD_VERTICAL_FLIP_EN, (val))
#define OVL_EL1_CON_VAL_ALPHA_EN(val)                          REG_FLD_VAL(OVL_EL1_CON_FLD_ALPHA_EN, (val))
#define OVL_EL1_CON_VAL_ALPHA(val)                             REG_FLD_VAL(OVL_EL1_CON_FLD_ALPHA, (val))

#define OVL_EL1_SRCKEY_VAL_SRCKEY(val)                         REG_FLD_VAL(OVL_EL1_SRCKEY_FLD_SRCKEY, (val))

#define OVL_EL1_SRC_SIZE_VAL_EL1_SRC_H(val)                    REG_FLD_VAL(OVL_EL1_SRC_SIZE_FLD_EL1_SRC_H, (val))
#define OVL_EL1_SRC_SIZE_VAL_EL1_SRC_W(val)                    REG_FLD_VAL(OVL_EL1_SRC_SIZE_FLD_EL1_SRC_W, (val))

#define OVL_EL1_OFFSET_VAL_EL1_YOFF(val)                       REG_FLD_VAL(OVL_EL1_OFFSET_FLD_EL1_YOFF, (val))
#define OVL_EL1_OFFSET_VAL_EL1_XOFF(val)                       REG_FLD_VAL(OVL_EL1_OFFSET_FLD_EL1_XOFF, (val))

#define OVL_EL1_PITCH_VAL_SURFL_EN(val)                        REG_FLD_VAL(OVL_EL1_PITCH_FLD_SURFL_EN, (val))
#define OVL_EL1_PITCH_VAL_EL1_BLEND_RND_SHT(val)               REG_FLD_VAL(OVL_EL1_PITCH_FLD_EL1_BLEND_RND_SHT, (val))
#define OVL_EL1_PITCH_VAL_EL1_SRGB_SEL_EXT2(val)               REG_FLD_VAL(OVL_EL1_PITCH_FLD_EL1_SRGB_SEL_EXT2, (val))
#define OVL_EL1_PITCH_VAL_EL1_CONST_BLD(val)                   REG_FLD_VAL(OVL_EL1_PITCH_FLD_EL1_CONST_BLD, (val))
#define OVL_EL1_PITCH_VAL_EL1_DRGB_SEL_EXT(val)                REG_FLD_VAL(OVL_EL1_PITCH_FLD_EL1_DRGB_SEL_EXT, (val))
#define OVL_EL1_PITCH_VAL_EL1_DA_SEL_EXT(val)                  REG_FLD_VAL(OVL_EL1_PITCH_FLD_EL1_DA_SEL_EXT, (val))
#define OVL_EL1_PITCH_VAL_EL1_SRGB_SEL_EXT(val)                REG_FLD_VAL(OVL_EL1_PITCH_FLD_EL1_SRGB_SEL_EXT, (val))
#define OVL_EL1_PITCH_VAL_EL1_SA_SEL_EXT(val)                  REG_FLD_VAL(OVL_EL1_PITCH_FLD_EL1_SA_SEL_EXT, (val))
#define OVL_EL1_PITCH_VAL_EL1_DRGB_SEL(val)                    REG_FLD_VAL(OVL_EL1_PITCH_FLD_EL1_DRGB_SEL, (val))
#define OVL_EL1_PITCH_VAL_EL1_DA_SEL(val)                      REG_FLD_VAL(OVL_EL1_PITCH_FLD_EL1_DA_SEL, (val))
#define OVL_EL1_PITCH_VAL_EL1_SRGB_SEL(val)                    REG_FLD_VAL(OVL_EL1_PITCH_FLD_EL1_SRGB_SEL, (val))
#define OVL_EL1_PITCH_VAL_EL1_SA_SEL(val)                      REG_FLD_VAL(OVL_EL1_PITCH_FLD_EL1_SA_SEL, (val))
#define OVL_EL1_PITCH_VAL_EL1_SRC_PITCH(val)                   REG_FLD_VAL(OVL_EL1_PITCH_FLD_EL1_SRC_PITCH, (val))

#define OVL_EL1_TILE_VAL_TILE_HORI_BLOCK_NUM(val)              REG_FLD_VAL(OVL_EL1_TILE_FLD_TILE_HORI_BLOCK_NUM, (val))
#define OVL_EL1_TILE_VAL_TILE_EN(val)                          REG_FLD_VAL(OVL_EL1_TILE_FLD_TILE_EN, (val))
#define OVL_EL1_TILE_VAL_TILE_WIDTH_SEL(val)                   REG_FLD_VAL(OVL_EL1_TILE_FLD_TILE_WIDTH_SEL, (val))
#define OVL_EL1_TILE_VAL_TILE_HEIGHT(val)                      REG_FLD_VAL(OVL_EL1_TILE_FLD_TILE_HEIGHT, (val))

#define OVL_EL1_CLIP_VAL_EL1_SRC_BOTTOM_CLIP(val)              REG_FLD_VAL(OVL_EL1_CLIP_FLD_EL1_SRC_BOTTOM_CLIP, (val))
#define OVL_EL1_CLIP_VAL_EL1_SRC_TOP_CLIP(val)                 REG_FLD_VAL(OVL_EL1_CLIP_FLD_EL1_SRC_TOP_CLIP, (val))
#define OVL_EL1_CLIP_VAL_EL1_SRC_RIGHT_CLIP(val)               REG_FLD_VAL(OVL_EL1_CLIP_FLD_EL1_SRC_RIGHT_CLIP, (val))
#define OVL_EL1_CLIP_VAL_EL1_SRC_LEFT_CLIP(val)                REG_FLD_VAL(OVL_EL1_CLIP_FLD_EL1_SRC_LEFT_CLIP, (val))

#define OVL_EL2_CON_VAL_DSTKEY_EN(val)                         REG_FLD_VAL(OVL_EL2_CON_FLD_DSTKEY_EN, (val))
#define OVL_EL2_CON_VAL_SRCKEY_EN(val)                         REG_FLD_VAL(OVL_EL2_CON_FLD_SRCKEY_EN, (val))
#define OVL_EL2_CON_VAL_LAYER_SRC(val)                         REG_FLD_VAL(OVL_EL2_CON_FLD_LAYER_SRC, (val))
#define OVL_EL2_CON_VAL_MTX_EN(val)                            REG_FLD_VAL(OVL_EL2_CON_FLD_MTX_EN, (val))
#define OVL_EL2_CON_VAL_MTX_AUTO_DIS(val)                      REG_FLD_VAL(OVL_EL2_CON_FLD_MTX_AUTO_DIS, (val))
#define OVL_EL2_CON_VAL_RGB_SWAP(val)                          REG_FLD_VAL(OVL_EL2_CON_FLD_RGB_SWAP, (val))
#define OVL_EL2_CON_VAL_BYTE_SWAP(val)                         REG_FLD_VAL(OVL_EL2_CON_FLD_BYTE_SWAP, (val))
#define OVL_EL2_CON_VAL_CLRFMT_MAN(val)                        REG_FLD_VAL(OVL_EL2_CON_FLD_CLRFMT_MAN, (val))
#define OVL_EL2_CON_VAL_R_FIRST(val)                           REG_FLD_VAL(OVL_EL2_CON_FLD_R_FIRST, (val))
#define OVL_EL2_CON_VAL_LANDSCAPE(val)                         REG_FLD_VAL(OVL_EL2_CON_FLD_LANDSCAPE, (val))
#define OVL_EL2_CON_VAL_EN_3D(val)                             REG_FLD_VAL(OVL_EL2_CON_FLD_EN_3D, (val))
#define OVL_EL2_CON_VAL_INT_MTX_SEL(val)                       REG_FLD_VAL(OVL_EL2_CON_FLD_INT_MTX_SEL, (val))
#define OVL_EL2_CON_VAL_CLRFMT(val)                            REG_FLD_VAL(OVL_EL2_CON_FLD_CLRFMT, (val))
#define OVL_EL2_CON_VAL_EXT_MTX_EN(val)                        REG_FLD_VAL(OVL_EL2_CON_FLD_EXT_MTX_EN, (val))
#define OVL_EL2_CON_VAL_HORIZONTAL_FLIP_EN(val)                REG_FLD_VAL(OVL_EL2_CON_FLD_HORIZONTAL_FLIP_EN, (val))
#define OVL_EL2_CON_VAL_VERTICAL_FLIP_EN(val)                  REG_FLD_VAL(OVL_EL2_CON_FLD_VERTICAL_FLIP_EN, (val))
#define OVL_EL2_CON_VAL_ALPHA_EN(val)                          REG_FLD_VAL(OVL_EL2_CON_FLD_ALPHA_EN, (val))
#define OVL_EL2_CON_VAL_ALPHA(val)                             REG_FLD_VAL(OVL_EL2_CON_FLD_ALPHA, (val))

#define OVL_EL2_SRCKEY_VAL_SRCKEY(val)                         REG_FLD_VAL(OVL_EL2_SRCKEY_FLD_SRCKEY, (val))

#define OVL_EL2_SRC_SIZE_VAL_EL2_SRC_H(val)                    REG_FLD_VAL(OVL_EL2_SRC_SIZE_FLD_EL2_SRC_H, (val))
#define OVL_EL2_SRC_SIZE_VAL_EL2_SRC_W(val)                    REG_FLD_VAL(OVL_EL2_SRC_SIZE_FLD_EL2_SRC_W, (val))

#define OVL_EL2_OFFSET_VAL_EL2_YOFF(val)                       REG_FLD_VAL(OVL_EL2_OFFSET_FLD_EL2_YOFF, (val))
#define OVL_EL2_OFFSET_VAL_EL2_XOFF(val)                       REG_FLD_VAL(OVL_EL2_OFFSET_FLD_EL2_XOFF, (val))

#define OVL_EL2_PITCH_VAL_SURFL_EN(val)                        REG_FLD_VAL(OVL_EL2_PITCH_FLD_SURFL_EN, (val))
#define OVL_EL2_PITCH_VAL_EL2_BLEND_RND_SHT(val)               REG_FLD_VAL(OVL_EL2_PITCH_FLD_EL2_BLEND_RND_SHT, (val))
#define OVL_EL2_PITCH_VAL_EL2_SRGB_SEL_EXT2(val)               REG_FLD_VAL(OVL_EL2_PITCH_FLD_EL2_SRGB_SEL_EXT2, (val))
#define OVL_EL2_PITCH_VAL_EL2_CONST_BLD(val)                   REG_FLD_VAL(OVL_EL2_PITCH_FLD_EL2_CONST_BLD, (val))
#define OVL_EL2_PITCH_VAL_EL2_DRGB_SEL_EXT(val)                REG_FLD_VAL(OVL_EL2_PITCH_FLD_EL2_DRGB_SEL_EXT, (val))
#define OVL_EL2_PITCH_VAL_EL2_DA_SEL_EXT(val)                  REG_FLD_VAL(OVL_EL2_PITCH_FLD_EL2_DA_SEL_EXT, (val))
#define OVL_EL2_PITCH_VAL_EL2_SRGB_SEL_EXT(val)                REG_FLD_VAL(OVL_EL2_PITCH_FLD_EL2_SRGB_SEL_EXT, (val))
#define OVL_EL2_PITCH_VAL_EL2_SA_SEL_EXT(val)                  REG_FLD_VAL(OVL_EL2_PITCH_FLD_EL2_SA_SEL_EXT, (val))
#define OVL_EL2_PITCH_VAL_EL2_DRGB_SEL(val)                    REG_FLD_VAL(OVL_EL2_PITCH_FLD_EL2_DRGB_SEL, (val))
#define OVL_EL2_PITCH_VAL_EL2_DA_SEL(val)                      REG_FLD_VAL(OVL_EL2_PITCH_FLD_EL2_DA_SEL, (val))
#define OVL_EL2_PITCH_VAL_EL2_SRGB_SEL(val)                    REG_FLD_VAL(OVL_EL2_PITCH_FLD_EL2_SRGB_SEL, (val))
#define OVL_EL2_PITCH_VAL_EL2_SA_SEL(val)                      REG_FLD_VAL(OVL_EL2_PITCH_FLD_EL2_SA_SEL, (val))
#define OVL_EL2_PITCH_VAL_EL2_SRC_PITCH(val)                   REG_FLD_VAL(OVL_EL2_PITCH_FLD_EL2_SRC_PITCH, (val))

#define OVL_EL2_TILE_VAL_TILE_HORI_BLOCK_NUM(val)              REG_FLD_VAL(OVL_EL2_TILE_FLD_TILE_HORI_BLOCK_NUM, (val))
#define OVL_EL2_TILE_VAL_TILE_EN(val)                          REG_FLD_VAL(OVL_EL2_TILE_FLD_TILE_EN, (val))
#define OVL_EL2_TILE_VAL_TILE_WIDTH_SEL(val)                   REG_FLD_VAL(OVL_EL2_TILE_FLD_TILE_WIDTH_SEL, (val))
#define OVL_EL2_TILE_VAL_TILE_HEIGHT(val)                      REG_FLD_VAL(OVL_EL2_TILE_FLD_TILE_HEIGHT, (val))

#define OVL_EL2_CLIP_VAL_EL2_SRC_BOTTOM_CLIP(val)              REG_FLD_VAL(OVL_EL2_CLIP_FLD_EL2_SRC_BOTTOM_CLIP, (val))
#define OVL_EL2_CLIP_VAL_EL2_SRC_TOP_CLIP(val)                 REG_FLD_VAL(OVL_EL2_CLIP_FLD_EL2_SRC_TOP_CLIP, (val))
#define OVL_EL2_CLIP_VAL_EL2_SRC_RIGHT_CLIP(val)               REG_FLD_VAL(OVL_EL2_CLIP_FLD_EL2_SRC_RIGHT_CLIP, (val))
#define OVL_EL2_CLIP_VAL_EL2_SRC_LEFT_CLIP(val)                REG_FLD_VAL(OVL_EL2_CLIP_FLD_EL2_SRC_LEFT_CLIP, (val))

#define OVL_EL0_CLR_VAL_ALPHA(val)                             REG_FLD_VAL(OVL_EL0_CLR_FLD_ALPHA, (val))
#define OVL_EL0_CLR_VAL_RED(val)                               REG_FLD_VAL(OVL_EL0_CLR_FLD_RED, (val))
#define OVL_EL0_CLR_VAL_GREEN(val)                             REG_FLD_VAL(OVL_EL0_CLR_FLD_GREEN, (val))
#define OVL_EL0_CLR_VAL_BLUE(val)                              REG_FLD_VAL(OVL_EL0_CLR_FLD_BLUE, (val))

#define OVL_EL1_CLR_VAL_ALPHA(val)                             REG_FLD_VAL(OVL_EL1_CLR_FLD_ALPHA, (val))
#define OVL_EL1_CLR_VAL_RED(val)                               REG_FLD_VAL(OVL_EL1_CLR_FLD_RED, (val))
#define OVL_EL1_CLR_VAL_GREEN(val)                             REG_FLD_VAL(OVL_EL1_CLR_FLD_GREEN, (val))
#define OVL_EL1_CLR_VAL_BLUE(val)                              REG_FLD_VAL(OVL_EL1_CLR_FLD_BLUE, (val))

#define OVL_EL2_CLR_VAL_ALPHA(val)                             REG_FLD_VAL(OVL_EL2_CLR_FLD_ALPHA, (val))
#define OVL_EL2_CLR_VAL_RED(val)                               REG_FLD_VAL(OVL_EL2_CLR_FLD_RED, (val))
#define OVL_EL2_CLR_VAL_GREEN(val)                             REG_FLD_VAL(OVL_EL2_CLR_FLD_GREEN, (val))
#define OVL_EL2_CLR_VAL_BLUE(val)                              REG_FLD_VAL(OVL_EL2_CLR_FLD_BLUE, (val))

#define OVL_SBCH_VAL_L3_SBCH_CNST_EN(val)                      REG_FLD_VAL(OVL_SBCH_FLD_L3_SBCH_CNST_EN, (val))
#define OVL_SBCH_VAL_L3_SBCH_TRANS_EN(val)                     REG_FLD_VAL(OVL_SBCH_FLD_L3_SBCH_TRANS_EN, (val))
#define OVL_SBCH_VAL_L2_SBCH_CNST_EN(val)                      REG_FLD_VAL(OVL_SBCH_FLD_L2_SBCH_CNST_EN, (val))
#define OVL_SBCH_VAL_L2_SBCH_TRANS_EN(val)                     REG_FLD_VAL(OVL_SBCH_FLD_L2_SBCH_TRANS_EN, (val))
#define OVL_SBCH_VAL_L1_SBCH_CNST_EN(val)                      REG_FLD_VAL(OVL_SBCH_FLD_L1_SBCH_CNST_EN, (val))
#define OVL_SBCH_VAL_L1_SBCH_TRANS_EN(val)                     REG_FLD_VAL(OVL_SBCH_FLD_L1_SBCH_TRANS_EN, (val))
#define OVL_SBCH_VAL_L0_SBCH_CNST_EN(val)                      REG_FLD_VAL(OVL_SBCH_FLD_L0_SBCH_CNST_EN, (val))
#define OVL_SBCH_VAL_L0_SBCH_TRANS_EN(val)                     REG_FLD_VAL(OVL_SBCH_FLD_L0_SBCH_TRANS_EN, (val))
#define OVL_SBCH_VAL_L3_SBCH_UPDATE(val)                       REG_FLD_VAL(OVL_SBCH_FLD_L3_SBCH_UPDATE, (val))
#define OVL_SBCH_VAL_L2_SBCH_UPDATE(val)                       REG_FLD_VAL(OVL_SBCH_FLD_L2_SBCH_UPDATE, (val))
#define OVL_SBCH_VAL_L1_SBCH_UPDATE(val)                       REG_FLD_VAL(OVL_SBCH_FLD_L1_SBCH_UPDATE, (val))
#define OVL_SBCH_VAL_L0_SBCH_UPDATE(val)                       REG_FLD_VAL(OVL_SBCH_FLD_L0_SBCH_UPDATE, (val))

#define OVL_SBCH_EXT_VAL_EL2_SBCH_CNST_EN(val)                 REG_FLD_VAL(OVL_SBCH_EXT_FLD_EL2_SBCH_CNST_EN, (val))
#define OVL_SBCH_EXT_VAL_EL2_SBCH_TRANS_EN(val)                REG_FLD_VAL(OVL_SBCH_EXT_FLD_EL2_SBCH_TRANS_EN, (val))
#define OVL_SBCH_EXT_VAL_EL1_SBCH_CNST_EN(val)                 REG_FLD_VAL(OVL_SBCH_EXT_FLD_EL1_SBCH_CNST_EN, (val))
#define OVL_SBCH_EXT_VAL_EL1_SBCH_TRANS_EN(val)                REG_FLD_VAL(OVL_SBCH_EXT_FLD_EL1_SBCH_TRANS_EN, (val))
#define OVL_SBCH_EXT_VAL_EL0_SBCH_CNST_EN(val)                 REG_FLD_VAL(OVL_SBCH_EXT_FLD_EL0_SBCH_CNST_EN, (val))
#define OVL_SBCH_EXT_VAL_EL0_SBCH_TRANS_EN(val)                REG_FLD_VAL(OVL_SBCH_EXT_FLD_EL0_SBCH_TRANS_EN, (val))
#define OVL_SBCH_EXT_VAL_EL2_SBCH_UPDATE(val)                  REG_FLD_VAL(OVL_SBCH_EXT_FLD_EL2_SBCH_UPDATE, (val))
#define OVL_SBCH_EXT_VAL_EL1_SBCH_UPDATE(val)                  REG_FLD_VAL(OVL_SBCH_EXT_FLD_EL1_SBCH_UPDATE, (val))
#define OVL_SBCH_EXT_VAL_EL0_SBCH_UPDATE(val)                  REG_FLD_VAL(OVL_SBCH_EXT_FLD_EL0_SBCH_UPDATE, (val))

#define OVL_SBCH_CON_VAL_EL2_SBCH_TRANS_INVALID(val)           REG_FLD_VAL(OVL_SBCH_CON_FLD_EL2_SBCH_TRANS_INVALID, (val))
#define OVL_SBCH_CON_VAL_EL1_SBCH_TRANS_INVALID(val)           REG_FLD_VAL(OVL_SBCH_CON_FLD_EL1_SBCH_TRANS_INVALID, (val))
#define OVL_SBCH_CON_VAL_EL0_SBCH_TRANS_INVALID(val)           REG_FLD_VAL(OVL_SBCH_CON_FLD_EL0_SBCH_TRANS_INVALID, (val))
#define OVL_SBCH_CON_VAL_L3_SBCH_TRANS_INVALID(val)            REG_FLD_VAL(OVL_SBCH_CON_FLD_L3_SBCH_TRANS_INVALID, (val))
#define OVL_SBCH_CON_VAL_L2_SBCH_TRANS_INVALID(val)            REG_FLD_VAL(OVL_SBCH_CON_FLD_L2_SBCH_TRANS_INVALID, (val))
#define OVL_SBCH_CON_VAL_L1_SBCH_TRANS_INVALID(val)            REG_FLD_VAL(OVL_SBCH_CON_FLD_L1_SBCH_TRANS_INVALID, (val))
#define OVL_SBCH_CON_VAL_L0_SBCH_TRANS_INVALID(val)            REG_FLD_VAL(OVL_SBCH_CON_FLD_L0_SBCH_TRANS_INVALID, (val))

#define OVL_L0_ADDR_VAL_L0_ADDR(val)                           REG_FLD_VAL(OVL_L0_ADDR_FLD_L0_ADDR, (val))

#define OVL_L1_ADDR_VAL_L1_ADDR(val)                           REG_FLD_VAL(OVL_L1_ADDR_FLD_L1_ADDR, (val))

#define OVL_L2_ADDR_VAL_L2_ADDR(val)                           REG_FLD_VAL(OVL_L2_ADDR_FLD_L2_ADDR, (val))

#define OVL_L3_ADDR_VAL_L3_ADDR(val)                           REG_FLD_VAL(OVL_L3_ADDR_FLD_L3_ADDR, (val))

#define OVL_EL0_ADDR_VAL_EL0_ADDR(val)                         REG_FLD_VAL(OVL_EL0_ADDR_FLD_EL0_ADDR, (val))

#define OVL_EL1_ADDR_VAL_EL1_ADDR(val)                         REG_FLD_VAL(OVL_EL1_ADDR_FLD_EL1_ADDR, (val))

#define OVL_EL2_ADDR_VAL_EL2_ADDR(val)                         REG_FLD_VAL(OVL_EL2_ADDR_FLD_EL2_ADDR, (val))

#define OVL_SECURE_VAL_L3_SECURE(val)                          REG_FLD_VAL(OVL_SECURE_FLD_L3_SECURE, (val))
#define OVL_SECURE_VAL_L2_SECURE(val)                          REG_FLD_VAL(OVL_SECURE_FLD_L2_SECURE, (val))
#define OVL_SECURE_VAL_L1_SECURE(val)                          REG_FLD_VAL(OVL_SECURE_FLD_L1_SECURE, (val))
#define OVL_SECURE_VAL_L0_SECURE(val)                          REG_FLD_VAL(OVL_SECURE_FLD_L0_SECURE, (val))

#ifdef __cplusplus
}
#endif

#endif // __DISP_OVL0_REGS_H__
