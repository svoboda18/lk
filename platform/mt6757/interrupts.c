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

#include <arch/arm.h>
#include <reg.h>
#include <kernel/thread.h>

#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_gpt.h>
#include <platform/mt_irq.h>
#include <mt_gic.h>
#include <platform/boot_mode.h>


#include <debug.h>

#define MPIDR_LEVEL_BITS 8
#define MPIDR_LEVEL_MASK    ((1 << MPIDR_LEVEL_BITS) - 1)
#define MPIDR_AFFINITY_LEVEL(mpidr, level) \
        ((mpidr >> (MPIDR_LEVEL_BITS * level)) & MPIDR_LEVEL_MASK)


extern uint32_t mt_mpidr_read(void);
extern void lk_scheduler(void);
extern void lk_usb_scheduler(void);
extern void lk_nand_irq_handler(unsigned int irq);
extern void lk_msdc_irq_handler(unsigned int irq);
extern void dummy_ap_irq_handler(unsigned int irq)__attribute__((weak)); /* this function is empty for normal load */

extern BOOT_ARGUMENT    *g_boot_arg;

uint64_t mt_irq_get_affinity(void)
{
	uint64_t mpidr, aff;
	int mp0off;

#ifdef MACH_FPGA
	mp0off = 0;
#else
#ifdef MTK_FORCE_CLUSTER1
	mp0off = 1;
#elif defined(MTK_CAN_FROM_CLUSTER1)
	mp0off = (get_devinfo_with_index(8) & 0x80) ? 1 : 0;
#else
	mp0off = 0;
#endif
#endif
	mpidr = (uint64_t) mt_mpidr_read();

	aff = (
//			MPIDR_AFFINITY_LEVEL(mpidr, 3) << 32 |
	          MPIDR_AFFINITY_LEVEL(mpidr, 2) << 16 |
	          MPIDR_AFFINITY_LEVEL(mpidr, 1) << 8  |
	          MPIDR_AFFINITY_LEVEL(mpidr, 0)
	      );

	/*
	 * cluster id + 1 when mp0 off
	 */
	if (mp0off)
		aff += (1 << 8);

	return aff;
}

uint32_t mt_interrupt_needed_for_secure(void)
{
#if defined(MACH_FPGA) && defined(FPGA_BOOT_FROM_LK)
	return 1;
#endif

	if (g_boot_arg->boot_mode == DOWNLOAD_BOOT)
		return 1;

	return 0;
}

enum handler_return platform_irq(struct arm_iframe *frame)
{
	unsigned int irq = mt_irq_get();

	if (irq == MT_GPT_IRQ_ID)
		lk_scheduler();
	else if (irq == MT_USB0_IRQ_ID)
		lk_usb_scheduler();
#ifndef MTK_EMMC_SUPPORT
	else if (irq == MT_NFI_IRQ_ID)
		lk_nand_irq_handler(irq);
#endif
	else if (irq == MT_MSDC0_IRQ_ID || irq == MT_MSDC1_IRQ_ID)
		lk_msdc_irq_handler(irq);

	if (dummy_ap_irq_handler)
		dummy_ap_irq_handler(irq);

	//return INT_NO_RESCHEDULE;
	return INT_RESCHEDULE;
}

void platform_fiq(struct arm_iframe *frame)
{

}
