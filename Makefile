PREFIX ?= /usr
BUILDDIR ?= build

motivate:	src/motivate.cpp
	mkdir -p $(BUILDDIR)
	g++ -o $(BUILDDIR)/motivate src/motivate.cpp
	gcc -o $(BUILDDIR)/map src/map.c
	mkdir -p $(BUILDDIR)/data
	cp data/quotes.txt $(BUILDDIR)/data/
	$(BUILDDIR)/map $(BUILDDIR)/data/quotes.txt $(BUILDDIR)/data/quotes.map
install:	motivate
	mkdir -p  $(DESTDIR)$(PREFIX)/bin
	cp -p $(BUILDDIR)/motivate $(DESTDIR)$(PREFIX)/bin
	mkdir -p $(DESTDIR)$(PREFIX)/share/motivate
	cp -p $(BUILDDIR)/data/quotes.txt  $(DESTDIR)$(PREFIX)/share/motivate/
	cp -p $(BUILDDIR)/data/quotes.map $(DESTDIR)$(PREFIX)/share/motivate/
uninstall:
	rm -rf $(DESTDIR)$(PREFIX)/bin/motivate
	rm -rf $(DESTDIR)$(PREFIX)/share/motivate
clean:
	rm -rf build/ *.tar.gz 

