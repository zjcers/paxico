
dnl Initialize autoconf and automake
AC_INIT(LibsimpleC, 0.1)
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

dnl Tell make to be quiet
AM_SILENT_RULES([yes])
AC_SUBST([MAKEFLAGS], [--no-print-directory])

dnl Check for build dependencies
AC_PROG_CC
AM_PROG_AR
AM_PROG_AS

dnl Initialize libtool
LT_PREREQ([2.4.0])
LT_INIT

dnl Detect platform
case $target in
	*linux*) PLATFORM_OS='-DPLATFORM_LINUX' ;;
	*) PLATFORM_OS='' ;;
esac
AC_SUBST([PLATFORM_OS])
case $target in
	*x86_64*) PLATFORM_CPU='-DPLATFORM_X86_64' ;;
	*) PLATFORM_CPU='' ;;
esac
AC_SUBST([PLATFORM_CPU])

dnl Tell autoconf about the makefiles we need to build
AC_CONFIG_FILES([
Makefile
src/Makefile
src/math/Makefile
src/stdio/Makefile
src/stdlib/Makefile
src/string/Makefile
src/getopt/Makefile
src/platform/Makefile
src/platform/x86_64-linux/Makefile
tests/Makefile
tests/math/Makefile
tests/start/Makefile
tests/stdio/Makefile
tests/stdlib/Makefile
tests/string/Makefile
])

dnl Process Makefile.in to create Makefile
AC_OUTPUT
