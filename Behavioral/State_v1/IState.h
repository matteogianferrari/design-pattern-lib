/**
 * @file        IState.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class IState.
 * 
 * @version     0.1
 * @date        2023-07-21
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef STATE_H
#define STATE_H

class IState
{
public:
    /**
     * @fn      ~IState
     * @brief   Destroy the IState object. 
     */
    virtual ~IState() {}

    /**
     * @fn      move
     * @brief   Moves the State possessor at the specific State velocity.
     */
    virtual void move(void) = 0;

    /**
     * @fn      printInfo
     * @brief   Print the specific State information.
     */ 
    virtual void printInfo(void) = 0;
};

#endif  //STATE_H
