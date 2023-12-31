ifeq ($(MAKECMDGOALS),spotless)
spotless:
	rm -rf build-*
else

-include local.mk
include make/macros.mk

# If one of our goals (from the commandline) happens to have a
# matching project/goal.mk, then we should re-invoke make with
# that project name specified...

project-name := $(firstword $(MAKECMDGOALS))

ifneq ($(project-name),)
ifneq ($(wildcard project/$(project-name).mk),)
do-nothing := 1
$(MAKECMDGOALS) _all: make-make
make-make:
	@PROJECT=$(project-name) $(MAKE) $(filter-out $(project-name), $(MAKECMDGOALS))
endif
endif

ifeq ($(do-nothing),)

ifeq ($(PROJECT),)
$(error No project specified.  Use "make projectname" or put "PROJECT := projectname" in local.mk)
endif

DEBUG ?= 0
HOST_OS ?= $(shell uname | tr '[A-Z]' '[a-z]')

ifndef BOOTLOADER_OUT
BOOTLOADER_OUT := .
endif

LK_TOP_DIR:= .
BUILDDIR := $(BOOTLOADER_OUT)/build-$(PROJECT)
OUTBIN := $(BUILDDIR)/lk.img
OUTELF := $(BUILDDIR)/lk
CONFIGHEADER := $(BUILDDIR)/config.h
VERSIONHEADER := $(BUILDDIR)/version.h

#Initialize the command-line flag ENABLE_TRUSTZONE. Value for flag passed in at command-line will take precedence
ENABLE_TRUSTZONE := 0

ifeq ($(ENABLE_TRUSTZONE),1)
	INPUT_TZ_BIN := tzbsp/tzbsp.bin
	OUTPUT_TZ_BIN := $(BUILDDIR)/tzbsp_bin.o
endif

INCLUDES := -I$(BUILDDIR) -Iinclude
CFLAGS := -O2 -g -gdwarf-2 -fno-builtin -finline -W -Wall -Wno-multichar -Wno-unused-parameter -Wno-unused-function -include $(CONFIGHEADER) -include $(VERSIONHEADER)
#CFLAGS += -Werror

ifeq ($(EMMC_BOOT),1)
  CFLAGS += -D_EMMC_BOOT=1
endif

ifeq ($(SIGNED_KERNEL),1)
  CFLAGS += -D_SIGNED_KERNEL=1
endif

###############################################################################
# Turn on stack-protector for userdebug and eng load.
###############################################################################
ifneq ($(filter user, $(TARGET_BUILD_VARIANT)),)
  # Do nothing!
else ifneq ($(filter userdebug, $(TARGET_BUILD_VARIANT)),)
  CFLAGS += -fstack-protector-strong
else ifneq ($(filter eng, $(TARGET_BUILD_VARIANT)),)
  CFLAGS += -fstack-protector-strong
endif

# When the host arch is ARM, ensure stack protection code is not emitted since
# it's not supported by the bootloader's libc
#ifneq ($(shell uname -m | grep "arm.*"),)
#  CFLAGS += -fno-stack-protector
#endif
CPPFLAGS := -fno-exceptions -fno-rtti -fno-threadsafe-statics
#CPPFLAGS += -Weffc++
ASMFLAGS := -DASSEMBLY
LDFLAGS :=

CFLAGS += -ffunction-sections -fdata-sections
LDFLAGS += -gc-sections

# top level rule
all:: $(OUTBIN) $(OUTELF).lst $(OUTELF).debug.lst $(OUTELF).sym $(OUTELF).size

# the following three object lists are identical except for the ordering
# which is bootobjs, kobjs, objs
BOOTOBJS :=
OBJS :=

# a linker script needs to be declared in one of the project/target/platform files
LINKER_SCRIPT :=

# anything you add here will be deleted in make clean
GENERATED := $(CONFIGHEADER)
GENERATED += $(VERSIONHEADER)

# anything added to DEFINES will be put into $(BUILDDIR)/config.h
DEFINES := LK=1

# Anything added to SRCDEPS will become a dependency of every source file in the system.
# Useful for header files that may be included by one or more source files.
SRCDEPS := $(CONFIGHEADER)
SRCDEPS += $(VERSIONHEADER)

# these need to be filled out by the project/target/platform rules.mk files
TARGET :=
PLATFORM :=
ARCH :=
MACH_TYPE :=
ALLMODULES :=
MODULES :=

# any rules you put here will also be built by the system before considered being complete
EXTRA_BUILDDEPS :=

# any rules you put here will be depended on in clean builds
EXTRA_CLEANDEPS :=

