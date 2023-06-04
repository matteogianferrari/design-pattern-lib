#include <iostream>
#include "MercedesSportCar.h"


MercedesSportCar::MercedesSportCar():
    _mutex {}
{
}


MercedesSportCar::~MercedesSportCar()
{
}


void MercedesSportCar::start(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Mercedes Sport Car started." << std::endl;
}


void MercedesSportCar::drive(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Driving the Mercedes Sport Car." << std::endl;
}
