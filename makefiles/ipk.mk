DEB_VERSION = 2.0

ARCH = arm

TDIR = __ipk

DATADIR = $(TDIR)/data
CTRLDIR = $(TDIR)/control

FILE = $(wildcard *.control)
PACKAGENAME = $(patsubst %.control, %, $(FILE))

version = $(shell cat ../VERSION)
depends = $(shell sed -n -e "s/^Depends: *//p" $(FILE))
files = $(shell sed -n -e "s/^Files://p" $(FILE))
package = $(PACKAGENAME)_$(version)_$(ARCH)

all: .tmpdir .copyfiles $(CTRLDIR)/control package .rmtmpdir

.tmpdir:
	@ln -sf .. bin
	@rm -rf $(TDIR)
	@mkdir -p $(DATADIR) $(CTRLDIR)

.rmtmpdir:
	@rm -rf bin $(TDIR)

.copyfiles:
	@for f in $(files); do \
		if [ -d $f ]; then \
			ffiles=`find $$f -type f -o -type b -o -type c -o -type l`; \
  	else \
  		ffiles=$$f; \
  	fi; \
  	for ff in $$ffiles; do \
  		if [ -f $$ff -o -b $$ff -o -c $$ff ]; then \
				fdir=$(DATADIR)/opt/QtPalmtop/`dirname $$ff`; \
				mkdir -p $$fdir; \
				cp $$ff $$fdir; \
			else \
  			echo >&2 "No such file: $$ff"; \
				exit 1; \
  		fi; \
  	done; \
  done;

$(CTRLDIR)/control:
	@echo "Package: $(PACKAGENAME)" > $@
	@echo -n "Installed-Size: " >> $@
	@du -b -s $(DATADIR) | sed -e 's/[	 ].*//' >> $@
	@echo "Filename: ./$(package).ipk" >> $@
	@echo "Version: $(version)" >> $@
	@echo "Depends: $(depends)" >> $@
	@egrep -v "^(Files|Version|Depends):" $(FILE) >> $@

package:
	@echo -n "Packaging..."
	@echo "$(DEB_VERSION)" > $(TDIR)/debian-binary
	@tar czf $(TDIR)/control.tar.gz -C $(CTRLDIR) .
	@tar czf $(TDIR)/data.tar.gz -C $(DATADIR) .
	@rm -rf $(CTRLDIR) $(DATADIR)
	@tar czf $(package).ipk -C $(TDIR) ./debian-binary ./control.tar.gz ./data.tar.gz
	@echo " OK"

clean:
	@rm -vf *.ipk
