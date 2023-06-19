/**
 * @file        TemperatureRecorder.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class TemperatureRecorder.
 * 
 * @version     0.1
 * @date        2023-06-19
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef TEMPERATURERECORDER_H
#define TEMPERATURERECORDER_H

#include <mutex>
#include "IDatabase.h"
#include "ILogger.h"

/**
 * @class   TemperatureRecorder "TemperatureRecorder.h" 
 * @brief   Concrete class for a temperature recorder system.
 * 
 * @details This implementation is the "Facade" design pattern. It creates a single
 *          interface for easily calling a set of functions for the client.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-19
 * @version 0.1
 */
class TemperatureRecorder
{
public:
    /**
     * @fn      getTemperatureRecorder
     * @brief   Gets the TemperatureRecorder object.
     * 
     * @details This function implements the "Singleton" design pattern.
     *          @n It's the safest implementation of a "Singleton" if a third-party developer
     *          needs to use this temperature recorder system in its project.
     * 
     * @return  TemperatureRecorder* A pointer to a TemperatureRecorder object.
     */
    static TemperatureRecorder* getTemperatureRecorder(void);

    /**
     * @fn      TemperatureRecorder
     * @brief   Copy constructor of a TemperatureRecorder object.
     * 
     * @details The TemperatureRecorder shouldn't be created from another object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy constructor is deleted.
     * 
     * @param   obj Reference to a TemperatureRecorder object.
     */
    TemperatureRecorder(TemperatureRecorder& obj) = delete;

    /**
     * @fn      operator=
     * @brief   Copy assignment operator of a TemperatureRecorder object.
     * 
     * @details The TemperatureRecorder shouldn't be created from another object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy assignment operator is deleted.
     * 
     * @param   obj Reference to a const TemperatureRecorder object.
     */
    void operator=(const TemperatureRecorder& obj) = delete;

    /**
     * @fn      insertTemperature
     * @brief   Tries to insert the temperature in the database and logs the event.
     * 
     * @details This functions wraps a set of sub-system functions.
     *          @n First inserts the value in the database and then logs the event.
     * 
     * @param timestamp String reference to when the event occurred.
     * @param value Value to store in the database.
     */
    void insertTemperature(std::string& timestamp, int32_t value);

    /**
     * @fn      deleteTemperature
     * @brief   Tries to remove the temperature in the database and logs the event.
     * 
     * @details This functions wraps a set of sub-system functions.
     *          @n First removes the value in the database and then logs the event.
     * 
     * @param timestamp String reference to when the event occurred.
     */
    void deleteTemperature(std::string& timestamp);

protected:
    /**
     * @fn      TemperatureRecorder
     * @brief   Construct a new Temperature Recorder object.
     */
    TemperatureRecorder();

    /**
     * @fn      ~TemperatureRecorder
     * @brief   Destroy the Temperature Recorder object.
     */
    ~TemperatureRecorder();

private:
    static std::mutex _mutex;               /*Mutex for thread safety.*/
    static TemperatureRecorder* _pInstance; /*Pointer to the TemperatureRecorder instance.*/
    IDatabase* _database;                   /*Pointer to the Database instance.*/
    ILogger* _logger;                       /*Pointer to the logger instance.*/
};

#endif  //TEMPERATURERECORDER_H
