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
#include <string.h>
#include <config.h>
#include <malloc.h>
#include <printf.h>
#include <platform/mt_typedefs.h>
#include <platform/mtk_nand.h>
#include <partition.h>
#include "partition_define.h"
#include "cust_nand.h"
#include <arch/ops.h>
#include <kernel/event.h>
#include <platform/mt_irq.h>
#include "mtk_nand.h"
#include <platform/mtk_nand_ops.h>
#include <platform/bmt.h>

struct mtk_nand_data_info *data_info;

#define ERR_RTN_SUCCESS   1
#define ERR_RTN_FAIL      0
#define ERR_RTN_BCH_FAIL -1
#define ALL_SLC_BUFFER    1

static bool are_on_diff_planes(unsigned int block0,
        unsigned int block1)
{
        return (block0 + block1) & 0x1;
}

static void add_work_list(struct worklist_ctrl *list_ctrl, struct nand_work *work)
{
	struct nand_work *idx;

	if (list_ctrl->head == NULL) {
		list_ctrl->head = work;
		list_ctrl->total_num++;
		return;
	}
	idx = list_ctrl->head;
	while (idx->next != NULL)
		idx = idx->next;
	idx->next = work;
	list_ctrl->total_num++;
}

static void free_multi_write_work(struct worklist_ctrl *list_ctrl, int count)
{
	int i;
	struct nand_work *work = list_ctrl->head;
	struct nand_work *temp;

	for (i = 0; i < count; i++) {
		temp = work;
		work = work->next;
		list_ctrl->total_num--;
		free(temp);
	}
	list_ctrl->head = work;
}

static void mtk_nand_dump_partition_info(
		struct nand_ftl_partition_info *partition_info)
{
	nand_debug("nand_ftl_partition_info dump info here");
	nand_debug("start_block:0x%x", partition_info->start_block);
	nand_debug("total_block:0x%x", partition_info->total_block);
	nand_debug("slc_ratio:%d", partition_info->slc_ratio);
	nand_debug("slc_block:%d", partition_info->slc_block);
}

static void mtk_chip_info_init(struct mtk_nand_chip_info *chip_info)
{
	unsigned int page_per_block;

	page_per_block = devinfo.blocksize*1024/devinfo.pagesize;

	chip_info->log_block_num = data_info->partition_info.total_block
		*data_info->partition_info.slc_ratio/100;

	chip_info->data_page_num = page_per_block;
	chip_info->data_page_size = devinfo.pagesize;
	chip_info->data_block_size = devinfo.blocksize*1024;
	chip_info->log_page_size = devinfo.pagesize;

	if (devinfo.NAND_FLASH_TYPE == MTK_NAND_FLASH_TLC) {
		chip_info->log_page_num =
			page_per_block/MTK_TLC_DIV;
		chip_info->log_block_size =
			chip_info->data_block_size/MTK_TLC_DIV;
	} else {

		chip_info->log_page_num =
			page_per_block/MTK_MLC_DIV;
		chip_info->log_block_size =
			chip_info->data_block_size/MTK_MLC_DIV;
	}

	if (devinfo.advancedmode & MULTI_PLANE) {
		chip_info->log_block_num >>= 1;
		chip_info->log_block_num <<= 1;
	}

	chip_info->data_block_num =
		data_info->partition_info.total_block - chip_info->log_block_num;

	if (devinfo.advancedmode & MULTI_PLANE) {
		chip_info->data_block_num >>= 1;
		chip_info->data_block_num <<= 1;
	}

	chip_info->data_oob_size = (devinfo.pagesize >> g_nand_chip.sector_shift)
					* g_nand_chip.nand_fdm_size;
	chip_info->log_oob_size = chip_info->data_oob_size;

	chip_info->slc_ratio = data_info->partition_info.slc_ratio;
	chip_info->start_block = data_info->partition_info.start_block;

	chip_info->sector_size_shift = 10;

	if (devinfo.NAND_FLASH_TYPE == MTK_NAND_FLASH_TLC)
		chip_info->max_keep_pages = (devinfo.advancedmode & MULTI_PLANE)?18:9;
	else
		chip_info->max_keep_pages = (devinfo.advancedmode & MULTI_PLANE)?2:1;

	if (devinfo.NAND_FLASH_TYPE == MTK_NAND_FLASH_TLC)
		chip_info->types = MTK_NAND_FLASH_TLC;
	else
		chip_info->types = MTK_NAND_FLASH_MLC;

	chip_info->plane_mask = 0x1;
	chip_info->plane_num = (devinfo.advancedmode & MULTI_PLANE)?2:1;
	chip_info->chip_num = 1;

	if (devinfo.advancedmode & MULTI_PLANE)
		chip_info->option = MTK_NAND_PLANE_MODE_SUPPORT |
					MTK_NAND_MULTI_READ_DIFFERENT_OFFSET;

	chip_info->info_version = MTK_NAND_CHIP_INFO_VERSION;

	return;
}

