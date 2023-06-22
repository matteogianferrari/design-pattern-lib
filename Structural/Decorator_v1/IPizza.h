/**
 * @file        IPizza.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class IPizza.
 * 
 * @version     0.1
 * @date        2023-06-22
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef IPIZZA_H
#define IPIZZA_H

#include "cstdint"

/**
 * @class   IPizza "IPizza.h" 
 * @brief   Abstract class for a generic pizza.
 * 
 * @details The implementations of this class must provide functions for getting
 *          the specific pizza calories.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-22
 * @version 0.1
 */
class IPizza
{
public:
    /**
     * @fn      ~IPizza
     * @brief   Destroy the IPizza object.
     */
    virtual ~IPizza() {}

    /**
     * @fn      getCalories
     * @brief   Gets the pizza calories.
     * 
     * @return  uint32_t Number of calories [Kcal].
     */
    virtual uint32_t getCalories(void) = 0;
};

#endif  //IPIZZA_H
