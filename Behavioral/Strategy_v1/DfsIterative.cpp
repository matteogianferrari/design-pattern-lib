#include "DfsIterative.h"
#include <stack>


DfsIterative::DfsIterative()
{
}


DfsIterative::~DfsIterative()
{
}


bool DfsIterative::find(Node* root, int32_t value)
{
    std::stack<Node*> stack;
    stack.push(root);

    while(!stack.empty())
    {
        Node* curr = stack.top();
        stack.pop();

        if(curr->_value == value)
            return true;
        
        if(curr->_right != nullptr)
            stack.push(curr->_right);

        if(curr->_left != nullptr)
            stack.push(curr->_left);
    }

    return false;
}
