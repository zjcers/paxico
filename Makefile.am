lib_LTLIBRARIES = libc.la
libc_la_SOURCES = libc.c math.c memory.c stdio.c stdlib.c string.c syscalls.c
libc_la_DEPENDENCIES = start.o
export AM_CFLAGS = -nostdinc -I$(abs_top_srcdir)/include -Wall -Werror -g -ffreestanding -nostdlib -fno-builtin -std=gnu99
SUBDIRS = tests
start.o: start.s
	$(AS) -c $(abs_top_srcdir)/start.s -o start.o
