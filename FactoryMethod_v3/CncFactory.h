/**
 * @file        CncFactory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of CncFactory class.
 * 
 * @version     0.1
 * @date        2023-06-01
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef CNCFACTORY_H
#define CNCFACTORY_H

#include <mutex>
#include "ICnc.h"
#include "LatheCnc.h"
#include "MillCnc.h"

/**
 * @class   CncFactory "CncFactory.h" 
 * @brief   Class that implements a Cnc factory.
 *  
 * @details This implementation uses template argument to specify the concrete Cnc machine
 *          class that derives from the ICnc abstract class. This class should be used only
 *          with concrete Cnc classes that derive from ICnc.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-01
 * @version 0.1
 */
template <class T>
class CncFactory
{
public:
    /**
     * @fn      CncFactory
     * @brief   Construct a new Cnc factory.
     */
    CncFactory():
        _mutex {}
    {
    }

    /**
     * @fn      ~CncFactory
     * @brief   Destroy the CncFactory object.
     */
    ~CncFactory()
    {
    }
    
    /**
     * @fn      factoryMethod
     * @brief   Creates a concrete Cnc object using a specific constructor.
     * 
     * @details This function represents the "Factory Method" design pattern.
     *          @n Another typical name could be "makeCnc".
     * 
     * @param   value Value shared between the concrete Cnc machine constructor.
     * @return  ICnc* A pointer to an ICnc object.
     */
    ICnc* factoryMethod(uint32_t value)
    {
        std::lock_guard<std::mutex> lock {_mutex};

        //Value is implictly narrowed
        return new T(value);
    }

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
};

#endif  //ICNCFACTORY_H
