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
EMAX6_SPARSE_TEST = $(wildcard ./test/test_*$(SUFFIX)) 
EMAX6_INCLUDE = $(wildcard ./Include/*.h) 
AR_TARGET = libsparse.a
SHARED_TARGET = libsparse.so
SHARED_FLAG = -shared -fPIC
ARCH = CENT
CENT = 1
ARM_CROSS = 0
ARM = 0
LINK_FORMAT = static
SHARED_LINK = 0

CPP     = cpp -P
CC      = gcc
CFLAGS  = -g3 -O0 -Wall  -msse3 -Wno-unknown-pragmas -funroll-loops -I/usr/local/include -I/usr/include/openblas -DCBLAS_GEMM -DEMAX6 -DDEBUG
LDFLAGS = -L/usr/lib64 -L/usr/local/lib -L/usr/lib64/atlas -lm -lrt -lopenblas -lX11 -lXext
DEVICE_DEBUG = 0

ifeq ($(ARM_CROSS),1)
CFLAGS  = -g3 -O0 -Wall  -msse3 -Wno-unknown-pragmas -funroll-loops -I/usr/local/include -I/usr/include/openblas -DCBLAS_GEMM -DEMAX6 -DCSIMDEBUG
CENT          = 0
OPTION	      = -mstrict-align -DDEBUG -DCYCLECNT -DARMSIML -DEMAX6 -DFPDDMA -DCSIMDEBUG
CPP           = aarch64-elf-cpp -P
CC            = aarch64-elf-gcc
CFLAGS        = -I. -O3 -Wno-attributes $(OPTION)
AS            = aarch64-elf-as
ASFLAGS       = 
LD            = aarch64-elf-ld
ARCHIVE = aarch64-elf-ar $(ARFLAGS)

endif


ifeq ($(ARM),1)
CENT          = 0
OPTION        = -mstrict-align  -DCYCLECNT -DARMZYNQ -DEMAX6 -DFPDDMA
CPP           = cpp -P 
CC            = gcc
ifeq ($(DEVICE_DEBUG),1)
CFLAGS        = -I. -O0 -g3 $(OPTION)
else
CFLAGS        = -I. -O2  $(OPTION)
endif

endif



ifeq ($(ARM),1)
test: binary $(EMAX6_SPARSE_TEST) $(EMAX6_INCLUDE)
	(cd ./test; $(MAKE) -f Makefile.arm LINK_FORMAT=$(LINK_FORMAT) CFLAGS="$(CFLAGS)")
endif

ifeq ($(CENT),1)
test: binary $(EMAX6_SPARSE_TEST) $(EMAX6_INCLUDE)
	(cd ./test; $(MAKE) -f Makefile.cent LINK_FORMAT=$(LINK_FORMAT) CFLAGS="$(CFLAGS)")
endif

#./../csim/csim -x test/test_chipB_div+dma
# xdisp系をcsimから消した
ifeq ($(ARM_CROSS),1)
test: binary $(EMAX6_SPARSE_TEST) $(EMAX6_INCLUDE)
	(cd ./test; $(MAKE) -f Makefile.csim LINK_FORMAT=$(LINK_FORMAT) CFLAGS="$(CFLAGS)")
endif


ifeq ($(LINK_FORMAT),shared)
binary: shared 
else
binary: static
endif


static: $(AR_TARGET)
shared: $(SHARED_TARGET)



ifeq ($(ARM),1)
$(AR_TARGET):  $(EMAX6_SPARSE_ARM_LIB)  $(EMAX6_INCLUDE)
	$(ARCHIVE)  $@ $(EMAX6_SPARSE_ARM_LIB)
	$(RM) kernel/*-*.c
endif
ifeq ($(CENT),1)
$(AR_TARGET): $(EMAX6_SPARSE_LIB) $(EMAX6_INCLUDE)
	$(ARCHIVE)  $@ $(EMAX6_SPARSE_LIB)
endif
ifeq ($(ARM_CROSS),1)
$(AR_TARGET):  $(EMAX6_SPARSE_ARM_LIB) $(EMAX6_INCLUDE)
	$(ARCHIVE)  $@ $(EMAX6_SPARSE_ARM_LIB)
	$(RM) kernel/*-*.c
endif



ifeq ($(ARM),1)
$(SHARED_TARGET): $(EMAX6_SPARSE_ARM_SRC)  $(EMAX6_INCLUDE)
	$(CC) $(SHARED_FLAG) $(CFLAGS) -o $@ $^
endif

ifeq ($(CENT),1)
$(SHARED_TARGET): $(EMAX6_SPARSE_SRC) $(EMAX6_INCLUDE)
	$(CC) $(SHARED_FLAG) $(CFLAGS) -o $@ $^
endif

ifeq ($(ARM_CROSS),1)
$(SHARED_TARGET): $(EMAX6_SPARSE_ARM_SRC)  $(EMAX6_INCLUDE)
	$(CC) $(SHARED_FLAG) $(CFLAGS) -o $@ $^
endif

/util/%.o: /util/%.c ./Include/emax6_sparselib.h 
	$(warning $(CC) $(CFLAGS) -c ${INCLUDE} $< -o $@)


ifeq ($(ARM),1)
ifeq ($(LINK_FORMAT),shared)
./kernel/%-emax6.c: ./kernel/%.c ./Include/emax6_sparselib.h 
	perl ./../conv-mark/conv-mark $< > $<-mark.c
	$(CPP) $(OPTION) $(INCLUDE)  $<-mark.c > $<-cppo.c
	./../conv-c2c/conv-c2c.arm $<-cppo.c
else
./kernel/%-emax6.o: ./kernel/%.c  ./Include/emax6_sparselib.h 
	perl ./../conv-mark/conv-mark $< > $<-mark.c
	$(CPP) $(OPTION) $(INCLUDE)  $<-mark.c > $<-cppo.c
	./..//conv-c2c/conv-c2c.arm $<-cppo.c
	$(CC) $(CFLAGS) -c ${INCLUDE} $(basename $<)-emax6.c -o $(basename $<)-emax6.o
endif
endif


ifeq ($(CENT),1) 
/kernel/%.o: /kernel/%.c ./Include/emax6_sparselib.h ./Include/sparse_gemm.h
	$(warning $(CC) $(CFLAGS) -c ${INCLUDE} $< -o $@)
endif


ifeq ($(ARM_CROSS),1)
ifeq ($(LINK_FORMAT),shared)
./kernel/%-emax6.c: ./kernel/%.c ./Include/emax6_sparselib.h 
	perl ./../conv-mark/conv-mark $< > $<-mark.c
	$(CPP) $(OPTION) $(INCLUDE)  $<-mark.c > $<-cppo.c
	./../conv-c2c/conv-c2c.csim $<-cppo.c
else
./kernel/%-emax6.o: ./kernel/%.c  ./Include/emax6_sparselib.h 
	perl ./../conv-mark/conv-mark $< > $<-mark.c
	$(CPP) $(OPTION) $(INCLUDE)  $<-mark.c > $<-cppo.c
	./..//conv-c2c/conv-c2c.csim $<-cppo.c
	$(CC) $(CFLAGS) -c ${INCLUDE} $(basename $<)-emax6.c -o $(basename $<)-emax6.o
endif
endif


clean:
	$(RM) *.o *.a *.so *-emax6.c util/*.o kernel/*.o kernel/*-*
	(cd ./test; $(MAKE) -f Makefile.cent clean)