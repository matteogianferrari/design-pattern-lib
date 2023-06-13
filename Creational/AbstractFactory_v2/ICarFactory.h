/**
 * @file        ICarFactory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ICarFactory.
 * 
 * @version     0.1
 * @date        2023-06-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ICARFACTORY_H
#define ICARFACTORY_H

#include "ISuv.h"
#include "ISportCar.h"

/**
 * @class   ICarFactory "ICarFactory.h" 
 * @brief   Abstract class for a generic car factory.
 * 
 * @details The implementations of this class must provide functions to make an Suv
 *          and a Sport car of a specific family.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-05
 * @version 0.1
 */
class ICarFactory
{
public:
    /**
     * @fn      ~ICarFactory
     * @brief   Destroy the ICarFactory object.
     */
    virtual ~ICarFactory() {}

    /**
     * @fn      makeSuv
     * @brief   Creates and returns an Suv of a specific family.
     * 
     * @details This function is the "factoryMethod" design pattern.
     * 
     * @return  ISuv* A pointer to an ISuv object.
     */
    virtual ISuv* makeSuv(void) = 0;

    /**
     * @fn      makeSportCar
     * @brief   Creates and returns a Sport car of a specific family.
     * 
     * @details This function is the "factoryMethod" design pattern.
     * 
     * @return  ISportCar* A pointer to an ISportCar object.
     */
    virtual ISportCar* makeSportCar(void) = 0;
};

#endif  //ICARTFACTORY_H
