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
#define DISP_INDEX_OFFSET (DISP_OVL0_2L_BASE - OVL0_BASE) /* used by ovl */
#define DISP_RDMA_INDEX_OFFSET (DISP_RDMA1_BASE - DISP_RDMA0_BASE) /* used by rdma */

#define DISPSYS_OVL0_BASE               OVL0_BASE
#define DISPSYS_RDMA0_BASE              DISP_RDMA0_BASE
#define DISPSYS_COLOR0_BASE             COLOR0_BASE
#define DISPSYS_AAL_BASE                DISP_AAL_BASE
#define DISPSYS_GAMMA_BASE              DISP_GAMMA_BASE
#define DISPSYS_SPLIT0_BASE             DISP_SPLIT0_BASE
#define DISPSYS_DSI0_BASE               DSI0_BASE
#define DISPSYS_MIPITX0_BASE            MIPI_TX_CONFIG_BASE
#define DISPSYS_MIPITX1_BASE            MIPI_TX_CONFIG_BASE /* cervino no use */
#define DISPSYS_DITHER_BASE             DITHER_BASE
#define DISPSYS_DSI1_BASE               DSI1_BASE
#define DISPSYS_PWM0_BASE               DISP_PWM0_BASE
#define DISPSYS_MUTEX_BASE              MM_MUTEX_BASE
#define DISPSYS_SMI_LARB0_BASE          SMI_LARB0_BASE
#define DISPSYS_SMI_LARB1_BASE          SMI_LARB1_BASE
#define DISPSYS_SMI_COMMON_BASE         SMI_COMMON_BASE
#define DISPSYS_CCORR_BASE              CCORR_BASE
#define DISPSYS_CONFIG_BASE             MMSYS_CONFIG_BASE


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


/* AAL */
#define DISP_AAL_EN                             (DISPSYS_AAL_BASE + 0x000)
#define DISP_AAL_CFG                            (DISPSYS_AAL_BASE + 0x020)
#define DISP_AAL_IN_CNT                         (DISPSYS_AAL_BASE + 0x024)
#define DISP_AAL_OUT_CNT                        (DISPSYS_AAL_BASE + 0x028)

#define CFG_FLD_RELAY_MODE                      REG_FLD(1, 0)
#define DISP_AAL_SIZE                           (DISPSYS_AAL_BASE + 0x030)
#define SIZE_FLD_HSIZE                          REG_FLD(13, 16)
#define SIZE_FLD_VSIZE                          REG_FLD(13, 0)
#define DISP_REG_AAL_SHADOW_CTRL		(DISPSYS_AAL_BASE + 0x0B0)
#define FLD_AAL_BYPASS_SHADOW			REG_FLD(1, 0)
#define FLD_AAL_READ_WRK_REG			REG_FLD(1, 2)


/* PWM */
#define DISP_PWM_EN_OFF                         (0x00)
#define DISP_PWM_COMMIT_OFF                     (0x0C)
#define DISP_PWM_CON_0_OFF                      (0x18)
#define DISP_PWM_CON_1_OFF                      (0x1C)


/* COLOR */
#define DISP_COLOR_CFG_MAIN             (DISPSYS_COLOR0_BASE + 0x400)
#define DISP_COLOR_PXL_CNT_MAIN         (DISPSYS_COLOR0_BASE + 0x404)
#define DISP_COLOR_LINE_CNT_MAIN        (DISPSYS_COLOR0_BASE + 0x408)
#define DISP_COLOR_START                (DISPSYS_COLOR0_BASE + 0xC00)
#define DISP_COLOR_INTERNAL_IP_WIDTH    (DISPSYS_COLOR0_BASE + 0xC50)
#define DISP_COLOR_INTERNAL_IP_HEIGHT   (DISPSYS_COLOR0_BASE + 0xC54)
#define DISP_COLOR_CM1_EN               (DISPSYS_COLOR0_BASE + 0xC60)
#define DISP_COLOR_CM2_EN               (DISPSYS_COLOR0_BASE + 0xCA0)
#define DISP_REG_COLOR_SHADOW_CTRL		(DISPSYS_COLOR0_BASE + 0xCB0)
#define FLD_COLOR_BYPASS_SHADOW			REG_FLD(1, 0)
#define FLD_COLOR_READ_WRK_REG			REG_FLD(1, 2)


