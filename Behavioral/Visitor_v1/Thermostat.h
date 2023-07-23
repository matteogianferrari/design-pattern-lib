/**
 * @file        Thermostat.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Thermostat.
 * 
 * @version     0.1
 * @date        2023-07-23
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "ISmartDevice.h"

/**
 * @class   Thermostat "Thermostat.h" 
 * @brief   Class that implements a Thermostat smart object.
 * 
 * @details This class derives from the abstract class ISmartObject.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-23
 * @version 0.1
 */
class Thermostat:
    public ISmartDevice
{
public:
    /**
     * @fn      Thermostat
     * @brief   Construct a new Thermostat object. 
     */
    Thermostat();
    
    /**
     * @fn      ~Thermostat
     * @brief   Destroy the Thermostat object. 
     */
    ~Thermostat() override;

    /**
     * @fn      acceptVisitor
     * @brief   Accepts a specific visitor and execute its function.
     * 
     * @param   visitor Pointer to an IVisitor object.
     */
    void acceptVisitor(IVisitor* visitor) override;

    /**
     * @fn      readTemperature
     * @brief   Reads the temperature from the ambient.
     * 
     * @param   temp The current ambient temperature.
     */
    void readTemperature(float temp);

    /**
     * @fn      getTemperature
     * @brief   Gets the current ambient temperature.
     * 
     * @return  float The current temperature.
     */
    float getTemperature(void);

private:
    float _temperature;     /*Internal variable for the temperature.*/
};

#endif  //THERMOSTAT_H
