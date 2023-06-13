#include "BmwBuilder.h"


BmwBuilder::BmwBuilder():
    _mutex {},
    _product {}
{
    resetCar();
}


BmwBuilder::~BmwBuilder()
{
    delete _product;
}


void BmwBuilder::resetCar(void)
{
    _product = new Car {};
}


Car* BmwBuilder::getCar(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    Car* retProduct = _product;
    resetCar();

    return retProduct;
}


void BmwBuilder::produceWheels(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _product->addComponent("Pirelli P0 265/35-R20 | 305/30-R21");
}


void BmwBuilder::produceBrakes(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _product->addComponent("Brembo 390mm | 375mm");
}


void BmwBuilder::produceEngine(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _product->addComponent("B58 3000cc");
}


void BmwBuilder::produceTransmission(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _product->addComponent("ZF 8 gears");
}


void BmwBuilder::produceInterios(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _product->addComponent("Bmw leather/alcantara | carbon fiber interiors");
}
