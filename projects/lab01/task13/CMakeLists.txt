cmake_minimum_required(VERSION 2.8)

set(binary_root_dir "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${binary_root_dir}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${binary_root_dir}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${binary_root_dir}/lib)

add_subdirectory(awesome-sort)
add_subdirectory(test-sort)