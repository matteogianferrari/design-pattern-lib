#ifndef ICNCFACTORY_H
#define ICNCFACTORY_H

#include "ICnc.h"

class ICncFactory
{
public:
    virtual ~ICncFactory() {}
    
    virtual ICnc* factoryMethod(void) = 0;

    virtual void setupCnc(void) = 0;
};

#endif  //ICNCFACTORY_H