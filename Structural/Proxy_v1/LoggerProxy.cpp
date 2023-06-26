#include "LoggerProxy.h"


LoggerProxy::LoggerProxy(ILogger* pLogger):
    _pLogger {pLogger},
    _buffer {},
    _mutex {}
{
}


LoggerProxy::~LoggerProxy()
{
    delete _pLogger;
}


bool LoggerProxy::print(std::string& id, std::string& message)
{
    std::lock_guard<std::mutex> lock {_mutex};

    //Checks if the id hashed value is valid
    if(getIdHash(id) != CLIENT_TOKEN)
        return false;

    //Appends the message to the internal buffer
    struct ClientMessage m {id, message};
    _buffer.push_back(m);

    //Checks if the buffer needs to be flushed
    if(_buffer.size() == MAX_STORED_MESSAGE)
        flushBuffer();

    return true;
}


uint32_t LoggerProxy::getIdHash(std::string& id)
{
    //Edge case
    if(id == "")
        return 0;

    //Compute the hashed value
    uint32_t hash {1};
    for(auto c: id)
        hash *= c;

    return hash / id.size();
}


void LoggerProxy::flushBuffer(void)
{
    for(struct ClientMessage& instance: _buffer)
        _pLogger->print(instance.id, instance.message);
        
    _buffer.clear();
}
