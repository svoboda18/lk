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

/**************************************************************************
 * [Software Secure Boot Format]
 **************************************************************************/
typedef enum {
	SW_SUPPORT_DISABLE = 0,
	SW_SUPPORT_ENABLE = 1
} SW_SEC_BOOT_FEATURE_SUPPORT;

typedef enum {
	SW_SEC_BOOT_LOCK = 1,
	SW_SEC_BOOT_UNLOCK = 2
} SW_SEC_BOOT_LOCK_TYPE;

typedef enum {
	SW_SEC_BOOT_CERT_PER_PROJECT = 1,
	SW_SEC_BOOT_CERT_PER_DEVICE = 2
} SW_SEC_BOOT_CERT_TYPE;

typedef enum {
	SW_SEC_BOOT_NOT_TRY = 0,
	SW_SEC_BOOT_TRY_LOCK = 1,
	SW_SEC_BOOT_TRY_UNLOCK = 2
} SW_SEC_BOOT_TRY_TYPE;

typedef enum {
	SW_SEC_BOOT_NOT_DONE = 0,
	SW_SEC_BOOT_DONE_LOCKED = 1,
	SW_SEC_BOOT_DONE_UNLOCKED = 2
} SW_SEC_BOOT_DONE_TYPE;

typedef enum {
	SW_SEC_BOOT_CHECK_IMAGE = 1,
	SW_SEC_BOOT_NOT_CHECK_IMAGE = 2
} SW_SEC_BOOT_CHK_TYPE;

typedef enum {
	SEC_LOCK = 0,
	SEC_UNLOCK = 1,
	SEC_VERIFIED = 2,
	SEC_CUSTOM = 3,
	SEC_UNDEFINED = 0xff
} LOCK_STATE;

typedef struct {
	unsigned int dl_format_lock;
	unsigned int dl_1st_loader_lock;
	unsigned int dl_2nd_loader_lock;
	unsigned int dl_image_lock;
	unsigned int boot_chk_2nd_loader;
	unsigned int boot_chk_logo;
	unsigned int boot_chk_bootimg;
	unsigned int boot_chk_recovery;
	unsigned int boot_chk_system;
	unsigned int boot_chk_others;
	unsigned int boot_chk_cust1;
	unsigned int boot_chk_cust2;
	unsigned int dl_tee_lock;
	unsigned int boot_chk_tee;
} SEC_POLICY_T;

#define MAX_NUM_LOCK_STATE 4

typedef struct {
	unsigned int  magic_number;
	unsigned int  sw_secure_boot_en;
	unsigned int  default_state;
	SEC_POLICY_T  state_policy[MAX_NUM_LOCK_STATE];
	unsigned char reserve[20];
} AND_SW_SEC_BOOT_T;

extern SEC_POLICY_T *g_cur_sec_policy;
/**************************************************************************
 * [seclib extern function]
 **************************************************************************/
void seclib_image_buf_init(void);
void seclib_image_buf_free(void);

/**************************************************************************
 * [SECURE PARTITION NAME]
 **************************************************************************/
struct sec_part_name_map {
	char fb_name[32];   /*partition name used by fastboot, and gpt since 95*/
	char ft_name[32];   /*partition name used by flash tool*/
	char st_name[32];    /* partition name used by sign tool */
	char sb_name[32];   /*partition name used by secure boot*/
	int partition_idx;  /*partition index*/
	int is_sec_dl_forbit;   /*partition support download in security */
};

extern struct sec_part_name_map g_secure_part_name[];

/* index for secure boot partition name, g_secure_part_name*/
#define SBOOT_PART_PRELOADER            0
#define SBOOT_PART_SECURE               8
#define SBOOT_PART_LK                   9
#define SBOOT_PART_BOOTIMG              10
#define SBOOT_PART_RECOVERY             11
#define SBOOT_PART_SECRO                12
#define SBOOT_PART_LOGO                 14
#define SBOOT_PART_ANDROID              17
#define SBOOT_PART_USRDATA              19
#define SBOOT_PART_CUST1                23
#define SBOOT_PART_CUST2                24

/* for avb recovery rollback location */
#define RECOVERY_ROLLBACK_INDEX         1

/* avb persist value.
 * If PERSIST_VALUE_OFFSET is not specified, offset is the half partition
 * size of seccfg by default.
 */
#define PERSIST_PART_NAME    "seccfg"
#define PERSIST_VALUE_OFFSET 0x200

/* secure boot flow */
int sec_func_init(unsigned long long pl_start_addr);
int seclib_set_oemkey(unsigned char *pubk, unsigned int size);
unsigned int sec_img_auth_init(char *part_name, char *img_name, unsigned int oem_opt);
unsigned int sec_img_auth(unsigned char *buf, unsigned int buf_sz);
unsigned int sec_img_auth_stor(char *part_name, char *img_name);
unsigned int sec_img_auth_custom(unsigned char *buf, unsigned int buf_sz);
int img_auth_stor(char *part_name, char *img_name, unsigned int feature_mask);

/* get secure boot info */
unsigned int seclib_sec_boot_enabled(unsigned int);
int sec_usbdl_enabled (void);
int sec_query_device_lock(int *lock_state);
unsigned int sec_get_c2kmd_sbcen(void);
unsigned int sec_get_ltemd_sbcen(void);

/* set secure boot info */
unsigned *fill_atag_masp_data(unsigned int *ptr);

#endif /* __VERIFIED_BOOT_H__ */
