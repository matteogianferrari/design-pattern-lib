#include <iostream>
#include "Cache.h"


Cache::Cache():
    _hashMap {},
    _mutex {}
{
}


Cache::~Cache()
{
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
