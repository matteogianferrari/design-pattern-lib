/**
 * @file        LogicalSignal.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class LogicalSignal.
 * 
 * @version     0.1
 * @date        2023-06-27
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef LOGICSIGNAL_H
#define LOGICSIGNAL_H

#include <mutex>
#include "ILogicBlock.h"

/**
 * @class   LogicSignal "LogicSignal.h" 
 * @brief   Class that implements a logical block as a concrete digital signal.
 * 
 * @details This class derives from the abstract class ILogicalBlock.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-27
 * @version 0.1
 */
class LogicSignal:
    public ILogicBlock
{
public:
    /**
     * @fn      LogicSignal
     * @brief   Construct a new signal object.
     *
     * @param   value Logical value of the digital signal.
     */
    LogicSignal(bool value);

    /**
     * @fn      ~LogicSignal
     * @brief   Destroy the Logic Signal object. 
     */
    ~LogicSignal() override;

    /**
     * @fn      getResult
     * @brief   Gets the boolean value of the digital signal.
     * 
     * @return  true if the digital signal is true, false otherwise. 
     */
    bool getResult(void) override;

    /**
     * @fn      setValue
     * @brief   Sets the boolean value of the digital signal.
     * 
     * @param   value Boolean updated value of the digital signal.
     */
    void setValue(bool value);

private:
    std::mutex _mutex;  /*Mutex for thread safety.*/
    bool _value;        /*Boolean value of the digital signal.*/
};

#endif  //LOGICSIGNAL_H
