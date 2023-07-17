/**
 * @file        Thermostat.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Thermostat.
 * 
 * @version     0.1
 * @date        2023-07-17
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "ISmartDevice.h"
#include "IMediator.h"

/**
 * @class   Thermostat "Thermostat.h" 
 * @brief   Class that implements a Thermostat smart object.
 * 
 * @details This class derives from the abstract class ISmartObject.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-17
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
     * @fn      setMediator
     * @brief   Sets the system mediator.
     * 
     * @param   mediator Pointer to an IMediator object.
     */
    void setMediator(IMediator* mediator) override;

    /**
     * @fn      toggleState
     * @brief   Toggles the thermostat state.
     * 
     * @param   state The state to set (true-On / false-Off).
     */
    void toggleState(bool state) override;

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
    bool _state;            /*State of the object.*/
    float _temperature;     /*Internal variable for the temperature.*/
    IMediator* _mediator;   /*Pointer to the system mediator.*/
};

#endif  //THERMOSTAT_H
