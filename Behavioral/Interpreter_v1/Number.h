/**
 * @file        Number.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Number.
 * 
 * @version     0.1
 * @date        2023-07-23
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef NUMBER_H
#define NUMBER_H

#include "IExpression.h"

/**
 * @class   Number "Number.h" 
 * @brief   Class that implements an expression that represents a number.
 * 
 * @details This class derives from the abstract class IExpression.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-23
 * @version 0.1
 */
class Number:
    public IExpression
{
public:
    /**
     * @fn      Number
     * @brief   Construct a new Number object.
     * 
     * @param   value The numeric value.
     */
    Number(int32_t value);
    
    /**
     * @fn      ~Number
     * @brief   Destroy the Number object.
     */
    ~Number() override;

    /**
     * @fn      interpret
     * @brief   Interprets the numeric expression and returns its resulting value.
     * 
     * @return  int32_t The result value of the expression. 
     */
    int32_t interpret(void) override;

private:
    int32_t _value;
};

#endif  //NUMBER_H
