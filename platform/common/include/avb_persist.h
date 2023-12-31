/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2019. All rights reserved.
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
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/

#ifndef __AVB_PERSIST_H__
#define __AVB_PERSIST_H__

#include <pal_typedefs.h>
#include <vboot_state.h>
#include <avb_ops.h>

#define PERSIST_MAGIC                   0x90790922
#define PERSIST_MAJOR_VER               0x1
#define PERSIST_MINOR_VER               0x0

#define PERSIST_UNSPECIFIED_OFFSET      0xFFFFFFFFFFFFFFFF
#define PERSIST_ALIGN_SZ                16
#define PERSIST_HDR_SZ                  64
#define DEFAULT_PERSIST_PREALLOC_BUF_SZ 512
#define PERSIST_TAG_MAGIC               0x90790804
#define MAX_PERSIST_TAG_SZ              8

typedef union {
	struct {
		uint32_t magic;
		uint32_t major_ver;
		uint32_t minor_ver;
	} info;

	uint8_t data[PERSIST_HDR_SZ];
} PersistHdr;

typedef struct PersistDescriptorHdr {
	uint32_t tag;
	uint32_t key_sz;    /* in bytes */
	uint32_t value_sz;  /* in bytes */
} PersistDescriptorHdr;

typedef struct PersistDescriptor {
	PersistDescriptorHdr hdr;
	uint8_t *key;
	uint8_t *value;
} PersistDescriptor;

bool get_init_persist_status(void);
void set_update_persist_status(void);
uint32_t init_persist_value(AvbOps *ops, char *part_name, uint64_t offset);
uint32_t write_persist_value(AvbOps *ops, char *part_name);
void set_update_persist_status(void);

#endif /* __VERIFIED_BOOT_COMMON_H__ */
