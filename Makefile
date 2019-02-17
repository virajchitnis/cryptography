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
default: dirs Output/bin/rsa Output/bin/primenumber Output/bin/main

# Compile the entire project for Windows
build_windows: dirs Output/bin/rsa.exe Output/bin/primenumber.exe Output/bin/main.exe

Output/bin/rsa: Output/obj/rsa.o Output/obj/Calc.o
	$(CC) $(CFLAGS) -o Output/bin/rsa Output/obj/rsa.o Output/obj/Calc.o

Output/bin/rsa.exe: Output/obj/rsa.o Output/obj/Calc.o
	$(CC) $(CFLAGS) -o Output/bin/rsa.exe Output/obj/rsa.o Output/obj/Calc.o

Output/bin/primenumber: Output/obj/primenumber.o Output/obj/Calc.o
	$(CC) $(CFLAGS) -o Output/bin/primenumber Output/obj/primenumber.o Output/obj/Calc.o

Output/bin/primenumber.exe: Output/obj/primenumber.o Output/obj/Calc.o
	$(CC) $(CFLAGS) -o Output/bin/primenumber.exe Output/obj/primenumber.o Output/obj/Calc.o

Output/obj/primenumber.o: Output/obj/Calc.o primenumber.cpp
	$(CC) $(CFLAGS) -o Output/obj/primenumber.o -c primenumber.cpp

Output/obj/rsa.o: Output/obj/Calc.o rsa.cpp
	$(CC) $(CFLAGS) -o Output/obj/rsa.o -c rsa.cpp

Output/bin/main: Output/obj/main.o Output/obj/CaesarCipher.o Output/obj/CodeBook.o Output/obj/VigenereCipher.o
	$(CC) $(CFLAGS) -o Output/bin/main Output/obj/main.o Output/obj/CaesarCipher.o Output/obj/CodeBook.o Output/obj/VigenereCipher.o

Output/bin/main.exe: Output/obj/main.o Output/obj/CaesarCipher.o Output/obj/CodeBook.o Output/obj/VigenereCipher.o
	$(CC) $(CFLAGS) -o Output/bin/main.exe Output/obj/main.o Output/obj/CaesarCipher.o Output/obj/CodeBook.o Output/obj/VigenereCipher.o

Output/obj/main.o: Output/obj/CaesarCipher.o main.cpp
	$(CC) $(CFLAGS) -o Output/obj/main.o -c main.cpp

Output/obj/Calc.o: Calc.h Calc.cpp
	$(CC) $(CFLAGS) -o Output/obj/Calc.o -c Calc.cpp

Output/obj/CaesarCipher.o: CaesarCipher.h CaesarCipher.cpp Output/obj/CodeBook.o
	$(CC) $(CFLAGS) -o Output/obj/CaesarCipher.o -c CaesarCipher.cpp

Output/obj/CodeBook.o: CodeBook.h CodeBook.cpp
	$(CC) $(CFLAGS) -o Output/obj/CodeBook.o -c CodeBook.cpp

Output/obj/VigenereCipher.o: VigenereCipher.h VigenereCipher.cpp
	$(CC) $(CFLAGS) -o Output/obj/VigenereCipher.o -c VigenereCipher.cpp

# Make the output directories
.PHONY: dirs
dirs: Output/bin Output/obj

Output/bin:
	mkdir -p Output/bin

Output/obj:
	mkdir -p Output/obj

# Clean the entire project
.PHONY: clean
clean:
	rm -rf Output
