/**
 * @file        ResourceFactory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of ResourceFactory class.
 * 
 * @version     0.1
 * @date        2023-07-04
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H

#include <string>
#include "IWorkResource.h"

/**
 * @class   ResourceFactory "ResourceFactory.h" 
 * @brief   Class that implements a work resource factory.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-04
 * @version 0.1
 */
class ResourceFactory
{
public:
    /**
     * @fn      ResourceFactory
     * @brief   Construct a new Resource factory.
     */
    ResourceFactory();

    /**
     * @fn      ~ResourceFactory
     * @brief   Destroy the ResourceFactory object.
     */
    ~ResourceFactory();
    
    /**
     * @fn      factoryMethod
     * @brief   Creates a concrete work resource object using a specific constructor.
     * 
     * @details This function represents the "Factory Method" design pattern.
     *          @n Another typical name could be "makeResource".
     * 
     * @param   resourceType Work resource type name that you want to create.
     * @return  IWorkResource* Pointer to an IWorkResource object.
     */
    IWorkResource* factoryMethod(std::string resourceType);
};

#endif  //RESOURCEFACTORY_H
