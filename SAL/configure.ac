AC_INIT([SAL Demo],[1.03],[diegobravo@x.com])
AM_INIT_AUTOMAKE([sal],[1.03])
AM_CONFIG_HEADER(config.h)
AC_PROG_CPP
AC_PROG_CC
AC_PROG_RANLIB
AC_PROG_MAKE_SET
AC_CHECK_HEADERS([mysql.h mysql/mysql.h])
AC_SEARCH_LIBS([mysql_real_connect],[mysqlclient],,
			   AC_MSG_ERROR([No se puede enlazar con libmysqlclient]))
AC_CONFIG_FILES([Makefile
				 src/Makefile
				 src/lib/Makefile
				 src/exe/Makefile])
AC_OUTPUT

