/**
 * @file        PizzaTirata.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class PizzaTirata.
 * 
 * @version     0.1
 * @date        2023-06-22
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef PIZZATIRATA_H
#define PIZZATIRATA_H

#include <mutex>
#include "IPizza.h"
#include "PizzaDecorator.h"

/**
 * @class   PizzaTirata "PizzaTirata.h" 
 * @brief   Class that implements the "tirata" decorator for a pizza.
 * 
 * @details This class derives from the abstract class PizzaDecorator.
 *          @n This implementation is thread-safe.
 * @note    A pizza "tirata" is a way of making the pizza. It stretches the dough
 *          to make the pizza thinner and increases the surface area.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-22
 * @version 0.1
 */
class PizzaTirata:
    public PizzaDecorator
{
public:
    /**
     * @fn      PizzaTirata
     * @brief   Construct a new Pizza Tirata object.
     * 
     * @param   pPizza Pointer to an IPizza instance.
     */
    PizzaTirata(IPizza* pPizza);

    /**
     * @fn      ~PizzaTirata
     * @brief   Destroy the Pizza Tirata object.
     * 
     * @details This function frees the allocated memory used by the pPizza pointer.
     *          @n Don't pass to this object a static pizza or you'll get segmentation fault.
     */
    ~PizzaTirata() override;

    /**
     * @fn      getCalories
     * @brief   Gets the pizza calories plus the extra calories from the extra garnishes.
     * 
     * @return  uint32_t Number of calories [Kcal].
     */
    uint32_t getCalories(void) override;

private:
    std::mutex _mutex;  /*Mutex for thread safety.*/
    int32_t _calories;  /*Number of calories contained in the garnishes.*/
    IPizza* _pPizza;    /*Pointer to an IPizza instance.*/
};

#endif  //PIZZATIRATA_H
