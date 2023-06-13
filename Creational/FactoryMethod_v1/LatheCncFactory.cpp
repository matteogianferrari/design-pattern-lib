#include "LatheCncFactory.h"
#include "LatheCnc.h"


LatheCncFactory::LatheCncFactory():
    _mutex {}
{
}


LatheCncFactory::~LatheCncFactory()
{
}


ICnc* LatheCncFactory::factoryMethod(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return new LatheCnc {true};
}
