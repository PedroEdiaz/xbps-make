package=oksh
version=7.1
pkgver=${version}_0
description=Portable OpenBSD ksh
conflict=
homepage=http://github.com/ibara/oksh
license=BSD-3-Clause
replace=

alternatives=sh:/usr/bin/sh:oksh
shlib-provides=
shlib-requires=libc.so

include ../../Makefile

SOURCES = \
	${package}-${version}.tar.gz

${package}-${version}.tar.gz:
	${DOWNLOAD} https://github.com/ibara/oksh/archive/$@
	${SHA256} "244ac5fed6e22b5cb0e817e9825f8fe755d5d648ed925940e77a3725f5b763a4"

prepare: ${SOURCES}
	tar -zxf ${package}-${version}.tar.gz
	mv ${package}-${package}-${version} build

root:
	./configure --prefix=/usr
	${MAKE}
	${MAKE} DESTDIR=${root} install

	ln -sf oksh "${root}/usr/bin/sh"

