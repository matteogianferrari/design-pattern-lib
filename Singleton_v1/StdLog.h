/**
 * @file        StdLog.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of StdLog class.
 * 
 * @version     0.1
 * @date        2023-05-25
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef STDLOG_H
#define STDLOG_H

#include "ILog.h"
#include <mutex>

#define MAX_BUF_SIZE 10000U /*Maximum size for the StdLog internal buffer.*/

/**
 * @class   StdLog "StdLog.h" 
 * @brief   Class that implements a logging system using the standard output.
 * 
 * @details This class derives from the abstract class ILog.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-05-25
 * @version 0.1
 */
class StdLog:
    public ILog
{
public:
    /**
     * @fn      StdLog
     * @brief   Construct a new Std Log object
     * 
     * @param   bufSize Size of the internal buffer (expressed in number of bytes).
     *          @n The default value is MAX_BUF_SIZE.
     */
    StdLog(uint32_t bufSize = MAX_BUF_SIZE);

    /**
     * @fn      ~StdLog
     * @brief   Destroy the Std Log object
     */
    ~StdLog() override;

    /**
     * @fn      print 
     * @brief   Print a logging message using the standard output.
     * 
     * @param   message The body of the message (C style). 
     * @param   ... Variable argument list (C style):
     */
    void print(const char* message, ...) override;

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
    uint32_t _bufSize;  /*Size of the internal buffer (expressed in bytes).*/
    char* _pBuffer;     /*Pointer to interal buffer for building the message.*/
};

#endif  //STDLOG_H
