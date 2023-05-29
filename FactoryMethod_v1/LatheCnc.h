#ifndef LATHECNC_H
#define LATHECNC_H

#include <string>
#include "ICnc.h"

class LatheCnc:
    public ICnc
{
public:
    LatheCnc(bool rotaryTurret);
    ~LatheCnc() override;

    void setPartProgram(std::string& partProgramName) override;
    void startMachining(void) override;

private:
    std::string _partProgramName;
    bool _rotaryTurret;
};

#endif  //LATHECNC_H