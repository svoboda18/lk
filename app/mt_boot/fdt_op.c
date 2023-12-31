/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2018. All rights reserved.
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
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <bootargs.h>
#include <errno.h>
#include <string.h>
#include <pal_assert.h>
#include <pal_typedefs.h>
#include <pal_log.h>
#include <memory_layout.h>
#include <libfdt.h>
#include <profiling.h>
#include <odm_mdtbo.h>
#include <boot_opt.h>
#include <boot_info.h>
#include <part_interface.h>
#include <ufdt_overlay.h>
#include <fdt_op.h>
#include <bootimg.h>
#include <mt_boot.h>
#include <arch/arm/mmu.h>
#include <load_vfy_boot.h>
#include <mt_rtc.h>
#include <part_interface.h>
#include <part_status.h>
#include <mkimg.h>
#include <platform/mt_gpt.h>
#include <odm_mdtbo.h>
#include <boot_info.h>
#include <platform/errno.h>
#include <lk_builtin_dtb.h>
#include <platform/verified_boot.h>

void *g_fdt;
DTBO_SRC g_dtbo_load_src = DTBO_FROM_STANDALONE;
extern u32 g_64bit_dtb_size;
extern int g_is_64bit_kernel;
extern char *p_AB_suffix;


#define DTBO_PART_NEW_A_NAME "dtbo_a"

static char *dtbo_one_part_name = "dtbo";
#ifndef MTK_AB_OTA_UPDATER
static char *dtbo_part_names[] = {"dtbo1", "dtbo2"};
#endif
static char *dtbo_fallback_part_name= "odmdtbo";
static char dtbo_part_name_full[DTBO_PART_NAME_LEN + 1];

extern int mboot_recovery_load_raw_part(char *part_name, unsigned long *addr, unsigned int size);
extern int unshield_recovery_detection(void);
extern int mboot_common_load_part(char *part_name, char *img_name, unsigned long addr);

DTBO_SRC get_dtbo_src(void)
{
	return g_dtbo_load_src;
}

void setup_kernel_fdt(void *fdt)
{
	g_fdt = fdt;
}
void *get_kernel_fdt(void)
{
	return g_fdt;
}
/***********************************************************************
* API to retrieve where dtbo partition from, the name is fallback iterated
************************************************************************/
char *get_dtbo_part_name(void)
{
	char *part_name = NULL;
	static uint32_t dtbo_part_name_inited = 0;

	if (!dtbo_part_name_inited) {
#ifdef MTK_AB_OTA_UPDATER
		part_name = dtbo_part_name_full;
		if (partition_exists(DTBO_PART_NEW_A_NAME) == PART_OK)
			strncpy(part_name,dtbo_one_part_name, DTBO_PART_NAME_LEN);
		else
			strncpy(part_name, dtbo_fallback_part_name, DTBO_PART_NAME_LEN);

		int part_name_len = strlen(part_name);
		if (p_AB_suffix) {
			strncpy((void *)&part_name[part_name_len], (void *)p_AB_suffix,
				DTBO_PART_NAME_LEN - part_name_len);
		}
#else
		int i;
		int array_size = (int)(sizeof(dtbo_part_names) / sizeof(dtbo_part_names[0]));

		/* check "dtbo" */
		if (partition_exists(dtbo_one_part_name) == PART_OK) {
			part_name = dtbo_one_part_name;
			goto partname_selected;
		}
		/* check "dtbo1" */
		if (partition_exists(dtbo_part_names[0]) == PART_OK) {
			for (i = 0; i < array_size; i++) {
				if (partition_get_active_bit_by_name(dtbo_part_names[i]))
					part_name = dtbo_part_names[i];
			}
			if(part_name == NULL)
				part_name = dtbo_part_names[0];
		} else
			/* Fallback to old style */
			part_name = dtbo_fallback_part_name;
partname_selected:
		strncpy(dtbo_part_name_full, part_name, DTBO_PART_NAME_LEN);
#endif
		if (strlen(part_name) > DTBO_PART_NAME_LEN) {
			pal_log_err("The length of DTBO partition name:%s > %d!\n", part_name,
				DTBO_PART_NAME_LEN);
			assert(0);
		}

		dtbo_part_name_full[DTBO_PART_NAME_LEN] = '\0';
		dtbo_part_name_inited = 1;
	}
	return dtbo_part_name_full;
}

#if defined(MTK_DCONFIG_SUPPORT)

#define DCONFIG_DTB_SIZE 131072
#define DCONFIG_PART "boot_para"
#define DCONFIG_DT_NAME "dconfig-dt"

