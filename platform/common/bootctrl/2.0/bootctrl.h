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
 * MediaTek Inc. (C) 2016. All rights reserved.
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


/* THE HAL BOOTCTRL HEADER MUST BE IN SYNC WITH THE UBOOT BOOTCTRL HEADER */

#ifndef _BOOTCTRL_H_
#define _BOOTCTRL_H_

#include <stdint.h>
#include <libavb_ab/libavb_ab.h>

/* struct boot_ctrl occupies the slot_suffix field of
 * struct bootloader_message */

#define BOOTCTRL_MAGIC 0x19191100

#define OFFSETOF_SLOT_SUFFIX 2048

#define BOOTCTRL_SUFFIX_A      "_a"
#define BOOTCTRL_SUFFIX_B      "_b"
#define BOOTCTRL_SUFFIX_MAXLEN 2

#define BOOT_CONTROL_VERSION    1
#define READ_PARTITION          0
#define WRITE_PARTITION         1

typedef struct slot_metadata_vendor {    
	uint8_t priority : 3;    
	uint8_t retry_count : 3;    
	uint8_t successful_boot : 1;    
	uint8_t normal_boot : 1;
} slot_metadata_t;

typedef struct boot_ctrl {    
	/* Magic for identification */    
	uint32_t magic;    
	/* Version of struct. */    
	uint8_t version;    
	/* Information about each slot. */    
	slot_metadata_t slot_info[2];    
	uint8_t recovery_retry_count;
} boot_ctrl_t;

/* bootctrl API */
const char *get_suffix(void);
int set_active_slot(const char *suffix);
uint8_t get_retry_count(const char *suffix);
int get_bootup_status(const char *suffix);
int get_bootable_status(const char *suffix);
int increase_tries_remaining(void);

#endif /* _BOOTCTRL_H_ */
