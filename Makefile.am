export AM_CFLAGS += -Wall -Werror -g -ffreestanding -fno-builtin -std=gnu99 -D$(PLATFORM_CPU) -D$(PLATFORM_OS) -I$(abs_top_srcdir)/include
export MAKEFLAGS = @MAKEFLAGS@
SUBDIRS = tests src include
all-local:
	mkdir -p $(abs_top_builddir)/usr/lib
	cp -v $(abs_top_builddir)/src/.libs/libc.a $(abs_top_builddir)/usr/lib
clean-local:
	rm -r $(abs_top_builddir)/usr
