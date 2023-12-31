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

#include <pal_typedefs.h>
#include <pal_log.h>
#include <pal_assert.h>
#include <verified_boot_error.h>
#include <avb_persist.h>
#include <part_status.h>
#include <avb_slot_verify.h>
#include <avb_ops.h>
#include <avb_util.h>
#include <avb_hal.h>
#include <part_interface.h>

PersistDescriptor *g_persist_des;
uint64_t g_persist_offset = 0;
uint32_t g_init_persist_area = 0;
uint32_t g_pre_alloc_sz = 0;
uint32_t g_update_persist = 0;
uint32_t g_persist_value_total_sz = 0;

bool save_to_add(uint32_t ori, uint32_t value_to_add, uint32_t boundary)
{
	if ((ori + value_to_add) > boundary || (ori + value_to_add) < ori)
		return 0;

	return 1;
}

void set_update_persist_status(void)
{
	g_update_persist = 1;
}

bool get_update_persist_status(void)
{
	return g_update_persist;
}

bool get_init_persist_status(void)
{
	if (g_init_persist_area)
		return 1;
	else
		return 0;
}

void avb_persist_descriptor_to_host_byte_order(PersistDescriptorHdr *buf, PersistDescriptorHdr *des)
{
	if (buf == NULL || des == NULL)
		return;

	avb_memcpy(des, buf, sizeof(PersistDescriptorHdr));

	des->tag = avb_be32toh(des->tag);
	des->key_sz = avb_be32toh(des->key_sz);
	des->value_sz = avb_be32toh(des->value_sz);
}

void avb_persist_descriptor_to_slave_byte_order(PersistDescriptorHdr *buf, PersistDescriptorHdr *des)
{
	if (buf == NULL || des == NULL)
		return;

	avb_memcpy(des, buf, sizeof(PersistDescriptorHdr));

	des->tag = avb_htobe32(des->tag);
	des->key_sz = avb_htobe32(des->key_sz);
	des->value_sz = avb_htobe32(des->value_sz);
}

void avb_persist_header_to_host_byte_order(PersistHdr *buf, PersistHdr *h)
{
	if (buf == NULL || h == NULL)
		return;

	avb_memcpy(h, buf, sizeof(h->info));
	h->info.magic = avb_be32toh(h->info.magic);
	h->info.major_ver = avb_be32toh(h->info.major_ver);
	h->info.minor_ver = avb_be32toh(h->info.minor_ver);
}

static uint32_t persist_value_validate(PersistHdr *buf, uint32_t *exist)
{
	uint32_t ret = 0;
	PersistHdr h;

	if (buf == NULL || exist == NULL) {
		ret = ERR_VB_INVALID_ADDR;
		goto end;
	}

	avb_persist_header_to_host_byte_order(buf, &h);
	*exist = 0;

	if (h.info.magic == PERSIST_MAGIC)
		*exist = 1;

end:
	return ret;
}

uint32_t create_persist_area(AvbOps *ops, char *part_name, uint64_t abs_offset, char *buf)
{
	uint32_t ret = 0;
	PersistHdr *h = NULL;
	AvbIOResult io_res;

	if (part_name == NULL || buf == NULL) {
		ret = ERR_VB_INVALID_ADDR;
		goto end;
	}

	avb_memset(buf, 0x0, sizeof(PersistHdr));

	h = (PersistHdr *)buf;

	h->info.magic = avb_htobe32(PERSIST_MAGIC);
	h->info.major_ver = avb_htobe32(PERSIST_MAJOR_VER);
	h->info.minor_ver = avb_htobe32(PERSIST_MINOR_VER);

	io_res = ops->write_to_partition(ops,
									 part_name,
									 abs_offset,
									 sizeof(PersistHdr),
									 h);
	if (io_res != AVB_IO_RESULT_OK) {
		pal_log_err("[AVB] Fail to write init persist value to %s.\n", part_name);
		ret = (uint32_t)io_res;
		goto end;
	}

end:
	return ret;
}

