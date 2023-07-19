/**
 * @file        Node.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of of a concrete class Node.
 * 
 * @version     0.1
 * @date        2023-07-19
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef NODE_H
#define NODE_H

#include <cstdint>

/**
 * @class   Node "Node.h" 
 * @brief   Class that implements a binary tree node.
 * 
 * @details This class declares its attributes public to allow the BonaryTree object,
 *          the abstract class ISearchAlgo and the derived class easily access.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-19
 * @version 0.1
 */
class Node
{
public:
    /**
     * @fn      Node
     * @brief   Construct a new Node object.
     * 
     * @param   value The node value.
     */
    Node(int32_t value);

    /**
     * @fn      ~Node
     * @brief   Destroy the Node object. 
     */
    ~Node();

    int32_t _value; /*Node value.*/
    Node* _left;    /*Pointer to the right Node branch.*/
    Node* _right;   /*Pointer to the left Node branch.*/
};

#endif  //NODE_H
