cmake_minimum_required(VERSION 2.8)
project(homulib)

if (NOT ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC"))
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    # If not using Visual Studio C++
    # Why use of stdlib produces so many warnings?
    # No, really, why?
endif()

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/../")

include_directories(../include)
file(GLOB HEADERS
    "../include/*.h"
)

# Added ${HEADERS} here just to tell QtCreator that headers belong to project
set(SOURCE_LIB  
    ADSR.cpp
    BrownNoise.cpp
    Generators.cpp
    KS_ext_filters.cpp
    KarplusStrong.cpp
    KarplusStrongFilter.cpp
    KarplusStrongBattery.cpp
    PinkNoise.cpp
    ringbuffer.cpp
    Sinewave.cpp
    Triangle.cpp
    Square.cpp
    WhiteNoise.cpp
    Delay.cpp
    Distortion.cpp
    Reverb.cpp
    AllPass.cpp
    SampleRate.cpp
    cwrapper.cpp
    ${HEADERS}
)

add_library(homulib SHARED ${SOURCE_LIB})
add_library(homulib-static STATIC ${SOURCE_LIB})
