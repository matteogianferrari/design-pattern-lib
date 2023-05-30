/**
 * @file        ICncFactory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ICncFactory.
 * 
 * @version     0.1
 * @date        2023-05-30
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ICNCFACTORY_H
#define ICNCFACTORY_H

#include "ICnc.h"

/**
 * @class   ICnc "ICnc.h" 
 * @brief   Abstract class for a generic Cnc factory.
 * 
 * @details The implementations of this class must provide the function factoryMethod,
 *          used to create a new concrete Cnc machine.
 *          @n Usually factory classes contain some core business logic that
 *          relies on Cnc objects, returned by the factory method.
 *          @n Subclasses can indirectly change that business logic by overriding the
 *          factory method and returning a different type of product from it.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-05-30
 * @version 0.1
 */
class ICncFactory
{
public:
    /**
     * @fn      ~ICncFactory
     * @brief   Destroy the ICncFactory object.
     */
    virtual ~ICncFactory() {}
    
    /**
     * @fn      factoryMethod
     * @brief   Creates a concrete Cnc object using a specific constructor.
     * 
     * @details This function represents the "Factory Method" design pattern.
     *          @n Another typical name could be "makeCnc".
     * 
     * @return  ICnc* A pointer to an ICnc object.
     */
    virtual ICnc* factoryMethod(void) = 0;

    /**
     * @fn      setupCnc
     * @brief   Performs some core business logic with the concrete Cnc machine that creates.
     * 
     * @details For more details refer to @ref ICncFactory class details.
     * 
     * @param partProgramName The part program's name.
     */
    void setupCnc(std::string& partProgramName)
    {
        //Calls a concrete factoryMethod function with "this" pointer. 
        //All classes that derive from ICncFactory inherit setupCnc, and they
        //implement the factoryMethod function with the specific Cnc.
        //When this function is called, "this" refers to the concrete factory class.
        ICnc* product {this->factoryMethod()};

        product->setPartProgram(partProgramName);
        product->startMachining();

        delete product;
    }
};

#endif  //ICNCFACTORY_H
