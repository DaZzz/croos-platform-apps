all: test-sort.o

INC=-I../awesome-sort/

test-sort.o: test-sort.cpp
	mkdir -p $(OUT_DIR)
	g++ -c -o $(OUT_DIR)/$@  $(INC) $<