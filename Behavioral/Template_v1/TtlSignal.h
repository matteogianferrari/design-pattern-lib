/**
 * @file        TtlSignal.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class TtlSignal.
 * 
 * @version     0.1
 * @date        2023-07-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef TTLSIGNAL_H
#define TTLSIGNAL_H

#include "ISignal.h"

#define MAX_TTL_VOLTAGE 5.f /*Maximum voltage value for a ttl signal.*/

/**
 * @class   TtlSignal "TtlSignal.h" 
 * @brief   Class that implements a ttl signal.
 * 
 * @details This class derives from the abstract class ISignal.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-05
 * @version 0.1
 */
class TtlSignal:
    public ISignal
{
public:
    /**
     * @fn      TtlSignal
     * @brief   Construct a new Ttl Signal object.
     * 
     * @param   voltage Voltage level of the signal.
     */
    TtlSignal(float voltage);

    /**
     * @fn      ~TtlSignal
     * @brief   Destroy the TtlSignal object.
     */
    ~TtlSignal() override;

    /**
     * @fn      getVoltage
     * @brief   Gets the voltage level of the ttl signal.
     * 
     * @return  float The ttl voltage level.
     */
    float getVoltage(void) override;

    /**
     * @fn      process
     * @brief   Processes the ttl signal.
     * 
     * @return  float The processed ttl voltage level.
     */
    float process(void) override;

    /**
     * @fn      filter
     * @brief   Filters the ttl signal. 
     * 
     * @return  float The filtered ttl voltage level.
     */
    float filter(void) override;

private:
    float _voltage; /*Internal voltage value.*/
};

#endif  //TTLSIGNAL_H
