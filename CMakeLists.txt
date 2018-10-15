cmake_minimum_required(VERSION 3.5)

project(cat2
        LANGUAGES C
        VERSION "1.0.1")

set(CMAKE_C_STANDARD 99)

set(AUTHORS "Cody Logan")
set(COPY_YEARS "2018")

add_executable(cat2 main.c)
configure_file(${CMAKE_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

install(TARGETS cat2 DESTINATION bin)
