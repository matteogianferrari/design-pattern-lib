#include <iostream>
#include "BmwSuv.h"


BmwSuv::BmwSuv():
    _mutex {}
{
}


BmwSuv::~BmwSuv()
{
}


void BmwSuv::start(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Bmw Suv started." << std::endl;
}


void BmwSuv::drive(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Driving the Bmw Suv." << std::endl;
}
