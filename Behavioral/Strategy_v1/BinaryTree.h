/**
 * @file        Node.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of of a concrete class BinaryTree.
 * 
 * @version     0.1
 * @date        2023-07-19
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "ISearchAlgo.h"
#include "Node.h"
#include <cstdint>

/**
 * @class   BinaryTree "BinaryTree.h" 
 * @brief   Class that implements a binary tree.
 * 
 * @details This class implement the Facade design pattern.
 *          @n It wraps the Node logic so that the user has access to an easy API.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-19
 * @version 0.1
 */
class BinaryTree
{
public:
    /**
     * @fn      BinaryTree
     * @brief   Construct a new BinaryTree object. 
     */
    BinaryTree();

    /**
     * @fn      ~BinaryTree
     * @brief   Destroy the BinaryTree object.
     */
    ~BinaryTree();

    /**
     * @fn      insert
     * @brief   Inserts in the binary tree a node with the specified value.
     * 
     * @param   value The value to insert in the binary tree.
     */
    void insert(int32_t value);

    /**
     * @fn      find
     * @brief   Checks if the value is present in the binary tree.
     * 
     * @param   value The value to find.
     * @return  true if the value is present, false otherwise.
     */
    bool find(int32_t value);

    /**
     * @fn      setStrategy
     * @brief   Sets the algorithm used to find a value in the tree.
     * 
     * @details This function is part of the "Strategy" design pattern.
     * 
     * @param   algorithm Pointer to an abstract search algorithm for binary tree.
     */
    void setStrategy(ISearchAlgo* algorithm);

private:
    /**
     * @fn      insertNode
     * @brief   Internal recursive function for inserting a node in the tree.
     * 
     * @param   node Pointer to the current node in the tree.
     * @param   value The value to insert.
     * @return  Node* POinter to the current node.
     */
    Node* insertNode(Node* node, int32_t value);

    ISearchAlgo* _algorithm;    /*Pointer to an ISearchAlgo object.*/
    Node* _root;                /*Pointer to the root Node of the tree.*/
};

#endif  //BINARYTREE_H
