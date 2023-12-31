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
#if !defined (__CPIO_HEADER__)
#define __CPIO_HEADER__
#define CPIO_ALIGNMENT      4
#define CPIO_NEW_C_MAGIC    "070701"
#define CPIO_MAGIC_LEN              6
#define CPIO_NEWC_FILE_SIZE_LEN      8
#define CPIO_NEWC_FILE_NAME_LEN      CPIO_NEWC_FILE_SIZE_LEN

#define CPIO_LAST_ENTRY_NAME    "TRAILER!!!"
#define CPIO_LAST_ENTRY_NAME_LEN (sizeof(CPIO_LAST_ENTRY_NAME))

typedef struct cpio_newc_header {
		char    c_magic[CPIO_MAGIC_LEN]; /* '070701' */
		char    c_ino[8];
		char    c_mode[8];
		char    c_uid[8];
		char    c_gid[8];
		char    c_nlink[8];
		char    c_mtime[8];
		char    c_filesize[8];
		char    c_devmajor[8];
		char    c_devminor[8];
		char    c_rdevmajor[8];
		char    c_rdevminor[8];
		char    c_namesize[8];
		char    c_check[8];
}cpio_newc_header_t;

#if 0
#define CPIO_ODC_MAGIC      "070707"
#define CPIO_OLD_BIN_MAGIC  070707
#define CPIO_ODC_FILE_SIZE_LEN      11
#define CPIO_ODC_FILE_NAME_LEN      6
typedef struct cpio_odc_header {
		char    c_magic[CPIO_MAGIC_LEN]; /* '070707' */
		char    c_dev[6];
		char    c_ino[6];
		char    c_mode[6];
		char    c_uid[6];
		char    c_gid[6];
		char    c_nlink[6];
		char    c_rdev[6];
		char    c_mtime[11];
		char    c_namesize[6];
		char    c_filesize[11];
}cpio_odc_header_t;

typedef struct cpio_old_header {
		unsigned short   c_magic; /* Octal 070707 */
		unsigned short   c_dev;
		unsigned short   c_ino;
		unsigned short   c_mode;
		unsigned short   c_uid;
		unsigned short   c_gid;
		unsigned short   c_nlink;
		unsigned short   c_rdev;
		unsigned short   c_mtime[2];
		unsigned short   c_namesize;
		unsigned short   c_filesize[2];
}cpio_old_header_t;
#endif
#endif /* __CPIO_HEADER__ */
