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
*/

#include <odm_mdtbo.h>                  // for get_odm_mdtbo_index()
#include <debug.h>                      // for dprintf()
#include <part_interface.h>             // for partition_read()
#include <part_status.h>
#include <block_generic_interface.h>    // for mt_part_get_device()
#include <stdlib.h>                     // for malloc()
#include <libfdt.h>
#include <img_info.h>
#include <rsc.h>

/* global variable to send androidboot.dtbo_idx */
static int hw_mdtbo_index = -1;
int get_dtbo_index(void)
{
	if (hw_mdtbo_index == -1)
		panic("hw_mdtbo_index is not inited!\n");
	return hw_mdtbo_index;
}
void set_dtbo_index(int dtbo_idx)
{
	hw_mdtbo_index = dtbo_idx;
}

/******************************************************************************
* NOTE: Customers need to implement their own customized_get_odm_mdtbo_index()
*       function. If customized_get_odm_mdtbo_index() is not implemented, the
*       value 0 will be used as the default dtbo index. Each customer can
*       maintain their own implementation of customized_get_odm_mdtbo_index()
*       in a separate source file as long as it can be linked.
******************************************************************************/
int get_odm_mdtbo_index(void)
{
	int odm_dtbo_index = 0;
	int rsc_is_valid = 0;

	if (rsc_get_dtbo_index) {
		rsc_is_valid = rsc_valid();
		if (rsc_is_valid)
			odm_dtbo_index = rsc_get_dtbo_index();
	}
	if (!rsc_is_valid) {
		if (customized_get_odm_mdtbo_index)
			odm_dtbo_index = customized_get_odm_mdtbo_index();
	}
	return odm_dtbo_index;
}


/******************************************************************************
******************************************************************************/
static bool is_odm_mdtbo_header(const mdtbo_hdr_t *hdr2)
{
	if (hdr2->info.magic != ODM_MDTBO_MAGIC) {
		dprintf(INFO, "Single ODM DTBO.\n");
		return false;
	}
	dprintf(INFO, "Multiple ODM DTBO.\n");
	return true;
}


/******************************************************************************
* dtb_size:   It is the size of the device tree selected by dtbo_index.
* dtb_offset: It is the offset from the beginning of the partition.
******************************************************************************/
static void get_odm_mdtbo_offset_and_size(const mdtbo_hdr_t *hdr2,
	int mdtbo_index, unsigned int *dtbo_size, unsigned int *dtbo_offset)
{
	if (mdtbo_index < 0 || mdtbo_index >= MAX_NUM_OF_ODM_MDTBO) {
		goto fail;
	}

	if ((unsigned int)mdtbo_index == hdr2->info.num_of_dtbo - 1)
		*dtbo_size = hdr2->info.dsize;
	else {
		if ((mdtbo_index+1) >= MAX_NUM_OF_ODM_MDTBO)
			goto fail;
		*dtbo_size = hdr2->info.dtbo_offset[mdtbo_index + 1];
	}

	if (*dtbo_size <= hdr2->info.dtbo_offset[mdtbo_index]) {
		dprintf(CRITICAL, "Error: incorrect dtbo size\n");
		assert(0);
	}
	*dtbo_size -= hdr2->info.dtbo_offset[mdtbo_index];

	*dtbo_offset = hdr2->info.dtbo_offset[mdtbo_index];
	*dtbo_offset += PART_HDR_DATA_SIZE + ODM_MDTBO_HDR_SIZE;
	return;

fail:
	dprintf(CRITICAL, "Error: mdtbo index %d is out of range!\n", mdtbo_index);
	assert(0);
}


/******************************************************************************
* Side effect: This function allocates a memory on success.
******************************************************************************/
static bool load_dtb_from_single_dtbo(char *part_name, union mkimg_hdr *img_hdr,
	char **handle, uint64_t recovery_dtbo_offset)
{
	unsigned int dsize = img_hdr->info.dsz;
	*handle = malloc(dsize);
	if (*handle == NULL) {
		dprintf(CRITICAL, "Fail to malloc %d-byte buffer for dtbo!\n", dsize);
		assert(0);
		return false;
	}

	long len = partition_read(part_name, (off_t)(recovery_dtbo_offset+PART_HDR_DATA_SIZE), (uchar*)*handle, (size_t)dsize);
	if (len < 0) {
		dprintf(CRITICAL, "(L%d) Fail to read %s partition!\n", __LINE__, part_name);
		free(*handle);
		return false;
	}

	if (fdt_magic(*handle) != FDT_MAGIC) {
		dprintf(CRITICAL, "Error: invalid dtbo image format!\n");
		free(*handle);
		assert(0);  // Keep running instead of assert!!
		return false;
	}

	return true;
}


