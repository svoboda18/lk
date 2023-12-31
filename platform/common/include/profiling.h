/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */

/* MediaTek Inc. (C) 2017. All rights reserved.
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
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
 * applicable license agreements with MediaTek Inc.
 */

#ifndef __PROFILING_H__
#define __PROFILING_H__

#include <pal_typedefs.h>
#include <pal_timer.h>

#define NUM_TIME_SLOT  (10)

struct profile_slot_info {
	char *name;
	uint32_t time;
};

/* definitions */
struct profile_info {
	/* updated each time profiling_start is called */
	uint32_t start_time;
	uint32_t running;
	/* used to record current time slot used */
	uint32_t cur_time_slot_idx;
	/* used to break down time elapsed of multiple sections */
	struct profile_slot_info time[NUM_TIME_SLOT];
};

/* functions */

/* enable/disable profiling */
void set_profiling_enable(uint32_t enable);
/* reset profile info structure */
void profiling_reset(struct profile_info *ctx);
/* start profiling */
void profiling_start(struct profile_info *ctx, char *prompt_str,
		     char *time_slot_name);
/* record time elapsed in current section and move to next section */
void profiling_stop(struct profile_info *ctx, char *prompt_str,
		    uint32_t advance_time_slot);
/* end profilng */
void profiling_end(struct profile_info *ctx, char *prompt_str);

extern unsigned int g_profile_level;

#define PROFILING_PRINTF(FMT, ...) dprintf(CRITICAL, "[PROFILE] ::: lvl(%d) " FMT "\n", \
						g_profile_level, ##__VA_ARGS__)

#define PROFILING_START(MSG) { char *msg = MSG; \
				unsigned int __profile_start = get_timer(0); \
				g_profile_level++;

#define PROFILING_END()	PROFILING_PRINTF("%s takes %d ms", \
						msg, \
						(int)get_timer(__profile_start)); \
						g_profile_level--; \
						}

#endif /* __PROFILING_H__ */

