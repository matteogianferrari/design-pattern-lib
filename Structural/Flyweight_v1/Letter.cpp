#include "Letter.h"
#include <iostream>


Letter::Letter(const char letter, const char* font):
    _letter {letter},
    _font {font}
{
}


Letter::~Letter()
{
}


void Letter::printInfo(void)
{
    std::cout << "Character: " << _letter << " Font: " << _font << std::endl;
}
