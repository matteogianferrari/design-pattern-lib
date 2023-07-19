#include "DfsRecursive.h"


DfsRecursive::DfsRecursive()
{
}


DfsRecursive::~DfsRecursive()
{
}


bool DfsRecursive::find(Node* root, int32_t value)
{
    //Edge case
    if(!root)
        return false;

    if(root->_value == value)
        return true;
    else if(root->_value > value)
        return find(root->_left, value);
    else
        return find(root->_right, value);
}
