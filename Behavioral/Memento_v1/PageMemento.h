/**
 * @file        PageMemento.h
 * @author      Matteo Gianferrari (https://github.com/matteogianferrari)
 * 
 * @brief       This file contains the definition of a concrete class PageMemento.
 * 
 * @version     0.1
 * @date        2023-07-12
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef PAGEMEMENTO_H
#define PAGEMEMENTO_H

#include <string>

/**
 * @class   PageMemento "PageMemento.h" 
 * @brief   Concrete class for saving a Page snapshot.
 * 
 * @details This class implements part of the "Memento" design pattern.
 *          @n This class has a narrow interface for the application, while
 *          it has a private interface for the friend class Page.
 * 
 * @author  Matteo Gianferrari
 * @date    2023-07-12
 * @version 0.1
 */
class PageMemento
{
public:
    /**
     * @fn      ~PageMemento
     * @brief   Destroy the Page Memento object. 
     */
    ~PageMemento();

private:
    friend class Page;  /*Private interface for Page.*/

    /**
     * @fn      PageMemento
     * @brief   Construct a new Page Memento object.
     * 
     * @param   url The website url.
     */
    PageMemento(std::string& url);

    /**
     * @fn      getState
     * @brief   Gets the Page object internal state stored in the snapshot.
     * 
     * @return  std::string& Reference to the internal state of Page (the url).
     */
    std::string& getState(void);

private:
    std::string _url;   /*The website url shown in the page.*/
};

#endif  //PAGEMEMENTO_H
