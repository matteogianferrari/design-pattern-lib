cmake_minimum_required(VERSION 3.0.0)
project(Strategy_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    ISearchAlgo.h
    BinaryTree.h
    BinaryTree.cpp
    Node.h
    Node.cpp
    DfsRecursive.h
    DfsRecursive.cpp
    DfsIterative.h
    DfsIterative.cpp)
add_executable(Strategy_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
