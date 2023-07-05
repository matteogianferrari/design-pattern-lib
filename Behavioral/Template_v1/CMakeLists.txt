cmake_minimum_required(VERSION 3.0.0)
project(Template_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    ISignal.h
    TtlSignal.h
    TtlSignal.cpp
    CmosSignal.h
    CmosSignal.cpp)
add_executable(Template_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