static void mtk_nand_dump_chip_info(struct mtk_nand_chip_info *chip_info)
{
	nand_debug("mtk_nand_chip_info dump info here");
	nand_debug("data_block_num:0x%x", chip_info->data_block_num);
	nand_debug("data_page_num:0x%x", chip_info->data_page_num);
	nand_debug("data_page_size:0x%x", chip_info->data_page_size);
	nand_debug("data_oob_size:0x%x", chip_info->data_oob_size);
	nand_debug("data_block_size:0x%x", chip_info->data_block_size);
	nand_debug("log_block_num:0x%x", chip_info->log_block_num);
	nand_debug("log_page_num:0x%x", chip_info->log_page_num);
	nand_debug("log_page_size:0x%x", chip_info->log_page_size);
	nand_debug("log_block_size:0x%x", chip_info->log_block_size);
	nand_debug("log_oob_size:0x%x", chip_info->log_oob_size);
	nand_debug("slc_ratio:0x%x", chip_info->slc_ratio);
	nand_debug("start_block:0x%x", chip_info->start_block);
	nand_debug("sector_size_shift:0x%x", chip_info->sector_size_shift);
	nand_debug("max_keep_pages:0x%x", chip_info->max_keep_pages);
	nand_debug("types:0x%x", chip_info->types);
	nand_debug("plane_mask:0x%x", chip_info->plane_mask);
	nand_debug("plane_num:0x%x", chip_info->plane_num);
	nand_debug("chip_num:0x%x", chip_info->chip_num);
	nand_debug("option:0x%x", chip_info->option);
}

static void mtk_nand_dump_bbt_info(struct mtk_nand_chip_bbt_info *chip_bbt)
{
	unsigned int i;

	nand_info("bad_block_num:%d, initial_bad_num:%d", chip_bbt->bad_block_num,
		chip_bbt->initial_bad_num);
	for (i = 0; i < chip_bbt->bad_block_num; i++)
		nand_info("bad_index:%d", chip_bbt->bad_block_table[i]);
}

static inline bool block_num_is_valid(
	struct mtk_nand_chip_info *info,
	unsigned int block)
{
	return (block >= 0 && block <
		(info->data_block_num + info->log_block_num));
}

int mtk_chip_bbt_init(data_bmt_struct *data_bmt)
{
	struct mtk_nand_chip_bbt_info *chip_bbt = &data_info->chip_bbt;
	unsigned int i, initial_bad_num;
	unsigned int initial_bad, ftl_mark_bad;
	u16 bad_block;

	chip_bbt->bad_block_num = data_bmt->bad_count;
	chip_bbt->initial_bad_num = data_bmt->bad_count;
	if (data_bmt->bad_count > BAD_BLOCK_MAX_NUM) {
		nand_err("bad block count > max(%d)", BAD_BLOCK_MAX_NUM);
		return -1;
	}

	initial_bad_num = 0;
	for (i = 0; i < data_bmt->bad_count; i++)
		if (data_bmt->entry[i].flag != FTL_MARK_BAD)
			initial_bad_num++;

	chip_bbt->initial_bad_num = initial_bad_num;
	initial_bad = 0;
	ftl_mark_bad = initial_bad_num;

	for (i = 0; i < data_bmt->bad_count; i++) {
		bad_block = data_bmt->entry[i].bad_index - data_bmt->start_block;
		if (data_bmt->entry[i].flag != FTL_MARK_BAD) {
			chip_bbt->bad_block_table[initial_bad] = bad_block;
			initial_bad++;
		} else {
			chip_bbt->bad_block_table[ftl_mark_bad] = bad_block;
			ftl_mark_bad++;
		}
	}

	for (i = data_bmt->bad_count; i < BAD_BLOCK_MAX_NUM; i++)
		chip_bbt->bad_block_table[i] = 0xffff;

	mtk_nand_dump_bbt_info(chip_bbt);

	return 0;
}

bool is_slc_block(struct mtk_nand_chip_info *info, unsigned int block)
{
#ifdef ALL_SLC_BUFFER
	int index, bit;

	index = block / 8;
	bit = block % 8;

	if ((info->block_type_bitmap[index] >> bit) & 1)
		return FALSE;
	return TRUE;
#else
	return block >= info->data_block_num;
#endif
}

static int mtk_nand_read_pages(struct mtk_nand_chip_info *info,
		unsigned char *data_buffer, unsigned char *oob_buffer,
		unsigned int block, unsigned int page,
		unsigned int offset, unsigned int size)
{
	static unsigned char *fdm_buf;
#ifdef MTK_FORCE_READ_FULL_PAGE
	static unsigned char *page_buf;
#endif
	unsigned int page_addr, page_size, oob_size;
	unsigned int sect_num, start_sect;
	unsigned int sect_read;
	unsigned int backup_corrected;
	int ret = 0;
#ifdef ALL_SLC_BUFFER
	bool block_type;
#endif

	nand_debug("block:%d page:%d offset:%d size:%d",
		block, page, offset, size);

	backup_corrected = 0;
#ifdef ALL_SLC_BUFFER
	block_type = is_slc_block(info, block);

	if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
		&& block_type)
		page_addr = (block+data_info->bmt.start_block)*info->data_page_num+page*MTK_TLC_DIV;

	else
		page_addr = (block+data_info->bmt.start_block)*info->data_page_num+page;

	/* For log area access */
	if (!block_type) {
		devinfo.tlcControl.slcopmodeEn = FALSE;
		page_size = info->data_page_size;
		oob_size = info->log_oob_size;
	} else {
		/* nand_debug("Read SLC mode"); */
		devinfo.tlcControl.slcopmodeEn = TRUE;
		page_size = info->log_page_size;
		oob_size = info->log_oob_size;
	}

#else
	if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
		&& (block >= info->data_block_num))
		page_addr = (block+data_info->bmt.start_block)*info->data_page_num+page*MTK_TLC_DIV;

	else
		page_addr = (block+data_info->bmt.start_block)*info->data_page_num+page;

	/* For log area access */
	if (block < info->data_block_num) {
		devinfo.tlcControl.slcopmodeEn = FALSE;
		page_size = info->data_page_size;
		oob_size = info->log_oob_size;
	} else {
		/* nand_debug("Read SLC mode"); */
		devinfo.tlcControl.slcopmodeEn = TRUE;
		page_size = info->log_page_size;
		oob_size = info->log_oob_size;
	}