static uint32_t parse_persist_value(char *buf, uint32_t boundary)
{
	uint32_t ret = 0;

#if defined(MTK_SECURITY_SW_SUPPORT) && defined(AVB_PERSIST_VALUE_SUPPORT)
	PersistDescriptorHdr *pDes = NULL, info;
	uint32_t persist_des_idx = 0;
	uint32_t curr_locate = 0;

	if (buf == NULL) {
		ret = ERR_VB_INVALID_ADDR;
		goto end;
	}

	if (!save_to_add(curr_locate, sizeof(PersistHdr) + \
					sizeof(PersistDescriptorHdr), boundary))
		goto end;

	pDes = (PersistDescriptorHdr *)(buf + sizeof(PersistHdr));
	avb_persist_descriptor_to_host_byte_order(pDes, &info);
	curr_locate += sizeof(PersistHdr) + sizeof(PersistDescriptorHdr);

	while (info.tag == PERSIST_TAG_MAGIC) {
		g_persist_des[persist_des_idx].hdr.tag = info.tag;
		g_persist_des[persist_des_idx].hdr.key_sz = info.key_sz;
		g_persist_des[persist_des_idx].hdr.value_sz = info.value_sz;

		g_persist_des[persist_des_idx].key = avb_malloc(info.key_sz);
		if (g_persist_des[persist_des_idx].key == NULL) {
			ret = ERR_VB_INVALID_ADDR;
			goto end;
		}

		if (!save_to_add(curr_locate, info.key_sz, boundary)) {
			ret = ERR_VB_BUF_OVERFLOW;
			goto end;
		}

		avb_memcpy(g_persist_des[persist_des_idx].key, (buf + curr_locate), info.key_sz);
		curr_locate += info.key_sz;

		g_persist_des[persist_des_idx].value = avb_malloc(info.value_sz);
		if (g_persist_des[persist_des_idx].value == NULL) {
			ret = ERR_VB_INVALID_ADDR;
			goto end;
		}

		if (!save_to_add(curr_locate, info.value_sz, boundary)) {
			ret = ERR_VB_BUF_OVERFLOW;
			goto end;
		}

		avb_memcpy(g_persist_des[persist_des_idx].value, (buf + curr_locate), info.value_sz);
		curr_locate += info.value_sz;

		if (!save_to_add(curr_locate, sizeof(PersistDescriptorHdr), boundary))
			goto end;

		pDes = (PersistDescriptorHdr *)(buf + curr_locate);
		avb_persist_descriptor_to_host_byte_order(pDes, &info);
		curr_locate += sizeof(PersistDescriptorHdr);
		persist_des_idx++;
	}

	g_persist_value_total_sz = curr_locate - sizeof(PersistHdr);

end:
#endif

	return ret;
}

