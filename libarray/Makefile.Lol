#global variables:
.CURDIR          = /home/iv/src/cmaze/libarray
.MAKE            = make
.MAKEFLAGS       =  -p 
.OBJDIR          = /home/iv/src/cmaze/libarray
.TARGETS         =  all
AFLAGS           = ${DEBUG}
AR               = ar
ARFLAGS          = rl
AS               = as
BEFOREMAN        = 
BINGRP           = bin
BINMODE          = 555
BINOWN           = root
BINUTILS217_ARCH = hppa64 ia64
BINUTILS_VERSION = binutils
BSDOBJDIR        = /usr/obj
BSDSRCDIR        = /usr/src
BSD_OWN_MK       = Done
CC               = cc
CDIAGFLAGS       = -Wall -Wpointer-arith -Wuninitialized -Wstrict-prototypes -Wmissing-prototypes -Wunused -Wsign-compare -Wshadow -Wdeclaration-after-statement
CFLAGS           = -O2 ${PIPE} ${DEBUG} ${COPTS}
CLEANFILES       = .man-linted ${MANLINT}
COMPILE.F        = ${FC} ${FFLAGS} ${CPPFLAGS} -c
COMPILE.S        = ${CC} ${AFLAGS} ${CPPFLAGS} -c
COMPILE.c        = ${CC} ${CFLAGS} ${CPPFLAGS} -c
COMPILE.cc       = ${CXX} ${CXXFLAGS} ${CPPFLAGS} -c
COMPILE.f        = ${FC} ${FFLAGS} -c
COMPILE.p        = ${PC} ${PFLAGS} ${CPPFLAGS} -c
COMPILE.r        = ${FC} ${FFLAGS} ${RFLAGS} -c
COMPILE.s        = ${CC} ${AFLAGS} -c
COMPILER_VERSION = gcc4
COPTS            = -std=c99
CPP              = cpp
CPPFLAGS         = 
CTAGS            = /usr/bin/ctags
CXX              = c++
CXXFLAGS         = ${CFLAGS} ${CXXOPTS}
DEBUG            = -g
DEBUGLIBS        = no
DEFAULT_PIE_DEF  = -DPIE_DEFAULT=1
DIRMODE          = 755
DIST_CFLAGS      = -Os
DIST_LIB         = lib${LIB}_d.a
DOBJS            = ${OBJS:.o=.do}
DOCDIR           = /usr/share/doc
DOCGRP           = bin
DOCMODE          = ${NONBINMODE}
DOCOWN           = root
FC               = f77
FFLAGS           = -O2
GCC3_ARCH        = m88k vax
GNUSYSTEM_AUX_DIR = ${BSDSRCDIR}/share/gnu
GOBJS            = ${OBJS:.o=.go}
HOSTCC           = cc
INCS             = array.h
INSTALL          = install
INSTALL_COPY     = -c
INSTALL_STRIP    = -s
LD               = ld
LDFLAGS          = ${DEBUG}
LEX              = lex
LEX.l            = ${LEX} ${LFLAGS}
LFLAGS           = 
LIB              = array
LIBDIR           = /usr/lib
LIBGRP           = ${BINGRP}
LIBMODE          = ${NONBINMODE}
LIBOWN           = ${BINOWN}
LINK.F           = ${FC} ${FFLAGS} ${CPPFLAGS} ${LDFLAGS}
LINK.S           = ${CC} ${AFLAGS} ${CPPFLAGS} ${LDFLAGS}
LINK.c           = ${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}
LINK.cc          = ${CXX} ${CXXFLAGS} ${CPPFLAGS} ${LDFLAGS}
LINK.f           = ${FC} ${FFLAGS} ${LDFLAGS}
LINK.p           = ${PC} ${PFLAGS} ${CPPFLAGS} ${LDFLAGS}
LINK.r           = ${FC} ${FFLAGS} ${RFLAGS} ${LDFLAGS}
LINK.s           = ${CC} ${AFLAGS} ${LDFLAGS}
LKMDIR           = /usr/lkm
LKMGRP           = ${BINGRP}
LKMMODE          = ${NONBINMODE}
LKMOWN           = ${BINOWN}
LOCALEDIR        = /usr/share/locale
LOCALEGRP        = wheel
LOCALEMODE       = ${NONBINMODE}
LOCALEOWN        = root
LORDER           = lorder
MACHINE          = amd64
MACHINE_ARCH     = amd64
MACHINE_CPU      = amd64
MAKE             = make
MAKEFILE         = Makefile
MANDIR           = /usr/share/man/man
MANGRP           = bin
MANLINT          = ${MAN:S/$/.manlint/}
MANMODE          = ${NONBINMODE}
MANOWN           = root
MANSUBDIR        = /
MFLAGS           =   -p 
NLSDIR           = /usr/share/nls
NLSGRP           = bin
NLSMODE          = ${NONBINMODE}
NLSNAME          = lib${LIB}
NLSOWN           = root
NONBINMODE       = 444
NOPIE_FLAGS      = -fno-pie
NOPIE_LDFLAGS    = -nopie
OBJS             = ${SRCS:N*.h:R:S/$/.o/}
OSMAJOR          = 5
OSMINOR          = 6
OSREV            = $(OSMAJOR).$(OSMINOR)
OSrev            = $(OSMAJOR)$(OSMINOR)
PC               = pc
PFLAGS           = 
PICFLAG          = -fpic
PIE_ARCH         = alpha amd64 hppa i386 mips64 mips64el powerpc sh sparc64
PIE_DEFAULT      = ${DEFAULT_PIE_DEF}
PIPE             = -pipe
POBJS            = ${OBJS:.o=.po}
RANLIB           = ranlib
RFLAGS           = 
SELECTED_DOBJS   = ${DOBJS}
SHAREDIR         = /usr/share
SHAREGRP         = bin
SHAREMODE        = ${NONBINMODE}
SHAREOWN         = root
SHELL            = /bin/sh
SKEY             = yes
SKIPDIR          = 
SOBJS            = ${OBJS:.o=.so}
SRCS             = array.c
STATIC           = -static
SUBDIR           = test
VISIBILITY_HIDDEN = -fvisibility=hidden
WARNINGS         = no
YACC             = yacc
YACC.y           = ${YACC} ${YFLAGS}
YFLAGS           = -d
YP               = yes
_LIBS            = lib${LIB}.a lib${LIB}_p.a
_MAN_SUFFIXES    = 1 2 3 3p 4 5 6 7 8 9
__objdir         = obj
unix             = We run OpenBSD.

