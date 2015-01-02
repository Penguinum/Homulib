cmake_minimum_required(VERSION 2.8)
project(homulib)

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
