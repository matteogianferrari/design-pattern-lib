#include <iostream>
#include "LatheCnc.h"


LatheCnc::LatheCnc(bool rotaryTurret):
    _partProgramName {},
    _rotaryTurret {rotaryTurret}
{
}


LatheCnc::~LatheCnc()
{
}


void LatheCnc::setPartProgram(std::string& partProgramName)
{
    _partProgramName = partProgramName;
}


void LatheCnc::startMachining(void)
{
    std::cout << "Lathe started machining a part with " << _partProgramName << std::endl;
}