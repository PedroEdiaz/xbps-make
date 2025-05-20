version=0.9.2
package=st
pkgver=${version}_0
description=st is a simple terminal implementation for Wayland
homepage=https://git.suckless.org/${package}
license=MIT/X Consortium License

shlib-requires=libc.so libXft.so.2

include ../../Makefile


SOURCES =  \
	${package}

FILES = \
	files/config.h \

${package}:
	export url="git://git.suckless.org" pkg=${package} commit=${version} && ${GITCLONE}
	#$(SHA256D) "161bbf218209d4278ab3d4124b42c3aeee7abe928ee5dc3771075f1bafd3ac76"

prepare: ${SOURCES}
	mv st  build/
	mv -f files/config.h  build

root:
	${MAKE} CFLAGS=-I/usr/include/freetype2
	install -Dm755 st "${root}/usr/bin/st"

