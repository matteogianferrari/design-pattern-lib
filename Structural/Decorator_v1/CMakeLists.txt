cmake_minimum_required(VERSION 3.0.0)
project(Decorator_v1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    IPizza.h
    Pizza.h
    Pizza.cpp
    PizzaFactory.h
    PizzaFactory.cpp
    PizzaDecorator.h
    PizzaTirata.h
    PizzaTirata.cpp
    PizzaMarinara.h
    PizzaMarinara.cpp)
add_executable(Decorator_v1 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
