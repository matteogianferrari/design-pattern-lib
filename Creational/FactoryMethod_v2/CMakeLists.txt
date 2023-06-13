cmake_minimum_required(VERSION 3.0.0)
project(FactoryMethod_v2 VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    ICnc.h
    CncFactory.h
    CncFactory.cpp
    LatheCnc.h
    LatheCnc.cpp
    MillCnc.h
    MillCnc.cpp)
add_executable(FactoryMethod_v2 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
