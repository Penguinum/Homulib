cmake_minimum_required(VERSION 2.8)
project(homulib)

if (NOT ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC"))
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    # If not using Visual Studio C++
    # Why use of stdlib produces so many warnings?
    # No, really, why?
endif()

set(SOURCE_LIB  
    ADSR.cpp
    BrownNoiseGenerator.cpp
    Generators.cpp
    KarplusStrongGenerator.cpp
    PinkNoiseGenerator.cpp
    ringbuffer.cpp
    SinewaveGenerator.cpp
    TriangleGenerator.cpp
    WhiteNoiseGenerator.cpp
    cwrapper.cpp
)

add_library(homulib SHARED ${SOURCE_LIB})
add_library(homulib-static STATIC ${SOURCE_LIB})
