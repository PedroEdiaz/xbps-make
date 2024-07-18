version=1.0.3
package=libudev-zero
pkgver=${version}_0
description=Daemonless replacement for libudev
homepage=https://github.com/illiliti/${package}
license=ISC
conflicts=eudev-libudev
replaces=eudev-libudev

shlib-provides=libudev.so.1

include ../../Makefile

SOURCES = \
	${version}.tar.gz

${version}.tar.gz:
	${DOWNLOAD} ${homepage}/archive/$@
	${SHA256}   "0bd89b657d62d019598e6c7ed726ff8fed80e8ba092a83b484d66afb80b77da5"

prepare: ${SOURCES}
	tar -zxf ${version}.tar.gz
	mv libudev-zero-${version} build

root:
	${MAKE}
	${MAKE} contrib/helper
	
	${MAKE} PREFIX="${root}/usr" install
	install -Dm 755 contrib/helper "${root}/usr/libexec/libudev-zero/helper"

