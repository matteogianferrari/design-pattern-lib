#include "Subtraction.h"


Subtraction::Subtraction(IExpression* left, IExpression* right):
    _left {left},
    _right {right}
{
}


Subtraction::~Subtraction()
{
    delete _left;
    delete _right;
}


int32_t Subtraction::interpret(void)
{
    return _left->interpret() - _right->interpret();
}
