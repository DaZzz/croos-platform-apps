# Makefile for awesome-sort

all: awesome-sort.a

awesome-sort.a: awesome-sort.o
	mkdir -p $(OUT_DIR)
	ar rc $(OUT_DIR)/$@ $(OUT_DIR)/$<

awesome-sort.o: awesome-sort.cpp
	mkdir -p $(OUT_DIR)
	g++ -c -o $(OUT_DIR)/$@ $<