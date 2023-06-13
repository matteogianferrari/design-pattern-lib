/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Prototype" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              @n call the cells's clone function and perform actions with the new copies.
 *              @n This example shows one implementation of the "Prototype" design pattern.
 *              @n This method uses an abstract class ICell without a concrete implementation
 *              of the clone in it. This function must be implemented in the derived classes.
 *              @n The clone function allow the client's code to make a deep copy of a
 *              concrete class without knowing the actual implementation or its attributes.
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
 * @date        2023-06-08
 * 
 * @copyright   Copyright (c) 2023
 */

#include <iostream>
#include <string>
#include <thread>
#include "PlantCell.h"
#include "FungiCell.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that creates a clone of the cell.
 * 
 * @details This function calls the clone function to create a deep copy of the cell.
 *          @n Used to simulate a threaded system.
 * 
 * @param   pCell Pointer to a concrete plant cell object.
 */
void client1(PlantCell* pCell)
{
    ICell* copy = pCell->clone();
    std::cout << *copy;

    pCell->photosyntesis();

    delete copy;
}


/**
 * @fn      client2
 * @brief   Function that simulates a client that creates a clone of the cell.
 * 
 * @details This function calls the clone function to create a deep copy of the cell.
 *          @n Used to simulate a threaded system.
 * 
 * @param   pCell Pointer to a concrete fungi cell object.
 */
void client2(FungiCell* pCell)
{
    ICell* copy = pCell->clone();
    std::cout << *copy;

    pCell->absorb();
    
    delete copy;
}


int main(int argc, char** argv)
{
    std::string plantName {"Abete"};
    std::string fungiName {"Porcino"};

    PlantCell plantCell {plantName};
    FungiCell fungiCell {fungiName};

    std::thread t1 {client1, &plantCell};
    std::thread t2 {client2, &fungiCell};

    t1.join();
    t2.join();

    return 0;
}
