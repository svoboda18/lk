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

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "aee.h"
#include "mrdump_private.h"

/* mdrump string file to uart log*/
/* #define DEBUG_MRDUMP_PRINTF */

#define MRDUMP_STR_BUFF_LEN (1024*100) /* 100Kib*/
static struct _mrdump_string_buf {
	char* buf;
	int len;
	int wpos;
} mrdump_string_buf = {
	.buf = NULL,
	.len = 0,
	.wpos = 0
};

extern int g_is_64bit_kernel;

static void init_mrdump_string_buf(void)
{
	dprintf(CRITICAL, "%s\n", __func__);

	if (mrdump_string_buf.buf) {
		dprintf(CRITICAL, "[ERROR]MT-RAMDUMP: mrdump_string_buf has already initialized(mrdump_string_wbuf.buf!=NULL)\n");
		return;
	}
	mrdump_string_buf.buf = malloc(MRDUMP_STR_BUFF_LEN);
	if (!mrdump_string_buf.buf) {
		dprintf(CRITICAL, "[ERROR]MT-RAMDUMP: faild to allocate mrdump_string_buf\n");
		return;
	}
	memset(mrdump_string_buf.buf, 0, MRDUMP_STR_BUFF_LEN);
	mrdump_string_buf.len = MRDUMP_STR_BUFF_LEN;
	mrdump_string_buf.wpos = 0;
}

static void uninit_mrdump_string_buf(void)
{
	dprintf(CRITICAL, "%s\n", __func__);

	if(mrdump_string_buf.buf)
		free(mrdump_string_buf.buf);
	memset(&mrdump_string_buf, 0, sizeof(mrdump_string_buf));
}

static int mrdump_vsprintf(const char *fmt, va_list ap)
{
	int wcnt, wmax;
	char* buf;

	if(mrdump_string_buf.buf == NULL)
		return 0;

	if(mrdump_string_buf.len<=mrdump_string_buf.wpos) {
		dprintf(CRITICAL, "Error: exceed mrdump_string_buf(%d,%d)\n", mrdump_string_buf.len, mrdump_string_buf.wpos);
		return 0;
	}

	buf = &mrdump_string_buf.buf[mrdump_string_buf.wpos];
	wmax = mrdump_string_buf.len-mrdump_string_buf.wpos;

	wcnt = vsnprintf(buf, wmax, fmt, ap);
	mrdump_string_buf.wpos += wcnt;

#ifdef DEBUG_MRDUMP_PRINTF /* cmm to uart log */
	dputs(CRITICAL,buf);
#endif

	return wcnt;
}

static int mrdump_printf(const char *fmt, ...)
{
	int w;
	va_list args;
	va_start(args, fmt);
	w = mrdump_vsprintf(fmt, args);
	va_end(args);
	return w;
}

static struct mrdump_machdesc* aee_get_machdesc_from_cb(struct mrdump_control_block *mrdump_cblock)
{
	if (mrdump_cblock)
		return &mrdump_cblock->machdesc;

	dprintf(CRITICAL, "Error: aee_get_machdesc_from_cb\n");
	return NULL;
}

static struct mrdump_ksyms_param* aee_get_ksyms_from_cb(struct mrdump_control_block *mrdump_cblock)
{
	struct mrdump_machdesc* mach;

	if (mrdump_cblock) {
		mach = &mrdump_cblock->machdesc;
		if(mach)
			return &mach->kallsyms;
	}

	dprintf(CRITICAL, "Error: aee_get_ksyms_from_cb\n");
	return NULL;
}

