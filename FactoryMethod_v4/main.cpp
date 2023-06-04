/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Factory Method" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              @n call the drill "Factory Method" and perform action with the drill.
 *              @n This example shows one implementation of the "Factory Method" design pattern.
 *              @n This method uses a concrete class DrillFactory with a concrete implementation
 *              of the factoryMethod, and a derived class BatteryDrillFactory with its own
 *              implementation of factoryMethod that overrides the base function.
 * 
 * @note        Use the "Factory Method" pattern when:
 *              @n -A class can't anticipate the class of objects it must create.
 *              @n -A class wants its subclasses to specify the objects it creates.
 *              @n -Classes delegate responsibility to one of several helper subclasses,
*               and you want to localize the knowledge of which helper subclass is the delegate.
 * 
 * @version     0.1
 * @date        2023-06-04
 * 
 * @copyright   Copyright (c) 2023
 */

#include <thread>
#include "Drill.h"
#include "BatteryDrill.h"
#include "DrillFactory.h"
#include "BatteryDrillFactory.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that creates a drill ad uses it.
 * 
 * @details This function calls the drill factory "Factory Method" to create the drill.
 *          @n Used to simulate a threaded system.
 * 
 * @param   pFactory Pointer to a drill factory object.
 */
void client1(DrillFactory* pFactory)
{
    Drill* drill {pFactory->factoryMethod()};
    drill->use();

    delete drill;
}


/**
 * @fn      client2
 * @brief   Function that simulates a client that creates a drill ad uses it.
 * 
 * @details This function calls the drill factory "Factory Method" to create the drill.
 *          @n Used to simulate a threaded system.
 * 
 * @param   pFactory Pointer to a drill factory object.
 */
void client2(DrillFactory* pFactory)
{
    Drill* drill {pFactory->factoryMethod()};
    drill->use();

    delete drill;
}


int main(int, char**) {
    DrillFactory drillFactory {};
    BatteryDrillFactory batteryDrillFactory {};

    std::thread t1 {client1, &drillFactory};
    std::thread t2 {client2, &batteryDrillFactory};

    t1.join();
    t2.join();

    return 0;
}
