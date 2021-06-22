PREFIX ?= /usr
motivate:	motivate.cpp
	g++ -o motivate motivate.cpp
install:	motivate
	mkdir -p  $(DESTDIR)$(PREFIX)/bin
	cp -p motivate $(DESTDIR)$(PREFIX)/bin
	mkdir -p $(DESTDIR)$(PREFIX)/share/motivate
	cp -p quotes.txt  $(DESTDIR)$(PREFIX)/share/motivate/

