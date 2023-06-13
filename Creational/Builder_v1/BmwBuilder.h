/**
 * @file        BmwBuilder.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class BmwBuilder.
 * 
 * @version     0.1
 * @date        2023-06-13
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef BMWBUILDER_H
#define BMWBUILDER_H

#include <mutex>
#include "ICarBuilder.h"
#include "Car.h"

/**
 * @class   BmwBuilder "BmwBuilder.h" 
 * @brief   Concrete class for a Bmw car builder.
 * 
 * @details This class derives from the abstract class ICarBuilder.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-13
 * @version 0.1
 */
class BmwBuilder:
    public ICarBuilder
{
public:
    /**
     * @fn      BmwBuilder
     * @brief   Construct a new Bmw Builder object.
     */
    BmwBuilder();

    /**
     * @fn      ~BmwBuilder
     * @brief   Destroy the Bmw Builder object.
     */
    ~BmwBuilder() override;

    /**
     * @fn      produceWheels
     * @brief   Produces a wheels component and adds it to the Bmw car.
     */
    void produceWheels(void) override;

    /**
     * @fn      produceBrakes
     * @brief   Produces a brakes component and adds it to the Bmw car.
     */
    void produceBrakes(void) override;
    
    /**
     * @fn      produceEngine
     * @brief   Produces an engine component and adds it to the Bmw car.
     */
    void produceEngine(void) override;
    
    /**
     * @fn      produceTransmission
     * @brief   Produces a transmission component and adds it to the Bmw car.
     */
    void produceTransmission(void) override;

    /**
     * @fn      produceInterios
     * @brief   Produces an interiors component and adds it to the Bmw car.
     */
    void produceInterios(void) override;

    /**
     * @fn      getCar
     * @brief   Gets the Bmw car object.
     * 
     * @details This function returns to the client the built Bmw car, and resets
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

#endif  //BMWBUILDER_H
