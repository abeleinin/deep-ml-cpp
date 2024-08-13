# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(DeepML LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source directories
set(EASY_DIR ${CMAKE_SOURCE_DIR}/easy)
set(MEDIUM_DIR ${CMAKE_SOURCE_DIR}/medium)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

# Include directories
include_directories(/opt/homebrew/include/eigen3)
include_directories(/opt/homebrew/include/)
include_directories(${EASY_DIR})

# Collect all source files
file(GLOB EASY_SRCS "${EASY_DIR}/*.cpp")
file(GLOB MEDIUM_SRCS "${MEDIUM_DIR}/*.cpp")
file(GLOB TEST_SRCS "${TEST_DIR}/*.cpp")

# Create object libraries to compile but not link source files
add_library(easy_objs OBJECT ${EASY_SRCS})
add_library(medium_objs OBJECT ${MEDIUM_SRCS})
add_library(test_objs OBJECT ${TEST_SRCS})

# Find Catch2 package
find_package(Catch2 3 REQUIRED)

# Add test executable
add_executable(test_easy ${TEST_DIR}/test_easy.cpp)

# Link with object libraries if necessary
# These tests can use the Catch2-provided main
target_link_libraries(test_easy PRIVATE easy_objs medium_objs Catch2::Catch2WithMain)

# Define tests if using CTest (optional)
enable_testing()
add_test(NAME TestEasy COMMAND test_easy)