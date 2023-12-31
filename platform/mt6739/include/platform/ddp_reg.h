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

#ifndef _DDP_REG_H_
#define _DDP_REG_H_

#include <platform/mt_typedefs.h>
#include <platform/sync_write.h>

#include <platform/mt_reg_base.h>

typedef void * cmdqRecHandle;


//TDODO: get base reg addr from system header
#define DISP_INDEX_OFFSET (0) /* used by ovl */
#define DISP_RDMA_INDEX_OFFSET (0) /* used by rdma */

#define DISPSYS_OVL0_BASE               DISP_OVL0_BASE
#define DISPSYS_WDMA0_BASE              DISP_WDMA0_BASE
#define DISPSYS_RDMA0_BASE              DISP_RDMA0_BASE
#define DISPSYS_MUTEX_BASE              DISP_MM_MUTEX_BASE
#define DISPSYS_DSI0_BASE               DISP_DSI0_BASE
#define DISPSYS_DBI_BASE				DISP_DBI0_BASE
#define DISPSYS_DPI_BASE				(0)

#define DISPSYS_MIPITX0_BASE			MIPI_TX0_BASE
#define DISPSYS_CONFIG_BASE				MMSYS_CONFIG_BASE


#define DISPSYS_COLOR0_BASE             DISP_COLOR0_BASE
#define DISPSYS_CCORR0_BASE             DISP_CCORR0_BASE
#define DISPSYS_AAL0_BASE               DISP_AAL0_BASE
#define DISPSYS_GAMMA0_BASE             DISP_GAMMA0_BASE
#define DISPSYS_DITHER0_BASE            DISP_DITHER0_BASE
#define DISPSYS_PWM0_BASE               DISP_PWM0_BASE


#define DISPSYS_SMI_LARB0_BASE          SMI_LARB0_BASE
#define DISPSYS_SMI_LARB1_BASE          SMI_LARB1_BASE
#define DISPSYS_SMI_COMMON_BASE         SMI_COMMON_BASE



// ---------------------------------------------------------------------------
//  Type Casting
// ---------------------------------------------------------------------------

#define AS_INT32(x)     (*(INT32 *)(x))
#define AS_INT16(x)     (*(INT16 *)(x))
#define AS_INT8(x)      (*(INT8  *)(x))

#define AS_UINT32(x)    (*(UINT32 *)(x))
#define AS_UINT16(x)    (*(UINT16 *)(x))
#define AS_UINT8(x)     (*(UINT8  *)(x))


// ---------------------------------------------------------------------------
//  Register Manipulations
// ---------------------------------------------------------------------------
/*
#define READ_REGISTER_UINT32(reg) \
    (*(volatile UINT32 * const)(reg))

#define WRITE_REGISTER_UINT32(reg, val) \
    (*(volatile UINT32 * const)(reg)) = (val)

#define READ_REGISTER_UINT16(reg) \
    (*(volatile UINT16 * const)(reg))

#define WRITE_REGISTER_UINT16(reg, val) \
    (*(volatile UINT16 * const)(reg)) = (val)

#define READ_REGISTER_UINT8(reg) \
    (*(volatile UINT8 * const)(reg))

#define WRITE_REGISTER_UINT8(reg, val) \
    (*(volatile UINT8 * const)(reg)) = (val)
*/

// ---------------------------------------------------------------------------
//  Register Field Access
// ---------------------------------------------------------------------------

#define REG_FLD(width, shift) \
	((unsigned int)((((width) & 0xFF) << 16) | ((shift) & 0xFF)))

#define REG_FLD_MSB_LSB(msb, lsb) REG_FLD((msb) - (lsb) + 1, (lsb))

#define REG_FLD_WIDTH(field) \
	((unsigned int)(((field) >> 16) & 0xFF))

#define REG_FLD_SHIFT(field) \
	((unsigned int)((field) & 0xFF))

#define REG_FLD_MASK(field) \
	((unsigned int)((1ULL << REG_FLD_WIDTH(field)) - 1) << REG_FLD_SHIFT(field))

#define REG_FLD_VAL(field, val) \
	(((val) << REG_FLD_SHIFT(field)) & REG_FLD_MASK(field))

#define REG_FLD_VAL_GET(field, regval) \
	(((regval) & REG_FLD_MASK(field)) >> REG_FLD_SHIFT(field))


#define DISP_REG_GET(reg32) (*(volatile unsigned int*)(reg32))
#define DISP_REG_GET_FIELD(field, reg32) ((*(volatile unsigned int*)(reg32) & REG_FLD_MASK(field)) >> REG_FLD_SHIFT(field))

/* polling register until masked bit is 1 */
#define DDP_REG_POLLING(reg32, mask) \
	do { \
		while (!((DISP_REG_GET(reg32))&mask))\
			; \
	} while (0)

/* Polling register until masked bit is 0 */
#define DDP_REG_POLLING_NEG(reg32, mask) \
	do { \
		while ((DISP_REG_GET(reg32))&mask)\
			; \
	} while (0)

#define DISP_CPU_REG_SET(reg32, val) mt_reg_sync_writel(val, (volatile unsigned int*)(reg32))
#define DISP_CPU_REG_SET_FIELD(field, reg32, val)  \
    do {                                \
           mt_reg_sync_writel( (*(volatile unsigned int*)(reg32) & ~REG_FLD_MASK(field))|REG_FLD_VAL((field), (val)), reg32);  \
    } while (0)

#define DISP_REG_MASK(handle, reg32, val, mask)     \
        do { \
            mt_reg_sync_writel((unsigned int)(INREG32(reg32)&~(mask))|(val),(volatile unsigned long*)(reg32) );\
        } while (0)

#define DISP_REG_SET(handle,reg32, val) \
        do { \
            mt_reg_sync_writel(val, (volatile unsigned int*)(reg32));\
        } while (0)


#define DISP_REG_SET_FIELD(handle,field, reg32, val)  \
        do {  \
             mt_reg_sync_writel( (*(volatile unsigned int*)(reg32) & ~REG_FLD_MASK(field))|REG_FLD_VAL((field), (val)), reg32);  \
        } while (0)

#define DISP_REG_CMDQ_POLLING(handle, reg32, val, mask) \
	do { \
		while ((DISP_REG_GET(reg32) & (mask)) != ((val) & (mask)))\
			; \
	} while (0)


#include <platform/ddp_reg_mmsys.h>
#include <platform/ddp_reg_mutex.h>
#include <platform/ddp_reg_ovl.h>
#include <platform/ddp_reg_dsi.h>
#include <platform/ddp_reg_mipi.h>
#include <platform/ddp_reg_dma.h>
#include <platform/ddp_reg_pq.h>

#endif
