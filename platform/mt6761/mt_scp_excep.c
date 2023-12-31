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

#include <stdint.h>
#include <string.h>
#include <debug.h>
#include <platform/boot_mode.h>
#include <platform/partition.h>
#include <platform/verified_boot.h>
#include <platform/sec_policy.h>
#include <env.h>
#include <assert.h>
#include <platform/mt_scp.h>
#include <platform/errno.h>
#include <mt_scp_excep.h>
#include <reg.h>
#include <malloc.h>
#include <lib/crc.h>
#include <lib/zutil.h>
#include <lib/zlib.h>
#include <platform/mtk_wdt.h>

#ifdef MTK_3LEVEL_PAGETABLE
#include <arch/arm/mmu.h>
#include <stdlib.h>
#include <err.h>
#endif

static inline void elf_setup_eident(unsigned char e_ident[EI_NIDENT], unsigned char elfclasz)
{
	memcpy(e_ident, "\177ELF", 4);    /* memcpy(e_ident, ELFMAG, SELFMAG) */
	e_ident[EI_CLASS] = elfclasz;
	e_ident[EI_DATA] = ELFDATA2LSB;
	e_ident[EI_VERSION] = EV_CURRENT;
	e_ident[EI_OSABI] = ELFOSABI_NONE;
	memset(e_ident+EI_PAD, 0, EI_NIDENT-EI_PAD);
}

struct elf_siginfo {
	int si_signo;
	int si_code;
	int si_errno;
};

struct elf32_note_t {
	__u32   n_namesz;       /* Name size */
	__u32   n_descsz;       /* Content size */
	__u32   n_type;         /* Content type */
};

struct elf32_timeval {
	int32_t tv_sec;
	int32_t tv_usec;
};
struct elf32_prstatus {
	struct elf_siginfo pr_info;
	short pr_cursig;
	uint32_t pr_sigpend;
	uint32_t pr_sighold;

	int32_t pr_pid;
	int32_t pr_ppid;
	int32_t pr_pgrp;

	int32_t pr_sid;
	struct elf32_timeval pr_utime;
	struct elf32_timeval pr_stime;
	struct elf32_timeval pr_cutime;
	struct elf32_timeval pr_cstime;

	uint32_t pr_reg[ELF_NGREGS];

	int32_t pr_fpvalid;
};

struct elf32_prpsinfo {
	char pr_state;
	char pr_sname;
	char pr_zomb;
	char pr_nice;
	uint32_t pr_flag;

	uint16_t pr_uid;
	uint16_t pr_gid;

	int32_t pr_pid;
	int32_t pr_ppid;
	int32_t pr_pgrp;
	int32_t pr_sid;

	char pr_fname[16];
	char pr_psargs[ELF_PRARGSZ];
};

struct scp_status_reg {
	unsigned int pc;
	unsigned int lr;
	unsigned int psp;
	unsigned int sp;
	unsigned int m2h;
	unsigned int h2m;
};

/* An ELF note in memory */
struct memelfnote {
	const char *name;
	int type;
	unsigned int datasz;
	void *data;
};

static uint32_t roundup(uint32_t x, uint32_t y)
{
	return ((x + y - 1) / y) * y;
}

static int notesize(struct memelfnote *en)
{
	int sz;

	sz = sizeof(struct elf32_note);
	sz += roundup((strlen(en->name) + 1), 4);
	sz += roundup(en->datasz, 4);

	return sz;
}

static uint8_t *storenote(struct memelfnote *men, uint8_t *bufp)
{
	struct elf32_note en;

	en.n_namesz = strlen(men->name) + 1;
	en.n_descsz = men->datasz;
	en.n_type = men->type;

	memcpy(bufp, &en, sizeof(en));
	bufp += sizeof(en);

	memcpy(bufp, men->name, en.n_namesz);
	bufp += en.n_namesz;

	bufp = (uint8_t *) roundup((unsigned long)bufp, 4);
	memcpy(bufp, men->data, men->datasz);
	bufp += men->datasz;

	bufp = (uint8_t *) roundup((unsigned long)bufp, 4);
	return bufp;
}

