include_directories(${CMAKE_SOURCE_DIR}/include
                    ${CMAKE_SOURCE_DIR}/include/dp)
file(GLOB DPFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*cpp)

foreach(dpfile ${DPFILES})
  string(REPLACE ".cpp" "" execu_name ${dpfile})
  add_executable(${execu_name} ${dpfile})
  install(TARGETS ${execu_name} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/install)
  message(STATUS "dpexe: ${execu_name} -> dpfile: ${dpfile}")
endforeach(dpfile ${DPFILES})
