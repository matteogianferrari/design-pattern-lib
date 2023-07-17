#include "HomeController.h"


HomeController::HomeController(Thermostat* sensor, AirConditioner* conditioner):
    _sensor {sensor},
    _conditioner {conditioner}
{
}

    
HomeController::~HomeController()
{
}


void HomeController::eventHandler(ISmartDevice* obj)
{
    if(obj == _sensor)
    {
        float temp {_sensor->getTemperature()};
        
        _conditioner->toggleState((temp > 25.f) ? true : false);
    }
    else if(obj == _conditioner)
    {
        bool state {_conditioner->getState()};
        _sensor->toggleState(state);
    }
}
