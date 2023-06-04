#ifndef ISUV_H
#define ISUV_H

#include "ICar.h"

class ISuv:
    public ICar
{
public:
    virtual ~ISuv() {}

    virtual void start(void) = 0;
    virtual void drive(void) = 0;
};

#endif  //ISUV_H
