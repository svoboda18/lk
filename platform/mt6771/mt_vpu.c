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
#include <stdlib.h>
#include <platform/errno.h>
#include <debug.h>
#include <platform/boot_mode.h>
#include <platform/partition.h>
#include <libfdt.h>
#include <arch/ops.h>
#include <fdt_op.h>
/*The buffer layout in DDR is as follows:
 * The total is 45MBs.
 * [phyaddr offset]                       [mapping mva]
 *  0x00000000  +-----------------------+
 *              |  Reset vector of core0      |
 *              |  code                              |
 *  0x00100000  +-----------------------+
 *              |  Main Program of core0    |
 *              |                                       |
 *  0x00400000  +-----------------------+
 *              |  Reset vector of core1      |
 *              |  code                              |
 *  0x00500000  +-----------------------+
 *              |  Main Program of core1    |
 *              |                                       |
 *  0x00800000  +-----------------------+
 *              |  Reset vector of core2      |
 *              |  code                              |
 *  0x00900000  +-----------------------+
 *              |  Main Program of core2    |
 *              |                                       |
 *  0x00C00000  +-----------------------+
 *              |  Algo Area                      |
 *              |                                      |
 *  0x02950000  +-----------------------+
 *              |  Main Prog. IRAM of core0|
 *              |  binary data                    |
 *  0x02980000  +-----------------------+
 *              |  Main Prog. IRAM of core1|
 *              |  binary data                    |
 *  0x029B0000  +-----------------------+
 *              |  Main Prog. IRAM of core2|
 *              |  binary data                    |
 *  0x029E0000  +-----------------------+
 *              |  Merged image header      |
 *              |                                       |
 *              +-----------------------+
 *
 *
 * the layout of Main Prog. IRAM
 *              +-----------------------+
 *              | num | off0| dst0|size0|
 *              | off1| dst1|size1| off2|
 *              | dst2|size2| ... |     |
 *              ...
 *              | seg0_data             |
 *              | seg0_data             |
 *              | seg1_data             |
 *              ...
 *              +-----------------------+
 * num: number of segment for IRAM program
 * off: bin data offset from start of Main Prog. IRAM
 * dst: the dst address of bin data at IRAM
 * size: size of bin data
 * seg_data: bin data
*/
extern int mboot_common_load_part(char *part_name, char *img_name, unsigned long addr);
extern void mtk_wdt_restart(void);

#define MODULE_NAME "LK_BOOT_VPU"
#define VPU_DRAM_ADDR_ALIGN    (0x00010000)
#define VPU_DRAM_ADDR_MAX      (0xA0000000)
#define VPU_DRAM_SIZE          (0x02A10000)              // total ddr size we apply for vpu
#define VPU_DRAM_PROG_OFFSET   (0x00100000)              // start address of main program (core0)
#define VPU_DRAM_ALGO_OFFSET   (0x00C00000)              // start address of algo, after 3*(reset vector+main program)
#define VPU_DRAM_IRAM_OFFSET   (VPU_DRAM_SIZE - 0xC0000) // start address of main program IRAM binary data (core0)
#define VPU_DRAM_HEADER_OFFSET (VPU_DRAM_SIZE - 0x30000) // start address of header
#define VPU_CORE_RESVEC_SHIFT  (0x00400000)              //1MB reset vector + 3 MB main program data
#define VPU_CORE_IRAM_SHIFT	   (0x0030000)               //max 192k for each iram region


#define VPU_MAX_PART_SIZE      (0x00F00000)
#define VPU_ADDR_MASK          (0xFFF00000)
#define VPU_ALIGN_MASK         (0x0000000F)              // 16 bytes alignment for algo bin and iram prog so that vpu core can use DMA to copy
static char *vpu_part_name[] = {"cam_vpu1", "cam_vpu2", "cam_vpu3"};
static int   vpu_part_size[] = {0x000C00000, 0x000F00000, 0x000F00000};
static void *vpu_m4u_base_addr[] = {0x7DA00000, 0x7DB00000, 0x7FF00000};  // m4u address, pre-defined
static void *vpu2_m4u_base_addr[] = {0x7E300000, 0x7E400000, 0x7FF00000}; // m4u address, pre-defined
static void *vpu3_m4u_base_addr[] = {0x7EC00000, 0x7ED00000, 0x7FF00000}; // m4u address, pre-defined

