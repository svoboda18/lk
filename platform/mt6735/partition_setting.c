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
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/
#include <platform/partition.h>
#include <part_interface.h>

#ifdef MTK_USERIMAGES_USE_F2FS
#define USERDATA_FS_TYPE "f2fs"
#else
#define USERDATA_FS_TYPE "ext4"
#endif

struct part_name_map g_part_name_map[PART_MAX_COUNT] = {
        {"preloader",   "preloader",    "raw data",     0,      0,      0},
        {"proinfo",     "proinfo",      "raw data",     1,      0,      0},
        {"nvram",       "nvram",        "raw data",     2,      0,      0},
        {"protect1",    "protect1",     "ext4",         3,      0,      0},
        {"protect2",    "protect2",     "ext4",         4,      0,      0},
        {"lk",          "lk",           "raw data",     5,      1,      1},
        {"lk2",         "lk2",          "raw data",     5,      1,      1},
        {"para",        "para",         "raw data",     6,      0,      0},
        {"boot",        "boot",         "raw data",     7,      1,      1},
        {"recovery",    "recovery",     "raw data",     8,      1,      1},
        {"logo",        "logo",         "raw data",     9,      0,      0},
        {"expdb",       "expdb",        "raw data",     10,     0,      0},
        {"seccfg",      "seccfg",       "raw data",     11,     0,      0},
        {"oemkeystore", "oemkeystore",  "raw data",     12,     0,      0},
        {"secro",       "secro",        "raw data",     13,     0,      0},
        {"keystore",    "keystore",     "raw data",     14,     1,      1},
        {"tee1",        "tee1",         "raw data",     15,     0,      0},
        {"tee2",        "tee2",         "raw data",     15,     0,      0},
        {"persist",     "persist",      "ext4",         17,     0,      0},
        {"custom",      "custom",       "ext4",         18,     0,      0},
        {"recovery2",	"recovery2",	"ext4",        	19,	0,	0},
        {"radio",       "radio",        "ext4",         20,     0,      0},
        {"vendor",	"vendor",	"ext4", 	21,	1,	1},
        {"odm", 	"odm",  	"ext4", 	22,	1,	1},
        {"oem", 	"oem",  	"ext4", 	23,	0,	0},
        {"odmdtbo",     "odmdtbo",      "raw data",     24,     1,      1},
        {"efuse",       "efuse",        "raw data",     25,     0,      0},
        {"frp",         "frp",          "raw data",     26,     0,      0},
        {"nvdata",      "nvdata",       "ext4",         27,     0,      0},
        {"metadata",    "metadata",     "raw data",     28,     0,      0},
        {"system",      "system",       "ext4",         29,     1,      1},
        {"cache",       "cache",        "ext4",         30,     1,      1},
        {"userdata",    "userdata",     USERDATA_FS_TYPE,         31,     1,      1},
        {"intsd",       "intsd",        "fat",          32,     0,      0},
        {"otp",         "otp",          "raw data",     33,     0,      0},
        {"flashinfo",   "flashinfo",    "raw data",     34,     0,      0},
        {"",		"",		"",		35,	0,	0},
};
