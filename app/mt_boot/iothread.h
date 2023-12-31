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
*/

#include <kernel/event.h>		// for event_t
#include <platform/boot_mode.h>		// for BOOTMODE


/******************************************************************************
******************************************************************************/
#define IO_THREAD_PRIORITY (DEFAULT_PRIORITY + 1)


/******************************************************************************
******************************************************************************/
extern event_t iothread_start_event;
extern event_t iothread_end_event;


/******************************************************************************
******************************************************************************/
#define wake_up_iothread()                                                    \
	do {                                                                  \
		dprintf(INFO, "Wake up iothread.\n");                         \
		event_signal(&iothread_start_event, false);                   \
	} while (0)


/******************************************************************************
******************************************************************************/
#define wait_for_iothread()                                                   \
	do {                                                                  \
		dprintf(INFO, "Wait for iothread...\n");                      \
		event_wait(&iothread_end_event);                              \
		event_unsignal(&iothread_end_event);                          \
		dprintf(INFO, "Met iothread.\n");                             \
	} while (0)


/******************************************************************************
******************************************************************************/
#define wake_up_bootstrap2()                                                  \
	do {                                                                  \
		dprintf(INFO, "Wake up bootstrap2.\n");                       \
		event_signal(&iothread_end_event, true);                      \
	} while (0)


/******************************************************************************
******************************************************************************/
#define wait_for_bootstrap2()                                                 \
	do {                                                                  \
		dprintf(INFO, "Wait for bootstrap2...\n");                    \
		event_wait(&iothread_start_event);                            \
		event_unsignal(&iothread_start_event);                        \
		dprintf(INFO, "Met bootstrap2.\n");                           \
	} while (0)


/******************************************************************************
******************************************************************************/
void load_images(BOOTMODE mode);
int iothread(void *arg);


