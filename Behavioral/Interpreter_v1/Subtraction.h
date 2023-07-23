/**
 * @file        Subtraction.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Subtraction.
 * 
 * @version     0.1
 * @date        2023-07-23
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "IExpression.h"

/**
 * @class   Subtraction "Subtraction.h" 
 * @brief   Class that implements an two expression subtraction.
 * 
 * @details This class derives from the abstract class IExpression.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-23
 * @version 0.1
 */
class Subtraction:
    public IExpression
{
public:
    /**
     * @fn      Subtraction
     * @brief   Construct a new Subtraction object.
     * 
     * @param   left Pointer to an IExpression object.
     * @param   right Pointer to an IExpression object.
     */
    Subtraction(IExpression* left, IExpression* right);

    /**
     * @fn      ~Subtraction
     * @brief   Destroy the Subtraction object.
     */
    ~Subtraction() override;

    /**
     * @fn      interpret
     * @brief   Interprets the subtraction expression and returns its resulting value.
     * 
     * @return  int32_t The result value of the addition. 
     */
    int32_t interpret(void) override;

private:
    IExpression* _left;     /*Pointer to the left IExpression object.*/
    IExpression* _right;    /*Pointer to the right IExpression object.*/
};

#endif  //SUBTRACTION_H
