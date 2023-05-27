/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Singleton" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              @n call the Cache "Singleton" to gain access to the cache memory
 *              @n and set/get a data.
 *              @n This example shows one implementation of the "Singleton" design pattern.
 *              @n It's suggested to use this method in an external enviroment and to
 *              @n be used by a third party client.
 * 
 *
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


int main()
{
    //Threads creation
    std::thread t1 {client1};
    std::thread t2 {client2};

    //Threads execution
    t1.join();
    t2.join();

    return 0;
}
