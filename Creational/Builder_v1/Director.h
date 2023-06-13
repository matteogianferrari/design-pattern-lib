/**
 * @file        Director.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Director.
 * 
 * @version     0.1
 * @date        2023-06-13
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <mutex>
#include "ICarBuilder.h"

/**
 * @class   Director "Director.h" 
 * @brief   Class that implements a builder director.
 * 
 * @details This class implements function for building different types of cars.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-13
 * @version 0.1
 */
class Director
{
public:
    /**
     * @fn      Director
     * @brief   Construct a new Director object.
     * 
     * @param   builder Pointer to a Car builder object.
     */
    Director(ICarBuilder* builder);

    /**
     * @fn ~Director
     * @brief Destroy the Director object.
     */
    ~Director();

    /**
     * @fn      setBuilder
     * @brief   Sets the Builder object.
     * 
     * @param   builder Pointer to a Car builder object. 
     */
    void setBuilder(ICarBuilder* builder);

    /**
     * @fn      buildSportCar
     * @brief   Builds a sport car using the specific car brand builder.
     */
    void buildSportCar(void);

    /**
     * @fn      buildRaceCar
     * @brief   Builds a race car using the specific car brand builder.
     */
    void buildRaceCar(void);

private:
    std::mutex _mutex;      /*Mutex for thread safety.*/
    ICarBuilder* _builder;  /*Pointer to a Car builder object.*/
};

#endif  //DIRECTOR_H
