#include <iostream>
#include "Team.h"


Team::Team(IWorkResource* resourceA, IWorkResource* resourceB):
    _resourceA {resourceA},
    _resourceB {resourceB}
{
}


Team::~Team()
{
    delete _resourceA;
    delete _resourceB;
}

    
int32_t Team::work(int32_t workLoad)
{
    if(workLoad - _resourceA->getWorkCapability() <= 0)
        return _resourceA->work(workLoad);
    else if(workLoad - _resourceB->getWorkCapability() <= 0)
        return _resourceB->work(workLoad);
    else
    {
        std::cout << "Team " << this << " is working." << std::endl;
        
        workLoad = _resourceA->work(workLoad);
        return _resourceB->work(workLoad);
    }
}


int32_t Team::getWorkCapability(void)
{
    return _resourceA->getWorkCapability() + _resourceB->getWorkCapability();
}
