# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.0.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.0.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/DaZzz/Developer/qt/projects/lab01/task13

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/DaZzz/Developer/qt/projects/lab01/_build/cmake-build

# Include any dependencies generated for this target.
include test-sort/CMakeFiles/test-sort.dir/depend.make

# Include the progress variables for this target.
include test-sort/CMakeFiles/test-sort.dir/progress.make

# Include the compile flags for this target's objects.
include test-sort/CMakeFiles/test-sort.dir/flags.make

test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o: test-sort/CMakeFiles/test-sort.dir/flags.make
test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o: /Users/DaZzz/Developer/qt/projects/lab01/task13/test-sort/test-sort.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/DaZzz/Developer/qt/projects/lab01/_build/cmake-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o"
	cd /Users/DaZzz/Developer/qt/projects/lab01/_build/cmake-build/test-sort && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test-sort.dir/test-sort.cpp.o -c /Users/DaZzz/Developer/qt/projects/lab01/task13/test-sort/test-sort.cpp

test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-sort.dir/test-sort.cpp.i"
	cd /Users/DaZzz/Developer/qt/projects/lab01/_build/cmake-build/test-sort && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/DaZzz/Developer/qt/projects/lab01/task13/test-sort/test-sort.cpp > CMakeFiles/test-sort.dir/test-sort.cpp.i

test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-sort.dir/test-sort.cpp.s"
	cd /Users/DaZzz/Developer/qt/projects/lab01/_build/cmake-build/test-sort && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/DaZzz/Developer/qt/projects/lab01/task13/test-sort/test-sort.cpp -o CMakeFiles/test-sort.dir/test-sort.cpp.s

test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o.requires:
.PHONY : test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o.requires

test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o.provides: test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o.requires
	$(MAKE) -f test-sort/CMakeFiles/test-sort.dir/build.make test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o.provides.build
.PHONY : test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o.provides

test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o.provides.build: test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o

# Object files for target test-sort
test__sort_OBJECTS = \
"CMakeFiles/test-sort.dir/test-sort.cpp.o"

# External object files for target test-sort
test__sort_EXTERNAL_OBJECTS =

test-sort/test-sort: test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o
test-sort/test-sort: test-sort/CMakeFiles/test-sort.dir/build.make
test-sort/test-sort: awesome-sort/libawesome-sort.a
test-sort/test-sort: test-sort/CMakeFiles/test-sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test-sort"
	cd /Users/DaZzz/Developer/qt/projects/lab01/_build/cmake-build/test-sort && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test-sort/CMakeFiles/test-sort.dir/build: test-sort/test-sort
.PHONY : test-sort/CMakeFiles/test-sort.dir/build

test-sort/CMakeFiles/test-sort.dir/requires: test-sort/CMakeFiles/test-sort.dir/test-sort.cpp.o.requires
.PHONY : test-sort/CMakeFiles/test-sort.dir/requires

test-sort/CMakeFiles/test-sort.dir/clean:
	cd /Users/DaZzz/Developer/qt/projects/lab01/_build/cmake-build/test-sort && $(CMAKE_COMMAND) -P CMakeFiles/test-sort.dir/cmake_clean.cmake
.PHONY : test-sort/CMakeFiles/test-sort.dir/clean

test-sort/CMakeFiles/test-sort.dir/depend:
	cd /Users/DaZzz/Developer/qt/projects/lab01/_build/cmake-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/DaZzz/Developer/qt/projects/lab01/task13 /Users/DaZzz/Developer/qt/projects/lab01/task13/test-sort /Users/DaZzz/Developer/qt/projects/lab01/_build/cmake-build /Users/DaZzz/Developer/qt/projects/lab01/_build/cmake-build/test-sort /Users/DaZzz/Developer/qt/projects/lab01/_build/cmake-build/test-sort/CMakeFiles/test-sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test-sort/CMakeFiles/test-sort.dir/depend

