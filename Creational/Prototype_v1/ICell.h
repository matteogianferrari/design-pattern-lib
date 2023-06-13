/**
 * @file        ICell.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of an abstract class ICell.
 * 
 * @version     0.1
 * @date        2023-06-07
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef ICELL_H
#define ICELL_H

#include <iostream>

/**
 * @class   ICell "ICell.h" 
 * @brief   Abstract class for a generic cell.
 * 
 * @details The implementations of this class must provide functions for cloning and
 *          printing the specific cell.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-07
 * @version 0.1
 */
class ICell
{
public:
    /**
     * @fn      ~ICell
     * @brief   Destroy the ICell object.
     */
    virtual ~ICell() {}

    /**
     * @fn      clone
     * @brief   Creates an ICell object copying the elements from this instance.
     * 
     * @details This function is the implementation of the "Protoype" design pattern.
     *          @n It makes a deep copy of this objact and returns a pointer to the new
     *          allocated object.
     * 
     * @return  ICell* A Pointer to an ICell object.
     */
    virtual ICell* clone(void) = 0;

    /**
     * @fn      print
     * @brief   Outputs to the specified output stream the object's information.
     * 
     * @param   os Reference to an output stream.
     */
    virtual void print(std::ostream& os) = 0;

    /**
     * @fn      operator<<
     * @brief   Output the cell's information on the specified output stream.
     * 
     * @details The friend declaration allows the "operator<<" to access the "print()"
     *          function in the derived classes.
     * 
     * @param   os Reference to the output stream.
     * @param   cell Reference to a const ICell object.
     * @return  std::ostream& A reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, ICell& cell)
    {
        cell.print(os);
        return os;
    }
};

#endif  //ICELL_H