#ifndef MUINT32
#define MUINT32 u32
#endif
/*---------------------------------------------------------------------------*/
/*  VPU Image file definition                                                */
/*---------------------------------------------------------------------------*/
#define VPU_PARTITION_FILE_HEADER_VERSION  (0x17102311) //chanage core index to bitwise presentation.

#define VPU_CODE_SEGMENT_MAX_NUM    (50)
#define VPU_ALG_MAX_NUM             (50)
#define VPU_ALG_MAX_NAME_CHAR       (32)
#define VPU_HEADER_STR_SIZE         (32)
/*---------------------------------------------------------------------------*/
/*  VPU Image file emum                                                      */
/*---------------------------------------------------------------------------*/
typedef enum _VPU_CORE_ENUM_{
	//0x60 stands for VP6
    VPU_CORE_0 		= ( 0x60 | (0x01 << 0) ), /* bitwise to represent core index */
    VPU_CORE_1 		= ( 0x60 | (0x01 << 1) ),
    VPU_CORE_2 		= ( 0x60 | (0x01 << 2) ),
    //
    VPU_CORE_MAX    = 0x03,
}VPU_CORE_ENUM;

/*---------------------------------------------------------------------------*/
/*  VPU Image file structure                                                 */
/*---------------------------------------------------------------------------*/

typedef struct _VPU_CODE_SEGMENT_INFO_ {
	MUINT32 vpu_core;		/* core index					*/
	MUINT32 off;            /* offset                       */
	MUINT32 pAddr;          /* destination                  */
	MUINT32 memsz_byt;      /* mem. size byte to occupied   */
	MUINT32 filesz_byt;     /* file size byte to copy       */
} VPU_CODE_SEGMENT_INFO;

typedef struct _VPU_ALG_INFO_ {
	MUINT32 vpu_core;       /* core index                   */
	MUINT32 off;            /* offset                       */
	MUINT32 filesz_byt;     /* file size byte to copy       */
	char name[VPU_ALG_MAX_NAME_CHAR ];
} VPU_ALG_INFO;
typedef struct _VPU_IMAGEFILE_HEADER_ {
	int version;
	int build_date;
	int hdr_str[VPU_HEADER_STR_SIZE / 4];
	int size_byt_hdr;   /* header size       */
	int size_byt_img;   /* binary code  size */
	//
	int segment_num;
	VPU_CODE_SEGMENT_INFO segment[VPU_CODE_SEGMENT_MAX_NUM];
	//
	int alg_num;
	VPU_ALG_INFO  alg[VPU_ALG_MAX_NUM ];
	//reserved
	int reserved[VPU_HEADER_STR_SIZE];
} VPU_IMAGEFILE_HEADER;

