cmake_minimum_required(VERSION 3.0.0)
project(Facade_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    IDatabase.h
    HashTableDatabase.h
    HashTableDatabase.cpp
    ILogger.h
    StdOutLogger.h
    StdOutLogger.cpp
    TemperatureRecorder.h
    TemperatureRecorder.cpp)
add_executable(Facade_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
