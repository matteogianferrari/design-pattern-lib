#include "LogicSignal.h"


LogicSignal::LogicSignal(bool value):
    _mutex {},
    _value {value}
{
}


LogicSignal::~LogicSignal()
{
}


bool LogicSignal::getResult(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    return _value;
}


void LogicSignal::setValue(bool value)
{
    std::lock_guard<std::mutex> lock {_mutex};        
    _value = value;
}
