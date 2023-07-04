/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Chain of Responsability" design pattern.
 * @details     This application simulates a multi-thread enviroment where 2 threads
 *              request to the company to handle a project. The company checks if these
 *              project can be completed and acts as required. 
 *              @n This example shows one implementation of the "Chain of Responsability"
 *              design pattern.
 * 
 * @note        Use the "Chain of Responsability" pattern when:
 *              @n -More than one object may handle a request, and the handler isn't known
 *              at priori. The handler should be ascertained automatically.
 *              @n -You want to issue a request to one of several objects without specifying
 *              the receiver explicitly.
 *              @n -The set of objects that can handle a request should be specified
 *              dynamically.
 * 
 * @version     0.1
 * @date        2023-07-04
 * 
 * @copyright   Copyright (c) 2023
 */

#include <iostream>
#include <thread>
#include "Company.h"


/**
 * @fn      client 
 * @brief   Function that simulates a client that proposes a project to the company.
 * 
 * @details Used to simulate a threaded system.
 * 
 * @param   requiredWork Required workload to complete the project.
 */
void client(int32_t requiredWork)
{
    if(!Company::getCompany()->handleProject(requiredWork))
        std::cout << "Couldn't secure the project." << std::endl;
    else   
        std::cout << "Project completed." << std::endl;
}


int main(int, char**){
    std::thread t1 {client, 5};
    std::thread t2 {client, 6};

    t1.join();
    t2.join();
    
    return 0;
}
