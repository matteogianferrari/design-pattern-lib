#include <iostream>
#include "Department.h"


Department::Department(IWorkResource* resourceA, IWorkResource* resourceB, IWorkResource* resourceC):
    _resourceA {resourceA},
    _resourceB {resourceB},
    _resourceC {resourceC}
{
}


Department::~Department()
{
    delete _resourceA;
    delete _resourceB;
    delete _resourceC;
}

    
int32_t Department::work(int32_t workLoad)
{
    //Resource A can get the work done
    if(isSubstainable(_resourceA->getWorkCapability(), workLoad))
        return _resourceA->work(workLoad);
    //Resource B can get the work done
    else if(isSubstainable(_resourceB->getWorkCapability(), workLoad))
        return _resourceB->work(workLoad);
    //Resource C can get the work done
    else if(isSubstainable(_resourceC->getWorkCapability(), workLoad))
        return _resourceC->work(workLoad);
    //Resource A and B can get the work done
    else if(isSubstainable(_resourceA->getWorkCapability() + _resourceB->getWorkCapability(), workLoad))
    {
        workLoad = _resourceA->work(workLoad);
        return _resourceB->work(workLoad);
    }
    //Resource A and C can get the work done
    else if(isSubstainable(_resourceA->getWorkCapability() + _resourceC->getWorkCapability(), workLoad))
    {
        workLoad = _resourceA->work(workLoad);
        return _resourceC->work(workLoad);
    }
    //Resource B and C can get the work done
    else if(isSubstainable(_resourceB->getWorkCapability() + _resourceC->getWorkCapability(), workLoad))
    {
        workLoad = _resourceB->work(workLoad);
        return _resourceC->work(workLoad);
    }
    //Resource A and B and C can get the work done
    else
    {
        std::cout << "The department " << this << " is working." << std::endl;

        workLoad = _resourceA->work(workLoad);
        workLoad = _resourceB->work(workLoad);
        return  _resourceC->work(workLoad);
    }
}


int32_t Department::getWorkCapability(void) 
{
    return _resourceA->getWorkCapability() +
           _resourceB->getWorkCapability() +
           _resourceC->getWorkCapability();
}


bool Department::isSubstainable(int32_t workCapability, int32_t workLoad)
{
    return workLoad <= workCapability;
}
