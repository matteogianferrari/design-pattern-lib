#include "BmwFactory.h"


BmwFactory::BmwFactory():
    _mutex {}
{
}


BmwFactory::~BmwFactory()
{
}


ISuv* BmwFactory::makeSuv(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return new BmwSuv {};
}


ISportCar* BmwFactory::makeSportCar(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return new BmwSportCar {};
}
