package=sdhcp
version=8455fd2d090bd9b227340c30c92c6aa13302c91a
pkgver=${version}_0
description=Suckless dhcp client
homepage=http://git.2f30.org/${package}
license=MIT/X Consortium License

shlib-requires=libc.so

include ../../Makefile

SOURCES = \
	${package}

FILES = \
	files/Makefile \
	files/setip.c

${package}:
	export url=git://git.2f30.org pkg=$@ commit=${version} && ${GITCLONE}
	${SHA256D} "c9c990f5469d5e0b819fe5c59e05b36d7d21e8594f33b0cf71486c9926e2eb5d"

prepare: ${SOURCES}
	mv    ${package}     build
	mv -f files/Makefile build/
	mv    files/setip.c  build/

root:
	sed "s/VERSION/$(VERSION)/g" sdhcp.1 > _
	mv _ sdhcp.1
	
	sed '/setenv("DNS", buf, 1);/asetenv("IFNAME", ifname, 1);' sdhcp.c > _
	mv _ sdhcp.c
	
	${MAKE}
	install -Dm 755 sdhcp     "${root}/usr/bin/sdhcp"
	install -Dm 644 sdhcp.1   "${root}/usr/share/man/man1/sdhcp.1"

	${MAKE} setip
	install -Dm 755 setip     "${root}/usr/libexec/sdhcp/setip"

