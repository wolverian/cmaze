COPTS=-std=c99
LIB=array2
INCS=array2.h

SYSTEM!=uname

.if ${SYSTEM} != OpenBSD
OBJS+=../libcross/*.o
DPADD+=../libcross/libcross.a
.endif

.include <bsd.lib.mk>