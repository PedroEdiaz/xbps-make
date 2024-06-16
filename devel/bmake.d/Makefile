version=20220726

package=bmake
pkgver=${version}_0
description=BSD Make tool
conflict=
homepage=http://crufy.net/help/sjg/bmake.html
license=BSD-3-Clause
replace=

alternatives=make:/usr/bin/make:bmake
shlib-provides=
shlib-requires=libc.so

include ../../Makefile
 

SOURCES = \
	bmake-${version}.tar.gz 

FILES = \
	files/sys.mk

bmake-${version}.tar.gz:
	${DOWNLOAD} https://www.crufty.net/ftp/pub/sjg/$@
	${SHA256}   "1bf3770789722721dca7b0bff8afc4a9520da20f0219bb7bc52350af0133f0a0"

prepare: ${SOURCES}
	tar -zxf bmake-${version}.tar.gz
	mv    bmake        build
	mv -f files/sys.mk build/mk/sys.mk

root:
	./configure
	prefix=/usr sh make-bootstrap.sh

	install -Dm 755 bmake     "${root}/usr/bin/bmake"
	install -Dm 644 mk/sys.mk "${root}/usr/share/mk/sys.mk"
	: > "${root}/usr/share/mk/posix.mk"

root-man:
	install -Dm 755 make.1 "${root}/usr/share/man/man1/bmake.1"

