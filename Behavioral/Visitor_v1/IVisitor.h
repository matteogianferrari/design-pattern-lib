/**
 * @file        IVisitor.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class IVisitor.
 * 
 * @version     0.1
 * @date        2023-07-23
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef IVISITOR_H
#define IVISITOR_H

class Thermostat;       /*Forward declaration of Thermostat class.*/
class AirConditioner;   /*Forward declaration of AirConditioner class.*/

/**
 * @class   IVisitor "IVisitor.h" 
 * @brief   Abstract class for a generic visitor.
 * 
 * @details The implementations of this class must provide function for executing
 *          a specific function for every smart device in the system.
 *          @n This function that has to be executed must be equal for every object
 *          (example: a logging function that varies based on the object).
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-23
 * @version 0.1
 */
class IVisitor
{
public:
    /**
     * @fn      ~IVisitor
     * @brief   Destroy the IVisitor object.
     */
    virtual ~IVisitor() {}

    /**
     * @fn      runThermostatOperation
     * @brief   Executes the specific function for the Thermostat object.
     * 
     * @param   obj Pointer to a Thermostat object.
     */
    virtual void runThermostatOperation(Thermostat* obj) = 0;

    /**
     * @fn      runAirConditionerOperation
     * @brief   Executes the specific function for the AirConditioner object.
     * 
     * @param   obj Pointer to a AirConditioner object.
     */
    virtual void runAirConditionerOperation(AirConditioner* obj) = 0;
};

#endif  //IVISITOR_H
