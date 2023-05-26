#ifndef CACHE_H
#define CACHE_H

#include <cstdint>
#include <mutex>
#include <unordered_map>

class Cache
{
public:
    static Cache* getCache(void);

    Cache(Cache& obj) = delete;
    void operator=(const Cache& obj) = delete;

    void putData(std::string key, int32_t value);
    int32_t getData(std::string key);

protected:
    Cache();

    ~Cache();

private:
    static std::mutex _mutex;
    static Cache* _pInstance;
    std::unordered_map<std::string, int32_t> _hashMap;
};

#endif  //CACHE_H