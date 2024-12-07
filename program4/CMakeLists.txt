cmake_minimum_required(VERSION 3.15...3.30)

project(
    Program4
    LANGUAGES CXX
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

endif()

add_executable(
    run
    sorter.cpp
    sorts.h
)