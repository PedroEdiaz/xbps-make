# VARIABLES
USER= `git config --get user.name`
MAIL= `git config --get user.email`
ARCH=x86_64-musl
CACHEDIR = ${XDG_CACHE_HOME}/xbps-make
BUILDDIR = ${XDG_RUNTIME_DIR}/xbps-make
XBPSDIR = ${XDG_CACHE_HOME}/xbps
POSIX=yes
MAN=yes

# PROTOTYPES
.SUFFIXES: .d .xbps .src

.d.src:
	mkdir -p ${BUILDDIR}
	${MAKE} -C $< ${CACHEDIR}/`basename $@`
	rm -rf ${BUILDDIR}

.d.xbps:
	mkdir -p ${BUILDDIR}
	${MAKE} -C $< ${CACHEDIR}/`basename $@`
	rm -rf ${BUILDDIR}

# Default
help:
	cat README

# BUILD RULES
${CACHEDIR}/${package}.src: ${CACHEDIR}
	test -d files && mkdir -p files && cp -R files ${BUILDDIR}/files || true
	${MAKE} -C ${BUILDDIR} -f `pwd`/Makefile prepare
	tar -z -cf $@ -C ${BUILDDIR}/build . 

${CACHEDIR}/${package}.xbps: ${CACHEDIR} ${BUILDDIR}/root
	xbps-create \
		-A ${ARCH} \
		-B xbps-make_0 \
		-m "${USER} <${MAIL}>" \
		-n ${package}-${pkgver} \
		-s "${description}" \
		-C "${conflicts}" \
		-D "${dependecies}" \
		-H "${homepage}" \
		-l "${license}" \
		-P "${provides}" \
		-R "${replaces}" \
		--alternatives "${alternatives}" \
		--shlib-provides "${shlib-provides}" \
		--shlib-requires "${shlib-requires}" \
		${BUILDDIR}/root 
	mv *.xbps ${XBPSDIR}
	xbps-rindex -af ${XBPSDIR}/${package}-${pkgver}.${ARCH}.xbps

${BUILDDIR}/root: ${BUILDDIR}/build
	${MAKE} -C ${BUILDDIR}/build -f `pwd`/Makefile root=$@ \
		root root-posix-${POSIX} root-man-${MAN}
	
	test -f `pwd`/postinstall.sh && install -Dm 755 `pwd`/postinstall.sh "$@/var/db/bmpm/${package}.sh" || true

${BUILDDIR}/build:
	mkdir -p $@
	tar -z -xf ${CACHEDIR}/${package}.src -C $@

${CACHEDIR}:
	mkdir -p $@

clean:
	rm -r ${BUILDDIR}

# OPTION BUILDS
root-posix:
root-posix-no:
root-posix-yes: root-posix
root-man:
root-man-yes: root-man
root-man-no:

# UTIL
DOWNLOAD = curl -sLO 
SHA256   = test `sha256sum $@ |sed 's/\s.*//'` = 
SHA256D  = test `find $@ -type f |xargs sha256sum|sort|sha256sum|sed 's/\s.*//'` =

GITCLONE = \
	git clone $$url/$$pkg &&\
        git -C $$pkg reset --hard $$commit &&\
	rm -rf $$pkg/.git
