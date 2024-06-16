version=0.9.2

package=st
pkgver=${version}_0
description=st is a simple terminal implementation for X
conflict=
homepage=https://github.com/aligrudi/neatvi
license=
provides=
replaces=
dependecies=

alternatives=
shlib-provies=
shlib-requires=libc.so libXft.so.2

include ../../Makefile


SOURCES =  \
	${package}

FILES = \
	files/config.h

${package}:
	export url="git://git.suckless.org" pkg=${package} commit=${version} && ${GITCLONE}

prepare: ${SOURCES}
	mv ${package}  build/
	mv -f files/config.h  build

root:
	${MAKE} CFLAGS=-I/usr/include/freetype2
	install -Dm755 st "${root}/usr/bin/st"

