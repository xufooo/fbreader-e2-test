QTDIR = /home/ooo/Work/Compile/blackhawk_e2_sdk_with_gcc-arm-iwmmxt/e2-sdk/qt
TOOLSDIR = /home/ooo/Work/Compile/blackhawk_e2_sdk_with_gcc-arm-iwmmxt/gcc-arm-iwmmxt/gcc-3.3.6-glibc-2.3.2/arm-linux
EZXDIR = /home/ooo/Work/Compile/blackhawk_e2_sdk_with_gcc-arm-iwmmxt/e2-sdk/ezx

MOC = $(QTDIR)/bin/moc
RM = rm -rvf
RM_QUIET = rm -rf
QTINCLUDE = -I $(QTDIR)/include -I $(EZXDIR)/include
UILIBS = -L $(QTDIR)/lib -L $(EZXDIR)/lib -lezxappbase -lpthread -lqte-mt #-lipp-miscGen -lipp-jp -lezxjpeg -lezxpm #-lezxappsdk 
CC = $(TOOLSDIR)/bin/arm-linux-gcc
AR = $(TOOLSDIR)/bin/arm-linux-ar rsu
LD = $(TOOLSDIR)/bin/arm-linux-g++
CXX	= $(TOOLSDIR)/bin/arm-linux-g++

# Add -DBETTER_TOOLBAR to CFLAGS to make the toolbar look better (remove bad transparency)
# You need Motorola's proprietary header called qwallpaper.h
# You can find it somewhere on the net because I can't ditributed it, copy to zlibrary/ezx/dropin
CFLAGS = -pipe -DQWS -fno-exceptions -fno-rtti -Wall -W -mcpu=iwmmxt -mtune=iwmmxt -DEZX -DQT_NO_DEBUG -DQT_NO_DRAGANDDROP -DQT_NO_PROPERTIES -DQT_NO_TOOLBUTTON# -Wno-ctor-dtor-privacy -fexpensive-optimizations -fomit-frame-pointer -DINSTALLDIR=\"$(INSTALLDIR)\" -v -Q 
LDFLAGS = -Wl,-rpath-link,$(QTDIR)/lib:$(EZXDIR)/lib,-rpath,./
#DEPGEN = $(CC) -MM

EXPATLIBS = -L /home/ooo/Work/Compile/fbreader-0.7.4g/common-lib/lib -lexpat
ENCALIBS = -L /home/ooo/Work/Compile/fbreader-0.7.4g/common-lib/lib -lenca
BZIP2LIBS = -L /home/ooo/Work/Compile/fbreader-0.7.4g/common-lib/lib -lbz2
ZLIBS = -L /home/ooo/Work/Compile/fbreader-0.7.4g/common-lib/lib -lz
