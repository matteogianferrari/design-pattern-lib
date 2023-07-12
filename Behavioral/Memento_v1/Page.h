/**
 * @file        Page.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class Page.
 * 
 * @version     0.1
 * @date        2023-07-12
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef PAGE_H
#define PAGE_H

#include <string>
#include "PageMemento.h"

/**
 * @class   Page "Page.h" 
 * @brief   Concrete class for a web page in a browser.
 * 
 * @details This class implements part of the "Memento" design pattern.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-12
 * @version 0.1
 */
class Page
{
public:
    /**
     * @fn      Page
     * @brief   Construct a new Page object.
     * 
     * @param   url The website url.
     */
    Page(std::string url);

    /**
     * @fn      ~Page
     * @brief   Destroy the Page object.
     */
    ~Page();

    /**
     * @fn      setUrl
     * @brief   Sets the url with the updated website.
     * 
     * @param   url The website url.
     */
    void setUrl(std::string& url);

    /**
     * @fn      loadPage
     * @brief   Loads the website page.
     */
    void loadPage(void);

    /**
     * @fn      save
     * @brief   Saves a snapshot of the internal state of the web page.
     * 
     * @return  PageMemento* Pointer to a PageMemento object.
     */
    PageMemento* save(void);

    /**
     * @fn      restore
     * @brief   Restores the internal state of the web page to the snapshot state.
     * 
     * @param   state Pointer to a PageMemento object (snapshot).
     */
    void restore(PageMemento* state);
    
private:
    std::string _url;   /*The website url shown in the page.*/
};

#endif  //PAGE_H
