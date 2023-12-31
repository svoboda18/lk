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
#include <malloc.h>
#include <spm_common.h>
#include <platform/mt_typedefs.h>
#include <debug.h>
#include <platform/errno.h>
#include <platform/partition.h>
#include <block_generic_interface.h>
#include <part_interface.h>
#include <storage_api.h>
#include <platform/boot_mode.h>
#include <assert.h>
#include <img_info.h>
#include <platform/mt_gpt.h>
#include <platform/mtk_wdt.h>
#include <verified_boot_common.h>
#include <platform/verified_boot.h>
#include <platform/sec_policy.h>
#include <arch/ops.h>
#include <libfdt.h>

#ifdef MTK_AB_OTA_UPDATER
#include <mt_boot.h>
#endif

#define SPM_MEM_SIZE   0x00010000  // 64K
#define SPM_MEM_ALIGN  0x00010000  // 64K (minimal size for EMI MPU)
#define SPM_MEM_LIMIT  0x78000000
extern BOOT_ARGUMENT *g_boot_arg;
static uint64_t spmfw_base_addr = 0;
#ifdef MTK_SMC_ID_MGMT
#include "mtk_secure_api.h"
#else
#define MTK_SIP_KERNEL_SPM_ARGS 0x8200022A
extern unsigned long mt_secure_call(unsigned long, unsigned long, unsigned long, unsigned long);
#endif
#define SPM_ARGS_SPMFW_INIT 1
extern int mboot_common_load_part(char *part_name, char *img_name, unsigned long addr);

#ifdef SPM_FW_USE_PARTITION
#ifdef DEVICE_TREE_SUPPORT
#define PCM_FIRMWARE_VERSION_SIZE 128
int platform_fdt_spm(void *fdt)
{
	int nodeoffset;
	int offset = 0;
	uint64_t *addr = NULL;
	char *name;
	struct spm_fw_header *header;
	char version[PCM_FIRMWARE_VERSION_SIZE];

	nodeoffset = fdt_path_offset(fdt, "/sleep");
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "/sleep not found. LINE: %d\n", __LINE__);
		return 1; /* return 1, if fail */
	}

	if (spmfw_base_addr == 0)
		return 1; /* return 1, if fail */

	/* Add properties in "/sleep" */
	name = "spmfw_version";

	addr = (uint64_t *)(uintptr_t)spmfw_base_addr;
	header = (struct spm_fw_header *)addr;
	while (header->magic == SPM_FW_MAGIC) {
		unsigned short firmware_size = 0;
		char *ptr;

		ptr = (((char *) header) + sizeof(*header));
		memcpy(&firmware_size, ptr + offset, 2);

		offset += 2 + (firmware_size * 4);

#ifdef SPM_FW_USE_MD32
		offset += sizeof(struct pcm_desc) - offsetof(struct pcm_desc, pmem_words);
#else
		offset += sizeof(struct pcm_desc) - offsetof(struct pcm_desc, size);
#endif

		snprintf(version, PCM_FIRMWARE_VERSION_SIZE - 1,
				"%s", ptr + offset);

		dprintf(CRITICAL, "spmfw version: %s\n", version);
		if (fdt_appendprop_string(fdt, nodeoffset, name, version) != 0)
			return 1; /* return 1, if fail */

		/* check next spmfw version */
		header = (struct spm_fw_header *) (((char *) header) + sizeof(*header) + header->size);
		offset = 0;
	}
	return 0; /* return 0, if success */
}
#endif
void get_spmfw_version(char *part_name, char *img_name, char *buf, int *wp)
{
	long len;
	void *ptr;
	union mkimg_hdr part_hdr_buf;
	union mkimg_hdr *img_hdr = &part_hdr_buf;
	u64 offset, offset_ver, part_size;
	long blksz;
	struct spm_fw_header *header;
	int idx = 0;

	if (partition_exists(part_name) != PART_OK) {
		return;
	}

	blksz = storage_get_blksz();
	ptr = malloc(blksz * 2);

	if (!ptr)
		return;

	part_size = partition_get_size_by_name(part_name);

	offset = 0;

	len = partition_read(part_name, offset, (uchar*)img_hdr, sizeof(union mkimg_hdr));
	if (len < 0) {
		dprintf(CRITICAL, "%s partition read error. LINE: %d\n", part_name, __LINE__);
		goto err;
	}

	img_hdr->info.name[31]='\0'; //append end char
	dprintf(CRITICAL, "\n=========================================\n");
	dprintf(CRITICAL, "%s magic number : 0x%x\n", part_name, img_hdr->info.magic);
	dprintf(CRITICAL, "%s name         : %s\n", part_name, img_hdr->info.name);
	dprintf(CRITICAL, "%s size         : %d\n", part_name, img_hdr->info.dsz);
	dprintf(CRITICAL, "=========================================\n");

	//***************
	//* check partition magic
	//*
	if (img_hdr->info.magic != MKIMG_MAGIC) {
		dprintf(CRITICAL, "%s partition magic error\n", part_name);
		goto err;
	}

	offset += sizeof(union mkimg_hdr);

	while (1) {
		unsigned int arg_size;
		unsigned short size;

		if (offset + blksz * 2 > part_size) {
			dprintf(CRITICAL, "%s partition read over size. LINE: %d\n", part_name, __LINE__);
			break;
		}

		len = partition_read(part_name, align_sz(offset, blksz), (uchar*)ptr, blksz * 2);

		if (len < 0) {
			dprintf(CRITICAL, "%s partition read error. LINE: %d\n", part_name, __LINE__);
			break;
		}

		header = (struct spm_fw_header *)(ptr + offset % blksz);

		if (header->magic != SPM_FW_MAGIC) {
			break;
		}
		dprintf(CRITICAL, "header->name %s\n", header->name);

		offset_ver = offset;
		offset += (sizeof(*header) + header->size);

		size = DRV_Reg16(ptr + offset_ver % blksz + sizeof(*header)) * SPM_FW_UNIT;
#ifdef SPM_FW_USE_MD32
		arg_size = sizeof(struct pcm_desc) - offsetof(struct pcm_desc, pmem_words);
#else
		arg_size = sizeof(struct pcm_desc) - offsetof(struct pcm_desc, size);
#endif
		offset_ver += (sizeof(*header) + 2 + size + arg_size);

		if (offset_ver + blksz * 2 > part_size) {
			dprintf(CRITICAL, "%s partition read over size. LINE: %d\n", part_name, __LINE__);
			break;
		}

		len = partition_read(part_name, align_sz(offset_ver, blksz), (uchar*)ptr, blksz * 2);

		if (len < 0) {
			dprintf(CRITICAL, "%s partition read error. LINE: %d\n", part_name, __LINE__);
			break;
		}

		idx++;
		*wp += sprintf(buf + *wp, "SPM firmware version(0x%x) = %s\n",
				idx, (char *)(ptr + offset_ver % blksz));
		dprintf(CRITICAL, "SPM firmware version(0x%x) = %s\n",
				idx, (char *)(ptr + offset_ver % blksz));
	}

err:
	if (ptr)
		free(ptr);
}

