# Makefile for awesome-sort
all: awesome-sort.a

awesome-sort.a: awesome-sort.o | _out
	ar rc $(OUT_DIR)/$@ $(OUT_DIR)/$<

awesome-sort.o: awesome-sort.cpp | _out
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $(OUT_DIR)/$@ $<

_out:
	mkdir -p $(OUT_DIR)

# Динамическая библиотека
.PHONY: dynamic
dynamic: awesome-sort.so

awesome-sort.so: awesome-sort.cpp | _out
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -dynamiclib -flat_namespace $< -o $(OUT_DIR)/$@