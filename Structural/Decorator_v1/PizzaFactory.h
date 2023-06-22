/**
 * @file        PizzaFactory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of PizzaFactory class.
 * 
 * @version     0.1
 * @date        2023-06-22
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef PIZZAFACTORY_H
#define PIZZAFACTORY_H

#include <mutex>
#include "Pizza.h"

/**
 * @class   PizzaFactory "PizzaFactory.h" 
 * @brief   Class that implements a margherita pizza (Pizza object) factory.
 *  
 * @details This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-22
 * @version 0.1
 */
class PizzaFactory
{
public:
    /**
     * @fn      PizzaFactory
     * @brief   Construct a new Pizza factory.
     */
    PizzaFactory();

    /**
     * @fn      ~PizzaFactory
     * @brief   Destroy the pizza factory object.
     */
    ~PizzaFactory();
    
    /**
     * @fn      makePizza
     * @brief   Creates a Pizza object.
     * 
     * @return  IPizza* A pointer to an IPizza object.
     */
    IPizza* makePizza(void);

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
};

#endif  //PIZZAFACTORY_H
