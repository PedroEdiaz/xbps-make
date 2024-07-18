package=nldev
version=0.4
pkgver=${version}_0
description=netlink device manager
homepage=http://r-36.net/scm/${package}/log.html
license=MIT/X Consorium License

shlib-requires=libc.so

SOURCES = \
	${package}

FILES = \
	files/config.h

include ../../Makefile

${package}:
	export url=git://r-36.net pkg=$@ commit=v${version} && ${GITCLONE}
	${SHA256D} "08a4bdcfe118857afa868c197f0488b0c9c4104f3425ed79bd19c3999c2a1723"

prepare: ${SOURCES}
	mv    ${package}     build
	mv -f files/config.h build/
	:  > config.mk

root:
	${MAKE} LDFLAGS=
	install -Dm 755 nldev   "${root}/usr/bin/nldev"
	install -Dm 644 nldev.8 "${root}/usr/share/man/man8/nldev.8"
