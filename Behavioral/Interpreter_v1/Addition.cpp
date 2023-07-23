#include "Addition.h"


Addition::Addition(IExpression* left, IExpression* right):
    _left {left},
    _right {right}
{
}


Addition::~Addition()
{
    delete _left;
    delete _right;
}


int32_t Addition::interpret(void)
{
    return _left->interpret() + _right->interpret();
}
