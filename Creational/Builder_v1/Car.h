/**
 * @file        Car.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Car.
 * 
 * @version     0.1
 * @date        2023-06-13
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef CAR_H
#define CAR_H

#include <mutex>
#include <vector>
#include <string>

/**
 * @class   Car "Car.h" 
 * @brief   Class that implements a car.
 * 
 * @details This class implements function for adding and showing the vehicle's parts.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-13
 * @version 0.1
 */
class Car
{
public:
    /**
     * @fn      Car
     * @brief   Construct a new Car object.
     */
    Car();

    /**
     * @fn      ~Car
     * @brief   Destroy the Car object.
     */
    ~Car();

    /**
     * @fn      showPartsList
     * @brief   Prints the list of the car parts.
     */
    void showPartsList(void);

    /**
     * @fn      addComponent
     * @brief   Adds to the parts list the specified component.
     * 
     * @param   component String that represents the component.
     */
    void addComponent(std::string component);
    
private:
    std::mutex _mutex;                      /*Mutex for thread safety.*/
    std::vector<std::string> _partsList;    /*Vector of components.*/
};

#endif  //CAR_H
