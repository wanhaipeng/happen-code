include_directories(${CMAKE_SOURCE_DIR}/include
                    ${CMAKE_SOURCE_DIR}/include/dfs)
file(GLOB DFSFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*cpp)

foreach(dfsfile ${DFSFILES})
  string(REPLACE ".cpp" "" execu_name ${dfsfile})
  add_executable(${execu_name} ${dfsfile})
  install(TARGETS ${execu_name} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/install)
  message(STATUS "dfsexe: ${execu_name} -> dfsfile: ${dfsfile}")
endforeach(dfsfile ${DFSFILES})
