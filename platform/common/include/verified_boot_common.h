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

#ifndef __VERIFIED_BOOT_COMMON_H__
#define __VERIFIED_BOOT_COMMON_H__

#include <pal_typedefs.h>
#include <vboot_state.h>
#include <lock_state.h>
#include <dm_verity_status.h>

#ifndef PLATFORM_SECURITY_VERSION
#error PLATFORM_SECURITY_VERSION is not defined
#elif PLATFORM_SECURITY_VERSION == 21
#include <verified_boot_21.h>
#elif PLATFORM_SECURITY_VERSION == 20
#include <verified_boot_20.h>
#elif PLATFORM_SECURITY_VERSION == 11
#include <verified_boot_11.h>
#else
#error PLATFORM_SECURITY_VERSION not supported
#endif

#define MAP_VB_PART_NUM  2
#define MAX_IMG_NAME_LEN 32

#define PUBK_LEN 256

#define SOC_ID_LEN       32

struct vb_part_name_map {
	char *part_name_ori;
	char *target_name;
};

int sec_query_warranty(int *warranty);
int sec_boot_check(int try_lock);
int sec_is_in_factory(int *in_factory);
struct vb_part_name_map vb_part_name_map_table[MAP_VB_PART_NUM];
int pkcs1_v15_decode_sha256(unsigned char *hash, unsigned int hash_sz,
		unsigned char *dec_sig, unsigned int dec_sig_sz, int *compare_result);
int RSADecryption65537(unsigned int *sig, unsigned int *buf_PublicKey,
		unsigned int *dec_sig);

uint32_t get_sboot_state(uint32_t *sboot_state);
uint32_t get_lock_state(uint32_t *lock_state);

uint32_t sec_set_pubk(uint8_t *pubk, uint32_t pubk_size);
uint32_t sec_get_pubk(uint8_t *pubk, uint32_t pubk_size);
uint32_t sec_clear_pubk(void);

/***********************************************************
 * anti-rollbck
 **********************************************************/
typedef enum {
	SECURE_GROUP = 0,
	NON_SECURE_GROUP,
	AVB_GROUP,
	RECOVERY_GROUP,
	MISC_GROUP
} OTPGroupType;

struct otp_group_info {
	OTPGroupType group;
	uint32_t unit;
	uint32_t start_idx;
	uint32_t end_idx;
	uint32_t otp_ver;
	uint32_t otp_max_ver;
	uint32_t min_ver;
};

#define SEC_FEATURE_MASK_ANTIROLLBACK 0x00000001
#define BYPASS_CERT_CHAIN_VERIFY      0x00000002
#define GET_SOCID_FROM_CERT2          0x00000004

#define INVAILD_OTP_VALUE  0xFFFFFFFF

#define PERSIST_UNSPECIFIED_OFFSET      0xFFFFFFFFFFFFFFFF

uint32_t get_otp_group_num(void);
uint32_t sec_get_otp_ver(uint32_t group, uint32_t *otp_ver);
uint32_t get_avb_otp_ver(uint32_t group, uint32_t *out_ver);
uint32_t set_avb_otp_ver(uint32_t group, uint32_t rollback_index);
uint32_t sec_otp_ver_update(uint32_t boot_mode);
uint32_t sec_rollback_check(uint32_t ext_group);
void enable_anti_rollback_v2_framework(void);
uint32_t sec_mtk_internal_ver_test(uint32_t magic_num);
int sec_dev_read_wrapper(char *part_name, uint64_t offset, uint8_t* data, uint32_t size);
int sec_dev_write_wrapper(char *part_name, uint64_t offset, uint8_t* data, uint32_t size);
uint8_t *seclib_image_allocate_mem(uint32_t buf_len);
void seclib_image_buf_init(void);
void seclib_image_buf_free(void);
void seclib_image_buf_reset(void);
void show_sec_reminder_warning(void);
uint32_t set_allow_rollback_count(uint32_t count);
uint32_t pl_auth(uint8_t *pl_addr, uint32_t pl_len);
uint32_t get_img_ver(uint32_t *ver);
uint32_t get_socid_chip(uint8_t *socid, uint32_t id_len);
uint32_t get_socid_cert(uint8_t *socid, uint32_t id_len);
uint32_t get_trnd(uint8_t *out_put, uint32_t sz_in_byte, uint32_t debug_en);

/**********************************************************/

#endif /* __VERIFIED_BOOT_COMMON_H__ */
