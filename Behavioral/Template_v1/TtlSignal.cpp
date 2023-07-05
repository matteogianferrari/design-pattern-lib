#include "TtlSignal.h"


TtlSignal::TtlSignal(float voltage):
    _voltage {voltage}
{
}


TtlSignal::~TtlSignal()
{
}


float TtlSignal::getVoltage(void)
{
    return _voltage;
}


float TtlSignal::process(void)
{
    return filter() * 3.f;
}


float TtlSignal::filter(void)
{
    return (_voltage > MAX_TTL_VOLTAGE) ? MAX_TTL_VOLTAGE : _voltage;
}