#endif
	if (fdm_buf == NULL) {
		fdm_buf = malloc(1024);
		if (fdm_buf == NULL) {
			ret = -EINVAL;
			nand_err("kmalloc fdm_buf fail\n");
			goto exit;
		} else {
			nand_info("kmalloc success. fdm_buf:%p\n", fdm_buf);
		}
	}

	if (size < page_size) {

		/* Sector read case */
		sect_num = page_size >> info->sector_size_shift;
		start_sect  = offset >> info->sector_size_shift;
		sect_read = size >> info->sector_size_shift;
		/* nand_debug("Sector read col_addr:0x%x sect_read:%d, sect_num:%d, start_sect:%d", */
			/* col_addr, sect_read, sect_num, start_sect); */

		if (page_buf == NULL) {
			page_buf = malloc(page_size);
			if (page_buf == NULL) {
				ret = -ENOMEM;
				nand_err("kmalloc page_buf fail!!!size:%d\n", page_size);
				goto exit;
			} else {
				nand_info("kmalloc success. page_buf:%p\n", page_buf);
			}
		}
		ret = nand_exec_read_page_hw(&g_nand_chip, page_addr, page_size, page_buf, fdm_buf);

		memcpy(data_buffer, page_buf+offset, size);
		memcpy(oob_buffer, fdm_buf+start_sect*g_nand_chip.nand_fdm_size,
			sect_read*g_nand_chip.nand_fdm_size);
	} else {
		ret = nand_exec_read_page_hw(&g_nand_chip, page_addr, page_size, data_buffer, fdm_buf);
		memcpy(oob_buffer, fdm_buf, oob_size);
	}

	if (ret != ERR_RTN_SUCCESS) {
		ret = -ENANDREAD;
	} else
		ret = 0;

exit:

	return ret;

}

static bool can_multi_plane(unsigned int block0, unsigned int page0,
				unsigned int block1, unsigned int page1)
{

	return ((block0 + block1) & 0x1) && (page0 == page1);
}

static bool is_multi_plane(struct mtk_nand_chip_info *info)
{
	return (devinfo.advancedmode & MULTI_PLANE);
}

static bool is_multi_read_support(struct mtk_nand_chip_info *info)
{
	return is_multi_plane(info) && (devinfo.vendor == VEND_MICRON);
}

static struct nand_work *seek_list_item(
	struct nand_work *cur, unsigned int offset)
{
	struct nand_work *item;
	int i;

	i = 0;
	item = cur;
	while (i < offset) {
		item = item->next;
		i++;
	}
	return item;
}

static bool can_ops_multi_plane(struct mtk_nand_chip_operation *ops0,
		struct mtk_nand_chip_operation *ops1)
{
	struct mtk_nand_chip_info *info = ops0->info;

	if (!is_multi_plane(info))
		return false;

	return can_multi_plane(ops0->block, ops0->page, ops1->block,
				ops1->page);
}

static void call_multi_work_callback(
	struct nand_work *cur, int count, int status)
{
	int i;
	struct nand_work *work;
	struct mtk_nand_chip_operation *ops;

	work = cur;
	for (i = 0; i < count; i++)  {
		if (work == NULL) {
			nand_err("NULL item");
			return;
		}
		ops = &work->ops;
		nand_debug("callback i:%d, block:%d page:%d",
			i, ops->block, ops->page);
		ops->callback(ops->info, ops->data_buffer,
			ops->oob_buffer, ops->block,
			ops->page, status, ops->userdata);
		if (i >= count)
			break;
		work = work->next;
	}
}

static void call_tlc_page_group_callback(
	struct nand_work *base_node, int start, int end,
	bool multi_plane, int status)
{
	int i;
	int count = multi_plane ? 2 : 1;
	struct nand_work *work;

	work = seek_list_item(base_node, start*count);
	for (i = 0; i < end - start + 1; i++) {
		call_multi_work_callback(
			work, count, status);

		if (i >= end - start)
			break;
		if (count == 1)
			work = work->next;
		else
			work = work->next->next;
	}
}

static inline bool block_page_num_is_valid(
	struct mtk_nand_chip_info *info,
	unsigned int block, unsigned int page)
{
	if (!block_num_is_valid(info, block))
		return false;

	if (page < 0)
		return false;

#ifdef ALL_SLC_BUFFER
	if ((!is_slc_block(info, block) &&
		page < info->data_page_num) ||
		(is_slc_block(info, block) &&
		page < info->log_page_num))
		return true;
	else
		return false;
#else
	if ((block < info->data_block_num &&
		page < info->data_page_num) ||
		(block >= info->data_block_num &&
		page < info->log_page_num))
		return true;
	else
		return false;
#endif
}

/**
 * mtk_nand_write_pages -  NAND write with ECC
 * @ops: mtk_nand_chip_operation structure
 * @lecountn: number of pages to write
 *
 * NAND write with ECC.
 */
static int mtk_nand_write_pages(struct mtk_nand_chip_operation *ops0,
		struct mtk_nand_chip_operation *ops1)
{
	struct mtk_nand_chip_info *info = &data_info->chip_info;
	unsigned char *fdm_buf = NULL;
	unsigned char *temp_page_buf = NULL;
	unsigned char *temp_fdm_buf = NULL;
	unsigned int page_addr0, page_addr1;
	unsigned int page_size, oob_size, sect_num;
	int ret = 0;

	if (ops0 == NULL) {
		nand_err("ops0 is NULL");
		return -EINVAL;
	}

