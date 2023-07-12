#include <iostream>
#include "Page.h"


Page::Page(std::string url):
    _url {url}
{
}


Page::~Page()
{
}


void Page::setUrl(std::string& url)
{
    _url = url;
}


void Page::loadPage(void)
{
    std::cout << "Loaded: " << _url << std::endl; 
}


PageMemento* Page::save(void)
{
    return new PageMemento {_url};
}


void Page::restore(PageMemento* state)
{
    _url = state->getState();
}
