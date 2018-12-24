CFLAGS=-ggdb3 -Wall -Werror -std=gnu99 -pedantic

mytest:test-power.o power.o
	gcc $(CFLAGS) -o mytest test-power.o power.o
power.o:power.c
	gcc $(CFLAGS) -c power.c
test-power.o:test-power.c
	gcc $(CFLAGS) -c test-power.c