static u8 *dtb_dconfig_load(void)
{
	static bool dconfig_dtb_failed = false;
	u8 *dconfig_dtb = NULL;
	int len = 0;

	if (dconfig_dtb_failed) {
		pal_log_info("dconfig-dt already load failed, don't do it again\n");
		return NULL;
	}

#ifdef MTK_SECURITY_SW_SUPPORT
	unsigned int policy_entry_idx = 0;
	unsigned int img_auth_required = 0;

	policy_entry_idx = get_policy_entry_idx(DCONFIG_PART);
	img_auth_required = get_vfy_policy(policy_entry_idx);
	if (img_auth_required) {
		uint32_t sec_ret = sec_img_auth_init(DCONFIG_PART, DCONFIG_DT_NAME, 0);
		if (sec_ret) {
			dconfig_dtb_failed = true;
			pal_log_err("dconfig image cert verify failed\n");
			return NULL;
		}
	}
#endif
	dconfig_dtb = malloc(DCONFIG_DTB_SIZE);
	if (dconfig_dtb == NULL) {
		dconfig_dtb_failed = true;
		pal_log_err("Not enough memory\n");
		return NULL;
	}
	len = mboot_common_load_part(DCONFIG_PART, DCONFIG_DT_NAME,
				     (unsigned long)dconfig_dtb);
	if (len <= 0) {
		dconfig_dtb_failed = true;
		pal_log_info("partition_read failed, return value %d\n", len);
		free(dconfig_dtb);
		return NULL;
	}
#ifdef MTK_SECURITY_SW_SUPPORT
	if (img_auth_required) {
		uint32_t sec_ret = sec_img_auth(dconfig_dtb, len);
		if (sec_ret) {
			dconfig_dtb_failed = true;
			pal_log_err("dconfig image verify failed\n");
			free(dconfig_dtb);
			return NULL;
		}
	}
#endif
	return dconfig_dtb;
}

bool dtb_dconfig_overlay(void *target_fdt)
{
	int ret = 0;

	if (target_fdt == NULL) {
		pal_log_err("dconfig: passing target fdt with null\n");
		return TRUE;
	}

	u8 *dconfig_dtb = dtb_dconfig_load();
	if (dconfig_dtb == NULL) {
		return TRUE;
	}

	struct fdt_header *dconfig_fdth = (struct fdt_header *) dconfig_dtb;
	if (fdt_magic(dconfig_fdth) != FDT_MAGIC) {
		pal_log_info("FDT magic number miss match : magic %x\n",
			     fdt_magic(dconfig_fdth));
		free(dconfig_dtb);
		return TRUE;
	}
	if (fdt_totalsize(dconfig_fdth) >= DCONFIG_DTB_SIZE) {
		pal_log_err("Dconfig's DT size too large %d\n", fdt_totalsize(dconfig_fdth));
		free(dconfig_dtb);
		return TRUE;
	}

	struct fdt_header *blob = ufdt_install_blob(target_fdt, DTB_MAX_SIZE);
	if (!blob) {
		pal_log_err("ufdt_install_blob() failed\n");
		free(dconfig_dtb);
		return FALSE;
	}

	void *merged_fdt = ufdt_apply_overlay(blob, fdt_totalsize(blob), dconfig_fdth,
					      fdt_totalsize(dconfig_fdth));
	if (!merged_fdt) {
		pal_log_err("dconfig: ufdt_apply_overlay failed\n");
		free(dconfig_dtb);
		return FALSE;
	}

	ret = fdt_pack(merged_fdt);
	if (ret) {
		pal_log_err("dconfig: fdt_pack failed\n");
		free(merged_fdt);
		free(dconfig_dtb);
		return FALSE;
	}

	int merged_size = fdt_totalsize(merged_fdt);
	if (merged_size > DTB_MAX_SIZE) {
		pal_log_err("dconfig: merged size %d > DTB_MAX_SIZE\n", merged_size);
		free(merged_fdt);
		free(dconfig_dtb);
		return FALSE;
	}

	if (fdt_open_into(merged_fdt, target_fdt, DTB_MAX_SIZE) != 0) {
		pal_log_err("dconfig: DTB replace failed\n");
		free(merged_fdt);
		free(dconfig_dtb);
		return FALSE;
	}

	free(merged_fdt);
	free(dconfig_dtb);
	return TRUE;
}

#else

bool dtb_dconfig_overlay(void *target_fdt)
{
	return TRUE;
}

#endif

#ifndef LK_MAIN_DTB_BUILT_IN
void *get_lk_overlayed_dtb(void){return g_fdt;}

int32_t prepare_kernel_dtb(void){return 0;}

