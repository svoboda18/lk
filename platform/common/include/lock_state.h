#ifndef _LOCK_STATE_H_
#define _LOCK_STATE_H_

#include <pal_typedefs.h>

/* LKS means "Lock State" */
typedef enum {
	LKS_DEFAULT                = 0x01,
	LKS_MP_DEFAULT,
	LKS_UNLOCK,
	LKS_LOCK,
	LKS_VERIFIED,
	LKS_CUSTOM,
} LKS;

/* LKCS means "LocK Crtitical State" */
typedef enum {
	LKCS_UNLOCK                 = 0x01,
	LKCS_LOCK,
} LKCS;

/* Secure boot runtime switch (preseved switch for customization) */
typedef enum {
	SBOOT_RUNTIME_OFF        = 0,
	SBOOT_RUNTIME_ON         = 1
} SBOOT_RUNTIME;

uint32_t seccfg_get_lock_state(uint32_t *lock_state);
uint32_t seccfg_set_lock_state(uint32_t lock_state);

#endif
