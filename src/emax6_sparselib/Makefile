
## EMAX5/6 Application Simulator       ##
##   Copyright (C) 2021 by NAIST UNIV. ##
##         Primary writer: T.Sugahara##
##                sugahara.takuya.ss4@is.naist.jp ##

ARCHIVE = $(AR) $(ARFLAGS)

SUFFIX   = .c
EMAX6_SPARSE_KERNEL_SRC = $(wildcard ./kernel/*$(SUFFIX)) 
EMAX6_SPARSE_KERNEL_ARM_SRC = $(patsubst %.c,%-emax6.c,$(EMAX6_SPARSE_KERNEL_SRC))
EMAX6_SPARSE_KERNEL_OBJ = $(EMAX6_SPARSE_KERNEL_SRC:$(SUFFIX)=.o)
EMAX6_SPARSE_KERNEL_ARM_OBJ = $(EMAX6_SPARSE_KERNEL_ARM_SRC:$(SUFFIX)=.o)

EMAX6_SPARSE_UTIL_SRC = $(wildcard ./util/*$(SUFFIX)) 
EMAX6_SPARSE_UTIL_ARM_SRC = $(EMAX6_SPARSE_UTIL_SRC)
EMAX6_SPARSE_UTIL_OBJ = $(EMAX6_SPARSE_UTIL_SRC:$(SUFFIX)=.o)
EMAX6_SPARSE_SRC = $(EMAX6_SPARSE_KERNEL_SRC) $(EMAX6_SPARSE_UTIL_SRC)
EMAX6_SPARSE_ARM_SRC = $(EMAX6_SPARSE_KERNEL_ARM_SRC) $(EMAX6_SPARSE_UTIL_ARM_SRC)
EMAX6_SPARSE_LIB = $(EMAX6_SPARSE_KERNEL_OBJ) $(EMAX6_SPARSE_UTIL_OBJ)
EMAX6_SPARSE_ARM_LIB = $(EMAX6_SPARSE_KERNEL_ARM_OBJ) $(EMAX6_SPARSE_UTIL_OBJ)
AR_TARGET = libsparse.a
SHARED_TARGET = libsparse.so
SHARED_FLAG = -shared -fPIC
ARM_CORSS = 0
ARM = 0
LINK_FORMAT = static
SHARED_LINK = 0

CPP     = cpp -P
CC      = gcc
CFLAGS  = -g3 -O0 -Wall  -msse3 -Wno-unknown-pragmas -funroll-loops -I/usr/local/include -I/usr/include/openblas -DCBLAS_GEMM -DEMAX6 -DDEBUG
LDFLAGS = -L/usr/lib64 -L/usr/local/lib -L/usr/lib64/atlas -lm -lrt -lopenblas -lX11 -lXext


ifeq ($(ARM_CORSS),1)
OPTION	      = -mstrict-align -DDEBUG -DCYCLECNT -DARMSIML -DEMAX6 -DFPDDMA
CFLAGS = -I. -O3 -Wno-attributes $(OPTION)
CPP           = ../../bin/aarch64-elf-cpp -P
CC            = ../../bin/aarch64-elf-gcc
ARCHIVE       = ../../bin/aarch64-elf-ar $(ARFLAGS)

endif

ifeq ($(ARM),1)
OPTION        = -mstrict-align  -DCYCLECNT -DARMZYNQ -DEMAX6 -DFPDDMA
CPP           = cpp -P 
CC            = gcc
CFLAGS        = -I. -O0 -g3 $(OPTION)

endif



ifeq ($(ARM),1)
test: binary
	(cd ./test; $(MAKE) -f Makefile.arm LINK_FORMAT=$(LINK_FORMAT) )
else
test: binary
	(cd ./test; $(MAKE) -f Makefile.cent LINK_FORMAT=$(LINK_FORMAT) )
endif


ifeq ($(LINK_FORMAT),shared)
binary: shared 
else
binary: static
endif


static: $(AR_TARGET)
shared: $(SHARED_TARGET)



ifeq ($(ARM),1)
$(AR_TARGET):  $(EMAX6_SPARSE_ARM_LIB) 
	$(ARCHIVE)  $@ $(EMAX6_SPARSE_ARM_LIB)
	#$(RM) kernel/*-*.c
else
$(AR_TARGET): $(EMAX6_SPARSE_LIB)
	$(ARCHIVE)  $@ $(EMAX6_SPARSE_LIB)
endif


ifeq ($(ARM),1)
$(SHARED_TARGET): $(EMAX6_SPARSE_ARM_SRC) 
	$(CC) $(SHARED_FLAG) $(CFLAGS) -o $@ $^
else
$(SHARED_TARGET): $(EMAX6_SPARSE_SRC)
	$(CC) $(SHARED_FLAG) $(CFLAGS) -o $@ $^
endif

/util/%.o: /util/%.c ./Include/emax6_sparselib.h 
	$(warning $(CC) $(CFLAGS) -c ${INCLUDE} $< -o $@)

ifeq ($(ARM),1)

ifeq ($(LINK_FORMAT),shared)
./kernel/%-emax6.c: ./kernel/%.c ./Include/emax6_sparselib.h 
	perl ./../conv-mark/conv-mark $< > $<-mark.c
	$(CPP) $(OPTION) $(INCLUDE)  $<-mark.c > $<-cppo.c
	./../conv-c2c/conv-c2c $<-cppo.c
else
./kernel/%-emax6.o: ./kernel/%.c  ./Include/emax6_sparselib.h 
	perl ./../conv-mark/conv-mark $< > $<-mark.c
	$(CPP) $(OPTION) $(INCLUDE)  $<-mark.c > $<-cppo.c
	./..//conv-c2c/conv-c2c $<-cppo.c
	$(CC) $(CFLAGS) -c ${INCLUDE} $(basename $<)-emax6.c -o $(basename $<)-emax6.o
endif
else 

/kernel/%.o: /kernel/%.c ./Include/emax6_sparselib.h ./Include/sparse_gemm.h
	$(warning $(CC) $(CFLAGS) -c ${INCLUDE} $< -o $@)
endif


clean:
	$(RM) *.o *.a *.so *-emax6.c util/*.o kernel/*.o kernel/*-*
	(cd ./test; $(MAKE) -f Makefile.cent clean)

