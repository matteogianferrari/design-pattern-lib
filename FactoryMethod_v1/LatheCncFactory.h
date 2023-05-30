/**
 * @file        LatheCncFactory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of LatheCncFactory class.
 * 
 * @version     0.1
 * @date        2023-05-30
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef LATHECNCFACTORY_H
#define LATHECNCFACTORY_H

#include "ICncFactory.h"

/**
 * @class   LatheCncFactory "LatheCncFactory.h" 
 * @brief   Class that implements a Cnc lathe factory.
 *  
 * @details This class derives from the abstract class ICncFactory.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-05-30
 * @version 0.1
 */
class LatheCncFactory:
    public ICncFactory
{
public:
    /**
     * @fn      LatheCncFactory
     * @brief   Construct a new Cnc lathe factory.
     */
    LatheCncFactory();

    /**
     * @fn      ~LatheCncFactory
     * @brief   Destroy the Cnc lathe factory object.
     */
    virtual ~LatheCncFactory() override;
    
    /**
     * @fn      factoryMethod
     * @brief   Creates a LatheCnc object.
     * 
     * @return  ICnc* A pointer to an ICnc object.
     */
    ICnc* factoryMethod(void) override;
};

#endif  //LATHECNCFACTORY_H
