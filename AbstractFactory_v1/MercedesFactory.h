#ifndef MERCEDESFACTORY_H
#define MERCEDESFACTORY_H

#include <mutex>
#include "ICarFactory.h"
#include "MercedesSuv.h"
#include "MercedesSportCar.h"

class MercedesFactory:
    public ICarFactory
{
public:
    MercedesFactory();
    ~MercedesFactory() override;

    ISuv* makeSuv(void) override;
    ISportCar* makeSportCar(void) override;

private:
    std::mutex _mutex;
};

#endif  //MERCEDESFACTORY_H
