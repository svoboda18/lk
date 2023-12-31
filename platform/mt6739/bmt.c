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
#include <stdio.h>
#include <platform/mtk_nand_ops.h>
#include <platform/bmt.h>

typedef struct {
	char signature[3];
	u8 version;
	u8 bad_count;               // bad block count in pool
	u8 mapped_count;            // mapped block count in pool
	u8 checksum;
	u8 reseverd[13];
} phys_bmt_header;

typedef struct {
	phys_bmt_header header;
	bmt_entry table[MAX_BMT_SIZE];
} phys_bmt_struct;

typedef struct {
	char signature[3];
} bmt_oob_data;

static char MAIN_SIGNATURE[] = "BMT";
static char OOB_SIGNATURE[] = "bmt";
#define SIGNATURE_SIZE      (3)

#define MAX_DAT_SIZE        0x4000
#define MAX_OOB_SIZE        0x800

extern flashdev_info devinfo;
#if defined(MTK_TLC_NAND_SUPPORT)
extern bool mtk_nand_write_tlc_block_hw(struct nand_chip *chip,
                                        uint8_t *buf, u32 mapped_block);
extern bool mtk_block_istlc(u64 addr);

extern unsigned char g_spare_buf[MAX_OOB_SIZE];
#endif
static struct nand_chip *nand_chip_bmt;
#define PAGE_SIZE_BMT           (nand_chip_bmt->page_size)
#if !defined(MTK_TLC_NAND_SUPPORT)
#define BLOCK_SIZE_BMT          (nand_chip_bmt->sector_size == 512?nand_chip_bmt->erasesize : nand_chip_bmt->erasesize*2)

#define OFFSET(block)       (((u64)block) * BLOCK_SIZE_BMT)
#define PAGE_ADDR(block)    ((block) * (BLOCK_SIZE_BMT / PAGE_SIZE_BMT))
#else
#define BLOCK_SIZE_BMT          (devinfo.blocksize * 1024)
#define PAGE_PER_SIZE_BMT       ((devinfo.blocksize * 1024) / devinfo.pagesize)
//#define OFFSET(block)       (((u64)block) * BLOCK_SIZE_BMT)
#define PAGE_ADDR(block)    ((block) * PAGE_PER_SIZE_BMT)
extern u64 OFFSET(u32 block);//return logical address
#endif

/*********************************************************************
* Flash is splited into 2 parts, system part is for normal system    *
* system usage, size is system_block_count, another is replace pool  *
*    +-------------------------------------------------+             *
*    |     system_block_count     |   bmt_block_count  |             *
*    +-------------------------------------------------+             *
*********************************************************************/
static u32 total_block_count;   // block number in flash
u32 system_block_count;
static int bmt_block_count;     // bmt table size
static int page_per_block;      // page per count
static u32 bmt_block_index;     // bmt block index
static bmt_struct bmt;          // dynamic created global bmt table
__attribute__((aligned(64))) static u8 dat_buf[MAX_DAT_SIZE];
static u8 oob_buf[MAX_OOB_SIZE];
static bool pool_erased;
extern bool nand_erase_hw (u64 offset);
extern bool mark_block_bad_hw(u64 offset);
extern int nand_write_page_hw(u32 page, u8 *dat, u8 *oob);

/***************************************************************
*
* Interface adaptor for preloader/uboot/kernel
*    These interfaces operate on physical address, read/write
*       physical data.
*
***************************************************************/
int nand_read_page_bmt(u32 page, u8 * dat, u8 * oob)
{
	return nand_exec_read_page_hw(nand_chip_bmt, page, PAGE_SIZE_BMT, dat, oob);

}

bool nand_block_bad_bmt(u64 offset)
{
	return nand_block_bad_hw(nand_chip_bmt, offset);
}

// actually uboot should never use the following 3 functions Fix me kai
bool nand_erase_bmt(u64 offset)
{
	return nand_erase_hw(offset);
}

