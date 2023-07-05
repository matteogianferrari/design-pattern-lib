/**
 * @file        ISignal.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ISignal.
 * 
 * @version     0.1
 * @date        2023-07-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ISIGNAL_H
#define ISIGNAL_H

/**
 * @class   ISignal "ISignal.h" 
 * @brief   Abstract class for a generic signal.
 * 
 * @details The implementations of this class must provide function for retrieving,
 *          filtering and processing a specific signal.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-05
 * @version 0.1
 */
class ISignal
{
public:
    /**
     * @fn      ~ISignal
     * @brief   Destroy the ISignal object.
     */
    virtual ~ISignal() {}

    /**
     * @fn      getVoltage
     * @brief   Gets the voltage level of the specific signal.
     * 
     * @return  float The voltage level.
     */
    virtual float getVoltage(void) = 0;

    /**
     * @fn      process
     * @brief   Processes the specified signal.
     * 
     * @return  float The processed voltage level.
     */
    virtual float process(void) = 0;

    /**
     * @fn      filter
     * @brief   Filters the specified signal. 
     * 
     * @return  float The filtered voltage level.
     */
    virtual float filter(void) = 0;
};

#endif  //ISIGNAL_H
