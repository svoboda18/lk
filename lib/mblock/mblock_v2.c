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
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#include <debug.h>
#include <stdlib.h>
#include <string.h>
#include <platform.h>
#include <platform/boot_mode.h>
#include <libfdt.h>
#include <arch/arm/mmu.h>

#ifdef MBLOCK_LIB_SUPPORT
#ifdef NEW_MEMORY_RESERVED_MODEL
#error NEW_MEMORY_RESERVED_MODEL is deprecated , you should not define it and still enable MBLOCK_LIB_SUPPORT Plz choose either
#endif

/*please acquire mblock_lock before traverse the list*/
#define for_each_mblock_reserved(Mmblock_info, pp_reserve) \
	for (pp_reserve = &Mmblock_info->reserved[0];\
		pp_reserve <= &Mmblock_info->reserved[Mmblock_info->reserved_num - 1]; pp_reserve++)

int get_mblock_num(void)
{
	return g_boot_arg->mblock_info.mblock_num;
}


static void mblock_version_check(void)
{
	mblock_info_t *mblock_info = &g_boot_arg->mblock_info;

	if (mblock_info->mblock_magic != MBLOCK_MAGIC || mblock_info->mblock_version != MBLOCK_VERSION) {
		dprintf(CRITICAL, "\n\n\n ***Critical ERROR, PL and LK mblock mismatch , halt stop boot*****\n\n\n");
		while (1)
			;
	}
}

int setup_mem_property_use_mblock_info(dt_dram_info *property, size_t p_size)
{
	dram_info_t *dram_info = &g_boot_arg->orig_dram_info;
	dt_dram_info *p;
	unsigned int i;
	mblock_info_t * mblock_info = &g_boot_arg->mblock_info;

	u64 mblock_low_start = 0, mblock_high_end = 0, reserved_low_start = 0
						   , reserved_high_end = 0, mem_start,mem_sz;



	/* FixMe: assum physical memory is continuous with multiple bank
	 * ban0 and ban1 should be continuous , if not , we need to modify
	 * accordinly. Search for lowest value in mblock and reerved info
	 * the lowest value will be the start of mem and the highest will
	 * be end of dram , we only need to setup one mem dts node accordingly */

	if (p_size < 1) {
		dprintf(CRITICAL, "dram_info->rank_num =%d is bigger than mem_property=%d\n", dram_info->rank_num, p_size);
		return 1;
	}
	/* mblock is ordered, we can assum first mblock have the lowest value
	 * so is highest*/
	mblock_low_start = mblock_info->mblock[0].start;
	mblock_high_end = mblock_info->mblock[mblock_info->mblock_num - 1].start +
		mblock_info->mblock[mblock_info->mblock_num - 1].size;
	/* reserved info is not ordered , we need to traverse to find out min
	 * and max value */
	reserved_low_start = mblock_info->reserved[0].start;
	reserved_high_end = mblock_info->reserved[mblock_info->reserved_num - 1].start + \
						mblock_info->reserved[mblock_info->reserved_num - 1].size;
	for (i = 0; i<mblock_info->reserved_num; i++) {
		if (mblock_info->reserved[i].start < reserved_low_start) {
			reserved_low_start = mblock_info->reserved[i].start;
		}

		if ((mblock_info->reserved[i].start + mblock_info->reserved[i].size) > reserved_high_end) {
			reserved_high_end = mblock_info->reserved[i].start + mblock_info->reserved[i].size;
		}
	}
	mem_start = (reserved_low_start < mblock_low_start)?reserved_low_start:mblock_low_start;
	mem_sz = (reserved_high_end > mblock_high_end)\
			 ?(reserved_high_end - mem_start):(mblock_high_end - mem_start);
	p = (property );

	p->start_hi = cpu_to_fdt32(mem_start>>32);
	p->start_lo = cpu_to_fdt32(mem_start);
	p->size_hi = cpu_to_fdt32((mem_sz>>32));
	p->size_lo = cpu_to_fdt32(mem_sz);

	dprintf(INFO, " mem_start=0x%llx mem_sz=0x%llx\n", mem_start, mem_sz);
	dprintf(INFO, " mem_reg_property[%d].start_hi = 0x%08X\n", i, p->start_hi);
	dprintf(INFO, " mem_reg_property[%d].start_lo = 0x%08X\n", i, p->start_lo);
	dprintf(INFO, " mem_reg_property[%d].size_hi  = 0x%08X\n", i, p->size_hi);
	dprintf(INFO, " mem_reg_property[%d].size_lo  = 0x%08X\n", i, p->size_lo);

	return 0;
}

int mblock_reserved_append(void *fdt)
{
	int offset, ret = 0;
	int nodeoffset = 0;
	unsigned int i;
	char node_name[128];
	char compatible[MBLOCK_RESERVED_NAME_SIZE + 64];
	dt_dram_info reg_info;
	reserved_t *reserved;

	offset = fdt_path_offset(fdt, "/reserved-memory");
	if (offset < 0) {
		dprintf(CRITICAL, "couldn't find /reserved-memory\n");
		return 1;
	}

	for (i = 0; i < g_boot_arg->mblock_info.reserved_num; i++) {
		reserved = &g_boot_arg->mblock_info.reserved[i];
		snprintf(node_name, sizeof(node_name), "mblock-%d-%s", i+1, reserved->name);
		dprintf(INFO, "%s: add_subnode name=%s start:0x%llx size:0x%llx\n", __func__, node_name, reserved->start, reserved->size);
		nodeoffset = fdt_add_subnode(fdt, offset, node_name);
		if (nodeoffset < 0) {
			dprintf(CRITICAL, "Warning: can't add mblock-reserved-memory node in device tree nodeoffset=0x%x\n", nodeoffset);
			return 1;
		}
		snprintf(compatible, sizeof(compatible), "mediatek,%s", reserved->name);
		ret = fdt_setprop_string(fdt, nodeoffset, "compatible", compatible);
		if (ret) {
			dprintf(CRITICAL, "Warning: can't add mblock-reserved-memory compatible property in device tree ret=0x%x\n", ret);
			return 1;
		}
		if (!reserved->mapping) {
			ret = fdt_setprop(fdt, nodeoffset, "no-map", NULL, 0);
			if (ret) {
				dprintf(CRITICAL, "Warning: can't add mblock-reserved-memory no-map property in device tree ret=0x%x\n", ret);
				return 1;
			}
		}

		reg_info.start_hi = cpu_to_fdt32(reserved->start>>32);
		reg_info.start_lo = cpu_to_fdt32(reserved->start);
		reg_info.size_hi = cpu_to_fdt32((reserved->size)>>32);
		reg_info.size_lo = cpu_to_fdt32(reserved->size);

		ret = fdt_setprop(fdt, nodeoffset, "reg", &reg_info, sizeof(reg_info));
		if (ret) {
			dprintf(CRITICAL, "Warning: can't add mblock-reserved-memory reg property in device tree ret=0x%x\n", ret);
			return 1;
		}

		dprintf(SPEW, "mblock-reserved-memory is appended (0x%llx, 0x%llx)\n",
				reserved->start, reserved->size);
	}
	return ret;
}