int mark_block_bad_bmt(u64 offset)
{
#if !defined(MTK_TLC_NAND_SUPPORT)
	return mark_block_bad_hw(offset);
#endif
}

bool nand_write_page_bmt(u32 page, u8 * dat, u8 * oob)
{
	return nand_write_page_hw(page, dat, oob);
}

/***************************************************************
*                                                              *
* static internal function                                     *
*                                                              *
***************************************************************/
static void dump_bmt_info(bmt_struct * bmt)
{
	int i;

	dprintf(INFO, "BMT v%d. total %d mapping:\n", bmt->version, bmt->mapped_count);
	for (i = 0; i < bmt->mapped_count; i++) {
		dprintf(INFO, "\tbad block (0x%x) has been mapped to block (0x%x)\n", bmt->table[i].bad_index, bmt->table[i].mapped_index);
	}
}

static bool match_bmt_signature(u8 * dat, u8 * oob)
{
	if (memcmp(dat + MAIN_SIGNATURE_OFFSET, MAIN_SIGNATURE, SIGNATURE_SIZE)) {
		dprintf(INFO, "[%s]0x%x,0x%x,0x%x,0x%x \n", __FUNCTION__, *((UINT32 *) dat), *(((UINT32 *) dat) + 1), *(((UINT32 *) dat) + 2), *(((UINT32 *) dat) + 3));
		return false;
	}

	if (memcmp(oob + OOB_SIGNATURE_OFFSET, OOB_SIGNATURE, SIGNATURE_SIZE)) {
		dprintf(INFO, "main signature match, oob signature doesn't match, but ignore\n");
	}
	return true;
}

static u8 cal_bmt_checksum(phys_bmt_struct * phys_table, int bmt_size)
{
	u32 i;
	u8 checksum = 0;
	u8 *dat = (u8 *) phys_table;

	checksum += phys_table->header.version;
	checksum += phys_table->header.mapped_count;

	dat += sizeof(phys_bmt_header);
	for (i = 0; i < bmt_size * sizeof(bmt_entry); i++) {
		checksum += dat[i];
	}

	return checksum;
}

// return -1 for unmapped block, and bad block index if mapped.
static int is_block_mapped(int index)
{
	int i;
	for (i = 0; i < bmt.mapped_count; i++) {
		if (index == bmt.table[i].mapped_index)
			return i;
	}
	return -1;
}

static bool is_page_used(u8 * dat, u8 * oob)
{
	if (2048 == PAGE_SIZE_BMT) {
		return ((oob[13] != 0xFF) || (oob[14] != 0xFF));
	} else {
		return ((oob[OOB_INDEX_OFFSET] != 0xFF) || (oob[OOB_INDEX_OFFSET + 1] != 0xFF));
	}
}

static bool valid_bmt_data(phys_bmt_struct * phys_table)
{
	int i;
	u8 checksum = cal_bmt_checksum(phys_table, bmt_block_count);
	if (phys_table->header.checksum != checksum) {
		dprintf(INFO, "BMT Data checksum error: %x %x\n", phys_table->header.checksum, checksum);
		return false;
	}
	dprintf(INFO, "BMT Checksum is: 0x%x\n", phys_table->header.checksum);
	for (i = 0; i < phys_table->header.mapped_count; i++) {
		if (phys_table->table[i].bad_index >= total_block_count || phys_table->table[i].mapped_index >= total_block_count || phys_table->table[i].mapped_index < system_block_count) {
			dprintf(INFO, "index error: bad_index: %d, mapped_index: %d\n", phys_table->table[i].bad_index, phys_table->table[i].mapped_index);
			return false;
		}
	}

	dprintf(INFO, "Valid BMT, version v%d\n", phys_table->header.version);
	return true;
}

