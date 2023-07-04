#include "Company.h"
#include "Employee.h"
#include "Team.h"

//The static member of the Company class need to be initialized outside the constructor
Company* Company::_pInstance {nullptr};
std::mutex Company::_mutex {};


Company* Company::getCompany(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    if(!_pInstance)
        _pInstance = new Company {};
    
    return _pInstance;
}


Company::Company():
    _resource {},
    _factory {new ResourceFactory {}}
{
    //Example of a department creation
    _resource = _factory->factoryMethod("Department");
}


Company::~Company()
{
    delete _resource;
    delete _factory;
    delete _pInstance;
}


bool Company::handleProject(int32_t requiredWork)
{
    std::lock_guard<std::mutex> lock {_mutex};

    if(requiredWork > _resource->getWorkCapability())
        return false;
    
    _resource->work(requiredWork);
    return true;
}
