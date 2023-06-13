/**
 * @file        CarFactorySingleton.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of CarFactorySingleton class.
 * 
 * @version     0.1
 * @date        2023-05-26
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef CARFACTORYSINGLETON_H
#define CARFACTORYSINGLETON_H

#include "ICarFactory.h"
#include "BmwFactory.h"
#include "MercedesFactory.h"

/**
 * @class   CarFactorySingleton "CarFactorySingleton.h" 
 * @brief   Class that implements a car factory Singleton.
 * 
 * @details This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-05
 * @version 0.1
 */
class CarFactorySingleton
{
public:
    /**
     * @fn      getCarFactory
     * @brief   Gets the concrete CarFactory object.
     * 
     * @details This function implements the "Singleton" design pattern.
     *          @n It's the safest implementation of a "Singleton" if a third-party developer
     *          needs to use a CarFactory in its project.
     * 
     * @param   brand The car factory brand to create.
     * @return  ICarFactory* A pointer to an ICarFactory object.
     */
    static ICarFactory* getCarFactory(std::string& brand);

    /**
     * @fn      CarFactorySingleton
     * @brief   Copy constructor of a CarFactorySingleton object.
     * 
     * @details The CarFactorySingleton shouldn't be created from another CarFactorySingleton object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy constructor is deleted.
     * 
     * @param   obj Reference to a CarFactorySingleton object.
     */
    CarFactorySingleton(CarFactorySingleton& obj) = delete;

    /**
     * @fn      operator=
     * @brief   Copy assignment operator of a CarFactorySingleton object.
     * 
     * @details The CarFactorySingleton shouldn't be created from another CarFactorySingleton object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy assignment operator is deleted.
     * 
     * @param   obj Reference to a const CarFactorySingleton object.
     */
    void operator=(const CarFactorySingleton& obj) = delete;

protected:
    /**
     * @fn CarFactorySingleton
     * @brief Construct a new Car Factory Singleton object.
     */
    CarFactorySingleton();

    /**
     * @fn ~CarFactorySingleton
     * @brief Destroy the Car Factory Singleton object.
     */
    ~CarFactorySingleton();

private:
    static std::mutex _mutex;           /*Mutex for the thread-safety.*/                   
    static ICarFactory* _pInstance;     /*Pointer to the Cache instance.*/
};

#endif  //CARFACTORYSINGLETON_H
