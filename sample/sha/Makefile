# By default, the code is compiled for a "big endian" machine.
# To compile on a "little endian" machine set the LITTLE_ENDIAN flag.
# To make smaller object code, but run a little slower, don't use UNROLL_LOOPS.
# To use NIST's modified SHA of 7/11/94, define USE_MODIFIED_SHA

CC = gcc
CFLAGS = -O3 -Wall

sha:	sha.o
	$(CC) -o $@ sha.o
	strip $@

clean:
	rm -rf *.o output*

run_small:;
	./sha input_small.asc | tee output_small.txt

run_large:;
	./sha input_large.asc | tee output_large.txt
