#include "Sensor.h"


Sensor::Sensor(float realValue, float simulatedValue):
    _realValue {realValue},
    _simulatedValue {simulatedValue},
    _currentValue {_realValue}
{
}


Sensor::~Sensor()
{
}


void Sensor::switchState(bool state)
{
    specificActions();

    _currentValue = (state) ? _realValue : _simulatedValue;
}


float Sensor::getValue(void)
{
    return _currentValue;
}
