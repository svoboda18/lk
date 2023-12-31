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

#include <block_generic_interface.h>
#include <malloc.h>
#include <printf.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <video.h>
#include <dev/mrdump.h>
#ifdef MTK_PARTITION_COMMON
#include <env.h>
#else
#include <platform/env.h>
#endif
#include <platform/mtk_key.h>
#include <platform/mtk_wdt.h>
#include <platform/mt_gpt.h>
#include <target/cust_key.h>
#include <platform/boot_mode.h>
#include <platform/ram_console.h>
#include <arch/ops.h>
#include <libfdt.h>
#include <platform.h>
#include "aee.h"
#include "mrdump_private.h"

extern BOOT_ARGUMENT *g_boot_arg;
char mrdump_key_compatible[] = "mediatek, mrdump_ext_rst-eint";
static char *force_mode;

void mrdump_key_secure_enable(void)
{
	force_mode = "SYSRST";
}

void mrdump_key_fdt(void *fdt)
{
	int offset, len;
	const void *data;

	if (!force_mode) {
		dprintf(CRITICAL, "%s:no force mode set\n", __func__);
#ifdef USERDEBUG_BUILD
		force_mode = "SYSRST";
#elif defined(USER_BUILD)
		force_mode = "EINT";
#elif defined(ENG_BUILD)
		force_mode = "SYSRST";
#endif
	}
	else
		dprintf(CRITICAL, "%s:force default to %s\n", __func__, force_mode);

	offset = fdt_node_offset_by_compatible(fdt,
		-1, mrdump_key_compatible);
	if (offset < 0) {
		dprintf(CRITICAL, "%s:%s not found\n",
			__func__, mrdump_key_compatible);
		return;
	}

	data = fdt_getprop(fdt, offset, "force_mode", &len);

	if (!data) {
		fdt_appendprop_string(fdt, offset, "force_mode", force_mode);
		dprintf(CRITICAL, "%s:set force mode %s\n",
			__func__, force_mode);
	} else
		dprintf(CRITICAL, "%s:exist force mode=%s\n", __func__, (char*)data);
}

static int mrdump_ddr_reserved_mode_control(void)
{
	if (g_boot_arg->ddr_reserve_ready != AEE_MRDUMP_DDR_RSV_READY) {
		cmdline_append("mrdump_ddrsv=no");
		return 0;
	}
	else {
		cmdline_append("mrdump_ddrsv=yes");
		return 1;
	}
}

#define MRDUMP_CB_BUF_LEN 64

void mrdump_append_cmdline(void *fdt)
{
	int res;

	res  = mrdump_ddr_reserved_mode_control();
	if (!res)
		dprintf(CRITICAL, "MT-RAMDUMP: DDR reserve mode not ready, skipped (0x%x)\n", g_boot_arg->ddr_reserve_ready);

#ifdef MTK_MRDUMP_SRAM_CB
	char *mrdump_cb_buf = malloc(MRDUMP_CB_BUF_LEN);
	if (mrdump_cb_buf) {
		snprintf(mrdump_cb_buf, MRDUMP_CB_BUF_LEN, "mrdump_cb=0x%x,0x%x", MRDUMP_CB_ADDR, MRDUMP_CB_SIZE);
		cmdline_append(mrdump_cb_buf);
	}
	free(mrdump_cb_buf);
#endif

#if defined(MTK_MRDUMP_SUPPORT)
	if (res) {
		if (mrdump_check_enable() <= MRDUMP_ALWAYS_ENABLE)
			cmdline_append("mrdump.lk=" MRDUMP_GO_DUMP);
	}
#endif

	mrdump_key_fdt(fdt);
}
