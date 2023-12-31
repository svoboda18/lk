/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2019 All rights reserved.
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


#include <pal_typedefs.h>
#include <pal_log.h>

#include <load_vfy_boot.h>
#include <verified_boot_common.h>
#include <avb_slot_verify.h>
#include <avb_ops.h>

#define SHA256_LENGTH 32
#define MTK_SIP_LK_ROOT_OF_TRUST_AARCH32    0x82000120

#define AVB_ROT_DEBUG (0)

#define OS_VERSION_KEY_IDX        (0)
#define OS_PATCHLEVEL_KEY_IDX     (1)
#define VENDOR_PATCHLEVEL_KEY_IDX (2)
#define BOOT_PATCHLEVEL_KEY_IDX   (3)
#define NUM_AVB_VERSIONS          (4)

/* query verified boot state - g_boot_state */
extern uint32_t g_boot_state;
int sha256(uint8_t *data, unsigned long data_len, uint8_t *output_hash);
int sec_query_device_lock(int *lock_state);

struct vb_version {
	uint32_t os_version;
	uint32_t os_patchlevel;
	uint32_t vendor_patchlevel;
	uint32_t boot_patchlevel;
};

static struct vb_version g_vb_version;
static uint8_t g_vbmeta_digest_sha256[SHA256_LENGTH] = {0};

static const char *avb_version_key[NUM_AVB_VERSIONS] = {
	"com.android.build.system.os_version",
	"com.android.build.system.security_patch",
	"com.android.build.vendor.security_patch",
	"com.android.build.boot.security_patch",
	NULL
};

static const char *avb_version_str[NUM_AVB_VERSIONS] = {NULL};

static uint32_t smc_call(uint32_t function_id, uint32_t arg0, uint32_t arg1,
			 uint32_t arg2, uint32_t arg3)
{
	uint32_t ret = 0;
	register uint32_t reg0 __asm__("r0") = function_id;
	register uint32_t reg1 __asm__("r1") = arg0;
	register uint32_t reg2 __asm__("r2") = arg1;
	register uint32_t reg3 __asm__("r3") = arg2;
	register uint32_t reg4 __asm__("r4") = arg3;

	__asm__ volatile("smc 0" : "+r"(reg0),
			 "+r"(reg1), "+r"(reg2), "+r"(reg3), "+r"(reg4));

	ret = reg0;
	return ret;
}

static uint32_t version_str_to_uint(uint32_t ver_type, char *str,
				    uint32_t str_sz)
{
#define MAX_OS_VER_NUM (3)
	uint32_t val = 0;
	uint32_t i = 0;
	uint32_t idx = 0;
	uint32_t xx[MAX_OS_VER_NUM] = {0};
	uint32_t yyyy = 0;
	uint32_t mm = 0;
	uint32_t dd = 0;

	/* return 0 for invalid version string */
	if (str == NULL || str_sz == 0)
		return 0;

	switch (ver_type) {
	case OS_VERSION_KEY_IDX:
		/* assume os_version format is
		 * xx[0] or
		 * xx[0].xx[1] or
		 * xx[0].xx[1].xx[2]
		 */

		for (i = 0; i < str_sz; i++) {
			if (str[i] == '.') {
				idx++;
				if (idx == MAX_OS_VER_NUM)
					break;
			} else if (str[i] < '0' || str[i] > '9') {
				pal_log_err("[%s] invalid os_version\n", __func__);
				return 0;
			}
			xx[idx] = xx[idx] * 10 + (str[i] - '0');
		}

		/* version overflow */
		for (idx = 0; idx < MAX_OS_VER_NUM; idx++)
			if (xx[idx] >= 100)
				xx[idx] = 99;

		val =  10000 * xx[0] + 100 * xx[1] + xx[2];
		break;
	case VENDOR_PATCHLEVEL_KEY_IDX:
	case BOOT_PATCHLEVEL_KEY_IDX:
	case OS_PATCHLEVEL_KEY_IDX:
		/* assume its format is YYYY-MM or YYYY-MM-DD */

		if (str_sz != 7 && str_sz != 10) {
			val = 0;
			break;
		}

		/* str_sz = 7 or 10 */
		for (i = 0; i < 4; i++) {
			if (str[i] < '0' && str[i] > '9')
				return 0;

			yyyy = yyyy * 10 + (uint32_t)(str[i] - '0');
		}

		val = yyyy;

		if (str[4] != '-')
			return 0;

		for (i = 5; i < 7; i++) {
			if (str[i] < '0' && str[i] > '9')
				return 0;

			mm = mm * 10 + (uint32_t)(str[i] - '0');
		}

		val = val * 100 + mm;

		if (str_sz == 10) {
			if (str[7] != '-')
				return 0;

			for (i = 8; i < 10; i++) {
				if (str[i] < '0' && str[i] > '9')
					return 0;

				dd = dd * 10 + (uint32_t)(str[i] - '0');
			}

			val = val * 100 + dd;
		}

		break;
	default:
		return 0;
	}

	if (ver_type == OS_PATCHLEVEL_KEY_IDX && val >= 1000000) {
		/* DD is ignored for os_patchlevel */
		val /= 100;
	}

	return val;
}

