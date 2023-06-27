/**
 * @file        LogicAnd.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class LogicAnd.
 * 
 * @version     0.1
 * @date        2023-06-27
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef LOGICAND_H
#define LOGICAND_H

#include <mutex>
#include "ILogicBlock.h"

/**
 * @class   LogicAnd "LogicAnd.h" 
 * @brief   Class that implements a logical And block.
 * 
 * @details This class derives from the abstract class ILogicalBlock.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-27
 * @version 0.1
 */
class LogicAnd:
    public ILogicBlock
{
public:
    /**
     * @fn      LogicAnd
     * @brief   Construct a new logical And block.
     * 
     * @param   inputA Reference to a logical block.
     * @param   inputB Reference to a logical block.
     */
    LogicAnd(ILogicBlock& inputA, ILogicBlock& inputB);
    
    /**
     * @fn      ~LogicAnd
     * @brief   Destroy the Logic And object.
     */
    ~LogicAnd() override;

    /**
     * @fn      getResult
     * @brief   Gets the boolean value of the logical And block.
     * 
     * @return  true if the logical And input are computed as true, false otherwise. 
     */
    bool getResult(void) override;

private:
    std::mutex _mutex;      /*Mutex for thread safety.*/
    ILogicBlock& _inputA;   /*Reference to logical block as inputA.*/
    ILogicBlock& _inputB;   /*Reference to logical block as inputB.*/
};

#endif  //LOGICAND_H
