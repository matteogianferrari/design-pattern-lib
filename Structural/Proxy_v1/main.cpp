/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Proxy" design pattern.
 * @details     This application simulates a multi-thread enviroment where 4 threads
 *              @n call the logging system to log a message.
 *              @n This example shows one implementation of the "Proxy" design pattern.
 *              @n The clients don't know the concrete logging system that are using. The
 *              proxy logging system adds a layer of virtualization and protection to the
 *              real logging system. The concrete logging system and the proxy derive from
 *              the same interface. The proxy checks if the client that want to log a
 *              message into the system has the privileges to do it.
 *              @n The concrete logging system requires a lot of computational power in each
 *              "print" call, so the proxy stores the clients messages into an internal buffer.
 *              @n When the internal buffer reaches the maximum capacity, it's automatically
 *              flushed to the logging system.
 * 
 * @note        Use the "Proxy" pattern when:
 *              @n -You want to provide a local representative for an object in a different
 *              address space (remote proxy).
 *              @n -You want to create expensive objects on demand (virtual proxy).
 *              @n -You want to control access to the original object. Protection proxie 
 *              are useful when objects should have different access rights (protection proxy). 
 * 
 * @version     0.1
 * @date        2023-06-26
 * 
 * @copyright   Copyright (c) 2023
 */

#include <thread>
#include "ILogger.h"
#include "StdLogger.h"
#include "LoggerProxy.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that tries to log a messagge to a logging system.
 * 
 * @details This function in reality is calling the proxy logging system, but the client
 *          doesn't know it.
 *          @n Used to simulate a threaded system.
 */
void client1(ILogger* pLogger)
{
    std::string clientId {"Friendly client"};
    std::string message {"I don't know if this is the real logger"};

    pLogger->print(clientId, message);
}


/**
 * @fn      client2
 * @brief   Function that simulates a client that tries to log a messagge to a logging system.
 * 
 * @details This function in reality is calling the proxy logging system and the client
 *          knows it.
 *          @n Used to simulate a threaded system.
 */
void client2(ILogger* pLogger)
{
    std::string clientId {"Friendly client"};
    std::string message {"I know that this isn't a real logger"};

    pLogger->print(clientId, message);
}


/**
 * @fn      client3
 * @brief   Function that simulates a client that tries to log a messagge to a logging system.
 * 
 * @details This function in reality is calling the proxy logging system, but the client
 *          doesn't know it and doesn't have the privileges to do it.
 *          @n Used to simulate a threaded system.
 */
void client3(ILogger* pLogger)
{
    std::string clientId {"Stupid client"};
    std::string message {"I want to log info"};

    pLogger->print(clientId, message);
}


/**
 * @fn      client4
 * @brief   Function that simulates a client that tries to log a messagge to a logging system.
 * 
 * @details This function in reality is calling the proxy logging system, but the client
 *          doesn't know it.
 *          @n Used to simulate a threaded system.
 */
void client4(ILogger* pLogger)
{
    std::string clientId {"Malicious client"};
    std::string message {"I want to log bad info but I don't know that the logger is protected"};

    pLogger->print(clientId, message);
}


int main(int, char**){
    LoggerProxy logger {new StdLogger {}};

    //Threads creation
    std::thread t1 {client1, &logger};
    std::thread t2 {client2, &logger};
    std::thread t3 {client3, &logger};
    std::thread t4 {client4, &logger};

    //Threads execution
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