uint32_t collect_rot_info(AvbSlotVerifyData *slot_data)
{
	uint32_t ret = 0;
	uint32_t i = 0;
	uint32_t j = 0;
	size_t out_val_size = 0;

	for (i = 0; i < slot_data->num_vbmeta_images; i++) {
		for (j = 0; j < NUM_AVB_VERSIONS; j++) {
			const char *val;

			if (avb_version_str[j])
				continue;

			val = avb_property_lookup(slot_data->vbmeta_images[i].vbmeta_data,
						  slot_data->vbmeta_images[i].vbmeta_size,
						  avb_version_key[j],
						  0,
						  &out_val_size);

			if (out_val_size) {
				pal_log_err("%s is found in idx 0x%x, val = %s\n", avb_version_key[j], i, val);
				avb_version_str[j] = val;
			}
			out_val_size = 0;
		}
	}

	/* if os_version is not found, set it to "10" */
	if (avb_version_str[OS_VERSION_KEY_IDX] == NULL)
		avb_version_str[OS_VERSION_KEY_IDX] = "10";

	if (avb_version_str[OS_VERSION_KEY_IDX]) {
		g_vb_version.os_version = version_str_to_uint(OS_VERSION_KEY_IDX,
					  avb_version_str[OS_VERSION_KEY_IDX],
					  strlen(avb_version_str[OS_VERSION_KEY_IDX]));
	}

	if (avb_version_str[OS_PATCHLEVEL_KEY_IDX]) {
		g_vb_version.os_patchlevel = version_str_to_uint(OS_PATCHLEVEL_KEY_IDX,
					     avb_version_str[OS_PATCHLEVEL_KEY_IDX],
					     strlen(avb_version_str[OS_PATCHLEVEL_KEY_IDX]));
	}

	if (avb_version_str[VENDOR_PATCHLEVEL_KEY_IDX]) {
		g_vb_version.vendor_patchlevel = version_str_to_uint(VENDOR_PATCHLEVEL_KEY_IDX,
						 avb_version_str[VENDOR_PATCHLEVEL_KEY_IDX],
						 strlen(avb_version_str[VENDOR_PATCHLEVEL_KEY_IDX]));
	}

	if (avb_version_str[BOOT_PATCHLEVEL_KEY_IDX]) {
		g_vb_version.boot_patchlevel = version_str_to_uint(BOOT_PATCHLEVEL_KEY_IDX,
					       avb_version_str[BOOT_PATCHLEVEL_KEY_IDX],
					       strlen(avb_version_str[BOOT_PATCHLEVEL_KEY_IDX]));
	}

	avb_slot_verify_data_calculate_vbmeta_digest(
		slot_data, AVB_DIGEST_TYPE_SHA256, g_vbmeta_digest_sha256);

#if AVB_ROT_DEBUG
	for (i = 0; i < NUM_AVB_VERSIONS; i++)
		pal_log_err("avb version str[%s] = %s\n", avb_version_key[i],
			    avb_version_str[i] == NULL ? "NOT FOUND" : avb_version_str[i]);

	pal_log_err("os_version = %u\n", g_vb_version.os_version);
	pal_log_err("os_patchlevel = %u\n", g_vb_version.os_patchlevel);
	pal_log_err("vendor_patchlevel = %u\n", g_vb_version.vendor_patchlevel);
	pal_log_err("boot_patchlevel = %u\n", g_vb_version.boot_patchlevel);
	pal_log_err("vbmeta_digest =\n");
	for (i = 0; i < AVB_SHA256_DIGEST_SIZE; i++)
		pal_log_err("0x%x\n", g_vbmeta_digest_sha256[i]);
#endif /* AVB_ROT_DEBUG */

	return ret;
}

static inline void smc_out(uint32_t id,
uint32_t p0,
uint32_t p1,
uint32_t p2)
{
uint32_t fun_id = (uint32_t)id;
uint32_t temp[3];

temp[0] = p0;
temp[1] = p1;
temp[2] = p2;


__asm__ volatile(
    ".arch_extension sec\n"
    "mov r0, %[fun_id]\n\t"
    "ldr r1, [%[temp], #0]\n\t"
    "ldr r2, [%[temp], #4]\n\t"
    "ldr r3, [%[temp], #8]\n\t"
    "smc 0\n\t"
    "nop\n\t"
    "nop\n\t"
    "nop"
: :
[fun_id] "r" (fun_id), [temp] "r" (temp)
 : "r0", "r1", "r2", "r3",  "memory");
}