	if (ops1 != NULL) {
		/* Check both in data or log area */
#ifdef ALL_SLC_BUFFER
		if (is_slc_block(info, ops1->block) != is_slc_block(info, ops0->block)) {
			nand_err("do not in same area ops0->block:0x%x ops1->block:0x%x ",
				ops0->block, ops1->block);
			return -EINVAL;
		}
#else
		if (((ops0->block < info->data_block_num)
				&& (ops1->block >= info->data_block_num))
			|| ((ops0->block >= info->data_block_num)
				&& (ops1->block < info->data_block_num))) {
			nand_err("do not in same area ops0->block:0x%x ops1->block:0x%x ",
				ops0->block, ops1->block);
			return -EINVAL;
		}
#endif
		if (mtk_isbad_block(ops1->block))
			page_addr1 = 0;
		else {
#ifdef ALL_SLC_BUFFER
			if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
				&& is_slc_block(info, ops1->block)) {
				page_addr1 = (ops1->block+data_info->bmt.start_block)*info->data_page_num
						+ ops1->page*MTK_TLC_DIV;
			} else {
				page_addr1 = (ops1->block+data_info->bmt.start_block)*info->data_page_num
					+ ops1->page;
			}
#else
			if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
				&& (ops1->block >= info->data_block_num)) {
				page_addr1 = (ops1->block+data_info->bmt.start_block)*info->data_page_num
						+ ops1->page*MTK_TLC_DIV;
			} else {
				page_addr1 = (ops1->block+data_info->bmt.start_block)*info->data_page_num
					+ ops1->page;
			}
#endif
		}
	} else {
		page_addr1 = 0;
	}

#ifdef ALL_SLC_BUFFER
	if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
		&& is_slc_block(info, ops0->block))
		page_addr0 = (ops0->block+data_info->bmt.start_block)*info->data_page_num
				+ ops0->page*MTK_TLC_DIV;
	else
		page_addr0 = (ops0->block+data_info->bmt.start_block)*info->data_page_num
				+ ops0->page;
#else
	if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
		&& (ops0->block >= info->data_block_num))
		page_addr0 = (ops0->block+data_info->bmt.start_block)*info->data_page_num
				+ ops0->page*MTK_TLC_DIV;
	else
		page_addr0 = (ops0->block+data_info->bmt.start_block)*info->data_page_num
				+ ops0->page;
#endif
	nand_debug("page_addr0= 0x%x page_addr1=0x%x",
		page_addr0, page_addr1);
#ifdef ALL_SLC_BUFFER
	if (!is_slc_block(info, ops0->block)) {
		page_size = info->data_page_size;
		devinfo.tlcControl.slcopmodeEn = FALSE;
		oob_size = info->data_oob_size;
	} else {
		nand_debug("write SLC mode");
		page_size = info->log_page_size;
		devinfo.tlcControl.slcopmodeEn = TRUE;
		oob_size = info->log_oob_size;
	}

#else
	/* For log area access */
	if (ops0->block < info->data_block_num) {
		page_size = info->data_page_size;
		devinfo.tlcControl.slcopmodeEn = FALSE;
		oob_size = info->data_oob_size;
	} else {
		nand_debug("write SLC mode");
		page_size = info->log_page_size;
		devinfo.tlcControl.slcopmodeEn = TRUE;
		oob_size = info->log_oob_size;
	}
