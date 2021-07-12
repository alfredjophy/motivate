#!/bin/bash

pkgver=$1

bold=$(tput bold)
normal=$(tput sgr0)

echo "${bold}creating release $pkgver${normal}"

make

tar czf motivate-$pkgver.tar.gz build/

gh release create $pkgver motivate-$pkgver.tar.gz

echo "${bold}updating PKGBUILD${normal}"

sed -i "/^pkgver*/c pkgver=$pkgver" PKGBUILD
bat PKGBUILD

