SOURCES := test-sort.cpp
CPPFLAGS += -MMD -MP -I ../awesome-sort/

vpath %.d $(OUT_DIR)
vpath %.o $(OUT_DIR)

$(OUT_DIR)/test-sort: $(SOURCES:%.cpp=$(OUT_DIR)/%.o) | _out
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^  $(OUT_DIR)/awesome-sort.a

$(OUT_DIR)/%.o: %.cpp | _out
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

-include $(SOURCES:%.cpp=$(OUT_DIR)/%.d)

_out:
	mkdir -p $(OUT_DIR)

# C динамическая библиотекой
.PHONY: dynamic
dynamic: $(OUT_DIR)/test-sort-dynamic

$(OUT_DIR)/test-sort-dynamic: $(SOURCES:%.cpp=$(OUT_DIR)/%.o) | _out
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^ $(OUT_DIR)/awesome-sort.so