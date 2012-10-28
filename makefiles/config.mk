include $(ROOTDIR)/makefiles/platforms.mk

MAKE = ROOTDIR=$(ROOTDIR) make

include $(ROOTDIR)/makefiles/arch/$(TARGET_ARCH).mk

CFLAGS += -DLIBICONV_PLUG

ifeq "$(TARGET_STATUS)" "release"
	CFLAGS += -O1
#	LDFLAGS += -s
endif
ifeq "$(TARGET_STATUS)" "debug"
	CFLAGS += -O0 -g
endif
ifeq "$(TARGET_STATUS)" "profile"
	CFLAGS += -O3 -g -pg
endif

ZDIR = $(ROOTDIR)/zlibrary
ZINCLUDE = -I $(ROOTDIR)/zlibrary/include -I $(ROOTDIR)/common-lib/include
