dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([Minimo],[1.0],[canicue@gmail.com])
AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])

AC_PROG_CC
AC_CONFIG_MACRO_DIR([m4])
AC_CANONICAL_SYSTEM

dnl Initialize automake
AM_INIT_AUTOMAKE

dnl this allows us specify individual liking flags for each target
AM_PROG_CC_C_O

dnl Initialize Libtool
LT_INIT

dnl Check if Libtool is present
dnl Libtool is used for building share libraries
AC_PROG_LIBTOOL

AC_CONFIG_FILES(Makefile
                src/ejemplo/Makefile
                src/controlador/Makefile
                src/funciones/Makefile
                src/include/Makefile)
AC_OUTPUT
