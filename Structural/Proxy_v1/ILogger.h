/**
 * @file        ILogger.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ILogger.
 * 
 * @version     0.1
 * @date        2023-06-26
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

#define CLIENT_TOKEN 140343159U /*Hashed value of "Friendly client".*/

/**
 * @class   ILogger "ILogger.h" 
 * @brief   Abstract class for a generic logging system.
 * 
 * @details The implementations of this class must provide functions for saving
 *          data messages in the specific logging system.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-26
 * @version 0.1
 */
class ILogger
{
public:
    /**
     * @fn      ~Ilogger
     * @brief   Destroy the ILogger object. 
     */
    virtual ~ILogger() {}

    /**
     * @fn      print
     * @brief   Logs the data to the specific logging system.
     * 
     * @param   id Reference to the client string id.
     * @param   message Reference to the string message.
     * @return  true if the message is correctly logged, false otherwise.
     */
    virtual bool print(std::string& id, std::string& message) = 0;
};

#endif  //ILOGGER_H
