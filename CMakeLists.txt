cmake_minimum_required(VERSION 3.5)
project(cat2 C)

set(CMAKE_C_STANDARD 99)

add_executable(cat2 main.c)

install(TARGETS cat2 DESTINATION bin)
