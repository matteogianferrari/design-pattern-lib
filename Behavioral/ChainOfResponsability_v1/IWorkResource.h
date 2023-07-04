/**
 * @file        IWorkResource.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class IWorkResource.
 * 
 * @version     0.1
 * @date        2023-07-03
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef IWORKRESOURCE_H
#define IWORKRESOURCE_H

#include <cstdint>

/**
 * @class   IWorkResource "IWorkResource.h" 
 * @brief   Abstract class for a generic work resource.
 * 
 * @details The implementations of this class must provide function for get the
 *          work done at its specific level.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-03
 * @version 0.1
 */
class IWorkResource
{
public:
    /**
     * @fn      ~IWorkResource
     * @brief   Destroy the IWorkResource object.
     */
    virtual ~IWorkResource() {}

    /**
     * @fn      work
     * @brief   Gets the object work done.
     *
     * @param   workLoad The project workload to substain.
     * @return  int32_t A unit of work load done.
     */
    virtual int32_t work(int32_t workLoad) = 0;

    /**
     * @fn      getWorkCapability
     * @brief   Retreives the potential work that the object can substain.
     * 
     * @return  int32_t A unit of potential work load.
     */
    virtual int32_t getWorkCapability(void) = 0;
};

#endif  //IWORKRESOURCE_H
