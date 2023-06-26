/**
 * @file        LoggerProxy.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class LoggerProxy.
 * 
 * @version     0.1
 * @date        2023-06-26
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef LOGGERPROXY_H
#define LOGGERPROXY_H

#include <mutex>
#include <vector>
#include "ILogger.h"

#define MAX_STORED_MESSAGE 2    /*Maximum number of messages stored in the buffer.*/

/**
 * @struct  ClientMessage
 * @brief   Struct containing the client id and message.
 */
struct ClientMessage
{
    std::string id;         /*Client id.*/
    std::string message;    /*Client message.*/
};

/**
 * @class   LoggerProxy "LoggerProxy.h" 
 * @brief   Class that implements a virtual and protected proxy for a generic logging system.
 *  
 * @details This class derives from the abstract class ILogger.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-26
 * @version 0.1
 */
class LoggerProxy:
    public ILogger
{
public:
    /**
     * @fn      LoggerProxy
     * @brief   Construct a new Logger Proxy object.
     * 
     * @details The logging system must be created dynamically.
     * @param   pLogger Pointer to a logging system.
     */
    LoggerProxy(ILogger* pLogger);

    /**
     * @fn      ~LoggingProxy
     * @brief   Destroy the Logger Proxy object. 
     * 
     * @details The logging system must be created dynamically.
     */
    ~LoggerProxy() override;

    /**
     * @fn      print
     * @brief   Logs the data in the pointed logging system.
     * 
     * @details This function checks if the client has the privileges to log in the system.
     *          @n If the client has the right privileges to log the data, puts the message
     *          into an internal buffer. When the internal buffer reaches the maximum
     *          capacity, flushes all the messages to the logging system.
     * 
     * @param   id Reference to the client string id.
     * @param   message Reference to the string message.
     * @return  true if the message is correctly logged, false otherwise.
     */
    bool print(std::string& id, std::string& message) override;

private:
    /**
     * @fn      getIdHash
     * @brief   Get the hash value of the client id.
     * 
     * @details The hash value is computed by doing the product of the single chars in the
     *          string, then by dividing the result by the string lenght.
     * 
     * @param   id Reference to the client string id.
     * @return  uint32_t Hashed value of the client id if id is valid, 0 otherwise.
     */
    uint32_t getIdHash(std::string& id);

    /**
     * @fn      flushBuffer
     * @brief   Flushes the internal buffer to the pointed logging system.
     */
    void flushBuffer(void);

    ILogger* _pLogger;                          /*Pointer to a logging system.*/
    std::vector<struct ClientMessage> _buffer;  /*Internal buffer for storing the messages.*/
    std::mutex _mutex;                          /*Mutex for thread safety.*/
};

#endif  //LOGGERPROXY_H