/***********************************************************************
* Done after bldr_load_dtb, overlay from associated dtbo partition
************************************************************************/
bool dtb_overlay(void *fdt, int size, uint64_t recovery_dtbo_offset)
{
	size_t overlay_len = 0;
	char *part_name = NULL;

	g_fdt = fdt;

	if (fdt == NULL) {
		pal_log_err("fdt is NULL\n");
		return FALSE;
	}
	if (size == 0) {
		pal_log_err("fdt size is zero\n");
		return FALSE;
	}

#ifdef MTK_AB_OTA_UPDATER
	part_name = get_dtbo_part_name();
#else
	/* for non-AB supporting bootimg hdr version 1, get dtbo from recovery */
	if (recovery_dtbo_offset == 0) {
		part_name = get_dtbo_part_name();
	}
	else {
		part_name = "recovery";
		g_dtbo_load_src = DTBO_FROM_RECOVERY;
	}
#endif  // MTK_AB_OTA_UPDATER

	// Note: A buffer is allocated in load_overlay_dtbo() to store the loaded
	//       odm dtb.
	char *overlay_buf = load_overlay_dtbo(part_name, &overlay_len, (uint64_t)recovery_dtbo_offset);

	// check overlay dtbo
	if (overlay_buf == NULL) {
		pal_log_err("load overlay dtbo failed !\n");
		return FALSE;
	}

	// check len of overlay dtbo
	if (overlay_len == 0) {
		pal_log_err("size of overlay dtbo is 0 !\n");
		free(overlay_buf);
		return FALSE;
	}

	struct fdt_header *fdth = (struct fdt_header *)g_fdt;
	fdth->totalsize = cpu_to_fdt32(size);

	int ret = fdt_open_into(g_fdt, g_fdt, size);
	if (ret) {
		pal_log_err("fdt_open_into failed \n");
		free(overlay_buf);
		return FALSE;
	}
	ret = fdt_check_header(g_fdt);
	if (ret) {
		pal_log_err("fdt_check_header check failed !\n");
		free(overlay_buf);
		return FALSE;
	}

	char *base_buf = fdt;
	size_t blob_len = size;
	struct fdt_header *blob = ufdt_install_blob(base_buf, blob_len);
	if (!blob) {
		pal_log_err("ufdt_install_blob() failed!\n");
		free(overlay_buf);
		return FALSE;
	}
	pal_log_info("blob_len: 0x%x, overlay_len: 0x%x\n", blob_len, overlay_len);

	void *merged_fdt = NULL;
	PROFILING_START("Overlay");
	// Note: A buffer is allocated in ufdt_apply_overlay() to store the merge
	//       device tree.
	merged_fdt = ufdt_apply_overlay(blob, blob_len, overlay_buf, overlay_len);
	if (!merged_fdt) {
		pal_log_err("ufdt_apply_overlay() failed!\n");
		free(overlay_buf);
		assert(0);
		return FALSE;
	}
	PROFILING_END();

	// Compact the merged device tree so that the size of the device tree can
	// be known.
	ret = fdt_pack(merged_fdt);
	if (ret) {
		pal_log_err("fdt_pack(merged_fdt) failed !\n");
		free(merged_fdt);
		free(overlay_buf);
		return FALSE;
	}


	int merged_size = fdt_totalsize(merged_fdt);
	pal_log_info("fdt merged_size: %d\n", merged_size);
	if (merged_size > DTB_MAX_SIZE) {
		pal_log_err("Error: merged size %d > DTB_MAX_SIZE!\n", merged_size);
		free(merged_fdt);
		free(overlay_buf);
		return FALSE;
	}

	// The memory pointed to by "g_fdt" is the location that the Linux kernel
	// expects to find the device tree, and it is at least a few mega-bytes
	// free. The merged device tree is therefore copied to that space.
	memcpy(g_fdt, merged_fdt, merged_size);

	// Make the totalsize of the device tree larger so that properties can
	// be inserted into the device tree.
	((struct fdt_header *)g_fdt)->totalsize = cpu_to_fdt32(DTB_MAX_SIZE);

	free(merged_fdt);
	free(overlay_buf);

	return TRUE;
}


/*******************************************************************
* mmap fdt buffer and sanity check it before doing any operation
********************************************************************/
bool setup_fdt(void *fdt, int size)
{
	int ret;
	g_fdt = fdt;
#ifdef MTK_3LEVEL_PAGETABLE
	u32 addr = (u32)fdt;
	arch_mmu_map((uint64_t)ROUNDDOWN(addr, PAGE_SIZE),
		(uint32_t)ROUNDDOWN(addr, PAGE_SIZE),
		MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
		ROUNDUP(size, PAGE_SIZE));
#endif
	ret = fdt_open_into(g_fdt, g_fdt, size); //DTB maximum size is 2MB
	if (ret) return FALSE;
	ret = fdt_check_header(g_fdt);
	if (ret) return FALSE;
	return TRUE;
}

