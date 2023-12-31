#include <arch/arm/mmu.h>
#include <debug.h>
#include <dev/aee_platform_debug.h>
#include <libfdt.h>
#ifdef MTK_SMC_ID_MGMT
#include <mtk_secure_api.h>
#endif
#include <platform/boot_mode.h>
#include <platform/mt_typedefs.h>
#include <platform/plat_atf_dbg_info.h>
#include <sys/types.h>

#ifdef MBLOCK_LIB_SUPPORT
#include <mblock.h>
#endif

/* default support ATF, define an empty function in ARMv7 chip family */
#pragma weak atf_log_init

#ifndef MTK_SMC_ID_MGMT
#define MTK_SIP_LK_DUMP_ATF_LOG_INFO_AARCH32	0x8200010A
#endif

#define ATF_CRASH_MAGIC_NO			0xdead1abf
#define ATF_LAST_LOG_MAGIC_NO			0x41544641
#define ATF_DUMP_DONE_MAGIC_NO			0xd07ed07e
#define ATF_SMC_UNK				0xffffffff

#define INFO_LOG(fmt, args...) do {dprintf(INFO, fmt, ##args);} while (0)
#define ALWAYS_LOG(fmt, args...) do {dprintf(ALWAYS, fmt, ##args);} while (0)

extern BOOT_ARGUMENT *g_boot_arg;

static u64 atf_ramdump_addr;
static u64 atf_ramdump_size;

static uint32_t atf_log_buf_addr;
static uint32_t atf_log_buf_size;
static uint32_t atf_crash_flag_addr;

static void get_atf_ramdump_memory(void)
{
#if (defined(MTK_SMC_ID_MGMT) && !defined(MTK_DIS_ATF_RAM_DUMP))
	uint32_t address_hi, address_lo, size_hi, size_lo;
	u64 limit_addr = (u64)ATF_RAMDUMP_BUFFER_LIMIT_ADDR;
	u64 align_addr = (u64)ATF_RAMDUMP_BUFFER_ADDR_ALIGNMENT;

	atf_ramdump_size = ATF_RAMDUMP_BUFFER_SIZE;
	atf_ramdump_addr = mblock_reserve_ext(&g_boot_arg->mblock_info,
					(u64) atf_ramdump_size, (u64)align_addr, limit_addr, 0,
					"atf-ramdump-memory");

	if (atf_ramdump_addr) {
		address_hi = (atf_ramdump_addr >> 32) & 0xFFFFFFFF;
		address_lo = atf_ramdump_addr & 0xFFFFFFFF;
		size_hi = 0;
		size_lo = ATF_RAMDUMP_BUFFER_SIZE & 0xFFFFFFFF;

		mt_secure_call(MTK_SIP_RAM_DUMP_ADDR, address_hi, address_lo, size_hi, size_lo);
		ALWAYS_LOG("atf ram dump address hi:0x%x, adress lo:0x%x, size hi:%u, size lo:%u\n",
					address_hi, address_lo, size_hi, size_lo);
	} else {
		ALWAYS_LOG("Can't reserve atf-ramdump-memory, atf_ramdump_addr=0x%llx!\n",
					atf_ramdump_addr);
	}
#else
	atf_ramdump_size = 0;
	atf_ramdump_addr = 0;
	ALWAYS_LOG("Do not support atf-ramdump-memory, atf_ramdump_addr=0x%llx!\n",
					atf_ramdump_addr);
#endif
}

static uint32_t save_atf_log(u64 offset, int *len, CALLBACK dev_write)
{
	uint32_t datasize = 0;
#ifdef MTK_3LEVEL_PAGETABLE
	/* ATF log is located in DRAM, we must allocate it first */
	arch_mmu_map(ROUNDDOWN((uint64_t)atf_log_buf_addr, PAGE_SIZE), ROUNDDOWN((uint32_t)atf_log_buf_addr, PAGE_SIZE),
				MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA, ROUNDUP(atf_log_buf_size, PAGE_SIZE));
#endif
	*len = atf_log_buf_size;
	datasize = dev_write((void *)atf_log_buf_addr, *len);
	/* Clear ATF crash flag */
	*(uint32_t *)atf_crash_flag_addr = ATF_DUMP_DONE_MAGIC_NO;
	arch_clean_cache_range((addr_t)atf_crash_flag_addr, sizeof(uint32_t));

	dprintf(INFO, "ATF: dev_write:%u, atf_log_buf_addr:0x%x, atf_log_buf_size:%u, crash_flag:0x%x\n", datasize, atf_log_buf_addr, atf_log_buf_size, *(uint32_t *)atf_crash_flag_addr);
	return datasize;
}

