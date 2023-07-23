cmake_minimum_required(VERSION 3.0.0)
project(Interpreter_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    IExpression.h
    Number.h
    Number.cpp
    Addition.h
    Addition.cpp
    Subtraction.h
    Subtraction.cpp)
add_executable(Interpreter_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
