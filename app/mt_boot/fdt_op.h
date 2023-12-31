/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2018. All rights reserved.
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
#if !defined (__FDT_OP_H)
#define __FDT_OP_H
#include <odm_mdtbo.h>

#define DTBO_PART_NAME_LEN	16
/*
 * FIXME: give a reasonable maximum dtbo
 * entry count for input validation.
 */
#define DTBO_ENTRY_CNT_MAX	10000

typedef enum {
	DTBO_FROM_STANDALONE = 1,
	DTBO_FROM_RECOVERY
} DTBO_SRC;

extern DTBO_SRC get_dtbo_src(void);
extern char *get_dtbo_part_name(void);
extern bool setup_fdt(void *fdt, int size);
extern int bldr_load_dtb(char *boot_load_partition);
extern void load_device_tree(void);
int32_t load_dtbo_buffer(void **dtbo_ptr, uint32_t *dtbo_size);
void setup_kernel_fdt(void *fdt);
void *get_kernel_fdt(void);
int32_t prepare_kernel_dtb(void);
#ifdef LK_MAIN_DTB_BUILT_IN
int32_t dtb_overlay(void *main_dtb_addr, uint32_t main_dtb_size,
					void *dtbo_addr, uint32_t dtbo_size,
					void **merged_dtb, uint32_t merged_max_size);
int32_t parse_dtbo_tbl(struct dt_table_header *dt_tbl_hdr_buffer,
		uint32_t hw_board_idx, uint32_t *dtbo_entry_idx_out,
		uint32_t *dtbo_size, uint32_t *dtbo_offset);
#else
extern bool dtb_overlay(void *fdt, int size, uint64_t recovery_dtbo_offset);
#endif

bool dtb_dconfig_overlay(void *target_fdt);

#endif /* __FDT_OP_H */

