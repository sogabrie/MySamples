#include "Utils.hpp"

    std::chrono::steady_clock::time_point   MySorts::Duration::_start \
    = std::chrono::steady_clock::now();

MySorts::Duration::Duration() {}

void MySorts::Duration::start()
{
    _start = std::chrono::steady_clock::now();
}

size_t MySorts::Duration::end()
{
    return (std::chrono::duration_cast<std::chrono::milliseconds>\
    (std::chrono::steady_clock::now() - _start)).count();
}

MySorts::Duration::~Duration(){}
