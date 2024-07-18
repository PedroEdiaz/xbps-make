version=2.29
package=thttpd
pkgver=${version}_0
description=thttpd is a simple, small, portable, fast, and secure HTTP server.
homepage=https://www.acme.com/software/thttpd
license=BSD-2-Clause

shlib-requires=libc.so 

include ../../Makefile


SOURCES =  \
	${package}-${version}.tar.gz

FILES = \
	files/mime_types.h

${package}-${version}.tar.gz:
	${DOWNLOAD} ${homepage}/$@

prepare: ${SOURCES}
	tar -zxf ${package}-${version}.tar.gz
	mv ${package}-${version}  build/
	mv -f files/mime_types.h  build

root:
	MAKE=${MAKE} ./configure
	bmake
	install -Dm755 thttpd "${root}/usr/bin/thttpd"
root-man:
	install -Dm644 thttpd.8 "${root}/usr/share/man/man8/thttpd.8"

