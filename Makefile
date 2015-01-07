CFLAGS=-std=c99 -Wall -Wextra -g
SRCS=cmaze.c set.c
#OBJS=cmaze.o set.o
PROG=cmaze

#${PROG}: ${OBJS}
# ${CC} ${LDFLAGS} ${LDSTATIC} -o ${.TARGET} ${OBJS} ${LDADD}

.include <bsd.prog.mk>
