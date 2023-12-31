LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

OBJS += \
	$(LOCAL_DIR)/mt_ssusb.o \
	$(LOCAL_DIR)/mt_mu3d_hal_qmu_drv.o \
	$(LOCAL_DIR)/mt_ssusb_qmu.o

ifeq ($(MTK_SSUSBPHY_A60810), yes)
OBJS += $(LOCAL_DIR)/mt_usbphy_a60810.o
DEFINES += CONFIG_A60810_SUPPORT
endif
ifeq ($(MTK_SSUSBPHY_D60802), yes)
OBJS += $(LOCAL_DIR)/mt_usbphy_d60802.o
DEFINES += CONFIG_D60802_SUPPORT
endif
ifeq ($(MTK_SSUSBPHY_E60802), yes)
OBJS += $(LOCAL_DIR)/mt_usbphy_e60802.o
DEFINES += CONFIG_E60802_SUPPORT
endif


