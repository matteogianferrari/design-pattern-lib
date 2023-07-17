/**
 * @file        ISmartDevice.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ISmartDevice.
 * 
 * @version     0.1
 * @date        2023-07-17
 * 
 * @copyright   Copyright (c) 2023
 */


#ifndef ISMARTDEVICE_H
#define ISMARTDEVICE_H

#include "IMediator.h"

/**
 * @class   ISmartDevice "ISmartDevice.h" 
 * @brief   Abstract class for a generic smart device.
 * 
 * @details The implementations of this class must provide function for setting
 *          the system mediator and for toggling the device state.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-17
 * @version 0.1
 */
class ISmartDevice
{
public:
    /**
     * @fn      ~ISmartDevice
     * @brief   Destroy the ISmartDevice object. 
     */
    virtual ~ISmartDevice() {}

    /**
     * @fn      setMediator
     * @brief   Sets the system mediator.
     * 
     * @param   mediator Pointer to an IMediator object.
     */
    virtual void setMediator(IMediator* mediator) = 0;

    /**
     * @fn      toggleState
     * @brief   Toggles the device state.
     * 
     * @param   state The state to set (true-On / false-Off).
     */
    virtual void toggleState(bool state) = 0;
};

#endif  //ISMARTDEVICE_H
