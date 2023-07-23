/**
 * @file        IExpression.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class IExpression.
 * 
 * @version     0.1
 * @date        2023-07-23
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include <cstdint>

/**
 * @class   IExpression "IExpression.h" 
 * @brief   Abstract class for a generic expression.
 * 
 * @details The implementations of this class must provide function for interpreting
 *          a specific expression.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-23
 * @version 0.1
 */
class IExpression
{
public:
    /**
     * @fn      ~IExpression
     * @brief   Destroy the IExpression object.
     */
    virtual ~IExpression() {}

    /**
     * @fn      interpret
     * @brief   Interprets the expression and returns its resulting value.
     * 
     * @return  int32_t The result value of the expression. 
     */
    virtual int32_t interpret(void) = 0;
};

#endif  //IEXPRESSION_H
