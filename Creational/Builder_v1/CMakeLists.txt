cmake_minimum_required(VERSION 3.0.0)
project(Builder_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    Car.h
    Car.cpp
    ICarBuilder.h
    BmwBuilder.h
    BmwBuilder.cpp
    TeslaBuilder.h
    TeslaBuilder.cpp
    Director.h
    Director.cpp)
add_executable(Builder_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