#endif
	sect_num = page_size/(1<<info->sector_size_shift);
	fdm_buf = malloc(1024);
	if (fdm_buf == NULL) {
		ret = -ENOMEM;
		goto exit;
	}
	memset(fdm_buf, 0xff, 1024);
	if (devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC) {
		if ((devinfo.tlcControl.normaltlc) && (devinfo.tlcControl.pPlaneEn)) {
			page_size /= 2;
			sect_num /= 2;
			tlc_lg_left_plane = TRUE;
			memcpy(fdm_buf, ops0->oob_buffer, oob_size);
			temp_page_buf = ops0->data_buffer;
			temp_fdm_buf = fdm_buf;
			ret = nand_exec_write_page_hw(&g_nand_chip, page_addr0,
						page_size, temp_page_buf, fdm_buf);
			if (ret != 1) {
				nand_err("write failed for page_addr0:0x%x", page_addr0);
				ret = -ENANDWRITE;
				goto exit;
			}

			tlc_lg_left_plane = FALSE;
			temp_page_buf += page_size;
			temp_fdm_buf += (sect_num * g_nand_chip.nand_fdm_size);

			ret = nand_exec_write_page_hw(&g_nand_chip, page_addr0,
						page_size, temp_page_buf, fdm_buf);
			if (ret != 1) {
				nand_err("write failed for page_addr0:0x%x", page_addr0);
				ret = -ENANDWRITE;
				goto exit;
			}

			if ((devinfo.advancedmode & MULTI_PLANE)  && page_addr1) {
				nand_debug("write Multi_plane mode page_addr0:0x%x page_addr1:0x%x",
					page_addr0, page_addr1);
				tlc_lg_left_plane = TRUE;
				memcpy(fdm_buf, ops1->oob_buffer, oob_size);

				temp_page_buf = ops1->data_buffer;
				temp_fdm_buf = fdm_buf;

				ret = nand_exec_write_page_hw(&g_nand_chip, page_addr1, page_size,
						temp_page_buf, temp_fdm_buf);
				if (ret != 1) {
					nand_err("write failed for page_addr1:0x%x", page_addr1);
					ret = -ENANDWRITE;
					goto exit;
				}

				tlc_lg_left_plane = FALSE;
				temp_page_buf += page_size;
				temp_fdm_buf += (sect_num * g_nand_chip.nand_fdm_size);

				ret  = nand_exec_write_page_hw(&g_nand_chip, page_addr1, page_size,
						temp_page_buf, temp_fdm_buf);
				if (ret != 1) {
					nand_err("write failed for page_addr1:0x%x", page_addr1);
					ret = -ENANDWRITE;
					goto exit;
				}
			}
		} else {
			memcpy(fdm_buf, ops0->oob_buffer, oob_size);
			temp_page_buf = ops0->data_buffer;
			temp_fdm_buf = fdm_buf;
			ret = nand_exec_write_page_hw(&g_nand_chip, page_addr0,
					page_size, temp_page_buf, fdm_buf);
			if (ret != 1) {
				nand_err("write failed for page_addr0:0x%x", page_addr0);
				ret = -ENANDWRITE;
				goto exit;
			}

			if ((devinfo.tlcControl.normaltlc)
					&& ((devinfo.advancedmode & MULTI_PLANE) && page_addr1)) {
				nand_debug("write Multi_plane mode page_addr0:0x%x page_addr1:0x%x",
					page_addr0, page_addr1);
				memcpy(fdm_buf, ops1->oob_buffer, oob_size);

				temp_page_buf = ops1->data_buffer;
				temp_fdm_buf = fdm_buf;

				ret = nand_exec_write_page_hw(&g_nand_chip, page_addr1, page_size,
						temp_page_buf, temp_fdm_buf);
				if (ret != 1) {
					nand_err("write failed for page_addr1:0x%x", page_addr1);
					ret = -ENANDWRITE;
					goto exit;
				}
			}
		}
	} else {
		memcpy(fdm_buf, ops0->oob_buffer, oob_size);

		ret = nand_exec_write_page_hw(&g_nand_chip, page_addr0,
				page_size, ops0->data_buffer, fdm_buf);
		if (ret != 1) {
			nand_err("write failed for page_addr0:0x%x", page_addr0);
			ret = -ENANDWRITE;
			goto exit;
		}

		if ((devinfo.advancedmode & MULTI_PLANE)  && page_addr1) {
			nand_debug("write Multi_plane mode page_addr0:0x%x page_addr1:0x%x",
				page_addr0, page_addr1);
			memcpy(fdm_buf, ops1->oob_buffer, oob_size);
			ret = nand_exec_write_page_hw(&g_nand_chip, page_addr1,
						page_size, ops1->data_buffer, fdm_buf);
			if (ret != 1) {
				nand_err("write failed for page_addr1:0x%x", page_addr1);
				ret = -ENANDWRITE;
				goto exit;
			}
		}

	}

exit:
	free(fdm_buf);

	if (ret != 1) {
		nand_err("fail!!!ret:%d, block0:%d, page0:%d\n", ret, ops0->block, ops0->page);
		if (ops1)
			nand_err("fail!!!ret:%d, block1:%d, page1:%d\n", ret, ops1->block, ops1->page);
		return ret;
	}
	return 0;
}


static int do_multi_work_write(struct nand_work *cur, int count)
{
	int i, status = 0;
	struct nand_work *work;
	struct mtk_nand_chip_operation *ops0, *ops1;
	bool multi_plane = false;
	bool multi_plane_en;

	ops0 = NULL;
	ops1 = NULL;
	work = cur;
	for (i = 0; i < count; i++)  {
		if (work == NULL) {
			nand_err("NULL item");
			return -ENANDWRITE;
		}
		if (i == 0)
			ops0 = &work->ops;
		else if (i == 1)
			ops1 = &work->ops;

		if (i+1 >= count)
			break;
		work = work->next;
	}
	multi_plane_en = (devinfo.advancedmode & MULTI_PLANE) ? true : false;

	if (multi_plane_en) {
		if (ops1 != NULL)
			multi_plane = are_on_diff_planes(ops0->block, ops1->block);

		if (multi_plane)
			return mtk_nand_write_pages(ops0, ops1);
	}

	if (multi_plane_en)
		devinfo.advancedmode &= (~MULTI_PLANE);
	status = mtk_nand_write_pages(ops0, NULL);
	if (status)
		goto OUT;
	if (ops1 != NULL)
		status = mtk_nand_write_pages(ops1, NULL);

OUT:
	if (multi_plane_en)
		devinfo.advancedmode |= MULTI_PLANE;
	return status;
}


static int do_tlc_page_group_write(struct nand_work *cur, int start,
	int step, NFI_TLC_PG_CYCLE program_cycle, enum TLC_MULTI_PROG_MODE prog_mode)
{
	struct nand_work *item;
	int status = 0, i;
	int count;


	item = seek_list_item(cur, start * step);

	nand_debug("start:%d, item:%p", start, item);



	devinfo.tlcControl.slcopmodeEn = FALSE;
	tlc_program_cycle = program_cycle;

	count = (prog_mode == MULTI_BLOCK) ? 2 : 1;
	item = (prog_mode == BLOCK1_ONLY) ? item->next : item;

	for (i = 0; i < 3; i++) {
		status = do_multi_work_write(item, count);
		if (status)
			break;
		if (i >= 2)
			break;
		if (step == 1)
			item = item->next;
		else
			item = item->next->next;
	}

	return status;
}

static int do_tlc_wl_write(struct mtk_nand_chip_info *info, struct nand_work *start_node,
		enum TLC_MULTI_PROG_MODE prog_mode)
{
	struct nand_work *work;
	struct mtk_nand_chip_operation *ops;
	int status, step;

	work = start_node;
	ops = &work->ops;

	if ((ops->page % MTK_TLC_DIV) != 0) {
		nand_err("Not TLC(3 pages) alsigned ops->page:0x%x",
			ops->page);
		return -1;
	}

