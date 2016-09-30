check_PROGRAMS = start_noargs strcmp_eq
LDADD = -L$(top_srcdir)/libc/ -lc
AM_LDFLAGS = -e _start
AM_CFLAGS = -I$(top_srcdir)/libc/include -Wall -Werror -g -ffreestanding -nostdlib
TESTS = start_noargs strcmp_eq
all:
