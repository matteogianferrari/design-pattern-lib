#include <iostream>
#include "Client.h"


Client::Client():
    _temperature {}
{
}


Client::~Client()
{
}


void Client::update(float value)
{   
    std::cout << "Received an update: " << value << " degrees." << std::endl;
    _temperature = value;
}