	step = (devinfo.advancedmode & MULTI_PLANE) ? 2 : 1;

	if (ops->page == 0) {
		status = do_tlc_page_group_write(work, 0, step, PROGRAM_1ST_CYCLE, prog_mode);
		if (status)
			return status;
		status = do_tlc_page_group_write(work, 3, step, PROGRAM_1ST_CYCLE, prog_mode);
		if (status)
			return status;
		status = do_tlc_page_group_write(work, 0, step, PROGRAM_2ND_CYCLE, prog_mode);
		if (status)
			return status;
	}


	if ((ops->page/3 + 2) < (info->data_page_num/3)) {
		status = do_tlc_page_group_write(work, 6, step, PROGRAM_1ST_CYCLE, prog_mode);
		if (status)
			return status;
	}

	if ((ops->page/3 + 1) < (info->data_page_num/3)) {
		status = do_tlc_page_group_write(work, 3, step, PROGRAM_2ND_CYCLE, prog_mode);
		if (status)
			return status;
	}

	status = do_tlc_page_group_write(work, 0, step, PROGRAM_3RD_CYCLE, prog_mode);
	if (status)
		return status;

	if (ops->page == (info->data_page_num - 9)) {
		status = do_tlc_page_group_write(work, 6, step, PROGRAM_2ND_CYCLE, prog_mode);
		if (status)
			return status;

		status = do_tlc_page_group_write(work, 3, step, PROGRAM_3RD_CYCLE, prog_mode);
		if (status)
			return status;

		status = do_tlc_page_group_write(work, 6, step, PROGRAM_3RD_CYCLE, prog_mode);
		if (status)
			return status;
	}

	return status;
}


static int do_tlc_write(
	struct mtk_nand_chip_info *info,
	struct worklist_ctrl *list_ctrl,
	int count)
{
	struct nand_work *work, *work1;
	struct mtk_nand_chip_operation *ops;
	int status;
	bool multi_plan = false;
	int free_count;
	enum TLC_MULTI_PROG_MODE prog_mode;

	if (count != info->max_keep_pages) {
		nand_err("error:count:%d max:%d",
			count, info->max_keep_pages);
		return -EINVAL;
	}

	multi_plan = (devinfo.advancedmode & MULTI_PLANE) ? true : false;

	work = list_ctrl->head;
	ops = &work->ops;

	nand_debug("page num:%d", ops->page);

	if ((ops->page % MTK_TLC_DIV) != 0) {
		nand_err("Not TLC(3 pages) alsigned ops->page:0x%x", ops->page);
		return NULL;
	}

	if (multi_plan) {
		work1 = work->next;
		prog_mode = are_on_diff_planes(work->ops.block, work1->ops.block) ? MULTI_BLOCK : BLOCK0_ONLY;
	} else {
		prog_mode = BLOCK0_ONLY;
	}
	status = do_tlc_wl_write(info, work, prog_mode);

	if (!status && multi_plan && (prog_mode == BLOCK0_ONLY))
		status = do_tlc_wl_write(info, work, BLOCK1_ONLY);

	call_tlc_page_group_callback(work, 0, 2, multi_plan, status);

	if (multi_plan)
		work = seek_list_item(work, 8 * 2);
	else
		work = seek_list_item(work, 8);

	free_count = multi_plan ? 2 : 1;
	free_multi_write_work(list_ctrl, (3 * free_count));

	ops = &work->ops;

	if (ops->page == (info->data_page_num - 1)) {
		work = list_ctrl->head;
		/*3~5*/
		call_tlc_page_group_callback(work, 0, 2,
						multi_plan, status);
		/*6~8*/
		call_tlc_page_group_callback(work, 3, 5,
						multi_plan, status);
		/*3~8*/
		free_multi_write_work(list_ctrl, (6 * free_count));
	}

	return 0;
}


static int mtk_nand_do_write(struct mtk_nand_chip_info *info,
		struct worklist_ctrl *list_ctrl, int count)
{
	if (info->types == NAND_FLASH_TLC)
		return do_tlc_write(info, list_ctrl, count);

	nand_err("unhandled work!\n");
	return NULL;
}

static int mtk_nand_do_slc_write(
	struct mtk_nand_chip_info *info,
		struct worklist_ctrl *list_ctrl, int count)
{
	struct mtk_nand_chip_operation *ops[2];
	struct nand_work *work;
	struct list_node *node;
	int i, status;

	if (!count)
		return NULL;

	if (count != 1 && count != 2) {
		nand_err("count not 1 or 2, count:%d\n", count);
		return NULL;
	}

	ops[0] = &list_ctrl->head->ops;
	if (count == 2)
		ops[1] = &list_ctrl->head->next->ops;
	else
		ops[1] = NULL;

	status = mtk_nand_write_pages(ops[0], ops[1]);

	call_multi_work_callback(list_ctrl->head, count, status);
	free_multi_write_work(list_ctrl, count);
	return 0;
}

static unsigned int complete_write_count(struct mtk_nand_chip_info *info,
				struct worklist_ctrl *list_ctrl)
{
	return (list_ctrl->total_num >= info->max_keep_pages) ? info->max_keep_pages : 0;
}

static unsigned int complete_slc_write_count(struct mtk_nand_chip_info *info,
				struct worklist_ctrl *list_ctrl)
{
	struct list_node *head;
	struct nand_work *work0, *work1;
	bool multi_op;

