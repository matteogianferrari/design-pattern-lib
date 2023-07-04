cmake_minimum_required(VERSION 3.0.0)
project(ChainOfResponsability_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    IWorkResource.h
    Employee.h
    Employee.cpp
    Team.h
    Team.cpp
    Department.h
    Department.cpp
    Company.h
    Company.cpp
    ResourceFactory.h
    ResourceFactory.cpp)
add_executable(ChainOfResponsability_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
