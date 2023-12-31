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
#include <mt_partition.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <platform/errno.h>
#include "pmt.h"
#include <platform/mtk_nand_ops.h>
#include <platform/bmt.h>
#include <target.h>

#define PMT

#ifdef PMT

extern pt_resident lastest_part[PART_MAX_COUNT];
extern part_t partition_layout[];
u8 block_type_bitmap[250];

static pt_info pi;

#if defined(MTK_TLC_NAND_SUPPORT)
extern u32 slc_ratio;
extern u32 sys_slc_ratio;
extern u32 usr_slc_ratio;
#endif
#define PMT_POOL_SIZE   (2)
#define dprintf MSG
#define INFO INIT

//extern const struct MLC_feature_set feature_set[];

__attribute__((aligned(64))) unsigned char page_buf[16384 + 640];
//unsigned char backup_buf[8192];


//BLK_SIZE is 512, block_size is from flash is 128K
static u32 block_size;
static u32 page_size;
extern flashdev_info devinfo;
extern struct NAND_CMD g_kCMD;
extern u64 total_size;
u32 current_pt_page;
bool clean_write;
bool init_pmt_done = FALSE;

u64 part_get_startaddress(u64 byte_address, int *idx)
{
	int index = 0;
	if (TRUE == init_pmt_done) {
		while (index < PART_MAX_COUNT) {
			if (lastest_part[index].offset > byte_address || lastest_part[index].size == 0) {
				*idx = index - 1;
				return lastest_part[index-1].offset;
			}
			index++;
			if (!strcmp(lastest_part[index-1].name,"BMTPOOL"))
				break;
		}
	}
	*idx = index - 1;
#if defined(MTK_TLC_NAND_SUPPORT)
	if (FALSE == init_pmt_done) {
		*idx = 0;
	}
#endif
	return byte_address;
}

bool raw_partition(u32 index)
{
	if ((partition_layout[index].type == TYPE_LOW)
#if defined(MTK_TLC_NAND_SUPPORT)
	        || (partition_layout[index].type == TYPE_SLC))
#else
	   )
#endif
		return TRUE;
	return FALSE;
}

unsigned long get_part_size(char* name)
{
	int i =0;
	for (i = 0; i < PART_MAX_COUNT; i++) {
		if (!strcmp(name,lastest_part[i].name))
			return lastest_part[i].size;
	}
	return 0;
}

unsigned long get_part_offset(char* name)
{
	int i =0;
	for (i = 0; i < PART_MAX_COUNT; i++) {
		if (!strcmp(name,lastest_part[i].name))
			return lastest_part[i].offset;
	}
	return 0;
}

void get_part_tab_from_complier(void)
{
	int index = 0;
	dprintf(INFO,"get_pt_from_complier \n");
	while (partition_layout[index].flags != PART_FLAG_END) {
		memcpy(lastest_part[index].name,partition_layout[index].name, MAX_PARTITION_NAME_LEN);
		lastest_part[index].size = (u64)partition_layout[index].blknum * BLK_SIZE ;
		lastest_part[index].offset = (u64)partition_layout[index].startblk * BLK_SIZE;
		if (lastest_part[index].size == 0) {
			lastest_part[index].size = total_size - lastest_part[index].offset;
		}
		lastest_part[index].mask_flags = partition_layout[index].flags;  //this flag in kernel should be fufilled even though in flash is 0.
		dprintf(INFO,"get_ptr  %s %016llx %016llx\n",lastest_part[index].name,lastest_part[index].offset,lastest_part[index].size);
		index++;
	}
}

