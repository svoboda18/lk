/*
 * MediaTek Inc. (C) 2016. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly
 * prohibited.
 */
/* MNTL basic type header file */

#ifndef __MNTL_TYPES_H__
#define __MNTL_TYPES_H__

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
/* typedef _Bool bool; */

typedef u64 mntl_size;
typedef u32 mntl_sector;

#ifndef NULL
#define NULL 0
#endif

#define false 0
#define true 1


struct mntl_scatter_list {
	void *address;
	u32 size;
};

#endif /* __MNTL_TYPES_H__ */

