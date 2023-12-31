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
#include <platform/mtk_nand.h>
#include <target.h>
#define PMT 1


//common
//BLK_SIZE is 512, block_size is from flash is 128K
static u32 block_size;
static u32 page_size;
#ifndef MTK_EMMC_SUPPORT
#ifdef MTK_SPI_NAND_SUPPORT
extern snand_flashdev_info devinfo;
#else
extern flashdev_info devinfo;
#endif
#endif
extern pt_resident lastest_part[PART_MAX_COUNT];
extern part_t partition_layout[];

extern u64 total_size;
extern struct NAND_CMD g_kCMD;
static pt_info pi;

bool init_pmt_done = FALSE;
extern u32 slc_ratio;
extern u32 sys_slc_ratio;
extern u32 usr_slc_ratio;

//if used malloc func ,the pdata = (uchar*)malloc(sizeof(uchar)*size);
// in recovery_check_command_trigger will return 0
//static char *page_buf;
__attribute__ ((aligned(64))) unsigned char page_buf[16384+1600];
__attribute__ ((aligned(64))) unsigned char backup_buf[16384];
#ifdef MTK_EMMC_SUPPORT
#define CFG_EMMC_PMT_SIZE 0xc00000
extern int g_user_virt_addr;
extern u64 g_emmc_size;
pt_resident32 lastest_part32[PART_MAX_COUNT];
#endif

u64 part_get_startaddress(u64 byte_address, int* idx)
{
	int index = 0;
	//*idx = 0;
	if (TRUE == init_pmt_done) {
		while (index < PART_MAX_COUNT) {
			if (lastest_part[index].offset > byte_address || lastest_part[index].size == 0) {
				*idx = index-1;
				return lastest_part[index-1].offset;
			}
			index++;
		}
	}
	//MSG(ERR, "index(%d) idx(0x%X)\n",*idx,idx);
	*idx = index-1;
	return byte_address;
}

bool raw_partition(u32 index)
{
	if (partition_layout[index].type == TYPE_LOW)
		return TRUE;
	return FALSE;
}

#ifdef PMT
void get_part_tab_from_complier(void)
{
#ifdef MTK_EMMC_SUPPORT
	int index=0;
	dprintf(INFO,"get_pt_from_complier\n");
	while (partition_layout[index].flags != PART_FLAG_END) {
		memcpy(lastest_part[index].name,partition_layout[index].name,MAX_PARTITION_NAME_LEN);
		lastest_part[index].size = (u64)partition_layout[index].blknum * BLK_SIZE ;
		lastest_part[index].offset = (u64)partition_layout[index].startblk * BLK_SIZE;
		if (lastest_part[index].size == 0) {
			lastest_part[index].size = target_get_max_flash_size() - lastest_part[index].offset - partition_reserve_size();
		}
		lastest_part[index].mask_flags = partition_layout[index].flags;  //this flag in kernel should be fufilled even though in flash is 0.
		dprintf(INFO,"get_ptr  %s %016llx %016llx\n",lastest_part[index].name,lastest_part[index].offset,lastest_part[index].size);
		index++;
	}
#else
	int index=0;
	dprintf(INFO,"get_pt_from_complier \n");
	while (partition_layout[index].flags!= PART_FLAG_END) {

		memcpy(lastest_part[index].name,partition_layout[index].name,MAX_PARTITION_NAME_LEN);
		lastest_part[index].size = (u64)partition_layout[index].blknum*BLK_SIZE ;
		lastest_part[index].offset = (u64)partition_layout[index].startblk * BLK_SIZE;
		if (lastest_part[index].size == 0) {
			lastest_part[index].size = total_size - lastest_part[index].offset;
		}
		lastest_part[index].mask_flags =  partition_layout[index].flags;  //this flag in kernel should be fufilled even though in flash is 0.
		dprintf(INFO,"get_ptr  %s %lx %lx\n",lastest_part[index].name,lastest_part[index].offset,lastest_part[index].size);
		index++;
	}
#endif
}

