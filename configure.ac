

#AC_PREREQ(2.60)

AC_INIT(SocketApp, 1.0, shahharsh1195@gmail.com)
AC_CONFIG_SRCDIR([server.c])
AC_CONFIG_SRCDIR([client.c])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE(SocketApp, main)

# Checks for program

AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET

# Checks for libraries

AM_PROG_LIBTOOL

# Set shared libraries

AC_DISABLE_STATIC
AC_ENABLE_SHARED

# AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
