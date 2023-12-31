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
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/

#ifndef __VERIFIED_BOOT_H__
#define __VERIFIED_BOOT_H__

#include <verified_boot_common.h>
#include <pal_typedefs.h>

/* max version for avb group */
#define AVB_OTP_MAX_UNIT_NUM            8
#define AVB_OTP_SECURE_GROUP_UNIT_NUM   1
#define RECOVERY_ROLLBACK_INDEX         1

/* avb persist value.
 * If PERSIST_VALUE_OFFSET is not specified, offset is the half partition
 * size of seccfg by default.
 */
#define PERSIST_PART_NAME    "seccfg"
#define PERSIST_VALUE_OFFSET 0x200

/* secure boot flow */
int sec_func_init(uint64_t pl_start_addr);
int seclib_set_oemkey(uint8_t *pubk, uint32_t size);
uint32_t sec_img_auth_init(char *part_name, char *img_name, uint32_t oem_opt);
uint32_t sec_img_auth(uint8_t *buf, uint32_t buf_sz);
uint32_t sec_img_auth_stor(char *part_name, char *img_name);
uint32_t sec_img_auth_custom(uint8_t *buf, uint32_t buf_sz);
int img_auth_stor(char *part_name, char *img_name, uint32_t feature_mask);

/* get secure boot info */
int sec_usbdl_enabled (void);
int sec_query_device_lock(int *lock_state);
uint32_t sec_get_c2kmd_sbcen(void);
uint32_t sec_get_ltemd_sbcen(void);
uint32_t sec_set_md_default_pubk_hash(void);

/* set secure boot info */
unsigned *fill_atag_masp_data(uint32_t *ptr);

#endif /* __VERIFIED_BOOT_H__ */

