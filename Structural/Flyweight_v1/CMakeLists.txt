cmake_minimum_required(VERSION 3.0.0)
project(Flyweight_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    Sentence.h
    Sentence.cpp
    Letter.h
    Letter.cpp
    LetterFactory.h
    LetterFactory.cpp)
add_executable(Flyweight_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
