cmake_minimum_required(VERSION 3.0.0)
project(Mediator_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    IMediator.h
    HomeController.h
    HomeController.cpp
    ISmartDevice.h
    Thermostat.h
    Thermostat.cpp
    AirConditioner.h
    AirConditioner.cpp)
add_executable(Mediator_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
