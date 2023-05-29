#include <string>
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


void LatheCncFactory::setupCnc(void)
{
    ICnc* pCnc = factoryMethod();
    std::string partProgramName {"90351012_F1"};

    pCnc->setPartProgram(partProgramName);
    pCnc->startMachining();
}