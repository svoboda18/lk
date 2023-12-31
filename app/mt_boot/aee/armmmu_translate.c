#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KEHeader.h"

extern uint64_t get_mpt(void);
extern uint64_t kedump_mem_read(uint64_t data, unsigned long sz, void *buf);
#if 0
extern int sLOG(char *fmt, ...);
#define LOG(fmt, ...)           \
    do { \
        sLOG(fmt, ##__VA_ARGS__);       \
        printf(fmt, ##__VA_ARGS__); \
    } while(0)

#else
#define LOG(fmt, ...)
#endif
static int read_mem(uint64_t paddr, void *buf, unsigned long size)
{
	uint64_t ret = 0;

	ret = kedump_mem_read(paddr, size, buf);
	return (ret == size) ? 0 : -1;
}


#define PAGE_SIZE 4096
#define PNUM_64 (PAGE_SIZE / sizeof(uint64_t))
static uint64_t lxpage[PNUM_64];

static uint64_t mmutable_64_translate_l3(uint64_t vptr,
		uint64_t ptable)
{
	int ret = 0;
	uint64_t pa;

	unsigned int lxidx = (vptr >> 12) & 0x1ff;
	if (lxidx >= PNUM_64) {
		LOG("address:0x%llx index:%d overflow error\n", vptr, lxidx);
		return 0;
	}

	memset(lxpage, 0, PAGE_SIZE);
	ret = read_mem(ptable, lxpage, PAGE_SIZE);
	if (ret == 0) {
		LOG("(%d)ent value:0x%llx\n", lxidx, lxpage[lxidx]);
	} else {
		return 0;
	}

	switch(lxpage[lxidx] & 3) {
		case 3:
			pa = (lxpage[lxidx] & 0x0000fffffffff000)
				+ (vptr & 0xfff);
			break;
		default:
			LOG("invalid (%d)ent value:0x%llx\n", lxidx,
					lxpage[lxidx]);
			pa = 0;
	}

	return pa;
}

static uint64_t mmutable_64_translate_l2(uint64_t vptr,
		uint64_t ptable)
{
	int ret = 0;
	uint64_t pa;
	uint64_t next_table_address;

	unsigned int lxidx = (vptr >> 21) & 0x1ff;
	if (lxidx >= PNUM_64) {
		LOG("address:0x%llx index:%d overflow error\n", vptr, lxidx);
		return 0;
	}

	memset(lxpage, 0, PAGE_SIZE);
	ret = read_mem(ptable, lxpage, PAGE_SIZE);
	if (ret == 0) {
		LOG("(%d)ent value:0x%llx\n", lxidx, lxpage[lxidx]);
	} else {
		return 0;
	}

	switch(lxpage[lxidx] & 3) {
		case 1:
			pa = (lxpage[lxidx] & 0x0000ffffffe00000)
				+ (vptr & 0x1fffff);
			break;
		case 3:
			next_table_address = lxpage[lxidx]
				& 0x0000fffffffff000;
			pa = mmutable_64_translate_l3(vptr,
					next_table_address);
			break;
		default:
			LOG("invalid (%d)ent value:0x%llx\n", lxidx,
					lxpage[lxidx]);
			pa = 0;
	}

	return pa;
}

static uint64_t mmutable_64_translate_l1(uint64_t vptr,
		uint64_t ptable)
{
	int ret = 0;
	uint64_t pa;
	uint64_t next_table_address;

	unsigned int lxidx = (vptr >> 30) & 0x1ff;
	if (lxidx >= PNUM_64) {
		LOG("address:0x%llx index:%d overflow error\n", vptr, lxidx);
		return 0;
	}

	memset(lxpage, 0, PAGE_SIZE);
	ret = read_mem(ptable, lxpage, PAGE_SIZE);
	if (ret == 0) {
		LOG("(%d)ent value:0x%llx\n", lxidx, lxpage[lxidx]);
	} else {
		return 0;
	}

	switch(lxpage[lxidx] & 3) {
		case 1:
			pa = (lxpage[lxidx] & 0x0000ffffc0000000)
				+ (vptr & 0x3fffffff);
			break;
		case 3:
			next_table_address = lxpage[lxidx]
				& 0x0000fffffffff000;
			pa = mmutable_64_translate_l2(vptr,
					next_table_address);
			break;
		default:
			LOG("invalid (%d)ent value:0x%llx\n", lxidx,
					lxpage[lxidx]);
			pa = 0;
	}

	return pa;
}

uint64_t v2p_64(uint64_t vptr)
{
	uint64_t mpt = get_mpt();
	/* LOG("mater_page_table:0x%llx, vptr:0x%llx\n", mpt, vptr); */

	if ((vptr & 0x8000000000000000) != 0) {
		return mmutable_64_translate_l1(vptr, mpt);
	} else {
		LOG("illegal address:0x%llx\n", vptr);
	}

	return 0;
}

