/**
 * @file        ICar.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ICar.
 * 
 * @version     0.1
 * @date        2023-06-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ICAR_H
#define ICAR_H

/**
 * @class   ICar "ICar.h" 
 * @brief   Abstract class for a generic car.
 * 
 * @details The implementations of this class must provide functions to start and
 *          to drive the related car.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-05
 * @version 0.1
 */
class ICar
{
public:
    /**
     * @fn      ~ICar
     * @brief   Destroy the ICar object.
     */
    virtual ~ICar() {}

    /**
     * @fn      start
     * @brief   Starts the car.
     */
    virtual void start(void) = 0;

    /**
     * @fn      drive
     * @brief   Starts driving the car.
     */
    virtual void drive(void) = 0;
};

#endif  //ICAR_H