static void fill_nand_bmt_buffer(bmt_struct * bmt, u8 * dat, u8 * oob)
{
	phys_bmt_struct *phys_bmt = NULL;

	phys_bmt = (phys_bmt_struct *)malloc(sizeof(phys_bmt_struct));
	if (!phys_bmt) {
		ASSERT(0);
	}

	dump_bmt_info(bmt);

	// fill phys_bmt_struct structure with bmt_struct
	memset(phys_bmt, 0xFF, sizeof(phys_bmt_struct));

	memcpy(phys_bmt->header.signature, MAIN_SIGNATURE, SIGNATURE_SIZE);
	phys_bmt->header.version = BMT_VERSION;
	// phys_bmt.header.bad_count = bmt->bad_count;
	phys_bmt->header.mapped_count = bmt->mapped_count;
	memcpy(phys_bmt->table, bmt->table, sizeof(bmt_entry) * bmt_block_count);

	phys_bmt->header.checksum = cal_bmt_checksum(phys_bmt, bmt_block_count);

	memcpy(dat + MAIN_SIGNATURE_OFFSET, phys_bmt, sizeof(phys_bmt_struct));
	memcpy(oob + OOB_SIGNATURE_OFFSET, OOB_SIGNATURE, SIGNATURE_SIZE);

	memcpy(dat + MAIN_SIGNATURE_OFFSET + sizeof(phys_bmt_struct),
		&(bmt->data_bmt), sizeof(data_bmt_struct));

	free(phys_bmt);
}

// return valid index if found BMT, else return 0
static int load_bmt_data(int start, int pool_size)
{
	int bmt_index = start + pool_size - 1;
	phys_bmt_struct *phys_table = NULL;
	int i;
	phys_table = (phys_bmt_struct *)malloc(sizeof(phys_bmt_struct));
	if (!phys_table) {
		ASSERT(0);
	}
	dprintf(INFO, "[%s]: begin to search BMT from block 0x%x\n", __FUNCTION__, bmt_index);
	dprintf(INFO, "[%s]: bmt_index=0x%x, start=0x%x, pool_size=0x%x,  \n", __FUNCTION__, bmt_index, start, pool_size);

	for (bmt_index = start + pool_size - 1; bmt_index >= start; bmt_index--) {
		dprintf(INFO, "[%s]: bmt_index=0x%x-- ", __FUNCTION__, bmt_index);
		if (nand_block_bad_bmt(OFFSET(bmt_index))) {
			dprintf(INFO, "Skip bad block: %d\n", bmt_index);
			continue;
		}

#if defined(MTK_TLC_NAND_SUPPORT)
		if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
		        && (devinfo.tlcControl.normaltlc))
			devinfo.tlcControl.slcopmodeEn = TRUE; //change to slc mode
#endif

		memset(dat_buf, 0xAA, sizeof(dat_buf));
		memset(oob_buf, 0xAA, sizeof(oob_buf));
		if (!nand_read_page_bmt(PAGE_ADDR(bmt_index), dat_buf, oob_buf)) {
			dprintf(INFO, "Error found when read block %d\n", bmt_index);
			continue;
		}

		if (!match_bmt_signature(dat_buf, oob_buf)) {
			dprintf(INFO, "[%s]: match_bmt_signature  out! \n", __FUNCTION__);
			continue;
		}

		dprintf(INFO, "Match bmt signature @ block: 0x%x\n", bmt_index);

		memcpy(phys_table, dat_buf + MAIN_SIGNATURE_OFFSET, sizeof(phys_bmt_struct));

		if (!valid_bmt_data(phys_table)) {
			dprintf(INFO, "BMT data is not correct %d\n", bmt_index);
			continue;
		} else {
			bmt.mapped_count = phys_table->header.mapped_count;
			bmt.version = phys_table->header.version;
			memcpy(bmt.table, phys_table->table, bmt.mapped_count * sizeof(bmt_entry));
			memcpy(&bmt.data_bmt,
					(dat_buf + MAIN_SIGNATURE_OFFSET + sizeof(phys_bmt_struct)),
					sizeof(data_bmt_struct));
			dprintf(INFO, "Data bmt bad_count:%d start_block:0x%x, end_block:0x%x\n", bmt.data_bmt.bad_count,
					bmt.data_bmt.start_block, bmt.data_bmt.end_block);

			dprintf(INFO, "bmt found at block: %d, mapped block: %d\n", bmt_index, bmt.mapped_count);
#if !defined(MTK_TLC_NAND_SUPPORT)
			for (i = 0; i < bmt.mapped_count; i++) {
				if (!nand_block_bad_bmt(OFFSET(bmt.table[i].bad_index))) {
					dprintf(INFO, "block 0x%x is not mark bad, should be power lost last time\n", bmt.table[i].bad_index);
					mark_block_bad_bmt(OFFSET(bmt.table[i].bad_index));
				}
			}
#endif
			free(phys_table);
			return bmt_index;
		}
	}
	free(phys_table);
	dprintf(INFO, "bmt block not found!\n");
	return 0;
}

