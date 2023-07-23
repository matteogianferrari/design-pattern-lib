#include "LoggerVisitor.h"
#include "Thermostat.h"
#include "AirConditioner.h"
#include <iostream>


LoggerVisitor::LoggerVisitor()
{
}


LoggerVisitor::~LoggerVisitor()
{
}


void LoggerVisitor::runThermostatOperation(Thermostat* obj)
{
    std::cout << "Logging the Thermostat object variables:" << std::endl;
    std::cout << "Temperature: " << obj->getTemperature() << std::endl;
}


void LoggerVisitor::runAirConditionerOperation(AirConditioner* obj)
{
    std::cout << "Logging the Air conditioner object variables:" << std::endl;
    std::cout << "State: " << obj->getState() << std::endl;
}
