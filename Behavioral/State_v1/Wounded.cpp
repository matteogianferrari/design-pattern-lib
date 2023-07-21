#include "Wounded.h"
#include <iostream>


Wounded::Wounded(float movementVelocity):
    _movementVelocity {movementVelocity}
{
}


Wounded::~Wounded()
{
}


void Wounded::move(void)
{
    std::cout << "The character is moving at " << _movementVelocity << " m/s" << std::endl;
}


void Wounded::printInfo(void)
{
    std::cout << "The character is wounded" << std::endl;
}
