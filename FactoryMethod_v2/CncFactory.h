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

/**
 * @class   CncFactory "CncFactory.h" 
 * @brief   Class that implements a Cnc factory.
 *  
 * @details This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-01
 * @version 0.1
 */
class CncFactory
{
public:
    /**
     * @fn      CncFactory
     * @brief   Construct a new Cnc factory.
     */
    CncFactory();

    /**
     * @fn      ~CncFactory
     * @brief   Destroy the CncFactory object.
     */
    ~CncFactory();
    
    /**
     * @fn      factoryMethod
     * @brief   Creates a concrete Cnc object using a specific constructor.
     * 
     * @details This function represents the "Factory Method" design pattern.
     *          @n Another typical name could be "makeCnc".
     * 
     * @param   cncType Cnc's type name that you want to create.
     * @return  ICnc* A pointer to an ICnc object.
     */
    ICnc* factoryMethod(std::string& cncType);

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
};

#endif  //ICNCFACTORY_H
