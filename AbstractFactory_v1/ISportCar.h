#ifndef ISPORTCAR_H
#define ISPORTCAR_H

#include "ICar.h"

class ISportCar:
    public ICar
{
public:
    virtual ~ISportCar() {}

    virtual void start(void) = 0;
    virtual void drive(void) = 0;
};

#endif  //ISPORTCAR_H
