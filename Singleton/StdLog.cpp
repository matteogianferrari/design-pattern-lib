#include "StdLog.h"
#include <iostream>
#include <cstdarg>
#include <cstring>


StdLog::StdLog(uint32_t bufSize):
    _mutex {},
    _bufSize {bufSize},
    _pBuffer {new char[_bufSize]}
{
}


StdLog::~StdLog()
{
    delete _pBuffer;
}


void StdLog::print(const char* message, ...)
{
    //Locks the mutex
    std::lock_guard<std::mutex> lock {_mutex};

    //Creates the arguments list
    va_list args;
    va_start(args, message);

    //Clears the internal buffer
    memset(_pBuffer, 0, _bufSize);
    //Builds the message
    vsnprintf(_pBuffer, _bufSize, message, args);

    va_end(args);

    std::cout << _pBuffer;
}
