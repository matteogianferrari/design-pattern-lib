/**
 * @file        BmwFactory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class BmwFactory.
 * 
 * @version     0.1
 * @date        2023-06-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef BMWFACTORY_H
#define BMWFACTORY_H

#include <mutex>
#include "ICarFactory.h"
#include "BmwSuv.h"
#include "BmwSportCar.h"

/**
 * @class   BmwFactory "BmwFactory.h" 
 * @brief   Concrete class for a Bmw car factory.
 * 
 * @details This class derives from the abstract class ICarFactory.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-05
 * @version 0.1
 */
class BmwFactory:
    public ICarFactory
{
public:
    /**
     * @fn      BmwFactory
     * @brief   Construct a new Bmw Factory object.
     */
    BmwFactory();

    /**
     * @fn      ~BmwFactory
     * @brief   Destroy the Bmw Factory object. 
     */
    ~BmwFactory() override;

    /**
     * @fn      makeSuv
     * @brief   Creates and returns a Bmw suv.
     * 
     * @return  ISuv* A pointer to an ISuv object.
     */
    ISuv* makeSuv(void) override;

    /**
     * @fn      makeSportCar
     * @brief   Creates and returns a Bmw sport car.
     * 
     * @return  ISportCar* A pointer to a ISportCar object.
     */
    ISportCar* makeSportCar(void) override;

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
};

#endif  //BMWFACTORY_H
