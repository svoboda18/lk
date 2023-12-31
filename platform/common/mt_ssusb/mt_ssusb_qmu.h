/*
 * Copyright (c) 2013 MediaTek Inc.
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

#ifndef __SSUSB_QMU_H__
#define __SSUSB_QMU_H__

#define USE_SSUSB_QMU

//#include "mt_mu3d_hal_qmu_drv.h"

#ifdef USE_SSUSB_QMU

#define GPD_BUF_SIZE 65532
#define GPD_BUF_SIZE_ALIGN 64512 /* 63 * 1024 */
#define BD_BUF_SIZE 32768 //set to half of 64K of max size

struct qmu_done_isr_data {
	struct musb *musb;
	u32 qmu_val;
};

//EXTERN void usb_initialize_qmu(void);
void usb_initialize_qmu(void);
//EXTERN void txstate_qmu(struct musb *musb, struct musb_request *req);
//EXTERN void txstate_qmu(struct urb *req);
void txstate_qmu(struct urb *req);

void qmu_exception_interrupt(void *base, u32 qmuval);
void qmu_done_interrupt(u32 qmu_val);

void qmu_handler(u32 qmu_val);

#endif //#ifdef USE_SSUSB_QMU

#endif //#ifndef __SSUSB_QMU_H__
