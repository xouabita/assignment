CC = g++
CFLAGS= -std=c++11 -Wall -g -pedantic -Wno-long-long -Werror

all: ./intersection ./increasing_subsequence

run: ./intersection ./increasing_subsequence
	./main
	./increasing_subsequence

./intersection: intersection.cpp
	$(CC) $(CFLAGS) $< -o $@

./increasing_subsequence: ./increasing_subsequence.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf ./intersection ./increasing_subsequence  *.dSYM
