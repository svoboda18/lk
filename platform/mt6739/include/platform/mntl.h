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
/* MNTL exported function header file */

#ifndef __MNTL_H__
#define __MNTL_H__

#include <mntl_types.h>

struct mntl_handler;

/* MNTL debug flags, user can set this to enable debugging features in core */
extern u32 mntl_debug_flags;

/* Time out callback function type */
typedef void (*mntl_time_out_func)(void *userdata);

/**
 * mntl_init - FTL initialization
 *
 * Initialize mntl map and buffer, and scan nand
 * On success a pointer to struct mntl_handler is returned,
 * otherwise NULL is returned.
 *
 */
struct mntl_handler *mntl_init(void);

/**
 * set time out callback function for write time out
 *
 * Write operations might take very long time. In order to cut latency,
 * mntl_write and GC operations will invoke time out callback once in a
 * while. User can process important/read operations in the callback.
 *
 * Only read-only operations like mntl_read are allowed in callback function.
 */
void mntl_set_time_out_callback(struct mntl_handler *mntl,
				mntl_time_out_func func, void *userdata);

/**
 * mntl_read - Read one or a group of sectors
 * @h: the mntl handler
 * @first_sector: the first sector address of scatter list
 * @list: the pointer to scatter list which contains the required number of
 *           sectors and the related buffers
 *
 * Read the continuous sectors starting from @first_sector,
 * the number of sectors is specified by @list->size.
 * The returned data is put in the memory pointed by @list->address[]
 * Return: 0 Success, <0 Fail error code
 *
 */
int mntl_read(struct mntl_handler *mntl,
		mntl_sector first_sector, struct mntl_scatter_list *list);

/**
 * mntl_write - write one or a group of sectors
 * @mntl: the mntl handler
 * @first_sector: the first sector address of scatter list
 * @list: the pointer to the scatter list which contains the required number
 *           of sectors and the related buffers
 *
 * Write the continuous sectors starting from @first_sector,
 * the number of sectors is specified by @list->size.
 * The data to be written to nand is in the memory pointed by list->address[]
 * Return: 0 Success, <0 Fail error code
 *
 */
int mntl_write(struct mntl_handler *mntl,
		mntl_sector first_sector, struct mntl_scatter_list *list);

/**
 * mntl_discard - clear the mapping
 * @mntl: the mntl handler
 * @first_sector: the first sector address of scatter list
 * @num: the number of sectors to be discarded
 *
 * Return: 0 Success, <0 Fail error code
 *
 */
int mntl_discard(struct mntl_handler *mntl, mntl_sector start_sector, int num);

/**
 * mntl_flush - flush all buffer to nand device
 * @mntl: the mntl handler
 * @sync: true if return after write finished, false if return immediately
 *
 * Return: 0 Success, <0 Fail error code
 *
 */
int mntl_flush(struct mntl_handler *mntl, bool sync);

/**
 * mntl_commit - commit ftl config info
 *
 * @mntl: the mntl handler
 *
 * Return: 0 Success, <0 Fail error code
 *
 */
int mntl_commit(struct mntl_handler *mntl);

/**
 * mntl_get_sector_num - return number of sector in mntl
 *
 * @mntl: the mntl handler
 *
 * Return: number of sector in mntl
 *
 */
mntl_sector mntl_get_sector_num(struct mntl_handler *mntl);

/**
 * Set MNTL device as read only.
 * @return: 0 Success, <0 Fail error code
 *
 * Set MNTL device as read only. After this function return success,
 * all write operations will be prohibited and return -EROFS.
 *
 * Before actually set MNTL as read only, this function will commit and
 * close current log block. It is safe to shutdown system after calling
 * this function.
 *
 * NOTE: After the device is set read-only, there are no way to make it
 *       read-write again.
 */
int mntl_set_read_only(struct mntl_handler *mntl);

/**
 * mntl_deinit - free allocated memory for @mntl
 * @mntl: the mntl handler
 *
 * return: 0 Success, <0 Fail error code
 *
 */
int mntl_deinit(struct mntl_handler *mntl);

/** MNTL maintenance request type */
enum MNTL_MAINT_REQUEST {
	MNTL_MAINT_NONE,
	MNTL_MAINT_DELAYED,
	MNTL_MAINT_IDLE,
	MNTL_MAINT_SLEEP,
};

/**
 * mntl_maintenance - Back ground maintenance
 * @param type: current maintenance type. See @MNTL_MAINT_REQUEST
 * @return: < 0 error while maintenance. >=0 next expected maintenance type.
 *          User is expected to call this function again at the time.
 *
 * Back ground maintenance try to perform MNTL maintenance when system
 * is idle.
 * After upper layer execute any non-maintenance MNTL operations
 * (eg, read/write/discard/commit), it should call mntl_maintenance
 * when it completed all current requests. This function will return
 * if further maintenance are necessary and when. User is expected to
 * call back at specified idle time when the system is idle.
 */
int mntl_maintenance(struct mntl_handler *mntl, enum MNTL_MAINT_REQUEST type);

#endif /* __MNTL_H__ */