	if (!list_ctrl->head)
		return 0;
	if (!is_multi_plane(info))
		return 1;
	/* multi plane, but not ready*/
	if (list_ctrl->total_num != 2)
		return 0;
	/* total >= plane_num */
	work0 = list_ctrl->head;
	work1 = list_ctrl->head->next;
	multi_op = can_ops_multi_plane(&work0->ops, &work1->ops);
	return multi_op ? 2 : 1;
}

static void mtk_nand_dump_bmt_info(data_bmt_struct *data_bmt)
{
	unsigned int i;

	nand_debug("nand_ftl_partition_info dump info here");
	nand_debug("bad_count:0x%x", data_bmt->bad_count);
	nand_debug("start_block:0x%x", data_bmt->start_block);
	nand_debug("end_block:0x%x", data_bmt->end_block);
	nand_debug("version:%d", data_bmt->version);

	for (i = 0; i < data_bmt->bad_count; i++) {
		nand_debug("bad_index:0x%x, flag:%d",
			data_bmt->entry[i].bad_index,
			data_bmt->entry[i].flag);
	}
}


/*********************************global***************************************/

bool mtk_isbad_block(unsigned int block)
{
	struct mtk_nand_chip_bbt_info *chip_bbt;
	unsigned int i;

	chip_bbt = &data_info->chip_bbt;
	for (i = 0; i < chip_bbt->bad_block_num; i++) {
		if (block == chip_bbt->bad_block_table[i]) {
			nand_debug("Check block:0x%x is bad", block);
			return TRUE;
		}
	}

	/* nand_debug("Check block:0x%x is Good", block); */
	return FALSE;
}

int mtk_nand_data_info_init(void)
{
	unsigned int data_struct_size;

	data_struct_size = sizeof(struct mtk_nand_data_info);
	data_info = malloc(data_struct_size);
	if (data_info == NULL) {
		nand_err("Malloc datainfo size: 0x%x failed\n",
			data_struct_size);
		return -ENOMEM;
	}
	memset(data_info, 0, data_struct_size);

	return 0;
}


int mtk_nand_chip_read_page(struct mtk_nand_chip_info *info,
		unsigned char *data_buffer, unsigned char *oob_buffer,
		unsigned int block, unsigned int page,
		unsigned int offset, unsigned int size)
{
	int ret = 0;

	if (data_buffer == NULL) {
		nand_err("data_buffer is null");
		return -EINVAL;
	}

	if (oob_buffer == NULL) {
		nand_err("oob_buffer is null");
		return -EINVAL;
	}

	if ((offset % (1 << info->sector_size_shift) != 0)
		|| (size % (1 << info->sector_size_shift) != 0)) {
		nand_err("offset or size is invalid:offset:%d, size:%d",
			offset, size);
		return -EINVAL;
	}

	if (!block_page_num_is_valid(info, block, page)) {
		nand_err("block or page num is invalid:block:%d, page:%d",
			block, page);
		return -EINVAL;
	}

	if (mtk_isbad_block(block))
		return -ENANDBAD;

	ret = mtk_nand_read_pages(info, data_buffer,
		oob_buffer, block, page, offset, size);

	if (ret) {
		nand_err("read err:%d, block:%d, page:%d, offset:%d, size:%d\n",
			ret, block, page, offset, size);
	}

	return ret;
}

int mtk_nand_chip_read_multi_pages(struct mtk_nand_chip_info *info, int page_num,
			struct mtk_nand_chip_read_param *param)

{
	struct mtk_nand_chip_read_param *p = param;
	int ret;

	if (!page_num) {
		nand_err("page_num is 0, so return 0\n");
		/* dump_stack(); */
		return 0;
	}

	if (page_num == 1 || !is_multi_read_support(info)) {
		ret = mtk_nand_chip_read_page(info, p->data_buffer, p->oob_buffer,
					p->block, p->page, p->offset, p->size);
		return ret ? ret : 1;
	}

	if (!can_multi_plane(p->block, p->page, p[1].block, p[1].page)) {
		ret = mtk_nand_chip_read_page(info, p->data_buffer, p->oob_buffer,
					p->block, p->page, p->offset, p->size);
		return ret ? ret : 1;
	}
	ret = mtk_nand_chip_read_page(info, p->data_buffer, p->oob_buffer,
					p->block, p->page, p->offset, p->size);
		return ret ? ret : 1;
}

int mtk_nand_chip_write_page(struct mtk_nand_chip_info *info,
		unsigned char *data_buffer, unsigned char *oob_buffer,
		unsigned int block, unsigned int page, bool more_page,
		mtk_nand_callback_func callback, void *userdata)
{
	/* Add to worklist here*/
	struct nand_work *work;
	struct mtk_nand_chip_operation *ops;
	int total_num;
	unsigned int max_keep_pages;
	int page_num;
	int ret;

	nand_debug("write block:%d page:%d more_page:%d\n", block, page, more_page);

	if (data_buffer == NULL) {
		nand_err("data_buffer is null");
		return -EINVAL;
	}

	if (oob_buffer == NULL) {
		nand_err("oob_buffer is null");
		return -EINVAL;
	}

	if (!block_page_num_is_valid(info, block, page)) {
		nand_err("block or page num is invalid:block:%d, page:%d",
			block, page);
		return -EINVAL;
	}

#ifdef ALL_SLC_BUFFER
	max_keep_pages = is_slc_block(info, block) ?
			info->plane_num : info->max_keep_pages;
#else
	max_keep_pages = (block < info->data_block_num) ?
			info->max_keep_pages : info->plane_num;
#endif

	work = malloc(sizeof(struct nand_work));
	if (work == NULL)
		return -ENOMEM;

	work->next = NULL;
	ops = &work->ops;

	ops->info = info;
	ops->types = MTK_NAND_OP_WRITE;
	ops->data_buffer = data_buffer;
	ops->oob_buffer = oob_buffer;
	ops->block = block;
	ops->page = page;
	ops->more = more_page;
	ops->callback = callback;
	ops->userdata = userdata;
#ifdef ALL_SLC_BUFFER
	if (!is_slc_block(info, block)) {
		add_work_list(&data_info->wlist_ctrl, work);
		ret = complete_write_count(info, &data_info->wlist_ctrl);
		if (ret)
			mtk_nand_do_write(info, &data_info->wlist_ctrl, ret);
	} else {
		add_work_list(&data_info->swlist_ctrl, work);
		ret = complete_slc_write_count(info, &data_info->swlist_ctrl);
		if (ret)
			mtk_nand_do_slc_write(info, &data_info->swlist_ctrl, ret);
	}
#else
	if (block < info->data_block_num) {
		add_work_list(&data_info->wlist_ctrl, work);
		ret = complete_write_count(info, &data_info->wlist_ctrl);
		if (ret)
			mtk_nand_do_write(info, &data_info->wlist_ctrl, ret);
	} else {
		add_work_list(&data_info->swlist_ctrl, work);
		ret = complete_slc_write_count(info, &data_info->swlist_ctrl);
		if (ret)
			mtk_nand_do_slc_write(info, &data_info->swlist_ctrl, ret);
	}
#endif

	return 0;
}

