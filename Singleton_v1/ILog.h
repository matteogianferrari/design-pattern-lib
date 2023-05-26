/**
 * @file        ILog.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ILog.
 * 
 * @version     0.1
 * @date        2023-05-25
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ILOG_H
#define ILOG_H

#include <cstdint>

/**
 * @class   ILog "ILog.h" 
 * @brief   Abstract class for a generic logging system.
 * 
 * @details The implementations of this class must provide a function to print
 *          a message on the related logging system.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-05-25
 * @version 0.1
 */
class ILog
{
public:
    /**
    * @fn       ~ILog
     * @brief   Destroy the ILog object.
     */
    virtual ~ILog() {}

    /**
     * @fn      print 
     * @brief   Print a logging message using a specific logging system.
     * 
     * @param   message The body of the message (C style). 
     * @param   ... Variable argument list (C style):
     */
    virtual void print(const char* message, ...) = 0;
};

#endif  //ILOG_H
