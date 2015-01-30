all: test-sort.o

INC=-I../awesome-sort/

test-sort.o: test-sort.cpp | _out
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $(OUT_DIR)/$@  $(INC) $<

_out:
	mkdir -p $(OUT_DIR)