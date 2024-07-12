version=3be48e27c9694d87c8c7ea5a7d7bcc58957daab9

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
	$(SHA256)   "7c2e5f17f97217a55f2be1834e20b937a8ddfeea83a598153ce05b005479c43b"

prepare: ${SOURCES}
	tar -zxf ${version}.tar.gz
	mv    neatvi-${version} build/
	mv -f files/conf.h      build

root:
	${MAKE}
	install -Dm755 vi "${root}/usr/bin/neatvi"

