cmake_minimum_required(VERSION 3.30)

project(
    program1
    LANGUAGES CXX
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_OSX_ARCHITECTURES "arm64")
    set(CMAKE_CXX_EXTENSIONS OFF)
    set_property(GLOBAL PROPERTY USER_FOLDERS ON)
    include(CTest)
endif()

include(FetchContent)

FetchContent_Declare(
    catch
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.7.0
)

FetchContent_MakeAvailable(catch)
# adds Catch2::Catch2

add_executable(
    testtimespan
    test_time_span.cpp
)

target_compile_features(
    testtimespan PRIVATE
    cxx_std_17
)

target_link_libraries(
    testtimespan PRIVATE
    time_span
    # Catch2::Catch2
)

add_test(NAME timespantest COMMAND testtimespan)

add_library(
    time_span
    time_span.cpp
    time_span.h
)

target_compile_features(
    time_span PUBLIC
    cxx_std_14
)