#variable name seen, but not defined: DESTDIR DIST_OBJS DPADD EXTRA_SYS_MK_INCLUDES LINKS MAKECONF MAKEOBJDIR MAN MLINKS NLS NLSALL NOMAN NONLS NOOBJ NOPIC NOPIE NOPROFILE PARALLEL PROG SHLIB_MAJOR SHLIB_MINOR VPATH _LEXINTM _YACCINTM _arch page s t


# Suffixes graph
# .1     ->.1.manlint 
# .1.manlint  <-.1 
# .2     ->.2.manlint 
# .2.manlint  <-.2 
# .3     ->.3.manlint 
# .3.manlint  <-.3 
# .3p    ->.3p.manlint 
# .3p.manlint  <-.3p 
# .4     ->.4.manlint 
# .4.manlint  <-.4 
# .5     ->.5.manlint 
# .5.manlint  <-.5 
# .6     ->.6.manlint 
# .6.manlint  <-.6 
# .7     ->.7.manlint 
# .7.manlint  <-.7 
# .8     ->.8.manlint 
# .8.manlint  <-.8 
# .9     ->.9.manlint 
# .9.manlint  <-.9 
# .C     -><empty> .o .go .po .so 
# .F    
# .S     -><empty> .o .go .po .so .do 
# .a    
# .c     -><empty> .o .go .po .so .do  <-.y .l 
# .cat   <-.msg 
# .cc    -><empty> .o .go .po .so 
# .cl   
# .cpp   ->.o .go .po .so 
# .cxx   -><empty> .o .go .po .so 
# .do    <-.S .s .c 
# .f     -><empty> .o .go .po .so 
# .go    <-.S .s .c .cc .cpp .C .cxx .f 
# .h    
# .l     -><empty> .o .c 
# .m    
# .m4   
# .msg   ->.cat 
# .o     <-.S .s .c .cc .cpp .C .cxx .f .y .l 
# .out  
# .p    
# .po    <-.S .s .c .cc .cpp .C .cxx .f 
# .r    
# .s     -><empty> .o .go .po .so .do 
# .sh   
# .so    <-.S .s .c .cc .cpp .C .cxx .f 
# .y     -><empty> .o .c 

