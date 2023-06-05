cmake_minimum_required(VERSION 3.0.0)
project(AbstractFactory_v2 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES
    main.cpp
    ICar.h
    ICarFactory.h
    CarFactorySingleton.h
    CarFactorySingleton.cpp
    ISuv.h
    ISportCar.h
    BmwSuv.h
    BmwSuv.cpp
    BmwSportCar.h
    BmwSportCar.cpp
    BmwFactory.h
    BmwFactory.cpp
    MercedesSuv.h
    MercedesSuv.cpp
    MercedesSportCar.h
    MercedesSportCar.cpp
    MercedesFactory.h
    MercedesFactory.cpp)
add_executable(AbstractFactory_v2 ${SOURCES})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
