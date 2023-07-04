#include <iostream>
#include "Employee.h"


Employee::Employee(int32_t workLoad):
    _workLoad {workLoad}
{
}


Employee::~Employee()
{
}


int32_t Employee::work(int32_t workLoad)
{
    std::cout << "Employee " << this << " is working." << std::endl;
    return workLoad - _workLoad;
}


int32_t Employee::getWorkCapability(void)
{
    return _workLoad;
}
