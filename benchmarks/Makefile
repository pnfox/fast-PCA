SHELL = /bin/sh
CXX = g++
CFLAGS = -Wall -std=c++17
ARRAYFIRE = -L/usr/lib64 $(shell pkg-config benchmark --libs) -I/usr/include/benchmark

all:
	$(CXX) $(CFLAGS) $(ARRAYFIRE) -o mybenchmark mybenchmark.cpp
