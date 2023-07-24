#include "LetterFactory.h"
#include "Letter.h"
#include <cstdint>


//The static member of the LetterFactory class need to be initialised outside the constructor
LetterFactory* LetterFactory::_pInstance {nullptr};


LetterFactory* LetterFactory::getLetterFactory(void)
{
    if(!_pInstance)
        _pInstance = new LetterFactory {};

    return _pInstance;
}


LetterFactory::LetterFactory()
{
    for(uint32_t i = 0; i < N_FONT; i++)
        for(uint32_t j = 0; j < N_CHARS; j++)
            _letterPool[i][j] = nullptr;
}


LetterFactory::~LetterFactory()
{
    for(uint32_t i = 0; i < N_FONT; i++)
        for(uint32_t j = 0; j < N_CHARS; j++)
            delete _letterPool[i][j];
}


Letter* LetterFactory::getLetter(char c, Fonts font)
{   
    //Checks if the Letter object is already in the Letter pool
    if(!_letterPool[static_cast<int>(font)][c])
    {   
        //Creates the Letter with the right font
        switch(font)
        {
            case Fonts::Verdana:
                _letterPool[static_cast<int>(font)][c] = new Letter {c, "Verdana"};
                break;
            
            case Fonts::TimesNewRoman:
                _letterPool[static_cast<int>(font)][c] = new Letter {c, "TimesNewRoman"};
                break;
            
            case Fonts::Garamond:
                _letterPool[static_cast<int>(font)][c] = new Letter {c, "Garamond"};
                break;
            
            default:
                _letterPool[static_cast<int>(font)][c] = nullptr;
                break;
        }
    }

    return _letterPool[static_cast<int>(font)][c];
}
