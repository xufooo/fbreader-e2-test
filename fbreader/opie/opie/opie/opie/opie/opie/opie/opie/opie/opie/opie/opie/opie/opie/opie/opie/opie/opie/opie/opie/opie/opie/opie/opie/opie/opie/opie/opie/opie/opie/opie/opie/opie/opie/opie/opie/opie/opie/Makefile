ROOTDIR = $(PWD)/../..
include $(ROOTDIR)/makefiles/platforms.mk

BASEDIR = data/opt/QtPalmtop
DEBDIR = data/DEBIAN

version = $(shell cat ../VERSION)
package = fbreader-opie_$(version)_$(TARGET_ARCH)_arm.ipk

all:
ifneq "$(TARGET_ARCH)" "qvfb"
	@make .builddir
	@make .buildpackage
	@make .cleandir
endif

install:

clean: .cleandir
	@rm -f *.ipk

.builddir: .cleandir
	@mkdir -p $(DEBDIR)
	@mkdir -p $(BASEDIR)/bin
	@mkdir -p $(BASEDIR)/apps/Applications
	@mkdir -p $(BASEDIR)/share/zlibrary
	@cp ../../zlibrary/data/keynames.opensimpad.xml $(BASEDIR)/share/zlibrary/keynames.xml
	@cp -r ../../zlibrary/data/encodings $(BASEDIR)/share/zlibrary
	@mkdir -p $(BASEDIR)/pics/fbreader
	@sed "s/VERSION/$(version)/" control.in > $(DEBDIR)/control
	@cp ../FBReader $(BASEDIR)/bin
	@cp fbreader.desktop $(BASEDIR)/apps/Applications
	@cp ../icons/22x18/FBReader.png $(BASEDIR)/pics/fbreader
	@cp ../icons/22x18/FBReader/*.png $(BASEDIR)/pics/fbreader
	@cp -r ../share  $(BASEDIR)
	@rm -rf `find $(BASEDIR)/share -name ".svn"`
	@mkdir $(BASEDIR)/share/FBReader/help
	@cp ../data/help/HowToStart.brownish.640x480.fb2 $(BASEDIR)/share/FBReader/help/HowToStart.fb2
	@mkdir $(BASEDIR)/share/FBReader/default
ifeq "$(TARGET_ARCH)" "opensimpad-0.9.0"
	@cp ../data/default/config.opie.xml $(BASEDIR)/share/FBReader/default/config.xml
	@cp ../data/default/keymap.opie-opensimpad.xml $(BASEDIR)/share/FBReader/default/keymap.xml
	@cp ../data/default/styles.640x480.xml $(BASEDIR)/share/FBReader/default/styles.xml
endif

.buildpackage:
	@dpkg -b data $(package)
	@cp $(package) ../..

.cleandir:
	@rm -rf data
