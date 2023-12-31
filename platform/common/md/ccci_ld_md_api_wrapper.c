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

#include <sys/types.h>
#include <stdint.h>
#include <platform/partition.h>
#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <platform/errno.h>
#include <printf.h>
#include <string.h>
#include <malloc.h>
#include <libfdt.h>
#include <platform/mt_gpt.h>
#include <platform/sec_export.h>
#include <debug.h>
#include "ccci_ld_md_core.h"
#include "ccci_ld_md_errno.h"
#ifdef MBLOCK_LIB_SUPPORT
#include <mblock.h>
#endif
#ifdef MTK_AB_OTA_UPDATER
#include "bootctrl.h"
#endif
#include <assert.h>
#include <block_generic_interface.h>
#include <part_interface.h>
#include <part_status.h>

#define MODULE_NAME "LK_LD_MD"


/***************************************************************************************************
** Sub section:
**   Memory operation: Reserve, Resize, Return
***************************************************************************************************/
extern BOOT_ARGUMENT *g_boot_arg;
static int free_in_kernel;

int ccci_resize_reserve_mem(unsigned char *addr, int old_size, int new_size)
{
	return mblock_resize(&g_boot_arg->mblock_info, &g_boot_arg->orig_dram_info, (u64)(unsigned long)addr,
	                     (u64)old_size, (u64)new_size);
}

/* This function will export to platform code to use */
static void *ccci_request_mem_v0(unsigned int mem_size, unsigned long long limit, unsigned long align)
{
	void *resv_addr;
#if defined(MBLOCK_EXPAND) && defined(MBLOCK_LIB_SUPPORT) && (MBLOCK_EXPAND(MBLOCK_LIB_SUPPORT) == MBLOCK_EXPAND(2))
	resv_addr = (void *)((unsigned long)mblock_reserve_ext(&g_boot_arg->mblock_info, mem_size, align, limit, 0, "ccci"));
#else
	resv_addr = (void *)((unsigned long)mblock_reserve(&g_boot_arg->mblock_info, mem_size, align, limit, RANKMAX));
#endif
	ALWAYS_LOG("request size: 0x%08x, get start address: %p\n", mem_size, resv_addr);
	return resv_addr;
}

#if defined(MBLOCK_EXPAND)
#if defined(MBLOCK_LIB_SUPPORT) && (MBLOCK_EXPAND(MBLOCK_LIB_SUPPORT) == MBLOCK_EXPAND(2))
static void *ccci_request_memext(unsigned int mem_size, unsigned long long limit, unsigned long align)
{
	void *resv_addr;
	resv_addr = (void *)((unsigned long)mblock_reserve_ext(&g_boot_arg->mblock_info, mem_size, align, limit, 1, "ccci"));
	ALWAYS_LOG("request size: 0x%08x, get start address: %p\n", mem_size, resv_addr);
	return resv_addr;
}
#endif
#endif

void *ccci_request_mem(unsigned int mem_size, unsigned long long limit, unsigned long align)
{
	return ccci_request_mem_v0(mem_size, limit, align);
}

void *ccci_request_resv_memory(unsigned int mem_size, unsigned long long limit, unsigned long align)
{
	if (free_in_kernel)
		return ccci_request_memext(mem_size, limit, align);
	return ccci_request_mem_v0(mem_size, limit, align);
}

void *ccci_request_named_mem(char *name, unsigned int mem_size, unsigned long long limit, unsigned long align)
{
	void *resv_addr;

	if (free_in_kernel) {
		resv_addr = (void *)((unsigned long)mblock_reserve_ext(&g_boot_arg->mblock_info, mem_size, align, limit, 1, name));
		ALWAYS_LOG("name[%s] request size: 0x%08x, get start address: %p\n", name, mem_size, resv_addr);
		return resv_addr;
	}
	return ccci_request_mem_v0(mem_size, limit, align);
}

//#define TAG_MAX_LK_INFO_SIZE	(0x10000)
#define TAG_MEM_ALIGNMENT	(0x1000L)
#define TAG_MEM_LIMIT		 (0xA0000000LL)

__WEAK int get_mem_limit_and_align(char name[], unsigned long long *limit,
	unsigned long *align)
{

	long long plat_query_ret;

	ALWAYS_LOG("get limit and align weak func\r\n");

	if (strcmp(name, "ccci_tag_mem") == 0) {
		*limit = TAG_MEM_LIMIT;
		*align = TAG_MEM_ALIGNMENT;
		return 0;
	} else if ((strcmp(name, "md1rom") == 0) || (strcmp(name, "md3rom") == 0)) {

		plat_query_ret = ccci_hal_get_ld_md_plat_setting("ro_rw_mem_limit");
		if (plat_query_ret <= 0) {
			ALWAYS_LOG("ro rw mem limit abnormal:%d\n", (int)plat_query_ret);
			//err_code = -LD_ERR_PT_ALLOC_RORW_MEM_FAIL;
			return -1;
		}
		*limit = (unsigned long long)plat_query_ret;

		plat_query_ret = ccci_hal_get_ld_md_plat_setting("ro_rw_mem_align");

		if (plat_query_ret <= 0) {
			ALWAYS_LOG("align abnormal for ro rw:%d\n", (int)plat_query_ret);
			//err_code = -LD_ERR_PT_ALIGN_SETTING_ABNORMAL;
			//update_md_err_to_lk_info(MD_SYS1, err_code);
			return -1;
		}
		*align = (unsigned long)plat_query_ret;

	} else if ((strcmp(name, "md_smem_cache") == 0) || (strcmp(name, "md_smem_ncache") == 0)) {
		plat_query_ret = ccci_hal_get_ld_md_plat_setting("share_mem_limit");

		if (plat_query_ret <= 0) {
			ALWAYS_LOG("limit abnormal:%d\n", (int)plat_query_ret);
			//err_code = -LD_ERR_PT_LIMIT_SETTING_ABNORMAL;
			return -1;
		}
		*limit = (unsigned long long)plat_query_ret;

		plat_query_ret = ccci_hal_get_ld_md_plat_setting("share_mem_align");

		if (plat_query_ret <= 0) {
			ALWAYS_LOG("align abnormal:%d\n", (int)plat_query_ret);
			//err_code = -LD_ERR_PT_ALIGN_SETTING_ABNORMAL;
			return -1;
		}
		*align = (unsigned long)plat_query_ret;
	}
	return 0;
}

