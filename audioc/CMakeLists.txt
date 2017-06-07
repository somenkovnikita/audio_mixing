cmake_minimum_required(VERSION 3.7)
project(audioc)

set(CMAKE_C_STANDARD 11)

include_directories(include)

file(GLOB HEADERS include/*.h)
file(GLOB SOURCES src/*.c)

add_library(audioc ${HEADERS} ${SOURCES})