DRVGEN_OUT := $(BUILDDIR)
PTGEN_OUT := $(BOOTLOADER_OUT)

include project/$(PROJECT).mk
include make/rat_config.mk
include target/$(TARGET)/rules.mk
include dev/rules.mk
include platform/$(PLATFORM)/rules.mk
ifeq ($(MTK_EMMC_SUPPORT), yes)
ifneq ($(filter MTK_NEW_COMBO_EMMC_SUPPORT, $(strip $(DEFINES))),)
DEFINES += PART_DEV_API_V2
#72/82 is old combo, use V1.
else
DEFINES += PART_DEV_API_V1
endif
else ifeq ($(MTK_UFS_SUPPORT), yes)
DEFINES += PART_DEV_API_V2
#nand is only used for mt6580 now, 80 also use V2.
else ifeq ($(MTK_NAND_UBIFS_SUPPORT), yes)
DEFINES += PART_DEV_API_V2
else
DEFINES += PART_DEV_API_V2
endif

ifneq ($(USE_DTB_NO_DWS),yes)
$(info **************** Use DWS ****************)
-include scripts/drvgen/drvgen.mk
else
$(info **************** Use DTB ****************)
endif

-include scripts/ptgen/$(PLATFORM)/ptgen.mk
include arch/$(ARCH)/rules.mk
include platform/pal/rules.mk
include platform/common/rules.mk
include platform/rules.mk
include target/rules.mk
include kernel/rules.mk
include app/rules.mk

# recursively include any modules in the MODULE variable, leaving a trail of included
# modules in the ALLMODULES list
include make/module.mk
# build internal repo(source not release to customer)
include make/build_nonrelease.mk
# any extra top level build dependencies that someone declared
all:: $(EXTRA_BUILDDEPS)

ALLOBJS := \
	$(BOOTOBJS) \
	$(OBJS)
# add some automatic configuration defines
ifeq ($(findstring MACH_TYPE, $(strip $(DEFINES))),)
DEFINES += MACH_TYPE=$(shell echo $(MACH_TYPE) | tr -dc '0-9')
endif

DEFINES += \
	BOARD=$(PROJECT) \
	PROJECT_$(PROJECT)=1 \
	TARGET_$(TARGET)=1 \
	PLATFORM_$(PLATFORM)=1 \
	ARCH_$(ARCH)=1 \
	MACH_TYPE_$(MACH_TYPE)=1 \
	$(addsuffix =1,$(addprefix WITH_,$(ALLMODULES)))

ifeq ($(USE_DTB_NO_DWS),yes)
DEFINES += USE_DTB_NO_DWS
endif

ifeq ($(MTK_EMMC_SUPPORT),yes)
DEFINES += MTK_EMMC_SUPPORT
ifeq ($(MTK_MMC_COMBO_DRV),yes)
DEFINES += MTK_MMC_COMBO_DRV
endif
endif

ifeq ($(MTK_UFS_SUPPORT),yes)
DEFINES += MTK_UFS_SUPPORT
endif

ifeq ($(MNTL_SUPPORT),yes)
DEFINES += MNTL_SUPPORT
ifeq ($(MTK_TLC_NAND_SUPPORT),yes)
DEFINES += MTK_TLC_NAND_SUPPORT
endif
ifeq ($(MTK_MMC_COMBO_DRV),yes)
DEFINES += MTK_MMC_COMBO_DRV
endif
endif

ifeq ($(MTK_UFS_OTP),yes)
DEFINES += MTK_UFS_OTP
endif

ifeq ($(MTK_SECURITY_SW_SUPPORT),yes)
DEFINES += MTK_SECURITY_SW_SUPPORT
endif

ifeq ($(MTK_VERIFIED_BOOT_SUPPORT),yes)
DEFINES += MTK_VERIFIED_BOOT_SUPPORT
endif

ifeq ($(CUSTOM_LK_USB_UNIQUE_SERIAL),yes)
CFLAGS += -DCONFIG_MTK_USB_UNIQUE_SERIAL
endif

# debug build?
ifneq ($(DEBUG),)
DEFINES += \
	DEBUG=$(DEBUG)
endif

ALLOBJS := $(addprefix $(BUILDDIR)/,$(ALLOBJS))
ALLOBJS += $(NON_ROBJS)

