/**
 * @file        Pizza.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Pizza.
 * 
 * @version     0.1
 * @date        2023-06-22
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <mutex>
#include "IPizza.h"

/**
 * @class   Pizza "Pizza.h" 
 * @brief   Class that implements a pizza margherita (the standard).
 * 
 * @details This class derives from the abstract class IPizza.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-22
 * @version 0.1
 */
class Pizza:
    public IPizza
{
public:
    /**
     * @fn      Pizza
     * @brief   Construct a new Pizza object.
     */
    Pizza();

    /**
     * @fn      ~Pizza
     * @brief   Destroy the Pizza object.
     */
    ~Pizza() override;

    /**
     * @fn      getCalories
     * @brief   Gets the pizza margherita calories.
     * 
     * @return  uint32_t Number of calories [Kcal].
     */
    uint32_t getCalories(void) override;

private:
    std::mutex _mutex;  /*Mutex for thread safety.*/
    uint32_t _calories; /*Number of calories contained.*/
};

#endif  //PIZZA_H
