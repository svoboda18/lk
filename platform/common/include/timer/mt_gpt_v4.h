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

#ifndef __MT_GPT_H__
#define __MT_GPT_H__
#include <platform/mt_typedefs.h>
#include <sys/types.h>

#define GPT_IRQEN_REG       ((volatile unsigned int*)(APXGPT_BASE))
#define GPT_IRQSTA_REG      ((volatile unsigned int*)(APXGPT_BASE+0x04))
#define GPT_IRQACK_REG      ((volatile unsigned int*)(APXGPT_BASE+0x08))

#define GPT5_CON_REG        ((volatile unsigned int*)(APXGPT_BASE+0x50))
#define GPT5_CLK_REG        ((volatile unsigned int*)(APXGPT_BASE+0x54))
#define GPT5_COUNT_REG      ((volatile unsigned int*)(APXGPT_BASE+0x58))
#define GPT5_COMPARE_REG    ((volatile unsigned int*)(APXGPT_BASE+0x5C))

#define GPT_MODE4_ONE_SHOT (0x00 << 4)
#define GPT_MODE4_REPEAT   (0x01 << 4)
#define GPT_MODE4_KEEP_GO  (0x02 << 4)
#define GPT_MODE4_FREERUN  (0x03 << 4)

#define GPT_CLEAR       2

#define GPT_ENABLE      1
#define GPT_DISABLE     0

#define GPT_CLK_SYS     (0x0 << 4)
#define GPT_CLK_RTC     (0x1 << 4)

#define GPT_DIV_BY_1        0
#define GPT_DIV_BY_2        1

#define CNTPCT_BIT_MASK_L 0x00000000FFFFFFFF
#define CNTPCT_1US_TICK       ((U32)13)           //    1000 / 76.92ns = 13.000
#define CNTPCT_1MS_TICK       ((U32)13000)        // 1000000 / 76.92ns = 13000.520

static inline U64 arch_counter_get_cntpct(void)
{
	U64 cval;

	__asm__ __volatile__("mrrc p15, 0, %Q0, %R0, c14" : "=r" (cval));
	return cval;
}

extern void gpt_busy_wait_us(unsigned int timeout_us);
extern void gpt_busy_wait_ms(unsigned int timeout_ms);

extern unsigned long get_timer(unsigned long base);
extern void mdelay(unsigned long msec);
extern void udelay(unsigned long usec);
extern void mtk_timer_init(void);

void gpt_one_shot_irq(unsigned int ms);
int gpt_irq_init(void);
void gpt_irq_ack();
extern unsigned int gpt4_tick2time_us (unsigned int tick);
extern unsigned int gpt4_get_current_tick (void);
extern bool gpt4_timeout_tick (U32 start_tick, U32 timeout_tick);
extern U32 gpt4_time2tick_us (U32 time_us);

#endif  /* !__MT_GPT_H__ */