int load_spm(void)
{
	int ret, fw_size;
#ifdef MTK_SECURITY_SW_SUPPORT
	unsigned int img_auth_required = 0;
	unsigned int policy_entry_idx = 0;
	unsigned int img_vfy_time = 0;
	u32 sec_ret = 0;
#endif
	char part_name[16] = "spmfw";

#ifdef MTK_AB_OTA_UPDATER
	get_AB_OTA_name((char *)&part_name, sizeof(part_name));
#endif /* MTK_AB_OTA_UPDATER */

	spmfw_base_addr = mblock_reserve_ext(&g_boot_arg->mblock_info, SPM_MEM_SIZE, SPM_MEM_ALIGN, SPM_MEM_LIMIT, 0, "SPM-reserved");

	dprintf(INFO, "[spmfw] addr=0x%llx size=0x%x\n", spmfw_base_addr, SPM_MEM_SIZE);

	if (spmfw_base_addr == 0)
		goto error;

#ifdef MTK_SECURITY_SW_SUPPORT
	img_vfy_time = get_timer(0);
	policy_entry_idx = get_policy_entry_idx("spmfw");
	img_auth_required = get_vfy_policy(policy_entry_idx);
	if (img_auth_required) {
		mtk_wdt_restart();
		sec_ret = sec_img_auth_init(part_name, "spmfw", 0);
		if (sec_ret) {
			dprintf(CRITICAL, "%s cert vfy fail...(0x%x)\n", part_name, sec_ret);
			red_state_warning("spmfw");
			assert(0);
		}
		dprintf(INFO, "[SBC] %s cert vfy(%d ms)\n", part_name, (unsigned int)get_timer(img_vfy_time));

#ifdef MTK_SECURITY_ANTI_ROLLBACK
		sec_ret = sec_rollback_check(1);
		if (sec_ret) {
			dprintf(CRITICAL, "spmfw ver check fail...(0x%x)\n", sec_ret);
			assert(0);
		}
#endif
	}
#endif

	ret = mboot_common_load_part(part_name, "spmfw", spmfw_base_addr);
	if (ret < 0) {
		dprintf(CRITICAL, "[spmfw] load spmfw fail, ret = %d\n", ret);
		goto error;
	}
	fw_size = ret;
	dprintf(INFO, "[spmfw] image size = %d\n", fw_size);

	/* Sync cache to make sure all data flush to DRAM */
	arch_sync_cache_range((addr_t)spmfw_base_addr, SPM_MEM_SIZE);

#ifdef MTK_SECURITY_SW_SUPPORT
	if (img_auth_required) {
		mtk_wdt_restart();
		img_vfy_time = get_timer(0);
		sec_ret = sec_img_auth((u8 *)((u32)spmfw_base_addr), fw_size);
		if (sec_ret) {
			dprintf(CRITICAL, "image %s vfy fail...(0x%x)\n", part_name, sec_ret);
			assert(0);
		}
		dprintf(INFO, "[SBC] img vfy(%d ms)\n", (unsigned int)get_timer(img_vfy_time));
	} else
		dprintf(CRITICAL, "[SBC] img vfy disabled\n");
#endif

	dprintf(INFO, "[spmfw] before smc call\n");
#ifdef MTK_SMC_ID_MGMT
	mt_secure_call(MTK_SIP_KERNEL_SPM_ARGS, SPM_ARGS_SPMFW_INIT, spmfw_base_addr, SPM_MEM_SIZE, 0);
#else
	mt_secure_call(MTK_SIP_KERNEL_SPM_ARGS, SPM_ARGS_SPMFW_INIT, spmfw_base_addr, SPM_MEM_SIZE);
#endif
	dprintf(INFO, "[spmfw] after smc call\n");

	return 0;

error:
	return -1;
}

#endif /* SPM_FW_USE_PARTITION */

