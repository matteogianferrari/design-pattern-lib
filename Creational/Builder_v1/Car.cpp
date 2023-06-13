#include <iostream>
#include "Car.h"


Car::Car():
    _mutex {},
    _partsList {}
{
}


Car::~Car()
{
}


void Car::showPartsList(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    std::cout << "Car components:" << std::endl;

    for(std::string& part: _partsList)
    {
        std::cout << "\t-" << part << std::endl;
    }
}


void Car::addComponent(std::string component)
{
    std::lock_guard<std::mutex> lock {_mutex};

    _partsList.push_back(component);
}
