cmake_minimum_required(VERSION 2.8)
project(homulib_and_examples)

include_directories(src)
add_subdirectory(src)
set(CMAKE_C_FLAGS -std=c99)

add_executable(example-c example.c)
add_executable(example-cpp example.cpp)

target_link_libraries(example-cpp homulib-static)
target_link_libraries(example-c homulib)
