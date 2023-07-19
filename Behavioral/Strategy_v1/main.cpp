/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Strategy" design pattern.
 * @details     This application simulates an enviroment where two clients set the 
 *              algorithm used to search a value into a binary tree. The algorithm in the
 *              BinaryTree object can be changed at runtime to handle the space/time 
 *              complexity trade-off. 
 *              @n This example shows one implementation of the "Strategy" design pattern.
 * 
 * @note        Use the "Strategy" pattern when:
 *              @n -Many related classes differ only in their behavior. Strategies provide
 *              a way to configure a class with one of many behaviors.
 *              @n -You need different variants of an algorithm (different space/time
 *              trade-offs).
 *              @n -An algorithm uses data that clients shouldn't know about.
 *              @n -A class defines many behaviors, and these appear as multiple conditional
 *              statements in its operations. Instead of many conditionals, move related
 *              conditional branches into their own Strategy class.
 * 
 * @version     0.1
 * @date        2023-07-19
 * 
 * @copyright   Copyright (c) 2023
 */

#include "BinaryTree.h"
#include "DfsIterative.h"
#include "DfsRecursive.h"
#include <iostream>


/**
 * @fn      client1
 * @brief   Client that creates a specific algorithm and searches a value in the binary tree.
 * 
 * @param   tree Pointer to a BinaryTree object.
 */
void client1(BinaryTree* tree)
{
    DfsRecursive* algo {new DfsRecursive {}};

    tree->setStrategy(algo);
    std::cout << "Find 700 using recursive DFS: " << tree->find(700) << std::endl;

    delete algo;
}


/**
 * @fn      client2
 * @brief   Client that creates a specific algorithm and searches a value in the binary tree.
 * 
 * @param   tree Pointer to a BinaryTree object.
 */
void client2(BinaryTree* tree)
{
    DfsIterative* algo {new DfsIterative {}};

    tree->setStrategy(algo);
    std::cout << "Find 60 using iterative DFS: " << tree->find(60) << std::endl;

    delete algo;
}


int main(int argc, char** argv)
{
    BinaryTree* tree {new BinaryTree {}};
    
    tree->insert(1);
    tree->insert(60);
    tree->insert(-12);
    tree->insert(5);
    tree->insert(-36);

    client1(tree);
    client2(tree);

    delete tree;

    return 0;
}