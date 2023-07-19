#include "BinaryTree.h"


BinaryTree::BinaryTree():
    _algorithm {nullptr},
    _root {nullptr}
{
}


BinaryTree::~BinaryTree()
{
    delete _root;
}


Node* BinaryTree::insertNode(Node* node, int32_t value)
{
    //Root is nullptr (tree is empty)
    if(!node)
        node = new Node {value};
    else
    {
        if(value <= node->_value)
            node->_left = insertNode(node->_left, value);
        else
            node->_right = insertNode(node->_right, value);
    }

    return node;
}


void BinaryTree::insert(int32_t value)
{
    _root = insertNode(_root, value);
}


void BinaryTree::setStrategy(ISearchAlgo* algorithm)
{
    _algorithm = algorithm;
}


bool BinaryTree::find(int32_t value)
{
    if(!_algorithm)
        return false;
    
    return _algorithm->find(_root, value);
}