bool find_mirror_pt_from_bottom(u64 *start_addr, part_dev_t *dev, u8 *buf)
{
	int mpt_locate;
	u64 mpt_start_addr;
	u64 current_start_addr=0;
	//unsigned int part_id;
	int ret;
	mpt_start_addr = total_size+block_size*3;
	//mpt_start_addr=MPT_LOCATION*block_size-page_size;
	for (mpt_locate = (block_size / page_size); mpt_locate > 0; mpt_locate--) {


		current_start_addr = mpt_start_addr + mpt_locate * page_size;
		ret = dev->read(dev, current_start_addr, page_buf, page_size, 0);
		if (!ret) {
			dprintf(INFO,"find_mirror read  failed %x %x %d\n",current_start_addr,mpt_locate,ret);
		}
		memcpy(&page_buf[page_size],g_kCMD.au1OOB,16);
		//need enhance must be the larget sequnce number
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#if defined(MTK_TLC_NAND_SUPPORT)
		if (is_valid_pt(page_buf))
#else
		if (is_valid_mpt(page_buf) && is_valid_mpt(&pmt_spare))
#endif
		{
			//if no pt, pt.has space is 0;
#if defined(MTK_TLC_NAND_SUPPORT)
			slc_ratio = *((u32 *)page_buf + 1);//slc ratio
			sys_slc_ratio = (slc_ratio >> 16)&0xFF;
			usr_slc_ratio = (slc_ratio)&0xFF;
			dprintf(INFO,"[lk] slc ratio %d\n",slc_ratio);
#endif
			pi.sequencenumber = page_buf[PT_SIG_SIZE+page_size];
			dprintf(INFO,"find_mirror find valid pt at %x sq %x \n",current_start_addr, pi.sequencenumber);
			break;
		} else {
			continue;
		}
	}
	if (mpt_locate == 0) {
		dprintf(INFO,"no valid mirror page\n");
		pi.sequencenumber =  0;
		return FALSE;
	} else {
		*start_addr = current_start_addr;
		memcpy(buf, &page_buf[PT_SIG_SIZE], sizeof(lastest_part));
		memcpy(block_type_bitmap, &page_buf[PT_SIG_SIZE + sizeof(lastest_part)], sizeof(block_type_bitmap));
		return TRUE;
	}
}

int load_exist_part_tab(u8 *buf, part_dev_t *dev)
{
	u64 pt_start_addr;
	u64 pt_cur_addr;
	u32 pt_locate;
	//unsigned int part_id;
	int reval=DM_ERR_OK;
	u64 mirror_address;
	char pmt_spare[PT_SIG_SIZE];
	bool pmt_find = FALSE;

#if defined(MTK_TLC_NAND_SUPPORT)
	if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
	        && (devinfo.tlcControl.normaltlc))
		block_size = devinfo.blocksize * 1024 / 3; // SLC MODE
	else
#endif
		block_size = devinfo.blocksize * 1024;
	page_size = devinfo.pagesize;

	//page_buf = malloc(page_size);

	pt_start_addr = total_size;
	dprintf(INFO,"load_pt from 0x%llx page num %d\n",pt_start_addr, block_size / page_size);
	//pt_start_addr=PT_LOCATION*block_size;
	for (pt_locate=0; pt_locate < (block_size / page_size); pt_locate++) {
		pt_cur_addr = pt_start_addr+pt_locate*page_size;
		current_pt_page = pt_locate;
		memset(pmt_spare,0xFF,PT_SIG_SIZE);

		if (!dev->read(dev, pt_cur_addr, page_buf, page_size, 0)) {
			dprintf(INFO,"load_pt read pt failded: %llx\n", pt_cur_addr);
		}

		memcpy(&page_buf[page_size],g_kCMD.au1OOB,16);

		memcpy(pmt_spare,&page_buf[page_size] ,PT_SIG_SIZE); //skip bad block flag
		if (is_valid_pt(page_buf)) {
#if defined(MTK_TLC_NAND_SUPPORT)
			slc_ratio = *((u32 *)page_buf + 1);//slc ratio
			sys_slc_ratio = (slc_ratio >> 16)&0xFF;
			usr_slc_ratio = (slc_ratio)&0xFF;
			dprintf(INFO,"[lk] slc ratio %d\n",slc_ratio);
#endif
			pi.sequencenumber = page_buf[PT_SIG_SIZE+page_size];
			dprintf(INFO,"load_pt find valid pt at %llx sq %x \n",pt_cur_addr, pi.sequencenumber);
			memcpy(buf,&page_buf[PT_SIG_SIZE],sizeof(lastest_part));
			memcpy(block_type_bitmap, &page_buf[PT_SIG_SIZE + sizeof(lastest_part)], sizeof(block_type_bitmap));
			pmt_find = TRUE;
		} else {
			if (pmt_find == TRUE)
				break;
		}
	}
	//for test
	//pt_locate==(block_size/page_size);
	if (pt_locate == (block_size/page_size) && pmt_find != TRUE) {
		//first download or download is not compelte after erase or can not download last time
		dprintf(INFO,"load_pt find pt failed \n");
		pi.pt_has_space = 0; //or before download pt power lost

		if (!find_mirror_pt_from_bottom(&mirror_address,dev, buf)) {
			dprintf(INFO,"First time download \n");
			reval=ERR_NO_EXIST;
			return reval;
		} else {
			//used the last valid mirror pt, at lease one is valid.
			dev->read(dev,mirror_address, page_buf,page_size, 0);
		}
	}

	return reval;
}