/*************************************************************************
* Find an available block and erase.                                     *
* start_from_end: if true, find available block from end of flash.       *
*                 else, find from the beginning of the pool              *
* need_erase: if true, all unmapped blocks in the pool will be erased    *
*************************************************************************/
static int find_available_block(bool start_from_end)
{
	int i;                      // , j;
	u32 block = system_block_count;
	int direction;
	dprintf(INFO, "Try to find_available_block, pool_erase: %d\n", pool_erased);
#if defined(MTK_TLC_NAND_SUPPORT)
	if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
	        && (devinfo.tlcControl.normaltlc))
		devinfo.tlcControl.slcopmodeEn = TRUE;
#endif

#if !defined(MTK_TLC_NAND_SUPPORT)
	if (!pool_erased) {
		dprintf(INFO, "Erase all un-mapped blocks in pool\n");
		for (i = 0; i < bmt_block_count; i++) {
			if (block == bmt_block_index) {
				dprintf(INFO, "Skip bmt block 0x%x\n", block);
				continue;
			}

			if (nand_block_bad_bmt(OFFSET(block + i))) {
				dprintf(INFO, "Skip bad block 0x%x\n", block + i);
				continue;
			}

			if (is_block_mapped(block + i) >= 0) {
				dprintf(INFO, "Skip mapped block 0x%x\n", block + i);
				continue;
			}
			//xiaolei: erase non-mapped block by SLC mode firstly
			//then, before using as each Mode, should erase by that Mode first.
			if (!nand_erase_bmt(((u64)(block + i)) * (devinfo.blocksize * 1024))) {
				dprintf(INFO, "Erase block 0x%x failed\n", block + i);
				mark_block_bad_bmt(OFFSET(block + i));
			}
		}

		pool_erased = 1;
	}
#endif

	if (start_from_end) {
		block = total_block_count - 1;
		direction = -1;
	} else {
		block = system_block_count;
		direction = 1;
	}

	for (i = 0; i < bmt_block_count; i++, block += direction) {
		if (block == bmt_block_index) {
			dprintf(INFO, "Skip bmt block 0x%x\n", block);
			continue;
		}

		if (nand_block_bad_bmt(OFFSET(block))) {
			dprintf(INFO, "Skip bad block 0x%x\n", block);
			continue;
		}

		if (is_block_mapped(block) >= 0) {
			dprintf(INFO, "Skip mapped block 0x%x\n", block);
			continue;
		}

#if defined(MTK_TLC_NAND_SUPPORT)
		if (!nand_erase_bmt(((u64)block) * (devinfo.blocksize * 1024))) {
			dprintf(INFO, "Erase block 0x%x failed\n", block);
			mark_block_bad_bmt(OFFSET(block));
		}
#endif

		dprintf(INFO, "Find block 0x%x available\n", block);
		return block;
	}

	return 0;
}

