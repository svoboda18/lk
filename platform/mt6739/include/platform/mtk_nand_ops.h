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


#ifndef __MTK_NAND_OPS_H__
#define __MTK_NAND_OPS_H__

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
#include <platform/mtk_nand_chip.h>

#ifndef EIO
#define	EIO		 5	/* I/O error */
#define	ENOMEM		12	/* Out of memory */
#define	EFAULT		14	/* Bad address */
#define	EBUSY		16	/* Device or resource busy */
#define	EINVAL		22	/* Invalid argument */
#define	ENOSPC		28	/* No space left on device */
#define	EROFS		30	/* Read-only file system */
#endif

#define MTK_FORCE_READ_FULL_PAGE

extern flashdev_info devinfo;
extern struct nand_chip g_nand_chip;
extern NFI_TLC_PG_CYCLE tlc_program_cycle;
extern bool tlc_lg_left_plane;
extern struct mtk_nand_host *host;
extern void dump_nfi(void);

#define NAND_DEBUG_DISABLE	1
/* nand debug messages */
#if NAND_DEBUG_DISABLE
#define nand_debug(fmt, ...) do {} while (0)
#else
#define nand_debug(fmt, ...) dprintf(CRITICAL, "NAND: " fmt "\n", ##__VA_ARGS__)
#endif

/* nand error messages */
#define nand_info(fmt, ...) dprintf(INFO, "NAND:%s %d info: " fmt "\n",      \
	__func__, __LINE__,  ##__VA_ARGS__)

/* nand error messages */
#define nand_err(fmt, ...) dprintf(CRITICAL, "NAND:%s %d failed: " fmt "\n",      \
	__func__, __LINE__,  ##__VA_ARGS__)

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef TRUE
#define TRUE  (1)
#endif

#ifndef NULL
#define NULL  (0)
#endif


#define MTK_TLC_DIV	3
#define MTK_MLC_DIV	2

/**********  BMT Related ***********/

#define DATA_BAD_BLK		0xffff

#define DATA_MAX_BMT_COUNT		0x400
#define DATA_BMT_VERSION		(1)

#define BAD_BLOCK_SHIPPED		(1)
#define BAD_BLOCK_ERASE_FAILED	(2)
#define BAD_BLOCK_WRITE_FAILED	(3)

struct data_bmt_entry {
	u16 bad_index;	/* bad block index */
	u8 flag;		/* mapping block index in the replace pool */
};

typedef struct {
	struct data_bmt_entry entry[DATA_MAX_BMT_COUNT];
	unsigned int  version;
	unsigned int bad_count;		/* bad block count */
	unsigned int start_block;	/* data partition start block addr */
	unsigned int end_block;		/* data partition start block addr */
	unsigned int checksum;
}data_bmt_struct;

/**********  PMT Related ***********/

#define FTL_PARTITION_NAME	"USRDATA"

struct nand_ftl_partition_info {
	unsigned int start_block;		/* Number of data blocks */
	unsigned int total_block;		/* Number of block */
	unsigned int slc_ratio;		/* FTL SLC ratio here */
	unsigned int slc_block;		/* FTL SLC ratio here */
};

enum operation_types {
	MTK_NAND_OP_READ = 0,
	MTK_NAND_OP_WRITE,
	MTK_NAND_OP_ERASE,
};

#define containerof(ptr, type, member) \
	((type *)((unsigned long)(ptr) - __builtin_offsetof(type, member)))

struct mtk_nand_chip_operation {
	struct mtk_nand_chip_info *info; /* Data info */
	enum operation_types types;
	/* Operation type, 0: Read, 1: write, 2:Erase*/
	int block;
	int page;
	int offset;
	int size;
	bool more;
	unsigned char *data_buffer;
	unsigned char *oob_buffer;
	mtk_nand_callback_func callback;
	void *userdata;
};

struct nand_work {
	struct nand_work *next;
	struct mtk_nand_chip_operation ops;
};

enum worklist_type {
	LIST_ERASE = 0,
	LIST_SLC_WRITE,
	LIST_NS_WRITE, /* none slc write list: mlc or tlc */
};

struct worklist_ctrl {
	struct nand_work *head;
	int total_num;
};

struct err_para {
	int rate;
	int count;/*max count*/
	int block;
	int page;
};
struct sim_err {
	struct err_para erase_fail;
	struct err_para write_fail;
	struct err_para read_fail;
	struct err_para bitflip_fail;
	struct err_para bad_block;
};

struct mtk_nand_data_info {
	data_bmt_struct bmt;
	struct mtk_nand_chip_bbt_info chip_bbt;
	struct mtk_nand_chip_info chip_info;
	struct nand_ftl_partition_info partition_info;

	struct worklist_ctrl elist_ctrl;
	struct worklist_ctrl swlist_ctrl;
	struct worklist_ctrl wlist_ctrl;

	struct sim_err err;
};

enum TLC_MULTI_PROG_MODE {
	MULTI_BLOCK = 0,
	BLOCK0_ONLY,
	BLOCK1_ONLY,
};
#if defined(CONFIG_PWR_LOSS_MTK_SPOH)
struct mvg_case_stack {
	char gname[63];
	char cname[63];
	struct mvg_case_stack *next;
};
#endif


extern struct mtk_nand_data_info *data_info;
extern int mtk_nand_ops_init(void);
extern int mtk_nand_data_info_init(void);
extern int get_data_partition_info(struct nand_ftl_partition_info *info, struct mtk_nand_chip_info *cinfo);

u32 get_ftl_row_addr(struct mtk_nand_chip_info *info,
							unsigned int block, unsigned int page);
extern int nand_exec_read_page_hw(struct nand_chip *nand, u32 page, u32 page_size, u8 * dat, u8 * oob);
extern bool nand_exec_write_page_hw(struct nand_chip * nand,u32 u4RowAddr,u32 u4PageSize,u8 * pPageBuf,u8 * pFDMBuf);
extern int nand_erase_hw(u64 offset);
extern int get_data_bmt(data_bmt_struct *data_bmt);

extern int load_part_tab(u8 *buf);
extern int mntl_update_part_tab(struct mtk_nand_chip_info *info, int num, unsigned int *blk);

#endif

