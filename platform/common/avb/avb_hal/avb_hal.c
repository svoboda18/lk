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
#include <string.h>
#include <avbkey.h>
#include <error.h>
#include <pal_typedefs.h>
#include <pal_log.h>
#include <part_interface.h>
#include <partition_error.h>
#include <part_status.h>
#include <lock_state.h>

#include <avb_ops.h>
#include <avb_crypto.h>
#include <avb_util.h>

#include <lock_state.h>
#include <platform/verified_boot.h>
#include <verified_boot_common.h>
#include <preload_partition.h>
#include <avb_persist.h>

static uint32_t g_vb_custom_key_exist = 0;
extern PersistDescriptor *g_persist_des;

uint8_t g_avb_key[AVB_PUBK_SZ] = {AVB_PUBK};

static int32_t abs(int64_t x)
{
	return x > 0 ? x : -x;
}

AvbIOResult get_abs_offset(const char *partition,
				  int64_t offset,
				  uint64_t *abs_offset)
{
	uint64_t part_sz = 0;
	int64_t tmp_size = 0;

	if (partition == NULL ||  abs_offset == NULL)
		return AVB_IO_RESULT_ERROR_IO;

	*abs_offset = 0;
	tmp_size = partition_get_size_by_name(partition);
	if (tmp_size < 0)
		return AVB_IO_RESULT_ERROR_NO_SUCH_PARTITION;

	part_sz = (uint64_t)tmp_size;

	if (offset < 0) {
		if ((uint64_t)abs(offset) > part_sz)
			return AVB_IO_RESULT_ERROR_RANGE_OUTSIDE_PARTITION;
		*abs_offset = part_sz - abs(offset);
	} else
		*abs_offset = offset;

	return AVB_IO_RESULT_OK;
}

uint32_t vb_custom_key_exist(void)
{
	return g_vb_custom_key_exist;
}

AvbIOResult avb_hal_read_from_partition(AvbOps *ops,
					const char *partition,
					int64_t offset,
					size_t num_bytes,
					void *buffer,
					size_t *out_num_read)
{
	uint64_t abs_offset = 0;
	uint32_t part_err = 0;
	ssize_t read_len = 0;
	AvbIOResult ret = AVB_IO_RESULT_OK;

	if (partition == NULL || buffer == NULL || out_num_read == NULL)
		return AVB_IO_RESULT_ERROR_IO;

	ret = get_abs_offset(partition, offset, &abs_offset);
	if (ret != AVB_IO_RESULT_OK)
		return ret;

	read_len = partition_read(partition, abs_offset, buffer,
				  num_bytes);

	if (read_len < 0) {
		part_err = get_last_error();
		if (part_err == ERR_PART_GENERAL_NOT_EXIST)
			return AVB_IO_RESULT_ERROR_NO_SUCH_PARTITION;
		else if (part_err == ERR_PART_GENERAL_INVALID_RANGE)
			return AVB_IO_RESULT_ERROR_RANGE_OUTSIDE_PARTITION;
		else
			return AVB_IO_RESULT_ERROR_IO;
	} else
		*out_num_read = (size_t)read_len;

	return AVB_IO_RESULT_OK;
}

AvbIOResult avb_hal_get_preloaded_partition(AvbOps* ops,
                                         const char* partition,
                                         size_t num_bytes,
                                         uint8_t** out_pointer,
                                         size_t* out_num_bytes_preloaded)
{
	AvbIOResult ret = AVB_IO_RESULT_OK;
	uint32_t preload_ret = 0;
	uint32_t preload_addr = 0;
	uint32_t preload_sz = 0;

	if (partition == NULL ||
		out_pointer == NULL ||
		out_num_bytes_preloaded == NULL) {
		return AVB_IO_RESULT_ERROR_IO;
	}

	/* the expected behavior is to copy from preloaded partition to
	 * buffer allocated here and assigned to *out_pointer. We don't
	 * allocate buffer here actually. Instead, we set *out_pointer
	 * to load address of preloaded partition */
	preload_ret = get_preload_partition_addr_sz(partition, &preload_addr, &preload_sz);
	if (preload_ret) {
		pal_log_err("use storage partition(%s)\n", partition);
		*out_pointer = NULL;
		*out_num_bytes_preloaded = 0;
	} else {
		pal_log_err("use preloaded partition(%s)\n", partition);
		if (num_bytes > preload_sz)
			return AVB_IO_RESULT_ERROR_RANGE_OUTSIDE_PARTITION;
		*out_pointer = (uint8_t *)(uint32_t)preload_addr;
		*out_num_bytes_preloaded = num_bytes;
	}

	return ret;
}

