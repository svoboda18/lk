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

#ifndef _MT_SCP_H_
#define _MT_SCP_H_

#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */

/*platform dependent address*/
#ifdef MTK_MINIMUM_SCP_DRAM_SIZE
#define SCP_DRAM_SIZE       0x00180000  // mblock_reserve requires max 1.5 MB
#else
#define SCP_DRAM_SIZE       0x00600000  // mblock_reserve requires max 6 MB(1MB platform image, 5MB overlay)
#endif  // MTK_MINIMUM_SCP_DRAM_SIZE
#define SCP_DRAM_ALIGN      0x00100000  // due to l1c align = 1MB

#define DRAM_ADDR_MAX       0x9FFFFFFF  // max address can SCP remap
#define DRAM_4GB_MAX        0xFFFFFFFF
#define DRAM_4GB_OFFSET     0x40000000
#define SCP_EMI_REGION      26
#define ENABLE_SCP_EMI_PROTECTION       (1)

#define SCP_SRAM_BASE            0x10500000
#define SCP_SRAM_SIZE            0x00040000
#define SCP_MAX_SRAM_SIZE        SCP_SRAM_SIZE

#define SCP_CFG_BASE             (SCP_SRAM_BASE + 0xC0000)
#define SCP_AP_RESOURCE              (SCP_CFG_BASE + 0x0004)
#define SCP_BUS_RESOURCE             (SCP_CFG_BASE + 0x0008)

#define SCP_A_DEBUG_SP_REG           (SCP_CFG_BASE + 0x00A8)
#define SCP_A_DEBUG_LR_REG           (SCP_CFG_BASE + 0x00AC)
#define SCP_A_DEBUG_PSP_REG          (SCP_CFG_BASE + 0x00B0)
#define SCP_A_DEBUG_PC_REG           (SCP_CFG_BASE + 0x00B4)
#define SCP_WDT_SP                   (SCP_CFG_BASE + 0x00B8)
#define SCP_WDT_LR                   (SCP_CFG_BASE + 0x00BC)
#define SCP_WDT_PSP                  (SCP_CFG_BASE + 0x00C0)
#define SCP_WDT_PC                   (SCP_CFG_BASE + 0x00C4)
#define SCP_SLP_PROTECT_CFG          (SCP_CFG_BASE + 0x00C8)
#define SCP_SYS_CTRL                 (SCP_CFG_BASE + 0x00E4)
#define AHB_SLICE_POST_WT   1
#define AUTO_DDREN_BIT      18
#define DDREN_FIX_VALUE_BIT 28
#define BYPASS_P_L1C      30
#define BYPASS_D_L1C      31

#define BUS_QOS                     (SCP_CFG_BASE + 0xE8)
#define AXI_AWULTRA    0
#define AXI_ARULTRA    6
#define SCP_BUS_CTRL   (SCP_CFG_BASE + 0x00F0)
	#define dbg_irq_info_sel_shift 26
	#define dbg_irq_info_sel_mask (0x3 << 26)
#define SCP_DEBUG_ADDR_S2R       (SCP_CFG_BASE + 0x00F4)
#define SCP_DEBUG_ADDR_DMA       (SCP_CFG_BASE + 0x00F8)
#define SCP_DEBUG_ADDR_SPI0      (SCP_CFG_BASE + 0x00FC)
#define SCP_DEBUG_ADDR_SPI1      (SCP_CFG_BASE + 0x0100)
#define SCP_DEBUG_ADDR_SPI2      (SCP_CFG_BASE + 0x0104)
#define SCP_DEBUG_BUS_STATUS     (SCP_CFG_BASE + 0x0110)

