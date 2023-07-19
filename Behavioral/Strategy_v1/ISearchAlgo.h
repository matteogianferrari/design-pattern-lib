/**
 * @file        ISearchAlgo.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ISearchAlgo.
 * 
 * @version     0.1
 * @date        2023-07-19
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ISEARCHALGO_H
#define ISEARCHALGO_H

#include "Node.h"
#include <cstdint>

/**
 * @class   ISearchAlgo "ISearchAlgo.h" 
 * @brief   Abstract class for a generic binary tree search algorithm.
 * 
 * @details The implementations of this class must provide function for finding
 *          a value using a specific algorithm.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-19
 * @version 0.1
 */
class ISearchAlgo
{
public:
    /**
     * @fn      ~ISearchAlgo
     * @brief   Destroy the ISearchAlgo object. 
     */
    virtual ~ISearchAlgo() {}

    /**
     * @fn      find
     * @brief   Finds a value in a BinaryTree object using a specific algorithm.
     * 
     * @param   root Pointer to the root Node of the BinaryTree.
     * @param   value The value to find.
     * @return  true if present, false otherwise.
     */
    virtual bool find(Node* root, int32_t value) = 0;
};

#endif  //ISEARCHALGO_H
