/**
 * @file        StdOutLogger.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class StdOutLogger.
 * 
 * @version     0.1
 * @date        2023-06-19
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef STDOUTLOGGER_H
#define STDOUTLOGGER_H

#include <mutex>
#include "ILogger.h"

/**
 * @class   StdOutLogger "StdOutLogger.h" 
 * @brief   Class that implements a logging system using the standard output.
 * 
 * @details This class derives from the abstract class ILogger.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-19
 * @version 0.1
 */
class StdOutLogger:
    public ILogger
{
public:
    /**
     * @fn      StdOutLogger
     * @brief   Construct a new Stdout Logger object.
     */
    StdOutLogger();

    /**
     * @fn      ~StdOutLogger
     * @brief   Destroy the Std Out Logger object
     */
    ~StdOutLogger() override;

    /**
     * @fn logInfo 
     * @brief Logs the data to the stdout logging system.
     * 
     * @param data Reference to the data message to log.
     */
    void logInfo(std::string& data) override;

private:
    std::mutex _mutex;  /*Mutex for thread safety.*/
};

#endif  //STDOUTLOGGER_H
