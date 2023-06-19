#include "HashTableDatabase.h"


HashTableDatabase::HashTableDatabase():
    _mutex {},
    _hashMap {}
{
}


HashTableDatabase::~HashTableDatabase()
{
}


bool HashTableDatabase::insertRecord(std::string& key, int32_t data)
{
    std::lock_guard<std::mutex> lock {_mutex};

    _hashMap[key] = data;

    return true;
}


bool HashTableDatabase::deleteRecord(std::string& key)
{
    std::lock_guard<std::mutex> lock {_mutex};

    _hashMap.erase(key);

    return true;
}
