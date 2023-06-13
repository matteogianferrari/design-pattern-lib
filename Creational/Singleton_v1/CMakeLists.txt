cmake_minimum_required(VERSION 3.0.0)
project(Singleton_v1 VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES main.cpp Cache.h Cache.cpp)
add_executable(Singleton_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
