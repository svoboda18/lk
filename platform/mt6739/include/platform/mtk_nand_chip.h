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


#ifndef __MTK_NAND_CHIP_H__
#define __MTK_NAND_CHIP_H__

#define RAMDOM_READ		(1<<0)
#define CACHE_READ		(1<<1)
#define MULTI_PLANE		(1<<2)
#define NAND_FLASH_SLC	(0x0000)
#define NAND_FLASH_MLC	(0x0001)
#define NAND_FLASH_TLC	(0x0002)
#define NAND_FLASH_MLC_HYBER	(0x0003)
#define NAND_FLASH_MASK	(0x00FF)

/* mtk_nand_chip_info option bit define*/
#define MTK_NAND_FDM_PARTIAL_SUPPORT		(1<<0)
#define MTK_NAND_PLANE_MODE_SUPPORT		(1<<1)
#define MTK_NAND_CACHE_PROGRAM_SUPPORT		(1<<2)
#define MTK_NAND_DISCONTIGOUS_BUFFER_SUPPORT	(1<<3)
#define MTK_NAND_MULTI_CHIP_SUPPORT		(1<<4)
#define MTK_NAND_MULTI_READ_DIFFERENT_OFFSET	(1<<5)
#define MTK_NAND_MULTI_READ_DIFFERENT_PAGE	(1<<6)

enum nand_flash_type {
	MTK_NAND_FLASH_SLC = 0,
	MTK_NAND_FLASH_MLC,
	MTK_NAND_FLASH_TLC,
};

#ifndef ENANDFLIPS
#define ENANDFLIPS	1024	/* Too many bitflips, corrected */
#define ENANDREAD	1025	/* Read fail, can't correct */
#define ENANDWRITE	1026	/* Write fail */
#define ENANDERASE	1027	/* Erase fail */
#define ENANDBAD	1028	/* Bad block */
#endif

#define BAD_BLOCK_MAX_NUM 1024
/**********  API For Wapper ***********/
struct mtk_nand_chip_bbt_info {
	unsigned int initial_bad_num;
	unsigned int bad_block_num;
	unsigned short bad_block_table[BAD_BLOCK_MAX_NUM];
};

#define MTK_NAND_CHIP_INFO_VERSION 1

struct mtk_nand_chip_info {
	int info_version;
	int data_block_num;		/* Number of data blocks */
	int data_page_num;		/* Number of page in a data block */
	int data_page_size;		/* Data page size */
	int data_oob_size;		/* Data OOB size in a page in bytes */
	int data_block_size;		/* Data block size */
	int data_pe;			/* Data block pe_cycle*/

	int log_block_num;		/* Number of log blocks */
	int log_page_num;		/* Number of page in a log block */
	int log_page_size;		/* Log page size */
	int log_oob_size;		/* Log OOB size in a page in bytes */
	int log_block_size;		/* Log block size */
	int log_pe;				/* Log block pe_cycle*/
	unsigned int slc_ratio;		/* FTL SLC ratio here */
	unsigned int start_block;	/* FTL partition start block number */
	unsigned int sector_size_shift;	/* Minimum Data size shift */
	/*      (1<<sector_size_shift) is sector size */
	/*      9: 512Bytes, 10: 1KB, 11: 2KB, others: Reserved */
	unsigned int max_keep_pages;	/* Max page number for write operation */
	/*      1 : MLC with single-plane */
	/*      2 : MLC with multi-plane */
	/*      9 : TLC with single plane */
	/*      18: TLC with multi-plane */
	enum nand_flash_type types;	/* Define nand flash types */
	unsigned int plane_mask;	/* Plane mask information */
	unsigned int plane_num;	/* Plane number */
	/*      1: Single plane, 2: Multi-plane, 4: Quad plane */
	unsigned int chip_num;       /* Chip number, 1/2/4 or more */
	unsigned int option;            /* Chip ability information */
	unsigned char block_type_bitmap[250];
	/*      bit[0]: FDM partial read */
	/*              0: Not support, 1: Support(Next Gen IP) */
	/*      bit[1]: Plane mode, 0: Not support, 1: Support */
	/*      bit[2]: Cache program, 0: Not support, 1: Support */
	/*      bit[3]: Buffer discontiguous address. */
	/*              this requirement for dma address */
	/*              0: Not support, 1: support, next gen IP  */
	/*      bit[4]: Multi-chip mode */
	/*              0: Not support, 1: Support */
	/*	bit[5]: Support different offset/size for multi-page read */
	/*	bit[6]: Support different page for multi-page read */
	/*      bit[7~31]: Reserved  */
};

/* struct mtk_nand_chip_info *mtk_nand_chip_init(void)
 * Init mntl_chip_info to nand wrapper, after nand driver init.
 * Return: On success, return mtk_nand_chip_info. On error, return error number.
 */
struct mtk_nand_chip_info *mtk_nand_chip_init(void);

/* mtk_nand_chip_read_page
 * Only one page data and FDM data read, support partial read.
 *
 * @info: NAND handler
 * @data_buffer/oob_buffer: Null for no need data/oob, must contiguous address space.
 * @block/page: The block/page to read data.
 * @offset: data offset to start read, and must be aligned to sector size.
 * @size: data size to read. size <= pagesize, less than page size will partial read,
 *    and OOB is only related sectors, uncompleted refer to whole page.
 * return : 0 on success, On error, return error number.
 */
