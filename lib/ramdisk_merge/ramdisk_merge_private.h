/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2018. All rights reserved.
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
#if !defined (__RAMDISK_MERGE_PRIVATE__)
#define __RAMDISK_MERGE_PRIVATE__


/* zlib parameters */
#define WINDOWBITS 15
#define GZIP_ENCODING 16

#define RAMDISK_NO_COMPRESSION
#ifdef RAMDISK_NO_COMPRESSION
#define COMPRESSION_LEVEL   Z_NO_COMPRESSION
#else
#define COMPRESSION_LEVEL   Z_DEFAULT_COMPRESSION
#endif
#define UNCOMPRESS_GUARD_BUFFER 1024

#ifndef IS_ALIGNED
#define IS_ALIGNED(a, b) (!((a) & ((b)-1)))
#endif /* IS_ALIGNED */

#ifndef ALIGN
#define ALIGN(x, a) (((x) + ((a) -1)) & ~((a) -1))
#endif

#define GZIP_HEADER_UNCOMPRESSED_DATA_SIZE_OFFSET_TAIL  4

#if _WIN32
#define dprintf(CRITICAL, fmt, args...) printf(fmt, ##args)
#endif

#define RM_DEBUG(fmt, args...) do {dprintf(CRITICAL, "[RAMDISK_M]"fmt, ##args);} while (0)

#define validate_ramdisk_buf(rm_ptr) {\
	assert(rm_ptr->decomp_buf); \
	assert(rm_ptr->comp_buf); \
}
/*
 * mkbootfs will pad 0x0 to make sure cpio archive size is 0xff alignment.
 * Search additional 256 byte.
 */
#define SEARCH_FROM_TAIL_SIZE (0xff + 0x100)
extern int gunzip(unsigned char *src, unsigned long *lenp, void *dst, int dstlen);
#endif  /* __RAMDISK_MERGE_PRIVATE__ */
