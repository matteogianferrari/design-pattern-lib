/**
 * @file        ILogicBlock.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ILogicBlock.
 * 
 * @version     0.1
 * @date        2023-06-27
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ILOGICBLOCK_H
#define ILOGICBLOCK_H

#include <cstdint>

/**
 * @class   ILogicBlock "ILogicBlock.h" 
 * @brief   Abstract class for a generic logical block.
 * 
 * @details The implementations of this class must provide function for getting
 *          the boolean value obtained as a result from the specific logical block.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-27
 * @version 0.1
 */
class ILogicBlock
{
public:
    /**
     * @fn      ~ILogicBlock
     * @brief   Destroy the ILogicBlock object.
     */
    virtual ~ILogicBlock() {}

    /**
     * @fn      getResult
     * @brief   Get the boolean result of the logical block.
     * 
     * @return  true if the logical block computation is true, false otherwise. 
     */
    virtual bool getResult(void) = 0;
};

#endif  //ILOGICBLOCK_H