AvbIOResult avb_hal_write_to_partition(AvbOps *ops,
				       const char *partition,
				       int64_t offset,
				       size_t num_bytes,
				       const void *buffer)
{
	uint64_t abs_offset = 0;
	uint32_t part_err = 0;
	ssize_t write_len = 0;
	AvbIOResult ret = AVB_IO_RESULT_OK;

	if (partition == NULL || buffer == NULL)
		return AVB_IO_RESULT_ERROR_IO;

	ret = get_abs_offset(partition, offset, &abs_offset);
	if (ret != AVB_IO_RESULT_OK)
		return ret;

	write_len = partition_write(partition, abs_offset, (uint8_t *)buffer,
				    num_bytes);

	if (write_len < 0) {
		part_err = get_last_error();
		if (part_err == ERR_PART_GENERAL_NOT_EXIST)
			return AVB_IO_RESULT_ERROR_NO_SUCH_PARTITION;
		else if (part_err == ERR_PART_GENERAL_INVALID_RANGE)
			return AVB_IO_RESULT_ERROR_RANGE_OUTSIDE_PARTITION;
		else
			return AVB_IO_RESULT_ERROR_IO;
	}

	return AVB_IO_RESULT_OK;
}

AvbIOResult avb_hal_verify_public_key(AvbOps *ops,
				      const uint8_t *public_key_data,
				      size_t public_key_length,
				      const uint8_t *public_key_metadata,
				      size_t public_key_metadata_length,
				      bool *out_is_trusted)
{
	AvbRSAPublicKeyHeader *key_hdr;
	uint8_t *pubk;
	uint32_t i = 0;
	uint32_t pubk_sz = 0;
	AvbIOResult ret = AVB_IO_RESULT_OK;

	if (out_is_trusted == NULL || public_key_data == NULL)
		return AVB_IO_RESULT_ERROR_IO;

	key_hdr = (AvbRSAPublicKeyHeader *)public_key_data;
	pubk = (uint8_t *)(public_key_data + sizeof(AvbRSAPublicKeyHeader));
	pubk_sz = avb_htobe32(key_hdr->key_num_bits) / 8;

	*out_is_trusted = FALSE;
	if (pubk_sz != AVB_PUBK_SZ) {
		pal_log_err("invalid pubk size\n");
		goto end;
	}

#ifdef MTK_SECURITY_SW_SUPPORT
	if (sec_set_pubk(pubk, pubk_sz) != STATUS_OK) {
		pal_log_err("[%s] fails to set public key\n", __func__);
		return AVB_IO_RESULT_ERROR_IO;
	}
#endif

	if (0 == memcmp((void *)g_avb_key, (void *)pubk, pubk_sz))
		*out_is_trusted = TRUE;
	else {
#ifdef MTK_SECURITY_YELLOW_STATE_SUPPORT
		*out_is_trusted = TRUE;
		g_vb_custom_key_exist = 1;
#else
		pal_log_err("oem_avb_key =\n");
		for (i = 0; i < AVB_PUBK_SZ; i++) {
			pal_log_err("0x%x ", g_avb_key[i]);
			if (((i + 1) % 16) == 0)
				pal_log_err("\n");
		}
		pal_log_err("vbmeta_avb_key =\n");
		for (i = 0; i < AVB_PUBK_SZ; i++) {
			pal_log_err("0x%x ", pubk[i]);
			if (((i + 1) % 16) == 0)
				pal_log_err("\n");
		}
#endif
	}

end:
	return ret;
}

AvbIOResult avb_hal_read_rollback_index(AvbOps *ops,
					size_t rollback_index_location,
					uint64_t *out_rollback_index)
{
#ifdef MTK_SECURITY_ANTI_ROLLBACK
	uint32_t ret = 0;
	uint32_t tmp_ver = 0;
#endif
	if (out_rollback_index == NULL)
		return AVB_IO_RESULT_ERROR_IO;

	*out_rollback_index = 0;

#ifdef MTK_SECURITY_ANTI_ROLLBACK
	/* get otp version of AVB group*/
	ret = get_avb_otp_ver(AVB_GROUP, &tmp_ver);
	if (ret)
		return AVB_IO_RESULT_ERROR_IO;

#ifdef MTK_OTP_FRAMEWORK_V2
/* If AB system is enabled, otp field for recovery group is unused
 * since there is no recovery image.
 */
#ifndef MTK_AB_OTA_UPDATER
	if (rollback_index_location == RECOVERY_ROLLBACK_INDEX) {
	/* get otp version of recovery group */
		ret = get_avb_otp_ver(RECOVERY_GROUP, &tmp_ver);
		if (ret)
			return AVB_IO_RESULT_ERROR_IO;
	}
#endif
#endif

	*out_rollback_index = (uint64_t)tmp_ver;
#endif

	return AVB_IO_RESULT_OK;
}

