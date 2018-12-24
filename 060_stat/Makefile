CFLAGS=-Werror -Wall -pedantic -ggdb3 -std=gnu99
mystat:mystat.o accessInfo.o fileinfo.o filehistory.o
	gcc -o mystat mystat.o accessInfo.o fileinfo.o filehistory.o
mystat.o:mystat.c
	gcc $(CFLAGS) -c mystat.c
accessInfo.o:accessInfo.c accessInfo.h
	gcc $(CFLAGS) -c accessInfo.c
fileinfo.o:fileinfo.c fileinfo.h
	gcc $(CFLAGS) -c fileinfo.c
filehistory.o:filehistory.c filehistory.h
	gcc $(CFLAGS) -c filehistory.c
clean:
	rm  *~ mystat  *.o
