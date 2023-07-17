#include <iostream>
#include "AirConditioner.h"


AirConditioner::AirConditioner():
    _state {false},
    _mediator {nullptr}
{
}


AirConditioner::~AirConditioner() 
{
}


void AirConditioner::setMediator(IMediator* mediator)
{
    _mediator = mediator;
}


void AirConditioner::start(void)
{
    _state = true;
    std::cout << "Air conditioner state: " << _state << std::endl;
    
    _mediator->eventHandler(this);
}


void AirConditioner::toggleState(bool state)
{
    _state = state;
    std::cout << "Air conditioner state: " << _state << std::endl;
}


bool AirConditioner::getState(void)
{
    return _state;
}