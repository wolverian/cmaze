.if ${SYSTEM} == OpenBSD
SUBDIR=libarray2 maze
.else
SUBDIR=libcross libarray2 maze
.endif

.include <bsd.subdir.mk>
