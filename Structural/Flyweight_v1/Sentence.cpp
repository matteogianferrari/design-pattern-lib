#include "Sentence.h"
#include "LetterFactory.h"
#include "Letter.h"
#include <iostream>


Sentence::Sentence(const char* sentence, Fonts font):
    _letters {}
{
    //Gets the letter factory singleton
    LetterFactory* pFactory {LetterFactory::getLetterFactory()};

    char* p = const_cast<char*>(sentence);
    for(; *p; p++)
    {
        //Append in the vector the Letter pointer returned by the factory
        _letters.push_back(pFactory->getLetter(*p, font));
    }
}


Sentence::~Sentence()
{
}


void Sentence::printInfo(void)
{
    for(Letter* c: _letters)
    {
        std::cout << "Letter " << c << " -> ";
        c->printInfo();
    }
}
