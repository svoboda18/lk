/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2016. All rights reserved.
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

#if !defined(__MRDUMP_PRIVATE_H__)
#define __MRDUMP_PRIVATE_H__

#include <stdint.h>
#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <dev/mrdump.h>

#ifdef MTK_MRDUMP_SRAM_CB
#include <platform/mtk_mrdump.h>
#endif

/* for LPAE (MTK_3LEVEL_PAGETABLE) */
#include <compiler.h>
#include <arch/arm/mmu.h>

#define MRDUMP_GO_DUMP "MRDUMP08"

/*
 * for ext4 and f2fs, InfoLBA (header), version 2
 * v1: support allocate size > 4G
 * v2: support timestamp
 */
#define MRDUMP_PAF_VERSION 0x0002

#define MRDUMP_PAF_INFO_LBA      4
#define MRDUMP_PAF_ADDR_LBA      8
#define MRDUMP_PAF_ALLOCSIZE    12
#define MRDUMP_PAF_COREDUMPSIZE 20
#define MRDUMP_PAF_TIMESTAMP    28
#define MRDUMP_PAF_CRC32        36
#define MRDUMP_LBA_DATAONLY     MRDUMP_PAF_CRC32
#define MRDUMP_PAF_TOTAL_SIZE   40

#define KZIP_ENTRY_MAX 30
#define LOCALHEADERMAGIC 0x04034b50UL
#define CENTRALHEADERMAGIC 0x02014b50UL
#define ZIP64ENDOFCENTRALDIRMAGIC 0x06064b50UL
#define ZIP64ENDOFCENTRALDIRLOCATORMAGIC 0x07064b50UL
#define ENDOFCENTRALDIRMAGIC 0x06054b50UL

#define MRDUMP_CORE_HEADER_SIZE 2 * 4096

struct kzip_entry {
	char *filename;
	int level;
	uint64_t localheader_offset;
	uint64_t comp_size;
	uint64_t uncomp_size;
	uint32_t crc32;
};

struct kzip_file {
	uint64_t reported_size;
	uint64_t wdk_kick_size;
	uint64_t current_size;

	uint32_t entries_num;
	struct kzip_entry zentries[KZIP_ENTRY_MAX];
	void *handle;

	int (*write_cb)(void *handle, void *buf, int size);
};

#define MEM_NO_MAP 0
#define MEM_DO_MAP 1
#define EXPDB_FILE 2
struct kzip_addlist {
	uint64_t address;
	uint64_t size;
	int type;
};

#define MRDUMP_CPU_MAX 12

#define MRDUMP_ENABLE_COOKIE 0x590d2ba3

typedef uint32_t arm32_gregset_t[18];
typedef uint64_t arm64_gregset_t[34];

struct arm32_ctrl_regs {
	uint32_t sctlr;
	uint64_t ttbcr;
	uint64_t ttbr0;
	uint64_t ttbr1;
};

struct arm64_ctrl_regs {
	uint32_t sctlr_el1;
	uint32_t sctlr_el2;
	uint32_t sctlr_el3;

	uint64_t tcr_el1;
	uint64_t tcr_el2;
	uint64_t tcr_el3;

	uint64_t ttbr0_el1;
	uint64_t ttbr0_el2;
	uint64_t ttbr0_el3;

	uint64_t ttbr1_el1;

	uint64_t sp_el[4];
};

struct mrdump_crash_record {
	int reboot_mode;

	char msg[128];

	uint32_t fault_cpu;

	union {
		arm32_gregset_t arm32_regs;
		arm64_gregset_t arm64_regs;
	} cpu_regs[MRDUMP_CPU_MAX];

	union {
		struct arm32_ctrl_regs arm32_creg;
		struct arm64_ctrl_regs arm64_creg;
	} cpu_creg[MRDUMP_CPU_MAX];
};

struct mrdump_ksyms_param {
	char     tag[4];
	uint32_t flag;
	uint32_t crc;
	uint64_t start_addr;
	uint32_t size;
	uint32_t addresses_off;
	uint32_t num_syms_off;
	uint32_t names_off;
	uint32_t markers_off;
	uint32_t token_table_off;
	uint32_t token_index_off;
} __attribute__((packed));

struct mrdump_machdesc {
	uint32_t nr_cpus;

	uint64_t page_offset;
	uint64_t high_memory;

	uint64_t kimage_vaddr;
	uint64_t dram_start;
	uint64_t dram_end;
	uint64_t kimage_stext;
	uint64_t kimage_etext;
	uint64_t kimage_stext_real;
	uint64_t kimage_voffset;
	uint64_t kimage_sdata;
	uint64_t kimage_edata;

	uint64_t vmalloc_start;
	uint64_t vmalloc_end;

	uint64_t modules_start;
	uint64_t modules_end;

	uint64_t phys_offset;
	uint64_t master_page_table;

	uint64_t memmap;

	uint64_t dfdmem_pa;  // Reserved for DFD 3.0+

	struct mrdump_ksyms_param kallsyms;
};

struct __attribute__((__packed__)) mrdump_cblock_result {
	char sig[9];
	char status[128];
	char log_buf[2048];
};

struct mrdump_control_block {
	char sig[8];

	struct mrdump_machdesc machdesc;
	uint32_t machdesc_crc;

	uint32_t enabled;
	uint32_t output_fs_lbaooo;

	struct mrdump_crash_record crash_record;
};

struct kzip_file *kzip_open(void *handle, int (*write_cb)(void *handle, void *p, int size));
bool kzip_add_file(struct kzip_file *zf, const struct kzip_addlist *addlist, const char *zfilename);
bool kzip_close(struct kzip_file *zf);

struct mrdump_dev {
	const char *name;
	void *handle;

	bool (*read)(struct mrdump_dev *dev, uint64_t sector_addr, uint8_t *pdBuf, int32_t blockLen);
	bool (*write)(struct mrdump_dev *dev, uint64_t sector_addr, uint8_t *pdBuf, int32_t blockLen);
	uint64_t (*get_size)(struct mrdump_dev *dev);
};

int mrdump_null_output(const struct mrdump_control_block *kparams, const struct kzip_addlist *memlist);
int mrdump_ext4_output(const struct mrdump_control_block *mrdump_cb, const struct kzip_addlist *memlist, struct mrdump_dev *mrdump_dev);
int mrdump_partition_output(const struct mrdump_control_block *mrdump_cb, const struct kzip_addlist *memlist, struct mrdump_dev *mrdump_dev);
int mrdump_usb_output(const struct mrdump_control_block *mrdump_cb, const struct kzip_addlist *memlist, const struct kzip_addlist *memlist_cmm);

void mrdump_core_header_init(const struct mrdump_control_block *kparams, const struct kzip_addlist *memlist);

struct kzip_addlist *mrdump_memlist_fill_cmm(struct mrdump_control_block *mrdump_cblock);
void mrdump_memlist_free_cmm(struct kzip_addlist *memlist);

struct mrdump_dev *mrdump_dev_blkpart(const char *partname);
void mrdump_partition_resize(void);
void mrdump_read_expdb(void *data, int len, u64 offset_src);

extern u64 physical_memory_size(void);
extern void mtk_wdt_disable(void);
extern void mtk_wdt_init(void);

int aee_mrdump_get_info(struct mrdump_control_block *mcb);
int mrdump_get_default_output_device(void);

#ifdef MTK_3LEVEL_PAGETABLE
vaddr_t scratch_addr(void);
#endif

#endif
