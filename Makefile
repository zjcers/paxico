OBJECTS=$(addsuffix .o, $(basename $(wildcard *.c)))
.PHONY: all
all: libc.a
start.o: start.asm
	as start.asm -o start.o
%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $(basename $@).c
libc.a: $(OBJECTS) start.o
	ar rcs libc.a $^
test: libc.a
	$(MAKE) -C tests
