## EMAX5/6 Application Simulator       ##
##   Copyright (C) 2021 by NAIST UNIV. ##
##         Primary writer: T.Sugahara##
##                sugahara.takuya.ss4@is.naist.jp ##

ARCHIVE = $(AR) $(ARFLAGS)

SUFFIX   = .c
SUFFIX1   = .cu
EMAX6_SPARSE_KERNEL_SRC = $(wildcard ./kernel/*$(SUFFIX)) 
EMAX6_SPARSE_KERNEL_ARM_SRC = $(patsubst %.c,%-emax6.c,$(EMAX6_SPARSE_KERNEL_SRC))
EMAX6_SPARSE_KERNEL_OBJ = $(EMAX6_SPARSE_KERNEL_SRC:$(SUFFIX)=.o)
EMAX6_SPARSE_KERNEL_ARM_OBJ = $(EMAX6_SPARSE_KERNEL_ARM_SRC:$(SUFFIX)=.o)

EMAX6_SPARSE_UTIL_SRC = $(wildcard ./util/*$(SUFFIX)) 
EMAX6_SPARSE_UTIL_ARM_SRC = $(EMAX6_SPARSE_UTIL_SRC)
EMAX6_SPARSE_UTIL_OBJ = $(EMAX6_SPARSE_UTIL_SRC:$(SUFFIX)=.o)

MAT_FORMAT_SRC = $(wildcard ./3rd/Matrix_Format_Io/*.c) 
MAT_FORMAT_INCLUDE = $(wildcard ./3rd/Matrix_Format_Io/*.h) 
MAT_FORMAT_OBJ = $(MAT_FORMAT_SRC:.c=.o)


3RD_SRC = $(MAT_FORMAT_SRC)
3RD_OBJ = $(MAT_FORMAT_OBJ)


EMAX6_SPARSE_LIB = $(addprefix ./build_cent/kernel/,$(notdir $(EMAX6_SPARSE_KERNEL_OBJ)))  $(addprefix ./build_cent/util/,$(notdir $(EMAX6_SPARSE_UTIL_OBJ)))\
				   $(addprefix ./build_cent/3rd/Matrix_Format_Io/,$(notdir $(3RD_OBJ)))
EMAX6_SPARSE_ARM_LIB =  $(addprefix ./build_arm/kernel/,$(notdir $(EMAX6_SPARSE_KERNEL_ARM_OBJ)))  $(addprefix ./build_arm/util/,$(notdir $(EMAX6_SPARSE_UTIL_OBJ)))\
					    $(addprefix ./build_arm/3rd/Matrix_Format_Io/,$(notdir $(3RD_OBJ)))
EMAX6_SPARSE_ARM_CROSS_LIB =  $(addprefix ./build_arm_cross/kernel/,$(notdir $(EMAX6_SPARSE_KERNEL_ARM_OBJ)))  $(addprefix ./build_arm_cross/util/,$(notdir $(EMAX6_SPARSE_UTIL_OBJ)))\
					  		  $(addprefix ./build_arm_cross/3rd/Matrix_Format_Io/,$(notdir $(3RD_OBJ)))

EMAX6_SPARSE_TEST = $(wildcard ./test/test_*$(SUFFIX))  
GPU_TEST = $(wildcard ./test/test_cu*$(SUFFIX1))
EMAX6_INCLUDE = $(wildcard ./Include/*.h) 
SHARED_TARGET = libsparse.so
SHARED_FLAG = -shared -fPIC
ifeq ($(MACHTYPE),x86_64)
ARCH = CENT
CENT = 1
endif
ARM_CROSS = 0
ARM = 0
ifeq ($(MACHTYPE),aarch64)
ARM = 1
CENT = 0
endif
LINK_FORMAT = static
SHARED_LINK = 0

CPP     = cpp -P
CC      = gcc
CFLAGS  = -g3 -O0 -Wall  -msse3 -Wno-unknown-pragmas -funroll-loops -I/usr/local/include -I/usr/include/openblas -DCBLAS_GEMM -DEMAX6 -DDEBUG
LDFLAGS = -L/usr/lib64 -L/usr/local/lib -L/usr/lib64/atlas -lm -lrt -lopenblas -lX11 -lXext
DEVICE_DEBUG = 0


ifeq ($(GPU),1)
CENT = 0 
endif

AR_TARGET = ./build_cent/libsparse.a

ifeq ($(ARM_CROSS),1)
AR_TARGET = ./build_arm_cross/libsparse.a
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
AR_TARGET = ./build_arm/libsparse.a
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

.PHONY : test




ifeq ($(ARM),1)
test: binary test1 $(EMAX6_INCLUDE)

test1: $(EMAX6_SPARSE_TEST)
	(cd ./test; $(MAKE) -f Makefile.arm LINK_FORMAT=$(LINK_FORMAT) CFLAGS="$(CFLAGS)")
endif

ifeq ($(CENT),1)
test: binary test1  $(EMAX6_INCLUDE)

test1: $(EMAX6_SPARSE_TEST)
	(cd ./test; $(MAKE) -f Makefile.cent LINK_FORMAT=$(LINK_FORMAT) CFLAGS="$(CFLAGS)")
endif


######################## test #######################################################

#./../csim/csim -x test/test_chipB_div+dma
# xdisp系をcsimから消した
ifeq ($(ARM_CROSS),1)
test: binary test1 $(EMAX6_INCLUDE)

test1: $(EMAX6_SPARSE_TEST)
	(cd ./test; $(MAKE) -f Makefile.csim LINK_FORMAT=$(LINK_FORMAT) CFLAGS="$(CFLAGS)")
endif

ifeq ($(GPU),1)
test: 
	(cd ./test; $(MAKE) -f Makefile.gpu)
endif
########################################################################################


ifeq ($(LINK_FORMAT),shared)
binary: shared 
else
binary: static
endif


static: $(AR_TARGET)
shared: $(SHARED_TARGET)


############################## archive #################################################
ifeq ($(ARM),1)
$(AR_TARGET):  $(EMAX6_SPARSE_ARM_LIB) $(EMAX6_INCLUDE)
	$(ARCHIVE)  $@ $(EMAX6_SPARSE_ARM_LIB)
	$(RM) ./kernel/*-*.c
endif
ifeq ($(CENT),1)
$(AR_TARGET): $(EMAX6_SPARSE_LIB) $(EMAX6_INCLUDE)
	$(ARCHIVE)  $@ $(EMAX6_SPARSE_LIB)
endif
ifeq ($(ARM_CROSS),1)
$(AR_TARGET):  $(EMAX6_SPARSE_ARM_CROSS_LIB) $(EMAX6_INCLUDE)
	$(ARCHIVE)  $@ $(EMAX6_SPARSE_ARM_CROSS_LIB)
	$(RM) ./kernel/*-*.c
endif
#######################################################################################


########################  3rd party  ##################################################
ifeq ($(ARM),1)
./build_arm/3rd/Matrix_Format_Io/%.o: ./3rd/Matrix_Format_Io/%.c $(MAT_FORMAT_INCLUDE) 
	$(CC) $(CFLAGS) -c  $< -o $@
endif

ifeq ($(CENT),1)
./build_cent/3rd/Matrix_Format_Io/%.o: ./3rd/Matrix_Format_Io/%.c $(MAT_FORMAT_INCLUDE) 
	$(CC) $(CFLAGS) -c  $< -o $@
endif
	
ifeq ($(ARM_CROSS),1)
./build_arm_cross/3rd/Matrix_Format_Io/%.o: ./3rd/Matrix_Format_Io/%.c $(MAT_FORMAT_INCLUDE) 
	$(CC) $(CFLAGS) -c  $< -o $@
endif
########################################################################################

########################  util  ########################################################
ifeq ($(ARM),1)
$(SHARED_TARGET): $(EMAX6_SPARSE_UTIL_ARM_SRC)  $(EMAX6_INCLUDE)
	$(CC) $(SHARED_FLAG) $(CFLAGS) -o $@ $^

./build_arm/util/%.o: ./util/%.c ./Include/emax6_sparselib.h 
	$(CC) $(CFLAGS) -c  $< -o $@
endif

ifeq ($(CENT),1)
$(SHARED_TARGET): $(EMAX6_SPARSE_UTIL_SRC) $(EMAX6_INCLUDE)
	$(CC) $(SHARED_FLAG) $(CFLAGS) -o $@ $^
./build_cent/util/%.o: ./util/%.c ./Include/emax6_sparselib.h 
	$(CC) $(CFLAGS) -c  $< -o $@
endif
	
ifeq ($(ARM_CROSS),1)
$(SHARED_TARGET): $(EMAX6_SPARSE_UTIL_ARM_SRC)  $(EMAX6_INCLUDE)
	$(CC) $(SHARED_FLAG) $(CFLAGS) -o $@ $^
./build_arm_cross/util/%.o: ./util/%.c ./Include/emax6_sparselib.h 
	$(CC) $(CFLAGS) -c  $< -o $@
endif
########################################################################################



############################### kernel #################################################
ifeq ($(ARM),1)
ifeq ($(LINK_FORMAT),shared)
./build_arm/kernel/%-emax6.c: ./kernel/%.c ./Include/emax6_sparselib.h
	perl ./../conv-mark/conv-mark $< > $<-mark.c
	$(CPP) $(OPTION) $(INCLUDE)  $<-mark.c > $<-cppo.c
	./../conv-c2c/conv-c2c.arm $<-cppo.c
else
./build_arm/kernel/%-emax6.o: ./kernel/%.c  ./Include/emax6_sparselib.h
	perl ./../conv-mark/conv-mark $< > $<-mark.c
	$(CPP) $(OPTION) $(INCLUDE)  $<-mark.c > $<-cppo.c
	./..//conv-c2c/conv-c2c.arm $<-cppo.c
	$(CC) $(CFLAGS) -c  $(basename $<)-emax6.c -o $@
endif
endif


ifeq ($(CENT),1)
./build_cent/kernel/%.o: ./kernel/%.c ./Include/emax6_sparselib.h 
	$(CC) $(CFLAGS) -c  $< -o $@
endif


ifeq ($(ARM_CROSS),1)
ifeq ($(LINK_FORMAT),shared)
./build_arm_cross/kernel/%-emax6.c: ./kernel/%.c ./Include/emax6_sparselib.h
	perl ./../conv-mark/conv-mark $< > $<-mark.c
	$(CPP) $(OPTION) $(INCLUDE)  $<-mark.c > $<-cppo.c
	./../conv-c2c/conv-c2c.csim $<-cppo.c
else
./build_arm_cross/kernel/%-emax6.o: ./kernel/%.c  ./Include/emax6_sparselib.h
	perl ./../conv-mark/conv-mark $< > $<-mark.c
	$(CPP) $(OPTION) $(INCLUDE)  $<-mark.c > $<-cppo.c
	./..//conv-c2c/conv-c2c.csim $<-cppo.c
	$(CC) $(CFLAGS) -c  $(basename $<)-emax6.c -o $@
endif
endif
########################################################################################



make_build_dir:
	@mkdir -p ${CURDIR}/build_arm/kernel
	@mkdir -p ${CURDIR}/build_arm/util
	@mkdir -p ${CURDIR}/build_arm/3rd/Matrix_Format_Io
	@mkdir -p ${CURDIR}/build_cent/kernel
	@mkdir -p ${CURDIR}/build_cent/util
	@mkdir -p ${CURDIR}/build_cent/3rd/Matrix_Format_Io
	@mkdir -p ${CURDIR}/build_arm_cross/kernel
	@mkdir -p ${CURDIR}/build_arm_cross/util
	@mkdir -p ${CURDIR}/build_arm_cross/3rd/Matrix_Format_Io


ifeq ($(CENT),1)
clean:
	$(RM) *.o *.a *.so util/*.o kernel/*.o kernel/*-* test/$(basename $(EMAX6_SPARSE_TEST)) ./build_cent/test_* ./build_cent/kernel/* ./build_cent/util/*  ./build_cent/3rd/Matrix_Format_Io/* ./build_cent/libsparse.a

endif


ifeq ($(ARM),1)
clean:
	$(RM) *.o *.a *.so *-emax6.c util/*.o kernel/*.o kernel/*-* test/$(basename $(EMAX6_SPARSE_TEST)) ./build_arm/test_* ./build_arm/kernel/* ./build_arm/util/* ./build_arm/3rd/Matrix_Format_Io/* ./build_arm/libsparse.a

endif


ifeq ($(ARM_CROSS),1)
clean:
	$(RM) *.o *.a *.so *-emax6.c util/*.o kernel/*.o kernel/*-* test/$(basename $(EMAX6_SPARSE_TEST)) ./build_arm_cross/test_* ./build_arm_cross/kernel/* ./build_arm_cross/util/* ./build_arm_cross/3rd/Matrix_Format_Io/* ./build_arm_cross/libsparse.a

endif