/**************************************************************************
* Load dtb from boot/recovery, does MMU map and relocate
***************************************************************************/
int bldr_load_dtb_from_boot(char *part_name, u32 *dtb_final_addr, uint64_t *recovery_dtbo_offset)
{
	int ret = 0;
	char *ptr;
	char *dtb_sz;
	u32 zimage_addr, zimage_size, dtb_size, addr, tmp;
	u32 dtb_addr = 0;
	u32 offset = 0;
	unsigned char *magic;
	struct bootimg_hdr *p_boot_hdr;

	ptr = malloc(DTB_MAX_SIZE);
	if (ptr == NULL) {
		pal_log_err("dtb malloc failed!\n");
		return -1;
	}

	//load boot hdr
	ret = mboot_recovery_load_raw_part(part_name, (unsigned long *)ptr,
					sizeof(struct bootimg_hdr) + 0x800);
	if (ret < 0) {
		pal_log_err("mboot_recovery_load_raw_part(%s, %d) failed, ret: 0x%x\n",
			part_name, sizeof(struct bootimg_hdr) + 0x800, ret);
		goto _end;
	}

	if (0 == bootimg_hdr_valid((uint8_t *)ptr)) {
		pal_log_err("bootimg_hdr_valid failed\n");
		ret = -1;
		goto _end;
	}

	p_boot_hdr = (void *)ptr;
	*dtb_final_addr = p_boot_hdr->tags_addr;

	/* Under recovery, get dtbo info from bootimg hdr version 1 */
	if (!strcmp(part_name, "recovery")) {
		if (p_boot_hdr->header_version >= BOOT_HEADER_VERSION_ONE) {
			*recovery_dtbo_offset = (uint64_t)p_boot_hdr->recovery_dtbo_offset;
			pal_log_err("bldr_load_dtb: recovery_dtbo_offset = 0x%llx\n", (uint64_t)*recovery_dtbo_offset);
			/* If offset is 0, implies dtbo in its standalone partition */
			/* In that case, recovery is not self-sufficient */
			if (*recovery_dtbo_offset == 0)
				pal_log_err("Warning: check recovery dtbo location!\n");
		}
	}

	/* Claim the DT/kernel/ramdisk addr from mblock */
	mboot_allocate_bootimg_from_mblock(p_boot_hdr);

	/* decide whether this is 64bit kernel from cmdline */
	platform_parse_bootopt(p_boot_hdr->cmdline);

	if (p_boot_hdr->header_version >= BOOT_HEADER_VERSION_TWO) {
		dtb_size = p_boot_hdr->dtb_size;
		tmp = p_boot_hdr->page_sz
			+ ROUNDUP(p_boot_hdr->kernel_sz, p_boot_hdr->page_sz)
			+ ROUNDUP(p_boot_hdr->ramdisk_sz, p_boot_hdr->page_sz)
			+ ROUNDUP(p_boot_hdr->second_sz, p_boot_hdr->page_sz)
			+ ROUNDUP(p_boot_hdr->recovery_dtbo_size, p_boot_hdr->page_sz);

		if (dtb_size == 0) {
			pal_log_err("can't find v2 dtb\n");
			ret = -1;
			goto _end;
		}

		ret = partition_read(part_name, (off_t)tmp, (u8 *)ptr,
			(size_t)ROUNDUP(dtb_size, p_boot_hdr->page_sz));
		if (ret < 0) {
			pal_log_err("partition_read for v2 dtb failed, ret: 0x%x\n", ret);
			goto _end;
		}

		/* Check dtb format comes with mkdtimg (table_header+table_entry+fdt_body) */
		if (DT_TABLE_MAGIC == fdt_magic(ptr))
		{
			struct dt_table_header *hdr = (struct dt_table_header *)ptr;
			uint32_t dt_entry_count = fdt32_to_cpu(hdr->dt_entry_count);
			dtb_addr = (u32)ptr + sizeof(struct dt_table_header)
				+ dt_entry_count * sizeof(struct dt_table_entry);

			pal_log_err("find v2 dtb with mkdtimg format, dtb file offset: 0x%x\n", tmp);
		}
		else if (FDT_MAGIC == fdt_magic(ptr))
		{
			dtb_addr = (u32)ptr;
			pal_log_err("find v2 dtb with fdt format only, dtb file offset: 0x%x\n", tmp);
		}

		goto _dt_relocate;
	}

	if (!g_is_64bit_kernel) {
		//Offset into zImage    Value   Description
		//0x24  0x016F2818  Magic number used to identify this is an ARM Linux zImage
		//0x28  start address   The address the zImage starts at
		//0x2C  end address The address the zImage ends at
		/* bootimg header size is 0x800, the kernel img text is next to the header */
		zimage_addr = (u32)ptr + p_boot_hdr->page_sz;
		if (*(unsigned int *)((unsigned int)zimage_addr) == MKIMG_MAGIC) {
			zimage_addr += MKIMG_HDR_SZ;
			offset += MKIMG_HDR_SZ;
		}
		zimage_size = *(unsigned int *)((unsigned int)zimage_addr + 0x2c) -
			*(unsigned int *)((unsigned int)zimage_addr + 0x28);
		//dtb_addr = (unsigned int)zimage_addr + zimage_size;
		offset += (p_boot_hdr->page_sz + zimage_size);
		tmp = ROUNDDOWN(offset, p_boot_hdr->page_sz);
		ret = partition_read(part_name, (off_t)tmp, (u8 *)ptr, (size_t)DTB_MAX_SIZE);
		if (ret < 0) {
			pal_log_err("partition_read failed, ret: 0x%x\n", ret);
			goto _end;
		}
		dtb_addr = (u32)ptr + offset - tmp;
		dtb_size = fdt32_to_cpu(*(unsigned int *)(ptr + (offset - tmp) + 0x4));
	} else {
		/* bootimg header size is 0x800, the kernel img text is next to the header */
		int i;
		zimage_size = p_boot_hdr->kernel_sz;
		offset = p_boot_hdr->page_sz + p_boot_hdr->kernel_sz - DTB_MAX_SIZE;
		tmp = ROUNDUP(offset, p_boot_hdr->page_sz);
		ret = partition_read(part_name, (off_t)tmp, (u8 *)ptr, (size_t)DTB_MAX_SIZE);
		if (ret < 0) {
			pal_log_err("partition_read failed, ret: 0x%x\n", ret);
			goto _end;
		}
		dtb_addr = 0;
		dtb_size = 0;
		addr = (u32)ptr + DTB_MAX_SIZE - 4;
		for (i = 0; i < (DTB_MAX_SIZE - 4); i++, addr--) {
			//FDT_MAGIC 0xd00dfeed
			//dtb append after image.gz may not 4 byte alignment
			magic = (unsigned char *)addr;
			if (*(magic + 3) == 0xED && *(magic + 2) == 0xFE &&
				*(magic + 1) == 0x0D && *(magic + 0) == 0xD0) {
				dtb_addr = addr;
				break;
			}
		}
		if (dtb_addr == 0) {
			pal_log_err("can't find dtb\n");
			ret = -1;
			goto _end;
		}
		dtb_sz = (char *)(dtb_addr + 4);
		dtb_size = *(dtb_sz) * 0x1000000 + *(dtb_sz + 1) * 0x10000 +
			*(dtb_sz + 2) * 0x100 + *(dtb_sz + 3);
		g_64bit_dtb_size = dtb_size;
		pal_log_err("Kernel(%d) zimage_size:0x%x,dtb_addr:0x%x(dtb_size:0x%x)\n",
			g_is_64bit_kernel, zimage_size, dtb_addr, dtb_size);
	}

_dt_relocate:
	if (dtb_size > DTB_MAX_SIZE) {
		pal_log_err("dtb_size too large: 0x%x\n", dtb_size);
		ret = -1;
		goto _end;
	}

#ifdef MTK_3LEVEL_PAGETABLE
	arch_mmu_map((uint64_t)ROUNDDOWN(*dtb_final_addr, PAGE_SIZE),
		(uint32_t)ROUNDDOWN(*dtb_final_addr, PAGE_SIZE),
		MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
		ROUNDUP(dtb_size, PAGE_SIZE));
#endif
	pal_log_err("Copy DTB from 0x%x to 0x%x(size: 0x%x)\n", dtb_addr,
		*dtb_final_addr, dtb_size);
	memcpy((void *)*dtb_final_addr, (void *)dtb_addr, dtb_size);

_end:
	free(ptr);
	return ret;
}

