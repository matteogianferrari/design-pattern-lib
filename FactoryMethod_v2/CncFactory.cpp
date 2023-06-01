#include "CncFactory.h"
#include "LatheCnc.h"
#include "MillCnc.h"


CncFactory::CncFactory():
    _mutex {}
{
}


CncFactory::~CncFactory()
{
}


ICnc* CncFactory::factoryMethod(std::string& cncType)
{
    std::lock_guard<std::mutex> lock {_mutex};

    if(cncType == "Lathe")
        return new LatheCnc {true};
    else if(cncType == "Mill")
        return new MillCnc {5};
    else
        return nullptr;
}
