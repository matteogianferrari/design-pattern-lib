/**
 * @file        LogicOr.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class LogicOr.
 * 
 * @version     0.1
 * @date        2023-06-27
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef LOGICOR_H
#define LOGICOR_H

#include <mutex>
#include "ILogicBlock.h"

/**
 * @class   LogicOr "LogicOr.h" 
 * @brief   Class that implements a logical Or block.
 * 
 * @details This class derives from the abstract class ILogicalBlock.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-27
 * @version 0.1
 */
class LogicOr:
    public ILogicBlock
{
public:
    /**
     * @fn      LogicOr
     * @brief   Construct a new logical Or block.
     * 
     * @param   inputA Reference to a logical block.
     * @param   inputB Reference to a logical block.
     */
    LogicOr(ILogicBlock& inputA, ILogicBlock& inputB);

    /**
     * @fn      ~LogicOr
     * @brief   Destroy the Logic Or object.
     */
    ~LogicOr() override;

    /**
     * @fn      getResult
     * @brief   Gets the boolean value of the logical Or block.
     * 
     * @return  true if the logical Or input are computed as true, false otherwise. 
     */
    bool getResult(void) override;

private:
    std::mutex _mutex;      /*Mutex for thread safety.*/
    ILogicBlock& _inputA;   /*Reference to logical block as inputA.*/
    ILogicBlock& _inputB;   /*Reference to logical block as inputB.*/
};

#endif  //LOGICOR_H
