cmake_minimum_required(VERSION 3.15...3.30)

project(
    Program3
    LANGUAGES CXX
)

# Only add this if this is the main project, not if included through add_subdirectory
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # use c++ 14 at least
    set(CMAKE_CXX_STANDARD 14)

    # Let's ensure -std=c++xx instead of g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USER_FOLDERS ON)
endif()

add_executable(
    run
    driver.cpp
    list342.h
)

add_library(
    child_lib
    child.cpp
    child.h
)

target_include_directories(
    child_lib PUBLIC
    .
)

target_link_libraries(
    run PRIVATE
    child_lib
)