int mtk_nand_chip_sync(struct mtk_nand_chip_info *info)
{
	return 0;
}

void mtk_nand_chip_set_blk_thread(struct task_struct *thead)
{

}

const struct mtk_nand_chip_bbt_info *mtk_nand_chip_bmt(struct mtk_nand_chip_info *info)
{

	if (&data_info->chip_bbt != NULL)
		return &data_info->chip_bbt;
	else
		return 0;
}

void mtk_chip_mark_bad_block(struct mtk_nand_chip_info *info, unsigned int block)
{
	struct mtk_nand_chip_bbt_info *chip_bbt = &data_info->chip_bbt;
	unsigned int i;
	bool success;

	nand_err("markbad block:%d", block);
	for (i = 0; i < chip_bbt->bad_block_num; i++) {
		if (block == chip_bbt->bad_block_table[i])
			return;
	}

	chip_bbt->bad_block_table[chip_bbt->bad_block_num++] = block;

	success = update_bmt(((u64)(block + data_info->bmt.start_block)) * info->data_block_size,
			FTL_MARK_BAD, NULL, NULL);
	if (!success)
		nand_err("mark block(%d) as bad fail!!!\n", block);

}


/*
 * mtk_nand_chip_erase_block
 * Erase API for nand wrapper, async mode for erase, just return success,
 * put erase operation into write worklist.
 * After Nand driver erase/write operation, callback function will be done.
 * @block: The block to erase
 * @*callback: Callback for wrapper, called after driver finish the operation.
 * @* userdata: for callback function
 * return : 0 on success, On error, return error num casted by ERR_PTR
 */
int mtk_nand_chip_erase_block(struct mtk_nand_chip_info *info,
		unsigned int block, unsigned int more_block,
		mtk_nand_callback_func callback, void *userdata)
{
	int total_num;
	u64 offset;
	bool status;
	int ret_status;

	nand_debug("erase block:%d more_page:%d\n", block, more_block);

	if (!block_num_is_valid(info, block)) {
		nand_err("block num is invalid:block:%d", block);
		return -EINVAL;
	}

#ifdef ALL_SLC_BUFFER
	if (!is_slc_block(info, block)) {
		devinfo.tlcControl.slcopmodeEn = FALSE;
	} else {
		nand_debug("erase SLC mode");
		devinfo.tlcControl.slcopmodeEn = TRUE;
	}
#else
	if (block < info->data_block_num) {
		devinfo.tlcControl.slcopmodeEn = FALSE;
	} else {
		nand_debug("erase SLC mode");
		devinfo.tlcControl.slcopmodeEn = TRUE;
	}
#endif
	offset = (u64)((block+data_info->bmt.start_block) * info->data_page_num);
	offset = offset * info->data_page_size;
	status = nand_erase_hw(offset);

	if (status)
		ret_status = 0;
	else
		ret_status = -EIO;
	callback(info, NULL, NULL, block, 0, ret_status, userdata);

	return ret_status;

}

struct mtk_nand_chip_info *mtk_nand_chip_init(void)
{

	if (&data_info->chip_info != NULL)
		return &data_info->chip_info;
	else
		return 0;
}

int mtk_nand_ops_init(void)
{
	int ret = 0;

	mtk_nand_data_info_init();

	ret = get_data_partition_info(&data_info->partition_info, &data_info->chip_info);
	if (ret) {
		nand_err("Get FTL partition info failed\n");
		goto err_out;
	}
	mtk_nand_dump_partition_info(&data_info->partition_info);

	ret = get_data_bmt(&data_info->bmt);
	if (ret) {
		nand_err("Get FTL bmt info failed\n");
		goto err_out;
	}
	mtk_nand_dump_bmt_info(&data_info->bmt);

	mtk_chip_info_init(&data_info->chip_info);

	mtk_nand_dump_chip_info(&data_info->chip_info);

	ret = mtk_chip_bbt_init(&data_info->bmt);
	if (ret) {
		nand_err("Get chip bbt info failed\n");
		goto err_out;
	}


#ifdef MTK_NAND_CHIP_TEST
	mtk_chip_unit_test();
#endif
	return 0;

err_out:
	return ret;
}

int mtk_nand_update_block_type(int num, unsigned int *blk)
{
	return mntl_update_part_tab(&data_info->chip_info, num, blk);
}


