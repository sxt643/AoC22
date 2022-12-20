cmake_minimum_required(VERSION 3.21)
project(AoC22)

set(CMAKE_CXX_STANDARD 20)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input02.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(02AoC22 AoC021222.cpp)
