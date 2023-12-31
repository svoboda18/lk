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

#ifndef _MT_SCP_EXCEP_H_
#define _MT_SCP_EXCEP_H_

typedef short   __s16;
typedef int __s32;
typedef long long __s64;
typedef unsigned short  __u16;
typedef unsigned int    __u32;
typedef unsigned long long __u64;

struct TaskContextType {
	unsigned int r0;
	unsigned int r1;
	unsigned int r2;
	unsigned int r3;
	unsigned int r4;
	unsigned int r5;
	unsigned int r6;
	unsigned int r7;
	unsigned int r8;
	unsigned int r9;
	unsigned int r10;
	unsigned int r11;
	unsigned int r12;
	unsigned int sp;              /* after pop r0-r3, lr, pc, xpsr                   */
	unsigned int lr;              /* lr before exception                             */
	unsigned int pc;              /* pc before exception                             */
	unsigned int psr;             /* xpsr before exeption                            */
	unsigned int control;         /* nPRIV bit & FPCA bit meaningful, SPSEL bit = 0  */
	unsigned int exc_return;      /* current lr                                      */
	unsigned int msp;             /* msp                                             */
};

#define CRASH_SUMMARY_LENGTH 12
#define CRASH_MEMORY_HEADER_SIZE  (8 * 1024)
#define CRASH_MEMORY_OFFSET  (0x800)
#define CRASH_MEMORY_LENGTH  (512 * 1024 - CRASH_MEMORY_OFFSET)
#define CRASH_DRAM_OFFSET   (0x80000)
#define CRASH_DRAM_LENGTH   (0x100000)

#define CRASH_REG_SIZE  (9 * 32)

#define ELF_NGREGS 18
#define ELF_PRARGSZ (80)
#define EM_ARM      40  /* ARM 32 bit */
#define ELF_CORE_EFLAGS 0
#define CORE_STR "CORE"

#define EI_NIDENT   16

struct elf32_hdr {
	unsigned char e_ident[EI_NIDENT];
	__u16    e_type;
	__u16    e_machine;
	__u32    e_version;
	__u32    e_entry;
	__u32 e_phoff;
	__u32 e_shoff;
	__u32    e_flags;
	__u16    e_ehsize;
	__u16    e_phentsize;
	__u16    e_phnum;
	__u16    e_shentsize;
	__u16    e_shnum;
	__u16    e_shstrndx;
};

struct elf32_phdr {
	__u32    p_type;
	__u32 p_offset;
	__u32    p_vaddr;
	__u32    p_paddr;
	__u32    p_filesz;
	__u32    p_memsz;
	__u32    p_flags;
	__u32    p_align;
};

#define EI_CLASS    4
#define EI_DATA     5
#define EI_VERSION  6
#define EI_OSABI    7
#define EI_PAD      8

#define ELFCLASS32  1

#define ELFDATA2LSB 1

#define EV_CURRENT  1

#define ELFOSABI_NONE   0

#define NT_PRSTATUS 1
#define NT_PRPSINFO 3

struct elf32_note {
	__u32    n_namesz;
	__u32    n_descsz;
	__u32    n_type;
};

/* scp reg dump*/
struct scp_reg_dump_list {
	uint32_t scp_reg_magic;
	uint32_t ap_resource;
	uint32_t bus_resource;
	uint32_t slp_protect;
	uint32_t cpu_sleep_status;
	uint32_t clk_sw_sel;
	uint32_t clk_enable;
	uint32_t clk_high_core;
	uint32_t debug_wdt_sp;
	uint32_t debug_wdt_lr;
	uint32_t debug_wdt_psp;
	uint32_t debug_wdt_pc;
	uint32_t debug_addr_s2r;
	uint32_t debug_addr_dma;
	uint32_t debug_addr_spi0;
	uint32_t debug_addr_spi1;
	uint32_t debug_addr_spi2;
	uint32_t debug_bus_status;
	uint32_t debug_infra_mon;
	uint32_t infra_addr_latch;
	uint32_t ddebug_latch;
	uint32_t pdebug_latch;
	uint32_t pc_value;
	uint32_t scp_reg_magic_end;
};

struct scp_dump_header_list {
	uint32_t scp_head_magic;
	struct scp_region_info_st scp_region_info;
	uint32_t scp_head_magic_end;
};

struct MemoryDump {
	struct elf32_hdr elf;
	struct elf32_phdr nhdr;
	struct elf32_phdr phdr;
	char notes[CRASH_MEMORY_HEADER_SIZE-sizeof(struct elf32_hdr)
		-sizeof(struct elf32_phdr)-sizeof(struct elf32_phdr)
		-sizeof(struct scp_dump_header_list)];
	/* ram dump total header size(elf+nhdr+phdr+header)
	 * must be fixed at CRASH_MEMORY_HEADER_SIZE
	 */
	struct scp_dump_header_list scp_dump_header;
	/*scp sram*/
	char memory[CRASH_MEMORY_LENGTH];
	/*scp reg*/
	struct scp_reg_dump_list scp_reg_dump;
};

enum scp_core_id {
	SCP_A_ID = 0,
	SCP_CORE_TOTAL = 1,
};


#define ET_CORE   4
#define AED_LOG_PRINT_SIZE  SZ_16K
#define SCP_LOCK_OFS    0xE0
#define SCP_TCM_LOCK_BIT    (1 << 20)

enum scp_excep_id {
	EXCEP_LOAD_FIRMWARE = 0,
	EXCEP_RESET,
	EXCEP_BOOTUP,
	EXCEP_RUNTIME,
	SCP_NR_EXCEP,
};

void scp_aed(enum scp_excep_id type, enum scp_core_id id);
void scp_aed_reset(enum scp_excep_id type, enum scp_core_id id);
void scp_aed_reset_inplace(enum scp_excep_id type, enum scp_core_id id);
void scp_get_log(enum scp_core_id id);
char *scp_get_last_log(enum scp_core_id id);
void scp_A_dump_regs(void);
uint32_t scp_dump_pc(void);
uint32_t scp_dump_lr(void);
void aed_scp_exception_api(const int *log, int log_size, const int *phy,
                           int phy_size, const char *detail, const int db_opt);
void scp_excep_cleanup(void);
int scp_crash_dump(void *crash_buffer);

enum { r0, r1, r2, r3, r12, lr, pc, psr};

#endif

