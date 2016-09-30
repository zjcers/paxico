dnl Initialize autoconf and automake
AC_INIT(LibsimpleC, 0.1)
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

dnl Check for build dependencies
AC_PROG_CC
AM_PROG_AR
AM_PROG_AS
LT_PREREQ([2.4.6])
LT_INIT

dnl Tell autoconf about the makefiles we need to build
AC_CONFIG_FILES([
Makefile
test/Makefile
])

dnl Process Makefile.in to create Makefile
AC_OUTPUT
