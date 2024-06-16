.POSIX:

OBJECTS = \
	tcc.o \
	libtcc.o  \
	tccpp.o \
	tccgen.o \
	tccdbg.o \
	tccelf.o \
	tccasm.o \
	tccrun.o  \
	x86_64-gen.o  \
	x86_64-link.o \
	i386-asm.o

ONE_SOURCE=0
include config.mak

XCFLAGS = ${CFLAGS} -I. ${NATIVE_DEFINES} \
	-DTCC_TARGET_X86_64 -DTCC_MUSL  -DONE_SOURCE=${ONE_SOURCE}

.SUFFIXES: .c .o .S

.c.o:
	${CC} ${XCFLAGS} -c $<

all: tcc libs

tcc: libtcc.a tcc.o
	${CC} -o tcc tcc.o libtcc.a -lm -lpthread -ldl -s

tcc.o:
	${CC} ${XCFLAGS} -DTCC_GITHASH="\"HEAD:${GITHASH}\"" -c tcc.c

tccpp.o: tccdefs_.h

tccdefs_.h:
	${CC} -DC2STR conftest.c -o c2str.exe 
	./c2str.exe include/tccdefs.h tccdefs_.h

libtcc.a: ${OBJECTS}
	${AR} ${ARFLAGS} $@ ${OBJECTS}

libs: tcc
	${MAKE} CC=../tcc -C ./lib

clean:
	rm ${OBJECTS} libtcc.a c2str.ext tccdefs_.h tcc

install: tcc libs
	install -Dm 755 tcc            $(bindir)/tcc
	install -Dm 644 lib/libtcc1.a  $(libdir)/libtcc1.a
