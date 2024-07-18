package=wsupp-libc
version=ba3de6001c02304fa9da7af886958bc13a3760b8
pkgver=${version}_0
description=wpa supplicant from minibase ported to standard libc
homepage=https://github.com/arsv/${package}
license=GPL-3.0 license

shlib-requires=libc.so

include ../../Makefile

SOURCES = \
	${version}.tar.gz

FILES = \
	files/Makefile \
	files/common.mk \
	files/crypto.mk \
	files/nlusctl.mk \
	files/netlink.mk 

${version}.tar.gz:
	${DOWNLOAD} ${homepage}/archive/$@
	${SHA256} "260d50874378509a0a67245f3765ffbfe515c8a2b61fe3171104aa887c62d71c"

prepare: ${SOURCES}
	tar -zxf ${version}.tar.gz
	mv ${package}-${version} build
	mv files/Makefile build
	mv files/common.mk build/common/Makefile
	mv files/crypto.mk build/crypto/Makefile
	mv files/nlusctl.mk build/nlusctl/Makefile
	mv files/netlink.mk build/netlink/Makefile
	
	sed "s/\"dhcp/\"\/bin\/sdhcp/g" build/wsupp_ifmon.c > _
	mv _ build/wsupp_ifmon.c

	sed "s/ctrl\///" build/control.h > _
	mv _ build/control.h


root:
	${MAKE}
	install -Dm 755 wifi "${root}/usr/bin/wifi"
	install -Dm 755 wsupp "${root}/usr/bin/wsupp"

