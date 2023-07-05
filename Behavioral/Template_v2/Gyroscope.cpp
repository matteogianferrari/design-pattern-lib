#include <iostream>
#include "Gyroscope.h"


Gyroscope::Gyroscope():
    Sensor {5.3f, 2.9f}
{
}


Gyroscope::~Gyroscope()
{
}


void Gyroscope::specificActions(void)
{
    std::cout << "Gyroscope specific actions" << std::endl;
}
