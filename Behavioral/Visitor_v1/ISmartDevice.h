/**
 * @file        ISmartDevice.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ISmartDevice.
 * 
 * @version     0.1
 * @date        2023-07-23
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ISMARTDEVICE_H
#define ISMARTDEVICE_H

class IVisitor;     /*Forward declaration of IVisitor abstract class.*/

/**
 * @class   ISmartDevice "ISmartDevice.h" 
 * @brief   Abstract class for a generic smart device.
 * 
 * @details The implementations of this class must provide function for accepting
 *          a specific visitor and executing its function.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-23
 * @version 0.1
 */
class ISmartDevice
{
public:
    /**
     * @fn      ~ISmartDevice
     * @brief   Destroy the ISmartDevice object. 
     */
    virtual ~ISmartDevice() {}

    /**
     * @fn      acceptVisitor
     * @brief   Accepts a specific visitor and execute its function.
     * 
     * @param   visitor Pointer to an IVisitor object.
     */
    virtual void acceptVisitor(IVisitor* visitor) = 0;
};

#endif  //ISMARTDEVICE_H
