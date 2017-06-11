cmake_minimum_required(VERSION 3.7)
project(audiocpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

file(GLOB HEADERS include/*.hpp)
file(GLOB SOURCES src/*.cpp)

add_library(audiocpp ${HEADERS} ${SOURCES})