static uint8_t *core_write_cpu_note(int cpu, struct elf32_phdr *nhdr, uint8_t *bufp, enum scp_core_id id)
{
	struct memelfnote notes;
	struct elf32_prstatus prstatus;
	char cpustr[16];
	unsigned int scp_A_task_context_addr;
	struct scp_region_info_st* scp_region_info = (void *)(SCP_SRAM_BASE + SCP_LOADER_SIZE);
	scp_A_task_context_addr = (unsigned int)scp_region_info->TaskContext_ptr;
	memset(&prstatus, 0, sizeof(struct elf32_prstatus));
	snprintf(cpustr, sizeof(cpustr), "CPU%d", cpu);
	/* set up the process status */
	notes.name = cpustr;
	notes.type = NT_PRSTATUS;
	notes.datasz = sizeof(struct elf32_prstatus);
	notes.data = &prstatus;

	prstatus.pr_pid = cpu + 1;
	/* if TaskContext_ptr with enable bit[31] */
	if ((scp_A_task_context_addr & 0x80000000) && (id == SCP_A_ID)) {
		memcpy((void *)&(prstatus.pr_reg),
		       (void *)(SCP_SRAM_BASE + (scp_A_task_context_addr & 0x7fffffff)), sizeof(prstatus.pr_reg));
	}
	if (prstatus.pr_reg[15] == 0x0 && (id == SCP_A_ID))
		prstatus.pr_reg[15] = readl(SCP_WDT_PC);
	if (prstatus.pr_reg[14] == 0x0 && (id == SCP_A_ID))
		prstatus.pr_reg[14] = readl(SCP_WDT_LR);
	if (prstatus.pr_reg[13] == 0x0 && (id == SCP_A_ID))
		prstatus.pr_reg[13] = readl(SCP_WDT_PSP);

	nhdr->p_filesz += notesize(&notes);
	return storenote(&notes, bufp);
}

