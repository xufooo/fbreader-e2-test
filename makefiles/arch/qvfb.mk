INSTALLDIR = /usr/local

QTDIR = /opt/opie/qt-2.3.10
OPIEDIR = /opt/opie/opie
MOC = $(QTDIR)/bin/moc
RM = rm -rvf
RM_QUIET = rm -rf
QTINCLUDE = -I $(QTDIR)/include -I $(OPIEDIR)/include
UILIBS = -L $(QTDIR)/lib -lqte -L $(OPIEDIR)/lib -lqpe
CC = gcc
AR = ar rsu
LD = g++

EXPATLIBS = -lexpat
ENCALIBS = -lenca
BZIP2LIBS = -lbz2

CFLAGS = -pipe -DOPIE_NO_DEBUG -DOPIE_NO_BUILTIN_SHUTDOWN -DUSE_FILE_NOTIFICATION -DOPIE_SOUND_FRAGMENT_SHIFT=16 -DQT_NO_DEBUG -DINSTALLDIR=\"$(INSTALLDIR)\" -DQWS -fno-exceptions -fno-rtti -Wall -Wno-ctor-dtor-privacy -W
DEPGEN = $(CC) -MM
