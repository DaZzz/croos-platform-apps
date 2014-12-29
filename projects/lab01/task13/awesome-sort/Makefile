# Makefile for awesome-sort

all: awesome-sort.a

awesome-sort.a: awesome-sort.o
	ar rc ../../_build/$@ ../../_build/$<

awesome-sort.o: awesome-sort.cpp
	g++ -c -o ../../_build/$@ $<