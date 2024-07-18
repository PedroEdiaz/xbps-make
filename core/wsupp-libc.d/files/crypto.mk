OBJ = \
	aes128.o \
	aes128_unwrap.o \
	aes128_wrap.o \
	pbkdf2_sha1.o \
	sha1.o \
	sha1_hash.o \
	sha1_hmac.o 

all: $(OBJ)

clean:
	rm -f *.o
