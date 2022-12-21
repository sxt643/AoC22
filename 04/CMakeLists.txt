# Remember to add to the root CMakeLists

cmake_minimum_required(VERSION 3.21)
project(AoC22)

set(CMAKE_CXX_STANDARD 20)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input04.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(04AoC22 AoC041222.cpp)
