#include <iostream>
#include "Drill.h"


Drill::Drill():
    _mutex {}
{
}


Drill::~Drill()
{
}


void Drill::use(void)
{
    std::lock_guard<std::mutex> lock {_mutex};
    std::cout << "Using the drill" << std::endl;
}
