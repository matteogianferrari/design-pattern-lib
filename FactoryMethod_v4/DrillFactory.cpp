#include "DrillFactory.h"


DrillFactory::DrillFactory():
    _mutex {}
{
}


DrillFactory::~DrillFactory()
{
}


Drill* DrillFactory::factoryMethod(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return new Drill {};
}
