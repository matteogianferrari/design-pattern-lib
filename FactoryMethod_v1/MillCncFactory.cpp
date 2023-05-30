#include "MillCncFactory.h"
#include "MillCnc.h"


MillCncFactory::MillCncFactory()
{
}


MillCncFactory::~MillCncFactory()
{
}


ICnc* MillCncFactory::factoryMethod(void)
{
    return new MillCnc {5};
}
