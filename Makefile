PREFIX ?= /usr
motivate:	src/motivate.cpp
	mkdir build
	g++ -o build/motivate src/motivate.cpp
	g++ -o build/map src/map.cpp
install:	motivate
	./map
	mkdir -p  $(DESTDIR)$(PREFIX)/bin
	cp -p motivate $(DESTDIR)$(PREFIX)/bin
	mkdir -p $(DESTDIR)$(PREFIX)/share/motivate
	cp -p data/quotes.txt  $(DESTDIR)$(PREFIX)/share/motivate/
	cp -p data/quotes.map $(DESTDIR)$(PREFIX)/share/motivate/
clean:
	rm -rf build/ *.tar.gz 

