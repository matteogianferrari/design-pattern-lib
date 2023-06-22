/**
 * @file        PizzaDecorator.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class PizzaDecorator.
 * 
 * @version     0.1
 * @date        2023-06-22
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef PIZZADECORATOR_H
#define PIZZADECORATOR_H

#include "IPizza.h"

/**
 * @class   PizzaDecorator "PizzaDecorator.h" 
 * @brief   Abstract class for a pizza decorator.
 * 
 * @details This class derives from the abstract class IPizza.
 *          This abstract class represents the "Decorator" design pattern and
 *          is used for the concrete implementations of pizza decorators.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-22
 * @version 0.1
 */
class PizzaDecorator:
    public IPizza
{
public:
    /**
     * @fn      ~PizzaDecorator
     * @brief   Destroy the Pizza Decorator object.
     */
    virtual ~PizzaDecorator() {}

    /**
     * @fn      getCalories
     * @brief   Gets the pizza calories.
     * 
     * @return  uint32_t Number of calories [Kcal].
     */
    virtual uint32_t getCalories(void) = 0;
};

#endif  //PIZZADECORATOR_H
