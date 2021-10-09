
## EMAX5/6 Application Simulator       ##
##   Copyright (C) 2021 by NAIST UNIV. ##
##         Primary writer: T.Sugahara##
##                sugahara.takuya.ss4@is.naist.jp ##

ARCHIVE = $(AR) $(ARFLAGS)
EMAX6_SPARSE_LIB = sparse_format.o sparse_multiply.o
AR_TARGET = libsparse.a
ARM_CORSS_COMPILE = 0

ifeq ($(ARM_CORSS_COMPILE),1)
OPTION	      = -mstrict-align -DDEBUG -DCYCLECNT -DARMSIML -DEMAX6 -DFPDDMA
CFLAGS = -I. -O3 -Wno-attributes $(OPTION)
CPP           = ../../bin/aarch64-elf-cpp -P
CC            = ../../bin/aarch64-elf-gcc
ARCHIVE       = ../../bin/aarch64-elf-ar $(ARFLAGS)
endif



all: static

static: $(AR_TARGET)

$(AR_TARGET): $(EMAX6_SPARSE_LIB)
	$(ARCHIVE)  $@ $^


%.o: /emax6_sparselib/%.c ../Include/emax6_sparselib.h
	$(CC) $(CFLAGS) -c ${INCLUDE} $<



clean:
	$(RM) *.o *.a

