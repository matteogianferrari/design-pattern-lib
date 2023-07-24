/**
 * @file        LetterFactory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class LetterFactory.
 * 
 * @version     0.1
 * @date        2023-07-24
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef LETTERFACTORY_H
#define LETTERFACTORY_H

#define N_CHARS 128 /*Number of character in the standard ASCII table.*/
#define N_FONT 3    /*Number of supported fonts.*/

/**
 * @enum    Fonts
 * @brief   Enum that contains all the possible fonts used by the program.
 */
enum class Fonts
{
    Verdana       = 0,  /*Verdana font.*/
    TimesNewRoman = 1,  /*Times New Roman font.*/
    Garamond      = 2   /*Garamond font.*/
};

class Letter;   /*Forward class declaration.*/

/**
 * @class   LetterFactory "LetterFactory.h" 
 * @brief   Class that implements a Letter factory method.
 * 
 * @details This class is implemented with "Singleton" design pattern.
 *          @n This class is part of the "Flyweight" design pattern.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-24
 * @version 0.1
 */
class LetterFactory
{
public:
    /**
     * @fn      getLetterFactory
     * @brief   Gets the LetterFactory object.
     * 
     * @details This function implements the "Singleton" design pattern.
     * 
     * @return  LetterFactory* Pointer to a LetterFactory object.
     */
    static LetterFactory* getLetterFactory(void);

    /**
     * @fn      LetterFactory
     * @brief   Copy constructor of a LetterFactory object.
     * 
     * @details The LetterFactory shouldn't be created from another LetterFactory object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy constructor is deleted.
     * 
     * @param   obj Reference to a LetterFactory object.
     */
    LetterFactory(LetterFactory& obj) = delete;

    /**
     * @fn      operator=
     * @brief   Copy assignment operator of a LetterFactory object.
     * 
     * @details The LetterFactory shouldn't be created from another LetterFactory object.
     *          @n Only 1 instance is allowed with the "Singleton" design pattern.
     *          @n The copy assignment operator is deleted.
     * 
     * @param   obj Reference to a const LetterFactory object.
     */
    void operator=(const LetterFactory& obj) = delete;

    /**
     * @fn      getLetter
     * @brief   Gets the specified Letter object.
     *  
     * @details This function implements the "Factory method" design pattern.
     *          @n If the specified letter to create isn't already created, create an object
     *          of it and store it in the Letter pool for another call.
     * 
     * @param   c Character to create the Letter object.
     * @param   font The character font.
     * @return  Letter* Pointer to a Letter object.
     */
    Letter* getLetter(char c, Fonts font);

protected:
    /**
     * @fn      LetterFactory
     * @brief   Construct a new LetterFactory object.
     */
    LetterFactory();

    /**
     * @fn      ~LetterFactory
     * @brief   Destroy the LetterFactory object.
     */
    ~LetterFactory();

private:
    static LetterFactory* _pInstance;       /*Pointer to a LetterFactory instance.*/
    Letter* _letterPool[N_FONT][N_CHARS];   /*Matrix of Letter pointers.*/
};

#endif  //LETTERFACTORY_H
