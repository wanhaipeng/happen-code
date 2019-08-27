project(happen_code)
cmake_minimum_required(VERSION 3.0)
# set environment variables
set(CMAKE_CXX_STANDARD          11)
SET(CMAKE_BUILD_TYPE            "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG       "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -w")
SET(CMAKE_CXX_FLAGS_RELEASE     "$ENV{CXXFLAGS} -O3 -Wall")
set(EXECUTABLE_OUTPUT_PATH      ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH         ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_MODULE_PATH           ${CMAKE_SOURCE_DIR}/cmake)

# cmake subdir macro
macro(SUBDIRLIST output input)
  file(GLOB children RELATIVE ${input} ${input}/*)
  set(DIRLIST "")
  foreach(child ${children})
    if(IS_DIRECTORY ${input}/${child})
      list(APPEND DIRLIST ${child})
    endif()
  endforeach(child ${children})
  set(${output} ${DIRLIST})
endmacro()

# add src subdirectory
add_subdirectory(src)