void *resv_named_memory(char name[], unsigned int size)
{
	unsigned long long limit;
	unsigned long align;

	if(get_mem_limit_and_align(name, &limit, &align) < 0) {
		ALWAYS_LOG("get limit and align fail for %s\r\n", name);
		return NULL;
	}

	return ccci_request_named_mem(name, size, limit, align);
}


int ccci_retrieve_mem(unsigned char *addr, int size)
{
	ALWAYS_LOG("  0x%xB retrieved by AP\n", (int)size);
	log_retrieve_info(addr, size);
#if defined(MBLOCK_EXPAND)
#if defined(MBLOCK_LIB_SUPPORT) && (MBLOCK_EXPAND(MBLOCK_LIB_SUPPORT) == MBLOCK_EXPAND(2))
	/*don't retrieve in lk, leave it to kernel.*/
#else
	return mblock_create(&g_boot_arg->mblock_info, &g_boot_arg->orig_dram_info, (u64)(unsigned long)addr,(u64)size);
#endif
#else
	return mblock_create(&g_boot_arg->mblock_info, &g_boot_arg->orig_dram_info, (u64)(unsigned long)addr,(u64)size);
#endif
	return 0;
}


int ccci_free_not_used_reserved_memory(unsigned char *md_start_addr, int reserved, int required)
{
	ALWAYS_LOG("md memory require:0x%x, reserved:0x%x\n", required, reserved);

	/* Resize if acutal memory less then reserved*/
	if (required == 0) {
		ALWAYS_LOG("free default reserved\n");
		return mblock_create(&g_boot_arg->mblock_info, &g_boot_arg->orig_dram_info,
			(u64)(unsigned long)md_start_addr,(u64)reserved);
	} else if (required < reserved) {
		/* Resize reserved memory */
		if (free_in_kernel)
			ccci_retrieve_mem((unsigned char*)(md_start_addr + required), reserved - required);
		else
			ccci_resize_reserve_mem(md_start_addr, reserved, required);
	}
	return required;
}



/***************************************************************************************************
** Sub section:
**   Load raw data from partition, support function
***************************************************************************************************/
#ifdef MTK_AB_OTA_UPDATER
static  char *ab_suffix;
#endif
int ccci_load_raw_data(char *part_name, unsigned char *mem_addr, unsigned int offset, int size)
{
	int len;
#if defined(MTK_EMMC_SUPPORT) || defined(MTK_UFS_SUPPORT)
	u64 __attribute__((unused))storage_start_addr;
#else
	unsigned long __attribute__((unused))storage_start_addr;
#endif
#ifdef MTK_AB_OTA_UPDATER
	char partition_name[32];
#endif

	LD_DBG_LOG("ccci_load_raw_data, name[%s], mem_addr[%p], offset[%x], size[%x]\n",
					part_name, mem_addr, offset, size);

	if (partition_exists(part_name) != PART_OK) {
		ALWAYS_LOG("partition %s not exists\n", part_name);
		return -LD_ERR_PT_NOT_FOUND;
	}

	storage_start_addr = partition_get_offset_by_name(part_name);
	LD_DBG_LOG("image[%s](%d) addr is 0x%llx in partition\n", part_name, offset, (u64)storage_start_addr);
	LD_DBG_LOG(" > to 0x%llx (at dram), size:0x%x\n",(u64)((unsigned long)mem_addr), size);

	len = partition_read(part_name, offset, mem_addr, size);
	if (len < 0) {
		ALWAYS_LOG("[%s] %s boot image header read error. LINE: %d\n", MODULE_NAME, part_name, __LINE__);
		return -LD_ERR_PT_READ_RAW_FAIL;
	}

	return len;
}


void ccci_ld_md_wrapper_api_init(void)
{
	free_in_kernel = 0;
#if defined(MBLOCK_EXPAND)
#if defined(MBLOCK_LIB_SUPPORT) && (MBLOCK_EXPAND(MBLOCK_LIB_SUPPORT) == MBLOCK_EXPAND(2))
	free_in_kernel = 1;
	ALWAYS_LOG("free_in_kernel = %d\n", free_in_kernel);
#endif
#endif

#ifdef MTK_AB_OTA_UPDATER
	/* get partition "_a"/"_b" suffix */
	ab_suffix = get_suffix();
#endif
}


/* This function should be called after ccci_tag_info function ready */
void ccci_ld_md_add_wrapper_api_info(void)
{
#if defined(MBLOCK_EXPAND)
#if defined(MBLOCK_LIB_SUPPORT) && (MBLOCK_EXPAND(MBLOCK_LIB_SUPPORT) == MBLOCK_EXPAND(2))
	if (insert_ccci_tag_inf("free_in_kernel", (char*)&free_in_kernel, sizeof(unsigned int)) < 0)
		ALWAYS_LOG("insert free_in_kernel fail\n");
#endif
#endif
}
