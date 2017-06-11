cmake_minimum_required(VERSION 3.7)
project(audiotest)

add_subdirectory(audioc)
add_subdirectory(audiocpp)

add_executable(audiotestc audiotest.c)
target_link_libraries(audiotestc audioc)

add_executable(audiotestcpp audiotest.cpp)
target_link_libraries(audiotestcpp audiocpp)
