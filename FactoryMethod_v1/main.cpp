/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Factory Method" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              @n call the Cnc "Factory Method" and perform action with the Cnc machine.
 *              @n This example shows one implementation of the "Factory Method" design pattern.
 *              This method uses an abstract class ICnc without a concrete implementation of
 *              the factory method in it. This function must be implemented in the derived
 *              classes.
 * 
 * @note        Use the "Factory Method" pattern when:
 *              @n -A class can't anticipate the class of objects it must create.
 *              @n -A class wants its subclasses to specify the objects it creates.
 *              @n -Classes delegate responsibility to one of several helper subclasses,
*               and you want to localize the knowledge of which helper subclass is the delegate.
 * 
 * @version     0.1
 * @date        2023-05-29
 * 
 * @copyright   Copyright (c) 2023
 */

#include <thread>
#include "ICnc.h"
#include "ICncFactory.h"
#include "LatheCnc.h"
#include "LatheCncFactory.h"
#include "MillCnc.h"
#include "MillCncFactory.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that creates a cnc machine ad uses it.
 * 
 * @details This function calls the Cnc factory "Factory Method" to create the Cnc machine.
 *          @n Used to simulate a threaded system.
 */
void client1(ICncFactory* pFactory)
{
    std::string partProgramName {"90351209_F1"};

    pFactory->setupCnc(partProgramName);
}


/**
 * @fn      client12
 * @brief   Function that simulates a client that creates a cnc machine ad uses it.
 * 
 * @details This function calls the Cnc factory "Factory Method" to create the Cnc machine.
 *          @n Used to simulate a threaded system.
 */
void client2(ICncFactory* pFactory)
{
    std::string partProgramName {"90010005_F1"};

    pFactory->setupCnc(partProgramName);
}


int main(int, char**) {
    LatheCncFactory latheFactory {};
    MillCncFactory millFactory {};

    std::thread t1 {client1, &latheFactory};
    std::thread t2 {client2, &millFactory};

    t1.join();
    t2.join();

    return 0;
}
