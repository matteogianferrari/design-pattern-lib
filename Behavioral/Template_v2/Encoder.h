/**
 * @file        Encoder.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Encoder.
 * 
 * @version     0.1
 * @date        2023-07-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ENCODER_H
#define ENCODER_H

#include "Sensor.h"

/**
 * @class   Encoder "Encoder.h" 
 * @brief   Concrete class for an encoder.
 * 
 * @details This class derives from the abstract class Sensor.
 *          
 * @author  Matteo Gianferrari
 * @date    2023-07-05
 * @version 0.1
 */
class Encoder:
    public Sensor
{
public:
    /**
     * @fn      Encoder
     * @brief   Construct a new Encoder object. 
     */
    Encoder();
    
    /**
     * @fn      ~Encoder
     * @brief   Destroy the Encoder object. 
     */
    ~Encoder() override;

    /**
     * @fn      specificActions
     * @brief   Performs specific actions related to the encoder.
     */
    void specificActions(void) override;
};

#endif  //ENCODER_H