void mblock_show_info(void)
{
	mblock_info_t *mblock_info = &g_boot_arg->mblock_info;
	unsigned int i;
	u64 start, sz;

	dprintf(CRITICAL, "mblock_magic:0x%x mblock_version:0x%x\n", \
			mblock_info->mblock_magic, mblock_info->mblock_version);
	mblock_version_check();
	for (i = 0; i < mblock_info->mblock_num; i++) {
		start = mblock_info->mblock[i].start;
		sz = mblock_info->mblock[i].size;
		dprintf(CRITICAL, "mblock[%d].start: 0x%llx, size: 0x%llx\n", i,
				start, sz);
	}

	for (i = 0; i < mblock_info->reserved_num; i++) {
		start = mblock_info->reserved[i].start;
		sz = mblock_info->reserved[i].size;
		dprintf(CRITICAL, "mblock[%d].start: 0x%llx, size: 0x%llx map:%d name:%s\n", i,
				start, sz, mblock_info->reserved[i].mapping, mblock_info->reserved[i].name);
	}
}


/*
 * reserve a memory from mblock
 * @mblock_info: address of mblock_info
 * @reserved_size: size of memory
 * @align: alignment
 * @limit: address limit. Must higher than return address + reserved_size
 * @mapping: describe kernel mapping mechanism , 1:map or 0:no-map
 * @name: assign a dedicated name for this memory area
 * It returns as high address as possible.
 */
u64 mblock_reserve_ext(mblock_info_t *mblock_info, u64 reserved_size, u64 align, u64 limit,
		   u32 mapping, char *name)
{
	unsigned int i;
	int target = -1;
	u64 start, end, sz, max_addr = 0;
	u64 reserved_addr = 0;
	mblock_t mblock;

	mblock_version_check();
	if (mblock_info->mblock_num >= (MBLOCK_NUM_MAX - 1) || mblock_info->reserved_num >= (MBLOCK_RESERVED_NUM_MAX - 1)||\
		(mapping >> 1) || (name)?(strlen(name) >= (MBLOCK_RESERVED_NAME_SIZE - 1)):true) {
		/* the mblock[] is full */
		dprintf(CRITICAL, "mblock_reserve error: mblock_num or reserved_num is full mblock_num=%d, \
			reserved_num=%d mapping=%d name=%s\n", mblock_info->mblock_num, mblock_info->reserved_num, mapping, name);
		return 0;
	}

	if (!align)
		align = 0x1000;
	/* must be at least 4k aligned */
	if (align & (0x1000 - 1))
		align &= ~(0x1000 - 1);
	for (i = 0; i < mblock_info->mblock_num; i++) {
		start = mblock_info->mblock[i].start;
		sz = mblock_info->mblock[i].size;
		end = limit < (start + sz) ? limit : (start + sz);

		if( reserved_size > sz || limit <= start || end <= start) {
			dprintf(CRITICAL,"skip this mblock start=%llx sz=%llx limit=%llx end=%llx\n",
				start, sz, limit, end);
			continue;
		}

		reserved_addr = (end - reserved_size);
		reserved_addr &= ~(align - 1);
		dprintf(CRITICAL, "mblock[%d].start: 0x%llx, sz: 0x%llx, limit: 0x%llx, max_addr: 0x%llx, target: %d, reserved_addr: 0x%llx,"
		       "reserved_size: 0x%llx\n",
		       i, start, sz, limit, max_addr,
		       target, reserved_addr, reserved_size);
		dprintf(CRITICAL, "mblock_reserve dbg[%d]: %d, %d, %d, %d\n",
		       i, (reserved_addr + reserved_size <= start + sz),
		       (reserved_addr >= start),
		       (start + sz > max_addr),
		       (reserved_addr + reserved_size <= limit));
		if ((reserved_addr + reserved_size <= start + sz) &&
			(reserved_addr >= start) &&
			(start + sz > max_addr) &&
			(reserved_addr + reserved_size <= limit)) {
			max_addr = start + sz;
			target = i;
		}
	}

	if (target < 0) {
		dprintf(CRITICAL, "mblock_reserve error\n");
		return 0;
	}


	/* update variable reference to correct target info*/
	start = mblock_info->mblock[target].start;
	sz = mblock_info->mblock[target].size;
	end = limit < (start + sz) ? limit : (start + sz);
	reserved_addr = (end - reserved_size);
	reserved_addr &= ~(align - 1);


	/* store reserved_t info */
/*	dprintf(CRITICAL,"mblock_info->reserved_num=%d\n",mblock_info->reserved_num); */
	/*sanity check , reserved_num of array must be empty */
	if (mblock_info->reserved[mblock_info->reserved_num].start) {
		dprintf(CRITICAL, "mblock_reserve error , resreved slot already exist\
			start=0x%llx size=0x%llx\n", mblock_info->reserved[mblock_info->reserved_num].start
				, mblock_info->reserved[mblock_info->reserved_num].size);
		return 0;
	}

	mblock_info->reserved[mblock_info->reserved_num].start = reserved_addr;
	mblock_info->reserved[mblock_info->reserved_num].size = reserved_size;
	mblock_info->reserved[mblock_info->reserved_num].mapping = mapping;
	strncpy((char*)&mblock_info->reserved[mblock_info->reserved_num].name, name,
		(strlen(name) >= MBLOCK_RESERVED_NAME_SIZE)? MBLOCK_RESERVED_NAME_SIZE - 1: strlen(name));
	if (strlen(name) < MBLOCK_RESERVED_NAME_SIZE)
		mblock_info->reserved[mblock_info->reserved_num].name[strlen(name)] = '\0';
	else
		mblock_info->reserved[mblock_info->reserved_num].name[MBLOCK_RESERVED_NAME_SIZE - 1] = '\0';

	mblock_info->reserved_num++;

	/* split mblock if necessary */
	if (reserved_addr == start) {
		/*
		 * only needs to fixup target mblock
		 * [reserved_addr, reserved_size](reserved) +
		 * [reserved_addr + reserved_size, sz - reserved_size]
		 */
		mblock_info->mblock[target].start = reserved_addr + reserved_size;
		mblock_info->mblock[target].size -= reserved_size;
	} else if ((reserved_addr + reserved_size) == (start + sz)) {
		/*
		 * only needs to fixup target mblock
		 * [start, reserved_addr - start] +
		 * [reserved_addr, reserved_size](reserved)
		 */
		mblock_info->mblock[target].size = reserved_addr - start;
	} else {
		/*
		 * fixup target mblock and create a new mblock
		 * [start, reserved_addr - start] +
		 * [reserved_addr, reserved_size](reserved) +
		 * [reserved_addr + reserved_size, start + sz - reserved_addr - reserved_size]
		 */
		/* fixup original mblock */
		mblock_info->mblock[target].size = reserved_addr - start;

		/* new mblock */
		mblock.rank =  mblock_info->mblock[target].rank;
		mblock.start = reserved_addr + reserved_size;
		mblock.size = start + sz - (reserved_addr + reserved_size);

		/* insert the new node, keep the list sorted */
		memmove(&mblock_info->mblock[target + 2],
			&mblock_info->mblock[target + 1],
				sizeof(mblock_t) *
				(mblock_info->mblock_num - target - 1));
		mblock_info->mblock[target + 1] = mblock;
		mblock_info->mblock_num += 1;
		dprintf(CRITICAL, "mblock[%d]: %llx, %llx from mblock\n"
			"mblock[%d]: %llx, %llx from mblock\n",
			target,
			mblock_info->mblock[target].start,
			mblock_info->mblock[target].size,
			target + 1,
			mblock_info->mblock[target + 1].start,
			mblock_info->mblock[target + 1].size);
	}

	dprintf(SPEW, "mblock_reserve: %llx - %llx from mblock %d\n",
		reserved_addr, reserved_addr + reserved_size,
		target);
#ifdef MTK_3LEVEL_PAGETABLE
	{
		u64 m_start = (u64)reserved_addr;
		u32 m_size = (u32)reserved_size;

		if (start <= 0xffffffff) {
			arch_mmu_map((uint64_t)m_start, (uint32_t)m_start,
						 MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA, ROUNDUP(m_size, PAGE_SIZE));
		}
	}
#endif

	/* print debug info */
	for (i = 0; i < mblock_info->mblock_num; i++) {
		start = mblock_info->mblock[i].start;
		sz = mblock_info->mblock[i].size;
		dprintf(CRITICAL, "mblock_reserve [%d].start: 0x%llx, sz: 0x%llx\n",
			i, start, sz);
	}

	for (i = 0; i < mblock_info->reserved_num; i++) {
		start = mblock_info->reserved[i].start;
		sz = mblock_info->reserved[i].size;
		dprintf(CRITICAL, "mblock_reserve-R[%d].start: 0x%llx, sz: 0x%llx map:%d name:%s\n",
		       i, start, sz, mblock_info->reserved[i].mapping, mblock_info->reserved[i].name);
	}

	return reserved_addr;
}