int part_get_mtd_index(char *name)
{
	int i;
	part_t *part = &partition_layout[0];
	for (i=0; i<PART_MAX_COUNT; i++,part++) {
		dprintf(INFO,"part_get_mtd_index %s\n", part->name);
		if (!strncasecmp(name, part->name, strlen(name)))
			return i;
	}
	return -1;
}

void part_init_pmt(unsigned long totalblks, part_dev_t *dev)
{
	part_t *part = &partition_layout[0];
	unsigned long lastblk;
	int retval = 0;
	int i = 0;
	dprintf(INFO,"mt6577_part_init_pmt \n");
	if (!totalblks) {
		return;
	}
	part->blknum = totalblks;
	clean_write = FALSE;
#if 0
	/* updater the number of blks of first part. */
	if (totalblks <= part->blknum) {
		part->blknum = totalblks;
	}

	totalblks -= part->blknum;
#ifdef MTK_MLC_NAND_SUPPORT
	if (part->type == TYPE_LOW)
		lastblk = part->startblk + part->blknum*2;
	else
#endif
		lastblk = part->startblk + part->blknum;

	while (totalblks) {
		part++;
		if (!part->name) {
			break;
		}

		if (part->flags & PART_FLAG_LEFT || totalblks <= part->blknum) {
			part->blknum = totalblks;
		}
		part->startblk = lastblk;
		totalblks -= part->blknum;
#ifdef MTK_MLC_NAND_SUPPORT
		if (part->type == TYPE_LOW)
			lastblk = part->startblk + part->blknum*2;
		else
#endif
			lastblk = part->startblk + part->blknum;
	}
#endif
	memset(&pi, 0xFF, sizeof(pi));
	memset(&lastest_part, 0, PART_MAX_COUNT * sizeof(pt_resident));
	memset(block_type_bitmap, 0xFF, sizeof(block_type_bitmap));
	retval = load_exist_part_tab((u8 *)&lastest_part, dev);
	if (retval == ERR_NO_EXIST) {
		//first run preloader before dowload
		//and valid mirror last download or first download
		dprintf(INFO,"no pt \n");
		get_part_tab_from_complier(); //get from complier
	} else {
		dprintf(INFO,"Find pt \n");
		for (i=0; i<PART_MAX_COUNT; i++,part++) {
			if (!strcmp(lastest_part[i-1].name,"BMTPOOL"))
				break;
			part->name = lastest_part[i].name;
			//part->size= lastest_part[i].size;
			part->blknum = lastest_part[i].size / BLK_SIZE;
			part->startblk =lastest_part[i].offset / BLK_SIZE;
			part->flags = PART_FLAG_NONE;

			if (lastest_part[i].part_id == REGION_LOW_PAGE) {
				part->type = TYPE_LOW;
			}
#if defined(MTK_TLC_NAND_SUPPORT)
			else if (lastest_part[i].part_id == REGION_SLC_MODE) {
				part->type = TYPE_SLC;
			} else if (lastest_part[i].part_id == REGION_TLC_MODE) {
				part->type = TYPE_TLC;
			}
#endif
			else {
				part->type = TYPE_FULL;
			}

			if (!strcmp(lastest_part[i].name,"BMTPOOL")) {
				lastest_part[i].offset = total_size + PMT_POOL_SIZE * (devinfo.blocksize * 1024);
#if defined(MTK_TLC_NAND_SUPPORT)
				if (devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC) {
					if (devinfo.tlcControl.normaltlc) {
						part->type = TYPE_SLC;
					} else
						part->type = TYPE_TLC;
				}
#endif
			}

			dprintf(INFO,"partition %s size %016llx %016llx \n",lastest_part[i].name,lastest_part[i].offset,lastest_part[i].size);
		}
	}
	init_pmt_done = TRUE;
}

