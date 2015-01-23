COPTS=-std=c99
PROG=maze
SRCS=main.c geom.c maze.c carve.c
DPADD+=../libarray2/libarray2.a

.if ${SYSTEM} != OpenBSD
OBJS+=../libcross/*.o
DPADD+=../libcross/libcross.a
.endif

.include <bsd.prog.mk>
