cmake_minimum_required(VERSION 3.0.0)
project(Composite_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    ILogicBlock.h
    LogicSignal.h
    LogicSignal.cpp
    LogicAnd.h
    LogicAnd.cpp
    LogicOr.h
    LogicOr.cpp
    LogicNot.h
    LogicNot.cpp)
add_executable(Composite_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
