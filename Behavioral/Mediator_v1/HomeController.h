/**
 * @file        HomeController.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class HomeController.
 * 
 * @version     0.1
 * @date        2023-07-17
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "IMediator.h"
#include "ISmartDevice.h"
#include "Thermostat.h"
#include "AirConditioner.h"

/**
 * @class   Thermostat "Thermostat.h" 
 * @brief   Class that implements a smart home controller object.
 * 
 * @details This class derives from the abstract class IMediator.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-17
 * @version 0.1
 */
class HomeController:
    public IMediator
{
public:
    /**
     * @fn      HomeController
     * @brief   Construct a new Home Controller object
     * 
     * @param   sensor Pointer to a Thermostat object.
     * @param   conditioner Pointer to an AirConditioner object.
     */
    HomeController(Thermostat* sensor, AirConditioner* conditioner);

    /**
     * @brief Destroy the HomeController object.
     */
    ~HomeController() override;

    /**
     * @fn      eventHandler
     * @brief   Handles the system logic when a smart device generates an event.
     * 
     * @param   obj Pointer to an ISmartDevice object.
     */
    void eventHandler(ISmartDevice* obj) override;

private:
    Thermostat* _sensor;            /*Pointer to a Thermostat object.*/
    AirConditioner* _conditioner;   /*Pointer to an AirConditioner object.*/
};

#endif  //HOMECONTROLLER_H
