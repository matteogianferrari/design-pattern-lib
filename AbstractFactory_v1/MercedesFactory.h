/**
 * @file        MercedesFactory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class MercedesFactory.
 * 
 * @version     0.1
 * @date        2023-06-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef MERCEDESFACTORY_H
#define MERCEDESFACTORY_H

#include <mutex>
#include "ICarFactory.h"
#include "MercedesSuv.h"
#include "MercedesSportCar.h"

/**
 * @class   MercedesFactory "MercedesFactory.h" 
 * @brief   Concrete class for a Mercedes car factory.
 * 
 * @details This class derives from the abstract class ICarFactory.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-05
 * @version 0.1
 */
class MercedesFactory:
    public ICarFactory
{
public:
    /**
     * @fn      MercedesFactory
     * @brief   Construct a new Mercedes Factory object.
     */
    MercedesFactory();

    /**
     * @fn      ~MercedesFactory
     * @brief   Destroy the Mercedes Factory object. 
     */
    ~MercedesFactory() override;

    /**
     * @fn      makeSuv
     * @brief   Creates and returns a Mercedes suv.
     * 
     * @return  ISuv* A pointer to an ISuv object.
     */
    ISuv* makeSuv(void) override;

    /**
     * @fn      makeSportCar
     * @brief   Creates and returns a Mercedes sport car.
     * 
     * @return  ISportCar* A pointer to a ISportCar object.
     */
    ISportCar* makeSportCar(void) override;

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
};

#endif  //MERCEDESFACTORY_H