void exception_header_init(void *oldbufp, enum scp_core_id id)
{
	struct elf32_phdr *nhdr, *phdr;
	struct elf32_hdr *elf;
	off_t offset = 0;

	uint8_t *bufp = oldbufp;
	uint32_t cpu;
	uint32_t dram_size = 0;
	struct scp_region_info_st* scp_region_info = (void *)(SCP_SRAM_BASE + SCP_LOADER_SIZE);

	/* NT_PRPSINFO */
	struct elf32_prpsinfo prpsinfo;
	struct memelfnote notes;

	elf = (struct elf32_hdr *) bufp;
	bufp += sizeof(struct elf32_hdr);
	offset += sizeof(struct elf32_hdr);
	elf_setup_eident(elf->e_ident, ELFCLASS32);

	/*setup elf header*/
	elf->e_type = ET_CORE;
	elf->e_machine = EM_ARM;
	elf->e_version = EV_CURRENT;
	elf->e_entry = 0;
	elf->e_phoff = sizeof(struct elf32_hdr);
	elf->e_shoff = 0;
	elf->e_flags = ELF_CORE_EFLAGS;
	elf->e_ehsize = sizeof(struct elf32_hdr);
	elf->e_phentsize = sizeof(struct elf32_phdr);
	elf->e_phnum = 2;
	elf->e_shentsize = 0;
	elf->e_shnum = 0;
	elf->e_shstrndx = 0;

	nhdr = (struct elf32_phdr *) bufp;
	bufp += sizeof(struct elf32_phdr);
	offset += sizeof(struct elf32_phdr);
	memset(nhdr, 0, sizeof(struct elf32_phdr));
	nhdr->p_type = 4; /* PT_NOTE */

	phdr = (struct elf32_phdr *) bufp;
	bufp += sizeof(struct elf32_phdr);
	offset += sizeof(struct elf32_phdr);
	phdr->p_flags = 0x4|0x2|0x1; /* PF_R|PF_W|PF_X */
	phdr->p_offset = CRASH_MEMORY_HEADER_SIZE;
	phdr->p_vaddr = CRASH_MEMORY_OFFSET;
	phdr->p_paddr = CRASH_MEMORY_OFFSET;

	if ((int)(scp_region_info->ap_dram_size) > 0)
		dram_size = scp_region_info->ap_dram_size;

	phdr->p_filesz = CRASH_MEMORY_LENGTH + roundup(dram_size, 4);
	phdr->p_memsz = CRASH_MEMORY_LENGTH + roundup(dram_size, 4);


	phdr->p_align = 0;
	phdr->p_type = 1; /* PT_LOAD */

	nhdr->p_offset = offset;

	/* set up the process info */
	notes.name = CORE_STR;
	notes.type = NT_PRPSINFO;
	notes.datasz = sizeof(struct elf32_prpsinfo);
	notes.data = &prpsinfo;

	memset(&prpsinfo, 0, sizeof(struct elf32_prpsinfo));
	prpsinfo.pr_state = 0;
	prpsinfo.pr_sname = 'R';
	prpsinfo.pr_zomb = 0;
	prpsinfo.pr_gid = prpsinfo.pr_uid = 0x0;
	strlcpy(prpsinfo.pr_fname, "freertos8", sizeof(prpsinfo.pr_fname));
	strlcpy(prpsinfo.pr_psargs, "freertos8", ELF_PRARGSZ);

	nhdr->p_filesz += notesize(&notes);
	bufp = storenote(&notes, bufp);

	/* Store pre-cpu backtrace */
	for (cpu = 0; cpu < 1; cpu++)
		bufp = core_write_cpu_note(cpu, nhdr, bufp, id);
}
/*dump scp reg*/
void scp_reg_copy(void *bufp)
{
	struct scp_reg_dump_list *scp_reg;
	uint32_t tmp;
	scp_reg = (struct scp_reg_dump_list *) bufp;

	/*setup scp reg*/
	scp_reg->scp_reg_magic = 0xDEADBEEF;
	scp_reg->ap_resource = readl(SCP_AP_RESOURCE);
	scp_reg->bus_resource = readl(SCP_BUS_RESOURCE);
	scp_reg->slp_protect = readl(SCP_SLP_PROTECT_CFG);
	scp_reg->cpu_sleep_status = readl(SCP_CPU_SLEEP_STATUS);
	scp_reg->clk_sw_sel = readl(SCP_CLK_SW_SEL);
	scp_reg->clk_enable = readl(SCP_CLK_ENABLE);
	scp_reg->clk_high_core = readl(SCP_CLK_HIGH_CORE_CG);
	scp_reg->debug_wdt_sp = readl(SCP_WDT_SP);
	scp_reg->debug_wdt_lr = readl(SCP_WDT_LR);
	scp_reg->debug_wdt_psp = readl(SCP_WDT_PSP);
	scp_reg->debug_wdt_pc = readl(SCP_WDT_PC);
	scp_reg->debug_addr_s2r = readl(SCP_DEBUG_ADDR_S2R);
	scp_reg->debug_addr_dma = readl(SCP_DEBUG_ADDR_DMA);
	scp_reg->debug_addr_spi0 = readl(SCP_DEBUG_ADDR_SPI0);
	scp_reg->debug_addr_spi1 = readl(SCP_DEBUG_ADDR_SPI1);
	scp_reg->debug_addr_spi2 = readl(SCP_DEBUG_ADDR_SPI2);
	scp_reg->debug_bus_status = readl(SCP_DEBUG_BUS_STATUS);
	/*  scp_reg->debug_infra_mon = readl(SCP_SYS_INFRA_MON); */
	tmp = readl(SCP_BUS_CTRL)&(~dbg_irq_info_sel_mask);
	writel(tmp | (0 << dbg_irq_info_sel_shift) ,SCP_BUS_CTRL);
	scp_reg->infra_addr_latch = readl(SCP_DEBUG_IRQ_INFO);
	writel(tmp | (1 << dbg_irq_info_sel_shift) ,SCP_BUS_CTRL);
	scp_reg->ddebug_latch = readl(SCP_DEBUG_IRQ_INFO);
	writel(tmp | (2 << dbg_irq_info_sel_shift) ,SCP_BUS_CTRL);
	scp_reg->pdebug_latch = readl(SCP_DEBUG_IRQ_INFO);
	writel(tmp | (3 << dbg_irq_info_sel_shift) ,SCP_BUS_CTRL);
	scp_reg->pc_value = readl(SCP_DEBUG_IRQ_INFO);
	scp_reg->scp_reg_magic_end = 0xDEADBEEF;

}

/*dump scp l1c header*/
void scp_sub_header_init(void *bufp)
{
	struct scp_region_info_st* scp_region_info = (void *)(SCP_SRAM_BASE + SCP_LOADER_SIZE);
	struct scp_dump_header_list *scp_sub_head;

	scp_sub_head = (struct scp_dump_header_list *) bufp;
	/*setup scp reg*/
	scp_sub_head->scp_head_magic = 0xDEADBEEF;
	memcpy(&scp_sub_head->scp_region_info,
		scp_region_info, sizeof(struct scp_region_info_st));
	scp_sub_head->scp_head_magic_end = 0xDEADBEEF;
}

