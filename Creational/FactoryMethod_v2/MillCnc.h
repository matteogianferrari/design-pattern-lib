/**
 * @file        MillCnc.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of MillCnc class.
 * 
 * @version     0.1
 * @date        2023-06-01
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef MILLCNC_H
#define MILLCNC_H

#include <mutex>
#include <cstdint>
#include "ICnc.h"

/**
 * @class   MillCnc "MillCnc.h" 
 * @brief   Class that implements a mill Cnc machine.
 * 
 * @details This class derives from the abstract class ICnc.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-01
 * @version 0.1
 */
class MillCnc:
    public ICnc
{
public:
    /**
     * @fn      MillCnc
     * @brief   Construct a new mill Cnc.
     * 
     * @param   axisNumber Number of axis on the mill.
     */
    MillCnc(uint32_t axisNumber);

    /**
     * @fn      ~MillCnc
     * @brief   Destroy the mill Cnc object.
     */
    ~MillCnc() override;

    /**
     * @fn      setPartProgram
     * @brief   Sets the part program on the mill Cnc machine.
     * 
     * @param   partProgramName The name of the part program.
     */
    void setPartProgram(std::string& partProgramName) override;

    /**
     * @fn      startMachining
     * @brief   Starts machining a piece, with a part program, using the mill Cnc machine.
     */
    void startMachining(void) override;

private:
    std::mutex _mutex;              /*Mutex for the thread-safety.*/
    std::string _partProgramName;   /*The part program's name.*/
    uint32_t _axisNumber;           /*Number of axis on the mill.*/
};

#endif  //MILLCNC_H
