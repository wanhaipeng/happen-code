SUBDIRLIST(CODE_SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
set(CODE_BASE_EXECUTABLE_OUTPUT_PATH ${EXECUTABLE_OUTPUT_PATH})

foreach(subdir ${CODE_SUBDIRS})
  message(STATUS "CODE SUBDIR: ${subdir}")
  set(EXECUTABLE_OUTPUT_PATH ${CODE_BASE_EXECUTABLE_OUTPUT_PATH}/${subdir})
  add_subdirectory(${subdir})
endforeach(subdir ${CODE_SUBDIRS})

# add spdlog test
set(EXECUTABLE_OUTPUT_PATH ${CODE_BASE_EXECUTABLE_OUTPUT_PATH})
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(test_spdlog test_spdlog.cpp)