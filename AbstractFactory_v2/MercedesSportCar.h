/**
 * @file        MercedesSportCar.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class MercedesSportCar.
 * 
 * @version     0.1
 * @date        2023-06-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef MERCEDESSPORTCAR_H
#define MERCEDESSPORTCAR_H

#include <mutex>
#include "ISportCar.h"

/**
 * @class   MercedesSportCar "MercedesSportCar.h" 
 * @brief   Class that implements a Mercedes sport car.
 * 
 * @details This class derives from the abstract class ISportCar.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-05
 * @version 0.1
 */
class MercedesSportCar:
    public ISportCar
{
public:
    /**
     * @fn      MercedesSportCar
     * @brief   Construct a new Mercedes Sport Car object.
     */
    MercedesSportCar();

    /**
     * @fn      ~MercedesSportCar
     * @brief   Destroy the Mercedes Sport Car object.
     */
    ~MercedesSportCar() override;

    /**
     * @fn      start
     * @brief   Starts the Mercedes sport car.
     */
    void start(void) override;

    /**
     * @fn      drive
     * @brief   Starts driving the Mercedes sport car.
     */
    void drive(void) override;

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
};

#endif  //MERCEDESSPORTCAR_H
