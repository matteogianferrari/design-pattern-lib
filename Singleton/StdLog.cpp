#include "StdLog.h"

#include <iostream>
#include <cstdarg>
#include <cstring>


StdLog::StdLog(uint32_t bufSize):
    _bufSize {bufSize},
    _pBuffer {new char[_bufSize]}
{
}


StdLog::~StdLog()
{
    delete _pBuffer;
}


int StdLog::print(const char* message, ...)
{
    va_list args;

    va_start(args, message);
    memset(_pBuffer, 0, _bufSize);
    vsnprintf(_pBuffer, _bufSize, message, args);
    va_end(args);

    std::cout << _pBuffer;

    return 0;
}
