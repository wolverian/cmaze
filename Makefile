.if ${SYSTEM} == OpenBSD
SUBDIR=libarray maze
.else
SUBDIR=libcross libarray maze
.endif

.include <bsd.subdir.mk>