AvbIOResult avb_hal_write_rollback_index(AvbOps *ops,
		size_t rollback_index_location,
		uint64_t rollback_index)
{
	AvbIOResult ret = AVB_IO_RESULT_OK;

	/* otp update process is not implemented here. */

	return ret;
}

AvbIOResult avb_hal_read_is_device_unlocked(AvbOps *ops, bool *out_is_unlocked)
{
	uint32_t ret = 0;
	uint32_t lock_state = LKS_DEFAULT;

	if (out_is_unlocked == NULL)
		return AVB_IO_RESULT_ERROR_IO;

	*out_is_unlocked = FALSE;

#ifdef MTK_SECURITY_SW_SUPPORT
	ret = get_lock_state(&lock_state);
	if (ret != 0)
		return AVB_IO_RESULT_ERROR_IO;

	if ((lock_state == LKS_DEFAULT) || (lock_state == LKS_MP_DEFAULT) ||
	    lock_state == LKS_LOCK)
		*out_is_unlocked = FALSE;
	else
		*out_is_unlocked = TRUE;
#else
	*out_is_unlocked = TRUE;
#endif
	pal_log_err("[AVB20] lock_state = 0x%x\n", lock_state);

	return AVB_IO_RESULT_OK;
}

AvbIOResult avb_hal_get_unique_guid_for_partition(AvbOps *ops,
		const char *partition,
		char *guid_buf,
		size_t guid_buf_size)
{
	uint8_t *part_uuid = NULL;

	if (partition == NULL || guid_buf == NULL)
		return AVB_IO_RESULT_ERROR_IO;

	if (guid_buf_size < PART_META_INFO_UUIDLEN)
		return AVB_IO_RESULT_ERROR_IO;

	if (partition_exists(partition) != PART_OK)
		return AVB_IO_RESULT_ERROR_NO_SUCH_PARTITION;

	part_uuid = partition_get_uuid_by_name(partition);
	if (part_uuid == NULL)
		return AVB_IO_RESULT_ERROR_IO;

	memcpy(guid_buf, part_uuid, PART_META_INFO_UUIDLEN);

	return AVB_IO_RESULT_OK;
}

AvbIOResult avb_hal_get_size_of_partition(AvbOps *ops,
		const char *partition,
		uint64_t *out_size_num_bytes)
{
	uint64_t size = 0;

	if (partition == NULL || out_size_num_bytes == NULL)
		return AVB_IO_RESULT_ERROR_IO;

	size = partition_get_size_by_name(partition);
	if (size == PART_NOT_EXIST)
		return AVB_IO_RESULT_ERROR_NO_SUCH_PARTITION;

	*out_size_num_bytes = (uint64_t)size;

	return AVB_IO_RESULT_OK;
}

AvbIOResult avb_hal_read_persistent_value(AvbOps *ops,
		const char *name,
		size_t buffer_sz,
		uint8_t *out_buffer,
		size_t *out_num_bytes_read)
{
	AvbIOResult ret = AVB_IO_RESULT_OK;
	uint32_t persist_des_idx = 0;
	uint32_t find = 0;

	if (name == NULL || out_buffer == NULL || out_num_bytes_read == NULL) {
		ret = AVB_IO_RESULT_ERROR_IO;
		goto end;
	}

	if (!get_init_persist_status()) {
		ret = AVB_IO_RESULT_ERROR_IO;
		goto end;
	}

	while (persist_des_idx < MAX_PERSIST_TAG_SZ &&
			g_persist_des[persist_des_idx].hdr.tag == PERSIST_TAG_MAGIC) {
		if (g_persist_des[persist_des_idx].hdr.key_sz == strlen(name)) {
			if (!avb_memcmp(g_persist_des[persist_des_idx].key,
							name, strlen(name))) {
				if (g_persist_des[persist_des_idx].hdr.value_sz > buffer_sz) {
					ret = AVB_IO_RESULT_ERROR_INSUFFICIENT_SPACE;
					goto end;
				}

				if (g_persist_des[persist_des_idx].value == NULL) {
					ret = AVB_IO_RESULT_ERROR_IO;
					goto end;
				}

				avb_memcpy(out_buffer, g_persist_des[persist_des_idx].value,
							g_persist_des[persist_des_idx].hdr.value_sz);
				*out_num_bytes_read = g_persist_des[persist_des_idx].hdr.value_sz;
				find = 1;
				break;
			}
		}

		persist_des_idx++;
	}

	if (find == 0) {
		ret = AVB_IO_RESULT_ERROR_NO_SUCH_VALUE;
		goto end;
	}

end:
	return ret;
}

