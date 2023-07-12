#include <iostream>
#include "PageHistory.h"


PageHistory::PageHistory(Page* page):
    _page {page},
    _history {},
    _index {0}
{
}


PageHistory::~PageHistory()
{
    //Deletes all the PageMemento created
    for(PageMemento* curr: _history)
        delete curr;
}


void PageHistory::saveCurrentPage(void)
{   
    //Saves the Page state and stores the snapshot in the vector
    //and updates the index
    PageMemento* state = _page->save();
    _history.push_back(state);
    _index = _history.size() - 1;
}


void PageHistory::goBack(uint32_t jump)
{
    if(jump > _index)
        return;

    //Restores the snapshot state in the Page object
    _index -= jump;
    _page->restore(_history[_index]);
}


void PageHistory::goForward(uint32_t jump)
{
    if(jump > _history.size() - _index - 1)
        return;

    //Restores the snapshot state in the Page object
    _index += jump;
    _page->restore(_history[_index]);
}