/**************************************************************************
* Please refer to bootimg.h for boot image header structure.
* bootimg header size is 0x800, the kernel img text is next to the header
***************************************************************************/
int bldr_load_dtb(char *boot_load_partition)
{
	int ret = 0;
	u32 dtb_final_addr;
	char part_name[16];
	uint64_t recovery_dtbo_offset = 0;

#ifdef MTK_AB_OTA_UPDATER
	/* no more recovery partition in A/B system update, instead choose boot_a or boot_b */
	snprintf(part_name, sizeof(part_name), "boot%s", p_AB_suffix);
#else
	snprintf(part_name, sizeof(part_name), "%s", boot_load_partition);
#endif

	/* load dtb from boot */
	ret = bldr_load_dtb_from_boot(part_name, &dtb_final_addr, &recovery_dtbo_offset);
	if (ret < 0)
		return ret;

	// Place setup_fdt() after bldr_load_dtb() because it sets "fdt_header->totalsize".
	ret = setup_fdt((void *)dtb_final_addr, DTB_MAX_SIZE);
	pal_log_err("[LK] fdt setup addr:0x%x status:%d!!!\n", dtb_final_addr, ret);
	if (ret == FALSE) {
		pal_log_err("setup_fdt fail, ret: 0x%x!\n", ret);
		ret = -1;
	}

	/* load odmdtbo and overlay */
	ret = dtb_overlay(g_fdt, DTB_MAX_SIZE, (uint64_t)recovery_dtbo_offset);
	if (ret == TRUE) {
		if (!strcmp(part_name, "recovery")) {
			set_recovery_dtbo_loaded();
			pal_log_err("dtb_overlay for recovery done !\n");
		}
	}
	/* command line buffer init */
	bootargs_init(g_fdt);

	return ret;
}
#else /* LK_MAIN_DTB_BUILT_IN */
#define DT_TBL_HDR_SIZE		(sizeof(struct dt_table_header))
int32_t load_dtbo_buffer(void **dtbo_ptr, uint32_t *dtbo_size)
{
	void *dtbo_buffer = NULL;
	struct dt_table_header *dt_tbl_hdr_buffer = NULL;
	size_t pre_read_dt_tbl_hdr_size = DT_TBL_HDR_SIZE;
	size_t dtbo_total_len;
	void *dtbo_total_buffer = NULL;
	void *selected_dtbo_body_ptr;
	ssize_t	len;
	int32_t ret = 0;
	uint32_t dtbo_offset;
	uint32_t dtbo_entry_idx;
	uint32_t _dtbo_size;
	char *dtbo_from_part_name = get_dtbo_part_name();
#ifdef MTK_SECURITY_SW_SUPPORT
	uint32_t sec_ret;
	uint32_t vfy_time;
	unsigned int policy_entry_idx = 0;
	unsigned int img_auth_required = 0;
	char *img_name = "dtbo";

	policy_entry_idx = get_policy_entry_idx(dtbo_from_part_name);
	img_auth_required = get_vfy_policy(policy_entry_idx);
	/* verify cert chain of boot img */
	if (img_auth_required) {
		vfy_time = get_timer(0);
		sec_ret = sec_img_auth_init(dtbo_from_part_name, img_name, 0);
		if (sec_ret) {
			ret = -1;
			goto end;
		}
		dprintf(CRITICAL, "[SBC] image %s cert vfy pass(%d ms)\n", img_name, (unsigned int)get_timer(vfy_time));
#ifdef MTK_SECURITY_ANTI_ROLLBACK
		sec_ret = sec_rollback_check(1);
		if (sec_ret) {
			dprintf(CRITICAL, "[SBC] image %s ver check fail...(0x%x)\n", img_name, sec_ret);
			ret = -1;
			goto end;
		}
#endif
	}
#endif

	dt_tbl_hdr_buffer = (struct dt_table_header *)malloc(pre_read_dt_tbl_hdr_size);
	if (dt_tbl_hdr_buffer == NULL) {
		ret = -ENOMEM;
		goto end;
	}
	/* init dt_tbl_hdr_buffer */
	memset(dt_tbl_hdr_buffer, 0x0, pre_read_dt_tbl_hdr_size);
	len = partition_read(dtbo_from_part_name, (off_t)0, (uint8_t *)dt_tbl_hdr_buffer, pre_read_dt_tbl_hdr_size);
	if (len < 0) {
		ret = len;
		goto end;
	}
	if (fdt32_to_cpu(dt_tbl_hdr_buffer->magic) != DT_TABLE_MAGIC) {
		pal_log_err("dt_table_header magic is not correct:0x%x\n",
			fdt32_to_cpu(dt_tbl_hdr_buffer->magic));
		ret = -EINVAL;
		goto end;
	}
	dtbo_total_len = fdt32_to_cpu(dt_tbl_hdr_buffer->total_size);
	if (dtbo_total_len > DTB_MAX_SIZE) {
		ret = -1;
		goto end;
	}
	dtbo_total_buffer = malloc(dtbo_total_len);
	if (dtbo_total_buffer == NULL){
		ret = -ENOMEM;
		goto end;
	}
	len = partition_read(dtbo_from_part_name, (off_t)0, (uint8_t *)dtbo_total_buffer, dtbo_total_len);
	if (len < 0) {
		ret = len;
		goto end;
	}
#ifdef MTK_SECURITY_SW_SUPPORT
	if (img_auth_required) {
		vfy_time = get_timer(0);
		sec_ret = sec_img_auth((uint8_t *)(dtbo_total_buffer + pre_read_dt_tbl_hdr_size), (len - pre_read_dt_tbl_hdr_size));
		if (sec_ret) {
			dprintf(CRITICAL, "[SBC] %s vfy fail(%d ms)\n", img_name, (unsigned int)get_timer(vfy_time));
			ret = -2;
			goto end;
		}
		dprintf(CRITICAL, "[SBC] %s vfy pass(%d ms)\n", img_name, (unsigned int)get_timer(vfy_time));
	}
#endif

	/* select dtbo via HW index */
	ret = parse_dtbo_tbl((struct dt_table_header *)dtbo_total_buffer, (uint32_t)get_odm_mdtbo_index(),
					&dtbo_entry_idx,
					(uint32_t *)&_dtbo_size, (uint32_t *)&dtbo_offset);
	if(ret < 0) {
		goto end;
	}
	if (_dtbo_size > DTB_MAX_SIZE) {
		ret = -EPERM;
		goto end;
	}
	*dtbo_size = _dtbo_size;
	set_dtbo_index(dtbo_entry_idx);

	dtbo_buffer = malloc(_dtbo_size);
	if (dtbo_buffer == NULL){
		ret = -ENOMEM;
		goto end;
	}
	selected_dtbo_body_ptr = dtbo_total_buffer + dtbo_offset;
	memcpy(dtbo_buffer, selected_dtbo_body_ptr, _dtbo_size);
	*dtbo_ptr = dtbo_buffer;
end:
	if (dtbo_total_buffer)
		free(dtbo_total_buffer);
	if (dt_tbl_hdr_buffer)
		free(dt_tbl_hdr_buffer);
	/* fail case */
	if (ret != 0) {
		if (dtbo_buffer)
			free(dtbo_buffer);
		*dtbo_ptr = NULL;
	}
	return ret;
}

