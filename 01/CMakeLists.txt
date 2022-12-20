cmake_minimum_required(VERSION 3.21)
project(AoC22)

set(CMAKE_CXX_STANDARD 20)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input01.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(01AoC22 AoC011222.cpp)
