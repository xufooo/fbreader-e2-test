ROOTDIR = $(PWD)/..
MAKEFILESDIR = $(ROOTDIR)/makefiles
include $(MAKEFILESDIR)/config.mk

TARGET = libzlibrary.a
#TARGET = libzlibrary.so

SUBDIRS_ALL = abstract/runnable abstract/time abstract/dialogs abstract/filesystem abstract/filesystem/zip abstract/filesystem/bzip2 abstract/filesystem/tar abstract/options abstract/util abstract/xml abstract/xml/expat abstract/encoding abstract/deviceInfo abstract/application abstract/view abstract/image abstract/xmlconfig desktop/dialogs unix/filesystem unix/time
QTSUBDIRS_ALL = qt/time qtopia/application qtopia/dialogs qtopia/deviceInfo qtopia/view qt/dialogs qt/deviceInfo qt/view qt/image qt/util opie/view opie/dialogs opie/application qt/application-desktop qt/application-pdaxrom ezx/view ezx/dialogs ezx/application ezx/dropin
GTKSUBDIRS_ALL = gtk/time gtk/dialogs gtk/deviceInfo gtk/view-desktop gtk/view-pdaxrom gtk/image gtk/util maemo/dialogs maemo/deviceInfo maemo/view gpe/dialogs gpe/view gtk/application-desktop gtk/application-pdaxrom maemo/application-maemo maemo/application-maemo2 gpe/application

SUBDIRS = abstract/runnable abstract/time abstract/dialogs abstract/filesystem abstract/filesystem/zip abstract/filesystem/bzip2 abstract/filesystem/tar abstract/options abstract/util abstract/xml abstract/xml/expat abstract/encoding abstract/image abstract/xmlconfig desktop/dialogs abstract/deviceInfo abstract/application abstract/view unix/filesystem unix/time

ifeq "$(UI_TYPE)" "qt"
	QTSUBDIRS = qt/time qt/dialogs qt/deviceInfo qt/view qt/image qt/util
ifeq "$(TARGET_ARCH)" "desktop"
	QTSUBDIRS += qt/application-desktop
else
	QTSUBDIRS += qt/application-pdaxrom
endif
endif

ifeq "$(UI_TYPE)" "gtk"
	GTKSUBDIRS = gtk/time gtk/dialogs gtk/deviceInfo gtk/image gtk/util
ifeq "$(TARGET_ARCH)" "desktop"
	GTKSUBDIRS += gtk/view-desktop gtk/application-desktop
else
	GTKSUBDIRS += gtk/view-pdaxrom gtk/application-pdaxrom
endif
endif

ifeq "$(UI_TYPE)" "gpe"
	GTKSUBDIRS = gtk/time gpe/dialogs gpe/application gtk/deviceInfo gtk/image gtk/util gpe/view
  SUBDIRS = abstract/time abstract/dialogs abstract/filesystem abstract/filesystem/zip abstract/filesystem/bzip2 abstract/filesystem/tar abstract/options abstract/util abstract/xml abstract/xml/expat abstract/encoding abstract/image abstract/xmlconfig abstract/deviceInfo abstract/application abstract/view unix/filesystem unix/time
endif

ifeq "$(UI_TYPE)" "opie"
	SUBDIRS = abstract/time abstract/dialogs abstract/filesystem abstract/filesystem/zip abstract/filesystem/bzip2 abstract/filesystem/tar abstract/options abstract/util abstract/xml abstract/xml/expat abstract/encoding abstract/image abstract/xmlconfig abstract/deviceInfo abstract/application abstract/view unix/filesystem unix/time
	QTSUBDIRS = qt/time opie/dialogs opie/application qtopia/deviceInfo opie/view qt/image qt/util
endif

ifeq "$(UI_TYPE)" "ezx"
	SUBDIRS = abstract/time abstract/dialogs abstract/filesystem abstract/filesystem/zip abstract/filesystem/bzip2 abstract/filesystem/tar abstract/options abstract/util abstract/xml abstract/xml/expat abstract/encoding abstract/image abstract/xmlconfig abstract/deviceInfo abstract/application abstract/view unix/filesystem unix/time
	QTSUBDIRS = qt/time ezx/dialogs ezx/application qtopia/deviceInfo ezx/view ezx/dropin qt/image qt/util
endif

ifeq "$(UI_TYPE)" "qtopia"
	SUBDIRS = abstract/time abstract/dialogs abstract/filesystem abstract/filesystem/zip abstract/filesystem/bzip2 abstract/filesystem/tar abstract/options abstract/util abstract/xml abstract/xml/expat abstract/encoding abstract/deviceInfo abstract/application abstract/view unix/filesystem unix/time abstract/image abstract/xmlconfig
	QTSUBDIRS = qt/time qtopia/application qtopia/dialogs qtopia/deviceInfo qtopia/view qt/util qt/image
endif

ifeq "$(UI_TYPE)" "$(findstring $(UI_TYPE), maemo maemo2)"
	GTKSUBDIRS = gtk/time maemo/dialogs maemo/deviceInfo maemo/view gtk/image gtk/util maemo/application-$(UI_TYPE)
endif

.objects:
	@for subdir in $(SUBDIRS); do \
		if [ -d $$subdir ]; then \
			if ! $(MAKE) -C $$subdir -f $(MAKEFILESDIR)/subdir.mk; then \
				exit 1; \
			fi; \
		fi; \
	done;
	@for subdir in $(QTSUBDIRS); do \
		if [ -d $$subdir ]; then \
			if ! $(MAKE) -C $$subdir -f $(MAKEFILESDIR)/qsubdir.mk; then \
				exit 1; \
			fi; \
		fi; \
	done;
	@for subdir in $(GTKSUBDIRS); do \
		if [ -d $$subdir ]; then \
			if ! $(MAKE) -C $$subdir -f $(MAKEFILESDIR)/gtksubdir.mk; then \
				exit 1; \
			fi; \
		fi; \
	done;

$(TARGET): .objects
	@echo -n "Creating $@ ..."
	@$(RM_QUIET) $(TARGET)
	@$(AR) $(TARGET) `find . -name *.o`
#	@$(CC) `find . -name *.o` -fPIC -shared -o $(TARGET)
	@echo " OK"

install: $(TARGET)

clean:
	@for subdir in $(SUBDIRS_ALL); do \
		if [ -d $$subdir ]; then \
			$(MAKE) -C $$subdir -f $(MAKEFILESDIR)/subdir.mk clean; \
		fi; \
	done;
	@for subdir in $(QTSUBDIRS_ALL); do \
		if [ -d $$subdir ]; then \
			$(MAKE) -C $$subdir -f $(MAKEFILESDIR)/qsubdir.mk clean; \
		fi; \
	done;
	@for subdir in $(GTKSUBDIRS_ALL); do \
		if [ -d $$subdir ]; then \
			$(MAKE) -C $$subdir -f $(MAKEFILESDIR)/gtksubdir.mk clean; \
		fi; \
	done;
	@$(RM) $(TARGET)
