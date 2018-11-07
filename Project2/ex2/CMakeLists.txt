cmake_minimum_required(VERSION 2.8.12)

project(ex2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_BUILD_TYPE "Release")

find_package(Qt5Core REQUIRED)
include_directories(${Qt5Core_INCLUDES})
add_definitions(${Qt5Core_DEFINITIONS})

find_package(Qt5Gui REQUIRED)
include_directories(${Qt5Gui_INCLUDES})
add_definitions(${Qt5Gui_DEFINITIONS})


find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)

# Create a debug build
set(CMAKE_CXX_FLAGS "-Wall --std=c++14")

# Set all CPP files to be source files
#file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
#file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../common/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../common/*.h)

set(SOURCE_FILES
    main.cpp
    ../common/displaysurface.cpp
    ../common/displaysurface.h
    ../common/vector.cpp
    ../common/vector.h
    ../common/point.cpp
    ../common/point.h


)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)