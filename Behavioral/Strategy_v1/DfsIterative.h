/**
 * @file        DfsIterative.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of of a concrete class DfsIterative.
 * 
 * @version     0.1
 * @date        2023-07-19
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef DFSITERATIVE_H
#define DFSITERATIVE_H

#include "ISearchAlgo.h"

/**
 * @class   DfsIterative "DfsIterative.h" 
 * @brief   Class that implements a binary tree search algorithm using iterative DFS.
 * 
 * @details This class derives from the abstract class ISearchAlgo.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-19
 * @version 0.1
 */
class DfsIterative:
    public ISearchAlgo
{
public:
    /**
     * @fn      DfsIterative
     * @brief   Construct a new DfsIterative object. 
     */
    DfsIterative();

    /**
     * @fn      ~DfsIterative
     * @brief   Destroy the DfsIterative object. 
     */
    ~DfsIterative() override;

    /**
     * @fn      find
     * @brief   Finds a value in a BinaryTree object using a the iterative DFS algorithm.
     * 
     * @param   root Pointer to the root Node of the BinaryTree.
     * @param   value The value to find.
     * @return  true if present, false otherwise.
     */
    bool find(Node* root, int32_t value) override;
};

#endif  //DFSITERATIVE_H