/*This field id is fixed by arm*/
#define ID_FIELD_F_FAST_SMC_CALL    1
#define ID_FIELD_F_STANDARD_SMC_CALL    0
#define ID_FIELD_W_64           1
#define ID_FIELD_W_32           0
#define ID_FIELD_T_ARM_SERVICE      0
#define ID_FIELD_T_CPU_SERVICE      1
#define ID_FIELD_T_SIP_SERVICE      2
#define ID_FIELD_T_OEM_SERVICE      3
#define ID_FIELD_T_STANDARD_SERVICE 4

/*TA Call 48-49*/
#define ID_FIELD_T_TA_SERVICE0              48
#define ID_FIELD_T_TA_SERVICE1              49
/*TOS Call 50-63*/
#define ID_FIELD_T_TRUSTED_OS_SERVICE0      50
#define ID_FIELD_T_TRUSTED_OS_SERVICE1      51

#define ID_FIELD_T_TRUSTED_OS_SERVICE2      52
#define ID_FIELD_T_TRUSTED_OS_SERVICE3      53

#define TEEI_CORE_COUNT     PLATFORM_CORE_COUNT

#define MAKE_SMC_CALL_ID(F, W, T, FN) (((F)<<31)|((W)<<30)|((T)<<24)|(FN))

void send_root_of_trust_info(void)
{
	uint8_t public_key[PUBK_LEN] = {0};
	uint8_t public_key_hash[SHA256_LENGTH] = {0};
	int device_lock_state = 0;

	pal_log_info("sending root of trust info...\n");

	/* read public key and generate SHA256(pubk) */
	if (sec_get_pubk(public_key, PUBK_LEN))
		pal_log_err("fail to get public key info\n");

	if (sha256(public_key, PUBK_LEN, public_key_hash))
		pal_log_err("fail to calculate public key hash\n");

	/* query device lock */
	if (sec_query_device_lock(&device_lock_state))
		pal_log_err("fail to get device lock state\n");

pal_log_err("device lock state %d\n", device_lock_state);

	/* send to ARM-TF via SMC call */
	uint32_t *p_hash = (uint32_t *)public_key_hash;
	uint32_t *p_vbmeta_digest = (uint32_t *)g_vbmeta_digest_sha256;
	uint32_t smc_ret = 0;


#define MTK_SIP_LK_ROOT_OF_TRUST_AARCH32    MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 10)
	smc_out(MTK_SIP_LK_ROOT_OF_TRUST_AARCH32, *(p_hash), *(p_hash+1), *(p_hash+2));
	pal_log_err("%x, %x, %x\n\n", *(p_hash), *(p_hash+1), *(p_hash+2));
	smc_out(MTK_SIP_LK_ROOT_OF_TRUST_AARCH32, *(p_hash+3), *(p_hash+4), *(p_hash+5));
	pal_log_err("%x, %x, %x\n\n", *(p_hash+3), *(p_hash+4), *(p_hash+5));
	smc_out(MTK_SIP_LK_ROOT_OF_TRUST_AARCH32, *(p_hash+6), *(p_hash+7), device_lock_state);
	pal_log_err("%x, %x, %x\n\n", *(p_hash+6), *(p_hash+7), device_lock_state);
	smc_out(MTK_SIP_LK_ROOT_OF_TRUST_AARCH32, g_boot_state, g_vb_version.os_version, g_vb_version.os_patchlevel);
	pal_log_err("%x, %x, %x\n\n", g_boot_state, g_vb_version.os_version, g_vb_version.os_patchlevel);

	smc_out(MTK_SIP_LK_ROOT_OF_TRUST_AARCH32, *(p_vbmeta_digest), *(p_vbmeta_digest+1), *(p_vbmeta_digest+2));
	smc_out(MTK_SIP_LK_ROOT_OF_TRUST_AARCH32, *(p_vbmeta_digest+3), *(p_vbmeta_digest+4), *(p_vbmeta_digest+5));
	smc_out(MTK_SIP_LK_ROOT_OF_TRUST_AARCH32, *(p_vbmeta_digest+6), *(p_vbmeta_digest+7), g_vb_version.vendor_patchlevel);

	smc_out(MTK_SIP_LK_ROOT_OF_TRUST_AARCH32, g_vb_version.boot_patchlevel, 0, 0);

}
