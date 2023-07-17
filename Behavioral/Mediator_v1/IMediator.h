/**
 * @file        IMediator.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class IMediator.
 * 
 * @version     0.1
 * @date        2023-07-17
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef IMEDIATOR_H
#define IMEDIATOR_H

class ISmartDevice; //Forward declaration

/**
 * @class   IMediator "IMediator.h" 
 * @brief   Abstract class for a generic smart devices mediator.
 * 
 * @details The implementations of this class must provide function for handling
 *          the devices events.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-17
 * @version 0.1
 */
class IMediator
{
public:
    /**
     * @fn      ~IMediator
     * @brief   Destroy the IMediator object. 
     */
    virtual ~IMediator() {}

    /**
     * @fn      eventHandler
     * @brief   Handles the system logic when a smart device generates an event.
     * 
     * @param   obj Pointer to an ISmartDevice object.
     */
    virtual void eventHandler(ISmartDevice* obj) = 0;
};

#endif  //IMEDIATOR_H