bool find_mirror_pt_from_bottom(u64 *start_addr,part_dev_t *dev)
{
	int mpt_locate;
	u64 mpt_start_addr;
	u64 current_start_addr=0;
	char pmt_spare[4];
	mpt_start_addr = total_size+block_size;
	//mpt_start_addr=MPT_LOCATION*block_size-page_size;
	for (mpt_locate=(block_size/page_size); mpt_locate>0; mpt_locate--) {
		memset(pmt_spare,0xFF,PT_SIG_SIZE);

		current_start_addr = mpt_start_addr+mpt_locate*page_size;
		if (!dev->read(dev,current_start_addr, page_buf,page_size,0)) {
			dprintf(INFO,"find_mirror read  failed %x %x \n",current_start_addr,mpt_locate);
		}
		memcpy(&page_buf[page_size],g_kCMD.au1OOB,16);
		memcpy(pmt_spare,&page_buf[page_size] ,PT_SIG_SIZE);
		//need enhance must be the larget sequnce number
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
		if (is_valid_mpt(page_buf)&&is_valid_mpt(&pmt_spare)) {
			//if no pt, pt.has space is 0;
			slc_ratio = *((u32 *)page_buf + 1);//slc ratio
			sys_slc_ratio = (slc_ratio >> 16)&0xFF;
			usr_slc_ratio = (slc_ratio)&0xFF;
			dprintf(INFO,"[lk] slc ratio %d\n",slc_ratio);
			pi.sequencenumber = page_buf[PT_SIG_SIZE+page_size];
			dprintf(INFO,"find_mirror find valid pt at %x sq %x \n",current_start_addr,pi.sequencenumber);
			break;
		} else {
			continue;
		}
	}
	if (mpt_locate==0) {
		dprintf(INFO,"no valid mirror page\n");
		pi.sequencenumber =  0;
		return FALSE;
	} else {
		*start_addr = current_start_addr;
		return TRUE;
	}
}
#ifdef MTK_EMMC_SUPPORT

#define PMT_REGION_SIZE     (0x1000)
#define PMT_REGION_OFFSET   (0x100000)

#define PMT_VER_V1          ("1.0")
#define PMT_VER_SIZE        (4)

