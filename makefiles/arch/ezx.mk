QTDIR = ~/Compile_temp/blackhawk_e2_sdk_with_gcc-arm-iwmmxt/e2-sdk/qt
TOOLSDIR = /opt/crosstool/gcc-arm-iwmmxt
EZXDIR = ~/Compile_temp/blackhawk_e2_sdk_with_gcc-arm-iwmmxt/e2-sdk/ezx

MOC = $(QTDIR)/bin/moc
RM = rm -rvf
RM_QUIET = rm -rf
QTINCLUDE = -I $(QTDIR)/include -I $(EZXDIR)/include
UILIBS = -L $(QTDIR)/lib -lqte-mt -lm -L $(EZXDIR)/lib -lqte-mt -lezxappbase -lezxappsdk -lpthread -lipp-miscGen -lipp-jp -lezxjpeg -lezxpm
CC = $(TOOLSDIR)/bin/arm-linux-gcc
AR = $(TOOLSDIR)/bin/arm-linux-ar rsu
LD = $(TOOLSDIR)/bin/arm-linux-gcc
CXX	= $(TOOLSDIR)/arm-linux-g++

# Add -DBETTER_TOOLBAR to CFLAGS to make the toolbar look better (remove bad transparency)
# You need Motorola's proprietary header called qwallpaper.h
# You can find it somewhere on the net because I can't ditributed it, copy to zlibrary/ezx/dropin
CFLAGS = -pipe -DEZX -DBETTER_TOOLBAR -DQT_NO_DEBUG -DQT_NO_DRAGANDDROP -DQT_NO_PROPERTIES -DQT_NO_TOOLBUTTON -DINSTALLDIR=\"$(INSTALLDIR)\" -DQWS -fno-exceptions -fno-rtti -fexpensive-optimizations -fomit-frame-pointer -Wall -Wno-ctor-dtor-privacy -W 
DEPGEN = $(CC) -MM

EXPATLIBS = -L ~/Compile_temp/fbreader-0.7.4g/common-lib/lib -lexpat
ENCALIBS = -L ~/Compile_temp/fbreader-0.7.4g/common-lib/lib -lenca
BZIP2LIBS = -L ~/Compile_temp/fbreader-0.7.4g/common-lib/lib -lbz2
ZLIBS = -L ~/Compile_temp/fbreader-0.7.4g/common-lib/lib -lz
