/*
 * Copyright (c) 2008 Travis Geiselbrecht
 *
 * Copyright (c) 2009, Code Aurora Forum. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <compiler.h>
#include <debug.h>
#include <string.h>
#include <app.h>
#include <arch.h>
#include <platform.h>
#include <target.h>
#include <lib/heap.h>
#include <kernel/thread.h>
#include <kernel/timer.h>
#include <kernel/dpc.h>
#include <platform/mt_gpt.h>
#include <iothread.h>
#include <version.h>

#ifdef MTK_LK_IRRX_SUPPORT
#include <platform/mtk_ir_lk_core.h>
#endif

extern void (*__ctor_list[])(void);
extern void (*__ctor_end[])(void);
extern int __bss_start;
extern int _end;

extern void mboot_allocate_lk_scratch_from_mblock(void);

/* boot_time is calculated form kmain to kernel jump */
volatile unsigned int boot_time = 0;


static int bootstrap2(void *arg);

#if (ENABLE_NANDWRITE)
void bootstrap_nandwrite(void);
#endif

static void print_stack_of_current_thread(void)
{
	extern thread_t *current_thread;
	if (current_thread)
	{
		char *stack_limit = current_thread->stack;
		char *stack_bottom = stack_limit + current_thread->stack_size;
		dprintf(CRITICAL, "thread: %s, bottom(stack) = %p, limit(stack) = %p\n",
			current_thread->name, stack_bottom, stack_limit);
	}
}

static void call_constructors(void)
{
	void (**ctor)(void);

	for (ctor = __ctor_list; ctor != __ctor_end; ctor++)
		(*ctor)();
}

/* called from crt0.S */
void kmain(void) __NO_RETURN __EXTERNALLY_VISIBLE;
void kmain(void)
{
#if !defined(MACH_FPGA) && !defined(SB_LK_BRINGUP)
	boot_time = get_timer(0);
#endif

	// get us into some sort of thread context
	thread_init_early();

	// early arch stuff
	arch_early_init();

	// do any super early platform initialization
	platform_early_init();

#if defined(MACH_FPGA) || defined(SB_LK_BRINGUP)
	boot_time = get_timer(0);
#endif

	// do any super early target initialization
	target_early_init();

	dprintf(INFO, "welcome to lk\n\n");
	dprintf(INFO, "LK_VER_TAG = %s\n", LK_VER_TAG);

	// deal with any static constructors
	dprintf(SPEW, "calling constructors\n");
	call_constructors();

	// bring up the kernel heap
	dprintf(SPEW, "initializing heap\n");
	heap_init();

	// initialize the threading system
	dprintf(SPEW, "initializing threads\n");
	thread_init();

	// initialize the dpc system
	dprintf(SPEW, "initializing dpc\n");
	dpc_init();

	// initialize kernel timers
	dprintf(SPEW, "initializing timers\n");
	timer_init();

#ifdef  MTK_LK_IRRX_SUPPORT
   mtk_ir_init(0);
#endif


#if (!ENABLE_NANDWRITE)
	// create a thread to complete system initialization
	dprintf(SPEW, "creating bootstrap completion thread\n");

	thread_t *thread_bs2 = thread_create("bootstrap2", &bootstrap2, NULL,
		DEFAULT_PRIORITY, DEFAULT_STACK_SIZE);
	if (thread_bs2)
		thread_resume(thread_bs2);
	else {
		dprintf(CRITICAL, "Error: Cannot create bootstrap2 thread!\n");
		assert(0);
	}

	thread_t *thread_io = thread_create("iothread", &iothread, NULL,
		IO_THREAD_PRIORITY, DEFAULT_STACK_SIZE);
	if (thread_io)
		thread_resume(thread_io);
	else {
		dprintf(CRITICAL, "Error: Cannot create I/O thread!\n");
		assert(0);
	}

	// enable interrupts
	exit_critical_section();

	// become the idle thread
	thread_become_idle();
#else
        bootstrap_nandwrite();
#endif
}


static int bootstrap2(void *arg)
{
	dprintf(SPEW, "top of bootstrap2()\n");

	print_stack_of_current_thread();

	arch_init();

	// XXX put this somewhere else
#if WITH_LIB_BIO
	bio_init();
#endif
#if WITH_LIB_FS
	fs_init();
#endif
	// Allocate LK memory from mb, free before jump to kernel
	mboot_allocate_lk_scratch_from_mblock();

	// initialize the rest of the platform
	dprintf(SPEW, "initializing platform\n");
	platform_init();

	// initialize the target
	dprintf(SPEW, "initializing target\n");
	target_init();

	dprintf(SPEW, "calling apps_init()\n");
	apps_init();

	return 0;
}

#if (ENABLE_NANDWRITE)
void bootstrap_nandwrite(void)
{
	dprintf(SPEW, "top of bootstrap2()\n");

	arch_init();

	// initialize the rest of the platform
	dprintf(SPEW, "initializing platform\n");
	platform_init();

	// initialize the target
	dprintf(SPEW, "initializing target\n");
	target_init();

	dprintf(SPEW, "calling nandwrite_init()\n");
	nandwrite_init();

	return 0;
}
#endif
