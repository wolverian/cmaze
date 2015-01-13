COPTS=-std=c99
LIB=array
INCS=array.h
SRCS=array.c
OBJS+=../libcross/*.o
DPADD+=../libcross/libcross.a

SYSTEM!=uname

.if ${SYSTEM} == OpenBSD
SUBDIR=test
.endif

.include <bsd.lib.mk>
