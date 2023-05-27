/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Singleton" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              @n call the Logging "Singleton" to gain access to the logging system
 *              @n and print a log message.
 *              @n This example shows one implementation of the "Singleton" design pattern.
 *              @n It's suggested to use this method in a controlled enviroment and not to
 *              @n be used by a third party client.
 * 
 * @version     0.1
 * @date        2023-05-25
 * 
 * @copyright   Copyright (c) 2023
 */

#include <iostream>
#include <thread>
#include "ILog.h"
#include "StdLog.h"


/**
 * @fn      getLogging
 * @brief   Gets the Logging object.
 * 
 * @details This function implements the "Singleton" design pattern.
 *          @n This method is suggested to be used in a confined enviroment.
 *          @n It's not the best implementation of a "Singleton" if a third-party developer
 *          @n needs to use this logging system in its project.
 * 
 * @return  ILog* A pointer to an abstract class ILog object.
 */
ILog* getLogging(void)
{
    //Change the static declaration with the derived logging class.
    static StdLog logging {};
    return &logging;
}


/**
 * @fn      client1 
 * @brief   Function that simulates a client that prints a logging message.
 * 
 * @details This function calls the Logging "Singleton" to print a message.
 *          @n Used to simulate a threaded system.
 */
void client1(void)
{
    getLogging()->print("Hi my name is Matteo and this is thread: %d\n", 1);
}


/**
 * @fn      client2
 * @brief   Function that simulates a client that prints a logging message.
 * 
 * @details This function calls the Logging "Singleton" to print a message.
 *          @n Used to simulate a threaded system.
 */
void client2(void)
{
    getLogging()->print("Hi from thread: %d\n", 2);
}


int main(int argc, char** argv) {
    //Threads creation
    std::thread t1 {client1};
    std::thread t2 {client2};

    //Threads execution
    t1.join();
    t2.join();

    return 0;
}
