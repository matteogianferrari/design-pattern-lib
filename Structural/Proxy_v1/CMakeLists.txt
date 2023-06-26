cmake_minimum_required(VERSION 3.0.0)
project(Proxy_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    ILogger.h
    StdLogger.h
    StdLogger.cpp
    LoggerProxy.h
    LoggerProxy.cpp)
add_executable(Proxy_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
