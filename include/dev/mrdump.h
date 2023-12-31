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

#if !defined (__MRDUMP_H__)
#define __MRDUMP_H__

#include <sys/types.h>

#define AEE_MRDUMP_LK_RSV_SIZE 0x400000
#define AEE_MRDUMP_DDR_RSV_READY 0x9502

enum {
	MRDUMP_SUCCESS_ENABLE = 1,
	MRDUMP_ALWAYS_ENABLE = 2,
	MRDUMP_ALWAYS_DISABLE = 3,
	MRDUMP_NO_SOCID_FROM_CHIP = 5,
	MRDUMP_SEC_IMG_AUTH_INIT_ERROR = 7,
	MRDUMP_DCONFIG_MALLOC_ERROR = 9,
	MRDUMP_MBOOT_LOAD_PART_ERROR = 11,
	MRDUMP_DCONFIG_IMG_VERIFY_ERROR = 13,
	MRDUMP_DCONFIG_SOCID_CERT_ERROR = 15,
	MRDUMP_DCNFIG_SOCID_MISMATCH = 17,
	MRDUMP_NOT_VALID_IMG = 19,
};
int mrdump_check_enable(void);
void mrdump_reserve_memory(void);
void mrdump_append_cmdline(void *fdt);
int mrdump_detection(void);

void mrdump_reboot(void);
int mrdump_run2(void);

int check_ram_console_is_abnormal_boot(void) __attribute__((weak));

/* extern functions */
int usb_write_with_timeout(void *buf, unsigned len, time_t timeout);
int usb_read_with_timeout(void *_buf, unsigned len, time_t timeout);
void mrdump_key_secure_enable(void);

#define MRDUMP_DEV_UNKNOWN 0
#define MRDUMP_DEV_NONE 1
#define MRDUMP_DEV_NULL 2
#define MRDUMP_DEV_ISTORAGE 3 /* ext4/f2fs */
#define MRDUMP_DEV_UNUSED 4 /* Retire from vfat support */
#define MRDUMP_DEV_USB 5
#define MRDUMP_DEV_PARTITION 6

int mrdump_set_output_device(const char *output_dev);

#endif
