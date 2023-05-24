#ifndef ILOG_H
#define ILOG_H

#include <cstdint>

class ILog
{
public:
    virtual ~ILog() {}

    virtual int32_t print(const char* message, ...) = 0;
};

#endif  //ILOG_H
