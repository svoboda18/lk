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
/* MNTL os porting layer - Linux Kernel implementation */

//#include <linux/slab.h>
//#include <linux/printk.h>
//#include <linux/string.h>
//#include <linux/spinlock.h>
//#include <linux/bug.h>
#include <printf.h>
#include <string.h>
#include <malloc.h>

#include <mntl_os.h>

void *os_calloc(mntl_size nmemb, mntl_size size)
{
	return calloc(nmemb, size);
}

void os_free(void *buf)
{
	free(buf);
}

static const char level_str[][sizeof("KERN_WARNING")] = {
	"KERN_ERR",
	"KERN_WARNING",
	"KERN_INFO",
	"KERN_DEBUG",
};

void os_print(int level, const char *fmt, ...)
{
	char buf[128];
	va_list ap;

	if (level > MNTL_PR_DEBUG)
		level = MNTL_PR_DEBUG;

	if (strlen(fmt) < sizeof(buf) - 8) {
		snprintf(buf, sizeof(buf), "%smntl: %s", level_str[level], fmt);
		fmt = buf;
	}

	va_start(ap, fmt);
	_dvprintf(fmt, ap);
	va_end(ap);
}

int os_snprintf(char *buf, int size, const char *fmt, ...)
{
	va_list ap;
	int ret;

	va_start(ap, fmt);
	ret = vsnprintf(buf, size, fmt, ap);
	va_end(ap);
	return ret;
}

void *os_memcpy(void *dest, const void *src, mntl_size n)
{
	return memcpy(dest, src, n);
}

void *os_memset(void *dest, int s, mntl_size n)
{
	return memset(dest, s, n);
}

#if 0
mntl_lock os_lock_create(void)
{
	spinlock_t *lock;

	lock = kmalloc(sizeof(spinlock_t), GFP_KERNEL | __GFP_ZERO);
	spin_lock_init(lock);
	return lock;
}

int os_lock_destroy(mntl_lock lock)
{
	kfree(lock);
	return 0;
}

int os_lock(mntl_lock lock)
{
	spin_lock((spinlock_t *)lock);
	return 0;
}

int os_unlock(mntl_lock lock)
{
	spin_unlock((spinlock_t *)lock);
	return 0;
}
#endif

void os_abort(void)
{
	return;
}

#if 0
unsigned long long os_current_time(void)
{
	struct timespec64 ts;

	getnstimeofday64(&ts);
	return ts.tv_sec*1000000000ULL + ts.tv_nsec;
}
#endif