int32_t prepare_kernel_dtb(void)
{
	int ret_overlay;
	uint32_t ret = 0;
	void *overlayed_dtb = NULL;
	void *dtbo = NULL;
	uint32_t dtbo_size = get_dtbo_img_size();
	uint32_t overlayed_dtb_size = 0;
	/*
	 * dtbo address may not native pointer alignment,
	 * which will cause unalignment fault.
	 */
	if (!IS_ALIGNED(get_dtbo_load_addr(), sizeof(void *))) {
		dtbo = malloc(dtbo_size);
		if (dtbo == NULL) {
			pal_log_err("Fail to malloc %s dtbo\n", __func__);
			ret = -1;
			goto end;
		}
		memcpy(dtbo, (void *)get_dtbo_load_addr(), dtbo_size);
	}
	/* overlay dtbo with main dtb */
	ret_overlay = dtb_overlay((void *)get_main_dtb_load_addr(),
				get_main_dtb_size(),
				dtbo ? dtbo : (void *)get_dtbo_load_addr(),
				dtbo_size,
				&overlayed_dtb, DTB_MAX_SIZE);
	if (ret_overlay == 0) {
		if (overlayed_dtb != NULL) {
			overlayed_dtb_size = fdt_totalsize(overlayed_dtb);
			if (overlayed_dtb_size > DTB_MAX_SIZE) {
				pal_log_err("fdt_totalsize(overlayed_dtb):%u is too large!\n", overlayed_dtb_size);
				ret = -1;
				goto end;
			}
			memcpy(get_kernel_fdt(), overlayed_dtb, overlayed_dtb_size);
			/* enlarge kernel's fdt for further property setting */
			fdt_set_totalsize(get_kernel_fdt(), DTB_MAX_SIZE);
		} else {
			ret = -1;
			pal_log_err("overlayed_dtb is NULL");
		}
	} else {
		pal_log_err("boot image dtb_overlay fail");
		ret = -2;
	}
end:
	if (dtbo)
		free(dtbo);
	if (overlayed_dtb)
		free(overlayed_dtb);
	return ret;
}


