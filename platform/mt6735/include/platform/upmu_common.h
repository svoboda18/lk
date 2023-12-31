#ifndef _MT_UPMU_COMMON_LK_SW_H_
#define _MT_UPMU_COMMON_LK_SW_H_

#include <platform/mt_pmic.h>

extern kal_uint16 mt6328_set_register_value(PMU_FLAGS_LIST_ENUM flagname,kal_uint32 val);
extern kal_uint16 mt6328_get_register_value(PMU_FLAGS_LIST_ENUM flagname);
extern kal_uint16 pmic_set_register_value(PMU_FLAGS_LIST_ENUM flagname,kal_uint32 val);
extern kal_uint16 pmic_get_register_value(PMU_FLAGS_LIST_ENUM flagname);

#endif
