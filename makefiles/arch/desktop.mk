INSTALLDIR=/usr/local

CC = gcc
AR = ar rsu
LD = g++

DEPGEN = $(CC) -MM
CFLAGS = -pipe -fno-exceptions -fno-rtti -Wall -Wno-ctor-dtor-privacy -W -DINSTALLDIR=\"$(INSTALLDIR)\"

MOC = moc-qt3
QTINCLUDE = -I /usr/include/qt3

GTKINCLUDE = $(shell pkg-config --cflags gtk+-2.0)

ifeq "$(UI_TYPE)" "qt"
	UILIBS = -lqt-mt
else
	UILIBS = $(shell pkg-config --libs gtk+-2.0)
endif

EXPATLIBS = -lexpat
ENCALIBS = -lenca
BZIP2LIBS = -lbz2

RM = rm -rvf
RM_QUIET = rm -rf