#if defined(MTK_TLC_NAND_SUPPORT)
extern u32 system_block_count;
u64 OFFSET(u32 block) //return logical address
{
	u64 offset;
	u32 idx;
	u64 start_address;
	bool raw_part;
	u64 real_address = (u64)block * (devinfo.blocksize * 1024);
	u32 total_blk_num; // total block number in FS partition
	u32 slc_blk_num;

	start_address = part_get_startaddress(real_address, &idx);
	if (raw_partition(idx))
		raw_part = TRUE;
	else
		raw_part = FALSE;

	if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
	        && devinfo.tlcControl.normaltlc) {
		if (raw_part)
			offset = start_address + (real_address - start_address) / 3;
		else {
			total_blk_num = (lastest_part[idx + 1].offset - lastest_part[idx].offset) / (devinfo.blocksize * 1024);
			if (!strcmp(lastest_part[idx].name,"ANDROID"))
				slc_blk_num = total_blk_num * sys_slc_ratio / 100;
			else {
				total_blk_num -= 2;//pmt block number
				slc_blk_num = total_blk_num * usr_slc_ratio / 100;
			}
			if (slc_blk_num % 3)
				slc_blk_num += (3 - (slc_blk_num % 3)); // slc block number must be 3 aligned
			if (block < (system_block_count - PMT_POOL_SIZE - slc_blk_num)) {
				offset = (((u64)block) * (devinfo.blocksize * 1024));
			} else {
				offset = (system_block_count - PMT_POOL_SIZE - slc_blk_num) * (devinfo.blocksize * 1024) + (block - (system_block_count - PMT_POOL_SIZE - slc_blk_num)) * (devinfo.blocksize * 1024) / 3;
			}
		}
	} else {
		offset = (((u64)block) * (devinfo.blocksize * 1024));
	}

	return offset;
}

void mtk_slc_blk_addr(u64 addr, u32* blk_num, u32* page_in_block)
{
	u64 start_address;
	u32 idx;
	u32 total_blk_num; // total block number in FS partition
	u32 slc_blk_num;
	u64 offset;
	u32 block_size = (devinfo.blocksize * 1024);

	start_address = part_get_startaddress(addr,&idx);
	if (raw_partition(idx)) { // raw partition just has SLC mode block
		*blk_num = (u32)((u32)(start_address / block_size) + (u32)((addr-start_address) / (block_size / 3)));
		*page_in_block = ((u32)((addr-start_address) / devinfo.pagesize) % ((block_size/devinfo.pagesize)/3));
		*page_in_block *= 3;
	} else {
		if ((addr < lastest_part[idx + 1].offset) && (addr >= (lastest_part[idx + 1].offset - PMT_POOL_SIZE * block_size))) {
			//for pmt update
			*blk_num = (u32)(addr / block_size);
			*page_in_block = ((u32)(addr / devinfo.pagesize) % ((block_size/devinfo.pagesize)/3));
			*page_in_block *= 3;
		} else {
			total_blk_num = (lastest_part[idx + 1].offset - lastest_part[idx].offset) / (devinfo.blocksize * 1024);
			if (!strcmp(lastest_part[idx].name,"ANDROID"))
				slc_blk_num = total_blk_num * sys_slc_ratio / 100;
			else {
				total_blk_num -= 2;//pmt block number
				slc_blk_num = total_blk_num * usr_slc_ratio / 100;
			}
			//total_blk_num -= 2;//pmt block number
			//slc_blk_num = total_blk_num * slc_ratio / 100;
			if (slc_blk_num % 3)
				slc_blk_num += (3 - (slc_blk_num % 3)); // slc block number must be 3 aligned

			offset = start_address + (u64)(devinfo.blocksize * 1024) * (total_blk_num - slc_blk_num);

			if (offset <= addr) {
				*blk_num = (u32)((u32)(offset / block_size) + (u32)((addr-offset) / (block_size / 3)));
				*page_in_block = ((u32)((addr-offset) / devinfo.pagesize) % ((block_size/devinfo.pagesize)/3));
				*page_in_block *= 3;
			} else {
				dprintf(INFO,"[xiaolei] error :this is not slc mode block\n");
				while (1);
			}
		}
	}
}

