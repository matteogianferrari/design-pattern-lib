cmake_minimum_required(VERSION 3.0.0)
project(Memento_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    Page.h
    Page.cpp
    PageHistory.h
    PageHistory.cpp
    PageMemento.h
    PageMemento.cpp
    PageObject.h
    PageObject.cpp)
add_executable(Memento_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
