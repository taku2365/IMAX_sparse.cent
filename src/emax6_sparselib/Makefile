
## EMAX5/6 Application Simulator       ##
##   Copyright (C) 2021 by NAIST UNIV. ##
##         Primary writer: T.Sugahara##
##                sugahara.takuya.ss4@is.naist.jp ##

ARCHIVE = $(AR) $(ARFLAGS)
EMAX6_SPARSE_LIB = sparse_format.o
AR_TARGET = sparse_lib.a

all: static

%.o: /emax6_sparselib/%.c ../Include/emax6_sparselib.h
	$(CC) $(CFLAGS) -c ${INCLUDE} $<


$(AR_TARGET): $(EMAX6_SPARSE_LIB)
	$(ARCHIVE)  $@ $^


static: $(AR_TARGET)

clean:
	$(RM) *.o *.a

