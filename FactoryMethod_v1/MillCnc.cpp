#include <iostream>
#include "MillCnc.h"


MillCnc::MillCnc(uint32_t axisNumber):
    _partProgramName {},
    _axisNumber {axisNumber}
{
}


MillCnc::~MillCnc()
{
}


void MillCnc::setPartProgram(std::string& partProgramName)
{
    _partProgramName = partProgramName;
}


void MillCnc::startMachining(void)
{
    std::cout << "Mill started machining a part with " << _partProgramName << std::endl;
}