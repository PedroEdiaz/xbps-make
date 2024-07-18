package=smdev
version=0.2.3
pkgver=${version}_0
description=suckless mdev
homepage=http://git.suckless.org/${package}
license=MIT/X Consortium License

shlib-requires=libc.so

SOURCES = \
	${package}

FILES = \
	files/Makefile

include ../../Makefile

${package}:
	export url=git://git.suckless.org pkg=$@ commit=v${version} && ${GITCLONE}
	${SHA256D} "2c29eea2bb3c7b39d094831353fd1a701f562d467b3b3bedd7ac625a315d7e8b"

prepare: ${SOURCES}
	mv    ${package}     build
	mv -f files/Makefile build/

	sed '/#include "util.h"/a#include <sys/sysmacros.h>' build/smdev.c > _
	mv -f _ build/smdev.c

root:
	${MAKE}
	install -Dm 755 smdev "${root}/usr/bin/smdev"

