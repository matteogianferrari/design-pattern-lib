/**
 * @file        LoggerVisitor.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class LoggerVisitor.
 * 
 * @version     0.1
 * @date        2023-07-23
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef LOGGERVISITOR_H
#define LOGGERVISITOR_H

#include "IVisitor.h"

/**
 * @class   LoggerVisitor "LoggerVisitor.h" 
 * @brief   Class that implements a logger visitor over the standard output stream.
 * 
 * @details This class derives from the abstract class LoggerVisitor.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-23
 * @version 0.1
 */
class LoggerVisitor:
    public IVisitor
{
public:
    /**
     * @fn      LoggerVisitor
     * @brief Construct a new LoggerVisitor object. 
     */
    LoggerVisitor();

    /**
     * @fn      ~LoggerVisitor
     * @brief   Destroy the LoggerVisitor object. 
     */
    ~LoggerVisitor() override;

    /**
     * @fn      runThermostatOperation
     * @brief   Executes the logging function for the Thermostat object.
     * 
     * @param   obj Pointer to a Thermostat object.
     */
    void runThermostatOperation(Thermostat* obj) override;

    /**
     * @fn      runAirConditionerOperation
     * @brief   Executes the logging function for the AirConditioner object.
     * 
     * @param   obj Pointer to a AirConditioner object.
     */
    void runAirConditionerOperation(AirConditioner* obj) override;
};

#endif  //LOGGERVISITOR_H
