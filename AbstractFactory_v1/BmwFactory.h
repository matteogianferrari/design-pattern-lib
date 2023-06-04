#ifndef BMWFACTORY_H
#define BMWFACTORY_H

#include <mutex>
#include "ICarFactory.h"
#include "BmwSuv.h"
#include "BmwSportCar.h"

class BmwFactory:
    public ICarFactory
{
public:
    BmwFactory();
    ~BmwFactory() override;

    ISuv* makeSuv(void) override;
    ISportCar* makeSportCar(void) override;

private:
    std::mutex _mutex;
};

#endif  //BMWFACTORY_H