/*
 * mblock_resize - resize mblock started at addr from oldsize to newsize,
 * current implementation only consider oldsize >= newsize.
 *
 * @mblock_info: mblock information
 * @orig_dram_info: original dram information
 * @addr: start address of a mblock
 * @oldsize: origianl size of the mblock
 * @newsize: new size of the given block
 * return 0 on success, otherwise 1
 */
int mblock_resize(mblock_info_t *mblock_info, dram_info_t *orig_dram_info,
		  u64 addr, u64 oldsize, u64 newsize)
{
	int err = 1;
	unsigned int i, map;
	u64 start, sz;
	mblock_t mblock;
	unsigned int found, target = 0;

	mblock_version_check();
	/* check size, oldsize must larger than newsize */
	if (oldsize <= newsize) {
		dprintf(CRITICAL, "mblock_resize error: mblock %llx oldsize(%llx) <= newsize(%llx)",
			addr, oldsize, newsize);
		goto error;
	}

	/* check alignment, at least 4k aligned */
	if ((oldsize & (0x1000 - 1)) || (newsize & (0x1000 - 1))) {
		dprintf(CRITICAL, "mblock_resize alignment error: oldsize(%llx) or newsize(%llx)\n",
			oldsize, newsize);
		goto error;
	}

	/* check mblock for overlap
	 * resized memory must not exist in mblock[i]
	 * it msut be in reserved[i]*/
	for (i = 0; i < mblock_info->mblock_num; i++) {
		start = mblock_info->mblock[i].start;
		sz = mblock_info->mblock[i].size;
		/* invalid mblock */
		if (sz && (((start >= addr) && (start < (addr + oldsize)))
			|| ((start < addr) && (start + sz > addr)))) {
			dprintf(CRITICAL, "mblock_resize error:");
			dprintf(CRITICAL,
			"addr %llx, oldsize: %llx  start: 0x%llx sz: 0x%llx is free\n",
				addr, oldsize, start, sz);
			dprintf(CRITICAL,
			"mblock_resize failed while(1) force hang\n");
			assert(0);
		}
	}

	/* check reserved */
	/* this record must exist exactly */
	found = 0;
	for (i = 0; i < mblock_info->reserved_num; i++) {
		if (addr == mblock_info->reserved[i].start && oldsize == mblock_info->reserved[i].size)	{
			dprintf(SPEW, "mblock_resize  start: %llx, size: %llx addr = %llx oldsize = %llx\n",
				mblock_info->reserved[i].start, mblock_info->reserved[i].size, addr, oldsize);
			found = 1;
			target = i;
		}
	}

	if (!found) {
		dprintf(CRITICAL, "mblock_resize error: mblock %llx, size: %llx is not exist\n",
				addr, oldsize);
		goto error;
	}

	/*
	 * ok, the mblock is valid and oldsize > newsize, let's
	 * shrink this mblock
	 */
	/* setup a new mblock */
	mblock.start = addr + newsize;
	mblock.size = oldsize - newsize;
	dprintf(CRITICAL, "mblock_resize putback mblock %llx size: %llx\n",
		mblock.start, mblock.size);
	/* setup rank */
	for (i = 0; i < orig_dram_info->rank_num; i++) {
		start = orig_dram_info->rank_info[i].start;
		sz = orig_dram_info->rank_info[i].size;
		if ((mblock.start >= start) && ((mblock.start + mblock.size) <= (start + sz))) {
			mblock.rank = i;
			break;
		}
	}
	if (i >= orig_dram_info->rank_num) {
		dprintf(CRITICAL, "mblock_resize error: mblock not in orig_dram_info: %llx, size(%llx)\n",
			mblock.start, mblock.size);
		goto error;
	}


	/* here , we decide to shrink or delete this reserved record*/
	if (newsize == 0) {
		/* destroy current record first */
		memset(&mblock_info->reserved[target], 0, sizeof(reserved_t));
		/* more than one record exist , we need to shift record */
		/* we no need to shif record once it's the last one */
		if (mblock_info->reserved_num > 1 && target != mblock_info->reserved_num - 1) {
			memmove(&mblock_info->reserved[target], &mblock_info->reserved[target + 1]\
				, sizeof(reserved_t) * ((mblock_info->reserved_num - 1) - target));
		}

		mblock_info->reserved_num--;
	}
	/* shirnk size directly */
	else {
		mblock_info->reserved[target].size = newsize;
	}

	/* put the mblock back to mblock_info */
	for (i = 0; i < mblock_info->mblock_num; i++) {
		start = mblock_info->mblock[i].start;
		sz = mblock_info->mblock[i].size;
		if (mblock.rank == mblock_info->mblock[i].rank) {
			if (mblock.start == start + sz) {
				/*
				 * the new mblock can be merged to this mblock
				 * [start, start + sz] +
				 * [mblock.start, mblock.start + mblock.size](new)
				 */
				mblock_info->mblock[i].size += mblock.size;
				/* destroy block */
				mblock.size = 0;
			} else if (start == mblock.start + mblock.size) {
				/*
				 * the new mblock can be merged to this mblock
				 * [mblock.start, mblock.start + * mblock.size](new) +
				 * [start, start + sz]
				 */
				mblock_info->mblock[i].start = mblock.start;
				mblock_info->mblock[i].size += mblock.size;
				/* destroy block */
				mblock.size = 0;
			}
		}
	}

	/*
	 * mblock cannot be merge info mblock_info, insert it into mblock_info
	 */
	if (mblock.size) {
		for (i = 0; i < mblock_info->mblock_num; i++) {
			if (mblock.start < mblock_info->mblock[i].start)
				break;
		}
		memmove(&mblock_info->mblock[i + 1],
			&mblock_info->mblock[i],
			sizeof(mblock_t) *
			(mblock_info->mblock_num - i));
		mblock_info->mblock[i] = mblock;
		mblock_info->mblock_num += 1;
	}

	/* print debug info */
	for (i = 0; i < mblock_info->mblock_num; i++) {
		start = mblock_info->mblock[i].start;
		sz = mblock_info->mblock[i].size;
		dprintf(INFO, "mblock_resize-debug[%d].start: 0x%llx, sz: 0x%llx\n",
			i, start, sz);
	}

	/* print debug info */
	for (i = 0; i < mblock_info->reserved_num; i++) {
		start = mblock_info->reserved[i].start;
		sz = mblock_info->reserved[i].size;
		map = mblock_info->reserved[i].mapping;
		dprintf(INFO, "mblock_resize-debug-R[%d].start: 0x%llx, sz: 0x%llx map: %d name: %s\n",
			i, start, sz, map, mblock_info->reserved[i].name);
	}

	return 0;
error:
	return err;
}