/* CCORR */
#define DISP_REG_CCORR_EN               (DISPSYS_CCORR_BASE + 0x000)
#define DISP_REG_CCORR_CFG              (DISPSYS_CCORR_BASE + 0x020)
#define DISP_REG_CCORR_IN_CNT           (DISPSYS_CCORR_BASE + 0x024)
#define DISP_REG_CCORR_OUT_CNT          (DISPSYS_CCORR_BASE + 0x028)
#define DISP_REG_CCORR_SIZE             (DISPSYS_CCORR_BASE + 0x030)
#define DISP_REG_CCORR_SHADOW_CTRL		(DISPSYS_CCORR_BASE + 0x0A0)
#define FLD_CCORR_BYPASS_SHADOW			REG_FLD(1, 2)
#define FLD_CCORR_READ_WRK_REG			REG_FLD(1, 0)



/* GAMMA */
#define DISP_REG_GAMMA_EN                               (DISPSYS_GAMMA_BASE + 0x000)
#define DISP_REG_GAMMA_CFG                               (DISPSYS_GAMMA_BASE + 0x020)
#define DISP_REG_GAMMA_SIZE                             (DISPSYS_GAMMA_BASE + 0x030)
#define DISP_REG_GAMMA_INPUT_COUNT					    (DISPSYS_GAMMA_BASE + 0x024)
#define DISP_REG_GAMMA_OUTPUT_COUNT					    (DISPSYS_GAMMA_BASE + 0x028)
#define DISP_REG_GAMMA_SHADOW_CTRL					    (DISPSYS_GAMMA_BASE + 0x034)
#define FLD_GAMMA_BYPASS_SHADOW									REG_FLD(1, 1)
#define FLD_GAMMA_READ_WRK_REG									REG_FLD(1, 2)


/* Dither */
#define DISP_REG_DITHER_EN                                        (DISPSYS_DITHER_BASE + 0x000)
#define DISP_REG_DITHER_CFG                                       (DISPSYS_DITHER_BASE + 0x020)
#define DISP_REG_DITHER_IN_CNT                                    (DISPSYS_DITHER_BASE + 0x024)
#define DISP_REG_DITHER_OUT_CNT                                   (DISPSYS_DITHER_BASE + 0x028)
#define DISP_REG_DITHER_SIZE                                      (DISPSYS_DITHER_BASE + 0x030)
#define DISP_REG_DITHER_0                                      (DISPSYS_DITHER_BASE + 0x100)
#define FLD_DITHER_BYPASS_SHADOW									REG_FLD(1, 0)
#define FLD_DITHER_READ_WRK_REG										REG_FLD(1, 2)



