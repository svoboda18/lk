#include <printf.h>
#include <platform/mt_typedefs.h>
#include <platform/mtk_key.h>
#include <platform/boot_mode.h>
#include <platform/mt_pmic.h>
#include <platform/mt_gpio.h>
#include <platform/mt_pmic_wrap_init.h>
#include <platform/sync_write.h>
#include <platform/upmu_common.h>
#include <target/cust_key.h>
#include <libfdt.h>
#include <lk_builtin_dtb.h>

extern int pmic_detect_powerkey(void);
extern int pmic_detect_homekey(void);
extern kal_uint16 pmic_get_register_value(PMU_FLAGS_LIST_ENUM flagname);
extern kal_uint16 pmic_set_register_value(PMU_FLAGS_LIST_ENUM flagname,kal_uint32 val);

struct keypad_dts_data kpd_dts_data;
static int kpd_dts_init_done = 0;

static unsigned int kpd_fdt_getprop_u32(const void *fdt, int nodeoffset, const char *name)
{
	const void *data = NULL;
	int len = 0;

	data = fdt_getprop(fdt, nodeoffset, name, &len);
	if (len > 0 && data)
		return fdt32_to_cpu(*(unsigned int *)data);
	else
		return 0;
}

static void kpd_fdt_getprop_u32_array(const void *fdt, int nodeoffset,
						const char *name, char *out_value, int maxlen)
{
	const void *data = NULL;
	int len = 0;

	data = fdt_getprop(fdt, nodeoffset, name, &len);
	if (len > 0 && data)
		memcpy(out_value, data, len > maxlen ? maxlen : len);
	else
		memset(out_value, 0, len > maxlen ? maxlen: len);
}

void get_kpd_dts_info(void)
{
	int offset;

	if (kpd_dts_init_done)
		return;
	memset(&kpd_dts_data, 0, sizeof(kpd_dts_data));
	offset = fdt_path_offset(get_lk_overlayed_dtb(), "/kp@10010000");
	if (offset >= 0) {
		kpd_dts_data.kpd_sw_pwrkey = kpd_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "mediatek,kpd-sw-pwrkey");
		kpd_dts_data.kpd_hw_pwrkey = kpd_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "mediatek,kpd-hw-pwrkey");
		kpd_dts_data.kpd_sw_rstkey = kpd_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "mediatek,kpd-sw-rstkey");
		kpd_dts_data.kpd_hw_rstkey = kpd_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "mediatek,kpd-hw-rstkey");
		kpd_dts_data.kpd_use_extend_type = kpd_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "mediatek,kpd-use-extend-type");
		kpd_dts_data.kpd_hw_recovery_key = kpd_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "mediatek,kpd-hw-recovery-key");
		kpd_dts_data.kpd_hw_factory_key = kpd_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "mediatek,kpd-hw-factory-key");
		dprintf(INFO, "kpd_sw_pwrkey = %d, kpd_hw_pwrkey = %d, kpd_sw_rstkey = %d, kpd_hw_rstkey = %d\n",
			kpd_dts_data.kpd_sw_pwrkey, kpd_dts_data.kpd_hw_pwrkey, kpd_dts_data.kpd_sw_rstkey, kpd_dts_data.kpd_hw_rstkey);
		dprintf(INFO, "kpd_use_extend_type = %d, kpd_hw_recovery_key = %d, kpd_hw_factory_key = %d\n",
			kpd_dts_data.kpd_use_extend_type, kpd_dts_data.kpd_hw_recovery_key, kpd_dts_data.kpd_hw_factory_key);
		kpd_dts_data.kpd_hw_map_num = kpd_fdt_getprop_u32(get_lk_overlayed_dtb(), offset, "mediatek,kpd-hw-map-num");
		kpd_fdt_getprop_u32_array(get_lk_overlayed_dtb(), offset, "mediatek,kpd-hw-init-map", (char *)kpd_dts_data.kpd_hw_init_map, KPD_NUM_KEYS * 4);
		kpd_dts_init_done = 1;
	} else {
		/* default setting when dts not found: recovery key = pmic home key, factory key = vol down key */
		dprintf(CRITICAL, "keypad dts not found, using default setting\n");
		kpd_dts_data.kpd_hw_pwrkey = 8;
		kpd_dts_data.kpd_hw_rstkey = 17;
		kpd_dts_data.kpd_hw_recovery_key = kpd_dts_data.kpd_hw_rstkey;
		kpd_dts_data.kpd_hw_factory_key = 0;
	}
#ifdef MT65XX_FACTORY_KEY
	dprintf(CRITICAL, "MT65XX_FACTORY_KEY 0x%x\n",MT65XX_FACTORY_KEY);
#endif
#ifdef MT65XX_BOOT_MENU_KEY
	dprintf(CRITICAL, "MT65XX_BOOT_MENU_KEY 0x%x\n",MT65XX_BOOT_MENU_KEY);
#endif
#ifdef MT65XX_RECOVERY_KEY
	dprintf(CRITICAL, "MT65XX_RECOVERY_KEY 0x%x\n",MT65XX_RECOVERY_KEY);
#endif
}


void set_kpd_pmic_mode(void)
{
	return;
}

void disable_PMIC_kpd_clock(void)
{
	return;
}

void enable_PMIC_kpd_clock(void)
{
	return;
}

BOOL mtk_detect_key(unsigned short key) /* key: HW keycode */
{
#ifdef MACH_FPGA
	return FALSE;
#else

	//dprintf(ALWAYS, "mtk detect key function key = %d\n", key);

	unsigned short idx, bit, din;

	get_kpd_dts_info();
	if (key >= KPD_NUM_KEYS)
		return FALSE;
#if 0
	if (key % 9 == 8)
		key = 8;
#endif
	if (key == MTK_PMIC_PWR_KEY) {
		/* Power key */
		if (1 == pmic_detect_powerkey()) {
			dprintf(ALWAYS, "power key is pressed\n");
			return TRUE;
		}
		return FALSE;
	}

#ifdef MTK_PMIC_RST_KEY
	if (key == MTK_PMIC_RST_KEY) {
		//dprintf(INFO, "mtk detect key function pmic_detect_homekey MTK_PMIC_RST_KEY = %d\n", MTK_PMIC_RST_KEY);
		if (1 == pmic_detect_homekey()) {
			dprintf(ALWAYS, "mtk detect key function pmic_detect_homekey pressed\n");
			return TRUE;
		}
		return FALSE;
	}
#endif

	idx = key / 16;
	bit = key % 16;

	din = DRV_Reg16(KP_MEM1 + (idx << 2)) & (1U << bit);
	if (!din) {
		dprintf(ALWAYS, "key %d is pressed\n", key);
		return TRUE;
	}
	return FALSE;
#endif
}

BOOL mtk_detect_pmic_just_rst(void)
{
	kal_uint32 just_rst = 0;

	dprintf(ALWAYS, "detecting pmic just reset\n");

	just_rst = pmic_get_register_value(PMIC_JUST_PWRKEY_RST);
	if (just_rst) {
		dprintf(ALWAYS, "Just recover from a reset\n");
		pmic_set_register_value(PMIC_CLR_JUST_RST, 0x01);
		return TRUE;
	}
	return FALSE;
}
