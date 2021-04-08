cmake_minimum_required(VERSION 3.17)
project(Lab9 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lab9
        Lab9.c
        Lab9.h
        main.c)
