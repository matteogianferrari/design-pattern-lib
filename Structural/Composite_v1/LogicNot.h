/**
 * @file        LogicNot.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class LogicNot.
 * 
 * @version     0.1
 * @date        2023-06-27
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef LOGICNOT_H
#define LOGICNOT_H

#include <mutex>
#include "ILogicBlock.h"

/**
 * @class   LogicNot "LogicNot.h" 
 * @brief   Class that implements a logical Not block.
 * 
 * @details This class derives from the abstract class ILogicalBlock.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-27
 * @version 0.1
 */
class LogicNot:
    public ILogicBlock
{
public:
    /**
     * @fn      LogicNot
     * @brief   Construct a new logical Not block.
     * 
     * @param   inputA Reference to a logical block.
     */
    LogicNot(ILogicBlock& inputA);

    /**
     * @fn      ~LogicNot
     * @brief   Destroy the Logic Not object.
     */
    ~LogicNot() override;

    /**
     * @fn      getResult
     * @brief   Gets the boolean value of the logical Not block.
     * 
     * @return  true if the logical Not input is false, false otherwise. 
     */
    bool getResult(void) override;

private:
    std::mutex _mutex;      /*Mutex for thread safety.*/
    ILogicBlock& _inputA;   /*Reference to logical block as inputA.*/
};

#endif  //LOGICNOT_H
