cmake_minimum_required(VERSION 3.0.0)
project(FactoryMethod_v1 VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    ICnc.h
    ICncFactory.h
    LatheCnc.h
    LatheCnc.cpp
    LatheCncFactory.h
    LatheCncFactory.cpp
    MillCnc.h
    MillCnc.cpp
    MillCncFactory.h
    MillCncFactory.cpp)
add_executable(FactoryMethod_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
