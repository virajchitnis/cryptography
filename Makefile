# Author: Viraj R Chitnis
# Date: 11/12/18
# Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.

# set the compiler and compiler flags
CXX=g++-8
CXXFLAGS=-Wall -pedantic -g -std=c++17 -O3
CC=$(CXX)
CFLAGS=$(CXXFLAGS)

# Compile the entire project
all: rsa primenumber

rsa: rsa.o Calc.o
	$(CC) $(CFLAGS) -o rsa rsa.o Calc.o

primenumber: primenumber.o Calc.o
	$(CC) $(CFLAGS) -o primenumber primenumber.o Calc.o

primenumber.o: Calc.o primenumber.cpp
	$(CC) $(CFLAGS) -c primenumber.cpp

rsa.o: Calc.o rsa.cpp
	$(CC) $(CFLAGS) -c rsa.cpp

Calc.o: Calc.h Calc.cpp
	$(CC) $(CFLAGS) -c Calc.cpp

# Clean the entire project
clean:
	-rm rsa
	-rm primenumber
	-rm *.o
	-rm -r *.dSYM
