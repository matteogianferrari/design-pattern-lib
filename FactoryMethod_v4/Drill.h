/**
 * @file        Drill.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of Drill class.
 * 
 * @version     0.1
 * @date        2023-06-04
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef DRILL_H
#define DRILL_H

#include <mutex>

/**
 * @class   Drill "Drill.h" 
 * @brief   Class that implements a drill.
 * 
 * @details This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-04
 * @version 0.1
 */
class Drill
{
public:
    /**
     * @fn      Drill
     * @brief   Construct a new Drill object.
     */
    Drill();

    /**
     * @fn      ~Drill
     * @brief   Destroy the Drill object.
     */
    virtual ~Drill();

    /**
     * @fn      use 
     * @brief   Uses the drill to perform actions.
     */
    virtual void use(void);

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
};

#endif  //DRILL_H