static void print_file_dialog_cmm(char* title, char* msg, char* file_path)
{
	mrdump_printf("	dialog.view\n");
	mrdump_printf("	(\n");
	mrdump_printf("          header \"%s\"\n", title);
	mrdump_printf("          pos 0. 0. 30. 3.\n");
	mrdump_printf("          box \"%s\"\n", msg);
	mrdump_printf("          pos 1. 1. 20. 1.\n");
	mrdump_printf("%s:     defedit \"\" \"\"\n", file_path);
	mrdump_printf("          pos 22. 1. 7. 1.\n");
	mrdump_printf("          button \"Browse...\"\n");
	mrdump_printf("          (\n");
	mrdump_printf("            dialog.file \"*.*\"\n");
	mrdump_printf("            entry %%line &file\n");
	mrdump_printf("            dialog.set %s \"&file\"\n", file_path);
	mrdump_printf("          )\n");
	mrdump_printf("          pos 6. 3. 7. 1.\n");
	mrdump_printf("          defbutton \"Ok\"\n");
	mrdump_printf("          (            \n");
	mrdump_printf("            &%s=dialog.string(%s)\n", file_path, file_path);
	mrdump_printf("            continue\n");
	mrdump_printf("          )\n");
	mrdump_printf("          pos 17. 3. 7. 1.\n");
	mrdump_printf("          button \"Cancel\"  \"continue\"\n");
	mrdump_printf("	)\n");
	mrdump_printf("	STOP\n");
	mrdump_printf("	dialog.end\n");
}

extern bool ram_console_get_kaslr_offset(uint64_t* kaslr_offset);
static void print_pre_cmm(struct mrdump_control_block *mrdump_cblock)
{
	struct mrdump_machdesc* machd = aee_get_machdesc_from_cb(mrdump_cblock);
	uint64_t kaslr_offset = 0;
	bool kaslr_valid;
	kaslr_valid = ram_console_get_kaslr_offset(&kaslr_offset);

	mrdump_printf("B::AREA\n");

	mrdump_printf("local &vmlinux_file\n");
	mrdump_printf("&vmlinux_file=\".\\vmlinux\"\n");
	mrdump_printf("IF OS.FILE(\"&vmlinux_file\")!=TRUE()\n");
	mrdump_printf("(\n");
	print_file_dialog_cmm("Load Vmlinux", "File path", "vmlinux_file");
	mrdump_printf(")\n\n");

	mrdump_printf("local &ramdump_elf_core_file\n");
	mrdump_printf("&ramdump_elf_core_file=\".\\SYS_COREDUMP\"\n");
	mrdump_printf("IF OS.FILE(\"&ramdump_elf_core_file\")!=TRUE()\n");
	mrdump_printf("(\n");
	print_file_dialog_cmm("Load RAMDUMP(Core ELF)", "File path", "ramdump_elf_core_file");
	mrdump_printf(")\n\n");

	/*T32 cmm: pre-setting*/
	mrdump_printf("sys.res\n");
	mrdump_printf("sys.cpu %s\n", g_is_64bit_kernel ? "CortexA53":"CortexA7MPCore");
	mrdump_printf("sys.config.cn %d\n", machd->nr_cpus);
	mrdump_printf("core.num %d\n", machd->nr_cpus);
	mrdump_printf("sys.o mmuspaces on\n");
	mrdump_printf("sys.u\n");
	mrdump_printf("title os.pwd()\n\n");

	mrdump_printf("d.load.e &vmlinux_file 0x%llx\n", kaslr_offset);
	mrdump_printf("&vmlinux_banner=V.STRING(linux_banner)\n");
	mrdump_printf("&vmlinux_banner_len=STRing.LENgth(\"&vmlinux_banner\")\n");
	mrdump_printf("&vmlinux_build_time=STRing.SPLIT(V.STRING(&linux_banner[200]),\"#\", -1)\n");

	mrdump_printf("d.load.e &ramdump_elf_core_file /nc /ny /physload\n\n");
	if(kaslr_valid)
		mrdump_printf("PRINT \"OK!, kaslr_offset is valid\"\n");
	else
		mrdump_printf("PRINT %%ERROR \"kaslr_offset IS NOT valid\"\n");
	mrdump_printf("\n");
}