uint32_t write_persist_value(AvbOps *ops, char *part_name)
{
	uint32_t ret = 0;

#if defined(MTK_SECURITY_SW_SUPPORT) && defined(AVB_PERSIST_VALUE_SUPPORT)
	uint32_t persist_des_idx = 0;
	uint64_t curr_offset = 0;
	uint64_t part_sz = 0;
	uint64_t total_write_sz = 0;
	uint64_t redundant_sz = 0;
	uint8_t *tmp_buf = NULL;
	AvbIOResult io_res;
	PersistDescriptorHdr info;

	if (!get_init_persist_status()) {
		ret = ERR_AVB_UNINITIAL_PERSIST_VALUE;
		goto end;
	}

	if (!get_update_persist_status())
		goto end;

	/* get persist storage size in specific "partition" */
	part_sz = partition_get_size_by_name(part_name);
	if (part_sz == PART_NOT_EXIST) {
		ret = ERR_AVB_NO_SUCH_PARTITION;
		goto end;
	}

	if (!save_to_add(curr_offset, g_persist_offset + \
						sizeof(PersistHdr), part_sz)) {
		ret = ERR_VB_BUF_OVERFLOW;
		goto end;
	}

	curr_offset += (g_persist_offset + sizeof(PersistHdr));

	while (persist_des_idx < MAX_PERSIST_TAG_SZ) {
		if (g_persist_des[persist_des_idx].hdr.tag != PERSIST_TAG_MAGIC) {
			persist_des_idx++;
			continue;
		}

		avb_persist_descriptor_to_slave_byte_order(
								&g_persist_des[persist_des_idx].hdr, &info);
		io_res = ops->write_to_partition(ops,
								 part_name,
								 curr_offset,
								 sizeof(PersistDescriptorHdr),
								 &info);
		if (io_res != AVB_IO_RESULT_OK) {
			pal_log_err("Error writing to partition %s.\n", part_name);
			ret = (uint32_t)io_res;
			goto end;
		}

		curr_offset += sizeof(PersistDescriptorHdr);

		if (!save_to_add(curr_offset,
							g_persist_des[persist_des_idx].hdr.key_sz, part_sz)) {
			ret = ERR_VB_BUF_OVERFLOW;
			goto end;
		}

		io_res = ops->write_to_partition(ops,
								 part_name,
								 curr_offset,
								 g_persist_des[persist_des_idx].hdr.key_sz,
								 g_persist_des[persist_des_idx].key);

		if (io_res != AVB_IO_RESULT_OK) {
			pal_log_err("Error writing to partition %s.\n", part_name);
			ret = (uint32_t)io_res;
			goto end;
		}

		curr_offset += g_persist_des[persist_des_idx].hdr.key_sz;

		if (!save_to_add(curr_offset,
							g_persist_des[persist_des_idx].hdr.value_sz,
							part_sz)) {
			ret = ERR_VB_BUF_OVERFLOW;
			goto end;
		}

		io_res = ops->write_to_partition(ops,
								 part_name,
								 curr_offset,
								 g_persist_des[persist_des_idx].hdr.value_sz,
								 g_persist_des[persist_des_idx].value);
		if (io_res != AVB_IO_RESULT_OK) {
			pal_log_err("Error writing to partition %s.\n", part_name);
			ret = (uint32_t)io_res;
			goto end;
		}

		curr_offset += g_persist_des[persist_des_idx].hdr.value_sz;
		persist_des_idx++;
	}

	total_write_sz = curr_offset - g_persist_offset - sizeof(PersistHdr);
	if (total_write_sz < g_persist_value_total_sz) {
		redundant_sz = g_persist_value_total_sz - total_write_sz;
		tmp_buf = avb_malloc(redundant_sz);
		if (tmp_buf == NULL) {
			ret = AVB_IO_RESULT_ERROR_OOM;
			goto end;
		}

		avb_memset(tmp_buf, 0x0, redundant_sz);

		io_res = ops->write_to_partition(ops,
										 part_name,
										 curr_offset,
										 redundant_sz,
										 tmp_buf);
		if (io_res != AVB_IO_RESULT_OK) {
			pal_log_err("Error writing to partition %s.\n", part_name);
			ret = (uint32_t)io_res;
			goto end;
		}
	}

	pal_log_info("Write persist value to %s.\n", part_name);

end:
	if (tmp_buf != NULL)
		avb_free(tmp_buf);
#endif

	return ret;
}

