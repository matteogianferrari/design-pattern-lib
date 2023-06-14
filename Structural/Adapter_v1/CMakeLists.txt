cmake_minimum_required(VERSION 3.0.0)
project(Adapter_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    UsbTypeA.h
    UsbTypeA.cpp
    UsbTypeC.h
    UsbTypeC.cpp
    UsbAdapterCToA.h
    UsbAdapterCToA.cpp)
add_executable(Adapter_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
