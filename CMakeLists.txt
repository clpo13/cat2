cmake_minimum_required(VERSION 3.5)

project(cat2
        VERSION 1.0.1
        DESCRIPTION "print to stdout"
        LANGUAGES C)

set(CMAKE_C_STANDARD 99)
enable_testing()

configure_file(${CMAKE_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(cat2 main.c)
add_test(test_cat2 cat2)

install(TARGETS cat2 DESTINATION bin)
