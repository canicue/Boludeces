make clean;
rm $(find -type f -name Makefile);
rm $(find -type f -name \*.in);
rm -rf $(find -type d -name .deps);
rm -rf $(find -type d -name .libs);
rm m4/*;
rm ltmain.sh;
rm aclocal.m4;
rm -rf autom4te.cache/;
rm compile*;
rm config.*;
rm configure;
rm depcomp*;
rm libtool*;
rm stamp-*;
rm missing*;
rm install-sh*;

