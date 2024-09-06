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
set(HARD_DIR ${CMAKE_SOURCE_DIR}/hard)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

# Include directories
include_directories(/opt/homebrew/include/eigen3)
include_directories(/opt/homebrew/include/)
include_directories(${EASY_DIR})
include_directories(${MEDIUM_DIR})
include_directories(${HARD_DIR})

# Collect all source files
file(GLOB EASY_SRCS "${EASY_DIR}/*.cpp")
file(GLOB MEDIUM_SRCS "${MEDIUM_DIR}/*.cpp")
file(GLOB HARD_SRCS "${HARD_DIR}/*.cpp")
file(GLOB TEST_SRCS "${TEST_DIR}/*.cpp")

# Create object libraries to compile but not link source files
add_library(easy_objs OBJECT ${EASY_SRCS})
add_library(medium_objs OBJECT ${MEDIUM_SRCS})
add_library(hard_objs OBJECT ${HARD_SRCS})
add_library(test_objs OBJECT ${TEST_SRCS})

# Find Catch2 package
find_package(Catch2 3 REQUIRED)

# Add test executable
add_executable(test_easy ${TEST_DIR}/test_easy.cpp)
add_executable(test_medium ${TEST_DIR}/test_medium.cpp)
add_executable(test_hard ${TEST_DIR}/test_hard.cpp)

# Link with object libraries if necessary
# These tests can use the Catch2-provided main
target_link_libraries(test_easy PRIVATE easy_objs Catch2::Catch2WithMain)
target_link_libraries(test_medium PRIVATE medium_objs Catch2::Catch2WithMain)
target_link_libraries(test_hard PRIVATE hard_objs Catch2::Catch2WithMain)

# Define tests if using CTest (optional)
enable_testing()
add_test(NAME TestEasy COMMAND test_easy)
add_test(NAME TestMedium COMMAND test_medium)
add_test(NAME TestHard COMMAND test_hard)