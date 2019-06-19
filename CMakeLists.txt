project(ppeng_code)
cmake_minimum_required(VERSION 3.0)
# set environment variables
set(CMAKE_CXX_STANDARD          11)
SET(CMAKE_BUILD_TYPE            "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG       "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE     "$ENV{CXXFLAGS} -O3 -Wall")
set(EXECUTABLE_OUTPUT_PATH      ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH         ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_MODULE_PATH           ${CMAKE_SOURCE_DIR}/cmake)
# include
include_directories(${PROJECT_SOURCE_DIR}/include)

# build executable
add_executable(test_spdlog ${PROJECT_SOURCE_DIR}/src/test_spdlog.cpp)
add_executable(test_LongestPalindromeSubstring ${PROJECT_SOURCE_DIR}/src/test_LongestPalindromeSubstring.cpp)
add_executable(test_MaxSubarray ${CMAKE_SOURCE_DIR}/src/test_MaxSubarray.cpp)
add_executable(test_UniquePaths ${CMAKE_SOURCE_DIR}/src/test_UniquePaths.cpp)
add_executable(test_ClimbStairs ${CMAKE_SOURCE_DIR}/src/test_ClimbStairs.cpp)
add_executable(test_LongestValidParentheses ${CMAKE_SOURCE_DIR}/src/test_LongestValidParentheses.cpp)
add_executable(test_IaMatch ${CMAKE_SOURCE_DIR}/src/test_IsMatch.cpp)