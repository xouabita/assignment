CC = g++
CFLAGS= -std=c++11 -Wall -g -pedantic -Wno-long-long -Werror

all: ./main

run: ./main
	./main

./main: main.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f main
