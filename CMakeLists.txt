cmake_minimum_required(VERSION 3.0.0)
project(UniAssign VERSION 0.1.0)

include(CTest)
enable_testing()
file(GLOB SOURCES src/**.c)
add_executable(UniAssign ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
