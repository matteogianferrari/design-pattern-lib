cmake_minimum_required(VERSION 3.0.0)
project(Prototype_v3 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    ICell.h
    CellSingleton.h
    CellSingleton.cpp
    PlantCell.h
    PlantCell.cpp
    FungiCell.h
    FungiCell.cpp)
add_executable(Prototype_v3 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
