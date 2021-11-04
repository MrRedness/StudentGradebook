#pragma once
#include <iostream>
#include <chrono>
#include <thread>

inline bool stringEqualsIgnoreCase(const std::string &a, const std::string &b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

inline bool stringEqualsIgnoreCase(const std::string &a, const std::string &b, const std::string &orC)
{
    return stringEqualsIgnoreCase(a, b) || stringEqualsIgnoreCase(a, orC);
}

inline void cOutAndWait(const std::string& msg, const int& timeToWait)
{
    std::cout << msg << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds{timeToWait});
}
