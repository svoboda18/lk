#include <stdint.h>
#include <string.h>
#include <debug.h>
#include <platform/boot_mode.h>
#include <platform/partition.h>
#include <platform/verified_boot.h>
#include <platform/sec_policy.h>
#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>
#endif
#include <platform/emi_mpu.h>
#include <part_interface.h>
#include <env.h>


#define SCP_DRAM_SIZE       0x00200000  // mblock_reserve requires 2MB, SCP only requires 512KB
#define DRAM_ADDR_MAX       0xBFFFFFFF  // max address can SCP remap
#define DRAM_4GB_MAX        0xFFFFFFFF
#define DRAM_4GB_OFFSET     0x40000000
#define SCP_EMI_REGION      2
#define LOADER_NAME         "tinysys-loader-CM4_A"
#define FIRMWARE_NAME       "tinysys-scp-CM4_A"

extern u64 physical_memory_size(void);
extern int mboot_common_load_part(char *part_name, char *img_name, unsigned long addr);
extern int verify_load_scp_image(char *part_name, char *loader_name, char *firmware_name, void *addr, unsigned int offset);


extern BOOT_ARGUMENT *g_boot_arg;

static int load_scp_status = 0;
static void *dram_addr;
static char *scp_part_name[] = {"scp1", "scp2"};


int load_scp_image(char *part_name, char *img_name, void *addr)
{
	uint32_t sec_ret;
	uint32_t scp_vfy_time;
	int ret;
#ifdef MTK_SECURITY_SW_SUPPORT
	unsigned int policy_entry_idx = 0;
	unsigned int img_auth_required = 0;

	policy_entry_idx = get_policy_entry_idx(part_name);
	img_auth_required = get_vfy_policy(policy_entry_idx);
	/* verify cert chain of boot img */
	if (img_auth_required) {
		scp_vfy_time = get_timer(0);
		sec_ret = sec_img_auth_init(part_name, img_name, 0);
		if (sec_ret)
			return -1;
		dprintf(DEBUG, "[SBC] scp cert vfy pass(%d ms)\n", (unsigned int)get_timer(scp_vfy_time));
	}
#endif

	ret = mboot_common_load_part(part_name, img_name, addr);

	dprintf(INFO, "%s(): ret=%d\n", __func__, ret);

	if (ret <= 0)
		return -1;

#ifdef MTK_SECURITY_SW_SUPPORT
	if (img_auth_required) {
		scp_vfy_time = get_timer(0);
		sec_ret = sec_img_auth(addr, ret);
		if (sec_ret)
			return -1;
		dprintf(DEBUG, "[SBC] scp vfy pass(%d ms)\n", (unsigned int)get_timer(scp_vfy_time));
	}
#endif

	return ret;
}

static char *scp_partition_name(void)
{
	int i;
	part_t *part;

	for (i = 0; i < (sizeof(scp_part_name) / sizeof(*scp_part_name)); i++) {
		if (partition_get_active_bit_by_name(scp_part_name[i]) == 1)
			return scp_part_name[i];
	}

	dprintf(CRITICAL, "no scp partition with active bit marked, load %s\n", scp_part_name[0]);

	return scp_part_name[0];
}

int load_scp(void)
{
	int ret;
	unsigned int dram_ofs, perm;
	u64 dram_size;
	char *part_name;

	dram_addr = (void *) mblock_reserve(&g_boot_arg->mblock_info, SCP_DRAM_SIZE, 0x10000, DRAM_ADDR_MAX, RANKMAX);

	dprintf(INFO, "%s(): dram_addr=%p\n", __func__, dram_addr);

	if (dram_addr == ((void *) 0))
		goto error;

	dram_size = physical_memory_size();

	if (dram_size > DRAM_4GB_MAX)
		dram_ofs = DRAM_4GB_OFFSET;
	else
		dram_ofs = 0;

	part_name = scp_partition_name();

	if (part_name) {
		ret = verify_load_scp_image(part_name, LOADER_NAME, FIRMWARE_NAME, dram_addr, dram_ofs);

		if (ret < 0) {
			dprintf(CRITICAL, "scp verify %s failed, code=%d\n", part_name, ret);
			goto error;
		}
	} else {
		ret = -1;
		dprintf(CRITICAL, "get scp partition failed\n");
		goto error;
	}

	/*clean dcache & icache before set up EMI MPU*/
	arch_sync_cache_range((addr_t)dram_addr, SCP_DRAM_SIZE);

	/*
	 * setup EMI MPU
	 * domain 0: AP
	 * domain 3: SCP
	 */
	perm = SET_ACCESS_PERMISSON(UNLOCK, FORBIDDEN, FORBIDDEN, FORBIDDEN, FORBIDDEN, NO_PROTECTION, FORBIDDEN, FORBIDDEN, SEC_RW);
	emi_mpu_set_region_protection(dram_addr, dram_addr + SCP_DRAM_SIZE - 1, SCP_EMI_REGION, perm);

	dprintf(INFO, "%s(): done\n", __func__);

	load_scp_status = 1;

	return 0;

error:
	/*
	 * @ret = 0, malloc() error
	 * @ret < 0, error code from load_scp_image()
	 */
	load_scp_status = ret;

	return -1;
}

#ifdef DEVICE_TREE_SUPPORT
int platform_fdt_scp(void *fdt)
{
	int nodeoffset;
	char *ret;

	dprintf(CRITICAL, "%s()\n", __func__);
	nodeoffset = fdt_node_offset_by_compatible(fdt, -1, "mediatek,scp");

	if (nodeoffset >= 0) {
		if (load_scp_status <= 0)
			ret = "fail";
		else
			ret = "okay";

		dprintf(CRITICAL, "status=%s\n", ret);

		fdt_setprop(fdt, nodeoffset, "status", ret, strlen(ret));

		return 0;
	}

	return 1;
}
#endif