static unsigned short get_bad_index_from_oob(u8 * oob_buf)
{
	unsigned short index;
	if (2048 == PAGE_SIZE_BMT) { // sector 1024 FDM size = 16, mark location moved
		memcpy(&index, oob_buf + 13, OOB_INDEX_SIZE);
	} else {
		memcpy(&index, oob_buf + OOB_INDEX_OFFSET, OOB_INDEX_SIZE);
	}

	return index;
}

void set_bad_index_to_oob(u8 * oob, u16 index)
{
	if (2048 == PAGE_SIZE_BMT) {
		memcpy(oob + 13, &index, sizeof(index));
	} else {
		memcpy(oob + OOB_INDEX_OFFSET, &index, sizeof(index));
	}
}

static int migrate_from_bad(u64 offset, u8 * write_dat, u8 * write_oob)
{
	int page;
#if defined(MTK_TLC_NAND_SUPPORT)
	u32 error_block = (u32)(offset / (devinfo.blocksize * 1024));
	u32 error_page = (u32)(offset >> nand_chip_bmt->page_shift) % page_per_block;
	u32 orig_block = error_block;
	u32 idx;
	bool tlc_mode_block = FALSE;
	int bRet;
#else
	u32 error_block = (u32)(offset / BLOCK_SIZE_BMT);
	u32 error_page = (u32)(offset / PAGE_SIZE_BMT) % page_per_block;
#endif
	int to_index;
	u32 tick = 1;

	memcpy(oob_buf, write_oob, MAX_OOB_SIZE);

	to_index = find_available_block(false);

	if (!to_index) {
		dprintf(INFO, "Cannot find an available block for BMT\n");
		return 0;
	}

#if defined(MTK_TLC_NAND_SUPPORT)
	if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
	        && (devinfo.tlcControl.normaltlc)) {
		if (error_block >= system_block_count) {  // mapped block become bad, find original bad block
			for (idx = 0; idx < bmt_block_count; idx++) {
				if (bmt.table[idx].mapped_index == error_block) {
					orig_block = bmt.table[idx].bad_index;
					break;
				}
			}
		}
		tlc_mode_block = mtk_block_istlc(orig_block * (devinfo.blocksize * 1024));
		if (!tlc_mode_block) {
			devinfo.tlcControl.slcopmodeEn = TRUE; //slc mode
			tick = 3;
		} else {
			devinfo.tlcControl.slcopmodeEn = false;
		}
	}
#endif

#if defined(MTK_TLC_NAND_SUPPORT)
	if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
	        && (devinfo.tlcControl.normaltlc) && tlc_mode_block) {
		if (error_block >= system_block_count)
			set_bad_index_to_oob(oob_buf, orig_block);
		else
			set_bad_index_to_oob(oob_buf, error_block);
		//erase block by slc mode in find_available_block
		//should erase block by tlc mode for tlc block
		memcpy(g_spare_buf, oob_buf, MAX_OOB_SIZE);
		nand_erase_bmt(((u64)to_index) * (devinfo.blocksize * 1024));
		bRet = mtk_nand_write_tlc_block_hw(nand_chip_bmt, write_dat, to_index);
		if (bRet != 0) {
			dprintf(INFO, "Write to page 0x%x fail\n", PAGE_ADDR(to_index) + error_page);
			mark_block_bad_bmt(OFFSET(to_index));
			return migrate_from_bad(offset, write_dat, write_oob);
		}
	} else
