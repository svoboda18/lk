LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/../inc
INCLUDES += -I$(LOCAL_DIR)/../../$(PLATFORM)/include
INCLUDES += -I$(LOCAL_DIR)/../../$(PLATFORM)/include/platform
INCLUDES += -I$(LOCAL_DIR)/include

OBJS += \
	$(LOCAL_DIR)/mmc_common_inter.o \
	$(LOCAL_DIR)/mmc_core.o\
	$(LOCAL_DIR)/mmc_test.o\
	$(LOCAL_DIR)/msdc.o\
	$(LOCAL_DIR)/mmc_rpmb.o\
	$(LOCAL_DIR)/msdc_dma.o\
	$(LOCAL_DIR)/msdc_utils.o\
	$(LOCAL_DIR)/msdc_irq.o