static void print_post_cmm(struct mrdump_control_block *mrdump_cblock)
{
	struct mrdump_crash_record* cr;
	struct mrdump_machdesc* mach;
	if (mrdump_cblock) {
		mach = &mrdump_cblock->machdesc;
		cr = &mrdump_cblock->crash_record;
	}
	else {
		mrdump_printf(";error mrdump_core_context_to_klog : mrdump_cblock=NULL\n");
		return;
	}

	mrdump_printf("; select fault cpu\n");
	mrdump_printf("core.select %u\n", cr->fault_cpu);

	/* the common address range for all processes and is everything above the process address range
	whole kernel address space including module */
	if (g_is_64bit_kernel) {
		mrdump_printf("mmu.format linuxswap3 swapper_pg_dir 0x%016llx--0xffffffffffffffff 0x%016llx\n",
		mach->page_offset, mach->dram_start);
		/* 0xFFFFFF8000000000--0xFFFFFFFFFFFFFFFF */
		mrdump_printf("trans.common 0x%016llx--0xffffffffffffffff \n",
		MIN(mach->page_offset, mach->modules_start));
	}
	else {
		mrdump_printf("mmu.format linuxswap3 swapper_pg_dir 0x%08x--0xffffffff 0x%x\n",
		(uint32_t)(mach->page_offset & 0xffffffff), (uint32_t)(mach->dram_start & 0xffffffff));
		/* trans.common 0xBF000000--0xFFFFFFFF */
		mrdump_printf("trans.common 0x%08x--0xffffffff \n",
		(uint32_t)(MIN(mach->page_offset, mach->modules_start) & 0xffffffff));
	}
	mrdump_printf("trans.tw on\n");
	mrdump_printf("trans.on\n");
	mrdump_printf("mmu.scan\n\n");
	/* show kernel pagetable */
	mrdump_printf("mmu.list.pagetable 0x%llx\n\n", mach->page_offset);

	if (g_is_64bit_kernel) {
		mrdump_printf("; load the awareness for Linux-3.x on ARM\n");
		mrdump_printf("TASK.CONFIG ~~/demo/arm64/kernel/linux/linux-3.x/linux3.t32\n");
		mrdump_printf("; load Linux menu:\n");
		mrdump_printf("MENU.ReProgram ~~/demo/arm64/kernel/linux/linux-3.x/linux.men\n");
		mrdump_printf("task.dmesg\n\n");
	}
	else {
		mrdump_printf("; load the awareness for Linux-3.x on ARM\n");
		mrdump_printf("TASK.CONFIG ~~/demo/arm/kernel/linux/linux-3.x/linux3.t32\n");
		mrdump_printf("; load Linux menu:\n");
		mrdump_printf("MENU.ReProgram ~~/demo/arm/kernel/linux/linux-3.x/linux.men\n");
		mrdump_printf("task.dmesg\n\n");
	}
}

static void print_verify_view_cmm(struct mrdump_crash_record* cr)
{
	/* verify linux_banner */
	mrdump_printf("&ramdump_banner=V.STRING(linux_banner)\n");
	mrdump_printf("&t32_max_strlen=255.\n");
	mrdump_printf("IF &vmlinux_banner_len>=&t32_max_strlen\n");
	mrdump_printf("(\n");
	mrdump_printf("\t&ramdump_build_time=STRing.SPLIT(V.STRING(&linux_banner[200]),\"#\", -1)\n\n");

	mrdump_printf("\tPRINT %%ERROR \"vmlinux banner : [#&vmlinux_build_time] &vmlinux_banner\"\n");
	mrdump_printf("\tPRINT %%ERROR \"ramdump banner : [#&ramdump_build_time] &ramdump_banner\"\n\n");

	mrdump_printf("\tIF (\"&vmlinux_banner\"!=\"&ramdump_banner\")\n");
	mrdump_printf("\t(\n");
	mrdump_printf("\t	PRINT %%ERROR \"!!!!!!!!! No maching vmlinux symbol and dump binary...\"\n");
	mrdump_printf("\t	PRINT %%ERROR \"or check your mmu settting...\"\n");
	mrdump_printf("\t	ENDDO\n");
	mrdump_printf("\t)\n\n");

	mrdump_printf("\tIF (\"&ramdump_build_time\"!=\"&vmlinux_build_time\")\n");
	mrdump_printf("\t(\n");
	mrdump_printf("\t	PRINT %%ERROR \"!!!!!!!!! No maching build time !!!!!!!!!\"\n");
	mrdump_printf("\t	PRINT %%ERROR \"check binary and vmlinux build time\"\n");
	mrdump_printf("\t	PRINT %%ERROR \"Symbole build time : #&vmlinux_build_time\"\n");
	mrdump_printf("\t	PRINT %%ERROR \"RAMDUM build time  : #&ramdump_build_time\"\n");
	mrdump_printf("\t)\n\n");
	mrdump_printf(")\n");

	mrdump_printf("ELSE\n");
	mrdump_printf("(\n");
	mrdump_printf("\tPRINT %%ERROR \"vmlinux banner : &vmlinux_banner\"\n");
	mrdump_printf("\tPRINT %%ERROR \"ramdump banner : &ramdump_banner\"\n");
	mrdump_printf("\tIF (\"&vmlinux_banner\"!=\"&ramdump_banner\")\n");
	mrdump_printf("\t(\n");
	mrdump_printf("\t\tPRINT %%ERROR \"!!!!!!!!! No maching vmlinux symbol and dump binary...\"\n");
	mrdump_printf("\t\tPRINT %%ERROR \"or check your mmu settting...\"\n");
	mrdump_printf("\t\tENDDO\n");
	mrdump_printf("\t)\n");
	mrdump_printf(")\n");

	/* windows layout */
	mrdump_printf(";y.l.sec\n");
	mrdump_printf("l\nr\nf\n");
	mrdump_printf("WinPOS 0.0 0.0 100. 6. 0. 0. W000\n");
	mrdump_printf("AREA\n");
	mrdump_printf("ENDDO\n");
}

