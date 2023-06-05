#include "CarFactorySingleton.h"


//The static member of the Cache class need to be initialised outside the constructor
std::mutex CarFactorySingleton::_mutex {};
ICarFactory* CarFactorySingleton::_pInstance {nullptr};


CarFactorySingleton::CarFactorySingleton()
{
}


CarFactorySingleton::~CarFactorySingleton()
{
    delete _pInstance;
}


ICarFactory* CarFactorySingleton::getCarFactory(std::string& brand)
{
    //Locks the mutex
    std::lock_guard<std::mutex> lock {_mutex};

    if(!_pInstance)
    {
        if(brand == "Bmw")
        {
            _pInstance = new BmwFactory {};
        }
        else    //default is Mercedes
        {
            _pInstance = new MercedesFactory {};
        }
    }

    return _pInstance;
}
