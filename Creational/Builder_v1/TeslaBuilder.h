/**
 * @file        TeslaBuilder.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class TeslaBuilder.
 * 
 * @version     0.1
 * @date        2023-06-13
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef TESLABUILDER_H
#define TESLABUILDER_H

#include <mutex>
#include "ICarBuilder.h"
#include "Car.h"

/**
 * @class   TeslaBuilder "TeslaBuilder.h" 
 * @brief   Concrete class for a Tesla car builder.
 * 
 * @details This class derives from the abstract class ICarBuilder.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-13
 * @version 0.1
 */
class TeslaBuilder:
    public ICarBuilder
{
public:
    /**
     * @fn      TeslaBuilder
     * @brief   Construct a new Tesla Builder object.
     */
    TeslaBuilder();

    /**
     * @fn      ~TeslaBuilder
     * @brief   Destroy the Tesla Builder object.
     */
    ~TeslaBuilder() override;

    /**
     * @fn      produceWheels
     * @brief   Produces a wheels component and adds it to the Tesla car.
     */
    void produceWheels(void) override;

    /**
     * @fn      produceBrakes
     * @brief   Produces a brakes component and adds it to the Tesla car.
     */
    void produceBrakes(void) override;
    
    /**
     * @fn      produceEngine
     * @brief   Produces an engine component and adds it to the Tesla car.
     */
    void produceEngine(void) override;
    
    /**
     * @fn      produceTransmission
     * @brief   Produces a transmission component and adds it to the Tesla car.
     */
    void produceTransmission(void) override;

    /**
     * @fn      produceInterios
     * @brief   Produces an interiors component and adds it to the Tesla car.
     */
    void produceInterios(void) override;

    /**
     * @fn      getCar
     * @brief   Gets the Tesla car object.
     * 
     * @details This function returns to the client the built Tesla car, and resets
     *          the internal car object to be rebuilt.
     *          @n The client must delete the returned Car object after
     *          performing the actions.
     * 
     * @return  Car* Pointer to a Car object.
     */
    Car* getCar(void) override;

private:
    /**
     * @fn      resetCar
     * @brief   Resets the internal car object to be built.
     */
    void resetCar(void);

    std::mutex _mutex;  /*Mutex for thread safety.*/
    Car* _product;      /*Pointer to a Car object.*/
};

#endif  //TESLABUILDER_H
