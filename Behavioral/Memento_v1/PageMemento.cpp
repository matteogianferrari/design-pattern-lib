#include "PageMemento.h"


PageMemento::PageMemento(std::string& url):
    _url {url}
{
}


PageMemento::~PageMemento()
{
}


std::string& PageMemento::getState(void)
{
    return _url;
}
