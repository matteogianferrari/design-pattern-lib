/**
 * @file        Gyroscope.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Gyroscope.
 * 
 * @version     0.1
 * @date        2023-07-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef GYROSCOPE_H
#define GYROSCOPE_H

#include "Sensor.h"

/**
 * @class   Gyroscope "Gyroscope.h" 
 * @brief   Concrete class for a gyroscope.
 * 
 * @details This class derives from the abstract class Sensor.
 *          
 * @author  Matteo Gianferrari
 * @date    2023-07-05
 * @version 0.1
 */
class Gyroscope:
    public Sensor
{
public:
    /**
     * @fn      Gyroscope
     * @brief   Construct a new Gyroscope object. 
     */
    Gyroscope();
    
    /**
     * @fn      ~Gyroscope
     * @brief   Destroy the Gyroscope object. 
     */
    ~Gyroscope() override;

    /**
     * @fn      specificActions
     * @brief   Performs specific actions related to the gyroscope.
     */
    void specificActions(void) override;
};

#endif  //GYROSCOPE_H
