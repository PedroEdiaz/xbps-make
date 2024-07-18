OBJ = \
	fail.o \
	memzero.o \
	nonzero.o \
	writeall.o

all: $(OBJ)

clean:
	rm -f *.o
