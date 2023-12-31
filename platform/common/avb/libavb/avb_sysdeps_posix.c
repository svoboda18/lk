/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <endian.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avb_sysdeps.h"
#include <pal_log.h>
#include <load_vfy_boot.h>
#include <assert.h>

uint32_t g_avb_heap_cur_alloc = 0;

#define MOD "AVB20"

int avb_memcmp(const void *src1, const void *src2, size_t n)
{
	return memcmp(src1, src2, n);
}

void *avb_memcpy(void *dest, const void *src, size_t n)
{
	return memcpy(dest, src, n);
}

void *avb_memset(void *dest, const int c, size_t n)
{
	return memset(dest, c, n);
}

int avb_strcmp(const char *s1, const char *s2)
{
	return strcmp(s1, s2);
}

size_t avb_strlen(const char *str)
{
	return strlen(str);
}

void avb_abort(void)
{
	pal_log_err("[%s] something error!", MOD);
	assert(0);
}

void avb_print(const char *message)
{
	pal_log_err("%s", message);
}

void avb_printv(const char *message, ...)
{
	va_list ap;
	const char *m;

	va_start(ap, message);
	for (m = message; m != NULL; m = va_arg(ap, const char *))
		pal_log_err("%s", m);
	va_end(ap);
}

void *avb_malloc_(size_t size)
{
	uint32_t given_size = 0;
	uint32_t ret_addr = 0;
	uint32_t heap_max_size = avb_heap_sz;

	/* the size is bytes */
	if (size == 0) {
		pal_log_err("[%s] malloc: try to allocate size zero\n", MOD);
		return NULL;
	}

	if (size > heap_max_size) {
		pal_log_err("[%s] malloc: heap size too small\n", MOD);
		return NULL;
	}

	if ((g_avb_heap_cur_alloc + size) > heap_max_size) {
		pal_log_err("[%s] malloc: heap size not enough\n", MOD);
		return NULL;
	}

	/* alignment to 4 bytes */
	given_size = ((size + 3) / 4) * 4;

	ret_addr = (uint32_t)avb_heap + g_avb_heap_cur_alloc;
	g_avb_heap_cur_alloc += given_size;

	return (void *)ret_addr;
}

void avb_free(void *ptr)
{
	return;
}

uint32_t avb_div_by_10(uint64_t* dividend)
{
  uint32_t rem = (uint32_t)(*dividend % 10);
  *dividend /= 10;
  return rem;
}
