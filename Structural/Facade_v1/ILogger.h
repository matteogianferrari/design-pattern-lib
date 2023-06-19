/**
 * @file        ILogger.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ILogger.
 * 
 * @version     0.1
 * @date        2023-06-19
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

/**
 * @class   ILogger "ILogger.h" 
 * @brief   Abstract class for a generic logging system.
 * 
 * @details The implementations of this class must provide functions for saving
 *          data messages in the specific logging system.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-19
 * @version 0.1
 */
class ILogger
{
public:
    /**
     * @fn      ~ILogger
     * @brief   Destroy the ILogger object.
     */
    virtual ~ILogger() {}

    /**
     * @fn logInfo 
     * @brief Logs the data to the specific logging system.
     * 
     * @param data Reference to the data message to log.
     */
    virtual void logInfo(std::string& data) = 0;
};

#endif  //ILOGGER_H