all: test-sort

CPPFLAGS += -I ../awesome-sort/

test-sort: test-sort.o | _out
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $(OUT_DIR)/test-sort $(OUT_DIR)/test-sort.o $(OUT_DIR)/awesome-sort.a

test-sort.o: test-sort.cpp | _out
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $(OUT_DIR)/$@ $<

_out:
	mkdir -p $(OUT_DIR)