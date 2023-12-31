#include <debug.h>
#include <stdlib.h>
#include <string.h>
#include <video.h>
#include <dev/uart.h>
#include <arch/arm.h>
#include <arch/arm/mmu.h>
#include <arch/ops.h>
#include <target/board.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_disp_drv.h>
#include <platform/disp_drv.h>
#include <platform/boot_mode.h>
#include <platform/mt_logo.h>
#include <platform/partition.h>
#include <env.h>
#include <platform/mt_gpio.h>
#include <platform/mt_pmic.h>
#include <platform/mt_pmic_wrap_init.h>
#include <platform/mt_i2c.h>
#include <platform/mtk_key.h>
#include <platform/mt_rtc.h>
#include <platform/mt_leds.h>
#include <platform/upmu_common.h>
#include <platform/mtk_wdt.h>
#include <platform/boot_mode.h>
#include <platform/disp_drv_platform.h>

#ifdef ENABLE_L2_SHARING

#define ADDR_CA7L_CACHE_CONFIG_MP(x) (CA7MCUCFG_BASE)
#define L2C_SIZE_CFG_OFFSET  5
/* 4'b1111: 2048KB(not support)
 * 4'b0111: 1024KB(not support)
 * 4'b0011: 512KB
 * 4'b0001: 256KB
 * 4'b0000: 128KB (not support)
 */

int is_l2_need_config(void)
{
    volatile unsigned int cache_cfg, addr;

    addr = ADDR_CA7L_CACHE_CONFIG_MP(0);
    cache_cfg = DRV_Reg32(addr);
    cache_cfg = cache_cfg >> L2C_SIZE_CFG_OFFSET;

    /* only read 256KB need to be config.*/
    if((cache_cfg &(0x7)) == 0x1)
    {
        return 1;
    }
    return 0;
}

void cluster_l2_share_enable(int cluster)
{
    volatile unsigned int cache_cfg, addr;

    addr = ADDR_CA7L_CACHE_CONFIG_MP(cluster);
    /* set L2C size to 256KB */
    cache_cfg = DRV_Reg32(addr);
    cache_cfg &= (~0x7) << L2C_SIZE_CFG_OFFSET;
    cache_cfg |= 0x1 << L2C_SIZE_CFG_OFFSET;
    DRV_WriteReg32(addr, cache_cfg);
}

void cluster_l2_share_disable(int cluster)
{
    volatile unsigned int cache_cfg, addr;

    addr = ADDR_CA7L_CACHE_CONFIG_MP(cluster);
    /* set L2C size to 512KB */
    cache_cfg = DRV_Reg32(addr);
    cache_cfg &= (~0x7) << L2C_SIZE_CFG_OFFSET;
    cache_cfg |= 0x3 << L2C_SIZE_CFG_OFFSET;
    DRV_WriteReg32(addr, cache_cfg);
}

/* config L2 cache and sram to its size */
void config_L2_size(void)
{
    int cluster;

    cluster_l2_share_disable(0);

}

/* config SRAM back from L2 cache for DA relocation */
void config_shared_SRAM_size(void)
{
    int cluster;

    cluster_l2_share_enable(0);
}

#endif
