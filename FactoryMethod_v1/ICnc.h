#ifndef ICNC_H
#define ICNC_H

#include <string>

class ICnc
{
public:
    virtual ~ICnc() {}

    virtual void startMachining(void) = 0;
    virtual void setPartProgram(std::string& partProgramName) = 0;
};

#endif  //ICNC_H