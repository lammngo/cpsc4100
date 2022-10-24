CC=g++
CFLAGS=-Wall -Werror

all: hw2_prob1 hw2_prob2 hw2_prob3

compression:
	tar -cvf p2.tar hw2_prob1.cpp hw2_prob2.cpp hw2_prob3.cpp Makefile README

hw2_prob3: hw2_prob3.o
	$(CC) $(CFLAGS) hw2_prob3.o -o hw2_prob3

hw2_prob3.o: hw2_prob3.cpp
	$(CC) -c $(CFLAGS) hw2_prob3.cpp -o hw2_prob3.o

hw2_prob2: hw2_prob2.o
	$(CC) $(CFLAGS) hw2_prob2.o -o hw2_prob2

hw2_prob2.o: hw2_prob2.cpp
	$(CC) -c $(CFLAGS) hw2_prob2.cpp -o hw2_prob2.o

hw2_prob1: hw2_prob1.o
	$(CC) $(CFLAGS) hw2_prob1.o -o hw2_prob1

hw2_prob1.o: hw2_prob1.cpp
	$(CC) -c $(CFLAGS) hw2_prob1.cpp -o hw2_prob1.o

clean:
	rm –rf main *o hw2_prob1 hw2_prob2 hw2_prob3
