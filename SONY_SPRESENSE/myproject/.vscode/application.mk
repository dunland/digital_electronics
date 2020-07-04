############################################################################
#
#   Copyright (C) 2015 Gregory Nutt. All rights reserved.
#   Copyright (C) 2015 Omni Hoverboards Inc. All rights reserved.
#   Authors: Gregory Nutt <gnutt@nuttx.org>
#            Paul Alexander Patience <paul-a.patience@polymtl.ca>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name NuttX nor the names of its contributors may be
#    used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
# OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
############################################################################

# SPRESENSE_IDE_VERSION := 1.1.0

############################################################################
#              THIS FILE IS AUTO GENERATED. DO NOT MODIFY                  #
############################################################################

ifeq ($(SDK_VERSION_MAJ),1)
-include $(TOPDIR)/Make.defs
-include $(SDKDIR)/Make.defs
-include $(SDKDIR)/.config
include $(APPDIR)/Make.defs
else
include $(TOPDIR)/Make.defs
include $(SDKDIR)/Make.defs
endif

# Take application name
APP_FOLDER_NAME := $(notdir $(shell pwd))

# Application command configurable parameters
ifeq ($(APPNAME),)
	APPNAME = $(APP_FOLDER_NAME)
endif

ifeq ($(PRIORITY),)
	PRIORITY = SCHED_PRIORITY_DEFAULT
endif

ifeq ($(STACKSIZE),)
	STACKSIZE = 2048
endif

ifeq ($(MAINSRC),)
	MAINSRC = $(APP_FOLDER_NAME)_main.c
endif
ASRCS +=
CSRCS += $(filter-out $(MAINSRC),$(wildcard *.c) $(wildcard */*.c))
CXXSRCS += $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard *.cxx) $(wildcard */*.cxx)

CFLAGS += $(foreach inc,$(wildcard ../*/include),-I$(inc))
CXXFLAGS += $(foreach inc,$(wildcard ../*/include),-I$(inc))

PROGNAME = $(APPNAME)$(EXEEXT)

ifeq ($(SDK_VERSION_MAJ),1)
# From Application.mk
CXXEXT ?= .cxx

AOBJS = $(ASRCS:.S=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT))
CXXOBJS = $(CXXSRCS:$(CXXEXT)=$(OBJEXT))

ifeq ($(suffix $(MAINSRC)),$(CXXEXT))
  MAINOBJ = $(MAINSRC:$(CXXEXT)=$(OBJEXT))
else
  MAINOBJ = $(MAINSRC:.c=$(OBJEXT))
endif

SRCS = $(ASRCS) $(CSRCS) $(CXXSRCS) $(MAINSRC)
OBJS = $(AOBJS) $(COBJS) $(CXXOBJS)

ifneq ($(CONFIG_BUILD_KERNEL),y)
  OBJS += $(MAINOBJ)
endif

ifeq ($(WINTOOL),y)
  BIN = "${shell cygpath -w $(APPDIR)$(DELIM)libuserapps$(LIBEXT)}"
  INSTALL_DIR = "${shell cygpath -w $(BIN_DIR)}"
else
  BIN = $(APPDIR)$(DELIM)libuserapps$(LIBEXT)
  INSTALL_DIR = $(BIN_DIR)
endif

ROOTDEPPATH += --dep-path .
VPATH +=

all: .built
.PHONY: clean preconfig depend distclean
.PRECIOUS: $(APPDIR)/libuserapps$(LIBEXT)

$(AOBJS): %$(OBJEXT): %.S
	$(call ASSEMBLE, $<, $@)

$(COBJS): %$(OBJEXT): %.c
	$(call COMPILE, $<, $@)

$(CXXOBJS): %$(OBJEXT): %$(CXXEXT)
	$(call COMPILEXX, $<, $@)

ifeq ($(suffix $(MAINSRC)),$(CXXEXT))
$(MAINOBJ): %$(OBJEXT): %$(CXXEXT)
	$(call COMPILEXX, $<, $@)
else
$(MAINOBJ): %$(OBJEXT): %.c
	$(call COMPILE, $<, $@)
endif

.built: $(OBJS)
	$(Q) touch $@

ifeq ($(CONFIG_BUILD_KERNEL),y)
$(BIN_DIR)$(DELIM)$(PROGNAME): $(OBJS) $(MAINOBJ)
	@echo "LD: $(PROGNAME)"
	$(Q) $(LD) $(LDELFFLAGS) $(LDLIBPATH) -o $(INSTALL_DIR)$(DELIM)$(PROGNAME) $(ARCHCRT0OBJ) $(MAINOBJ) $(LDLIBS)
	$(Q) $(NM) -u $(INSTALL_DIR)$(DELIM)$(PROGNAME)

install: $(BIN_DIR)$(DELIM)$(PROGNAME)
else
install: $(OBJS)
	$(call ARCHIVE, $(BIN), $(OBJS))
endif

preconfig:

ifeq ($(CONFIG_NSH_BUILTIN_APPS),y)
ifneq ($(APPNAME),)
ifneq ($(PRIORITY),)
ifneq ($(STACKSIZE),)
$(BUILTIN_REGISTRY)$(DELIM)$(APPNAME)_main.bdat: $(DEPCONFIG) Makefile
	$(call REGISTER,$(APPNAME),$(PRIORITY),$(STACKSIZE),$(APPNAME)_main)

context: $(BUILTIN_REGISTRY)$(DELIM)$(APPNAME)_main.bdat
else
context:
endif
else
context:
endif
else
context:
endif
else
context:
endif

.depend: Makefile $(SRCS)
ifeq ($(filter %$(CXXEXT),$(SRCS)),)
	$(Q) $(MKDEP) $(ROOTDEPPATH) "$(CC)" -- $(CFLAGS) -- $(SRCS) >Make.dep
else
	$(Q) $(MKDEP) $(ROOTDEPPATH) "$(CXX)" -- $(CXXFLAGS) -- $(SRCS) >Make.dep
endif
	$(Q) touch $@

depend: .depend

clean:
	$(call DELFILE, .built)
	$(call CLEAN)

distclean: clean
	$(call DELFILE, Make.dep)
	$(call DELFILE, .depend)

-include Make.dep
else
include $(APPDIR)/Application.mk
endif
