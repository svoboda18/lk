LOCAL_PATH := $(call my-dir)
LK_ROOT_DIR := $(PWD)

ifdef LK_PROJECT
    LK_DIR := $(LOCAL_PATH)
    INSTALLED_LK_TARGET := $(PRODUCT_OUT)/lk.img
    INSTALLED_LOGO_TARGET := $(PRODUCT_OUT)/logo.bin

    SIGN_LK_TARGET := $(addsuffix -verified$(suffix $(INSTALLED_LK_TARGET)),$(basename $(INSTALLED_LK_TARGET)))
    SIGN_LOGO_TARGET := $(addsuffix -verified$(suffix $(INSTALLED_LOGO_TARGET)),$(basename $(INSTALLED_LOGO_TARGET)))

  ifeq ($(wildcard $(TARGET_PREBUILT_LK)),)
    TARGET_LK_OUT ?= $(TARGET_OUT_INTERMEDIATES)/BOOTLOADER_OBJ
    TARGET_LK_ROOT_OUT := $(if $(filter /% ~%,$(TARGET_LK_OUT)),,$(LK_ROOT_DIR)/)$(TARGET_LK_OUT)
    BUILT_LK_TARGET := $(TARGET_LK_OUT)/build-$(LK_PROJECT)/lk.img
    ifeq ($(LK_CROSS_COMPILE),)
    ifeq ($(TARGET_ARCH), arm)
      LK_CROSS_COMPILE := $(LK_ROOT_DIR)/$(TARGET_TOOLS_PREFIX)
    else ifeq ($(TARGET_2ND_ARCH), arm)
      LK_CROSS_COMPILE := $(LK_ROOT_DIR)/$($(TARGET_2ND_ARCH_VAR_PREFIX)TARGET_TOOLS_PREFIX)
    endif
    endif
    LK_MAKE_OPTION := $(if $(SHOW_COMMANDS),NOECHO=) $(if $(LK_CROSS_COMPILE),TOOLCHAIN_PREFIX=$(LK_CROSS_COMPILE)) BOOTLOADER_OUT=$(TARGET_LK_ROOT_OUT) ROOTDIR=$(LK_ROOT_DIR)
    LK_MAKE_OPTION += LCM_WIDTH=$(LCM_WIDTH) LCM_HEIGHT=$(LCM_HEIGHT)
    LK_MAKE_OPTION += COMPILER=$(LK_ROOT_DIR)/$(SOONG_CLANG)

LK_MAKE_DEPENDENCIES := $(shell find $(LK_DIR) -name .git -prune -o -type f | sort)
LK_MAKE_DEPENDENCIES := $(filter-out %/.git %/.gitignore %/.gitattributes,$(LK_MAKE_DEPENDENCIES))

.KATI_RESTAT: $(BUILT_LK_TARGET)
$(BUILT_LK_TARGET): $(LK_MAKE_DEPENDENCIES)
	$(hide) mkdir -p $(dir $@)
	$(PREBUILT_MAKE_PREFIX)$(MAKE) -C $(LK_DIR) $(LK_MAKE_OPTION) $(LK_PROJECT)

$(INSTALLED_LK_TARGET): $(BUILT_LK_TARGET) $(MTK_LK_DTB_TARGET)
	$(hide) mkdir -p $(dir $@)
	$(hide) cat $(BUILT_LK_TARGET) $(MTK_LK_DTB_TARGET) > $@

$(INSTALLED_LOGO_TARGET): $(BUILT_LK_TARGET)
	$(hide) mkdir -p $(dir $@)
	$(hide) cp -f $(dir $<)$(notdir $@) $@

  else

$(INSTALLED_LK_TARGET): $(TARGET_PREBUILT_LK) $(MTK_LK_DTB_TARGET)
	$(hide) mkdir -p $(dir $@)
	$(hide) cat $^ > $@

$(INSTALLED_LOGO_TARGET): $(dir $(TARGET_PREBUILT_LK))$(notdir $(INSTALLED_LOGO_TARGET))
	$(hide) mkdir -p $(dir $@)
	$(hide) cp -f $< $@

  endif#TARGET_PREBUILT_LK

.PHONY: lk clean-lk check-lk-config check-mtk-config
droidcore: $(INSTALLED_LK_TARGET) $(INSTALLED_LOGO_TARGET) $(SIGN_LK_TARGET) $(SIGN_LOGO_TARGET)
lk: $(INSTALLED_LK_TARGET) $(INSTALLED_LOGO_TARGET) $(SIGN_LK_TARGET) $(SIGN_LOGO_TARGET)
$(SIGN_LK_TARGET) $(SIGN_LOGO_TARGET):

  ifeq ($(wildcard $(TARGET_PREBUILT_LK)),)
lk: check-lk-config

clean-lk:
	$(hide) rm -rf $(INSTALLED_LK_TARGET) $(INSTALLED_LOGO_TARGET) $(TARGET_LK_OUT)

droid: check-lk-config
check-mtk-config: check-lk-config
check-lk-config:
ifneq (yes,$(strip $(DISABLE_MTK_CONFIG_CHECK)))
	python device/mediatek/build/build/tools/check_kernel_config.py -c $(MTK_TARGET_PROJECT_FOLDER)/ProjectConfig.mk -l $(LK_DIR)/project/$(LK_PROJECT).mk -p $(MTK_PROJECT_NAME)
else
	-python device/mediatek/build/build/tools/check_kernel_config.py -c $(MTK_TARGET_PROJECT_FOLDER)/ProjectConfig.mk -l $(LK_DIR)/project/$(LK_PROJECT).mk -p $(MTK_PROJECT_NAME)
endif

    TARGET_LK_FES_OUT ?= $(TARGET_OUT_INTERMEDIATES)/LK_FES_OBJ
    TARGET_LK_FES_ROOT_OUT := $(if $(filter /% ~%,$(TARGET_LK_FES_OUT)),,$(LK_ROOT_DIR)/)$(TARGET_LK_FES_OUT)
    BUILT_LK_FES_TARGET := $(TARGET_LK_FES_OUT)/build-$(LK_PROJECT)/lk.img
    LK_FES_MAKE_OPTION := $(if $(SHOW_COMMANDS),NOECHO=) $(if $(LK_CROSS_COMPILE),TOOLCHAIN_PREFIX=$(LK_CROSS_COMPILE)) BOOTLOADER_OUT=$(TARGET_LK_FES_OUT) ROOTDIR=$(LK_ROOT_DIR)
    LK_FES_MAKE_OPTION += MTK_SECURITY_SW_SUPPORT=no
    LK_FES_MAKE_OPTION += CFG_DTB_EARLY_LOADER_SUPPORT=no
    LK_FES_MAKE_OPTION += PLATFORM_FASTBOOT_EMPTY_STORAGE=yes
    LK_FES_MAKE_OPTION += APPSBOOTHDR_FILES=

.KATI_RESTAT: $(BUILT_LK_FES_TARGET)
$(BUILT_LK_FES_TARGET): $(LK_MAKE_DEPENDENCIES)
	$(hide) mkdir -p $(dir $@)
	$(PREBUILT_MAKE_PREFIX)$(MAKE) -C $(LK_DIR) $(LK_FES_MAKE_OPTION) $(LK_PROJECT)

  endif#TARGET_PREBUILT_LK
endif#LK_PROJECT
