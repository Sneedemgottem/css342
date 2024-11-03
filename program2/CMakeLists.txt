cmake_minimum_required(VERSION 3.15...3.30)

project(
    Program2
    LANGUAGES CXX
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set_property(GLOBAL PROPERTY USER_FOLDERS ON)
endif()

add_library(
    greedy_robot
    greedy_robot.cpp
    greedy_robot.h
)

target_include_directories(
    greedy_robot PUBLIC
    .
)

add_executable(
    run
    robot_driver.cpp
)

target_link_libraries(
    run PRIVATE
    greedy_robot
)

add_executable(
    catalan
    catalan.cpp
)