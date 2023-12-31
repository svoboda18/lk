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
#include <load_vfy_boot.h>
#include <memory_layout.h>
#include <target.h>
#include <lib/ramdisk_merge.h>
#include <load_ramdisk.h>
#include <pal_assert.h>
#include <pal_typedefs.h>
#include <pal_log.h>
#include <verified_boot_common.h>

#if PLATFORM_SECURITY_VERSION < 20
#error load_vfy_ramdisk: lowest allowed platform security version is 20
#endif

extern int g_is_64bit_kernel;
/*
** +------------------------------+ <--SCRATCH_ADDR
** |kernel image(if kernel is 64 bit)
** |------------------------------+
** | recovery compressed ramdisk
** +------------------------------+
** | vendor compressed ramdisk
** +------------------------------+
** | recovery uncompressed ramdisk
** +------------------------------+
** | vendor uncompressed ramdisk
** +------------------------------+
*/
void load_vfy_ramdisk(uint32_t *merged_ramdisk_size)
{
	DEFINE_RAMDISK_BUF(rd_recovery);
	DEFINE_RAMDISK_BUF(rd_vendor);
	DEFINE_RAMDISK_BUF(target_ramdisk);
	uint8_t *work_buf;
	uint8_t *work_buf_ptr;
	uint8_t *work_buf_end;
	uint32_t ramdisk_target_addr;
	int vb_ret = 0;
	uint32_t recovery_ramdisk_page_align_size;
	uint32_t vendor_ramdisk_page_align_size;

	work_buf = (uint8_t *)target_get_scratch_address();
	work_buf_end = work_buf + SCRATCH_SIZE;
	pal_log_err("work_buf:0x%x, work_buf_end:0x%x\n", (uint32_t)work_buf,
		    (uint32_t)work_buf_end);

	/* boot image loaded in scratch address, work buffer offset to kenel image's end */
	work_buf_ptr = work_buf + get_kernel_real_sz() + get_page_sz();
	work_buf_ptr = (uint8_t *)ALIGN((size_t)(work_buf_ptr), 64);

	rd_recovery.comp_buf = work_buf_ptr;
	rd_recovery.comp_max_size = (uint32_t)(work_buf_end - work_buf_ptr);

	vb_ret = verified_boot_init("recovery_ramdisk", "recovery-ramdisk");
	PAL_ASSERT(vb_ret == 0);

	recovery_ramdisk_read(&rd_recovery, &ramdisk_target_addr, &recovery_ramdisk_page_align_size);

	vb_ret = verified_boot_flow("recovery-ramdisk",
				    (unsigned long)rd_recovery.comp_buf,
				    recovery_ramdisk_page_align_size);
	PAL_ASSERT(vb_ret == 0);

	work_buf_ptr = rd_recovery.comp_buf + recovery_ramdisk_page_align_size;

	rd_vendor.comp_buf = (uint8_t *)ALIGN((size_t)(work_buf_ptr), 64);
	rd_vendor.comp_max_size = (uint32_t)(work_buf_end - rd_vendor.comp_buf);

	vb_ret = verified_boot_init("recovery_vendor", "recovery-vendor");
	PAL_ASSERT(vb_ret == 0);

	vendor_ramdisk_read(&rd_vendor, &vendor_ramdisk_page_align_size);

	vb_ret = verified_boot_flow("recovery-vendor",
				    (unsigned long)rd_vendor.comp_buf,
				    vendor_ramdisk_page_align_size);
	PAL_ASSERT(vb_ret == 0);

	DUMP_RAMDISK_STRUCT(&rd_recovery);
	DUMP_RAMDISK_STRUCT(&rd_vendor);
	work_buf_ptr = rd_vendor.comp_buf + vendor_ramdisk_page_align_size;
	target_ramdisk.comp_buf = (uint8_t *)ramdisk_target_addr;
	target_ramdisk.comp_max_size = LK_RAMDISK_MAX_SIZE;

	/* Recovery ramdisk merge including relocating ramdisk */
	recovery_ramdisk_merge(&rd_recovery, &rd_vendor, &target_ramdisk, work_buf_ptr,
			       work_buf_end);

	DUMP_RAMDISK_STRUCT(&target_ramdisk);
	*merged_ramdisk_size = target_ramdisk.comp_size;
	pal_log_err("target_ramdisk.comp_size:%u\n", target_ramdisk.comp_size);
}

