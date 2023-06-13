#include <iostream>
#include "MercedesSuv.h"


MercedesSuv::MercedesSuv():
    _mutex {}
{
}


MercedesSuv::~MercedesSuv()
{
}


void MercedesSuv::start(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Mercedes Suv started." << std::endl;
}


void MercedesSuv::drive(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Driving the Mercedes Suv." << std::endl;
}