.PATH: 

.SUFFIXES: .msg .cat .9.manlint .9 .8.manlint .8 .7.manlint .7 .6.manlint .6 .5.manlint .5 .4.manlint .4 .3p.manlint .3p .3.manlint .3 .2.manlint .2 .1.manlint .sh .1 .m .h .p .m4 .l .cl .y .f .cxx .C .r .cpp .cc .F .c .s .S .do .so .po .go .a .o .out

.1.1.manlint    : 
	mandoc -Tlint -Wfatal ${.IMPSRC}
	@touch ${.TARGET}

.2.2.manlint    : 
	mandoc -Tlint -Wfatal ${.IMPSRC}
	@touch ${.TARGET}

.3.3.manlint    : 
	mandoc -Tlint -Wfatal ${.IMPSRC}
	@touch ${.TARGET}

.3p.3p.manlint  : 
	mandoc -Tlint -Wfatal ${.IMPSRC}
	@touch ${.TARGET}

.4.4.manlint    : 
	mandoc -Tlint -Wfatal ${.IMPSRC}
	@touch ${.TARGET}

.5.5.manlint    : 
	mandoc -Tlint -Wfatal ${.IMPSRC}
	@touch ${.TARGET}

.6.6.manlint    : 
	mandoc -Tlint -Wfatal ${.IMPSRC}
	@touch ${.TARGET}

.7.7.manlint    : 
	mandoc -Tlint -Wfatal ${.IMPSRC}
	@touch ${.TARGET}

.8.8.manlint    : 
	mandoc -Tlint -Wfatal ${.IMPSRC}
	@touch ${.TARGET}

.9.9.manlint    : 
	mandoc -Tlint -Wfatal ${.IMPSRC}
	@touch ${.TARGET}

.C              : 
	${LINK.cc} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}

.C.a            : 
	${COMPILE.cc} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.C.go           : 
	@echo "${COMPILE.cc} -g ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} -g ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.C.o            : 
	@echo "${COMPILE.cc} ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.C.po           : 
	@echo "${COMPILE.cc} -p ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} -p ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.C.so           : 
	@echo "${COMPILE.cc} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.F              : 
	${LINK.F} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}

.F.a            : 
	${COMPILE.F} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.F.o            : 
	${COMPILE.F} ${.IMPSRC}

.S              : 
	${LINK.S} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}

.S.a            : 
	${COMPILE.S} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.S.do           : 
	@echo "${COMPILE.S} ${CFLAGS:M-[ID]*} ${AINC} ${DIST_CFLAGS}  ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.S} ${CFLAGS:M-[ID]*} ${AINC} ${DIST_CFLAGS} ${.IMPSRC}  -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.S.go           : 
	@echo "${COMPILE.S} ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.S} ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.S.o            : 
	@echo "${COMPILE.S} ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.S} ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.S.po           : 
	@echo "${COMPILE.S} -DPROF ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC}  -o ${.TARGET}"
	@${COMPILE.S} -DPROF ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC}  -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.S.so           : 
	@echo "${COMPILE.S} ${PICFLAG} ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC}  -o ${.TARGET}"
	@${COMPILE.S} ${PICFLAG} ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC}  -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.c              : 
	${LINK.c} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}

.c.a            : 
	${COMPILE.c} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.c.do           : 
	@echo "${COMPILE.c} ${DIST_CFLAGS} ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.c} ${DIST_CFLAGS} ${.IMPSRC}  -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.c.go           : 
	@echo "${COMPILE.c} -g ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.c} -g ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.c.o            : 
	@echo "${COMPILE.c} ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.c} ${.IMPSRC}  -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.c.po           : 
	@echo "${COMPILE.c} -p ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.c} -p ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.c.so           : 
	@echo "${COMPILE.c} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.c} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cc             : 
	${LINK.cc} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}

.cc.a           : 
	${COMPILE.cc} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.cc.go          : 
	@echo "${COMPILE.cc} -g ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} -g ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cc.o           : 
	@echo "${COMPILE.cc} ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cc.po          : 
	@echo "${COMPILE.cc} -p ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} -p ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cc.so          : 
	@echo "${COMPILE.cc} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cpp.go         : 
	@echo "${COMPILE.cc} -g ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} -g ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cpp.o          : 
	@echo "${COMPILE.cc} ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cpp.po         : 
	@echo "${COMPILE.cc} -p ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} -p ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cpp.so         : 
	@echo "${COMPILE.cc} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cxx            : 
	${LINK.cc} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}