/*
 * mblock_create - create mblock started at addr or merge with existing mblock
 *
 * @mblock_info: mblock information
 * @orig_dram_info: original dram information
 * @addr: start address of a mblock, must be 4k align
 * @size: size of the given block, must be 4K align
 * return 0 on success, otherwise 1
 */
int mblock_create(mblock_info_t *mblock_info, dram_info_t *orig_dram_info
		  , u64 addr, u64 size)
{
	int err = -1;
	unsigned int i, valid, target, map;
	u64 start, sz;
	mblock_t mblock;
	reserved_t reserved;
	mblock_t *mblock_candidate_left = NULL, *mblock_candidate_right = NULL;

	mblock_version_check();
	/* check size, addr valid and align with 4K*/
	if (!size || size&(0x1000 - 1) || addr&(0x1000 - 1)) {
		dprintf(CRITICAL, "mblock_create size invalid size=%llx\n", size);
		goto error;
	}
	/* for lca check*/
	if (g_boot_arg->lca_reserved_mem.start && g_boot_arg->lca_reserved_mem.size) {
		if ((addr >= g_boot_arg->lca_reserved_mem.start && addr < g_boot_arg->lca_reserved_mem.start \
			+ g_boot_arg->lca_reserved_mem.size) || \
				(addr + size > g_boot_arg->lca_reserved_mem.start \
					&& (addr + size) < g_boot_arg->lca_reserved_mem.start + g_boot_arg->lca_reserved_mem.size)) {
			dprintf(CRITICAL, "mblock_create ERROR , overlap with LCA addr and size invalid addr = %llx size=%llx\n", addr, size);
			goto error;
		}
	}

	/* for tee check*/
	if (g_boot_arg->tee_reserved_mem.start && g_boot_arg->tee_reserved_mem.size) {
		if ((addr >= g_boot_arg->tee_reserved_mem.start && addr < g_boot_arg->tee_reserved_mem.start \
			+ g_boot_arg->tee_reserved_mem.size) || \
				(addr + size > g_boot_arg->tee_reserved_mem.start \
					&& (addr + size) < g_boot_arg->tee_reserved_mem.start + g_boot_arg->tee_reserved_mem.size)) {
			dprintf(CRITICAL, "mblock_create ERROR , overlap with tee addr and size invalid addr = %llx size=%llx\n", addr, size);
			goto error;
		}
	}

	/*it's not allow to create mblock which is cross rank
	 * and mblock should not exceed rank size */
	for (i = 0, valid = 0; i < orig_dram_info->rank_num; i++) {
		start = orig_dram_info->rank_info[i].start;
		sz = orig_dram_info->rank_info[i].size;
		if (addr >= start && addr < start + sz && addr + size <= start + sz) {
			valid = 1;
			break;
		}
	}
	if (!valid) {
		dprintf(CRITICAL, "mblock_create addr \
				and size invalid addr=%llx size=%llx\n", addr, size);
		goto error;
	}

	/* check every mblock the addr and size should not be within any existing mblock */
	for (i = 0; i < mblock_info->mblock_num; i++) {
		start = mblock_info->mblock[i].start;
		sz = mblock_info->mblock[i].size;
		/*addr should start from reserved memory space and addr + size should not overlap with mblock
		 * when addr is smaller than start*/
		if (((addr >= start) && (addr < start + sz)) || (addr < start && addr + size > start)) {
			dprintf(CRITICAL, "mblock_create error: addr %llx overlap with mblock %llx, size: %llx\n",
				addr, start, sz);
			goto error;
		}
	}

	/* check if reserved record contain this one , it must exist */
	for (i = 0, valid = 0; i < mblock_info->reserved_num; i++) {
		start = mblock_info->reserved[i].start;
		sz = mblock_info->reserved[i].size;
/*		dprintf(CRITICAL, "mblock_create start=0x%llx sz=0x%llx addr=0x%lx size=0x%llx\n",
				start, sz, addr, size);
*/
		if (addr >= start && ((addr + size) <= (start + sz))) {
			valid = 1;
			target = i;
			break;
		}
	}

	if (!valid) {
		dprintf(CRITICAL, "mblock_create error: not exist in reserved record\n addr=0x%llx size=0x%llx\n",
				addr, size);
		goto error;
	}

	/* dealling with 4 case */
	/* 1. create whole reserved record means destroy it and shit rest record*/
	/* 2. create from the left most side to the middle of record*/
	/* 3. create from the right most side to the middle of record*/
	/* 4. create from the middle of record, and then divide it*/
	start =  mblock_info->reserved[target].start;
	sz = mblock_info->reserved[target].size;
	if (addr == start && size == sz) {
		/* destroy current record first */
		memset(&mblock_info->reserved[i], 0, sizeof(reserved_t));
		/* more than one record exist , we need to shift record */
		/* we no need to shift record once it's the last one */
		if (mblock_info->reserved_num > 1 && target != mblock_info->reserved_num - 1) {
			memmove(&mblock_info->reserved[target], &mblock_info->reserved[target + 1]\
				, sizeof(reserved_t) * ((mblock_info->reserved_num - 1) - target));
			/* after memmove, we must clean the last one */
			memset(&mblock_info->reserved[mblock_info->reserved_num - 1], 0, sizeof(reserved_t));
		}
		mblock_info->reserved_num--;
	} else if (addr == start || (addr + size == start + sz)) {
		/*Now we deal with lef and right most case*/
		/* we just shrink the record */
		if (addr == start) {
			mblock_info->reserved[target].start = start + size;
			mblock_info->reserved[target].size = sz - size;
		} else {/* (addr + size == start + sz)*/
			mblock_info->reserved[target].size = sz - size;
		}
	} else {/* this is middle case we need to divide it*/
	       /* shrink original one and create new one after */
		if (mblock_info->reserved_num >= MBLOCK_RESERVED_NUM_MAX) {
			dprintf(CRITICAL, "mblock_create error: can not split , reserved_num reach the max\n");
			goto error;
		}

		reserved.start = addr + size;
		reserved.size = (start + sz) - (addr + size);
		/* clone from original one*/
		reserved.mapping  = mblock_info->reserved[target].mapping;
		memcpy(&reserved.name, &mblock_info->reserved[target].name, MBLOCK_RESERVED_NAME_SIZE);
		/* check if this target is last one or not */
		/* target start from 0 , reserved_num start from 1 */
		if (target != mblock_info->reserved_num - 1) {
			for (i = 0; i < (mblock_info->reserved_num - target - 1); i++) {
				mblock_info->reserved[mblock_info->reserved_num - i] = \
					mblock_info->reserved[mblock_info->reserved_num - i - 1];
			}
			mblock_info->reserved[target+1] = reserved;
		} else {/*target is the last one */
			mblock_info->reserved[mblock_info->reserved_num] = reserved;
		}
		/* shrink original target size at last step */
		mblock_info->reserved[target].size = addr - start;

		mblock_info->reserved_num++;

	}

	/*
	 * ok, the mblock is valid let's create the mblock
	 * and try to merge it with the same bank and choose the bigger size one
	 */
	/* setup a new mblock */
	mblock.start = addr;
	mblock.size = size;
	dprintf(CRITICAL, "mblock_create mblock start %llx size: %llx\n",
		mblock.start, mblock.size);
	/* setup rank */
	for (i = 0; i < orig_dram_info->rank_num; i++) {
		start = orig_dram_info->rank_info[i].start;
		sz = orig_dram_info->rank_info[i].size;
		if ((mblock.start >= start) && ((mblock.start + mblock.size) <= (start + sz))) {
			mblock.rank = i;
			break;
		}
	}
	if (i >= orig_dram_info->rank_num) {
		dprintf(CRITICAL, "mblock_create error: mblock not in orig_dram_info: %llx, size(%llx)\n",
			mblock.start, mblock.size);
		goto error;
	}

	/* put the mblock back to mblock_info */
	for (i = 0; i < mblock_info->mblock_num; i++) {
		start = mblock_info->mblock[i].start;
		sz = mblock_info->mblock[i].size;
		if (mblock.rank == mblock_info->mblock[i].rank) {
			if (mblock.start + mblock.size == start) {
				/*
				 * the new mblock could be merged to this mblock
				 */
				mblock_candidate_right = &mblock_info->mblock[i];
			} else if (start + sz == mblock.start) {
				/*
				 * the new mblock can be merged to this mblock
				 */
				mblock_candidate_left =  &mblock_info->mblock[i];
			}
		}
	}
	/*we can merge either left or right , choose the bigger one */
	if (mblock_candidate_right && mblock_candidate_left) {
		if (mblock_candidate_right->size >= mblock_candidate_left->size) {
			dprintf(CRITICAL, "mblock_candidate_right->size = %llx \
				mblock_candidate_left->size = %llx \n", mblock_candidate_right->size, mblock_candidate_left->size);
			mblock_candidate_right->start = mblock.start;
			mblock_candidate_right->size += mblock.size;
		} else { /*left bigger*/
			dprintf(CRITICAL, "mblock_candidate_right->size = %llx \
				mblock_candidate_left->size = %llx \n", mblock_candidate_right->size, mblock_candidate_left->size);
			mblock_candidate_left->size += mblock.size;
		}
		/* destroy block */
		mblock.size = 0;
	} else {
		if (mblock_candidate_right) {
			mblock_candidate_right->start = mblock.start;
			mblock_candidate_right->size += mblock.size;
			/* destroy block */
			mblock.size = 0;
		}

		if (mblock_candidate_left) {
			mblock_candidate_left->size += mblock.size;
			/* destroy block */
			mblock.size = 0;
		}
	}

	/*
	 * mblock cannot be merge into mblock_info, insert it into mblock_info
	 */
	if (mblock.size) {
		for (i = 0; i < mblock_info->mblock_num; i++) {
			if (mblock.start < mblock_info->mblock[i].start)
				break;
		}
		/* insert the new node, keep the list sorted */
		if (i != mblock_info->mblock_num) {
			memmove(&mblock_info->mblock[i + 1],
				&mblock_info->mblock[i],
				sizeof(mblock_t) *
				(mblock_info->mblock_num - i));
		}
		mblock_info->mblock[i] = mblock;
		mblock_info->mblock_num += 1;
		dprintf(INFO, "create mblock[%d]: %llx, %llx\n",
			i,
			mblock_info->mblock[i].start,
			mblock_info->mblock[i].size);
	}

	/* print debug info */
	for (i = 0; i < mblock_info->mblock_num; i++) {
		start = mblock_info->mblock[i].start;
		sz = mblock_info->mblock[i].size;
		dprintf(INFO, "mblock-create-debug[%d].start: 0x%llx, sz: 0x%llx\n",
			i, start, sz);
	}

	/* print debug info */
	for (i = 0; i < mblock_info->reserved_num; i++) {
		start = mblock_info->reserved[i].start;
		sz = mblock_info->reserved[i].size;
		map = mblock_info->reserved[i].mapping;
		dprintf(INFO, "mblock-create-debug-R[%d].start: 0x%llx, sz: 0x%llx map: %d name: %s\n",
			i, start, sz, map, mblock_info->reserved[i].name);
	}

	return 0;
error:
	return err;
}

