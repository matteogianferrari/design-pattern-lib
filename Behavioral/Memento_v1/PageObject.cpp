#include "PageObject.h"


PageObject::PageObject(std::string url):
    _page {new Page {url}},
    _history {new PageHistory {_page}}
{
    //Saves the home page in the history and loads it
    _history->saveCurrentPage();
    _page->loadPage();
}


PageObject::~PageObject()
{
    delete _page;
    delete _history;
}


void PageObject::jumpBack(uint32_t jump)
{
    //Goes back n-times, saves the Page as just seen and loads it 
    _history->goBack(jump);
    _history->saveCurrentPage();
    _page->loadPage();
}



void PageObject::goBack(void)
{   
    //Goes back 1 time, saves the Page as just seen and loads it 
    _history->goBack(1);
    _history->saveCurrentPage();
    _page->loadPage();
}


void PageObject::goForward(void)
{
    //Goes forward 1 time, saves the Page as just seen and loads it 
    _history->goForward(1);
    _history->saveCurrentPage();
    _page->loadPage();
}


void PageObject::visit(std::string url)
{
    //Sets the url, saves the page in the history and loads it
    _page->setUrl(url);
    _history->saveCurrentPage();
    _page->loadPage();
}