static void print_arm64regs_cmm(struct mrdump_crash_record* cr, int nr_cpu)
{
	char msg[128+32];
	struct arm64_ctrl_regs* pcore_sysr;
	uint64_t* pcore_cpur;

	int i, cpu;
	if(!cr)
		return;

	snprintf(msg, sizeof(msg), ";%s\n", cr->msg);
	mrdump_printf(msg);

	for (cpu=0; cpu<nr_cpu; cpu++) {
		mrdump_printf("; CPU%d's Registers\n", cpu);
		mrdump_printf("core.select %d\n", cpu);

		/* print cpu registers */
		pcore_cpur = &cr->cpu_regs[cpu].arm64_regs[0];
		for(i=0; i<31; i++) {
			mrdump_printf("R.S X%d 0x%016llx\n", i, pcore_cpur[i]);
		}
		mrdump_printf("R.S SP 0x%016llx\n", pcore_cpur[i++]);
		mrdump_printf("R.S PC 0x%016llx\n", pcore_cpur[i++]);
		mrdump_printf("R.S CPSR 0x%llx\n", pcore_cpur[i++]/*pstate*/);
		mrdump_printf("; END CPU Regs\n");

		/*MMU registers*/
		pcore_sysr = &cr->cpu_creg[cpu].arm64_creg;
		mrdump_printf("; CPU%d's MMU & System Control Registers\n", cpu);

		mrdump_printf("PER.Set SPR:0x30200 %%QUAD 0x%016llx ;TTBR0_EL1\n", pcore_sysr->ttbr0_el1);
		mrdump_printf("PER.Set SPR:0x34200 %%QUAD 0x%016llx ;TTBR0_EL2\n", pcore_sysr->ttbr0_el2);
		mrdump_printf("PER.Set SPR:0x36200 %%QUAD 0x%016llx ;TTBR0_EL3\n", pcore_sysr->ttbr0_el3);

		mrdump_printf("PER.Set SPR:0x30201 %%QUAD 0x%016llx ;TTBR1_EL1\n", pcore_sysr->ttbr1_el1);

		mrdump_printf("PER.Set SPR:0x30100 %%QUAD 0x%08x ;SCTLR_EL1\n", pcore_sysr->sctlr_el1);
		mrdump_printf("PER.Set SPR:0x34100 %%QUAD 0x%08x ;SCTLR_EL2\n", pcore_sysr->sctlr_el2);
		mrdump_printf("PER.Set SPR:0x36100 %%QUAD 0x%08x ;SCTLR_EL3\n", pcore_sysr->sctlr_el3);

		mrdump_printf("PER.Set SPR:0x30202 %%QUAD 0x%016llx ;TCR_EL1\n", pcore_sysr->tcr_el1);
		mrdump_printf("PER.Set SPR:0x34202 %%QUAD 0x%016llx ;TCR_EL2\n", pcore_sysr->tcr_el2);
		mrdump_printf("PER.Set SPR:0x36202 %%QUAD 0x%016llx ;TCR_EL3\n", pcore_sysr->tcr_el3);

		for(i=0; i<4; i++) {
			mrdump_printf("R.S sp_el%d 0x%016llx\n", i, pcore_sysr->sp_el[i]);
		}
		mrdump_printf("; END MMU & SCTLR\n");
	}
}

