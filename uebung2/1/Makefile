#
# See following link for explanation of the backtick char for
# command substitution:
# http://ubuntuforums.org/showpost.php?s=9d8c54988be3eaf3efc382a25e5e743b&p=3307591&postcount=3
#
# AUTHOR: Richard Fussenegger
# AUTHOR: Markus Deutschl
#

all: mm

mm: matrix_multiplication.c
	gcc -Wall -g -DCLS=`getconf LEVEL1_DCACHE_LINESIZE` -std=c99 -msse2 -O3 -o mm matrix_multiplication.c

test: mm
	./mm

clean:
	rm -f mm
	