.cxx.a          : 
	${COMPILE.cc} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.cxx.go         : 
	@echo "${COMPILE.cc} -g ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} -g ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cxx.o          : 
	@echo "${COMPILE.cc} ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cxx.po         : 
	@echo "${COMPILE.cc} -p ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} -p ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cxx.so         : 
	@echo "${COMPILE.cc} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.f              : 
	${LINK.f} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}

.f.a            : 
	${COMPILE.f} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.f.go           : 
	@echo "${COMPILE.f} -g ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.f} -g ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.f.o            : 
	@echo "${COMPILE.f} ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.f} ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.f.po           : 
	@echo "${COMPILE.f} -p ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.f} -p ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.f.so           : 
	@echo "${COMPILE.f} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.f} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.l              : 
	${LEX.l} ${.IMPSRC}
	${LINK.c} -o ${.TARGET} lex.yy.c ${LDLIBS} -ll
	rm -f lex.yy.c

.l.c            : 
	${LEX.l} ${.IMPSRC}
	mv lex.yy.c ${.TARGET}

.l.o            : 
	${LEX.l} ${.IMPSRC}
	${COMPILE.c} -o ${.TARGET} lex.yy.c 
	rm -f lex.yy.c

.msg.cat        : 
	@rm -f ${.TARGET}
	gencat ${.TARGET} ${.IMPSRC}

.p              : 
	${LINK.p} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}

.p.a            : 
	${COMPILE.p} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.p.o            : 
	${COMPILE.p} ${.IMPSRC}

.r              : 
	${LINK.r} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}

.r.a            : 
	${COMPILE.r} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.r.o            : 
	${COMPILE.r} ${.IMPSRC}

.s              : 
	${LINK.s} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}

.s.a            : 
	${COMPILE.s} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.s.do           : 
	@echo "${COMPILE.S} ${CFLAGS:M-[ID]*} ${AINC} ${DIST_CFLAGS}  ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.S} ${CFLAGS:M-[ID]*} ${AINC} ${DIST_CFLAGS} ${.IMPSRC}  -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.s.go           : 
	@echo "${COMPILE.S} ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.S} ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.s.o            : 
	@echo "${COMPILE.S} ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.S} ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.s.po           : 
	@echo "${COMPILE.S} -DPROF ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC}  -o ${.TARGET}"
	@${COMPILE.S} -DPROF ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC}  -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.s.so           : 
	@echo "${COMPILE.S} ${PICFLAG} ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC}  -o ${.TARGET}"
	@${COMPILE.S} ${PICFLAG} ${CFLAGS:M-[ID]*} ${AINC} ${.IMPSRC}  -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.sh             : 
	rm -f ${.TARGET}
	cp ${.IMPSRC} ${.TARGET}

.y              : 
	${YACC.y} ${.IMPSRC}
	${LINK.c} -o ${.TARGET} y.tab.c ${LDLIBS}
	rm -f y.tab.c

.y.c            : 
	${YACC.y} ${.IMPSRC}
	mv y.tab.c ${.TARGET}

.y.o            : 
	${YACC.y} ${.IMPSRC}
	${COMPILE.c} -o ${.TARGET} y.tab.c
	rm -f y.tab.c

.SUFFIXES: .msg .cat .9.manlint .9 .8.manlint .8 .7.manlint .7 .6.manlint .6 .5.manlint .5 .4.manlint .4 .3p.manlint .3p .3.manlint .3 .2.manlint .2 .1.manlint .1 .m .m4 .l .y .f .cxx .C .cpp .cc .c .s .S .do .so .po .go .o .out
#   Input graph:
# parent targets: afterdepend depend 
.depend         : array.c 
	@rm -f .depend
	@files="${.ALLSRC:M*.s} ${.ALLSRC:M*.S}";  if [ "$$files" != " " ]; then  echo mkdep -a ${MKDEP} ${CFLAGS:M-[ID]*} ${CPPFLAGS} ${AINC} $$files; mkdep -a ${MKDEP} ${CFLAGS:M-[ID]*} ${CPPFLAGS} ${AINC} $$files;  fi
	@files="${.ALLSRC:M*.c}";  if [ "$$files" != "" ]; then  echo mkdep -a ${MKDEP} ${CFLAGS:M-[ID]*} ${CPPFLAGS} $$files;  mkdep -a ${MKDEP} ${CFLAGS:M-[ID]*} ${CPPFLAGS} $$files;  fi
	@files="${.ALLSRC:M*.cc} ${.ALLSRC:M*.C} ${.ALLSRC:M*.cxx}";  if [ "$$files" != "  " ]; then  echo mkdep -a ${MKDEP} ${CXXFLAGS:M-[ID]*} ${CPPFLAGS} $$files;  mkdep -a ${MKDEP} ${CXXFLAGS:M-[ID]*} ${CPPFLAGS} $$files;  fi


