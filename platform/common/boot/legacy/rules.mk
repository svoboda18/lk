LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

OBJS += $(LOCAL_DIR)/dm_verity.o

ifeq ($(MTK_AB_OTA_UPDATER),yes)
OBJS += $(LOCAL_DIR)/load_vfy_boot_ab.o
else
OBJS += $(LOCAL_DIR)/load_vfy_boot.o
endif

