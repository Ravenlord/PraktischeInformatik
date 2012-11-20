#
# AUTHOR: Richard Fussenegger
# AUTHOR: Markus Deutschl
#

all: spair

spair: spair.c
	gcc -Wall -g -O3 -o $@ spair.c

test: spair
	./spair

clean:
	rm -f spair
