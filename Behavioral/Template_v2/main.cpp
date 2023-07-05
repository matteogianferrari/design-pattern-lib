/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Template" design pattern.
 * @details     This application simulates an enviroment where a client performs actions
 *              on a sensor.
 *              @n This example shows one implementation of the "Template" design pattern.
 *              @n The pattern relies on a base class that implements a common part of 
 *              code in a function. The derived classes don't have to repeat the common code
 *              and can call the base class function. The derived classes need to implement
 *              the specific function that is pure virtual.
 * 
 * @note        Use the "Template" pattern when:
 *              @n -You want to implement the invariant parts of an algorithm once and
 *              leave it up to subclasses to implement the behavior that can vary.
 *              @n -The common behavior among subclasses should be factored and localized
 *              in a common class to avoid code duplication.
 *              @n -You want to control subclasses extensions. You can define a template
 *              method that call "hook" operations at specific points, thereby permitting
 *              extensions only at those points.
 * 
 * @version     0.1
 * @date        2023-07-05
 * 
 * @copyright   Copyright (c) 2023
 */

#include <iostream>
#include "Sensor.h"
#include "Encoder.h"
#include "Gyroscope.h"


/**
 * @fn      client
 * @brief   Function that simulates a client that performs actions on a sensor.
 * 
 * @param   sensor Pointer to an Sensor object.
 */
void client(Sensor* sensor)
{
    std::cout << "Sensor value: " << sensor->getValue() << std::endl;
    sensor->switchState(false);
    std::cout << "Sensor value: " << sensor->getValue() << std::endl;
}


int main(int argc, char** argv)
{
    Encoder s1 {};
    Gyroscope s2 {};

    client(&s1);
    client(&s2);

    return 0;
}
