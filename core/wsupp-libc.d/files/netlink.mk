OBJ = \
	attr_bin.o \
	attr_buf.o \
	attr_gen.o \
	attr_nst.o \
	attr_str.o \
	attr_sub.o \
	base_err.o \
	base_gen.o \
	ctx.o \
	ctx_cmd.o \
	ctx_gen.o \
	ctx_grp.o \
	genl_fam.o \
	genl_grp.o \
	pack.o \
	pack_str.o \
	pack_sub.o 

all: $(OBJ)

clean:
	rm -f *.o
