version=79a8229fb5da15135ac0c54c2c696a8da8988b24
package=tcc
pkgver=${version}_0
description=Tiny C compiler
homepage=
license=LGPL-2.1

alternatives=cc:/usr/bin/cc:tcc
shlib-requires=libc.so

include ../../Makefile

SOURCES = \
	${version}.tar.gz

FILES = \
	files/ar \
	files/Makefile \
	files/Makefile-libs

${version}.tar.gz:
	${DOWNLOAD} https://repo.or.cz/tinycc.git/snapshot/$@
	${SHA256}   ec4b05d28f83970b9f405ed50c60fe8fac88826ef7ce80fa95ec4a5cde2a319f

GITHASH = `echo ${version} | dd ibs=1 obs=1 count=7 2>/dev/null`

prepare: ${SOURCES} ${FILES}
	tar -zxf ${version}.tar.gz
	mv    tinycc-${GITHASH}   build
	mv    files/ar            build/
	mv -f files/Makefile      build/
	mv -f files/Makefile-libs build/lib/Makefile

root:
	./configure \
		--prefix=/usr \
		--cc=${CC} \
		--config-musl
	
	${MAKE} GITHASH=${GITHASH}
	${MAKE} DESTDIR=${root} install


root-posix:
	mkdir -p ${root}/usr/bin
	install -Dm 755 ar "${root}/usr/bin/ar"
	
root-man:
	install -Dm 644 tcc-doc.texi "${root}/usr/share/man/man1/tcc.texi"