int32_t dtb_overlay(void *main_dtb_addr, uint32_t main_dtb_size,
					void *dtbo_addr, uint32_t dtbo_size,
					void **merged_dtb, uint32_t merged_max_size)
{
	int ret;
	struct fdt_header *blob;
	struct fdt_header *merged_fdt;

	PAL_ASSERT(main_dtb_addr);
	PAL_ASSERT(main_dtb_size);
	PAL_ASSERT(dtbo_addr);
	PAL_ASSERT(dtbo_size);
	PAL_ASSERT(merged_dtb);
	if (merged_max_size < (main_dtb_size + dtbo_size)) {
		pal_log_err("merged_max_size:%u, main_dtb_size + dtbo_size:%u\n",
			merged_max_size, main_dtb_size + dtbo_size);
		return -EINVAL;
	}

	ret = fdt_open_into(main_dtb_addr, main_dtb_addr, main_dtb_size);
	if (ret < 0) {
		pal_log_err("fdt_open_into failed \n");
		return ret;
	}
	blob = ufdt_install_blob(main_dtb_addr, main_dtb_size);
	if (blob == NULL) {
		pal_log_err("ufdt_install_blob() failed!\n");
		return -1;
	}
	merged_fdt = ufdt_apply_overlay(blob, main_dtb_size, dtbo_addr, dtbo_size);
	if (merged_fdt == NULL) {
		pal_log_err("ufdt_apply_overlay() failed!\n");
		return -1;
	}
	/*
	  * Compact the merged device tree so that the size of the device tree can
	  * be known.
	  */
	ret = fdt_pack((void *)merged_fdt);
	if (ret < 0) {
		pal_log_err("fdt_pack(merged_fdt) failed !\n");
		if (merged_fdt)
			free(merged_fdt);
		return -1;
	}
	*merged_dtb = (void *)merged_fdt;
	return ret;
}
#endif

