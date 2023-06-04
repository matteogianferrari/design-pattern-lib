/**
 * @file        BatteryDrill.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of BatteryDrill class.
 * 
 * @version     0.1
 * @date        2023-06-04
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef BATTERYDRILL_H
#define BATTERYDRILL_H

#include <mutex>
#include "Drill.h"

/**
 * @class   BatteryDrill "BatteryDrill.h" 
 * @brief   Class that implements a battery drill.
 * 
 * @details This class derives from the concrete class Drill.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-04
 * @version 0.1
 */
class BatteryDrill:
    public Drill
{
public:
    /**
     * @fn      BatteryDrill
     * @brief   Construct a new Battery Drill object.
     */
    BatteryDrill();

    /**
     * @fn      ~BatteryDrill
     * @brief   Destroy the Battery Drill object.
     */
    ~BatteryDrill() override;

    /**
     * @fn      use 
     * @brief   Uses the battery drill to perform actions.
     */
    void use(void) override;

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
};

#endif  //BATTERYDRILL_H