static u64 mlp_reserved_end = ULLONG_MAX;
void memory_lowpwer_prev_fixup(u64 start)
{
	dprintf(CRITICAL, "%s: %d\n", __func__, __LINE__);

	if (mlp_reserved_end <= start)
		return;

	dprintf(CRITICAL, "%s: %d: %llu\n", __func__, __LINE__, start);
	mlp_reserved_end = start;
}

/*
 * memory_lowpower_fixup
 *
 * To support various DRAM size with single logic, we fixup
 * the reserved memory used by memory-lowpower feature according
 * chip DRAM size.
 * It's fine to put the function in common part since it searches
 * for specified node and only fixup the node.
 *
 * input:
 * @fdt: pointer to fdt
 *
 * output:
 * return 0 on success, otherwise 1
 */
int memory_lowpwer_fixup(void *fdt)
{
	int offset, nodeoffset, new_nodeoffset, len, errline, ret;
	unsigned int i;
	char node_name[128];
	char compatible_str[MBLOCK_RESERVED_NAME_SIZE + 64], *compatible;
	int prop_offset;
	const char *name;
	const void *val;
	u32 clone_size[2], clone_align[2];
	dt_dram_info alloc_range, reg_info;
	mblock_info_t *mblock_info = &g_boot_arg->mblock_info;
	u32 *psize, *prange, *palign, node_size[2];
	u64 size, start, alignment, newstart, end = 0;

	offset = fdt_path_offset(fdt, "/reserved-memory");

	if (!offset) {
		errline = __LINE__;
		goto error;
	}

	/* Create final zmc dts node */
	new_nodeoffset = fdt_subnode_offset(fdt, offset,
				"zone-movable-cma-memory");
	if (new_nodeoffset < 0) {
		snprintf(node_name, sizeof(node_name), "zone-movable-cma-memory");
		new_nodeoffset = fdt_add_subnode(fdt, offset, node_name);

		if (new_nodeoffset < 0) {
			dprintf(CRITICAL,"add zone-movable-cma-memory dts node fail\n");
			goto exit;
		}
	}
	else {
		dprintf(CRITICAL,"zone-movable-cma-memory dts node already exist\n");
		goto exit;
	}

	nodeoffset = fdt_subnode_offset(fdt, offset,
			"memory-lowpower-reserved-memory");
	if (nodeoffset < 0) {
		nodeoffset = fdt_subnode_offset(fdt, offset,
				"zmc-default");
		if (nodeoffset < 0)
			goto exit;
	}

	/* Clone zmc-default property to final zmc node */
	for (prop_offset = fdt_first_property_offset(fdt, nodeoffset);
			prop_offset >= 0; prop_offset = fdt_next_property_offset(fdt, prop_offset)) {

		val = fdt_getprop_by_offset(fdt, prop_offset, &name, &len);

		if (val) {
			int update_offset = 0;
			u64 out_prop, out_prop_lower;
			u32 *out;
			if (strncmp(name, "compatible", 10)==0) {
				compatible = (char *)fdt_getprop(fdt, nodeoffset, name, &len);
				snprintf(compatible_str, sizeof(compatible_str), compatible);
				ret = fdt_setprop_string(fdt, new_nodeoffset, "compatible", compatible_str);
				if (ret) {
					errline = __LINE__;
					goto error;
				}
			}
			else if (strncmp(name, "size", 4)==0) {
				out = (u32 *)fdt_getprop(fdt, nodeoffset, name, &len);
				if (out != NULL) {
					out_prop = ((u64)fdt32_to_cpu(*out) << 32) + fdt32_to_cpu(*(out + 1));
					clone_size[0] = (u32)cpu_to_fdt32(out_prop >> 32);
					clone_size[1] = (u32)cpu_to_fdt32(out_prop);
					ret = fdt_setprop(fdt, new_nodeoffset, name, clone_size, sizeof(u32)*2);
					if (ret) {
						errline = __LINE__;
						goto error;
					}
				}
			}
			else if (strncmp(name, "alignment", 9)==0) {
				out = (u32 *)fdt_getprop(fdt, nodeoffset, name, &len);
				if (out != NULL) {
					out_prop = ((u64)fdt32_to_cpu(*out) << 32) + fdt32_to_cpu(*(out + 1));
					clone_align[0] = (u32)cpu_to_fdt32(out_prop >> 32);
					clone_align[1] = (u32)cpu_to_fdt32(out_prop);
					ret = fdt_setprop(fdt, new_nodeoffset, name, clone_align, sizeof(u32)*2);
					if (ret) {
						errline = __LINE__;
						goto error;
					}
				}
			}
			else if (strncmp(name, "alloc-ranges", 12)==0) {
				out = (u32 *)fdt_getprop(fdt, nodeoffset, name, &len);
				if (out != NULL) {
					out_prop = ((u64)fdt32_to_cpu(*out) << 32) + fdt32_to_cpu(*(out + 1));
					out_prop_lower = ((u64)fdt32_to_cpu(*(out + 2)) << 32) + fdt32_to_cpu(*(out + 3));
					alloc_range.start_hi = cpu_to_fdt32(out_prop >> 32);
					alloc_range.start_lo = cpu_to_fdt32(out_prop);
					alloc_range.size_hi = cpu_to_fdt32((out_prop_lower) >> 32);
					alloc_range.size_lo = cpu_to_fdt32(out_prop_lower);
					ret = fdt_setprop(fdt, new_nodeoffset, name, &alloc_range, sizeof(dt_dram_info));
					if (ret) {
						errline = __LINE__;
						goto error;
					}
				}
			}
			else if (strncmp(name, "reg", 3)==0) {
				out = (u32 *)fdt_getprop(fdt, nodeoffset, name, &len);
				if (out != NULL) {
					out_prop = ((u64)fdt32_to_cpu(*out) << 32) + fdt32_to_cpu(*(out + 1));
					out_prop_lower = ((u64)fdt32_to_cpu(*(out + 2)) << 32) + fdt32_to_cpu(*(out + 3));
					reg_info.start_hi = cpu_to_fdt32(out_prop >> 32);
					reg_info.start_lo = cpu_to_fdt32(out_prop);
					reg_info.size_hi = cpu_to_fdt32((out_prop_lower) >> 32);
					reg_info.size_lo = cpu_to_fdt32(out_prop_lower);
					ret = fdt_setprop(fdt, new_nodeoffset, name, &reg_info, sizeof(dt_dram_info));
					if (ret) {
						errline = __LINE__;
						goto error;
					}
				}
			}
			else if (strncmp(name, "no-map", 6)==0) {
				ret = fdt_setprop(fdt, new_nodeoffset, "no-map", NULL, 0);
				if (ret) {
					errline = __LINE__;
					goto error;
				}
			}
			else if (strncmp(name, "reusable", 8)==0) {
				ret = fdt_setprop(fdt, new_nodeoffset, "reusable", NULL, 0);
				if (ret) {
					errline = __LINE__;
					goto error;
				}
			}
			else
				continue;
			/* Update offset of dts node */
			update_offset = fdt_subnode_offset(fdt, offset, "zmc-default");
			new_nodeoffset = fdt_subnode_offset(fdt, offset, "zone-movable-cma-memory");
			prop_offset = prop_offset + (update_offset - nodeoffset);
			nodeoffset = update_offset;
		}
	}

	/* set status:disable to zmc-default */
	nodeoffset = fdt_subnode_offset(fdt, offset, "zmc-default");
	ret = fdt_setprop_string(fdt, nodeoffset, "status", "disabled");
	if (ret) {
		errline = __LINE__;
		goto error;
	}

	/* direct to zmc final dts node */
	nodeoffset = fdt_subnode_offset(fdt, offset, "zone-movable-cma-memory");

	/* get size */
	psize = (u32 *)fdt_getprop(fdt, nodeoffset, "size", &len);
	if (!psize) {
		errline = __LINE__;
		goto error;
	}
	size = ((u64)fdt32_to_cpu(*psize) << 32) + fdt32_to_cpu(*(psize + 1));

	/* get alignment */
	palign = (u32 *)fdt_getprop(fdt, nodeoffset, "alignment", &len);
	if (palign) {
		alignment = ((u64)fdt32_to_cpu(*palign) << 32) + fdt32_to_cpu(*(palign + 1));
	} else {
		/* fallback to default alignment */
		alignment = 256 * 1024 * 1024;
	}

	/* get alloc_rage */
	prange = (u32 *)fdt_getprop(fdt, nodeoffset, "alloc-ranges", &len);
	if (!prange) {
		errline = __LINE__;
		goto error;
	}
	start = ((u64)fdt32_to_cpu(*prange) << 32) + fdt32_to_cpu(*(prange + 1));

	/* search for max available DRAM address */
	for (i = 0; i < mblock_info->mblock_num; i++) {
		if ((mblock_info->mblock[i].start +
			mblock_info->mblock[i].size) > end)
			end = mblock_info->mblock[i].start +
				mblock_info->mblock[i].size;
	}

	/* bypass if start is not in the range of available DRAM */
	if (end <= start)
		goto exit;

	/* other reservations */
	if (mlp_reserved_end < end) {
		dt_dram_info mlp_reg_property;

		end = mlp_reserved_end;
		mlp_reg_property.start_hi = cpu_to_fdt32(start >> 32);
		mlp_reg_property.start_lo = cpu_to_fdt32(start);
		mlp_reg_property.size_hi = cpu_to_fdt32((end - start) >> 32);
		mlp_reg_property.size_lo = cpu_to_fdt32(end - start);

		ret |= fdt_setprop(fdt, nodeoffset, "alloc-ranges",
			&mlp_reg_property, sizeof(dt_dram_info));
		if (ret) {
			errline = __LINE__;
			goto error;
		}
	}

	/* fix size according to DRAM size */
	if (size > (end - start)) {
		newstart = start + size - (end - start);
		newstart = ((newstart + alignment - 1) / alignment) * alignment;
		dprintf(CRITICAL, "%s: newstart: %llx, size: 0x%llx => 0x%llx)\n",
				__func__, newstart, size, (start + size - newstart));
		if (newstart >= start + size) {
			errline = __LINE__;
			goto error;
		}
		size = start + size - newstart;
		node_size[0] = (u32)cpu_to_fdt32(size >> 32);
		node_size[1] = (u32)cpu_to_fdt32(size);
		ret = fdt_setprop(fdt, nodeoffset, "size",  node_size,
				sizeof(u32) * 2);
		if (ret) {
			errline = __LINE__;
			goto error;
		}
	}

exit:
	return 0;
error:
	dprintf(CRITICAL, "%s: errline: %d\n", __func__, errline);
	return 1;
}