int mt_load_vpu(void)
{
	int i, j, len, ret = 0;
	int part_offset;
	int read_size;
	u32 iram_num = 0;
	u32 iram_bin_offset = 0;
	u32 vpu_iram_bin_offset = ((4 + VPU_CODE_SEGMENT_MAX_NUM * 12) + VPU_ALIGN_MASK) & ~VPU_ALIGN_MASK;
	u32 vpu2_iram_bin_offset = ((4 + VPU_CODE_SEGMENT_MAX_NUM * 12) + VPU_ALIGN_MASK) & ~VPU_ALIGN_MASK;
	u32 vpu3_iram_bin_offset = ((4 + VPU_CODE_SEGMENT_MAX_NUM * 12) + VPU_ALIGN_MASK) & ~VPU_ALIGN_MASK;
	u32 *pIramNum, *pIram;
	void *part = NULL;
	VPU_IMAGEFILE_HEADER *part_hdr = NULL;
	char *part_name;
	int part_size;
	u32 dstHdrBase;
	u32 dstBase;
	u32 dst;
	u32 dstAlg;
#ifdef DEVICE_TREE_SUPPORT
	u64 value;
	u32 size;
	int nodeoffset;
#endif

	// get physical address
	dstBase = (u32)mblock_reserve_ext(&g_boot_arg->mblock_info, VPU_DRAM_SIZE, VPU_DRAM_ADDR_ALIGN, VPU_DRAM_ADDR_MAX, 0, "vpu_binary");
	dprintf(INFO, "[%s] phyAddr of Allocation: 0x%x\n", MODULE_NAME, dstBase);
	if (!dstBase) {
		dprintf(CRITICAL, "[%s] vpu memory allocation failed.\n", MODULE_NAME);
		return -ENOMEM;
	}
	// get header base address
	dstHdrBase = dstBase + VPU_DRAM_HEADER_OFFSET;
	dprintf(INFO, "[%s] Base PhyAddr of Header: 0x%x\n", MODULE_NAME, dstHdrBase);
	// get alg base address
	dstAlg = dstBase + VPU_DRAM_ALGO_OFFSET;
	dprintf(INFO, "[%s] Base PhyAddr of Alg: 0x%x\n", MODULE_NAME, dstAlg);

	if (SCRATCH_SIZE < VPU_MAX_PART_SIZE) {
		dprintf(CRITICAL, "[%s] SCRATCH_SIZE(0x%x) < VPU_MAX_PART_SIZE(0x%x) .\n", MODULE_NAME, SCRATCH_SIZE, VPU_MAX_PART_SIZE);
		return -ENOMEM;
	}

	part = (void *)((UINT32) SCRATCH_ADDR + SCRATCH_SIZE - VPU_DRAM_SIZE); // Not to mess with kernel zimage, use tail

#ifdef DEVICE_TREE_SUPPORT
	// set phyaddress to device tree
	nodeoffset = fdt_node_offset_by_compatible(get_kernel_fdt(), -1, "mediatek,vpu_core0");  // get vpu node offset
	dprintf(INFO, "[%s] nodeoffset %d\n", MODULE_NAME, nodeoffset);
	if (nodeoffset < 0) { // node add sub-node to /
		int offset;
		offset = fdt_path_offset(get_kernel_fdt(), "/");
		dprintf(INFO, "[%s] root offset %d\n", MODULE_NAME, offset);
		if (offset < 0) {
			dprintf(CRITICAL, "[%s] fail to get fdt offset\n", MODULE_NAME);
			ret = -EINVAL;
			goto exit;
		} else {
			nodeoffset = fdt_add_subnode(get_kernel_fdt(), offset, "vpu_core0");
			dprintf(INFO, "[%s] nodeoffset %d\n", MODULE_NAME, nodeoffset);
			if (nodeoffset < 0) {
				ret = -EINVAL;
				dprintf(CRITICAL, "[%s] fail to add subnode to fdt\n", MODULE_NAME);
				goto exit;
			} else {
				fdt_setprop_string(get_kernel_fdt(), nodeoffset, "compatible", "mediatek,vpu_core0");
			}
		}
	}

	value = cpu_to_fdt32(dstBase);
	fdt_setprop(get_kernel_fdt(), nodeoffset, "bin-phy-addr", (char *)&value, sizeof(u32));
	size = cpu_to_fdt32(VPU_DRAM_SIZE);
	fdt_setprop(get_kernel_fdt(), nodeoffset, "bin-size", (char *)&size, sizeof(u32));
#endif

	//initialization
	pIramNum  = (u32 *)(dstBase + VPU_DRAM_IRAM_OFFSET);
	*pIramNum = 0;
	pIramNum  = (u32 *)(dstBase + VPU_DRAM_IRAM_OFFSET + VPU_CORE_IRAM_SHIFT);
	*pIramNum = 0;
	pIramNum  = (u32 *)(dstBase + VPU_DRAM_IRAM_OFFSET + (VPU_CORE_IRAM_SHIFT << 1));
	*pIramNum = 0;

	for (i = 0 ; i < (sizeof(vpu_part_name)/sizeof(*vpu_part_name)) ; i++) {
#ifdef MTK_SECURITY_SW_SUPPORT
		unsigned int sec_feature_mask = 0;
		unsigned int policy_entry_idx = 0;
		unsigned int img_auth_required = 0;
		unsigned int vpu_vfy_time= 0;
#endif
		part_name = vpu_part_name[i];
		part_size = vpu_part_size[i];
#ifdef MTK_SECURITY_SW_SUPPORT
		policy_entry_idx = get_policy_entry_idx(part_name);
		img_auth_required = get_vfy_policy(policy_entry_idx);
		if (img_auth_required) {
			mtk_wdt_restart();
			vpu_vfy_time = get_timer(0);
			ret = (int)sec_img_auth_init(part_name, part_name, 0);
			if (ret) {
				dprintf(CRITICAL, "[%s] fail to verify %s cert (0x%x)\n", MODULE_NAME, part_name, ret);
				assert(0);
			}
			dprintf(CRITICAL, "[SBC] %s cert vfy pass(%d ms)\n", part_name, (unsigned int)get_timer(vpu_vfy_time));
#ifdef MTK_SECURITY_ANTI_ROLLBACK
			ret = sec_rollback_check(1);
			if (ret) {
				dprintf(CRITICAL, "[%s] fail to check %s version (0x%x)\n", MODULE_NAME, part_name, ret);
				assert(0);
			}
#endif
		}
#endif
		if ((len = mboot_common_load_part(part_name, part_name, (unsigned long)part)) < 0) {
			dprintf(CRITICAL, "[%s] vpu %s partition read error. len = %d\n", MODULE_NAME, part_name, len);
			ret = -EINVAL;
			goto exit;
		}
		arch_sync_cache_range(part, len);

		dprintf(INFO, "[%s] sync arch_sync_cache_range lens = %d\n", MODULE_NAME, len);

#ifdef MTK_SECURITY_SW_SUPPORT
		if (img_auth_required) {
			mtk_wdt_restart();
			vpu_vfy_time = get_timer(0);
			ret = (int)sec_img_auth(part, len);
			if (ret) {
				dprintf(CRITICAL, "[%s] fail to check %s hash (0x%x)\n", MODULE_NAME, part_name, ret);
				assert(0);
			}
			dprintf(CRITICAL, "[SBC] %s vfy pass(%d ms)\n", part_name, (unsigned int)get_timer(vpu_vfy_time));
		}
#endif
		// 1. read partition header
		part_offset = 0;

		read_size = sizeof(VPU_IMAGEFILE_HEADER);
		part_hdr = (VPU_IMAGEFILE_HEADER *)((u8*)part + part_offset);
		dprintf(INFO, "[%s] ============== part_name %s, len 0x%x ================= \n", MODULE_NAME, part_name, read_size);

		if (part_hdr->version != VPU_PARTITION_FILE_HEADER_VERSION) {
			dprintf(CRITICAL, "[%s] vpu version 0x%x != 0x%x\n", MODULE_NAME, part_hdr->version, VPU_PARTITION_FILE_HEADER_VERSION);
		}

		if (part_hdr->size_byt_hdr != sizeof(VPU_IMAGEFILE_HEADER)) {
			dprintf(CRITICAL, "[%s] vpu header size 0x%x != 0x%x\n", MODULE_NAME, part_hdr->size_byt_hdr, sizeof(VPU_IMAGEFILE_HEADER));
			ret = -EINVAL;
			goto exit;
		}

		part_hdr->hdr_str[VPU_HEADER_STR_SIZE/4 -1] = 0;
		dprintf(INFO, "[%s] version 0x%x, build_date 0x%x, hdr_str %s, size 0x%x, numOfSeg %d\n",
		        MODULE_NAME, part_hdr->version, part_hdr->build_date, (char *)part_hdr->hdr_str, part_hdr->size_byt_img, part_hdr->segment_num);

		if (part_hdr->size_byt_img > part_size || part_hdr->segment_num > VPU_CODE_SEGMENT_MAX_NUM) {
			dprintf(CRITICAL, "[%s] invalid parameter !! part size 0x%x, numOfSeg %d\n", MODULE_NAME, part_hdr->size_byt_img, part_hdr->segment_num);
			ret = -EINVAL;
			goto exit;
		}
		

		// 2. write segment to ddr for each segment from partition
		for (j = 0 ; j < part_hdr->segment_num ; j++) {
			VPU_CODE_SEGMENT_INFO *seg = &part_hdr->segment[j];
			dprintf(INFO, "[%s] Seg[%d] offset 0x%x, size 0x%x, dst 0x%x\n", MODULE_NAME, j, seg->off, seg->filesz_byt, seg->pAddr);
			if ((seg->pAddr & VPU_ADDR_MASK) == (MUINT32)vpu_m4u_base_addr[1]) {
				dst = dstBase + VPU_DRAM_PROG_OFFSET + (int)((uchar*)seg->pAddr - (uchar*)vpu_m4u_base_addr[1]);
				dprintf(INFO, "[%s] base 0x%x, offset 0x%x, dst 0x%x\n", MODULE_NAME, dstBase + VPU_DRAM_PROG_OFFSET, (int)((uchar*)seg->pAddr - (uchar*)vpu_m4u_base_addr[1]), dst);
			} else if ((seg->pAddr & VPU_ADDR_MASK) == (MUINT32)vpu2_m4u_base_addr[1]) {
				dst = dstBase + VPU_CORE_RESVEC_SHIFT + VPU_DRAM_PROG_OFFSET + (int)((uchar*)seg->pAddr - (uchar*)vpu2_m4u_base_addr[1]);
				dprintf(INFO, "[%s] base 0x%x, offset 0x%x, dst 0x%x\n", MODULE_NAME, dstBase + VPU_CORE_RESVEC_SHIFT + VPU_DRAM_PROG_OFFSET, (int)((uchar*)seg->pAddr - (uchar*)vpu2_m4u_base_addr[1]), dst);
			} else if ((seg->pAddr & VPU_ADDR_MASK) == (MUINT32)vpu3_m4u_base_addr[1]) {
				dst = dstBase + (VPU_CORE_RESVEC_SHIFT << 1) + VPU_DRAM_PROG_OFFSET + (int)((uchar*)seg->pAddr - (uchar*)vpu3_m4u_base_addr[1]);
				dprintf(INFO, "[%s] base 0x%x, offset 0x%x, dst 0x%x\n", MODULE_NAME, dstBase + (VPU_CORE_RESVEC_SHIFT << 1) + VPU_DRAM_PROG_OFFSET, (int)((uchar*)seg->pAddr - (uchar*)vpu3_m4u_base_addr[1]), dst);
			} else if ((seg->pAddr & VPU_ADDR_MASK) == (MUINT32)vpu_m4u_base_addr[0]) {
				dst = dstBase + (int)((uchar*)seg->pAddr - (uchar*)vpu_m4u_base_addr[0]);
				dprintf(INFO, "[%s] base 0x%x, offset 0x%x, dst 0x%x\n", MODULE_NAME, dstBase, (int)((uchar*)seg->pAddr - (uchar*)vpu_m4u_base_addr[0]), dst);
			} else if ((seg->pAddr & VPU_ADDR_MASK) == (MUINT32)vpu2_m4u_base_addr[0]) {
				dst = dstBase + VPU_CORE_RESVEC_SHIFT + (int)((uchar*)seg->pAddr - (uchar*)vpu2_m4u_base_addr[0]);
				dprintf(INFO, "[%s] base 0x%x, offset 0x%x, dst 0x%x\n", MODULE_NAME, dstBase + VPU_CORE_RESVEC_SHIFT, (int)((uchar*)seg->pAddr - (uchar*)vpu2_m4u_base_addr[0]), dst);
			} else if ((seg->pAddr & VPU_ADDR_MASK) == (MUINT32)vpu3_m4u_base_addr[0]) {
				dst = dstBase + (VPU_CORE_RESVEC_SHIFT << 1) + (int)((uchar*)seg->pAddr - (uchar*)vpu3_m4u_base_addr[0]);
				dprintf(INFO, "[%s] base 0x%x, offset 0x%x, dst 0x%x\n", MODULE_NAME, dstBase + (VPU_CORE_RESVEC_SHIFT << 1), (int)((uchar*)seg->pAddr - (uchar*)vpu3_m4u_base_addr[0]), dst);
			} else if ((seg->pAddr & VPU_ADDR_MASK) == (MUINT32)vpu_m4u_base_addr[2]) {
				switch (seg->vpu_core) {
					case VPU_CORE_0:
						dst = dstBase + VPU_DRAM_IRAM_OFFSET + vpu_iram_bin_offset;
						pIramNum  = (u32 *)(dstBase + VPU_DRAM_IRAM_OFFSET);
						iram_bin_offset = vpu_iram_bin_offset;
						vpu_iram_bin_offset += ((seg->memsz_byt + VPU_ALIGN_MASK) & ~VPU_ALIGN_MASK);
						break;
					case VPU_CORE_1:
						dst = dstBase + VPU_DRAM_IRAM_OFFSET + VPU_CORE_IRAM_SHIFT + vpu2_iram_bin_offset;
						pIramNum  = (u32 *)(dstBase + VPU_DRAM_IRAM_OFFSET + VPU_CORE_IRAM_SHIFT);	
						iram_bin_offset = vpu2_iram_bin_offset;
						vpu2_iram_bin_offset += ((seg->memsz_byt + VPU_ALIGN_MASK) & ~VPU_ALIGN_MASK);
						break;
					case VPU_CORE_2:
						dst = dstBase + VPU_DRAM_IRAM_OFFSET + (VPU_CORE_IRAM_SHIFT << 1) + vpu3_iram_bin_offset;
						pIramNum  = (u32 *)(dstBase + VPU_DRAM_IRAM_OFFSET + (VPU_CORE_IRAM_SHIFT << 1));
						iram_bin_offset = vpu3_iram_bin_offset;
						vpu3_iram_bin_offset += ((seg->memsz_byt + VPU_ALIGN_MASK) & ~VPU_ALIGN_MASK);
						break;
					default:
						dprintf(CRITICAL, "[%s] wrong seg->core info %d\n", MODULE_NAME, seg->vpu_core);
						break;
				}				
				dprintf(INFO, "[%s] iram[%d/%d] offset 0x%x, dst_addr 0x%x, size 0x%x, dst 0x%x\n", MODULE_NAME, \
					seg->vpu_core, iram_num, iram_bin_offset, seg->pAddr, seg->memsz_byt, dst);
				//update iram descriptor
				dprintf(INFO, "[%s] (*pIramNum)[%d]\n", MODULE_NAME, (*pIramNum));
				//shift starting position of iram info in descriptor for same core
				pIram     = (pIramNum + 1) + (3 * (*pIramNum)); 
				*pIram++= iram_bin_offset;
				*pIram++= seg->pAddr;
				*pIram++= seg->memsz_byt;
				iram_num++;	
				*pIramNum = ((*pIramNum) + 1);
			} else {
				dprintf(CRITICAL, "[%s] invalid parameter !! seg->pAddr 0x%x\n", MODULE_NAME, seg->pAddr);
				ret = -EINVAL;
				goto exit;
			}
			part_offset = seg->off;
			read_size   = seg->filesz_byt;
			dprintf(INFO, "[%s] seg[%d]: copy size 0x%x from part_offset 0x%x to dst 0x%x\n", MODULE_NAME, j, seg->filesz_byt, seg->off, dst);
			if (seg->filesz_byt > 0) {
				if (part_offset + read_size > part_size) {
					dprintf(CRITICAL, "[%s] %s partition offset error, offset 0x%x, read_size 0x%x\n", MODULE_NAME, part_name, part_offset, read_size);
					ret = -EINVAL;
					goto exit;
				} else {
					memcpy((void *)dst,(void *)((u8*)part + part_offset) , read_size);
				}
			}
			len = seg->memsz_byt - seg->filesz_byt;
			if (len > 0) {
				dprintf(INFO, "[%s] seg[%d]: memset size 0x%x from dst 0x%x\n", MODULE_NAME, j, len, dst);
				memset((void*)(dst + seg->filesz_byt), 0, len);
			}
		}

		// 3. write algo to ddr
		dprintf(INFO, "[%s] part_hdr->alg_num %d\n", MODULE_NAME, part_hdr->alg_num);
		if (part_hdr->alg_num > VPU_ALG_MAX_NUM) {
			dprintf(CRITICAL, "[%s] invalid parameter !! part_hdr->alg_num %d\n", MODULE_NAME, part_hdr->alg_num);
			ret = -EINVAL;
			goto exit;
		}
		for (j = 0 ; j < part_hdr->alg_num ; j++) {
			VPU_ALG_INFO *alg = &part_hdr->alg[j];
			part_offset = alg->off;
			read_size   = alg->filesz_byt;
			dprintf(INFO, "[%s] alg[%d]: copy size 0x%x from part_offset 0x%x to dstAlg 0x%x\n", MODULE_NAME, j, alg->filesz_byt, alg->off, dstAlg);
			if (part_offset + read_size > part_size) {
				dprintf(CRITICAL, "[%s] %s partition offset error, offset 0x%x, read_size 0x%x\n", MODULE_NAME, part_name, part_offset, read_size);
				ret = -EINVAL;
				goto exit;
			} else {
				memcpy((void *)dstAlg,(void *)((u8*)part + part_offset) , read_size);
			}

			// 3.1. modify alg offset in partition header, let driver to get real offset from start vpu addr in ddr
			alg->off = (int)(dstAlg - dstBase);
			dprintf(INFO, "[%s] alg[%d], modify alg offset to 0x%x, dstAlg 0x%x, dstBase 0x%x\n", MODULE_NAME, j, alg->off, dstAlg, dstBase);
			dstAlg += ((alg->filesz_byt + VPU_ALIGN_MASK) & ~VPU_ALIGN_MASK);
		}

		// 4. write partition header to ddr
		dprintf(INFO, "[%s] copy partition header to 0x%x\n", MODULE_NAME, dstHdrBase + sizeof(VPU_IMAGEFILE_HEADER)*i);
		memcpy((void *)(dstHdrBase + sizeof(VPU_IMAGEFILE_HEADER)*i),(void *)part_hdr , sizeof(VPU_IMAGEFILE_HEADER));
	}

exit:

	return ret;
}
