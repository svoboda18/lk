LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

OBJS += $(LOCAL_DIR)/boot_info.o
OBJS += $(LOCAL_DIR)/boot_opt.o
OBJS += $(LOCAL_DIR)/vboot_state.o

ifeq ($(MTK_SECURITY_ANTI_ROLLBACK),yes)
OBJS += $(LOCAL_DIR)/anti_rollback_util.o
endif

ifeq ($(MTK_AVB20_SUPPORT),yes)
MODULES += $(LOCAL_DIR)/avb20
else
MODULES += $(LOCAL_DIR)/legacy
endif

ifeq ($(MTK_BUILD_DEFAULT_UNLOCK),yes)
DEFINES += MTK_BUILD_DEFAULT_UNLOCK
endif
