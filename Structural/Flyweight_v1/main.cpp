/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Flyweight" design pattern.
 * @details     This application simulates an enviroment where a client creates a sentence
 *              using a font. The letters that compose the sentence use heavily the memory,
 *              so the Flyweight design pattern is used.
 *              @n A Letter object pool is keeped in the LetterFactory, so when a recurring
 *              letter is needed, the pointer to the letter in memory is returned, saving
 *              a lot of memory avoiding to create duplicate letters.
 *              @n This example shows one implementation of the "Flyweight" design pattern.
 * 
 * @note        Use the "Flyweight" pattern when all of the following are true:
 *              @n -An application uses a large number of objects.
 *              @n -Storage costs are high because of the sheer quantity of objects.
 *              @n -Most object state can be made extrinsic.
 *              @n -Many groups of objects may be replaced by relatively few shared objects
                once extrinsic state is removed.
                @n -The application doesn't depend on object identity.
 * 
 * @version     0.1
 * @date        2023-07-24
 * 
 * @copyright   Copyright (c) 2023
 */

#include "Sentence.h"
#include "LetterFactory.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that creates a sentence and prints it.
 * 
 * @param   sentence Sentence to create.
 * @param   font The sentence font to use.
 */
void client1(const char* sentence, Fonts font)
{
    Sentence* s = new Sentence {sentence, font};

    s->printInfo();

    delete s;
}


int main(int, char**){  
    client1("Hello my name is Matteo and I'm an Embedded Software Engineer.", Fonts::Verdana);
    client1("I want to become an expert in AI engineering.", Fonts::TimesNewRoman);

    return 0;
}
