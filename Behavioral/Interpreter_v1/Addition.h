/**
 * @file        Addition.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Addition.
 * 
 * @version     0.1
 * @date        2023-07-23
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ADDITION_H
#define ADDITION_H

#include "IExpression.h"

/**
 * @class   Addition "Addition.h" 
 * @brief   Class that implements an two expression addition.
 * 
 * @details This class derives from the abstract class IExpression.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-23
 * @version 0.1
 */
class Addition:
    public IExpression
{
public:
    /**
     * @fn      Addition
     * @brief   Construct a new Addition object..
     * 
     * @param   left Pointer to an IExpression object.
     * @param   right Pointer to an IExpression object.
     */
    Addition(IExpression* left, IExpression* right);

    /**
     * @fn      ~Addition
     * @brief   Destroy the Addition object.
     */
    ~Addition() override;

    /**
     * @fn      interpret
     * @brief   Interprets the addition expression and returns its resulting value.
     * 
     * @return  int32_t The result value of the addition. 
     */
    int32_t interpret(void) override;

private:
    IExpression* _left;     /*Pointer to the left IExpression object.*/
    IExpression* _right;    /*Pointer to the right IExpression object.*/
};

#endif  //ADDITION_H
