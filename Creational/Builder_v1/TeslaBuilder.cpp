#include "TeslaBuilder.h"


TeslaBuilder::TeslaBuilder():
    _mutex {},
    _product {}
{
    resetCar();
}


TeslaBuilder::~TeslaBuilder()
{
    delete _product;
}


void TeslaBuilder::resetCar(void)
{
    _product = new Car {};
}


Car* TeslaBuilder::getCar(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    Car* retProduct = _product;
    resetCar();

    return retProduct;
}


void TeslaBuilder::produceWheels(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _product->addComponent("Bridgestone Potenza Sport 285/35-R19 | 305/30-R20");
}


void TeslaBuilder::produceBrakes(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _product->addComponent("Brembo 370mm | 370mm");
}


void TeslaBuilder::produceEngine(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _product->addComponent("Triple electric motor");
}


void TeslaBuilder::produceTransmission(void)
{
    //Teslas don't have a transmission
}


void TeslaBuilder::produceInterios(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _product->addComponent("Leather interior | wood interiors");
}
