/**
 * @file        StdLogger.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class StdLogger.
 * 
 * @version     0.1
 * @date        2023-06-26
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef STDLOGGER_H
#define STDLOGGER_H

#include <mutex>
#include "ILogger.h"

/**
 * @class   StdLogger "StdLogger.h" 
 * @brief   Class that implements a logging system using the standard output.
 * 
 * @details This class derives from the abstract class ILogger.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-26
 * @version 0.1
 */
class StdLogger:
    public ILogger
{
public:
    /**
     * @fn      StdLogger
     * @brief   Construct a new Std Logger object.
     */
    StdLogger();

    /**
     * @fn      ~StdLogger
     * @brief   Destroy the Std Logger object.
     */
    ~StdLogger() override;

    /**
     * @fn      print
     * @brief   Logs the data to the standard output logging system.
     * 
     * @details This function should be used carefully because it costs a lot of computing
     *          time (specified to make the example valid).
     * 
     * @param   id Reference to the client string id.
     * @param   message Reference to the string message.
     * @return  true if the message is correctly logged, false otherwise.
     */
    bool print(std::string& id, std::string& key) override;

private:
    std::mutex _mutex;  /*Mutex for thread safety.*/
};

#endif  //STDLOGGER_H
