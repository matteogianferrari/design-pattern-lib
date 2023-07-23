#include "Thermostat.h"
#include "IVisitor.h"


Thermostat::Thermostat():
    _temperature {0.f}
{
}


Thermostat::~Thermostat() 
{
}


void Thermostat::acceptVisitor(IVisitor* visitor)
{
    visitor->runThermostatOperation(this);
}


void Thermostat::readTemperature(float temp)
{
    _temperature = temp;
}


float Thermostat::getTemperature(void)
{
    return _temperature;
}
