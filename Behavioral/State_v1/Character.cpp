#include "Character.h"


Character::Character(const std::string& characterId, IState* initialState):
    _currentState {initialState},
    _characterId {characterId}
{
}
 

Character::~Character()
{
}


void Character::move(void)
{
    if(_currentState)
        _currentState->move();
}


void Character::printInfo(void)
{
    if(_currentState)
        _currentState->printInfo();
}


void Character::setState(IState* state)
{
    _currentState = state;
}