#define BUF_SIZE 65536
int scp_zip_compress(unsigned char* input, unsigned char* output, unsigned int input_size)
{
	int ret, flush;
	int have;
	z_stream strm;
	int i = 0;
	int j = 0;
	unsigned int avail_input_size = input_size;
	unsigned char *ibuf;
	unsigned char *obuf;

	ibuf = malloc(BUF_SIZE);
	if (ibuf == NULL)
		return Z_BUF_ERROR;

	obuf = malloc(BUF_SIZE);
	if (obuf == NULL) {
		free(ibuf);
		return Z_BUF_ERROR;
	}

	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	/* allocate deflate state */
	memset(&strm, 0, sizeof(z_stream));
	ret = deflateInit2(&strm, Z_BEST_COMPRESSION, Z_DEFLATED, 31, 8, Z_DEFAULT_STRATEGY);
	if (ret != Z_OK) {
		free(ibuf);
		free(obuf);
		return ret;
	}

	/* compress until end of file */
	do {
		strm.avail_in = BUF_SIZE;
		strm.next_in = ibuf;
		strm.avail_out = BUF_SIZE;
		strm.next_out = obuf;
		flush = Z_NO_FLUSH;
		if (avail_input_size < BUF_SIZE) {
			strm.avail_in = avail_input_size;
			flush = Z_FINISH;
		}

		memcpy(ibuf, (void *)&input[i], strm.avail_in);
		i += strm.avail_in;
		avail_input_size -= strm.avail_in;
		strm.next_in = ibuf;

		/* run deflate() on input until output buffer not full, finish
		   compression if all of source has been read in */
		do {
			strm.avail_out = BUF_SIZE;
			strm.next_out = obuf;
			ret = deflate(&strm, flush);    /* no bad return value */
			assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
			have = BUF_SIZE - strm.avail_out;
			memcpy((void *)&output[j], obuf, have);
			j+=have;
			mtk_wdt_restart();
		} while (strm.avail_out == 0);
		assert(strm.avail_in == 0);     /* all input will be used */

		/* done when last data in file processed */
	} while (flush != Z_FINISH);
	assert(ret == Z_STREAM_END);        /* stream will be complete */
	free(ibuf);
	free(obuf);
	/* clean up and return */
	(void)deflateEnd(&strm);
	return j;
}

/*
 * this function need SCP to keeping awaken
 * scp_crash_dump: dump scp tcm info.
 * @param MemoryDump:   scp dump struct
 * @param scp_core_id:  core id
 * @return:             scp dump size
 */

#define SCP_EE_SIZE 0xA0000 //640 KB
int scp_crash_dump(void *crash_buffer)
{
	unsigned int scp_dump_size;
	int datasize;
	struct MemoryDump *pDump;
	void *tmp_ptr;
	uint32_t dram_start = 0;
	uint32_t dram_size = 0;
	struct scp_region_info_st* scp_region_info = (void *)(SCP_SRAM_BASE + SCP_LOADER_SIZE);

	/* L1C support? */
	if ((int)(scp_region_info->ap_dram_size) <= 0) {
		scp_dump_size = sizeof(struct MemoryDump);
	} else {
		scp_l1c_init(scp_region_info->Il1c_con, scp_region_info->Dl1c_con);
		dram_start = scp_region_info->ap_dram_start;
		dram_size = scp_region_info->ap_dram_size;
		if (arch_mmu_map((uint64_t)dram_start, (uint32_t)dram_start,
		                 MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA, ROUNDUP(dram_size, PAGE_SIZE)) != NO_ERROR)
			dprintf(INFO, "scp_crash_dump: map error\n");
		scp_dump_size = sizeof(struct MemoryDump) + ROUNDUP(dram_size, 4);
	}
	tmp_ptr = pDump = malloc(scp_dump_size);
	if (tmp_ptr == NULL)
		return 0;
	/* todo confirm sram is power on? */
	exception_header_init(tmp_ptr, SCP_A_ID);
	/* init sub header*/
	scp_sub_header_init(&(pDump->scp_dump_header));

	if (dram_size) {
		/* can't flush due to we don't remap l1c yet*/
		/* must 4 byte alignment */
		memcpy((void *)&(pDump->memory),
		       (void *)(SCP_SRAM_BASE + CRASH_MEMORY_OFFSET), CRASH_MEMORY_LENGTH);

		memcpy((void *)&(pDump->scp_reg_dump),
		       (void *)(dram_start), dram_size);
		scp_reg_copy((void *)(&pDump->scp_reg_dump) + ROUNDUP(dram_size,4 ));
	} else {
		/* must 4 byte alignment */
		memcpy((void *)&(pDump->memory),
		       (void *)(SCP_SRAM_BASE + CRASH_MEMORY_OFFSET), CRASH_MEMORY_LENGTH);
		scp_reg_copy(&(pDump->scp_reg_dump));
	}

	datasize = scp_zip_compress((void *)tmp_ptr, (void *)crash_buffer, scp_dump_size);
	free(tmp_ptr);
	return datasize;
}