/******************************************************************************
* Side effect: This function allocates a memory on success.
******************************************************************************/
static bool load_dtb_from_multiple_dtbo(char *part_name,
	const mdtbo_hdr_t *hdr2, char **handle, uint64_t recovery_dtbo_offset)
{
	if (hdr2->info.hdr_size != ODM_MDTBO_HDR_SIZE) {
		dprintf(CRITICAL, "Error: odm mdtbo header size %d mismatch!\n",
			hdr2->info.hdr_size);
		assert(0);
		return false;
	}

	if (hdr2->info.hdr_version != ODM_MDTBO_VERSION) {
		dprintf(CRITICAL, "Error: odm mdtbo header version %d mismatch!\n",
			hdr2->info.hdr_version);
		assert(0);
		return false;
	}

	hw_mdtbo_index = get_odm_mdtbo_index();
	if (hw_mdtbo_index < 0 || hw_mdtbo_index >= MAX_NUM_OF_ODM_MDTBO) {
		dprintf(CRITICAL, "Error: mdtbo index %d is out of range!\n", hw_mdtbo_index);
		assert(0);
		return false;
	}

	unsigned int dtbo_size = 0, dtbo_offset = 0;
	if ((unsigned int)hw_mdtbo_index >= hdr2->info.num_of_dtbo) {
		dprintf(CRITICAL, "Error: hw_mdtbo_index %d >= num_of_dtbo %d.\n",
			hw_mdtbo_index, hdr2->info.num_of_dtbo);
		dprintf(CRITICAL, "Set hw_mdtbo_index to 0 for error handling!\n");
		hw_mdtbo_index = 0;
	}
	get_odm_mdtbo_offset_and_size(hdr2, hw_mdtbo_index, &dtbo_size, &dtbo_offset);
	dprintf(INFO, "ODM hw_mdtbo_index: %d, dtbo_offset: %d, dtbo_size: %d\n",
		hw_mdtbo_index, dtbo_offset, dtbo_size);

	*handle = malloc(dtbo_size);
	if (!*handle) {
		dprintf(CRITICAL, "Fail to malloc %d-byte buffer for dtbo!\n", dtbo_size);
		assert(0);
		return false;
	}

	long len = partition_read(part_name, (off_t)(recovery_dtbo_offset+dtbo_offset), (uchar*)*handle, (size_t)dtbo_size);
	if (len < 0) {
		dprintf(CRITICAL, "(L%d) Fail to read %s partition!\n", __LINE__, part_name);
		free(*handle);
		return false;
	}

	if (fdt_magic(*handle) != FDT_MAGIC) {
		dprintf(CRITICAL, "Error: invalid dtbo image format!\n");
		free(*handle);
		assert(0);  // Keep running instead of assert!!
		return false;
	}

	return true;
}

/******************************************************************************
* Load function from new dtb partition format defined since Android P
******************************************************************************/
static bool load_dtb_from_dtb_entry(char *part_name,
	const struct dt_table_header *hdr2, char **handle, uint64_t recovery_dtbo_offset)
{
	unsigned int i, dtbo_size = 0, dtbo_offset = 0;
	const struct dt_table_entry *hdr3 = (struct dt_table_entry *)(hdr2 + 1);

	if (fdt32_to_cpu(hdr2->header_size) != sizeof(struct dt_table_header)) {
		dprintf(CRITICAL, "Error: dt_table_header size %d mismatch!\n",
			fdt32_to_cpu(hdr2->header_size));
		assert(0);
		return false;
	}

	if (fdt32_to_cpu(hdr2->dt_entry_size) != sizeof(struct dt_table_entry)) {
		dprintf(CRITICAL, "Error: dt_table_entry size %d mismatch!\n",
			fdt32_to_cpu(hdr2->dt_entry_size));
		assert(0);
		return false;
	}

	hw_mdtbo_index = get_odm_mdtbo_index();

	/* traverse hw_mdtbo_index into dt_table_entry->id */
	for(i = 0; i < fdt32_to_cpu(hdr2->dt_entry_count); i++) {
		if ((unsigned int)hw_mdtbo_index == fdt32_to_cpu((hdr3 + i)->id)) {
			hw_mdtbo_index = i;
			dprintf(CRITICAL, "real mdtbo index=%d\n", hw_mdtbo_index);
			break;
		}
	}
	/* traverse end */

	if ((unsigned int)hw_mdtbo_index >= fdt32_to_cpu(hdr2->dt_entry_count)) {
		dprintf(CRITICAL, "Set hw_mdtbo_index to 0 for error handling!\n");
		hw_mdtbo_index = 0;
	}

	hdr3 = (struct dt_table_entry *)(hdr3 + hw_mdtbo_index);
	dtbo_size = fdt32_to_cpu(hdr3->dt_size);
	dtbo_offset = fdt32_to_cpu(hdr3->dt_offset);
	dprintf(INFO, "hw_mdtbo_index: %d, dtbo_offset: %d, dtbo_size: %d\n",
		hw_mdtbo_index, dtbo_offset, dtbo_size);

	*handle = malloc(dtbo_size);
	if (!*handle) {
		dprintf(CRITICAL, "Fail to malloc %d-byte buffer for dtbo!\n", dtbo_size);
		assert(0);
		return false;
	}

	long len = partition_read(part_name, (off_t)(recovery_dtbo_offset+dtbo_offset), (uchar*)*handle, (size_t)dtbo_size);
	if (len < 0) {
		dprintf(CRITICAL, "(L%d) Fail to read %s partition!\n", __LINE__, part_name);
		free(*handle);
		return false;
	}

	if ((fdt_magic(*handle) != FDT_MAGIC)||(fdt_totalsize(*handle) != dtbo_size)) {
		dprintf(CRITICAL, "Error: invalid dtbo image format!\n");
		free(*handle);
		assert(0);
		return false;
	}

	return true;
}

