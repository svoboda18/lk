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
#include <platform/mt_typedefs.h>
#include <platform/sec_status.h>
#include <platform/errno.h>
#include <debug.h>
#include <platform/boot_mode.h>
#include <part_interface.h>
#include <part_internal_wrapper.h>
#include <verified_boot_common.h>

extern BOOTMODE g_boot_mode;

struct vb_part_name_map vb_part_name_map_table[MAP_VB_PART_NUM] = {
	{"boot",     "/boot"},
	{"recovery", "/recovery"}
};

u64 sec_dev_part_get_offset_wrapper(char *name)
{
	return part_get_offset_wrapper(name);
}

char* sec_dev_get_part_r_name_wrapper(char *name)
{
	return part_get_r_name_wrapper(name);
}

/* dummy parameter is for prameter alignment */
int sec_dev_read_wrapper(char *part_name, u64 offset, u8* data, u32 size)
{
	int ret = partition_read(part_name, offset, data, size);
	if (ret < 0)
	    return ret;
	return B_OK;
}

/* dummy parameter is for prameter alignment */
int sec_dev_write_wrapper(char *part_name, u64 offset, u8* data, u32 size)
{
	int ret = partition_write(part_name, offset, data, size);
	if (ret < 0)
		return ret;
	return B_OK;
}

BOOL is_recovery_mode(void)
{
	if (g_boot_mode == RECOVERY_BOOT) {
		return TRUE;
	} else {
		return FALSE;
	}
}

