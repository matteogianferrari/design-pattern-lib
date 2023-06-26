#include <iostream>
#include "StdLogger.h"


StdLogger::StdLogger():
    _mutex {}
{
}


StdLogger::~StdLogger()
{
}


bool StdLogger::print(std::string& id, std::string& message)
{
    std::lock_guard<std::mutex> lock {_mutex};

    std::cout << "Client '" << id << "': --> " << message << std::endl;
    return true;
}
