#ifndef __MT_L2C_H__
#define __MT_L2C_H__

int is_l2_need_config(void);
void cluster_l2_share_enable(int cluster);
void cluster_l2_share_disable(int cluster);
/* config L2 cache and sram to its size */
void config_L2_size(void);
/* config SRAM back from L2 cache for DA relocation */
void config_shared_SRAM_size(void);

#endif /* end of __MT_L2C_H__ */
