/**
 * @file        PageHistory.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class PageHistory.
 * 
 * @version     0.1
 * @date        2023-07-12
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef PAGEHISTORY_H
#define PAGEHISTORY_H

#include <vector>
#include "Page.h"
#include "PageMemento.h"

/**
 * @class   PageHistory "PageHistory.h" 
 * @brief   Concrete class for a handling the history of a web page in a browser..
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-12
 * @version 0.1
 */
class PageHistory
{
public:
    /**
     * @fn      PageHistory
     * @brief   Construct a new Page History object.
     * 
     * @param   page Pointer to a Page object.
     */
    PageHistory(Page* page);

    /**
     * @fn      ~PageHistory
     * @brief   Destroy the Page History object.
     */
    ~PageHistory();

    /**
     * @fn      goBack
     * @brief   Restores the Page state going back n-times.
     * 
     * @param   jump Number of state to jump back.
     */
    void goBack(uint32_t jump);

    /**
     * @fn      goForward
     * @brief   Restores the Page state going forward n-times.
     * 
     * @param   jump Number of state to jump forward.
     */
    void goForward(uint32_t jump);

    /**
     * @fn      saveCurrentPage
     * @brief   Saves the current Page state creating a PageMemento.
     *
     * @details The PageMemento object created is stored in a vector.
     */
    void saveCurrentPage(void);

private:
    Page* _page;                        /*Pointer to the Page object.*/
    std::vector<PageMemento*> _history; /*Vector of pointer to PageMemento objects.*/
    uint32_t _index;                    /*Current index in the vector of PageMemento.*/
};

#endif  //PAGEHISTORY_H
