/**
 * @file        MercedesSuv.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class MercedesSuv.
 * 
 * @version     0.1
 * @date        2023-06-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef MERCEDESSUV_H
#define MERCEDESSUV_H

#include <mutex>
#include "ISuv.h"

/**
 * @class   MercedesSuv "MercedesSuv.h" 
 * @brief   Class that implements a Mercedes suv.
 * 
 * @details This class derives from the abstract class ISuv.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-05
 * @version 0.1
 */
class MercedesSuv:
    public ISuv
{
public:
    /**
     * @fn      MercedesSuv
     * @brief   Construct a new Mercedes Suv object. 
     */
    MercedesSuv();

    /**
     * @fn      ~MercedesSuv
     * @brief   Destroy the Mercedes Suv object.
     */
    ~MercedesSuv() override;

    /**
     * @fn      start
     * @brief   Starts the Bmw suv.
     */
    void start(void) override;

    /**
     * @fn      drive
     * @brief   Starts driving the Bmw suv.
     */
    void drive(void) override;

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
};

#endif  //MERCEDESSUV_H