#endif
	{
		{
			// migrate error page first
			dprintf(INFO, "Write error page: 0x%x\n", error_page);
			if (!write_dat) {
				nand_read_page_bmt(PAGE_ADDR(error_block) + error_page, dat_buf, NULL);
				write_dat = dat_buf;
			}
			// memcpy(oob_buf, write_oob, MAX_OOB_SIZE);

			if (error_block < system_block_count)
				set_bad_index_to_oob(oob_buf, error_block); // if error_block is already a mapped block, original mapping index is in OOB.

			if (!nand_write_page_bmt(PAGE_ADDR(to_index) + error_page, write_dat, oob_buf)) {
				dprintf(INFO, "Write to page 0x%x fail\n", PAGE_ADDR(to_index) + error_page);
				mark_block_bad_bmt(OFFSET(to_index));
				return migrate_from_bad(offset, write_dat, write_oob);
			}
		}

		for (page = 0; page < page_per_block; page+=tick) {
			if ((u32)page != error_page) {
				nand_read_page_bmt(PAGE_ADDR(error_block) + page, dat_buf, oob_buf);
				if (is_page_used(dat_buf, oob_buf)) {
					if (error_block < system_block_count) {
						set_bad_index_to_oob(oob_buf, error_block);
					}
					dprintf(INFO, "\tmigrate page 0x%x to page 0x%x\n",PAGE_ADDR(error_block) + page, PAGE_ADDR(to_index) + page);
					if (!nand_write_page_bmt(PAGE_ADDR(to_index) + page, dat_buf, oob_buf)) {
						dprintf(INFO, "Write to page 0x%x fail\n", PAGE_ADDR(to_index) + page);
						mark_block_bad_bmt(OFFSET(to_index));
						return migrate_from_bad(offset, write_dat, write_oob);
					}
				}
			}
		}
	}

	dprintf(INFO, "Migrate from 0x%x to 0x%x done!\n", error_block, to_index);

	return to_index;
}

static bool write_bmt_to_flash(u8 * dat, u8 * oob)
{
	bool need_erase = true;
	dprintf(INFO, "Try to write BMT\n");

	if (bmt_block_index == 0) {
		// if we don't have index, we don't need to erase found block as it has been erased in find_available_block()
		need_erase = false;
		if (!(bmt_block_index = find_available_block(true))) {
			dprintf(INFO, "Cannot find an available block for BMT\n");
			return false;
		}
	}

	dprintf(INFO, "Find BMT block: 0x%x\n", bmt_block_index);

#if defined(MTK_TLC_NAND_SUPPORT)
	if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
	        && (devinfo.tlcControl.normaltlc))
		devinfo.tlcControl.slcopmodeEn = TRUE; //change to slc mode
#endif

	if (need_erase) {
		if (!nand_erase_bmt(((u64)bmt_block_index) * (devinfo.blocksize * 1024))) {
			dprintf(INFO, "BMT block erase fail, mark bad: 0x%x\n", bmt_block_index);
			mark_block_bad_bmt(OFFSET(bmt_block_index));

			bmt_block_index = 0;
			return write_bmt_to_flash(dat, oob);    // recursive call
		}
	}

	if (!nand_write_page_bmt(PAGE_ADDR(bmt_block_index), dat, oob)) {
		dprintf(INFO, "Write BMT data fail, need to write again\n");
		mark_block_bad_bmt(OFFSET(bmt_block_index));
		// bmt.bad_count++;

		bmt_block_index = 0;
		return write_bmt_to_flash(dat, oob);    // recursive call
	}

	dprintf(INFO, "Write BMT data to block 0x%x success\n", bmt_block_index);
	return true;
}

