/**
 * @file        ISuv.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ISuv.
 * 
 * @version     0.1
 * @date        2023-06-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ISUV_H
#define ISUV_H

#include "ICar.h"

/**
 * @class   ISuv "ISuv.h" 
 * @brief   Abstract class for a generic suv.
 * 
 * @details This class derives from the abstract class ICar.
 *          @n The implementations of this class must provide functions to
 *          start and to drive the related car.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-05
 * @version 0.1
 */
class ISuv:
    public ICar
{
public:
    /**
     * @fn      ~ISuv
     * @brief   Destroy the ISuv object.
     */
    virtual ~ISuv() {}

    /**
     * @fn      start
     * @brief   Starts the suv.
     */
    virtual void start(void) = 0;

    /**
     * @fn      drive
     * @brief   Starts driving the suv.
     */
    virtual void drive(void) = 0;
};

#endif  //ISUV_H
