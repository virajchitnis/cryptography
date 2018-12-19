# Author: Viraj R Chitnis
# Date: 11/12/18
# Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.

# set the compiler and compiler flags
CXX=g++-8
CXXFLAGS=-Wall -pedantic -g -std=c++17 -O3
CC=$(CXX)
CFLAGS=$(CXXFLAGS)

# Compile the entire project
all: rsa primenumber main

rsa: rsa.o Calc.o
	$(CC) $(CFLAGS) -o rsa rsa.o Calc.o

primenumber: primenumber.o Calc.o
	$(CC) $(CFLAGS) -o primenumber primenumber.o Calc.o

primenumber.o: Calc.o primenumber.cpp
	$(CC) $(CFLAGS) -c primenumber.cpp

rsa.o: Calc.o rsa.cpp
	$(CC) $(CFLAGS) -c rsa.cpp

main: main.o CaesarCipher.o CodeBook.o VigenereCipher.o
	$(CC) $(CFLAGS) -o main main.o CaesarCipher.o CodeBook.o VigenereCipher.o

main.o: CaesarCipher.o main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Calc.o: Calc.h Calc.cpp
	$(CC) $(CFLAGS) -c Calc.cpp

CaesarCipher.o: CaesarCipher.h CaesarCipher.cpp CodeBook.o
	$(CC) $(CFLAGS) -c CaesarCipher.cpp

CodeBook.o: CodeBook.h CodeBook.cpp
	$(CC) $(CFLAGS) -c CodeBook.cpp

VigenereCipher.o: VigenereCipher.h VigenereCipher.cpp
	$(CC) $(CFLAGS) -c VigenereCipher.cpp

# Clean the entire project
clean:
	-rm rsa
	-rm primenumber
	-rm main
	-rm *.o
	-rm -r *.dSYM
