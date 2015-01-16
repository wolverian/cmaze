COPTS=-std=c99
LIB=array
INCS=array.h
SRCS=array.c

.if ${SYSTEM} == OpenBSD
SUBDIR=test
.else
OBJS+=../libcross/*.o
DPADD+=../libcross/libcross.a
.endif

.include <bsd.lib.mk>
