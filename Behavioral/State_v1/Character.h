/**
 * @file        Character.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Character.
 * 
 * @version     0.1
 * @date        2023-07-21
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "IState.h"
#include <string>

/**
 * @class   Character "Character.h" 
 * @brief   Class that implements a character for a game.
 * 
 * @details This class uses the State design pattern to change behaviour at runtime.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-21
 * @version 0.1
 */
class Character
{
public:
    /**
     * @fn      Character
     * @brief   Construct a new Character object
     * 
     * @param   characterId Reference to the character id. 
     * @param   initialState Pointer to IState object (nullptr as default).
     */
    Character(const std::string& characterId, IState* initialState = nullptr);

    /**
     * @fn      ~Character
     * @brief   Destroy the Character object. 
     */
    ~Character();

    /**
     * @fn      move
     * @brief   Moves the character at its current state velocity.  
     */
    void move(void);

    /**
     * @fn      printInfo
     * @brief   Prints the character info based on its state.
     */
    void printInfo(void);

    /**
     * @fn      setState
     * @brief   Sets the internal character state.
     * 
     * @param   state Pointer to an IState object.
     */
    void setState(IState* state);

private:
    IState* _currentState;      /*Current internal character state.*/
    std::string _characterId;   /*Character id.*/
};

#endif  //CHARACTER_H