/* RDMA */
#define DISP_REG_RDMA_INT_ENABLE				(DISPSYS_RDMA0_BASE+0x000)
#define DISP_REG_RDMA_INT_STATUS				(DISPSYS_RDMA0_BASE+0x004)
#define DISP_REG_RDMA_GLOBAL_CON				(DISPSYS_RDMA0_BASE+0x010)
#define DISP_REG_RDMA_SIZE_CON_0                (DISPSYS_RDMA0_BASE+0x014)
#define DISP_REG_RDMA_SIZE_CON_1                (DISPSYS_RDMA0_BASE+0x018)
#define DISP_REG_RDMA_TARGET_LINE             	(DISPSYS_RDMA0_BASE+0x01C)
#define DISP_REG_RDMA_MEM_CON                   (DISPSYS_RDMA0_BASE+0x024)
#define DISP_REG_RDMA_MEM_SRC_PITCH				(DISPSYS_RDMA0_BASE+0x02C)
#define DISP_REG_RDMA_MEM_GMC_SETTING_0			(DISPSYS_RDMA0_BASE+0x030)
#define DISP_REG_RDMA_MEM_GMC_SETTING_1			(DISPSYS_RDMA0_BASE+0x034)
#define DISP_REG_RDMA_MEM_SLOW_CON				(DISPSYS_RDMA0_BASE+0x038)
#define DISP_REG_RDMA_MEM_GMC_SETTING_2			(DISPSYS_RDMA0_BASE+0x03c)
#define DISP_REG_RDMA_FIFO_CON                  (DISPSYS_RDMA0_BASE+0x040)
#define DISP_REG_RDMA_FIFO_LOG                  (DISPSYS_RDMA0_BASE+0x044)
#define DISP_REG_RDMA_C00                       (DISPSYS_RDMA0_BASE+0x054)
#define DISP_REG_RDMA_C01                       (DISPSYS_RDMA0_BASE+0x058)
#define DISP_REG_RDMA_C02                       (DISPSYS_RDMA0_BASE+0x05C)
#define DISP_REG_RDMA_C10                       (DISPSYS_RDMA0_BASE+0x060)
#define DISP_REG_RDMA_C11                       (DISPSYS_RDMA0_BASE+0x064)
#define DISP_REG_RDMA_C12                       (DISPSYS_RDMA0_BASE+0x068)
#define DISP_REG_RDMA_C20                       (DISPSYS_RDMA0_BASE+0x06C)
#define DISP_REG_RDMA_C21                       (DISPSYS_RDMA0_BASE+0x070)
#define DISP_REG_RDMA_C22                       (DISPSYS_RDMA0_BASE+0x074)
#define DISP_REG_RDMA_PRE_ADD_0					(DISPSYS_RDMA0_BASE+0x078)
#define DISP_REG_RDMA_PRE_ADD_1                 (DISPSYS_RDMA0_BASE+0x07C)
#define DISP_REG_RDMA_PRE_ADD_2                 (DISPSYS_RDMA0_BASE+0x080)
#define DISP_REG_RDMA_POST_ADD_0				(DISPSYS_RDMA0_BASE+0x084)
#define DISP_REG_RDMA_POST_ADD_1                (DISPSYS_RDMA0_BASE+0x088)
#define DISP_REG_RDMA_POST_ADD_2                (DISPSYS_RDMA0_BASE+0x08C)
#define DISP_REG_RDMA_DUMMY                     (DISPSYS_RDMA0_BASE+0x090)
#define DISP_REG_RDMA_DEBUG_OUT_SEL             (DISPSYS_RDMA0_BASE+0x094)
#define DISP_REG_RDMA_MEM_START_ADDR			(DISPSYS_RDMA0_BASE+0xf00)
#define DISP_REG_RDMA_BG_CON_0                  (DISPSYS_RDMA0_BASE+0x0a0)
#define DISP_REG_RDMA_BG_CON_1                  (DISPSYS_RDMA0_BASE+0x0a4)
#define DISP_REG_RDMA_THRESHOLD_FOR_SODI        (DISPSYS_RDMA0_BASE+0x0a8)
#define DISP_REG_RDMA_THRESHOLD_FOR_DVFS		(DISPSYS_RDMA0_BASE+0x0ac)
#define DISP_REG_RDMA_SRAM_SEL					(DISPSYS_RDMA0_BASE+0x0b0)
#define DISP_REG_RDMA_STALL_CG_CON				(DISPSYS_RDMA0_BASE+0x0b4)
#define DISP_REG_RDMA_DRAM_CON					(DISPSYS_RDMA0_BASE+0x0c0)
#define DISP_REG_RDMA_DVFS_SETTING_PRE			(DISPSYS_RDMA0_BASE+0x0d0)
#define DISP_REG_RDMA_DVFS_SETTING_ULTRA		(DISPSYS_RDMA0_BASE+0x0d4)

#define DISP_REG_RDMA_MEM_GMC_SETTING_3 		(DISPSYS_RDMA0_BASE+0x0e8)

#define DISP_REG_RDMA_IN_P_CNT                  (DISPSYS_RDMA0_BASE+0x0f0)
#define DISP_REG_RDMA_IN_LINE_CNT               (DISPSYS_RDMA0_BASE+0x0f4)
#define DISP_REG_RDMA_OUT_P_CNT                 (DISPSYS_RDMA0_BASE+0x0f8)
#define DISP_REG_RDMA_OUT_LINE_CNT              (DISPSYS_RDMA0_BASE+0x0fc)

