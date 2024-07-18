OBJ= \
	get.o \
	get_base.o \
	get_nest.o \
	put.o \
	recv.o \
	recv_msg.o

all: $(OBJ)

clean:
	rm -f *.o
