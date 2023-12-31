/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2008. All rights reserved.
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

#ifndef __DISP_DRV_LOG_H__
#define __DISP_DRV_LOG_H__

#ifdef USER_BUILD
#define DISP_DFINFO     (1)
#else
#define DISP_DFINFO     (0)
#endif

#define DISP_LOG_PRINT(level, sub_module, fmt, arg...)      \
    do {                                                    \
        dprintf(DISP_DFINFO,"DISP/"fmt, ##arg);                          \
    }while(0)

#define LOG_PRINT(level, module, fmt, arg...)               \
    do {                                                    \
        dprintf(DISP_DFINFO,fmt, ##arg);                                 \
    }while(0)



#define DISPMSG(string, args...) dprintf(DISP_DFINFO,"[DISP]"string, ##args)  // default on, important msg, not err
#define DISPDBG(string, args...) dprintf(DISP_DFINFO,"[DISP]"string, ##args)  // default on, important msg, not err
#define DISPERR(string, args...) dprintf(DISP_DFINFO,"[DISP]ERROR:"string, ##args)  //default on, err msg
#define DISPFUNC()               dprintf(DISP_DFINFO,"[DISP]func|%s\n", __func__)

#define DISPCHECK(string, args...) dprintf(DISP_DFINFO,"[DISPCHECK]"string, ##args)
#define DISPINFO(string, args...) dprintf(0,"[DISPINFO]"string, ##args)

#endif // __DISP_DRV_LOG_H__