#define SCP_CPU_SLEEP_STATUS         (SCP_CFG_BASE + 0x0114)
#define L1C_REMAP_CFG0               (SCP_CFG_BASE + 0x12C)
#define L1C_SHIFT_MASK           0xfff00000
#define L1C_ALIGN                0x00100000
#define L1C_EXT_ADDR_SHIFT       20
#define L1C_REMAP_CFG1               (SCP_CFG_BASE + 0x130)
#define L1C_REMAP_CFG2               (SCP_CFG_BASE + 0x134)
#define L1C_REMAP_CFG3               (SCP_CFG_BASE + 0x138)
#define L1C_REMAP_OTHER              (SCP_CFG_BASE + 0x13C)
#define SCP_DEBUG_IRQ_INFO       (SCP_CFG_BASE + 0x0160)

#define SCP_SRAM_PDN             (SCP_CFG_BASE + 0x402c)
#define SCP_CLK_SEL              (SCP_CFG_BASE + 0x4000)
#define SCP_CLK_SW_SEL           (SCP_CFG_BASE + 0x4000)
#define SCP_CLK_EN               (SCP_CFG_BASE + 0x4004)
#define SCP_CLK_ENABLE           (SCP_CFG_BASE + 0x4004)
#define SCP_CFGREG_SW_RSTN       (SCP_CFG_BASE + 0x0000)
#define SCP_SLP_EN               (SCP_CFG_BASE + 0x4020)
#define SCP_CLR_CLK_CG           (SCP_CFG_BASE + 0x4058)
#define L1C_I_CTRL_CG   23
#define L1C_D_CTRL_CG   24
#define SCP_CLK_HIGH_CORE_CG     (SCP_CFG_BASE + 0x405C)
#define CLK_CTRL_L1_SRAM_PD       (SCP_CFG_BASE + 0x4080)
#define CLK_CTRL_TCM_TAIL_SRAM_PD (SCP_CFG_BASE + 0x4094)
#define L1C_IL1C 0
#define L1C_DL1C 1

/* #define SCP_SYS_INFRA_MON        (SCP_SCPSYS_BASE + 0x0D50) */

#define L1C_BASE            (SCP_SRAM_BASE + 0xD4000)
#define L1C_SEL(x) ((L1C_REGISTER_T *)(L1C_BASE+x*0x3000))

/* L1C_CON register definitions
 */
#define L1C_CON_MCEN_OFFSET                   (0)
#define L1C_CON_MCEN_MASK                     (1<<L1C_CON_MCEN_OFFSET)
#define L1C_CON_CNTEN0_OFFSET                 (2)
#define L1C_CON_CNTEN0_MASK                   (1<<L1C_CON_CNTEN0_OFFSET)
#define L1C_CON_CNTEN1_OFFSET                 (3)
#define L1C_CON_CNTEN1_MASK                   (1<<L1C_CON_CNTEN1_OFFSET)
#define L1C_CON_L1CSIZE_OFFSET              (8)
#define L1C_CON_L1CSIZE_MASK                (3<<L1C_CON_L1CSIZE_OFFSET)

/* L1C_OP register definitions
 */
#define L1C_OP_EN_OFFSET                      (0)
#define L1C_OP_EN_MASK                        (1<<L1C_OP_EN_OFFSET)
#define L1C_OP_OP_OFFSET                      (1)
#define L1C_OP_OP_MASK                        (15<<L1C_OP_OP_OFFSET)

#define L1C_WAY_NUM                           (1<<10)

/* L1C_HCNT0L register definitions
 */
#define L1C_HCNT0L_CHIT_CNT0_MASK             (0xFFFFFFFFUL<<0)
/* L1C_HCNT0U register definitions
 */
#define L1C_HCNT0U_CHIT_CNT0_MASK             (0xFFFFUL<<0)
/* L1C_CCNT0L register definitions
 */
#define L1C_CCNT0L_CACC_CNT0_MASK             (0xFFFFFFFFUL<<0)
/* L1C_CCNT0U register definitions
 */
#define L1C_CCNT0U_CACC_CNT0_MASK             (0xFFFFUL<<0)
/* L1C_HCNT1L register definitions
 */
#define L1C_HCNT1L_CHIT_CNT1_MASK             (0xFFFFFFFFUL<<0)
/* L1C_HCNT1U register definitions
 */
