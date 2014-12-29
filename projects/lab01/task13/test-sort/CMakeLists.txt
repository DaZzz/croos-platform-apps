cmake_minimum_required(VERSION 2.8)

project(test-sort)

add_executable(test-sort test-sort.cpp)

include_directories(../awesome-sort)

target_link_libraries(test-sort awesome-sort)