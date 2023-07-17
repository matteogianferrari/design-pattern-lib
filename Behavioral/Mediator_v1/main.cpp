/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Mediator" design pattern.
 * @details     This application simulates an enviroment where a client set the temperature
 *              in the home, and the system reacts to the temperature changes. 
 *              @n This example shows one implementation of the "Mediator" design pattern.
 * 
 * @note        Use the "Mediator" pattern when:
 *              @n -A set of objects communicate in well-defined but complex ways.
 *              The resulting interdependencies are unstructured and difficult to understand.
 *              @n -Reusing an object is difficult because it refers to and communicates
 *              with many other objects.
 *              @n -A behavior that's distributed between several classes should be
 *              customizable without a lot of subclassing.
 * 
 * @version     0.1
 * @date        2023-07-17
 * 
 * @copyright   Copyright (c) 2023
 */

#include "Thermostat.h"
#include "AirConditioner.h"
#include "HomeController.h"


/**
 * @fn      client 
 * @brief   Function that simulates an home enviroment.
 */
void client(void)
{
    Thermostat t {};
    AirConditioner a {};

    HomeController smartHome {&t, &a};

    t.setMediator(&smartHome);
    a.setMediator(&smartHome);

    a.start();

    t.readTemperature(19.4f);
    t.readTemperature(26.f);
    t.readTemperature(24.1f);
}


int main(int argc, char** argv)
{
    client();

    return 0;
}
