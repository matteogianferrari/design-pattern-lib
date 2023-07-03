/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Observer" design pattern.
 * @details     This application simulates an enviroment where 2 clients get subscribed to
 *              a temperature logger, and they get notified when the logger records an
 *              updated temperature value.
 *              @n This example shows one implementation of the "Observer" design pattern.
 *              @n This method uses the "Singleton" design pattern to ensure that there is
 *              only one Logger instance.
 * 
 * @note        Use the Observer pattern when:
 *              @n -An abstraction has two aspects, one dependent on the other. Encapsulating
 *              these aspects in separate objects lets you vary and reuse them
 *              independently.
 *              @n -A change to one object requires changing others, and you don't know
 *              how many objects need to be changed.
 *              @n -An object should be able to notify other objects without making
 *              assumptions about who these objects are. In other words, you don't want
 *              these objects tightly coupled.
 * 
 * @version     0.1
 * @date        2023-07-03
 * 
 * @copyright   Copyright (c) 2023
 */

#include "Client.h"
#include "TemperatureLogger.h"


int main(int argc, char** argv)
{
    Client c1 {};
    Client c2 {};

    TemperatureLogger* logger {TemperatureLogger::getTemperatureLogger()};

    logger->subscribe(&c1);
    logger->subscribe(&c2);
    
    logger->setTemperature(34.4);

    logger->unsubscribe(&c1);
    logger->unsubscribe(&c2);

    return 0;
}
