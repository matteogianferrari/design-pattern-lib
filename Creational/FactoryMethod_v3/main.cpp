/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Factory Method" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              @n call the Cnc "Factory Method" and perform action with the Cnc machine.
 *              @n This example shows one implementation of the "Factory Method" design pattern.
 *              @n This method uses a concrete class CncFactory with a template argument that
 *              must be a concrete Cnc class derived from ICnc. The function factoryMethod
 *              creates an object T which is casted to ICnc* internally.
 * 
 * @note        Use the "Factory Method" pattern when:
 *              @n -A class can't anticipate the class of objects it must create.
 *              @n -A class wants its subclasses to specify the objects it creates.
 *              @n -Classes delegate responsibility to one of several helper subclasses,
*               and you want to localize the knowledge of which helper subclass is the delegate.
 * 
 * @version     0.1
 * @date        2023-06-01
 * 
 * @copyright   Copyright (c) 2023
 */

#include <thread>
#include "ICnc.h"
#include "LatheCnc.h"
#include "MillCnc.h"
#include "CncFactory.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that creates a cnc machine ad uses it.
 * 
 * @details This function calls the Cnc factory "Factory Method" to create the Cnc machine.
 *          @n Used to simulate a threaded system.
 * 
 * @param   factory Reference to a template Cnc factory object.
 */
template <class T>
void client1(CncFactory<T>& factory)
{
    std::string partProgramName {"90351053_F1"};

    ICnc* cnc {factory.factoryMethod(1)};
    cnc->setPartProgram(partProgramName);
    cnc->startMachining();

    delete cnc;
}


/**
 * @fn      client2
 * @brief   Function that simulates a client that creates a cnc machine ad uses it.
 * 
 * @details This function calls the Cnc factory "Factory Method" to create the Cnc machine.
 *          @n Used to simulate a threaded system.
 * 
 * @param   factory Reference to a template Cnc factory object.
 */
template <class T>
void client2(CncFactory<T>& factory)
{
    std::string partProgramName {"90010005_F1"};

    ICnc* cnc {factory.factoryMethod(5)};
    cnc->setPartProgram(partProgramName);
    cnc->startMachining();

    delete cnc;
}


int main(int, char**) {
    CncFactory<LatheCnc> latheFactory {};
    CncFactory<MillCnc> millFactory {};

    std::thread t1 {client1<LatheCnc>, std::ref(latheFactory)};
    std::thread t2 {client2<MillCnc>, std::ref(millFactory)};

    t1.join();
    t2.join();

    return 0;
}
