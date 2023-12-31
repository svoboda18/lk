#ifndef __DOWNLOAD_COMMANDS_H
#define __DOWNLOAD_COMMANDS_H
#include <platform/mt_typedefs.h>


void cmd_install_sig(const char *arg, void *data, unsigned sz);
bool cmd_flash_mmc_img(const char *arg, void *data, unsigned sz);
bool cmd_flash_mmc_sparse_img(const char *arg, void *data, unsigned sz);
void cmd_flash_mmc(const char *arg, void *data, unsigned sz);
void cmd_erase_mmc(const char *arg, void *data, unsigned sz);




#ifdef MTK_ULTRA_FLASH
void cmd_oem_ultra_flash(const char *arg, void *data, unsigned sz);
void cmd_oem_ultra_flash_en(const char *arg, void *data, unsigned sz);
//internal use.
void display_progress(const char* msg_prefix, unsigned size, unsigned totle_size);
void* get_available_ram_base();
void* special_heap_alloc(int length);
#endif

#endif
