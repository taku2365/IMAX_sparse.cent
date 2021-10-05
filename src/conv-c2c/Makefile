
## EMAX6 Compiler                      ##
##         Copyright (C) 2012 by NAIST ##
##         Primary writer: Y.Nakashima ##
##                nakashim@is.naist.jp ##

PROGRAM	      = conv-c2c
IMAX_DEBUG    = 0
ifeq ($(MACHTYPE),aarch64)
CFLAGS        = -O2 -fsigned-char
LDFLAGS       =
else
CFLAGS        = -O2 -m32 -fsigned-char
LDFLAGS       = -m32
endif

ifeq ($(IMAX_DEBUG),1)
CFLAGS        = -g3 -O0 -m32 -fsigned-char
endif

LIBFLAGS      =

OBJS	      =  \
		y.tab.o \
		emax6.o \
		yacc_lex_util.o \
		main.o\

SRCS	      = main.c \
		y.tab.c \
		emax6.c

all:	      $(PROGRAM)

$(PROGRAM):     $(OBJS)
		@echo -n "Loading $(PROGRAM) ... "
		@cc $(OBJS) $(LDFLAGS) -o $(PROGRAM) $(LIBFLAGS)
		@echo "done"

.c.o:;		cc -c $(CFLAGS) $<

y.tab.c:	conv-c2c.y
		bison  -t -v -y -d conv-c2c.y

lex.yy.c:	conv-c2c.l
		flex  conv-c2c.l

clean:;		@rm -f $(OBJS) y.tab.c y.tab.h lex.yy.c core mon.out y.output Make.log *~

###

main.o:		yacc_lex_util.h
y.tab.o:	lex.yy.c yacc_lex_util.h
emax6.o:	conv-c2c.h emax6.h
yacc_lex_util.o: conv-c2c.h emax6.h
