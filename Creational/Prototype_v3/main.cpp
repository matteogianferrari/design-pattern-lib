/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Prototype" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              @n call the Cell "Singleton" to gain access to a base cell, which is used
 *              to clone it and perform actions.
 *              @n This example shows one implementation of the "Prototype" design pattern.
 *              @n This method uses an abstract class ICell without a concrete implementation
 *              of the clone in it. This function must be implemented in the derived classes.
 * 
 * @note        Use the Prototype pattern when a system should be independent of how its
 *              products are created, composed, and represented; and:
 *              @n -When the classes to instantiate are specified at run-time, for example,
 *              by dynamic loading; or
 *              @n -To avoid building a class hierarchy of factories that parallels the class
 *              hierarchy of products; or
 *              @n -When instances of a class can have one of only a few different combination
 *              of state. It may be more convenient to install a corresponding number of
 *              prototypes and clone them rather than instantiating the class manually,
 *              each time with the appropriate state.
 * 
 * @version     0.1
 * @date        2023-06-12
 * 
 * @copyright   Copyright (c) 2023
 */

#include <iostream>
#include <string>
#include <thread>
#include "CellSingleton.h"
#include "PlantCell.h"
#include "FungiCell.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that creates a cell clone using the "Prototype".
 * 
 * @details This function calls the Cell "Singleton" to get a base cell and clone it.
 *          @n Used to simulate a threaded system.
 */
void client1(void)
{
    std::string cellType {"Plant"};

    ICell* copy = CellSingleton::getCell(cellType)->clone();
    std::cout << *copy;

    delete copy;
}


/**
 * @fn      client2
 * @brief   Function that simulates a client that creates a cell clone using the "Prototype".
 * 
 * @details This function calls the Cell "Singleton" to get a base cell and clone it.
 *          @n Used to simulate a threaded system.
 */
void client2(void)
{
    std::string fungiType {"Fungi"};

    ICell* copy = CellSingleton::getCell(fungiType)->clone();
    std::cout << *copy;

    delete copy;
}


int main(int argc, char** argv)
{
    std::thread t1 {client1};
    std::thread t2 {client2};

    t1.join();
    t2.join();

    return 0;
}
