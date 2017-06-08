cmake_minimum_required(VERSION 3.7)
project(audiotest)

add_subdirectory(audioc)
#add_subdirectory(audiocpp)

add_executable(audiotestc audiotest.c)
target_include_directories(audiotestc PRIVATE audioc)
target_link_libraries(audiotestc audioc)
