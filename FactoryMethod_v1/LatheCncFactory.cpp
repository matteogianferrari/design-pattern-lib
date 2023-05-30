#include "LatheCncFactory.h"
#include "LatheCnc.h"


LatheCncFactory::LatheCncFactory()
{
}


LatheCncFactory::~LatheCncFactory()
{
}


ICnc* LatheCncFactory::factoryMethod(void)
{
    return new LatheCnc {true};
}
