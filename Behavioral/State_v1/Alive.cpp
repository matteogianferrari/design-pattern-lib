#include "Alive.h"
#include <iostream>


Alive::Alive(float movementVelocity):
    _movementVelocity {movementVelocity}
{
}


Alive::~Alive()
{
}


void Alive::move(void)
{
    std::cout << "The character is moving at " << _movementVelocity << " m/s" << std::endl;
}


void Alive::printInfo(void)
{
    std::cout << "The character is alive" << std::endl;
}
