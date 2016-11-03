noinst_LTLIBRARIES = libx86_64_linux.la
libx86_64_linux_la_SOURCES = syscalls.c
dist_libx86_64_linux_la = start.s
libx86_64_linux_la_DEPENDENCIES = start.o
start.o:
	$(AS) -c $(abs_top_srcdir)/src/platform/x86_64-linux/start.s -o start.o
	cp -v start.o $(abs_top_builddir)/
