/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

#ifndef __RAM_CONSOLE_COMMON_H__
#define __RAM_CONSOLE_COMMON_H__

#ifndef __RAM_CONSOLE_H__
#error "Please DON'T include this internal common file directly and use #include <platform/ram_console.h> instead"
#endif

enum RAM_CONSOLE_DEF_TYPE {
    RAM_CONSOLE_DEF_UNKNOWN = 0,
    RAM_CONSOLE_DEF_SRAM,
    RAM_CONSOLE_DEF_DRAM,
};

enum AEE_EXP_TYPE_NUM {
	AEE_EXP_TYPE_HWT = 1,
	AEE_EXP_TYPE_KE = 2,
	AEE_EXP_TYPE_NESTED_PANIC = 3,
	AEE_EXP_TYPE_SMART_RESET = 4,
	AEE_EXP_TYPE_HANG_DETECT = 5,
	AEE_EXP_TYPE_LK_CRASH = 6,
};

#define RAM_CONSOLE_EXP_TYPE_MAGIC 0xaeedead0
#define RAM_CONSOLE_EXP_TYPE_DEC(exp_type) \
	((exp_type ^ RAM_CONSOLE_EXP_TYPE_MAGIC) < 16 ? exp_type ^ RAM_CONSOLE_EXP_TYPE_MAGIC : exp_type)

typedef unsigned int u32;
#define MEM_MAGIC1 0x61646472 // "addr"
#define MEM_MAGIC2 0x73697a65 // "size"
/*
 * ram console sram layout description:
 * |ram console|plt_dbg_info|reserved|memory_info|log_store|mrdump(i.e. fulldump)|
 * ram console dram layout description:
 * |ram console dram memory|pstore|mrdump mini header|
 */
struct ram_console_memory_info {
	u32 magic1;
	u32 sram_plat_dbg_info_addr;
	u32 sram_plat_dbg_info_size;
	u32 sram_log_store_addr;
	u32 sram_log_store_size;
	u32 mrdump_addr;
	u32 mrdump_size;
	u32 dram_addr;
	u32 dram_size;
	u32 pstore_addr;
	u32 pstore_size;
	u32 pstore_console_size;
	u32 pstore_pmsg_size;
	u32 mrdump_mini_header_addr;
	u32 mrdump_mini_header_size;
	u32 magic2;
};

void ram_console_init(void);
bool ram_console_get_wdt_status(unsigned int *);
bool ram_console_get_fiq_step(unsigned int *);
bool ram_console_get_exp_type(unsigned int *);
bool ram_console_set_exp_type(unsigned int exp_type);
bool ram_console_is_abnormal_boot(void);
void ram_console_lk_save(unsigned int val, int index);
void ram_console_addr_size(unsigned int *addr, unsigned int *size);
void ram_console_sram_addr_size(unsigned int *addr, unsigned int *size);
u32 ram_console_def_memory(void);
u32 ram_console_sram_offset(void);
void sram_plat_dbg_info_addr_size(unsigned int *addr, unsigned int *size);
void sram_log_store_addr_size(unsigned int *addr, unsigned int *size);
void sram_mrdump_addr_size(unsigned int *addr, unsigned int *size);
void pstore_addr_size(unsigned int *addr, unsigned int *size);
void mrdump_mini_header_addr_size(unsigned int *addr, unsigned int *size);
void ram_console_dts_written(void *fdt);
void ram_console_set_dump_step(unsigned int step);
int ram_console_get_dump_step(void);
#endif // #ifndef __RAM_CONSOLE_COMMON_H__
