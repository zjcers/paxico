lib_LTLIBRARIES = libc.la
libc_la_SOURCES = libc.c math.c memory.c stdio.c stdlib.c string.c syscalls.c start.s
AM_CFLAGS = -I$(top_srcdir)/libc/include -Wall -Werror -g -ffreestanding -nostdlib
AUTOMAKE_OPTIONS = dejagnu
SUBDIRS = tests
