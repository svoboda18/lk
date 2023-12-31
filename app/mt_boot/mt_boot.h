/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2017. All rights reserved.
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

#ifndef _MT_BOOT_H_
#define _MT_BOOT_H_

#include "memory_layout.h"
#include <fdt_op.h>
#include <bootimg.h>

#define DTB_MAX_SIZE    (512*1024)

#ifndef DUMMY_MEMORY_LAYOUT

#if DTB_MAX_SIZE > LK_DT_MAX_SIZE
#error DTB_MAX_SIZE > LK_DT_MAX_SIZE
#endif

#if KERNEL_DECOMPRESS_SIZE > LK_KERNEL_64_MAX_SIZE
#error KERNEL_DECOMPRESS_SIZE > LK_KERNEL_64_MAX_SIZE
#endif

#if (MEMBASE != LK_LK_BASE)||(MEMSIZE > LK_LK_MAX_SIZE)
#error check LK MEMBASE or MEMSIZE
#endif

#if (SCRATCH_ADDR != LK_DL_BASE)||(SCRATCH_SIZE > LK_DL_MAX_SIZE)
#error check SCRATCH_ADDR or SCRATCH_SIZE
#endif

#endif
#define EXTRACT_UBYTE(x, n)     ((uint32_t)((uint8_t *)&x)[n])

void Debug_log_EMI_MPU(void) __attribute__((weak));

#ifdef MTK_AB_OTA_UPDATER
void get_AB_OTA_name(char *part_name, int size);
#endif /* MTK_AB_OTA_UPDATER */

bool get_atm_enable_status(void);
bool cmdline_append(const char *append_string);
void mboot_allocate_bootimg_from_mblock(struct bootimg_hdr *p_boot_hdr);
int bldr_load_dtb(char* boot_load_partition);
void msg_header_error(char *img_name);
void msg_img_error(char *img_name);

#endif  // _MT_BOOT_H_

