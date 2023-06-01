#include <iostream>
#include "LatheCnc.h"


LatheCnc::LatheCnc(bool rotaryTurret):
    _mutex {},
    _partProgramName {},
    _rotaryTurret {rotaryTurret}
{
}


LatheCnc::~LatheCnc()
{
}


void LatheCnc::setPartProgram(std::string& partProgramName)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _partProgramName = partProgramName;
}


void LatheCnc::startMachining(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Lathe started machining a part with " << _partProgramName << std::endl;
}