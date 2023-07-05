#include "CmosSignal.h"


CmosSignal::CmosSignal(float voltage):
    _voltage {voltage}
{
}


CmosSignal::~CmosSignal()
{
}


float CmosSignal::getVoltage(void)
{
    return _voltage;
}


float CmosSignal::process(void)
{
    return filter() * 1.5f;
}


float CmosSignal::filter(void)
{
    return (_voltage > MAX_CMOS_VOLTAGE) ? MAX_CMOS_VOLTAGE : _voltage;
}
