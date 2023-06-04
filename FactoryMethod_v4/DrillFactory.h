/**
 * @file        DrillFactory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of DrillFactory class.
 * 
 * @version     0.1
 * @date        2023-06-04
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef DRILLFACTORY_H
#define DRILLFACTORY_H

#include <mutex>
#include "Drill.h"

/**
 * @class   DrillFactory "DrillFactory.h" 
 * @brief   Class that implements a drill factory.
 *  
 * @details This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-04
 * @version 0.1
 */
class DrillFactory
{
public:
    /**
     * @fn      DrillFactory
     * @brief   Construct a new Drill Factory object.
     */
    DrillFactory();

    /**
     * @fn      ~DrillFactory
     * @brief   Destroy the Drill Factory object.
     */
    ~DrillFactory();

    /**
     * @fn      factoryMethod
     * @brief   Creates a concrete drill object.
     * 
     * @details This function represents the "Factory Method" design pattern.
     *          @n Another typical name could be "makeDrill".
     * 
     * @return  Drill* A pointer to a Drill object.
     */
    virtual Drill* factoryMethod(void);

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
};

#endif  //DRILLFACTORY_H
