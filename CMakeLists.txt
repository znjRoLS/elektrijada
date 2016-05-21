cmake_minimum_required(VERSION 3.3)
project(test_build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BUILD_1 inf_2016_1)
set(SOURCE_FILES_1 inf/2016/1.c)
add_executable(${BUILD_1} ${SOURCE_FILES_1})

set(BUILD_2 inf_2012)
file(GLOB SOURCE_FILES_2 inf/2012/*.c)
add_executable(${BUILD_2} ${SOURCE_FILES_2})