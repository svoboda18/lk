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

#include <malloc.h>
#include <string.h>
#include <printf.h>
#include "mrdump_private.h"
#include "mrdump_elf.h"

#define mrdump_elf_setup_elfhdr(elfp, machid, elfhdr_t, elfphdr_t, phdrcount)	\
	elfp->e_type = ET_CORE;						\
	elfp->e_machine = machid;					\
	elfp->e_version = EV_CURRENT;					\
	elfp->e_entry = 0;						\
	elfp->e_phoff = sizeof(elfhdr_t);				\
	elfp->e_shoff = 0;						\
	elfp->e_flags = ELF_CORE_EFLAGS;				\
	elfp->e_ehsize = sizeof(elfhdr_t);				\
	elfp->e_phentsize = sizeof(elfphdr_t);				\
	elfp->e_phnum = phdrcount;					\
	elfp->e_shentsize = 0;						\
	elfp->e_shnum = 0;						\
	elfp->e_shstrndx = 0;						\

static inline void mrdump_elf_setup_eident(unsigned char e_ident[EI_NIDENT], unsigned char elfclasz)
{
	memcpy(e_ident, ELFMAG, SELFMAG);
	e_ident[EI_CLASS] = elfclasz;
	e_ident[EI_DATA] = ELFDATA2LSB;
	e_ident[EI_VERSION] = EV_CURRENT;
	e_ident[EI_OSABI] = ELFOSABI_NONE;
	memset(e_ident+EI_PAD, 0, EI_NIDENT-EI_PAD);
}

static uint32_t roundup(uint32_t x, uint32_t y)
{
	return ((x + y - 1) / y) * y;
}

/* An ELF note in memory */
struct memelfnote {
	const char *name;
	int type;
	unsigned int datasz;
	void *data;
};

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

	bufp = (uint8_t*) roundup((unsigned long)bufp, 4);
	memcpy(bufp, men->data, men->datasz);
	bufp += men->datasz;

	bufp = (uint8_t*) roundup((unsigned long)bufp, 4);
	return bufp;
}

static uint8_t *mrdump_core32_write_cpu_note(const struct mrdump_control_block *mrdump_cb, int cpu, struct elf32_phdr *nhdr, uint8_t *bufp)
{
	struct memelfnote notes;
	struct elf32_arm_prstatus prstatus;
	char cpustr[16];

	memset(&prstatus, 0, sizeof(struct elf32_arm_prstatus));

	snprintf(cpustr, sizeof(cpustr), "CPU%d", cpu);
	/* set up the process status */
	notes.name = cpustr;
	notes.type = NT_PRSTATUS;
	notes.datasz = sizeof(struct elf32_arm_prstatus);
	notes.data = &prstatus;

	prstatus.pr_pid = cpu + 1;
	memcpy(&prstatus.pr_reg, (unsigned long*)&mrdump_cb->crash_record.cpu_regs[cpu].arm32_regs, sizeof(elf_arm_gregset_t));

	nhdr->p_filesz += notesize(&notes);
	return storenote(&notes, bufp);
}

static uint8_t *mrdump_core32_write_machdesc(const struct mrdump_control_block *mrdump_cb, struct elf32_phdr *nhdr, uint8_t *bufp)
{
	struct memelfnote notes;
	struct elf_mrdump_machdesc machdesc;
	const struct mrdump_machdesc *kparams = &mrdump_cb->machdesc;

	memset(&machdesc, 0, sizeof(struct elf_mrdump_machdesc));

	notes.name = "MRDUMP01";
	notes.type = NT_MRDUMP_MACHDESC;
	notes.datasz = sizeof(struct elf_mrdump_machdesc);
	notes.data = &machdesc;

	machdesc.flags = MRDUMP_TYPE_FULL_MEMORY;
	machdesc.nr_cpus = kparams->nr_cpus;
	machdesc.phys_offset = kparams->phys_offset;
	machdesc.page_offset = kparams->page_offset;
	machdesc.high_memory = kparams->high_memory;
	machdesc.kimage_vaddr = kparams->kimage_vaddr;
	machdesc.modules_start = kparams->modules_start;
	machdesc.modules_end = kparams->modules_end;
	machdesc.vmalloc_start = kparams->vmalloc_start;
	machdesc.vmalloc_end = kparams->vmalloc_end;
	machdesc.master_page_table = kparams->master_page_table;

	nhdr->p_filesz += notesize(&notes);
	return storenote(&notes, bufp);
}

