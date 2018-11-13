cmake_minimum_required(VERSION 2.8.12)

project(ex2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_BUILD_TYPE "Release")

# Create a debug build
set(CMAKE_CXX_FLAGS "-Wall --std=c++14")

# Set all CPP files to be source files
#file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
#file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../common/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../common/*.h)

set(SOURCE_FILES
    main.cpp
    matrix.cpp
    matrix.h
    ../common/displaysurface.cpp
    ../common/displaysurface.h
    ../common/vector.cpp
    ../common/vector.h
    ../common/point.cpp
    ../common/point.h

)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})