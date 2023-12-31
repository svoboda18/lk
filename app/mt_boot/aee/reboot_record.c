#include <string.h>
#include <arch/ops.h>
#include <dev/mrdump.h>
#include <debug.h>
#include "aee.h"
#include "mrdump_private.h"

#ifdef MTK_MRDUMP_SRAM_CB
struct mrdump_control_block *mrdump_cb_addr(void)
{
	/* directly return the address of debug service on SRAM */
	return (struct mrdump_control_block *)MRDUMP_CB_ADDR;
}

int mrdump_cb_size(void)
{
	return MRDUMP_CB_SIZE;
}

#else
#ifdef MTK_3LEVEL_PAGETABLE
#include <stdlib.h>
#include <err.h>
#endif

#define SEARCH_SIZE 33554432
#define SEARCH_STEP 1024

#ifdef MTK_3LEVEL_PAGETABLE
#define MAX_MAP_CNT (SECTION_SIZE/SEARCH_STEP)
#define mapflags (MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA)
struct mrdump_control_block *mrdump_cb_addr(void)
{
	int i, cnt = 0;

	/* to write sig, use 1-on-1 mapping */
	uint64_t paddr = DRAM_PHY_ADDR;
	vaddr_t vaddr = (vaddr_t)paddr;

	for (i = 0; i < SEARCH_SIZE; i += SEARCH_STEP) {
		if (cnt == 0) {
			int map_ok = arch_mmu_map(paddr, vaddr, mapflags, SECTION_SIZE);
			if (map_ok != NO_ERROR) {
				dprintf(CRITICAL, "%s: arch_mmu_map error.\n", __func__);
				return NULL;
			}
		}

		struct mrdump_control_block *bufp = (struct mrdump_control_block *)vaddr;
		if (memcmp(bufp->sig, MRDUMP_GO_DUMP, 8) == 0) {
			return bufp;
		}

		cnt++;
		cnt %= MAX_MAP_CNT;
		paddr += SEARCH_STEP;
		vaddr += SEARCH_STEP;
	}
	return NULL;
}
#else
struct mrdump_control_block *mrdump_cb_addr(void)
{
	int i;
	for (i = 0; i < SEARCH_SIZE; i += SEARCH_STEP) {
		struct mrdump_control_block *bufp = (struct mrdump_control_block *)(DRAM_PHY_ADDR + i);
		if (memcmp(bufp->sig, MRDUMP_GO_DUMP, 8) == 0) {
			return bufp;
		}
	}
	return NULL;
}
#endif

int mrdump_cb_size(void)
{
	return 8192; /* Hardcode for old platform */
}

#endif //MTK_MRDUMP_SRAM_CB

int aee_mrdump_get_info(struct mrdump_control_block *mcb)
{
	if (mcb == NULL)
		return -1;

	struct mrdump_control_block *bufp = NULL;

	memset(mcb, 0, sizeof(struct mrdump_control_block));

	bufp = mrdump_cb_addr();
	if (bufp == NULL)
		return -2;

	if (memcmp(bufp->sig, MRDUMP_GO_DUMP, 8) == 0) {
		memcpy(mcb, bufp, sizeof(struct mrdump_control_block));
		return 0;
	} else {
		return -3;
	}
}

struct mrdump_control_block *aee_mrdump_get_params(void)
{
	struct mrdump_control_block *bufp = mrdump_cb_addr();
	if (bufp == NULL) {
		dprintf(CRITICAL, "mrdump_cb is NULL\n");
		return NULL;
	}
	if (memcmp(bufp->sig, MRDUMP_GO_DUMP, 8) == 0) {
		bufp->sig[0] = 'X';
		aee_mrdump_flush_cblock(bufp);
		dprintf(CRITICAL, "Boot record found at %p[%02x%02x]\n", bufp, bufp->sig[0], bufp->sig[1]);
		return bufp;
	} else {
		dprintf(CRITICAL, "No Boot record found\n");
		return NULL;
	}
}

void aee_mrdump_flush_cblock(struct mrdump_control_block *bufp)
{
	if (bufp != NULL) {
		arch_clean_cache_range((addr_t)bufp, sizeof(struct mrdump_control_block));
	}
}
