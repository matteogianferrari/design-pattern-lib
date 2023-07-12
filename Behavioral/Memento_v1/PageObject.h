/**
 * @file        PageObject.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class PageObject.
 * 
 * @version     0.1
 * @date        2023-07-12
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef PAGEOBJECT_H
#define PAGEOBJECT_H

#include "Page.h"
#include "PageHistory.h"

/**
 * @class   PageObject "PageObject.h" 
 * @brief   Concrete class that implements a browser page with its history.
 * 
 * @details This class is a "Facade" design pattern used to handle the Page and
 *          PageHistory objects over one generic interface.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-12
 * @version 0.1
 */
class PageObject
{
public:
    /**
     * @fn      PageObject
     * @brief   Construct a new Page Object object.
     * 
     * @param   url The home url (Google as default). 
     */
    PageObject(std::string url = "https://google.com");
    
    /**
     * @fn      ~PageObject
     * @brief   Destroy the Page Object object.
     */
    ~PageObject();

    /**
     * @fn      jumpBack
     * @brief   Goes back n-times in the website history.
     * 
     * @param   jump Number of website url to jump back.
     */
    void jumpBack(uint32_t jump);

    /**
     * @fn      goBack
     * @brief   Goes back 1 time in the website history.
     */
    void goBack(void);

    /**
     * @fn      goForward
     * @brief   Goes forward 1 time in the website history.
     */
    void goForward(void);

    /**
     * @fn      visit
     * @brief   Visits the website page.
     * 
     * @param   url The website url.
     */
    void visit(std::string url);

private:
    Page* _page;            /*Pointer to a Page object.*/
    PageHistory* _history;  /*Pointer to a PageHistory object.*/
};

#endif  //PAGEOBJECT_H
