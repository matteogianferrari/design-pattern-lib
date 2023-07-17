/**
 * @file        AirConditioner.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class AirConditioner.
 * 
 * @version     0.1
 * @date        2023-07-17
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef AIRCONDITIONER_H
#define AIRCONDITIONER_H

#include "ISmartDevice.h"
#include "IMediator.h"

/**
 * @class   AirConditioner "AirConditioner.h" 
 * @brief   Class that implements an air conditioner smart object.
 * 
 * @details This class derives from the abstract class ISmartObject.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-17
 * @version 0.1
 */
class AirConditioner:
    public ISmartDevice
{
public:
    /**
     * @fn      AirConditioner
     * @brief   Construct a new AirConditioner object. 
     */
    AirConditioner();

    /**
     * @fn      ~AirConditioner
     * @brief   Destroy the AirConditioner object. 
     */  
    ~AirConditioner() override;

    /**
     * @fn      start
     * @brief   Manually starts the air conditioner.
     */
    void start(void);

    /**
     * @fn      setMediator
     * @brief   Sets the system mediator.
     * 
     * @param   mediator Pointer to an IMediator object.
     */
    void setMediator(IMediator* mediator) override;

    /**
     * @fn      toggleState
     * @brief   Toggles the air conditioner state.
     * 
     * @param   state The state to set (true-On / false-Off).
     */
    void toggleState(bool state) override;

    /**
     * @fn      getState
     * @brief   Gets the air conditioner state.
     * 
     * @return  bool The air conditioner state (true-On / false-Off).
     */
    bool getState(void);

private:
    bool _state;            /*State of the object.*/
    IMediator* _mediator;   /*Pointer to the system mediator.*/
};

#endif  //AIRCONDITIONER_H
