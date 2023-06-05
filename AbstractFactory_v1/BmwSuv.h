/**
 * @file        BmwSuv.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class BmwSuv.
 * 
 * @version     0.1
 * @date        2023-06-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef BMWSUV_H
#define BMWSUV_H

#include <mutex>
#include "ISuv.h"

/**
 * @class   BmwSuv "BmwSuv.h" 
 * @brief   Class that implements a Bmw suv.
 * 
 * @details This class derives from the abstract class ISuv.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-05
 * @version 0.1
 */
class BmwSuv:
    public ISuv
{
public:
    /**
     * @fn      BmwSuv
     * @brief   Construct a new Bmw Suv object.
     */
    BmwSuv();

    /**
     * @fn      ~BmwSuv
     * @brief   Destroy the Bmw Suv object.
     */
    ~BmwSuv() override;

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

#endif  //BMWSUV_H
