SHELL = /bin/sh
CXX = g++
CFLAGS = -Wall -std=c++17
ARRAYFIRE = -L/opt/arrayfire/lib64 -lafcpu -I/opt/arrayfire/include

all:
	$(CXX) $(CFLAGS) $(ARRAYFIRE) -o svd svd.cpp