DEPS := $(ALLOBJS:%o=%d)
INCLUDEDEPS := $(filter-out $(DEPS),$(MAKEFILE_LIST))
SRCDEPS += $(INCLUDEDEPS) make/build.mk arch/$(ARCH)/compile.mk
SRCDEPS += $(EMIGEN_FILE_LIST)
SRCDEPS += $(DRVGEN_FILE_LIST)
SRCDEPS += $(PTGEN_FILE_LIST)
SRCDEPS += $(LOGO_IMAGE)

# default to no ccache
CCACHE ?=
TOOLCHAIN_PREFIX ?=gcc/bin/arm-linux-androideabi-
CC := $(CCACHE) $(TOOLCHAIN_PREFIX)gcc
#LD := $(TOOLCHAIN_PREFIX)ld
LD := $(TOOLCHAIN_PREFIX)ld.bfd
OBJDUMP := $(TOOLCHAIN_PREFIX)objdump
OBJCOPY := $(TOOLCHAIN_PREFIX)objcopy
CPPFILT := $(TOOLCHAIN_PREFIX)c++filt
SIZE := $(TOOLCHAIN_PREFIX)size
NM := $(TOOLCHAIN_PREFIX)nm

# comment out or override if you want to see the full output of each command
NOECHO ?= @

# the logic to compile and link stuff is in here
include make/build.mk

clean: $(EXTRA_CLEANDEPS)
	rm -f $(ALLOBJS) $(DEPS) $(GENERATED) $(OUTBIN) $(OUTELF) $(OUTELF).lst

install: all
	scp $(OUTBIN) 192.168.0.4:/tftproot

# generate a config.h file with all of the DEFINES laid out in #define format
configheader:

$(CONFIGHEADER): configheader
	@$(MKDIR)
	@echo generating $@
	@rm -f $(CONFIGHEADER).tmp; \
	echo \#ifndef __CONFIG_H > $(CONFIGHEADER).tmp; \
	echo \#define __CONFIG_H >> $(CONFIGHEADER).tmp; \
	for d in `echo $(DEFINES) | tr [:lower:] [:upper:]`; do \
		echo "#define $$d" | sed "s/=/\ /g;s/-/_/g;s/\//_/g" >> $(CONFIGHEADER).tmp; \
	done; \
	echo \#endif >> $(CONFIGHEADER).tmp; \
	if [ -f "$(CONFIGHEADER)" ]; then \
		if cmp "$(CONFIGHEADER).tmp" "$(CONFIGHEADER)"; then \
			rm -f $(CONFIGHEADER).tmp; \
		else \
			mv $(CONFIGHEADER).tmp $(CONFIGHEADER); \
		fi \
	else \
		mv $(CONFIGHEADER).tmp $(CONFIGHEADER); \
	fi

LAST_COMMIT_HASH := $(shell git log -1 --pretty=format:%h)
LAST_COMMIT_DATE := $(shell git log -1 --date=format:'%Y%m%d%H%M%S' --pretty=format:"%cd")
BUILD_DATE := $(shell date +'%Y%m%d%H%M%S')
$(VERSIONHEADER): versionheader
	@$(MKDIR)
	@echo generating $@
	@rm -f $(VERSIONHEADER).tmp; \
	echo \#ifndef __VERSION_H > $(VERSIONHEADER).tmp; \
	echo \#define __VERSION_H >> $(VERSIONHEADER).tmp; \
	echo "/* LK_VER_TAG = <PROJECT>-<LAST_COMMIT_HASH>-<LAST_COMMIT_DATE>-<BUILD_DATE> */" >> $(VERSIONHEADER).tmp; \
	echo "#define LK_VER_TAG \"$(PROJECT)-$(LAST_COMMIT_HASH)-$(LAST_COMMIT_DATE)-$(BUILD_DATE)\"" >> $(VERSIONHEADER).tmp; \
	echo "#define PROJECT \"$(PROJECT)\"" >> $(VERSIONHEADER).tmp; \
	echo \#endif >> $(VERSIONHEADER).tmp; \
	if [ -f "$(VERSIONHEADER)" ]; then \
		if cmp "$(VERSIONHEADER).tmp" "$(VERSIONHEADER)"; then \
			rm -f $(VERSIONHEADER).tmp; \
		else \
			mv $(VERSIONHEADER).tmp $(VERSIONHEADER); \
		fi \
	else \
		mv $(VERSIONHEADER).tmp $(VERSIONHEADER); \
	fi

# Empty rule for the .d files. The above rules will build .d files as a side
# effect. Only works on gcc 3.x and above, however.
%.d:

ifeq ($(filter $(MAKECMDGOALS), clean), )
-include $(DEPS)
endif

.PHONY: configheader versionheader
endif

endif # make spotless
