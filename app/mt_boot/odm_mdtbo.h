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

#ifndef _ODM_MDTBO_H_
#define _ODM_MDTBO_H_


#ifdef MTK_GPT_SCHEME_SUPPORT
#include <platform/partition.h>
#else
#include <mt_partition.h>
#endif  // MTK_GPT_SCHEME_SUPPORT


/******************************************************************************
* Some platform, e.g. mt6755, defines the symbol BLK_SIZE rather than
* PART_HDR_DATA_SIZE. in "partition.h".  If PART_HDR_DATA_SIZE is not defined,
* define it here to avoid compilation error on those platforms.
* TO DO: The interface (e.g. partition.h) should be common code.
******************************************************************************/
#ifndef PART_HDR_DATA_SIZE
#define PART_HDR_DATA_SIZE      512
#endif  // PART_HDR_DATA_SIZE

#define ODM_MDTBO_HDR_SIZE      (512)
#define ODM_MDTBO_HDR_PROLOG    (32)
#define MAX_NUM_OF_ODM_MDTBO    ((ODM_MDTBO_HDR_SIZE - ODM_MDTBO_HDR_PROLOG) / 4)
#define ODM_MDTBO_MAGIC         (0xdeaddead)
#define ODM_MDTBO_VERSION       (2)


/******************************************************************************
* MDTBO: Multiple Device Tree Blob for Overlay
******************************************************************************/
typedef union {
	struct {
		unsigned int magic;             /* magic: PART_MAGIC = 0xdeaddead */
		unsigned int dsize;             /* data size (not including this 512-byte header) */
		unsigned int hdr_size;          /* header size */
		unsigned int hdr_version;       /* header version: ODM_MDTBO_VERSION */
		unsigned int num_of_dtbo;       /* number of dtbo */
		unsigned int reserved[3];       /* reserved */
		/* The data above this is the "header prolog". */
		unsigned int dtbo_offset[MAX_NUM_OF_ODM_MDTBO];  /* offset of dtbo (not including this header) */
	} info;
	unsigned char data[ODM_MDTBO_HDR_SIZE];
} mdtbo_hdr_t;


/******************************************************************************
* New DTBO partition format defined since Android P
******************************************************************************/
#define DT_TABLE_MAGIC 0xd7b7ab1e
#define LARGE_DT_ENTRY_SIZE 0 //can be customized in case of built-in super large # of DT

struct dt_table_header {
	uint32_t magic;			// DT_TABLE_MAGIC
	uint32_t total_size;		// includes dt_table_header + all dt_table_entry and all dtb/dtbo
	uint32_t header_size;		// sizeof(dt_table_header)

	uint32_t dt_entry_size;		// sizeof(dt_table_entry)
	uint32_t dt_entry_count;	// number of dt_table_entry
	uint32_t dt_entries_offset;	// offset to the first dt_table_entry from head of dt_table_header

	uint32_t page_size;		// flash page size we assume
	uint32_t version;		// DTBOage version, the current version is 0.
					// The version will be incremented when the
					// dt_table_header struct is updated.
};

struct dt_table_entry {
	uint32_t dt_size;
	uint32_t dt_offset;		// offset from head of dt_table_header

	uint32_t id;			// use this field as index of CONFIG_BUILD_ARM_DTB_OVERLAY_IMAGE_NAMES
	uint32_t rev;			// optional, must be zero if unused
	uint32_t custom[4];		// optional, must be zero if unused
};


/******************************************************************************
* NOTE: Customers need to implement their own customized_get_odm_mdtbo_index()
*       function. If customized_get_odm_mdtbo_index() is not implemented, the
*       value 0 will be used as the default dtbo index. Each customer can
*       maintain their own implementation of customized_get_odm_mdtbo_index()
*       in a separate source file as long as it can be linked.
******************************************************************************/
int customized_get_odm_mdtbo_index(void) __attribute__((weak));

int get_odm_mdtbo_index(void);
char *load_overlay_dtbo(char *part_name, unsigned int *size, uint64_t recovery_dtbo_offset);
int get_dtbo_index(void);
void set_dtbo_index(int dtbo_idx);

#endif // _ODM_MDTBO_H_


