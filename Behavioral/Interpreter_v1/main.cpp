/**
 * @file        main.cpp
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       Concrete application example of the "Interpreter" design pattern.
 * @details     This application simulates an enviroment where two client create abstract
 *              syntax trees and an interpreter evaluates the expressions to obtain a result.
 *              @n This example shows one implementation of the "Interpreter" design pattern.
 * 
 * @note        Use the "Interpreter" pattern when:
 *              @n -The grammar is simple.
 *              @n -You don't care about efficiency of your interpreter.
 *              @n -You can represent grammar statements in the language as abstract syntax
 *              trees.
 * 
 * @version     0.1
 * @date        2023-07-23
 * 
 * @copyright   Copyright (c) 2023
 */

#include <iostream>
#include "Number.h"
#include "Addition.h"
#include "Subtraction.h"


/**
 * @fn      client1 
 * @brief   Function that simulates a client that creates an expression and evaluates
 *          it using an interpreter.
 */
void client1(void)
{
    IExpression* obj = new Addition {
        new Number {10},
        new Subtraction {
            new Number {-5},
            new Number {78}
        }
    };

    std::cout << "The math expression result is: " << obj->interpret() << std::endl;
}


/**
 * @fn      client2
 * @brief   Function that simulates a client that creates an expression and evaluates
 *          it using an interpreter.
 */
void client2(void)
{
    IExpression* obj = new Subtraction {
        new Addition {
            new Addition {
                new Number {20},
                new Number {123}
            },
            new Number {1}
        },
        new Subtraction {
            new Number {-5},
            new Number {78}
        }
    };

    std::cout << "The math expression result is: " << obj->interpret() << std::endl;
}


int main(int, char**){
    client1();
    client2();

    return 0;
}