static void print_arm32regs_cmm(struct mrdump_crash_record* cr, int nr_cpu)
{
	char msg[128+32];
	struct arm32_ctrl_regs* pcore_sysr;
	uint32_t * pcore_cpur;

	int i, cpu;
	if(!cr)
		return;

	snprintf(msg, sizeof(msg), ";%s\n", cr->msg);
	mrdump_printf(msg);

	for (cpu=0; cpu<nr_cpu; cpu++) {
		mrdump_printf("; CPU%d's Registers\n", cpu);
		mrdump_printf("core.select %d\n", cpu);

		/* print cpu registers */
		pcore_cpur = &cr->cpu_regs[cpu].arm32_regs[0];
		for(i=0; i<15; i++) {
			mrdump_printf("R.S r%d 0x%08x\n", i, pcore_cpur[i]);
		}
		i=15;
		mrdump_printf("R.S PC 0x%08x\n", pcore_cpur[i++]);
		mrdump_printf("R.S CPSR 0x%08x\n", pcore_cpur[i++]/*pstate*/);
		mrdump_printf("; END CPU Regs\n");

		/*MMU registers*/
		pcore_sysr = &cr->cpu_creg[cpu].arm32_creg;
		mrdump_printf("; CPU%d's MMU & System Control Registers\n", cpu);
		mrdump_printf("PER.Set.simple C15:0x1 %%Long 0x%08x ;SCTRL\n", pcore_sysr->sctlr);
		mrdump_printf("PER.Set.simple C15:0x202 %%Long 0x%08x ;TTBCR\n",  (uint32_t)pcore_sysr->ttbcr);
		mrdump_printf("PER.Set.simple C15:0x2 %%Long 0x%08x ;TTBR0\n",  (uint32_t)pcore_sysr->ttbr0);
		mrdump_printf("PER.Set.simple C15:0x102 %%Long 0x%08x ;TTBR1\n",  (uint32_t)pcore_sysr->ttbr1);
		mrdump_printf("; END MMU & SCTLR\n");
	}
}

static void print_mrdump_machdesc(struct mrdump_control_block *mrdump_cblock)
{
	struct mrdump_machdesc* mach;
	struct mrdump_ksyms_param* kallsym;
	char tag[5];
	if (mrdump_cblock) {
		mach = &mrdump_cblock->machdesc;
		kallsym = &mach->kallsyms;
	}
	else {
		mrdump_printf(";error mrdump_core_context_to_klog : mrdump_cblock=NULL\n");
		return;
	}

	mrdump_printf(";\n;*** mrdump_machdesc ***\n");
	mrdump_printf(";nr_cpus=%u\n", mach->nr_cpus);

	mrdump_printf(";page_offset = 0x%llx\n", mach->page_offset);
	mrdump_printf(";high_memory = 0x%llx\n", mach->high_memory);

	mrdump_printf(";kimage_vaddr = 0x%llx\n", mach->kimage_vaddr);
	mrdump_printf(";dram_start = 0x%llx\n",  mach->dram_start);
	mrdump_printf(";dram_end = 0x%llx\n", mach->dram_end);
	mrdump_printf(";kimage_stext = 0x%llx\n", mach->kimage_stext);
	mrdump_printf(";kimage_etext = 0x%llx\n", mach->kimage_etext);
	mrdump_printf(";kimage_stext_real = 0x%llx\n", mach->kimage_stext_real);
	mrdump_printf(";kimage_voffset = 0x%llx\n", mach->kimage_voffset);
	mrdump_printf(";kimage_sdata = 0x%llx\n", mach->kimage_sdata);
	mrdump_printf(";kimage_edata = 0x%llx\n", mach->kimage_edata);

	mrdump_printf(";vmalloc_start = 0x%llx\n", mach->vmalloc_start);
	mrdump_printf(";vmalloc_end = 0x%llx\n", mach->vmalloc_end);

	mrdump_printf(";module_start = 0x%llx\n", mach->modules_start);
	mrdump_printf(";module_end = 0x%llx\n", mach->modules_end);

	mrdump_printf(";phys_offset = 0x%llx\n",  mach->phys_offset);
	mrdump_printf(";master_page_table = 0x%llx\n", mach->master_page_table);

	mrdump_printf(";memmap = 0x%llx\n", mach->memmap);

	mrdump_printf(";dfdmem_pa = 0x%llx\n", mach->dfdmem_pa);
	memcpy(tag, kallsym->tag,4);
	tag[4] = '\0';
	mrdump_printf(";ksyms.tag=%s\n", tag);

	mrdump_printf(";ksyms.flag=0x%x(%s)\n", kallsym->flag, kallsym->flag==1?"KSYM_32":"KSYM_64");
	mrdump_printf(";ksyms.crc=0x%x\n", kallsym->crc);
	mrdump_printf(";ksyms.start_addr=0x%llx\n", kallsym->start_addr);
	mrdump_printf(";ksyms.size=0x%x\n", kallsym->size);
	mrdump_printf(";ksyms.address_off=0x%x\n", kallsym->addresses_off);
	mrdump_printf(";ksyms.num_syms_off=0x%x\n", kallsym->num_syms_off);
	mrdump_printf(";ksyms.names_off=0x%x\n", kallsym->names_off);
	mrdump_printf(";ksyms.markers_off=0x%x\n",  kallsym->markers_off);
	mrdump_printf(";ksyms.token_table_off=0x%x\n", kallsym->token_table_off);
	mrdump_printf(";ksyms.token_index_off=0x%x\n", kallsym->token_index_off);
}

