include config.mk

.POSIX:
.SUFFIXES: .c .o

LIB = \
	util/agetcwd.o      \
	util/apathmax.o     \
	util/dev.o          \
	util/eprintf.o      \
	util/estrtol.o      \
	util/mkpath.o       \
	util/recurse.o      \
	util/strlcpy.o

BIN = smdev

OBJ = $(BIN).o $(LIB)
MAN = $(BIN).1

all: options $(BIN)

options:
	@echo mdev build options:
	@echo "CFLAGS   = $(CFLAGS)"
	@echo "LDFLAGS  = $(LDFLAGS)"
	@echo "CC       = $(CC)"

$(BIN): $(BIN).o

$(OBJ): config.h util.h config.mk

config.h:
	@echo creating $@ from config.def.h
	@cp config.def.h $@

.o: util.a
	@echo LD $@
	@$(LD) -o $@ $< util.a $(LDFLAGS)

.c.o:
	@echo CC $<
	@$(CC) -c -o $@ $< $(CFLAGS)

util.a: $(LIB)
	@echo AR $@
	@$(AR) -r -c $@ $(LIB)

install: all
	@echo installing executable to $(DESTDIR)$(PREFIX)/bin
	@mkdir -p $(DESTDIR)$(PREFIX)/bin
	@cp -f $(BIN) $(DESTDIR)$(PREFIX)/bin
	@cd $(DESTDIR)$(PREFIX)/bin && chmod 755 $(BIN)

uninstall:
	@echo removing executable from $(DESTDIR)$(PREFIX)/bin
	@cd $(DESTDIR)$(PREFIX)/bin && rm -f $(BIN)

clean:
	@echo cleaning
	@rm -f $(BIN) $(OBJ) $(LIB) util.a
