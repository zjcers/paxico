noinst_LTLIBRARIES = libx86_64_linux.la
libx86_64_linux_la_SOURCES = syscalls.c
dist_libx86_64_linux_la = start.s
STARTFILES = crt1.o crti.o crtbegin.o crtend.o crtn.o
libx86_64_linux_la_DEPENDENCIES = $(STARTFILES)
$(STARTFILES): crt%.o: crt%.s
	$(AS) -c $< -o $@
	mkdir -p $(abs_top_builddir)/usr/lib/
	cp -v $@ $(abs_top_builddir)/usr/lib/
