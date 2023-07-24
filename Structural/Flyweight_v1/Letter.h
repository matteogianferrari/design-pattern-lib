/**
 * @file        Letter.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Letter.
 * 
 * @version     0.1
 * @date        2023-07-24
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef LETTER_H
#define LETTER_H

/**
 * @class   Letter "Letter.h" 
 * @brief   Class that implements a graphical ASCII letter.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-24
 * @version 0.1
 */
class Letter
{
public:
    /**
     * @fn      Letter
     * @brief   Construct a new Letter object.
     * 
     * @param   letter ASCII character.
     * @param   font The character font.
     */
    Letter(const char letter, const char* font);   

    /**
     * @fn      ~Letter
     * @brief   Destroy the Letter object.
     */
    ~Letter();

    /**
     * @fn      printInfo
     * @brief   Prints the Letter attributes to the standard output.
     */
    void printInfo(void);
    
private:
    const char _letter; /*The ASCII character.*/
    const char* _font;  /*The character font.*/
};

#endif  //LETTER_H
