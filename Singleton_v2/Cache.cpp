#include "Cache.h"
#include <iostream>

//The static member of the Cache class need to be initialised outside the constructor
std::mutex Cache::_mutex {};
Cache* Cache::_pInstance {nullptr};


Cache::Cache():
    _hashMap {}
{
}

Cache::~Cache()
{
    delete _pInstance;
}


Cache* Cache::getCache()
{
    //Locks the mutex
    std::lock_guard<std::mutex> lock {_mutex};

    if(!_pInstance)
    {
        _pInstance = new Cache {};
    }
    return _pInstance;
}


void Cache::putData(std::string key, int32_t value)
{
    //Locks the mutex
    std::lock_guard<std::mutex> lock {_mutex};
    _hashMap[key] = value;
}


int32_t Cache::getData(std::string key)
{
    //Locks the mutex
    std::lock_guard<std::mutex> lock {_mutex};
    return _hashMap[key];
}