uint32_t init_persist_value(AvbOps *ops, char *part_name, uint64_t offset)
{
	uint32_t ret = 0;

#if defined(MTK_SECURITY_SW_SUPPORT) && defined(AVB_PERSIST_VALUE_SUPPORT)

	uint64_t part_sz = 0;
	size_t read_len = 0;
	uint64_t abs_offset = 0;
	PersistHdr *buf = NULL;
	AvbIOResult io_res;
	uint32_t persist_exist = 0;

	if (part_name == NULL) {
		ret = ERR_VB_INVALID_ADDR;
		goto end;
	}

	/* get persist storage offset in specific "partition" */
	part_sz = partition_get_size_by_name(part_name);
	if (part_sz == PART_NOT_EXIST) {
		ret = ERR_AVB_NO_SUCH_PARTITION;
		goto end;
	}

	/* Check offset value. If offset is uninitial, we assume that persist
	 * value is stored at the offset is half of assigned partition size.
	 */
	g_persist_offset = offset;
	if (g_persist_offset == PERSIST_UNSPECIFIED_OFFSET) {
		pal_log_info("[AVB] Persist offset is half of partition \"%s\" size\n",
						part_name);
		g_persist_offset = ((part_sz / 2) + (PERSIST_ALIGN_SZ - 1)) /
							PERSIST_ALIGN_SZ * PERSIST_ALIGN_SZ;
	}

	if (g_persist_offset >= part_sz ||
		(g_persist_offset + sizeof(PersistHdr) + sizeof(PersistDescriptor)) > part_sz ||
		(g_persist_offset + sizeof(PersistHdr) + sizeof(PersistDescriptor)) <= g_persist_offset) {
		pal_log_err("[AVB] persist_offset = 0x%llx is invalid\n", g_persist_offset);
		ret = ERR_AVB_INVALID_OFFSET;
		goto end;
	}

	ret = (uint32_t)get_abs_offset(part_name, g_persist_offset, &abs_offset);
	if (ret != AVB_IO_RESULT_OK)
		goto end;

	/* Read persist area. If it does not exist, create a new one. */
	if ((part_sz - abs_offset) > DEFAULT_PERSIST_PREALLOC_BUF_SZ)
		g_pre_alloc_sz = DEFAULT_PERSIST_PREALLOC_BUF_SZ;
	else
		g_pre_alloc_sz = part_sz - abs_offset;

	buf = avb_malloc(g_pre_alloc_sz);
	if (buf == NULL) {
		ret = ERR_VB_INVALID_ADDR;
		goto end;
	}

	io_res = ops->read_from_partition(ops,
									part_name,
									abs_offset,
									g_pre_alloc_sz,
									buf,
									&read_len);
	if (io_res != AVB_IO_RESULT_OK) {
		pal_log_err("Error loading persist value from %s.\n", part_name);
		ret = (uint32_t)io_res;
		goto end;
	}

	ret = persist_value_validate(buf, &persist_exist);
	if (ret)
		goto end;

	g_persist_des = avb_malloc(sizeof(PersistDescriptor) * MAX_PERSIST_TAG_SZ);
	if (g_persist_des == NULL) {
		pal_log_err("g_persist_des NULL\n");
		ret = ERR_VB_INVALID_ADDR;
		goto end;
	}

	avb_memset(g_persist_des, 0x0, sizeof(PersistDescriptor) * MAX_PERSIST_TAG_SZ);

	if (!persist_exist) {
		ret = create_persist_area(ops, part_name, abs_offset, (char *)buf);
		if (ret)
			goto end;
	} else {
		ret = parse_persist_value((char *)buf, g_pre_alloc_sz);
		if (ret) {
			pal_log_err("Parse persist value fail. ret = 0x%x\n", ret);
			avb_memset(g_persist_des, 0x0, sizeof(PersistDescriptor) * MAX_PERSIST_TAG_SZ);
			ret = 0;
		}
	}

	g_init_persist_area = 1;

end:
	pal_log_info("[AVB] \"%s\" partition size = 0x%llx\n", part_name, part_sz);
	pal_log_info("[AVB] persist offset = 0x%llx\n", g_persist_offset);
	pal_log_info("[AVB] persist allocate size = 0x%x\n", g_pre_alloc_sz);
	pal_log_info("[AVB] persist area init end (%d).\n", g_init_persist_area);
	pal_log_info("[AVB] persist ret = 0x%x.\n", ret);

	if (buf != NULL)
		avb_free(buf);

#endif
	return ret;
}

