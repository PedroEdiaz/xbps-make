.SUFFIXES: .c .o .so

AR = ar
ARFLAGS = -rv

CC = cc
CFLAGS = -Wall -std=c99

.c:
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $<

.c.o:
	${CC} ${CFLAGS} -o $@ -c $<

.c.so:
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ -shared $<

.SUFFIXES: .t .aux .pdf .grap .pic

.t.aux:
	sed '/^\s*$$/d' $<|soin|pic|tbl >$@

.aux.pdf:
	cat $<|eqn |roff $(ROFFLAGS) |pdf >$@

.grap.pic:
	grap $< |sed 's/aligned//g' > $@
