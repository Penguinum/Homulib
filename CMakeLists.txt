cmake_minimum_required(VERSION 2.8)
project(homulib_and_examples)

if (NOT ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC"))
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    # If not using Visual Studio C++
    # Why use of stdlib produces so many warnings?
endif()
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

include_directories(src)
add_subdirectory(src)

add_executable(example-c example.c)
add_executable(example-cpp example.cpp)
add_executable(sinewave-test-cpp ./tests/SinewaveTest.cpp)
add_executable(triangle-test-cpp ./tests/TriangleTest.cpp)
add_executable(square-test-cpp ./tests/SquareTest.cpp)
add_executable(adsr-test-cpp ./tests/ADSRTest.cpp)

target_link_libraries(example-cpp homulib-static)
target_link_libraries(example-c homulib)
target_link_libraries(sinewave-test-cpp homulib-static)
target_link_libraries(triangle-test-cpp homulib-static)
target_link_libraries(square-test-cpp homulib-static)
target_link_libraries(adsr-test-cpp homulib-static)
