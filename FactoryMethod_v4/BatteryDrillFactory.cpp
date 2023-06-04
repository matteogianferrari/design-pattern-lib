#include "BatteryDrillFactory.h"


BatteryDrillFactory::BatteryDrillFactory():
    _mutex {}
{
}


BatteryDrillFactory::~BatteryDrillFactory()
{
}


Drill* BatteryDrillFactory::factoryMethod(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return new BatteryDrill {};
}
