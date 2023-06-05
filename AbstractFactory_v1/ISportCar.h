/**
 * @file        ISportCar.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ISportCar.
 * 
 * @version     0.1
 * @date        2023-06-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ISPORTCAR_H
#define ISPORTCAR_H

#include "ICar.h"

/**
 * @class   ISportCar "ISportCar.h" 
 * @brief   Abstract class for a generic sport car.
 * 
 * @details This class derives from the abstract class ICar.
 *          @n The implementations of this class must provide functions to
 *          start and to drive the related car.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-05
 * @version 0.1
 */
class ISportCar:
    public ICar
{
public:
    /**
     * @fn      ~ISportCar
     * @brief   Destroy the ISportCar object.
     */
    virtual ~ISportCar() {}

    /**
     * @fn      start
     * @brief   Starts the sport car.
     */
    virtual void start(void) = 0;

    /**
     * @fn      drive
     * @brief   Starts driving the sport car.
     */
    virtual void drive(void) = 0;
};

#endif  //ISPORTCAR_H