AvbIOResult avb_hal_write_persistent_value(AvbOps *ops,
		const char* name,
        size_t value_sz,
        const uint8_t *value) {

	AvbIOResult ret = AVB_IO_RESULT_OK;
	uint32_t persist_des_idx = 0;
	uint32_t empty_tag_idx = MAX_PERSIST_TAG_SZ;
	uint32_t find = 0;
	uint8_t *new_buf = NULL;

	if (name == NULL || value == NULL) {
		ret = AVB_IO_RESULT_ERROR_IO;
		goto end;
	}

	if (!get_init_persist_status()) {
		ret = AVB_IO_RESULT_ERROR_IO;
		goto end;
	}

	while (persist_des_idx < MAX_PERSIST_TAG_SZ) {
		if (g_persist_des[persist_des_idx].hdr.tag == PERSIST_TAG_MAGIC &&
			g_persist_des[persist_des_idx].hdr.key_sz == strlen(name)) {

			if (!avb_memcmp(g_persist_des[persist_des_idx].key,
							name, strlen(name))) {
				if (g_persist_des[persist_des_idx].hdr.value_sz >= value_sz) {
					if (value_sz == 0) {
						/* delete this item */
						g_persist_des[persist_des_idx].hdr.tag = 0x0;
					}
					avb_memset(g_persist_des[persist_des_idx].value, 0x0,
								g_persist_des[persist_des_idx].hdr.value_sz);

					if (g_persist_des[persist_des_idx].value == NULL) {
						ret = AVB_IO_RESULT_ERROR_IO;
						goto end;
					}

					avb_memcpy(g_persist_des[persist_des_idx].value, value,
								value_sz);
					g_persist_des[persist_des_idx].hdr.value_sz = value_sz;

				} else {
					new_buf = avb_malloc(value_sz);
					if (new_buf == NULL) {
						ret = AVB_IO_RESULT_ERROR_OOM;
						goto end;
					}
					avb_memcpy(new_buf, value, value_sz);
					g_persist_des[persist_des_idx].value = new_buf;
				}
				find = 1;
				break;
			}

		} else if (g_persist_des[persist_des_idx].hdr.tag != PERSIST_TAG_MAGIC &&
					empty_tag_idx == MAX_PERSIST_TAG_SZ) {
			empty_tag_idx = persist_des_idx;
		}

		persist_des_idx++;
	}

	/* create a new item */
	if (find == 0) {
		if (empty_tag_idx >= MAX_PERSIST_TAG_SZ) {
			ret = AVB_IO_RESULT_ERROR_OOM;
			goto end;
		}
		pal_log_info("[AVB] create a new persist item...\n");
		g_persist_des[empty_tag_idx].hdr.tag = PERSIST_TAG_MAGIC;
		g_persist_des[empty_tag_idx].hdr.key_sz = strlen(name);
		g_persist_des[empty_tag_idx].hdr.value_sz = value_sz;
		new_buf = avb_malloc(strlen(name));
		if (new_buf == NULL) {
			ret = AVB_IO_RESULT_ERROR_OOM;
			goto end;
		}
		avb_memcpy(new_buf, name, strlen(name));
		g_persist_des[empty_tag_idx].key = new_buf;

		new_buf = avb_malloc(value_sz);
		if (new_buf == NULL) {
			ret = AVB_IO_RESULT_ERROR_OOM;
			goto end;
		}
		avb_memcpy(new_buf, value, value_sz);
		g_persist_des[empty_tag_idx].value = new_buf;
	}

	set_update_persist_status();

end:
	return ret;
}

AvbOps ops = {
	.user_data = NULL,
	.ab_ops = NULL,
	.atx_ops = NULL,
	.read_from_partition = avb_hal_read_from_partition,
#ifdef PRELOAD_PARTITION_SUPPORT
	.get_preloaded_partition = avb_hal_get_preloaded_partition,
#else
	.get_preloaded_partition = NULL,
#endif
	.write_to_partition = avb_hal_write_to_partition,
	.validate_vbmeta_public_key = avb_hal_verify_public_key,
	.read_rollback_index = avb_hal_read_rollback_index,
	.write_rollback_index = avb_hal_write_rollback_index,
	.read_is_device_unlocked = avb_hal_read_is_device_unlocked,
	.get_unique_guid_for_partition = avb_hal_get_unique_guid_for_partition,
	.get_size_of_partition = avb_hal_get_size_of_partition,
#ifdef AVB_PERSIST_VALUE_SUPPORT
	.read_persistent_value = avb_hal_read_persistent_value,
	.write_persistent_value = avb_hal_write_persistent_value
#else
	.read_persistent_value = NULL,
	.write_persistent_value = NULL
#endif
};

