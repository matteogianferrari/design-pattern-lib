/**
 * @file        LatheCnc.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of LatheCnc class.
 * 
 * @version     0.1
 * @date        2023-06-01
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef LATHECNC_H
#define LATHECNC_H

#include <mutex>
#include "ICnc.h"

/**
 * @class   LatheCnc "LatheCnc.h" 
 * @brief   Class that implements a lathe Cnc machine.
 * 
 * @details This class derives from the abstract class ICnc.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-01
 * @version 0.1
 */
class LatheCnc:
    public ICnc
{
public:
    /**
     * @fn      LatheCnc
     * @brief   Construct a new lathe Cnc.
     * 
     * @param   rotaryTurret Flag that indicates if the lathe Cnc
     *          has a rotary turret installed.
     */
    LatheCnc(bool rotaryTurret);

    /**
     * @fn      ~LatheCnc
     * @brief   Destroy the lathe Cnc object.
     */
    ~LatheCnc() override;

    /**
     * @fn      setPartProgram
     * @brief   Sets the part program on the lathe Cnc machine.
     * 
     * @param   partProgramName The name of the part program.
     */
    void setPartProgram(std::string& partProgramName) override;

    /**
     * @fn      startMachining
     * @brief   Starts machining a piece, with a part program, using the lathe Cnc machine.
     */
    void startMachining(void) override;

private:
    std::mutex _mutex;              /*Mutex for the thread-safety.*/
    std::string _partProgramName;   /*The part program's name.*/
    bool _rotaryTurret;             /*Flag that indicates if the lathe Cnc
                                     *has a rotary turret installed.*/
};

#endif  //LATHECNC_H
