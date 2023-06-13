#include <iostream>
#include "MillCnc.h"


MillCnc::MillCnc(uint32_t axisNumber):
    _mutex {},
    _partProgramName {},
    _axisNumber {axisNumber}
{
}


MillCnc::~MillCnc()
{
}


void MillCnc::setPartProgram(std::string& partProgramName)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _partProgramName = partProgramName;
}


void MillCnc::startMachining(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Mill started machining a part with " << _partProgramName << std::endl;
}