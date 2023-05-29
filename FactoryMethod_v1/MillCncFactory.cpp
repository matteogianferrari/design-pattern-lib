#include <string>
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


void MillCncFactory::setupCnc(void)
{
    ICnc* pCnc = factoryMethod();
    std::string partProgramName {"90351012_F2"};

    pCnc->setPartProgram(partProgramName);
    pCnc->startMachining();
}