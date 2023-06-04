/**
 * @file        BatteryDrillFactory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of BatteryDrillFactory class.
 * 
 * @version     0.1
 * @date        2023-06-04
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef BATTERYDRILLFACTORY_H
#define BATTERYDRILLFACTORY_H

#include <mutex>
#include "BatteryDrill.h"
#include "DrillFactory.h"

/**
 * @class   BatteryDrillFactory "BatteryDrillFactory.h" 
 * @brief   Class that implements a battery drill factory.
 *  
 * @details This class derives from the concrete class DrillFactory.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-04
 * @version 0.1
 */
class BatteryDrillFactory:
    public DrillFactory
{
public:
    /**
     * @fn      BatteryDrillFactory
     * @brief   Construct a new Battery Drill Factory object.
     */
    BatteryDrillFactory();

    /**
     * @fn      ~BatteryDrillFactory
     * @brief   Destroy the Battery Drill Factory object.
     */
    ~BatteryDrillFactory();

    /**
     * @fn      factoryMethod
     * @brief   Creates a concrete battery drill object.
     * 
     * @details This function represents the "Factory Method" design pattern.
     *          @n Another typical name could be "makeDrill".
     * 
     * @return  Drill* A pointer to a Drill object.
     */
    Drill* factoryMethod(void) override;

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
};

#endif  //BATTERYDRILLFACTORY_H
