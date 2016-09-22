FILES=$(wildcard *.c)
TESTS=$(basename $(FILES))
OBJECTS=$(addsuffix .o, $(TESTS))
.PHONY: all
all: $(TESTS)
$(TESTS): $(OBJECTS)
	$(CC) -specs=../../proj.spec $@.o -nostdlib -lc -o $@
%.o: %.c
	$(CC) -specs=../../proj.spec -I../ -g -Wall -c $<
