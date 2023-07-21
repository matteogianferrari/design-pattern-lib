/**
 * @file        Wounded.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Wounded.
 * 
 * @version     0.1
 * @date        2023-07-21
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef WOUNDED_H
#define WOUNDED_H

#include "IState.h"

/**
 * @class   Wounded "Wounded.h" 
 * @brief   Class that implements the Wounded state for a character.
 * 
 * @details This class derives from the abstract class IState.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-21
 * @version 0.1
 */
class Wounded:
    public IState
{
public:
    /**
     * @fn      Wounded
     * @brief   Construct a new Wounded object.
     * 
     * @param   movementVelocity The movement velocity.
     */
    Wounded(float movementVelocity);
    
    /**
     * @fn      ~Wounded
     * @brief   Destroy the Wounded object. 
     */
    ~Wounded() override;

    /**
     * @fn      move
     * @brief   Moves the character at the Wounded state velocity.
     */
    void move(void) override;

    /**
     * @fn      printInfo 
     * @brief   Prints the Wounded information.
     */
    void printInfo(void) override;

private:
    float _movementVelocity;    /*Movement velocity when a character is Wounded.*/
};

#endif  //WOUNDED_H
