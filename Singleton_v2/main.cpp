/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Singleton" design pattern.
 * @details     This application simulates a threaded enviroment where 2 threads
 *              @n call the Logging "Singleton" to gain access to the logging system
 *              @n and print a log message.
 *              @n This example shows one implementation of the "Singleton" design pattern.
 *              @n It's suggested to use this method in an external enviroment and to
 *              @n be used by a third party client.
 * 
 * @version     0.1
 * @date        2023-05-26
 * 
 * @copyright   Copyright (c) 2023
 */

#include "Cache.h"
#include <iostream>
#include <thread>


void client1(void)
{
    Cache* pCache = Cache::getCache();

    pCache->putData("Balance", 100);
}


void client2(void)
{
    Cache* pCache = Cache::getCache();

    std::cout << "Balance: " << pCache->getData("Balance") << std::endl;
}


int main()
{
    //std::thread t1 {client1};
    std::thread t2 {client2};

    //t1.join();
    t2.join();

    return 0;
}