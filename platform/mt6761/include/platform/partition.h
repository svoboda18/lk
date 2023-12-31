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

#ifndef __PARTITION_H__
#define __PARTITION_H__

#include <platform/mt_typedefs.h>
#include <part.h>
#include <part_dev.h>

#define BIMG_HEADER_SZ              (0x800)
#define MKIMG_HEADER_SZ             (0x200)

#define PART_HDR_DATA_SIZE	512

#define PART_KERNEL     "KERNEL"
#define PART_ROOTFS     "ROOTFS"

#define PART_MAGIC          0x58881688
#define PART_EXT_MAGIC      0x58891689
#define PART_MAX_COUNT      128
#define PART_PRELOADER_SIZE (0x200)

#define FRP_NAME        "frp"

typedef union {
	struct {
		unsigned int magic;        /* partition magic */
		unsigned int dsize;        /* partition data size */
		char         name[32];     /* partition name */
		unsigned int maddr;        /* partition memory address */
		unsigned int mode;      /* maddr is counted from the beginning or end of RAM */
		/* extension */
		unsigned int ext_magic;    /* always EXT_MAGIC */
		unsigned int hdr_size;     /* header size is 512 bytes currently, but may extend in the future */
		unsigned int hdr_version;  /* see HDR_VERSION */
		unsigned int img_type;     /* please refer to #define beginning with IMG_TYPE_ */
		unsigned int img_list_end; /* end of image list? 0: this image is followed by another image 1: end */
		unsigned int align_size;   /* image size alignment setting in bytes, 16 by default for AES encryption */
		unsigned int dsize_extend; /* high word of image size for 64 bit address support */
		unsigned int maddr_extend; /* high word of image load address in RAM for 64 bit address support */
	} info;
	unsigned char data[PART_HDR_DATA_SIZE];
} part_hdr_t;

#endif /* __PARTITION_H__ */

