LOCAL_DIR := $(GET_LOCAL_DIR)

#INCLUDES += -I$(LOCAL_DIR)/include
ifeq ("$(PLAT_DBG_INFO_LIB_SUPPORT)", "1")
OBJS += \
	$(LOCAL_DIR)/plat_dbg_info.o
endif
