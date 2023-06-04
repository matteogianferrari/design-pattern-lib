#include "MercedesFactory.h"


MercedesFactory::MercedesFactory():
    _mutex {}
{
}


MercedesFactory::~MercedesFactory()
{
}


ISuv* MercedesFactory::makeSuv(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return new MercedesSuv {};
}


ISportCar* MercedesFactory::makeSportCar(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return new MercedesSportCar {};
}