/*******************************************************************
* Reconstruct bmt, called when found bmt info doesn't match bad
* block info in flash.
*
* Return NULL for failure
*******************************************************************/
bmt_struct *reconstruct_bmt(bmt_struct * bmt)
{
	int i;
	int index = system_block_count;
	unsigned short bad_index;
	int mapped;

	bmt->version = BMT_VERSION;
	bmt->bad_count = 0;
	bmt->mapped_count = 0;

	memset(bmt->table, 0, bmt_block_count * sizeof(bmt_entry));

	for (i = 0; i < bmt_block_count; i++, index++) {
		if (nand_block_bad_bmt(OFFSET(index))) {
			dprintf(INFO, "Skip bad block: 0x%x\n", index);
			continue;
		}

		nand_read_page_bmt(PAGE_ADDR(index), dat_buf, oob_buf);
		if ((bad_index = get_bad_index_from_oob(oob_buf)) >= system_block_count) {
			dprintf(INFO, "get bad index: 0x%x\n", bad_index);
			if (bad_index != 0xFFFF)
				dprintf(INFO, "Invalid bad index found in block 0x%x, bad index 0x%x\n", index, bad_index);
			continue;
		}

		dprintf(INFO, "Block 0x%x is mapped to bad block: 0x%x\n", index, bad_index);

		if (!nand_block_bad_bmt(OFFSET(bad_index))) {
			dprintf(INFO, "\tbut block 0x%x is not marked as bad, invalid mapping\n", bad_index);
			continue;           // no need to erase here, it will be erased later when trying to write BMT
		}

		if ((mapped = is_block_mapped(bad_index)) >= 0) {
			dprintf(INFO, "bad block 0x%x is mapped to 0x%x, should be caused by power lost, replace with one\n", bmt->table[mapped].bad_index, bmt->table[mapped].mapped_index);
			bmt->table[mapped].mapped_index = index;    // use new one instead.
		} else {
			bmt->table[bmt->mapped_count].bad_index = bad_index;
			bmt->table[bmt->mapped_count].mapped_index = index;
			bmt->mapped_count++;
		}

		dprintf(INFO, "Add mapping: 0x%x -> 0x%x to BMT\n", bad_index, index);

	}

	dprintf(INFO, "Scan replace pool done, mapped block: %d\n", bmt->mapped_count);

	memset(oob_buf, 0xFF, sizeof(oob_buf));
	fill_nand_bmt_buffer(bmt, dat_buf, oob_buf);

	if (!write_bmt_to_flash(dat_buf, oob_buf)) {
		dprintf(INFO, "TRAGEDY: cannot find a place to write BMT!!!!\n");
	}

	return bmt;
}

/*******************************************************************
* [BMT Interface]
*
* Description:
*   Init bmt from nand. Reconstruct if not found or data error
*
* Parameter:
*   size: size of bmt and replace pool
*
* Return:
*   NULL for failure, and a bmt struct for success
*******************************************************************/
bmt_struct *init_bmt(struct nand_chip * chip, int size)
{

	if (size > 0 && size < MAX_BMT_SIZE) {
		dprintf(INFO, "Init bmt table, size: %d\n", size);
		bmt_block_count = size;
	} else {
		dprintf(INFO, "Invalid bmt table size: %d\n", size);
		return NULL;
	}

	nand_chip_bmt = chip;
	system_block_count = (u32)(chip->chipsize / (devinfo.blocksize * 1024));
	total_block_count = bmt_block_count + system_block_count;
	page_per_block = (devinfo.blocksize * 1024) / devinfo.pagesize;

	dprintf(INFO, "bmt count: %d, system count: %d\n", bmt_block_count, system_block_count);
	pool_erased = 0;
	memset(bmt.table, 0, size * sizeof(bmt_entry));
	if ((bmt_block_index = load_bmt_data(system_block_count, size))) {
		dprintf(INFO, "Load bmt data success @ block 0x%x\n", bmt_block_index);
		//dump_bmt_info(&bmt);
		return &bmt;
	} else {
		dprintf(INFO, "Load bmt data fail, need re-construct!\n");
#if defined(MTK_TLC_NAND_SUPPORT)
		//cannot go here by normal flow on TLC NAND.  bmt table can not be restructed by reading oob of each bmt pool block.
		//because it is invisiable of SLC/TLC MODE in bmt pool.
		return NULL;
#else
		if (reconstruct_bmt(&bmt))
			return &bmt;
		else
			return NULL;
#endif
	}
}

