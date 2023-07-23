#include "Number.h"


Number::Number(int32_t value):
    _value {value}
{
}


Number::~Number()
{
}


int32_t Number::interpret(void)
{
    return _value;
}