static int load_pt_from_fixed_addr(u8 *buf, part_dev_t *dev)
{
	int reval = ERR_NO_EXIST;
	u64 pt_start;
	u64 mpt_start;
	int pt_size = PMT_REGION_SIZE;
	int buffer_size = pt_size;

	pt_start = g_emmc_size - PMT_REGION_OFFSET;
	mpt_start = pt_start + PMT_REGION_SIZE;

	dprintf(INFO,"============func=%s===scan pmt from %llx=====\n", __func__, pt_start);
	/* try to find the pmt at fixed address, signature:0x50547631 */

	dev->read(dev, pt_start, (u8*)page_buf, buffer_size,0);
	if (is_valid_pt(page_buf)) {
		if (!memcmp(page_buf + PT_SIG_SIZE, PMT_VER_V1, PMT_VER_SIZE)) {
			if (is_valid_pt(&page_buf[pt_size - PT_SIG_SIZE])) {
				dprintf(INFO,"find pt at %llx\n", pt_start);
				memcpy(buf, page_buf + PT_SIG_SIZE + PMT_VER_SIZE, PART_MAX_COUNT * sizeof(pt_resident));
				reval = DM_ERR_OK;
				return reval;
			} else {
				dprintf(INFO,"invalid tail pt format\n");
				reval = ERR_NO_EXIST;
			}
		} else {
			dprintf(INFO,"invalid pt version %s\n", page_buf + PT_SIG_SIZE);
			reval = ERR_NO_EXIST;
		}
	}


	dev->read(dev, mpt_start, (u8*)page_buf, buffer_size,0);
	if (is_valid_mpt(page_buf)) {
		if (!memcmp(page_buf + PT_SIG_SIZE, PMT_VER_V1, PMT_VER_SIZE)) {
			if (is_valid_mpt(&page_buf[pt_size - PT_SIG_SIZE])) {
				dprintf(INFO,"find mpt at %llx\n", mpt_start);
				memcpy(buf, page_buf + PT_SIG_SIZE + PMT_VER_SIZE, PART_MAX_COUNT * sizeof(pt_resident));
				reval = DM_ERR_OK;
				return reval;
			} else {
				dprintf(INFO,"invalid tail mpt format\n");
				reval = ERR_NO_EXIST;
			}
		} else {
			dprintf(INFO,"invalid mpt version %s\n", page_buf + PT_SIG_SIZE);
			reval = ERR_NO_EXIST;
		}
	}

	return reval;
}
#endif
int load_exist_part_tab(u8 *buf,part_dev_t *dev)
{
#ifndef MTK_EMMC_SUPPORT
	u64 pt_start_addr;
	u64 pt_cur_addr;
	u64 pt_locate;
	int reval=DM_ERR_OK;
	u64 mirror_address;
	char pmt_spare[PT_SIG_SIZE];

	block_size= devinfo.blocksize*1024;
	page_size = devinfo.pagesize;

	//page_buf = malloc(page_size);

	pt_start_addr = total_size;
	dprintf(INFO,"load_pt from 0x%x \n",pt_start_addr);
	//pt_start_addr=PT_LOCATION*block_size;
	for (pt_locate=0; pt_locate<(block_size/page_size); pt_locate++) {
		pt_cur_addr = pt_start_addr+pt_locate*page_size;
		memset(pmt_spare,0xFF,PT_SIG_SIZE);

		if (!dev->read(dev,pt_cur_addr, page_buf,page_size,0)) {
			dprintf(INFO,"load_pt read pt failded: %x\n",pt_cur_addr);
		}
		memcpy(&page_buf[page_size],g_kCMD.au1OOB,16);

		memcpy(pmt_spare,&page_buf[page_size] ,PT_SIG_SIZE); //skip bad block flag
		if (is_valid_pt(page_buf)&&is_valid_pt(pmt_spare)) {
			slc_ratio = *((u32 *)page_buf + 1);//slc ratio
			sys_slc_ratio = (slc_ratio >> 16)&0xFF;
			usr_slc_ratio = (slc_ratio)&0xFF;
			dprintf(INFO,"[lk] slc ratio %d\n",slc_ratio);
			pi.sequencenumber = page_buf[PT_SIG_SIZE+page_size];
			dprintf(INFO,"load_pt find valid pt at %x sq %x \n",pt_start_addr,pi.sequencenumber);
			break;
		} else {
			continue;
		}
	}
	//for test
	//pt_locate==(block_size/page_size);
	if (pt_locate==(block_size/page_size)) {
		//first download or download is not compelte after erase or can not download last time
		dprintf(INFO,"load_pt find pt failed \n");
		pi.pt_has_space = 0; //or before download pt power lost

		if (!find_mirror_pt_from_bottom(&mirror_address,dev)) {
			dprintf(INFO,"First time download \n");
			reval=ERR_NO_EXIST;
			return reval;
		} else {
			//used the last valid mirror pt, at lease one is valid.
			dev->read(dev,mirror_address, page_buf,page_size,0);
		}
	}
	memcpy(buf,&page_buf[PT_SIG_SIZE],sizeof(lastest_part));

	return reval;
#endif
	return DM_ERR_OK; //should not happen
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
void part_init_pmt(unsigned long totalblks,part_dev_t *dev)
{

	part_t *part = &partition_layout[0];
	unsigned long lastblk;
	int retval=0;
	int i=0;
	dprintf(INFO,"mt6577_part_init_pmt \n");
	if (!totalblks) return;
	part->blknum = totalblks;
#if 0
	/* updater the number of blks of first part. */
	if (totalblks <= part->blknum)
		part->blknum = totalblks;

	totalblks -= part->blknum;
	if (part->type == TYPE_LOW)
		lastblk = part->startblk + part->blknum*2;
	else
		lastblk = part->startblk + part->blknum;

	while (totalblks) {
		part++;
		if (!part->name)
			break;

		if (part->flags & PART_FLAG_LEFT || totalblks <= part->blknum)
			part->blknum = totalblks;

		part->startblk = lastblk;
		totalblks -= part->blknum;
		if (part->type == TYPE_LOW)
			lastblk = part->startblk + part->blknum*2;
		else
			lastblk = part->startblk + part->blknum;
	}
#endif
	init_pmt_done = FALSE;
	memset(&pi,0xFF,sizeof(pi));
	memset(&lastest_part,0,PART_MAX_COUNT*sizeof(pt_resident));
	retval=load_exist_part_tab((u8 *)&lastest_part,dev);
	if (retval==ERR_NO_EXIST) { //first run preloader before dowload
		//and valid mirror last download or first download
		dprintf(INFO,"no pt \n");
		get_part_tab_from_complier(); //get from complier
	} else {
		dprintf(INFO,"Find pt \n");
		for (i=0; i<PART_MAX_COUNT; i++,part++) {
			//dprintf(INFO,"%s, %x\n",lastest_part[i].name,lastest_part[i].size);
			if (lastest_part[i].size == 0) {
				//lastest_part[i].offset = 0xFFFFFFFF00000000 | lastest_part[i].offset;
				lastest_part[i].offset = total_size + 2 * (devinfo.blocksize * 1024);
				lastest_part[i].size = total_size - lastest_part[i].offset;
				dprintf(INFO,"partition %s size %llx %llx \n",lastest_part[i].name,lastest_part[i].offset,lastest_part[i].size);
				break;
			}
			part->name = lastest_part[i].name;
			//part->size= lastest_part[i].size;
			part->blknum = lastest_part[i].size /BLK_SIZE;
			part->startblk =lastest_part[i].offset / BLK_SIZE;
			part->flags = PART_FLAG_NONE;
			part->part_id = 0;
			if (lastest_part[i].part_id == REGION_LOW_PAGE) {
				part->type = TYPE_LOW;
			} else {
				part->type = TYPE_FULL;
			}
			if (!strcmp(part->name, PART_USRDATA)) {
				part->type = TYPE_FULL;
			}
			dprintf(INFO,"partition @ %x %s size %llx %llx \n",&lastest_part[i],lastest_part[i].name,lastest_part[i].offset,lastest_part[i].size);
		}
	}
	init_pmt_done = TRUE;
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

	total_blk_num = (lastest_part[idx + 1].offset - lastest_part[idx].offset) / (devinfo.blocksize * 1024);
	if (!strcmp(lastest_part[idx].name,"ANDROID"))
		slc_blk_num = total_blk_num * sys_slc_ratio / 100;
	else {
		total_blk_num -= 2;//pmt block number
		slc_blk_num = total_blk_num * usr_slc_ratio / 100;
	}
	//total_blk_num -= 2;//pmt block number
	//slc_blk_num = total_blk_num * slc_ratio / 100;
	if (slc_blk_num % 2)
		slc_blk_num += (2 - (slc_blk_num % 2)); // slc block number must be 3 aligned
	offset = start_address + (u64)(devinfo.blocksize * 1024) * (total_blk_num - slc_blk_num);

	if (offset <= addr) {
		*blk_num = (u32)((u32)(offset / block_size) + (u32)((addr-offset) / (block_size/2)));
		*page_in_block = ((u32)((addr-offset) / devinfo.pagesize) % (((block_size/2)/devinfo.pagesize)));
	} else {
		dprintf(INFO,"[xiaolei] error :this is not slc mode block\n");
		while (1);
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

	total_blk_num = (lastest_part[idx + 1].offset - lastest_part[idx].offset) / (devinfo.blocksize * 1024);
	if (!strcmp(lastest_part[idx].name,"ANDROID"))
		slc_blk_num = total_blk_num * sys_slc_ratio / 100;
	else {
		total_blk_num -= 2;//pmt block number
		slc_blk_num = total_blk_num * usr_slc_ratio / 100;
	}
	//slc_blk_num = total_blk_num * slc_ratio / 100;
	if (slc_blk_num % 2)
		slc_blk_num += (2 - (slc_blk_num % 2)); // slc block number must be 3 aligned
	offset = start_address + (u64)(devinfo.blocksize * 1024) * (total_blk_num - slc_blk_num);
	if (offset <= addr)
		return FALSE;
	else
		return TRUE;
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



#endif
