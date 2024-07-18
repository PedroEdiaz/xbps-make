version=16
package=neatvi
pkgver=${version}_0
description=A small vi/ex editor editing bidirectional UTF-8 text
homepage=https://github.com/aligrudi/neatvi
license=ISC
replaces=nvi

alternatives=vi:/usr/bin/vi:neatvi ex:/usr/bin/ex:neatvi
shlib-requires=libc.so

include ../../Makefile


SOURCES = \
	${version}.tar.gz

FILES = \
	files/conf.h

${version}.tar.gz:
	$(DOWNLOAD) ${homepage}/archive/$@
	$(SHA256)   "7ceae3d6433d514c642e6a8bd1cd0fa2992095d64ff2e8a02a40ce90113d6e9f"

prepare: ${SOURCES}
	tar -zxf ${version}.tar.gz
	mv    neatvi-${version} build/
	mv -f files/conf.h      build

root:
	${MAKE}
	install -Dm755 vi "${root}/usr/bin/neatvi"

