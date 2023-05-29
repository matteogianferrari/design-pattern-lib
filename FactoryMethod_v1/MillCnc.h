#ifndef MILLCNC_H
#define MILLCNC_H

#include <string>
#include "ICnc.h"

class MillCnc:
    public ICnc
{
public:
    MillCnc(uint32_t axisNumber);
    ~MillCnc() override;

    void setPartProgram(std::string& partProgramName) override;
    void startMachining(void) override;

private:
    std::string _partProgramName;
    uint32_t _axisNumber;
};

#endif  //MILLCNC_H