int fdt_memory_append(void *fdt)
{
	char *ptr;
	int offset;
	int ret = 0;

	offset = fdt_path_offset(fdt, "/memory");

	if (offset < 0) {
		dprintf(CRITICAL, "%s:[%d] get fdt_path_offset of memory failed\n", __func__, __LINE__);
		ret = offset;
		goto exit;
	}

	ptr = (char *)&g_boot_arg->orig_dram_info;
	ret = fdt_setprop(fdt, offset, "orig_dram_info", ptr, sizeof(dram_info_t));
	if (ret) {
		dprintf(CRITICAL, "%s:[%d] fdt_setprop failed, ret=%d\n", __func__, __LINE__, ret);
		goto exit;
	}

	ptr = (char *)&g_boot_arg->mblock_info;
	ret = fdt_setprop(fdt, offset, "mblock_info", ptr, sizeof(mblock_info_t));
	if (ret) {
		dprintf(CRITICAL, "%s:[%d] fdt_setprop failed, ret=%d\n", __func__, __LINE__, ret);
		goto exit;
	}

	ptr = (char *)&g_boot_arg->lca_reserved_mem;
	ret = fdt_setprop(fdt, offset, "lca_reserved_mem", ptr, sizeof(mem_desc_t));
	if (ret) {
		dprintf(CRITICAL, "%s:[%d] fdt_setprop failed, ret=%d\n", __func__, __LINE__, ret);
		goto exit;
	}

	ptr = (char *)&g_boot_arg->tee_reserved_mem;
	ret = fdt_setprop(fdt, offset, "tee_reserved_mem", ptr, sizeof(mem_desc_t));
	if (ret) {
		dprintf(CRITICAL, "%s:[%d] fdt_setprop failed, ret=%d\n", __func__, __LINE__, ret);
		goto exit;
	}

	ret = memory_lowpwer_fixup(fdt);
	if (ret)
		goto exit;
exit:

	if (ret)
		return 1;

	return 0;
}

