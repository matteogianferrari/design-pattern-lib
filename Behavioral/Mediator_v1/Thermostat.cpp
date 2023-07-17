#include <iostream>
#include "Thermostat.h"


Thermostat::Thermostat():
    _state {false},
    _temperature {0.f},
    _mediator {nullptr}
{
}


Thermostat::~Thermostat() 
{
}


void Thermostat::setMediator(IMediator* mediator)
{
    _mediator = mediator;
}


float Thermostat::getTemperature(void)
{
    return _temperature;
}

void Thermostat::toggleState(bool state)
{
    _state = state;
    std::cout << "Thermostat state: " << _state << std::endl;
}


void Thermostat::readTemperature(float temp)
{
    _temperature = temp;
    std::cout << "Temperature: " << _temperature << std::endl;
    
    _mediator->eventHandler(this);
}
