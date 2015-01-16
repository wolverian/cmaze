COPTS=-std=c99
PROG=maze
SRCS=main.c geom.c maze.c carve.c
OBJS+=../libarray/array.o
DPADD+=../libarray/libarray.a

.if ${SYSTEM} != OpenBSD
OBJS+=../libcross/*.o
DPADD+=../libcross/libcross.a
.endif

.include <bsd.prog.mk>
