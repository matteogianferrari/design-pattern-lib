/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Composite" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              update the values of 2 digital signals, and another thread computes the 
 *              output value of the logical network using the "Composite" principle.
 *              @n This example shows one implementation of the "Composite" design pattern.
 * 
 * @note        Use the "Composite" pattern when:
 *              @n -You want to represent part-whole hierarchies of objects.
 *              @n -You want clients to be able to ignore the difference between compositions
 *              of objects and individual objects. Clients will treat all objects in the
 *              composite structure uniformly.
 * 
 * @version     0.1
 * @date        2023-06-27
 * 
 * @copyright   Copyright (c) 2023
 */

#include <iostream>
#include <thread>
#include "ILogicBlock.h"
#include "LogicSignal.h"
#include "LogicAnd.h"
#include "LogicOr.h"
#include "LogicNot.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that updates a digital signal value.
 * 
 * @details Used to simulate a threaded system.
 * 
 * @param   signal Pointer to a digital signal.
 */
void client1(LogicSignal* signal)
{
    std::cout << "Client1 sets signal to true" << std::endl;
    signal->setValue(true);
}


/**
 * @fn      client2
 * @brief   Function that simulates a client that updates a digital signal value.
 * 
 * @details Used to simulate a threaded system.
 * 
 * @param   signal Pointer to a digital signal.
 */
void client2(LogicSignal* signal)
{
    std::cout << "Client2 sets signal to false" << std::endl;
    signal->setValue(false);
}


/**
 * @fn      client3
 * @brief   Function that computes the output of a complex logical network.
 * 
 * @details Used to simulate a threaded system.
 * 
 * @param   logicNetwork Pointer to a logical block.
 */
void client3(ILogicBlock* logicNetwork)
{
    std::cout << "Logic network result: " << logicNetwork->getResult() << std::endl;
}


int main(int, char**){
    LogicSignal s1 {true};
    LogicSignal s2 {true};
    LogicSignal s3 {false};

    LogicAnd b1 {s1, s2};
    LogicOr b2 {b1, s3};
    LogicNot b3 {b2};
    LogicOr b4 {b3, s1};

    //Threads creation
    std::thread t1 {client1, &s1};
    std::thread t2 {client2, &s3};
    std::thread t3 {client3, &b4};

    //Threads execution
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