#define L1C_HCNT1U_CHIT_CNT1_MASK             (0xFFFFUL<<0)
/* L1C_CCNT1L register definitions
 */
#define L1C_CCNT1L_CACC_CNT1_MASK             (0xFFFFFFFFUL<<0)
/* L1C_CCNT1U register definitions
 */
#define L1C_CCNT1U_CACC_CNT1_MASK             (0xFFFFUL<<0)
/* L1C_ENTRY_N register definitions
 */
#define L1C_ENTRY_N_C_MASK                    (1<<8)
#define L1C_ENTRY_BASEADDR_MASK               (0xFFFFFUL<<12)
/* L1C_END_ENTRY_N register definitions
 */
#define L1C_END_ENTRY_N_BASEADDR_MASK         (0xFFFFFUL<<12)

#define MTK_L1C_LINE_SIZE         (32)        /**< L1C line size is 8-word(32-byte) */
#define MTK_L1C_REGION_SIZE_UNIT  (0x1000)    /**< L1C region size must be 4KB aligned */

#define DRAM_REGION_BASE  0x80000 /* l1c start from address 8M */
#define DRAM_REGION_LENGTH (0x10000000 - DRAM_REGION_BASE) /* l1c end in the address, 256M */
#define REGION_INFO_BASE 0x400

#define SCP_LOADER_OFFSET           0x0
#define SCP_LOADER_SIZE             0x400
#define SCP_FW_OFFSET               0x800
#define SCP_L1C_OFFSET              0x80000  //fixed offset
#define SCP_L1C_SIZE                0x100000 //1MB
#define SCP_L1C_BACKUO_OFFSET       0x180000 //fixed offset

/*image name definition*/
#define LOADER_NAME_SCP_A         "tinysys-loader-CM4_A"
#define FIRMWARE_NAME_SCP_A       "tinysys-scp-CM4_A"
#define L1C_NAME_SCP_A         "tinysys-scp-CM4_A_dram"
#define DO_NAME_SCP_A             "tinysys-dos-CM4_A"
#define DO_NAME_SCP_B             "tinysys-dos-CM4_B"

typedef enum {
	L1C_STATUS_INVALID_PARAMETER = -7,    /**< Invalid parameter */
	L1C_STATUS_ERROR_BUSY = -6,           /**< L1C is busy */
	L1C_STATUS_ERROR_L1C_SIZE = -5,     /**< L1C size is invalid, total L1C size is not a value of type #l1c_size_t*/
	L1C_STATUS_ERROR_REGION = -4,         /**< L1C region error, L1C region is not a value of type #l1c_region_t */
	L1C_STATUS_ERROR_REGION_ADDRESS = -3, /**< L1C region address error, L1C region address is not 4KB aligned */
	L1C_STATUS_ERROR_REGION_SIZE = -2,    /**< L1C region size error, L1C region size is not a multiple of 4KB */
	L1C_STATUS_ERROR = -1,                /**< L1C error , imprecise error*/
	L1C_STATUS_OK = 0                     /**< L1C ok */
} l1c_status_t;

typedef enum {
	L1C_SIZE_0KB = 0,                     /**< No L1C */
	L1C_SIZE_8KB = 1,                     /**< L1C size is 8KB */
	L1C_SIZE_16KB = 2,                    /**< L1C size is 16KB */
	L1C_SIZE_32KB = 3,                    /**< L1C size is 32KB */
	L1C_SIZE_MAX                          /**< MAX L1C size (invalid) */
} l1c_size_t;