static uint32_t save_atf_rdump(u64 offset, int *len, CALLBACK dev_write)
{
	uint32_t datasize = 0;
	u64 local_atf_ramdump_addr;
	u64 local_atf_ramdump_size;

	local_atf_ramdump_addr = atf_ramdump_addr;
	local_atf_ramdump_size = atf_ramdump_size;
#ifdef MTK_3LEVEL_PAGETABLE
	/* ATF log is located in DRAM, we must allocate it first */
	arch_mmu_map(ROUNDDOWN((uint64_t)local_atf_ramdump_addr, PAGE_SIZE),
				ROUNDDOWN((uint32_t)local_atf_ramdump_addr, PAGE_SIZE),
				MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
				ROUNDUP(local_atf_ramdump_size, PAGE_SIZE));
#endif
	*len = local_atf_ramdump_size;
	datasize = dev_write((void *)(uint32_t)local_atf_ramdump_addr, *len);

	dprintf(CRITICAL, "ATF: dev_write:%u, local_atf_ramdump_addr:0x%llx, local_atf_ramdump_size:0x%llx\n",
			datasize, local_atf_ramdump_addr, local_atf_ramdump_size);

	return datasize;
}

void atf_log_init(void)
{
#ifdef MTK_SMC_ID_MGMT
	uint32_t smc_id = MTK_SIP_LK_DUMP_ATF_LOG_INFO;
#else
	uint32_t smc_id = MTK_SIP_LK_DUMP_ATF_LOG_INFO_AARCH32;
#endif
	plat_atf_log_get = NULL;
	plat_atf_crash_get = NULL;
	plat_atf_rdump_get = save_atf_rdump;

	/* reserve ramdump memory and pass to ATF*/
	get_atf_ramdump_memory();

#ifdef MTK_SMC_ID_MGMT
	atf_log_buf_addr = mt_secure_call_ret3(smc_id, 0, 0, 0, 0, &atf_log_buf_size, &atf_crash_flag_addr);
#else
	__asm__ volatile("mov r0, %[smcid]\n"
			"smc #0x0\n"
			"mov %[addr], r0\n"
			"mov %[size], r1\n"
			"mov %[type], r2\n"
			:[addr]"=r"(atf_log_buf_addr), [size]"=r"(atf_log_buf_size),
			[type]"=r"(atf_crash_flag_addr):[smcid]"r"(smc_id):"cc",
			"r0", "r1" ,"r2", "r3");
#endif

	if(atf_log_buf_addr == ATF_SMC_UNK) {
		dprintf(CRITICAL, "LK Dump: atf_log_init not supported\n");
	} else {
		plat_atf_rdump_get = save_atf_rdump;
#ifdef MTK_3LEVEL_PAGETABLE
		arch_mmu_map(ROUNDDOWN((uint64_t)atf_crash_flag_addr, PAGE_SIZE),
					ROUNDDOWN((uint32_t)atf_crash_flag_addr, PAGE_SIZE),
					MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
					PAGE_SIZE);
#endif
		if(ATF_CRASH_MAGIC_NO == *(uint32_t *)atf_crash_flag_addr){
			dprintf(CRITICAL, "ATF: CRASH BUFF\n");
			plat_atf_crash_get = save_atf_log;
		}
		else if(ATF_LAST_LOG_MAGIC_NO == *(uint32_t *)atf_crash_flag_addr){
			dprintf(CRITICAL, "ATF: LAST BUFF\n");
			plat_atf_log_get = save_atf_log;
		}
		else {
			dprintf(CRITICAL, "ATF: RAW BUFF\n");
			plat_atf_raw_log_get = save_atf_log;
		}
		dprintf(CRITICAL, "atf_log_buf_addr:0x%x, atf_log_buf_size:%u, atf_crash_flag addr:0x%x, atf_log_type:0x%x\n",
				atf_log_buf_addr, atf_log_buf_size, atf_crash_flag_addr,
				*(uint32_t *)atf_crash_flag_addr);
		dprintf(CRITICAL, "plat_atf_log_get:%p, plat_atf_crash_get:%p\n",
				plat_atf_log_get, plat_atf_crash_get);
	}
}

