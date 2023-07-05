/**
 * @file        Sensor.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete base class Sensor.
 * 
 * @version     0.1
 * @date        2023-07-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef SENSOR_H
#define SENSOR_H

/**
 * @class   Sensor "Sensor.h" 
 * @brief   Concrete base class for a generic sensor.
 * 
 * @details This class implements the "Template" design pattern.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-05
 * @version 0.1
 */
class Sensor
{
public:
    /**
     * @fn      Sensor
     * @brief   Construct a new Sensor object.
     * 
     * @param   realValue Real sensor value.
     * @param   simulatedValue Simulated sensor value.
     */
    Sensor(float realValue, float simulatedValue);

    /**
     * @fn      ~Sensor
     * @brief   Destroy the Sensor object.
     */
    virtual ~Sensor();

    /**
     * @fn      switchState
     * @brief   Switches state between real and simulated sensor value.
     *  
     * @details This function calls the "specificActions" function.
     * 
     * @param   state True for the real value, false for the simulated value.
     */
    void switchState(bool state);

    /**
     * @fn      getValue
     * @brief   Gets the current active sensor value.
     * 
     * @return  float The current sensor value.
     */
    float getValue(void);

    /**
     * @fn      specificActions
     * @brief   Performs specific actions related to the specific sensor.
     * 
     * @details This function must be implemented by the derived class.
     */
    virtual void specificActions(void) = 0;

private:
    float _realValue;       /*Real sensor value.*/
    float _simulatedValue;  /*Simulated sensor value.*/
    float _currentValue;    /*Current active value.*/
};

#endif  //SENSOR_H
