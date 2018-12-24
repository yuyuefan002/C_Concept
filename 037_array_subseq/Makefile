CFLAGS=-ggdb3 -Wall -Werror -std=gnu99 -pedantic
myseq: test-subseq.o maxSeq.o
	gcc $(CFLAGS) -o myseq test-subseq.o maxSeq.o
test-subseq.o: test-subseq.c
	gcc $(CFLAGS) -c test-subseq.c
maxSeq.o: maxSeq.c
	gcc $(CFLAGS) -c maxSeq.c