static int reserved_memory_conflict_check(void *fdt, mblock_info_t *mblock_info)
{
	int reserved_memory_offset, reserved_node, last_node = -1;
	int len, sanity_fail = 0;
	unsigned int i;
	const struct fdt_property *prop;
	dt_dram_info *data;
	u64 start, sz, reserved_start, reserved_sz;

	reserved_memory_offset = fdt_path_offset(fdt, "/reserved-memory");
	if (reserved_memory_offset < 0) {
		dprintf(CRITICAL, "couldn't find /reserved-memory\n");
		return reserved_memory_offset;
	}

	for (reserved_node = fdt_first_subnode(fdt, reserved_memory_offset); reserved_node >= 0;
		reserved_node = fdt_next_subnode(fdt, last_node)) {
		prop = fdt_get_property(fdt, reserved_node, "reg", &len);
		if (!prop) {
			last_node = reserved_node;
			continue;
		}

		data = (dt_dram_info *)prop->data;
		start = (((u64)fdt32_to_cpu(data->start_hi))<<32)|(fdt32_to_cpu(data->start_lo));
		sz = (((u64)fdt32_to_cpu(data->size_hi))<<32)|(fdt32_to_cpu(data->size_lo));

		dprintf(INFO, "DTS node:%s reserved start: 0x%llx size: 0x%llx\n",
			fdt_get_name(fdt, reserved_node, NULL), start, sz);
		for (i = 0; i < mblock_info->reserved_num; i++) {
			reserved_start = mblock_info->reserved[i].start;
			reserved_sz = mblock_info->reserved[i].size;
			if (((start < reserved_start) && \
					((start + sz) > (reserved_start))) || \
					((start >= reserved_start) && ((start < (reserved_start + reserved_sz))))) {
				sanity_fail = 1;
				dprintf(CRITICAL, "%s:%d failed i:%d %d:%d:%d:%d\n", __func__, __LINE__, i\
						, (start < reserved_start), ((start + sz) > (reserved_start))\
						, (start >= reserved_start), ((start < (reserved_start + reserved_sz))));
			}
		}

		if (sanity_fail) {
			/* print debug info */
			for (i = 0; i < mblock_info->mblock_num; i++) {
				start = mblock_info->mblock[i].start;
				sz = mblock_info->mblock[i].size;
				dprintf(CRITICAL, "mblock_reserve [%d].start: 0x%llx, sz: 0x%llx\n",
						i, start, sz);
			}

			for (i = 0; i < mblock_info->reserved_num; i++) {
				start = mblock_info->reserved[i].start;
				sz = mblock_info->reserved[i].size;
				dprintf(CRITICAL, "mblock_reserve-R[%d].start: 0x%llx, sz: 0x%llx map:%d name:%s\n",
					   i, start, sz, mblock_info->reserved[i].mapping, mblock_info->reserved[i].name);
			}
		} else
			dprintf(INFO, "%s:PASS\n", __func__);

		if (sanity_fail) {
			dprintf(CRITICAL, "%s fatal error keep while (1)\n", __func__);
			while (1)
				;
		}

		last_node = reserved_node;
	}

	return 0;
}

