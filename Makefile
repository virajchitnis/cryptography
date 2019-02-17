# Author: Viraj R Chitnis
# Date: 11/12/18
# Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.

# set the compiler and compiler flags
CXX=g++-8
CXXFLAGS=-Wall -pedantic -g -std=c++17 -O3
CC=$(CXX)
CFLAGS=$(CXXFLAGS)

# set linux specific compiler flags
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CXXFLAGS+= -static
endif

# Compile the entire project
default: rsa primenumber main

# Compile the entire project for Windows
build_windows: rsa.exe primenumber.exe main.exe

rsa: rsa.o Calc.o
	$(CC) $(CFLAGS) -o rsa rsa.o Calc.o

rsa.exe: rsa.o Calc.o
	$(CC) $(CFLAGS) -o rsa.exe rsa.o Calc.o

primenumber: primenumber.o Calc.o
	$(CC) $(CFLAGS) -o primenumber primenumber.o Calc.o

primenumber.exe: primenumber.o Calc.o
	$(CC) $(CFLAGS) -o primenumber.exe primenumber.o Calc.o

primenumber.o: Calc.o primenumber.cpp
	$(CC) $(CFLAGS) -c primenumber.cpp

rsa.o: Calc.o rsa.cpp
	$(CC) $(CFLAGS) -c rsa.cpp

main: main.o CaesarCipher.o CodeBook.o VigenereCipher.o
	$(CC) $(CFLAGS) -o main main.o CaesarCipher.o CodeBook.o VigenereCipher.o

main.exe: main.o CaesarCipher.o CodeBook.o VigenereCipher.o
	$(CC) $(CFLAGS) -o main.exe main.o CaesarCipher.o CodeBook.o VigenereCipher.o

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
	-rm *.exe
	-rm *.o
	-rm -r *.dSYM
