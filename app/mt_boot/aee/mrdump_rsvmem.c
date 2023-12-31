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
* THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
* CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
* SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
* STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
* CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*/

#include <memory_layout.h>
#include <malloc.h>
#include <printf.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <libfdt.h>

#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <mt_boot.h>
#include <mblock.h>
#include <platform.h>

#include <dev/mrdump.h>
#include "aee.h"
#include "mrdump_private.h"

void mrdump_reserve_memory(void)
{
#if defined(MBLOCK_LIB_SUPPORT)
#if	defined(MBLOCK_LIB_SUPPORT) \
	&& (MBLOCK_EXPAND(MBLOCK_LIB_SUPPORT)\
	== MBLOCK_EXPAND(2))

	if (mrdump_check_enable() <= MRDUMP_ALWAYS_ENABLE) {
#if defined (MEMSIZE) && defined(SECTION_SIZE)
		(void)mblock_reserve_ext(&g_boot_arg->mblock_info,
					 MEMSIZE, SECTION_SIZE, (MEMBASE + MEMSIZE),
					 0, "lk_addr_mrdump");
#endif
#if defined(LK_DT_BASE)
		(void)mblock_reserve_ext(&g_boot_arg->mblock_info,
					 DTB_MAX_SIZE, DTB_MAX_SIZE,
					 (LK_DT_BASE + DTB_MAX_SIZE),
					 1, "dtb_addr_mrdump");
#endif
	}
	else {
#ifdef PL_BOOTARG_BASE
		if (mblock_query_reserved(&g_boot_arg->mblock_info,
					  "pl-bootarg", 0)) {
			if (mblock_create(&g_boot_arg->mblock_info,
					  &g_boot_arg->orig_dram_info,
					  PL_BOOTARG_BASE, PL_BOOTARG_MAX_SIZE)) {
				dprintf(CRITICAL, "%s: free PL_BOOT_ARG failed\n", __func__);
				assert(0);
			}
		}
#endif /* end of PL_BOOTARG_BASE */
	}
#endif
#endif
}