/*
 * mblock_sanity_check
 * after executing mblock related api , we perform
 * sanity check in the last step to confirm there
 * is nothing wrong, we will check overlap and
 * conflict between DTS and mblock API
 *
 * input:
 * @fdt: pointer to fdt
 * @mblock_info: the address of mblock_info
 * @dram_info_t: the address of dram_info
 *
 * output:
 * return 0 on success, otherwise 1
 */
int mblock_sanity_check(void *fdt, mblock_info_t *mblock_info,
		dram_info_t *dram_info) {

	u64 mblock_start, reserved_start, mblock_sz, reserved_sz;
	unsigned int i, j, sanity_fail = 0, ret = 0;
	/* check if mblock and reserved overlap*/
	mblock_version_check();
	for (i = 0; i < mblock_info->mblock_num; i++) {
		mblock_start = mblock_info->mblock[i].start;
		mblock_sz = mblock_info->mblock[i].size;
		for (j = 0; j < mblock_info->reserved_num; j++) {
			reserved_start = mblock_info->reserved[j].start;
			reserved_sz = mblock_info->reserved[j].size;
			if (((reserved_start >= mblock_start) &&
					(reserved_start < (mblock_start + mblock_sz))) || \
					((reserved_start < mblock_start) && ((reserved_start + reserved_sz) > mblock_start))) {
				sanity_fail = 1;
				dprintf(CRITICAL, "%s:%d failed i:%d j:%d %d:%d:%d:%d\n",
					__func__, __LINE__, i, j, (reserved_start >= mblock_start)\
					, (reserved_start <= (mblock_start + mblock_sz))\
					, (reserved_start < mblock_start), \
					((reserved_start + reserved_sz) > mblock_start));
			}
		}
	}

	if (sanity_fail) {
		/* print debug info */
		for (i = 0; i < mblock_info->mblock_num; i++) {
			mblock_start = mblock_info->mblock[i].start;
			mblock_sz = mblock_info->mblock[i].size;
			dprintf(CRITICAL, "mblock_reserve [%d].start: \
				0x%llx, sz: 0x%llx\n",
					i, mblock_start, mblock_sz);
		}

		for (i = 0; i < mblock_info->reserved_num; i++) {
			reserved_start = mblock_info->reserved[i].start;
			reserved_sz = mblock_info->reserved[i].size;
			dprintf(CRITICAL, "mblock_reserve-R[%d].start:\
				0x%llx, sz: 0x%llx map:%d name:%s\n",
					i, reserved_start, reserved_sz,
						mblock_info->reserved[i].mapping,\
							mblock_info->reserved[i].name);
		}
	} else {
		dprintf(INFO, "%s:PASS\n", __func__);
	}
	ret = reserved_memory_conflict_check(fdt, mblock_info);

	if (sanity_fail || ret) {
		dprintf(CRITICAL, "%s fatal error keep while (1)\n", __func__);
		while (1)
			;
	}

	return 0;

}

u64 mblock_get_memory_size(mblock_info_t *mblock_info)
{
	u64 total_size = 0;
	unsigned int i;

	for (i = 0; i < mblock_info->mblock_num; i++) {
		if (mblock_info->mblock[i].start)
			total_size += mblock_info->mblock[i].size;
	}

	for (i = 0; i < mblock_info->reserved_num; i++) {
		if (mblock_info->reserved[i].start)
			total_size += mblock_info->reserved[i].size;
	}

	return total_size;
}

const reserved_t *mblock_query_reserved
	(mblock_info_t *mblock_info, const char *name,
	reserved_t *index)
{
    reserved_t *p_reserved;

    for_each_mblock_reserved(mblock_info, p_reserved) {
        if (index && (p_reserved <= index))
            continue;
        if ((strlen(p_reserved->name) && strlen(name)) &&
                (strlen(p_reserved->name) == strlen(name)) &&
                (strncmp(p_reserved->name, name, strlen(name)) == 0)) {
            return p_reserved;
        }
    }
    return 0;
}

int mblock_query_reserved_count(mblock_info_t *mblock_info, const char *name)
{
    reserved_t *p_reserved;
    int i = 0;

    for_each_mblock_reserved(mblock_info, p_reserved) {
        if ((strlen(p_reserved->name) && strlen(name)) &&
                (strlen(p_reserved->name) == strlen(name)) &&
                (strncmp(p_reserved->name, name, strlen(name)) == 0))
            i++;
    }
    return i;
}

#endif
