#include <iostream>
#include "BmwSportCar.h"


BmwSportCar::BmwSportCar():
    _mutex {}
{
}


BmwSportCar::~BmwSportCar()
{
}


void BmwSportCar::start(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Bmw Sport Car started." << std::endl;
}


void BmwSportCar::drive(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Driving the Bmw Sport Car." << std::endl;
}
