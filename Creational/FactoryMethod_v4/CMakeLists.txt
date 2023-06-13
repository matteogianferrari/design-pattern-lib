cmake_minimum_required(VERSION 3.0.0)
project(FactoryMethod_v4 VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    Drill.h
    Drill.cpp
    BatteryDrill.h
    BatteryDrill.cpp
    DrillFactory.h
    DrillFactory.cpp
    BatteryDrillFactory.h
    BatteryDrillFactory.cpp)
add_executable(FactoryMethod_v4 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
