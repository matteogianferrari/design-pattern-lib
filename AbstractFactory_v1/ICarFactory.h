#ifndef ICARFACTORY_H
#define ICARFACTORY_H

#include "ISuv.h"
#include "ISportCar.h"

class ICarFactory
{
public:
    virtual ~ICarFactory() {}

    virtual ISuv* makeSuv(void) = 0;
    virtual ISportCar* makeSportCar(void) = 0;
};

#endif  //ICARTFACTORY_H
