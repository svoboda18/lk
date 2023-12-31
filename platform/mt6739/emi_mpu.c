#include <debug.h>
#include <platform/mt_typedefs.h>
#include <platform/emi_mpu.h>
#include <kernel/thread.h>

extern unsigned long mt_secure_call(unsigned long, unsigned long, unsigned long, unsigned long);

#define DBG_EMI(x...) dprintf(CRITICAL, x)

#define MTK_SIP_KERNEL_EMIMPU_SET           0x82000262

#define emi_mpu_smc_set(start, end, region_apc) \
    mt_secure_call(MTK_SIP_KERNEL_EMIMPU_SET, start, end, region_apc)

/*
 * emi_mpu_set_region_protection: protect a region.
 * @start: start address of the region
 * @end: end address of the region
 * @region: EMI MPU region id
 * @access_permission: EMI MPU access permission
 * Return 0 for success, otherwise negative status code.
 */
int emi_mpu_set_region_protection(unsigned int start, unsigned int end, int region, unsigned int access_permission)
{
	int ret = 0;
	unsigned int apc;

	start = start >> 16;
	end = end >> 16;
	apc = (access_permission & 0x04FFFFFF) | (((unsigned int)region & 0x1F) << 27);

	enter_critical_section();
	emi_mpu_smc_set(start, end, apc);
	exit_critical_section();

	DBG_EMI("LK set emi mpu region protection start:%x end=%x region=%d apc=%x\n", start, end, region, apc);

	return ret;
}

