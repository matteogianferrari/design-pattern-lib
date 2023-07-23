/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "VIsitor" design pattern.
 * @details     This application simulates an enviroment where two clients create a smart
 *              device and execute a function defined in the same visitor object.
 *              @n This example shows one implementation of the "Visitor" design pattern.
 * 
 * @note        Use the "Visitor" pattern when:
 *              @n -An object structure contains many classes of objects with differing
 *              interfaces and you want to perform operations on these objects that depend
 *              on their concrete classes.
 *              @n -Many distinct and unrelated operations need to be performed on objects
 *              in an object structure, and you want to avoid "polluting" their classes with
 *              these operations. Visitor lets you keep related operations together by
 *              defining them in one class.
 *              @n -The classes defining the object structure rarely change, but you often
 *              want to define new operations over the structure.
 * 
 * @version     0.1
 * @date        2023-07-23
 * 
 * @copyright   Copyright (c) 2023
 */

#include "AirConditioner.h"
#include "Thermostat.h"
#include "LoggerVisitor.h"


/**
 * @fn      client1
 * @brief   Function that creates a smart device and execute a function
 *          defined in the visitor.
 * 
 * @param   visitor Pointer to an IVisitor object.
 */
void client1(IVisitor* visitor)
{
    Thermostat t {};

    t.readTemperature(34.f);
    t.acceptVisitor(visitor);
}


/**
 * @fn      client2
 * @brief   Function that creates a smart device and execute a function
 *          defined in the visitor.
 * 
 * @param   visitor Pointer to an IVisitor object.
 */
void client2(IVisitor* visitor)
{
    AirConditioner a {};

    a.setState(true);
    a.acceptVisitor(visitor);
}


int main(int argc, char** argv)
{
    LoggerVisitor logger {};

    client1(&logger);
    client2(&logger);
    
    return 0;
}
