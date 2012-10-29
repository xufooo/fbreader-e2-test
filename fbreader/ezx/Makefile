ROOTDIR = $(PWD)/../..
include $(ROOTDIR)/makefiles/platforms.mk

BASEDIR = mpkg/fbreader

version = $(shell cat ../VERSION)
package = fbreader_$(version)_$(TARGET_ARCH).mpkg

all:
	@make .builddir
	@make .buildpackage
	@make .cleandir

install:

clean: .cleandir
	@rm -f *.mpkg

.builddir: .cleandir
	@mkdir -p $(BASEDIR)/bin
	@mkdir -p $(BASEDIR)/lib
	@mkdir -p $(BASEDIR)/share/zlibrary
	@cp ../../zlibrary/data/keynames.ezx.xml $(BASEDIR)/share/zlibrary/keynames.xml
	@cp -r ../../zlibrary/data/encodings $(BASEDIR)/share/zlibrary
	@cp ../FBReader $(BASEDIR)/bin
	@cp ../LICENSE $(BASEDIR)
	@cp fbreader.desktop $(BASEDIR)
	@cp fbreader.sh $(BASEDIR)
	@cp fbreader-b.png $(BASEDIR)
	@cp fbreader-s.png $(BASEDIR)
	@mkdir -p $(BASEDIR)/pics
	@cp ../icons/18x15/FBReader.png $(BASEDIR)/pics
	@cp ../icons/18x15/FBReader/*.png $(BASEDIR)/pics
	@cp -r ../share  $(BASEDIR)
	@rm -rf `find $(BASEDIR)/share -name ".svn"`
	@mkdir $(BASEDIR)/share/FBReader/help
	@cp ../data/help/HowToStart.brownish.240x320.fb2 $(BASEDIR)/share/FBReader/help/HowToStart.fb2
	@mkdir $(BASEDIR)/share/FBReader/default
	@cp ../data/default/config.ezx.xml $(BASEDIR)/share/FBReader/default/config.xml
	@cp ../data/default/keymap.ezx.xml $(BASEDIR)/share/FBReader/default/keymap.xml
	@cp ../data/default/styles.ezx.xml $(BASEDIR)/share/FBReader/default/styles.xml
	@cp ../../common-lib/lib/libenca.so.0.5.1 $(BASEDIR)/lib/libenca.so.0
	@cp ../../common-lib/lib/libexpat.so.1.5.2 $(BASEDIR)/lib/libexpat.so.1

.buildpackage:
	@tar czf $(package) -C mpkg fbreader
	@cp $(package) ../..

.cleandir:
	@rm -rf mpkg
