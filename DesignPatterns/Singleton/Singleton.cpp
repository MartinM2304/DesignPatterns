#include "Singleton.h"

Singleton::Singleton() = default;

Singleton& Singleton::getInstance()
{
    static Singleton instance;
    return instance;
}

Singleton::~Singleton() noexcept = default;