static void gen_cmm(struct mrdump_control_block *mrdump_cblock)
{
	struct mrdump_crash_record *crash_record;

	if (mrdump_cblock) {
		crash_record = &mrdump_cblock->crash_record;
	}
	else {
		dprintf(CRITICAL, "error mrdump_core_context_to_klog : mrdump_cblock=NULL\n");
		return;
	}
	dprintf(CRITICAL, "%s:mrdump_cblock=%p, crach_record=%p\n",__func__, mrdump_cblock, crash_record);
	dprintf(CRITICAL, "crash_recode msg: %s\n", crash_record->msg);
#if 0 /* show mem layout */
	print_mrdump_machdesc(mrdump_cblock);
#endif
	mrdump_printf(";******************************************************\n");
	mrdump_printf(";* CMM for Linux arch=%s [%s]*\n",
	g_is_64bit_kernel ? "arm64":"arm(32)", crash_record->msg);
	mrdump_printf(";******************************************************\n");

	print_pre_cmm(mrdump_cblock);
	if(g_is_64bit_kernel)
		print_arm64regs_cmm(&mrdump_cblock->crash_record, mrdump_cblock->machdesc.nr_cpus);
	else
		print_arm32regs_cmm(&mrdump_cblock->crash_record, mrdump_cblock->machdesc.nr_cpus);

	mrdump_printf("; select fault cpu\n");
	mrdump_printf("core.select %u\n", mrdump_cblock->crash_record.fault_cpu);

	print_post_cmm(mrdump_cblock);
	print_verify_view_cmm(&mrdump_cblock->crash_record);

	mrdump_printf(";******************************************************\n");
	mrdump_printf(";*                    End CMM                          \n");
	mrdump_printf(";******************************************************\n");
}

static void mrdump_cmm_gen(struct mrdump_control_block *mrdump_cblock)
{
	init_mrdump_string_buf();
	gen_cmm(mrdump_cblock);
}

struct kzip_addlist *mrdump_memlist_fill_cmm(struct mrdump_control_block *mrdump_cblock)
{
	if (!mrdump_cblock)
		return NULL;

	mrdump_cmm_gen(mrdump_cblock);
	if (mrdump_string_buf.buf && mrdump_string_buf.wpos > 0)
	{
		struct kzip_addlist *memlist = malloc(sizeof(struct kzip_addlist) * 2);
		if (memlist == NULL)
			return NULL;

		memlist[0].address = (uint64_t)(uintptr_t) mrdump_string_buf.buf;
		memlist[0].size = mrdump_string_buf.wpos;
		memlist[0].type = MEM_NO_MAP;
		memlist[1].address = 0;
		memlist[1].size = 0;
		memlist[1].type = MEM_NO_MAP;
		return memlist;
	}
	return NULL;
}

void mrdump_memlist_free_cmm(struct kzip_addlist *memlist)
{
	uninit_mrdump_string_buf();
	free(memlist);
}
