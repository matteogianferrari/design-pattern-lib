/**
 * @file        Alive.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Alive.
 * 
 * @version     0.1
 * @date        2023-07-21
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ALIVE_H
#define ALIVE_H

#include "IState.h"

/**
 * @class   Alive "Alive.h" 
 * @brief   Class that implements the Alive state for a character.
 * 
 * @details This class derives from the abstract class IState.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-21
 * @version 0.1
 */
class Alive:
    public IState
{
public:
    /**
     * @fn      Alive
     * @brief   Construct a new Alive object.
     * 
     * @param   movementVelocity The movement velocity.
     */
    Alive(float movementVelocity);
    
    /**
     * @fn      ~Alive
     * @brief   Destroy the Alive object. 
     */
    ~Alive() override;

    /**
     * @fn      move
     * @brief   Moves the character at the Alive state velocity.
     */
    void move(void) override;

    /**
     * @fn      printInfo 
     * @brief   Prints the Alive information.
     */
    void printInfo(void) override;

private:
    float _movementVelocity;    /*Movement velocity when a character is Alive.*/
};

#endif  //ALIVE_H