static uint8_t *mrdump_core32_write_cb(const struct mrdump_control_block *mrdump_cb, struct elf32_phdr *nhdr, uint8_t *bufp)
{
	struct memelfnote notes;
	uint64_t mrdump_cb_paddr = (uint64_t)(uintptr_t)mrdump_cb;

	notes.name = MRDUMP_GO_DUMP;
	notes.type = NT_MRDUMP_CBLOCK;
	notes.datasz = sizeof(mrdump_cb_paddr);
	notes.data = &mrdump_cb_paddr;

	nhdr->p_filesz += notesize(&notes);
	return storenote(&notes, bufp);
}

static void mrdump_core32_header_init(const struct mrdump_control_block *mrdump_cb, const struct kzip_addlist *memlist)
{
	struct elf32_phdr *nhdr, *phdr;
	struct elf32_hdr *elf;
	off_t offset = 0;
	const struct mrdump_machdesc *kparams = &mrdump_cb->machdesc;

	uint8_t *bufp = (uint8_t *)(uintptr_t)memlist[0].address;

	elf = (struct elf32_hdr *) bufp;
	bufp += sizeof(struct elf32_hdr);
	offset += sizeof(struct elf32_hdr);

	nhdr = (struct elf32_phdr *) bufp;
	bufp += sizeof(struct elf32_phdr);
	offset += sizeof(struct elf32_phdr);
	memset(nhdr, 0, sizeof(struct elf32_phdr));
	nhdr->p_type = PT_NOTE;

	unsigned long long foffset = MRDUMP_CORE_HEADER_SIZE;
	int i;
	for (i = 1; memlist[i].address != 0;i++) {
		phdr = (struct elf32_phdr *) bufp;
		bufp += sizeof(struct elf32_phdr);
		offset += sizeof(struct elf32_phdr);

		phdr->p_type    = PT_LOAD;
		phdr->p_flags   = PF_R|PF_W|PF_X;
		phdr->p_offset  = foffset;
		phdr->p_vaddr   = 0;
		phdr->p_paddr   = memlist[i].address;
		phdr->p_filesz  = memlist[i].size;
		phdr->p_memsz   = memlist[i].size;
		phdr->p_align   = 0;

		foffset += phdr->p_filesz;
	}

	mrdump_elf_setup_eident(elf->e_ident, ELFCLASS32);
	mrdump_elf_setup_elfhdr(elf, EM_ARM, struct elf32_hdr, struct elf32_phdr, i);

	nhdr->p_offset = offset;

	/* NT_PRPSINFO */
	struct elf32_prpsinfo prpsinfo;
	struct memelfnote notes;
	/* set up the process info */
	notes.name = CORE_STR;
	notes.type = NT_PRPSINFO;
	notes.datasz = sizeof(struct elf32_prpsinfo);
	notes.data = &prpsinfo;

	memset(&prpsinfo, 0, sizeof(struct elf32_prpsinfo));
	prpsinfo.pr_state = 0;
	prpsinfo.pr_sname = 'R';
	prpsinfo.pr_zomb = 0;
	prpsinfo.pr_gid = prpsinfo.pr_uid = mrdump_cb->crash_record.fault_cpu + 1;
	strlcpy(prpsinfo.pr_fname, "vmlinux", sizeof(prpsinfo.pr_fname));
	strlcpy(prpsinfo.pr_psargs, "vmlinux", ELF_PRARGSZ);

	nhdr->p_filesz += notesize(&notes);
	bufp = storenote(&notes, bufp);

	bufp = mrdump_core32_write_machdesc(mrdump_cb, nhdr, bufp);

	/* Store pre-cpu backtrace */
	bufp = mrdump_core32_write_cpu_note(mrdump_cb, mrdump_cb->crash_record.fault_cpu, nhdr, bufp);
	for (unsigned int cpu = 0; cpu < kparams->nr_cpus; cpu++) {
		if (cpu != mrdump_cb->crash_record.fault_cpu) {
			bufp = mrdump_core32_write_cpu_note(mrdump_cb, cpu, nhdr, bufp);
		}
	}

	/* store mrdump control block */
	bufp = mrdump_core32_write_cb(mrdump_cb, nhdr, bufp);
}

static int notesize64(struct memelfnote *en)
{
	int sz;

	sz = sizeof(struct elf64_note);
	sz += roundup((strlen(en->name) + 1), 4);
	sz += roundup(en->datasz, 4);

	return sz;
}