bool mtk_block_istlc(u64 addr)
{
	u64 start_address;
	u32 idx;
	u32 total_blk_num; // total block number in FS partition
	u32 slc_blk_num;
	u64 offset;

	start_address = part_get_startaddress(addr,&idx);
	if (raw_partition(idx)) { // raw partition just has SLC mode block
		return FALSE;
	} else {
		if (devinfo.tlcControl.normaltlc) {
			total_blk_num = (lastest_part[idx + 1].offset - lastest_part[idx].offset) / (devinfo.blocksize * 1024);
			if (!strcmp(lastest_part[idx].name,"ANDROID"))
				slc_blk_num = total_blk_num * sys_slc_ratio / 100;
			else {
				total_blk_num -= 2;//pmt block number
				slc_blk_num = total_blk_num * usr_slc_ratio / 100;
			}
			//slc_blk_num = total_blk_num * slc_ratio / 100;
			if (slc_blk_num % 3)
				slc_blk_num += (3 - (slc_blk_num % 3)); // slc block number must be 3 aligned

			offset = start_address + (u64)(devinfo.blocksize * 1024) * (total_blk_num - slc_blk_num);

			if (offset <= addr)
				return FALSE;
			else
				return TRUE;
		} else //micron tlc
			return TRUE;
	}
}

void mtk_pmt_reset(void)
{
	u32 index;
	if ((devinfo.NAND_FLASH_TYPE == NAND_FLASH_TLC)
	        && devinfo.tlcControl.normaltlc) {
		for (index = 0; index < PART_MAX_COUNT; index++) { //must have this step
			partition_layout[index].type = TYPE_SLC; //default SLC MODE
			lastest_part[index].offset = 0; //default 0
		}
	}
}

bool mtk_nand_IsBMTPOOL(u64 logical_address)
{
	u64 start_address;
	u32 idx;

	start_address = part_get_startaddress(logical_address,&idx);

	if ((!strcmp(lastest_part[idx].name,"BMTPOOL")) || (!init_pmt_done))
		return TRUE;
	else
		return FALSE;
}

int get_data_partition_info(struct nand_ftl_partition_info *info, struct mtk_nand_chip_info *cinfo)
{
#if 1
	unsigned int i;
	u64 temp;

	dprintf(INFO,"get_data_partition_info start\n");
	for (i = 0; i < PART_MAX_COUNT; i++) {
		dprintf(INFO,"get_data_partition_info %s %d\n",
			lastest_part[i].name, i);
		if (!strcmp(lastest_part[i].name, FTL_PARTITION_NAME)) {

			temp = (lastest_part[i + 1].offset - lastest_part[i].offset) / (devinfo.blocksize * 1024);
			dprintf(INFO,"temp = %llu, gn_devinfo.blocksize = %u", temp, devinfo.blocksize);
			info->total_block = (u32)temp - 2;
			dprintf(INFO,"info->total_block = %u", info->total_block);

			temp = lastest_part[i].offset / (devinfo.blocksize * 1024);
			info->start_block = temp;
			info->slc_ratio = usr_slc_ratio;//slc_ratio

			dprintf(INFO,"get part info, start_block:0x%x total_block:0x%x slc_ratio:%d\n",
				info->start_block, info->total_block, info->slc_ratio);

			memcpy(cinfo->block_type_bitmap, block_type_bitmap, sizeof(block_type_bitmap));

			dprintf(INFO,"get_data_partition_info end\n");
			return 0;
		}
	}

	dprintf(INFO,"get_data_partition_info end\n");
#endif
	return 1;

}

