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
/* MNTL os porting layer header file */

#ifndef __MNTL_OS_LAYER_H__
#define __MNTL_OS_LAYER_H__

#include <mntl_types.h>
#include <errno.h>

/*
 * level used with os_print
 *   ERROR will be printed in all build/cases
 *   DEBUG only available when build witn MNTL_DEBUG
 */
#define MNTL_PR_ERROR	0
#define MNTL_PR_WARN	1
#define MNTL_PR_INFO	2
#define MNTL_PR_DEBUG	3

/*
 * allocate memory and memset zero, see calloc
 * @nmemb:  Number of element to allocate
 * @size:   Size of each element
 */
void *os_calloc(mntl_size nmemb, mntl_size size);

/*
 * Free a buffer allocated by os_calloc
 * @buf:  Buffer to free. os_free will just return if it is NULL.
 */
void os_free(void *buf);

/*
 * print message
 * @level: level of this message, see MNTL_PR_*
 * @fmt:   printf format to print.
 *
 * The message might be only going internal buffer or completely dropped
 * based on level and system build.
 */
void os_print(int level, const char *fmt, ...);

/*
 * format string
 * @buf:   output buffer
 * @size:  size of the buffer.
 * @fmt:   printf format to print.
 *
 * see standard C snprintf
 */
extern __attribute__((format(printf, 3, 4)))
int os_snprintf(char *buf, int size, const char *fmt, ...);

/* see memcpy */
void *os_memcpy(void *dest, const void *src, mntl_size n);

/* see memset */
void *os_memset(void *dest, int s, mntl_size n);

#if 0
/* opaque handle for fast lock */
typedef void *mntl_lock;

/* create a lock */
mntl_lock os_lock_create(void);

/* destroy lock */
int os_lock_destroy(mntl_lock lock);

/* Acquire the lock. This is fast lock, expect the lock to be released soon */
int os_lock(mntl_lock lock);

/* Release the lock */
int os_unlock(mntl_lock lock);
#endif

/* Abort the system. Should only be used when debug. */
void os_abort(void);

#if 0
/* Get current system timestemp in ns */
unsigned long long os_current_time(void);

typedef size_t (*mtk_btag_seq_f) (struct seq_file *);
char *os_get_task_comm(char *buf, struct task_struct *tsk);
unsigned long long os_sched_clock(void);
typedef int (*mtk_btag_pidlog_add_f)(void *q, pid_t pid, __u32 len, int rw);
struct mtk_blocktag *os_mtk_btag_alloc(const char *name, int major,
    unsigned ringtrace_count, size_t ctx_size, unsigned ctx_count,
    mtk_btag_seq_f seq_show, mtk_btag_pidlog_add_f pidlog_add);
#endif

#endif /* __MNTL_OS_LAYER_H__ */
