cmake_minimum_required(VERSION 2.8)
project(homulib_and_example)

include_directories(src)
add_subdirectory(src)

add_executable(example example.cpp)
target_link_libraries(example homulib)
