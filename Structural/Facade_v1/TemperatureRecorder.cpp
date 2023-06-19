#include "TemperatureRecorder.h"
#include "StdOutLogger.h"
#include "HashTableDatabase.h"

//The static member of the TemperatureRecorder class need to be initialised
//outside the constructor
std::mutex TemperatureRecorder::_mutex {};
TemperatureRecorder* TemperatureRecorder::_pInstance {nullptr};


TemperatureRecorder::TemperatureRecorder(void):
    _database {new HashTableDatabase {}},
    _logger {new StdOutLogger {}}
{
}


TemperatureRecorder::~TemperatureRecorder()
{
    delete _database;
    delete _logger;
}


TemperatureRecorder* TemperatureRecorder::getTemperatureRecorder(void)
{
    std::lock_guard<std::mutex> lock {_mutex};

    if(!_pInstance)
    {
        _pInstance = new TemperatureRecorder {};
    }
    return _pInstance;
}


void TemperatureRecorder::insertTemperature(std::string& timestamp, int32_t value)
{
    std::lock_guard<std::mutex> lock {_mutex};

    if(_database->insertRecord(timestamp, value))
    {
        std::string message {timestamp};
        message += " - Temperature inserted in Database: ";
        message += std::to_string(value);

        _logger->logInfo(message);
    }
    else
    {
        std::string message {"Error in inserting temperature in Database!"};
        _logger->logInfo(message);
    }
}


void TemperatureRecorder::deleteTemperature(std::string& timestamp)
{
    std::lock_guard<std::mutex> lock {_mutex};

    if(_database->deleteRecord(timestamp))
    {
        std::string message {timestamp};
        message += " - Temperature removed from Database.";

        _logger->logInfo(message);
    }
    else
    {
        std::string message {"Error in removing temperature from Database!"};
        _logger->logInfo(message);
    }
}
