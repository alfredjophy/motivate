#!/bin/bash

pkgver=$1
echo $pkgver

cp -r data/ build/

cd build

./map >> /dev/null

cd ..
tar czf motivate-$pkgver.tar.gz build/motivate build/data/quotes.map build/data/quotes.txt
