#include "Node.h"


Node::Node(int32_t value):
    _value {value},
    _left {nullptr},
    _right {nullptr}
{
}


Node::~Node()
{
    delete _left;
    delete _right;
}