/**************************************************************************************
* Main device tree loading function, considering loading accordingly from different boot mode
***************************************************************************************/
void load_device_tree(void)
{
#ifndef LK_MAIN_DTB_BUILT_IN
	PROFILING_START("early load dtb");

	char *part_name = "boot";

	/* If RECOVERY_AS_BOOT is enabled, there is no recovery partition.  */
#if !defined(NO_BOOT_MODE_SEL) && !defined(RECOVERY_AS_BOOT)
	if (Check_RTC_Recovery_Mode() || unshield_recovery_detection())
		part_name = "recovery";
	else
		part_name = "boot";
#endif

#if defined(CFG_DTB_EARLY_LOADER_SUPPORT)
	if (bldr_load_dtb(part_name) < 0)
		dprintf(CRITICAL, "Error: %s failed\n", __func__);
#endif

	PROFILING_END();
#else /* LK_MAIN_DTB_BUILT_IN */
	lk_dtb_init();
#endif
}

int32_t parse_dtbo_tbl(struct dt_table_header *dt_tbl_hdr_buffer,
		uint32_t hw_board_idx, uint32_t *dtbo_entry_idx_out,
		uint32_t *dtbo_size, uint32_t *dtbo_offset)
{
	struct dt_table_entry *dt_entry_head;
	struct dt_table_entry *dt_entry_selected;
	uint32_t dt_entry_cnt;
	uint32_t dtbo_entry_idx;

	assert(dt_tbl_hdr_buffer);
	assert(dtbo_entry_idx_out);
	assert(dtbo_size);
	assert(dtbo_offset);
	/* sanity check */
	if (fdt32_to_cpu(dt_tbl_hdr_buffer->magic) != DT_TABLE_MAGIC) {
		pal_log_err("dt_table_header magic is not correct:0x%x\n",
			fdt_magic(dt_tbl_hdr_buffer));
		return -EINVAL;
	}
	dt_entry_cnt = fdt32_to_cpu(dt_tbl_hdr_buffer->dt_entry_count);
	if (dt_entry_cnt > DTBO_ENTRY_CNT_MAX) {
		pal_log_err("dt_entry_cnt is out of bound: %u, max:%u\n", dt_entry_cnt, DTBO_ENTRY_CNT_MAX);
		return -EINVAL;
	}
	dt_entry_head = (struct dt_table_entry *)(dt_tbl_hdr_buffer + 1);
	/*
	 * traverse dt_table_entry list, compare
	 * dt_table_entry->id with hw_board_idx
	 */
	for(dtbo_entry_idx = 0; dtbo_entry_idx < dt_entry_cnt ; dtbo_entry_idx++) {
		if (hw_board_idx == fdt32_to_cpu((dt_entry_head + dtbo_entry_idx)->id)) {
			break;
		}
	}
	/* traverse end */

	if (dtbo_entry_idx >= dt_entry_cnt) {
		dprintf(CRITICAL, "Error: dtbo_entry_idx %d >= num_of_dtbo %d.\n",
			dtbo_entry_idx, dt_entry_cnt);
		dprintf(CRITICAL, "Set dtbo_entry_idx to 0 for error handling!\n");
		dtbo_entry_idx = 0;
	}
	*dtbo_entry_idx_out = dtbo_entry_idx;
	dt_entry_selected = dt_entry_head + dtbo_entry_idx;
	*dtbo_size = fdt32_to_cpu(dt_entry_selected->dt_size);
	*dtbo_offset = fdt32_to_cpu(dt_entry_selected->dt_offset);
	return 0;
}
