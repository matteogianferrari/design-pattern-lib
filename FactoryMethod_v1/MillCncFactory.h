/**
 * @file        MillCncFactory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of MillCncFactory class.
 * 
 * @version     0.1
 * @date        2023-05-30
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef MILLCNCFACTORY_H
#define MILLCNCFACTORY_H

#include "ICncFactory.h"

/**
 * @class   MillCncFactory "MillCncFactory.h" 
 * @brief   Class that implements a Cnc mill factory.
 *  
 * @details This class derives from the abstract class ICncFactory.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-05-30
 * @version 0.1
 */
class MillCncFactory:
    public ICncFactory
{
public:
    /**
     * @fn      MillCncFactory
     * @brief   Construct a new Cnc mill factory.
     */
    MillCncFactory();

    /**
     * @fn      ~MillCncFactory
     * @brief   Destroy the Cnc mill factory object.
     */
    virtual ~MillCncFactory() override;
    
    /**
     * @fn      factoryMethod
     * @brief   Creates a MillCnc object.
     * 
     * @return  ICnc* A pointer to an ICnc object.
     */
    ICnc* factoryMethod(void) override;
};

#endif  //MILLCNCFACTORY_H
