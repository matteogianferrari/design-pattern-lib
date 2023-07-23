cmake_minimum_required(VERSION 3.0.0)
project(Visitor_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    IVisitor.h
    LoggerVisitor.h
    LoggerVisitor.cpp
    ISmartDevice.h
    Thermostat.h
    Thermostat.cpp
    AirConditioner.h
    AirConditioner.cpp)
add_executable(Visitor_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
