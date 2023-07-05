/**
 * @file        CmosSignal.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class CmosSignal.
 * 
 * @version     0.1
 * @date        2023-07-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef CMOSSIGNAL_H
#define CMOSSIGNAL_H

#include "ISignal.h"

#define MAX_CMOS_VOLTAGE 3.3f   /*Maximum voltage value for a cmos signal.*/

/**
 * @class   CmosSignal "CmosSignal.h" 
 * @brief   Class that implements a cmos signal.
 * 
 * @details This class derives from the abstract class ISignal.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-05
 * @version 0.1
 */
class CmosSignal:
    public ISignal
{
public:
    /**
     * @fn      CmosSignal
     * @brief   Construct a new Cmos Signal object.
     * 
     * @param   voltage Voltage level of the signal.
     */
    CmosSignal(float voltage);

    /**
     * @fn      ~CmosSignal
     * @brief   Destroy the Cmos Signal object.
     */
    ~CmosSignal() override;

    /**
     * @fn      getVoltage
     * @brief   Gets the voltage level of the cmos signal.
     * 
     * @return  float The cmos voltage level.
     */
    float getVoltage(void) override;

    /**
     * @fn      process
     * @brief   Processes the cmos signal.
     * 
     * @return  float The processed cmos voltage level.
     */
    float process(void) override;

    /**
     * @fn      filter
     * @brief   Filters the cmos signal. 
     * 
     * @return  float The filtered cmos voltage level.
     */
    float filter(void) override;

private:
    float _voltage; /*Internal voltage value.*/
};

#endif  //CMOSSIGNAL_H
