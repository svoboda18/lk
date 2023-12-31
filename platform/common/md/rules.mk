LOCAL_DIR := $(GET_LOCAL_DIR)

OBJS += \
	$(LOCAL_DIR)/ccci_ld_md_padding.o \
	$(LOCAL_DIR)/ccci_ld_md_ass.o \
	$(LOCAL_DIR)/ccci_ld_md_tel.o \
	$(LOCAL_DIR)/ccci_ld_md_tag_dt.o \
	$(LOCAL_DIR)/ccci_ld_md_hal.o \
	$(LOCAL_DIR)/ccci_ld_md_api_wrapper.o \
	$(LOCAL_DIR)/ccci_ld_md_sec.o \
	$(LOCAL_DIR)/ccci_ld_md_core.o

INCLUDES += -I$(LK_TOP_DIR)/dev/md_com

ifeq ($(MTK_AB_OTA_UPDATER),yes)
INCLUDES += -I$(LK_TOP_DIR)/platform/common/bootctrl
endif