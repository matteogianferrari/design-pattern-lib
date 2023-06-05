/**
 * @file        BmwSportCar.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class BmwSportCar.
 * 
 * @version     0.1
 * @date        2023-06-05
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef BMWSPORTCAR_H
#define BMWSPORTCAR_H

#include <mutex>
#include "ISportCar.h"

/**
 * @class   BmwSportCar "BmwSportCar.h" 
 * @brief   Class that implements a Bmw sport car.
 * 
 * @details This class derives from the abstract class ISportCar.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-05
 * @version 0.1
 */
class BmwSportCar:
    public ISportCar
{
public:
    /**
     * @fn      BmwSportCar
     * @brief   Construct a new Bmw Sport Car object.
     */
    BmwSportCar();

    /**
     * @fn      ~BmwSportCar
     * @brief   Destroy the Bmw Sport Car object.
     */
    ~BmwSportCar() override;

    /**
     * @fn      start
     * @brief   Starts the Bmw sport car.
     */
    void start(void) override;

    /**
     * @fn      drive
     * @brief   Starts driving the Bmw sport car.
     */
    void drive(void) override;

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
};

#endif  //BMWSPORTCAR_H
