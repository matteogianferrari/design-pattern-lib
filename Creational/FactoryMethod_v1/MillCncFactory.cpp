#include "MillCncFactory.h"
#include "MillCnc.h"


MillCncFactory::MillCncFactory():
    _mutex {}
{
}


MillCncFactory::~MillCncFactory()
{
}


ICnc* MillCncFactory::factoryMethod(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return new MillCnc {5};
}
