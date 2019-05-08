project(ppeng_code)
cmake_minimum_required(VERSION 3.0)
# set global param
set(CMAKE_CXX_STANDARD     11)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH      ${CMAKE_BINARY_DIR}/cmake)
set(LIBRARY_OUTPUT_PATH    ${CMAKE_BINARY_DIR}/lib)
# include
include_directories(${PROJECT_SOURCE_DIR}/include)

# build executable
add_executable(test_LongestPalindromeSubstring ${PROJECT_SOURCE_DIR}/src/test_LongestPalindromeSubstring.cpp)