/**
 * @file        Sentence.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Sentence.
 * 
 * @version     0.1
 * @date        2023-07-24
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef SENTENCE_H
#define SENTENCE_H

#include <vector>

enum class Fonts;   /*Forward enum declaration.*/
class Letter;       /*Forward class declaration.*/

/**
 * @class   Sentence "Sentence.h" 
 * @brief   Class that implements a sentence composed of Letters object.
 * 
 * @details This class is part of the "Flyweight" design pattern.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-24
 * @version 0.1
 */
class Sentence
{
public:
    /**
     * @fn      Sentence
     * @brief   Construct a new Sentence object.
     * 
     * @param   sentence The sentence to represents using Letter objects.
     * @param   font The characters font.
     */
    Sentence(const char* sentence, Fonts font);

    /**
     * @fn      ~Sentence
     * @brief   Destroy the Sentence object.
     */
    ~Sentence();

    /**
     * @fn      printInfo
     * @brief   Prints the Sentence Letters to the standard output.
     */
    void printInfo(void);

private:
    std::vector<Letter*> _letters;  /*Vector of pointer to Letter objects.*/
};

#endif  //SENTENCE_H