static uint8_t *storenote64(struct memelfnote *men, uint8_t *bufp)
{
	struct elf64_note en;
	en.n_namesz = strlen(men->name) + 1;
	en.n_descsz = men->datasz;
	en.n_type = men->type;

	memcpy(bufp, &en, sizeof(en));
	bufp += sizeof(en);

	memcpy(bufp, men->name, en.n_namesz);
	bufp += en.n_namesz;

	bufp = (uint8_t*) roundup((unsigned long)bufp, 4);
	memcpy(bufp, men->data, men->datasz);
	bufp += men->datasz;

	bufp = (uint8_t*) roundup((unsigned long)bufp, 4);
	return bufp;
}

static uint8_t *mrdump_core64_write_cpu_note(const struct mrdump_control_block *mrdump_cb, int cpu, struct elf64_phdr *nhdr, uint8_t *bufp)
{
	struct memelfnote notes;
	struct elf_arm64_prstatus64 prstatus;
	char cpustr[16];

	memset(&prstatus, 0, sizeof(struct elf_arm64_prstatus64));

	snprintf(cpustr, sizeof(cpustr), "CPU%d", cpu);
	/* set up the process status */
	notes.name = cpustr;
	notes.type = NT_PRSTATUS;
	notes.datasz = sizeof(struct elf_arm64_prstatus64);
	notes.data = &prstatus;

	prstatus.pr_pid = cpu + 1;
	memcpy(&prstatus.pr_reg, &mrdump_cb->crash_record.cpu_regs[cpu].arm64_regs, sizeof(elf_arm64_gregset_t));

	nhdr->p_filesz += notesize64(&notes);
	return storenote64(&notes, bufp);
}

static uint8_t *mrdump_core64_write_machdesc(const struct mrdump_control_block *mrdump_cb, struct elf64_phdr *nhdr, uint8_t *bufp)
{
	struct memelfnote notes;
	struct elf_mrdump_machdesc machdesc;
	const struct mrdump_machdesc *kparams = &mrdump_cb->machdesc;

	memset(&machdesc, 0, sizeof(struct elf_mrdump_machdesc));

	notes.name = "MRDUMP01";
	notes.type = NT_MRDUMP_MACHDESC;
	notes.datasz = sizeof(struct elf_mrdump_machdesc);
	notes.data = &machdesc;

	machdesc.flags = MRDUMP_TYPE_FULL_MEMORY;
	machdesc.nr_cpus = kparams->nr_cpus;
	machdesc.phys_offset = kparams->phys_offset;
	machdesc.page_offset = kparams->page_offset;
	machdesc.high_memory = kparams->high_memory;
	machdesc.kimage_vaddr = kparams->kimage_vaddr;
	machdesc.modules_start = kparams->modules_start;
	machdesc.modules_end = kparams->modules_end;
	machdesc.vmalloc_start = kparams->vmalloc_start;
	machdesc.vmalloc_end = kparams->vmalloc_end;
	machdesc.master_page_table = kparams->master_page_table;

	nhdr->p_filesz += notesize64(&notes);
	return storenote64(&notes, bufp);
}

static uint8_t *mrdump_core64_write_vmcoreinfo(const struct mrdump_control_block *mrdump_cb, struct elf64_phdr *nhdr, uint8_t *bufp)
{
	struct memelfnote notes;
	const struct mrdump_machdesc *kparams = &mrdump_cb->machdesc;
	char vmcoreinfo[512];

	memset(vmcoreinfo, 0, sizeof(vmcoreinfo));

	notes.name = "VMCOREINFO";
	notes.type = 0;
	notes.datasz = 0;
	notes.data = &vmcoreinfo;
	snprintf(vmcoreinfo, sizeof(vmcoreinfo),
		 "PAGESIZE=4096\n"
		 "NUMBER(kimage_voffset)=0x%llx\n"
		 "SYMBOL(_stext)=0x%llx\n"
		 "NUMBER(VA_BITS)=%d\n"
		 "NUMBER(PHYS_OFFSET)=0x%llx\n",
		 (uint64_t)kparams->kimage_voffset,
		 (uint64_t)kparams->kimage_stext_real,
		 39,
		 (uint64_t)kparams->phys_offset);
	notes.datasz = strlen(vmcoreinfo);

	nhdr->p_filesz += notesize64(&notes);
	return storenote64(&notes, bufp);
}

