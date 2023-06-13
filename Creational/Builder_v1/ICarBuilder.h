/**
 * @file        ICarBuilder.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ICarBuilder.
 * 
 * @version     0.1
 * @date        2023-06-13
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ICARBUILDER_H
#define ICARBUILDER_H

#include "Car.h"

/**
 * @class   ICarBuilder "ICarBuilder.h" 
 * @brief   Abstract class for a generic car builder.
 * 
 * @details The implementations of this class must provide functions to produce
 *          a component specific of a concrete car builder.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-13
 * @version 0.1
 */
class ICarBuilder
{
public:
    /**
     * @fn      ~ICarBuilder
     * @brief   Destroy the ICarBuilder object.
     */
    virtual ~ICarBuilder() {}

    /**
     * @fn      produceWheels
     * @brief   Produces a wheels component and adds it to the car.
     */
    virtual void produceWheels(void) = 0;

    /**
     * @fn      produceBrakes
     * @brief   Produces a brakes component and adds it to the car.
     */
    virtual void produceBrakes(void) = 0;

    /**
     * @fn      produceEngine
     * @brief   Produces an engine component and adds it to the car.
     */
    virtual void produceEngine(void) = 0;

    /**
     * @fn      produceTransmission
     * @brief   Produces a transmission component and adds it to the car.
     */
    virtual void produceTransmission(void) = 0;

    /**
     * @fn      produceInterios
     * @brief   Produces an interiors component and adds it to the car.
     */
    virtual void produceInterios(void) = 0;

    /**
     * @fn      getCar
     * @brief   Gets the Car object.
     * 
     * @details This function returns to the client the built car, and resets
     *          the internal car object to be rebuilt.
     * 
     * @return  Car* Pointer to a Car object.
     */
    virtual Car* getCar(void) = 0;
};

#endif  //ICARBUILDER_H
