#include <iostream>
#include "Encoder.h"


Encoder::Encoder():
    Sensor {1.2f, 1.4f}
{
}


Encoder::~Encoder()
{
}


void Encoder::specificActions(void)
{
    std::cout << "Encoder specific actions" << std::endl;
}
