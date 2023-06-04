#include <iostream>
#include "BatteryDrill.h"


BatteryDrill::BatteryDrill():
    _mutex {}
{
}


BatteryDrill::~BatteryDrill()
{
}


void BatteryDrill::use(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Using the battery drill" << std::endl;
}