#define DISP_REG_RDMA_DBG_OUT					(DISPSYS_RDMA0_BASE+0x100)


#define INT_ENABLE_FLD_TARGET_LINE_INT_EN		    REG_FLD(1, 5)
#define INT_ENABLE_FLD_FIFO_UNDERFLOW_INT_EN		        REG_FLD(1, 4)
#define INT_ENABLE_FLD_EOF_ABNORMAL_INT_EN		    REG_FLD(1, 3)
#define INT_ENABLE_FLD_FRAME_END_INT_EN				    REG_FLD(1, 2)
#define INT_ENABLE_FLD_FRAME_START_INT_EN			    REG_FLD(1, 1)
#define INT_ENABLE_FLD_REG_UPDATE_INT_EN			    REG_FLD(1, 0)
#define INT_STATUS_FLD_FIFO_EMPTY_INT_FLAG		        REG_FLD(1, 6)
#define INT_STATUS_FLD_TARGET_LINE_INT_FLAG		        REG_FLD(1, 5)
#define INT_STATUS_FLD_FIFO_UNDERFLOW_INT_FLAG		            REG_FLD(1, 4)
#define INT_STATUS_FLD_EOF_ABNORMAL_INT_FLAG		        REG_FLD(1, 3)
#define INT_STATUS_FLD_FRAME_END_INT_FLAG			    REG_FLD(1, 2)
#define INT_STATUS_FLD_FRAME_START_INT_FLAG		        REG_FLD(1, 1)
#define INT_STATUS_FLD_REG_UPDATE_INT_FLAG		    REG_FLD(1, 0)
#define GLOBAL_CON_FLD_SMI_BUSY					REG_FLD(1, 12)
#define GLOBAL_CON_FLD_RESET_STATE				REG_FLD(3, 8)
#define GLOBAL_CON_FLD_SOFT_RESET				REG_FLD(1, 4)
#define GLOBAL_CON_FLD_MODE_SEL					REG_FLD(1, 1)
#define GLOBAL_CON_FLD_ENGINE_EN				REG_FLD(1, 0)
#define SIZE_CON_0_FLD_MATRIX_INT_MTX_SEL			    REG_FLD(4, 20)
#define SIZE_CON_0_FLD_MATRIX_WIDE_GAMUT_EN		        REG_FLD(1, 18)
#define SIZE_CON_0_FLD_MATRIX_ENABLE				REG_FLD(1, 17)
#define SIZE_CON_0_FLD_MATRIX_EXT_MTX_EN		    REG_FLD(1, 16)
#define SIZE_CON_0_FLD_OUTPUT_FRAME_WIDTH		        REG_FLD(13, 0)
#define SIZE_CON_1_FLD_OUTPUT_FRAME_HEIGHT		        REG_FLD(20, 0)
#define TARGET_LINE_FLD_TARGET_LINE				REG_FLD(20, 0)
#define MEM_CON_FLD_MEM_MODE_HORI_BLOCK_NUM		            REG_FLD(8, 24)
#define MEM_CON_FLD_MEM_MODE_INPUT_COSITE		            REG_FLD(1, 13)
#define MEM_CON_FLD_MEM_MODE_INPUT_UPSAMPLE		        REG_FLD(1, 12)
#define MEM_CON_FLD_MEM_MODE_INPUT_SWAP				        REG_FLD(1, 8)
#define MEM_CON_FLD_MEM_MODE_INPUT_FORMAT		            REG_FLD(4, 4)
#define MEM_CON_FLD_MEM_MODE_TILE_INTERLACE		        REG_FLD(1, 1)
#define MEM_CON_FLD_MEM_MODE_TILE_EN                            REG_FLD(1, 0)
#define MEM_SRC_PITCH_FLD_MEM_MODE_SRC_PITCH		        REG_FLD(16, 0)
#define MEM_GMC_SETTING_0_FLD_PRE_ULTRA_THRESHOLD_LOW                    REG_FLD(12, 0)
#define MEM_GMC_SETTING_0_FLD_PRE_ULTRA_THRESHOLD_HIGH                   REG_FLD(12,16)
#define MEM_GMC_SETTING_0_FLD_RG_VALID_THRESHOLD_FORCE_PREULTRA          REG_FLD( 1,30)
#define MEM_GMC_SETTING_0_FLD_SETTING_0__RG_VDE_FORCE_PREULTRA           REG_FLD( 1,31)
#define MEM_SLOW_CON_FLD_MEM_MODE_SLOW_COUNT			REG_FLD(16, 16)
#define MEM_SLOW_CON_FLD_MEM_MODE_SLOW_EN			REG_FLD(1, 0)
#define MEM_GMC_SETTING_2_FLD_ISSUE_REQ_THRESHOLD		REG_FLD(12, 0)
#define FIFO_CON_FLD_FIFO_UNDERFLOW_EN				REG_FLD(1, 31)
#define FIFO_CON_FLD_FIFO_PSEUDO_SIZE				REG_FLD(12, 16)
#define FIFO_CON_FLD_OUTPUT_VALID_THRESHOLD_PER_LINE REG_FLD(1, 15)
#define FIFO_CON_FLD_OUTPUT_VALID_FIFO_THRESHOLD		REG_FLD(12, 0)
#define FIFO_LOG_FLD_RDMA_FIFO_LOG					REG_FLD(12, 0)
#define C00_FLD_DISP_RDMA_C00					REG_FLD(13, 0)
#define C01_FLD_DISP_RDMA_C01                                   REG_FLD(13, 0)
#define C02_FLD_DISP_RDMA_C02					REG_FLD(13, 0)
#define C10_FLD_DISP_RDMA_C10					REG_FLD(13, 0)
#define C11_FLD_DISP_RDMA_C11					REG_FLD(13, 0)
#define C12_FLD_DISP_RDMA_C12					REG_FLD(13, 0)
#define C20_FLD_DISP_RDMA_C20					REG_FLD(13, 0)
#define C21_FLD_DISP_RDMA_C21					REG_FLD(13, 0)
#define C22_FLD_DISP_RDMA_C22					REG_FLD(13, 0)
#define PRE_ADD_0_FLD_DISP_RDMA_PRE_ADD_0				    REG_FLD(9, 0)
#define PRE_ADD_1_FLD_DISP_RDMA_PRE_ADD_1				    REG_FLD(9, 0)
#define PRE_ADD_2_FLD_DISP_RDMA_PRE_ADD_2				    REG_FLD(9, 0)
#define POST_ADD_0_FLD_DISP_RDMA_POST_ADD_0				    REG_FLD(9, 0)
#define POST_ADD_1_FLD_DISP_RDMA_POST_ADD_1			        REG_FLD(9, 0)
#define POST_ADD_2_FLD_DISP_RDMA_POST_ADD_2			        REG_FLD(9, 0)
#define DUMMY_FLD_DISP_RDMA_DUMMY				REG_FLD(32, 0)
#define DEBUG_OUT_SEL_FLD_DISP_RDMA_DEBUG_OUT_SEL	        REG_FLD(4, 0)
#define MEM_START_ADDR_FLD_MEM_MODE_START_ADDR		        REG_FLD(32, 0)
#define RDMA_BG_CON_0_LEFT					REG_FLD(13, 0)
#define RDMA_BG_CON_0_RIGHT					REG_FLD(13, 16)
#define RDMA_BG_CON_1_TOP					REG_FLD(13, 0)
#define RDMA_BG_CON_1_BOTTOM				REG_FLD(13, 16)
#define MEM_GMC_SETTING_3_FLD_URGENT_THRESHOLD_LOW 	REG_FLD(12, 0)
#define MEM_GMC_SETTING_3_FLD_URGENT_THRESHOLD_HIGH REG_FLD(12, 16)

/* ------------------------------------------------------------- */

#define REG_FLD_GET DISP_REG_GET_FIELD
#define REG_FLD_SET DISP_CPU_REG_SET_FIELD


#include <platform/ddp_reg_mmsys.h>
#include <platform/ddp_reg_split.h>
#include <platform/ddp_reg_dsi.h>
#include <platform/ddp_reg_mutex.h>
#include <platform/ddp_reg_ovl.h>
#include <platform/ddp_reg_mipi.h>

#endif
