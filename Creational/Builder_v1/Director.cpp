#include "Director.h"


Director::Director(ICarBuilder* builder):
    _mutex {},
    _builder {builder}
{
}


Director::~Director()
{
}


void Director::setBuilder(ICarBuilder* builder)
{
    std::lock_guard<std::mutex> lock {_mutex};
    _builder = builder;
}


void Director::buildSportCar(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    //Wheels and brakes
    _builder->produceWheels();
    _builder->produceBrakes();

    //Engine and trasmission
    _builder->produceEngine();
    _builder->produceTransmission();

    //Interiors
    _builder->produceInterios();
}


void Director::buildRaceCar(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    //Wheels and brakes
    _builder->produceWheels();
    _builder->produceBrakes();

    //Engine and trasmission
    _builder->produceEngine();
    _builder->produceTransmission();
}