/*******************************************************************
* [BMT Interface]
*
* Description:
*   Update BMT.
*
* Parameter:
*   offset: update block/page offset.
*   reason: update reason, see update_reason_t for reason.
*   dat/oob: data and oob buffer for write fail.
*
* Return:
*   Return true for success, and false for failure.
*******************************************************************/
unsigned short get_mapping_block_index(u32 index)
{
	data_bmt_struct *data_bmt_info = &bmt.data_bmt;
	int i;
	if (index > system_block_count) {
		dprintf(INFO, "Given index exceed: 0x%x > 0x%x\n", index, system_block_count);
		return index;
	}

	if ((index >= data_bmt_info->start_block) && (index < data_bmt_info->end_block)) {
		for (i = 0; i < data_bmt_info->bad_count; i++) {
			if (data_bmt_info->entry[i].bad_index == index) {
				dprintf(INFO, "$$$$$FTL partition bad block at 0x%x, bad_count:%d\n",
					index, data_bmt_info->bad_count);
				return DATA_BAD_BLK;
			}
		}
	} else {
		for (i = 0; i < bmt.mapped_count; i++) {
			if (bmt.table[i].bad_index == index) {
				dprintf(INFO, "Redirect 0x%x to 0x%x\n", index, bmt.table[i].mapped_index);
				return bmt.table[i].mapped_index;
			}
		}
	}

	return index;
}


bool update_bmt(u64 offset, update_reason_t reason, u8 * dat, u8 * oob)
{
	int map_index;
	int orig_bad_block = -1;
	int i;
	u32 bad_index = (u32)(offset / (devinfo.blocksize * 1024));
	data_bmt_struct *data_bmt_info = &bmt.data_bmt;

	if ((bad_index >= data_bmt_info->start_block)
		&& (bad_index < data_bmt_info->end_block)) {
		if (get_mapping_block_index(bad_index) != DATA_BAD_BLK) {
			dprintf(INFO, "update_bmt DATA bad block is 0x%x, bad_count:%d\n",
					bad_index, data_bmt_info->bad_count);
			data_bmt_info->entry[data_bmt_info->bad_count].bad_index = bad_index;
			data_bmt_info->entry[data_bmt_info->bad_count].flag = reason;

			data_bmt_info->bad_count++;
		} else
			return false;
	} else {
		if (reason == UPDATE_WRITE_FAIL) {
			dprintf(INFO, "Write fail, need to migrate\n");
			if (!(map_index = migrate_from_bad(offset, dat, oob))) {
				dprintf(INFO, "migrate fail\n");
				return false;
			}
		} else {
			if (!(map_index = find_available_block(false))) {
				dprintf(INFO, "Cannot find block in pool\n");
				return false;
			}
		}
	}

	if ((u32)bad_index >= system_block_count) {
		for (i = 0; i < bmt_block_count; i++) {
			if (bmt.table[i].mapped_index == bad_index) {
				orig_bad_block = bmt.table[i].bad_index;
				break;
			}
		}
		dprintf(INFO, "Mapped block becomes bad, orig bad block is 0x%x\n", orig_bad_block);

		bmt.table[i].mapped_index = map_index;
	} else {
		bmt.table[bmt.mapped_count].mapped_index = map_index;
		bmt.table[bmt.mapped_count].bad_index = bad_index;
		bmt.mapped_count++;
	}

	memset(oob_buf, 0xFF, sizeof(oob_buf));
	fill_nand_bmt_buffer(&bmt, dat_buf, oob_buf);
	if (!write_bmt_to_flash(dat_buf, oob_buf))
		return false;

	mark_block_bad_bmt(offset);

	return true;
}

int get_data_bmt(data_bmt_struct *data_bmt)
{
	if (bmt.data_bmt.version == DATA_BMT_VERSION) {
		memcpy(data_bmt, &bmt.data_bmt, sizeof(data_bmt_struct));
		return 0;
	}
	return 1;
}

