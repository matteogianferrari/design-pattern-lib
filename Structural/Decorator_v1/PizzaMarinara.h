/**
 * @file        PizzaMarinara.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class PizzaMarinara.
 * 
 * @version     0.1
 * @date        2023-06-22
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef PIZZAMARINARA_H
#define PIZZAMARINARA_H

#include <mutex>
#include "IPizza.h"
#include "PizzaDecorator.h"

/**
 * @class   PizzaMarinara "PizzaMarinara.h" 
 * @brief   Class that implements the "marinara" decorator for a pizza.
 * 
 * @details This class derives from the abstract class PizzaDecorator.
 *          @n This implementation is thread-safe.
 * @note    A pizza "marinara" is a type of pizza. It removes the mozzarella.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-22
 * @version 0.1
 */
class PizzaMarinara:
    public PizzaDecorator
{
public:
    /**
     * @fn      PizzaMarinara
     * @brief   Construct a new Pizza Marinara object.
     * 
     * @param   pPizza Pointer to an IPizza instance.
     */
    PizzaMarinara(IPizza* pPizza);

    /**
     * @fn      ~PizzaMarinara
     * @brief   Destroy the Pizza Marinara object.
     * 
     * @details This function frees the allocated memory used by the pPizza pointer.
     *          @n Don't pass to this object a static pizza or you'll get segmentation fault.
     */
    ~PizzaMarinara() override;

    /**
     * @fn      getCalories
     * @brief   Gets the pizza calories minus the calories from the removed mozzarella.
     * 
     * @return  uint32_t Number of calories [Kcal].
     */
    uint32_t getCalories(void) override;

private:
    std::mutex _mutex;  /*Mutex for thread safety.*/
    int32_t _calories;  /*Number of calories removed.*/
    IPizza* _pPizza;    /*Pointer to an IPizza instance.*/
};

#endif  //PIZZAMARINARA_H