static uint8_t *mrdump_core64_write_cb(const struct mrdump_control_block *mrdump_cb, struct elf64_phdr *nhdr, uint8_t *bufp)
{
	struct memelfnote notes;
	uint64_t mrdump_cb_paddr = (uint64_t)(uintptr_t)mrdump_cb;

	notes.name = MRDUMP_GO_DUMP;
	notes.type = NT_MRDUMP_CBLOCK;
	notes.datasz = sizeof(mrdump_cb_paddr);
	notes.data = &mrdump_cb_paddr;

	nhdr->p_filesz += notesize64(&notes);
	return storenote64(&notes, bufp);
}

static void mrdump_core64_header_init(const struct mrdump_control_block *mrdump_cb, const struct kzip_addlist *memlist)
{
	struct elf64_phdr *nhdr, *phdr;
	struct elf64_hdr *elf;
	off_t offset = 0;
	const struct mrdump_machdesc *kparams = &mrdump_cb->machdesc;

	uint8_t *bufp = (uint8_t *)(uintptr_t)memlist[0].address;

	elf = (struct elf64_hdr *) bufp;
	bufp += sizeof(struct elf64_hdr);
	offset += sizeof(struct elf64_hdr);

	nhdr = (struct elf64_phdr *) bufp;
	bufp += sizeof(struct elf64_phdr);
	offset += sizeof(struct elf64_phdr);
	memset(nhdr, 0, sizeof(struct elf64_phdr));
	nhdr->p_type = PT_NOTE;

	unsigned long long foffset = MRDUMP_CORE_HEADER_SIZE;
	int i;
	for (i = 1; memlist[i].address != 0;i++) {
		phdr = (struct elf64_phdr *) bufp;
		bufp += sizeof(struct elf64_phdr);
		offset += sizeof(struct elf64_phdr);

		phdr->p_type    = PT_LOAD;
		phdr->p_flags   = PF_R|PF_W|PF_X;
		phdr->p_offset  = foffset;
		phdr->p_vaddr   = 0;
		phdr->p_paddr   = memlist[i].address;
		phdr->p_filesz  = memlist[i].size;
		phdr->p_memsz   = memlist[i].size;
		phdr->p_align   = 0;

		foffset += phdr->p_filesz;
	}

	mrdump_elf_setup_eident(elf->e_ident, ELFCLASS64);
	mrdump_elf_setup_elfhdr(elf, EM_AARCH64, struct elf64_hdr, struct elf64_phdr, i);

	nhdr->p_offset = offset;

	/* NT_PRPSINFO */
	struct elf_prpsinfo64 prpsinfo;
	struct memelfnote notes;
	/* set up the process info */
	notes.name = CORE_STR;
	notes.type = NT_PRPSINFO;
	notes.datasz = sizeof(struct elf_prpsinfo64);
	notes.data = &prpsinfo;

	memset(&prpsinfo, 0, sizeof(struct elf_prpsinfo64));
	prpsinfo.pr_state = 0;
	prpsinfo.pr_sname = 'R';
	prpsinfo.pr_zomb = 0;
	prpsinfo.pr_gid = prpsinfo.pr_uid = mrdump_cb->crash_record.fault_cpu + 1;
	strlcpy(prpsinfo.pr_fname, "vmlinux", sizeof(prpsinfo.pr_fname));
	strlcpy(prpsinfo.pr_psargs, "vmlinux", ELF_PRARGSZ);

	nhdr->p_filesz += notesize64(&notes);
	bufp = storenote64(&notes, bufp);

	bufp = mrdump_core64_write_machdesc(mrdump_cb, nhdr, bufp);
	bufp = mrdump_core64_write_vmcoreinfo(mrdump_cb, nhdr, bufp);

	/* Store pre-cpu backtrace */
	bufp = mrdump_core64_write_cpu_note(mrdump_cb, mrdump_cb->crash_record.fault_cpu, nhdr, bufp);
	for (unsigned int cpu = 0; cpu < kparams->nr_cpus; cpu++) {
		if (cpu != mrdump_cb->crash_record.fault_cpu) {
			bufp = mrdump_core64_write_cpu_note(mrdump_cb, cpu, nhdr, bufp);
		}
	}

	/* store mrdump control block */
	bufp = mrdump_core64_write_cb(mrdump_cb, nhdr, bufp);
}

void mrdump_core_header_init(const struct mrdump_control_block *kparams, const struct kzip_addlist *memlist)
{
	if (kparams->machdesc.page_offset <= 0xffffffffULL) {
		voprintf_info("32b kernel detected\n");
		mrdump_core32_header_init(kparams, memlist);
	} else {
		voprintf_info("64b kernel detected\n");
		mrdump_core64_header_init(kparams, memlist);
	}
}
