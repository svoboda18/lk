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

/* These defines comes from Linux */
//#define USE_LINUX_DEFINES
#ifdef USE_LINUX_DEFINES
#define USB_ENDPOINT_XFERTYPE_MASK	0x03	/* in bmAttributes */
#define USB_ENDPOINT_XFER_CONTROL	0
#define USB_ENDPOINT_XFER_ISOC		1
#define USB_ENDPOINT_XFER_BULK		2
#define USB_ENDPOINT_XFER_INT		3
#define USB_ENDPOINT_MAX_ADJUSTABLE	0x80

#define USB_ENDPOINT_SYNCTYPE		0x0c
#define USB_ENDPOINT_SYNC_NONE		(0 << 2)
#define USB_ENDPOINT_SYNC_ASYNC		(1 << 2)
#define USB_ENDPOINT_SYNC_ADAPTIVE	(2 << 2)
#define USB_ENDPOINT_SYNC_SYNC		(3 << 2)

#define USB_ENDPOINT_USAGE_MASK		0x30
#define USB_ENDPOINT_USAGE_DATA		0x00
#define USB_ENDPOINT_USAGE_FEEDBACK	0x10
#define USB_ENDPOINT_USAGE_IMPLICIT_FB	0x20	/* Implicit feedback Data endpoint */
#endif

#endif //#ifndef __SSUSB_QMU_H__
