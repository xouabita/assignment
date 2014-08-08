CC = g++
CFLAGS= -std=c++11 -Wall -g -pedantic -Wno-long-long -Werror

all: ./main ./increasing_subsequence

run: ./main
	./main
	./increasing_subsequence

./main: main.cpp
	$(CC) $(CFLAGS) $< -o $@

./increasing_subsequence: ./increasing_subsequence.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf ./main ./increasing_subsequence  *.dSYM