int mtk_nand_chip_read_page(struct mtk_nand_chip_info *info,
		unsigned char *data_buffer, unsigned char *oob_buffer,
		unsigned int block, unsigned int page,
		unsigned int offset, unsigned int size);

/*
 * mtk_nand_chip_read_param
 * Parameter for mult-pages read API.
 *
 * @data_buffer/oob_buffer: data/oob buffer for the page
 *    must contiguous address space.
 * @block/page: block/page to read data.
 * @offset: data offset to start read, and must be aligned to sector size.
 * @size: data size to read. size <= pagesize,
 *    less than page size will partial read,
 *    and OOB is only related sectors, uncompleted refer to whole page.
*/
struct mtk_nand_chip_read_param {
	unsigned char *data_buffer;
	unsigned char *oob_buffer;
	unsigned int block;
	unsigned int page;
	unsigned int offset;
	unsigned int size;
};

/* mtk_nand_chip_read_multi_pages
 * Read multiple pages of data/FDM at once. Support partial read.
 *
 * The driver can choose the number of pages it actually read.
 * Driver only guarantee to read at least one page. Caller must handle
 * unread pages by itself.
 *
 * If there are any error in 2nd or following pages, just return numbers
 * of page read without any error. Driver shouldn't retry/re-read other pages.
 *
 * @info: NAND handler
 * @page_num: the page numbers to read.
 * @param: parameters for each page read
 * return : >0 number of pages read without any error (including ENANDFLIPS)
 *          On first page read error, return error number.
 */
int mtk_nand_chip_read_multi_pages(struct mtk_nand_chip_info *info,
		int page_num, struct mtk_nand_chip_read_param *param);

/*
 * mtk_nand_callback_func
 * Callback for Nand async operation.
 * After Nand driver erase/write operation, callback function will be called.
 * @block/page: The block/page for current operation.
 * @data_buffer/oob_buffer: The block/page for current operation.
 * @status: operation status info from driver.
 * @* userdata : userdata for callback.
 * return : On success, return 0. On error, return error number
 */
typedef int (*mtk_nand_callback_func)(struct mtk_nand_chip_info *info,
		unsigned char *data_buffer, unsigned char *oob_buffer,
		unsigned int block, unsigned int page, int status, void *userdata);

/* mtk_nand_chip_write_page
 * write page API. Only one page data write, async mode.
 * Just return 0 and add to write worklist as below:
 *  a) For TLC WL write, NAND handler call nand driver WL write function.
 *  b) For Multi-plane program, if more_page is TRUE,
 *  wait for the next pages write and do multi-plane write on time.
 *  c) For cache  program, driver will depend on more_page flag for TLC program,
 *  can not used for SLC/MLC program.
 * after Nand driver erase/write operation, callback function will be done.
 *
 * @info: NAND handler
 * @data_buffer/oob_buffer: must contiguous address space.
 * @block/page: The block/page to write data.
 * @more_page: for TLC WL write and multi-plane program operation.
 *    if more_page is true, driver will wait complete operation and call driver function.
 * @*callback: callback for wrapper, called after driver finish the operation.
 * @*userdata : for callback function
 * return : 0 on success, On error, return error number casted by ERR_PTR
 */
int mtk_nand_chip_write_page(struct mtk_nand_chip_info *info,
		unsigned char *data_buffer, unsigned char *oob_buffer,
		unsigned int block, unsigned int page, bool more_page,
		mtk_nand_callback_func callback, void *userdata);

/*
 * mtk_nand_chip_erase_block
 * Erase API for nand wrapper, async mode for erase, just return success,
 * put erase operation into write worklist.
 * After Nand driver erase/write operation, callback function will be done.
 * @block: The block to erase
 * @*callback: Callback for wrapper, called after driver finish the operation.
 * @* userdata: for callback function
 * return : 0 on success, On error, return error number casted by ERR_PTR
 */
int mtk_nand_chip_erase_block(struct mtk_nand_chip_info *info,
		unsigned int block, unsigned int more_block,
		mtk_nand_callback_func callback, void *userdata);


/*
 * mtk_nand_chip_sync
 * flush all async worklist to nand driver.
 * return : On success, return 0. On error, return error number
 */
int mtk_nand_chip_sync(struct mtk_nand_chip_info *info);

/* mtk_nand_chip_bmt, bad block table maintained by driver, and read only for wrapper
 * @info: NAND handler
 * Return FTL partition's bad block table for nand wrapper.
 */
const struct mtk_nand_chip_bbt_info *mtk_nand_chip_bmt(
		struct mtk_nand_chip_info *info);

/* mtk_chip_mark_bad_block
 * Mark specific block as bad block,and update bad block list and bad block table.
 * @block: block address to markbad
 */
void mtk_chip_mark_bad_block(struct mtk_nand_chip_info *info, unsigned int block);

int mtk_nand_update_slc_ratio(int ratio);

int mtk_nand_update_block_type(int num, unsigned int *blk);


#endif
