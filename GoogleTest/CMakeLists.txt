cmake_minimum_required(VERSION 3.23)

set(This Gumball)

project(${This} C CXX)

include(CTest)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    Gumball.hpp
)
set(Sources
    Gumball.cpp
)
set(BUILD_GMOCK ON)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)