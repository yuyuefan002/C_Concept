CC=g++
CFLAGS=-std=gnu++11 -Werror -Wall -ggdb3 -pedantic
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
test:code.cpp
	g++ $(CFLAGS) -o $@ code.cpp
clean:
	rm -f test *.cpp~ *.o *.h~
