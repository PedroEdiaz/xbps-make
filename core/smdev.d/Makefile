package=smdev
version=8d07540c417e3a31942028318197c89b640278d5
pkgver=${version}_0
description=suckless mdev
homepage=http://git.suckless.org/smdev
license=MIT/X Consortium License

shlib-requires=libc.so

SOURCES = \
	${package}

FILES = \
	files/Makefile

include ../../Makefile

${package}:
	export url=git://git.suckless.org pkg=$@ commit=${version} && ${GITCLONE}
	${SHA256D} "72696381df1e5601a7d9b51f2af1e2df0fc4a33b7e06b8e62fe60c9cef180e19"

prepare: ${SOURCES}
	mv    ${package}     build
	mv -f files/Makefile build/

	sed '/#include "util.h"/a#include <sys/sysmacros.h>' build/smdev.c > _
	mv -f _ build/smdev.c

root:
	${MAKE}
	install -Dm 755 smdev "${root}/usr/bin/smdev"