bool nand_erase_pmt(u64 offset)
{
	return nand_erase_hw(offset);
}

bool nand_write_page_pmt(u32 page, u8 * dat, u8 * oob)
{
	return nand_write_page_hw(page, dat, oob);
}

void update_block_map(struct mtk_nand_chip_info *info, int num, unsigned int *blk)
{
	int i;
	unsigned int blknum;
	int index, bit;

	for (i = 0; i < num; i++) {
		blknum = *blk;
		index = blknum / 8;
		bit = blknum % 8;
		info->block_type_bitmap[index] |= (1 << bit);
		blk++;
	}
}

int mntl_update_part_tab(struct mtk_nand_chip_info *info, int num, unsigned int *blk)
{
	int retval = 0;
	u64 start_addr = total_size;
	u64 current_addr = 0;
	u32 page_addr;
	u64 temp_value;
	u8 *buf = page_buf;
	u8 *oob = &page_buf[page_size];

	memset(page_buf, 0xFF, page_size + 64);
	update_block_map(info, num, blk);

	if (num != 0) {
		temp_value = (u64)slc_ratio;
		temp_value = temp_value << 32;
		temp_value = temp_value | PT_SIG;
		memcpy(page_buf, &temp_value, PT_SIG_SIZE);
		memcpy(&page_buf[PT_SIG_SIZE], &lastest_part[0], sizeof(lastest_part));
		memcpy(&page_buf[PT_SIG_SIZE + sizeof(lastest_part)], info->block_type_bitmap,
			sizeof(info->block_type_bitmap));
		memcpy(&page_buf[page_size], &temp_value, PT_SIG_SIZE);
		memcpy(&page_buf[page_size + PT_SIG_SIZE], &pi, PT_SIG_SIZE);

		if (current_pt_page == ((block_size / page_size) - 1) || clean_write == FALSE) {
			/* update mirror first */
			if (!nand_erase_pmt(start_addr + (block_size * 3))) {
				dprintf(INFO,"update_pt erase failed %llx\n", start_addr);
				retval = DM_ERR_NO_SPACE_FOUND;
				return retval;
			}
			current_addr = start_addr + (block_size * 3);
			page_addr = current_addr / page_size;
			dprintf(INFO,"update_pt write mirror %llx\n", current_addr);
			if (!nand_write_page_pmt(page_addr, buf, oob)) {
				dprintf(INFO,"update_pt write failed\n");
				return -EIO;
			}

			/* erase original pmt */
			if (!nand_erase_pmt(start_addr)) {
				dprintf(INFO,"update_pt erase failed %llx\n", start_addr);
				if (pi.mirror_pt_dl == 0)
					retval = DM_ERR_NO_SPACE_FOUND;
				return retval;
			}
			clean_write = TRUE;
			current_pt_page = 0;
		} else
			current_pt_page++;
		current_addr = start_addr + current_pt_page * page_size;
		page_addr = current_addr / page_size;
		if (!nand_write_page_pmt(page_addr, buf, oob)) {
			dprintf(INFO,"update_pt write failed\n");
			retval = -EIO;
		}
		dprintf(INFO,"update_pt write %llx\n", current_addr);
	} else {
		dprintf(INFO,"update_pt no change\n");
	}
	return DM_ERR_OK;
}

#endif

part_t* get_part(char *name)
{
	return NULL;
}

unsigned long mt_part_get_part_active_bit(part_t *part)
{
	return 0;
}

#endif
