#include <algorithm>
#include <iostream>
#include "TemperatureLogger.h"


//The static member of the TemperatureLogger class need to be initialised outside the constructor
TemperatureLogger* TemperatureLogger::_pInstance {nullptr};
std::mutex TemperatureLogger::_mutex {};


TemperatureLogger* TemperatureLogger::getTemperatureLogger(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    if(!_pInstance)
        _pInstance = new TemperatureLogger {};

    return _pInstance;
}


TemperatureLogger::TemperatureLogger():
    _subscribers {},
    _data {}
{
}


TemperatureLogger::~TemperatureLogger()
{
    delete _pInstance;
}


bool TemperatureLogger::subscribe(Client* client)
{
    std::lock_guard<std::mutex> lock {_mutex};

    //Checks if the client is already subscribed
    if(std::find(_subscribers.begin(), _subscribers.end(), client) != _subscribers.end())
        return false;

    _subscribers.push_back(client);
    
    return true;
}


bool TemperatureLogger::unsubscribe(Client* client)
{
    std::lock_guard<std::mutex> lock {_mutex};

    //Checks if the client is subscribed
    std::vector<Client*>::iterator ref = std::find(_subscribers.begin(), _subscribers.end(), client);
    if(ref == _subscribers.end())
        return false;

    _subscribers.erase(ref);
    
    return true;
}


void TemperatureLogger::setTemperature(float temp)
{
    std::lock_guard<std::mutex> lock {_mutex};

    std::cout << "Data set to " << temp << " degrees." << std::endl;
    _data = temp;
    notifyAll();
}


void TemperatureLogger::notifyAll(void)
{
    for(auto client: _subscribers)
        client->update(_data);
}
