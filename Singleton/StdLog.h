#ifndef STDLOG_H
#define STDLOG_H

#include "ILog.h"

#define MAX_BUF_SIZE 10000

class StdLog:
    public ILog
{
public:
    StdLog(uint32_t bufSize = MAX_BUF_SIZE);

    ~StdLog() override;

    int32_t print(const char* message, ...) override;

private:
    uint32_t _bufSize;
    char* _pBuffer;
};

#endif  //STDLOG_H
