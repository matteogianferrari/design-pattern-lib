#include <iostream>
#include "StdOutLogger.h"


StdOutLogger::StdOutLogger():
    _mutex {}
{
}


StdOutLogger::~StdOutLogger()
{
}


void StdOutLogger::logInfo(std::string& data)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Data logged: " << data << std::endl;
}
