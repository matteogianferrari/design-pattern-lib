#ifndef MILLCNCFACTORY_H
#define MILLCNCFACTORY_H

#include "ICncFactory.h"

class MillCncFactory:
    public ICncFactory
{
public:
    MillCncFactory();
    virtual ~MillCncFactory() override;
    
    ICnc* factoryMethod(void) override;

    void setupCnc(void) override;
};

#endif  //MILLCNCFACTORY_H