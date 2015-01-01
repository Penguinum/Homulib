cmake_minimum_required(VERSION 2.8)
project(homulib)

set(SOURCE_LIB  
    ADSR.cpp
    BrownNoiseGenerator.cpp
    Generators.cpp
    KarplusStrongGenerator.cpp
    PinkNoiseGenerator.cpp
    ringbuffer.cpp
    SinusGenerator.cpp
    TriangleGenerator.cpp
    WhiteNoiseGenerator.cpp
)

add_library(homulib SHARED ${SOURCE_LIB})
