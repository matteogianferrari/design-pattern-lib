#include "AirConditioner.h"
#include "IVisitor.h"


AirConditioner::AirConditioner():
    _state {false}
{
}


AirConditioner::~AirConditioner() 
{
}


void AirConditioner::acceptVisitor(IVisitor* visitor)
{
    visitor->runAirConditionerOperation(this);
}


void AirConditioner::setState(bool state)
{
    _state = state;
}


bool AirConditioner::getState(void)
{
    return _state;
}
