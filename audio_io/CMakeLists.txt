cmake_minimum_required(VERSION 3.7)
project(audio_io)

set(CMAKE_C_STANDARD 11)

add_library(audio_io
        audio_generator.h
        audio_generator.c
        audio_reader.h
        audio_reader.c)
