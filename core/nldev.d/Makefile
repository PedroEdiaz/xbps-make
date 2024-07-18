package=nldev
version=662ba24641d02fd93e6a5e43041805ce2bee9328
pkgver=${version}_0
description=netlink device manager
homepage=http://r-36.net/scm/nldev/log.html
license=MIT/X Consorium License

SOURCES = \
	${package}

FILES = \
	files/config.h

include ../../Makefile

${package}:
	export url=git://r-36.net pkg=$@ commit=${version} && ${GITCLONE}
	${SHA256D} "c33daf0cf87c57940b16dce3727cea86432a1a48021212bccd5a6e5324ac0a2e"

prepare: ${SOURCES}
	mv    ${package}     build
	mv -f files/config.h build/

root:
	${MAKE}
	install -Dm 755 nldev   "${root}/usr/bin/nldev"
	install -Dm 644 nldev.8 "${root}/usr/share/man/man8/nldev.8"