# parent targets: all clean cleandir install obj realdepend tags includes regress 
_SUBDIRUSE      : .USE 
	@for entry in ${SUBDIR}; do  (set -e; if test -d ${.CURDIR}/$${entry}.${MACHINE}; then  _newdir_="$${entry}.${MACHINE}";  else  _newdir_="$${entry}";  fi;  if test X"${_THISDIR_}" = X""; then  _nextdir_="$${_newdir_}";  else  _nextdir_="$${_THISDIR_}/$${_newdir_}";  fi;  _makefile_spec_="";  if [ -e ${.CURDIR}/$${_newdir_}/Makefile.bsd-wrapper ]; then  _makefile_spec_="-f Makefile.bsd-wrapper";  fi;  subskipdir='';  for skipdir in ${SKIPDIR}; do  subentry=$${skipdir#$${entry}};  if [ X$${subentry} != X$${skipdir} ]; then  if [ X$${subentry} = X ]; then  echo "($${_nextdir_} skipped)";  break;  fi;  subskipdir="$${subskipdir} $${subentry#/}";  fi;  done;  if [ X$${skipdir} = X -o X$${subentry} != X ]; then  echo "===> $${_nextdir_}";  cd ${.CURDIR}/$${_newdir_};  exec ${MAKE} SKIPDIR="$${subskipdir}"  $${_makefile_spec_} _THISDIR_="$${_nextdir_}"  ${MAKE_FLAGS}  ${.TARGET:S/^real//};  fi);  done


# parent targets: depend 
afterdepend     : .depend 
	@(TMP=`mktemp -q /tmp/_dependXXXXXXXXXX`;  if [ $$? -ne 0 ]; then  echo "$$0: cannot create temp file, exiting...";  exit 1;  fi;  sed -e 's/^\([^\.]*\).o[ ]*:/\1.o \1.go \1.po \1.so \1.do:/'  < .depend > $$TMP;  mv $$TMP .depend)


# parent targets: maninstall 
afterinstall    : realinstall 


all             : libarray.a libarray_p.a _SUBDIRUSE 


# parent targets: depend 
beforedepend    : 


# parent targets: realinstall 
beforeinstall   : 


# parent targets: cleandir 
clean           : _SUBDIRUSE 
	rm -f a.out [Ee]rrs mklog *.core ${CLEANFILES}
	rm -f lib${LIB}.a ${OBJS}
	rm -f lib${LIB}_g.a ${GOBJS}
	rm -f lib${LIB}_p.a ${POBJS}
	rm -f lib${LIB}.so.*.* ${SOBJS}
	rm -f ${DIST_LIB} ${DOBJS}


# parent targets: cleandir 
cleandepend     : 
	rm -f .depend ${.CURDIR}/tags


cleandir        : _SUBDIRUSE clean cleandepend 


depend          : beforedepend .depend realdepend afterdepend 


includes        : _SUBDIRUSE 


install         : maninstall _SUBDIRUSE 


# parent targets: all 
libarray.a      : array.o 
	@echo building standard ${LIB} library
	@rm -f lib${LIB}.a
	@${AR} cq lib${LIB}.a `${LORDER} ${OBJS} | tsort -q`
	${RANLIB} lib${LIB}.a


libarray.so..   : array.so 
	@echo building shared ${LIB} library \(version ${SHLIB_MAJOR}.${SHLIB_MINOR}\)
	@rm -f lib${LIB}.so.${SHLIB_MAJOR}.${SHLIB_MINOR}
	${CC} -shared ${PICFLAG}  -o lib${LIB}.so.${SHLIB_MAJOR}.${SHLIB_MINOR}  `${LORDER} ${SOBJS}|tsort -q` ${LDADD}


libarray_d.a    : array.do 
	@echo building distrib ${DIST_LIB} library from ${SELECTED_DOBJS}
	@rm -f ${DIST_LIB}
	@${AR} cq ${DIST_LIB} `${LORDER} ${SELECTED_DOBJS} | tsort -q`
	${RANLIB} ${DIST_LIB}


libarray_g.a    : array.go 
	@echo building debugging ${LIB} library
	@rm -f lib${LIB}_g.a
	@${AR} cq lib${LIB}_g.a `${LORDER} ${GOBJS} | tsort -q`
	${RANLIB} lib${LIB}_g.a


# parent targets: all 
libarray_p.a    : array.po 
	@echo building profiled ${LIB} library
	@rm -f lib${LIB}_p.a
	@${AR} cq lib${LIB}_p.a `${LORDER} ${POBJS} | tsort -q`
	${RANLIB} lib${LIB}_p.a


# parent targets: install 
maninstall      : afterinstall 


nlsinstall      : 


obj             ! _SUBDIRUSE 
	@cd ${.CURDIR};  here=`/bin/pwd`; bsdsrcdir=`cd ${BSDSRCDIR}; /bin/pwd`;  subdir=$${here#$${bsdsrcdir}/};  if test $$here != $$subdir ; then  dest=${BSDOBJDIR}/$$subdir ;  echo "$$here/${__objdir} -> $$dest";  if test ! -L ${__objdir} -o  X`readlink ${__objdir}` != X$$dest;  then  if test -e ${__objdir}; then rm -rf ${__objdir}; fi;  ln -sf $$dest ${__objdir};  fi;  if test -d ${BSDOBJDIR}; then  test -d $$dest || mkdir -p $$dest;  else  if test -e ${BSDOBJDIR}; then  echo "${BSDOBJDIR} is not a directory";  else  echo "${BSDOBJDIR} does not exist";  fi;  fi;  else  true ;  dest=$$here/${__objdir} ;  if test ! -d ${__objdir} ; then  echo "making $$dest" ;  mkdir $$dest;  fi ;  fi;


# parent targets: depend 
realdepend      : _SUBDIRUSE 


# parent targets: afterinstall 
realinstall     : beforeinstall 
	${INSTALL} ${INSTALL_COPY} -S -o ${LIBOWN} -g ${LIBGRP} -m 600 lib${LIB}.a  ${DESTDIR}${LIBDIR}/lib${LIB}.a
	${RANLIB} -t ${DESTDIR}${LIBDIR}/lib${LIB}.a
	chmod ${LIBMODE} ${DESTDIR}${LIBDIR}/lib${LIB}.a
	${INSTALL} ${INSTALL_COPY} -S -o ${LIBOWN} -g ${LIBGRP} -m 600  lib${LIB}_p.a ${DESTDIR}${LIBDIR}
	${RANLIB} -t ${DESTDIR}${LIBDIR}/lib${LIB}_p.a
	chmod ${LIBMODE} ${DESTDIR}${LIBDIR}/lib${LIB}_p.a


regress         : _SUBDIRUSE 


tags            : array.c _SUBDIRUSE 
	-cd ${.CURDIR}; ${CTAGS} -f /dev/stdout -d -t ${.ALLSRC:N*.h} |  sed "s;\${.CURDIR}/;;" > tags


test            :: 
	@set -e; if test -d ${.CURDIR}/${.TARGET}.${MACHINE}; then  _newdir_=${.TARGET}.${MACHINE};  else  _newdir_=${.TARGET};  fi;  _makefile_spec_="";  if [ -f ${.CURDIR}/$${_newdir_}/Makefile.bsd-wrapper ]; then  _makefile_spec_="-f Makefile.bsd-wrapper";  fi;  echo "===> $${_newdir_}";  cd ${.CURDIR}/$${_newdir_};  exec ${MAKE} ${MAKE_FLAGS} $${_makefile_spec_} _THISDIR_="$${_newdir_}" all




.PHONY: afterdepend afterinstall all beforedepend beforeinstall clean cleandepend cleandir cleanman cleannls depend includes install maninstall manpages nlsinstall obj print realdepend realinstall spell subdirdepend

#   Other target names:
#	array.c
#	array.do
#	array.go
#	array.o
#	array.po
#	array.so
#	cleanman
#	cleannls
#	manpages
#	print
#	spell
#	subdirdepend

