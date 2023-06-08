/**
 * @file        FungiCell.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class FungiCell.
 * 
 * @version     0.1
 * @date        2023-06-07
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef FUNGICELL_H
#define FUNGICELL_H

#include <mutex>
#include <string>
#include "ICell.h"

/**
 * @class   FungiCell "FungiCell.h" 
 * @brief   Class that implements a fungi cell.
 * 
 * @details This class derives from the abstract class ICell.
 *          @n This implementation is thread-safe.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-06-07
 * @version 0.1
 */
class FungiCell:
    public ICell
{
public:
    /**
     * @fn      FungiCell
     * @brief   Construct a new Fungi Cell object.
     * 
     * @param   fungi Reference to a string that represents the fungi's type.
     */
    FungiCell(std::string& fungi);

    /**
     * @fn      FungiCell
     * @brief   Copy constructor of a FungiCell object.
     * 
     * @param   cell Reference to a FungiCell object.
     */
    FungiCell(FungiCell& cell);

    /**
     * @fn      ~FungiCell
     * @brief   Destroy the Fungi Cell object.
     */
    ~FungiCell() override;

    /**
     * @fn      clone
     * @brief   Creates an ICell object copying the elements from this FungiCell instance.
     * 
     * @details This function is the implementation of the "Protoype" design pattern.
     *          @n It makes a deep copy of this fungi cell and returns a pointer to the new
     *          allocated object.
     * 
     * @return  ICell* A Pointer to an ICell object.
     */
    ICell* clone(void) override;

    /**
     * @fn      getType
     * @brief   Gets the plant cell's type.
     * 
     * @return  std::string& A reference to the string representing the type.
     */
    std::string& getType(void) override;

    /**
     * @fn      print
     * @brief   Outputs to the specified output stream the object's information.
     * 
     * @param   os Reference to an output stream.
     */
    void print(std::ostream& os) override;

    /**
     * @fn      photosyntesis
     * @brief   Starts the fungi cell's absorb process.
     */
    void absorb(void);

private:
    std::mutex _mutex;  /*Mutex for the thread-safety.*/
    std::string _fungi; /*Fungi cell's type.*/
};

#endif  //FUNGICELL_H
