version=0.9.2
package=st
pkgver=${version}_0
description=st is a simple terminal implementation for X
homepage=https://git.suckless.org/st
license=MIT/X Consortium License

shlib-requires=libc.so libXft.so.2

include ../../Makefile


SOURCES =  \
	${package}

FILES = \
	files/config.h

${package}:
	export url="git://git.suckless.org" pkg=${package} commit=${version} && ${GITCLONE}
	$(SHA256D) "b734416dd95db2e5bc029f25c28a62e28b7b4f22558488e215f7477a0f092899"

prepare: ${SOURCES}
	mv ${package}  build/
	mv -f files/config.h  build

root:
	${MAKE} CFLAGS=-I/usr/include/freetype2
	install -Dm755 st "${root}/usr/bin/st"

