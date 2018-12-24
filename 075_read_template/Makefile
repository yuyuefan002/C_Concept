CC=g++
CFLAGS=std=gnu++11 -pedantic -Wall -Werror -ggdb3
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
test:$(OBJS)
	g++ -o $@ $(OBJS)

clean:
	rm -f test *.o *.c~ *.h~