typedef enum {
	L1C_REGION_0 = 0,                     /**< L1C region 0 */
	L1C_REGION_1 = 1,                     /**< L1C region 1 */
	L1C_REGION_2 = 2,                     /**< L1C region 2 */
	L1C_REGION_3 = 3,                     /**< L1C region 3 */
	L1C_REGION_4 = 4,                     /**< L1C region 4 */
	L1C_REGION_5 = 5,                     /**< L1C region 5 */
	L1C_REGION_6 = 6,                     /**< L1C region 6 */
	L1C_REGION_7 = 7,                     /**< L1C region 7 */
	L1C_REGION_8 = 8,                     /**< L1C region 8 */
	L1C_REGION_9 = 9,                     /**< L1C region 9 */
	L1C_REGION_10 = 10,                   /**< L1C region 10 */
	L1C_REGION_11 = 11,                   /**< L1C region 11 */
	L1C_REGION_12 = 12,                   /**< L1C region 12 */
	L1C_REGION_13 = 13,                   /**< L1C region 13 */
	L1C_REGION_14 = 14,                   /**< L1C region 14 */
	L1C_REGION_15 = 15,                   /**< L1C region 15 */
	L1C_REGION_MAX                        /**< Max L1C region number (invalid) */
} l1c_region_t;

typedef enum {
	L1C_INVALIDATE_ALL_LINES = 1,             /**< Invalidate all L1C line */
	L1C_INVALIDATE_ONE_LINE_BY_ADDRESS = 2,   /**< Invalidate one line by address */
	L1C_INVALIDATE_ONE_LINE_BY_SET_WAY = 4,   /**< Invalidate one line by set and way */
	L1C_FLUSH_ALL_LINES = 9,                  /**< Flush all L1C lines */
	L1C_FLUSH_ONE_LINE_BY_ADDRESS = 10,       /**< Flush one line by address */
	L1C_FLUSH_ONE_LINE_BY_SET_WAY = 12        /**< Flush one line by set and way */
} l1c_line_command_t;

/* structure type to access the L1C register
 */
typedef struct {
	__IO uint32_t L1C_CON;
	__IO uint32_t L1C_OP;
	__IO uint32_t L1C_HCNT0L;
	__IO uint32_t L1C_HCNT0U;
	__IO uint32_t L1C_CCNT0L;
	__IO uint32_t L1C_CCNT0U;
	__IO uint32_t L1C_HCNT1L;
	__IO uint32_t L1C_HCNT1U;
	__IO uint32_t L1C_CCNT1L;
	__IO uint32_t L1C_CCNT1U;
	uint32_t RESERVED0[1];
	__IO uint32_t L1C_REGION_EN;
	uint32_t RESERVED1[2036];                  /**< (0x2000-12*4)/4 */
	__IO uint32_t L1C_ENTRY_N[16];
	__IO uint32_t L1C_END_ENTRY_N[16];
} L1C_REGISTER_T;

/******************************************************************************
* 1. New entries must be appended to the end of the structure.
* 2. Do NOT use conditional option such as #ifdef inside the structure.
******************************************************************************/
struct scp_region_info_st {
	uint32_t ap_loader_start;
	uint32_t ap_loader_size;
	uint32_t ap_firmware_start;
	uint32_t ap_firmware_size;
	uint32_t ap_dram_start;
	uint32_t ap_dram_size;
	uint32_t ap_dram_backup_start;
	/*	This is the size of the structure.
	 *	It can act as a version number if entries can only be
	 *	added to (not deleted from) the structure.
	 *	It should be the first entry of the structure, but for
	 *	compatibility reason, it is appended here.
	 */
	uint32_t struct_size;
	uint32_t scp_log_thru_ap_uart;
	uint32_t TaskContext_ptr;
	uint32_t Il1c_con;
	uint32_t Dl1c_con;
};

typedef struct {
	uint32_t l1c_region_address;  /**< L1C region start address */
	uint32_t l1c_region_size;     /**< L1C region size */
} l1c_region_config_t;

#define L1C_POWER(y)    ((y & 0x300) >> 8)
#define L1C_SIZE(x)     (((1 << L1C_POWER(x)) << 2) * 1024)      /* formula: 2^power*4*1024 */
#define L1C_INDEX(z)    L1C_POWER(z)

int load_scp(void);
void disable_scp_hw(void);
int platform_fdt_scp(void *fdt);
void scp_l1c_init(unsigned int l1c_icon, unsigned int l1c_dcon);

#endif

