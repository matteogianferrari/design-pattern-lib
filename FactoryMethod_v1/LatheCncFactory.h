#ifndef LATHECNCFACTORY_H
#define LATHECNCFACTORY_H

#include "ICncFactory.h"

class LatheCncFactory:
    public ICncFactory
{
public:
    LatheCncFactory();
    virtual ~LatheCncFactory() override;
    
    ICnc* factoryMethod(void) override;

    void setupCnc(void) override;
};

#endif  //LATHECNCFACTORY_H