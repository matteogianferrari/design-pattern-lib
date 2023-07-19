/**
 * @file        DfsRecursive.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of of a concrete class DfsRecursive.
 * 
 * @version     0.1
 * @date        2023-07-19
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef DFSRECURSIVE_H
#define DFSRECURSIVE_H

#include "ISearchAlgo.h"

/**
 * @class   DfsRecursive "DfsRecursive.h" 
 * @brief   Class that implements a binary tree search algorithm using recursive DFS.
 * 
 * @details This class derives from the abstract class ISearchAlgo.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-19
 * @version 0.1
 */
class DfsRecursive:
    public ISearchAlgo
{
public:
    /**
     * @fn      DfsRecursive
     * @brief   Construct a new Dfs Recursive object. 
     */
    DfsRecursive();

    /**
     * @fn      ~DfsRecursive
     * @brief   Destroy the DfsRecursive object. 
     */
    ~DfsRecursive() override;

    /**
     * @fn      find
     * @brief   Finds a value in a BinaryTree object using a the recursive DFS algorithm.
     * 
     * @param   root Pointer to the root Node of the BinaryTree.
     * @param   value The value to find.
     * @return  true if present, false otherwise.
     */
    bool find(Node* root, int32_t value) override;
};

#endif  //DFSRECURSIVE_H
