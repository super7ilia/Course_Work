CC=g++

CFLAGS=-c -Wall

all: algo

algo: main.o BoyerMooreAlgorithm.o KnuthMorrisPrattAlgorithm.o RabinKarpAlgorithm.o Coincidence.o staffFile.o
	$(CC) main.o BoyerMooreAlgorithm.o KnuthMorrisPrattAlgorithm.o RabinKarpAlgorithm.o Coincidence.o staffFile.o -o algo

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

BoyerMooreAlgorithm.o: BoyerMooreAlgorithm.hpp BoyerMooreAlgorithm.cpp
	$(CC) $(CFLAGS) BoyerMooreAlgorithm.hpp BoyerMooreAlgorithm.cpp

KnuthMorrisPrattAlgorithm.o: KnuthMorrisPrattAlgorithm.hpp KnuthMorrisPrattAlgorithm.cpp
	$(CC) $(CFLAGS) KnuthMorrisPrattAlgorithm.hpp KnuthMorrisPrattAlgorithm.cpp

RabinKarpAlgorithm.o: RabinKarpAlgorithm.hpp RabinKarpAlgorithm.cpp
	$(CC) $(CFLAGS) RabinKarpAlgorithm.hpp RabinKarpAlgorithm.cpp

Coincidence.o: Coincidence.hpp Coincidence.cpp
	$(CC) $(CFLAGS) Coincidence.hpp Coincidence.cpp

staffFile.o: staffFile.hpp staffFile.cpp
	$(CC) $(CFLAGS) staffFile.hpp staffFile.cpp
clean:
	rm -rf *.o algo