/******************************************************************************
******************************************************************************/
char *load_overlay_dtbo(char *part_name, unsigned int *size, uint64_t recovery_dtbo_offset)
{
	if (sizeof(union mkimg_hdr) != PART_HDR_DATA_SIZE) {
		dprintf(CRITICAL, "Error: incorrect partition header size!\n");
		assert(0);
		return NULL;
	}

	if (size == NULL) {
		dprintf(CRITICAL, "(L%d) Error: size is NULL!\n", __LINE__);
		return NULL;
	}

	if (partition_exists(part_name) != PART_OK) {
		dprintf(CRITICAL, "(L%d) Fail to get partition %s!\n", __LINE__, part_name);
		return NULL;
	}

	/* Read the partition header & the trailing 32 bytes for possible prolog. */
	long read_size = (long)(PART_HDR_DATA_SIZE + ODM_MDTBO_HDR_SIZE + LARGE_DT_ENTRY_SIZE);
	union mkimg_hdr *img_hdr = (union mkimg_hdr *)malloc(read_size);
	if (img_hdr == NULL) {
		dprintf(CRITICAL, "(L%d) Fail to allocate %d-byte memory!\n", __LINE__, (int)read_size);
		return NULL;
	}

	/* Read mkimage header. Treat it as the mdtbo header. */
	long len = partition_read(part_name, (off_t)recovery_dtbo_offset, (uchar*)img_hdr, (size_t)read_size);
	if (len < 0) {
		dprintf(CRITICAL, "(L%d) Fail to read %s partition!\n", __LINE__, part_name);
		free(img_hdr);
		return NULL;
	}

	/* Legacy MKIMG+MDTBO header parsing */
	if ((MKIMG_MAGIC == img_hdr->info.magic) && (MKIMG_EXT_MAGIC == img_hdr->info.ext_magic)) {

		/* hdr2 points to the possible prolog. */
		const mdtbo_hdr_t *hdr2 = (mdtbo_hdr_t*)(img_hdr + 1);
		char *ptr = NULL;
		bool success = false;
		if (is_odm_mdtbo_header(hdr2) == false)
			success = load_dtb_from_single_dtbo(part_name, img_hdr, &ptr, (uint64_t)recovery_dtbo_offset);
		else
			success = load_dtb_from_multiple_dtbo(part_name, hdr2, &ptr, (uint64_t)recovery_dtbo_offset);

		free(img_hdr);
		if (success) {
			*size = fdt32_to_cpu(*(unsigned int *)(ptr + 4));
			return ptr;
		}
	/* New DTBO parsing using dt_table_header/dt_table_entry */
	} else if (DT_TABLE_MAGIC == fdt_magic(img_hdr)) {
		const struct dt_table_header *hdr2 = (struct dt_table_header *)img_hdr;
		unsigned int dt_entries_offset = fdt32_to_cpu(hdr2->dt_entries_offset);
		unsigned int dt_entry_count = fdt32_to_cpu(hdr2->dt_entry_count);
		unsigned int dt_entry_size = fdt32_to_cpu(hdr2->dt_entry_size);
		char *ptr = NULL;
		bool success = false;

		if ((PART_HDR_DATA_SIZE + ODM_MDTBO_HDR_SIZE + LARGE_DT_ENTRY_SIZE) <
			(dt_entries_offset + dt_entry_count * dt_entry_size)){
			dprintf(CRITICAL, "error handle: need to load more dt_entry size = (%d)!\n",
				(dt_entries_offset + dt_entry_count * dt_entry_size));
			assert(0);
			return NULL;
		}

		success = load_dtb_from_dtb_entry(part_name, hdr2, &ptr, (uint64_t)recovery_dtbo_offset);

		free(img_hdr);
		if (success) {
			*size = fdt32_to_cpu(*(unsigned int *)(ptr + 4));
			return ptr;
		}
	}
	else {
		dprintf(CRITICAL, "assert: non of any known dtbo format !\n");
		assert(0);
		return NULL;
	}

	return NULL;
}


