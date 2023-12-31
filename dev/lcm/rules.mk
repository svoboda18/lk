#
# Makefile for misc devices that really don't fit anywhere else.
#
LOCAL_DIR := $(GET_LOCAL_DIR)

LCM_DEFINES := $(shell echo $(CUSTOM_LK_LCM) | tr a-z A-Z)
DEFINES += $(foreach LCM,$(LCM_DEFINES),$(LCM))
DEFINES += MTK_LCM_PHYSICAL_ROTATION=\"$(MTK_LCM_PHYSICAL_ROTATION)\"
DEFINES += LCM_WIDTH=\"$(LCM_WIDTH)\"
DEFINES += LCM_HEIGHT=\"$(LCM_HEIGHT)\"

ifeq ($(PLATFORM), $(filter $(PLATFORM), mt6757 mt6763 mt6771 mt6765 mt6762 mt6779 mt6768 mt6785))
DEFINES += LCM_SET_DISPLAY_ON_DELAY=y
endif


LCM_LISTS := $(subst ",,$(CUSTOM_LK_LCM))
OBJS += $(foreach LCM,$(LCM_LISTS),$(LOCAL_DIR)/$(LCM)/$(addsuffix .o, $(LCM)))
OBJS += $(LOCAL_DIR)/mt65xx_lcm_list.o \
		$(LOCAL_DIR)/lcm_common.o \
		$(LOCAL_DIR)/lcm_gpio.o \
		$(LOCAL_DIR)/lcm_i2c.o \
		$(LOCAL_DIR)/lcm_util.o \
		$(LOCAL_DIR)/lcm_pmic.o

INCLUDES += -I$(LOCAL_DIR)/inc

