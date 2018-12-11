# Author: Viraj R Chitnis
# Date: 11/12/18
# Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.

# set the compiler and compiler flags
CXX=g++-8
CXXFLAGS=-Wall -pedantic -g -std=c++17
CC=$(CXX)
CFLAGS=$(CXXFLAGS)

# Compile the entire project
all: rsa

# Run the program
run: all
	./rsa

rsa: rsa.o Calc.o
	$(CC) $(CFLAGS) -o rsa rsa.o Calc.o

rsa.o: Calc.o rsa.cpp
	$(CC) $(CFLAGS) -c rsa.cpp

Calc.o: Calc.h Calc.cpp
	$(CC) $(CFLAGS) -c Calc.cpp

# Clean the entire project
clean:
	-rm rsa
	-rm -r *.dSYM
