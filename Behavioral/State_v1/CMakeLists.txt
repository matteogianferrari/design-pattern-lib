cmake_minimum_required(VERSION 3.0.0)
project(State_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    IState.h
    Alive.h
    Alive.cpp
    Wounded.h
    Wounded.cpp
    Character.h
    Character.cpp)
add_executable(State_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
