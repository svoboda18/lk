LOCAL_DIR := $(GET_LOCAL_DIR)

#INCLUDES += -I$(LOCAL_DIR)/include
ifeq ("$(MBLOCK_LIB_SUPPORT)", "2")
OBJS += \
	$(LOCAL_DIR)/mblock_v2.o
endif
