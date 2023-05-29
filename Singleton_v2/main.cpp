/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Singleton" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              @n call the Cache "Singleton" to gain access to the cache memory
 *              and set/get a data.
 *              @n This example shows one implementation of the "Singleton" design pattern.
 *              @n It's suggested to use this method in an external enviroment and to
 *              be used by a third party client.
 * 
 * @note        Use the "Singleton" pattern when:
 *              @n -There must be exactly one instance of a class, and it must be accessible
 *              to clients from a well-known access point.
 *              @n -The sole instance should be extensible by subclassing, and clients
 *              should be able to use an extended instance without modifying their code.
 * 
 * @version     0.1
 * @date        2023-05-26
 * 
 * @copyright   Copyright (c) 2023
 */

#include <iostream>
#include <thread>
#include "Cache.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that sets data in the cache.
 * 
 * @details This function calls the Cache "Singleton" to set data.
 *          @n Used to simulate a threaded system.
 */
void client1(void)
{
    Cache* pCache = Cache::getCache();

    pCache->putData("Balance", 100);
}


/**
 * @fn      client2
 * @brief   Function that simulates a client that gets data from the cache.
 * 
 * @details This function calls the Cache "Singleton" to get data.
 *          @n Used to simulate a threaded system.
 */
void client2(void)
{
    Cache* pCache = Cache::getCache();

    std::cout << "Balance: " << pCache->getData("Balance") << std::endl;
}


int main(int argc, char** argv)
{
    //Threads creation
    std::thread t1 {client1};
    std::thread t2 {client2};

    //Threads execution
    t1.join();
    t2.join();

    return 0;
}
