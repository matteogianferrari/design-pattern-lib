/**
 * @file        ICnc.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ICnc.
 * 
 * @version     0.1
 * @date        2023-05-30
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ICNC_H
#define ICNC_H

#include <string>

/**
 * @class   ICnc "ICnc.h" 
 * @brief   Abstract class for a generic Cnc machine.
 * 
 * @details The implementations of this class must provide functions to set the
 *          part program name and to start machining on the related Cnc machine.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-05-30
 * @version 0.1
 */
class ICnc
{
public:
    /**
    * @fn       ~ICnc
     * @brief   Destroy the ICnc object.
     */
    virtual ~ICnc() {}

    /**
     * @fn      setPartProgram
     * @brief   Sets the part program on the specific Cnc machine.
     * 
     * @param   partProgramName The name of the part program.
     */
    virtual void setPartProgram(std::string& partProgramName) = 0;

    /**
     * @fn      startMachining
     * @brief   Starts machining a piece, with a part program, using a specific Cnc machine.
     */
    virtual void startMachining(void) = 0;
};

#endif  //ICNC_H
